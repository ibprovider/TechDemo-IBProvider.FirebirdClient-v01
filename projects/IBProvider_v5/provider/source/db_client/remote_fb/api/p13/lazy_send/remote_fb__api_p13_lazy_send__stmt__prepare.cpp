////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__stmt__prepare.cpp
//! \brief   Подготовка запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__api_p13_lazy_send__stmt__prepare.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__PrepareStatement

RemoteFB__API_P13_LAZY_SEND__PrepareStatement RemoteFB__API_P13_LAZY_SEND__PrepareStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__PrepareStatement::RemoteFB__API_P13_LAZY_SEND__PrepareStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__PrepareStatement::~RemoteFB__API_P13_LAZY_SEND__PrepareStatement()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__PrepareStatement::exec
                                           (db_obj::t_db_operation_context& OpCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            protocol::P_USHORT        const SQL_dialect,
                                            sql_str_box_type          const SQL_str,
                                            unsigned long*            const pStmtTypeID)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);
 assert(pStmtTypeID!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__PrepareStatement::exec";

 //-----------------------------------------
 (*pStmtTypeID)=0;

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- проверка дескриптора транзакции
 if(pTrHandle!=nullptr && (*pTrHandle)!=nullptr)
 {
  if(!(*pTrHandle)->m_ID.has_value())
  {
   assert(false);

   RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
    (c_bugcheck_src,
     L"#001");
  }//if

  pData->BugCheck__CheckTr
   (*pTrHandle,
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

 //-----------------------------------------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED))
 {
  //ERROR - у запроса висит незакрытый курсор.

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd__attempt_to_prepare_stmt_with_open_cursor_0);
 }//if

 assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

 //! \note
 //!  У запроса может быть отложенное закрытие курсора.

 //-----------------------------------------------------------------------
 //
 // Формально, запрос должен находится в закрытом состоянии. В противном случае,
 // сервер генерирует ошибку "The prepare statement identifies a prepare
 // statement with an open cursor".
 //
 // Но на текущий момент [2015-08-26] нет возможности определить у запроса
 // наличие открытого курсора. Все что мы можем сделать - это проверить,
 // что отсутствие FETCH-операций.
 //
 // Поэтому ограничимся номинальной проверкой в отладочной сборке.

 assert(!(*pStmtHandle)->m_spFetchResult);

 //-----------------------------------------------------------------------
 if((*pStmtHandle)->m_ID.is_defer())
 {
  //нам нужно будет "материализовать" новый дескриптор запроса.

  //освободим все ненужные ресурсы подключения

  RemoteFB__P13_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);

  //предыдущая операция не влияет на наш запрос.
  assert(pStmtHandle);
  assert(*pStmtHandle);
  assert((*pStmtHandle)->m_ID.is_defer());
 }//if (*pStmtHandle)->m_ID.is_defer()

 //-----------------------------------------------------------------------
 (*pStmtHandle)->ResetPrepareState();

 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

 assert(!(*pStmtHandle)->m_pParentTr);

 //-----------------------------------------------------------------------
 if((*pStmtHandle)->m_ID.is_defer())
 {
  self_type::helper__exec__allocate_and_prepare
   (serverOperation,
    pData,
    pTrHandle,
    *pStmtHandle,
    SQL_dialect,
    SQL_str);
 }
 else
 if((*pStmtHandle)->m_pClosingTr!=nullptr)
 {
  //у запроса висит отложенное закрытие курсора

  assert((*pStmtHandle)->m_ID.has_value());

  self_type::helper__exec__close_and_prepare
   (serverOperation,
    pData,
    pTrHandle,
    *pStmtHandle,
    SQL_dialect,
    SQL_str);
 }
 else
 {
  assert((*pStmtHandle)->m_ID.has_value());
  assert((*pStmtHandle)->m_pClosingTr==nullptr);

  self_type::helper__exec__prepare
   (serverOperation,
    pData,
    pTrHandle,
    *pStmtHandle,
    SQL_dialect,
    SQL_str);
 }//else

 //----------------------------------------- EXIT
 (*pStmtHandle)->m_PFlags.set(stmt_data_type::PFLAG__PREPARED);

 //-----------------------------------------
 assert(!(*pStmtHandle)->m_PData__StmtTypeID.null());

 (*pStmtTypeID)=(*pStmtHandle)->m_PData__StmtTypeID.value();
}//exec

//helper methods ---------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__PrepareStatement::helper__exec__prepare
                                           (RemoteFB__P13__SrvOperation&   serverOperation,
                                            RemoteFB__ConnectorData* const pData,
                                            tr_handle_type*          const pTrHandle,
                                            stmt_data_type*          const pStmt,
                                            protocol::P_USHORT       const SQL_dialect,
                                            sql_str_box_type         const SQL_str)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_ID.has_value());

 //случай с наличием отложенного закрытия обрабатывается отдельно
 assert(pStmt->m_pClosingTr==nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__PrepareStatement::helper__exec__prepare";

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_prepare_statement;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  RemoteFB__P13__StmtHelper::BuildPacket__op_prepare_statement
   (&packet,
    pTrHandle,
    pStmt->m_ID.get_value(),
    SQL_dialect,
    SQL_str);

  assert(packet.operation==c_OperationID);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   if(packet.p_resp.p_resp__object&protocol::P_STMT_BLOB)
   {
    //Пока не понятно когда такой случай возникает и что потом с ним делать.
    //Поэтому просто обработает как BUG-CHECK ошибку.

    //pStmt->m_PFlags.set(stmt_data_type::PFLAG__BLOB);

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#001",
      me_bug_check__unsupported_stmt_kind__BLOB_0)
   }//if STMT_BLOB

   if(packet.p_resp.p_resp__object&protocol::P_STMT_DEFER_EXECUTE)
   {
    pStmt->m_PFlags.set(stmt_data_type::PFLAG__DEFER_EXECUTE);
   }//if STMT_DEFER_EXECUTE

   //обработка информационного буфера
   api::helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf
    (pStmt,
     packet.p_resp.p_resp__data.cstr_length,
     packet.p_resp.p_resp__data.cstr_address);

   assert(!pStmt->m_PData__StmtTypeID.null());

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#002",
    packet.operation);
 }//for[ever]
}//helper__exec__prepare

//------------------------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__PrepareStatement::helper__exec__allocate_and_prepare
                                           (RemoteFB__P13__SrvOperation&   serverOperation,
                                            RemoteFB__ConnectorData* const pData,
                                            tr_handle_type*          const pTrHandle,
                                            stmt_data_type*          const pStmt,
                                            protocol::P_USHORT       const SQL_dialect,
                                            sql_str_box_type         const SQL_str)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_ID.is_defer());

 //отложенное закрытие отсутствует как класс
 assert(pStmt->m_pClosingTr==nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__PrepareStatement::helper__exec__allocate_and_prepare";

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID1=protocol::set02::op_allocate_statement;
 const protocol::set02::P_OP c_OperationID2=protocol::set02::op_prepare_statement;

 {
  //---------------------------------------- 2. build packet1
  protocol::set02::PACKET_V02 packet1;

  packet1.operation = c_OperationID1;

  //------------- p_rlse.p_rlse_object
  packet1.p_rlse.p_rlse__object=pData->GetPort()->m_ID.get_value();

  //---------------------------------------- 3. build packet2
  protocol::set02::PACKET_V02 packet2;

  RemoteFB__P13__StmtHelper::BuildPacket__op_prepare_statement
   (&packet2,
    pTrHandle,
    protocol::P_INVALID_OBJECT,
    SQL_dialect,
    SQL_str);

  assert(packet2.operation==c_OperationID2);

  //---------------------------------------- 4. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try // сторож сбоев работы с портом
  {
   pData->GetPort()->send_packet_with_delay
    (portOpCtx,
     packet1); //throw

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

 //----------------------------------------- 5. get response

 bool PortStateGuardIsActive=true;

 try // сторож сбоев работы с портом
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet1;
  protocol::set02::PACKET_V02 packet2;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet1); //throw

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet2); //throw

  //---------------------------------------- обработка первого ответа
  if(packet1.operation==protocol::set02::op_response)
  {
   isc_api::t_ibp_isc_status const allocateResultCode
    =pset02::RemoteFB__PSET02__ErrorUtilites::GetResultCode
      (pData,
       c_OperationID1,
       packet1.p_resp);

   if(allocateResultCode!=0)
   {
    //Из за баги с rem_port::port_last_object_id, вторая команда (op_prepare_statement)
    //cкорее всего обработала дескриптор предыдущего запроса.
    //
    //Так что переводим порт в недействительное состояние.

    //portStateGuard.complete();

    //по хорошему, нам надо было бы сохранить ошибку и посмотреть, что к нам
    //приехало во втором пакете.

    assert(PortStateGuardIsActive);

    //-----
    if(const t_ibp_error_element::self_ptr spErrRec
        =pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
         (pData,
          c_OperationID1,
          packet1.p_resp,
          E_FAIL))
    {
     t_ibp_error exc(spErrRec);

     exc.add_error(exc.com_code(),
                   ibp_subsystem__remote_fb__p13,
                   ibp_mce_cmd_alloc_SQL_stmt_0);

     exc.raise_me();
    }//else

    assert(PortStateGuardIsActive);

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#001",
      me_bug_check__we_expected_the_error_0);
   }//if

   assert(packet1.p_resp.p_resp__object!=protocol::P_INVALID_OBJECT);

   //запоминаем идентификатор дескриптора запроса
   pStmt->m_ID.set_value(&packet1.p_resp.p_resp__object);
  }
  else
  {
   //ERROR - [BUG CHECK] unexpected answer from server

   assert(packet1.operation!=protocol::set02::op_response);

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pData->GetPort(),
     c_bugcheck_src,
     L"#002",
     packet1.operation);
  }//else

  //---------------------------------------- обработка второго ответа
  if(packet2.operation==protocol::set02::op_response)
  {
   //в данной точке мы можем уже быть уверены, что порт находится в согласованном состоянии
   PortStateGuardIsActive=false;

   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID2,
     packet2.p_resp,
     E_FAIL); //throw

   if(packet2.p_resp.p_resp__object&protocol::P_STMT_BLOB)
   {
    //Пока не понятно когда такой случай возникает и что потом с ним делать.
    //Поэтому просто обработает как BUG-CHECK ошибку.

    //pStmt->m_PFlags.set(stmt_data_type::PFLAG__BLOB);

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#003",
      me_bug_check__unsupported_stmt_kind__BLOB_0)
   }//if STMT_BLOB

   if(packet2.p_resp.p_resp__object&protocol::P_STMT_DEFER_EXECUTE)
   {
    pStmt->m_PFlags.set(stmt_data_type::PFLAG__DEFER_EXECUTE);
   }//if STMT_DEFER_EXECUTE

   //обработка информационного буфера
   api::helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf
    (pStmt,
     packet2.p_resp.p_resp__data.cstr_length,
     packet2.p_resp.p_resp__data.cstr_address);

   assert(!pStmt->m_PData__StmtTypeID.null());
  }//if - protocol::op_response
  else
  {
   //ERROR - [BUG CHECK] unexpected answer from server

   assert(packet2.operation!=protocol::set02::op_response);

   assert(PortStateGuardIsActive);

   PortStateGuardIsActive=false;

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pData->GetPort(),
     c_bugcheck_src,
     L"#004",
     packet2.operation);
  }//else
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
}//helper__exec__allocate_and_prepare

//------------------------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__PrepareStatement::helper__exec__close_and_prepare
                                           (RemoteFB__P13__SrvOperation&   serverOperation,
                                            RemoteFB__ConnectorData* const pData,
                                            tr_handle_type*          const pTrHandle,
                                            stmt_data_type*          const pStmt,
                                            protocol::P_USHORT       const SQL_dialect,
                                            sql_str_box_type         const SQL_str)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_ID.has_value());

 assert(pStmt->m_pClosingTr!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__PrepareStatement::helper__exec__close_and_prepare";

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID1__close   =protocol::set02::op_free_statement;
 const protocol::set02::P_OP c_OperationID2__prepare =protocol::set02::op_prepare_statement;

 {
  //---------------------------------------- 2. build packet1
  protocol::set02::PACKET_V02 packet1__close;

  packet1__close.operation = c_OperationID1__close;

  //------------- p_sqlfree__statement
  packet1__close.p_sqlfree.p_sqlfree__statement=pStmt->m_ID.get_value();

  //------------- p_sqlfree__option
  packet1__close.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;

  //---------------------------------------- 3. build packet2
  protocol::set02::PACKET_V02 packet2__prepare;

  RemoteFB__P13__StmtHelper::BuildPacket__op_prepare_statement
   (&packet2__prepare,
    pTrHandle,
    pStmt->m_ID.get_value(),
    SQL_dialect,
    SQL_str);

  assert(packet2__prepare.operation==c_OperationID2__prepare);

  //---------------------------------------- 4. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try // сторож сбоев работы с портом
  {
   pData->GetPort()->send_packet_with_delay
    (portOpCtx,
     packet1__close); //throw

   pData->GetPort()->send_packet
    (portOpCtx,
     packet2__prepare); //throw
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//catch

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 5. get response

 bool PortStateGuardIsActive=true;

 try // сторож сбоев работы с портом
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet1__close;
  protocol::set02::PACKET_V02 packet2__prepare;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet1__close); //throw

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet2__prepare); //throw

  //----------------------------------------
  t_ibp_error Errors(S_OK); //no throw

  //---------------------------------------- обработка первого ответа
  bool close_was_failed=false;

  if(packet1__close.operation==protocol::set02::op_response)
  {
   //Проверям ошибку
   const t_ibp_error_element::self_ptr
    spErrRec(pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
               (pData,
                c_OperationID1__close,
                packet1__close.p_resp,
                E_FAIL)); //throw

   if(spErrRec)
   {
    close_was_failed=true;

    Errors.add_error
     (spErrRec); //throw

    Errors.add_error
     (spErrRec->m_err_code,
      ibp_subsystem__remote_fb__p13,
      ibp_mce_cmd_close_stmt_0);
   }
   else
   {
    //завершаем отложенное закрытие курсора
    assert(pStmt->m_pClosingTr);

    pStmt->Dangerous__CloseCursorOfClosingTr();

    assert(!pStmt->m_pClosingTr);
   }//if
  }
  else
  {
   //ERROR - [BUG CHECK] unexpected answer from server

   assert(packet1__close.operation!=protocol::set02::op_response);

   assert(PortStateGuardIsActive);

   PortStateGuardIsActive=false;

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pData->GetPort(),
     c_bugcheck_src,
     L"#001",
     packet1__close.operation);
  }//else

  //---------------------------------------- обработка второго пакета
  if(packet2__prepare.operation==protocol::set02::op_response)
  {
   //в данной точке мы можем уже быть уверены, что порт находится в согласованном состоянии
   PortStateGuardIsActive=false;

   //Проверям ошибку
   const t_ibp_error_element::self_ptr
    spErrRec(pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
               (pData,
                c_OperationID2__prepare,
                packet2__prepare.p_resp,
                E_FAIL)); //throw

   if(spErrRec)
   {
    Errors.add_error(spErrRec);

    //! \todo
    //!  Объявить текущую ошибку в качестве основной

    //указываем код первой ошибки
    DEBUG_CODE(size_t const debug_curErrCount=Errors.get_record_count());

    assert(debug_curErrCount>0);

    Errors=IBP_MapErrorRecordToHRESULT(Errors.get_record(0));

    assert(FAILED(Errors.com_code()));

    //количество описаний ошибки не должно измениться
    assert(Errors.get_record_count()==debug_curErrCount);

    //и выкидываем исключение
    Errors.raise_me();
   }//if spErrRec

   //запрос был подготовлен без ошибок
   assert(!spErrRec);

   //значит его курсор находится в закрытом состоянии
   if(close_was_failed)
    pStmt->Dangerous__CloseCursorOfClosingTr();

   assert(pStmt->m_pClosingTr==nullptr);

   //-------
   if(packet2__prepare.p_resp.p_resp__object&protocol::P_STMT_BLOB)
   {
    //Пока не понятно когда такой случай возникает и что потом с ним делать.
    //Поэтому просто обработает как BUG-CHECK ошибку.

    //pStmt->m_PFlags.set(stmt_data_type::PFLAG__BLOB);

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#002",
      me_bug_check__unsupported_stmt_kind__BLOB_0)
   }//if STMT_BLOB

   if(packet2__prepare.p_resp.p_resp__object&protocol::P_STMT_DEFER_EXECUTE)
   {
    pStmt->m_PFlags.set(stmt_data_type::PFLAG__DEFER_EXECUTE);
   }//if STMT_DEFER_EXECUTE

   //------------

   //обработка информационного буфера
   api::helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf
    (pStmt,
     packet2__prepare.p_resp.p_resp__data.cstr_length,
     packet2__prepare.p_resp.p_resp__data.cstr_address);

   assert(!pStmt->m_PData__StmtTypeID.null());
  }
  else
  {
   //ERROR - [BUG CHECK] unexpected answer from server

   assert(packet2__prepare.operation!=protocol::set02::op_response);

   assert(PortStateGuardIsActive);

   PortStateGuardIsActive=false;

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pData->GetPort(),
     c_bugcheck_src,
     L"#003",
     packet2__prepare.operation);
  }//else
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
}//helper__exec__close_and_prepare

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
