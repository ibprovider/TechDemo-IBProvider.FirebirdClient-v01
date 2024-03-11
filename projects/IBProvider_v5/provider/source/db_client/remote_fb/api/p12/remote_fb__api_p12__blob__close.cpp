////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__blob__close.cpp
//! \brief   Закрытие блоба.
//! \author  Kovalenko Dmitry
//! \date    12.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__close.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__CloseBlob

RemoteFB__API_P12__CloseBlob RemoteFB__API_P12__CloseBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__CloseBlob::RemoteFB__API_P12__CloseBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__CloseBlob::~RemoteFB__API_P12__CloseBlob()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12__CloseBlob::exec(db_obj::t_db_operation_context& OpCtx,
                                        RemoteFB__ConnectorData*  const pData,
                                        blob_handle_type*         const pBlobHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pBlobHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__CloseBlob::exec";

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
    ibp_subsystem__remote_fb__p12,
    ibp_mce_blob__attempt_to_close_of_closed_blob_0);
 }//if

 pData->BugCheck__CheckBlob
  (*pBlobHandle,
   c_bugcheck_src,
   L"#003",
   L"#004");

 //-----------------------------------------
 if((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Create)
 {
  //мы не должны пытаться закрывать блоб после ошибки сохранения данных.
  assert((*pBlobHandle)->m_WriteMode__State!=blob_data_type::WriteState__Failed);

  try
  {
   //выгрузка буферизированных данных
   pData->m_API__FlushBlob.get()->exec
    (OpCtx,
     pData,
     pBlobHandle);
  }
  catch(const std::exception& e)
  {
   //добавляем дополнительную информацию о причинах сбоя.

   IBP_ErrorUtils::ReThrowWithSameHResult
    (e,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_bw__fail_write_to_db_0);
  }//catch
 }//if
#ifndef NDEBUG
 else
 {
  assert((*pBlobHandle)->m_BlobMode==blob_data_type::BlobMode__Open);
 }//else
#endif

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_close_blob;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

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

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#005",
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
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
