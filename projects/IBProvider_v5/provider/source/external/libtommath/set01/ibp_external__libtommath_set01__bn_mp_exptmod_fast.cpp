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

/* computes Y == G**X mod P, HAC pp.616, Algorithm 14.85
 *
 * Uses a left-to-right k-ary sliding window to compute the modular exponentiation.
 * The value of k changes based on the size of the exponent.
 *
 * Uses Montgomery or Diminished Radix reduction [whichever appropriate]
 */

#ifdef MP_LOW_MEM
   #define TAB_SIZE 32
#else
   #define TAB_SIZE 256
#endif

static unsigned mp_exptmod_fast__helper__calc_winsize(mp_int_size_type const bits_count_in_X)
{
 if(bits_count_in_X <= 7)
  return 2;

 if(bits_count_in_X <= 36)
  return 3;

 if(bits_count_in_X <= 140)
  return 4;

#ifdef MP_LOW_MEM

 return 5;
#else

 if(bits_count_in_X <= 450)
  return 5;

 if(bits_count_in_X <= 1303)
  return 6;

 if(bits_count_in_X <= 3529)
  return 7;

  return 8;
#endif
}//mp_exptmod_fast__helper__calc_winsize

//------------------------------------------------------------------------
mp_err mp_exptmod_fast(const mp_int* const G,
                       const mp_int* const X,
                       const mp_int* const P,
                       mp_int*       const Y,
                       int           const redmode)
{
 DEBUG_CODE(mp_debug__check_int__total(G);)
 DEBUG_CODE(mp_debug__check_int__total(X);)
 DEBUG_CODE(mp_debug__check_int__total(P);)
 DEBUG_CODE(mp_debug__check_int__total(Y);)

 mp_err err;

 mp_int_x M[TAB_SIZE];
 mp_int_x res;

 mp_digit mp;
 
 /* use a pointer to the reduction algorithm.  This allows us to use
  * one of many reduction algorithms without modding the guts of
  * the code with if statements everywhere.
  */
 int(*redux)(mp_int*, const mp_int*, mp_digit);

 /* find window size */
 mp_int::size_type c_bits_in_X = 0;

 if((err = mp_count_bits_v2(X, &c_bits_in_X)) != MP_OKAY)
  return err;

 const unsigned winsize = mp_exptmod_fast__helper__calc_winsize(c_bits_in_X);

 assert(winsize >= 2);
 assert(winsize <= 8);

 /* determine and setup reduction code */
 if(redmode == 0)
 {
  //! \todo
  //!  Very strange logic for code generation

 #ifdef BN_MP_MONTGOMERY_SETUP_C
  /* now setup montgomery  */
  if((err = mp_montgomery_setup(P, &mp)) != MP_OKAY)
   return err;

 #else
  return MP_VAL;
 #endif

  /* automatically pick the comba one if available (saves quite a few calls/ifs) */
 #ifdef BN_FAST_MP_MONTGOMERY_REDUCE_C
  if (((P->used * 2 + 1) < MP_WARRAY) &&
       P->used < (1 << ((CHAR_BIT * sizeof(mp_word)) - (2 * MP_DIGIT_BIT))))
  {
   redux = fast_mp_montgomery_reduce;
  }
  else
 #endif
  {
  #ifdef BN_MP_MONTGOMERY_REDUCE_C
   /* use slower baseline Montgomery method */
   redux = mp_montgomery_reduce;
  #else
   return MP_VAL;
  #endif
  }
 }
 else
 if(redmode == 1)
 {
 #if defined(BN_MP_DR_SETUP_C) && defined(BN_MP_DR_REDUCE_C)
  /* setup DR reduction for moduli of the form B**k - b */
  mp_dr_setup(P, &mp);

  redux = mp_dr_reduce;
 #else
  return MP_VAL;
 #endif
 }
 else
 {
 #if defined(BN_MP_REDUCE_2K_SETUP_C) && defined(BN_MP_REDUCE_2K_C)
  /* setup DR reduction for moduli of the form 2**k - b */
  if((err = mp_reduce_2k_setup(P, &mp)) != MP_OKAY)
   return err;

  redux = mp_reduce_2k;
 #else
  return MP_VAL;
 #endif
 }//else

 /* create M table
  *

  *
  * The first half of the table is not computed though accept for M[0] and M[1]
  */

 if(redmode == 0)
 {
 #ifdef BN_MP_MONTGOMERY_CALC_NORMALIZATION_C
  /* now we need R mod m */
  if((err = mp_montgomery_calc_normalization(&res, P)) != MP_OKAY)
   return err;

  /* now set M[1] to G * R mod m */
  if((err = mp_mulmod(G, &res, P, &M[1])) != MP_OKAY)
   return err;
 #else
  return MP_VAL;
 #endif
 }
 else
 {
  assert_hint(redmode != 0); //signed value

  if((err = mp_set_v2(&res, 1)) != MP_OKAY)
   return err;

  if((err = mp_mod(G, P, &M[1])) != MP_OKAY)
   return err;
 }//else

 /* compute the value at M[1<<(winsize-1)] by squaring M[1] (winsize-1) times */
 if((err = mp_copy(&M[1], &M[((size_t)1) << (winsize - 1)])) != MP_OKAY)
  return err;

 for(unsigned x = 0, _c = (winsize - 1); x != _c; ++x)
 {
  const size_t ii = (((size_t)1) << _c);

  assert(ii<_DIM_(M));

  if((err = mp_sqr(&M[ii], &M[ii])) != MP_OKAY)
   return err;

  if((err = redux(&M[ii], P, mp)) != MP_OKAY)
   return err;
 }//for x

 /* create upper table */
 for(unsigned x = (((size_t)1) << (winsize - 1)) + 1; x < (((size_t)1) << winsize); ++x)
 {
  assert_hint(x>0);
  assert(x<_DIM_(M));

  if((err = mp_mul(&M[x - 1], &M[1], &M[x])) != MP_OKAY)
   return err;

  if((err = redux(&M[x], P, mp)) != MP_OKAY)
   return err;
 }//for x

 /* set initial mode and bit cnt */
 int               mode    = 0;
 unsigned          bitcnt2 = 1;
 mp_digit          buf     = 0;
 mp_int::size_type digidx2 = X->used;
 unsigned          bitcpy2 = 0;
 unsigned          bitbuf2 = 0;

 for(;;)
 {
  assert(bitcnt2 > 0);

  /* grab next digit as required */
  --bitcnt2;

  if(bitcnt2 == 0)
  {
   /* if digidx == -1 we are out of digits so break */
   if(digidx2 == 0)
    break;

   /* read next digit and reset bitcnt */
   --digidx2;

   buf = X->dp[digidx2];

   bitcnt2 = MP_DIGIT_BIT;
  }//if

  /* grab the next msb from the exponent */
  mp_digit const y = (mp_digit)(buf >> (MP_DIGIT_BIT - 1)) & 1;

  assert((y == 0) || (y == 1));

  buf <<= (mp_digit)1;

  /* if the bit is zero and mode == 0 then we ignore it
   * These represent the leading zero bits before the first 1 bit
   * in the exponent.  Technically this opt is not required but it
   * does lower the # of trivial squaring/reductions used
   */
  if(mode == 0 && y == 0)
   continue;

  /* if the bit is zero and mode == 1 then we square */
  if(mode == 1 && y == 0)
  {
   if((err = mp_sqr(&res, &res)) != MP_OKAY)
    return err;

   if((err = redux(&res, P, mp)) != MP_OKAY)
    return err;

   continue;
  }//if

  /* else we add it to the window */
  assert(bitcpy2 < winsize);

  ++bitcpy2;

  assert(bitcpy2 <= winsize);

  bitbuf2 |= (y << (winsize - bitcpy2));

  mode = 2;

  if(bitcpy2 == winsize)
  {
   /* ok window is filled so square as required and multiply  */
   /* square first */
   for(unsigned x = 0; x != winsize; ++x)
   {
    if((err = mp_sqr(&res, &res)) != MP_OKAY)
     return err;

    if((err = redux(&res, P, mp)) != MP_OKAY)
     return err;
   }//for x

   /* then multiply */
   assert(bitbuf2 < _DIM_(M));

   if((err = mp_mul(&res, &M[bitbuf2], &res)) != MP_OKAY)
    return err;

   if((err = redux(&res, P, mp)) != MP_OKAY)
    return err;

   /* empty window and reset */
   bitcpy2 = 0;

   bitbuf2 = 0;

   mode    = 1;
  }//if
 }//for[ever]

 /* if bits remain then square/multiply */
 assert(bitcpy2 == 0 || (bitcpy2 > 0));

 //[2016-05-30] Research asserts
 assert(bitcpy2 <= winsize);
 assert(bitcpy2 < winsize); // yes?

 if(mode == 2 && bitcpy2 > 0)
 {
  /* square then multiply if the bit is set */
  for(unsigned x = 0; x != bitcpy2; x++)
  {
   if((err = mp_sqr(&res, &res)) != MP_OKAY)
    return err;

   if((err = redux(&res, P, mp)) != MP_OKAY)
    return err;

   /* get next bit of the window */
   bitbuf2 <<= 1;

   if((bitbuf2 & (1 << winsize)) != 0)
   {
    /* then multiply */
    if((err = mp_mul(&res, &M[1], &res)) != MP_OKAY)
     return err;

    if((err = redux(&res, P, mp)) != MP_OKAY)
     return err;
   }//if
  }//for x
 }//if

 if(redmode == 0)
 {
  /* fixup result if Montgomery reduction is used
   * recall that any value in a Montgomery system is
   * actually multiplied by R mod n.  So we have
   * to reduce one more time to cancel out the factor
   * of R.
   */
  if((err = redux(&res, P, mp)) != MP_OKAY)
   return err;
 }//if

 /* swap res with Y */
 mp_exch(&res, Y);
 
 assert(err == MP_OKAY);

 return MP_OKAY;
}//mp_exptmod_fast

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
