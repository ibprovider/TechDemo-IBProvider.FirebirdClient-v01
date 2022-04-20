////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                Dmitry Kovalenko. 05.12.2018.
#include <_pch_.h>
#pragma hdrstop

#include <structure/internal/throw_error.h>

#include "source/error_services/ibp_error_utils.h"

namespace structure{namespace internal{
////////////////////////////////////////////////////////////////////////////////
//class throw_error

void throw_error::parameter_list__duplicate_param(astr_box_type const name)
{
 LCPI_IBP_NMS::IBP_ErrorUtils::Throw__Error
  (E_INVALIDARG,
   LCPI_IBP_NMS::lcpi_lib_structure__err_mc__parameter_list___duplicate_param__1,
   name);
}//parameter_list__duplicate_param - astr

//------------------------------------------------------------------------
void throw_error::parameter_list__duplicate_param(wstr_box_type const name)
{
 LCPI_IBP_NMS::IBP_ErrorUtils::Throw__Error
  (E_INVALIDARG,
   LCPI_IBP_NMS::lcpi_lib_structure__err_mc__parameter_list___duplicate_param__1,
   name);
}//parameter_list__duplicate_param - wstr

//------------------------------------------------------------------------
void throw_error::parameter_list__bad_format_of_quoted_item_name()
{
 LCPI_IBP_NMS::IBP_ErrorUtils::Throw__Error
  (E_INVALIDARG,
   LCPI_IBP_NMS::lcpi_lib_structure__err_mc__parameter_list___bad_fmt_of_quoted_item_name__0);
}//parameter_list__bad_format_of_quoted_item_name

//------------------------------------------------------------------------
void throw_error::parameter_list__bad_format_of_quoted_item_value()
{
 LCPI_IBP_NMS::IBP_ErrorUtils::Throw__Error
  (E_INVALIDARG,
   LCPI_IBP_NMS::lcpi_lib_structure__err_mc__parameter_list___bad_fmt_of_quoted_item_value__0);
}//parameter_list__bad_format_of_quoted_item_value

////////////////////////////////////////////////////////////////////////////////
}/*nms internal*/}/*nms structure*/
