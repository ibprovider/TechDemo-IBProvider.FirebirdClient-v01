////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__blob__read.cpp
//! \brief   ������ ������ �����.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__read.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error_messages.h"

#include "source/db_obj/db_operation_reg.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer

class RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__MemoryPool
{
 private:
  using self_type=tagOpMemoryBuffer;
  using inherited=RemoteFB__MemoryPool;

  tagOpMemoryBuffer(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  explicit tagOpMemoryBuffer(blob_data_type* pBlobData);

  virtual ~tagOpMemoryBuffer();

  //interface ------------------------------------------------------------
  virtual void* allocate(enumMemoryID memID,
                         size_t       sz) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  blob_data_type* const m_pBlobData;

#ifndef NDEBUG
  bool m_DEBUG__BufferForBlobWasAllocated;
#endif
};//class RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer

RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer::tagOpMemoryBuffer(blob_data_type* pBlobData)
 :m_pBlobData(pBlobData)
#ifndef NDEBUG
 ,m_DEBUG__BufferForBlobWasAllocated(false)
#endif
{
 assert(m_pBlobData);
}//tagOpMemoryBuffer

//------------------------------------------------------------------------
RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer::~tagOpMemoryBuffer()
{;}

//interface --------------------------------------------------------------
void* RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer::allocate
                                           (enumMemoryID const memID,
                                            size_t       const sz)
{
 assert(m_pBlobData);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_P13__ReadBlob::tagOpMemoryBuffer::allocate";

 //-----------------------------------------
 if(memID==mem_id__p_op_resp__data)
 {
  //������ �� ��������� ������ ��� ������ �����

  //��������� ������ ����������� ��������� ������
  assert(!m_DEBUG__BufferForBlobWasAllocated);

  //������ ��� ������ ��� ������ ���� ���������������
  if(m_pBlobData->m_Buffer.capacity()<sz)
  {
   structure::wstr_formatter
    freason(me_bug_check__target_buffer_length_less_than_required_2);

   freason<<m_pBlobData->m_Buffer.capacity()<<sz;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#001",
     freason.c_str())
  }//if

  DEBUG_CODE(m_DEBUG__BufferForBlobWasAllocated=true;)

  return m_pBlobData->m_Buffer.alloc(sz); //no throw!
 }//if memID==mem_id__p_op_resp__p_resp_data

 return inherited::allocate(memID,sz);
}//allocate

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__ReadBlob

RemoteFB__API_P13__ReadBlob RemoteFB__API_P13__ReadBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__ReadBlob::RemoteFB__API_P13__ReadBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__ReadBlob::~RemoteFB__API_P13__ReadBlob()
{;}

//interface --------------------------------------------------------------
bool RemoteFB__API_P13__ReadBlob::exec
                        (db_obj::t_db_operation_context& OpCtx,
                         RemoteFB__ConnectorData*  const pData,
                         blob_handle_type*         const pBlobHandle,
                         size_t                    const cbBuffer,
                         void*                     const pvBuffer,
                         size_t*                   const pcbActualReaded)
{
 assert(pData!=nullptr);
 assert(!pData->GetPort()->TestPortFlag__rpc());
 assert(pcbActualReaded!=nullptr);
 assert(cbBuffer==0 || pvBuffer!=nullptr);

 CHECK_WRITE_PTR(pvBuffer,cbBuffer);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__ReadBlob::exec";

 //-----------------------------------------
 (*pcbActualReaded)=0;

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- �������� ����������� �����
 if((*pBlobHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pBlobHandle)->m_ID.has_value())
 {
  //[2015-09-12] ���� ��� ������� ������� - �� ������� ������ � IBProvider
  //�� ������������� ��������� �������� ������ ��� ������� ����������.
  //assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_blob__read_data_from_closed_blob_0);
 }//if

 pData->BugCheck__CheckBlob
  (*pBlobHandle,
   c_bugcheck_src,
   L"#002",
   L"#003");

 //-----------------------------------------
 if((*pBlobHandle)->m_BlobMode!=blob_data_type::BlobMode__Open)
 {
  //���� �� ��� ���� �������� API, �� ������ ������ ����� ���� �� ������������
  //�� �����������, � �� ��� BUG CHECK.

  //�� ��������� API ��������, �� ������ � ��� ���������� ��������.
  // ������� assert � BUG CHECK.

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_IncorrectBlobHandleMode
   (c_bugcheck_src,
    L"#004",
    (*pBlobHandle)->m_BlobMode);
 }//if

 //-----------------------------------------
 if((*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Failed)
 {
  assert((*pBlobHandle)->m_spExc);

  std::rethrow_exception((*pBlobHandle)->m_spExc);
 }//if

 assert(!(*pBlobHandle)->m_spExc);

 //-----------------------------------------
 void*   pTargetBuffer  =pvBuffer;
 size_t  cbTargetBuffer =cbBuffer;

 while(cbTargetBuffer>0)
 {
  assert((*pBlobHandle)->m_ReadMode__BufferActualSize<=(*pBlobHandle)->m_Buffer.size());
  assert((*pBlobHandle)->m_ReadMode__BufferPos<=(*pBlobHandle)->m_ReadMode__BufferActualSize);

  assert((*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__None    ||
         (*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Ok      ||
         (*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Segment ||
         (*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__EofPending);

  //----------------------------------------
  if((*pBlobHandle)->m_ReadMode__FragmentTailSize>0)
  {
   assert((*pBlobHandle)->m_ReadMode__BufferActualSize>0);
   assert((*pBlobHandle)->m_ReadMode__FragmentTailSize<(*pBlobHandle)->m_ReadMode__BufferActualSize);

   assert((*pBlobHandle)->m_ReadMode__BufferPos<=((*pBlobHandle)->m_ReadMode__BufferActualSize-(*pBlobHandle)->m_ReadMode__FragmentTailSize));

   size_t x=(*pBlobHandle)->m_ReadMode__FragmentTailSize;

   if(cbTargetBuffer<x)
    x=cbTargetBuffer;

   memcpy(pTargetBuffer,
          (*pBlobHandle)->m_Buffer.ptr_at((*pBlobHandle)->m_ReadMode__BufferPos),
          x);

   //-----
   (*pBlobHandle)->m_ReadMode__BufferPos+=x;

   (*pBlobHandle)->m_ReadMode__FragmentTailSize-=x;

   assert_s(sizeof(char)==1);

   pTargetBuffer=reinterpret_cast<char*>(pTargetBuffer)+x;

   cbTargetBuffer-=x;

   continue;
  }//if (*pBlobHandle)->m_ReadMode__FragmentTailSize>0

  assert((*pBlobHandle)->m_ReadMode__FragmentTailSize==0);

  //----------------------------------------
  assert((*pBlobHandle)->m_ReadMode__BufferPos<=(*pBlobHandle)->m_ReadMode__BufferActualSize);

  if((*pBlobHandle)->m_ReadMode__BufferPos!=(*pBlobHandle)->m_ReadMode__BufferActualSize)
  {
   size_t cbBufferTail=(*pBlobHandle)->m_ReadMode__BufferActualSize-(*pBlobHandle)->m_ReadMode__BufferPos;

   protocol::P_USHORT cbFragment=0;

   if(cbBufferTail<sizeof(cbFragment))
   {
    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#005",
      me_bug_check__incorrect_blob_data_buffer_format_0);
   }//if

   assert(sizeof(cbFragment)<=cbBufferTail);

   isc_base::isc_portable_format_to_integer::exec
    (sizeof(cbFragment),
     (*pBlobHandle)->m_Buffer.ptr_at((*pBlobHandle)->m_ReadMode__BufferPos),
     &cbFragment,
     ibp_subsystem__remote_fb__p13,
     L"cbBlobDataFragment");

   cbBufferTail-=sizeof(cbFragment);

   if(cbBufferTail<cbFragment)
   {
    structure::wstr_formatter
     freason(me_bug_check__incorrect_blob_data_buffer_format__wrong_fragment_length_2);

    freason<<cbFragment<<cbBufferTail;

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#006",
      freason.c_str())
   }//if cbBufferTail<cbFragment

   (*pBlobHandle)->m_ReadMode__BufferPos+=sizeof(cbFragment);

   (*pBlobHandle)->m_ReadMode__FragmentTailSize=cbFragment;

   continue;
  }//if (*pBlobHandle)->m_ReadMode__BufferPos!=(*pBlobHandle)->m_ReadMode__BufferActualSize

  //���������� ��� ������ � ������
  assert((*pBlobHandle)->m_ReadMode__BufferPos==(*pBlobHandle)->m_ReadMode__BufferActualSize);

  if((*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__EofPending)
   break; //�������� ���������

  //-----
  self_type::helper__read_to_buffer
   (serverOperation,
    pData,
    *pBlobHandle); //throw

  assert((*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Ok ||
         (*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Segment ||
         (*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__EofPending);

  assert((*pBlobHandle)->m_ReadMode__BufferActualSize==(*pBlobHandle)->m_Buffer.size());
  assert((*pBlobHandle)->m_ReadMode__BufferPos==0);
 }//while(cbTargetBuffer>0)

 //-----------------------------------------
 assert(cbTargetBuffer<=cbBuffer);

 (*pcbActualReaded)=cbBuffer-cbTargetBuffer;

 if((*pBlobHandle)->m_ReadMode__BufferPos<(*pBlobHandle)->m_ReadMode__BufferActualSize)
  return true;

 if((*pBlobHandle)->m_ReadMode__State!=blob_data_type::ReadState__EofPending)
  return true;

 return false; /*EOF*/
}//exec

//------------------------------------------------------------------------
void RemoteFB__API_P13__ReadBlob::helper__read_to_buffer
                        (RemoteFB__P13__SrvOperation&   serverOperation,
                         RemoteFB__ConnectorData* const pData,
                         blob_data_type*          const pBlobData)
{
 assert(pData);
 assert(pBlobData);
 assert(pBlobData->m_BlobMode==blob_data_type::BlobMode__Open);

 assert(pBlobData->m_ReadMode__State==blob_data_type::ReadState__None ||
        pBlobData->m_ReadMode__State==blob_data_type::ReadState__Ok ||
        pBlobData->m_ReadMode__State==blob_data_type::ReadState__Segment);

 assert(pBlobData->m_ReadMode__BufferActualSize<=pBlobData->m_Buffer.size());

 //���������� ��� ������ � ������
 assert(pBlobData->m_ReadMode__BufferPos==pBlobData->m_ReadMode__BufferActualSize);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__ReadBlob::helper__read_to_buffer";

 //----------------------------------------- �������� ��������� ������
 pBlobData->m_ReadMode__BufferActualSize=0;
 pBlobData->m_ReadMode__BufferPos=0;

 //----------------------------------------- ����������� ����� ��� ������ �����
 const protocol::P_USHORT c_BlockSize=structure::t_numeric_limits<protocol::P_USHORT>::max_value();

 pBlobData->m_Buffer.alloc(c_BlockSize);

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_get_segment;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sgmt.p_sgmt_blob
  packet.p_sgmt.p_sgmt__blob=pBlobData->m_ID.get_value();

  //---------------------------------------- p_sgmt.p_sgmt_length
  packet.p_sgmt.p_sgmt__length=c_BlockSize;

  //---------------------------------------- p_sgmt.p_sgmt_segment
  assert(packet.p_sgmt.p_sgmt__segment.cstr_length==0);

  packet.p_sgmt.p_sgmt__segment.cstr_length=0;

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ Let's define the boundaries of work with the server
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  tagOpMemoryBuffer memoryPool(pBlobData);

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   try //������ ������ �������� � ������
   {
    pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
     (pData,
      c_OperationID,
      packet.p_resp,
      E_FAIL); //throw

    assert(packet.p_resp.p_resp__data.cstr_address==pBlobData->m_Buffer.buffer());
    assert(packet.p_resp.p_resp__data.cstr_length==pBlobData->m_Buffer.size());

    if(packet.p_resp.p_resp__data.cstr_length==0)
    {
     // ���������� � ������ EOF
     if(!(/*pBlobData->m_ReadMode__State==blob_data_type::ReadState__None &&*/ packet.p_resp.p_resp__object==/*EOF*/2))
     {
      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#001",
        me_bug_check__empty_block_with_blob_data_0)
     }//if
    }//if packet.p_resp.p_resp_data.cstr_length==0

    switch(packet.p_resp.p_resp__object)
    {
     case 0:
      pBlobData->m_ReadMode__State=blob_data_type::ReadState__Ok;
      break;

     case 1:
      pBlobData->m_ReadMode__State=blob_data_type::ReadState__Segment;
      break;

     case 2:
      pBlobData->m_ReadMode__State=blob_data_type::ReadState__EofPending;
      break;

     default:
     {
      structure::wstr_formatter
       freason(me_bug_check__unexpected_blob_read_result_1);

      freason<<packet.p_resp.p_resp__object;

      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#002",
        freason.c_str());
     }//default
    }//switch
   }
   catch(...)
   {
    pBlobData->m_ReadMode__State=blob_data_type::ReadState__Failed;

    pBlobData->m_spExc=std::current_exception();

    assert(pBlobData->m_spExc);

    throw;
   }//catch

   //��������� ��������� ������ � ������
   pBlobData->m_ReadMode__BufferActualSize=packet.p_resp.p_resp__data.cstr_length;

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
 assert(pBlobData->m_ReadMode__BufferPos==0);
}//helper__read_to_buffer

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
