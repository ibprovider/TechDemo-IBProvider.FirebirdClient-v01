////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__transmission__pset01
//! \file    remote_fb__transmission__pset01__op__info.cpp
//! \brief   Информационные утилиты для работы с сетевыми пакетами.
//! \author  Kovalenko Dmitry
//! \date    05.09.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/transmission/pset01/remote_fb__transmission__pset01__op__info.h"
#include "source/db_client/remote_fb/transmission/remote_fb__transmission__xdr__info.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace transmission{namespace pset01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PSET01__OpInfo

size_t RemoteFB__PSET01__OpInfo::get_size__op_fetch_response(size_t szMsg)
{
 using xdr=RemoteFB__XDR__Info;

 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__PSET01__OpInfo::get_size__op_fetch_response";

 //-----------------------------------------
 size_t result=xdr::get_size__p_op();

 //protocol::P_OP_SQLDATA::p_sqldata_status
 result+=xdr::get_size__p_ulong_as_p_long();

 //protocol::P_OP_SQLDATA::p_sqldata_messages
 result+=xdr::get_size__p_ushort_as_p_short();

 //-----
 szMsg=xdr::get_size__opaque(szMsg);

 if((structure::t_numeric_limits<size_t>::max_value()-result)<szMsg)
  IBP_ThrowOverflowInMemSizeCalculation(c_bugcheck_src,L"#001");

 result+=szMsg;

 //-----
 return result;
}//get_size__op_fetch_response

////////////////////////////////////////////////////////////////////////////////
}/*nms pset01*/}/*nms transmission*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
