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

/* returns size of ASCII reprensentation */
mp_err mp_radix_size(const mp_int* const a,
                     int           const radix,
                     size_t*       const size)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 assert(size);

 mp_err res;

 (*size) = 0;

 /* special case for binary */
 if(radix == 2)
 {
  mp_int::size_type total_bits_in_a = 0;

  if((res = mp_count_bits_v2(a, &total_bits_in_a)) != MP_OKAY)
   return res;

  //! \todo
  //!  Add the overlow control

  (*size) = (total_bits_in_a + (a->sign == MP_NEG ? 1 : 0) + 1);

  return MP_OKAY;
 }//if

 /* make sure the radix is in range */
 if(radix < 2 || radix > 64)
 {
  return MP_VAL;
 }

 if(mp_iszero(a) == MP_YES)
 {
  (*size) = 2;

  return MP_OKAY;
 }//if

 /* digs is the digit count */
 size_t digs = 0;

 /* if it's negative add one for the sign */
 if(a->sign == MP_NEG)
 {
  ++digs;
 }

 /* init a copy of the input */
 mp_int_x t;

 if((res = mp_copy(a, &t)) != MP_OKAY)
  return res;

 /* force temp to positive */
 t.sign = MP_ZPOS;

 /* fetch out all of the digits */
 while(mp_iszero(&t) == MP_NO)
 {
  mp_digit d;

  if((res = mp_div_d(&t, (mp_digit)radix, &t, &d)) != MP_OKAY)
   return res;

  ++digs;
 }//while

 /* return digs + 1, the 1 is for the NULL byte that would be required. */
 (*size) = digs + 1;

 return MP_OKAY;
}//mp_radix_size

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
