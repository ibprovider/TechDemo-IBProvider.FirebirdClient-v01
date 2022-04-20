////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_set01__utilities.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR (V1).
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error.h"
#include <structure/t_str_formatter.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////

void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ThrowBugCheck__UnexpectedTruncation
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const sqld)
{
 assert(place);
 assert(point);

 structure::wstr_formatter
  freason(L"unexpected truncation of buffer. sqld: %1");

 freason<<sqld;

 IBP_ThrowBugCheck
  (place,
   point,
   freason.c_str());
}//Helper__ThrowBugCheck__UnexpectedTruncation

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue
                                           (const wchar_t* const fieldName)
{
 assert(fieldName);

 t_ibp_error exc(E_FAIL,
                 ibp_mce_isc__bug_check__mult_def_of_xsqlvar_field_value_1);

 exc<<fieldName;

 exc.raise_me();
}//Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
                                           (const wchar_t* const fieldName)
{
 assert(fieldName);

 t_ibp_error exc(E_FAIL,
                 ibp_mce_isc__bug_check__not_def_xsqlvar_field_value_1);

 exc<<fieldName;

 exc.raise_me();
}//Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
