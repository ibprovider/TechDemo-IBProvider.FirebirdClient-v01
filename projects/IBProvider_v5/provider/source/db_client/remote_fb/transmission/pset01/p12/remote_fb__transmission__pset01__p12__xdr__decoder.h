////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__xdr__decoder.h
//! \brief   ������� ��� ���������� ������ �������� ������.
//! \author  Kovalenko Dmitry
//! \date    27.05.2015.
#ifndef _remote_fb__transmission__pset01__p12__xdr__decoder_H_
#define _remote_fb__transmission__pset01__p12__xdr__decoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset01__p12
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__P12__XDR__Decoder

/// <summary>
///  ������� ��� ���������� ������ �������� ������.
/// </summary>
class RemoteFB__PSET01__P12__XDR__Decoder LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__PSET01__P12__XDR__Decoder;

 public: //typedefs ------------------------------------------------------
  using buf_type=RemoteFB__PortReader;

 public:
  /// <summary>
  ///  ���������� MSG-������ � ������� �� "��������" �������.
  /// </summary>
  //! \param[in]  pBuf
  //!  Not null.
  //! \param[in]  msg_blr_size
  //! \param[in]  msg_blr
  //! \param[in]  msg_data_size
  //! \param[out] msg_data
  //!
  //! \attention
  //!  ��������������, ��� msg_blr �������� ���������� ������ � ���������� � �������� msg_data.
  //!  � ���������� ������ �������������� �������� ������� � �����������.
  static void decode__sql_message
               (buf_type*                pBuf,
                size_t                   msg_blr_size,
                const protocol::P_UCHAR* msg_blr,
                size_t                   msg_data_size,
                protocol::P_UCHAR*       msg_data);
};//class RemoteFB__PSET01__P12__XDR__Decoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
