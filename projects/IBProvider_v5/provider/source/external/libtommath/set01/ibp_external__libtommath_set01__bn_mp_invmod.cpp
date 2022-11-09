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

/* hac 14.61, pp608 */
mp_err mp_invmod(const mp_int* const a,
                 const mp_int* const b,
                 mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 /* b cannot be negative */
 if(b->sign == MP_NEG || mp_iszero(b) == 1)
 {
  return MP_VAL;
 }

#ifdef BN_FAST_MP_INVMOD_C
 /* if the modulus is odd we can use a faster routine instead */
 if(mp_isodd(b) == 1)
 {
  return fast_mp_invmod(a, b, c);
 }
#endif

#ifdef BN_MP_INVMOD_SLOW_C
 return mp_invmod_slow(a, b, c);
#else
 return MP_VAL;
#endif
}//mp_invmod

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
