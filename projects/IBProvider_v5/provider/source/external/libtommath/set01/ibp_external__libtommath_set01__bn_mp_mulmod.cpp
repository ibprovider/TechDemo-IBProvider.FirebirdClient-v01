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

/* d = a * b (mod c) */
mp_err mp_mulmod(const mp_int* const a,
                 const mp_int* const b,
                 const mp_int* const c,
                 mp_int*       const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__total(c);)
 DEBUG_CODE(mp_debug__check_int__light(d);)

 mp_err res;

 mp_int_x t;

 if((res = mp_mul(a, b, &t)) != MP_OKAY)
  return res;

 return mp_mod(&t, c, d);
}//mp_mulmod

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
