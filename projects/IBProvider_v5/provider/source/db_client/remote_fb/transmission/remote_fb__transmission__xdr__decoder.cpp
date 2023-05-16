////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__decoder.cpp
//! \brief   ”тилиты дл€ распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_client/remote_fb/remote_fb__array_slice_descr.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/dbms_fb/common/api/errors/set02/db_obj__dbms_fb__common__api__errors__set02__scodes.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_tmp_seg_buffer.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Decoder

void RemoteFB__XDR__Decoder::decode__p_hyper_long
                              (buf_type*               const pBuf,
                               const wchar_t*          const DEBUG_CODE(pv_sign),
                               protocol::P_HYPER_LONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 pBuf->read__long(pv); //throw
}//decode__p_hyper_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_hyper_longlong
                              (buf_type*                   const pBuf,
                               const wchar_t*              const DEBUG_CODE(pv_sign),
                               protocol::P_HYPER_LONGLONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_HYPER_LONGLONG)==2*sizeof(protocol::P_HYPER_LONG));

 protocol::P_HYPER_LONG h DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&h);

 protocol::P_HYPER_LONG l DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&l);

 //-----
 protocol::P_HYPER_LONGLONG tmp=(static_cast<protocol::P_HYPER_LONGLONG>(h)<<32);

 tmp|=static_cast<protocol::P_HYPER_LONGLONG>(l)&0x00000000FFFFFFFF;

 (*pv)=tmp;
}//decode__p_hyper_longlong

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_arch
                              (buf_type*         const pBuf,
                               const wchar_t*    const pv_sign,
                               protocol::P_ARCH* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 //провер€ем идентичность типов
 assert_s(sizeof(protocol::P_ARCH)==sizeof(protocol::P_LONG));

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 self_type::decode__p_long
  (pBuf,
   pv_sign,
   &tmp); //throw

 (*pv)=(protocol::P_ARCH)tmp;
}//decode__p_arch

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_objct
                              (buf_type*          const pBuf,
                               const wchar_t*     const pv_sign,
                               protocol::P_OBJCT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 self_type::decode__p_long
  (pBuf,
   pv_sign,
   &tmp); //throw

 assert_s(sizeof(protocol::P_SHORT)==sizeof(*pv));

 if(!structure::can_numeric_cast(reinterpret_cast<protocol::P_SHORT*>(pv),tmp))
 {
  // ERROR - загружены некорректные OBJCT-данные

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_remote__receive_pack__xdr__bad_data_3,
    pv_sign,
    L"objct",
    tmp);
 }//if

 structure::static_numeric_cast(reinterpret_cast<protocol::P_SHORT*>(pv),tmp);
}//decode__p_objct

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_short
                              (buf_type*          const pBuf,
                               const wchar_t*     const pv_sign,
                               protocol::P_SHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 self_type::decode__p_long
  (pBuf,
   pv_sign,
   &tmp); //throw

 if(!structure::can_numeric_cast(pv,tmp))
 {
  // ERROR - загружено некорректное SHORT-значение

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_remote__receive_pack__xdr__bad_data_3,
    pv_sign,
    L"short",
    tmp);
 }//if

 structure::static_numeric_cast(pv,tmp);
}//decode__p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_long
                              (buf_type*         const pBuf,
                               const wchar_t*    const pv_sign,
                               protocol::P_LONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_LONG)==sizeof(protocol::P_HYPER_LONG));

 self_type::decode__p_hyper_long
  (pBuf,
   pv_sign,
   reinterpret_cast<protocol::P_HYPER_LONG*>(pv));
}//decode__p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_int64
                              (buf_type*          const pBuf,
                               const wchar_t*     const pv_sign,
                               protocol::P_INT64* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT64)==sizeof(protocol::P_HYPER_LONGLONG));

 self_type::decode__p_hyper_longlong
  (pBuf,
   pv_sign,
   reinterpret_cast<protocol::P_HYPER_LONGLONG*>(pv));
}//decode__p_int64

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_ushort
                              (buf_type*           const pBuf,
                               const wchar_t*      const pv_sign,
                               protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 self_type::decode__p_long
  (pBuf,
   pv_sign,
   &tmp); //throw

 if(!structure::can_numeric_cast(pv,tmp))
 {
  // ERROR - загружено некорректное USHORT-значение

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_remote__receive_pack__xdr__bad_data_3,
    pv_sign,
    L"ushort",
    tmp);
 }//if

 structure::static_numeric_cast(pv,tmp);
}//decode__p_ushort

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_ushort_as_p_short
                              (buf_type*           const pBuf,
                               const wchar_t*      const pv_sign,
                               protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_USHORT)==sizeof(protocol::P_SHORT));

 self_type::decode__p_short
  (pBuf,
   pv_sign,
   reinterpret_cast<protocol::P_SHORT*>(pv));
}//decode__p_ushort_as_p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_ulong_as_p_long
                              (buf_type*          const pBuf,
                               const wchar_t*     const pv_sign,
                               protocol::P_ULONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_ULONG)==sizeof(protocol::P_LONG));

 self_type::decode__p_long
  (pBuf,
   pv_sign,
   reinterpret_cast<protocol::P_LONG*>(pv));
}//decode__p_ulong_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_float
                              (buf_type*          const pBuf,
                               const wchar_t*     const pv_sign,
                               protocol::P_FLOAT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(*pv)==sizeof(protocol::P_LONG));

 self_type::decode__p_long
  (pBuf,
   pv_sign,
   reinterpret_cast<protocol::P_LONG*>(pv));
}//decode__p_float

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_double
                              (buf_type*           const pBuf,
                               const wchar_t*      const DEBUG_CODE(pv_sign),
                               protocol::P_DOUBLE* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT64)==sizeof(protocol::P_DOUBLE));
 assert_s(sizeof(protocol::P_INT64)==2*sizeof(protocol::P_LONG));

 protocol::P_LONG h DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&h);

 protocol::P_LONG l DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&l);

 //-----
 protocol::P_INT64 tmp=(static_cast<protocol::P_INT64>(h)<<32);

 tmp|=static_cast<protocol::P_INT64>(l)&0x00000000FFFFFFFF;

 (*pv)=*reinterpret_cast<const protocol::P_DOUBLE*>(&tmp);
}//decode__p_double

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_bid
                              (buf_type*        const pBuf,
                               const wchar_t*   const pv_sign1__quad_high,
                               const wchar_t*   const pv_sign2__quad_low,
                               protocol::P_BID* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign1__quad_high!=nullptr);
 assert(pv_sign2__quad_low!=nullptr);
 assert(pv!=nullptr);

 //-----------------------------------------
 protocol::P_BID tmp_v;

 self_type::decode__p_ulong_as_p_long
  (pBuf,
   pv_sign1__quad_high,
   &tmp_v.high);

 self_type::decode__p_ulong_as_p_long
  (pBuf,
   pv_sign2__quad_low,
   &tmp_v.low);

 //-----------------------------------------
 (*pv)=tmp_v;
}//decode__p_bid

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__opaque(buf_type*          const pBuf,
                                            const wchar_t*     const pv_sign,
                                            size_t             const sz,
                                            protocol::P_UCHAR* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);

 CHECK_WRITE_PTR(pv,sz);

 //-----------------------------------------
 pBuf->read__bytes
  (sz,
   pv);

 //-----------------------------------------
 self_type::helper__read_align_uchars
  (pBuf,
   pv_sign,
   sz);
}//decode__opaque

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__string
                              (buf_type*           const pBuf,
                               mem_type*           const pMem,
                               mem_id_type         const memID,
                               const wchar_t*      const pv_sign,
                               protocol::P_ULONG   const maxLength,
                               protocol::P_ULONG*  const pcchData,
                               protocol::P_UCHAR** const ppszData)
{
 assert(pBuf!=nullptr);
 assert(pMem!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pcchData!=nullptr);
 assert(ppszData!=nullptr);

 typedef protocol::P_UCHAR char_type;

 (*pcchData)=0;
 (*ppszData)=nullptr;

 //-----------------------------------------
 protocol::P_ULONG tmp_cchData;

 self_type::decode__p_ulong_as_p_long
  (pBuf,
   pv_sign,
   &tmp_cchData);

 if(maxLength<tmp_cchData)
 {
  //ERROR - Length of string is too long!

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_remote__receive_pack__xdr__str_too_long_3,
    pv_sign,
    tmp_cchData,
    maxLength);
 }//if

 //выдел€ем пам€ть с резервированием места под терминальный нулевой символ

 const size_t c_maxCCH
  =(structure::t_numeric_limits<size_t>::max_value()/sizeof(char_type));

 assert(c_maxCCH>1);

 if(!(tmp_cchData<c_maxCCH))
 {
  IBP_ErrorUtils::Throw__Error
   (E_OUTOFMEMORY,
    ibp_subsystem__remote_fb,
    ibp_mce_remote__receive_pack__xdr__str_too_long_3,
    pv_sign,
    tmp_cchData,
    (c_maxCCH-1));
 }//if

 assert(tmp_cchData<c_maxCCH);

 protocol::P_UCHAR* const tmp_pszData
  =RemoteFB__AllocPacketMemory<protocol::P_UCHAR>
    (pMem,
     memID,
     size_t(tmp_cchData)+1); //throw

 assert(tmp_pszData!=nullptr);

 pBuf->read__bytes(tmp_cchData,
                   tmp_pszData); //throw

 tmp_pszData[tmp_cchData]=0;

 self_type::helper__read_align_uchars
  (pBuf,
   pv_sign,
   tmp_cchData);

 //-----------------------------------------
 (*pcchData)=tmp_cchData;
 (*ppszData)=tmp_pszData;
}//decode__string

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_uint64
                              (buf_type*           const pBuf,
                               const wchar_t*      const pv_sign,
                               protocol::P_UINT64* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_UINT64)==sizeof(protocol::P_HYPER_LONGLONG));

 self_type::decode__p_hyper_longlong
  (pBuf,
   pv_sign,
   reinterpret_cast<protocol::P_HYPER_LONGLONG*>(pv));
}//decode__p_uint64

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_int128
                              (buf_type*           const pBuf,
                               const wchar_t*      const pv_sign_low,
                               const wchar_t*      const pv_sign_high,
                               protocol::P_INT128* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign_low!=nullptr);
 assert(pv_sign_high!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT128)==2*sizeof(protocol::P_UINT64));

 // [2023-05-15] Just for point out. The decoders for big and little will be equal.

#if (IBP_BYTE_ORDER==IBP_BYTE_ORDER__LOW_ENDIAN)

 self_type::decode__p_uint64
  (pBuf,
   pv_sign_high,
   &pv->data.high);

 self_type::decode__p_uint64
  (pBuf,
   pv_sign_low,
   &pv->data.low);

#elif (IBP_BYTE_ORDER==IBP_BYTE_ORDER__BIG_ENDIAN)

# error Not implemented!

#else

# error Unexpected BYTE ORDER!

#endif
}//decode__p_int128

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__status_vector__eset02
                              (buf_type*                      const pBuf,
                               mem_type*                      const pMem,
                               mem_id_type                    const memID,
                               size_t                         const maxSize,
                               const wchar_t*                 const pv_sign,
                               protocol::P_ISC_STATUS_VECTOR* const pv)
{
 assert(pBuf!=nullptr);
 assert(pMem!=nullptr);
 assert(maxSize>0);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 //! \note
 //!  ќбрабатываем scodes из пространства имен ibp::db_obj::dbms_fb::common::api::errors::set02.

 namespace fb_api_eset02=ibp::db_obj::dbms_fb::common::api::errors::set02;

 //алгоритм декодировани€ статус-вектора гарантирует его корректную структуру.
 // - последний элемент будет равен нулю (tagID==0)
 // - содержит последовательности групп <tagID><tagDATA>

 typedef structure::t_tmp_seg_buffer
          <protocol::P_ISC_STATUS,
           _DIM_(pv->inplace_sv_buffer),
           RemoteFB__MemoryAllocator>       local_buf_type;

 local_buf_type local_buf;

 protocol::P_LONG s;

 for(;;)
 {
  if(local_buf.size()==maxSize)
  {
   //ERROR - длина статус-вектора превышает максимальную

   helper__throw_err__status_vector_is_too_long(pv_sign,maxSize,L"#E01");
  }//if

  //---------------------------------------- 1. читаем идентификатор
  self_type::decode__p_long
   (pBuf,
    L"status_vector tag",
    &s); //throw

  assert(structure::can_numeric_cast<local_buf_type::value_type>(s));

  local_buf.push_back(s);

  if(s==fb_api_eset02::ibp_fb_scode__arg_end)
   break;

  //---------------------------------------- 2. читаем данные
  switch(s)
  {
   case fb_api_eset02::ibp_fb_scode__arg_interpreted:
   case fb_api_eset02::ibp_fb_scode__arg_string:
   case fb_api_eset02::ibp_fb_scode__arg_sql_state:
   {
    if(local_buf.size()==maxSize)
    {
     //ERROR - длина статус-вектора превышает максимальную

     helper__throw_err__status_vector_is_too_long(pv_sign,maxSize,L"#E02");
    }//if

    protocol::P_ULONG  elementLength =0;
    protocol::P_UCHAR* elementData   =nullptr;

    self_type::decode__string
     (pBuf,
      pMem,
      mem_type::mem_id__status_vector_string,
      L"status_vector string",
      protocol::FB_MAX_STATUS_VECTOR_STR_DATA_LENGTH,
      &elementLength,
      &elementData); //throw

    assert(elementData!=nullptr);

    assert_s(sizeof(local_buf_type::value_type)==sizeof(elementData));

    local_buf.push_back(reinterpret_cast<local_buf_type::value_type>(elementData));

    break;
   }//case interpreted, string, sql_state

   case fb_api_eset02::ibp_fb_scode__arg_gds:
   case fb_api_eset02::ibp_fb_scode__arg_warning:
   case fb_api_eset02::ibp_fb_scode__arg_win32:
   case fb_api_eset02::ibp_fb_scode__arg_unix:
   case fb_api_eset02::ibp_fb_scode__arg_next_mach:
   case fb_api_eset02::ibp_fb_scode__arg_dos:
   case fb_api_eset02::ibp_fb_scode__arg_number:
   {
    if(local_buf.size()==maxSize)
    {
     //ERROR - длина статус-вектора превышает максимальную

     helper__throw_err__status_vector_is_too_long(pv_sign,maxSize,L"#E03");
    }//if

    self_type::decode__p_long
     (pBuf,
      L"status_vector numeric",
      &s);

    assert(structure::can_numeric_cast<local_buf_type::value_type>(s));

    local_buf.push_back(s);

    break;
   }//case numeric value

   default:
   {
    //ERROR - Unexpected status vector argID

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_subsystem__remote_fb,
      ibp_mce_remote__receive_pack__unexpected_arg_in_status_vector_2,
      pv_sign,
      s);
   }//default
  }//switch

  /*go to next fetch*/
 }//for[ever]

 assert(!local_buf.empty());

 //-----------------------------------------
 protocol::P_ISC_STATUS* pTarget DEBUG_CODE(=nullptr);

 if(_DIM_(pv->inplace_sv_buffer)<local_buf.size())
 {
  pTarget
   =RemoteFB__AllocPacketMemory<protocol::P_ISC_STATUS>
     (pMem,
      memID,
      local_buf.size());
 }
 else
 {
  assert(local_buf.size()<=_DIM_(pv->inplace_sv_buffer));

  pTarget
   =pv->inplace_sv_buffer;
 }//else

 assert(pTarget);

 pv->ptr  =pTarget;
 pv->size =local_buf.size();

 //копирование загруженных данных в буфер получател€.

 DEBUG_CODE(pv->debug__check_state();)

 _VERIFY(structure::copy
          (local_buf.cbegin(),
           local_buf.cend(),
           pTarget,
           pTarget+pv->size)
         DEBUG_CODE(==std::make_pair
                       (local_buf.cend(),
                        pTarget+pv->size)));
}//decode__status_vector__eset02

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__array_slice
                              (buf_type*          const pBuf,
                               const asd_type&          ArrSliceDescr,
                               size_t             const szSlice,
                               protocol::P_UCHAR* const pSlice)
{
 assert(pBuf);

 CHECK_WRITE_TYPED_PTR(pSlice,szSlice);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__XDR__Decoder::decode__array_slice";

 //-----------------------------------------
 if(ArrSliceDescr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] нулева€ длина элемента массива

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#001",
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 if((szSlice%ArrSliceDescr.m_element_total_length)!=0)
 {
  //ERROR - [BUG CHECK] несогласованные размеры буфера и элемента массива

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__bug_check__inconsistent_sizes_of_slice_and_element_5,
    c_bugcheck_src,
    L"#002",
    szSlice,
    ArrSliceDescr.m_element_total_length,
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 //-----------------------------------------
 typedef self_type xdr;

 //-----------------------------------------
 assert_s(sizeof(protocol::P_UCHAR)==1);

 protocol::P_UCHAR* pElement=pSlice;

 protocol::P_UCHAR* _eElement=pSlice+szSlice;

 try
 {
  for(;pElement!=_eElement;pElement+=ArrSliceDescr.m_element_total_length)
  {
   switch(ArrSliceDescr.m_element_blr_typeid)
   {
    case isc_api::ibp_isc_blr_dtype__short:
    {
     typedef protocol::P_SHORT              value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_short
      (pBuf,
       L"array_slice.short",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__short

    case isc_api::ibp_isc_blr_dtype__long:
    {
     typedef protocol::P_LONG               value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_long
      (pBuf,
       L"array_slice.long",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__long

    case isc_api::ibp_isc_blr_dtype__int64:
    {
     typedef protocol::P_INT64              value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%min(sizeof(value_type),sizeof(size_t)))==0);

     xdr::decode__p_int64
      (pBuf,
       L"array_slice.int64",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__int64

    case isc_api::ibp_isc_blr_dtype__float:
    {
     typedef protocol::P_FLOAT              value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_float
      (pBuf,
       L"array_slice.float",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__float

    case isc_api::ibp_isc_blr_dtype__double:
    {
     typedef protocol::P_DOUBLE             value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%min(sizeof(value_type),sizeof(size_t)))==0);

     xdr::decode__p_double
      (pBuf,
       L"array_slice.double",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__double

    case isc_api::ibp_isc_blr_dtype__sql_date:
    {
     typedef isc_api::t_ibp_isc_date        value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_long
      (pBuf,
       L"array_slice.sql_date",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__sql_date

    case isc_api::ibp_isc_blr_dtype__sql_time:
    {
     typedef isc_api::t_ibp_isc_time        value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__p_ulong_as_p_long
      (pBuf,
       L"array_slice.sql_time",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_isc_blr_dtype__sql_time

    case isc_api::ibp_isc_blr_dtype__timestamp:
    {
     typedef isc_api::t_ibp_isc_timestamp   value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(&reinterpret_cast<value_type*>(pElement)->timestamp_date)%sizeof(isc_api::t_ibp_isc_date))==0);
     assert((reinterpret_cast<size_t>(&reinterpret_cast<value_type*>(pElement)->timestamp_time)%sizeof(isc_api::t_ibp_isc_time))==0);

     xdr::decode__p_long
      (pBuf,
       L"array_slice.timestamp.date",
       &reinterpret_cast<value_type*>(pElement)->timestamp_date);

     xdr::decode__p_ulong_as_p_long
      (pBuf,
       L"array_slice.timestamp.time",
       &reinterpret_cast<value_type*>(pElement)->timestamp_time);

     break;
    }//case - ibp_isc_blr_dtype__timestamp

    case isc_api::ibp_isc_blr_dtype__text2:
    {
     xdr::decode__opaque
      (pBuf,
       L"array_slice.text2",
       ArrSliceDescr.m_element_total_length,
       pElement);

     break;
    }//isc_api::ibp_isc_blr_dtype__text2

    case isc_api::ibp_fb030_blr_dtype__bool:
    {
     typedef isc_api::t_ibp_fb030_bool value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%sizeof(value_type))==0);

     xdr::decode__opaque
      (pBuf,
       L"array_slice.boolean",
       sizeof(value_type),
       pElement);

     break;
    }//case - ibp_fb030_blr_dtype__bool

    case isc_api::ibp_fb040_blr_dtype__int128:
    {
     typedef protocol::P_INT128 value_type;

     assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

     assert((reinterpret_cast<size_t>(pElement)%min(sizeof(value_type),sizeof(size_t)))==0);

     xdr::decode__p_int128
      (pBuf,
       L"array_slice.int128.low",
       L"array_slice.int128.high",
       reinterpret_cast<value_type*>(pElement));

     break;
    }//case - ibp_fb040_blr_dtype__int128

    default:
    {
     //ERROR - [BUG CHECK] unexpected typeID
     assert_msg(false,"typeID: "<<int(ArrSliceDescr.m_element_blr_typeid));

     IBP_ErrorUtils::Throw__Error
      (E_FAIL,
       ibp_mce_isc__unk_blr_data_type_1,
       ArrSliceDescr.m_element_blr_typeid);
    }//default
   }//switch
  }//for[ever]
 }
 catch(const std::exception& e)
 {
  //ƒобавл€ем информацию о пор€дковом номере элемента массива

  IBP_ErrorUtils::Throw__Error
   (e,
    E_FAIL,
    ibp_subsystem__remote_fb,
    ibp_mce_remote__decode_packet__xdr__error_in_element_of_slice_data_buffer_1,
    size_t(pElement-pSlice));
 }//catch
}//decode__array_slice

//helper methods ---------------------------------------------------------
void RemoteFB__XDR__Decoder::helper__read_align_uchars
                              (buf_type*      const pBuf,
                               const wchar_t* const DEBUG_CODE(pv_sign),
                               size_t         const cch)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);

 //const wchar_t* const c_bugcheck_src
 // =L"RemoteFB__XDR__Decoder::helper__read_align_uchars";

 if(size_t l=(cch%protocol::FB_PACKET_FIELD_ALIGN))
 {
  assert(l>0);
  assert(l<protocol::FB_PACKET_FIELD_ALIGN);

  l=(protocol::FB_PACKET_FIELD_ALIGN-l);

  assert(l>0);

  protocol::P_UCHAR trash[protocol::FB_PACKET_FIELD_ALIGN];

  assert(l<=_DIM_(trash));

  pBuf->read__bytes(l,trash);

#if 0 // [2015-12-06] ѕроблемы с 10-ым протоколом

  //Check of trash
  for(size_t i=0;i!=l;++i)
  {
   if(trash[i]==0)
    continue;

   structure::wstr_formatter freason(me_bug_check__garbage_in_alignment_bytes_1);

   freason<<pv_sign;

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#001",
     freason.c_str());
  }//for i
#endif
 }//if l
}//helper__read_align_uchars

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::helper__throw_err__status_vector_is_too_long
                                           (const wchar_t* const pv_sign,
                                            size_t         const MaxLength,
                                            const wchar_t* const check_point)
{
 assert(pv_sign);
 assert(check_point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_subsystem__remote_fb,
   ibp_mce_remote__receive_pack__status_vector_is_too_long_3,
   pv_sign,
   MaxLength,
   check_point);
}//helper__throw_err__status_vector_is_too_long

////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
