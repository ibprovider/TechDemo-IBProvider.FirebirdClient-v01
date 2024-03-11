////////////////////////////////////////////////////////////////////////////////
//! \ingroup ib_base
//! \file    ib_charset_utility.h
//! \brief   Утилиты для работы с кодовыми страницами
//! \author  Kovalenko Dmitry
//! \date    12.01.2009
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/ib_base/ib_charset_utility.h"
#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/db_obj/db_charset_manager_v2.h"
#include "source/db_obj/db_service_utils.h"

#include "source/error_services/ibp_error_utils.h"

#include <structure/charsets/t_cs_utf_fss.h>
#include <structure/charsets/t_cs_utf16.h>

#include <lcpi/lib/structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace ib_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ib_base
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Получение кодовой страницы для конвертирования метаданных
/// </summary>
//! \param[in] pCsMng
//!  Not NULL
db_obj::t_db_charset_const_ptr ib_get_metadata_charset(db_obj::t_db_charset_manager_v2* const pCsMng)
{
 assert(pCsMng);

 db_obj::t_db_charset_const_ptr spCnCharset(pCsMng->get_cn_charset());

 assert(spCnCharset);

 if(!spCnCharset->get_info().is_none())
  return /*move*/ spCnCharset;

 return pCsMng->get_ods_charset();
}//ib_get_metadata_charset

////////////////////////////////////////////////////////////////////////////////

static bool ib_object_name_is_ok__fss_bytes
                             (const isc_base::t_isc_connection_settings& cns,
                              structure::t_const_wstr_box          const objectName)
{
 assert(cns.max_obj_name_len.is_in_fss_bytes());

 assert(cns.max_obj_name_len.get_value()>0);

 const wchar_t* const c_bugcheck_src
  =L"ib_base::ib_object_name_is_ok__fss_bytes";

 namespace cs_utf_fss=structure::charsets::cs_utf_fss;

 const auto r
  =cs_utf_fss::length_of_ucs2_as_fss
    (objectName.begin(),
     objectName.end(),
     cns.max_obj_name_len.get_value());

 switch(r.second)
 {
  case cs_utf_fss::cs_cvt_result__ok:
  {
   assert(r.first<=cns.max_obj_name_len.get_value());

   return true;
  }//ok

  case cs_utf_fss::cs_cvt_result__overflow:
  {
   return false;
  }//overflow

  default:
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#001",
     L"unexpected cvt-result [%1]",
     lib::structure::to_underlying(r.second));
  }//if
 }//switch r.second
}//ib_object_name_is_ok__fss_bytes

//-------------------------------------------------------------------
static bool ib_object_name_is_ok__utf8_symbols
                             (const isc_base::t_isc_connection_settings& cns,
                              structure::t_const_wstr_box          const objectName)
{
 assert(cns.max_obj_name_len.is_in_utf8_symbols());

 assert(cns.max_obj_name_len.get_value()>0);

 const wchar_t* const c_bugcheck_src
  =L"ib_base::ib_object_name_is_ok__utf8_symbols";

 namespace cs_utf16=structure::charsets::cs_utf16;

 const auto r
  =cs_utf16::calc_symbol_count
    (objectName.begin(),
     objectName.end(),
     cns.max_obj_name_len.get_value());

 switch(r.second)
 {
  case cs_utf16::cs_cvt_result__ok:
  {
   assert(r.first<=cns.max_obj_name_len.get_value());

   return true;
  }//ok

  case cs_utf16::cs_cvt_result__overflow:
  {
   return false;
  }//overflow

  case cs_utf16::cs_cvt_result__trunc_input:
  {
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_common__cant_calc_object_name_length_1,
     L"trunc_input");
  }//trunc_input

  case cs_utf16::cs_cvt_result__bad_input:
  {
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_common__cant_calc_object_name_length_1,
     L"bad_input");
  }//bad_input

  default:
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#001",
     L"unexpected cvt-result [%1]",
     lib::structure::to_underlying(r.second));
  }//if
 }//switch r.second

 return false;
}//ib_object_name_is_ok__utf8_symbols

//-------------------------------------------------------------------
bool ib_object_name_is_ok(const isc_base::t_isc_connection_settings& cns,
                          structure::t_const_wstr_box          const objectName)
{
 assert(!cns.max_obj_name_len.is_not_defined());

 const wchar_t* const c_bugcheck_src
  =L"ib_base::ib_object_name_is_ok";

 switch(const auto kind=cns.max_obj_name_len.get_kind())
 {
  case isc_base::tag_isc_max_obj_name_len_kind::in_fss_bytes:
  {
   return ib_object_name_is_ok__fss_bytes
           (cns,
            objectName);
  }//in_fss_bytes

  case isc_base::tag_isc_max_obj_name_len_kind::in_utf8_symbols:
  {
   return ib_object_name_is_ok__utf8_symbols
           (cns,
            objectName);
  }//in_utf8_symbols

  default:
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#001",
     L"unexpected max_obj_name_len.kind [%1]",
     lib::structure::to_underlying(kind));
  }//default
 }//switch
}//ib_object_name_is_ok

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ib_base*/}/*nms ibp*/}/*nms lcpi*/
