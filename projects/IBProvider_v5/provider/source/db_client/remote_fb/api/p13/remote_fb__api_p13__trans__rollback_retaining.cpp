////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__trans__rollback_retaining.cpp
//! \brief   Откат транзакции с сохранением контекста.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__rollback_retaining.h"

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"

#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"

#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__RollbackRetaining

RemoteFB__API_P13__RollbackRetaining RemoteFB__API_P13__RollbackRetaining::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__RollbackRetaining::RemoteFB__API_P13__RollbackRetaining()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__RollbackRetaining::~RemoteFB__API_P13__RollbackRetaining()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13__RollbackRetaining::exec(RemoteFB__ConnectorData* const pData,
                                                tr_handle_type*          const pTrHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pTrHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__RollbackRetaining::exec";

 //----------------------------------------- проверка дескриптора транзакции
 if((*pTrHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pTrHandle)->m_ID.has_value())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 pData->BugCheck__CheckTr
  (*pTrHandle,
   c_bugcheck_src,
   L"#003");

 //-----------------------------------------
 if(pData->GetPort()->TestPortFlag__lazy())
 {
  //
  // [2021-02-26]
  //  Форсируем освобождение отложенных запросов.
  //
  //  Зависшие запросы могут помешать другим подключениям закоммитить DDL запросы.
  //
  //  Зависшие блобы тоже, теоритически, могут вызвать проблемы.
  //
  //  Поэтому проталкиваем ВСЁ.
  //

  RemoteFB__P13_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);
 }//if

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_rollback_retaining;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_rlse_object
  packet.p_rlse.p_rlse__object=(*pTrHandle)->m_ID.get_value();

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

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#004",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT

 //ничего делать не надо. транзакция продолжает быть активной.
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
