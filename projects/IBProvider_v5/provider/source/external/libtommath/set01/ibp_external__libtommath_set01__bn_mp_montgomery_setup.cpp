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

/* setups the montgomery reduction stuff */
mp_err mp_montgomery_setup(const mp_int* const n,
                           mp_digit*     const rho)
{
 DEBUG_CODE(mp_debug__check_int__total(n);)

 assert(rho);

 /* fast inversion mod 2**k
  *
  * Based on the fact that
  *
  * XA = 1 (mod 2**n)  =>  (X(2-XA)) A = 1 (mod 2**2n)
  *                    =>  2*X*A - X*X*A*A = 1
  *                    =>  2*(1) - (1)     = 1
  */
 const mp_digit b = n->dp[0];

 if((b & 1) == 0)
 {
  return MP_VAL;
 }

 mp_digit x = ((((b + 2) & 4) << 1) + b); /* here x*a==1 mod 2**4 */

 x *= (2 - b * x);               /* here x*a==1 mod 2**8 */

#if !defined(MP_8BIT)
 x *= (2 - b * x);               /* here x*a==1 mod 2**16 */
#endif

#if defined(MP_64BIT) || !(defined(MP_8BIT) || defined(MP_16BIT))
 x *= (2 - b * x);               /* here x*a==1 mod 2**32 */
#endif

#ifdef MP_64BIT
 x *= (2 - b * x);               /* here x*a==1 mod 2**64 */
#endif

 /* rho = -1/m mod b */
 (*rho) = (mp_digit)(((mp_word)1 << ((mp_word)MP_DIGIT_BIT)) - x) & MP_MASK;

 return MP_OKAY;
}//mp_montgomery_setup

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
