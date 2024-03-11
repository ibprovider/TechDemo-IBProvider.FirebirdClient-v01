////////////////////////////////////////////////////////////////////////////////
//Configuration file for create PCH file and config for target system and compiler
//                                                 Dmitry Kovalenko. 1999 year.

#ifndef __pch_H_
#define __pch_H_

////////////////////////////////////////////////////////////////////////////////
//configurations
// ALL:
//  INCLUDE_LOCAL_PCH_HEADER
//   - add #include "_pch_local_.h" in this file

////////////////////////////////////////////////////////////////////////////////
//Target-specific standart header files

//required macros define (used in <debug_services.h>)
//__ODS_IMPLEMENTATION__(msg)

#if defined(_WIN32)

  #if(!defined(__WIN32__))
    #define __WIN32__
  #endif

  #include <_pch_win_.h>

#else
  #error("unknown target") 
#endif

////////////////////////////////////////////////////////////////////////////////

//set of helpers macroses
#include <_util_mac.h>

//compiler configurations
#include <config/config_compiler.h>

//CRT configurations
#include <config/config_crt.h>

//STL configurations
#include <config/config_stl.h>

//set of debug macroses
#include <_debug_mac.h>

////////////////////////////////////////////////////////////////////////////////
//support local PCH files

#ifdef INCLUDE_LOCAL_PCH_HEADER
# include "_pch_local_.h"
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
