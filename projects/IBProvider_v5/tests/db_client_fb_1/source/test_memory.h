////////////////////////////////////////////////////////////////////////////////
#ifndef _test_memory_H_
#define _test_memory_H_

#include <structure/test_obj/fw/set01/test_fw_set01__base.h>

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//Memory Allocator

using TTSO_MemoryAllocator
 =structure::test_fw::set01::TestFW__StdMemoryAllocator;

using TTSO_SmartInterface
 =lib::structure::t_smart_interface;

using TTSO_SmartMemoryObject
 =lib::structure::t_basic_smart_interface_impl__dynamic<TTSO_SmartInterface,TTSO_MemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////
//typedefs for system structures

using TSYS_MemoryAllocator
 =structure::test_fw::set01::TestFW__SysMemoryAllocator;

using TSYS_SmartInterface
 =structure::test_fw::set01::TestFW__SysSmartInterface;

using TSYS_SmartMemoryObject
 =structure::test_fw::set01::TestFW__SysSmartMemoryObject;

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
