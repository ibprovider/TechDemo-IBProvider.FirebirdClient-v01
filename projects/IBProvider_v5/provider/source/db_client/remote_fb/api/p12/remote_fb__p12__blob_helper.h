////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__blob_helper.h
//! \brief   ¬спомогательный класс с кодом дл€ работы с блобами.
//! \author  Kovalenko Dmitry
//! \date    20.09.2015
#ifndef _remote_fb__p12__blob_helper_H_
#define _remote_fb__p12__blob_helper_H_

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12.h"
#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__BlobHelper

/// <summary>
///  ¬спомогательный класс с кодом дл€ работы с блобами.
/// </summary>
class RemoteFB__P12__BlobHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__P12__BlobHelper;

 public:
  static void WriteSegment(RemoteFB__P12__SrvOperation& serverOperation,
                           RemoteFB__ConnectorData*     pData,
                           protocol::P_OBJCT            blobSrvID,
                           protocol::P_USHORT           cbData,
                           const void*                  pvData);
};//class RemoteFB__P12__BlobHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
