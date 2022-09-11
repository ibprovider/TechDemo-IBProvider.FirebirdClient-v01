////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Windows OLE Automation
//                                                 Kovalenko Dmitry. 06.09.2022.
#ifndef _lcpi_infrastructure_os__windows_ole32_H_
#define _lcpi_infrastructure_os__windows_ole32_H_

#include <lcpi/infrastructure/os/.config.h>

////////////////////////////////////////////////////////////////////////////////

#ifndef LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE
# define LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE LCPI_INFRASTRUCTURE_OS__BUILD_MODE
#endif

////////////////////////////////////////////////////////////////////////////////

#if   LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__NONE

# include <lcpi/infrastructure/os/.impl/windows/native/windows-ole32.h>

#elif LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__EXPORT

# include <lcpi/infrastructure/os/.impl/windows/proxy/windows-ole32.h>

#elif LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE==LCPI_INFRASTRUCTURE_OS__BUILD_MODE__IMPORT

# include <lcpi/infrastructure/os/.impl/windows/proxy/windows-ole32.h>

#else

# error Unexpected LCPI_INFRASTRUCTURE_OS_WINDOWS_OLE32__BUILD_MODE

#endif

////////////////////////////////////////////////////////////////////////////////
#endif
