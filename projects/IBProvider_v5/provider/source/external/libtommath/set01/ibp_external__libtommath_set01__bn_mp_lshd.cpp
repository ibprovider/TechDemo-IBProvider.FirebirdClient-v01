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

/* shift left a certain amount of digits */
mp_err mp_lshd(mp_int*          const a,
               mp_int_size_type const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 //[2016-05-15] Research assert
 assert((b == 0) || (b > 0));

 mp_err res;

 /* if its less than zero return */
 if(b == 0)
  return MP_OKAY;

 if(mp_iszero(a) == MP_YES)
 {
  return MP_OKAY;
 }

 assert(a->used > 0);

 /* grow to fit the new digits */
 if((res = mp_grow(a, a->used + b)) != MP_OKAY)
  return res;

 {
  /* increment the used by the shift amount then copy upwards */
  a->used += b;

  assert(a->used > b);

  /* top */
  mp_digit* top = (a->dp + a->used);

  /* base */
  const mp_digit* bottom = (top - b);

  while(bottom != a->dp)
  {
   --top;
   --bottom;

   (*top) = (*bottom);
  }//while

  assert(top != a->dp);
  assert(top == (a->dp + b));

  /* zero the lower digits */
  while(top != a->dp)
  {
   --top;
   
   (*top) = 0;
  }//while
 }//local

 DEBUG_CODE(mp_debug__check_int__total(a);)

 return MP_OKAY;
}//mp_lshd

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
