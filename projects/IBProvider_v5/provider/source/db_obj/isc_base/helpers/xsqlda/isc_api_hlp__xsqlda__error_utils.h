////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api_hlp__xsqlda__error_utils.h
//! \brief   Утилиты для обработки ошибок XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    28.02.2023
#ifndef _isc_api_hlp__xsqlda__error_utils_H_
#define _isc_api_hlp__xsqlda__error_utils_H_

#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace isc_base{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class ISC_API_HLP__XSQLDA__ErrorUtils

/// <summary>
///  Утилиты для обработки ошибок XSQLDA / XSQLVAR.
/// </summary>
class ISC_API_HLP__XSQLDA__ErrorUtils
{
 public:
  template<typename TSize>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheck__XSQLVAR__IncorrectSqlLen
               (const wchar_t*     sqlTypeSign,
                TSize              sqlLen);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheck__XSQLVAR__IncorrectSqlScale
               (const wchar_t*     sqlBaseTypeSign,
                long               sqlScale);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
               (long               sqlType);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheck__XSQLVAR__OtherSqlScale
               (const wchar_t*     sqlBaseTypeSign,
                long               actualSqlScale,
                long               expectedSqlScale);

  template<typename TActualSize,typename TExpectedSize>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheck__XSQLVAR__OtherSqlLen
               (const wchar_t*     sqlTypeSign,
                TActualSize        actualSqlLen,
                TExpectedSize      expectedSqlLen);
};//class ISC_API_HLP__XSQLDA__ErrorUtils

////////////////////////////////////////////////////////////////////////////////
//class ISC_API_HLP__XSQLDA__ErrorUtils

template<typename TSize>
void ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
                                           (const wchar_t*     const sqlTypeSign,
                                            TSize              const sqlLen)
{
 assert(sqlTypeSign!=nullptr);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__incorrect_sqllen_in_xvar_2,
   sqlTypeSign,
   sqlLen);
}//ThrowBugCheck__XSQLVAR__IncorrectSqlLen

//------------------------------------------------------------------------
template<typename TActualSize,typename TExpectedSize>
void ISC_API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlLen
                                           (const wchar_t*     const sqlTypeSign,
                                            TActualSize        const actualSqlLen,
                                            TExpectedSize      const expectedSqlLen)
{
 assert(sqlTypeSign!=nullptr);
 assert(actualSqlLen!=expectedSqlLen);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_isc__bug_check__other_sqllen_of_xvar_3,
   sqlTypeSign,
   actualSqlLen,
   expectedSqlLen);
}//ThrowBugCheck__XSQLVAR__OtherSqlLen

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
