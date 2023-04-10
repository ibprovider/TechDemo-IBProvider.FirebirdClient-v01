////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_pset02
//! \file    remote_fb__pset02__utilities.cc
//! \brief   Common utilities for PSET02.
//! \author  Kovalenko Dmitry
//! \date    09.04.2023
#ifndef _remote_fb__pset02__utilities_CC_
#define _remote_fb__pset02__utilities_CC_

#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__Utilities

template<typename... Args>
void RemoteFB__PSET02__Utilities::CheckAndSetLength__CSTRING_CONST_V1
                                (protocol::set02::P_CSTRING_CONST_V1* const pDestCString,
                                 size_t                               const SourceValue,
                                 t_ibp_subsystem_id                   const ErrSubSystemID,
                                 ibp_msg_code_type                    const ErrMsgID_ArgsPlus2,
                                 Args&&...                                  ErrArgs)
{
 assert(pDestCString!=nullptr);

 assert_s(protocol::set02::C_CSTRING_V1_MAX_LENGTH>0);

 if(protocol::set02::C_CSTRING_V1_MAX_LENGTH<SourceValue)
 {
  //ERROR - Too large data length

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ErrSubSystemID,
    ErrMsgID_ArgsPlus2,
    std::forward<Args>(ErrArgs)...,
    SourceValue,
    protocol::set02::C_CSTRING_V1_MAX_LENGTH);
 }//if

 assert(structure::can_numeric_cast(&pDestCString->cstr_length,SourceValue));

 structure::static_numeric_cast(&pDestCString->cstr_length,SourceValue);
}//CheckAndSetLength__CSTRING_CONST_V1

////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
