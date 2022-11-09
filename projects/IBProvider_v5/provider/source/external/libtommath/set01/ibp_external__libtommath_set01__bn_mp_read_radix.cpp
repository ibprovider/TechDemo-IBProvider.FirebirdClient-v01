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

/* read a string [ASCII] in a given radix */
mp_err mp_read_radix(mp_int*     const a,
                     const char*       str,
                     mp_digit    const radix)
{
 DEBUG_CODE(mp_debug__check_int__light(a);)
 assert(str);
 assert(radix >= 2);

 mp_err res;

 /* zero the digit bignum */
 mp_zero(a);

 /* make sure the radix is ok */
 if(radix < 2 || radix > _DIM_(mp_s_rmap))
 {
  return MP_VAL;
 }

 // if the leading digit is a
 // minus set the sign to negative.

 mp_int_sign_type neg;

 if((*str) == '-')
 {
  ++str;

  neg = MP_NEG;
 }
 else
 {
  neg = MP_ZPOS;
 }

 /* set the integer to the default of zero */
 mp_zero(a);

 /* process each digit of the string */
 while(*str)
 {
  /* if the radix < 36 the conversion is case insensitive
   * this allows numbers like 1AB and 1ab to represent the same  value
   * [e.g. in hex]
   */

  //
  // [2021-02-25] switch from toupper to mp_upper7
  //
  const char ch = (char)((radix < 36) ? mp_upper7(*str) : *str);

  mp_digit y;

  for(y = 0; y < _DIM_(mp_s_rmap); y++)
  {
   if(ch == mp_s_rmap[y])
   {
    break;
   }
  }//for y

  /* if the char was found in the map
   * and is less than the given radix add it
   * to the number, otherwise exit the loop.
   */
  if(!(y < radix))
  {
   assert(false);

   return MP_VAL;
  }//if

  if((res = mp_mul_d(a, (mp_digit)radix, a)) != MP_OKAY)
   return res;

  if((res = mp_add_d(a, y, a)) != MP_OKAY)
   return res;

  ++str;
 }//while

 /* set the sign only if a != 0 */
 if(mp_iszero(a) != 1)
 {
  a->sign = neg;
 }//if

 return MP_OKAY;
}//mp_read_radix

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
