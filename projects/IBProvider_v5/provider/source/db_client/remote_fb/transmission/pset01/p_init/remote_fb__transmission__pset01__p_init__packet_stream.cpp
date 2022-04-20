////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p_init
//! \file    remote_fb__transmission__pset01__p_init__packet_stream.cpp
//! \brief   Поток пакетов этапа инициализации подключения.
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/p_init/remote_fb__transmission__pset01__p_init__packet_stream.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__packet__send.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__packet__receive.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__op__encoder.h"
#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__op__decoder.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p_init{
////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__PSET01__P_INIT__PacketStream::tag_data

struct RemoteFB__PSET01__P_INIT__PacketStream::tag_data
{
 public:
  //упаковщики
  static const RemoteFB__PSET01__PacketEncoderDescr sm_encoders[];

  //распаковщики
  static const RemoteFB__PSET01__PacketDecoderDescr sm_decoders[];
};//struct RemoteFB__PSET01__P_INIT__PacketStream::tag_data

////////////////////////////////////////////////////////////////////////////////
//Упаковщики

const RemoteFB__PSET01__PacketEncoderDescr RemoteFB__PSET01__P_INIT__PacketStream::tag_data::sm_encoders[]=
{
 /* 0*/ DIRECT_FB__PACKET_ENCODER_NONE
 /* 1*/ DIRECT_FB__PACKET_ENCODER_DESCR_STD_C(op_connect)
};//sm_encoders

STARTUP_CODE_EX__DEBUG(check_encoders,
                       RemoteFB__PSET01__P_INIT__PacketStream::Debug__CheckEncoders);

////////////////////////////////////////////////////////////////////////////////
//Распаковщики

const RemoteFB__PSET01__PacketDecoderDescr RemoteFB__PSET01__P_INIT__PacketStream::tag_data::sm_decoders[]=
{
 /* 0*/ DIRECT_FB__PACKET_DECODER_NONE
 /* 1*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_connect
 /* 2*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_exit
 /* 3*/ DIRECT_FB__PACKET_DECODER_DESCR_STD_C(op_accept)
 /* 4*/ DIRECT_FB__PACKET_DECODER_DESCR_STD_C(op_reject)
 /* 5*/ DIRECT_FB__PACKET_DECODER_NONE
 /* 6*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_disconnect
 /* 7*/ DIRECT_FB__PACKET_DECODER_NONE
 /* 8*/ DIRECT_FB__PACKET_DECODER_NONE
 /* 9*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_response
 /*10*/ DIRECT_FB__PACKET_DECODER_NONE
 /*11*/ DIRECT_FB__PACKET_DECODER_NONE
 /*12*/ DIRECT_FB__PACKET_DECODER_NONE
 /*13*/ DIRECT_FB__PACKET_DECODER_NONE
 /*14*/ DIRECT_FB__PACKET_DECODER_NONE
 /*15*/ DIRECT_FB__PACKET_DECODER_NONE
 /*16*/ DIRECT_FB__PACKET_DECODER_NONE
 /*17*/ DIRECT_FB__PACKET_DECODER_NONE
 /*18*/ DIRECT_FB__PACKET_DECODER_NONE
 /*19*/ DIRECT_FB__PACKET_DECODER_NONE
 /*20*/ DIRECT_FB__PACKET_DECODER_NONE
 /*21*/ DIRECT_FB__PACKET_DECODER_NONE
 /*22*/ DIRECT_FB__PACKET_DECODER_NONE
 /*23*/ DIRECT_FB__PACKET_DECODER_NONE
 /*24*/ DIRECT_FB__PACKET_DECODER_NONE
 /*25*/ DIRECT_FB__PACKET_DECODER_NONE
 /*26*/ DIRECT_FB__PACKET_DECODER_NONE
 /*27*/ DIRECT_FB__PACKET_DECODER_NONE
 /*28*/ DIRECT_FB__PACKET_DECODER_NONE
 /*29*/ DIRECT_FB__PACKET_DECODER_NONE
 /*30*/ DIRECT_FB__PACKET_DECODER_NONE
 /*31*/ DIRECT_FB__PACKET_DECODER_NONE
 /*32*/ DIRECT_FB__PACKET_DECODER_NONE
 /*33*/ DIRECT_FB__PACKET_DECODER_NONE
 /*34*/ DIRECT_FB__PACKET_DECODER_NONE
 /*35*/ DIRECT_FB__PACKET_DECODER_NONE
 /*36*/ DIRECT_FB__PACKET_DECODER_NONE
 /*37*/ DIRECT_FB__PACKET_DECODER_NONE
 /*38*/ DIRECT_FB__PACKET_DECODER_NONE
 /*39*/ DIRECT_FB__PACKET_DECODER_NONE
 /*40*/ DIRECT_FB__PACKET_DECODER_NONE
 /*41*/ DIRECT_FB__PACKET_DECODER_NONE
 /*42*/ DIRECT_FB__PACKET_DECODER_NONE
 /*43*/ DIRECT_FB__PACKET_DECODER_NONE
 /*44*/ DIRECT_FB__PACKET_DECODER_NONE
 /*45*/ DIRECT_FB__PACKET_DECODER_NONE
 /*46*/ DIRECT_FB__PACKET_DECODER_NONE
 /*47*/ DIRECT_FB__PACKET_DECODER_NONE
 /*48*/ DIRECT_FB__PACKET_DECODER_NONE
 /*49*/ DIRECT_FB__PACKET_DECODER_NONE
 /*50*/ DIRECT_FB__PACKET_DECODER_NONE
 /*51*/ DIRECT_FB__PACKET_DECODER_NONE
 /*52*/ DIRECT_FB__PACKET_DECODER_NONE
 /*53*/ DIRECT_FB__PACKET_DECODER_NONE
 /*54*/ DIRECT_FB__PACKET_DECODER_NONE
 /*55*/ DIRECT_FB__PACKET_DECODER_NONE
 /*56*/ DIRECT_FB__PACKET_DECODER_NONE
 /*57*/ DIRECT_FB__PACKET_DECODER_NONE
 /*58*/ DIRECT_FB__PACKET_DECODER_NONE
 /*59*/ DIRECT_FB__PACKET_DECODER_NONE
 /*60*/ DIRECT_FB__PACKET_DECODER_NONE
 /*61*/ DIRECT_FB__PACKET_DECODER_NONE
 /*62*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_allocate_statement
 /*63*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_execute
 /*64*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_exec_immediate
 /*65*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_fetch
 /*66*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_fetch_response
 /*67*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_free_statement
 /*68*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_prepare_statement
 /*69*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_set_cursor
 /*70*/ DIRECT_FB__PACKET_DECODER_NONE                 //op_info_sql
 /*71*/ DIRECT_FB__PACKET_DECODER_DESCR_STD_C(op_dummy)
};//sm_decoders

STARTUP_CODE_EX__DEBUG(check_decoders,
                       RemoteFB__PSET01__P_INIT__PacketStream::Debug__CheckDecoders);

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P_INIT__PacketStream

RemoteFB__PSET01__P_INIT__PacketStream RemoteFB__PSET01__P_INIT__PacketStream::Instance;

//------------------------------------------------------------------------
RemoteFB__PSET01__P_INIT__PacketStream::RemoteFB__PSET01__P_INIT__PacketStream()
{;}

//stream interface -------------------------------------------------------
void RemoteFB__PSET01__P_INIT__PacketStream::SendPacket
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            const protocol::PACKET&         packet)const
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET01__P_INIT__PacketStream::SendPacket";

 if(packet.protocolSetID!=protocol::PROTOCOL_SET_ID__01)
 {
  //ERROR - [BUG CHECK] Incorrect packet structure!

  RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedPacketStructure
   (c_bugcheck_src,
    L"#001",
    packet.protocolSetID,
    protocol::PROTOCOL_SET_ID__01);
 }//if

 return RemoteFB__PSET01__SendPacket
         (op_ctx,
          static_cast<const protocol::set01::PACKET_V01&>(packet),
          _DIM_(tag_data::sm_encoders),
          tag_data::sm_encoders);
}//SendPacket

//------------------------------------------------------------------------
void RemoteFB__PSET01__P_INIT__PacketStream::ReceivePacket
                                           (RemoteFB__PortOperationContext& op_ctx,
                                            protocol::PACKET&               packet)const
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PSET01__P_INIT__PacketStream::ReceivePacket";

 if(packet.protocolSetID!=protocol::PROTOCOL_SET_ID__01)
 {
  //ERROR - [BUG CHECK] Incorrect packet structure!

  RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedPacketStructure
   (c_bugcheck_src,
    L"#001",
    packet.protocolSetID,
    protocol::PROTOCOL_SET_ID__01);
 }//if

 return RemoteFB__PSET01__ReceivePacket
         (op_ctx,
          static_cast<protocol::set01::PACKET_V01&>(packet),
          _DIM_(tag_data::sm_decoders),
          tag_data::sm_decoders);
}//ReceivePacket

//debug methods ----------------------------------------------------------
#ifndef NDEBUG

void RemoteFB__PSET01__P_INIT__PacketStream::Debug__CheckEncoders()
{
 RemoteFB__PSET01__PacketEncoderDescr::Debug__CheckArray
   (_DIM_(tag_data::sm_encoders),
    tag_data::sm_encoders);
}//Debug__CheckEncoders

#endif

//------------------------------------------------------------------------
#ifndef NDEBUG

void RemoteFB__PSET01__P_INIT__PacketStream::Debug__CheckDecoders()
{
 RemoteFB__PSET01__PacketDecoderDescr::Debug__CheckArray
   (_DIM_(tag_data::sm_decoders),
    tag_data::sm_decoders);
}//Debug__CheckDecoders

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms p_init*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
