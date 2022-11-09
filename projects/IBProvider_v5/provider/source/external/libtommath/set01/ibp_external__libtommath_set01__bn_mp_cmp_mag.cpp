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

/* compare maginitude of two ints (unsigned) */
int mp_cmp_mag(const mp_int* const a,
               const mp_int* const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)

 /* compare based on # of non-zero digits */
 if(a->used > b->used)
  return MP_GT;

 if(a->used < b->used)
  return MP_LT;

 assert(a->used == b->used);

 /* alias for a */
 const mp_digit* tmpa = (a->dp + a->used);

 /* alias for b */
 const mp_digit* tmpb = (b->dp + a->used);

 /* compare based on digits  */
 while(tmpa != a->dp)
 {
  --tmpa;
  --tmpb;
  
  if((*tmpa) > (*tmpb))
   return MP_GT;

  if((*tmpa) < (*tmpb))
   return MP_LT;
 }//while

 return MP_EQ;
}//mp_cmp_mag

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
