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

/* compare a digit */
int mp_cmp_d(const mp_int* const a,
             mp_digit      const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a));

 assert((b == 0) || (b > 0));
 assert(b <= MP_DIGIT_MAX);

 if(a->used == 0)
 {
  if(b > 0)
   return MP_LT;

  assert(b == 0);

  return MP_EQ;
 }//if

 assert_hint(a->used > 0);

 /* compare based on sign */
 if(a->sign == MP_NEG)
  return MP_LT;

 /* compare based on magnitude */
 if(a->used > 1)
  return MP_GT;

 /* compare the only digit of a to b */
 if(a->dp[0] > b)
  return MP_GT;

 if(a->dp[0] < b)
  return MP_LT;

 return MP_EQ;
}//mp_cmp_d

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
