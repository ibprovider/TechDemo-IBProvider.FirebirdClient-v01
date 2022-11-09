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

/* Karatsuba squaring, computes b = a*a using three
 * half size squarings
 *
 * See comments of karatsuba_mul for details.  It
 * is essentially the same algorithm but merely
 * tuned to perform recursive squarings.
 */
mp_err mp_karatsuba_sqr(const mp_int* const a,
                        mp_int*       const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(b);)

 mp_err err;

 /* min # of digits */
 const mp_int::size_type c_minSrcSize = a->used;

 /* now divide in two */
 const mp_int::size_type B = (c_minSrcSize >> 1);

 assert(B <= a->used); 

 mp_int_x x0, x1, t1, t2, x0x0, x1x1;

 /* init copy all the temps */
 if((err = mp_grow(&x0, B)) != MP_OKAY)
  return err;

 if((err = mp_grow(&x1, a->used - B)) != MP_OKAY)
  return err;

 /* init temps */
 if((err = mp_grow(&t1, a->used * 2)) != MP_OKAY)
  return err;

 if((err = mp_grow(&t2, a->used * 2)) != MP_OKAY)
  return err;

 if((err = mp_grow(&x0x0, B * 2)) != MP_OKAY)
  return err;

 if((err = mp_grow(&x1x1, (a->used - B) * 2)) != MP_OKAY)
  return err;

 {
  const mp_digit* src = a->dp;

  /* now shift the digits */
  mp_digit* dst = x0.dp;

  for(mp_int::size_type x = 0; x < B; ++x, ++dst, ++src)
  {
   (*dst) = (*src);
  }

  dst = x1.dp;

  for(mp_int::size_type x = B; x < a->used; ++x, ++dst, ++src)
  {
   (*dst) = (*src);
  }
 }//local

 x0.used = B;
 x1.used = (a->used - B);

 mp_clamp(&x0);

 DEBUG_CODE(mp_debug__check_int__total(&x1);) //contains top digits of 'a'

 /* now calc the products x0*x0 and x1*x1 */
 if((err = mp_sqr(&x0, &x0x0)) != MP_OKAY)
  return err;           /* x0x0 = x0*x0 */

 if((err = mp_sqr(&x1, &x1x1)) != MP_OKAY)
  return err;           /* x1x1 = x1*x1 */

 /* now calc (x1+x0)**2 */
 if((err = s_mp_add(&x1, &x0, &t1)) != MP_OKAY)
  return err;           /* t1 = x1 - x0 */

 if((err = mp_sqr(&t1, &t1)) != MP_OKAY)
  return err;           /* t1 = (x1 - x0) * (x1 - x0) */

 /* add x0y0 */
 if((err = s_mp_add(&x0x0, &x1x1, &t2)) != MP_OKAY)
  return err;           /* t2 = x0x0 + x1x1 */

 if((err = s_mp_sub(&t1, &t2, &t1)) != MP_OKAY)
  return err;           /* t1 = (x1+x0)**2 - (x0x0 + x1x1) */

 /* shift by B */
 if((err = mp_lshd(&t1, B)) != MP_OKAY)
  return err;           /* t1 = (x0x0 + x1x1 - (x1-x0)*(x1-x0))<<B */

 if((err = mp_lshd(&x1x1, B * 2)) != MP_OKAY)
  return err;           /* x1x1 = x1x1 << 2*B */

 if((err = mp_add(&x0x0, &t1, &t1)) != MP_OKAY)
  return err;           /* t1 = x0x0 + t1 */

 if((err = mp_add(&t1, &x1x1, b)) != MP_OKAY)
  return err;           /* t1 = x0x0 + t1 + x1x1 */

 DEBUG_CODE(mp_debug__check_int__total(b);)

 assert_hint(err == MP_OKAY);

 return MP_OKAY;
}//mp_karatsuba_sqr

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
