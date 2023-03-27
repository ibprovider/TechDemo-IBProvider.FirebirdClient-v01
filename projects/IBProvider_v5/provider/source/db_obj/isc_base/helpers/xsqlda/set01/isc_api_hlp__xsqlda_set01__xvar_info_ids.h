////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_api_hlp__xsqlda_set01__xvar_info_ids.h
//! \brief   The tag ids of XSQLDA SET01.
//! \author  Kovalenko Dmitry
//! \date    26.03.2023
#ifndef _isc_api_hlp__xsqlda_set01__xvar_info_ids_H_
#define _isc_api_hlp__xsqlda_set01__xvar_info_ids_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{namespace isc_base{namespace helpers{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////

#define IBP_ISC_API_HLP__XSQLDA_SET01__XVAR_INFO_IDS__C11 \
 isc_api::ibp_isc_info_sql_describe_vars,                 \
 isc_api::ibp_isc_info_sql_sqlda_seq,                     \
 isc_api::ibp_isc_info_sql_type,                          \
 isc_api::ibp_isc_info_sql_sub_type,                      \
 isc_api::ibp_isc_info_sql_scale,                         \
 isc_api::ibp_isc_info_sql_length,                        \
 isc_api::ibp_isc_info_sql_field,                         \
 isc_api::ibp_isc_info_sql_relation,                      \
 isc_api::ibp_isc_info_sql_owner,                         \
 isc_api::ibp_isc_info_sql_alias,                         \
 isc_api::ibp_isc_info_sql_describe_end,

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms helpers*/}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
