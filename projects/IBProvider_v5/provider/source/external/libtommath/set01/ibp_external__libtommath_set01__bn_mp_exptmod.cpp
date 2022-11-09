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


/* this is a shell function that calls either the normal or Montgomery
 * exptmod functions.  Originally the call to the montgomery code was
 * embedded in the normal function but that wasted alot of stack space
 * for nothing (since 99% of the time the Montgomery code would be called)
 */
mp_err mp_exptmod(const mp_int* const G,
                  const mp_int* const X,
                  const mp_int* const P,
                  mp_int*       const Y)
{
 DEBUG_CODE(mp_debug__check_int__total(G);)
 DEBUG_CODE(mp_debug__check_int__total(X);)
 DEBUG_CODE(mp_debug__check_int__total(P);)
 DEBUG_CODE(mp_debug__check_int__light(Y);)

 /* modulus P must be positive */
 if(P->sign == MP_NEG)
 {
  return MP_VAL;
 }

 /* if exponent X is negative we have to recurse */
 if(X->sign == MP_NEG)
 {
 #ifdef BN_MP_INVMOD_C
  mp_err err;

  mp_int_x tmpG, tmpX;

  /* first compute 1/G mod P */

  if((err = mp_invmod(G, P, &tmpG)) != MP_OKAY)
   return err;

  /* now get |X| */

  if((err = mp_abs(X, &tmpX)) != MP_OKAY)
   return err;

  /* and now compute (1/G)**|X| instead of G**X [X < 0] */
  return mp_exptmod(&tmpG, &tmpX, P, Y);
 #else
  /* no invmod */
  return MP_VAL;
 #endif
 }//if X->sign == MP_NEG

 /* modified diminished radix reduction */
#if defined(BN_MP_REDUCE_IS_2K_L_C) && defined(BN_MP_REDUCE_2K_L_C) && defined(BN_S_MP_EXPTMOD_C)
 if(mp_reduce_is_2k_l(P) == MP_YES)
 {
  return s_mp_exptmod(G, X, P, Y, 1);
 }
#endif

#ifdef BN_MP_DR_IS_MODULUS_C
 /* is it a DR modulus? */
 int dr = mp_dr_is_modulus(P);

 assert(dr == 0 || (P->used > 2));
#else
 /* default to no */
 int dr = 0;
#endif

#ifdef BN_MP_REDUCE_IS_2K_C
 /* if not, is it a unrestricted DR modulus? */
 if(dr == 0)
 {
  dr = mp_reduce_is_2k(P) /*0 or 1*/ << 1;

  assert(dr == 0 || (P->used > 0));
 }//if
#endif

 /* if the modulus is odd or dr != 0 use the montgomery method */
#ifdef BN_MP_EXPTMOD_FAST_C
 if(mp_isodd(P) == 1 || dr != 0)
 {
  //[2016-05-15] BY FACT
  assert(P->used>0);

  return mp_exptmod_fast(G, X, P, Y, dr);
 }//if
#endif

#ifdef BN_S_MP_EXPTMOD_C
 /* otherwise use the generic Barrett reduction technique */
 return s_mp_exptmod(G, X, P, Y, 0);
#else
 /* no exptmod for evens */
 return MP_VAL;
#endif
}//mp_exptmod

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
