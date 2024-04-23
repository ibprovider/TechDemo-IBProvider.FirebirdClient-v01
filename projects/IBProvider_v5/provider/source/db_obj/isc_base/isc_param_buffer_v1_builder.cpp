////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_param_buffer_v1_builder.cpp
//! \brief   Класс для формирования буфера с параметрами (v1).
//! \author  Kovalenko Dmitry
//! \date    28.10.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h"
#include "source/db_obj/isc_base/isc_integer_to_portable_format.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/ibp_utils.h"

#include <lcpi/lib/structure/utilities/string/string_is_null_or_empty.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_param_buffer_v1_builder

t_isc_param_buffer_v1_builder::t_isc_param_buffer_v1_builder
                                           (structure::wstr_parameter const bufTypeName)
 :m_bufTypeName(bufTypeName.str())
{
 assert(!m_bufTypeName.empty());
}//t_isc_param_buffer_v1_builder

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder::t_isc_param_buffer_v1_builder
                                           (structure::wstr_parameter const bufTypeName,
                                            byte_type                 const bufPrefix)
 :m_bufTypeName(bufTypeName.str())
{
 assert(!m_bufTypeName.empty());

 m_buffer.push_back(bufPrefix);
}//t_isc_param_buffer_v1_builder

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder::~t_isc_param_buffer_v1_builder()
{
}

//Selectors --------------------------------------------------------------
const std::wstring& t_isc_param_buffer_v1_builder::GetBufferTypeName()const
{
 return m_bufTypeName;
}//GetBufferTypeName

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder::size_type t_isc_param_buffer_v1_builder::GetBufferLength()const
{
 return m_buffer.size();
}//GetBufferLength

//------------------------------------------------------------------------
const t_isc_param_buffer_v1_builder::byte_type* t_isc_param_buffer_v1_builder::GetBuffer()
{
 return m_buffer.make_flat();
}//GetBuffer

//Append methods ---------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendTag(tag_id_type const tagID)
{
 assert_s(sizeof(tagID)==1);
 assert_s(sizeof(tag_size_type)==1);

 //----------------------------------------- 1. TAG
 m_buffer.push_back(tagID);

 //----------------------------------------- 2. LENGTH=0
 this->helper__push_length(static_cast<tag_size_type>(0));

 //----------
 return *this;
}//AppendTag

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendByte(tag_id_type const tagID,
                                           byte_type   const v)
{
 assert_s(sizeof(tagID)==1);
 assert_s(sizeof(tag_size_type)==1);
 assert_s(sizeof(v)==1);
 assert(structure::can_numeric_cast<tag_size_type>(sizeof(v)));

 //----------------------------------------- 1. TAG
 m_buffer.push_back(tagID);

 //----------------------------------------- 2. LENGTH=sizeof(v)
 this->helper__push_length(sizeof(v));

 //----------------------------------------- 3. DATA
 m_buffer.push_back(v);

 //----------
 return *this;
}//AppendByte

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendInt(tag_id_type const tagID,
                                          long_type   const v)
{
 assert_s(sizeof(tagID)==1);
 assert_s(sizeof(tag_size_type)==1);
 assert_s(sizeof(v)>0);
 assert(structure::can_numeric_cast<tag_size_type>(sizeof(v)));

 //----------------------------------------- 1. TAG
 m_buffer.push_back(tagID);

 //----------------------------------------- 2. LENGTH=sizeof(v)
 this->helper__push_length(sizeof(v));

 //----------------------------------------- 3. DATA
 {
  isc_integer_to_portable_format::tag_buffer<sizeof(v)> data;

  isc_integer_to_portable_format::exec(&data,v);

  m_buffer.write(data.data,_DIM_(data.data));
 }//local

 //----------
 return *this;
}//AppendInt

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendMbcString
                            (tag_id_type      const tagID,
                             const wchar_t*   const tagSIGN,
                             mbc_str_box_type const str)
{
 assert_s(sizeof(tagID)==1);
 assert_s(sizeof(tag_size_type)==1);
 assert(!lib::structure::string_is_null_or_empty(tagSIGN));

 CHECK_READ_TYPED_PTR(str.ptr,str.len);

 if(!structure::can_numeric_cast<tag_size_type>(str.len))
 {
  //ERROR - Генерируем  ошибку переполнения, а не обрезать строку
  this->helper__throw_error__value_is_too_large
   (tagID,
    tagSIGN,
    str.len);
 }//if

 //----------------------------------------- 1. TAG
 m_buffer.push_back(tagID);

 //----------------------------------------- 2. LENGTH
 this->helper__push_length(static_cast<tag_size_type>(str.len));

 //----------------------------------------- 3. DATA
 assert_s(sizeof(*str.ptr)==sizeof(byte_type));

 m_buffer.write(reinterpret_cast<const byte_type*>(str.ptr),str.len);

 //----------
 return *this;
}//AppendMbcString

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendMbcString
                            (tag_id_type       const tagID,
                             const wchar_t*    const tagSIGN,
                             ucs2_str_box_type const str)
{
 assert(!lib::structure::string_is_null_or_empty(tagSIGN));

 CHECK_READ_TYPED_PTR(str.ptr,str.len);

 bool error=false;

 std::string mbc_str;

 structure::tstr_to_tstr(&mbc_str,str,&error);

 if(error)
 {
  //ERROR - ошибка конвертирования
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__param_buf_builder__failed_to_translate_str_to_sys_charset_3,
    m_bufTypeName,
    int(tagID),
    tagSIGN);
 }//if

 return this->AppendMbcString
         (tagID,
          tagSIGN,
          mbc_str);
}//AppendMbcString

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendMbcString_AsUTF8
                            (tag_id_type       const tagID,
                             const wchar_t*    const tagSIGN,
                             ucs2_str_box_type const str)
{
 assert(!lib::structure::string_is_null_or_empty(tagSIGN));

 CHECK_READ_TYPED_PTR(str.ptr,str.len);

 std::string mbc_str;

 if(!ibp::IBP_Utils::WStrToUtf8__Fast(str,&mbc_str))
 {
  //ERROR - ошибка конвертирования
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_isc__param_buf_builder__failed_to_translate_str_to_utf8_3,
    m_bufTypeName,
    int(tagID),
    tagSIGN);
 }//if - ошибка конвертирования в UTF8

 return this->AppendMbcString
         (tagID,
          tagSIGN,
          mbc_str);
}//AppendMbcString_AsUTF8

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendBytes
                            (tag_id_type    const tagID,
                             const wchar_t* const tagSIGN,
                             size_t         const cb,
                             const void*    const pv)
{
 assert_s(sizeof(tagID)==1);
 assert_s(sizeof(tag_size_type)==1);
 assert(!lib::structure::string_is_null_or_empty(tagSIGN));

 CHECK_READ_PTR(pv,cb);

 if(!structure::can_numeric_cast<tag_size_type>(cb))
 {
  //ERROR - Генерируем  ошибку переполнения, а не обрезать строку
  this->helper__throw_error__value_is_too_large
   (tagID,
    tagSIGN,
    cb);
 }//if

 //----------------------------------------- 1. TAG
 m_buffer.push_back(tagID);

 //----------------------------------------- 2. LENGTH
 this->helper__push_length(static_cast<tag_size_type>(cb));

 //----------------------------------------- 3. DATA
 assert_s(1==sizeof(byte_type));

 m_buffer.write(reinterpret_cast<const byte_type*>(pv),cb);

 //----------
 return *this;
}//AppendBytes

//------------------------------------------------------------------------
t_isc_param_buffer_v1_builder&
 t_isc_param_buffer_v1_builder::AppendMultiPartParameter
                            (tag_id_type    const tagID,
                             const wchar_t* const tagSIGN,
                             size_t         const cb,
                             const void*    const pv)
{
 //разваливаем данные на последовательность блоков
 //
 // <tagSign><blockLength [1..255]><номер блока [0..255]><данные блока [0..254]>

 //------------------
 const size_t c_maxBlockCount=256;

 const size_t c_maxBlockSize=254;

 const size_t c_maxDataSize=c_maxBlockCount*c_maxBlockSize;

 if(cb==0)
 {
  //---------------------------------------- 1. TAG
  m_buffer.push_back(tagID);

  //---------------------------------------- 2. LENGTH
  this->helper__push_length(static_cast<tag_size_type>(1));

  //---------------------------------------- 3. BLOCK_INDEX
  m_buffer.push_back(0);

  //---------------------------------------- 4. DATA

  //данных нет.

  //----------------------------------------
  return *this;
 }//if cb==0

 assert(cb>0);

 if(c_maxDataSize<cb)
 {
  this->helper__throw_error__value_is_too_large
   (tagID,
    tagSIGN,
    cb);
 }//if

 size_t cbSrc=cb;

 const void* pSrc=pv;

 for(byte_type nBlock=0;;)
 {
  assert(cbSrc>0);

  assert(nBlock<c_maxBlockCount);

  const size_t cbBlock=min(cbSrc,c_maxBlockSize);

  //---------------------------------------- 1. TAG
  m_buffer.push_back(tagID);

  //---------------------------------------- 2. LENGTH
  this->helper__push_length(static_cast<tag_size_type>(cbBlock+1));

  //---------------------------------------- 3. BLOCK_INDEX
  m_buffer.push_back(nBlock);

  //---------------------------------------- 4. DATA
  assert_s(1==sizeof(byte_type));

  m_buffer.write(reinterpret_cast<const byte_type*>(pSrc),cbBlock);

  //----------------------------------------
  cbSrc-=cbBlock;

  if(cbSrc==0)
   break;

  pSrc=reinterpret_cast<const byte_type*>(pSrc)+cbBlock;

  assert(nBlock!=structure::get_numeric_limits(nBlock).max_value());

  ++nBlock;
 }//for[ever]

 assert(cbSrc==0);

 return *this;
}//AppendMultiPartParameter

//helper methods ---------------------------------------------------------
void t_isc_param_buffer_v1_builder::helper__push_length
                                           (tag_size_type const valueSize)
{
 assert_s(sizeof(valueSize)==1);

 m_buffer.push_back(valueSize);
}//helper__push_length

//------------------------------------------------------------------------
void t_isc_param_buffer_v1_builder::helper__throw_error__value_is_too_large
                                           (tag_id_type    const tagID,
                                            const wchar_t* const tagSIGN,
                                            size_t         const valueSize)const
{
 assert(!lib::structure::string_is_null_or_empty(tagSIGN));

 assert_s(1==sizeof(tagID));

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__param_buf_builder__value_is_too_large_5,
   m_bufTypeName,
   int(tagID),
   tagSIGN,
   valueSize,
   structure::t_numeric_limits<tag_size_type>().max_value());
}//helper__throw_error__value_is_too_large

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
