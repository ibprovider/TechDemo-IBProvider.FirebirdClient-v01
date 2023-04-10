////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_pset02
//! \file    remote_fb__pset02__utilities.h
//! \brief   Common utilities for PSET02.
//! \author  Kovalenko Dmitry
//! \date    09.04.2023
#ifndef _remote_fb__pset02__utilities_H_
#define _remote_fb__pset02__utilities_H_

#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/error_services/ibp_error_codes.h"
#include "source/ibp_subsystem_ids.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_pset02
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__Utilities

class RemoteFB__PSET02__Utilities
{
 public:
  template<typename... Args>
  static void CheckAndSetLength__CSTRING_CONST_V1
               (protocol::set02::P_CSTRING_CONST_V1* pDestCString,
                size_t                               SourceValue,
                t_ibp_subsystem_id                   ErrSubSystemID,
                ibp_msg_code_type                    ErrMsgID_ArgsPlus2,
                Args&&...                            ErrArgs);
};//class RemoteFB__PSET02__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__utilities.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
