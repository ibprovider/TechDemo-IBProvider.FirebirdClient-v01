////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_svc_p13__db__cancel_operation.cpp
//! \brief   Сервис отмены выполнения операции.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_svc_p13__db__cancel_operation.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/fb_base/fb_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SVC_P13__CancelDbOperation

RemoteFB__SVC_P13__CancelDbOperation RemoteFB__SVC_P13__CancelDbOperation::Instance;

//------------------------------------------------------------------------
RemoteFB__SVC_P13__CancelDbOperation::RemoteFB__SVC_P13__CancelDbOperation()
{;}

//------------------------------------------------------------------------
RemoteFB__SVC_P13__CancelDbOperation::~RemoteFB__SVC_P13__CancelDbOperation()
{;}

//------------------------------------------------------------------------
void RemoteFB__SVC_P13__CancelDbOperation::exec(RemoteFB__ConnectorData* const pData)
{
 assert(pData!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__SVC_P13__CancelDbOperation::exec";

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
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_cancel;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_cancel__kind
  packet.p_cancel.p_cancel__kind=fb_api::ibp_fb_cancel_raise;

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet(portOpCtx,
                                packet); //throw
 }//local
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
