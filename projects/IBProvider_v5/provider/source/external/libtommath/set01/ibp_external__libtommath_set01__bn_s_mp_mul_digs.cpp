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

/* multiplies |a| * |b| and only computes upto digs digits of result
 * HAC pp. 595, Algorithm 14.12  Modified so you can control how
 * many digits of output are created.
 */
mp_err s_mp_mul_digs(const mp_int*    const a,
                     const mp_int*    const b,
                     mp_int*          const c,
                     mp_int_size_type const digs)
{
 // [2016-05-27]
 //  Completely checked and prepared for "mp_int_size_type=size_t"

 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 assert((digs == 0) || (digs > 0));
 assert(digs >= a->used); //[2016-05-27] Required by this algorithm

 //-----------------------------------------------------------------------
 if(digs < a->used)
 {
  //[2016-05-26]
  assert(false);

  return MP_VAL;
 }//if

 assert_hint(a->used <= digs);

 //-----------------------------------------------------------------------
 mp_err res;

 /* can we use the fast multiplier? */
 if((digs < MP_WARRAY) &&
    MIN(a->used, b->used) < (1 << ((CHAR_BIT * sizeof(mp_word)) - (2 * MP_DIGIT_BIT))))
 {
  return fast_s_mp_mul_digs(a, b, c, digs);
 }

 mp_int_x t;

 if((res = mp_grow(&t, digs)) != MP_OKAY)
  return res;

 t.used = digs;

 /* compute the digits of the product directly */
 const mp_int::size_type pa = a->used;

 for(mp_int::size_type ix = 0; ix != pa; ++ix)
 {
  /* set the carry to zero */
  mp_digit u = 0;

  /* limit ourselves to making digs digits of output */
  assert(ix < digs);

  const mp_int::size_type pb = MIN(b->used, digs - ix);

  assert((pb == 0) || (pb > 0));

  /* setup some aliases */
  /* copy of the digit from a used within the nested loop */
  const mp_digit tmpx = a->dp[ix];

  /* an alias for the destination shifted ix places */
  mp_digit* tmpt = (t.dp + ix);

  /* an alias for the digits of b */
  const mp_digit* tmpy = b->dp;

  /* compute the columns of the output and propagate the carry */
  mp_int::size_type iy;

  for(iy = 0; iy != pb; ++iy, ++tmpt, ++tmpy)
  {
   assert(tmpt >= t.dp);
   assert(tmpt < (t.dp + t.used));

   /* compute the column as a mp_word */
   const mp_word r = ((mp_word)*tmpt) + ((mp_word)tmpx) * ((mp_word)*tmpy) + ((mp_word)u);

   /* the new column is the lower part of the result */
   (*tmpt) = (mp_digit)(r & ((mp_word)MP_MASK));

   /* get the carry word from the result */
   u = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));
  }//for iy

  /* set carry if it is placed below digs */
  if((ix + iy) < digs)
  {
   assert(tmpt >= t.dp);
   assert(tmpt < (t.dp + t.used));

   (*tmpt) = u;
  }//if
 }//for ix

 mp_clamp(&t);

 mp_exch(&t, c);

 return MP_OKAY;
}//s_mp_mul_digs

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
