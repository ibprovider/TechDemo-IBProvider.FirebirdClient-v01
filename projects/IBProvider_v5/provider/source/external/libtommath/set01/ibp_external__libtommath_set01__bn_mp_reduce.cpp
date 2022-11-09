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

/* reduces x mod m, assumes 0 < x < m**2, mu is
 * precomputed via mp_reduce_setup.
 * From HAC pp.604 Algorithm 14.42
 */
mp_err mp_reduce(mp_int*       const x,
                 const mp_int* const m,
                 const mp_int* const mu)
{
 DEBUG_CODE(mp_debug__check_int__light(x);)
 DEBUG_CODE(mp_debug__check_int__total(m);)
 DEBUG_CODE(mp_debug__check_int__total(mu);)

 assert(m->used > 0); //see assumed info 0 < m**2

 mp_err res;

 mp_int_x q;

 /* q = x */
 if((res = mp_copy(x, &q)) != MP_OKAY)
  return res;

 /* q1 = x / b**(k-1)  */
 const mp_int::size_type um = m->used;

 assert(um > 0);

 mp_rshd(&q, um - 1);

 /* according to HAC this optimization is ok */
 if(um > (((mp_digit)1) << (MP_DIGIT_BIT - 1)))
 {
  if((res = mp_mul(&q, mu, &q)) != MP_OKAY)
   return res;
 }
 else
 {
 #ifdef BN_S_MP_MUL_HIGH_DIGS_C

  if((res = s_mp_mul_high_digs(&q, mu, &q, um)) != MP_OKAY)
   return res;

 #elif defined(BN_FAST_S_MP_MUL_HIGH_DIGS_C)

  if((res = fast_s_mp_mul_high_digs(&q, mu, &q, um)) != MP_OKAY)
   return res;

 #else

  return MP_VAL;

 #endif
 }//else

 /* q3 = q2 / b**(k+1) */
 assert(um > 0);
 
 mp_rshd(&q, um + 1);

 /* x = x mod b**(k+1), quick (no division) */
 if((res = mp_mod_2d(x, MP_DIGIT_BIT * (um + 1), x)) != MP_OKAY)
  return res;

 /* q = q * m mod b**(k+1), quick (no division) */
 if((res = s_mp_mul_digs(&q, m, &q, um + 1)) != MP_OKAY)
  return res;

 /* x = x - q */
 if((res = mp_sub(x, &q, x)) != MP_OKAY)
  return res;

 /* If x < 0, add b**(k+1) to it */
 if(mp_cmp_d(x, 0) == MP_LT)
 {
  if((res = mp_set_v2(&q, 1)) != MP_OKAY)
   return res;

  if((res = mp_lshd(&q, um + 1)) != MP_OKAY)
   return res;

  if((res = mp_add(x, &q, x)) != MP_OKAY)
   return res;
 }//if

 /* Back off if it's too big */
 while(mp_cmp(x, m) != MP_LT)
 {
  if((res = s_mp_sub(x, m, x)) != MP_OKAY)
   return res;
 }//while

 assert(res == MP_OKAY);

 return MP_OKAY;
}//mp_reduce

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
