////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath_private.h"
#include <structure/t_limits.h>

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

/* returns the number of bits in an int */
mp_err mp_count_bits_v2(const mp_int*     const a,
                        mp_int_size_type* const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 assert(c);

 (*c) = 0;

 /* shortcut */
 if(a->used == 0)
  return MP_OKAY;

 assert_hint(a->used > 0);

 /* get number of digits and add that */
 mp_int::size_type const n = (a->used - 1);

 if((structure::t_numeric_limits<mp_int::size_type>::max_value() / MP_DIGIT_BIT) < n)
 {
  //[2016-05-27] Bingo!
  assert(false);

  return MP_VAL;
 }//if

 mp_int::size_type r = (n * MP_DIGIT_BIT);

 /* take the last digit and count the bits in it */
 for(mp_digit q = a->dp[n]; q != 0; q = (q / 2))
 {
  assert_hint(q > 0);

  if(r == structure::t_numeric_limits<mp_int::size_type>::max_value())
  {
   //[2016-05-27] Bingo!
   assert(false);

   return MP_VAL;
  }//if

  ++r;
 }//for q

 (*c) = r;

 return MP_OKAY;
}//mp_count_bits_v2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
