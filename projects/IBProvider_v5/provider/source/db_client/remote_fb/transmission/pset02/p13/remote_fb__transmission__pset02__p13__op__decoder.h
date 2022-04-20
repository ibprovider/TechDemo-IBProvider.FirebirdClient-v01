////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__op__decoder.h
//! \brief   Ќабор утилит дл€ распаковки операций
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__transmission__pset02__p13__op__decoder_H_
#define _remote_fb__transmission__pset02__p13__op__decoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02__p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__OpDecoder

/// <summary>
///  Ќабор утилит дл€ распаковки операций
/// </summary>
class RemoteFB__PSET02__P13__OpDecoder
{
 public:
  static void decode__op_sql_response__a
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_fetch_response__a
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_slice__a
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);
};//class RemoteFB__PSET02__P13__OpDecoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
