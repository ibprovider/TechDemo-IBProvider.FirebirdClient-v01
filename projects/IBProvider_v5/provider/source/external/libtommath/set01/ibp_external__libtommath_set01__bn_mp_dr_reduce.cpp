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

/* reduce "x" in place modulo "n" using the Diminished Radix algorithm.
 *
 * Based on algorithm from the paper
 *
 * "Generating Efficient Primes for Discrete Log Cryptosystems"
 *                 Chae Hoon Lim, Pil Joong Lee,
 *          POSTECH Information Research Laboratories
 *
 * The modulus must be of a special format [see manual]
 *
 * Has been modified to use algorithm 7.10 from the LTM book instead
 *
 * Input x must be in the range 0 <= x <= (n-1)**2
 */
mp_err mp_dr_reduce(mp_int*       const x,
                    const mp_int* const n,
                    mp_digit      const k)
{
 DEBUG_CODE(mp_debug__check_int__light(x);)
 DEBUG_CODE(mp_debug__check_int__total(n);)

 mp_err err;

 /* m = digits in modulus */
 mp_int::size_type const m = n->used;

 /* ensure that "x" has at least 2m digits */
 if((err = mp_grow(x, m + m)) != MP_OKAY)
  return err;

 /* top of loop, this is where the code resumes if
  * another reduction pass is required.
  */

 for(;;)
 {
  //By fact. Required in this algorithm (point #AAA)
  assert(x->used > 0);

  /* aliases for digits */
  /* alias for lower half of x */
  mp_digit* tmpx1 = x->dp;

  /* alias for upper half of x, or x/B**m */
  const mp_digit* tmpx2 = (x->dp + m);

  /* set carry to zero */
  mp_digit mu = 0;

  /* compute (x mod B**m) + k * [x/B**m] inline and inplace */
  for(mp_int::size_type i = 0; i != m; ++i, ++tmpx1, ++tmpx2)
  {
   assert(i < m);

   assert(tmpx1 >= x->dp);
   assert(tmpx1 <  (x->dp + x->alloc));
   assert(tmpx1 <  (x->dp + x->used)); //yes?

   assert(tmpx1 >= (x->dp + m));
   assert(tmpx1 <  (x->dp + x->alloc));
   assert(tmpx1 <  (x->dp + x->used)); //yes?

   const mp_word r = ((mp_word)*tmpx2) * ((mp_word)k) + (*tmpx1) + mu;

   (*tmpx1) = (mp_digit)(r & MP_MASK);

   mu = (mp_digit)(r >> ((mp_word)MP_DIGIT_BIT));
  }//for

  /* set final carry */
  assert(mu <= MP_DIGIT_MAX);

  assert(tmpx1 >= x->dp);
  assert(tmpx1 <  (x->dp + x->alloc));
  assert(tmpx1 <  (x->dp + x->used)); //yes?

  (*tmpx1) = mu; /* #AAA */

  ++tmpx1;

  /* zero words above m */
  for(mp_int::size_type i = (m + 1); i < x->used; ++i, ++tmpx1)
  {
   assert(tmpx1 >= x->dp);
   assert(tmpx1 <  (x->dp + x->alloc));
   assert(tmpx1 <  (x->dp + x->used)); //yes?

   (*tmpx1) = 0;
  }//for

  /* clamp, sub and return */
  mp_clamp(x);

  /* if x >= n then subtract and reduce again
   * Each successive "recursion" makes the input smaller and smaller.
   */
  if(mp_cmp_mag(x, n) != MP_LT)
  {
   s_mp_sub(x, n, x);

   continue;
  }//if

  return MP_OKAY;
 }//for[ever]
}//mp_dr_reduce

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
