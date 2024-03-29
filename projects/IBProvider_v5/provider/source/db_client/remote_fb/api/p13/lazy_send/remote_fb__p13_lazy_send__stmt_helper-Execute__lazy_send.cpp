////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13_lazy_send__stmt_helper-Execute__lazy_send.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    04.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v2.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13_LAZY_SEND__StmtHelper

protocol::P_OBJCT
 RemoteFB__P13_LAZY_SEND__StmtHelper::Execute__lazy_send
                             (RemoteFB__P13__SrvOperation&               serverOperation,
                              RemoteFB__ConnectorData*             const pData,
                              tr_handle_type*                      const pTrHandle,
                              stmt_handle_type*                    const pStmtHandle,
                              RemoteFB__OpSvc__StmtExecuteData_v2* const pStmtExecData)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(lib::structure::negative_one));
 assert(pStmtExecData);

 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());

 assert(pStmtExecData->OutMsg_BLR.empty());
 assert(pStmtExecData->OutMsg_DATA.empty());
 assert(pStmtExecData->OutMsg_DATA_DESCRS.empty());
 assert(pStmtExecData->OutMsg_NULLS.empty());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P13_LAZY_SEND__StmtHelper::Execute__lazy_send";

 //-----------------------------------------
 if((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE))
 {
  if(!pTrHandle || !(*pTrHandle))
  {
   //������� � ���������� ����������� ������ ����������� � ������ ����������

   //����� ������� ����������� ��� �����, � ���� ������� ����������.

   //� ���������� ������ ����� ��������� ���������� ���������.
   assert(false);

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__p13,
     ibp_mce_cmd__stmt_with_defer_exec_requires_tr_context_0);
  }//if - �� ������� ����������

  assert(pTrHandle);
  assert((*pTrHandle));
  assert((*pTrHandle)->m_ID.has_value());

  //It needs to save IN-parameters to pStmtHandle.
  // - InMsg_BLR
  // - InMsg_DATA
  // - InMsg_DATA_DESCRS
  // - InMsg_NULLS
  (*pStmtHandle)->SaveInParams(pStmtExecData); //throw

  //���������� ���������� �������
  (*pStmtHandle)->m_EFlags.set(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED);

  return (*pTrHandle)->m_ID.get_value();
 }//if (*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE)

 assert(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE));

 //-----------------------------------------------------------------------

 //[2015-11-15]
 // � ��� ����� ������ ������������� �������� �������� �������.
 // IBProvider �� ������� ������ ��������� ��� �������� ��� ����� ���� �������.
 // � �������, ��������� � ���������� ������ �������� �� ���� ���������.

 bool send_op1_close=false;

 if((*pStmtHandle)->m_pClosingTr!=nullptr)
 {
  //����� ��������� ������� �� �������� �������.

  //[2015-11-15] ����������������� ��������� ������!
  assert_msg(false,"stmtType="<<(*pStmtHandle)->m_PData__StmtTypeID.value_or_default(lib::structure::negative_one));

  send_op1_close=true;
 }//if

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID1=protocol::set02::op_free_statement;
 const protocol::set02::P_OP c_OperationID2=protocol::set02::op_execute;

 {
  //---------------------------------------- 2. build packets
  protocol::set02::PACKET_V02 packet1;
  protocol::set02::PACKET_V02 packet2;

  //---------------------------------------- 2.1 build packet1
  if(send_op1_close)
  {
   packet1.operation = c_OperationID1;

   //------- p_sqlfree__statement
   packet1.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

   //------- p_sqlfree__option
   packet1.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;
  }//if send_op1_close

  //---------------------------------------- 2.2 build packet2
  {
   RemoteFB__P13__StmtHelper::BuildPacket__op_execute
    (&packet2,
     pTrHandle?*pTrHandle:nullptr,
     *pStmtHandle,
     pStmtExecData->InMsg_BLR);

   assert(packet2.operation==c_OperationID2);
  }//build packet2

  //---------------------------------------- 3. send packets
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc(pStmtExecData);

  //------ Let's define the boundaries of work with the server
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try //������ ����� ������ � ������
  {
   if(send_op1_close)
   {
    pData->GetPort()->send_packet
     (portOpCtx,
      packet1); //throw
   }//if

   pData->GetPort()->send_packet
    (portOpCtx,
     packet2); //throw
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

#if(COMP_BUILD_UNUSED_CODE)
   assert_hint(false);
#endif
  }//catch

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get responses
 protocol::P_OBJCT TrID=0;

 t_ibp_error Errors(E_FAIL);

 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet1;
  protocol::set02::PACKET_V02 packet2;

  try //������ ����� ������ � ������
  {
   if(send_op1_close)
   {
    pData->GetPort()->receive_packet
     (portOpCtx,
      packet1); //throw
   }//if

   pData->GetPort()->receive_packet
    (portOpCtx,
     packet2); //throw
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

#if(COMP_BUILD_UNUSED_CODE)
   assert_hint(false);
#endif
  }//catch

  //��� ������ � �������� ��������. ��������� ����� ���������������.

  //---------------------------------------- ��������� ������ CLOSE
  bool close_was_failed=false;

  if(send_op1_close)
  {
   if(packet1.operation==protocol::set02::op_response)
   {
    assert((*pStmtHandle)->m_pClosingTr);

    if(const t_ibp_error_element::self_ptr
        spErrRec
         =pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
           (pData,
            c_OperationID1,
            packet1.p_resp,
            E_FAIL))
    {
     // [2015-11-15] � �� ���� ��� �������������� ������ ������.

     close_was_failed=true;

     Errors.add_error
      (spErrRec); //throw

     //�������������� ���������� � ����.
     Errors.add_error
      (spErrRec->m_err_code,
       ibp_subsystem__remote_fb__p13,
       ibp_mce_cmd_close_stmt_0);
    }
    else
    {
     //�������� ���� ��������� ��� ������.

     //������, FB 2.5.5 �� �������� �� �������� ������ ��� (� �������) "INSERT" �������.
     //������, ��� ������ �������.

     (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
    }//else
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#002",
      packet1.operation);

#if(COMP_BUILD_UNUSED_CODE)
    assert_hint(false);
#endif
   }//else
  }//if send_op1_close

  //---------------------------------------- ��������� ������ EXECUTE
  if(packet2.operation==protocol::set02::op_response)
  {
   if(const t_ibp_error_element::self_ptr
       spErrRec
        =pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
          (pData,
           c_OperationID2,
           packet2.p_resp,
           E_FAIL))
   {
    assert(FAILED(spErrRec->m_err_code));

    Errors.add_error(spErrRec);

    //������ ������ ���������� ������� ��������
    Errors.set_last_error_as_primary();

    Errors.raise_me(spErrRec->m_err_code);
   }//if

   if(close_was_failed)
   {
    //��� ������ ���������� ��� �������, �� ������������� ������ �������� �������.

    assert((*pStmtHandle)->m_pClosingTr);

    (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
   }//if close_was_failed

   assert((*pStmtHandle)->m_pClosingTr==nullptr);

   TrID=packet2.p_resp.p_resp__object;
  }//if - protocol::op_response
  else
  {
   //ERROR - [BUG CHECK] unexpected answer from server

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pData->GetPort(),
     c_bugcheck_src,
     L"#003",
     packet2.operation);

#if(COMP_BUILD_UNUSED_CODE)
   assert_hint(false);
#endif
  }//else
 }//local

 return TrID;
}//Execute__lazy_send

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
