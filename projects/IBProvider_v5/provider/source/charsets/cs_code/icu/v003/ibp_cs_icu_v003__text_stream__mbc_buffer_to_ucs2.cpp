////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v003
//! \file    ibp_cs_icu_v003__text_stream__mbc_buffer_to_ucs2.cpp
//! \brief   Конвертор массива MultiByte-символов в поток UCS2-символов
//! \author  Kovalenko Dmitry
//! \date    09.12.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/icu/v003/ibp_cs_icu_v003__text_stream__mbc_buffer_to_ucs2.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v003{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2

t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2::tag_text_stream__mbc_buffer_to_ucs2
                                           (const charset_type* const charset,
                                            const char*         const source_buffer,
                                            size_type           const source_buffer_size)
 :m_charset            (lib::structure::not_null_ptr(charset))
 ,m_icu_conv           (charset,tag_conv_holder::conv_direction__to_unicode)
 ,m_target_buffer_pos  (0)
 ,m_target_buffer_size (0)
 ,m_source_buffer_pos  (0)
 ,m_source_buffer_size (source_buffer_size)
 ,m_source_buffer      (source_buffer)
{
 assert(m_charset);

 CHECK_READ_TYPED_PTR(m_source_buffer,m_source_buffer_size);
}

//------------------------------------------------------------------------
t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2::~tag_text_stream__mbc_buffer_to_ucs2()
{
}

//------------------------------------------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2::read_ucs2
                        (db_obj::t_db_operation_context& /*op_ctx*/,
                         size_type                 const ucs2_buffer_size,
                         wchar_t*                  const ucs2_buffer,
                         size_type*                const cb_readed)
{
 assert(cb_readed);
 assert(m_charset);

 CHECK_WRITE_TYPED_PTR(ucs2_buffer,ucs2_buffer_size);

 //----------------------------------------- MT-LOCK
 lock_guard_type __lock(m_guard);

 (*cb_readed)=0;

 if(m_source_buffer_size==0)
  return db_obj::db_cs_result__ok;

 for(;;)
 {
  //разгружаем буфер с UCS2-символами
  assert(m_target_buffer_size<=_DIM_(m_target_buffer));
  assert(m_target_buffer_pos<=m_target_buffer_size);

  while((*cb_readed)!=ucs2_buffer_size && m_target_buffer_pos!=m_target_buffer_size)
  {
   assert(m_target_buffer_pos<_DIM_(m_target_buffer));

   ucs2_buffer[*cb_readed]=m_target_buffer[m_target_buffer_pos];

   ++(*cb_readed);

   ++m_target_buffer_pos;
  }//while

  if((*cb_readed)==ucs2_buffer_size)
   break;

  {
   //сброс буфера невыгруженных данных
   m_target_buffer_pos=0;
   m_target_buffer_size=0;

   //формируем указатели на буферы
   wchar_t* target=m_target_buffer;

   const char* const source_beg =m_source_buffer+m_source_buffer_pos;
   const char*       source     =source_beg;
   const char* const source_end =m_source_buffer+m_source_buffer_size;

   //вызываем ICU-конвертор
   api::UErrorCode icu_status=api::U_ZERO_ERROR;

   m_charset->call__ucnv_toUnicode
    (m_icu_conv.ptr(),
     &target,
     _END_(m_target_buffer),
     &source,
     source_end,
     /*flush*/true,
     &icu_status);

   //обрабатываем результаты вызова
   assert(target>=m_target_buffer);
   assert(target<=_END_(m_target_buffer));

   assert(source>=m_source_buffer+m_source_buffer_pos);
   assert(source<=m_source_buffer+m_source_buffer_size);

   //----
   m_target_buffer_size=target-m_target_buffer;

   m_source_buffer_pos=source-m_source_buffer;

   //----
   switch(icu_status)
   {
    case api::U_ZERO_ERROR:
    case api::U_BUFFER_OVERFLOW_ERROR:
     break;

    default:
     return db_obj::db_cs_result__fail;
   }//switch

   //----
   if(m_target_buffer_size!=0)
    continue; //выгружаем сформированные символы

   if(m_source_buffer_pos==m_source_buffer_size && icu_status==api::U_ZERO_ERROR)
   {
    //выбрали все данные из входящего потока и опустошили ICU-конвертор
    break;
   }

   //---- должны были сдвинутся
   if(source==source_beg)
   {
    //обнаружено потенциальное зацикливание
    m_charset->Throw_BugCheck
     (m_charset->m_spICU->m_ucnv_toUnicode.point_name(),
      L"v003::t_ibp_cs_icu::tag_text_stream__mbc_buffer_to_ucs2::read_ucs2 #001");
   }//if
  }//local

  assert(m_source_buffer_pos<=m_source_buffer_size);

  //нужно продолжать работать, потому что во внутренних буферах ICU-конвертора
  //могут оставаться необработанные/невыгруженные данные
 }//for - forever

 return db_obj::db_cs_result__ok;
}//read_ucs2

////////////////////////////////////////////////////////////////////////////////
}/*nms v003*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
