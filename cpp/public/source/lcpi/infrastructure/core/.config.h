///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Core.
//                                               Dmitry Kovalenko. 16.07.2019.
#ifndef _lcpi_infrastructre_core__config_H_
#define _lcpi_infrastructre_core__config_H_

#include <lcpi/.config.h>

///////////////////////////////////////////////////////////////////////////////

#define LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE                  0
#define LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__EXPORT                1
#define LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT                2

///////////////////////////////////////////////////////////////////////////////
//LCPI_INFRASTRUCTURE_CORE__BUILD_MODE

#ifndef LCPI_INFRASTRUCTURE_CORE__BUILD_MODE

#define LCPI_INFRASTRUCTURE_CORE__BUILD_MODE LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE

#endif

///////////////////////////////////////////////////////////////////////////////
//LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG

// Export/Import specification for classes

#if   LCPI_INFRASTRUCTURE_CORE__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE
# define LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG
#elif LCPI_INFRASTRUCTURE_CORE__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__EXPORT
# define LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG __declspec(dllexport)
#elif LCPI_INFRASTRUCTURE_CORE__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT
# define LCPI_INFRASTRUCTURE_CORE__CFG__CLASS_STG __declspec(dllimport)
#else
# error Unexpected LCPI_INFRASTRUCTURE_CORE__BUILD_MODE
#endif

///////////////////////////////////////////////////////////////////////////////
//LCPI_INFRASTRUCTURE_CORE__CFG__IFACE_STG

// Export/Import specification for interfaces

#define LCPI_INFRASTRUCTURE_CORE__CFG__IFACE_STG

///////////////////////////////////////////////////////////////////////////////
#endif
