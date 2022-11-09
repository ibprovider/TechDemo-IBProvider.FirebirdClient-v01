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

/* shift left by a certain bit count */
mp_err mp_mul_2d(const mp_int*    const a,
                 mp_int_size_type const b,
                 mp_int*          const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 assert((b == 0) || (b >0));

 mp_err res;

 /* copy */
 if((res = mp_copy(a, c)) != MP_OKAY)
  return res;

 if(mp_iszero(c) || (b == 0))
  return MP_OKAY;

 assert_hint(b > 0);

 const mp_int::size_type lshift_bytes =(b / MP_DIGIT_BIT);
 const unsigned          lshift_bits  =(b % MP_DIGIT_BIT);

 if((res = mp_grow(c, c->used + lshift_bytes + (lshift_bits > 0 ? 1 : 0))) != MP_OKAY)
  return res;

 /* shift by as many digits in the bit count */
 if((res = mp_lshd(c, lshift_bytes)) != MP_OKAY)
  return res;

 /* shift any bit count < MP_DIGIT_BIT */
 if(const unsigned d = lshift_bits)
 {
  assert_hint(d > 0);

  /* bitmask for carries */
  mp_digit const mask = (((mp_digit)1) << d) - 1;

  /* shift for msbs */
  mp_digit const shift = (MP_DIGIT_BIT - d);

  /* alias */
  mp_digit* tmpc = c->dp;

  /* carry */
  mp_digit r = 0;

  for(mp_int::size_type x = 0; x != c->used; ++x)
  {
   /* get the higher bits of the current word */
   mp_digit const rr = ((*tmpc >> shift) & mask);

   /* shift the current word and OR in the carry */
   (*tmpc) = (((*tmpc << d) | r) & MP_MASK);

   ++tmpc;

   /* set the carry to the carry bits of the current word */
   r = rr;
  }//for x

  /* set final carry */
  if(r != 0)
  {
   assert(c->used < c->alloc);

   c->dp[c->used] = r;

   ++c->used;
  }//if
 }//if(d != 0)

 mp_clamp(c);

 return MP_OKAY;
}//mp_mul_2d

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
