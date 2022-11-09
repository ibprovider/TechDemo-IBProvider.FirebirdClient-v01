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

/* set to zero */
void mp_zero(mp_int* const a)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 mp_digit*             tmp = a->dp;
 const mp_digit* const end = (a->dp + a->used);

 for(; tmp != end; ++tmp)
 {
  (*tmp)=0;
 }

 a->sign = MP_ZPOS;
 a->used = 0;

 DEBUG_CODE(mp_debug__check_int__total(a);)
}//mp_zero

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
