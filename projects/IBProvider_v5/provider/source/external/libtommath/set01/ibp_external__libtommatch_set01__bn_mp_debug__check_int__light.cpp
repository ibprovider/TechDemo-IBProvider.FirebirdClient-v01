////////////////////////////////////////////////////////////////////////////////
//libtommath library.
//                                                 Kovalenko Dmitry. 12.05.2016.
#include <_pch_.h>
#pragma hdrstop

#include "source/external/libtommath/set01/ibp_external__libtommatch_set01__tommath_private.h"
#include <structure/t_numeric_cast.h>

namespace lcpi{namespace ibp{namespace external{namespace libtommath{namespace set01{
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

void mp_debug__check_int__light(const mp_int* const a)
{
 assert(a);
 assert(a->used<=a->alloc);

 assert(structure::can_numeric_cast<size_t>(a->used));

 CHECK_READ_TYPED_PTR(a->dp,a->alloc);

 if(a->alloc==0)
 {
  assert(a->dp==nullptr);
 }

 for(mp_int::size_type i=0;i!=a->used;++i)
 {
  assert(a->dp[i]<=MP_MASK);
 }//for i

 for(mp_int::size_type i=a->used;i!=a->alloc;++i)
 {
  assert(a->dp[i]==0);
 }//for i

#if(MP_CFG__USE_DEBUG_MEM)
 mp_mem__debug_check_block(a->dp);
#endif
}//mp_debug__check_int__light

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
