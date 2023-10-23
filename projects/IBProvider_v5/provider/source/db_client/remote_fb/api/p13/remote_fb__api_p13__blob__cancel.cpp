////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__cancel.cpp
//! \brief   Отмена создания блоба.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__cancel.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__CancelBlob

RemoteFB__API_P13__CancelBlob RemoteFB__API_P13__CancelBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__CancelBlob::RemoteFB__API_P13__CancelBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__CancelBlob::~RemoteFB__API_P13__CancelBlob()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P13__CancelBlob::exec(RemoteFB__ConnectorData* const pData,
                                         blob_handle_type*        const pBlobHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pBlobHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__CancelBlob::exec";

 //----------------------------------------- проверка дескриптора блоба
 if((*pBlobHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pBlobHandle)->m_ID.has_value())
 {
  //[2015-09-12]
  // Пока это слишком жестоко - на текущий момент в IBProvider
  // не отслеживается косвенное закрытие блобов при коммите транзакций.

  //[2016-08-10]
  // Провайдер научился отслеживать косвенное закрытие блобов.
  // Так что теперь будем ругаться по-полной.
  assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_blob__attempt_to_cancel_of_closed_blob_0);
 }//if

 pData->BugCheck__CheckBlob
  (*pBlobHandle,
   c_bugcheck_src,
   L"#003",
   L"#004");

 //-----------------------------------------
 if((*pBlobHandle)->m_BlobMode!=blob_data_type::BlobMode__Create)
 {
  //Если бы это было открытое API, то данную ошибку нужно было бы обрабатывать
  //по нормальному, а не как BUG CHECK.

  //Но поскольку API закрытое, то значит у нас внутренняя проблема.
  // Поэтому assert и BUG CHECK.

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectBlobHandleMode
   (c_bugcheck_src,
    L"#005",
    lib::structure::to_underlying((*pBlobHandle)->m_BlobMode));
 }//if

 assert((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Create);

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_cancel_blob;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_rlse_object
  packet.p_rlse.p_rlse__object=(*pBlobHandle)->m_ID.get_value();

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

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#006",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT

 //разрушение дескриптора блоба
 (*pBlobHandle)->Dangerous__DropHandle();

 assert((*pBlobHandle)->m_ID.is_null());
 assert((*pBlobHandle)->m_pParentTr==nullptr);

 //обнуляем дескриптор
 (*pBlobHandle)=nullptr;
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
