////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_hlp
//! \file    remote_fb__p12__xsqlda_utilities.cpp
//! \brief   Утилиты для обработки XSQLDA / XSQLVAR.
//! \author  Kovalenko Dmitry
//! \date    19.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_HLP__XSQLDA_SET01__Utilities - static data

const RemoteFB__API_HLP__XSQLDA_SET01__Utilities::byte_type
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__describe[12]=
{
 isc_api::ibp_isc_info_sql_select,          //0
 isc_api::ibp_isc_info_sql_describe_vars,   //1
 isc_api::ibp_isc_info_sql_sqlda_seq,       //2
 isc_api::ibp_isc_info_sql_type,            //3
 isc_api::ibp_isc_info_sql_sub_type,        //4
 isc_api::ibp_isc_info_sql_scale,           //5
 isc_api::ibp_isc_info_sql_length,          //6
 isc_api::ibp_isc_info_sql_field,           //7
 isc_api::ibp_isc_info_sql_relation,        //8
 isc_api::ibp_isc_info_sql_owner,           //9
 isc_api::ibp_isc_info_sql_alias,           //10
 isc_api::ibp_isc_info_sql_describe_end,    //11
};//sm_sql_info__describe

//------------------------------------------------------------------------
const RemoteFB__API_HLP__XSQLDA_SET01__Utilities::byte_type
 RemoteFB__API_HLP__XSQLDA_SET01__Utilities::sm_sql_info__describe_bind[12]=
{
 isc_api::ibp_isc_info_sql_bind,            //0
 isc_api::ibp_isc_info_sql_describe_vars,   //1
 isc_api::ibp_isc_info_sql_sqlda_seq,       //2
 isc_api::ibp_isc_info_sql_type,            //3
 isc_api::ibp_isc_info_sql_sub_type,        //4
 isc_api::ibp_isc_info_sql_scale,           //5
 isc_api::ibp_isc_info_sql_length,          //6
 isc_api::ibp_isc_info_sql_field,           //7
 isc_api::ibp_isc_info_sql_relation,        //8
 isc_api::ibp_isc_info_sql_owner,           //9
 isc_api::ibp_isc_info_sql_alias,           //10
 isc_api::ibp_isc_info_sql_describe_end,    //11
};//sm_sql_info__describe_bind

////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
