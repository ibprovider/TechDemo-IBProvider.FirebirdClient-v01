////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__stmt_helper-ExecuteImmediate.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    13.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__StmtHelper

protocol::P_OBJCT
 RemoteFB__P12__StmtHelper::ExecuteImmediate
                             (RemoteFB__P12__SrvOperation&   serverOperation,
                              RemoteFB__ConnectorData* const pData,
                              tr_handle_type*          const pTrHandle,
                              protocol::P_USHORT       const SQL_dialect,
                              sql_str_box_type         const SQL_str)
{
 assert(pData);
 assert(pTrHandle); // [since from beginning] It is expected!

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12__StmtHelper::ExecuteImmediate";

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_exec_immediate;

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

  //------ Let's define the boundaries of work with the server
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response
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
}//ExecuteImmediate

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
