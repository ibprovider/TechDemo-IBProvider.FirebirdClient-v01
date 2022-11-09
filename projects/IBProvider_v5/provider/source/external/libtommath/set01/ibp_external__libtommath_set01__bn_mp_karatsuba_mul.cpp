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

/* c = |a| * |b| using Karatsuba Multiplication using
 * three half size multiplications
 *
 * Let B represent the radix [e.g. 2**MP_DIGIT_BIT] and
 * let n represent half of the number of digits in
 * the min(a,b)
 *
 * a = a1 * B**n + a0
 * b = b1 * B**n + b0
 *
 * Then, a * b =>
   a1b1 * B**2n + ((a1 + a0)(b1 + b0) - (a0b0 + a1b1)) * B + a0b0
 *
 * Note that a1b1 and a0b0 are used twice and only need to be
 * computed once.  So in total three half size (half # of
 * digit) multiplications are performed, a0b0, a1b1 and
 * (a1+b1)(a0+b0)
 *
 * Note that a multiplication of half the digits requires
 * 1/4th the number of single precision multiplications so in
 * total after one call 25% of the single precision multiplications
 * are saved.  Note also that the call to mp_mul can end up back
 * in this function if the a0, a1, b0, or b1 are above the threshold.
 * This is known as divide-and-conquer and leads to the famous
 * O(N**lg(3)) or O(N**1.584) work which is asymptopically lower than
 * the standard O(N**2) that the baseline/comba methods use.
 * Generally though the overhead of this method doesn't pay off
 * until a certain size (N ~ 80) is reached.
 */
mp_err mp_karatsuba_mul(const mp_int* const a,
                        const mp_int* const b,
                        mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 /* default the return code to an error */
 mp_err err = MP_MEM;

 /* min # of digits */
 const mp_int::size_type c_minSrcSize = MIN(a->used, b->used);

 /* now divide in two */
 const mp_int::size_type B = (c_minSrcSize >> 1);

 mp_int_x x0, x1, y0, y1, t1, x0y0, x1y1;

 /* init copy all the temps */
 if((err = mp_grow(&x0, B)) != MP_OKAY)
  return err;

 if((err = mp_grow(&x1, a->used - B)) != MP_OKAY)
  return err;

 if((err = mp_grow(&y0, B)) != MP_OKAY)
  return err;

 if((err = mp_grow(&y1, b->used - B)) != MP_OKAY)
  return err;

 /* init temps */
 if((err = mp_grow(&t1, B * 2)) != MP_OKAY)
  return err;

 if((err = mp_grow(&x0y0, B * 2)) != MP_OKAY)
  return err;

 if((err = mp_grow(&x1y1, B * 2)) != MP_OKAY)
  return err;

 /* now shift the digits */
 x0.used = y0.used = B;
 x1.used = (a->used - B);
 y1.used = (b->used - B);

 {
  /* we copy the digits directly instead of using higher level functions
   * since we also need to shift the digits
   */
  const mp_digit* tmpa = a->dp;
  const mp_digit* tmpb = b->dp;

  mp_digit* tmpx = x0.dp;
  mp_digit* tmpy = y0.dp;

  for(mp_int::size_type x = 0; x < B; ++x, ++tmpx, ++tmpa, ++tmpy, ++tmpb)
  {
   (*tmpx) = (*tmpa);
   (*tmpy) = (*tmpb);
  }

  tmpx = x1.dp;

  for(mp_int::size_type x = B; x < a->used; ++x, ++tmpx, ++tmpa)
  {
   (*tmpx) = (*tmpa);
  }

  tmpy = y1.dp;

  for(mp_int::size_type x = B; x < b->used; ++x, ++tmpy, ++tmpb)
  {
   (*tmpy) = (*tmpb);
  }
 }//local

 /* only need to clamp the lower words since by definition the
  * upper words x1/y1 must have a known number of digits
  */
 mp_clamp(&x0);
 mp_clamp(&y0);

 /* now calc the products x0y0 and x1y1 */
 /* after this x0 is no longer required, free temp [x0==t2]! */
 if((err = mp_mul(&x0, &y0, &x0y0)) != MP_OKAY)
  return err;          /* x0y0 = x0*y0 */

 if((err = mp_mul(&x1, &y1, &x1y1)) != MP_OKAY)
  return err;          /* x1y1 = x1*y1 */

 /* now calc x1+x0 and y1+y0 */
 if((err = s_mp_add(&x1, &x0, &t1)) != MP_OKAY)
  return err;          /* t1 = x1 - x0 */

 if((err = s_mp_add(&y1, &y0, &x0)) != MP_OKAY)
  return err;          /* t2 = y1 - y0 */

 if((err = mp_mul(&t1, &x0, &t1)) != MP_OKAY)
  return err;          /* t1 = (x1 + x0) * (y1 + y0) */

 /* add x0y0 */
 if((err = mp_add(&x0y0, &x1y1, &x0)) != MP_OKAY)
  return err;          /* t2 = x0y0 + x1y1 */

 if((err = s_mp_sub(&t1, &x0, &t1)) != MP_OKAY)
  return err;          /* t1 = (x1+x0)*(y1+y0) - (x1y1 + x0y0) */

 /* shift by B */
 if((err = mp_lshd(&t1, B)) != MP_OKAY)
  return err;          /* t1 = (x0y0 + x1y1 - (x1-x0)*(y1-y0))<<B */

 if((err = mp_lshd(&x1y1, B * 2)) != MP_OKAY)
  return err;          /* x1y1 = x1y1 << 2*B */

 if((err = mp_add(&x0y0, &t1, &t1)) != MP_OKAY)
  return err;          /* t1 = x0y0 + t1 */

 if((err = mp_add(&t1, &x1y1, c)) != MP_OKAY)
  return err;          /* t1 = x0y0 + t1 + x1y1 */

 /* Algorithm succeeded set the return code to MP_OKAY */
 assert_hint(err == MP_OKAY); 

 return MP_OKAY;
}//mp_karatsuba_mul

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
