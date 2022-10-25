////////////////////////////////////////////////////////////////////////////////
//ole_lib library configurations
//                                                 Dmitry Kovalenko. 28.04.2004
#ifndef _ole_lib_cfg_H_
#define _ole_lib_cfg_H_

#include <lcpi/lib/com/.config.h>

#include <structure/t_common.h>

////////////////////////////////////////////////////////////////////////////////
//configuration
//
// OLE_LIB_NO_COM_MODULE
//  - not define ole_lib::TComModule
//    if define _USE_ATL_, this macros defined automatically
//
// OLE_LIB_NO_OLE_AUTO
//  - disable support OLE Automation in TComModule
//
// OLE_LIB_DEFAULT_TYPE_HOLDER
//  - default class used in templates of dual interfaces
//
// OLE_LIB_OUTPROC_SERVER
//  - generate code for COM-server in EXE
//
// OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO
//  - 0 no t_base_com_error::set_error_info method
//  - 1 generate t_base_com_error::set_error_info method

////////////////////////////////////////////////////////////////////////////////
#ifdef _USE_ATL_
# define OLE_LIB_NO_COM_MODULE
#endif

//------------------------------------------------------------------------
#ifndef OLE_LIB_DEFAULT_TYPE_HOLDER
# if !defined(OLE_LIB_NO_COM_MODULE) && !defined(OLE_LIB_NO_OLE_AUTO)
#  define OLE_LIB_DEFAULT_TYPE_HOLDER ole_lib::TComModule
# else
#  define OLE_LIB_DEFAULT_TYPE_HOLDER void* //DEFAULT
# endif
#endif

//------------------------------------------------------------------------
#ifndef OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO
# define OLE_LIB__COM_ERROR__HAS__SET_ERROR_INFO                   1
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
