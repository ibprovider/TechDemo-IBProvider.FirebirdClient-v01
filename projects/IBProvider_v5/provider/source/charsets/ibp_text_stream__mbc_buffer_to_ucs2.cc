////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_text_stream__mbc_buffer_to_ucs2.cc
//! \brief   ������������� ��������� ������� MultiByte-�������� � ����� UCS2-��������
//! \author  Kovalenko Dmitry
//! \date    08.12.2008
#ifndef _ibp_text_stream__mbc_buffer_to_ucs2_CC_
#define _ibp_text_stream__mbc_buffer_to_ucs2_CC_

#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_text_stream__mbc_buffer_to_ucs2

template<class TCharset>
t_ibp_text_stream__mbc_buffer_to_ucs2<TCharset>::t_ibp_text_stream__mbc_buffer_to_ucs2
                                 (const charset_type* const charset,
                                  const char*         const source_buffer,
                                  size_type           const source_buffer_size)
 :m_charset            (structure::not_null_ptr(charset))
 ,m_target_buffer_pos  (0)
 ,m_target_buffer_size (0)
 ,m_source_buffer_pos  (0)
 ,m_source_buffer_size (source_buffer_size)
 ,m_source_buffer      (source_buffer)
{
 assert(m_charset);

 CHECK_READ_TYPED_PTR(m_source_buffer,m_source_buffer_size);
}//t_ibp_text_stream__mbc_buffer_to_ucs2

//------------------------------------------------------------------------
template<class TCharset>
t_ibp_text_stream__mbc_buffer_to_ucs2<TCharset>::~t_ibp_text_stream__mbc_buffer_to_ucs2()
{;}

//------------------------------------------------------------------------
template<class TCharset>
db_obj::t_db_cs_result
 t_ibp_text_stream__mbc_buffer_to_ucs2<TCharset>::read_ucs2
                                   (size_type  const ucs2_buffer_size,
                                    wchar_t*   const ucs2_buffer,
                                    size_type* const cb_readed)
{
 assert(m_charset);
 assert(cb_readed);

 CHECK_WRITE_TYPED_PTR(ucs2_buffer,ucs2_buffer_size);

 //----------------------------------------- MT-LOCK
 const lock_guard_type __lock(m_guard);

 //-----------------------------------------
 (*cb_readed)=0;

 for(;;)
 {
  //���������� ����� � UCS2-���������
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

  assert(m_source_buffer_pos<=m_source_buffer_size);

  if(m_source_buffer_pos==m_source_buffer_size)
   break; //���������� ���� ����� �������� ������

  {
   //����� ������ ������������� ������
   m_target_buffer_pos=0;
   m_target_buffer_size=_DIM_(m_target_buffer);

   //������������ ��������� MultiByte-������
   const char* source_ptr=m_source_buffer+m_source_buffer_pos;

   const db_obj::t_db_cs_result
    cvt_result=m_charset->single_mbc_to_ucs2
                                 (&source_ptr,
                                  m_source_buffer+m_source_buffer_size,
                                  m_target_buffer,
                                  m_target_buffer_size);

   assert(source_ptr>=m_source_buffer+m_source_buffer_pos);
   assert(source_ptr<=m_source_buffer+m_source_buffer_size);

   assert(m_target_buffer_size<=_DIM_(m_target_buffer));

   //� ��� �� ������ ��������� ������� � �������� OUT-������
   assert(cvt_result!=db_obj::db_cs_result__trunc);

   if(cvt_result==db_obj::db_cs_result__ok)
   {
    //������ ���������
    assert(source_ptr!=m_source_buffer+m_source_buffer_pos);

    //m_source_buffer_pos ���������� ������ ���� �� ���������������� ������
    m_source_buffer_pos=source_ptr-m_source_buffer;

    //��������� UCS2-�������
    continue;
   }//if - ok

   //�� ������������� ������ �� ��� �������� ������ � OUT-����� ������������ �������.

   //������� ���� �� �� ������ ���������������� - ������ �������� �����-�� ��������

   //�� ����, �� ��������� � ���, ��� OUT-����� �������������� �������
   assert(cvt_result!=db_obj::db_cs_result__trunc);

   return db_obj::db_cs_result__fail;
  }//local
 }//for - forever

 return db_obj::db_cs_result__ok;
}//read_ucs2

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
