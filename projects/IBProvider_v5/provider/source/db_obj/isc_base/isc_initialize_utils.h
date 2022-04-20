////////////////////////////////////////////////////////////////////////////////
//! \ingroup  isc_base
//! \file     isc_initialize_utils.h
//! \brief    Конструкции для выполнения стандартных операций инициализации ISC-подключения
//! \author   Kovalenko Dmitry
//! \date     04.10.2008
#ifndef _isc_initialize_utils_H_
#define _isc_initialize_utils_H_

#include "source/db_obj/db_charset_manager_v2.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__forwards.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_charset_manager_v2_ptr
 isc_create_charset_manager_v2
  (const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
   const wchar_t*                               pCsName__ODS);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
