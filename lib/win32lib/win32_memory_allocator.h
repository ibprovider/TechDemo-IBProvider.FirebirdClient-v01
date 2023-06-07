////////////////////////////////////////////////////////////////////////////////
//Classes for work with VERSIONINFO resource
//                                                  Kovalenko Dmitry. 13.09.2022
#ifndef _win32_memory_allocator_H_
#define _win32_memory_allocator_H_

#include <structure/t_memory.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//Memory allocator for WIN32-objects

LCPI_CPP_LIB__DECLARE_WRAP_ALLOCATOR(TWin32MemoryAllocator);

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
