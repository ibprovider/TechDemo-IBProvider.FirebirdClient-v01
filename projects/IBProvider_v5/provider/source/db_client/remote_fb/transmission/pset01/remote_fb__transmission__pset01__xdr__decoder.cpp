////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__xdr__decoder.cpp
//! \brief   Утилиты для распаковки данных сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    02.05.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__decoder.h"
#include "source/db_obj/dbms_fb/common/api/errors/set02/db_obj__dbms_fb__common__api__errors__set02__scodes.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__XDR__Decoder

void RemoteFB__PSET01__XDR__Decoder::decode__p_op
                              (buf_type*              const pBuf,
                               const wchar_t*         const /*pv_sign*/,
                               protocol::set01::P_OP* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 //проверяем идентичность типов
 assert_s(sizeof(protocol::set01::P_OP)==sizeof(protocol::P_LONG));

 protocol::P_LONG tmp DEBUG_CODE(=structure::negative_one);

 pBuf->read__long(&tmp); //throw

 (*pv)=(protocol::set01::P_OP)tmp;
}//decode__p_op

//------------------------------------------------------------------------
void RemoteFB__PSET01__XDR__Decoder::decode__p_cstring_const
                              (buf_type*                         const pBuf,
                               mem_type*                         const pMem,
                               mem_id_type                       const memID,
                               const wchar_t*                    const pv_sign1__cstr_length,
                               const wchar_t*                    const pv_sign2__cstr_addr,
                               protocol::set01::P_CSTRING_CONST* const pv)
{
 assert(pBuf!=nullptr);
 assert(pMem!=nullptr);
 assert(pv_sign1__cstr_length!=nullptr);
 assert(pv_sign2__cstr_addr!=nullptr);
 assert(pv!=nullptr);

 //-----------------------------------------
 protocol::P_USHORT cstr_length;

 self_type::decode__p_ushort_as_p_short
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
}//decode__p_cstring_const

////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
