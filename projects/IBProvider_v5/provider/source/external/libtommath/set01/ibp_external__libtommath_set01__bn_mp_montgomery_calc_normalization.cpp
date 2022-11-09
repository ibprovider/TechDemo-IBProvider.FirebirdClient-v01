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

/*
 * shifts with subtractions when the result is greater than b.
 *
 * The method is slightly modified to shift B unconditionally upto just under
 * the leading bit of b.  This saves alot of multiple precision shifting.
 */
mp_err mp_montgomery_calc_normalization(mp_int*       const a,
                                        const mp_int* const b)
{
 DEBUG_CODE(mp_debug__check_int__light(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)

 mp_err res;

 /* how many bits of last digit does b use */
 mp_int::size_type total_bits_in_b = 0;

 if((res = mp_count_bits_v2(b, &total_bits_in_b)) != MP_OKAY)
  return res;

 mp_int::size_type bits = (total_bits_in_b % MP_DIGIT_BIT);

 assert(bits == 0 || bits > 0); // bits >= 0
 assert_hint(bits < MP_DIGIT_BIT);
  
 if(b->used > 1)
 {
  if((res = mp_2expt(a, (b->used - 1) * MP_DIGIT_BIT + bits - 1)) != MP_OKAY)
  {
   return res;
  }
 }
 else
 {
  if((res = mp_set_v2(a, 1)) != MP_OKAY)
  {
   return res;
  }

  bits = 1;
 }//else

 assert(bits == 0 || bits > 0); // bits >= 0

 assert_s(MP_DIGIT_BIT>1);

 assert_hint(bits < MP_DIGIT_BIT);

 /* now compute C = A * B mod b */

 //for(int x = bits - 1; x < (int)MP_DIGIT_BIT; x++)

 for(mp_int::size_type x = bits, _c = (MP_DIGIT_BIT + 1); x != _c; ++x)
 {
  assert_hint(x < _c);

  if((res = mp_mul_2(a, a)) != MP_OKAY)
   return res;

  if(mp_cmp_mag(a, b) != MP_LT)
  {
   if((res = s_mp_sub(a, b, a)) != MP_OKAY)
    return res;
  }//if
 }//for x

 DEBUG_CODE(mp_debug__check_int__total(a);)

 return MP_OKAY;
}//mp_montgomery_calc_normalization

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
