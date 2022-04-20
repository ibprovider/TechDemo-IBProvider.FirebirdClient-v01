////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__common__api__errors__set02__scodes
//! \file    db_obj__dbms_fb__common__api__errors__set02__scodes.h
//! \brief   Перечисление SCODES описанных в Firebird 2.5
//! \author  Kovalenko Dmitry
//! \date    08.08.2016
#ifndef _db_obj__dbms_fb__common__api__errors__set02__scodes_H_
#define _db_obj__dbms_fb__common__api__errors__set02__scodes_H_

#include "source/db_obj/isc_base/isc_api.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace common{namespace api{namespace errors{namespace set02{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__common__api__errors__set02__scodes
//! @{
////////////////////////////////////////////////////////////////////////////////

const isc_api::t_ibp_isc_status ibp_fb_scode__facility              = 20;
const isc_api::t_ibp_isc_status ibp_fb_scode__factor                = 1;

/// End of argument list
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_end               = 0;

/// Generic DSRI status value
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_gds               = 1;

/// String argument
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_string            = 2;

/// Count & string argument
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_cstring           = 3;

/// Numeric argument (long)
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_number            = 4;

/// Interpreted status code (string)
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_interpreted       = 5;

/// VAX/VMS status code (long)
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_vms               = 6;

/// UNIX error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_unix              = 7;

/// Apollo/Domain error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_domain            = 8;

/// MSDOS/OS2 error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_dos               = 9;

/// HP MPE/XL error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_mpexl             = 10;

/// HP MPE/XL IPC error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_mpexl_ipc         = 11;

/// NeXT/Mach error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_next_mach         = 15;

/// NetWare error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_netware           = 16;

/// Win32 error code
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_win32             = 17;

/// Warning argument
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_warning           = 18;

/// SQLSTATE [introduced in Firebird 2.5]
const isc_api::t_ibp_isc_status ibp_fb_scode__arg_sql_state         = 19;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms set02*/}/*nms errors*/}/*nms api*/}/*nms common*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
