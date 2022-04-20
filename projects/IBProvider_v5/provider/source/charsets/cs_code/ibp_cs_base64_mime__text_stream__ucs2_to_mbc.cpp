////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_base64_mime__text_stream__ucs2_to_mbc.cpp
//! \brief   BASE64 [MIME]. ��������� ������ UCS2-�������� � ����� MBC-��������.
//! \author  Kovalenko Dmitry
//! \date    18.11.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_base64_mime__text_stream__ucs2_to_mbc.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc

t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc::tag_text_stream__ucs2_to_mbc
                                           (db_obj::t_db_text_stream__ucs2* const source__ucs2)
 :m_source__ucs2  (structure::not_null_ptr(source__ucs2))
 ,m_state_id      (state_id__process_mime_chars)
 ,m_buffer_pos    (0)
 ,m_buffer_size   (0)
{
 assert(m_source__ucs2);

 //������ ������� ������ ��������� � ����������� ���������
 assert(m_mime_decoder.complete());
}//tag_text_stream__ucs2_to_mbc

//------------------------------------------------------------------------
t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc::~tag_text_stream__ucs2_to_mbc()
{;}

//t_db_text_stream__mbc interface ----------------------------------------
db_obj::t_db_cs_result t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc::read_mbc
                                           (size_type  const mbc_buffer_size,
                                            char*      const mbc_buffer,
                                            size_type* const cb_readed)
{
 assert(cb_readed);
 assert(m_source__ucs2);

 CHECK_WRITE_TYPED_PTR(mbc_buffer,mbc_buffer_size);

 //-----
 const wchar_t* const c_bug_check_src
  =L"t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc::read_mbc";

 //-----
 const lock_guard_type __lock(m_guard);

 for((*cb_readed)=0;(*cb_readed)!=mbc_buffer_size;)
 {
  assert(m_buffer_pos<=m_buffer_size);

  if(m_buffer_pos==m_buffer_size)
  {
   //���������� ��� ������� � ��������� ������

   //�����
   m_buffer_pos=0;
   m_buffer_size=0;

   //�������� ����� ������
   assert(m_source__ucs2);

   const db_obj::t_db_cs_result
    cs_result=m_source__ucs2->read_ucs2(_DIM_(m_buffer),m_buffer,&m_buffer_size); //throw

   assert(m_buffer_size<=_DIM_(m_buffer));

   if(cs_result!=db_obj::db_cs_result__ok)
   {
    assert(cs_result==db_obj::db_cs_result__fail);

    return cs_result;
   }//if

   //-----
   if(m_buffer_size==0)
    return this->ev_finish(); //������� ��� ������
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

    //������� � ����� ��������� ������������ ��������
    m_state_id=state_id__process_terminate_space;

    continue;
   }//state_id__process_mime_chars

   case state_id__process_terminate_space:
   {
    //�� ������������ ������� ������ � ������ ����������� ����������
    //��������� MIME-������

    assert(m_mime_decoder.complete());

    //���� ��������� ����������� ��������
    if(source_ch!=source_char_traits2::ch_space())
     return db_obj::db_cs_result__fail;

    //���������� ������������ �������
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

  //��������� ��������� ������ � ��������� ������
  assert((*cb_readed)<mbc_buffer_size);

  mbc_buffer[*cb_readed]=dest_char_type(source_ch);

  //���������� ������� �� ���������� ������
  ++m_buffer_pos;

  ++(*cb_readed);
 }//for - �������� ���� ���� ����� � OUT-������

 return db_obj::db_cs_result__ok;
}//read_mbc

//------------------------------------------------------------------------
db_obj::t_db_cs_result t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc::ev_finish()const
{
 const wchar_t* const c_bug_check_src
  =L"t_ibp_cs_base64_mime::tag_text_stream__ucs2_to_mbc::ev_finish";

 switch(m_state_id)
 {
  case state_id__process_mime_chars:
  {
   //�� ������������ MIME-�������

   //���� ����� ������������ �������� ������ 4, �� ��� ���������
   if(m_mime_decoder.complete())
    return db_obj::db_cs_result__ok;

   return db_obj::db_cs_result__fail;
  }//state_id__process_mime_chars

  case state_id__process_terminate_space:
  {
   //�� ������������ ����������� ������������ �������

   //��� �������� ������ � ������ ����������� ���������� ��������� MIME-������
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
