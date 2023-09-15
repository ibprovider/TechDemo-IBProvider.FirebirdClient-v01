////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_base64_mime__text_stream__mbc_to_ucs2.cpp
//! \brief   BASE64 [MIME]. Конвертор потока MBC-символов в поток UCS2-символов.
//! \author  Kovalenko Dmitry
//! \date    19.11.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_base64_mime__text_stream__mbc_to_ucs2.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_base64_mime::tag_text_stream__mbc_to_ucs2

t_ibp_cs_base64_mime::tag_text_stream__mbc_to_ucs2::tag_text_stream__mbc_to_ucs2
                                           (db_obj::t_db_text_stream__mbc* const source__mbc)
 :m_source__mbc (structure::not_null_ptr(source__mbc))
 ,m_state_id    (state_id__process_mime_chars)
 ,m_buffer_pos  (0)
 ,m_buffer_size (0)
{
 assert(m_source__mbc);

 //пустой декодер должен находится в завершенном состоянии
 assert(m_mime_decoder.complete());
}//tag_text_stream__mbc_to_ucs2

//------------------------------------------------------------------------
t_ibp_cs_base64_mime::tag_text_stream__mbc_to_ucs2::~tag_text_stream__mbc_to_ucs2()
{;}

//t_db_text_stream__mbc interface ----------------------------------------
db_obj::t_db_cs_result t_ibp_cs_base64_mime::tag_text_stream__mbc_to_ucs2::read_ucs2
                                           (size_type  const ucs2_buffer_size,
                                            wchar_t*   const ucs2_buffer,
                                            size_type* const cb_readed)
{
 assert(cb_readed);
 assert(m_source__mbc);

 CHECK_WRITE_TYPED_PTR(ucs2_buffer,ucs2_buffer_size);

 //-----
 const wchar_t* const c_bug_check_src
  =L"t_ibp_cs_base64_mime::tag_text_stream__mbc_to_ucs2::read_mbc";

 //-----
 const lock_guard_type __lock(m_guard);

 for((*cb_readed)=0;(*cb_readed)!=ucs2_buffer_size;)
 {
  assert(m_buffer_pos<=m_buffer_size);

  if(m_buffer_pos==m_buffer_size)
  {
   //обработали все символы в локальном буфере

   //сброс
   m_buffer_pos=0;
   m_buffer_size=0;

   //загрузка новой партии
   assert(m_source__mbc);

   const db_obj::t_db_cs_result
    cs_result=m_source__mbc->read_mbc(_DIM_(m_buffer),m_buffer,&m_buffer_size); //throw

   assert(m_buffer_size<=_DIM_(m_buffer));

   if(cs_result!=db_obj::db_cs_result__ok)
   {
    assert(cs_result==db_obj::db_cs_result__fail);

    return cs_result;
   }//if

   //-----
   if(m_buffer_size==0)
    return this->ev_finish(); //выбрали все данные
  }//if

  //----------------------------------------
  assert(m_buffer_size<=_DIM_(m_buffer));
  assert(m_buffer_pos<m_buffer_size);

  const source_char_type source_ch=m_buffer[m_buffer_pos];

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
    IBP_ErrorUtils::Throw__BugCheck__DEBUG
     (c_bug_check_src,
      L"#001",
      L"unexpected state_id [%1]",
      int(m_state_id));
   }//default
  }//switch m_state_id

  //сохраняем выбранный символ в исходящем буфере
  assert((*cb_readed)<ucs2_buffer_size);

  ucs2_buffer[*cb_readed]=dest_char_type(source_ch);

  //перемещаем позицию во внутреннем буфере
  ++m_buffer_pos;

  ++(*cb_readed);
 }//for - работаем пока есть место в OUT-буфере

 return db_obj::db_cs_result__ok;
}//read_mbc

//------------------------------------------------------------------------
db_obj::t_db_cs_result t_ibp_cs_base64_mime::tag_text_stream__mbc_to_ucs2::ev_finish()const
{
 const wchar_t* const c_bug_check_src
  =L"t_ibp_cs_base64_mime::tag_text_stream__mbc_to_ucs2::ev_finish";

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

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (c_bug_check_src,
   L"#001",
   L"unexpected state_id [%1]",
   int(m_state_id));

#if(COMP_BUILD_UNUSED_CODE)
 return db_obj::db_cs_result__fail;
#endif
}//ev_finish

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
