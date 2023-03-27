////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_svc_p12__db__cancel_operation.cpp
//! \brief   Сервис отмены выполнения операции.
//! \author  Kovalenko Dmitry
//! \date    04.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_svc_p12__db__cancel_operation.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/fb_base/fb_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SVC_P12__CancelDbOperation

RemoteFB__SVC_P12__CancelDbOperation RemoteFB__SVC_P12__CancelDbOperation::Instance;

//------------------------------------------------------------------------
RemoteFB__SVC_P12__CancelDbOperation::RemoteFB__SVC_P12__CancelDbOperation()
{;}

//------------------------------------------------------------------------
RemoteFB__SVC_P12__CancelDbOperation::~RemoteFB__SVC_P12__CancelDbOperation()
{;}

//------------------------------------------------------------------------
void RemoteFB__SVC_P12__CancelDbOperation::exec(RemoteFB__ConnectorData* const pData)
{
 assert(pData!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__SVC_P12__CancelDbOperation::exec";

 //----------------------------------------- проверка идентификатора подключения
 if(!pData->GetPort()->m_ID.has_value())
 {
  //ERROR - недействительный дескриптор подключения

  RemoteFB__ErrorUtils::Throw_BugCheck_BadCnHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 assert(pData->GetPort()->m_ID.has_value());

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_cancel;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_cancel__kind
  packet.p_cancel.p_cancel__kind=fb_api::ibp_fb_cancel_raise;

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw
 }//local
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
