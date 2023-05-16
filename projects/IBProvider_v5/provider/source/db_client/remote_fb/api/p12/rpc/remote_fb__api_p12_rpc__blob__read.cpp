////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_rpc
//! \file    remote_fb__api_p12_rpc__blob__read.cpp
//! \brief   „тение данных блоба  [RPC протокол].
//! \author  Kovalenko Dmitry
//! \date    15.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/rpc/remote_fb__api_p12_rpc__blob__read.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/dbms_fb/v02_5_0/api/db_obj__dbms_fb__v02_5_0__api__error_codes.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////

namespace fb_v02_5_0__api=ibp::db_obj::dbms_fb::v02_5_0::api;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer

class RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer:public RemoteFB__MemoryPool
{
 private:
  typedef tagOpMemoryBuffer                 self_type;
  typedef RemoteFB__MemoryPool              inherited;

  tagOpMemoryBuffer(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tagOpMemoryBuffer(blob_data_type* pBlobData);

  virtual ~tagOpMemoryBuffer();

  //interface ------------------------------------------------------------
  virtual void* allocate(enumMemoryID memID,
                         size_t       sz) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  blob_data_type* const m_pBlobData;

#ifndef NDEBUG
  bool m_DEBUG__BufferForBlobWasAllocated;
#endif
};//class RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer

RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer::tagOpMemoryBuffer(blob_data_type* pBlobData)
 :m_pBlobData(pBlobData)
#ifndef NDEBUG
 ,m_DEBUG__BufferForBlobWasAllocated(false)
#endif
{
 assert(m_pBlobData);
}//tagOpMemoryBuffer

//------------------------------------------------------------------------
RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer::~tagOpMemoryBuffer()
{;}

//interface --------------------------------------------------------------
void* RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer::allocate
                                           (enumMemoryID const memID,
                                            size_t       const sz)
{
 assert(m_pBlobData);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__API_P12_RPC__ReadBlob::tagOpMemoryBuffer::allocate";

 //-----------------------------------------
 if(memID==mem_id__p_op_resp__data)
 {
  //запрос на выделение пам€ти под данные блоба

  //разрешаем только однократное выделение пам€ти
  assert(!m_DEBUG__BufferForBlobWasAllocated);

  //пам€ть под данные уже должны быть зарезервирована
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
//class RemoteFB__API_P12_RPC__ReadBlob

RemoteFB__API_P12_RPC__ReadBlob RemoteFB__API_P12_RPC__ReadBlob::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12_RPC__ReadBlob::RemoteFB__API_P12_RPC__ReadBlob()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12_RPC__ReadBlob::~RemoteFB__API_P12_RPC__ReadBlob()
{;}

//interface --------------------------------------------------------------
bool RemoteFB__API_P12_RPC__ReadBlob::exec(RemoteFB__ConnectorData* const pData,
                                           blob_handle_type*        const pBlobHandle,
                                           size_t                   const cbBuffer,
                                           void*                    const pvBuffer,
                                           size_t*                  const pcbActualReaded)
{
 assert(pData!=nullptr);
 assert(pData->GetPort()->TestPortFlag__rpc());

 assert(pcbActualReaded!=nullptr);
 assert(cbBuffer==0 || pvBuffer!=nullptr);

 CHECK_WRITE_PTR(pvBuffer,cbBuffer);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_RPC__ReadBlob::exec";

 //-----------------------------------------
 (*pcbActualReaded)=0;

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
  //[2015-09-12] ѕока это слишком жестоко - на текущий момент в IBProvider
  //не отслеживаетс€ косвенное закрытие блобов при коммите транзакций.
  //assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_blob__read_data_from_closed_blob_0);
 }//if

 if(!(*pBlobHandle)->m_pParentTr)
 {
  //вот эту ошибку уже можно обрабатывать как реальную проблему в коде
  //у нас действительный серверный идентификатор (открытого) блоба и нулевой указатель
  //на родительскую транзакцию
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 if((*pBlobHandle)->m_pParentTr->m_pParentPort!=pData->GetPort())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (c_bugcheck_src,
    L"#003");
 }//if

 //-----------------------------------------
 if((*pBlobHandle)->m_BlobMode!=blob_data_type::BlobMode__Open)
 {
  //≈сли бы это было открытое API, то данную ошибку нужно было бы обрабатывать
  //по нормальному, а не как BUG CHECK.

  //Ќо поскольку API закрытое, то значит у нас внутренн€€ проблема.
  // ѕоэтому assert и BUG CHECK.

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
         /*(*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Segment ||*/
         (*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__EofPending);

  if(size_t cbBlockSize=(*pBlobHandle)->m_ReadMode__BufferActualSize-(*pBlobHandle)->m_ReadMode__BufferPos)
  {
   assert(cbBlockSize>0);

   if(cbTargetBuffer<cbBlockSize)
    cbBlockSize=cbTargetBuffer;

   memcpy(pTargetBuffer,
          (*pBlobHandle)->m_Buffer.ptr_at((*pBlobHandle)->m_ReadMode__BufferPos),
          cbBlockSize);

   (*pBlobHandle)->m_ReadMode__BufferPos+=cbBlockSize;

   cbTargetBuffer-=cbBlockSize;

   assert_s(sizeof(char)==1);

   pTargetBuffer=reinterpret_cast<char*>(pTargetBuffer)+cbBlockSize;

   continue;
  }//if

  //обработали все данные в буфере
  assert((*pBlobHandle)->m_ReadMode__BufferPos==(*pBlobHandle)->m_ReadMode__BufferActualSize);

  if((*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__EofPending)
   break; //загрузка завершена

  //-----
  self_type::helper__read_to_buffer(pData,
                                    *pBlobHandle); //throw

  assert((*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Ok ||
         /*(*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__Segment ||*/
         (*pBlobHandle)->m_ReadMode__State==blob_data_type::ReadState__EofPending);

  assert((*pBlobHandle)->m_ReadMode__BufferActualSize==(*pBlobHandle)->m_Buffer.size());
  assert((*pBlobHandle)->m_ReadMode__BufferPos==0);
 }//while cbTargetBuffer>0

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
void RemoteFB__API_P12_RPC__ReadBlob::helper__read_to_buffer
                                           (RemoteFB__ConnectorData* const pData,
                                            blob_data_type*          const pBlobData)
{
 assert(pData);
 assert(pBlobData);
 assert(pBlobData->m_BlobMode==blob_data_type::BlobMode__Open);

 assert(pBlobData->m_ReadMode__State==blob_data_type::ReadState__None ||
        pBlobData->m_ReadMode__State==blob_data_type::ReadState__Ok /*||
        pBlobData->m_ReadMode__State==blob_data_type::ReadState__Segment*/);

 assert(pBlobData->m_ReadMode__BufferActualSize<=pBlobData->m_Buffer.size());

 //обработаны все данные в буфере
 assert(pBlobData->m_ReadMode__BufferPos==pBlobData->m_ReadMode__BufferActualSize);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_RPC__ReadBlob::helper__read_to_buffer";

 //----------------------------------------- обнул€ем описатели буфера
 pBlobData->m_ReadMode__BufferActualSize=0;
 pBlobData->m_ReadMode__BufferPos=0;

 //----------------------------------------- резервируем место под данные блоба
 const protocol::P_USHORT c_BlockSize=structure::t_numeric_limits<protocol::P_USHORT>::max_value();

 pBlobData->m_Buffer.alloc(c_BlockSize);

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_get_segment;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

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

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  tagOpMemoryBuffer memoryPool(pBlobData);

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   try //захват ошибки операции с блобом
   {
    switch(const isc_api::isc_status GeneralIscCode=pset01::RemoteFB__PSET01__ErrorUtilites::GetResultCode
                                                      (pData,
                                                       c_OperationID,
                                                       packet.p_resp))
    {
     case 0:
      pBlobData->m_ReadMode__State=blob_data_type::ReadState__Ok;
      break;

     //[2015-10-09]
     // “ака€ ситуаци€ вообще не должна возникнуть, потому что мы указываем
     // буфер, в который поместитс€ сегмент любого размера.
     // ¬ том числе и максимального.
     //
     //case fb_v25::ibp_fb_v25_err__segment:
     // pBlobData->m_ReadMode__State=blob_data_type::ReadState__Segment;
     // break;

     case fb_v02_5_0__api::ibp_fb_v25_err__segstr_eof:
      pBlobData->m_ReadMode__State=blob_data_type::ReadState__EofPending;
      break;

     default:
     {
      assert(GeneralIscCode!=fb_v02_5_0__api::ibp_fb_v25_err__segment);

      pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
       (pData,
        c_OperationID,
        packet.p_resp,
        E_FAIL); //throw

      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#001",
        me_bug_check__we_expected_the_error_0);

      break;
     }//default
    }//switch GeneralIscCode

    assert(packet.p_resp.p_resp__data.cstr_address==pBlobData->m_Buffer.buffer());
    assert(packet.p_resp.p_resp__data.cstr_length==pBlobData->m_Buffer.size());

    if(packet.p_resp.p_resp__data.cstr_length==0)
    {
     // игнорируем в случае EOF
     if(!(/*pBlobData->m_ReadMode__State==blob_data_type::ReadState__None &&*/ pBlobData->m_ReadMode__State==blob_data_type::ReadState__EofPending))
     {
      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#002",
        me_bug_check__empty_block_with_blob_data_0)
     }//if
    }//if packet.p_resp.p_resp_data.cstr_length==0
   }
   catch(...)
   {
    pBlobData->m_ReadMode__State=blob_data_type::ReadState__Failed;

    pBlobData->m_spExc=std::current_exception();

    assert(pBlobData->m_spExc);

    throw;
   }//catch

   //обновл€ем описатели данных в буфере
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
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
