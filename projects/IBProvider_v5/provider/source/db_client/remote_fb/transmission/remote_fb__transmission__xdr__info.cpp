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

size_t RemoteFB__XDR__Info::get_size__p_hyper_long()
{
 return sizeof(protocol::P_HYPER_LONG);
}//get_size__p_hyper_long

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_hyper_longlong()
{
 assert_s(sizeof(protocol::P_HYPER_LONGLONG)==2*sizeof(protocol::P_HYPER_LONG));

 return 2*self_type::get_size__p_hyper_long();
}//get_size__p_hyper_longlong

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_op()
{
 return self_type::get_size__p_long();
}//get_size__p_op

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_arch()
{
 return self_type::get_size__p_long();
}//get_size__p_arch

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_objct()
{
 return self_type::get_size__p_long();
}//get_size__p_objct

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_short()
{
 return self_type::get_size__p_long();
}//get_size__p_short

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_long()
{
 assert_s(sizeof(protocol::P_LONG)==sizeof(protocol::P_HYPER_LONG));

 return self_type::get_size__p_hyper_long();
}//get_size__p_long

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_int64()
{
 assert_s(sizeof(protocol::P_INT64)==sizeof(protocol::P_HYPER_LONGLONG));

 return self_type::get_size__p_hyper_longlong();
}//get_size__p_int64

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_ushort()
{
 return self_type::get_size__p_long();
}//get_size__p_ushort

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_ushort_as_p_short()
{
 return self_type::get_size__p_long();
}//get_size__p_ushort_as_p_short

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_ulong_as_p_long()
{
 return self_type::get_size__p_long();
}//get_size__p_ulong_as_p_long

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_float()
{
 assert_s(sizeof(protocol::P_FLOAT)==sizeof(protocol::P_LONG));

 return self_type::get_size__p_long();
}//get_size__p_float

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_double()
{
 assert_s(sizeof(protocol::P_DOUBLE)==2*sizeof(protocol::P_LONG));

 return 2*self_type::get_size__p_long();
}//get_size__p_double

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_bid()
{
 return self_type::get_size__p_ulong_as_p_long()+self_type::get_size__p_ulong_as_p_long();
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

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_uint64()
{
 assert_s(sizeof(protocol::P_UINT64)==sizeof(protocol::P_HYPER_LONGLONG));

 return self_type::get_size__p_hyper_longlong();
}//get_size__p_uint64

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_int128()
{
 assert_s(sizeof(protocol::P_INT128)==2*sizeof(protocol::P_UINT64));

 return 2*self_type::get_size__p_uint64();
}//get_size__p_int64

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_decfloat16()
{
 assert_s(sizeof(protocol::P_DECFLOAT16)==sizeof(protocol::P_UINT64));

 return self_type::get_size__p_uint64();
}//get_size__p_decfloat16

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__p_decfloat34()
{
 assert_s(sizeof(protocol::P_DECFLOAT34)==2*sizeof(protocol::P_UINT64));

 return 2*self_type::get_size__p_uint64();
}//get_size__p_decfloat34

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__isc_time()
{
 return self_type::get_size__p_ulong_as_p_long();
}//get_size__isc_time

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__isc_date()
{
 return self_type::get_size__p_long();
}//get_size__isc_date

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__isc_timestamp()
{
 // case dtype_timestamp:
 //     fb_assert(desc->dsc_length >= 2 * sizeof(SLONG));
 //     if (!xdr_long(xdrs, &((SLONG*) p)[0]))
 //         return FALSE;
 //     if (!xdr_long(xdrs, &((SLONG*) p)[1]))
 //         return FALSE;
 //     break;

 return self_type::get_size__isc_date()+self_type::get_size__isc_time();
}//get_size__isc_timestamp

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__fb040_timezone()
{
 return self_type::get_size__p_ushort_as_p_short();
}//get_size__fb040_timezone

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__fb040_timestamp_with_tz()
{
 // case dtype_timestamp_tz:
 //     fb_assert(desc->dsc_length >= 2 * sizeof(SLONG) + 1);
 //     if (!xdr_long(xdrs, &((SLONG*) p)[0]))
 //         return FALSE;
 //     if (!xdr_long(xdrs, &((SLONG*) p)[1]))
 //         return FALSE;
 //     if (!xdr_short(xdrs, reinterpret_cast<SSHORT*>(p + 2 * sizeof(SLONG))))
 //         return FALSE;
 //     break;

 return self_type::get_size__isc_timestamp()+self_type::get_size__fb040_timezone();
}//get_size__fb040_timestamp_with_tz

//------------------------------------------------------------------------
size_t RemoteFB__XDR__Info::get_size__fb040_time_with_tz()
{
 // case dtype_sql_time_tz:
 //     fb_assert(desc->dsc_length >= sizeof(SLONG) + sizeof(SSHORT));
 //     if (!xdr_long(xdrs, reinterpret_cast<SLONG*>(p)))
 //         return FALSE;
 //     if (!xdr_short(xdrs, reinterpret_cast<SSHORT*>(p + sizeof(SLONG))))
 //         return FALSE;
 //     break;

 return self_type::get_size__isc_time()+self_type::get_size__fb040_timezone();
}//get_size__fb040_time_with_tz

////////////////////////////////////////////////////////////////////////////////
}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
