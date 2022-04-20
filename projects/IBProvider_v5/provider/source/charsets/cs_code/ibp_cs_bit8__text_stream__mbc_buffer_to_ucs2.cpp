////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_bit8__text_stream__mbc_buffer_to_ucs2.cpp
//! \brief   Конвертор потока MultiByte-символов в поток UCS2-символов
//! \author  Kovalenko Dmitry
//! \date    07.12.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_bit8__text_stream__mbc_buffer_to_ucs2.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_bit8::tag_text_stream__mbc_buffer_to_ucs2

t_ibp_cs_bit8::tag_text_stream__mbc_buffer_to_ucs2::tag_text_stream__mbc_buffer_to_ucs2
                                        (const t_ibp_cs_bit8* const charset,
                                         const char*          const source_buffer,
                                         size_type            const source_buffer_size)
 :m_charset            (structure::not_null_ptr(charset))
 ,m_source_buffer_pos  (0)
 ,m_source_buffer_size (source_buffer_size)
 ,m_source_buffer      (source_buffer)
{
 assert(m_charset);

 CHECK_READ_TYPED_PTR(m_source_buffer,m_source_buffer_size);
}//tag_text_stream__mbc_buffer_to_ucs2

//------------------------------------------------------------------------
t_ibp_cs_bit8::tag_text_stream__mbc_buffer_to_ucs2::~tag_text_stream__mbc_buffer_to_ucs2()
{;}

//------------------------------------------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_bit8::tag_text_stream__mbc_buffer_to_ucs2::read_ucs2
                                         (size_type  const ucs2_buffer_size,
                                          wchar_t*   const ucs2_buffer,
                                          size_type* const cb_readed)
{
 assert(cb_readed);
 assert(m_charset);

 CHECK_WRITE_TYPED_PTR(ucs2_buffer,ucs2_buffer_size);

 const lock_guard_type __lock(m_guard);

 for((*cb_readed)=0;
     (*cb_readed)!=ucs2_buffer_size && m_source_buffer_pos!=m_source_buffer_size;
     ++(*cb_readed),++m_source_buffer_pos)
 {
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
