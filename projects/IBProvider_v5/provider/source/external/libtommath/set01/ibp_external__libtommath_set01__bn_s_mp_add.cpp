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

/* low level addition, based on HAC pp.594, Algorithm 14.7 */
mp_err s_mp_add(const mp_int* const a,
                const mp_int* const b,
                mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 mp_err res;

 const mp_int* x;

 mp_int::size_type min;
 mp_int::size_type max;

 /* find sizes, we let |a| <= |b| which means we have to sort
  * them.  "x" will point to the input with the most digits
  */
 if(a->used > b->used)
 {
  min = b->used;
  max = a->used;
  x   = a;
 }
 else
 {
  min = a->used;
  max = b->used;
  x   = b;
 }//else

 assert(min <= max);

 /* init result */
 if((res = mp_grow(c, max + 1)) != MP_OKAY)
  return res;

 /* get old used digit count and set new one */
 const mp_int::size_type oldused = c->used;

 c->used = (max + 1);

 {
  /* alias for digit pointers */

  /* first input */
  const mp_digit* tmpa = a->dp;

  /* second input */
  const mp_digit* tmpb = b->dp;

  /* destination */
  mp_digit* tmpc = c->dp;

  /* zero the carry */
  mp_digit u = 0;

  mp_int::size_type i;

  for(i = 0; i != min; ++i, ++tmpa, ++tmpb, ++tmpc)
  {
   assert(i < min);

   /* Compute the sum at one digit, T[i] = A[i] + B[i] + U */
   (*tmpc) = ((*tmpa) + (*tmpb) + u);

   /* U = carry bit of T[i] */
   u = (*tmpc >> ((mp_digit)MP_DIGIT_BIT));

   /* take away carry bit from T[i] */
   (*tmpc) &= MP_MASK;
  }//for

  assert(i == min);

  /* now copy higher words if any, that is in A+B
   * if A or B has more digits add those in
   */
  for(; i != max; ++i, ++tmpc)
  {
   assert(i < max);

   /* T[i] = X[i] + U */
   (*tmpc) = (x->dp[i] + u);

   /* U = carry bit of T[i] */
   u = (*tmpc >> ((mp_digit)MP_DIGIT_BIT));

   /* take away carry bit from T[i] */
   (*tmpc) &= MP_MASK;
  }//for

  assert(i == max);

  /* add carry */
  assert(u <= MP_DIGIT_MAX);

  (*tmpc) = u;
 }//local

 /* clear digits above oldused */
 if(c->used < oldused)
 {
  assert(oldused <= c->alloc);

  std::fill(c->dp + c->used, c->dp + oldused, 0);
 }//if

 mp_clamp(c);

 return MP_OKAY;
}//s_mp_add

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
