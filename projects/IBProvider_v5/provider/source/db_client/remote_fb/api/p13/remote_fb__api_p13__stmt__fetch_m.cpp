////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__fetch_m.cpp
//! \brief   API for fetching the row of result set.
//! \author  Kovalenko Dmitry
//! \date    15.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__fetch_m.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/api/helpers/blr/v05/remote_fb__api_hlp__blr_v05__utilities.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__msg_v1_utilities.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__FetchStatement_M

RemoteFB__API_P13__FetchStatement_M RemoteFB__API_P13__FetchStatement_M::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__FetchStatement_M::RemoteFB__API_P13__FetchStatement_M()
{
}

//------------------------------------------------------------------------
RemoteFB__API_P13__FetchStatement_M::~RemoteFB__API_P13__FetchStatement_M()
{
}

//interface --------------------------------------------------------------
bool RemoteFB__API_P13__FetchStatement_M::exec(db_obj::t_db_operation_context&  OpCtx,
                                               RemoteFB__ConnectorData*   const pData,
                                               stmt_handle_type*          const pStmtHandle,
                                               const RemoteFB__OutMsg_v1* const pOutMsg)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(!pData->GetPort()->TestPortFlag__rpc());   //deprecated
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__FetchStatement_M::exec";

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

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
    ibp_subsystem__remote_fb__p13,
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
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd__cant_fetch_from_closed_cursor_0);
 }//if

 //-----------------------------------------
 assert(pOutMsg!=nullptr); //check again

 helpers::RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg
  (pOutMsg,
   1 /*minSQLD*/,
   ibp_subsystem__remote_fb__p13);

 //-----------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF))
 {
  //ERROR - synchronization error. fetch after EOF!

  assert(false);

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
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
   OutMSG_BLR
    (pOutMsg->blr.data(),pOutMsg->blr.size());

  assert(!OutMSG_BLR.empty());

  RemoteFB__FetchResult::msg_data_descrs_type
   OutMSG_DATA_DESCRS
    (pOutMsg->descrs.data(),pOutMsg->descrs.data()+pOutMsg->descrs.size());

  assert(!OutMSG_DATA_DESCRS.empty());

  //---------
  protocol::P_USHORT cBatchRows DEBUG_CODE(=0);

  assert(!pData->GetPort()->TestPortFlag__rpc());

  if(!(*pStmtHandle)->m_PData__BatchFetch.value_or_default(true))
  {
   //������ ����� ���������� �� ����� ������.
   cBatchRows=1;
  }
  else
  if(pData->GetPort()->TestPortFlag__symmetric())
  {
   cBatchRows
    =RemoteFB__P13__StmtHelper::ComputeBatchSize(pOutMsg->data.size());
  }
  else
  {
   const size_t
    szMsgData
     =helpers::RemoteFB__API_HLP__BLR_V05__Utilities::Calc_BLR_MAX_XDR_SIZE
       (pOutMsg->blr);

   assert(szMsgData>0);

   cBatchRows
    =RemoteFB__P13__StmtHelper::ComputeBatchSize(szMsgData);
  }//else

  assert(cBatchRows>0);

  //---------
  RemoteFB__FetchResult::self_ptr
   spFetchResult
    (RemoteFB__FetchResult::Create
      (std::move(OutMSG_BLR),
       std::move(OutMSG_DATA_DESCRS),
       cBatchRows,
       pOutMsg->data.size(),
       pOutMsg->data_align));

  assert(spFetchResult);
  assert(spFetchResult->m_State==RemoteFB__FetchResult::state__active);
  assert(spFetchResult->m_ProcessedFetchCount==0);
  assert(spFetchResult->ROWS__GetCount()==0);

  //--------- Allocating a memory for NULLs
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Alloc_XSQLDA_MSG_NULLS
   (pOutMsg->descrs,
    spFetchResult->m_OutMSG_NULLS);

  assert(!spFetchResult->m_OutMSG_NULLS.empty());

  //--------- The preparation is completed
  (*pStmtHandle)->m_spFetchResult.swap(spFetchResult);

  assert((*pStmtHandle)->m_spFetchResult);
 }
 else
 {
  assert((*pStmtHandle)->m_spFetchResult);

  //! \todo
  //!  �������� ������������ ���������� � �������� � pOutMsg.
  //!  ���� �������� ���������, �� ���������� BUG-CHECK ������.

  assert(!(*pStmtHandle)->m_spFetchResult->m_OutMSG_BLR.empty());

  assert(pOutMsg);
  assert(pOutMsg->descrs.size()>0);
  assert((*pStmtHandle)->m_spFetchResult->m_OutMSG_DATA_DESCRS.size()==pOutMsg->descrs.size());

  assert((*pStmtHandle)->m_spFetchResult->m_OutMSG_BLR.size()==pOutMsg->blr.size());

  assert(memcmp((*pStmtHandle)->m_spFetchResult->m_OutMSG_BLR.data(),pOutMsg->blr.data(),pOutMsg->blr.size())==0);

  assert(!(*pStmtHandle)->m_spFetchResult->m_OutMSG_NULLS.empty());
 }//else (*pStmtHandle)->m_spFetchResult

 assert((*pStmtHandle)->m_spFetchResult);

 assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF));

 //-----------------------------------------------------------------------
 for(DEBUG_CODE(bool debug__OpFetchWasSended=false);;)
 {
  if((*pStmtHandle)->m_spFetchResult->ROWS__GetCount()>0)
  {
   //��������� ���������� ���������� � pOutMsg

   if((*pStmtHandle)->m_spFetchResult->ROWS__GetDataSize()!=pOutMsg->data.size())
   {
    RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedUserRowDataBufferSize
     (c_bugcheck_src,
      L"#R00",
      pOutMsg->data.size(),
      (*pStmtHandle)->m_spFetchResult->ROWS__GetDataSize());
   }//if

   assert((*pStmtHandle)->m_spFetchResult->ROWS__GetDataSize()==pOutMsg->data.size());

   memcpy
    (pOutMsg->data.data(),
     (*pStmtHandle)->m_spFetchResult->ROWS__GetFirstBlock(),
     (*pStmtHandle)->m_spFetchResult->ROWS__GetDataSize());

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

   assert((*pStmtHandle)->m_spFetchResult->m_spFetchExc);

   std::rethrow_exception((*pStmtHandle)->m_spFetchResult->m_spFetchExc);
  }//if FAILED

  assert(!(*pStmtHandle)->m_spFetchResult->m_spFetchExc);

  assert_msg
   ((*pStmtHandle)->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active ||
    (*pStmtHandle)->m_spFetchResult->m_State==RemoteFB__FetchResult::state__completed,
    "state: "<<int((*pStmtHandle)->m_spFetchResult->m_State));

  //----------------------------------------
  //���������� ������� ����� ������ �������

  //� ��� ����� �� ������ �������� ������ ���� ���
  assert(!debug__OpFetchWasSended);

  RemoteFB__P13__StmtHelper::FetchNextRows
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
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
