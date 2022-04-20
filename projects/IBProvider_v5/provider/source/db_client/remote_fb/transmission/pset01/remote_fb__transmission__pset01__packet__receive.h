////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__packet__receive.h
//! \brief   Конструкции для получения и распаковки пакета
//! \author  Kovalenko Dmitry
//! \date    06.11.2014.
#ifndef _remote_fb__transmission__pset01__packet__receive_H_
#define _remote_fb__transmission__pset01__packet__receive_H_

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__packet_decoder_descr.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////

void RemoteFB__PSET01__ReceivePacket(RemoteFB__PortOperationContext&             op_ctx,
                                     protocol::set01::PACKET_V01&                packet,
                                     size_t                                      cDecoders,
                                     const RemoteFB__PSET01__PacketDecoderDescr* pDecoders);

////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
