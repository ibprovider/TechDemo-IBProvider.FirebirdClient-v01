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

/* hac 14.61, pp608 */
mp_err mp_invmod_slow(const mp_int* const a,
                      const mp_int* const b,
                      mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 /* b cannot be negative */
 if(b->sign == MP_NEG || mp_iszero(b) == 1)
 {
  return MP_VAL;
 }

 //-----------------------------------------
 mp_err res;

 mp_int_x x, y, u, v, A, B, C, D;

 /* x = a, y = b */
 if((res = mp_mod(a, b, &x)) != MP_OKAY)
  return res;

 if((res = mp_copy(b, &y)) != MP_OKAY)
  return res;

 /* 2. [modified] if x,y are both even then return an error! */
 if(mp_iseven(&x) == 1 && mp_iseven(&y) == 1)
  return MP_VAL;

 /* 3. u=x, v=y, A=1, B=0, C=0,D=1 */
 if((res = mp_copy(&x, &u)) != MP_OKAY)
  return res;

 if((res = mp_copy(&y, &v)) != MP_OKAY)
  return res;

 if((res = mp_set_v2(&A, 1)) != MP_OKAY)
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

   /* 4.2 if A or B is odd then */
   if(mp_isodd(&A) == 1 || mp_isodd(&B) == 1)
   {
    /* A = (A+y)/2, B = (B-x)/2 */
    if((res = mp_add(&A, &y, &A)) != MP_OKAY)
     return res;

    if((res = mp_sub(&B, &x, &B)) != MP_OKAY)
     return res;
   }//if

   /* A = A/2, B = B/2 */
   if((res = mp_div_2(&A, &A)) != MP_OKAY)
    return res;

   if((res = mp_div_2(&B, &B)) != MP_OKAY)
    return res;
  }//while

  /* 5.  while v is even do */
  while(mp_iseven(&v) == 1)
  {
   /* 5.1 v = v/2 */
   if((res = mp_div_2(&v, &v)) != MP_OKAY)
    return res;

   /* 5.2 if C or D is odd then */
   if(mp_isodd(&C) == 1 || mp_isodd(&D) == 1)
   {
    /* C = (C+y)/2, D = (D-x)/2 */
    if((res = mp_add(&C, &y, &C)) != MP_OKAY)
     return res;

    if((res = mp_sub(&D, &x, &D)) != MP_OKAY)
     return res;
   }//if

   /* C = C/2, D = D/2 */
   if((res = mp_div_2(&C, &C)) != MP_OKAY)
    return res;

   if((res = mp_div_2(&D, &D)) != MP_OKAY)
    return res;
  }//while

  /* 6.  if u >= v then */
  if (mp_cmp(&u, &v) != MP_LT)
  {
   /* u = u - v, A = A - C, B = B - D */
   if((res = mp_sub(&u, &v, &u)) != MP_OKAY)
    return res;

   if((res = mp_sub(&A, &C, &A)) != MP_OKAY)
    return res;

   if((res = mp_sub(&B, &D, &B)) != MP_OKAY)
    return res;
  }
  else
  {
   /* v - v - u, C = C - A, D = D - B */
   if((res = mp_sub(&v, &u, &v)) != MP_OKAY)
    return res;

   if((res = mp_sub(&C, &A, &C)) != MP_OKAY)
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

 /* if its too low */
 while(mp_cmp_d(&C, 0) == MP_LT)
 {
  if((res = mp_add(&C, b, &C)) != MP_OKAY)
   return res;
 }//while

 /* too big */
 while(mp_cmp_mag(&C, b) != MP_LT)
 {
  if((res = mp_sub(&C, b, &C)) != MP_OKAY)
   return res;
 }//while

 /* C is now the inverse */
 mp_exch(&C, c);

 assert(res == MP_OKAY);

 return MP_OKAY;
}//mp_invmod_slow

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
