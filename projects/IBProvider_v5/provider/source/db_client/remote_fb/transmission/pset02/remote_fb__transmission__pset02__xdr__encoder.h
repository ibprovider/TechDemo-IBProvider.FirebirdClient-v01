////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__xdr__encoder.h
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__xdr__encoder_H_
#define _remote_fb__transmission__pset02__xdr__encoder_H_

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__XDR__Encoder

/// <summary>
///  Первичный трансформатор записываемых данных
/// </summary>
class RemoteFB__PSET02__XDR__Encoder:public RemoteFB__XDR__Encoder
{
 private:
  typedef RemoteFB__PSET02__XDR__Encoder    self_type;

 public: //typedefs ------------------------------------------------------
  typedef RemoteFB__PortWriter              buf_type;

 public:
  static void encode__p_op
               (buf_type*                    pBuf,
                const protocol::set02::P_OP* pv);

  static void encode__p_ulong_length_as_p_long__pset02
               (buf_type*                    pBuf,
                const protocol::P_ULONG*     pv);

  static void encode__p_cstring_const
               (buf_type*                                  pBuf,
                const protocol::set02::P_CSTRING_CONST_V1* pv);

  static void encode__p_cstring_const
               (buf_type*                                  pBuf,
                const protocol::set02::P_CSTRING_CONST_V2* pv);

  static void encode__p_longs
               (buf_type*                                  pBuf,
                const protocol::set02::P_CSTRING_CONST_V2* pv);
};//class RemoteFB__PSET02__XDR__Encoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
