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

/* multiplies |a| * |b| and does not compute the lower digs digits
 * [meant to get the higher part of the product]
 */
mp_err s_mp_mul_high_digs(const mp_int*    const a,
                          const mp_int*    const b,
                          mp_int*          const c,
                          mp_int_size_type const digs)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 assert((digs == 0) || (digs > 0));

 mp_err res;

 /* can we use the fast multiplier? */
#ifdef BN_FAST_S_MP_MUL_HIGH_DIGS_C
 if(((a->used + b->used + 1) < MP_WARRAY)
    && MIN(a->used, b->used) < (1 << ((CHAR_BIT * sizeof(mp_word)) - (2 * MP_DIGIT_BIT))))
 {
  return fast_s_mp_mul_high_digs(a, b, c, digs);
 }
#endif

 mp_int_x t;

 if((res = mp_grow(&t, a->used + b->used + 1)) != MP_OKAY)
  return res;

 t.used = (a->used + b->used + 1);

 assert(digs < t.used);

 const mp_int::size_type pa = a->used;
 const mp_int::size_type pb = b->used;

 for(mp_int::size_type ix = 0; ix != pa; ++ix)
 {
  /* clear the carry */
  mp_digit u = 0;

  /* left hand side of A[ix] * B[iy] */
  const mp_digit tmpx = a->dp[ix];

  /* alias to the address of where the digits will be stored */
  mp_digit* tmpt = &(t.dp[digs]);

  /* alias for where to read the right hand side from */
  assert(digs >= ix);

  const mp_digit* tmpy = (b->dp + (digs - ix));

  for(mp_int::size_type iy = (digs - ix); iy < pb; ++iy, ++tmpt, ++tmpy)
  {
   assert(tmpt >= t.dp);
   assert(tmpt < (t.dp + t.alloc));
   assert(tmpt < (t.dp + t.used));

   assert(tmpy >= b->dp);
   assert(tmpy < (b->dp + b->alloc));
   assert(tmpy < (b->dp + b->used));

   /* calculate the double precision result */
   const mp_word r = ((mp_word)*tmpt) + ((mp_word)tmpx) * ((mp_word)*tmpy) + ((mp_word)u);

   /* get the lower part */
   (*tmpt) = (mp_digit)(r & ((mp_word)MP_MASK));

   /* carry the carry */
   u = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));
  }//for iy

  (*tmpt) = u;
 }//for ix

 mp_clamp(&t);

 mp_exch(&t, c);

 return MP_OKAY;
}//s_mp_mul_high_digs

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
