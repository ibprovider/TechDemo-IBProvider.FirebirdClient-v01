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

/* the jist of squaring...
 * you do like mult except the offset of the tmpx [one that
 * starts closer to zero] can't equal the offset of tmpy.
 * So basically you set up iy like before then you min it with
 * (ty-tx) so that it never happens.  You double all those
 * you add in the inner loop

After that loop you do the squares and add them in.
*/

mp_err fast_s_mp_sqr(const mp_int* const a,
                     mp_int*       const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(b);)

 assert(a->used <= (MP_WARRAY/2));

 mp_err res;

 if(mp_iszero(a))
 {
  mp_zero(b);

  return MP_OKAY;
 }//if

 assert(a->used > 0);

 mp_digit W[MP_WARRAY];

 /* grow the destination as required */
 const mp_int::size_type pa = (a->used + a->used);

 assert(pa >= 2);
 assert(pa <= _DIM_(W));

 if((res = mp_grow(b, pa)) != MP_OKAY)
  return res;

 /* number of output digits to produce */
 mp_word W1 = 0;

 for(mp_int::size_type ix = 0; ix != pa; ++ix)
 {
  assert(ix < pa);

  /* clear counter */
  mp_word _W = 0;

  /* get offsets into the two bignums */
  assert(a->used > 0);

  const mp_int::size_type ty = MIN(a->used - 1, ix);

  assert((ty == 0) || (ty > 0));
  assert(ty < a->used);
  assert(ty <= ix);

  const mp_int::size_type tx = (ix - ty);

  assert((tx == 0) || (tx > 0));

  if(tx < a->used)
  {
   /* setup temp aliases */
   const mp_digit* tmpx = (a->dp + tx);
   const mp_digit* tmpy = (a->dp + ty);
   
   // this is the number of times the loop will iterrate, essentially
   // while (tx++ < a->used && ty-- >= 0) { ... }
   mp_int::size_type iy = MIN(a->used - tx, ty + 1);

   // now for squaring tx can never equal ty
   // we halve the distance since they approach at a rate of 2x
   // and we have to round because odd cases need to be executed
   iy = MIN(iy, (ty - tx + 1) >> 1);

   /* execute loop */
   //for(int iz = 0; iz < iy; iz++)

   for(const mp_digit* const _ex = (tmpx + iy); tmpx != _ex; ++tmpx, --tmpy)
   {
    //_W += ((mp_word)*tmpx++)*((mp_word)*tmpy--);

    assert(tmpx >= (a->dp));
    assert(tmpx <  (a->dp + a->used));
    assert(tmpy >= (a->dp));
    assert(tmpy <  (a->dp + a->used));

    const mp_word m = (static_cast<mp_word>(*tmpx) * static_cast<mp_word>(*tmpy));

    assert(m < (structure::t_numeric_limits<mp_word>::max_value() - _W));

    _W += m;
   }//for
  }//if(tx < a->used)

  /* double the inner product and add carry */

  assert(W1 <= (structure::t_numeric_limits<mp_word>::max_value()));
  assert(_W <= (structure::t_numeric_limits<mp_word>::max_value() - W1));
  assert(_W <= (structure::t_numeric_limits<mp_word>::max_value() - W1 - _W));

  _W = (_W + _W + W1);

  /* even columns have the square term in them */
  if((ix & 1) == 0)
  {
   const mp_int::size_type ix2 = (ix >> 1);

   assert(ix2 < a->used);

   const mp_word d = a->dp[ix2];

   const mp_word m = (d * d);

   assert(m < (structure::t_numeric_limits<mp_word>::max_value() - _W));

   _W += m;
  }//if

  /* store it */
  assert((ix == 0) || (ix > 0));
  assert(ix < _DIM_(W));

  W[ix] = (mp_digit)(_W & MP_MASK);

  /* make next carry */
  W1 = _W >> ((mp_word)MP_DIGIT_BIT);
 }//for ix

 /* setup dest */
 if(pa < b->used)
 {
  std::fill(b->dp + pa, b->dp + b->used, 0);
 }//if

 for(mp_int::size_type ix = 0; ix != pa ; ++ix)
 {
  assert((ix == 0) || (ix > 0));
  assert(ix < _DIM_(W));

  /* now extract the previous digit [below the carry] */

  assert(W[ix] <= MP_MASK);

  b->dp[ix] = W[ix];
 }//for ix

 b->used = pa;

 mp_clamp(b);

 return MP_OKAY;
}//fast_s_mp_sqr

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
