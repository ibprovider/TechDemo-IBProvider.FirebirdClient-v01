////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__registry_utils.h
//! \brief   Utilities for work with Windows Registry
//! \author  Kovalenko Dmitry
//! \date    15.12.2022
#ifndef _ibp_os_win32__registry_utils_H_
#define _ibp_os_win32__registry_utils_H_

#include <lcpi/lib/.config.h>
#include <string>
#include <Ole2.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__registry_utils

class t_ibp_os_win32__registry_utils LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  /// <summary>
  ///  Reading ID of Error Lookup service. THROW.
  /// </summary>
  static std::pair<bool,std::wstring> read_error_lookup_clsid(REFCLSID providerClassID);

#ifdef _PROCESS_DEBUG_MESSAGE_
  /// <summary>
  ///  Reading flush period for log file. NO THROW.
  /// </summary>
  static std::pair<bool,DWORD> read_flush_period_for_log_file(REFCLSID providerClassID);
#endif
};//class t_ibp_os_win32__registry_utils

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
