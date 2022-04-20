////////////////////////////////////////////////////////////////////////////////
//Base library for creating COM-objects
// The main idea was taken from the book "Inside COM" Dale Rodgerson
//                                                    Dmitry Kovalenko. 98 year.
#ifndef _ole_lib_H_
#define _ole_lib_H_

#include <ole_lib/ole_ptr_std.h>

#include <structure/t_smart_vector.h>

#include <structure/stl/t_stl_map.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//content

#ifndef OLE_LIB_NO_OLE_AUTO

template<class Allocator>
class TTypeInfoAccelerator;

template<class Allocator>
class TTypeInfoCacheItem;

template<class Allocator>
class TTypeInfoCache;

#endif //OLE_LIB_NO_OLE_AUTO

////////////////////////////////////////////////////////////////////////////////
//include files with implementations

#include <ole_lib/impl/ole_lib_impl_mac_debug.hxx>
#include <ole_lib/impl/ole_lib_impl_mac_help.hxx>
#include <ole_lib/impl/ole_lib_impl_memory_allocator.hxx>
#include <ole_lib/impl/ole_lib_impl_nondelegating_unknown.hxx>
#include <ole_lib/impl/ole_lib_impl_base_unknown2.hxx>
#include <ole_lib/impl/ole_lib_impl_base_unknown2__with_free_thread_marshaler.hxx>
#include <ole_lib/impl/ole_lib_impl_template_unknown2.hxx>
#include <ole_lib/impl/ole_lib_impl_class_factory.hxx>

#ifndef OLE_LIB_NO_OLE_AUTO

#include <ole_lib/impl/ole_lib_impl_type_info__attr.hxx>
#include <ole_lib/impl/ole_lib_impl_type_info__func_desc.hxx>
#include <ole_lib/impl/ole_lib_impl_type_info__accelerator.hxx>
#include <ole_lib/impl/ole_lib_impl_type_info__cache.hxx>

#endif

////////////////////////////////////////////////////////////////////////////////

#ifndef OLE_LIB_NO_COM_MODULE
#include <ole_lib/impl/ole_lib_impl_com_module.hxx>
extern TComModule _Module;
#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/ole_lib.cc>
////////////////////////////////////////////////////////////////////////////////
#endif


