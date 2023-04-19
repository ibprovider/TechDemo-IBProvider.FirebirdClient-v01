////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__stmt__execute_m.cpp
//! \brief   The API function for a statement execution. The version for a lazy_send-protocol.
//! \author  Kovalenko Dmitry
//! \date    11.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__api_p13_lazy_send__stmt__execute_m.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__msg_v1_utilities.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v2.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M_M

RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M()
{
}

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::~RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M()
{
}

//interface --------------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::exec
                                           (db_obj::t_db_operation_context&  OpCtx,
                                            RemoteFB__ConnectorData*   const pData,
                                            tr_handle_type*            const pTrHandle,
                                            stmt_handle_type*          const pStmtHandle,
                                            const RemoteFB__InMsg_v1*  const pInMsg,
                                            const RemoteFB__OutMsg_v1* const pOutMsg)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pTrHandle!=nullptr);
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::exec";

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

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
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd_not_prepared_0);
 }//if

 assert((*pStmtHandle)->m_ID.has_value());

 //-----------------------------------------
 const bool HasInParams
  =helpers::RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg(pInMsg)!=0;

 //-----------------------------------------
 const bool HasOutParams
  =helpers::RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg(pOutMsg)!=0;

 //-----------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED))
 {
  //ERROR - [BUG CHECK] повторное выполнение отложенного запроса.
  //Скорее всего не был закрыт курсор.

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd__attempt_to_reexecute_stmt_with_open_cursor_0);
 }//if

 //У запроса может быть отложенная команда на закрытие курсора.
 //Это должно учитываться при выполнении запроса.

 //----------------------------------------- проталкиваем освобождение ресурсов
 RemoteFB__P13_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);

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
      pInMsg,
      pOutMsg); //throw
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
      pInMsg); //throw
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
      /*oldTrID*/(*pTrHandle)->m_ID.get_value(),
      /*newTrID*/TrID);
   }
   catch(...)
   {
    RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

#if(COMP_BUILD_UNUSED_CODE)
    assert_hint(false);
#endif
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
 RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::helper__execute
                                           (RemoteFB__P13__SrvOperation&    serverOperation,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

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
 RemoteFB__OpSvc__StmtExecuteData_v2
  stmtExecuteData;

 assert(stmtExecuteData.InMsg_BLR.empty());

 assert(stmtExecuteData.InMsg_DATA_DESCRS.empty());

 assert(stmtExecuteData.InMsg_DATA.empty());

 assert(stmtExecuteData.InMsg_NULLS.empty());

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P13_LAZY_SEND__StmtHelper::Execute__lazy_send
    (serverOperation,
     pData,
     pTrHandle,
     pStmtHandle,
     &stmtExecuteData);

 return TrID;
}//helper__execute

//------------------------------------------------------------------------
protocol::P_USHORT
 RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::helper__execute
                                           (RemoteFB__P13__SrvOperation&    serverOperation,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            const RemoteFB__InMsg_v1* const pInMsg)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

 assert(pInMsg);
 assert(!pInMsg->descrs.empty());
 assert(!pInMsg->blr.empty());
 assert(!pInMsg->data.empty());
 assert(pInMsg->blr.data()!=nullptr);
 assert(pInMsg->data.data()!=nullptr);

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
 RemoteFB__OpSvc__StmtExecuteData_v2
  stmtExecuteData;

 //-----------------------------------------
 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_NULLS
  (pInMsg->descrs,
   pInMsg->data,
   (*pStmtHandle)->m_InParams__MSG_NULLS); //throw

 //-----------------------------------------
 stmtExecuteData.InMsg_BLR
  =pInMsg->blr;

 stmtExecuteData.InMsg_DATA_DESCRS
  =pInMsg->descrs;

 stmtExecuteData.InMsg_DATA
  =pInMsg->data;

 stmtExecuteData.InMsg_NULLS
  =(*pStmtHandle)->m_InParams__MSG_NULLS;

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P13_LAZY_SEND__StmtHelper::Execute__lazy_send
    (serverOperation,
     pData,
     pTrHandle,
     pStmtHandle,
     &stmtExecuteData);

 return TrID;
}//helper__execute

//------------------------------------------------------------------------
protocol::P_OBJCT
 RemoteFB__API_P13_LAZY_SEND__ExecuteStatement_M::helper__execute2
                                           (RemoteFB__P13__SrvOperation&     serverOperation,
                                            RemoteFB__ConnectorData*   const pData,
                                            tr_handle_type*            const pTrHandle,
                                            stmt_handle_type*          const pStmtHandle,
                                            const RemoteFB__InMsg_v1*  const pInMsg,
                                            const RemoteFB__OutMsg_v1* const pOutMsg)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

#ifndef NDEBUG
 if(pInMsg==nullptr)
 {
 }
 else
 if(pInMsg->descrs.empty())
 {
  assert(pInMsg->blr.empty());
  assert(pInMsg->data.empty());
 }
 else
 {
  assert(!pInMsg->descrs.empty());
  assert(!pInMsg->blr.empty());
  assert(!pInMsg->data.empty());

  assert(pInMsg->blr.data()!=nullptr);
  assert(pInMsg->data.data()!=nullptr);
 }//if
#endif

 assert(pOutMsg);
 assert(!pOutMsg->descrs.empty());
 assert(!pOutMsg->blr.empty());
 assert(!pOutMsg->data.empty());
 assert(pOutMsg->blr.data()!=nullptr);
 assert(pOutMsg->data.data()!=nullptr);

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
 RemoteFB__OpSvc__StmtExecuteData_v2
  stmtExecuteData;

 //-----------------------------------------
 if(pInMsg!=nullptr)
 {
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_NULLS
   (pInMsg->descrs,
    pInMsg->data,
    (*pStmtHandle)->m_InParams__MSG_NULLS); //throw

  stmtExecuteData.InMsg_BLR
   =pInMsg->blr;

  stmtExecuteData.InMsg_DATA_DESCRS
   =pInMsg->descrs;

  stmtExecuteData.InMsg_DATA
   =pInMsg->data;

  stmtExecuteData.InMsg_NULLS
   =(*pStmtHandle)->m_InParams__MSG_NULLS;
 }//if pInMsg!=nullptr

 //-----------------------------------------
 //
 // Reserving a space for loading the indicators of NULLs
 //
 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Alloc_XSQLDA_MSG_NULLS
  (pOutMsg->descrs,
   (*pStmtHandle)->m_OutParams__MSG_NULLS);

 stmtExecuteData.OutMsg_BLR
  =pOutMsg->blr;

 stmtExecuteData.OutMsg_DATA_DESCRS
  =pOutMsg->descrs;

 stmtExecuteData.OutMsg_DATA
  =pOutMsg->data;

 stmtExecuteData.OutMsg_NULLS
  =(*pStmtHandle)->m_OutParams__MSG_NULLS;

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P13_LAZY_SEND__StmtHelper::Execute2__lazy_send
    (serverOperation,
     pData,
     pTrHandle,
     pStmtHandle,
     &stmtExecuteData);

 //-----------------------------------------
 return TrID;
}//helper__execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
