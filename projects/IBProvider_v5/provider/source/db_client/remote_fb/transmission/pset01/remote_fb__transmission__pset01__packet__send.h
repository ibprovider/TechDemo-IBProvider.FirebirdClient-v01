////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__packet__send.h
//! \brief   Конструкции для упаковки и отправки пакета
//! \author  Kovalenko Dmitry
//! \date    01.11.2014.
#ifndef _remote_fb__transmission__pset01__packet__send_H_
#define _remote_fb__transmission__pset01__packet__send_H_

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__packet_encoder_descr.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////

void RemoteFB__PSET01__SendPacket(RemoteFB__PortOperationContext&             op_ctx,
                                  const protocol::set01::PACKET_V01&          packet,
                                  size_t                                      cEncoders,
                                  const RemoteFB__PSET01__PacketEncoderDescr* pEncoders);

////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
