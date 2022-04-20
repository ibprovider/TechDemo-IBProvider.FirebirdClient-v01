///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. Multitasking [IBP].
//                                               Dmitry Kovalenko. 26.08.2019.
#ifndef _lcpi_infrastructure_multitasking_ibp__config_H_
#define _lcpi_infrastructure_multitasking_ibp__config_H_

#include <lcpi/infrastructure/core/.config.h>

///////////////////////////////////////////////////////////////////////////////

#define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE__NONE   LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE
#define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE__EXPORT LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__EXPORT
#define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE__IMPORT LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT

///////////////////////////////////////////////////////////////////////////////
//LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE

#ifndef LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE

#define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE__NONE

#endif

///////////////////////////////////////////////////////////////////////////////
//Checks

#if LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT
# if LCPI_INFRASTRUCTURE_CORE__BUILD_MODE!=LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT
#  error Failed configuration
# endif
#endif

#if LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__EXPORT
# if LCPI_INFRASTRUCTURE_CORE__BUILD_MODE!=LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__IMPORT
#  error Failed configuration
# endif
#endif

//------------------------------------------------------------------------
#if LCPI_INFRASTRUCTURE_CORE__BUILD_MODE==LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE
# if LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE!=LCPI_INFRASTRUCTURE_CORE__BUILD_MODE__NONE
#  error Failed configuration
# endif
#endif

///////////////////////////////////////////////////////////////////////////////
//LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__CLASS_STG

// Export/Import specification for classes

#if   LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE==LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE__NONE
# define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__CLASS_STG
#elif LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE==LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE__EXPORT
# define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__CLASS_STG __declspec(dllexport)
#elif LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE==LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE__IMPORT
# define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__CLASS_STG __declspec(dllimport)
#else
# error Unexpected LCPI_INFRASTRUCTURE_MULTITASKING_IBP__BUILD_MODE
#endif

///////////////////////////////////////////////////////////////////////////////
//LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG

// Export/Import specification for interfaces

#define LCPI_INFRASTRUCTURE_MULTITASKING_IBP__CFG__IFACE_STG

///////////////////////////////////////////////////////////////////////////////
#endif
