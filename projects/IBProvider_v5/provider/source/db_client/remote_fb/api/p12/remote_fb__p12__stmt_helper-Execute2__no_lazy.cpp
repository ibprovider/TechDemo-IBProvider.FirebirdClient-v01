////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__stmt_helper--Execute2__no_lazy.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    04.04.2023
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

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__StmtHelper

protocol::P_OBJCT
 RemoteFB__P12__StmtHelper::Execute2__no_lazy
                             (RemoteFB__P12__SrvOperation&         serverOperation,
                              RemoteFB__ConnectorData*             pData,
                              tr_handle_type*                      pTrHandle,
                              stmt_handle_type*                    pStmtHandle,
                              RemoteFB__OpSvc__StmtExecuteData_v1* pStmtExecData)
{
 assert(pData);
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert(pStmtExecData);

 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());

 assert(!pStmtExecData->OutMsg_BLR.empty());
 assert(!pStmtExecData->OutMsg_DATA.empty());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12__StmtHelper::Execute2__no_lazy";

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_execute2;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqldata_statement
  packet.p_sqldata.p_sqldata__statement=(*pStmtHandle)->m_ID.get_value();

  //---------------------------------------- p_sqldata_transaction
  packet.p_sqldata.p_sqldata__transaction=(*pTrHandle)?(*pTrHandle)->m_ID.get_value():0;

  //---------------------------------------- p_sqldata_blr
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqldata.p_sqldata__blr,
    pStmtExecData->InMsg_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pInXSQLDA");

  assert(packet.p_sqldata.p_sqldata__blr.cstr_length==pStmtExecData->InMsg_BLR.size());

  packet.p_sqldata.p_sqldata__blr.cstr_address=pStmtExecData->InMsg_BLR.data();

  //---------------------------------------- p_sqldata_message_number
  packet.p_sqldata.p_sqldata__message_number=0;

  //---------------------------------------- p_sqldata_messages + p_sqldata_message_data
  packet.p_sqldata.p_sqldata__messages=pStmtExecData->InMsg_BLR.empty()?0:1;

  //--------------------------------------- p_sqldata_out_blr [op_execute2]
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqldata.p_sqldata__out_blr,
    pStmtExecData->OutMsg_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pOutXSQLDA");

  assert(packet.p_sqldata.p_sqldata__out_blr.cstr_length==pStmtExecData->OutMsg_BLR.size());

  packet.p_sqldata.p_sqldata__out_blr.cstr_address=pStmtExecData->OutMsg_BLR.data();

  //--------------------------------------- p_sqldata_out_message_number [op_execute2]
  packet.p_sqldata.p_sqldata__out_message_number=0;

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
 if(cOutMessages!=1)
 {
  //ERROR - [BUG CHECK] The wrong number of OUT-results.

  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#004",
    L"Unexpected count of OUT-results: %1",
    cOutMessages);
 }//if

 //-----------------------------------------
 return TrID;
}//Execute2__no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
