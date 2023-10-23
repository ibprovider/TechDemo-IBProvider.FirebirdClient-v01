////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api_p13__dsql__execute_immediate_m.h
//! \brief   The immediate execution of a statement.
//! \author  Kovalenko Dmitry
//! \date    13.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__dsql__execute_immediate_m.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v2.h"
#include "source/db_client/remote_fb/api/helpers/remote_fb__api_hlp__msg_v1_utilities.h"
#include "source/db_client/remote_fb/remote_fb__msg_v1.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ExecuteImmediate_M_M

RemoteFB__API_P13__ExecuteImmediate_M RemoteFB__API_P13__ExecuteImmediate_M::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__ExecuteImmediate_M::RemoteFB__API_P13__ExecuteImmediate_M()
{
}

//------------------------------------------------------------------------
RemoteFB__API_P13__ExecuteImmediate_M::~RemoteFB__API_P13__ExecuteImmediate_M()
{
}

//interface --------------------------------------------------------------
void RemoteFB__API_P13__ExecuteImmediate_M::exec(db_obj::t_db_operation_context&  OpCtx,
                                                 RemoteFB__ConnectorData*   const pData,
                                                 tr_handle_type*            const pTrHandle,
                                                 protocol::P_USHORT         const SQL_dialect,
                                                 sql_str_box_type           const SQL_str,
                                                 const RemoteFB__InMsg_v1*  const pInMsg,
                                                 const RemoteFB__OutMsg_v1* const pOutMsg)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pTrHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__ExecuteImmediate_M::exec";

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

 //-----------------------------------------
 const bool HasInParams
  =helpers::RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg(pInMsg)!=0;

 //-----------------------------------------
 const bool HasOutParams
  =helpers::RemoteFB__API_HLP__Msg_v1__Utilities::TestMsg(pOutMsg)!=0;

 //-----------------------------------------
 if(pData->GetPort()->TestPortFlag__lazy())
 {
  //поддержка "lazy_send" режима.

  //нам нужно освбодить/закрыть все зависшие ресурсы подключения.

  RemoteFB__P13_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);
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
      HasInParams?pInMsg:nullptr,
      HasOutParams?pOutMsg:nullptr); //throw
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
 RemoteFB__API_P13__ExecuteImmediate_M::helper__execute
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
 RemoteFB__API_P13__ExecuteImmediate_M::helper__execute2
                             (RemoteFB__P13__SrvOperation&     serverOperation,
                              RemoteFB__ConnectorData*   const pData,
                              tr_handle_type*            const pTrHandle,
                              protocol::P_USHORT         const SQL_dialect,
                              sql_str_box_type           const SQL_str,
                              const RemoteFB__InMsg_v1*  const pInMsg,
                              const RemoteFB__OutMsg_v1* const pOutMsg)
{
 assert(pData);
 assert(pTrHandle);

 //-----------------------------------------
 using stmt_data_type=handles::RemoteFB__HandleData_Statement;

 //-----------------------------------------
 stmt_data_type::msg_nulls_buffer_type
  InMsg_NULLS;

 stmt_data_type::msg_nulls_buffer_type
  OutMsg_NULLS;

 //-----------------------------------------
 const bool HasInParams=(pInMsg!=nullptr);

 const bool HasOutParams=(pOutMsg!=nullptr);

 assert(HasInParams || HasOutParams);

 //-----------------------------------------
 RemoteFB__OpSvc__StmtExecuteData_v2
  stmtExecuteData;

 if(HasInParams)
 {
  assert(pInMsg);
  assert(!pInMsg->blr.empty());
  assert(!pInMsg->data.empty());
  assert(!pInMsg->descrs.empty());

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_NULLS
   (pInMsg->descrs,
    pInMsg->data,
    InMsg_NULLS); //throw

  stmtExecuteData.InMsg_BLR=pInMsg->blr;

  stmtExecuteData.InMsg_DATA=pInMsg->data;

  stmtExecuteData.InMsg_DATA_DESCRS=pInMsg->descrs;

  stmtExecuteData.InMsg_NULLS=InMsg_NULLS;
 }//if HasInParams

 if(HasOutParams)
 {
  assert(pOutMsg);
  assert(!pOutMsg->blr.empty());
  assert(!pOutMsg->data.empty());
  assert(!pOutMsg->descrs.empty());

  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Alloc_XSQLDA_MSG_NULLS
   (pOutMsg->descrs,
    OutMsg_NULLS); //throw

  stmtExecuteData.OutMsg_BLR=pOutMsg->blr;

  stmtExecuteData.OutMsg_DATA=pOutMsg->data;

  stmtExecuteData.OutMsg_DATA_DESCRS=pOutMsg->descrs;

  stmtExecuteData.OutMsg_NULLS=OutMsg_NULLS;
 }//if HasOutParams

 //------
 //! \todo
 //!  Проверить состояние XVAR-элементов в pOutXSQLDA.
 //!  - указатели на данные
 //!  - указатели на индикаторы
 //!  - допустимость типов (нельзя запрашивать SQL_NULL)

 //-----------------------------------------
 const auto TrID
  =RemoteFB__P13__StmtHelper::ExecuteImmediate2
    (serverOperation,
     pData,
     pTrHandle,
     SQL_dialect,
     SQL_str,
     &stmtExecuteData);

 return TrID;
}//helper_execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
