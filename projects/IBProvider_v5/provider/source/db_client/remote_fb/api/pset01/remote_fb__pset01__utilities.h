////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_pset01
//! \file    remote_fb__pset01__utilities.h
//! \brief   Common utilities for PSET01.
//! \author  Kovalenko Dmitry
//! \date    09.04.2023
#ifndef _remote_fb__pset01__utilities_H_
#define _remote_fb__pset01__utilities_H_

#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/error_services/ibp_error_codes.h"
#include "source/ibp_subsystem_ids.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_pset01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__Utilities

class RemoteFB__PSET01__Utilities
{
 public:
  template<typename... Args>
  static void CheckAndSetLength__CSTRING_CONST
               (protocol::set01::P_CSTRING_CONST* pDestCString,
                size_t                            SourceValue,
                t_ibp_subsystem_id                ErrSubSystemID,
                ibp_msg_code_type                 ErrMsgID_ArgsPlus2,
                Args&&...                         ErrArgs);
};//class RemoteFB__PSET01__Utilities

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__utilities.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
