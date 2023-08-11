////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__path_utils.h
//! \brief   Utilities for work with paths
//! \author  Kovalenko Dmitry
//! \date    25.09.2022
#ifndef _ibp_os_win32__path_utils_H_
#define _ibp_os_win32__path_utils_H_

#include "source/ibp_char.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__path_utils

class t_ibp_os_win32__path_utils LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef t_ibp_os_win32__path_utils                       self_type;

 public:
  static t_ibp_str_box GetParentDir(const t_ibp_str_box& path);

  static t_ibp_string Concat(const t_ibp_str_box& path1,
                             const t_ibp_str_box& path2);

 private:
  static t_ibp_str_box Helper__NormalizationPath(const t_ibp_str_box& path);
};//class t_ibp_os_win32__path_utils

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
