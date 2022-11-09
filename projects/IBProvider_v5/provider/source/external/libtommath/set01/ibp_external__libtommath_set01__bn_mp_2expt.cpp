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

/* computes a = 2**b
 *
 * Simple algorithm which zeroes the int, grows it then just sets one bit
 * as required.
 */
mp_err mp_2expt(mp_int*          const a,
                mp_int_size_type const b)
{
 DEBUG_CODE(mp_debug__check_int__light(a);)

 //[2016-05-19] It expected ...
 assert((b == 0) || (b > 0));

 mp_err res;

 /* zero a as per default */
 mp_zero(a);

 /* grow a to accomodate the single bit */
 const mp_int::size_type iLast = (b / MP_DIGIT_BIT);

 const mp_int::size_type newSize = (iLast + 1);

 if((res = mp_grow(a, newSize)) != MP_OKAY)
  return res;

 /* set the used count of where the bit will go */
 a->used = newSize;

 /* put the single bit in its place */
 a->dp[iLast] = (((mp_digit)1) << (b % MP_DIGIT_BIT));

 DEBUG_CODE(mp_debug__check_int__total(a);)

 return MP_OKAY;
}//mp_2expt

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
