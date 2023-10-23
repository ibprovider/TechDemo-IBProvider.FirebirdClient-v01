////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__packet__receive.cpp
//! \brief   Конструкции для получения и распаковки пакета
//! \author  Kovalenko Dmitry
//! \date    06.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__packet__receive.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__op__decoder.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__decoder.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01
//! @{
////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
static void Helper__RemoteFB__ReceivePacket__GetDecoder__ThrowErrow__UnkOp
                                           (int const iOp)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_subsystem__remote_fb__pset01,
   ibp_mce_remote__receive_pack__unk_op_id_1,
   iOp);
}//Helper__RemoteFB__ReceivePacket__GetDecoder__ThrowErrow__UnkOp

////////////////////////////////////////////////////////////////////////////////

static const RemoteFB__PSET01__PacketDecoderDescr&
        Helper__RemoteFB__ReceivePacket__GetDecoder
                                           (protocol::set01::P_OP                       const op,
                                            size_t                                      const cDecoders,
                                            const RemoteFB__PSET01__PacketDecoderDescr* const pDecoders)
{
 const int iOp=static_cast<int>(op);

 if(iOp<0)
 {
  // ERROR - некорректный идентификатор операции

  Helper__RemoteFB__ReceivePacket__GetDecoder__ThrowErrow__UnkOp(iOp);
 }//if iOp<0

 const size_t uiOp=static_cast<size_t>(iOp);

 if(uiOp>=cDecoders)
 {
  // ERROR - некорректный идентификатор операции

  Helper__RemoteFB__ReceivePacket__GetDecoder__ThrowErrow__UnkOp(iOp);
 }//if

 const RemoteFB__PSET01__PacketDecoderDescr& descr=pDecoders[uiOp];

 if(descr.PacketDecoder==nullptr)
 {
  assert(descr.OperationID==protocol::set01::op_void || descr.OperationID==op);

  // ERROR - неизвестный идентификатор операции

  Helper__RemoteFB__ReceivePacket__GetDecoder__ThrowErrow__UnkOp(iOp);
 }//if

 assert(descr.PacketDecoder!=nullptr);

 assert(descr.OperationID==op);

 return descr;
}//Helper__RemoteFB__ReceivePacket__GetDecoder

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Получение и распаковка пакета
/// </summary>
//! \param[in]  op_ctx
//! \param[out] packet
//! \param[in]  cDecoders
//! \param[in]  pDecoders
void RemoteFB__PSET01__ReceivePacket(RemoteFB__PortOperationContext&                   op_ctx,
                                     protocol::set01::PACKET_V01&                      packet,
                                     size_t                                      const cDecoders,
                                     const RemoteFB__PSET01__PacketDecoderDescr* const pDecoders)
{
 using xdr=RemoteFB__PSET01__XDR__Decoder;

 RemoteFB__PortReadGuard readGuard(op_ctx); //throw

 for(;;)
 {
  xdr::decode__p_op
   (readGuard.reader(),
    L"protocol::set01::PACKET_V01::p_operation",
    &packet.operation); //throw

  const RemoteFB__PSET01__PacketDecoderDescr&
   descr
    =Helper__RemoteFB__ReceivePacket__GetDecoder
      (packet.operation,
       cDecoders,
       pDecoders);

  assert(descr.OperationID==packet.operation);
  assert(descr.PacketDecoder!=nullptr);

  descr.PacketDecoder
   (op_ctx,
    packet); //throw

  if(packet.operation!=protocol::set01::op_dummy)
   break;
 }//for[ever]

 readGuard.complete(); //throw
}//RemoteFB__PSET01__ReceivePacket

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
