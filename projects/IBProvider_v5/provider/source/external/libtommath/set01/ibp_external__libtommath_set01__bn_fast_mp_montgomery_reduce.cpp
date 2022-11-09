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

/* computes xR**-1 == x (mod N) via Montgomery Reduction
 *
 * This is an optimized implementation of montgomery_reduce
 * which uses the comba method to quickly calculate the columns of the
 * reduction.
 *
 * Based on Algorithm 14.32 on pp.601 of HAC.
*/
mp_err fast_mp_montgomery_reduce(mp_int*       const x,
                                 const mp_int* const n,
                                 mp_digit      const rho)
{
 DEBUG_CODE(mp_debug__check_int__light(x);)
 DEBUG_CODE(mp_debug__check_int__total(n);)

 //----------------------------------------- [2016-05-26]
 if(n->used > ((MP_WARRAY- 1) / 2))
 {
  assert_msg(false,"n->used: "<<n->used);

  return MP_VAL;
 }//if

 assert_hint(n->used <= ((MP_WARRAY- 1) / 2));

 const mp_int::size_type _cW = ((n->used * 2) + 1);

 assert_hint(_cW <= MP_WARRAY);

 if(x->used > _cW)
 {
  assert_msg(false,"x->used: "<<x->used);

  return MP_VAL;
 }//if

 assert_hint(x->used <= _cW);

 assert_hint(_cW <= MP_WARRAY); // Again

 //-----------------------------------------
 mp_err res;

 mp_word W[MP_WARRAY];

 /* get old used count */
 mp_int::size_type const olduse = x->used;

 /* grow a as required */
 if((res = mp_grow(x, n->used + 1)) != MP_OKAY)
  return res;

 // first we have to get the digits of the input into
 // an array of double precision words W[...]
 {
  /* alias for the W[] array */
  mp_word* _W = W;

  /* alias for the digits of  x*/
  const mp_digit* tmpx = x->dp;

  /* copy the digits of a into W[0..a->used-1] */

  // ----- mp_int::size_type ix;
  // ----- 
  // ----- for(ix = 0; ix < x->used; ++ix, ++_W, ++tmpx)
  // ----- {
  // -----  (*_W) = (*tmpx);
  // ----- }
  // ----- 
  // ----- /* zero the high words of W[a->used..m->used*2] */
  // ----- for(const mp_int::size_type _c = ((n->used * 2) + 1); ix < _c; ++ix, ++_W)
  // ----- {
  // -----  (*_W) = 0;
  // ----- }

  for(const mp_digit* const _eX = (x->dp + x->used); tmpx != _eX; ++_W, ++tmpx)
  {
   (*_W) = (*tmpx);
  }//for

  assert(_W <= (W + _cW));

  /* zero the high words of W[x->used..m->used*2] */
  for(const mp_word* const _eW = (W + _cW); _W != _eW; ++_W)
  {
   (*_W) = 0;
  }//for

  assert(_W == (W + _cW));
 }//local

 // now we proceed to zero successive digits
 // from the least significant upwards
 for(mp_int::size_type ix = 0; ix != n->used; ++ix)
 {
  assert(ix < n->used);

  //[2018-12-22] Hint
  assert_s(_DIM_(W)==MP_WARRAY);
  assert_hint(n->used <= ((MP_WARRAY- 1) / 2)); //Again. See above.

  assert(((MP_WARRAY- 1) / 2) < MP_WARRAY);

  assert_hint(n->used < MP_WARRAY);

  //[2018-12-22] So
  assert_hint(ix < _DIM_(W)); // equal to : ix < MP_WARRAY

  {
   /* mu = ai * m' mod b
   *
   * We avoid a double precision multiplication (which isn't required)
   * by casting the value down to a mp_digit.  Note this requires
   * that W[ix-1] have  the carry cleared (see after the inner loop)
   */
   mp_digit const mu = (mp_digit)(((W[ix] & MP_MASK) * rho) & MP_MASK);

   /* a = a + mu * m * b**i
    *
    * This is computed in place and on the fly.  The multiplication
    * by b**i is handled by offseting which columns the results
    * are added to.
    *
    * Note the comba method normally doesn't handle carries in the
    * inner loop In this case we fix the carry from the previous
    * column since the Montgomery reduction requires digits of the
    * result (so far) [see above] to work.  This is
    * handled by fixing up one carry after the inner loop.  The
    * carry fixups are done in order so after these loops the
    * first m->used words of W[] have the carries fixed
    */

   /* alias for the digits of the modulus */
   const mp_digit*      tmpn = (n->dp);
   const mp_digit* const _en = (n->dp + n->used);

   /* Alias for the columns set by an offset of ix */
   assert((ix == 0) || (ix > 0));
   assert_hint(ix <= _DIM_(W));
   assert_hint(ix < _DIM_(W)); // [2018-12-22] Again

   mp_word* _W = (W + ix);

   /* inner loop */
   for(; tmpn != _en; ++tmpn, ++_W)
   {
    assert(_W != _END_(W));

    mp_word const M = static_cast<mp_word>(mu) * static_cast<mp_word>(*tmpn);

    assert(M <= (structure::t_numeric_limits<mp_word>::max_value() - (*_W)));

    (*_W) += M;
   }//for
  }//local

  /* now fix carry for next digit, W[ix+1] */
  {
   assert((ix == 0) || (ix > 0));
   assert_hint(ix < _DIM_(W));

   mp_word const D = (W[ix] >> ((mp_word)MP_DIGIT_BIT));

   //--- HINT
   assert_s(_DIM_(W)==MP_WARRAY);
   assert_hint(n->used <= ((MP_WARRAY- 1) / 2)); //Again. See above.

   assert(ix < n->used);
   assert_hint(ix < ((MP_WARRAY- 1) / 2));
   assert_hint((2*ix) < (MP_WARRAY- 1));
   assert_hint((2*ix + 1) < MP_WARRAY);
   assert_hint((ix + 1) < MP_WARRAY); // [A] 

   //---
   assert((ix == 0) || (ix > 0));
   assert_hint((ix + 1) < _DIM_(W)); // see [A]

   assert(D <= (structure::t_numeric_limits<mp_word>::max_value() - W[ix + 1]));

   W[ix + 1] += D;
  }//local
 }//for ix [0 .. n->used)

 // now we have to propagate the carries and
 // shift the words downward [all those least
 // significant digits we zeroed].
 {
  /* now fix rest of carries */

  /* alias for current word */
  mp_word* _W = (W + n->used);

  for(const mp_word* const _eW = (_W + n->used); _W != _eW;)
  {
   assert(_W >= W);
   assert(_W <  _END_(W));

   mp_word const D = ((*_W) >> ((mp_word)MP_DIGIT_BIT));

   ++_W;

   assert(_W >= W);
   assert(_W <  _END_(W));

   assert(D <= (structure::t_numeric_limits<mp_word>::max_value() - (*_W)));

   (*_W) += D;
  }//for
 }//local

 /* set the max used and clamp */
 assert(x->used == olduse);

 x->used = (n->used + 1);

 assert(x->used <= x->alloc);

 {
  // zero oldused digits, if the input a was larger than
  // m->used+1 we'll have to clear the digits

  if(x->used < olduse)
  {
   std::fill(x->dp + x->used, x->dp + olduse, 0);
  }

  // copy out, A = A/b**n
  //
  // The result is A/b**n but instead of converting from an
  // array of mp_word to mp_digit than calling mp_rshd
  // we just copy them in the right order

  /* alias for destination word */
  mp_digit* tmpx = x->dp;

  /* alias for shifted double precision result */
  const mp_word* _W = (W + n->used);

  assert(_W >= W);
  assert(_W <= _END_(W));
  
  const mp_word* const _eW = (_W + x->used);

  assert(_eW >= _W);
  assert(_eW <= _END_(W));

  assert(_eW == (W + _cW));

  for(; _W != _eW; ++tmpx, ++_W)
  {
   (*tmpx) = (mp_digit)((*_W) & ((mp_word)MP_MASK));
  }
 }//local

 mp_clamp(x);

 /* if A >= m then A = A - m */
 if(mp_cmp_mag(x, n) != MP_LT)
 {
  return s_mp_sub(x, n, x);
 }

 return MP_OKAY;
}//fast_mp_montgomery_reduce

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
