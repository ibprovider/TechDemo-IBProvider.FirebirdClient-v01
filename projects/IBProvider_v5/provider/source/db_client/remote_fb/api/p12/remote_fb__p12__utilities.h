////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__utilities.h
//! \brief   Common utilities for P12.
//! \author  Kovalenko Dmitry
//! \date    09.04.2023
#ifndef _remote_fb__p12__utilities_H_
#define _remote_fb__p12__utilities_H_

#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/error_services/ibp_error_codes.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__Utilities

class RemoteFB__P12__Utilities
{
 public:
  template<typename... Args>
  static void CheckAndSetLength__CSTRING_CONST
               (protocol::set01::P_CSTRING_CONST* pDestCString,
                size_t                            SourceValue,
                ibp_msg_code_type                 ErrMsgID_ArgsPlus2,
                Args&&...                         ErrArgs);
};//class RemoteFB__P12__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__utilities.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
