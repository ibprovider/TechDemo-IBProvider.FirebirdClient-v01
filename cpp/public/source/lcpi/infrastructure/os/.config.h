///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API.
//                                               Dmitry Kovalenko. 06.09.2022.
#ifndef _lcpi_infrastructure_os__config_H_
#define _lcpi_infrastructure_os__config_H_

#include <lcpi/infrastructure/core/.config.h>

///////////////////////////////////////////////////////////////////////////////

#define LCPI_INFRASTRUCTURE_OS__BUILD_MODE__NONE   LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE
#define LCPI_INFRASTRUCTURE_OS__BUILD_MODE__EXPORT LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__EXPORT
#define LCPI_INFRASTRUCTURE_OS__BUILD_MODE__IMPORT LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT

///////////////////////////////////////////////////////////////////////////////
//LCPI_INFRASTRUCTURE_OS__BUILD_MODE

#ifndef LCPI_INFRASTRUCTURE_OS__BUILD_MODE

#define LCPI_INFRASTRUCTURE_OS__BUILD_MODE LCPI_INFRASTRUCTURE_OS__BUILD_MODE__NONE

#endif

///////////////////////////////////////////////////////////////////////////////
//Checks

//#if LCPI_INFRASTRUCTURE_OS__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT
//#endif
//
//#if LCPI_INFRASTRUCTURE_OS__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__EXPORT
//#endif
//
//#if LCPI_INFRASTRUCTURE_CORE__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE
//#endif

///////////////////////////////////////////////////////////////////////////////
#endif
