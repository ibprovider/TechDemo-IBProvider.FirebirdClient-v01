////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02__p13
//! \file    remote_fb__transmission__pset02__p13__xdr__decoder.h
//! \brief   Утилиты для распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    20.09.2016
#ifndef _remote_fb__transmission__pset02__p13__xdr__decoder_H_
#define _remote_fb__transmission__pset02__p13__xdr__decoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission__pset02__p13
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__P13__XDR__Decoder

/// <summary>
///  Утилиты для распаковки данных сетевого пакета.
/// </summary>
class RemoteFB__PSET02__P13__XDR__Decoder LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__PSET02__P13__XDR__Decoder;

 public: //typedefs ------------------------------------------------------
  using buf_type=RemoteFB__PortReader;

  using mded_type=RemoteFB__MsgDataElementDescr;

 public:
  /// <summary>
  ///  Распаковка MSG-буфера с данными из "сетевого" формата.
  /// </summary>
  //! \param[in]  pBuf
  //!  Not null.
  //! \param[in]  msg_descrs_count
  //! \param[in]  msg_descrs
  //! \param[in]  msg_data_size
  //! \param[out] msg_data
  //! \param[in]  msg_nulls_size
  //! \param[out] msg_nulls
  //!
  //! \attention
  //!  Предполагается, что msg_blr содержит корректные данные и согласован с размером msg_data.
  //!  В отладочной сборке осуществляется контроль размера и содержимого.
  static void decode__sql_message
               (buf_type*               pBuf,
                size_t                  msg_descrs_count,
                const mded_type*        msg_descrs,
                size_t                  msg_data_size,
                protocol::P_UCHAR*      msg_data,
                size_t                  msg_nulls_size,
                protocol::P_UCHAR*      msg_nulls);
};//class RemoteFB__PSET02__P13__XDR__Decoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
