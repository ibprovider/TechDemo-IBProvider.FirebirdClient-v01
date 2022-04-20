////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_lib.h>

#ifndef OLE_LIB_NO_COM_MODULE
# include <win32lib/win32lib.h>
#endif

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////

#include <ole_lib/impl/ole_lib_impl_memory_allocator.cxx>
#include <ole_lib/impl/ole_lib_impl_base_unknown2.cxx>
#include <ole_lib/impl/ole_lib_impl_base_unknown2__with_free_thread_marshaler.cxx>
#include <ole_lib/impl/ole_lib_impl_class_factory.cxx>

#ifndef OLE_LIB_NO_OLE_AUTO

#include <ole_lib/impl/ole_lib_impl_type_info__attr.cxx>
#include <ole_lib/impl/ole_lib_impl_type_info__func_desc.cxx>

#endif

////////////////////////////////////////////////////////////////////////////////

#ifndef OLE_LIB_NO_COM_MODULE
#include <ole_lib/impl/ole_lib_impl_com_module.cxx>
TComModule _Module;
#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib

