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

/* determines the setup value */
mp_err mp_reduce_2k_setup(const mp_int* const a,
                          mp_digit*     const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 assert(d);

 mp_err res;

 mp_int::size_type p = 0;

 if((res = mp_count_bits_v2(a, &p)) != MP_OKAY)
  return res;

 mp_int_x tmp;

 if((res = mp_2expt(&tmp, p)) != MP_OKAY)
  return res;

 if((res = s_mp_sub(&tmp, a, &tmp)) != MP_OKAY)
  return res;

 DEBUG_CODE(mp_debug__check_int__total(&tmp););

 //[2016-05-16] We expected it ...
 assert(tmp.used > 0);

 (*d) = tmp.dp[0];

 return MP_OKAY;
}//mp_reduce_2k_setup

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
