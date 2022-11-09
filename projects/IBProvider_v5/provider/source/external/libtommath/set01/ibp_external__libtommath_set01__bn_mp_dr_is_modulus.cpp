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

/* determines if a number is a valid DR modulus */
int mp_dr_is_modulus(const mp_int* const a)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 /* must be at least two digits */
 if(a->used < 2)
  return 0;

 assert_hint(a->used >= 2);

 /* must be of the form b**k - a [a <= b] so all
  * but the first digit must be equal to -1 (mod b).
  */
 for(mp_int::size_type ix = 1; ix != a->used; ++ix)
 {
  if(a->dp[ix] != MP_MASK)
   return 0;
 }//for ix

 return 1;
}//mp_dr_is_modulus

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
