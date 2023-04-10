////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__utilities.cc
//! \brief   Common utilities for P13.
//! \author  Kovalenko Dmitry
//! \date    09.04.2023
#ifndef _remote_fb__p13__utilities_CC_
#define _remote_fb__p13__utilities_CC_

#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__Utilities

template<typename... Args>
void RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
                                (protocol::set02::P_CSTRING_CONST_V2* const pDestCString,
                                 size_t                               const SourceValue,
                                 ibp_msg_code_type                    const ErrMsgID_ArgsPlus2,
                                 Args&&...                                  ErrArgs)
{
 assert(pDestCString!=nullptr);

 assert_s(std::is_same<decltype(pDestCString->cstr_length) _LITER_COMMA_ protocol::P_ULONG>::value);
 assert_s(protocol::set02::C_CSTRING_V2_MAX_LENGTH_P13>0);

 //VS2013 does not allow to use assert_s here
 assert(protocol::set02::C_CSTRING_V2_MAX_LENGTH_P13<=(std::numeric_limits<protocol::P_ULONG>::max)());

 if(protocol::set02::C_CSTRING_V2_MAX_LENGTH_P13<SourceValue)
 {
  //ERROR - Too large data length

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ErrMsgID_ArgsPlus2,
    std::forward<Args>(ErrArgs)...,
    SourceValue,
    protocol::set02::C_CSTRING_V2_MAX_LENGTH_P13);
 }//if

 assert(structure::can_numeric_cast(&pDestCString->cstr_length,SourceValue));

 structure::static_numeric_cast(&pDestCString->cstr_length,SourceValue);
}//CheckAndSetLength__CSTRING_CONST_V2

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
