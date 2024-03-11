////////////////////////////////////////////////////////////////////////////////
#ifndef _test_memory_H_
#define _test_memory_H_

#include <lcpi/lib/structure/t_smart_object.h>
#include <lcpi/lib/structure/t_memory.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//Memory Allocator

LCPI_CPP_LIB__DECLARE_WRAP_ALLOCATOR(TTSO_MemoryAllocator)

////////////////////////////////////////////////////////////////////////////////
//typedefs for system structures

using TSYS_MemoryAllocator
 =TTSO_MemoryAllocator;

using TSYS_SmartInterface
 =lcpi::lib::structure::t_smart_interface;

using TSYS_SmartMemoryObject
 =lcpi::lib::structure::t_basic_smart_interface_impl__dynamic
   <TSYS_SmartInterface,
    TSYS_MemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
