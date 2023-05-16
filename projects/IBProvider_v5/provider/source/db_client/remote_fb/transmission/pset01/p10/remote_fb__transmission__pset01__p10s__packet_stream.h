////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p10
//! \file    remote_fb__transmission__pset01__p10s__packet_stream.h
//! \brief   ����� ������� ������������� ��������� v10.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#ifndef _remote_fb__transmission__pset01__p10s__packet_stream_H_
#define _remote_fb__transmission__pset01__p10s__packet_stream_H_

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__packet_stream.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01__p10
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P10S__PacketStream

/// <summary>
///  ����� ������� ������������� ��������� v10.
/// <summary>
class RemoteFB__PSET01__P10S__PacketStream:public RemoteFB__PacketStream
{
 private:
  typedef RemoteFB__PSET01__P10S__PacketStream    self_type;

  RemoteFB__PSET01__P10S__PacketStream(const self_type&);
  self_type& operator = (const self_type&);

  /// <summary>
  ///  ����������� ��-���������.
  /// </summary>
  RemoteFB__PSET01__P10S__PacketStream();

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
};//class RemoteFB__PSET01__P10S__PacketStream

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
