////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_base64_mime__text_stream__mbc_buffer_to_ucs2.cpp
//! \brief   BASE64 [MIME]. Конвертор массива MBC-символов в поток UCS2 символов.
//! \author  Kovalenko Dmitry
//! \date    19.11.2010
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_base64_mime__text_stream__mbc_buffer_to_ucs2.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2

t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2::tag_text_stream__mbc_buffer_to_ucs2
                                           (const source_char_type* const source_buffer,
                                            size_type               const source_buffer_size)
 :m_source_buffer      (source_buffer)
 ,m_source_buffer_size (source_buffer_size)
 ,m_source_buffer_pos  (0)
 ,m_state_id           (state_id__process_mime_chars)
{
 CHECK_READ_TYPED_PTR(m_source_buffer,m_source_buffer_size);

 //пустой декодер должен находится в завершенном состоянии
 assert(m_mime_decoder.complete());
}//tag_text_stream__mbc_buffer_to_ucs2

//------------------------------------------------------------------------
t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2::~tag_text_stream__mbc_buffer_to_ucs2
                                           ()
{;}

//t_db_text_stream__ucs2 interface ---------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2::read_ucs2
                                           (size_type  const ucs2_buffer_size,
                                            wchar_t*   const ucs2_buffer,
                                            size_type* const cb_readed)
{
 assert(cb_readed);

 CHECK_WRITE_TYPED_PTR(ucs2_buffer,ucs2_buffer_size);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bug_check_src
  =L"t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2::read_ucs2";

 //-----------------------------------------------------------------------
 const lock_guard_type __lock(m_guard);

 (*cb_readed)=0;

 for((*cb_readed)=0;(*cb_readed)!=ucs2_buffer_size;)
 {
  assert(m_source_buffer_pos<=m_source_buffer_size);

  if(m_source_buffer_pos==m_source_buffer_size)
   return this->ev_finish();

  //----------------------------------------------------------------------
  assert(m_source_buffer_pos<m_source_buffer_size);

  const source_char_type source_ch=m_source_buffer[m_source_buffer_pos];

  switch(m_state_id)
  {
   case state_id__process_mime_chars:
   {
    if(m_mime_decoder.push(source_ch))
     break;

    if(!m_mime_decoder.complete())
     return db_obj::db_cs_result__fail;

    //переход в режим обработки терминальных пробелов
    m_state_id=state_id__process_terminate_space;

    continue;
   }//state_id__process_mime_chars

   case state_id__process_terminate_space:
   {
    //мы обрабатываем пробелы только в случае нормального завершения
    //обработки MIME-строки

    assert(m_mime_decoder.complete());

    //идет обработка завершающих пробелов
    if(source_ch!=source_char_traits2::ch_space())
     return db_obj::db_cs_result__fail;

    //пропускаем терминальные пробелы
    break;
   }//state_id__process_terminate_space

   default:
   {
    structure::wstr_formatter freason(L"unexpected state_id [%1]");

    freason<<int(m_state_id);

    IBP_BUG_CHECK__DEBUG
     (c_bug_check_src,
      L"#001",
      freason.c_str());
   }//default
  }//switch m_state_id

  //сохраняем выбранный символ в исходящем буфере
  assert((*cb_readed)<ucs2_buffer_size);

  ucs2_buffer[*cb_readed]=dest_char_type(source_ch);

  //перемещаем позицию во внутреннем буфере
  ++m_source_buffer_pos;

  ++(*cb_readed);
 }//for - работаем пока есть место в OUT-буфере

 return db_obj::db_cs_result__ok;
}//read_ucs2

//------------------------------------------------------------------------
db_obj::t_db_cs_result t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2::ev_finish()const
{
 const wchar_t* const c_bug_check_src
  =L"t_ibp_cs_base64_mime::tag_text_stream__mbc_buffer_to_ucs2::ev_finish";

 switch(m_state_id)
 {
  case state_id__process_mime_chars:
  {
   //мы обрабатываем MIME-символы

   //если число обработанных символов кратно 4, то все нормально
   if(m_mime_decoder.complete())
    return db_obj::db_cs_result__ok;

   return db_obj::db_cs_result__fail;
  }//state_id__process_mime_chars

  case state_id__process_terminate_space:
  {
   //мы обрабатываем завершающие терминальные символы

   //это возможно только в случае нормального завершения обработки MIME-строки
   assert(m_mime_decoder.complete());

   return db_obj::db_cs_result__ok;
  }//state_id__process_terminate_space
 }//switch m_state_id

 structure::wstr_formatter freason(L"unexpected state_id [%1]");

 freason<<int(m_state_id);

 IBP_BUG_CHECK__DEBUG
  (c_bug_check_src,
   L"#001",
   freason.c_str());

#if(COMP_BUILD_UNUSED_CODE)
 return db_obj::db_cs_result__fail;
#endif
}//ev_finish

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
