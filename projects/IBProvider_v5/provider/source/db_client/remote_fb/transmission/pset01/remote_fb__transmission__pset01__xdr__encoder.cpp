////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__xdr__encoder.cpp
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    02.05.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__xdr__encoder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__XDR__Encoder

void RemoteFB__PSET01__XDR__Encoder::encode__p_op
                              (buf_type*                    const pBuf,
                               const protocol::set01::P_OP* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_op

//------------------------------------------------------------------------
void RemoteFB__PSET01__XDR__Encoder::encode__p_ushort_length_as_p_short__pset01
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(*pv)==sizeof(protocol::P_SHORT));

 //
 // [2023-04-08]
 // 
 //  We will write USHORT that more than SHRT_MAX as a negative value.
 //

 return self_type::encode__p_short
         (pBuf,
          reinterpret_cast<const protocol::P_SHORT*>(pv));
}//encode__p_ushort_length_as_p_short__pset01

//------------------------------------------------------------------------
void RemoteFB__PSET01__XDR__Encoder::encode__p_cstring_const
                              (buf_type*                               const pBuf,
                               const protocol::set01::P_CSTRING_CONST* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 CHECK_READ_TYPED_PTR(pv->cstr_address,pv->cstr_length);

 self_type::encode__p_ushort_length_as_p_short__pset01
  (pBuf,
   &pv->cstr_length);

 self_type::encode__opaque
  (pBuf,
   pv->cstr_length,
   pv->cstr_address);
}//encode__p_cstring_const

//------------------------------------------------------------------------
void RemoteFB__PSET01__XDR__Encoder::encode__p_longs
                                           (buf_type*                               const pBuf,
                                            const protocol::set01::P_CSTRING_CONST* const pv)
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

 self_type::encode__p_ushort_length_as_p_short__pset01
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
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
