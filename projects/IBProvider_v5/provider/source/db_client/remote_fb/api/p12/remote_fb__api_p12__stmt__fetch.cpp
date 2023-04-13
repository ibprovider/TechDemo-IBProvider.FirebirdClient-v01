////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__fetch.cpp
//! \brief   ������� ����������� ���������� �������.
//! \author  Kovalenko Dmitry
//! \date    24.08.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
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
//class RemoteFB__API_P12__FetchStatement

RemoteFB__API_P12__FetchStatement RemoteFB__API_P12__FetchStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__FetchStatement::RemoteFB__API_P12__FetchStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__FetchStatement::~RemoteFB__API_P12__FetchStatement()
{;}

//interface --------------------------------------------------------------
bool RemoteFB__API_P12__FetchStatement::exec(db_obj::t_db_operation_context& OpCtx,
                                             RemoteFB__ConnectorData*  const pData,
                                             stmt_handle_type*         const pStmtHandle,
                                             const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__FetchStatement::exec";

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

 if(!(*pStmtHandle)->m_ID.has_value())
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
  //
  //[2019-05-15]
  // ����� �� ��� ��� ������� ����������� ��������� �������� �������. ��� ���
  // ������ ����� ��������� ���������� ������.
  //

#ifdef IBP_BUILD_TESTCODE
  //[2019-05-28]
  // ��������� �� ��������� ������, ������� ��������� ������ ������.
#else
  assert(false);
#endif

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
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_BLR
   (pOutXSQLDA,
    (*pStmtHandle)->m_OutParams__MSG_BLR); //throw

  assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

  //---------
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA_DESCRS
   (pOutXSQLDA,
    (*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
    &(*pStmtHandle)->m_OutParams__MSG_DATA_SIZE,
    &(*pStmtHandle)->m_OutParams__MSG_DATA_ALIGN); //throw

  assert(!(*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.empty());

  //---------
  protocol::P_USHORT cBatchRows DEBUG_CODE(=0);

  if(pData->GetPort()->TestPortFlag__rpc())
  {
   cBatchRows=1;
  }
  else
  if(!(*pStmtHandle)->m_PData__BatchFetch.value_or_default(true))
  {
   //������ ����� ���������� �� ����� ������.
   cBatchRows=1;
  }
  else
  if(pData->GetPort()->TestPortFlag__symmetric())
  {
   cBatchRows
    =RemoteFB__P12__StmtHelper::ComputeBatchSize((*pStmtHandle)->m_OutParams__MSG_DATA_SIZE);
  }
  else
  {
   const size_t szMsgData
    =helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Calc_XSQLDA_MAX_XDR_SIZE(pOutXSQLDA);

   assert(szMsgData>0);

   cBatchRows=RemoteFB__P12__StmtHelper::ComputeBatchSize(szMsgData);
  }//else

  assert(cBatchRows>0);

  //---------
  handles::RemoteFB__FetchResult::self_ptr
   spFetchResult
    (handles::RemoteFB__FetchResult::Create
      (cBatchRows,
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
   //��������� ���������� ���������� � pOutXSQLDA

   try
   {
    helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA_MSG_DATA
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
   (*pStmtHandle)->m_EFlags.set(stmt_data_type::EFLAG__PAST_EOF);

   //���� ������ ��� ������ �� �����
   (*pStmtHandle)->m_spFetchResult.Release();

   return false;
  }//if EOF

  //----------------------------------------
  if((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__failed)
  {
   //ERROR - ������������ ������ ������� ������

   assert(FAILED((*pStmtHandle)->m_spFetchResult->m_FetchErr.com_code()));

   (*pStmtHandle)->m_spFetchResult->m_FetchErr.raise();
  }//if FAILED

  assert_msg
   ((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active ||
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

  //������ �� ��� ������
  assert((*pStmtHandle)->m_pParentTr);

  assert((*pStmtHandle)->m_spFetchResult);
 }//for[ever]
}//exec

//helper methods ---------------------------------------------------------
void RemoteFB__API_P12__FetchStatement::helper__fetch_next_rows
                                           (RemoteFB__P12__SrvOperation&   serverOperation,
                                            RemoteFB__ConnectorData* const pData,
                                            stmt_data_type*          const pStmt)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_pParentPort);
 assert(pStmt->m_spFetchResult);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__FetchStatement::helper__fetch_next_rows";

 //-----------------------------------------
 //��� ����������� ������ ���� ����������
 assert(pStmt->m_spFetchResult->ROWS__GetCount()==0);

 assert_msg
  (pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active ||
   pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__completed,
   "state: "<<int(pStmt->m_spFetchResult->m_State));

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_fetch;

 //����������������� ��� ��������� ��������� ������ �������
 pStmt->m_spFetchResult->Reactivate();

 assert(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);

 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqldata_statement
  packet.p_sqldata.p_sqldata__statement=pStmt->m_ID.get_value();

  //---------------------------------------- p_sqldata_blr
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqldata.p_sqldata__blr,
    pStmt->m_OutParams__MSG_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pOutXSQLDA");

  assert(packet.p_sqldata.p_sqldata__blr.cstr_length==pStmt->m_OutParams__MSG_BLR.size());

  packet.p_sqldata.p_sqldata__blr.cstr_address=pStmt->m_OutParams__MSG_BLR.buffer();

  //---------------------------------------- p_sqldata_message_number
  packet.p_sqldata.p_sqldata__message_number=0;

  //---------------------------------------- p_sqldata_messages
  assert(structure::can_numeric_cast
          (&packet.p_sqldata.p_sqldata__messages,
           pStmt->m_spFetchResult->m_RequestedFetchCount));

  structure::static_numeric_cast
          (&packet.p_sqldata.p_sqldata__messages,
           pStmt->m_spFetchResult->m_RequestedFetchCount);

  assert(packet.p_sqldata.p_sqldata__messages>0);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ Let's define the boundaries of work with the server
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pStmt->m_pParentPort->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local - sending a packet

 //----------------------------------------- �������� ������� ������
 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

 for(;;)
 {
  assert(pStmt);
  assert(pStmt->m_spFetchResult);
  assert(pStmt->m_spFetchResult->m_RequestedFetchCount>0);
  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);
  assert(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);

  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(pStmt);

  protocol::set01::PACKET_V01 packet;

  pStmt->m_pParentPort->receive_packet
   (portOpCtx,
    packet); //throw

  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);

  if(packet.operation==protocol::set01::op_fetch_response)
  {
   switch(packet.p_sqldata.p_sqldata__status)
   {
    case 0:
    {
     if(packet.p_sqldata.p_sqldata__messages==0)
     {
      //�������� ������� ���������� �����

      //�� ����� ������� ������ ��� �������.
      // ��������, ��� ������� "select id from dual FOR UPDATE".

      //�� ��� ��������� ��� ����������� ������, ��� ��������� ������ ���� ������.

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
      {
       //��������� ��� ���������� ���� ������. ��������� ���������.

       pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__completed;

       return;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==1)
      {
       //�������� ���� ���. ��������� ���������.

       pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__completed;

       return;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      //ERROR - ��������������� ���������� ��������� ������� ������.
      //������ ����� ���������� ����� �������� ���� ����������� �������.

      try // �������� ���������� � ������� ����� � ���������������� ���������
      {
       structure::wstr_formatter
        freason(L"unexpected achievement of the rows group end. Expected: %1. Obtained: %2");

       freason<<pStmt->m_spFetchResult->m_RequestedFetchCount
              <<pStmt->m_spFetchResult->m_ProcessedFetchCount;

       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#001",
         freason.c_str())

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

       assert(false);
      }//catch
     }//if packet.p_sqldata.p_sqldata_messages==0

     //�������� ������ ����

     assert(packet.p_sqldata.p_sqldata__messages==1);

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

     if(packet.p_sqldata.p_sqldata__messages!=0)
     {
      assert(packet.p_sqldata.p_sqldata__messages==1);

      //ERROR - [BUG CHECK] �� �� ������ ������������ �������� EOF � ������ ����.

      try // �������� ���������� � ������� ����� � ���������������� ���������
      {
       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#002",
         L"fetch_response packet contains EOF flag and row data")

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

       assert(false);
      }//catch
     }//if packet.p_sqldata.p_sqldata__messages!=0

     assert(packet.p_sqldata.p_sqldata__messages==0);

     if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
     {
      //ERROR - [BUG CHECK] ������ ������, ��������� ������ �����, ������������
      //����� ������ �����.

      try // �������� ���������� � ������� ����� � ���������������� ���������
      {
       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#003",
         L"expected end-of-rows-group response packet");

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

       assert(false);
      }//catch
     }//if m_ProcessedFetchCount==m_RequestedFetchCount

     assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

     //��������� ���������
     pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__eof;

     return;
    }//case 100 [EOF]

    default:
    {
     //ERROR - [BUG CHECK] ������������ ������ ��������

     try // �������� ���������� � ������� ����� � ���������������� ���������
     {
      structure::wstr_formatter freason(L"unexpected sqldata status: %1");

      freason<<packet.p_sqldata.p_sqldata__status;

      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#004",
        freason.c_str());

      assert(false);
     }
     catch(...)
     {
      RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
       (pData->GetPort());

      assert(false);
     }//catch
    }//default - unexpected status
   }//switch

   //�� �� ������ �������� � ��� �����
   assert(false);
  }//if - op_fetch_response

  //��������� ������ ���������� �������

  if(packet.operation==protocol::set01::op_response)
  {
   //�� �������, ��� ��������� ������ ������� ������.

   //��������� ���������������� (� �������� ������) ���������� �� ������.

   try
   {
    pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
     (pData,
      c_OperationID,
      packet.p_resp,
      E_FAIL); //throw

    //ERROR - [BUG CHECK] ����������� ����� �� �������. ��������� ������.

    try // �������� ���������� � ������� ����� � ���������������� ���������
    {
     IBP_BUG_CHECK__DEBUG
      (c_bugcheck_src,
       L"#005",
       me_bug_check__we_expected_the_error_0);

     assert(false);
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

    return;
   }
   catch(t_ibp_error& exc)
   {
    assert(FAILED(exc.com_code()));

    pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__failed;

    pStmt->m_spFetchResult->m_FetchErr.swap(exc); //no throw!

    assert(FAILED(pStmt->m_spFetchResult->m_FetchErr.com_code()));

    return;
   }//catch exc

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pStmt->m_pParentPort,
    c_bugcheck_src,
    L"#006",
    packet.operation);
 }//for[ever]

 return;
}//helper__fetch_next_rows

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
