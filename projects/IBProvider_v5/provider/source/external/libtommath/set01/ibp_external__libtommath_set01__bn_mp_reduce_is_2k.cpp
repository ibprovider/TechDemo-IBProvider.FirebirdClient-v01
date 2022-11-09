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

/* determines if mp_reduce_2k can be used */
int mp_reduce_is_2k(const mp_int* const a)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 if(a->used == 0)
 {
  return MP_NO;
 }//if

 assert_hint(a->used > 0);

 if(a->used == 1)
 {
  return MP_YES;
 }//if

 assert_hint(a->used > 1);

 mp_int::size_type N = (a->used - 1);

 assert((N == 0) || (N > 0)); // N>=0

 for(mp_int::size_type iw = 1; iw != N; ++iw)
 {
  assert(iw < N);

  assert(a->dp[iw] <= MP_MASK);

  if(a->dp[iw] != MP_MASK)
   return MP_NO;
 }//if

 assert_hint(a->used > 1);

 assert(a->dp[N] != 0);

 for(mp_digit last_d = a->dp[N]; last_d != 0; last_d = (last_d >> 1))
 {
  if((last_d & 1) == 0)
   return MP_NO;
 }//for m

 return MP_YES;
}//mp_reduce_is_2k

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
