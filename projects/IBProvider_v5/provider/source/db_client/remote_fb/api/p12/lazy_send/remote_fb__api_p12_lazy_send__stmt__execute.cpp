////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__execute.cpp
//! \brief   Выполнение запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    28.10.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__api_p12_lazy_send__stmt__execute.h"
#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__p12_lazy_send__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__p12_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
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
//class RemoteFB__API_P12_LAZY_SEND__ExecuteStatement

RemoteFB__API_P12_LAZY_SEND__ExecuteStatement RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::RemoteFB__API_P12_LAZY_SEND__ExecuteStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::~RemoteFB__API_P12_LAZY_SEND__ExecuteStatement()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::exec
                                           (db_obj::t_db_operation_context& OpCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            const isc_api::XSQLDA_V1* const pInXSQLDA,
                                            const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pTrHandle!=nullptr);
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::exec";

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

 //----------------------------------------- проверка дескриптора запроса
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#003");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value() && !(*pStmtHandle)->m_ID.is_defer())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#004");
 }//if

 pData->BugCheck__CheckStmt
  (*pStmtHandle,
   c_bugcheck_src,
   L"#005");

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED))
 {
  IBP_ErrorUtils::Throw__Error
   (DB_E_NOTPREPARED,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd_not_prepared_0);
 }//if

 assert((*pStmtHandle)->m_ID.has_value());

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
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED))
 {
  //ERROR - [BUG CHECK] повторное выполнение отложенного запроса.
  //Скорее всего не был закрыт курсор.

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd__attempt_to_reexecute_stmt_with_open_cursor_0);
 }//if

 //У запроса может быть отложенная команда на закрытие курсора.
 //Это должно учитываться при выполнении запроса.

 //----------------------------------------- проталкиваем освобождение ресурсов
 RemoteFB__P12_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);

 //-----------------------------------------
 (*pStmtHandle)->ResetExecuteState();

 assert((*pStmtHandle)->m_pParentTr==nullptr);

 //-----------------------------------------
 //подготавливаем объект дескриптора транзакции

 if(!pData->m_spPreCreatedTr)
  pData->m_spPreCreatedTr=handles::RemoteFB__HandleData_Transaction::Create();

 assert(pData->m_spPreCreatedTr!=nullptr);
 assert(pData->m_spPreCreatedTr->get_cntRef()==1);

 //-----------------------------------------
 protocol::P_OBJCT TrID=0;

 if(HasOutParams)
 {
  TrID
   =self_type::helper__execute2
     (serverOperation,
      pData,
      pTrHandle,
      pStmtHandle,
      pInXSQLDA,
      pOutXSQLDA); //throw
 }
 else
 if(HasInParams)
 {
  assert(!HasOutParams);

  TrID
   =self_type::helper__execute
     (serverOperation,
      pData,
      pTrHandle,
      pStmtHandle,
      pInXSQLDA); //throw
 }
 else
 {
  assert(!HasOutParams);
  assert(!HasInParams);

  TrID
   =self_type::helper__execute
     (serverOperation,
      pData,
      pTrHandle,
      pStmtHandle); //throw
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
      /*old*/(*pTrHandle)->m_ID.get_value(),
      /*new*/TrID);
   }
   catch(...)
   {
    RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

    assert(false);
   }//catch
  }//else

  //Привязка запроса к транзакции, если транзакция все еще существует.

  if(*pTrHandle)
   (*pTrHandle)->StmtList__Add(*pStmtHandle);

  break;
 }//for[ever]
}//exec

//------------------------------------------------------------------------
protocol::P_USHORT
 RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::helper__execute
                                           (RemoteFB__P12__SrvOperation&    serverOperation,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(lib::structure::negative_one));

 //-----------------------------------------
 assert((*pStmtHandle)->m_InParams__MSG_BLR.empty());
 assert((*pStmtHandle)->m_InParams__MSG_DATA.empty());
 assert((*pStmtHandle)->m_InParams__MSG_DATA_DESCRS.empty());
 assert((*pStmtHandle)->m_InParams__MSG_NULLS.empty());

 assert((*pStmtHandle)->m_OutParams__MSG_BLR.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_DATA.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_NULLS.empty());

 //-----------------------------------------
 RemoteFB__OpSvc__StmtExecuteData_v1
  stmtExecuteData;

 assert(stmtExecuteData.InMsg_BLR.empty());

 assert(stmtExecuteData.InMsg_DATA.empty());

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P12_LAZY_SEND__StmtHelper::Execute__lazy_send
    (serverOperation,
     pData,
     pTrHandle,
     pStmtHandle,
     &stmtExecuteData);

 return TrID;
}//helper__execute

//------------------------------------------------------------------------
protocol::P_USHORT
 RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::helper__execute
                                           (RemoteFB__P12__SrvOperation&    serverOperation,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            const isc_api::XSQLDA_V1* const pInXSQLDA)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(lib::structure::negative_one));

 assert(pInXSQLDA);
 assert(pInXSQLDA->sqld>0);

 //-----------------------------------------
 assert((*pStmtHandle)->m_InParams__MSG_BLR.empty());
 assert((*pStmtHandle)->m_InParams__MSG_DATA.empty());
 assert((*pStmtHandle)->m_InParams__MSG_DATA_DESCRS.empty());
 assert((*pStmtHandle)->m_InParams__MSG_NULLS.empty());

 assert((*pStmtHandle)->m_OutParams__MSG_BLR.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_DATA.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_NULLS.empty());

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
 spMsgBlrBuilder->Build_XSQLDA_MSG_BLR
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_BLR); //throw

 assert(!(*pStmtHandle)->m_InParams__MSG_BLR.empty());

 spMsgDataSvc->Build_XSQLDA_MSG_DATA
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_DATA);

 //-----------------------------------------
 RemoteFB__OpSvc__StmtExecuteData_v1
  stmtExecuteData;

 stmtExecuteData.InMsg_BLR
  =(*pStmtHandle)->m_InParams__MSG_BLR;

 stmtExecuteData.InMsg_DATA
  =(*pStmtHandle)->m_InParams__MSG_DATA;

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P12_LAZY_SEND__StmtHelper::Execute__lazy_send
    (serverOperation,
     pData,
     pTrHandle,
     pStmtHandle,
     &stmtExecuteData);

 return TrID;
}//helper__execute

//------------------------------------------------------------------------
protocol::P_OBJCT
 RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::helper__execute2
                                           (RemoteFB__P12__SrvOperation&    serverOperation,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            const isc_api::XSQLDA_V1* const pInXSQLDA,
                                            const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(lib::structure::negative_one));

 assert(pOutXSQLDA!=nullptr);
 assert(pOutXSQLDA->sqld>0);

 //-----------------------------------------
 assert((*pStmtHandle)->m_InParams__MSG_BLR.empty());
 assert((*pStmtHandle)->m_InParams__MSG_DATA.empty());
 assert((*pStmtHandle)->m_InParams__MSG_DATA_DESCRS.empty());
 assert((*pStmtHandle)->m_InParams__MSG_NULLS.empty());

 assert((*pStmtHandle)->m_OutParams__MSG_BLR.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_DATA.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.empty());
 assert((*pStmtHandle)->m_OutParams__MSG_NULLS.empty());

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

 const isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder_ptr
  spMsgDataDescrsBuilder
   (db_obj::query_db_service<isc_base::t_isc_xsqlda_v1_svc__msg_data_descrs_builder>
     (pData));

 assert(spMsgDataDescrsBuilder);

 //-----------------------------------------
 spMsgBlrBuilder->Build_XSQLDA_MSG_BLR
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_BLR); //throw

 assert((pInXSQLDA==nullptr || pInXSQLDA->sqld==0)==((*pStmtHandle)->m_InParams__MSG_BLR.empty()));

 spMsgDataSvc->Build_XSQLDA_MSG_DATA
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_DATA);

 spMsgBlrBuilder->Build_XSQLDA_MSG_BLR
  (pOutXSQLDA,
   (*pStmtHandle)->m_OutParams__MSG_BLR); //throw

 assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

 spMsgDataDescrsBuilder->Build_XSQLDA_MSG_DATA_DESCRS
  (pOutXSQLDA,
   (*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
   &(*pStmtHandle)->m_OutParams__MSG_DATA_SIZE,
   &(*pStmtHandle)->m_OutParams__MSG_DATA_ALIGN); //throw

 (*pStmtHandle)->m_OutParams__MSG_DATA.alloc((*pStmtHandle)->m_OutParams__MSG_DATA_SIZE);

 //! \todo
 //!  Проверить состояние XVAR-элементов в pOutXSQLDA.
 //!  - указатели на данные
 //!  - указатели на индикаторы
 //!  - допустимость типов (нельзя запрашивать SQL_NULL)

 //-----------------------------------------
 RemoteFB__OpSvc__StmtExecuteData_v1
  stmtExecuteData;

 stmtExecuteData.InMsg_BLR
  =(*pStmtHandle)->m_InParams__MSG_BLR;

 stmtExecuteData.InMsg_DATA
  =(*pStmtHandle)->m_InParams__MSG_DATA;

 stmtExecuteData.OutMsg_BLR
  =(*pStmtHandle)->m_OutParams__MSG_BLR;

 stmtExecuteData.OutMsg_DATA
  =(*pStmtHandle)->m_OutParams__MSG_DATA;

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P12_LAZY_SEND__StmtHelper::Execute2__lazy_send
    (serverOperation,
     pData,
     pTrHandle,
     pStmtHandle,
     &stmtExecuteData);

 //Сохраняем полученные результаты в pOutXSQLDA

 try
 {
  spMsgDataSvc->Parse_XSQLDA_MSG_DATA
   ((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
    (*pStmtHandle)->m_OutParams__MSG_DATA.size(),
    (*pStmtHandle)->m_OutParams__MSG_DATA.buffer(),
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

 return TrID;
}//helper__execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
