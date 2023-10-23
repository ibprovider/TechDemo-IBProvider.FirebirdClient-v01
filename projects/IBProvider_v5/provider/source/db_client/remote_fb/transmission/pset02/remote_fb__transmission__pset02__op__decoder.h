////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__op__decoder.h
//! \brief   Ќабор утилит дл€ распаковки операций
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__op__decoder_H_
#define _remote_fb__transmission__pset02__op__decoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__OpDecoder

/// <summary>
///  Ќабор утилит дл€ распаковки операций
/// </summary>
class RemoteFB__PSET02__OpDecoder LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static void decode__op_cond_accept
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_accept_data
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_reject
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_response
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_dummy
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_cont_auth
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_sql_response__s
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_fetch_response__s
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);

  static void decode__op_slice__s
               (RemoteFB__PortOperationContext& op_ctx,
                protocol::set02::PACKET_V02&    packet);
};//class RemoteFB__PSET02__OpDecoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
