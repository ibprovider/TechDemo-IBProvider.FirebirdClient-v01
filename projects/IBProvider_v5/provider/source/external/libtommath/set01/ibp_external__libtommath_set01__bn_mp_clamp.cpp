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

/* trim unused digits
 *
 * This is used to ensure that leading zero digits are
 * trimed and the leading "used" digit will be non-zero
 * Typically very fast.  Also fixes the sign if there
 * are no more leading digits
 */

void mp_clamp(mp_int* const a)
{
 DEBUG_CODE(mp_debug__check_int__light(a);)

 // decrease used while the most significant digit is zero.

 const mp_digit* p=(a->dp + a->used);

 for(;;)
 {
  if(p == a->dp)
  {
   a->used = 0;

   a->sign = MP_ZPOS;

   DEBUG_CODE(mp_debug__check_int__total(a);)

   return;
  }//if

  const mp_digit* const newP = (p - 1);

  if((*newP) != 0)
   break;

  p = newP;
 }//for[ever]

 assert(p != a->dp);

 assert(p >= a->dp);
 assert(p <= (a->dp + a->used));

 a->used = (p - a->dp);

 DEBUG_CODE(mp_debug__check_int__total(a);)
}//mp_clamp

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
