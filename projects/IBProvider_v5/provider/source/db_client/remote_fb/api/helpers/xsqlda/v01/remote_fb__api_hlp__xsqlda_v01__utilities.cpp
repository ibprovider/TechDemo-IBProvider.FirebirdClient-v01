////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_set01__utilities.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR (V1).
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//RemoteFB__API_HLP__XSQLDA_V01__Utilities

void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA
                                           (const isc_api::XSQLDA_V1* const pXSQLDA,
                                            protocol::P_SHORT         const minSQLD,                           
                                            t_ibp_subsystem_id        const subsystemID,
                                            const wchar_t*            const pXSQLDA_Sign)
{
 assert(pXSQLDA);
 assert(minSQLD==0 || minSQLD==1);
 assert(pXSQLDA_Sign);

 const wchar_t* c_bugcheck_src
  =L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Check_XSQLDA";

 if(pXSQLDA->version!=pXSQLDA->c_version_num)
 {
  RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
   (c_bugcheck_src,
    L"#001",
    pXSQLDA_Sign,
    pXSQLDA->version);
 }//if

 if(pXSQLDA->sqld<minSQLD)
 {
  //ERROR - [BUG CHECK] incorrect XSQLDA::sqld

  assert_msg(false,"pXSQLDA->sqld: "<<pXSQLDA->sqld);

  RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
   (subsystemID,
    pXSQLDA_Sign,
    pXSQLDA->sqld);
 }//if

 if(pXSQLDA->sqln<pXSQLDA->sqld)
 {
  //ERROR - [BUG CHECK] incorrect XSQLDA::sqln

  assert_msg(false,"pXSQLDA->sqln: "<<pXSQLDA->sqln<<". pXSQLDA->sqld: "<<pXSQLDA->sqld);

  RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
   (subsystemID,
    pXSQLDA_Sign,
    pXSQLDA->sqln,
    pXSQLDA->sqld);
 }//if
}//Check_XSQLDA

//Helper utilities -------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ThrowBugCheck__UnexpectedTruncation
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            size_t         const sqld)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   L"unexpected truncation of buffer. sqld: %1",
   sqld);
}//Helper__ThrowBugCheck__UnexpectedTruncation

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue
                                           (const wchar_t* const fieldName)
{
 assert(fieldName);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_subsystem__remote_fb,
   ibp_mce_isc__bug_check__mult_def_of_xsqlvar_field_value_1,
   fieldName);
}//Helper__ThrowBugCheck__XSQLVAR__MultDefFieldValue

//------------------------------------------------------------------------
void RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue
                                           (const wchar_t* const fieldName)
{
 assert(fieldName);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_subsystem__remote_fb,
   ibp_mce_isc__bug_check__not_def_xsqlvar_field_value_1,
   fieldName);
}//Helper__ThrowBugCheck__XSQLVAR__NotDefFieldValue

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
