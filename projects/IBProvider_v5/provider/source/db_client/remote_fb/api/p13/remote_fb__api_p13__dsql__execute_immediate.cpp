////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api
//! \file    remote_fb__api_p13__dsql__execute_immediate.cpp
//! \brief   Немедленное выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    23.06.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ExecuteImmediate

RemoteFB__API_P13__ExecuteImmediate RemoteFB__API_P13__ExecuteImmediate::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__ExecuteImmediate::RemoteFB__API_P13__ExecuteImmediate()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__ExecuteImmediate::~RemoteFB__API_P13__ExecuteImmediate()
{;}

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
  if(pInXSQLDA->version!=pInXSQLDA->c_version_num)
  {
   RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
    (c_bugcheck_src,
     L"#003",
     L"pInXSQLDA",
     pInXSQLDA->version);
  }//if

  if(pInXSQLDA->sqld<0)
  {
   //ERROR - [BUG CHECK] incorrect input XSQLDA::sqld

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
    (ibp_subsystem__remote_fb__p13,
     L"pInXSQLDA",
     pInXSQLDA->sqld);
  }//if

  if(pInXSQLDA->sqln<pInXSQLDA->sqld)
  {
   //ERROR - [BUG CHECK] incorrect input XSQLDA::sqln

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
    (ibp_subsystem__remote_fb__p13,
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
     L"#004",
     L"pOutXSQLDA",
     pOutXSQLDA->version);
  }//if

  if(pOutXSQLDA->sqld<0)
  {
   //ERROR - [BUG CHECK] incorrect output XSQLDA::sqld

   assert_msg(false,"pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
    (ibp_subsystem__remote_fb__p13,
     L"pOutXSQLDA",
     pOutXSQLDA->sqld);
  }//if

  if(pOutXSQLDA->sqln<pOutXSQLDA->sqld)
  {
   //ERROR - [BUG CHECK] incorrect output XSQLDA::sqln

   assert_msg(false,"pOutXSQLDA->sqln: "<<pOutXSQLDA->sqln<<". pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
    (ibp_subsystem__remote_fb__p13,
     L"pOutXSQLDA",
     pOutXSQLDA->sqln,
     pOutXSQLDA->sqld);
  }//if

  HasOutParams=(pOutXSQLDA->sqld>0);
 }//if pOutXSQLDA

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
  TrID=helper__execute2(serverOperation,
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

  TrID=helper__execute(serverOperation,
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
protocol::P_OBJCT RemoteFB__API_P13__ExecuteImmediate::helper__execute
                             (RemoteFB__P13__SrvOperation&    serverOperation,
                              RemoteFB__ConnectorData*  const pData,
                              tr_handle_type*           const pTrHandle,
                              protocol::P_USHORT        const SQL_dialect,
                              sql_str_box_type          const SQL_str)
{
 assert(pTrHandle);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__ExecuteStatement::helper__execute";

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_exec_immediate;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqlst__transaction
  assert(packet.p_sqlst.p_sqlst__transaction==0);

  if(pTrHandle && (*pTrHandle))
  {
   assert((*pTrHandle)->m_ID.has_value());

   packet.p_sqlst.p_sqlst__transaction=(*pTrHandle)->m_ID.get_value();
  }//if

  //---------------------------------------- p_sqlst__statement
  assert(packet.p_sqlst.p_sqlst__statement==0);

  //---------------------------------------- p_sqlst__SQL_dialect
  packet.p_sqlst.p_sqlst__SQL_dialect=SQL_dialect;

  //---------------------------------------- p_sqlst__SQL_str
  CHECK_READ_TYPED_PTR(SQL_str.ptr,SQL_str.len);

  if(!structure::can_numeric_cast(&packet.p_sqlst.p_sqlst__SQL_str.cstr_length,
                                  SQL_str.len))
  {
   //ERROR - too large sql text

   t_ibp_error exc(E_FAIL,
                   ibp_subsystem__remote_fb__p13,
                   ibp_mce_cmd_stmt_too_long_2);

   exc<<SQL_str.len
      <<structure::get_numeric_limits(packet.p_sqlst.p_sqlst__SQL_str.cstr_length).max_value();

   exc.raise_me();
  }//if

  structure::static_numeric_cast(&packet.p_sqlst.p_sqlst__SQL_str.cstr_length,
                                 SQL_str.len);

  assert_s(sizeof(*packet.p_sqlst.p_sqlst__SQL_str.cstr_address)==sizeof(*SQL_str.ptr));

  structure::reinterpret_ptr_cast
   (&packet.p_sqlst.p_sqlst__SQL_str.cstr_address,
    SQL_str.ptr);

  //---------------------------------------- p_sqlst__buffer_length
  assert(packet.p_sqlst.p_sqlst__buffer_length==0);

  //---------------------------------------- p_sqlst__items
  assert(packet.p_sqlst.p_sqlst__items.cstr_length==0);

  assert(packet.p_sqlst.p_sqlst__items.cstr_address==nullptr);

  //---------------------------------------- p_sqlst__blr
  assert(packet.p_sqlst.p_sqlst__blr.cstr_length==0);

  assert(packet.p_sqlst.p_sqlst__blr.cstr_address==nullptr);

  //---------------------------------------- p_sqlst__message_number
  assert(packet.p_sqlst.p_sqlst__message_number==0);

  //---------------------------------------- p_sqlst__messages
  assert(packet.p_sqlst.p_sqlst__messages==0);

  //---------------------------------------- p_sqlst__out_blr
  assert(packet.p_sqlst.p_sqlst__out_blr.cstr_length==0);

  assert(packet.p_sqlst.p_sqlst__out_blr.cstr_address==nullptr);

  //---------------------------------------- p_sqlst__out_message_number
  assert(packet.p_sqlst.p_sqlst__out_message_number==0);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet(portOpCtx,
                                packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response
 protocol::P_OBJCT TrID=0;

 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet(portOpCtx,
                                   packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   TrID=packet.p_resp.p_resp__object;

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#001",
    packet.operation);
 }//for[ever]

 return TrID;
}//helper_execute

//------------------------------------------------------------------------
protocol::P_OBJCT RemoteFB__API_P13__ExecuteImmediate::helper__execute2
                             (RemoteFB__P13__SrvOperation&    serverOperation,
                              RemoteFB__ConnectorData*  const pData,
                              tr_handle_type*           const pTrHandle,
                              protocol::P_USHORT        const SQL_dialect,
                              sql_str_box_type          const SQL_str,
                              const isc_api::XSQLDA_V1* const pInXSQLDA,
                              const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pTrHandle);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__ExecuteStatement::helper__execute2";

 //-----------------------------------------
 typedef handles::RemoteFB__HandleData_Statement stmt_data_type;

 const stmt_data_type::self_ptr spStmt(stmt_data_type::Create());

 assert(spStmt);

 //-----------------------------------------
 const bool HasInParams=pInXSQLDA && (pInXSQLDA->sqld>0);

 const bool HasOutParams=pOutXSQLDA && (pOutXSQLDA->sqld>0);

 assert(HasInParams || HasOutParams);

 //-----------------------------------------
 RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_BLR(pInXSQLDA,spStmt->m_InParams__MSG_BLR); //throw

 assert(HasInParams==!spStmt->m_InParams__MSG_BLR.empty());

 RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA(pInXSQLDA,spStmt->m_InParams__MSG_DATA);

 size_t unused__InParams_MsgDataSize=0;
 size_t unused__InParams_MsgDataAlign=0;

 RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA_DESCRS
  (pInXSQLDA,
   spStmt->m_InParams__MSG_DATA_DESCRS,
   &unused__InParams_MsgDataSize,
   &unused__InParams_MsgDataAlign); //throw

 RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_NULLS(pInXSQLDA,spStmt->m_InParams__MSG_NULLS);

 //------
 RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_BLR(pOutXSQLDA,spStmt->m_OutParams__MSG_BLR); //throw

 assert(HasOutParams==!spStmt->m_OutParams__MSG_BLR.empty());

 RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA_DESCRS
  (pOutXSQLDA,
   spStmt->m_OutParams__MSG_DATA_DESCRS,
   &spStmt->m_OutParams__MSG_DATA_SIZE,
   &spStmt->m_OutParams__MSG_DATA_ALIGN); //throw

 spStmt->m_OutParams__MSG_DATA.alloc(spStmt->m_OutParams__MSG_DATA_SIZE);

 RemoteFB__P13__XSQLDA_Utilities::Alloc_XSQLDA_MSG_NULLS(pOutXSQLDA,spStmt->m_OutParams__MSG_NULLS);

 //! \todo
 //!  Проверить состояние XVAR-элементов в pOutXSQLDA.
 //!  - указатели на данные
 //!  - указатели на индикаторы
 //!  - допустимость типов (нельзя запрашивать SQL_NULL)

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_exec_immediate2;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqlst__transaction
  assert(packet.p_sqlst.p_sqlst__transaction==0);

  if(pTrHandle && (*pTrHandle))
  {
   assert((*pTrHandle)->m_ID.has_value());

   packet.p_sqlst.p_sqlst__transaction=(*pTrHandle)->m_ID.get_value();
  }//if

  //---------------------------------------- p_sqlst__statement
  assert(packet.p_sqlst.p_sqlst__statement==0);

  //---------------------------------------- p_sqlst__SQL_dialect
  packet.p_sqlst.p_sqlst__SQL_dialect=SQL_dialect;

  //---------------------------------------- p_sqlst__SQL_str
  CHECK_READ_TYPED_PTR(SQL_str.ptr,SQL_str.len);

  if(!structure::can_numeric_cast(&packet.p_sqlst.p_sqlst__SQL_str.cstr_length,
                                  SQL_str.len))
  {
   //ERROR - too large sql text

   t_ibp_error exc(E_FAIL,
                   ibp_subsystem__remote_fb__p13,
                   ibp_mce_cmd_stmt_too_long_2);

   exc<<SQL_str.len
      <<structure::get_numeric_limits(packet.p_sqlst.p_sqlst__SQL_str.cstr_length).max_value();

   exc.raise_me();
  }//if

  structure::static_numeric_cast(&packet.p_sqlst.p_sqlst__SQL_str.cstr_length,
                                 SQL_str.len);

  assert_s(sizeof(*packet.p_sqlst.p_sqlst__SQL_str.cstr_address)==sizeof(*SQL_str.ptr));

  structure::reinterpret_ptr_cast
   (&packet.p_sqlst.p_sqlst__SQL_str.cstr_address,
    SQL_str.ptr);

  //---------------------------------------- p_sqlst__buffer_length
  assert(packet.p_sqlst.p_sqlst__buffer_length==0);

  //---------------------------------------- p_sqlst__items
  assert(packet.p_sqlst.p_sqlst__items.cstr_length==0);

  assert(packet.p_sqlst.p_sqlst__items.cstr_address==nullptr);

  //---------------------------------------- p_sqlst__blr
  if(!structure::can_numeric_cast(&packet.p_sqlst.p_sqlst__blr.cstr_length,
                                  spStmt->m_InParams__MSG_BLR.size()))
  {
   //ERROR - BLR data of input parameters is too long.

   t_ibp_error exc(E_FAIL,
                   ibp_subsystem__remote_fb__p13,
                   ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3);

   exc<<L"pInXSQLDA"
      <<spStmt->m_InParams__MSG_BLR.size()
      <<structure::get_numeric_limits(packet.p_sqlst.p_sqlst__blr.cstr_length).max_value();

   exc.raise_me();
  }//if

  structure::static_numeric_cast(&packet.p_sqlst.p_sqlst__blr.cstr_length,
                                 spStmt->m_InParams__MSG_BLR.size());

  packet.p_sqlst.p_sqlst__blr.cstr_address=spStmt->m_InParams__MSG_BLR.buffer();

  //---------------------------------------- p_sqlst__message_number
  assert(packet.p_sqlst.p_sqlst__message_number==0);

  //---------------------------------------- p_sqlst__messages
  assert(packet.p_sqlst.p_sqlst__messages==0);

  if(HasInParams)
   packet.p_sqlst.p_sqlst__messages=1;

  //---------------------------------------- p_sqlst__out_blr
  if(!structure::can_numeric_cast(&packet.p_sqlst.p_sqlst__out_blr.cstr_length,
                                   spStmt->m_OutParams__MSG_BLR.size()))
  {
   //ERROR - BLR data of output parameters is too long.

   t_ibp_error exc(E_FAIL,
                   ibp_subsystem__remote_fb__p13,
                   ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3);

   exc<<L"pOutXSQLDA"
      <<spStmt->m_OutParams__MSG_BLR.size()
      <<structure::get_numeric_limits(packet.p_sqlst.p_sqlst__blr.cstr_length).max_value();

   exc.raise_me();
  }//if

  structure::static_numeric_cast(&packet.p_sqlst.p_sqlst__out_blr.cstr_length,
                                  spStmt->m_OutParams__MSG_BLR.size());

  packet.p_sqlst.p_sqlst__out_blr.cstr_address=spStmt->m_OutParams__MSG_BLR.buffer();

  //---------------------------------------- p_sqlst__out_message_number
  assert(packet.p_sqlst.p_sqlst__out_message_number==0);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc(spStmt.ptr());

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet(portOpCtx,
                                packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response1
 protocol::P_USHORT cOutMessages=0;

 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(spStmt.ptr());

  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet(portOpCtx,
                                   packet); //throw

  if(packet.operation==protocol::set02::op_sql_response)
  {
   //обработка ответа от сервера

   cOutMessages=packet.p_sqldata.p_sqldata__messages;

   //отсутствие или одно OUT-сообщение
   assert_msg(cOutMessages<2,"cOutMessages: "<<cOutMessages);

   break;
  }//if

  // [2015-11-06]
  //  Судя по результатам тестирования, в эту точку мы не попадаем!
  //  Так что мы сюда поставим assert и будем проверять наше открытие.
  assert(false);

  //Ожидается ошибка выполнения запроса

  if(packet.operation==protocol::set02::op_response)
  {
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //ERROR - [BUG CHECK] Неожиданный ответ от сервера. Ожидалась ошибка.

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#001",
     me_bug_check__we_expected_the_error_0);

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#002",
    packet.operation);
 }//for[ever]

 //----------------------------------------- 4. get response2
 protocol::P_OBJCT TrID=0;

 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet(portOpCtx,
                                   packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //все нормально - запрос выполнился без ошибок.

   TrID=packet.p_resp.p_resp__object;

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#003",
    packet.operation);
 }//for[ever]

 //-----------------------------------------
 const protocol::P_USHORT cExpectedOutMessages=(HasOutParams?1:0);

 if(cOutMessages!=cExpectedOutMessages)
 {
  //ERROR - [BUG CHECK] Некорректное число OUT-результатов.

  structure::wstr_formatter
   freason(L"Unexpected count of OUT-results: %1. Expected: %2.");

  freason<<cOutMessages<<cExpectedOutMessages;

  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#004",
    freason.c_str());
 }//if

 if(HasOutParams)
 {
  //Сохраняем полученные результаты в pOutXSQLDA
  try
  {
   RemoteFB__P13__XSQLDA_Utilities::Parse_XSQLDA_MSG_DATA
      (spStmt->m_OutParams__MSG_DATA_DESCRS,
       spStmt->m_OutParams__MSG_DATA.size(),
       spStmt->m_OutParams__MSG_DATA.buffer(),
        pOutXSQLDA);
  }
  catch(const std::exception& e)
  {
   t_ibp_error exc(e);

   //Добавляем информацию о текущей операции (установка значений OUT-параметров)

   //Как протестировать этот обработчик - непонятно.

   exc.add_error(E_FAIL,
                 ibp_subsystem__remote_fb__p13,
                 ibp_mce_isc__failed_to_set_xsqlda_xvalues_1);

   exc<<L"pOutXSQLDA";

   exc.raise_me();
  }//catch
 }//if HasOutParams

 //-----------------------------------------
 return TrID;
}//helper_execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
