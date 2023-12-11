////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__packet__send.cpp
//! \brief   Конструкции для упаковки и отправки пакета
//! \author  Kovalenko Dmitry
//! \date    01.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__packet__send.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__encoder.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_str_formatter.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01
//! @{
////////////////////////////////////////////////////////////////////////////////

static void Helper__RemoteFB__SendPacket__ThrowBugCheck__UnkOp
                                           (const wchar_t*        const place,
                                            const wchar_t*        const point,
                                            protocol::set01::P_OP const operationID)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__send_packet_with_unk_operation_1,
   operationID);
}//Helper__RemoteFB__SendPacket__ThrowBugCheck__UnkOp

//------------------------------------------------------------------------
/// <summary>
///  Упаковка и отправка пакета
/// </summary>
//! \param[in] op_ctx
//! \param[in] packet
//! \param[in] cEncoders
//! \param[in] pEncoders
void RemoteFB__PSET01__SendPacket(RemoteFB__PortOperationContext&                   op_ctx,
                                  const protocol::set01::PACKET_V01&                packet,
                                  size_t                                      const cEncoders,
                                  const RemoteFB__PSET01__PacketEncoderDescr* const pEncoders)
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET01__SendPacket";

 //-----------------------------------------
 const size_t idx=static_cast<size_t>(packet.operation);

 if(!(idx<cEncoders))
 {
  Helper__RemoteFB__SendPacket__ThrowBugCheck__UnkOp
   (c_bugcheck_src,
    L"#001",
    packet.operation);
 }//if

 assert(idx<cEncoders);

 const RemoteFB__PSET01__PacketEncoderDescr& descr=pEncoders[idx];

 assert(descr.OperationID==packet.operation);

 if(descr.PacketEncoder==nullptr)
 {
  Helper__RemoteFB__SendPacket__ThrowBugCheck__UnkOp
   (c_bugcheck_src,
    L"#002",
    packet.operation);
 }//if

 assert(descr.PacketEncoder!=nullptr);

 //-----------------------------------------
 using xdr=RemoteFB__PSET01__XDR__Encoder;

 RemoteFB__PortWriteGuard writeGuard(op_ctx); //throw

 xdr::encode__p_op(writeGuard.writer(),&packet.operation); //throw

 descr.PacketEncoder(op_ctx,packet); //throw

 writeGuard.complete(); //throw
}//RemoteFB__PSET01__SendPacket

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
