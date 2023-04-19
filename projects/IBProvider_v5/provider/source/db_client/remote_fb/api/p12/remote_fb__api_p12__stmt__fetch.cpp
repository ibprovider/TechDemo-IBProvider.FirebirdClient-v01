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
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__FetchStatement

RemoteFB__API_P12__FetchStatement RemoteFB__API_P12__FetchStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__FetchStatement::RemoteFB__API_P12__FetchStatement()
{
}

//------------------------------------------------------------------------
RemoteFB__API_P12__FetchStatement::~RemoteFB__API_P12__FetchStatement()
{
}

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
  IBP_ErrorUtils::Throw__Error
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

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd__cant_fetch_from_closed_cursor_0);
 }//if

 //-----------------------------------------
 assert(pOutXSQLDA!=nullptr); //check again

 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA
  (pOutXSQLDA,
   1 /*minSQLD*/,
   ibp_subsystem__remote_fb__p12,
   L"pOutXSQLDA");

 //-----------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF))
 {
  //ERROR - synchronization error. fetch after EOF!

  assert(false);

  IBP_ErrorUtils::Throw__Error
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
  RemoteFB__FetchResult::msg_blr_buffer_type
   OutMSG_BLR;

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_BLR
   (pOutXSQLDA,
    OutMSG_BLR); //throw

  assert(!OutMSG_BLR.empty());

  //---------
  RemoteFB__FetchResult::msg_data_descrs_type
   OutMSG_DATA_DESCRS;

  size_t OutMSG_DATA_SIZE  =0;
  size_t OutMSG_DATA_ALIGN =0;

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA_DESCRS
   (pOutXSQLDA,
    OutMSG_DATA_DESCRS,
    &OutMSG_DATA_SIZE,
    &OutMSG_DATA_ALIGN); //throw

  assert(!OutMSG_DATA_DESCRS.empty());
  assert(OutMSG_DATA_SIZE>0); // [2023-03-30] Research

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
   cBatchRows=RemoteFB__P12__StmtHelper::ComputeBatchSize(OutMSG_DATA_SIZE);
  }
  else
  {
   const size_t
    szMsgData
     =helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Calc_XSQLDA_MAX_XDR_SIZE
       (pOutXSQLDA);

   assert(szMsgData>0);

   cBatchRows=RemoteFB__P12__StmtHelper::ComputeBatchSize(szMsgData);
  }//else

  assert(cBatchRows>0);

  //---------
  RemoteFB__FetchResult::self_ptr
   spFetchResult
    (RemoteFB__FetchResult::Create
      (std::move(OutMSG_BLR),
       std::move(OutMSG_DATA_DESCRS),
       cBatchRows,
       OutMSG_DATA_SIZE,
       OutMSG_DATA_ALIGN));

  assert(spFetchResult);
  assert(spFetchResult->m_State==RemoteFB__FetchResult::state__active);
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

  assert(!(*pStmtHandle)->m_spFetchResult->m_OutMSG_BLR.empty());

  assert(pOutXSQLDA);
  assert(pOutXSQLDA->sqld>0);
  assert((*pStmtHandle)->m_spFetchResult->m_OutMSG_DATA_DESCRS.size()==size_t(pOutXSQLDA->sqld));
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
 for(DEBUG_CODE(bool debug__OpFetchWasSended=false);;)
 {
  if((*pStmtHandle)->m_spFetchResult->ROWS__GetCount()>0)
  {
   //��������� ���������� ���������� � pOutXSQLDA

   try
   {
    helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA_MSG_DATA
     ((*pStmtHandle)->m_spFetchResult->m_OutMSG_DATA_DESCRS,
      (*pStmtHandle)->m_spFetchResult->ROWS__GetDataSize(),
      (*pStmtHandle)->m_spFetchResult->ROWS__GetFirstBlock(),
      pOutXSQLDA);
   }
   catch(const std::exception& e)
   {
    //��������� ���������� � ������� �������� (��������� �������� �������)

    //��� �������������� ���� ���������� - ���������.

    IBP_ErrorUtils::Throw__Error
     (e,
      E_FAIL,
      ibp_subsystem__remote_fb__p12,
      ibp_mce_isc__failed_to_set_xsqlda_xvalues_1,
      L"pOutXSQLDA");
   }//catch

   (*pStmtHandle)->m_spFetchResult->ROWS__FreeFirstBlock();

   return true;
  }//if (*pStmtHandle)->m_spFetchResult->ROWS__GetCount()>0

  assert((*pStmtHandle)->m_spFetchResult->ROWS__GetCount()==0);

  //----------------------------------------
  if((*pStmtHandle)->m_spFetchResult->m_State==RemoteFB__FetchResult::state__eof)
  {
   (*pStmtHandle)->m_EFlags.set(stmt_data_type::EFLAG__PAST_EOF);

   //���� ������ ��� ������ �� �����
   (*pStmtHandle)->m_spFetchResult.Release();

   return false;
  }//if EOF

  //----------------------------------------
  if((*pStmtHandle)->m_spFetchResult->m_State==RemoteFB__FetchResult::state__failed)
  {
   //ERROR - ������������ ������ ������� ������

   assert(FAILED((*pStmtHandle)->m_spFetchResult->m_FetchErr.com_code()));

   (*pStmtHandle)->m_spFetchResult->m_FetchErr.raise();
  }//if FAILED

  assert_msg
   ((*pStmtHandle)->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active ||
    (*pStmtHandle)->m_spFetchResult->m_State==RemoteFB__FetchResult::state__completed,
    "state: "<<int((*pStmtHandle)->m_spFetchResult->m_State));

  //----------------------------------------
  //���������� ������� ����� ������ �������

  //� ��� ����� �� ������ �������� ������ ���� ���
  assert(!debug__OpFetchWasSended);

  RemoteFB__P12__StmtHelper::FetchNextRows
   (serverOperation,
    pData,
    *pStmtHandle); //throw

  DEBUG_CODE(debug__OpFetchWasSended=true;)

  //----------------------------------------

  //������ �� ��� ������
  assert((*pStmtHandle)->m_pParentTr);

  assert((*pStmtHandle)->m_spFetchResult);
 }//for[ever]
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
