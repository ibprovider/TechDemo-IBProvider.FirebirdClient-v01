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

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//RemoteFB__API_HLP__XSQLDA_V01__Utilities

size_t RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__AddMsgLength
                                           (size_t        cbMsg,
                                            size_t  const cbElement,
                                            size_t  const cbAlign,
                                            size_t* const pcbResultAlign)
{
 cbMsg=Helper__AlignMsgLength(cbMsg,cbAlign,pcbResultAlign); //throw

 return Helper__AddMsgLength(cbMsg,cbElement); //throw
}//Helper__AddMsgLength

//------------------------------------------------------------------------
size_t RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__AddMsgLength
                                           (size_t       cbMsg,
                                            size_t const cbElement)
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__AddMsgLength";

 if((structure::t_numeric_limits<size_t>::max_value()-cbMsg)<cbElement)
  IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

 return cbMsg+cbElement;
}//Helper__AddMsgLength

//------------------------------------------------------------------------
size_t RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__AlignMsgLength
                                           (size_t        cbMsg,
                                            size_t  const cbAlign,
                                            size_t* const pcbResultAlign)
{
 assert(cbAlign==1 ||
        cbAlign==2 ||
        cbAlign==4 ||
        cbAlign==8 ||
        cbAlign==16);

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_HLP__XSQLDA_V01__Utilities::Helper__AlignMsgLength";

 if(!structure::align_memory_size(/*ref*/cbMsg,cbAlign))
  IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

 if(pcbResultAlign!=nullptr)
 {
  if((*pcbResultAlign)<cbAlign)
   (*pcbResultAlign)=cbAlign;
 }//if

 return cbMsg;
}//Helper__AlignMsgLength

//------------------------------------------------------------------------
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
