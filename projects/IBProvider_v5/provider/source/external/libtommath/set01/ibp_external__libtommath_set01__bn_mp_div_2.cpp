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

/* b = a/2 */
mp_err mp_div_2(const mp_int* const a,
                mp_int*       const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(b);)

 mp_err res;

 /* reserve */
 if((res = mp_grow(b, a->used)) != MP_OKAY)
  return res;

 assert(a->used <= b->alloc);

 {
  /* source alias */
  const mp_digit* tmpa = (a->dp + a->used);

  /* dest alias */
  mp_digit* tmpb = (b->dp + a->used);

  /* carry */
  mp_digit r = 0;

  while(tmpb != b->dp)
  {
   --tmpa;
   --tmpb;

   /* get the carry for the next iteration */
   const mp_digit rr = ((*tmpa) & 1);

   /* shift the current digit, add in carry and store */
   (*tmpb) = ((*tmpa) >> 1) | (r << (MP_DIGIT_BIT - 1));

   /* forward carry to next iteration */
   r = rr;
  }//for
 }//local

 if(a->used < b->used)
 {
  /* zero excess digits */
  mp_digit*             tmpb = (b->dp + a->used);
  const mp_digit* const endb = (b->dp + b->used);

  for(;tmpb != endb; ++tmpb)
  {
   (*tmpb) = 0;
  }
 }//local

 b->sign = a->sign;
 b->used = a->used;

 mp_clamp(b);

 return MP_OKAY;
}//mp_div_2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
