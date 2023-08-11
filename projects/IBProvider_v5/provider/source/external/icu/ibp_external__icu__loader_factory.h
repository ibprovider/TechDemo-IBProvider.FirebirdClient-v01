////////////////////////////////////////////////////////////////////////////////
//ICU Library Helpers.
//                                                 Kovalenko Dmitry. 03.07.2023.
#ifndef _ibp_external__icu__loader_factory_H_
#define _ibp_external__icu__loader_factory_H_

#include "source/external/icu/ibp_external__icu__loader.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__forwards.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////

ICU__Loader::self_ptr
 create_icu_loader(const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues);

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
