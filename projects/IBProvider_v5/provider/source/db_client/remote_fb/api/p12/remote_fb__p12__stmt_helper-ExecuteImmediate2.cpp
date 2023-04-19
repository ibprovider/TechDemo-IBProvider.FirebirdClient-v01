////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__stmt_helper-ExecuteImmediate2.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    13.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v1.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v1.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__StmtHelper

protocol::P_OBJCT
 RemoteFB__P12__StmtHelper::ExecuteImmediate2
                             (RemoteFB__P12__SrvOperation&               serverOperation,
                              RemoteFB__ConnectorData*             const pData,
                              tr_handle_type*                      const pTrHandle,
                              protocol::P_USHORT                   const SQL_dialect,
                              sql_str_box_type                     const SQL_str,
                              RemoteFB__OpSvc__StmtExecuteData_v1* const pStmtExecData)
{
 assert(pData);
 assert(pTrHandle); // [since from beginning] It is expected!

 assert(pStmtExecData);

 //-----------------------------------------
#ifndef NDEBUG
 if(pStmtExecData->InMsg_BLR.empty())
 {
  //No input parameters

  assert(pStmtExecData->InMsg_DATA.empty());
 }
 else
 {
  //Has input parameters

  assert(!pStmtExecData->InMsg_BLR.empty());
  assert(!pStmtExecData->InMsg_DATA.empty());
 }//else

 //-----------------------------------------
 if(pStmtExecData->OutMsg_BLR.empty())
 {
  //No output parameters

  assert(pStmtExecData->OutMsg_DATA.empty());
 }
 else
 {
  //Has output parameters

  assert(!pStmtExecData->OutMsg_BLR.empty());
  assert(!pStmtExecData->OutMsg_DATA.empty());
 }//else
#endif

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12__StmtHelper::ExecuteImmediate2";

 //-----------------------------------------
 const bool HasInParams=!pStmtExecData->InMsg_BLR.empty();

 const bool HasOutParams=!pStmtExecData->OutMsg_BLR.empty();

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_exec_immediate2;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

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

  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqlst.p_sqlst__SQL_str,
    SQL_str.len,
    ibp_mce_cmd_stmt_too_long_2);

  assert(packet.p_sqlst.p_sqlst__SQL_str.cstr_length==SQL_str.len);

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
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqlst.p_sqlst__blr,
    pStmtExecData->InMsg_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pInXSQLDA");

  assert(packet.p_sqlst.p_sqlst__blr.cstr_length==pStmtExecData->InMsg_BLR.size());

  packet.p_sqlst.p_sqlst__blr.cstr_address=pStmtExecData->InMsg_BLR.data();

  //---------------------------------------- p_sqlst__message_number
  assert(packet.p_sqlst.p_sqlst__message_number==0);

  //---------------------------------------- p_sqlst__messages
  assert(packet.p_sqlst.p_sqlst__messages==0);

  if(HasInParams)
   packet.p_sqlst.p_sqlst__messages=1;

  //---------------------------------------- p_sqlst__out_blr
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqlst.p_sqlst__out_blr,
    pStmtExecData->OutMsg_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pOutXSQLDA");

  assert(packet.p_sqlst.p_sqlst__out_blr.cstr_length==pStmtExecData->OutMsg_BLR.size());

  packet.p_sqlst.p_sqlst__out_blr.cstr_address=pStmtExecData->OutMsg_BLR.data();

  //---------------------------------------- p_sqlst__out_message_number
  assert(packet.p_sqlst.p_sqlst__out_message_number==0);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc(pStmtExecData);

  //------ Let's define the boundaries of work with the server
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response1
 protocol::P_USHORT cOutMessages=0;

 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(pStmtExecData);

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_sql_response)
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

  //
  // [2023-04-13]
  //  Amen.
  //
#if 0
  //Ожидается ошибка выполнения запроса

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //ERROR - [BUG CHECK] Неожиданный ответ от сервера. Ожидалась ошибка.

   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#001",
     me_bug_check__we_expected_the_error_0);

   break;
  }//if - protocol::op_response
#endif

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

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
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

  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#004",
    L"Unexpected count of OUT-results: %1. Expected: %2.",
    cOutMessages,
    cExpectedOutMessages);
 }//if

 //-----------------------------------------
 return TrID;
}//ExecuteImmediate2

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
