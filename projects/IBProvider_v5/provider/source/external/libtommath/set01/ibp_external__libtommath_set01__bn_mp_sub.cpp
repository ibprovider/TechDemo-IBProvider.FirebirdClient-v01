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

/* high level subtraction (handles signs) */
mp_err mp_sub(const mp_int* const a,
              const mp_int* const b,
              mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 mp_int::sign_type const sa = a->sign;
 mp_int::sign_type const sb = b->sign;

 if(sa != sb)
 {
  /* subtract a negative from a positive, OR */
  /* subtract a positive from a negative. */
  /* In either case, ADD their magnitudes, */
  /* and use the sign of the first number. */
  c->sign = sa;

  return s_mp_add(a, b, c);
 }//if

 /* subtract a positive from a positive, OR */
 /* subtract a negative from a negative. */
 /* First, take the difference between their */
 /* magnitudes, then... */
 if(mp_cmp_mag(a, b) != MP_LT)
 {
  /* Copy the sign from the first */
  c->sign = sa;

  /* The first has a larger or equal magnitude */
  return s_mp_sub(a, b, c);
 }//if

 /* The result has the *opposite* sign from */
 /* the first number. */
 c->sign = (sa == MP_ZPOS) ? MP_NEG : MP_ZPOS;

 /* The second has a larger magnitude */
 return s_mp_sub(b, a, c);
}//mp_sub

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
