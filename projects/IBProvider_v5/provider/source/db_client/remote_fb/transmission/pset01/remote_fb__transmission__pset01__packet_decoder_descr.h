////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__packet_decoder_descr.h
//! \brief   Описание распаковщика пакета.
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#ifndef _remote_fb__transmission__pset01__packet_decoder_descr_H_
#define _remote_fb__transmission__pset01__packet_decoder_descr_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__PSET01__PacketDecoderDescr

/// <summary>
///  Описание распаковщика пакета.
/// </summary>
struct RemoteFB__PSET01__PacketDecoderDescr LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__PSET01__PacketDecoderDescr;

 public: //typedefs ------------------------------------------------------
  using PacketDecodePFunc_t
   =void (*)
     (RemoteFB__PortOperationContext& op_ctx,
      protocol::set01::PACKET_V01&    packet);

 public:
#ifndef NDEBUG
  protocol::set01::P_OP OperationID;
#endif
  PacketDecodePFunc_t   PacketDecoder;

 public:
#ifndef NDEBUG
  static void Debug__CheckArray(size_t           szArray,
                                const self_type* pArray);
#endif
};//struct RemoteFB__PSET01__PacketDecoderDescr

////////////////////////////////////////////////////////////////////////////////
//Map

#ifndef NDEBUG

# define DIRECT_FB__PACKET_DECODER_DESCR(id,func)  {protocol::set01::id,func},

#else

# define DIRECT_FB__PACKET_DECODER_DESCR(id,func)  {func},

#endif

//------------------------------------------------------------------------

# define DIRECT_FB__PACKET_DECODER_DESCR_STD_C(op)  \
 DIRECT_FB__PACKET_DECODER_DESCR(op,RemoteFB__PSET01__OpDecoder::decode__##op)

# define DIRECT_FB__PACKET_DECODER_DESCR_STD_S(op)  \
 DIRECT_FB__PACKET_DECODER_DESCR(op,RemoteFB__PSET01__OpDecoder::decode__##op##__s)

# define DIRECT_FB__PACKET_DECODER_NONE             \
 DIRECT_FB__PACKET_DECODER_DESCR(op_void,nullptr)

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
