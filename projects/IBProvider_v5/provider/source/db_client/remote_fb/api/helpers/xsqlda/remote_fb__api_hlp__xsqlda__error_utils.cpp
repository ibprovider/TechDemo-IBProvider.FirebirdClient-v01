////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda__error_utils.cpp
//! \brief   Утилиты для обработки ошибок XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/remote_fb__api_hlp__xsqlda__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA__ErrorUtils

void RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__IncorrectSqlScale
                                           (const wchar_t* const sqlBaseTypeSign,
                                            long           const sqlScale)
{
 assert(sqlBaseTypeSign!=nullptr);

 t_ibp_error exc(E_FAIL,
                 ibp_subsystem__remote_fb,
                 ibp_mce_isc__bug_check__incorrect_sqlscale_in_xvar_2);

 exc<<sqlBaseTypeSign
    <<sqlScale;

 exc.raise_me();
}//ThrowBugCheck__XSQLVAR__IncorrectSqlScale

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__NullPtrInSQLIND
                                           (long const sqlType)
{
 t_ibp_error exc(E_FAIL,
                 ibp_subsystem__remote_fb,
                 ibp_mce_isc__bug_check__null_ptr_to_sqlind_in_xvar_1);

 exc<<sqlType;

 exc.raise_me();
}//ThrowBugCheck__XSQLVAR__NullPtrInSQLIND

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA__ErrorUtils::ThrowBugCheck__XSQLVAR__OtherSqlScale
                                           (const wchar_t* const sqlBaseTypeSign,
                                            long           const actualSqlScale,
                                            long           const expectedSqlScale)
{
 assert(sqlBaseTypeSign!=nullptr);
 assert(actualSqlScale!=expectedSqlScale);

 t_ibp_error exc(E_FAIL,
                 ibp_subsystem__remote_fb,
                 ibp_mce_isc__bug_check__other_sqlscale_of_xvar_3);

 exc<<sqlBaseTypeSign
    <<actualSqlScale
    <<expectedSqlScale;

 exc.raise_me();
}//ThrowBugCheck__XSQLVAR__OtherSqlScale

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
