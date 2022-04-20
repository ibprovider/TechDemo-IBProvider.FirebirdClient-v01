////////////////////////////////////////////////////////////////////////////////
//Configuration header for Windows Platform
//                                               Dmitry Kovalenko. 31.01.2001.
#ifndef __pch_win_H_
#define __pch_win_H_

////////////////////////////////////////////////////////////////////////////////
//configurations
//
//  NO_WINDOWS_HEADER       - no windows.h
// --
//  INCLUDE_COMMCTRL_HEADER
//  INCLUDE_OLE_HEADER      - OLE support
//  INCLUDE_SHELL_HEADER    - shell support
//  INCLUDE_COMCAT_HEADER
//  INCLUDE_OLEDB_HEADER    - support of OLEDB
//  INCLUDE_ADODB_HEADER    - support of ADODB
//  INCLUDE_MSXML_HEADER    - support MSXML

////////////////////////////////////////////////////////////////////////////////

#if(!defined(__pch_H_))
 #error ("_pch_.h must be include before this header file.")
#endif

#if(!defined(__WIN32__))
 #error ("This header file only for WIN32 compile.")
#endif

////////////////////////////////////////////////////////////////////////////////

#ifndef STRICT
 #define STRICT
#endif

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif

////////////////////////////////////////////////////////////////////////////////
//Standart header files [Windows]

#ifdef NO_WINDOWS_HEADER
#else
#   include <windows.h>
#endif

#ifdef INCLUDE_COMMCTRL_HEADER
#   include <commctrl.h>
#endif

#if defined(INCLUDE_OLE_HEADER)     ||      \
    defined(INCLUDE_SHELL_HEADER)   ||      \
    defined(INCLUDE_COMCAT_HEADER)  ||      \
    defined(INCLUDE_OLEDB_HEADER)   ||      \
    defined(INCLUDE_MSXML_HEADER)
#   include <olectl.h>
#   include <oleidl.h>
#endif

#ifdef INCLUDE_SHELL_HEADER
#   include <shlobj.h>
#   include <shellapi.h>
#   include <shlwapi.h>
#endif

#ifdef INCLUDE_COMCAT_HEADER
#   include <comcat.h>
#endif

#ifdef INCLUDE_OLEDB_HEADER
#   include <oledb.h>
#   include <oledberr.h>

#   if !defined(OLEDBVER)
#    error "Unknown OLEDB version !!!"
#   endif
#endif

#ifdef INCLUDE_ADODB_HEADER
#   include <adoid.h>
#   include <adoint.h>

#   ifndef ADO_VERSION
#    error "Unknown ADO version !!!"
#   endif
#endif

#ifdef INCLUDE_MSXML_HEADER
#   include <msxml2.h>
#   include <msxml2did.h>
#endif

////////////////////////////////////////////////////////////////////////////////
//Define standard macros

//(required) standart engine for debug information output
#define __ODS_IMPLEMENTATION__(msg)  ::OutputDebugStringA(msg)

////////////////////////////////////////////////////////////////////////////////
#endif //end of file _pch_win_.h
