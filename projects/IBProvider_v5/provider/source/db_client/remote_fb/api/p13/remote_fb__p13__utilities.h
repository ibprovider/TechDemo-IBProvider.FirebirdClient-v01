////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__utilities.h
//! \brief   Common utilities for P13.
//! \author  Kovalenko Dmitry
//! \date    09.04.2023
#ifndef _remote_fb__p13__utilities_H_
#define _remote_fb__p13__utilities_H_

#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/error_services/ibp_error_codes.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__Utilities

class RemoteFB__P13__Utilities
{
 public:
  template<typename... Args>
  static void CheckAndSetLength__CSTRING_CONST_V2
               (protocol::set02::P_CSTRING_CONST_V2* pDestCString,
                size_t                               SourceValue,
                ibp_msg_code_type                    ErrMsgID_ArgsPlus2,
                Args&&...                            ErrArgs);
};//class RemoteFB__P13__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
