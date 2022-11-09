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

/* shift right a certain amount of digits */
void mp_rshd(mp_int*          const a,
             mp_int_size_type const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a));

 //[2016-05-15] Research assert
 assert((b == 0) || (b > 0));

 /* if b <= 0 then ignore it */
 if(b == 0)
  return;

 assert_hint(b > 0);

 /* if b > used then simply zero it and return */
 if(a->used <= b)
 {
  mp_zero(a);

  return;
 }//if

 assert_hint(b > 0);
 assert_hint(b < a->used);

 {
  /* shift the digits down */

  /* bottom */
  mp_digit* bottom = a->dp;

  /* top [offset into digits] */
  const mp_digit* top = a->dp + b;

  /* this is implemented as a sliding window where
   * the window is b-digits long and digits from
   * the top of the window are copied to the bottom
   *
   * e.g.

   b-2 | b-1 | b0 | b1 | b2 | ... | bb |   ---->
               /\                   |      ---->
                \-------------------/      ---->
   */

  const mp_digit* const e2 = (a->dp + a->used);

  assert_hint(b > 0);
  assert_hint(b < a->used);

  a->used -= b;

  const mp_digit* const e1 = (a->dp + a->used);

  assert(a->used > 0);

  for(; bottom!= e1; ++bottom, ++top)
  {
   assert(top != e2);

   (*bottom) = (*top);
  }//for

  /* zero the top digits */
  for(; bottom!= e2; ++bottom)
  {
   (*bottom) = 0;
  }//for
 }//local

 DEBUG_CODE(mp_debug__check_int__total(a);)
}//mp_rshd

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
