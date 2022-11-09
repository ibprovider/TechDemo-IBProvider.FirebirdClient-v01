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

/* calc a value mod 2**b */
mp_err mp_mod_2d(const mp_int*    const a,
                 mp_int_size_type const b,
                 mp_int*          const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 //[2016-05-16] Исследовательский ассерт
 assert((b == 0) || (b > 0));

 mp_err res;

 /* if b is == 0 then zero the int */
 if(b == 0)
 {
  mp_zero(c);

  return MP_OKAY;
 }//if

 /* if the modulus is larger than the value than return */
 if(b >= (a->used * MP_DIGIT_BIT))
  return mp_copy(a, c);

 assert_hint(b < (a->used * MP_DIGIT_BIT));

 assert(a->used > 0);

 /* copy */
 if((res = mp_copy(a, c)) != MP_OKAY)
  return res;

 assert(a->used == c->used);

 /* zero digits above the last digit of the modulus */
 assert(((b / MP_DIGIT_BIT) + ((b % MP_DIGIT_BIT) == 0 ? 0 : 1)) <= c->used);

 for(mp_int::size_type x = ((b / MP_DIGIT_BIT) + ((b % MP_DIGIT_BIT) == 0 ? 0 : 1)); x != c->used; ++x)
 {
  assert(x < c->alloc);
  assert(x < c->used);

  c->dp[x] = 0;
 }//for

 /* clear the digit that is not completely outside/inside the modulus */
 assert((b / MP_DIGIT_BIT) < c->alloc);
 assert((b / MP_DIGIT_BIT) < c->used);

 c->dp[b / MP_DIGIT_BIT] &=
  (mp_digit)((((mp_digit)1) << unsigned(b % MP_DIGIT_BIT)) - ((mp_digit)1));

 mp_clamp(c);

 return MP_OKAY;
}//mp_mod_2d

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
