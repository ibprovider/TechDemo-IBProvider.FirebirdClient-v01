////////////////////////////////////////////////////////////////////////////////
//! \ingroup lib_structure
//! \file    t_memory.h
//! \brief   Structures for work with memory
//! \author  Kovalenko Dmitry
//! \date    06.02.2000.
#ifndef _t_memory_H_
#define _t_memory_H_

#include <lcpi/lib/structure/t_memory.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

using namespace ::lcpi::lib::structure;

////////////////////////////////////////////////////////////////////////////////
//support rebind

#define __STLS_ALLOCATOR_REBIND(Allocator,U)                                  \
 LCPI_CPP_LIB__STLS_ALLOCATOR_REBIND(Allocator,U)

////////////////////////////////////////////////////////////////////////////////
//define wrap allocator

//макрос для определения обертки вокруг функций распределения памяти
//DECLARE_WRAP_ALLOCATOR(AllocatorClassName)

//declare wrap allocator
#define DECLARE_WRAP_ALLOCATOR(AllocatorClassName)                            \
 LCPI_CPP_LIB__DECLARE_WRAP_ALLOCATOR(AllocatorClassName)

//------------------------------------------------------------------------
//wrap allocator implementations

#define DEFINE_WRAP_ALLOCATOR(AllocatorClassName)                             \
 LCPI_CPP_LIB__DEFINE_WRAP_ALLOCATOR(AllocatorClassName)

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
