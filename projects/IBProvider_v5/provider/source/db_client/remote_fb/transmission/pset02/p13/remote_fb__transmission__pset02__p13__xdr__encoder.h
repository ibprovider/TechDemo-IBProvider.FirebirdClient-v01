////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__xdr__encoder.h
//! \brief   ������� ��� �������� ������ � ������� �����.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__transmission__pset02__p13__xdr__encoder_H_
#define _remote_fb__transmission__pset02__p13__xdr__encoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02__p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__XDR__Encoder

/// <summary>
///  ������� ��� �������� ������ � ������� �����.
/// </summary>
class RemoteFB__PSET02__P13__XDR__Encoder LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__PSET02__P13__XDR__Encoder;

 public: //typedefs ------------------------------------------------------
  using buf_type=RemoteFB__PortWriter;

  using mded_type=RemoteFB__MsgDataElementDescr;

 public:
  /// <summary>
  ///  ����������� MSG-������ � ������� � "�������" ������.
  /// </summary>
  //! \param[in] pBuf
  //!  Not null.
  //! \param[in] msg_descrs_count
  //! \param[in] msg_descrs
  //! \param[in] msg_data_size
  //! \param[in] msg_data
  //! \param[in] msg_nulls_size
  //! \param[in] msg_nulls
  //!
  //!
  //! \attention
  //!  ��������������, ��� msg_blr � msg_data �������� ���������� ������.
  //!  � ���������� ������ �������������� �������� ������� � �����������.
  static void encode__sql_message
               (buf_type*                pBuf,
                size_t                   msg_descrs_count,
                const mded_type*         msg_descrs,
                size_t                   msg_data_size,
                const protocol::P_UCHAR* msg_data,
                size_t                   msg_nulls_size,
                const protocol::P_UCHAR* msg_nulls);
};//class RemoteFB__PSET02__P13__XDR__Encoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
