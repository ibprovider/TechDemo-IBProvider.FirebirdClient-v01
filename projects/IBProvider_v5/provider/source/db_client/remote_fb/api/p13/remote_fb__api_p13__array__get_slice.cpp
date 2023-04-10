////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__array__get_slice.cpp
//! \brief   Чтение массива.
//! \author  Kovalenko Dmitry.
//! \date    24.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__array__get_slice.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__array_slice_utilities.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__get_array_slice_descr.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer

class RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer:public RemoteFB__MemoryPool
{
 private:
  typedef tagOpMemoryBuffer                 self_type;
  typedef RemoteFB__MemoryPool              inherited;

  tagOpMemoryBuffer(const self_type&);
  self_type& operator = (const self_type&);

 public:
  tagOpMemoryBuffer(size_t szSliceData,
                    void*  pvSliceData);

  virtual ~tagOpMemoryBuffer();

  //interface ------------------------------------------------------------
  virtual void* allocate(enumMemoryID memID,
                         size_t       sz) COMP_W000004_OVERRIDE_FINAL;

 private:
  size_t const m_szSliceData;
  void*  const m_pvSliceData;

#ifndef NDEBUG
  bool m_DEBUG__BufferForDataWasAllocated;
#endif
};//class RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer

RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer::tagOpMemoryBuffer
                                           (size_t const szSliceData,
                                            void*  const pvSliceData)
 :m_szSliceData(szSliceData)
 ,m_pvSliceData(pvSliceData)
#ifndef NDEBUG
 ,m_DEBUG__BufferForDataWasAllocated(false)
#endif
{
 CHECK_WRITE_PTR(m_pvSliceData,m_szSliceData)
}//tagOpMemoryBuffer

//------------------------------------------------------------------------
RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer::~tagOpMemoryBuffer()
{;}

//interface --------------------------------------------------------------
void* RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer::allocate
                                           (enumMemoryID const memID,
                                            size_t       const sz)
{
 const wchar_t* const c_bug_check_src
  =L"RemoteFB__API_P13__GetArraySlice::tagOpMemoryBuffer::allocate";

 if(memID==mem_id__p_op_slice__data)
 {
  //запрос на выделение памяти под данные элементов массива

  if(m_szSliceData!=sz)
  {
   structure::wstr_formatter
    freason(me_bug_check__array_slice_size_not_equal_to_expected_2);

   freason<<m_szSliceData<<sz;

   IBP_BUG_CHECK__DEBUG
    (c_bug_check_src,
     L"#001",
     freason.c_str())
  }//if

  //разрешаем только однократное выделение памяти
  assert(!m_DEBUG__BufferForDataWasAllocated);

  DEBUG_CODE(m_DEBUG__BufferForDataWasAllocated=true;)

  return m_pvSliceData;
 }//if memID==mem_id__p_op_resp__p_resp_data

 return inherited::allocate(memID,sz);
}//allocate

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetArraySlice::tagOpGetArraySliceDescr

class RemoteFB__API_P13__GetArraySlice::tagOpGetArraySliceDescr
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__OpSvc__GetArraySliceDescr)
{
 private:
  typedef tagOpGetArraySliceDescr           self_type;

  tagOpGetArraySliceDescr(const self_type&);
  self_type& operator = (const self_type&);

 public:
  RemoteFB__ArraySliceDescr m_descr;

 public:
  tagOpGetArraySliceDescr();

  virtual ~tagOpGetArraySliceDescr();

  //interface ------------------------------------------------------------
  virtual const RemoteFB__ArraySliceDescr& GetArraySliceDescr()const COMP_W000004_OVERRIDE_FINAL;
};//RemoteFB__API_P13__GetArraySlice::tagOpGetArraySliceDescr

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetArraySlice::tagOpGetArraySliceDescr

RemoteFB__API_P13__GetArraySlice::tagOpGetArraySliceDescr::tagOpGetArraySliceDescr()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__GetArraySlice::tagOpGetArraySliceDescr::~tagOpGetArraySliceDescr()
{;}

//interface --------------------------------------------------------------
const RemoteFB__ArraySliceDescr&
 RemoteFB__API_P13__GetArraySlice::tagOpGetArraySliceDescr::GetArraySliceDescr()const
{
 return m_descr;
}//GetArraySliceDescr

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__GetArraySlice

RemoteFB__API_P13__GetArraySlice RemoteFB__API_P13__GetArraySlice::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__GetArraySlice::RemoteFB__API_P13__GetArraySlice()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__GetArraySlice::~RemoteFB__API_P13__GetArraySlice()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P13__GetArraySlice::exec(db_obj::t_db_operation_context& opCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            const db_obj::DB_IBARRAYID&     ArrayID,
                                            size_t                    const szArraySDL,
                                            const unsigned char*      const pArraySDL,
                                            size_t                    const szArrayData,
                                            void*                     const pArrayData)
{
 assert(pData!=nullptr);
 assert(pTrHandle!=nullptr);

 CHECK_READ_TYPED_PTR(pArraySDL,szArraySDL);

 CHECK_WRITE_PTR(pArrayData,szArrayData);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__GetArraySlice::exec";

 //-----------------------------------------
 if(!(*pTrHandle))
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
 tagOpGetArraySliceDescr GetArraySliceDescrSvc;

 RemoteFB__P13__ArraySlice_Utilities::ParseSDL
  (opCtx,
   szArraySDL,
   pArraySDL,
   &GetArraySliceDescrSvc.m_descr);//throw

 //-----------------------------------------
 if(GetArraySliceDescrSvc.m_descr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] нулевая длина элемента массива

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#004",
    GetArraySliceDescrSvc.m_descr.m_element_blr_typeid);
 }//if

 //проверка размера буфера под элементы массива
 {
  const size_t ExpectedArraySize=GetArraySliceDescrSvc.m_descr.GetMemorySize();

  if(ExpectedArraySize!=szArrayData)
  {
   //ERROR - invalid array buffer size

   RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__InvalidBufferSize
    (c_bugcheck_src,
     L"#005",
     GetArraySliceDescrSvc.m_descr.m_relation_name.c_str(),
     GetArraySliceDescrSvc.m_descr.m_field_name.c_str(),
     szArrayData,
     ExpectedArraySize);
  }//if
 }//local

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_get_slice;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_get_slc_transaction
  packet.p_get_slc.p_get_slc__transaction=(*pTrHandle)->m_ID.get_value();

  //---------------------------------------- p_get_slc_id
  packet.p_get_slc.p_get_slc__id=ArrayID;

  //---------------------------------------- p_get_slc_length
  if(!structure::can_numeric_cast(&packet.p_get_slc.p_get_slc__length,
                                  szArrayData))
  {
   //ERROR - Too large array data

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__p13,
     ibp_mce_isc__too_large_array_slice_buffer_size_2,
     szArrayData,
     structure::get_numeric_limits(packet.p_get_slc.p_get_slc__length).max_value());
  }//if

  structure::static_numeric_cast
   (&packet.p_get_slc.p_get_slc__length,
    szArrayData);

  //---------------------------------------- p_get_slc_sdl
  RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
   (&packet.p_get_slc.p_get_slc__sdl,
    szArraySDL,
    ibp_mce_isc__too_large_sdl_buffer_size_2);

  assert(packet.p_get_slc.p_get_slc__sdl.cstr_length==szArraySDL);

  assert_s(sizeof(*packet.p_get_slc.p_get_slc__sdl.cstr_address)==sizeof(*pArraySDL));

  structure::reinterpret_ptr_cast
   (&packet.p_get_slc.p_get_slc__sdl.cstr_address,
    pArraySDL);

  //---------------------------------------- p_get_slc_parameters

  //no params
  packet.p_get_slc.p_get_slc__parameters.cstr_length=0;

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  tagOpMemoryBuffer memoryPool(szArrayData,pArrayData);

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(&GetArraySliceDescrSvc); //no throw

  //----
  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set02::op_slice)
  {
   //проверяем размер загруженных данных
   assert(packet.p_slc_data.p_slc_data__slice.lstr_length==szArrayData);

   //проверяем, что данные были загружены в буфер вызывающей стороны
   assert(packet.p_slc_data.p_slc_data__slice.lstr_address==pArrayData);

   break;
  }//if

  if(packet.operation==protocol::set02::op_response)
  {
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //мы ожидали ошибку. формально, эта проблема не связана с рассинхронизацией
   //работы порта. поэтому set_invalid_port_state вызывать не надо.

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#006",
     me_bug_check__we_expected_the_error_0);

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#007",
    packet.operation);
 }//for[ever]

 //EXIT
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
