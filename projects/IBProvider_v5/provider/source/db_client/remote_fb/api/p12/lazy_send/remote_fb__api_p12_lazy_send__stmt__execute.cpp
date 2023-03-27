////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__execute.cpp
//! \brief   Выполнение запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    28.10.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__api_p12_lazy_send__stmt__execute.h"
#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__p12_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__xsqlda_utilities.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_pointer_cast.h>

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
  IBP_ThrowSimpleError
   (DB_E_NOTPREPARED,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd_not_prepared_0);
 }//if

 assert((*pStmtHandle)->m_ID.has_value());

 //-----------------------------------------
 bool HasInParams=false;

 if(pInXSQLDA!=nullptr)
 {
  if(pInXSQLDA->version!=pInXSQLDA->c_version_num)
  {
   RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
    (c_bugcheck_src,
     L"#006",
     L"pInXSQLDA",
     pInXSQLDA->version);
  }//if

  if(pInXSQLDA->sqld<0)
  {
   //ERROR - [BUG CHECK] incorrect input XSQLDA::sqld

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
    (ibp_subsystem__remote_fb__p12,
     L"pInXSQLDA",
     pInXSQLDA->sqld);
  }//if

  if(pInXSQLDA->sqln<pInXSQLDA->sqld)
  {
   //ERROR - [BUG CHECK] incorrect input XSQLDA::sqln

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
    (ibp_subsystem__remote_fb__p12,
     L"pInXSQLDA",
     pInXSQLDA->sqln,
     pInXSQLDA->sqld);
  }//if

  //----
  HasInParams=(pInXSQLDA->sqld>0);
 }//if pInXSQLDA

 //-----------------------------------------
 bool HasOutParams=false;

 if(pOutXSQLDA!=nullptr)
 {
  if(pOutXSQLDA->version!=pOutXSQLDA->c_version_num)
  {
   RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
    (c_bugcheck_src,
     L"#007",
     L"pOutXSQLDA",
     pOutXSQLDA->version);
  }//if

  if(pOutXSQLDA->sqld<0)
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

  HasOutParams=(pOutXSQLDA->sqld>0);
 }//if pOutXSQLDA

 //-----------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED))
 {
  //ERROR - [BUG CHECK] повторное выполнение отложенного запроса.
  //Скорее всего не был закрыт курсор.

  IBP_ThrowSimpleError
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

 if(!HasOutParams)
 {
  TrID=helper__execute(serverOperation,
                       pData,
                       pTrHandle,
                       pStmtHandle,
                       pInXSQLDA); //throw
 }
 else
 {
  TrID=helper__execute2(serverOperation,
                        pData,
                        pTrHandle,
                        pStmtHandle,
                        pInXSQLDA,
                        pOutXSQLDA); //throw
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
protocol::P_USHORT RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::helper__execute
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
 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::helper__execute";

 //-----------------------------------------
 RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_BLR
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_BLR); //throw

 assert((pInXSQLDA==nullptr || pInXSQLDA->sqld==0)==((*pStmtHandle)->m_InParams__MSG_BLR.empty()));

 RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_DATA);

 //-----------------------------------------
 if((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE))
 {
  if(!pTrHandle || !(*pTrHandle))
  {
   //запросы с отложенным выполнением должны выполняться в рамках транзакции

   //такие запросы выполняются при фетче, а фетч требует транзакцию.

   //В отладочной сборке сразу остановим выполнение программы.
   assert(false);

   IBP_ThrowSimpleError
    (E_FAIL,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_cmd__stmt_with_defer_exec_requires_tr_context_0);
  }//if - не указана транзакция

  assert(pTrHandle);
  assert((*pTrHandle));
  assert((*pTrHandle)->m_ID.has_value());

  //отложенное выполнение запроса
  (*pStmtHandle)->m_EFlags.set(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED);

  return (*pTrHandle)->m_ID.get_value();
 }//if (*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE)

 assert(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE));

 //-----------------------------------------------------------------------

 //[2015-11-15]
 // У нас может висеть невыполненная операция закрытия курсора.
 // IBProvider на текущий момент выполняет эту операцию без учета типа запроса.
 // В будущем, предлагаю в отладочной сборке ругаться на этот беспредел.

 bool send_op1_close=false;

 if((*pStmtHandle)->m_pClosingTr!=nullptr)
 {
  //нужно отправить команду на закрытие курсора.

  //[2015-11-15] Раскомментировать следующий ассерт!
  assert_msg(false,"stmtType="<<(*pStmtHandle)->m_StmtTypeID.value_or_default(structure::negative_one));

  send_op1_close=true;
 }//if

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID1=protocol::set01::op_free_statement;
 const protocol::set01::P_OP c_OperationID2=protocol::set01::op_execute;

 {
  //---------------------------------------- 2. build packets
  protocol::set01::PACKET_V01 packet1;
  protocol::set01::PACKET_V01 packet2;

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
   RemoteFB__P12__StmtHelper::BuildPacket__op_execute
    (&packet2,
     pTrHandle?*pTrHandle:nullptr,
     *pStmtHandle);

   assert(packet2.operation==c_OperationID2);
  }//build packet2

  //---------------------------------------- 3. send packets
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc((*pStmtHandle).ptr());

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try //сторож сбоев работы с портом
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

   assert(false);
  }//catch

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get responses
 protocol::P_OBJCT TrID=0;

 t_ibp_error Errors(E_FAIL);

 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet1;
  protocol::set01::PACKET_V01 packet2;

  try //сторож сбоев работы с портом
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

   assert(false);
  }//catch

  //все пакеты с ответами получены. состояние порта стабилизировано.

  //---------------------------------------- обработка ответа CLOSE
  bool close_was_failed=false;

  if(send_op1_close)
  {
   if(packet1.operation==protocol::set01::op_response)
   {
    assert((*pStmtHandle)->m_pClosingTr);

    if(const t_ibp_error_element::self_ptr
       spErrRec=pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
        (pData,
         c_OperationID1,
         packet1.p_resp,
         E_FAIL))
    { 
     // [2015-11-15] Я не знаю как протестировать данную ошибку.

     close_was_failed=true;

     Errors.add_error
      (spErrRec); //throw

     //дополнительная информация о сбое.
     Errors.add_error
      (spErrRec->m_err_code,
       ibp_subsystem__remote_fb__p12,
       ibp_mce_cmd_close_stmt_0);
    }
    else
    {
     //операция была выполнена без ошибок.

     //Кстати, FB 2.5.5 не ругается на закрытие кусора для (к примеру) "INSERT" запроса.
     //Вообще, это весьма странно.

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

    assert(false);
   }//else
  }//if send_op1_close

  //---------------------------------------- обработка ответа EXECUTE
  if(packet2.operation==protocol::set01::op_response)
  {
   if(const t_ibp_error_element::self_ptr
      spErrRec=pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
       (pData,
        c_OperationID2,
        packet2.p_resp,
        E_FAIL))
   {
    Errors.add_error(spErrRec);

    //делаем ошибку выполнения запроса основной
    Errors.set_last_error_as_primary();

    Errors=spErrRec->m_err_code;

    //----
    Errors.raise_me();
   }//if

   if(close_was_failed)
   {
    //раз запрос выполнился без проблем, то проигнорируем ошибку закрытия курсора.

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

   assert(false);
  }//else
 }//local

 return TrID;
}//helper__execute

//------------------------------------------------------------------------
protocol::P_OBJCT RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::helper__execute2
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
 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

 assert(pOutXSQLDA!=nullptr);
 assert(pOutXSQLDA->sqld>0);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_LAZY_SEND__ExecuteStatement::helper__execute2";

 //-----------------------------------------
 if((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE))
 {
  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#000",
    me_bug_check__defer_execution_of_stmt_with_out_params_not_supported_0);
 }//if

 assert(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE));

 //-----------------------------------------------------------------------

 //[2015-11-15]
 // У нас может висеть невыполненная операция закрытия курсора.
 // IBProvider на текущий момент выполняет эту операцию без учета типа запроса.
 // В будущем, предлагаю в отладочной сборке ругаться на этот беспредел.

 bool send_op1_close=false;

 if((*pStmtHandle)->m_pClosingTr!=nullptr)
 {
  //нужно отправить команду на закрытие курсора.

  //[2015-11-15] Раскомментировать следующий ассерт!
  //[2016-10-08] Аминь
  assert_msg(false,"stmtType="<<(*pStmtHandle)->m_StmtTypeID.value_or_default(structure::negative_one));

  //! \todo
  //!  [2016-10-10] Предлагаю выкидывать BUG-CHECK ошибку

  send_op1_close=true;
 }//if

 //-----------------------------------------
 RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_BLR
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_BLR); //throw

 assert((pInXSQLDA==nullptr || pInXSQLDA->sqld==0)==((*pStmtHandle)->m_InParams__MSG_BLR.empty()));

 RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_DATA);

 RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_BLR
  (pOutXSQLDA,
   (*pStmtHandle)->m_OutParams__MSG_BLR); //throw

 assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

 RemoteFB__P12__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA_DESCRS
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
 const protocol::set01::P_OP c_OperationID1=protocol::set01::op_free_statement;
 const protocol::set01::P_OP c_OperationID2=protocol::set01::op_execute2;

 {
  //---------------------------------------- 2. build packets
  protocol::set01::PACKET_V01 packet1;
  protocol::set01::PACKET_V01 packet2;

  //---------------------------------------- 2.1 build packet1 CLOSE
  if(send_op1_close)
  {
   packet1.operation = c_OperationID1;

   //----- p_sqlfree__statement
   packet1.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

   //----- p_sqlfree__option
   packet1.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;
  }//if send_op1_close

  //---------------------------------------- 2.2 build packet2 EXECUTE2
  {
   packet2.operation = c_OperationID2;

   //---------------------------------------- p_sqldata_statement
   packet2.p_sqldata.p_sqldata__statement=(*pStmtHandle)->m_ID.get_value();

   //---------------------------------------- p_sqldata_transaction
   packet2.p_sqldata.p_sqldata__transaction=(*pTrHandle)?(*pTrHandle)->m_ID.get_value():0;

   //---------------------------------------- p_sqldata_blr
   if(!structure::can_numeric_cast(&packet2.p_sqldata.p_sqldata__blr.cstr_length,
                                   (*pStmtHandle)->m_InParams__MSG_BLR.size()))
   {
    //ERROR - BLR data of input parameters is too long.

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_subsystem__remote_fb__p12,
      ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
      L"pInXSQLDA",
      (*pStmtHandle)->m_InParams__MSG_BLR.size(),
      structure::get_numeric_limits(packet2.p_sqldata.p_sqldata__blr.cstr_length).max_value());
   }//if

   structure::static_numeric_cast
    (&packet2.p_sqldata.p_sqldata__blr.cstr_length,
     (*pStmtHandle)->m_InParams__MSG_BLR.size());

   packet2.p_sqldata.p_sqldata__blr.cstr_address=(*pStmtHandle)->m_InParams__MSG_BLR.buffer();

   //---------------------------------------- p_sqldata_message_number
   packet2.p_sqldata.p_sqldata__message_number=0;

   //---------------------------------------- p_sqldata_messages + p_sqldata_message_data
   packet2.p_sqldata.p_sqldata__messages=(*pStmtHandle)->m_InParams__MSG_BLR.empty()?0:1;

   //--------------------------------------- p_sqldata_out_blr [op_execute2]
   if(!structure::can_numeric_cast(&packet2.p_sqldata.p_sqldata__out_blr.cstr_length,
                                    (*pStmtHandle)->m_OutParams__MSG_BLR.size()))
   {
    //ERROR - BLR data of output parameters is too long.

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_subsystem__remote_fb__p12,
      ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
      L"pOutXSQLDA",
      (*pStmtHandle)->m_OutParams__MSG_BLR.size(),
      structure::get_numeric_limits(packet2.p_sqldata.p_sqldata__blr.cstr_length).max_value());
   }//if

   structure::static_numeric_cast
    (&packet2.p_sqldata.p_sqldata__out_blr.cstr_length,
     (*pStmtHandle)->m_OutParams__MSG_BLR.size());

   packet2.p_sqldata.p_sqldata__out_blr.cstr_address=(*pStmtHandle)->m_OutParams__MSG_BLR.buffer();

   //--------------------------------------- p_sqldata_out_message_number [op_execute2]
   packet2.p_sqldata.p_sqldata__out_message_number=0;
  }//local - build packet2

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc((*pStmtHandle).ptr());

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try //сторож сбоев работы с портом
  {
   if(send_op1_close)
   {
    pData->GetPort()->send_packet
     (portOpCtx,
      packet1); //throw
   }//if send_op1_close

   pData->GetPort()->send_packet
    (portOpCtx,
     packet2); //throw
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//catch

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get responses
#ifdef NDEBUG
 protocol::P_OBJCT TrID=0;
#else
 structure::t_value_with_null<protocol::P_OBJCT> TrID;
#endif

 //флаг активности сторожа сбоев порта
 bool PortStateGuardIsActive=true;

 try // сторож сбоев работы с портом
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc((*pStmtHandle).ptr());

  //----------------------------------------- 4.1 get response1 - CLOSE
  t_ibp_error Errors(E_FAIL);

  bool close_was_failed=false;

  if(send_op1_close)
  {
   protocol::set01::PACKET_V01 packet1;

   pData->GetPort()->receive_packet(portOpCtx,packet1);//throw

   if(packet1.operation==protocol::set01::op_response)
   {
    assert((*pStmtHandle)->m_pClosingTr);

    if(const t_ibp_error_element::self_ptr
       spErrRec=pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
        (pData,
         c_OperationID1,
         packet1.p_resp,
         E_FAIL))
    {
     // [2015-11-15] Я не знаю как протестировать данную ошибку.

     close_was_failed=true;

     Errors.add_error
      (spErrRec); //throw

     //дополнительная информация о сбое.
     Errors.add_error
      (spErrRec->m_err_code,
       ibp_subsystem__remote_fb__p12,
       ibp_mce_cmd_close_stmt_0);
    }
    else
    {
     //операция была выполнена без ошибок.

     //Кстати, FB 2.5.5 не ругается на закрытие кусора для (к примеру) "INSERT" запроса.
     //Вообще, это весьма странно.

     (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
    }//else
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    //отключаем нашего сторожа от порта.
    PortStateGuardIsActive=false;

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#001",
      packet1.operation);

    assert(false);
   }//else
  }//send_op1_close

  //----------------------------------------- 4.2 get response2
  protocol::P_USHORT cOutMessages=0;

  {
   protocol::set01::PACKET_V01 packet2;

   pData->GetPort()->receive_packet
    (portOpCtx,
     packet2); //throw

   if(packet2.operation==protocol::set01::op_sql_response)
   {
    //обработка ответа от сервера

    cOutMessages=packet2.p_sqldata.p_sqldata__messages;

    //отсутствие или одно OUT-сообщение
    assert_msg(cOutMessages<2,"cOutMessages: "<<cOutMessages);
   }//if
   else//Ожидается ошибка выполнения запроса
   if(packet2.operation==protocol::set01::op_response)
   {
    if(const t_ibp_error_element::self_ptr spErrRec
        =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
          (pData,
           c_OperationID2,
           packet2.p_resp,
           E_FAIL)) //throw
    {
     //будем считать, что состояние порта стаблизировалось. все пакеты с ответом получены.
     PortStateGuardIsActive=false;

     Errors.add_error(spErrRec);

     //делаем ошибку выполнения запроса основной
     Errors.set_last_error_as_primary();

     Errors=spErrRec->m_err_code;

     //----
     Errors.raise_me();
    }//if spErrRec

    //ERROR - [BUG CHECK] Неожиданный ответ от сервера. Ожидалась ошибка.

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#002",
      me_bug_check__we_expected_the_error_0);

    assert(false);
   }//if - protocol::op_response
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    //отключаем нашего сторожа от порта.
    PortStateGuardIsActive=false;

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#003",
      packet2.operation);
   }//else
  }//local

  //----------------------------------------- 4.3 get response3
  {
   protocol::set01::PACKET_V01 packet3;

   pData->GetPort()->receive_packet
    (portOpCtx,
     packet3); //throw

   //состояние порта стаблизировано. получены все пакеты.
   PortStateGuardIsActive=false;

   if(packet3.operation==protocol::set01::op_response)
   {
    if(const t_ibp_error_element::self_ptr spErrRec
        =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
          (pData,
           c_OperationID2,
           packet3.p_resp,
           E_FAIL)) //throw
    {
     Errors.add_error(spErrRec);

     //делаем ошибку выполнения запроса основной
     Errors.set_last_error_as_primary();

     Errors=spErrRec->m_err_code;

     //----
     Errors.raise_me();
    }//if spErrRec

    //все нормально - запрос выполнился без ошибок.

    if(close_was_failed)
    {
     assert((*pStmtHandle)->m_pClosingTr);

     //принудительно закрываем курсор запроса
     (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
    }//if

    assert((*pStmtHandle)->m_pClosingTr==nullptr);

    TrID=packet3.p_resp.p_resp__object;
   }//if - protocol::op_response
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#004",
      packet3.operation);
   }//else
  }//local

  //-----------------------------------------
  if(cOutMessages!=1)
  {
   //ERROR - [BUG CHECK] Некорректное число OUT-результатов.

   structure::wstr_formatter freason(L"Unexpected count of OUT-results: %1");

   freason<<cOutMessages;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#005",
     freason.c_str());
  }//if

  //Сохраняем полученные результаты в pOutXSQLDA

  try
  {
   RemoteFB__P12__XSQLDA_Utilities::Parse_XSQLDA_MSG_DATA
      ((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
       (*pStmtHandle)->m_OutParams__MSG_DATA.size(),
       (*pStmtHandle)->m_OutParams__MSG_DATA.buffer(),
        pOutXSQLDA);
  }
  catch(const std::exception& e)
  {
   t_ibp_error exc(e);

   //Добавляем информацию о текущей операции (установка значений OUT-параметров)

   //Как протестировать этот обработчик - непонятно.

   exc.add_error
    (E_FAIL,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_isc__failed_to_set_xsqlda_xvalues_1);

   exc<<L"pOutXSQLDA";

   exc.raise_me();
  }//catch
 }
 catch(...)
 {
  if(PortStateGuardIsActive)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//if

  throw;
 }//catch

 assert(!TrID.null());

 return TrID DEBUG_CODE(.value());
}//helper__execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
