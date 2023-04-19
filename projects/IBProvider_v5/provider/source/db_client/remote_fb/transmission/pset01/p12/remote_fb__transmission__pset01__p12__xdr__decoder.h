////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01__p12
//! \file    remote_fb__transmission__pset01__p12__xdr__decoder.h
//! \brief   Утилиты для распаковки данных сетевого пакета.
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
///  Утилиты для распаковки данных сетевого пакета.
/// </summary>
class RemoteFB__PSET01__P12__XDR__Decoder
{
 private:
  typedef RemoteFB__PSET01__P12__XDR__Decoder       self_type;

 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__PortReader                      buf_type;

 public:
  /// <summary>
  ///  Распаковка MSG-буфера с данными из "сетевого" формата.
  /// </summary>
  //! \param[in]  pBuf
  //!  Not null.
  //! \param[in]  msg_blr_size
  //! \param[in]  msg_blr
  //! \param[in]  msg_data_size
  //! \param[out] msg_data
  //!
  //! \attention
  //!  Предполагается, что msg_blr содержит корректные данные и согласован с размером msg_data.
  //!  В отладочной сборке осуществляется контроль размера и содержимого.
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
