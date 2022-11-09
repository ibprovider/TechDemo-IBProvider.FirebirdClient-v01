////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath_private.h"
#include <structure/t_limits.h>

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

/* this is a modified version of fast_s_mul_digs that only produces
 * output digits *above* digs.  See the comments for fast_s_mul_digs
 * to see how it works.
 *
 * This is used in the Barrett reduction since for one of the multiplications
 * only the higher digits were needed.  This essentially halves the work.
 *
 * Based on Algorithm 14.12 on pp.595 of HAC.
 */
mp_err fast_s_mp_mul_high_digs(const mp_int*    const a,
                               const mp_int*    const b,
                               mp_int*          const c,
                               mp_int_size_type const digs)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 assert(a->used <= (MP_WARRAY/2));
 assert(b->used <= (MP_WARRAY/2));

 assert((digs == 0) || (digs > 0));
 assert(digs <= a->used ||
        digs <= b->used);

 mp_err res;

 if(mp_iszero(a) || mp_iszero(b))
 {
  mp_zero(c);

  return MP_OKAY;
 }//if

 assert(a->used > 0);
 assert(b->used > 0);

 /* grow the destination as required */
 const mp_int::size_type pa = (a->used + b->used);

 if((res = mp_grow(c, pa)) != MP_OKAY)
  return res;

 /* number of output digits to produce */
 assert(pa == (a->used + b->used));

 mp_digit W[MP_WARRAY];

 /* clear the carry */
 mp_word _W = 0;

 assert(digs <= pa);

 for(mp_int::size_type ix = digs; ix != pa; ++ix)
 {
  assert(ix < pa);

  assert(b->used > 0);

  /* get offsets into the two bignums */
  const mp_int::size_type ty = MIN(b->used - 1, ix);

  assert((ty == 0) || (ty > 0));
  assert(ty < b->used);

  assert(ix >= ty);

  const mp_int::size_type tx = (ix - ty);

  assert((tx == 0) || (tx > 0));

  if(tx < a->used)
  {
   /* setup temp aliases */
   const mp_digit* tmpx = (a->dp + tx);
   const mp_digit* tmpy = (b->dp + ty);

   // this is the number of times the loop will iterrate, essentially its
   // while (tx++ < a->used && ty-- >= 0) { ... }
   const mp_int::size_type iy = MIN(a->used - tx, ty + 1);

   assert(iy > 0);

   /* execute loop */

   for(const mp_digit* const _ex = (tmpx + iy); tmpx != _ex; ++tmpx, --tmpy)
   {
    assert(tmpx >= (a->dp));
    assert(tmpx <  (a->dp + a->used));
    assert(tmpy >= (b->dp));
    assert(tmpy <  (b->dp + b->used));

    const mp_word m = (static_cast<mp_word>(*tmpx) * static_cast<mp_word>(*tmpy));

    assert(m < (structure::t_numeric_limits<mp_word>::max_value() - _W));

    _W += m;
   }//for
  }//if(tx < a->used)

  /* store term */
  assert((ix == 0) || (ix > 0));
  assert(ix < _DIM_(W));

  W[ix] = ((mp_digit)_W) & MP_MASK;

  /* make next carry */
  _W = _W >> ((mp_word)MP_DIGIT_BIT);
 }//for is

 /* setup dest */
 if(pa < c->used)
 {
  std::fill(c->dp + pa, c->dp + c->used, 0);
 }//if

 assert(digs <= pa);

 for(mp_int::size_type ix = digs; ix != pa ; ++ix)
 {
  assert(ix < pa);

  assert((ix == 0) || (ix > 0));
  assert(ix < _DIM_(W));

  /* now extract the previous digit [below the carry] */
  assert(W[ix] <= MP_MASK);

  c->dp[ix] = W[ix];
 }//for ix

 c->used = pa;

 mp_clamp(c);

 return MP_OKAY;
}//fast_s_mp_mul_high_digs

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
