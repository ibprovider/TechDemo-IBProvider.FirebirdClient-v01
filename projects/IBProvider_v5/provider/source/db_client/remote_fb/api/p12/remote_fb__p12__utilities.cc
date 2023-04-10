////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__utilities.cc
//! \brief   Common utilities for P12.
//! \author  Kovalenko Dmitry
//! \date    09.04.2023
#ifndef _remote_fb__p12__utilities_CC_
#define _remote_fb__p12__utilities_CC_

#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__Utilities

template<typename... Args>
void RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
                                (protocol::set01::P_CSTRING_CONST* const pDestCString,
                                 size_t                            const SourceValue,
                                 ibp_msg_code_type                 const ErrMsgID_ArgsPlus2,
                                 Args&&...                               ErrArgs)
{
 assert(pDestCString!=nullptr);

 assert_s(protocol::set01::C_CSTRING_MAX_LENGTH>0);

 if(protocol::set01::C_CSTRING_MAX_LENGTH<SourceValue)
 {
  //ERROR - Too large data length

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ErrMsgID_ArgsPlus2,
    std::forward<Args>(ErrArgs)...,
    SourceValue,
    protocol::set01::C_CSTRING_MAX_LENGTH);
 }//if

 assert(structure::can_numeric_cast(&pDestCString->cstr_length,SourceValue));

 structure::static_numeric_cast(&pDestCString->cstr_length,SourceValue);
}//CheckAndSetLength__CSTRING_CONST

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
