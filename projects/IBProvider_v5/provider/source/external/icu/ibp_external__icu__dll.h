////////////////////////////////////////////////////////////////////////////////
//ICU Library Helpers.
//                                                 Kovalenko Dmitry. 26.06.2023.
#ifndef _ibp_external__icu__dll_H_
#define _ibp_external__icu__dll_H_

#include "source/os/ibp_os__dll.h"

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////
//class ICU__Dll

class LCPI_CPP_CFG__DECLSPEC__NOVTABLE ICU__Dll:public os::t_ibp_os__dll
{
};//class ICU__Dll

using ICU__Dll_Ptr=lib::structure::t_smart_object_ptr<ICU__Dll>;

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
