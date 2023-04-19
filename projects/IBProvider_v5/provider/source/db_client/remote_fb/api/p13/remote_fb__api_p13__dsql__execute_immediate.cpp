////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api_p13__dsql__execute_immediate.cpp
//! \brief   ����������� ���������� �������.
//! \author  Kovalenko Dmitry
//! \date    23.06.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v2.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ExecuteImmediate

RemoteFB__API_P13__ExecuteImmediate RemoteFB__API_P13__ExecuteImmediate::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__ExecuteImmediate::RemoteFB__API_P13__ExecuteImmediate()
{
}

//------------------------------------------------------------------------
RemoteFB__API_P13__ExecuteImmediate::~RemoteFB__API_P13__ExecuteImmediate()
{
}

//interface --------------------------------------------------------------
void RemoteFB__API_P13__ExecuteImmediate::exec(db_obj::t_db_operation_context& OpCtx,
                                               RemoteFB__ConnectorData*  const pData,
                                               tr_handle_type*           const pTrHandle,
                                               protocol::P_USHORT        const SQL_dialect,
                                               sql_str_box_type          const SQL_str,
                                               const isc_api::XSQLDA_V1* const pInXSQLDA,
                                               const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pTrHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__ExecuteImmediate::exec";

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- �������� ����������� ����������
 if((*pTrHandle)!=nullptr)
 {
  if(!(*pTrHandle)->m_ID.has_value())
  {
   assert(false);

   RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
    (c_bugcheck_src,
     L"#001");
  }//if

  pData->BugCheck__CheckTr
   ((*pTrHandle),
    c_bugcheck_src,
    L"#002");
 }//if - �������� ��������� ���������� ����������

 //-----------------------------------------
 bool HasInParams=false;

 if(pInXSQLDA!=nullptr)
 {
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA
   (pInXSQLDA,
    0 /*minSQLD*/,
    ibp_subsystem__remote_fb__p13,
    L"pInXSQLDA");

  HasInParams=(pInXSQLDA->sqld>0);
 }//if pInXSQLDA

 //-----------------------------------------
 bool HasOutParams=false;

 if(pOutXSQLDA!=nullptr)
 {
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA
   (pOutXSQLDA,
    0 /*minSQLD*/,
    ibp_subsystem__remote_fb__p13,
    L"pOutXSQLDA");

  HasOutParams=(pOutXSQLDA->sqld>0);
 }//if pOutXSQLDA

 //-----------------------------------------
 if(pData->GetPort()->TestPortFlag__lazy())
 {
  //��������� "lazy_send" ������.

  //��� ����� ���������/������� ��� �������� ������� �����������.

  RemoteFB__P13_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);
 }//if lazy port

 //-----------------------------------------
 //�������������� ������ ����������� ����������

 if(!pData->m_spPreCreatedTr)
  pData->m_spPreCreatedTr=handles::RemoteFB__HandleData_Transaction::Create();

 assert(pData->m_spPreCreatedTr!=nullptr);
 assert(pData->m_spPreCreatedTr->get_cntRef()==1);

 //-----------------------------------------
 protocol::P_OBJCT TrID=0;

 if(HasInParams || HasOutParams)
 {
  TrID
   =self_type::helper__execute2
     (serverOperation,
      pData,
      pTrHandle,
      SQL_dialect,
      SQL_str,
      pInXSQLDA,
      pOutXSQLDA); //throw
 }//else
 else
 {
  assert(!HasInParams);
  assert(!HasOutParams);

  TrID
   =self_type::helper__execute
     (serverOperation,
      pData,
      pTrHandle,
      SQL_dialect,
      SQL_str); //throw
 }//else

 //----------------------------------------- EXIT
 for(;;)
 {
  if(TrID==0)
  {
   if((*pTrHandle))
   {
    //������� �������� ����������
    (*pTrHandle)->CleanupTrResources();

    //������� ���������� �� ������
    pData->TrList__Remove(*pTrHandle);

    //�������� ����������
    (*pTrHandle)=nullptr;
   }//if

   break;
  }//if

  assert(TrID!=0);

  if(!(*pTrHandle))
  {
   //���������� ������������� ����������� ����������
   handles::RemoteFB__TrHandle newTrHandle;

   assert(!newTrHandle);
   assert(pData->m_spPreCreatedTr);
   assert(pData->m_spPreCreatedTr->get_cntRef()==1);

   pData->m_spPreCreatedTr.swap(newTrHandle);

   assert(!pData->m_spPreCreatedTr);
   assert(newTrHandle);
   assert(newTrHandle->get_cntRef()==1);

   assert(newTrHandle->m_ID.is_null());

   newTrHandle->m_ID.set_value(&TrID);

   //������������ ���������� � ������
   pData->TrList__Add(newTrHandle); //no throw

   //���������� ���������� ���������� �������
   (*pTrHandle)=__STL_MOVE_VALUE(newTrHandle);
  }//if
  else
  if((*pTrHandle)->m_ID.get_value()!=TrID)
  {
   // [2015-05-07]
   //  ��������� ����� �������������� ����������. ��� ��������� � ������ ��������
   //  ���� �� �������. ��� ��� ���� ����� ������������ ��� BUG CHECK ������.

   try // �������� ���������� � ������� ����� � ���������������� ���������
   {
    RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedChangeOfTransaction
     (c_bugcheck_src,
      L"#008",
      /*oldTrID*/(*pTrHandle)->m_ID.get_value(),
      /*newTrID*/TrID);

    assert(false);
   }
   catch(...)
   {
    RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

    assert(false);
   }//catch
  }//if (*pTrHandle)->m_ID.get_value()!=TrID

  break;
 }//for[ever]
}//exec

//helper methods ---------------------------------------------------------
protocol::P_OBJCT
 RemoteFB__API_P13__ExecuteImmediate::helper__execute
                             (RemoteFB__P13__SrvOperation&    serverOperation,
                              RemoteFB__ConnectorData*  const pData,
                              tr_handle_type*           const pTrHandle,
                              protocol::P_USHORT        const SQL_dialect,
                              sql_str_box_type          const SQL_str)
{
 assert(pData);
 assert(pTrHandle);

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P13__StmtHelper::ExecuteImmediate
    (serverOperation,
     pData,
     pTrHandle,
     SQL_dialect,
     SQL_str);

 return TrID;
}//helper_execute

//------------------------------------------------------------------------
protocol::P_OBJCT
 RemoteFB__API_P13__ExecuteImmediate::helper__execute2
                             (RemoteFB__P13__SrvOperation&    serverOperation,
                              RemoteFB__ConnectorData*  const pData,
                              tr_handle_type*           const pTrHandle,
                              protocol::P_USHORT        const SQL_dialect,
                              sql_str_box_type          const SQL_str,
                              const isc_api::XSQLDA_V1* const pInXSQLDA,
                              const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pData);
 assert(pTrHandle);

 //-----------------------------------------
 typedef handles::RemoteFB__HandleData_Statement stmt_data_type;

 //-----------------------------------------
 stmt_data_type::msg_blr_buffer_type
  InMsg_BLR;

 stmt_data_type::msg_data_buffer_type
  InMsg_DATA;

 stmt_data_type::msg_data_descrs_type
  InMsg_DATA_DESCRS;

 stmt_data_type::msg_nulls_buffer_type
  InMsg_NULLS;

 //---------------------------
 stmt_data_type::msg_blr_buffer_type
  OutMsg_BLR;

 stmt_data_type::msg_data_buffer_type
  OutMsg_DATA;

 stmt_data_type::msg_data_descrs_type
  OutMsg_DATA_DESCRS;

 stmt_data_type::msg_nulls_buffer_type
  OutMsg_NULLS;

 //-----------------------------------------
 const bool HasInParams=pInXSQLDA && (pInXSQLDA->sqld>0);

 const bool HasOutParams=pOutXSQLDA && (pOutXSQLDA->sqld>0);

 assert(HasInParams || HasOutParams);

 //-----------------------------------------
 if(HasInParams)
 {
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_BLR
   (pInXSQLDA,
    InMsg_BLR); //throw

  assert(!InMsg_BLR.empty());

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA
   (pInXSQLDA,
    InMsg_DATA);

  size_t unused__InParams_MsgDataSize=0;
  size_t unused__InParams_MsgDataAlign=0;

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA_DESCRS
   (pInXSQLDA,
    InMsg_DATA_DESCRS,
    &unused__InParams_MsgDataSize,
    &unused__InParams_MsgDataAlign); //throw

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_NULLS
   (pInXSQLDA,
    InMsg_NULLS);
 }//if HasInParams

 //------
 if(HasOutParams)
 {
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_BLR
   (pOutXSQLDA,
    OutMsg_BLR); //throw

  assert(!OutMsg_BLR.empty());

  size_t OutParams_MsgDataSize=0;
  size_t OutParams_MsgDataAlign=0;

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA_DESCRS
   (pOutXSQLDA,
    OutMsg_DATA_DESCRS,
    &OutParams_MsgDataSize,
    &OutParams_MsgDataAlign); //throw

  OutMsg_DATA.alloc(OutParams_MsgDataSize);

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Alloc_XSQLDA_MSG_NULLS
   (pOutXSQLDA,
    OutMsg_NULLS);
 }//if HasOutParams

 //! \todo
 //!  ��������� ��������� XVAR-��������� � pOutXSQLDA.
 //!  - ��������� �� ������
 //!  - ��������� �� ����������
 //!  - ������������ ����� (������ ����������� SQL_NULL)

 //-----------------------------------------
 RemoteFB__OpSvc__StmtExecuteData_v2
  stmtExecuteData;

 stmtExecuteData.InMsg_BLR
  =InMsg_BLR;

 stmtExecuteData.InMsg_DATA_DESCRS
  =InMsg_DATA_DESCRS;

 stmtExecuteData.InMsg_DATA
  =InMsg_DATA;

 stmtExecuteData.InMsg_NULLS
  =InMsg_NULLS;

 stmtExecuteData.OutMsg_BLR
  =OutMsg_BLR;

 stmtExecuteData.OutMsg_DATA_DESCRS
  =OutMsg_DATA_DESCRS;

 stmtExecuteData.OutMsg_DATA
  =OutMsg_DATA;

 stmtExecuteData.OutMsg_NULLS
  =OutMsg_NULLS;

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P13__StmtHelper::ExecuteImmediate2
    (serverOperation,
     pData,
     pTrHandle,
     SQL_dialect,
     SQL_str,
     &stmtExecuteData);

 //-----------------------------------------
 if(HasOutParams)
 {
  //��������� ���������� ���������� � pOutXSQLDA
  try
  {
   helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA_MSG_DATA
    (OutMsg_DATA_DESCRS,
     OutMsg_DATA.size(),
     OutMsg_DATA.data(),
     pOutXSQLDA);
  }
  catch(const std::exception& e)
  {
   //��������� ���������� � ������� �������� (��������� �������� OUT-����������)

   //��� �������������� ���� ���������� - ���������.

   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb__p13,
     ibp_mce_isc__failed_to_set_xsqlda_xvalues_1,
     L"pOutXSQLDA");
  }//catch
 }//if HasOutParams

 //-----------------------------------------
 return TrID;
}//helper_execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
