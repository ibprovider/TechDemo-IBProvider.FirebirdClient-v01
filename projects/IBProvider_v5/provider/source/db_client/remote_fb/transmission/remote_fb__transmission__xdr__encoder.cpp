////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__encoder.cpp
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/remote_fb__array_slice_descr.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Encoder

const protocol::P_UCHAR
 RemoteFB__XDR__Encoder::sm_bytes_filler4[protocol::FB_PACKET_FIELD_ALIGN]
  ={};

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_hyper_long
                              (buf_type*                     const pBuf,
                               const protocol::P_HYPER_LONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 pBuf->write__long(pv);
}//encode__p_hyper_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_hyper_longlong
                              (buf_type*                         const pBuf,
                               const protocol::P_HYPER_LONGLONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_HYPER_LONGLONG)==2*sizeof(protocol::P_HYPER_LONG));

 const protocol::P_HYPER_LONG h
  =static_cast<protocol::P_HYPER_LONG>(((*pv)>>32)&0x00000000FFFFFFFF);

 pBuf->write__long(&h);

 const protocol::P_HYPER_LONG l
  =static_cast<protocol::P_HYPER_LONG>((*pv)&0x00000000FFFFFFFF);

 pBuf->write__long(&l);
}//encode__p_int64

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_arch
                              (buf_type*               const pBuf,
                               const protocol::P_ARCH* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 self_type::encode__p_long
  (pBuf,
   &tmp);
}//encode__p_arch

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_objct
                              (buf_type*                const pBuf,
                               const protocol::P_OBJCT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_SHORT)==sizeof(*pv));

 const protocol::P_LONG tmp=*reinterpret_cast<const protocol::P_SHORT*>(pv);

 self_type::encode__p_long
  (pBuf,
   &tmp);
}//encode__p_objct

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_short
                              (buf_type*                const pBuf,
                               const protocol::P_SHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 self_type::encode__p_long
  (pBuf,
   &tmp);
}//encode__p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_long
                              (buf_type*               const pBuf,
                               const protocol::P_LONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_LONG)==sizeof(protocol::P_HYPER_LONG));

 self_type::encode__p_hyper_long
  (pBuf,
   reinterpret_cast<const protocol::P_HYPER_LONG*>(pv));
}//encode__p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_int64
                              (buf_type*                const pBuf,
                               const protocol::P_INT64* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT64)==sizeof(protocol::P_HYPER_LONGLONG));

 self_type::encode__p_hyper_longlong
  (pBuf,
   reinterpret_cast<const protocol::P_HYPER_LONGLONG*>(pv));
}//encode__p_int64

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 self_type::encode__p_long
  (pBuf,
   &tmp);
}//encode__p_ushort

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort_as_p_long
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 self_type::encode__p_long
  (pBuf,
   &tmp);
}//encode__p_ushort_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort_as_p_short
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(*pv)==sizeof(protocol::P_SHORT));

 self_type::encode__p_short
  (pBuf,
   reinterpret_cast<const protocol::P_SHORT*>(pv));
}//encode__p_ushort_as_p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ulong_as_p_long
                              (buf_type*                const pBuf,
                               const protocol::P_ULONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_LONG)==sizeof(*pv));

 self_type::encode__p_long
  (pBuf,
   reinterpret_cast<const protocol::P_LONG*>(pv));
}//encode__p_ulong_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_float
                              (buf_type*                const pBuf,
                               const protocol::P_FLOAT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_FLOAT)==sizeof(protocol::P_LONG));

 self_type::encode__p_long
  (pBuf,
   reinterpret_cast<const protocol::P_LONG*>(pv));
}//encode__p_float

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_double
                              (buf_type*                 const pBuf,
                               const protocol::P_DOUBLE* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_DOUBLE)==sizeof(protocol::P_INT64));
 assert_s(sizeof(protocol::P_DOUBLE)==2*sizeof(protocol::P_LONG));

 const protocol::P_INT64 i64=*reinterpret_cast<const protocol::P_INT64*>(pv);

 const protocol::P_LONG h=static_cast<protocol::P_LONG>((i64>>32)&0x00000000FFFFFFFF);

 pBuf->write__long(&h);

 const protocol::P_LONG l=static_cast<protocol::P_LONG>(i64&0x00000000FFFFFFFF);

 pBuf->write__long(&l);
}//encode__p_double

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_bid(buf_type*              const pBuf,
                                           const protocol::P_BID* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 self_type::encode__p_ulong_as_p_long
  (pBuf,
   &pv->high);

 self_type::encode__p_ulong_as_p_long
  (pBuf,
   &pv->low);
}//encode__p_bid

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__opaque(buf_type*                const pBuf,
                                            size_t                   const sz,
                                            const protocol::P_UCHAR* const pv)
{
 assert(pBuf!=nullptr);

 CHECK_READ_TYPED_PTR(pv,sz);

 pBuf->write__bytes(sz,pv);

 //-----------------------------------------
 self_type::helper__write_align_cch
  (pBuf,
   sz);
}//encode__opaque

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_uint64
                              (buf_type*                 const pBuf,
                               const protocol::P_UINT64* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_UINT64)==sizeof(protocol::P_HYPER_LONGLONG));

 self_type::encode__p_hyper_longlong
  (pBuf,
   reinterpret_cast<const protocol::P_HYPER_LONGLONG*>(pv));
}//encode__p_uint64

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_int128
                              (buf_type*                 const pBuf,
                               const protocol::P_INT128* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT128)==2*sizeof(protocol::P_UINT64));

 // [2023-05-15] Just for point out. The encoders for big and little will be equal.

#if (IBP_BYTE_ORDER==IBP_BYTE_ORDER__LOW_ENDIAN)

 self_type::encode__p_uint64
  (pBuf,
   &pv->data.high);

 self_type::encode__p_uint64
  (pBuf,
   &pv->data.low);

#elif (IBP_BYTE_ORDER==IBP_BYTE_ORDER__BIG_ENDIAN)

# error Not implemented!

#else

# error Unexpected BYTE ORDER!

#endif
}//encode__p_int128

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_decfloat16
                              (buf_type*                     const pBuf,
                               const protocol::P_DECFLOAT16* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_DECFLOAT16)==sizeof(protocol::P_UINT64));

 self_type::encode__p_uint64
  (pBuf,
   &pv->value);
}//encode__p_decfloat16

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_decfloat34
                              (buf_type*                     const pBuf,
                               const protocol::P_DECFLOAT34* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_DECFLOAT34)==2*sizeof(protocol::P_UINT64));

 // [2023-05-15] Just for point out. The encoders for big and little will be equal.

#if (IBP_BYTE_ORDER==IBP_BYTE_ORDER__LOW_ENDIAN)

 self_type::encode__p_uint64
  (pBuf,
   &pv->data.high);

 self_type::encode__p_uint64
  (pBuf,
   &pv->data.low);

#elif (IBP_BYTE_ORDER==IBP_BYTE_ORDER__BIG_ENDIAN)

# error Not implemented!

#else

# error Unexpected BYTE ORDER!

#endif
}//encode__p_decfloat34

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__fb040_timestamp_with_tz
                              (buf_type*                                         const pBuf,
                               const db_obj::t_dbvalue__fb040_timestamp_with_tz* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 self_type::encode__p_long
  (pBuf,
   &pv->utc_timestamp.timestamp_date);

 self_type::encode__p_ulong_as_p_long
  (pBuf,
   &pv->utc_timestamp.timestamp_time);

 self_type::encode__p_ushort_as_p_short
  (pBuf,
   &pv->time_zone);
}//encode__fb040_timestamp_with_tz

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__fb040_time_with_tz
                              (buf_type*                                    const pBuf,
                               const db_obj::t_dbvalue__fb040_time_with_tz* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 self_type::encode__p_ulong_as_p_long
  (pBuf,
   &pv->utc_time);

 self_type::encode__p_ushort_as_p_short
  (pBuf,
   &pv->time_zone);
}//encode__fb040_time_with_tz

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__array_slice
                                           (buf_type*                const pBuf,
                                            const asd_type&                ArrSliceDescr,
                                            size_t                   const slice_size,
                                            const protocol::P_UCHAR* const slice)
{
 assert(pBuf);

 CHECK_READ_TYPED_PTR(slice,slice_size)

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__XDR__Encoder::encode__array_slice";

 //-----------------------------------------
 //Сценарий
 //1. Нужно определить количество и тип передаваемых элементов массива
 //
 //   Для этого нужно обработать SDL.
 //
 //   Формально, при этом мы можем проверить и размерность передаваемых данных.
 //
 //2. Отправляем элементы массива в порт подключения

 //----------------------------------------- 1.
 if(ArrSliceDescr.m_element_total_length==0)
 {
  //ERROR - [BUG CHECK] нулевая длина элемента

  RemoteFB__ErrorUtils::Throw_BugCheck__InvalidArray__ZeroSizeOfElement
   (c_bugcheck_src,
    L"#001",
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 if((slice_size%ArrSliceDescr.m_element_total_length)!=0)
 {
  //ERROR - Несогласованные размеры буфера и элемента массива

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__bug_check__inconsistent_sizes_of_slice_and_element_5,
    c_bugcheck_src,
    L"#002",
    slice_size,
    ArrSliceDescr.m_element_total_length,
    ArrSliceDescr.m_element_blr_typeid);
 }//if

 //const size_t nElements=slice_size/ArrSliceDescr.m_element_total_length;

 //-----------------------------------------
 typedef self_type xdr;

 assert_s(sizeof(protocol::P_UCHAR)==1);

 for(const protocol::P_UCHAR *pElement=slice,*_eElement=slice+slice_size;
     pElement!=_eElement;
     pElement+=ArrSliceDescr.m_element_total_length)
 {
  switch(ArrSliceDescr.m_element_blr_typeid)
  {
   case isc_api::ibp_isc_blr_dtype__short:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_SHORT));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_SHORT))==0);

    xdr::encode__p_short
     (pBuf,
      reinterpret_cast<const protocol::P_SHORT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__short

   case isc_api::ibp_isc_blr_dtype__long:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_LONG));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_LONG))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const protocol::P_LONG*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__long

   case isc_api::ibp_isc_blr_dtype__int64:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_INT64));

    //проверяем выравнивание. в 32-битном бинарнике может быть 4х байтное выравнивание.
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_INT64),sizeof(size_t)))==0);

    xdr::encode__p_int64
     (pBuf,
      reinterpret_cast<const protocol::P_INT64*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__int64

   case isc_api::ibp_isc_blr_dtype__float:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_FLOAT));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(protocol::P_FLOAT))==0);

    xdr::encode__p_float
     (pBuf,
      reinterpret_cast<const protocol::P_FLOAT*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__float

   case isc_api::ibp_isc_blr_dtype__double:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_DOUBLE));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%min(sizeof(protocol::P_DOUBLE),sizeof(size_t)))==0);

    xdr::encode__p_double
     (pBuf,
      reinterpret_cast<const protocol::P_DOUBLE*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__double

   case isc_api::ibp_isc_blr_dtype__sql_time:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_time));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_time))==0);

    xdr::encode__p_ulong_as_p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_time*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_time

   case isc_api::ibp_isc_blr_dtype__sql_date:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_date));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_isc_date))==0);

    xdr::encode__p_long
     (pBuf,
      reinterpret_cast<const isc_api::t_ibp_isc_date*>(pElement));

    break;
   }//case - ibp_isc_blr_dtype__sql_date

   case isc_api::ibp_isc_blr_dtype__timestamp:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_isc_timestamp));

    //проверяем выравнивание
    assert((reinterpret_cast<size_t>(&reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_date)%sizeof(isc_api::t_ibp_isc_date))==0);
    assert((reinterpret_cast<size_t>(&reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_time)%sizeof(isc_api::t_ibp_isc_time))==0);

    xdr::encode__p_long
     (pBuf,
      &reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_date);

    xdr::encode__p_ulong_as_p_long
     (pBuf,
      &reinterpret_cast<const isc_api::t_ibp_isc_timestamp*>(pElement)->timestamp_time);

    break;
   }//case - ibp_isc_blr_dtype__timestamp

   case isc_api::ibp_isc_blr_dtype__text2:
   {
    xdr::encode__opaque
     (pBuf,
      ArrSliceDescr.m_element_total_length,
      pElement);

    break;
   }//case - ibp_isc_blr_dtype__text2

   case isc_api::ibp_fb030_blr_dtype__bool:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(isc_api::t_ibp_fb030_bool));

    //checking an alignment
    assert((reinterpret_cast<size_t>(pElement)%sizeof(isc_api::t_ibp_fb030_bool))==0);

    xdr::encode__opaque
     (pBuf,
      sizeof(isc_api::t_ibp_fb030_bool),
      pElement);

    break;
   }//case - ibp_fb030_blr_dtype__bool

   case isc_api::ibp_fb040_blr_dtype__int128:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_INT128));

    //проверяем выравнивание. в 32-битном бинарнике может быть 4х байтное выравнивание.
    assert((reinterpret_cast<size_t>(pElement)%(std::min)(sizeof(protocol::P_INT128().data.low),sizeof(size_t)))==0);
    assert((reinterpret_cast<size_t>(pElement)%(std::min)(sizeof(protocol::P_INT128().data.high),sizeof(size_t)))==0);

    xdr::encode__p_int128
     (pBuf,
      reinterpret_cast<const protocol::P_INT128*>(pElement));

    break;
   }//case - ibp_fb040_blr_dtype__int128

   case isc_api::ibp_fb040_blr_dtype__decfloat16:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_DECFLOAT16));

    //проверяем выравнивание. в 32-битном бинарнике может быть 4х байтное выравнивание.
    assert((reinterpret_cast<size_t>(pElement)%(std::min)(sizeof(protocol::P_DECFLOAT16().value),sizeof(size_t)))==0);

    xdr::encode__p_decfloat16
     (pBuf,
      reinterpret_cast<const protocol::P_DECFLOAT16*>(pElement));

    break;
   }//case - ibp_fb040_blr_dtype__decfloat16

   case isc_api::ibp_fb040_blr_dtype__decfloat34:
   {
    assert(ArrSliceDescr.m_element_total_length==sizeof(protocol::P_DECFLOAT34));

    //проверяем выравнивание. в 32-битном бинарнике может быть 4х байтное выравнивание.
    assert((reinterpret_cast<size_t>(pElement)%(std::min)(sizeof(protocol::P_DECFLOAT34().data.low),sizeof(size_t)))==0);
    assert((reinterpret_cast<size_t>(pElement)%(std::min)(sizeof(protocol::P_DECFLOAT34().data.high),sizeof(size_t)))==0);

    xdr::encode__p_decfloat34
     (pBuf,
      reinterpret_cast<const protocol::P_DECFLOAT34*>(pElement));

    break;
   }//case - ibp_fb040_blr_dtype__decfloat34

   case isc_api::ibp_fb040_blr_dtype__timestamp_with_tz:
   {
    using value_type=isc_api::t_ibp_fb040_timestamp_with_tz;

    assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

    //Let's check an alignment
    assert_s(isc_api::ibp_fb040_type_align__timestamp_with_tz==4);

    assert((reinterpret_cast<size_t>(pElement)%isc_api::ibp_fb040_type_align__timestamp_with_tz)==0);

    xdr::encode__fb040_timestamp_with_tz
     (pBuf,
      reinterpret_cast<const value_type*>(pElement));

    break;
   }//case - ibp_fb040_blr_dtype__timestamp_with_tz

   case isc_api::ibp_fb040_blr_dtype__time_with_tz:
   {
    using value_type=isc_api::t_ibp_fb040_time_with_tz;

    assert(ArrSliceDescr.m_element_total_length==sizeof(value_type));

    //Let's check an alignment
    assert_s(isc_api::ibp_fb040_type_align__time_with_tz==4);

    assert((reinterpret_cast<size_t>(pElement)%isc_api::ibp_fb040_type_align__time_with_tz)==0);

    xdr::encode__fb040_time_with_tz
     (pBuf,
      reinterpret_cast<const value_type*>(pElement));

    break;
   }//case - ibp_fb040_blr_dtype__time_with_tz

   default:
   {
    //ERROR - unknown blr data type

    //ERROR - [BUG CHECK] unexpected typeID
    assert_msg(false,"typeID: "<<int(ArrSliceDescr.m_element_blr_typeid));

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_mce_isc__bug_check__unknown_blr_data_type_3,
      c_bugcheck_src,
      L"#003",
      ArrSliceDescr.m_element_blr_typeid);
   }//default
  }//switch ArrSliceDescr.m_element_blr_typeid
 }//for pElement
}//encode__array_slice

//helper methods ---------------------------------------------------------
void RemoteFB__XDR__Encoder::helper__write_align_cch(buf_type* const pBuf,
                                                     size_t    const cch)
{
 if(size_t l=(cch%protocol::FB_PACKET_FIELD_ALIGN))
 {
  assert(l>0);
  assert(l<protocol::FB_PACKET_FIELD_ALIGN);

  l=(protocol::FB_PACKET_FIELD_ALIGN-l);

  assert(l<=_DIM_(sm_bytes_filler4));

  pBuf->write__bytes(l,sm_bytes_filler4);
 }//if
}//helper__write_align_cch

////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
