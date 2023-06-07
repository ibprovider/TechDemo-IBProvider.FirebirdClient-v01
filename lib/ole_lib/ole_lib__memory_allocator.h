////////////////////////////////////////////////////////////////////////////////
//C++ library for OLE.
//                                                Kovalenko Dmitry. 28.10.2022.
#ifndef _ole_lib__memory_allocator_H_
#define _ole_lib__memory_allocator_H_

#include <structure/t_memory.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//Memory allocator for COM-objects

LCPI_CPP_LIB__DECLARE_WRAP_ALLOCATOR(TComObjectMemoryAllocator);

////////////////////////////////////////////////////////////////////////////////
//Helper utility for work with TComObjectMemoryAllocator

inline void* ComObjectAllocMemory(size_t const sz)
 {return TComObjectMemoryAllocator::instance.allocate(sz);}

inline void ComObjectFreeMemory(void* const pv)
 {TComObjectMemoryAllocator::instance.deallocate(pv,0);}

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
