////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb
//! \file    ibp_oledb__prop__names.h
//! \brief   Определение имен OLEDB-свойств провайдера
//! \author  Kovalenko Dmitry
//! \date    19.08.2010
#ifndef _ibp_oledb__prop__names_H_
#define _ibp_oledb__prop__names_H_

#include <ole_lib/oledb/provider/oledb_wms.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_props
//! @{
////////////////////////////////////////////////////////////////////////////////

#define IBP_DBPROP_NAME__DSCREATE__DEFAULT_CHARSET \
 MAKE_OLEDB_WMS(L"IBP_NEWDB: Default Charset")

#define IBP_DBPROP_NAME__DSCREATE__DATABASE_PAGE_SIZE \
 MAKE_OLEDB_WMS(L"IBP_NEWDB: Database Page Size")

#define IBP_DBPROP_NAME__DSCREATE__DATABASE_DIALECT \
 MAKE_OLEDB_WMS(L"IBP_NEWDB: Database Dialect")

#define IBP_DBPROP_NAME__DSCREATE__DEFAULT_CHARSET_COLLATION \
 MAKE_OLEDB_WMS(L"IBP_NEWDB: Default Charset Collation")

#define IBP_DBPROP_NAME__DSCREATE__TYPE_OF_DATABASE_USERS \
 MAKE_OLEDB_WMS(L"IBP_NEWDB: Type Of Database Users")

////////////////////////////////////////////////////////////////////////////////

#define IBP_DBPROP_NAME__INIT__DATA_SOURCE \
 MAKE_OLEDB_WMS(L"Data Source")

#define IBP_DBPROP_NAME__INIT__LOCATION \
 MAKE_OLEDB_WMS(L"Location")

#define IBP_DBPROP_NAME__INIT__USER_ID \
 MAKE_OLEDB_WMS(L"User ID" L"\0" L"User")

#define IBP_DBPROP_NAME__INIT__PASSWORD \
 MAKE_OLEDB_WMS(L"Password" L"\0" L"PSWD")

#define IBP_DBPROP_NAME__INIT__HWND \
 MAKE_OLEDB_WMS(L"Window Handle")

#define IBP_DBPROP_NAME__INIT__DBCLIENT_LIBRARY \
 MAKE_OLEDB_WMS(L"dbclient_library")

#define IBP_DBPROP_NAME__INIT__SYS_ENCRYPT_PASSWORD \
 MAKE_OLEDB_WMS(L"sys_encrypt_password")

#define IBP_DBPROP_NAME__INIT__REMOTE__WIRE_CRYPT \
 MAKE_OLEDB_WMS(L"remote:wire_crypt")

#define IBP_DBPROP_NAME__INIT__REMOTE__AUTH \
 MAKE_OLEDB_WMS(L"remote:auth")

#define IBP_DBPROP_NAME__INIT__REMOTE__WIRE_COMPRESSION \
 MAKE_OLEDB_WMS(L"remote:wire_compression")

#define IBP_DBPROP_NAME__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY \
 MAKE_OLEDB_WMS(L"remote:wire_compression_library")

#define IBP_DBPROP_NAME__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY_64 \
 MAKE_OLEDB_WMS(L"remote:wire_compression_library_64")

#define IBP_DBPROP_NAME__INIT__REMOTE__WIRE_COMPRESSION_TYPE \
 MAKE_OLEDB_WMS(L"remote:wire_compression_type")

////////////////////////////////////////////////////////////////////////////////

#define IBP_DBPROP_NAME__STD__SUPPORT_SQUARE_DELIM_NAME \
 MAKE_OLEDB_WMS(L"support_square_delim_name")

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
