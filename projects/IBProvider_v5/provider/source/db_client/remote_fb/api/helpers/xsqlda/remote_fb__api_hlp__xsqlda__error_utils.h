////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda__error_utils.h
//! \brief   Утилиты для обработки ошибок XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__api_hlp__xsqlda__error_utils_H_
#define _remote_fb__api_hlp__xsqlda__error_utils_H_

#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_hlp
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA__ErrorUtils

/// <summary>
///  Утилиты для обработки ошибок XSQLDA / XSQLVAR.
/// </summary>
class RemoteFB__API_HLP__XSQLDA__ErrorUtils
{
 public:
  template<typename TSize>
  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__XSQLVAR__IncorrectSqlLen
               (const wchar_t* sqlTypeSign,
                TSize          sqlLen);

  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__XSQLVAR__IncorrectSqlScale
               (const wchar_t* sqlBaseTypeSign,
                long           sqlScale);

  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__XSQLVAR__NullPtrInSQLIND(long sqlType);

  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__XSQLVAR__OtherSqlScale(const wchar_t* sqlBaseTypeSign,
                                                            long           actualSqlScale,
                                                            long           expectedSqlScale);
  template<typename TActualSize,typename TExpectedSize>
  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__XSQLVAR__OtherSqlLen(const wchar_t* sqlTypeSign,
                                                          TActualSize    actualSqlLen,
                                                          TExpectedSize  expectedSqlLen);
};//class RemoteFB__API_HLP__XSQLDA__ErrorUtils

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA__ErrorUtils

template<typename TSize>
void RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlLen
                                           (const wchar_t* const sqlTypeSign,
                                            TSize          const sqlLen)
{
 assert(sqlTypeSign!=nullptr);

 t_ibp_error exc(E_FAIL,
                 ibp_mce_isc__bug_check__incorrect_sqllen_in_xvar_2);

 exc<<sqlTypeSign
    <<sqlLen;

 exc.raise_me();
}//ThrowBugCheck__XSQLVAR__IncorrectSqlLen

//------------------------------------------------------------------------
template<typename TActualSize,typename TExpectedSize>
void RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlLen
                                           (const wchar_t* const sqlTypeSign,
                                            TActualSize    const actualSqlLen,
                                            TExpectedSize  const expectedSqlLen)
{
 assert(sqlTypeSign!=nullptr);
 assert(actualSqlLen!=expectedSqlLen);

 t_ibp_error exc(E_FAIL,
                 ibp_mce_isc__bug_check__other_sqllen_of_xvar_3);

 exc<<sqlTypeSign
    <<actualSqlLen
    <<expectedSqlLen;

 exc.raise_me();
}//ThrowBugCheck__XSQLVAR__OtherSqlLen

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
