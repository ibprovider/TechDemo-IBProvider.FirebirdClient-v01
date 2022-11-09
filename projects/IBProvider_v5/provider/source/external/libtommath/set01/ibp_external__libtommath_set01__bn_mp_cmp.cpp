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

/* compare two ints (signed)*/
int mp_cmp (const mp_int* const a,
            const mp_int* const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a));
 DEBUG_CODE(mp_debug__check_int__total(b));

 /* compare based on sign */
 if(a->sign != b->sign)
 {
  if(a->sign == MP_NEG)
   return MP_LT;
 
  return MP_GT;
 }//if

 /* compare digits */
 if(a->sign == MP_NEG)
 {
  /* if negative compare opposite direction */
  return mp_cmp_mag(b, a);
 }//if

 return mp_cmp_mag(a, b);
}//mp_cmp

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
