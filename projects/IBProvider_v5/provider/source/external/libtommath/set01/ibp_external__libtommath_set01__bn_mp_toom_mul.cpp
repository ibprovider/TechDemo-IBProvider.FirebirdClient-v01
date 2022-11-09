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

/* multiplication using the Toom-Cook 3-way algorithm
 *
 * Much more complicated than Karatsuba but has a lower
 * asymptotic running time of O(N**1.464).  This algorithm is
 * only particularly useful on VERY large inputs
 * (we're talking 1000s of digits here...).
*/
mp_err mp_toom_mul(const mp_int* const a,
                   const mp_int* const b,
                   mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 mp_err res;

 mp_int_x w0, w1, w2, w3, w4, tmp1, tmp2, a0, a1, a2, b0, b1, b2;

 /* B */
 mp_int::size_type const B = (MIN(a->used, b->used) / 3);

 /* a = a2 * B**2 + a1 * B + a0 */
 if((res = mp_mod_2d(a, MP_DIGIT_BIT * B, &a0)) != MP_OKAY)
  return res;

 if((res = mp_copy(a, &a1)) != MP_OKAY)
  return res;

 mp_rshd(&a1, B);

 if((res = mp_mod_2d(&a1, MP_DIGIT_BIT * B, &a1)) != MP_OKAY)
  return res;

 if((res = mp_copy(a, &a2)) != MP_OKAY)
  return res;

 mp_rshd(&a2, B * 2);

 /* b = b2 * B**2 + b1 * B + b0 */
 if((res = mp_mod_2d(b, MP_DIGIT_BIT * B, &b0)) != MP_OKAY)
  return res;

 if((res = mp_copy(b, &b1)) != MP_OKAY)
  return res;

 mp_rshd(&b1, B);

 if((res = mp_mod_2d(&b1, MP_DIGIT_BIT * B, &b1)) != MP_OKAY)
  return res;

 if((res = mp_copy(b, &b2)) != MP_OKAY)
  return res;

 mp_rshd(&b2, B * 2);

 /* w0 = a0*b0 */
 if((res = mp_mul(&a0, &b0, &w0)) != MP_OKAY)
  return res;

 /* w4 = a2 * b2 */
 if((res = mp_mul(&a2, &b2, &w4)) != MP_OKAY)
  return res;

 /* w1 = (a2 + 2(a1 + 2a0))(b2 + 2(b1 + 2b0)) */
 if((res = mp_mul_2(&a0, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp1, &a1, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_mul_2(&tmp1, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp1, &a2, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_mul_2(&b0, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp2, &b1, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_mul_2(&tmp2, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp2, &b2, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_mul(&tmp1, &tmp2, &w1)) != MP_OKAY)
  return res;

 /* w3 = (a0 + 2(a1 + 2a2))(b0 + 2(b1 + 2b2)) */
 if((res = mp_mul_2(&a2, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp1, &a1, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_mul_2(&tmp1, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp1, &a0, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_mul_2(&b2, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp2, &b1, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_mul_2(&tmp2, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp2, &b0, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_mul(&tmp1, &tmp2, &w3)) != MP_OKAY)
  return res;

 /* w2 = (a2 + a1 + a0)(b2 + b1 + b0) */
 if((res = mp_add(&a2, &a1, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp1, &a0, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&b2, &b1, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp2, &b0, &tmp2)) != MP_OKAY)
  return res;

 if((res = mp_mul(&tmp1, &tmp2, &w2)) != MP_OKAY)
  return res;

 /* now solve the matrix

    0  0  0  0  1
    1  2  4  8  16
    1  1  1  1  1
    16 8  4  2  1
    1  0  0  0  0

    using 12 subtractions, 4 shifts,
           2 small divisions and 1 small multiplication
  */

  /* r1 - r4 */
 if((res = mp_sub(&w1, &w4, &w1)) != MP_OKAY)
  return res;

 /* r3 - r0 */
 if((res = mp_sub(&w3, &w0, &w3)) != MP_OKAY)
  return res;

 /* r1/2 */
 if((res = mp_div_2(&w1, &w1)) != MP_OKAY)
  return res;

 /* r3/2 */
 if((res = mp_div_2(&w3, &w3)) != MP_OKAY)
  return res;

 /* r2 - r0 - r4 */
 if((res = mp_sub(&w2, &w0, &w2)) != MP_OKAY)
  return res;

 if((res = mp_sub(&w2, &w4, &w2)) != MP_OKAY)
  return res;

 /* r1 - r2 */
 if((res = mp_sub(&w1, &w2, &w1)) != MP_OKAY)
  return res;

 /* r3 - r2 */
 if((res = mp_sub(&w3, &w2, &w3)) != MP_OKAY)
  return res;

 /* r1 - 8r0 */
 if((res = mp_mul_2d(&w0, 3, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_sub(&w1, &tmp1, &w1)) != MP_OKAY)
  return res;

 /* r3 - 8r4 */
 if((res = mp_mul_2d(&w4, 3, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_sub(&w3, &tmp1, &w3)) != MP_OKAY)
  return res;

 /* 3r2 - r1 - r3 */
 if((res = mp_mul_d(&w2, 3, &w2)) != MP_OKAY)
  return res;

 if((res = mp_sub(&w2, &w1, &w2)) != MP_OKAY)
  return res;

 if((res = mp_sub(&w2, &w3, &w2)) != MP_OKAY)
  return res;

 /* r1 - r2 */
 if((res = mp_sub(&w1, &w2, &w1)) != MP_OKAY)
  return res;

 /* r3 - r2 */
 if((res = mp_sub(&w3, &w2, &w3)) != MP_OKAY)
  return res;

 /* r1/3 */
 if((res = mp_div_3(&w1, &w1, NULL)) != MP_OKAY)
  return res;

 /* r3/3 */
 if((res = mp_div_3(&w3, &w3, NULL)) != MP_OKAY)
  return res;

 /* at this point shift W[n] by B*n */
 if((res = mp_lshd(&w1, 1 * B)) != MP_OKAY)
  return res;

 if((res = mp_lshd(&w2, 2 * B)) != MP_OKAY)
  return res;

 if((res = mp_lshd(&w3, 3 * B)) != MP_OKAY)
  return res;

 if((res = mp_lshd(&w4, 4 * B)) != MP_OKAY)
  return res;

 if((res = mp_add(&w0, &w1, c)) != MP_OKAY)
  return res;

 if((res = mp_add(&w2, &w3, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&w4, &tmp1, &tmp1)) != MP_OKAY)
  return res;

 if((res = mp_add(&tmp1, c, c)) != MP_OKAY)
  return res;

 assert_hint(res == MP_OKAY);

 DEBUG_CODE(mp_debug__check_int__total(c);)

 return MP_OKAY;
}//mp_toom_mul

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
