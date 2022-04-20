////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__fetch.cpp
//! \brief   ������� ����������� ���������� �������. ������ ��� lazy_send-���������.
//! \author  Kovalenko Dmitry
//! \date    29.10.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__api_p12_lazy_send__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__xsqlda_utilities.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__FetchStatement

RemoteFB__API_P12_LAZY_SEND__FetchStatement RemoteFB__API_P12_LAZY_SEND__FetchStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__FetchStatement::RemoteFB__API_P12_LAZY_SEND__FetchStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__FetchStatement::~RemoteFB__API_P12_LAZY_SEND__FetchStatement()
{;}

//interface --------------------------------------------------------------
bool RemoteFB__API_P12_LAZY_SEND__FetchStatement::exec
                                           (db_obj::t_db_operation_context& OpCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            stmt_handle_type*         const pStmtHandle,
                                            const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_LAZY_SEND__FetchStatement::exec";

 //-----------------------------------------
 RemoteFB__P12__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- �������� ����������� �������
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value() && !(*pStmtHandle)->m_ID.is_defer())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 pData->BugCheck__CheckStmt
  (*pStmtHandle,
   c_bugcheck_src,
   L"#003");

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED))
 {
  IBP_ThrowSimpleError
   (DB_E_NOTPREPARED,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd_not_prepared_0);
 }//if

 //������ ������ ���� �������� � ����������.
 //����� ��������� ��� �� ��������� � �������� ���������.
 if((*pStmtHandle)->m_pParentTr==nullptr)
 {
  //[2015-09-08]
  // �� ������� ������ ��� ����� �������. �������� � �������
  // IBProvider �������� ����������� �������� �������� ����� ���������� ����������.
  //assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd__cant_fetch_from_closed_cursor_0);
 }//if

 //-----------------------------------------
 assert(pOutXSQLDA!=nullptr); //check again

 if(pOutXSQLDA->version!=pOutXSQLDA->c_version_num)
 {
  RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
   (c_bugcheck_src,
    L"#004",
    L"pOutXSQLDA",
    pOutXSQLDA->version);
 }//if

 if(pOutXSQLDA->sqld<=0)
 {
  //ERROR - [BUG CHECK] incorrect output XSQLDA::sqld

  assert_msg(false,"pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

  RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
   (ibp_subsystem__remote_fb__p12,
    L"pOutXSQLDA",
    pOutXSQLDA->sqld);
 }//if

 if(pOutXSQLDA->sqln<pOutXSQLDA->sqld)
 {
  //ERROR - [BUG CHECK] incorrect output XSQLDA::sqln

  assert_msg(false,"pOutXSQLDA->sqln: "<<pOutXSQLDA->sqln<<". pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

  RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
   (ibp_subsystem__remote_fb__p12,
    L"pOutXSQLDA",
    pOutXSQLDA->sqln,
    pOutXSQLDA->sqld);
 }//if

 //-----------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF))
 {
  //ERROR - synchronization error. fetch after EOF!

  assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd__cant_fetch_after_eof_0);
 }//if

 assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF));

 //-----------------------------------------
 if(!(*pStmtHandle)->m_spFetchResult)
 {
  //it is first fetch from cursor

  assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF));

  //---------
  RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_BLR
   (pOutXSQLDA,
    (*pStmtHandle)->m_OutParams__MSG_BLR); //throw

  assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

  //---------
  RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA_DESCRS
   (pOutXSQLDA,
    (*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
    &(*pStmtHandle)->m_OutParams__MSG_DATA_SIZE,
    &(*pStmtHandle)->m_OutParams__MSG_DATA_ALIGN); //throw

  assert(!(*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.empty());

  //---------
  protocol::P_USHORT cBatchRows DEBUG_CODE(=0);

  if(!(*pStmtHandle)->m_BatchFetch.value_or_default(true))
  {
   //������ ����� ���������� �� ����� ������.
   cBatchRows=1;
  }
  else
  if(pData->GetPort()->TestPortFlag__symmetric())
  {
   cBatchRows=RemoteFB__P12__StmtHelper::ComputeBatchSize((*pStmtHandle)->m_OutParams__MSG_DATA_SIZE);
  }
  else
  {
   const size_t szMsgData=RemoteFB__P12__XSQLDA_Utilities::Calc_XSQLDA_MAX_XDR_SIZE(pOutXSQLDA);

   assert(szMsgData>0);

   cBatchRows=RemoteFB__P12__StmtHelper::ComputeBatchSize(szMsgData);
  }//else

  assert(cBatchRows>0);

  //---------
  handles::RemoteFB__FetchResult::self_ptr spFetchResult
   (handles::RemoteFB__FetchResult::Create(cBatchRows,
                                           (*pStmtHandle)->m_OutParams__MSG_DATA_SIZE,
                                           (*pStmtHandle)->m_OutParams__MSG_DATA_ALIGN));

  assert(spFetchResult);
  assert(spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);
  assert(spFetchResult->m_ProcessedFetchCount==0);
  assert(spFetchResult->ROWS__GetCount()==0);

  //--------- ���������� ���������
  (*pStmtHandle)->m_spFetchResult.swap(spFetchResult);

  assert((*pStmtHandle)->m_spFetchResult);
 }
 else
 {
  assert((*pStmtHandle)->m_spFetchResult);

  //! \todo
  //!  �������� ������������ ���������� � �������� � pOutXSQLDA.
  //!  ���� �������� ���������, �� ���������� BUG-CHECK ������.

  assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

  assert(pOutXSQLDA);
  assert(pOutXSQLDA->sqld>0);
  assert((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.size()==size_t(pOutXSQLDA->sqld));
 }//else (*pStmtHandle)->m_spFetchResult

 assert((*pStmtHandle)->m_spFetchResult);

 assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF));

 //-----------------------------------------------------------------------
 //! \todo
 //!  ��������� ��������� XVAR-��������� � pOutXSQLDA.
 //!  - ��������� �� ������
 //!  - ��������� �� ����������
 //!  - ������������ ����� (������ ����������� SQL_NULL)

 //-----------------------------------------------------------------------
 for(DEBUG_CODE(bool OpFetchWasSended=false);;)
 {
  if((*pStmtHandle)->m_spFetchResult->ROWS__GetCount()>0)
  {
   //� ��� ��� ����������� �������� �������
   assert((*pStmtHandle)->m_pClosingTr==nullptr);

   //������ ��� ��������
   assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

   //��������� ���������� ���������� � pOutXSQLDA

   try
   {
    RemoteFB__P12__XSQLDA_Utilities::Parse_XSQLDA_MSG_DATA
     ((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
      (*pStmtHandle)->m_spFetchResult->ROWS__GetDataSize(),
      (*pStmtHandle)->m_spFetchResult->ROWS__GetFirstBlock(),
       pOutXSQLDA);
   }
   catch(const std::exception& e)
   {
    t_ibp_error exc(e);

    //��������� ���������� � ������� �������� (��������� �������� �������)

    //��� �������������� ���� ���������� - ���������.

    exc.add_error
     (E_FAIL,
      ibp_subsystem__remote_fb__p12,
      ibp_mce_isc__failed_to_set_xsqlda_xvalues_1);

    exc<<L"pOutXSQLDA";

    exc.raise_me();
   }//catch

   (*pStmtHandle)->m_spFetchResult->ROWS__FreeFirstBlock();

   return true;
  }//if (*pStmtHandle)->m_spFetchResult->ROWS__GetCount()>0

  assert((*pStmtHandle)->m_spFetchResult->ROWS__GetCount()==0);

  //----------------------------------------
  if((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__eof)
  {
   //� ��� ��� ����������� �������� �������
   assert((*pStmtHandle)->m_pClosingTr==nullptr);

   //������ ��� ��������
   assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

   //------
   (*pStmtHandle)->m_EFlags.set(stmt_data_type::EFLAG__PAST_EOF);

   //���� ������ ��� ������ �� �����
   (*pStmtHandle)->m_spFetchResult.Release();

   return false;
  }//if EOF

  //----------------------------------------
  if((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__failed)
  {
   //� ��� ��� ����������� �������� �������
   assert((*pStmtHandle)->m_pClosingTr==nullptr);

   //������ ��� ��������
   assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

   //ERROR - ������������ ������ ������� ������

   assert(FAILED((*pStmtHandle)->m_spFetchResult->m_FetchErr.com_code()));

   (*pStmtHandle)->m_spFetchResult->m_FetchErr.raise();
  }//if FAILED

  assert_msg((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active ||
             (*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__completed,
             "state: "<<int((*pStmtHandle)->m_spFetchResult->m_State));

  //----------------------------------------
  //���������� ������� ����� ������ �������

  //� ��� ����� �� ������ �������� ������ ���� ���
  assert(!OpFetchWasSended);

  self_type::helper__fetch_next_rows
   (serverOperation,
    pData,
    *pStmtHandle); //throw

  DEBUG_CODE(OpFetchWasSended=true;)

  //----------------------------------------

  //���������� �������� ������ ���� ���������
  assert((*pStmtHandle)->m_pClosingTr==nullptr);

  //������ ��� ��������
  assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

  //������ �� ��� ������ (�������� �������������� ������������ ����������).
  assert((*pStmtHandle)->m_pParentTr);

  assert((*pStmtHandle)->m_spFetchResult);
 }//for[ever]
}//exec

//helper methods ---------------------------------------------------------
void RemoteFB__API_P12_LAZY_SEND__FetchStatement::helper__fetch_next_rows
                                           (RemoteFB__P12__SrvOperation&   serverOperation,
                                            RemoteFB__ConnectorData* const pData,
                                            stmt_data_type*          const pStmt)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_pParentPort);
 assert(pStmt->m_pParentTr);
 assert(pStmt->m_spFetchResult);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_LAZY_SEND__FetchStatement::helper__fetch_next_rows";

 //-----------------------------------------
 //��� ����������� ������ ���� ����������
 assert(pStmt->m_spFetchResult->ROWS__GetCount()==0);

 assert_msg(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active ||
            pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__completed,
            "state: "<<int(pStmt->m_spFetchResult->m_State));

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID1__close =protocol::set01::op_free_statement;
 const protocol::set01::P_OP c_OperationID2__exec  =protocol::set01::op_execute;
 const protocol::set01::P_OP c_OperationID3__fetch =protocol::set01::op_fetch;

 bool send_op1__close=false;
 bool send_op2__exec=false;

 //-----------------------------------------
 if(pStmt->m_pClosingTr!=nullptr)
 {
  //����� ������� ���������� ������, ����� ������� �����
  assert(pStmt->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

  send_op1__close =true;
  send_op2__exec  =true;
 }
 else
 if(pStmt->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED))
 {
  //������� ����� ������� ������

  send_op2__exec =true;
 }//else

 //-----------------------------------------
 {
  //����������������� ��� ��������� ��������� ������ �������
  pStmt->m_spFetchResult->Reactivate();

  assert(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);

  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

  //---------------------------------------- 2. build packets
  protocol::set01::PACKET_V01 packet1__close;
  protocol::set01::PACKET_V01 packet2__exec;
  protocol::set01::PACKET_V01 packet3__fetch;

  //---------------------------------------- 2.1 build packet for close op.
  if(send_op1__close)
  {
   packet1__close.operation = c_OperationID1__close;

   //--------------- p_sqlfree_statement
   packet1__close.p_sqlfree.p_sqlfree__statement=pStmt->m_ID.get_value();

   //--------------- p_sqlfree_statement
   packet1__close.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;
  }//if send_op1__close

  //---------------------------------------- 2.2 build packet for exec op
  if(send_op2__exec)
  {
   RemoteFB__P12__StmtHelper::BuildPacket__op_execute
    (&packet2__exec,
     pStmt->m_pParentTr,
     pStmt);

    assert(packet2__exec.operation==c_OperationID2__exec);
  }//if send_op2__exec

  //---------------------------------------- 2.2 build packet for fetch op
  {
   packet3__fetch.operation = c_OperationID3__fetch;

   //--------------- p_sqldata_statement
   packet3__fetch.p_sqldata.p_sqldata__statement=pStmt->m_ID.get_value();

   //--------------- p_sqldata_blr
   if(!structure::can_numeric_cast(&packet3__fetch.p_sqldata.p_sqldata__blr.cstr_length,
                                   pStmt->m_OutParams__MSG_BLR.size()))
   {
    //ERROR - BLR data of input parameters is too long.

    t_ibp_error exc(E_FAIL,
                    ibp_subsystem__remote_fb__p12,
                    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3);

    exc<<L"pOutXSQLDA"
       <<pStmt->m_OutParams__MSG_BLR.size()
       <<structure::get_numeric_limits(packet3__fetch.p_sqldata.p_sqldata__blr.cstr_length).max_value();

    exc.raise_me();
   }//if

   structure::static_numeric_cast
    (&packet3__fetch.p_sqldata.p_sqldata__blr.cstr_length,
     pStmt->m_OutParams__MSG_BLR.size());

   packet3__fetch.p_sqldata.p_sqldata__blr.cstr_address=pStmt->m_OutParams__MSG_BLR.buffer();

   //--------------- p_sqldata_message_number
   packet3__fetch.p_sqldata.p_sqldata__message_number=0;

   //--------------- p_sqldata_messages
   assert(structure::can_numeric_cast
           (&packet3__fetch.p_sqldata.p_sqldata__messages,
            pStmt->m_spFetchResult->m_RequestedFetchCount));

   structure::static_numeric_cast
           (&packet3__fetch.p_sqldata.p_sqldata__messages,
            pStmt->m_spFetchResult->m_RequestedFetchCount);

   assert(packet3__fetch.p_sqldata.p_sqldata__messages>0);
  }//local

  //---------------------------------------- 3. send packets
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc(pStmt); //no throw

  //------ ���������� ����� ������ �������� � ��������
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try //������ ����� ������ � ������
  {
   if(send_op1__close)
   {
    pStmt->m_pParentPort->send_packet_with_delay
     (portOpCtx,
      packet1__close); //throw
   }//if send_op1__close

   //--------------
   if(send_op2__exec)
   {
    pStmt->m_pParentPort->send_packet_with_delay
     (portOpCtx,
      packet2__exec); //throw
   }//if send_op2__exec

   //--------------
   {
    pStmt->m_pParentPort->send_packet
     (portOpCtx,
      packet3__fetch); //throw
   }//local
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//catch

  sendFrame.complete(); //throw
 }//local - �������� �������

 //-----------------------------------------------------------------------
 assert(pStmt->m_spFetchResult);
 assert(pStmt->m_spFetchResult->m_RequestedFetchCount>0);
 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);
 assert(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);

 bool PortStateGuardIsActive=true;

 try //������ ����� ������ � ������
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(pStmt);

  protocol::set01::PACKET_V01 packet1__close;
  protocol::set01::PACKET_V01 packet2__exec;
  protocol::set01::PACKET_V01 packet3__fetch;

  //----------------------------------------
  if(send_op1__close)
  {
   pStmt->m_pParentPort->receive_packet
    (portOpCtx,
     packet1__close); //throw
  }//if send_op1__close

  if(send_op2__exec)
  {
   pStmt->m_pParentPort->receive_packet
    (portOpCtx,
     packet2__exec); //throw
  }//if send_op2__exec

  {
   pStmt->m_pParentPort->receive_packet
    (portOpCtx,
     packet3__fetch); //throw
  }//local

  //----------------------------------------
  t_ibp_error Errors(S_OK); //no throw

  //---------------------------------------- ���������� CLOSE
  t_ibp_error_element::self_ptr spCloseSrvErr;

  if(send_op1__close)
  {
   if(packet1__close.operation==protocol::set01::op_response)
   {
    //�������� ������
    spCloseSrvErr=pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
                   (pData,
                    c_OperationID1__close,
                    packet1__close.p_resp,
                    E_FAIL); //throw

    if(spCloseSrvErr)
    {
     Errors.add_error
      (spCloseSrvErr); //throw

     Errors.add_error
      (spCloseSrvErr->m_err_code,
       ibp_subsystem__remote_fb__p12,
       ibp_mce_cmd_close_stmt_0);
    }
    else
    {
     //��������� ���������� �������� �������
     assert(pStmt->m_pClosingTr);

     pStmt->Dangerous__CloseCursorOfClosingTr();

     assert(!pStmt->m_pClosingTr);
    }//if
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    //��������� ������� �����
    PortStateGuardIsActive=false;

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pStmt->m_pParentPort,
      c_bugcheck_src,
      L"#001",
      packet1__close.operation);
   }//else
  }//if send_op1__close

  //---------------------------------------- ���������� EXECUTE
  assert(pStmt->m_pParentTr);
  assert(pStmt->m_spFetchResult);

  t_ibp_error_element::self_ptr spExecuteSrvErr;

  if(send_op2__exec)
  {
   if(packet2__exec.operation==protocol::set01::op_response)
   {
    //������� ������

    spExecuteSrvErr=pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
                      (pData,
                       c_OperationID2__exec,
                       packet2__exec.p_resp,
                       E_FAIL); //throw

    if(spExecuteSrvErr)
    {
     //�� �� ����� ��������� ������, ������ ��� ������������ �� �����,
     //��� ���������� ���� ��������.

     //������� �� ����� ��� ��������� �������� � StmtClose.

     Errors.add_error
      (spExecuteSrvErr); //throw

     Errors.add_error
      (spExecuteSrvErr->m_err_code,
       ibp_subsystem__remote_fb__p12,
       ibp_mce_cmd_execute_SQL_stmt_0);
    }
    else
    if(packet2__exec.p_resp.p_resp__object!=pStmt->m_pParentTr->m_ID.get_value())
    {
     //ERROR - [BUG CHECK] � ���, ��������, ���������� ����������!

     assert(false);

     //����������� ����� ���������� � "����������������" ���������

     RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedChangeOfTransaction
      (c_bugcheck_src,
       L"#003",
       pStmt->m_pParentTr->m_ID.get_value(),
       packet2__exec.p_resp.p_resp__object);
    }
    else
    {
     //������ ���������� ��� �������.

     //���������� ������� ����������� ���������� �������.

     pStmt->m_EFlags.clear(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED);

     //� ������������� ��������� ���������� �������� �������.
     if(spCloseSrvErr)
      pStmt->Dangerous__CloseCursorOfClosingTr();

     assert(pStmt->m_pClosingTr==nullptr);
    }//else
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pStmt->m_pParentPort,
      c_bugcheck_src,
      L"#004",
      packet2__exec.operation);
   }//else
  }//if send_op2__exec

  //---------------------------------------- ���������� FETCH

  //�� �������� �� ������� �� ���������� ������, ������ ������ ����������
  //� �������� ���������!
  assert(pStmt->m_pParentTr);
  assert(pStmt->m_spFetchResult);

  if(spExecuteSrvErr)
  {
   //��� ���� ���������� �������.
   assert(send_op2__exec);

   assert(Errors.get_record_count()>0);

   if(packet3__fetch.operation==protocol::set01::op_response)
   {
    const t_ibp_error_element::self_ptr
     spFetchSrvRec=pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
                    (pData,
                     c_OperationID3__fetch,
                     packet3__fetch.p_resp,
                     E_FAIL); //throw

    //�� ������� ������!
    if(!spFetchSrvRec)
    {
     assert(PortStateGuardIsActive);

     IBP_BUG_CHECK2__DEBUG
      (Errors,
       c_bugcheck_src,
       L"#005",
       me_bug_check__we_expected_the_error_0);
    }//if !spFetchSrvRec

    assert(spFetchSrvRec);

    PortStateGuardIsActive=false;

    //��������� ������ � ����� ���������
    Errors.add_error(spFetchSrvRec); //throw

    //���������� ��� ������ ������
    const HRESULT firstErrCode=IBP_MapErrorRecordToHRESULT(Errors.get_record(0));

    assert(FAILED(firstErrCode));

    //! \todo
    //!  ���� ����� ���������� ��� ��������� �������� � �������� �����������
    //!  � �������� � ������ ���� ������� � ������ ���������.
    //!
    //!  [2016-02-02]
    //   �� ������� ��� ���������� ����� ��������� ��������,
    //!  ��������� �� ������� ��������, ��� ����������� ��� ���������� � ������������
    //!  ���� � ��������� � ������������� "������� � ������ ��������� ������".
    //!  ��� �� ��������� - ����� ��� ��� ������ ����� ������ (��������� � ������ ���������).

    //� ���������� ����������
    Errors.raise_me(firstErrCode);
   }//if packet3__fetch.operation==protocol::op_response

   //����������, ��� � ��� ��� ���� EXECUTE
   assert(spExecuteSrvErr);
   assert(FAILED(spExecuteSrvErr->m_err_code)); //� ������, ��.

   if(packet3__fetch.operation==protocol::set01::op_fetch_response)
   {
    //FETCH, ���-�� ��� ���������.

    //������� �� ���������� ���������� CLOSE_STMT (���� �� ����������)
    if(spCloseSrvErr && spCloseSrvErr->m_err_code==DB_E_CANCELED)
    {
     //��� ���� ������, ������ ���� �������� ������� �� �������� �������
     assert(send_op1__close);

     assert(Errors.get_record_count()>0);
     assert(Errors.get_record(0)==spCloseSrvErr);

     // [2016-02-01]
     // 1. �� ����� ���������� ������ �� ���� ������� (close, execute, fetch) ������
     //    ������� ������ ���������� �������� (�� ������ ��� FETCH)
     //
     // 2. Cancel ������� �������� ������� (close)
     //
     // 3. Execute, �������������� ��� �� �� ���������� (reopen opened cursor).
     //
     // 4. � ��� Fetch ��� ����������, ������ ��� � ��� �� ��� ������ ���������� ������.
     //
     // ------------------------------------
     // ������ ����� ��� � ���� ���������� CORE-3984 [FB Tracker], ����� ���
     // ������ ����� fbclient.dll �� �������� ������:
     //
     //  | Dynamic SQL Error
     //  | SQL error code = -502
     //  | Attempt to reopen an open cursor
     //
     // ����� fbclient.dll ���� ������ ���������� �� ������ �������� ������� (DB_E_CANCELLED)
     // � �������� �� ������ ���������� �������.
     // ------------------------------------
     //
     // ��� ���, �������� ����� ��� ���������
     //  - ��������� ������� ��������� �����
     //  - ���������� ���������� � �������������� ������� ������

     PortStateGuardIsActive=false;

     //! \todo
     //!  �� ��������, ��� ����� �������� ������������, ��� � ��� �������� ����������
     //!  ������ �������. ������ ��� ������������ ����� �����, ��� ������ ���
     //!  ������, � �� ������-�� �������� ��������� ��������.

     assert(spCloseSrvErr->m_err_code==DB_E_CANCELED); //��� ��� ��������

     Errors.raise_me(spCloseSrvErr->m_err_code);
    }//if spCloseSrvErr && spCloseSrvErr->m_err_code==DB_E_CANCELED
   }//if packet3__fetch.operation==protocol::op_fetch_response

   //ERROR - [BUG CHECK] unexpected answer from server

   PortStateGuardIsActive=false;

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck2_UnexpectedServerAnswer
    (Errors,
     pStmt->m_pParentPort,
     c_bugcheck_src,
     L"#006",
     packet3__fetch.operation);
  }//if spExecuteSrvErr

  assert(!spExecuteSrvErr);

  for(bool firstIteration=true;;firstIteration=false)
  {
   assert(pStmt->m_pParentTr);
   assert(pStmt->m_spFetchResult);

   if(!firstIteration)
   {
    packet3__fetch.init();

    pStmt->m_pParentPort->receive_packet
     (portOpCtx,
      packet3__fetch); //throw
   }//if !firstIteration

   assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);

   if(packet3__fetch.operation==protocol::set01::op_fetch_response)
   {
    switch(packet3__fetch.p_sqldata.p_sqldata__status)
    {
     case 0:
     {
      if(packet3__fetch.p_sqldata.p_sqldata__messages==0)
      {
       //�������� ������� ���������� �����

       //�� ����� ������� ������ ��� �������.
       // ��������, ��� ������� "select id from dual FOR UPDATE".

       //�� ��� ��������� ��� ����������� ������, ��� ��������� ������ ���� ������.

       if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
       {
        //��������� ��� ���������� ���� ������. ��������� ���������.

        pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__completed;

        PortStateGuardIsActive=false;

        return;
       }//if

       assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

       if(pStmt->m_spFetchResult->m_ProcessedFetchCount==1)
       {
        //�������� ���� ���. ��������� ���������.

        pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__completed;

        PortStateGuardIsActive=false;

        return;
       }//if

       assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

       //ERROR - ��������������� ���������� ��������� ������� ������.
       //������ ����� ���������� ����� �������� ���� ����������� �������.

       structure::wstr_formatter
        freason(L"unexpected achievement of the rows group end. Expected: %1. Obtained: %2");

       freason<<pStmt->m_spFetchResult->m_RequestedFetchCount
              <<pStmt->m_spFetchResult->m_ProcessedFetchCount;

       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#007",
         freason.c_str())
      }//if packet.p_sqldata.p_sqldata_messages==0

      //�������� ������ ����

      assert(packet3__fetch.p_sqldata.p_sqldata__messages==1);

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
      {
       //�������� ��������� ����� ������ ������� � �������

       //������ ����������� "������" �����.
       continue;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      //��������� �� ���������.

      //���������� �������� ������� ������
      continue;
     }//case 0

     case 100:
     {
      //��������� ����� ��������������� ���������

      if(packet3__fetch.p_sqldata.p_sqldata__messages!=0)
      {
       assert(packet3__fetch.p_sqldata.p_sqldata__messages==1);

       //ERROR - [BUG CHECK] �� �� ������ ������������ �������� EOF � ������ ����.

       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#008",
         L"fetch_response packet contains EOF flag and row data")
      }//if

      assert(packet3__fetch.p_sqldata.p_sqldata__messages==0);

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
      {
       //ERROR - [BUG CHECK] ������ ������, ��������� ������ �����, ������������
       //����� ������ �����.

       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#009",
         L"expected end-of-rows-group response packet");
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      //��������� ���������
      pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__eof;

      PortStateGuardIsActive=false;

      return;
     }//case 100 [EOF]

     default:
     {
      //ERROR - [BUG CHECK] ������������ ������ ��������

      structure::wstr_formatter freason(L"unexpected sqldata status: %1");

      freason<<packet3__fetch.p_sqldata.p_sqldata__status;

      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#010",
        freason.c_str());
     }//default - unexpected status
    }//switch

    //�� �� ������ �������� � ��� �����
    assert(false);
   }//if - op_fetch_response

   //��������� ������ ���������� �������

   if(packet3__fetch.operation==protocol::set01::op_response)
   {
    //�� �������, ��� ��������� ������ ������� ������.

    //��������� ���������������� (� �������� ������) ���������� �� ������.

    try
    {
     pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
      (pData,
       c_OperationID3__fetch,
       packet3__fetch.p_resp,
       E_FAIL); //throw

     //ERROR - [BUG CHECK] ����������� ����� �� �������. ��������� ������.
     assert(PortStateGuardIsActive);

     PortStateGuardIsActive=false;

     try // �������� ���������� � ������� ����� � ���������������� ���������
     {
      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#011",
        me_bug_check__we_expected_the_error_0);
     }
     catch(...)
     {
      RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
       (pData->GetPort());

      assert(false);
     }//catch
    }
    catch(const std::bad_alloc&)
    {
     pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__failed;

     pStmt->m_spFetchResult->m_FetchErr.clear_state(E_OUTOFMEMORY);
    }
    catch(t_ibp_error& exc)
    {
     assert(FAILED(exc.com_code()));

     pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__failed;

     pStmt->m_spFetchResult->m_FetchErr.swap(exc); //no throw!

     assert(FAILED(pStmt->m_spFetchResult->m_FetchErr.com_code()));
    }//catch exc

    break;
   }//if - protocol::op_response

   //ERROR - [BUG CHECK] unexpected answer from server

   assert(PortStateGuardIsActive);

   PortStateGuardIsActive=false;

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pStmt->m_pParentPort,
     c_bugcheck_src,
     L"#012",
     packet3__fetch.operation);
  }//for[ever]
 }//local
 catch(...)
 {
  if(PortStateGuardIsActive)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
    (pData->GetPort());

   assert(false);
  }//if

  throw;
 }//catch

 return;
}//helper__fetch_next_rows

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
