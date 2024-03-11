////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8__text_stream__mbc_to_ucs2.cpp
//! \brief   Конвертор потока MultiByte-символов в поток UCS2-символов
//! \author  Kovalenko Dmitry
//! \date    07.12.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_bit8__text_stream__mbc_to_ucs2.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8::tag_text_stream__mbc_to_ucs2

t_ibp_cs_bit8::tag_text_stream__mbc_to_ucs2::tag_text_stream__mbc_to_ucs2
                                        (const t_ibp_cs_bit8*           const charset,
                                         db_obj::t_db_text_stream__mbc* const source__mbc)
 :m_charset            (lib::structure::not_null_ptr(charset))
 ,m_source__mbc        (lib::structure::not_null_ptr(source__mbc))
 ,m_source_buffer_pos  (0)
 ,m_source_buffer_size (0)
{
 assert(m_charset);
 assert(m_source__mbc);
}//tag_text_stream__mbc_to_ucs2

//------------------------------------------------------------------------
t_ibp_cs_bit8::tag_text_stream__mbc_to_ucs2::~tag_text_stream__mbc_to_ucs2()
{;}

//------------------------------------------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_bit8::tag_text_stream__mbc_to_ucs2::read_ucs2
                        (db_obj::t_db_operation_context& op_ctx,
                         size_type                 const ucs2_buffer_size,
                         wchar_t*                  const ucs2_buffer,
                         size_type*                const cb_readed)
{
 assert(cb_readed);
 assert(m_charset);
 assert(m_source__mbc);

 CHECK_WRITE_TYPED_PTR(ucs2_buffer,ucs2_buffer_size);

 const lock_guard_type __lock(m_guard);

 for((*cb_readed)=0;(*cb_readed)!=ucs2_buffer_size;++(*cb_readed),++m_source_buffer_pos)
 {
  if(m_source_buffer_pos==m_source_buffer_size)
  {
   //обработали все символы в локальном буфере

   //сброс
   m_source_buffer_pos=0;
   m_source_buffer_size=0;

   //загрузка новой партии
   assert(m_source__mbc);

   const db_obj::t_db_cs_result
    cs_result
     =m_source__mbc->read_mbc
       (op_ctx,
        _DIM_(m_source_buffer),
        m_source_buffer,
        &m_source_buffer_size); //throw

   assert(m_source_buffer_size<=_DIM_(m_source_buffer));

   if(cs_result!=db_obj::db_cs_result__ok)
   {
    assert(cs_result==db_obj::db_cs_result__fail);

    return cs_result;
   }//if

   //-----
   if(m_source_buffer_size==0)
    break; //выбрали все данные
  }//if

  assert(m_source_buffer_size<=_DIM_(m_source_buffer));
  assert(m_source_buffer_pos<m_source_buffer_size);

  //-------
  assert(m_charset->m_data);

  const uchar_type mbc=m_source_buffer[m_source_buffer_pos];

  assert(int(mbc)>=0);
  assert(int(mbc)<int(_DIM_(*(m_charset->m_data->to_unicode_map))));

  ucs2_buffer[*cb_readed]=(*(m_charset->m_data->to_unicode_map))[mbc];
 }//for (*cb_readed)

 return db_obj::db_cs_result__ok;
}//read_ucs2

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
