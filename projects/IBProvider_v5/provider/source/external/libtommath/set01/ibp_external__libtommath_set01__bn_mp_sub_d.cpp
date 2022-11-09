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

/* single digit subtraction */
mp_err mp_sub_d(const mp_int* const a,
                mp_digit      const b,
                mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 assert(b <= MP_DIGIT_MAX);

 mp_err res;

 /* if a is negative just do an unsigned
  * addition [with fudged signs]
  */

 if(b == 0)
 {
  return mp_copy(a, c);
 }//if b == 0

 assert_hint(b > 0);

 mp_int::size_type const oldused = c->used;

 if(a->sign == MP_NEG)
 {
  if((res = mp_grow(c, a->used + 1)) != MP_OKAY)
   return res;

  // add digit, after this we're propagating
  // the carry.

  /* source alias */
  const mp_digit* tmpa = a->dp;

  const mp_digit* _ea = (a->dp + a->used);

  /* destination alias */
  mp_digit* tmpc = c->dp;

  mp_digit mu = b;
  
  /* now handle rest of the digits */
  for(; tmpa != _ea; ++tmpa, ++tmpc)
  {
   (*tmpc) = (*tmpa + mu);

   mu = ((*tmpc) >> MP_DIGIT_BIT);

   (*tmpc) &= MP_MASK;
  }//for

  /* set final carry */

  (*tmpc) = mu;

  /* setup size */
  c->used = (a->used + 1);

  /* sign always positive */
  c->sign = MP_NEG;
 }//if
 else 
 if(a->used == 0) /* if a <= b simply fix the single digit */
 {
  if((res = mp_grow(c, 1)) != MP_OKAY)
   return res;

  assert(c->alloc > 0);
  assert(c->alloc >= oldused);

  c->dp[0] = b;

  /* negative/1digit */
  c->sign = MP_NEG;
  c->used = 1;
 }
 else
 if(a->used == 1 && a->dp[0] <= b)
 {
  if(b == a->dp[0])
  {
   mp_zero(c);

   return MP_OKAY;
  }//if

  if((res = mp_grow(c, 1)) != MP_OKAY)
   return res;

  assert(c->alloc > 0);
  assert(c->alloc >= oldused);

  c->dp[0] = (b - a->dp[0]);

  /* negative/1digit */
  c->sign = MP_NEG;
  c->used = 1;
 }
 else
 {
  assert_hint(a->used > 0);

  if((res = mp_grow(c, a->used)) != MP_OKAY)
   return res;

  assert(c->alloc >= a->used);
  assert(c->alloc >= oldused);

  /* positive/size */
  c->sign = MP_ZPOS;
  c->used = a->used;

  /* subtract first digit */
  mp_digit mu = b;

  const mp_digit* tmpa = a->dp;

  const mp_digit* const _ea = (a->dp + a->used);

  mp_digit* tmpc = c->dp;

  for(; tmpa != _ea; ++tmpc, ++tmpa)
  {
   (*tmpc) = (*tmpa) - mu;

   mu = (*tmpc) >> (sizeof(mp_digit) * CHAR_BIT - 1);

   assert((mu == 0) || (mu == 1));

   (*tmpc) &= MP_MASK;
  }//for
 }//else

 /* zero excess digits */
 assert(c->alloc >= oldused);

 if(c->used < oldused)
 {
  assert(oldused <= c->alloc);

  std::fill(c->dp + c->used, c->dp + oldused, 0);
 }//if

 mp_clamp(c);

 return MP_OKAY;
}//mp_sub_d

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
