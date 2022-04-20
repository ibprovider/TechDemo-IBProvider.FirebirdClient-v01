////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__db__detach.cpp
//! \brief   Отключение от базы данных.
//! \author  Kovalenko Dmitry
//! \date    20.02.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__detach.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__DetachDatabase

RemoteFB__API_P12__DetachDatabase RemoteFB__API_P12__DetachDatabase::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__DetachDatabase::RemoteFB__API_P12__DetachDatabase()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__DetachDatabase::~RemoteFB__API_P12__DetachDatabase()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P12__DetachDatabase::exec(RemoteFB__ConnectorData* const pData)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__DetachDatabase::exec";

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
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_detach;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_rlse_object
  packet.p_rlse.p_rlse__object=pData->GetPort()->m_ID.get_value();

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet(portOpCtx,
                                packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet(portOpCtx,
                                   packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#002",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT

 //сброс идентификатора подключения
 pData->GetPort()->m_ID.reset();

 //отключаем все ресурсы подключения
 pData->ReleaseAllResources();
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
