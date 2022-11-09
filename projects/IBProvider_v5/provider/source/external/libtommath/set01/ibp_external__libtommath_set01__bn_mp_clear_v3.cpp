////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath_private.h"

namespace lcpi{namespace ibp{namespace external{namespace libtommath{namespace set01{
////////////////////////////////////////////////////////////////////////////////

/* LibTomMath, multiple-precision integer library -- Tom St Denis
 *
 * LibTomMath is a library that provides multiple-precision
 * integer arithmetic as well as number theoretic functionality.
 *
 * The library was designed directly after the MPI library by
 * Michael Fromberger but has been written from scratch with
 * additional optimizations in place.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtom.org
 */

/* clear one (frees)  */
void mp_clear_v3(mp_int* const a)
{
 DEBUG_CODE(mp_debug__check_int__light(a);)

 //------
 std::fill(a->dp, a->dp + a->used, 0);

 //------
 void* const tmp = a->dp;

 //------
 a->dp    = nullptr;
 a->alloc = 0;
 a->used  = 0;
 a->sign  = MP_ZPOS;

 //------
 mp_mem__free(tmp);

 //------
 DEBUG_CODE(mp_debug__check_int__total(a);)
}//mp_clear_v3

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
