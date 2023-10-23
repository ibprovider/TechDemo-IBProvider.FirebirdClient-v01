////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__op__decoder.h
//! \brief   Ќабор утилит дл€ распаковки операций
//! \author  Kovalenko Dmitry
//! \date    26.11.2014.
#ifndef _remote_fb__transmission__pset01__op__decoder_H_
#define _remote_fb__transmission__pset01__op__decoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__OpDecoder

/// <summary>
///  Ќабор утилит дл€ распаковки операций
/// </summary>
class RemoteFB__PSET01__OpDecoder LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static void decode__op_accept
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_reject
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_response
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_dummy
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_trusted_auth
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_sql_response__s
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_fetch_response__s
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);

  static void decode__op_slice__s
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set01::PACKET_V01&    packet);
};//class RemoteFB__PSET01__OpDecoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
