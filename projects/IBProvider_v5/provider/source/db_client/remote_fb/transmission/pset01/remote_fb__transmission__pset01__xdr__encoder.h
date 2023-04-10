////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__xdr__encoder.h
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    02.05.2016
#ifndef _remote_fb__transmission__pset01__xdr__encoder_H_
#define _remote_fb__transmission__pset01__xdr__encoder_H_

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__XDR__Encoder

/// <summary>
///  Первичный трансформатор записываемых данных
/// </summary>
class RemoteFB__PSET01__XDR__Encoder:public RemoteFB__XDR__Encoder
{
 private:
  typedef RemoteFB__PSET01__XDR__Encoder    self_type;

 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__PortWriter              buf_type;

 public:
  static void encode__p_op
               (buf_type*                    pBuf,
                const protocol::set01::P_OP* pv);

  // It is a special variant for encoding an USHORT-value with length.
  static void encode__p_ushort_length_as_p_short__pset01
               (buf_type*                    pBuf,
                const protocol::P_USHORT*    pv);

  static void encode__p_cstring_const
               (buf_type*                               pBuf,
                const protocol::set01::P_CSTRING_CONST* pv);

  static void encode__p_longs
               (buf_type*                               pBuf,
                const protocol::set01::P_CSTRING_CONST* pv);
};//class RemoteFB__PSET01__XDR__Encoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
