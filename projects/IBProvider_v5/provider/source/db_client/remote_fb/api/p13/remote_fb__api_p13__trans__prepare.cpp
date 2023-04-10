////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__trans__prepare.cpp
//! \brief   Подготовка транзакции.
//! \author  Kovalenko Dmitry
//! \date    15.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__prepare.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__PrepareTransaction

RemoteFB__API_P13__PrepareTransaction RemoteFB__API_P13__PrepareTransaction::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__PrepareTransaction::RemoteFB__API_P13__PrepareTransaction()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__PrepareTransaction::~RemoteFB__API_P13__PrepareTransaction()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13__PrepareTransaction::exec
                                           (RemoteFB__ConnectorData* const pData,
                                            tr_handle_type*          const pTrHandle,
                                            size_t                   const data_length,
                                            const void*              const data)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pTrHandle!=nullptr);

 CHECK_READ_PTR(data,data_length);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__PrepareTransaction::exec";

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
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_prepare2;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_prep__transaction
  packet.p_prep.p_prep__transaction=(*pTrHandle)->m_ID.get_value();

  //---------------------------------------- p_prep__data.cstr_length
  RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
   (&packet.p_prep.p_prep__data,
    data_length,
    ibp_mce_ibtrans__tr_prep_data_is_too_large__2);

  assert(packet.p_prep.p_prep__data.cstr_length==data_length);

  //---------------------------------------- p_prep__data.cstr_address
  assert_s(sizeof(*packet.p_prep.p_prep__data.cstr_address)==1);

  structure::reinterpret_ptr_cast
   (&packet.p_prep.p_prep__data.cstr_address,
    data);

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
    L"#004",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT

 //ничего делать не надо. транзакция продолжает быть активной.

 //исходя из исходных текстов Firebird, связанные блобы и курсоры никак не
 //затрагиваются. так что - НИЧЕГО делать не надо.
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
