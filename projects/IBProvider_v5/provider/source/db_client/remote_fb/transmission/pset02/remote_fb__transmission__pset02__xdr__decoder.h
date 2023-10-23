////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__xdr__decoder.h
//! \brief   Утилиты для распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#ifndef _remote_fb__transmission__pset02__xdr__decoder_H_
#define _remote_fb__transmission__pset02__xdr__decoder_H_

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__XDR__Decoder

/// <summary>
///  Финальный трансформатор читаемых данных
/// </summary>
class RemoteFB__PSET02__XDR__Decoder LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__XDR__Decoder
{
 private:
  using self_type=RemoteFB__PSET02__XDR__Decoder;

 public: //typedefs ------------------------------------------------------
  using buf_type=RemoteFB__PortReader;

  using mem_type=RemoteFB__PacketMemory;

  using mem_id_type=mem_type::enumMemoryID;

 public:
  static void decode__p_op
               (buf_type*              pBuf,
                const wchar_t*         pv_sign,
                protocol::set02::P_OP* pv);

  static void decode__p_ulong_length_as_p_long__pset02
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_ULONG*  pv);

  static void decode__p_cstring_const
               (buf_type*                            pBuf,
                mem_type*                            pMem,
                mem_id_type                          memID,
                const wchar_t*                       pv_sign1__cstr_length,
                const wchar_t*                       pv_sign2__cstr_addr,
                protocol::set02::P_CSTRING_CONST_V2* pv);
};//class RemoteFB__PSET02__XDR__Decoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
