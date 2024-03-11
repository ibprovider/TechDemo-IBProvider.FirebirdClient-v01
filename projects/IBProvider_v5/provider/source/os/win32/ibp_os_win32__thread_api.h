////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__thread_api.h
//! \brief   Thread API [Win32]
//! \author  Kovalenko Dmitry
//! \date    29.02.2024
#ifndef _ibp_os_win32__thread_api_H_
#define _ibp_os_win32__thread_api_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//class ibp_os_win32__thread_api

class ibp_os_win32__thread_api LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=ibp_os_win32__thread_api;

 public:
  using thread_id_type=DWORD;

 public:
  static thread_id_type GetCurrentThreadId();
};//class ibp_os_win32__thread_api

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
