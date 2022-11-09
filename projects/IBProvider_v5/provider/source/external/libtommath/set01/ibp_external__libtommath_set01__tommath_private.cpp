////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath_private.h"
#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace external{namespace libtommath{namespace set01{
////////////////////////////////////////////////////////////////////////////////

#ifndef MP_CFG__USE_DEBUG_MEM
# error MP_CFG__USE_DEBUG_MEM not defined!
#endif

////////////////////////////////////////////////////////////////////////////////

#if(!MP_CFG__USE_DEBUG_MEM)

void* mp_mem__malloc(size_t const n)
{
 return IBP_MemoryAllocator::instance.allocate(n); //throw
}//mp_mem__malloc

//------------------------------------------------------------------------
void mp_mem__free(void* const p)
{
 return IBP_MemoryAllocator::instance.deallocate(p,0);
}//mp_mem__free

#else

//------------------------------------------------------------------------
void* mp_mem__malloc(size_t const n)
{
 return IBP_MemoryWithDebugChecks::Alloc(n);
}//mp_mem__malloc

//------------------------------------------------------------------------
void mp_mem__free(void* const p)
{
 return IBP_MemoryWithDebugChecks::Free(p);
}//mp_mem__free

//------------------------------------------------------------------------
#ifndef NDEBUG

void mp_mem__debug_check_block(const void* const p)
{
 return IBP_MemoryWithDebugChecks::Debug__CheckBlock(p);
}//mp_mem__debug_check_block

#endif // !NDEBUG

//------------------------------------------------------------------------
#endif // MP_CFG__USE_DEBUG_MEM

////////////////////////////////////////////////////////////////////////////////

char mp_upper7(char const ch)
{
 assert_s('A'<'a');

 assert_s('A'<'Z');
 assert_s('Z'<'a');
 assert_s('a'<'z');

 assert_s(('Z'-'A')==('z'-'a'));

 if(ch>='a' && ch<='z')
  return ch-('a'-'A');

 return ch;
}//mp_upper7

////////////////////////////////////////////////////////////////////////////////
//class mp_int_x

mp_int_x::mp_int_x()
{
 mp_init_v3(this);
}//mp_int_x

//------------------------------------------------------------------------
mp_int_x::~mp_int_x()
{
 mp_clear_v3(this);
}//~mp_int_x

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
