////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base__dbparams_for_create__processor.h
//! \brief   ”тилиты обработки параметров новой базы данных.
//! \author  Kovalenko Dmitry
//! \date    16.02.2019
#ifndef _isc_base__dbparams_for_create__processor_H_
#define _isc_base__dbparams_for_create__processor_H_

#include "source/db_obj/isc_base/isc_base__dbparams_for_create__installer.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__forwards.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_base__dbparams_for_create__processor

class isc_base__dbparams_for_create__processor
{
 private:
  typedef isc_base__dbparams_for_create__processor             self_type;

 public:
  static void set_newdb_params
               (const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
                isc_base__dbparams_for_create__installer*    pDbParamInstaller);
};//class isc_base__dbparams_for_create__processor

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
