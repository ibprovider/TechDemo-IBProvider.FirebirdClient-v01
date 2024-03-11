////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__blob_helper.h
//! \brief   ¬спомогательный класс с кодом дл€ работы с блобами.
//! \author  Kovalenko Dmitry
//! \date    23.09.2016
#ifndef _remote_fb__p13__blob_helper_H_
#define _remote_fb__p13__blob_helper_H_

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13.h"
#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__BlobHelper

/// <summary>
///  ¬спомогательный класс с кодом дл€ работы с блобами.
/// </summary>
class RemoteFB__P13__BlobHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__P13__BlobHelper;

 public:
  static void WriteSegment(RemoteFB__P13__SrvOperation& serverOperation,
                           RemoteFB__ConnectorData*     pData,
                           protocol::P_OBJCT            blobSrvID,
                           protocol::P_USHORT           cbData,
                           const void*                  pvData);
};//class RemoteFB__P13__BlobHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
