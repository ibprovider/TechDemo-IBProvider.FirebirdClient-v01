////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__packet_decoder_descr.h
//! \brief   Описание распаковщика пакета.
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__packet_decoder_descr_H_
#define _remote_fb__transmission__pset02__packet_decoder_descr_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__PSET02__PacketDecoderDescr

/// <summary>
///  Описание распаковщика пакета.
/// </summary>
struct RemoteFB__PSET02__PacketDecoderDescr
{
 private:
  typedef RemoteFB__PSET02__PacketDecoderDescr      self_type;

 public: //typedefs ------------------------------------------------------
  typedef void (*PacketDecodeFunc)(RemoteFB__PortOperationContext& op_ctx,
                                   protocol::set02::PACKET_V02&    packet);
 public:
#ifndef NDEBUG
  protocol::set02::P_OP OperationID;
#endif
  PacketDecodeFunc      PacketDecoder;

 public:
#ifndef NDEBUG
  static void Debug__CheckArray(size_t           szArray,
                                const self_type* pArray);
#endif
};//struct RemoteFB__PSET02__PacketDecoderDescr

////////////////////////////////////////////////////////////////////////////////
//Map

#ifndef NDEBUG

# define DIRECT_FB__PACKET_DECODER_DESCR(id,func)  {protocol::set02::id,func},

#else

# define DIRECT_FB__PACKET_DECODER_DESCR(id,func)  {func},

#endif

//------------------------------------------------------------------------

# define DIRECT_FB__PACKET_DECODER_DESCR_STD_C(op)  \
 DIRECT_FB__PACKET_DECODER_DESCR(op,RemoteFB__PSET02__OpDecoder::decode__##op)

# define DIRECT_FB__PACKET_DECODER_DESCR_STD_S(op)  \
 DIRECT_FB__PACKET_DECODER_DESCR(op,RemoteFB__PSET02__OpDecoder::decode__##op##__s)

# define DIRECT_FB__PACKET_DECODER_NONE             \
 DIRECT_FB__PACKET_DECODER_DESCR(op_void,nullptr)

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
