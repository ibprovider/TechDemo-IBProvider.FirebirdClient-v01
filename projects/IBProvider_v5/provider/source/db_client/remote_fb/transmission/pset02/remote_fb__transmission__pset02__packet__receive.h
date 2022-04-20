////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__packet__receive.h
//! \brief   Конструкции для получения и распаковки пакета
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__packet__receive_H_
#define _remote_fb__transmission__pset02__packet__receive_H_

#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__packet_decoder_descr.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////

void RemoteFB__PSET02__ReceivePacket(RemoteFB__PortOperationContext&             op_ctx,
                                     protocol::set02::PACKET_V02&                packet,
                                     size_t                                      cDecoders,
                                     const RemoteFB__PSET02__PacketDecoderDescr* pDecoders);

////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
