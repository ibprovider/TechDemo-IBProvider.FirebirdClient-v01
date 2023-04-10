////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__encoder.cpp
//! \brief   Утилиты для упаковки данных в сетевой пакет.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__encoder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Encoder

const protocol::P_UCHAR
 RemoteFB__XDR__Encoder::sm_bytes_filler4[protocol::FB_PACKET_FIELD_ALIGN]
  ={};

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_arch
                              (buf_type*               const pBuf,
                               const protocol::P_ARCH* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_arch

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_objct
                              (buf_type*                const pBuf,
                               const protocol::P_OBJCT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_SHORT)==sizeof(*pv));

 const protocol::P_LONG tmp=*reinterpret_cast<const protocol::P_SHORT*>(pv);

 pBuf->write__long(&tmp);
}//encode__p_objct

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_short
                              (buf_type*                const pBuf,
                               const protocol::P_SHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_long
                              (buf_type*               const pBuf,
                               const protocol::P_LONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 pBuf->write__long(pv);
}//encode__p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_int64
                              (buf_type*                const pBuf,
                               const protocol::P_INT64* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_INT64)==2*sizeof(protocol::P_LONG));

 const protocol::P_LONG h=static_cast<protocol::P_LONG>(((*pv)>>32)&0x00000000FFFFFFFF);

 pBuf->write__long(&h);

 const protocol::P_LONG l=static_cast<protocol::P_LONG>((*pv)&0x00000000FFFFFFFF);

 pBuf->write__long(&l);
}//encode__p_int64

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_ushort

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort_as_p_long
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 const protocol::P_LONG tmp=*pv;

 pBuf->write__long(&tmp);
}//encode__p_ushort_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ushort_as_p_short
                              (buf_type*                 const pBuf,
                               const protocol::P_USHORT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(*pv)==sizeof(protocol::P_SHORT));

 return self_type::encode__p_short
         (pBuf,
          reinterpret_cast<const protocol::P_SHORT*>(pv));
}//encode__p_ushort_as_p_short

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_ulong_as_p_long
                              (buf_type*                const pBuf,
                               const protocol::P_ULONG* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_LONG)==sizeof(*pv));

 pBuf->write__long(reinterpret_cast<const protocol::P_LONG*>(pv));
}//encode__p_ulong_as_p_long

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_float
                              (buf_type*                const pBuf,
                               const protocol::P_FLOAT* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_FLOAT)==sizeof(protocol::P_LONG));

 pBuf->write__long(reinterpret_cast<const protocol::P_LONG*>(pv));
}//encode__p_float

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_double
                              (buf_type*                 const pBuf,
                               const protocol::P_DOUBLE* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 assert_s(sizeof(protocol::P_DOUBLE)==sizeof(protocol::P_INT64));
 assert_s(sizeof(protocol::P_DOUBLE)==2*sizeof(protocol::P_LONG));

 const protocol::P_INT64 i64=*reinterpret_cast<const protocol::P_INT64*>(pv);

 const protocol::P_LONG h=static_cast<protocol::P_LONG>((i64>>32)&0x00000000FFFFFFFF);

 pBuf->write__long(&h);

 const protocol::P_LONG l=static_cast<protocol::P_LONG>(i64&0x00000000FFFFFFFF);

 pBuf->write__long(&l);
}//encode__p_double

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__p_bid(buf_type*              const pBuf,
                                           const protocol::P_BID* const pv)
{
 assert(pBuf!=nullptr);
 assert(pv!=nullptr);

 self_type::encode__p_ulong_as_p_long(pBuf,
                                      &pv->high);

 self_type::encode__p_ulong_as_p_long(pBuf,
                                      &pv->low);
}//encode__p_bid

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::encode__opaque(buf_type*                const pBuf,
                                            size_t                   const sz,
                                            const protocol::P_UCHAR* const pv)
{
 assert(pBuf!=nullptr);

 CHECK_READ_TYPED_PTR(pv,sz);

 pBuf->write__bytes(sz,pv);

 //-----------------------------------------
 self_type::helper__write_align_cch(pBuf,
                                    sz);
}//encode__opaque

//------------------------------------------------------------------------
void RemoteFB__XDR__Encoder::helper__write_align_cch(buf_type* const pBuf,
                                                     size_t    const cch)
{
 if(size_t l=(cch%protocol::FB_PACKET_FIELD_ALIGN))
 {
  assert(l>0);
  assert(l<protocol::FB_PACKET_FIELD_ALIGN);

  l=(protocol::FB_PACKET_FIELD_ALIGN-l);

  assert(l<=_DIM_(sm_bytes_filler4));

  pBuf->write__bytes(l,sm_bytes_filler4);
 }//if
}//helper__write_align_cch

////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
