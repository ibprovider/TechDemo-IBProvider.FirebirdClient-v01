////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_cs_octets.cpp
//! \brief   «аглушка дл€ представлени€ кодовой страницы OCTETS
//! \author  Kovalenko Dmitry
//! \date    22.01.2009
#include <_pch_.h>
#pragma hdrstop

#include "source/charsets/cs_code/ibp_cs_octets.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_cs_octets

t_ibp_cs_octets::t_ibp_cs_octets(const db_obj::t_db_charset_info& cs_info)
 :m_cs_info(cs_info)
{
}

//------------------------------------------------------------------------
t_ibp_cs_octets::~t_ibp_cs_octets()
{
}

//t_db_charset interface -------------------------------------------------
const db_obj::t_db_charset_info& t_ibp_cs_octets::get_info()const
{
 return m_cs_info;
}//get_info

//------------------------------------------------------------------------
bool t_ibp_cs_octets::to_unicode_v2(std::wstring*              const /*pws*/,
                                    structure::t_const_str_box const /*s*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::to_unicode_v2",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return false;
#endif
}//to_unicode_v2

//------------------------------------------------------------------------
bool t_ibp_cs_octets::from_unicode_v2(std::string*                const /*ps*/,
                                      structure::t_const_wstr_box const /*ws*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::from_unicode_v2",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return false;
#endif
}//from_unicode_v2

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_octets::mbc_stream_to_ucs2_stream
                                  (db_obj::t_db_text_stream__mbc* /*mbc_stream*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::mbc_stream_to_ucs2_stream",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//mbc_stream_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__ucs2_ptr
 t_ibp_cs_octets::mbc_buffer_to_ucs2_stream
                                  (const char* /*mbc_buffer*/,
                                   size_type   /*mbc_buffer_size*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::mbc_buffer_to_ucs2_stream",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//mbc_buffer_to_ucs2_stream

//------------------------------------------------------------------------
db_obj::t_db_text_stream__mbc_ptr
 t_ibp_cs_octets::ucs2_stream_to_mbc_stream
                                  (db_obj::t_db_text_stream__ucs2* const /*ucs2_stream*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::ucs2_stream_to_mbc_stream",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//ucs2_stream_to_mbc_stream

//------------------------------------------------------------------------
db_obj::t_db_cs_result
 t_ibp_cs_octets::sb_to_unicode(ansi_streambuf_type& /*in_buf*/,
                                wchar_t*             /*ws*/,
                                size_type&           /*wsz*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::sb_to_unicode",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return db_obj::db_cs_result__fail;
#endif
}//sb_to_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_octets::sb_len_as_unicode(ansi_streambuf_type& /*in_buf*/,
                                        size_type&           /*wsz*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::sb_len_as_unicode",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return false;
#endif
}//sb_len_as_unicode

//------------------------------------------------------------------------
bool t_ibp_cs_octets::unicode_to_blob(const wchar_t*                  const /*source*/,
                                      size_type                       const /*source_size*/,
                                      db_obj::t_db_seq_stream_writer* const /*writer*/)const
{
 IBP_BUG_CHECK__DEBUG
  (L"t_ibp_cs_octets::unicode_to_blob",
   L"#001",
   L"it is dummy code");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return false;
#endif
}//unicode_to_blob

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
