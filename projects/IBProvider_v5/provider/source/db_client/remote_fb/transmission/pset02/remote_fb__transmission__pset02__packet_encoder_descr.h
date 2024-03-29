////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__packet_encoder_descr.h
//! \brief   �������� ���������� ������
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__packet_encoder_descr_H_
#define _remote_fb__transmission__pset02__packet_encoder_descr_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02
//! @{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__PSET02__PacketEncoderDescr

/// <summary>
///  �������� ���������� ������.
/// </summary>
struct RemoteFB__PSET02__PacketEncoderDescr LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__PSET02__PacketEncoderDescr;

 public:
  using PacketEncodePFunc_t
   =void (*)
     (RemoteFB__PortOperationContext&    op_ctx,
      const protocol::set02::PACKET_V02& packet);

 public:
#ifndef NDEBUG
  protocol::set02::P_OP     OperationID;
#endif
  PacketEncodePFunc_t       PacketEncoder;

 public:
#ifndef NDEBUG
  static void Debug__CheckArray(size_t           szArray,
                                const self_type* pArray);
#endif
};//struct RemoteFB__PSET02__PacketEncoderDescr

////////////////////////////////////////////////////////////////////////////////
//Map

#ifndef NDEBUG

# define DIRECT_FB__PACKET_ENCODER_DESCR(id,func) {protocol::set02::id,func},

#else

# define DIRECT_FB__PACKET_ENCODER_DESCR(id,func) {func},

#endif

//------------------------------------------------------------------------

#define DIRECT_FB__PACKET_ENCODER_DESCR_STD_C(op)  \
 DIRECT_FB__PACKET_ENCODER_DESCR(op,RemoteFB__PSET02__OpEncoder::encode__##op)

#define DIRECT_FB__PACKET_ENCODER_DESCR_STD_A(op)  \
 DIRECT_FB__PACKET_ENCODER_DESCR(op,RemoteFB__PSET02__OpEncoder::encode__##op##__a)

#define DIRECT_FB__PACKET_ENCODER_DESCR_STD_S(op)  \
 DIRECT_FB__PACKET_ENCODER_DESCR(op,RemoteFB__PSET02__OpEncoder::encode__##op##__s)

#define DIRECT_FB__PACKET_ENCODER_NONE             \
 DIRECT_FB__PACKET_ENCODER_DESCR(op_void,nullptr)

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
