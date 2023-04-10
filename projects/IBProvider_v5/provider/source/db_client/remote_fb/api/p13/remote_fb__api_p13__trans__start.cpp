////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__trans__start.cpp
//! \brief   Старт транзакции.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__start.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__StartTransaction

RemoteFB__API_P13__StartTransaction RemoteFB__API_P13__StartTransaction::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__StartTransaction::RemoteFB__API_P13__StartTransaction()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__StartTransaction::~RemoteFB__API_P13__StartTransaction()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13__StartTransaction::exec(RemoteFB__ConnectorData* const pData,
                                               tr_handle_type*          const pTrHandle,
                                               size_t                   const tpb_length,
                                               const unsigned char*     const tpb)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pTrHandle!=nullptr);

 CHECK_READ_TYPED_PTR(tpb,tpb_length);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__StartTransaction::exec";

 //----------------------------------------- проверка идентификатора подключения
 if(!pData->GetPort()->m_ID.has_value())
 {
  //ERROR - недействительный дескриптор подключения

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadCnHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 assert(pData->GetPort()->m_ID.has_value());

 //-----------------------------------------
 if((*pTrHandle)!=nullptr)
 {
  //ERROR - [BUG CHECK] ненулевое значение дескриптора транзакции

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_TrHandleNotZero
   (c_bugcheck_src,
    L"#002");
 }//if

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
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_transaction;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sttr_database
  packet.p_sttr.p_sttr__database=pData->GetPort()->m_ID.get_value();

  //---------------------------------------- p_sttr_tpb.cstr_length
  RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
   (&packet.p_sttr.p_sttr__tpb,
    tpb_length,
    ibp_mce_common__formed_param_buf_is_too_large_3,
    L"TPB");

  assert(packet.p_sttr.p_sttr__tpb.cstr_length==tpb_length);

  //---------------------------------------- p_sttr_tpb.cstr_address
  packet.p_sttr.p_sttr__tpb.cstr_address=tpb;

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw
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

   newTrHandle->m_ID.set_value(&packet.p_resp.p_resp__object);

   //регистрируем транзакцию в списке
   pData->TrList__Add(newTrHandle); //no throw

   //возвращаем дескриптор вызывающей стороне
   (*pTrHandle)=__STL_MOVE_VALUE(newTrHandle);

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#003",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT
 assert(*pTrHandle);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
