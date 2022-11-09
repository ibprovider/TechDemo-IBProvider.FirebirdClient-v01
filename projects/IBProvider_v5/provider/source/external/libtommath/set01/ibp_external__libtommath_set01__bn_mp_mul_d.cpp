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

/* multiply by a digit */
mp_err mp_mul_d(const mp_int* const a,
                mp_digit      const b,
                mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 mp_err res;

 if(mp_iszero(a) || (b == 0))
 {
  mp_zero(c);

  return MP_OKAY;
 }//if

 /* make sure c is big enough to hold a*b */
 if((res = mp_grow(c, a->used + 1)) != MP_OKAY)
  return res;

 /* get the original destinations used count */
 const mp_int::size_type oldused = c->used;

 /* set the sign */
 c->sign = a->sign;

 /* alias for a->dp [source] */
 const mp_digit* tmpa = a->dp;
 
 const mp_digit* const _ea = (a->dp + a->used);

 /* alias for c->dp [dest] */
 mp_digit* tmpc = c->dp;

 /* zero carry */
 mp_digit u = 0;

 /* compute columns */

 for(; tmpa != _ea; ++tmpc, ++tmpa)
 {
  /* compute product and carry sum for this term */
  mp_word const r = ((mp_word)u) + ((mp_word)*tmpa) * ((mp_word)b);

  /* mask off higher bits to get a single digit */
  (*tmpc) = (mp_digit)(r & ((mp_word)MP_MASK));

  /* send carry into next iteration */
  u = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));
 }//for ix

 /* store final carry [if any] and increment ix offset  */
 assert(c->alloc >= (a->used + 1));
 assert(tmpc == (c->dp + a->used));

 (*tmpc) = u;

 /* set used count */
 c->used = (a->used + 1);

 if(c->used < oldused)
 {
  assert(oldused <= c->alloc);

  std::fill(c->dp + c->used, c->dp + oldused, 0);
 }//if

 mp_clamp(c);

 return MP_OKAY;
}//mp_mul_d

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
