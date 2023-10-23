////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api_p12__dsql__execute_immediate.cpp
//! \brief   Немедленное выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    06.11.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__p12_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v1.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/db_obj/isc_base/isc_xsqlda_v1_svc__msg_blr01_builder.h"
#include "source/db_obj/isc_base/isc_xsqlda_v1_svc__msg_data_descrs_builder.h"
#include "source/db_obj/isc_base/isc_xsqlda_v1_svc__msg_data.h"

#include "source/db_obj/db_service_utils.h"
#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__ExecuteImmediate

RemoteFB__API_P12__ExecuteImmediate RemoteFB__API_P12__ExecuteImmediate::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__ExecuteImmediate::RemoteFB__API_P12__ExecuteImmediate()
{
}

//------------------------------------------------------------------------
RemoteFB__API_P12__ExecuteImmediate::~RemoteFB__API_P12__ExecuteImmediate()
{
}

//interface --------------------------------------------------------------
void RemoteFB__API_P12__ExecuteImmediate::exec(db_obj::t_db_operation_context& OpCtx,
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
  =L"RemoteFB__API_P12__ExecuteImmediate::exec";

 //-----------------------------------------
 RemoteFB__P12__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- проверка дескриптора транзакции
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
 }//if - передали ненулевой дескриптор транзакции

 //-----------------------------------------
 bool HasInParams=false;

 if(pInXSQLDA!=nullptr)
 {
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA
   (pInXSQLDA,
    0 /*minSQLD*/,
    ibp_subsystem__remote_fb__p12,
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
    ibp_subsystem__remote_fb__p12,
    L"pOutXSQLDA");

  HasOutParams=(pOutXSQLDA->sqld>0);
 }//if pOutXSQLDA

 //-----------------------------------------
 if(pData->GetPort()->TestPortFlag__lazy())
 {
  //поддержка "lazy_send" режима.

  //нам нужно освбодить/закрыть все зависшие ресурсы подключения.

  RemoteFB__P12_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);
 }//if lazy port

 //-----------------------------------------
 //подготавливаем объект дескриптора транзакции

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
    //очистка ресурсов транзакции
    (*pTrHandle)->CleanupTrResources();

    //удаляем транзакцию из списка
    pData->TrList__Remove(*pTrHandle);

    //обнуляем дескриптор
    (*pTrHandle)=nullptr;
   }//if

   break;
  }//if

  assert(TrID!=0);

  if(!(*pTrHandle))
  {
   //запоминаем идентификатор дескриптора транзакции
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

   //регистрируем транзакцию в списке
   pData->TrList__Add(newTrHandle); //no throw

   //возвращаем дескриптор вызывающей стороне
   (*pTrHandle)=__STL_MOVE_VALUE(newTrHandle);
  }//if
  else
  if((*pTrHandle)->m_ID.get_value()!=TrID)
  {
   // [2015-05-07]
   //  Произошла смена идентификатора транзакции. Как поступать в данной ситуации
   //  пока не понятно. Так что пока будем обрабатывать как BUG CHECK ошибку.

   try // перехват исключения и перевод порта в недействительное состояние
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
 RemoteFB__API_P12__ExecuteImmediate::helper__execute
                             (RemoteFB__P12__SrvOperation&    serverOperation,
                              RemoteFB__ConnectorData*  const pData,
                              tr_handle_type*           const pTrHandle,
                              protocol::P_USHORT        const SQL_dialect,
                              sql_str_box_type          const SQL_str)
{
 assert(pData);
 assert(pTrHandle);

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P12__StmtHelper::ExecuteImmediate
    (serverOperation,
     pData,
     pTrHandle,
     SQL_dialect,
     SQL_str);

 return TrID;
}//helper_execute

//------------------------------------------------------------------------
protocol::P_OBJCT
 RemoteFB__API_P12__ExecuteImmediate::helper__execute2
                             (RemoteFB__P12__SrvOperation&    serverOperation,
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
 const isc_base::t_isc_xsqlda_v1_svc__msg_blr01_builder_ptr
  spMsgBlrBuilder
   (db_obj::query_db_service<isc_base::t_isc_xsqlda_v1_svc__msg_blr01_builder>
     (pData));

 assert(spMsgBlrBuilder);

 const isc_base::t_isc_xsqlda_v1_svc__msg_data_ptr
  spMsgDataSvc
   (db_obj::query_db_service<isc_base::t_isc_xsqlda_v1_svc__msg_data>
     (pData));

 assert(spMsgDataSvc);

 //-----------------------------------------
 using stmt_data_type=handles::RemoteFB__HandleData_Statement;

 //-----------------------------------------
 stmt_data_type::msg_blr_buffer_type
  InMsg_BLR;

 stmt_data_type::msg_data_buffer_type
  InMsg_DATA;

 //---------------------------
 stmt_data_type::msg_blr_buffer_type
  OutMsg_BLR;

 stmt_data_type::msg_data_buffer_type
  OutMsg_DATA;

 stmt_data_type::msg_data_descrs_type
  OutMsg_DATA_DESCRS;

 //-----------------------------------------
 const bool HasInParams=pInXSQLDA && (pInXSQLDA->sqld>0);

 const bool HasOutParams=pOutXSQLDA && (pOutXSQLDA->sqld>0);

 assert(HasInParams || HasOutParams);

 //-----------------------------------------
 if(HasInParams)
 {
  spMsgBlrBuilder->Build_XSQLDA_MSG_BLR
   (pInXSQLDA,
    InMsg_BLR); //throw

  assert(!InMsg_BLR.empty());

  spMsgDataSvc->Build_XSQLDA_MSG_DATA
   (pInXSQLDA,
    InMsg_DATA);
 }//if HasInParams

 //------
 if(HasOutParams)
 {
  spMsgBlrBuilder->Build_XSQLDA_MSG_BLR
   (pOutXSQLDA,
    OutMsg_BLR); //throw

  assert(!OutMsg_BLR.empty());

  const isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder_ptr
   spMsgDataDescrsBuilder
    (db_obj::query_db_service<isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder>
      (pData));

  assert(spMsgDataDescrsBuilder);

  size_t OutParams_MsgDataSize=0;
  size_t OutParams_MsgDataAlign=0;

  spMsgDataDescrsBuilder->Build_XSQLDA_MSG_DATA_DESCRS
   (pOutXSQLDA,
    OutMsg_DATA_DESCRS,
    &OutParams_MsgDataSize,
    &OutParams_MsgDataAlign); //throw

  OutMsg_DATA.alloc(OutParams_MsgDataSize);
 }//if HasOutParams

 //! \todo
 //!  Проверить состояние XVAR-элементов в pOutXSQLDA.
 //!  - указатели на данные
 //!  - указатели на индикаторы
 //!  - допустимость типов (нельзя запрашивать SQL_NULL)

 //-----------------------------------------
 RemoteFB__OpSvc__StmtExecuteData_v1
  stmtExecuteData;

 stmtExecuteData.InMsg_BLR
  =InMsg_BLR;

 stmtExecuteData.InMsg_DATA
  =InMsg_DATA;

 stmtExecuteData.OutMsg_BLR
  =OutMsg_BLR;

 stmtExecuteData.OutMsg_DATA
  =OutMsg_DATA;

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P12__StmtHelper::ExecuteImmediate2
    (serverOperation,
     pData,
     pTrHandle,
     SQL_dialect,
     SQL_str,
     &stmtExecuteData);

 //-----------------------------------------
 if(HasOutParams)
 {
  //Сохраняем полученные результаты в pOutXSQLDA
  try
  {
   spMsgDataSvc->Parse_XSQLDA_MSG_DATA
    (OutMsg_DATA_DESCRS,
     OutMsg_DATA.size(),
     OutMsg_DATA.data(),
     pOutXSQLDA);
  }
  catch(const std::exception& e)
  {
   //Добавляем информацию о текущей операции (установка значений OUT-параметров)

   //Как протестировать этот обработчик - непонятно.

   IBP_ErrorUtils::Throw__Error
    (e,
     E_FAIL,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_isc__failed_to_set_xsqlda_xvalues_1,
     L"pOutXSQLDA");
  }//catch
 }//if HasOutParams

 //-----------------------------------------
 return TrID;
}//helper_execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
