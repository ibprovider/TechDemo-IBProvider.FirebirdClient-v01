////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll_entry_point.h
//! \brief   Класс для управления точкой входа динамической библиотеки (DLL).
//! \author  Kovalenko Dmitry
//! \date    28.11.2014
#ifndef _ibp_os__dll_entry_point_H_
#define _ibp_os__dll_entry_point_H_

#include "source/os/win32/ibp_os_win32__dll_entry_point.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//struct t_ibp_os__dll_entry_point

template<class Func>
struct ibp_os__dll_entry_point
{
 public:
  typedef os::win32::t_ibp_os_win32__dll_entry_point<Func> type;
};//struct ibp_os__dll_entry_point

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
