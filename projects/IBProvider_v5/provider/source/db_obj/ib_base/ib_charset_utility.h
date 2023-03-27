////////////////////////////////////////////////////////////////////////////////
//! \ingroup ib_base
//! \file    ib_charset_utility.h
//! \brief   Утилиты для работы с кодовыми страницами
//! \author  Kovalenko Dmitry
//! \date    12.01.2009
#ifndef _ib_charset_utility_H_
#define _ib_charset_utility_H_

#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace ib_base{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_charset_const_ptr ib_get_metadata_charset(db_obj::t_db_charset_manager_v2* pCsMng);

////////////////////////////////////////////////////////////////////////////////

bool ib_object_name_is_ok(const isc_base::t_isc_connection_settings& cns,
                          structure::t_const_wstr_box                objectName);

////////////////////////////////////////////////////////////////////////////////
}/*nms ib_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
