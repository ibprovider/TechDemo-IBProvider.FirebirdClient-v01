////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__registry_utils.h
//! \brief   Utilities for work with Registry Storage
//! \author  Kovalenko Dmitry
//! \date    15.12.2022
#ifndef _ibprovider_source_os__ibp_os__registry_utils_H_
#define _ibprovider_source_os__ibp_os__registry_utils_H_

#if     (!defined(LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE))

# include "source/os/win32/ibp_os__registry_utils.h"

#elif   (LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT)

# include "source/os/lcpi_os/ibp_os__registry_utils.h"

#else

# include "source/os/win32/ibp_os__registry_utils.h"

#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
