////////////////////////////////////////////////////////////////////////////////
#ifndef _test_memory_H_
#define _test_memory_H_

#include <structure/t_smart_object.h>

namespace ibp_test{
////////////////////////////////////////////////////////////////////////////////
//Memory Allocator

DECLARE_WRAP_ALLOCATOR(TTSO_MemoryAllocator)

////////////////////////////////////////////////////////////////////////////////
//typedefs for system structures

typedef TTSO_MemoryAllocator                                  TSYS_MemoryAllocator;

typedef structure::t_smart_interface                          TSYS_SmartInterface;

typedef structure::t_basic_smart_interface_impl__dynamic
         <TSYS_SmartInterface,
          TSYS_MemoryAllocator>                               TSYS_SmartMemoryObject;

////////////////////////////////////////////////////////////////////////////////
}//namespace ibp_test
#endif
