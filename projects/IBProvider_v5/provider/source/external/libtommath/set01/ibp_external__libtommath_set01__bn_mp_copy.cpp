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

/* copy, b = a */
mp_err mp_copy(const mp_int* const a, mp_int* const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(b);)

 mp_err res;

 /* if dst == src do nothing */
 if(a == b)
 {
  return MP_OKAY;
 }//if

 /* grow dest */
 if(b->alloc < a->used)
 {
  if((res = mp_grow(b, a->used)) != MP_OKAY)
  {
   return res;
  }//if

  assert(a->used <= b->alloc);
 }//if

 /* zero b and copy the parameters over */
 {
  /* pointer aliases */

  /* source */
  const mp_digit*       tmpa = a->dp;
  const mp_digit* const enda = (tmpa + a->used);

  /* destination */
  mp_digit* tmpb = b->dp;

  /* copy all the digits */
  for(; tmpa != enda; ++tmpa, ++tmpb)
  {
   (*tmpb) = (*tmpa);
  }//for

  /* clear high digits */
  if(a->used < b->used)
  {
   const mp_digit* const endb = (b->dp + b->used);

   assert(tmpb < endb); 

   for(; tmpb != endb; ++tmpb)
   {
    (*tmpb) = 0;
   }//for
  }//if
 }//local

 /* copy used count and sign */
 b->used = a->used;

 b->sign = a->sign;

 DEBUG_CODE(mp_debug__check_int__total(b);)

 return MP_OKAY;
}//mp_copy

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
