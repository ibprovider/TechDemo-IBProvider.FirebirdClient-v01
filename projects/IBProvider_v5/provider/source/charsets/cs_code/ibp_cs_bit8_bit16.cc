////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8_bit16.cc
//! \brief   Управляющий класс для кодовых страниц BIT8-BIT16
//! \author  Kovalenko Dmitry
//! \date    28.09.2008
#ifndef _ibp_cs_bit8_bit16_CC_
#define _ibp_cs_bit8_bit16_CC_

#include "source/charsets/ibp_text_stream__mbc_to_ucs2.h"
#include "source/charsets/ibp_text_stream__mbc_buffer_to_ucs2.h"
#include "source/charsets/ibp_text_stream__ucs2_to_mbc.h"
#include "source/charsets/ibp_charset_const.h"
#include "source/db_obj/db_blob_writer_buf.h"
#include "source/ibp_numeric_cast.h"
#include <structure/stream/t_istream_buffer_iterator.h>
#include <structure/stream/t_ostream_buffer_iterator.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8_bit16

template<class TCS_Traits>
t_ibp_cs_bit8_bit16<TCS_Traits>::t_ibp_cs_bit8_bit16(const db_obj::t_db_charset_info& charset_info,
                                                     const data_type* const           data)
 :m_charset_info (charset_info)
 ,m_data         (data)
{
 assert(m_data);
}

//------------------------------------------------------------------------
template<class TCS_Traits>
t_ibp_cs_bit8_bit16<TCS_Traits>::~t_ibp_cs_bit8_bit16()
{
}

//t_ibp_charset interface ------------------------------------------------
template<class TCS_Traits>
const db_obj::t_db_charset_info& t_ibp_cs_bit8_bit16<TCS_Traits>::get_info()const
{
 return m_charset_info;
}//get_info

//------------------------------------------------------------------------
template<class TCS_Traits>
bool t_ibp_cs_bit8_bit16<TCS_Traits>::to_unicode_v2
                                      (std::wstring*              const pws,
                                       structure::t_const_str_box const s)const
{
 assert(pws);

 CHECK_READ_TYPED_PTR(s.ptr,s.len);

 //-----------------------------------------------------------------------
 pws->clear();

 assert(data_type::c_char_size__min>0);

 //! \todo
 //!  Добавить контроль переполнения
 pws->reserve((s.len+data_type::c_char_size__min-1)/data_type::c_char_size__min);

 const char*       cur_s=s.ptr;
 const char* const end_s=s.ptr+s.len;

 wchar_t cvt_wc[data_type::c_max_ucs2_in_one_char];

 for(;;)
 {
  size_t cvt_sz=_DIM_(cvt_wc);

  //! \todo
  //!  Добавить контроль движения вперед указателя cur_s

  const db_obj::t_db_cs_result
   cvt_code
    =m_data->convert_single_own_to_unicode_v3
      (/*in-out*/cur_s,
       end_s,
       cvt_wc,
       /*in-out*/cvt_sz);

  assert(cvt_code!=db_obj::db_cs_result__trunc);

  if(cvt_code!=db_obj::db_cs_result__ok)
   return false;

  if(cvt_sz==0)
   break;

  assert(cvt_sz<=_DIM_(cvt_wc));

  pws->append(cvt_wc,cvt_wc+cvt_sz);
 }//for[ever]

 return true;
}//to_unicode_v2

//------------------------------------------------------------------------
template<class TCS_Traits>
bool t_ibp_cs_bit8_bit16<TCS_Traits>::from_unicode_v2
                                      (std::string*                const ps,
                                       structure::t_const_wstr_box const ws)const
{
 assert(ps);

 CHECK_READ_TYPED_PTR(ws.ptr,ws.len);

 //-----------------------------------------------------------------------
 ps->clear();

 assert(data_type::c_char_size__max>0);

 //до c_char_size__max байт на один символ
 ps->reserve(data_type::c_char_size__max*ws.len);

 const wchar_t*       psrc_cur=ws.ptr;
 const wchar_t* const psrc_end=psrc_cur+ws.len;

 return m_data->ucs2_to_own(psrc_cur,psrc_end,std::back_inserter(*ps))==db_obj::db_cs_result__ok;
}//from_unicode_v2

//------------------------------------------------------------------------
template<class TCS_Traits>
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_bit8_bit16<TCS_Traits>::mbc_stream_to_ucs2_stream
                                  (db_obj::t_db_text_stream__mbc* const mbc_stream)const
{
 if(mbc_stream==NULL)
  return nullptr;

 typedef t_ibp_text_stream__mbc_to_ucs2<self_type>
          tag_text_stream__mbc_to_ucs2;

 return lib::structure::not_null_ptr
         (new tag_text_stream__mbc_to_ucs2
           (this,
            mbc_stream));
}//mbc_stream_to_ucs2_stream

//------------------------------------------------------------------------
template<class TCS_Traits>
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_bit8_bit16<TCS_Traits>::mbc_buffer_to_ucs2_stream
                                            (const char* const mbc_buffer,
                                             size_type   const mbc_buffer_size)const
{
 CHECK_READ_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 typedef t_ibp_text_stream__mbc_buffer_to_ucs2<self_type>
          tag_text_stream__mbc_buffer_to_ucs2;

 return lib::structure::not_null_ptr
         (new tag_text_stream__mbc_buffer_to_ucs2
           (this,
            mbc_buffer,
            mbc_buffer_size));
}//mbc_buffer_to_ucs2_stream

//------------------------------------------------------------------------
template<class TCS_Traits>
db_obj::t_db_text_stream__mbc_ptr
 t_ibp_cs_bit8_bit16<TCS_Traits>::ucs2_stream_to_mbc_stream
                                  (db_obj::t_db_text_stream__ucs2* const ucs2_stream)const
{
 if(ucs2_stream==NULL)
  return nullptr;

 typedef t_ibp_text_stream__ucs2_to_mbc<self_type>
          tag_text_stream__ucs2_to_mbc;

 return lib::structure::not_null_ptr
          (new tag_text_stream__ucs2_to_mbc
            (this,
             ucs2_stream));
}//ucs2_stream_to_mbc_stream

//------------------------------------------------------------------------
template<class TCS_Traits>
db_obj::t_db_cs_result
 t_ibp_cs_bit8_bit16<TCS_Traits>::sb_to_unicode
                                            (ansi_streambuf_type& in_buf,
                                             wchar_t*      const  ws,
                                             size_type&           wsz)const
{
 typedef structure::t_basic_istream_buffer_iterator
          <ansi_streambuf_type::value_type>              in_buf_iterator;

 CHECK_WRITE_TYPED_PTR(ws,wsz);

 const size_t original_wsz=wsz;

 wsz=0;

 //проверяем наличие данных
 if(in_buf.eof())
  return db_obj::db_cs_result__ok;

 //----
 wchar_t cvt_wc[data_type::c_max_ucs2_in_one_char];

 for(in_buf_iterator cur(in_buf),end;;)
 {
  size_t cvt_sz=_DIM_(cvt_wc);

  const db_obj::t_db_cs_result
   cvt_code
    =m_data->convert_single_own_to_unicode_v3(cur,end,cvt_wc,cvt_sz);

  assert(cvt_code!=db_obj::db_cs_result__trunc);

  if(cvt_code!=db_obj::db_cs_result__ok)
   return db_obj::db_cs_result__fail; //общая ошибка конвертирования

  if(cvt_sz==0)
   return db_obj::db_cs_result__ok; //EOF

  assert(cvt_sz<=_DIM_(cvt_wc));

  assert(wsz<=original_wsz);

  if(cvt_sz>static_cast<size_type>(original_wsz-wsz))
  {
   //данные не поместились в out-буфер. Происходит потеря данных.
   return db_obj::db_cs_result__trunc;
  }//if

  for(size_t i(0);i!=cvt_sz;++i,++wsz)
   ws[wsz]=cvt_wc[i];
 }//for[ever]
}//sb_to_unicode

//------------------------------------------------------------------------
template<class TCS_Traits>
bool t_ibp_cs_bit8_bit16<TCS_Traits>::sb_len_as_unicode
                                            (ansi_streambuf_type& in_buf,
                                             size_type&           wsz)const
{
 typedef structure::t_basic_istream_buffer_iterator
          <ansi_streambuf_type::value_type>              in_buf_iterator;

 wsz=0;

 //проверяем наличие данных
 if(in_buf.eof())
  return true;

 //----
 wchar_t cvt_wc[data_type::c_max_ucs2_in_one_char];

 for(in_buf_iterator cur(in_buf),end;;)
 {
  size_t cvt_sz=_DIM_(cvt_wc);

  const db_obj::t_db_cs_result
   cvt_code
    =m_data->convert_single_own_to_unicode_v3(cur,end,cvt_wc,cvt_sz);

  assert(cvt_code!=db_obj::db_cs_result__trunc);

  if(cvt_code!=db_obj::db_cs_result__ok)
   return false;

  if(cvt_sz==0)
   break; //EOF

  assert(cvt_sz<=_DIM_(cvt_wc));

  //контроль переполнения
  if(!ibp::ibp_can_numeric_add(wsz,cvt_sz))
  {
   //ERROR - переполнение при вычислении размера UNICODE-представления данных
   IBP_ErrorUtils::Throw__Error
    (DB_E_DATAOVERFLOW,
     ibp_mce_cs__calc_length_in_ucs2_chars__overflow_1,
     this->get_info().name);
  }//if

  //все нормально, можно увеличивать
  wsz+=cvt_sz;
 }//for[ever]

 return true;
}//sb_len_as_unicode

//------------------------------------------------------------------------
template<class TCS_Traits>
bool t_ibp_cs_bit8_bit16<TCS_Traits>::unicode_to_blob
                                            (const wchar_t*                        source,
                                             size_type                       const source_size,
                                             db_obj::t_db_seq_stream_writer* const writer)const
{
 assert(writer);

 CHECK_READ_TYPED_PTR(source,source_size);

 //----
 if(source_size==0)
  return true;

 //---- подключаем объект записи к буферу потока
 char out_buf[8*1024];

 db_obj::t_db_blob_writer_buf writer_buf(out_buf,_DIM_(out_buf),writer);

 typedef structure::t_basic_ostream_buffer_iterator<db_obj::t_db_blob_writer_buf::char_type>
  writer_buf_iterator;

 if(m_data->ucs2_to_own(source,
                        source+source_size,
                        writer_buf_iterator(writer_buf))!=db_obj::db_cs_result__ok)
 {
  return false;
 }//if

 //---- сброс невыгруженных данных
 writer_buf.flush();

 //----
 return true;
}//unicode_to_blob

//Auxiliary utilities ----------------------------------------------------

template<class TCS_Traits>
RELEASE_CODE(inline)
db_obj::t_db_cs_result
 t_ibp_cs_bit8_bit16<TCS_Traits>::single_mbc_to_ucs2
                                   (const char** const source_beg,
                                    const char*  const source_end,
                                    wchar_t*     const target,
                                    size_t&            target_size)const
{
 assert(source_beg);

 return m_data->convert_single_own_to_unicode_v3
         (*source_beg,
          source_end,
          target,
          target_size);
}//single_mbc_to_ucs2

//------------------------------------------------------------------------
template<class TCS_Traits>
RELEASE_CODE(inline)
db_obj::t_db_cs_result
 t_ibp_cs_bit8_bit16<TCS_Traits>::single_ucs2_to_mbc
                                   (const wchar_t** const source_beg,
                                    const wchar_t*  const source_end,
                                    char*           const target,
                                    size_t&               target_size)const
{
 assert(source_beg);

 return m_data->convert_single_unicode_to_own_v3
         (*source_beg,
          source_end,
          target,
          target_size);
}//single_ucs2_to_mbc

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
