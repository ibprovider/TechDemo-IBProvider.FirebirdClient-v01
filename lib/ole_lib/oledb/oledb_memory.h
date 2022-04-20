////////////////////////////////////////////////////////////////////////////////
//Memory management of C++ library for OLEDB
//                                                 Kovalenko Dmitry. 01.12.2014.
#ifndef _oledb_memory_H_
#define _oledb_memory_H_

#include <structure/t_memory.h>

#include <lcpi/lib/structure/t_smart_object.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class TOLEDBMemoryAllocator

DECLARE_WRAP_ALLOCATOR(TOLEDBMemoryAllocator)

////////////////////////////////////////////////////////////////////////////////

using t_oledb_smart_memory_object
 =lcpi::lib::structure::t_basic_smart_interface_impl__dynamic
   <lcpi::infrastructure::core::structure::t_smart_interface,
    TOLEDBMemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////

using t_oledb_smart_object_base2
 =lcpi::lib::structure::t_basic_smart_object_base2
   <TOLEDBMemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb_lib*/
#endif
