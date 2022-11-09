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

/* stores a bignum as a ASCII string in a given radix (2..64)
 *
 * Stores upto maxlen-1 chars and always a NULL byte
 */
mp_err mp_toradix_n(const mp_int* const a,
                    char*               str,
                    mp_digit      const radix,
                    size_t              maxlen)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 CHECK_WRITE_TYPED_PTR(str,maxlen);

 assert(radix>=2);
 assert(radix<=_DIM_(mp_s_rmap));

 mp_err res;

 /* check range of the maxlen, radix */
 if(maxlen < 2 || radix < 2 || radix > 64)
 {
  return MP_VAL;
 }//if

 /* quick out if its zero */
 if(mp_iszero(a) == MP_YES)
 {
  str[0] = '0';
  str[1] = '\0';

  return MP_OKAY;
 }//if

 mp_int_x t;

 if((res = mp_copy(a, &t)) != MP_OKAY)
  return res;

 /* if it is negative output a - */

 if(t.sign == MP_NEG)
 {
  t.sign = MP_ZPOS;

  /* store the flag and mark the number as positive */
  (*str) = '-';

  ++str;

  /* subtract a char */
  --maxlen;
 }//if

 char* const _s = str;

 size_t digs = 0;

 while(mp_iszero(&t) == 0)
 {
  if(maxlen < 2 /* ch + end */)
  {
   /* no more room */
   assert(false);

   return MP_VAL;
  }//if

  --maxlen;
  
  mp_digit d;

  if((res = mp_div_d(&t, (mp_digit)radix, &t, &d)) != MP_OKAY)
   return res;

  assert(d < radix);

  assert(d < _DIM_(mp_s_rmap));

  (*str) = mp_s_rmap[d];

  ++str;

  ++digs;
 }//while

 /* reverse the digits of the string.  In this case _s points
  * to the first digit [exluding the sign] of the number
  */
 std::reverse(_s, _s + digs);

 /* append a NULL so the string is properly terminated */
 (*str) = '\0';

 return MP_OKAY;
}//mp_toradix_n

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
