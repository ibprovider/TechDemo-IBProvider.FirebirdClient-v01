////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission
//! \file    remote_fb__transmission__xdr__info.cpp
//! \brief   Информационные утилиты для работы с данными сетевого пакета.
//! \author  Kovalenko Dmitry
//! \date    05.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__info.h"
#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__XDR__Info

size_t RemoteFB__XDR__Info::get_size__p_op()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_op

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_arch()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_arch

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_objct()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_objct

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_short()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_short

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_long()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_long

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_int64()
{
 return sizeof(protocol::P_LONG)+sizeof(protocol::P_LONG);
}//get_size__p_int64

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_ushort()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_ushort

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_ushort_as_p_short()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_ushort_as_p_short

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_ulong_as_p_long()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_ulong_as_p_long

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_float()
{
 return sizeof(protocol::P_LONG);
}//get_size__p_float

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_double()
{
 return sizeof(protocol::P_LONG)+sizeof(protocol::P_LONG);
}//get_size__p_double

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_bid()
{
 return get_size__p_ulong_as_p_long()+get_size__p_ulong_as_p_long();
}//get_size__p_bid

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__opaque(size_t length)
{
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__XDR__Info::get_size__opaque";

 if(size_t l=(length%protocol::FB_PACKET_FIELD_ALIGN))
 {
  assert(l>0);
  assert(l<protocol::FB_PACKET_FIELD_ALIGN);

  l=(protocol::FB_PACKET_FIELD_ALIGN-l);

  if((structure::t_numeric_limits<size_t>::max_value()-length)<l)
   IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

  length+=l;
 }//if

 return length;
}//get_size__opaque

////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
