////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__xdr__decoder.h
//! \brief   ������� ��� ���������� ������ �������� ������.
//! \author  Kovalenko Dmitry
//! \date    02.05.2016
#ifndef _remote_fb__transmission__pset01__xdr__decoder_H_
#define _remote_fb__transmission__pset01__xdr__decoder_H_

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__decoder.h"
#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__transmission
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__XDR__Decoder

/// <summary>
///  ��������� ������������� �������� ������
/// </summary>
class RemoteFB__PSET01__XDR__Decoder LCPI_CPP_CFG__CLASS__FINAL
 :public RemoteFB__XDR__Decoder
{
 private:
  using self_type=RemoteFB__PSET01__XDR__Decoder;

 public: //typedefs ------------------------------------------------------
  using buf_type=RemoteFB__PortReader;

  using mem_type=RemoteFB__PacketMemory;

  using mem_id_type=mem_type::enumMemoryID;

 public:
  static void decode__p_op
               (buf_type*              pBuf,
                const wchar_t*         pv_sign,
                protocol::set01::P_OP* pv);

  // It is a special variant for decoding an USHORT-value with length.
  static void decode__p_ushort_length_as_p_short__pset01
               (buf_type*           pBuf,
                const wchar_t*      pv_sign,
                protocol::P_USHORT* pv);

  static void decode__p_cstring_const
               (buf_type*                         pBuf,
                mem_type*                         pMem,
                mem_id_type                       memID,
                const wchar_t*                    pv_sign1__cstr_length,
                const wchar_t*                    pv_sign2__cstr_addr,
                protocol::set01::P_CSTRING_CONST* pv);
};//class RemoteFB__PSET01__XDR__Decoder

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
