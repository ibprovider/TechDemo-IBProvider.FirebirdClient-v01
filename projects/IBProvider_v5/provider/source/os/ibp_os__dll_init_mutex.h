////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll_init_mutex.h
//! \brief   Guard for initialize dynamic library (DLL)
//! \author  Kovalenko Dmitry
//! \date    31.08.2022
#ifndef _ibp_os__dll_init_mutex_H_
#define _ibp_os__dll_init_mutex_H_

#include "source/os/win32/ibp_os_win32__dll_init_mutex.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////

typedef os::win32::t_ibp_os_win32__dll_init_mutex          t_ibp_os__dll_init_mutex;

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
