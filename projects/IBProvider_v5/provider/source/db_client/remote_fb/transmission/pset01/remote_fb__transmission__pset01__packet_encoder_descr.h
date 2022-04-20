////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__packet_encoder_descr.h
//! \brief   Описание упаковщика пакета
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#ifndef _remote_fb__transmission__pset01__packet_encoder_descr_H_
#define _remote_fb__transmission__pset01__packet_encoder_descr_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__PSET01__PacketEncoderDescr

/// <summary>
///  Описание упаковщика пакета.
/// </summary>
struct RemoteFB__PSET01__PacketEncoderDescr
{
 private:
  typedef RemoteFB__PSET01__PacketEncoderDescr      self_type;

 public:
  typedef void (*PacketEncodeFunc)(RemoteFB__PortOperationContext&    op_ctx,
                                   const protocol::set01::PACKET_V01& packet);

 public:
#ifndef NDEBUG
  protocol::set01::P_OP     OperationID;
#endif
  PacketEncodeFunc          PacketEncoder;

 public:
#ifndef NDEBUG
  static void Debug__CheckArray(size_t           szArray,
                                const self_type* pArray);
#endif
};//struct RemoteFB__PSET01__PacketEncoderDescr

////////////////////////////////////////////////////////////////////////////////
//Map

#ifndef NDEBUG

# define DIRECT_FB__PACKET_ENCODER_DESCR(id,func) {protocol::set01::id,func},

#else

# define DIRECT_FB__PACKET_ENCODER_DESCR(id,func) {func},

#endif

//------------------------------------------------------------------------

#define DIRECT_FB__PACKET_ENCODER_DESCR_STD_C(op)  \
 DIRECT_FB__PACKET_ENCODER_DESCR(op,RemoteFB__PSET01__OpEncoder::encode__##op)

#define DIRECT_FB__PACKET_ENCODER_DESCR_STD_A(op)  \
 DIRECT_FB__PACKET_ENCODER_DESCR(op,RemoteFB__PSET01__OpEncoder::encode__##op##__a)

#define DIRECT_FB__PACKET_ENCODER_DESCR_STD_S(op)  \
 DIRECT_FB__PACKET_ENCODER_DESCR(op,RemoteFB__PSET01__OpEncoder::encode__##op##__s)

#define DIRECT_FB__PACKET_ENCODER_NONE             \
 DIRECT_FB__PACKET_ENCODER_DESCR(op_void,nullptr)

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
