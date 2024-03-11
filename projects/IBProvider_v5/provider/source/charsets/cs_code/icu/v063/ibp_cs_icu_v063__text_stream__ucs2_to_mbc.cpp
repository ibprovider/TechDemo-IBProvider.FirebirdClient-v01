////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_cs_icu_v063
//! \file    ibp_cs_icu_v063__text_stream__ucs2_to_mbc.cpp
//! \brief   Конвертор потока UCS2-символов в поток MultiByte-символов
//! \author  Kovalenko Dmitry
//! \date    15.06.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/icu/v063/ibp_cs_icu_v063__text_stream__ucs2_to_mbc.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace charsets{namespace cs_code{namespace icu{namespace v063{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc

t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc::tag_text_stream__ucs2_to_mbc
                                           (const charset_type*             const charset,
                                            db_obj::t_db_text_stream__ucs2* const source__ucs2)
 :m_charset            (lib::structure::not_null_ptr(charset))
 ,m_source__ucs2       (lib::structure::not_null_ptr(source__ucs2))
 ,m_icu_conv           (charset,tag_conv_holder::conv_direction__from_unicode)
 ,m_get_eof            (false)
 ,m_target_buffer_pos  (0)
 ,m_target_buffer_size (0)
 ,m_source_buffer_pos  (0)
 ,m_source_buffer_size (0)
{
 assert(m_charset);
 assert(m_source__ucs2);
}

//------------------------------------------------------------------------
t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc::~tag_text_stream__ucs2_to_mbc()
{
}

//------------------------------------------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc::read_mbc
                        (db_obj::t_db_operation_context& op_ctx,
                         size_type                 const mbc_buffer_size,
                         char*                     const mbc_buffer,
                         size_type*                const cb_readed)
{
 assert(cb_readed);
 assert(m_charset);
 assert(m_source__ucs2);

 CHECK_WRITE_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 //----------------------------------------- MT-LOCK
 const lock_guard_type __lock(m_guard);

 (*cb_readed)=0;

 for(;;)
 {
  //разгружаем буфер с MultiByte-символами
  assert(m_target_buffer_size<=_DIM_(m_target_buffer));
  assert(m_target_buffer_pos<=m_target_buffer_size);

  while((*cb_readed)!=mbc_buffer_size && m_target_buffer_pos!=m_target_buffer_size)
  {
   assert(m_target_buffer_pos<_DIM_(m_target_buffer));

   mbc_buffer[*cb_readed]=m_target_buffer[m_target_buffer_pos];

   ++(*cb_readed);

   ++m_target_buffer_pos;
  }//while

  if((*cb_readed)==mbc_buffer_size)
   break;

  if(m_source_buffer_pos!=m_source_buffer_size || m_get_eof)
  {
   //сброс буфера невыгруженных данных
   m_target_buffer_pos=0;
   m_target_buffer_size=0;

   //формируем указатели на буферы
   char* target=m_target_buffer;

   const wchar_t* const source_beg =m_source_buffer+m_source_buffer_pos;
   const wchar_t*       source     =source_beg;
   const wchar_t* const source_end =m_source_buffer+m_source_buffer_size;

   //вызываем ICU-конвертор
   api::UErrorCode icu_status=api::U_ZERO_ERROR;

   m_charset->call__ucnv_fromUnicode
    (m_icu_conv.ptr(),
     &target,
     _END_(m_target_buffer),
     &source,
     source_end,
     /*flush*/m_get_eof,
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

   if(m_get_eof && icu_status==api::U_ZERO_ERROR)
   {
    //выбрали все данные из входящего потока и опустошили ICU-конвертор
    break;
   }

   //---- должны были сдвинутся
   if(source==source_beg)
   {
    //обнаружено потенциальное зацикливание
    m_charset->Throw_BugCheck
     (m_charset->m_spICU->m_ucnv_fromUnicode.point_name(),
      L"v063::t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc::read_mbc #001");
   }//if
  }//if m_source_buffer_pos!=m_source_buffer_size

  if(!m_get_eof)
  {
   //сдвигаем необработанный хвост в начало буфера
   assert(m_source_buffer_size<=_DIM_(m_source_buffer));
   assert(m_source_buffer_pos<=m_source_buffer_size);

   memcpy(m_source_buffer,m_source_buffer+m_source_buffer_pos,
          (m_source_buffer_size-m_source_buffer_pos)*sizeof(*m_source_buffer));

   m_source_buffer_size=m_source_buffer_size-m_source_buffer_pos;

   m_source_buffer_pos=0;

   //---------------------------------------
   //в буфере должно быть пустое место. Иначе это означает что мы зациклились

   assert(m_source_buffer_size!=_DIM_(m_source_buffer));

   if(m_source_buffer_size==_DIM_(m_source_buffer))
   {
    IBP_ThrowBugCheck
     (L"v063::t_ibp_cs_icu::tag_text_stream__ucs2_to_mbc::read_ucs2",
      L"#002",
      L"internal error");
   }//if

   //---------------------------------------
   assert(m_source__ucs2);

   size_type cb_readed_ucs2=0;

   const db_obj::t_db_cs_result
    cvt_result
     =m_source__ucs2->read_ucs2
       (op_ctx,
        _DIM_(m_source_buffer)-m_source_buffer_size,
        m_source_buffer+m_source_buffer_size,
        &cb_readed_ucs2);

   assert(cb_readed_ucs2<=_DIM_(m_source_buffer)-m_source_buffer_size);

   m_source_buffer_size+=cb_readed_ucs2;

   //----
   if(cvt_result!=db_obj::db_cs_result__ok)
   {
    assert(cvt_result==db_obj::db_cs_result__fail);

    return cvt_result;
   }//if

   if(m_source_buffer_size==0)
   {
    //выбрали все данные из входящего потока
    m_get_eof=true;
   }
  }//if !m_get_eof
 }//for - forever

 return db_obj::db_cs_result__ok;
}//read_mbc

////////////////////////////////////////////////////////////////////////////////
}/*nms v063*/}/*nms icu*/}/*nms cs_code*/}/*nms charsets*/}/*nms ibp*/}/*nms lcpi*/
