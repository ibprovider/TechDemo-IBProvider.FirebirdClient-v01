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

/* low level subtraction (assumes |a| > |b|), HAC pp.595 Algorithm 14.9 */
mp_err s_mp_sub(const mp_int* const a,
                const mp_int* const b,
                mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 assert(b->used <= a->used);

 mp_err res;

 /* find sizes */
 const mp_int::size_type min = b->used;
 const mp_int::size_type max = a->used;

 assert(min <= max);

 /* init result */
 if((res = mp_grow(c, max)) != MP_OKAY)
  return res;

 const mp_int::size_type oldused = c->used;

 c->used = max;

 {
  /* alias for digit pointers */
  const mp_digit* tmpa = a->dp;
  const mp_digit* tmpb = b->dp;

  mp_digit* tmpc = c->dp;

  /* set carry to zero */
  mp_digit u = 0;

  mp_int::size_type i;

  for(i = 0; i != min; ++i, ++tmpa, ++tmpb, ++tmpc)
  {
   assert(i < min);

   /* T[i] = A[i] - B[i] - U */
   (*tmpc) = ((*tmpa) - (*tmpb) - u);

   /* U = carry bit of T[i]
    * Note this saves performing an AND operation since
    * if a carry does occur it will propagate all the way to the
    * MSB.  As a result a single shift is enough to get the carry
    */
   u = ((*tmpc) >> ((mp_digit)(CHAR_BIT * sizeof(mp_digit) - 1)));

   /* Clear carry from T[i] */
   (*tmpc) &= MP_MASK;
  }//for i

  assert(i == min);

  /* now copy higher words if any, e.g. if A has more digits than B  */
  for(; i != max; ++i, ++tmpc, ++tmpa)
  {
   assert(i < max);

   /* T[i] = A[i] - U */
   (*tmpc) = (*tmpa) - u;

   /* U = carry bit of T[i] */
   u = ((*tmpc) >> ((mp_digit)(CHAR_BIT * sizeof(mp_digit) - 1)));

   /* Clear carry from T[i] */
   (*tmpc) &= MP_MASK;
  }//for i

  assert(i == max);

  assert(u == 0);
 }//local

 /* clear digits above used (since we may not have grown result above) */
 if(c->used < oldused)
 {
  assert(oldused <= c->alloc);

  std::fill(c->dp + c->used, c->dp + oldused, 0);
 }//if

 mp_clamp(c);

 return MP_OKAY;
}//s_mp_sub

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
