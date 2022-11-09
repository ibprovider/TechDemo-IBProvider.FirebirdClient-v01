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

/* low level squaring, b = a*a, HAC pp.596-597, Algorithm 14.16 */
mp_err s_mp_sqr(const mp_int* const a,
                mp_int*       const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(b);)

 mp_err res;

 const mp_int::size_type pa = a->used;

 mp_int_x t;
 
 if((res = mp_grow(&t, 2 * pa + 1)) != MP_OKAY)
  return res;

 /* default used is maximum possible size */
 t.used = (2 * pa + 1);

 for(mp_int::size_type ix = 0; ix != pa; ++ix)
 {
  assert(ix < pa);

  /* first calculate the digit at 2*ix */
  /* calculate double precision result */
  mp_word r = ((mp_word)t.dp[2 * ix]) + ((mp_word)a->dp[ix])*((mp_word)a->dp[ix]);

  /* store lower part in result */
  t.dp[ix + ix] = (mp_digit)(r & ((mp_word)MP_MASK));

  /* get the carry */
  mp_digit u = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));

  /* left hand side of A[ix] * A[iy] */
  const mp_digit tmpx = a->dp[ix];

  /* alias for where to store the results */
  mp_digit* tmpt = (t.dp + (2 * ix + 1));

  for(mp_int::size_type iy = (ix + 1); iy != pa; ++iy, ++tmpt)
  {
   assert(iy < pa);

   /* first calculate the product */
   r = (((mp_word)tmpx) * ((mp_word)a->dp[iy]));

   /* now calculate the double precision result, note we use
    * addition instead of *2 since it's easier to optimize
    */
   r = (((mp_word)*tmpt) + r + r + ((mp_word)u));

   /* store lower part */
   (*tmpt) = (mp_digit)(r & ((mp_word)MP_MASK));

   /* get carry */
   u = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));
  }//for
 
  /* propagate upwards */
  for(; u != ((mp_digit)0); ++tmpt)
  {
   r = (((mp_word)*tmpt) + ((mp_word)u));

   (*tmpt) = (mp_digit)(r & ((mp_word)MP_MASK));

   u = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));
  }//while
 }//for ix

 mp_clamp(&t);

 mp_exch(&t, b);

 return MP_OKAY;
}//s_mp_sqr

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
