////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_text_stream__ucs2_to_mbc.cc
//! \brief   Универсальный конвертор потока UCS2-символов в поток MultiByte-символов
//! \author  Kovalenko Dmitry
//! \date    09.12.2008
#ifndef _ibp_text_stream__ucs2_to_mbc_CC_
#define _ibp_text_stream__ucs2_to_mbc_CC_

#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_text_stream__ucs2_to_mbc

template<class TCharset>
t_ibp_text_stream__ucs2_to_mbc<TCharset>::t_ibp_text_stream__ucs2_to_mbc
                                 (const charset_type*             const charset,
                                  db_obj::t_db_text_stream__ucs2* const source__ucs2)
 :m_charset            (lib::structure::not_null_ptr(charset))
 ,m_source__ucs2       (lib::structure::not_null_ptr(source__ucs2))
 ,m_target_buffer_pos  (0)
 ,m_target_buffer_size (0)
 ,m_source_buffer_pos  (0)
 ,m_source_buffer_size (0)
{
 assert(m_charset);
 assert(m_source__ucs2);
}//t_ibp_text_stream__ucs2_to_mbc

//------------------------------------------------------------------------
template<class TCharset>
t_ibp_text_stream__ucs2_to_mbc<TCharset>::~t_ibp_text_stream__ucs2_to_mbc()
{;}

//------------------------------------------------------------------------
template<class TCharset>
db_obj::t_db_cs_result
 t_ibp_text_stream__ucs2_to_mbc<TCharset>::read_mbc
                        (db_obj::t_db_operation_context& op_ctx,
                         size_type                 const mbc_buffer_size,
                         char*                     const mbc_buffer,
                         size_type*                const cb_readed)
{
 assert(m_charset);
 assert(m_source__ucs2);
 assert(cb_readed);

 CHECK_WRITE_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 //----------------------------------------- MT-LOCK
 const lock_guard_type __lock(m_guard);

 //-----------------------------------------
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

  if(m_source_buffer_pos!=m_source_buffer_size)
  {
   //сброс буфера невыгруженных данных
   m_target_buffer_pos=0;
   m_target_buffer_size=_DIM_(m_target_buffer);

   //конвертируем следующий UCS2-символ
   const wchar_t* source_pos=m_source_buffer+m_source_buffer_pos;

   const db_obj::t_db_cs_result
    cvt_result
     =m_charset->single_ucs2_to_mbc
       (&source_pos,
        m_source_buffer+m_source_buffer_size,
        m_target_buffer,
        m_target_buffer_size);

   assert(source_pos>=m_source_buffer+m_source_buffer_pos);
   assert(source_pos<=m_source_buffer+m_source_buffer_size);

   assert(m_target_buffer_size<=_DIM_(m_target_buffer));

   //у нас не должно возникать проблем с размером OUT-буфера
   assert(cvt_result!=db_obj::db_cs_result__trunc);

   if(cvt_result==db_obj::db_cs_result__ok)
   {
    //должны сдвинутся
    assert(source_pos!=m_source_buffer+m_source_buffer_pos);

    //m_source_buffer_pos сдвигается только если мы отконвертировали символ
    m_source_buffer_pos=source_pos-m_source_buffer;

    //выгружаем MultiByte-символы
    continue;
   }//if - ok

   if(cvt_result!=db_obj::db_cs_result__input_trunc)
    return db_obj::db_cs_result__fail;
  }//if

  //загрузка следующей партии UCS2-символов

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
     (L"t_ibp_text_stream__ucs2_to_mbc::read_mbc",
      L"#001",
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
   }

   if(m_source_buffer_size==0)
    break; //выбрали все данные из входящего потока
  }//local
 }//for - forever

 return db_obj::db_cs_result__ok;
}//read_mbc

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
