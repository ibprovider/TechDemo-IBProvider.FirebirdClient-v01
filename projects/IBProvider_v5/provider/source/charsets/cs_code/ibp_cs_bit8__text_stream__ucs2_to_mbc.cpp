////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8__text_stream__ucs2_to_mbc.cpp
//! \brief   Конвертор потока UCS2-символов в поток MultiByte-символов
//! \author  Kovalenko Dmitry
//! \date    07.12.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_bit8__text_stream__ucs2_to_mbc.h"
#include "source/charsets/ibp_charset_const.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8::tag_text_stream__ucs2_to_mbc

t_ibp_cs_bit8::tag_text_stream__ucs2_to_mbc::tag_text_stream__ucs2_to_mbc
                              (const t_ibp_cs_bit8*            const charset,
                               db_obj::t_db_text_stream__ucs2* const source__ucs2)
 :m_charset      (lib::structure::not_null_ptr(charset))
 ,m_source__ucs2 (lib::structure::not_null_ptr(source__ucs2))
 ,m_buffer_pos   (0)
 ,m_buffer_size  (0)
{
 assert(m_charset);
 assert(m_source__ucs2);
}

//------------------------------------------------------------------------
t_ibp_cs_bit8::tag_text_stream__ucs2_to_mbc::~tag_text_stream__ucs2_to_mbc()
{;}

//t_db_text_stream__mbc interface ----------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_bit8::tag_text_stream__ucs2_to_mbc::read_mbc
                        (db_obj::t_db_operation_context& op_ctx,
                         size_type                 const mbc_buffer_size,
                         char*                     const mbc_buffer,
                         size_type*                const cb_readed)
{
 assert(cb_readed);
 assert(m_charset);
 assert(m_source__ucs2);

 CHECK_WRITE_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 const lock_guard_type __lock(m_guard);

 for((*cb_readed)=0;(*cb_readed)!=mbc_buffer_size;++(*cb_readed),++m_buffer_pos)
 {
  if(m_buffer_pos==m_buffer_size)
  {
   //обработали все символы в локальном буфере

   //сброс
   m_buffer_pos=0;
   m_buffer_size=0;

   //загрузка новой партии
   assert(m_source__ucs2);

   const db_obj::t_db_cs_result
    cs_result
     =m_source__ucs2->read_ucs2
      (op_ctx,
       _DIM_(m_buffer),
       m_buffer,
       &m_buffer_size); //throw

   assert(m_buffer_size<=_DIM_(m_buffer));

   if(cs_result!=db_obj::db_cs_result__ok)
   {
    assert(cs_result==db_obj::db_cs_result__fail);

    return cs_result;
   }//if

   //-----
   if(m_buffer_size==0)
    break; //выбрали все данные
  }//if

  assert(m_buffer_size<=_DIM_(m_buffer));
  assert(m_buffer_pos<m_buffer_size);

  //-------
  assert(m_charset->m_data);

  const ushort_type ucs2=m_buffer[m_buffer_pos];

  assert(int(ucs2)>=0);
  assert(int(ucs2/256)<int(_DIM_(*m_charset->m_data->from_unicode_map)));

  const size_type n=(*m_charset->m_data->from_unicode_map)[ucs2/256]+(ucs2%256);

  assert_msg(n<m_charset->m_data->from_unicode_mapping_array_size,"n=="<<n);

  const char mbc=(m_charset->m_data->from_unicode_mapping_array)[n];

  if(mbc==IBP_CS_BIT8_CANT_MAP_CHARACTER && ucs2!=IBP_CS_BIT8_CANT_MAP_CHARACTER)
   return db_obj::db_cs_result__fail;

  //-------
  mbc_buffer[*cb_readed]=mbc;
 }//for (*cb_readed)

 return db_obj::db_cs_result__ok;
}//read_mbc

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
