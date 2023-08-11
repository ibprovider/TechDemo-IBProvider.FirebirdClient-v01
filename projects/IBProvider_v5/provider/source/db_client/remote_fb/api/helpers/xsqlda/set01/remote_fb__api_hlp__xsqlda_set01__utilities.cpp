////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__api_hlp__xsqlda_set01__utilities.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_obj/isc_base/helpers/xsqlda/set01/isc_api_hlp__xsqlda_set01__xvar_info_ids.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_SET01__Utilities - static data

const RemoteFB__API_HLP__XSQLDA_SET01__Utilities::byte_type
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__describe[12]=
{
 isc_api::ibp_isc_info_sql_select,                 //0
 IBP_ISC_API_HLP__XSQLDA_SET01__XVAR_INFO_IDS__C11 //1-11
};//sm_sql_info__describe

//------------------------------------------------------------------------
const RemoteFB__API_HLP__XSQLDA_SET01__Utilities::byte_type
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__describe_bind[12]=
{
 isc_api::ibp_isc_info_sql_bind,                   //0
 IBP_ISC_API_HLP__XSQLDA_SET01__XVAR_INFO_IDS__C11 //1-11
};//sm_sql_info__describe_bind

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
