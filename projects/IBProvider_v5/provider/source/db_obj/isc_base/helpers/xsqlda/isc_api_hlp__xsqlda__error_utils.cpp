////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api_hlp__xsqlda__error_utils.cpp
//! \brief   Утилиты для обработки ошибок XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    28.02.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/helpers/xsqlda/isc_api_hlp__xsqlda__error_utils.h"

namespace lcpi{namespace ibp{namespace isc_base{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class ISC_API_HLP__XSQLDA__ErrorUtils

void ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlScale
                                           (const wchar_t*     const sqlBaseTypeSign,
                                            long               const sqlScale)
{
 assert(sqlBaseTypeSign!=nullptr);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sqlscale_in_xvar_2,
   sqlBaseTypeSign,
   sqlScale);
}//ThrowBugCheck__XSQLVAR__IncorrectSqlScale

//------------------------------------------------------------------------
void ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
                                           (long               const sqlType)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__null_ptr_to_sqlind_in_xvar_1,
   sqlType);
}//ThrowBugCheck__XSQLVAR__NullPtrInSQLIND

//------------------------------------------------------------------------
void ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
                                           (const wchar_t*     const sqlBaseTypeSign,
                                            long               const actualSqlScale,
                                            long               const expectedSqlScale)
{
 assert(sqlBaseTypeSign!=nullptr);
 assert(actualSqlScale!=expectedSqlScale);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__other_sqlscale_of_xvar_3,
   sqlBaseTypeSign,
   actualSqlScale,
   expectedSqlScale);
}//ThrowBugCheck__XSQLVAR__OtherSqlScale

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
