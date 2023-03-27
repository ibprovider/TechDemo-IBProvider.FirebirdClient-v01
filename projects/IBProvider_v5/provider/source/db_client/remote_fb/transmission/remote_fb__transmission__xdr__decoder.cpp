////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__decoder.cpp
//! \brief   Утилиты для распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_obj/dbms_fb/common/api/errors/set02/db_obj__dbms_fb__common__api__errors__set02__scodes.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_tmp_seg_buffer.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Decoder

void RemoteFB__XDR__Decoder::decode__p_arch
                              (buf_type*         const pBuf,
                               const wchar_t*    const /*pv_sign*/,
                               protocol::P_ARCH* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 //проверяем идентичность типов
 assert_s(sizeof(protocol::P_ARCH)==sizeof(protocol::P_LONG));

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&tmp); //throw

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

 pBuf->read__long(&tmp); //throw

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

 pBuf->read__long(&tmp); //throw

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
                               const wchar_t*    const DEBUG_CODE(pv_sign),
                               protocol::P_LONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&tmp); //throw

 (*pv)=tmp;
}//decode__p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_int64
                              (buf_type*          const pBuf,
                               const wchar_t*     const DEBUG_CODE(pv_sign),
                               protocol::P_INT64* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT64)==2*sizeof(protocol::P_LONG));

 protocol::P_LONG h DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&h);

 protocol::P_LONG l DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&l);

 //-----
 protocol::P_INT64 tmp=(static_cast<protocol::P_INT64>(h)<<32);

 tmp|=static_cast<protocol::P_INT64>(l)&0x00000000FFFFFFFF;

 (*pv)=tmp;
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

 pBuf->read__long(&tmp); //throw

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
                               const wchar_t*     const DEBUG_CODE(pv_sign),
                               protocol::P_ULONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_ULONG)==sizeof(protocol::P_LONG));

 protocol::P_ULONG tmp DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(reinterpret_cast<protocol::P_LONG*>(&tmp)); //throw

 (*pv)=tmp;
}//decode__p_ulong_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Decoder::decode__p_float
                              (buf_type*          const pBuf,
                               const wchar_t*     const DEBUG_CODE(pv_sign),
                               protocol::P_FLOAT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(*pv)==sizeof(protocol::P_LONG));

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&tmp); //throw

 (*reinterpret_cast<protocol::P_LONG*>(pv))=tmp;
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

 //выделяем память с резервированием места под терминальный нулевой символ

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
 //!  Обрабатываем scodes из пространства имен ibp::db_obj::dbms_fb::common::api::errors::set02.

 namespace fb_api_eset02=ibp::db_obj::dbms_fb::common::api::errors::set02;

 //алгоритм декодирования статус-вектора гарантирует его корректную структуру.
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

 //копирование загруженных данных в буфер получателя.

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

#if 0 // [2015-12-06] Проблемы с 10-ым протоколом

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
