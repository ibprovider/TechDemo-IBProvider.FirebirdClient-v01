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

/* computes the modular inverse via binary extended euclidean algorithm,
 * that is c = 1/a mod b
 *
 * Based on slow invmod except this is optimized for the case where b is
 * odd as per HAC Note 14.64 on pp. 610
 */
mp_err fast_mp_invmod(const mp_int* const a,
                      const mp_int* const b,
                      mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 /* 2. [modified] b must be odd   */
 if(mp_iseven(b) == 1)
  return MP_VAL;

 mp_err res;

 mp_int_x x, y, u, v, B, D;

 /* x == modulus, y == value to invert */
 if((res = mp_copy(b, &x)) != MP_OKAY)
  return res;

 /* we need y = |a| */
 if((res = mp_mod(a, b, &y)) != MP_OKAY)
  return res;

 /* 3. u=x, v=y, A=1, B=0, C=0,D=1 */
 if((res = mp_copy(&x, &u)) != MP_OKAY)
  return res;

 if((res = mp_copy(&y, &v)) != MP_OKAY)
  return res;

 if((res = mp_set_v2(&D, 1)) != MP_OKAY)
  return res;

 for(;;)
 {
  /* 4.  while u is even do */
  while(mp_iseven(&u) == 1)
  {
   /* 4.1 u = u/2 */
   if((res = mp_div_2(&u, &u)) != MP_OKAY)
    return res;

   /* 4.2 if B is odd then */
   if(mp_isodd(&B) == 1)
   {
    if((res = mp_sub(&B, &x, &B)) != MP_OKAY)
     return res;
   }//if

   /* B = B/2 */
   if((res = mp_div_2(&B, &B)) != MP_OKAY)
    return res;
  }//while

  /* 5.  while v is even do */
  while(mp_iseven(&v) == 1)
  {
   /* 5.1 v = v/2 */
   if((res = mp_div_2(&v, &v)) != MP_OKAY)
    return res;

   /* 5.2 if D is odd then */
   if(mp_isodd(&D) == 1)
   {
    /* D = (D-x)/2 */
    if((res = mp_sub(&D, &x, &D)) != MP_OKAY)
     return res;
   }

   /* D = D/2 */
   if((res = mp_div_2(&D, &D)) != MP_OKAY)
    return res;
  }//while

  /* 6.  if u >= v then */
  if(mp_cmp(&u, &v) != MP_LT)
  {
   /* u = u - v, B = B - D */
   if((res = mp_sub(&u, &v, &u)) != MP_OKAY)
    return res;

   if((res = mp_sub(&B, &D, &B)) != MP_OKAY)
    return res;
  }
  else
  {
   /* v - v - u, D = D - B */
   if((res = mp_sub(&v, &u, &v)) != MP_OKAY)
    return res;

   if((res = mp_sub(&D, &B, &D)) != MP_OKAY)
    return res;
  }//else

  /* if not zero goto step 4 */
  if(mp_iszero(&u) == 0)
   continue;

  break;
 }//for[ever]

 /* now a = C, b = D, gcd == g*v */

 /* if v != 1 then there is no inverse */
 if(mp_cmp_d(&v, 1) != MP_EQ)
  return MP_VAL;

 /* b is now the inverse */
 const mp_int_sign_type neg = a->sign;

 while(D.sign == MP_NEG)
 {
  if((res = mp_add(&D, b, &D)) != MP_OKAY)
   return res;
 }//while

 //[2016-05-24] Research. Can be used for code normalization ...
 assert_hint(a->sign == neg);

 mp_exch(&D, c);

 c->sign = neg;

 assert(res == MP_OKAY);

 //[2016-12-05] Research asserts
 DEBUG_CODE(mp_debug__check_int__total(c);)

 return MP_OKAY;
}//fast_mp_invmod

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
