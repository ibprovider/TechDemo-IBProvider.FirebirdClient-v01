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

/* shift right by a certain bit count (store quotient in c, optional remainder in d) */
mp_err mp_div_2d(const mp_int*    const a,
                 mp_int_size_type const b,
                 mp_int*          const c,
                 mp_int*          const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 assert((b == 0) || (b > 0));

#ifndef NDEBUG
 if(d)
  mp_debug__check_int__light(d);
#endif

 mp_err res;

 /* if the shift count is <= 0 then we do no work */
 if(b == 0)
 {
  if((res = mp_copy(a, c)) != MP_OKAY)
   return res;

  assert_hint(res == MP_OKAY);

  if(d != NULL)
  {
   mp_zero(d);
  }

  assert_hint(res == MP_OKAY);

  return MP_OKAY;
 }//if

 mp_int_x t;

 /* get the remainder */
 if(d != NULL)
 {
  if((res = mp_mod_2d(a, b, &t)) != MP_OKAY)
   return res;
 }//if

 /* copy */
 if((res = mp_copy(a, c)) != MP_OKAY)
  return res;

 /* shift by as many digits in the bit count */
 if(b >= MP_DIGIT_BIT)
 {
  mp_rshd(c, b / MP_DIGIT_BIT);
 }

 /* shift any bit count < MP_DIGIT_BIT */
 if(const mp_digit D = (mp_digit)(b % MP_DIGIT_BIT))
 {
  assert_hint(D > 0);
  assert(D < MP_DIGIT_BIT);

  /* mask */
  const mp_digit mask = ((((mp_digit)1) << D) - 1);

  /* shift for lsb */
  const mp_digit shift = (MP_DIGIT_BIT - D);

  /* carry */
  mp_digit r = 0;

  for(mp_digit* tmpc = (c->dp + c->used); tmpc != c->dp;)
  {
   --tmpc; 

   /* get the lower  bits of this word in a temp */
   const mp_digit rr = ((*tmpc) & mask);

   /* shift the current word and mix in the carry bits from the previous word */
   (*tmpc) = ((*tmpc) >> D) | (r << shift);

   /* set the carry to the carry bits of the current word found above */
   r = rr;
  }//for tmpc
 }//if D!=0

 mp_clamp(c);

 if(d != NULL)
 {
  mp_exch(&t, d);
 }

 return MP_OKAY;
}//mp_div_2d

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
