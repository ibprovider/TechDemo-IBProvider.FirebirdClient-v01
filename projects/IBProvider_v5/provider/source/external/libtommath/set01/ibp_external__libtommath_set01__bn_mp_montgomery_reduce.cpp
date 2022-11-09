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

/* computes xR**-1 == x (mod N) via Montgomery Reduction */
mp_err mp_montgomery_reduce(mp_int*       const x,
                            const mp_int* const n,
                            mp_digit      const rho)
{
 DEBUG_CODE(mp_debug__check_int__light(x);)
 DEBUG_CODE(mp_debug__check_int__total(n);)

 mp_err res;

 /* can the fast reduction [comba] method be used?
  *
  * Note that unlike in mul you're safely allowed *less*
  * than the available columns [255 per default] since carries
  * are fixed up in the inner loop.
  */
 mp_int::size_type const digs = (n->used * 2 + 1);

 if((digs < MP_WARRAY) &&
    n->used < (1 << ((CHAR_BIT * sizeof(mp_word)) - (2 * MP_DIGIT_BIT))))
 {
  return fast_mp_montgomery_reduce(x, n, rho);
 }

 /* grow the input as required */
 if((res = mp_grow(x, digs)) != MP_OKAY)
  return res;

 x->used = digs;

 for(mp_int::size_type ix = 0; ix != n->used; ++ix)
 {
  assert(ix < n->used);

  /* mu = ai * rho mod b
   *
   * The value of rho must be precalculated via
   * montgomery_setup() such that
   * it equals -1/n0 mod b this allows the
   * following inner loop to reduce the
   * input one digit at a time
   */
  mp_digit const mu = (mp_digit)(((mp_word)x->dp[ix]) * ((mp_word)rho) & MP_MASK);

  /* a = a + mu * m * b**i */
  {
   /* alias for digits of the modulus */
   const mp_digit* tmpn = n->dp;

   /* alias for the digits of x [the input] */
   mp_digit* tmpx = (x->dp + ix);

   /* set the carry to zero */
   mp_digit u = 0;

   /* Multiply and add in place */
   for(mp_int::size_type iy = 0; iy != n->used; ++iy, ++tmpx, ++tmpn)
   {
    assert(iy < n->used);

    assert(tmpn >= n->dp);
    assert(tmpn < (n->dp + n->alloc));
    assert(tmpn < (n->dp + n->used));

    assert(tmpx >= x->dp);
    assert(tmpx < (x->dp + x->alloc));
    assert(tmpx < (x->dp + x->used));

    /* compute product and sum */
    const mp_word r
     = (((mp_word)mu) * ((mp_word)*tmpn) + ((mp_word)u) + ((mp_word)*tmpx));

    /* get carry */
    u = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));

    /* fix digit */
    (*tmpx) = (mp_digit)(r & ((mp_word)MP_MASK));
   }//for iy

   /* At this point the ix'th digit of x should be zero */

   /* propagate carries upwards as required*/
   for(; u; ++tmpx)
   {
    assert(tmpx >= x->dp);
    assert(tmpx < (x->dp + x->alloc));
    assert(tmpx < (x->dp + x->used));

    (*tmpx) += u;

    u = ((*tmpx) >> MP_DIGIT_BIT);

    (*tmpx) &= MP_MASK;
   }//while
  }//local
 }//for ix

 /* at this point the n.used'th least
  * significant digits of x are all zero
  * which means we can shift x to the
  * right by n.used digits and the
  * residue is unchanged.
  */

  /* x = x/b**n.used */
 mp_clamp(x);

 mp_rshd(x, n->used);

 /* if x >= n then x = x - n */
 if(mp_cmp_mag(x, n) != MP_LT)
 {
  return s_mp_sub(x, n, x);
 }

 DEBUG_CODE(mp_debug__check_int__total(x);)

 return MP_OKAY;
}//mp_montgomery_reduce

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
