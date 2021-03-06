////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__blob_helper.h
//! \brief   ??????????????? ????? ? ????? ??? ?????? ? ???????.
//! \author  Kovalenko Dmitry
//! \date    20.09.2015
#ifndef _remote_fb__p12__blob_helper_H_
#define _remote_fb__p12__blob_helper_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__api_p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__BlobHelper

/// <summary>
///  ??????????????? ????? ? ????? ??? ?????? ? ???????.
/// </summary>
class RemoteFB__P12__BlobHelper LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef RemoteFB__P12__BlobHelper             self_type;

 public:
  static void WriteSegment(RemoteFB__ConnectorData* pData,
                           protocol::P_OBJCT        blobSrvID,
                           protocol::P_USHORT       cbData,
                           const void*              pvData);
};//class RemoteFB__P12__BlobHelper

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
