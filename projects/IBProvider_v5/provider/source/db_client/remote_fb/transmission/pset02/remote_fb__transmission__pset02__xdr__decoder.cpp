////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__xdr__decoder.cpp
//! \brief   Утилиты для распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__xdr__decoder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__XDR__Decoder

void RemoteFB__PSET02__XDR__Decoder::decode__p_op
                              (buf_type*              const pBuf,
                               const wchar_t*         const /*pv_sign*/,
                               protocol::set02::P_OP* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 //проверяем идентичность типов
 assert_s(sizeof(protocol::set02::P_OP)==sizeof(protocol::P_LONG));

 protocol::P_LONG tmp DEBUG_CODE(=lib::structure::negative_one);

 pBuf->read__long(&tmp); //throw

 (*pv)=(protocol::set02::P_OP)tmp;
}//decode__p_op

//------------------------------------------------------------------------
void RemoteFB__PSET02__XDR__Decoder::decode__p_ulong_length_as_p_long__pset02
                              (buf_type*          const pBuf,
                               const wchar_t*     const pv_sign,
                               protocol::P_ULONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv_sign!=nullptr);
 assert(pv!=nullptr);

 return self_type::decode__p_ulong_as_p_long
          (pBuf,
           pv_sign,
           pv);
}//decode__p_ulong_length_as_p_long__pset02

//------------------------------------------------------------------------
void RemoteFB__PSET02__XDR__Decoder::decode__p_cstring_const
                              (buf_type*                            const pBuf,
                               mem_type*                            const pMem,
                               mem_id_type                          const memID,
                               const wchar_t*                       const pv_sign1__cstr_length,
                               const wchar_t*                       const pv_sign2__cstr_addr,
                               protocol::set02::P_CSTRING_CONST_V2* const pv)
{
 assert(pBuf!=nullptr);
 assert(pMem!=nullptr);
 assert(pv_sign1__cstr_length!=nullptr);
 assert(pv_sign2__cstr_addr!=nullptr);
 assert(pv!=nullptr);

 //-----------------------------------------
 protocol::P_ULONG cstr_length;

 self_type::decode__p_ulong_length_as_p_long__pset02
  (pBuf,
   pv_sign1__cstr_length,
   &cstr_length);

 protocol::P_UCHAR* const cstr_address
  =RemoteFB__AllocPacketMemory<protocol::P_UCHAR>
    (pMem,
     memID,
     cstr_length);

 self_type::decode__opaque
  (pBuf,
   pv_sign2__cstr_addr,
   cstr_length,
   cstr_address);

 //-----------------------------------------
 pv->cstr_length  =cstr_length;
 pv->cstr_address =cstr_address;
}//decode__p_cstring_const - P_CSTRING_CONST_V2

////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
