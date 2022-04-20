////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base__dbparams_for_attach__processor.h
//! \brief   Утилиты обработки параметров инициализации подключения и создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    16.02.2019
#ifndef _isc_base__dbparams_for_attach__processor_H_
#define _isc_base__dbparams_for_attach__processor_H_

#include "source/db_obj/isc_base/isc_base__dbparams_for_attach__installer.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__forwards.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class isc_base__dbparams_for_attach__processor

class isc_base__dbparams_for_attach__processor
{
 private:
  typedef isc_base__dbparams_for_attach__processor             self_type;

 public:
  static void set_dbinit_params
               (const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues,
                isc_base__dbparams_for_attach__installer*    pDbParamInstaller);
};//class isc_base__dbparams_for_attach__processor

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
