////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__packet_stream.h
//! \brief   Интерфейс потока пакетов.
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#ifndef _remote_fb__transmission__packet_stream_H_
#define _remote_fb__transmission__packet_stream_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PacketStream

/// <summary>
///  Интерфейс потока пакетов.
/// <summary>
class RemoteFB__PacketStream
{
 public:
  /// <summary>
  ///  Упаковка и отправка пакета
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] packet
  virtual void SendPacket(RemoteFB__PortOperationContext& op_ctx,
                          const protocol::PACKET&         packet)const=0;

  /// <summary>
  ///  Получение и распаковка пакета
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[out] packet
  virtual void ReceivePacket(RemoteFB__PortOperationContext& op_ctx,
                             protocol::PACKET&               packet)const=0;
};//class RemoteFB__PacketStream

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
