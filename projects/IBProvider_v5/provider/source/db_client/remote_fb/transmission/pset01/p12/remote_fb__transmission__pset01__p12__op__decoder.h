////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__op__decoder.h
//! \brief   Ќабор утилит дл€ распаковки операций
//! \author  Kovalenko Dmitry
//! \date    27.05.2015.
#ifndef _remote_fb__transmission__pset01__p12__op__decoder_H_
#define _remote_fb__transmission__pset01__p12__op__decoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01__p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__OpDecoder

/// <summary>
///  Ќабор утилит дл€ распаковки операций
/// </summary>
class RemoteFB__PSET01__P12__OpDecoder
{
 public:
  static void decode__op_sql_response__a
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_fetch_response__a
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_slice__a
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);
};//class RemoteFB__PSET01__P12__OpDecoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
