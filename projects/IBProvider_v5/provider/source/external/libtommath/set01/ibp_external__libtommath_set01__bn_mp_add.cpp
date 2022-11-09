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

/* high level addition (handles signs) */
mp_err mp_add(const mp_int* const a,
              const mp_int* const b,
              mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 /* get sign of both inputs */
 const mp_int::sign_type sa = a->sign;
 const mp_int::sign_type sb = b->sign;

 /* handle two cases, not four */
 if(sa == sb)
 {
  /* both positive or both negative */
  /* add their magnitudes, copy the sign */
  c->sign = sa;

  return s_mp_add(a, b, c);
 }//if

 assert_hint(sa != sb);

 /* one positive, the other negative */
 /* subtract the one with the greater magnitude from */
 /* the one of the lesser magnitude.  The result gets */
 /* the sign of the one with the greater magnitude. */

 if(mp_cmp_mag(a, b) == MP_LT)
 {
  c->sign = sb;

  return s_mp_sub(b, a, c);
 }//if

 c->sign = sa;

 return s_mp_sub(a, b, c);
}//mp_add

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
