////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__stmt_helper--Execute__no_lazy.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    04.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v1.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__StmtHelper

protocol::P_OBJCT
 RemoteFB__P12__StmtHelper::Execute__no_lazy
                             (RemoteFB__P12__SrvOperation&         serverOperation,
                              RemoteFB__ConnectorData*             pData,
                              tr_handle_type*                      pTrHandle,
                              stmt_handle_type*                    pStmtHandle,
                              RemoteFB__OpSvc__StmtExecuteData_v1* pStmtExecData)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert(pStmtExecData);

 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());

 assert(pStmtExecData->OutMsg_BLR.empty());
 assert(pStmtExecData->OutMsg_DATA.empty());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12__StmtHelper::Execute__no_lazy";

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_execute;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  RemoteFB__P12__StmtHelper::BuildPacket__op_execute
   (&packet,
    pTrHandle?*pTrHandle:nullptr,
    *pStmtHandle,
    pStmtExecData->InMsg_BLR);

  assert(packet.operation==c_OperationID);

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
}//Execute__no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
