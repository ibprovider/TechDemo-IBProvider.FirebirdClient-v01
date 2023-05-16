////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8.cpp
//! \brief   ”правл€ющий класс дл€ кодовых страниц BIT8
//! \author  Kovalenko Dmitry
//! \date    27.09.2005
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_bit8__text_stream__mbc_to_ucs2.h"
#include "source/charsets/cs_code/ibp_cs_bit8__text_stream__mbc_buffer_to_ucs2.h"
#include "source/charsets/cs_code/ibp_cs_bit8__text_stream__ucs2_to_mbc.h"
#include "source/charsets/ibp_charset_const.h"
#include "source/db_obj/db_blob_writer.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/ibp_limits.h"
#include <structure/t_memory.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8

t_ibp_cs_bit8::t_ibp_cs_bit8(const db_obj::t_db_charset_info& charset_info,
                             const data_type*           const data)
 :m_charset_info(charset_info)
 ,m_data(data)
{
 assert(m_data!=NULL);
}

//------------------------------------------------------------------------
t_ibp_cs_bit8::~t_ibp_cs_bit8()
{
}

//t_ibp_charset interface ------------------------------------------------
const db_obj::t_db_charset_info& t_ibp_cs_bit8::get_info()const
{
 return m_charset_info;
}//charset_info

//------------------------------------------------------------------------
bool t_ibp_cs_bit8::to_unicode_v2(std::wstring*              const pws,
                                  structure::t_const_str_box const s)const
{
 assert(pws);

 CHECK_READ_TYPED_PTR(s.ptr,s.len);

 //-------
 pws->clear();

 pws->reserve(s.len);

 //-------
 assert_s(sizeof(uchar_type)==sizeof(*s.ptr));

 const uchar_type*       i_s=reinterpret_cast<const uchar_type*>(s.ptr);
 const uchar_type* const e_s=i_s+s.len;

 //-------
 assert(m_data!=NULL);
 assert(m_data->to_unicode_map!=NULL);

 for(;i_s!=e_s;++i_s)
 {
  //—огласно уверени€м в исходниках FireBird 1.5.2
  // нам не нужно контролировать ошибки конвертировани€
  // все символы должны конвертироватьс€ в UNICODE

  assert(int(*i_s)>=0);
  assert(int(*i_s)<int(_DIM_(*m_data->to_unicode_map)));

  pws->push_back((*m_data->to_unicode_map)[*i_s]);
 }//for

 return true;
}//to_unicode_v2

//------------------------------------------------------------------------
bool t_ibp_cs_bit8::from_unicode_v2(std::string*                const ps,
                                    structure::t_const_wstr_box const ws)const
{
 assert(ps);

 CHECK_READ_TYPED_PTR(ws.ptr,ws.len);

 //----------
 ps->clear();

 ps->reserve(ws.len);

 //----------
 assert(m_data!=NULL);
 assert(m_data->from_unicode_map!=NULL);

 CHECK_READ_TYPED_PTR(m_data->from_unicode_mapping_array,
                      m_data->from_unicode_mapping_array_size);

 assert(_DIM_(*m_data->from_unicode_map)==256);

 assert_s(sizeof(wchar_t)==sizeof(ushort_type));

 const ushort_type*       i_ws=reinterpret_cast<const ushort_type*>(ws.ptr);
 const ushort_type* const e_ws=i_ws+ws.len;

 for(;i_ws!=e_ws;++i_ws)
 {
  const ushort_type wc=*i_ws;

  assert(int(wc)>=0);
  assert(int(wc/256)<int(_DIM_(*m_data->from_unicode_map)));

  const size_type n=(*m_data->from_unicode_map)[wc/256]+(wc%256);

  assert_msg(n<m_data->from_unicode_mapping_array_size,"n=="<<n);

  const char ch=(m_data->from_unicode_mapping_array)[n];

  if(ch==IBP_CS_BIT8_CANT_MAP_CHARACTER && wc!=IBP_CS_BIT8_CANT_MAP_CHARACTER)
   return false;

  ps->push_back(ch);
 }//for i_ws

 return true;
}//from_unicode_v2

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_bit8::mbc_stream_to_ucs2_stream(db_obj::t_db_text_stream__mbc* const mbc_stream)const
{
 if(mbc_stream==NULL)
  return nullptr;

 return structure::not_null_ptr(new tag_text_stream__mbc_to_ucs2(this,mbc_stream));
}//mbc_stream_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_bit8::mbc_buffer_to_ucs2_stream(const char* const mbc_buffer,
                                          size_type   const mbc_buffer_size)const
{
 CHECK_READ_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 return structure::not_null_ptr(new tag_text_stream__mbc_buffer_to_ucs2(this,mbc_buffer,mbc_buffer_size));
}//mbc_buffer_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__mbc_ptr
 t_ibp_cs_bit8::ucs2_stream_to_mbc_stream(db_obj::t_db_text_stream__ucs2* const ucs2_stream)const
{
 if(ucs2_stream==NULL)
  return nullptr;

 return structure::not_null_ptr(new tag_text_stream__ucs2_to_mbc(this,ucs2_stream));
}//ucs2_stream_to_mbc_stream

//------------------------------------------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_bit8::sb_to_unicode(ansi_streambuf_type& in_buf,
                              wchar_t*       const ws,
                              size_type&           wsz)const
{
 CHECK_WRITE_TYPED_PTR(ws,wsz)

 const size_type original_wsz=wsz;

 wsz=0;

 //------
 assert(m_data!=NULL);
 assert(m_data->to_unicode_map!=NULL);

 ansi_streambuf_type::value_type sc;

 assert_s(sizeof(sc)==sizeof(uchar_type));

 for(;wsz!=original_wsz;++wsz)
 {
  if(!in_buf.get(&sc))
   return db_obj::db_cs_result__ok;

  const uchar_type c=static_cast<uchar_type>(sc);

  assert(int(c)>=0);
  assert(int(c)<int(_DIM_(*m_data->to_unicode_map)));

  ws[wsz]=(*m_data->to_unicode_map)[c];
 }//for

 if(in_buf.eof())
  return db_obj::db_cs_result__ok; //выбрали все данные из буфера

 return db_obj::db_cs_result__trunc; //в буфере остались данные
}//sb_to_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_bit8::sb_len_as_unicode(ansi_streambuf_type& in_buf,size_type& wsz)const//abstract
{
 wsz=0;

 const size_type c_max_wsz=structure::t_numeric_limits<size_type>::max_value();

 //один байт - один UNICODE символ

 //! \todo
 //!  ѕеределать на skipn или skip_all

 while(in_buf.skip())
 {
  if(wsz==c_max_wsz)
  {
   //ERROR - переполнение при вычислении размера UNICODE-представлени€ данных
   IBP_ErrorUtils::Throw__Error
    (DB_E_DATAOVERFLOW,
     ibp_mce_cs__calc_length_in_ucs2_chars__overflow_1,
     this->get_info().name);
  }//if

  ++wsz;
 }//while

 return true;
}//sb_len_as_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_bit8::unicode_to_blob(const wchar_t*                        source,
                                    size_type                       const source_size,
                                    db_obj::t_db_seq_stream_writer* const writer)const
{
 assert(writer);

 CHECK_READ_TYPED_PTR(source,source_size);

 //-----
 char  out_buffer[8*1024];
 char* out=out_buffer;

 const char* const out_end=_END_(out_buffer);

 for(const wchar_t* const source_end=source+source_size;
     source!=source_end;
     ++source)
 {
  const ushort_type wc=*source;

  assert(int(wc)>=0);
  assert(int(wc/256)<int(_DIM_(*m_data->from_unicode_map)));

  //---------
  const size_type n=(*m_data->from_unicode_map)[wc/256]+(wc%256);

  assert(n<m_data->from_unicode_mapping_array_size);

  //---------
  const uchar_type c=(m_data->from_unicode_mapping_array)[n];

  if(c==IBP_CS_BIT8_CANT_MAP_CHARACTER && wc!=IBP_CS_BIT8_CANT_MAP_CHARACTER)
   return false;

  (*out)=c;

  //---------
  ++out;

  if(out==out_end)
  {
   writer->write(sizeof(out_buffer),out_buffer);

   out=out_buffer;
  }//if - сброс буфера
 }//for source

 if(out!=out_buffer)
 {
  //сброс невыгруженных данных
  assert(out<=out_end);

  writer->write((out-out_buffer)*sizeof(*out),out_buffer);
 }//if

 return true;
}//unicode_to_blob

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
