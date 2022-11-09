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

/* reduces a modulo n where n is of the form 2**p - d */
mp_err mp_reduce_2k(mp_int*       const a,
                    const mp_int* const n,
                    mp_digit      const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(n);)

 mp_err res;

 mp_int::size_type p = 0;

 if((res = mp_count_bits_v2(n, &p)) != MP_OKAY)
  return res;

 mp_int_x q;

 for(;;)
 {
  /* q = a/2**p, a = a mod 2**p */
  assert((p == 0) || (p > 0));

  if((res = mp_div_2d(a, p, &q, a)) != MP_OKAY)
   return res;

  if(d != 1)
  {
   /* q = q * d */
   if((res = mp_mul_d(&q, d, &q)) != MP_OKAY)
    return res;
  }//if

  /* a = a + q */
  if((res = s_mp_add(a, &q, a)) != MP_OKAY)
   return res;

  if(mp_cmp_mag(a, n) != MP_LT)
  {
   if((res = s_mp_sub(a, n, a)) != MP_OKAY)
    return res;

   continue;
  }//if

  break;
 }//for[ever]

 assert_hint(res == MP_OKAY);

 return MP_OKAY;
}//mp_reduce_2k

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
