////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13_init
//! \file    remote_fb__transmission__pset02__p13_init__packet_stream.h
//! \brief   ����� ������� ����� ������������� �����������.
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__p13_init__packet_stream_H_
#define _remote_fb__transmission__pset02__p13_init__packet_stream_H_

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__packet_stream.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13_init{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13_INIT__PacketStream

class RemoteFB__PSET02__P13_INIT__PacketStream LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__PacketStream
{
 private:
  using self_type=RemoteFB__PSET02__P13_INIT__PacketStream;

  RemoteFB__PSET02__P13_INIT__PacketStream(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  /// <summary>
  ///  ����������� ��-���������.
  /// </summary>
  RemoteFB__PSET02__P13_INIT__PacketStream();

 public:
  /// <summary>
  ///  ������������ ��������� �������.
  /// </summary>
  static self_type Instance;

 public:
  /// <summary>
  ///  �������� � �������� ������
  /// </summary>
  //! \param[in] op_ctx
  //! \param[in] packet
  virtual void SendPacket(RemoteFB__PortOperationContext& op_ctx,
                          const protocol::PACKET&         packet)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ��������� � ���������� ������
  /// </summary>
  //! \param[in]  op_ctx
  //! \param[out] packet
  virtual void ReceivePacket(RemoteFB__PortOperationContext& op_ctx,
                             protocol::PACKET&               packet)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;
 public:
#ifndef NDEBUG
  static void Debug__CheckEncoders();
  static void Debug__CheckDecoders();
#endif

 private:
  struct tag_data;
};//class RemoteFB__PSET02__P13_INIT__PacketStream

////////////////////////////////////////////////////////////////////////////////
}/*nms p13_init*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
