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

/* b = a*2 */
mp_err mp_mul_2(const mp_int* const a,
                mp_int*       const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(b);)

 mp_err res;

 if(mp_iszero(a))
 {
  mp_zero(b);

  return MP_OKAY;
 }//if

 /* grow to accomodate result */
 if((res = mp_grow(b, a->used + 1)) != MP_OKAY)
  return res;

 const mp_int::size_type oldused = b->used;

 b->used = a->used;

 {
  /* alias for source */
  const mp_digit*      tmpa = a->dp;
  const mp_digit* const _ea = (a->dp + a->used);

  /* alias for dest */
  mp_digit* tmpb = b->dp;

  /* carry */
  mp_digit r = 0;

  for(; tmpa != _ea; ++tmpa, ++tmpb)
  {
   /* get what will be the *next* carry bit from the
    * MSB of the current digit
    */
   const mp_digit rr = ((*tmpa) >> ((mp_digit)(MP_DIGIT_BIT - 1)));

   /* now shift up this digit, add in the carry [from the previous] */
   (*tmpb) = (((*tmpa << ((mp_digit)1)) | r) & MP_MASK);

   /* copy the carry that would be from the source
    * digit into the next iteration
    */
   r = rr;
  }//for tmpa, tmpb

  assert(tmpb == (b->dp + b->used));

  /* new leading digit? */
  if(r != 0)
  {
   /* add a MSB which is always 1 at this point */
   (*tmpb) = 1;
  
   ++(b->used);
  }//if

  /* now zero any excess digits on the destination
   * that we didn't write to
   */
  if(b->used < oldused)
  {
   assert(oldused <= b->alloc);

   std::fill(b->dp + b->used, b->dp + oldused, 0);
  }//if
 }//local

 b->sign = a->sign;

 DEBUG_CODE(mp_debug__check_int__total(b);)

 return MP_OKAY;
}//mp_mul_2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
