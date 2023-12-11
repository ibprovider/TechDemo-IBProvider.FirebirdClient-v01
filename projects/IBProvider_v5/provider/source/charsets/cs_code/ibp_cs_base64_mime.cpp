////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_base64_mime.cpp
//! \brief   Управляющий класс для кодовой страницы BASE64 [MIME]
//! \author  Kovalenko Dmitry
//! \date    17.11.2010
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_base64_mime__text_stream__ucs2_to_mbc.h"
#include "source/charsets/cs_code/ibp_cs_base64_mime__text_stream__mbc_to_ucs2.h"
#include "source/charsets/cs_code/ibp_cs_base64_mime__text_stream__mbc_buffer_to_ucs2.h"
#include "source/db_obj/db_blob_writer.h"
#include "source/error_services/ibp_error_utils.h"
#include <structure/stream/t_istream_buffer_iterator.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_base64_mime

t_ibp_cs_base64_mime::t_ibp_cs_base64_mime(const db_obj::t_db_charset_info& cs_info)
 :m_cs_info(cs_info)
{
}

//------------------------------------------------------------------------
t_ibp_cs_base64_mime::~t_ibp_cs_base64_mime()
{
}

//t_ibp_charset interface ------------------------------------------------
const db_obj::t_db_charset_info& t_ibp_cs_base64_mime::get_info()const
{
 return m_cs_info;
}//charset_info

//------------------------------------------------------------------------
bool t_ibp_cs_base64_mime::to_unicode_v2
                                 (std::wstring*              const pws,
                                  structure::t_const_str_box const s)const
{
 return self_type::tbase64_to_tbase64(pws,s);
}//to_unicode_v2

//------------------------------------------------------------------------
bool t_ibp_cs_base64_mime::from_unicode_v2(std::string*                const ps,
                                           structure::t_const_wstr_box const ws)const
{
 return self_type::tbase64_to_tbase64(ps,ws);
}//from_unicode_v2

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_base64_mime::mbc_stream_to_ucs2_stream(db_obj::t_db_text_stream__mbc* const mbc_stream)const
{
 if(mbc_stream==NULL)
  return nullptr;

 return lib::structure::not_null_ptr
         (new tag_text_stream__mbc_to_ucs2
           (mbc_stream));
}//mbc_stream_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_base64_mime::mbc_buffer_to_ucs2_stream(const char* const mbc_buffer,
                                                 size_type   const mbc_buffer_size)const
{
 CHECK_READ_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 return lib::structure::not_null_ptr
         (new tag_text_stream__mbc_buffer_to_ucs2
           (mbc_buffer,
            mbc_buffer_size));
}//mbc_buffer_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__mbc_ptr
 t_ibp_cs_base64_mime::ucs2_stream_to_mbc_stream(db_obj::t_db_text_stream__ucs2* const ucs2_stream)const
{
 if(ucs2_stream==NULL)
  return nullptr;

 return lib::structure::not_null_ptr
         (new tag_text_stream__ucs2_to_mbc
           (ucs2_stream));
}//ucs2_stream_to_mbc_stream

//------------------------------------------------------------------------
db_obj::t_db_cs_result t_ibp_cs_base64_mime::sb_to_unicode
                                      (ansi_streambuf_type& in_buf,
                                       wchar_t*    const    ws,
                                       size_type&           wsz)const
{
 typedef char                                              source_char_type;
 typedef structure::t_char_traits2<source_char_type>       source_char_traits2;

 typedef structure::t_basic_istream_buffer_iterator
          <ansi_streambuf_type::value_type>                in_buf_iterator;

 typedef wchar_t                                           dest_char_type;

 //-----
 CHECK_WRITE_TYPED_PTR(ws,wsz);

 //-----
 const size_type original_wsz=wsz;

 wsz=0;

 //-----
 structure::charsets::t_base64_mime__block_decoder<source_char_type>
  mime_decoder;

 //пустой декодер должен рапортовать о завершенности процесса
 assert(mime_decoder.complete());

 in_buf_iterator       source(in_buf);
 in_buf_iterator const s_end;

 //-----------------------------------------
 ///Допускаем безболезненное обрезание терминальных пробелов

#define OUT_SYMBOL(ch,cs_trunc_result_code)         \
 {                                                  \
  assert(wsz<=original_wsz);                        \
                                                    \
  if(wsz==original_wsz)                             \
  {                                                 \
   return cs_trunc_result_code;                     \
  }                                                 \
                                                    \
  ws[wsz]=dest_char_type(ch);                       \
                                                    \
  ++wsz;                                            \
 }

 //-----------------------------------------
 for(;source!=s_end;++source)
 {
  const source_char_type source_ch=(*source);

  if(!mime_decoder.push(source_ch))
   break;

  OUT_SYMBOL(source_ch,db_obj::db_cs_result__trunc)
 }//for source

 //у нас должна быть строка с блоками по четыре символа
 if(!mime_decoder.complete())
  return db_obj::db_cs_result__fail;

 //пропускаем терминальные пробелы
 for(;source!=s_end;++source)
 {
  const source_char_type source_ch=(*source);

  if(source_ch!=source_char_traits2::ch_space())
   break;

  //сохраняем терминальные пробелы в результирующей строке
  OUT_SYMBOL(source_ch,db_obj::db_cs_result__ok);
 }//for source

 if(source!=s_end)
  return db_obj::db_cs_result__fail; //обнаружен недопустимый символ

 //-----------------------------------------
#undef OUT_SYMBOL

 //-----------------------------------------
 return db_obj::db_cs_result__ok;
}//sb_to_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_base64_mime::sb_len_as_unicode(ansi_streambuf_type& in_buf,
                                             size_type&           wsz)const
{
 typedef char                                              source_char_type;
 typedef structure::t_char_traits2<source_char_type>       source_char_traits2;

 typedef structure::t_basic_istream_buffer_iterator
          <ansi_streambuf_type::value_type>                in_buf_iterator;

 typedef wchar_t                                           dest_char_type;

 //-----
 wsz=0;

 //-----
 structure::charsets::t_base64_mime__block_decoder<source_char_type>
  mime_decoder;

 //пустой декодер должен рапортовать о завершенности процесса
 assert(mime_decoder.complete());

 in_buf_iterator       source(in_buf);
 in_buf_iterator const s_end;

 //-----------------------------------------
 const size_type c_max_wsz=structure::t_numeric_limits<size_type>::max_value();

 //-----------------------------------------
#define OUT_SYMBOL(ch)                                                    \
 {                                                                        \
  if(wsz==c_max_wsz)                                                      \
  {                                                                       \
   IBP_ErrorUtils::Throw__Error                                           \
    (DB_E_DATAOVERFLOW,                                                   \
     ibp_mce_cs__calc_length_in_ucs2_chars__overflow_1,                   \
     this->get_info().name);                                              \
  }                                                                       \
                                                                          \
  ++wsz;                                                                  \
 }

 //-----------------------------------------
 for(;source!=s_end;++source)
 {
  source_char_type const source_ch=(*source);

  if(!mime_decoder.push(source_ch))
   break;

  OUT_SYMBOL(source_ch);
 }//for source

 //у нас должна быть строка с блоками по четыре символа
 if(!mime_decoder.complete())
  return false;

 //пропускаем терминальные пробелы
 for(;source!=s_end;++source)
 {
  source_char_type const source_ch=(*source);

  if(source_ch!=source_char_traits2::ch_space())
   break;

  //сохраняем терминальные пробелы в результирующей строке
  OUT_SYMBOL(source_ch);
 }//for source

 if(source!=s_end)
  return false; //обнаружен недопустимый символ

 //-----------------------------------------
#undef OUT_SYMBOL

 //-----------------------------------------
 return true;
}//sb_len_as_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_base64_mime::unicode_to_blob(const wchar_t*                  source,
                                           size_type                       source_size,
                                           db_obj::t_db_seq_stream_writer* writer)const
{
 typedef wchar_t                                       source_char_type;
 typedef structure::t_char_traits2<source_char_type>   source_char_traits2;

 typedef char                                          dest_char_type;

 //-----
 assert(writer);

 CHECK_READ_TYPED_PTR(source,source_size);

 //-----
 dest_char_type  out_buffer[8*1024];
 dest_char_type* out=out_buffer;

 const dest_char_type* const out_end=_END_(out_buffer);

 //-----
 structure::charsets::t_base64_mime__block_decoder<source_char_type>
  mime_decoder;

 //пустой декодер должен рапортовать о завершенности процесса
 assert(mime_decoder.complete());

 const source_char_type* const s_end=source+source_size;

 //-----------------------------------------
#define OUT_SYMBOL(ch)                              \
 {                                                  \
  assert(out>=out_buffer);                          \
  assert(out<=out_end);                             \
                                                    \
  if(out==out_end)                                  \
  {                                                 \
   writer->write(sizeof(out_buffer),out_buffer);    \
                                                    \
   out=out_buffer;                                  \
  }                                                 \
                                                    \
  assert(out!=out_end);                             \
                                                    \
  (*out)=dest_char_type(ch);                        \
                                                    \
  ++out;                                            \
 }

 //-----------------------------------------
 for(;source!=s_end;++source)
 {
  if(!mime_decoder.push(*source))
   break;

  OUT_SYMBOL(*source)
 }//for source

 //у нас должна быть строка с блоками по четыре символа
 if(!mime_decoder.complete())
  return false;

 //пропускаем терминальные пробелы
 for(;source!=s_end;++source)
 {
  if((*source)!=source_char_traits2::ch_space())
   break;

  //сохраняем терминальные пробелы в результирующей строке
  OUT_SYMBOL(*source);
 }//for source

 if(source!=s_end)
  return false; //обнаружен недопустимый символ

 //-----------------------------------------
#undef OUT_SYMBOL

 //-----------------------------------------
 assert(out>=out_buffer);
 assert(out<=out_end);

 if(out!=out_buffer)
 {
  //выгружаем несохраненные данные
  writer->write(sizeof(*out)*(out-out_buffer),out_buffer); //throw
 }//if

 //-----------------------------------------
 return true;
}//unicode_to_blob

//------------------------------------------------------------------------
template<typename source_charT,typename dest_charT>
bool t_ibp_cs_base64_mime::tbase64_to_tbase64
                               (__STL_DEF_BASIC_STRING(dest_charT)*            const dest_str,
                                structure::t_basic_const_str_box<source_charT> const source)
{
 assert(dest_str);

 CHECK_READ_TYPED_PTR(source.ptr,source.len);

 //-----------------------------------------
 typedef source_charT                                   source_char_type;
 typedef structure::t_char_traits2<source_char_type>    source_char_traits2;

 typedef dest_charT                                     dest_char_type;
 typedef __STL_DEF_BASIC_STRING(dest_char_type)         dest_string_type;

 //-----------------------------------------
 dest_str->clear();

 //-----------------------------------------
#define OUT_SYMBOL(ch)                              \
 {                                                  \
  result_str.push_back(dest_char_type(ch));         \
 }

 //-----------------------------------------
 structure::charsets::t_base64_mime__block_decoder<source_char_type>
  mime_decoder;

 //пустой декодер должен рапортовать о завершенности процесса
 assert(mime_decoder.complete());

 dest_string_type result_str;

 result_str.reserve(source.len);

 const source_char_type*       s_ptr=source.ptr;
 const source_char_type* const s_end=source.ptr+source.len;

 for(;s_ptr!=s_end;++s_ptr)
 {
  if(!mime_decoder.push(*s_ptr))
   break;

  OUT_SYMBOL(*s_ptr);
 }//for source

 //у нас должна быть строка с блоками по четыре символа
 if(!mime_decoder.complete())
  return false;

 //пропускаем терминальные пробелы
 for(;s_ptr!=s_end;++s_ptr)
 {
  if((*s_ptr)!=source_char_traits2::ch_space())
   break;

  //сохраняем терминальные пробелы в результирующей строке
  OUT_SYMBOL(*s_ptr);
 }//for s_ptr

 if(s_ptr!=s_end)
  return false; //обнаружен недопустимый символ

 //-----------------------------------------
#undef OUT_SYMBOL

 //-----------------------------------------
 //строка полностью обработана
 dest_str->swap(result_str);

 return true;
}//tbase64_to_tbase64

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
