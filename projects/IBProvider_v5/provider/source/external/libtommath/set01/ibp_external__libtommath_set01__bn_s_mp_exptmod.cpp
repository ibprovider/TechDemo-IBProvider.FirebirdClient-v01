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
#ifdef MP_LOW_MEM
   #define TAB_SIZE 32
#else
   #define TAB_SIZE 256
#endif

static unsigned s_mp_exptmod__helper__calc_winsize(mp_int_size_type const bits_count_in_X)
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
}//s_mp_exptmod__helper__calc_winsize

//------------------------------------------------------------------------
mp_err s_mp_exptmod(const mp_int* const G,
                    const mp_int* const X,
                    const mp_int* const P,
                    mp_int*       const Y,
                    int           const redmode)
{ 

 DEBUG_CODE(mp_debug__check_int__total(G);)
 DEBUG_CODE(mp_debug__check_int__total(X);)
 DEBUG_CODE(mp_debug__check_int__total(P);)
 DEBUG_CODE(mp_debug__check_int__light(Y);)

 assert(P->used > 0); // used with mp_mod

 mp_err err;

 mp_int_x M[TAB_SIZE], res, mu;

 int(*redux)(mp_int*, const mp_int*, const mp_int*);

 /* find window size */
 mp_int::size_type c_bits_in_X = 0;

 if((err = mp_count_bits_v2(X, &c_bits_in_X)) != MP_OKAY)
  return err;

 const unsigned winsize = s_mp_exptmod__helper__calc_winsize(c_bits_in_X);

 assert(winsize >= 2);
 assert(winsize <= 8);

 if(redmode == 0)
 {
  if((err = mp_reduce_setup(&mu, P)) != MP_OKAY)
   return err;

  redux = mp_reduce;
 }
 else
 {
  if((err = mp_reduce_2k_setup_l(P, &mu)) != MP_OKAY)
   return err;

  redux = mp_reduce_2k_l;
 }//else

 /* create M table
  *
  * The M table contains powers of the base,
  * e.g. M[x] = G**x mod P
  *
  * The first half of the table is not
  * computed though accept for M[0] and M[1]
  */
 if((err = mp_mod(G, P, &M[1])) != MP_OKAY)
  return err;

 /* compute the value at M[1<<(winsize-1)] by squaring
  * M[1] (winsize-1) times
  */
 if((err = mp_copy(&M[1], &M[((size_t)1) << (winsize - 1)])) != MP_OKAY)
  return err;

 for(unsigned x = 0, _c = (winsize - 1); x != _c; ++x)
 {
  const size_t ii = ((size_t)1) << _c;

  assert(ii < _DIM_(M));

  /* square it */
  if((err = mp_sqr(&M[ii], &M[ii])) != MP_OKAY)
   return err;

  /* reduce modulo P */
  if((err = redux(&M[ii], P, &mu)) != MP_OKAY)
   return err;
 }//for x

 /* create upper table, that is M[x] = M[x-1] * M[1] (mod P)
  * for x = (2**(winsize - 1) + 1) to (2**winsize - 1)
  */
 for(unsigned x = ((1u << (winsize - 1)) + 1); x != (1u << winsize); ++x)
 {
  assert_hint(x>0);
  assert(x<_DIM_(M));

  if((err = mp_mul(&M[x - 1], &M[1], &M[x])) != MP_OKAY)
   return err;

  if((err = redux(&M[x], P, &mu)) != MP_OKAY)
   return err;
 }//for x

 /* setup result */

 if((err = mp_set_v2(&res, 1)) != MP_OKAY)
  return err;

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
   /* if digidx == 0 we are out of digits */
   if(digidx2 == 0)
   {
    break;
   }

   assert_hint(digidx2 > 0);

   /* read next digit and reset the bitcnt */
   --digidx2;

   buf = X->dp[digidx2];

   bitcnt2 = MP_DIGIT_BIT;
  }//if

  /* grab the next msb from the exponent */
  const mp_digit y = (buf >> (mp_digit)(MP_DIGIT_BIT - 1)) & 1;

  assert((y == 0) || (y == 1));

  buf <<= (mp_digit)1;

  /* if the bit is zero and mode == 0 then we ignore it
   * These represent the leading zero bits before the first 1 bit
   * in the exponent.  Technically this opt is not required but it
   * does lower the # of trivial squaring/reductions used
   */
  if(mode == 0 && y == 0)
  {
   continue;
  }

  /* if the bit is zero and mode == 1 then we square */
  if(mode == 1 && y == 0)
  {
   if((err = mp_sqr(&res, &res)) != MP_OKAY)
    return err;

   if((err = redux(&res, P, &mu)) != MP_OKAY)
    return err;

   continue;
  }//if

  /* else we add it to the window */
  assert(bitcpy2 < winsize);

  ++bitcpy2;

  assert(bitcpy2 <= winsize);

  bitbuf2 |= (((size_t)y) << (winsize - bitcpy2));

  mode = 2;

  if(bitcpy2 == winsize)
  {
   /* ok window is filled so square as required and multiply  */
   /* square first */
   for(unsigned x = 0; x != winsize; ++x)
   {
    if((err = mp_sqr(&res, &res)) != MP_OKAY)
     return err;

    if((err = redux(&res, P, &mu)) != MP_OKAY)
     return err;
   }//for

   /* then multiply */
   assert(bitbuf2 < _DIM_(M));

   if((err = mp_mul(&res, &M[bitbuf2], &res)) != MP_OKAY)
    return err;

   if((err = redux(&res, P, &mu)) != MP_OKAY)
    return err;

   /* empty window and reset */
   bitcpy2 = 0;

   bitbuf2 = 0;

   mode    = 1;
  }//if(bitcpy == winsize)
 }//for[ever]

 /* if bits remain then square/multiply */
 assert(bitcpy2 == 0 || (bitcpy2 > 0));

 //[2016-05-30] Research asserts
 assert(bitcpy2 <= winsize);
 assert(bitcpy2 < winsize); // yes?

 if(mode == 2 && bitcpy2 > 0)
 {
  /* square then multiply if the bit is set */
  for(unsigned x = 0; x != bitcpy2; ++x)
  {
   if((err = mp_sqr(&res, &res)) != MP_OKAY)
    return err;

   if((err = redux(&res, P, &mu)) != MP_OKAY)
    return err;

   bitbuf2 <<= 1;

   if((bitbuf2 & (((size_t)1) << winsize)) != 0)
   {
    /* then multiply */
    if((err = mp_mul(&res, &M[1], &res)) != MP_OKAY)
     return err;

    if((err = redux(&res, P, &mu)) != MP_OKAY)
     return err;
   }//if
  }//for x
 }//if

 mp_exch(&res, Y);

 assert(err == MP_OKAY);

 return MP_OKAY;
}//s_mp_exptmod

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
