////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0__api
//! \file    db_obj__dbms_fb__v03_0_0__api__error_descrs2.h
//! \brief   Firebird 3.0 Error Descriptions.
//! \author  Kovalenko Dmitry
//! \date    14.04.2016
#ifndef _db_obj__dbms_fb__v03_0_0__api__error_descrs2_H_
#define _db_obj__dbms_fb__v03_0_0__api__error_descrs2_H_

#include "source/db_obj/dbms_fb/v03_0_0/api/db_obj__dbms_fb__v03_0_0__api__error_codes.h"
#include "source/db_obj/isc_base/isc_error_code_descr2.h"

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{namespace api{
////////////////////////////////////////////////////////////////////////////////

extern const isc_base::t_isc_error_code_descr2 g_fb_v03_0_0__error_descrs2[ibp_fb_v30_err__count];

////////////////////////////////////////////////////////////////////////////////
}/*nms api*/}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
