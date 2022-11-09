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

/* divide by three (based on routine from MPI and the GMP manual) */
mp_err mp_div_3(const mp_int* const a,
                mp_int*       const c,
                mp_digit*     const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

#ifndef NDEBUG
 if(c)
  mp_debug__check_int__light(c);
#endif

 mp_err res;

 mp_int_x q;

 if((res = mp_grow(&q, a->used)) != MP_OKAY)
  return res;

 assert_hint(res == MP_OKAY);

 q.used = a->used;
 q.sign = a->sign;

 /* b = 2**MP_DIGIT_BIT / 3 */
 const mp_digit b = (((mp_word)1) << ((mp_word)MP_DIGIT_BIT)) / ((mp_word)3);

 mp_word w = 0;

 for(mp_int::size_type ix = a->used; ix > 0;)
 {
  --ix;

  assert((ix == 0) || (ix > 0));
  assert(ix < a->used);

  w = (w << ((mp_word)MP_DIGIT_BIT)) | ((mp_word)a->dp[ix]);

  mp_word t;

  if(w >= 3)
  {
   /* multiply w by [1/3] */
   t = (w * ((mp_word)b)) >> ((mp_word)MP_DIGIT_BIT);

   /* now subtract 3 * [w/3] from w, to get the remainder */
   w -= (t + t + t);

   /* fixup the remainder as required since
    * the optimization is not exact.
    */
   while(w >= 3)
   {
    t += 1;
    w -= 3;
   }
  }
  else
  {
   t = 0;
  }

  q.dp[ix] = (mp_digit)t;
 }//for ix

 /* [optional] store the remainder */
 if(d != NULL)
 {
  assert((w == 0) || (w > 0));

  //[2016-05-30] Research assert
  assert(w <= MP_DIGIT_MAX);

  (*d) = (mp_digit)w;
 }//if

 /* [optional] store the quotient */
 if(c != NULL)
 {
  mp_clamp(&q);

  mp_exch(&q, c);
 }//if

 assert_hint(res == MP_OKAY);

 return res;
}//mp_div_3

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
