////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset02
//! \file    remote_fb__transmission__pset02__xdr__encoder.cpp
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    10.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset02/remote_fb__transmission__pset02__xdr__encoder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset02{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET02__XDR__Encoder

void RemoteFB__PSET02__XDR__Encoder::encode__p_op
                              (buf_type*                    const pBuf,
                               const protocol::set02::P_OP* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_op

//------------------------------------------------------------------------
void RemoteFB__PSET02__XDR__Encoder::encode__p_ulong_length_as_p_long__pset02
                              (buf_type*                const pBuf,
                               const protocol::P_ULONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 // [2023-04-09] Remove it when time come
 assert((*pv)<=protocol::set02::C_CSTRING_V2_MAX_LENGTH_P13);

 return self_type::encode__p_ulong_as_p_long
         (pBuf,
          pv);
}//encode__p_ulong_length_as_p_long__pset02

//------------------------------------------------------------------------
void RemoteFB__PSET02__XDR__Encoder::encode__p_cstring_const
                              (buf_type*                                  const pBuf,
                               const protocol::set02::P_CSTRING_CONST_V1* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 CHECK_READ_TYPED_PTR(pv->cstr_address,pv->cstr_length);

 //
 // [] Здесь нужно обеспечить совместимость с PSET01 и PSET02
 //
 // [2023-04-08] It is not needed.
 //

 self_type::encode__p_ushort_as_p_long
  (pBuf,
   &pv->cstr_length);

 self_type::encode__opaque
  (pBuf,
   pv->cstr_length,
   pv->cstr_address);
}//encode__p_cstring_const - P_CSTRING_CONST_V1

//------------------------------------------------------------------------
void RemoteFB__PSET02__XDR__Encoder::encode__p_cstring_const
                              (buf_type*                                  const pBuf,
                               const protocol::set02::P_CSTRING_CONST_V2* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 CHECK_READ_TYPED_PTR(pv->cstr_address,pv->cstr_length);

 self_type::encode__p_ulong_length_as_p_long__pset02
  (pBuf,
   &pv->cstr_length);

 self_type::encode__opaque
  (pBuf,
   pv->cstr_length,
   pv->cstr_address);
}//encode__p_cstring_const - P_CSTRING_CONST_V2

//------------------------------------------------------------------------
void RemoteFB__PSET02__XDR__Encoder::encode__p_longs
                                           (buf_type*                                  const pBuf,
                                            const protocol::set02::P_CSTRING_CONST_V2* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 CHECK_READ_TYPED_PTR(pv->cstr_address,pv->cstr_length);

 using item_type=protocol::P_LONG;

 //проверка размера
 assert(pv->cstr_length%sizeof(item_type)==0);

 //проверка выравнивания
 assert((size_t(pv->cstr_address)%sizeof(item_type))==0);

 const size_t n=(pv->cstr_length/sizeof(item_type));

 assert(((n*sizeof(item_type))%protocol::FB_PACKET_FIELD_ALIGN)==0);

 self_type::encode__p_ulong_length_as_p_long__pset02
  (pBuf,
   &pv->cstr_length);

 const item_type*        pItem=reinterpret_cast<const item_type*>(pv->cstr_address);
 const item_type* const _eItem=pItem+n;

 for(;pItem!=_eItem;++pItem)
 {
  self_type::encode__p_long(pBuf,pItem);
 }//for pItem
}//encode__p_longs

////////////////////////////////////////////////////////////////////////////////
}/*nms pset02*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
