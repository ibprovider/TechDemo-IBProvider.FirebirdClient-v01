////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__create.cpp
//! \brief   �������� �����.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__create.h"
#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__CreateBlob

RemoteFB__API_P13__CreateBlob RemoteFB__API_P13__CreateBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__CreateBlob::RemoteFB__API_P13__CreateBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__CreateBlob::~RemoteFB__API_P13__CreateBlob()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P13__CreateBlob::exec(RemoteFB__ConnectorData* const pData,
                                         tr_handle_type*          const pTrHandle,
                                         blob_handle_type*        const pBlobHandle,
                                         db_obj::DB_IBBLOBID*     const pBlobId,
                                         size_t                   const szBPB,
                                         const protocol::P_UCHAR* const pBPB)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pTrHandle!=nullptr);
 assert(pBlobHandle!=nullptr);
 assert(pBlobId!=nullptr);

 CHECK_READ_TYPED_PTR(pBPB,szBPB);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__CreateBlob::exec";

 //-----------------------------------------
 if((*pBlobHandle)!=nullptr)
 {
  //ERROR - [BUG CHECK] ��������� �������� ����������� �����

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BlobHandleNotZero
   (c_bugcheck_src,
    L"#001");
 }//if

 //-----------------------------------------
 if(!(*pTrHandle))
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 //-----------------------------------------
 if(!(*pTrHandle)->m_ID.has_value())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
   (c_bugcheck_src,
    L"#003");
 }//if

 pData->BugCheck__CheckTr
  (*pTrHandle,
   c_bugcheck_src,
   L"#004");

 //-----------------------------------------
 //��������� ��� �������� ������� ����������� [LAZY_SEND mode]

 if(pData->GetPort()->TestPortFlag__lazy())
 {
  RemoteFB__P13_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources(pData);
 }//if

 //-----------------------------------------
 //�������������� ������ ����������� �����

 blob_handle_type
  NewBlobHandle(blob_data_type::Create(blob_data_type::BlobMode__Create)); //throw

 assert(NewBlobHandle!=nullptr);

 db_obj::DB_IBBLOBID
  NewBlobId={};

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_create_blob2;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_blob.p_blob_transaction
  packet.p_blob.p_blob__transaction=(*pTrHandle)->m_ID.get_value();

  //---------------------------------------- p_blob__bpb.cstr_length

  // [2015-01-04]
  // � ���� ����������� ������������ ������ �������� ����������: �������� stream-����.
  // � ��� ����� ������ 4 �����.

  RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
   (&packet.p_blob.p_blob__bpb,
    szBPB,
    ibp_mce_common__formed_param_buf_is_too_large_3,
    L"BPB");

  assert(packet.p_blob.p_blob__bpb.cstr_length==szBPB);

  //---------------------------------------- p_blob__bpb.cstr_address
  packet.p_blob.p_blob__bpb.cstr_address=pBPB;

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

   //���������� ������������� ����������� �����
   assert(NewBlobHandle!=nullptr);

   NewBlobHandle->m_ID.set_value(&packet.p_resp.p_resp__object);

   //���������� ������������� �����
   NewBlobId=packet.p_resp.p_resp__blob_id;
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

 // ����������� ����� � ����������
 (*pTrHandle)->BlobList__Add(NewBlobHandle); //no throw

 // ���������� ���������� ���������� �������
 (*pBlobHandle)=LCPI_STL_MOVE_VALUE(NewBlobHandle);

 assert(*pBlobHandle);

 // ���������� ������������� ����� ���������� �������
 (*pBlobId)=NewBlobId;
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
