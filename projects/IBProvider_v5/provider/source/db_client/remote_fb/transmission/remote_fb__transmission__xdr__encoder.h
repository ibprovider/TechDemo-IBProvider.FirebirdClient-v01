////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__encoder.h
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#ifndef _remote_fb__transmission__xdr__encoder_H_
#define _remote_fb__transmission__xdr__encoder_H_

#include "source/db_client/remote_fb/ports/remote_fb__port.h"
#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Encoder

/// <summary>
///  Первичный трансформатор записываемых данных
/// </summary>
class RemoteFB__XDR__Encoder
{
 private:
  typedef RemoteFB__XDR__Encoder            self_type;

 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__PortWriter              buf_type;

 public:
  static void encode__p_arch
               (buf_type*                    pBuf,
                const protocol::P_ARCH*      pv);

  static void encode__p_objct
               (buf_type*                    pBuf,
                const protocol::P_OBJCT*     pv);

  static void encode__p_short
               (buf_type*                    pBuf,
                const protocol::P_SHORT*     pv);

  static void encode__p_long
               (buf_type*                    pBuf,
                const protocol::P_LONG*      pv);

  static void encode__p_int64
               (buf_type*                    pBuf,
                const protocol::P_INT64*     pv);

  static void encode__p_ushort
               (buf_type*                    pBuf,
                const protocol::P_USHORT*    pv);

  static void encode__p_ushort_as_p_short
               (buf_type*                    pBuf,
                const protocol::P_USHORT*    pv);

  static void encode__p_ushort_as_p_long
               (buf_type*                    pBuf,
                const protocol::P_USHORT*    pv);

  static void encode__p_ulong_as_p_long
               (buf_type*                    pBuf,
                const protocol::P_ULONG*     pv);

  static void encode__p_float
               (buf_type*                    pBuf,
                const protocol::P_FLOAT*     pv);

  static void encode__p_double
               (buf_type*                    pBuf,
                const protocol::P_DOUBLE*    pv);

  static void encode__p_bid
               (buf_type*                    pBuf,
                const protocol::P_BID*       pv);

  static void encode__opaque
               (buf_type*                    pBuf,
                size_t                       sz,
                const protocol::P_UCHAR*     pv);

 private:
  static void helper__write_align_cch
               (buf_type* pBuf,
                size_t    cch);

 private:
  static const protocol::P_UCHAR sm_bytes_filler4[protocol::FB_PACKET_FIELD_ALIGN];
};//class RemoteFB__XDR__Encoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
