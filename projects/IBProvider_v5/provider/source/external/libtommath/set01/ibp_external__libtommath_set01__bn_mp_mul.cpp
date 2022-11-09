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

/* high level multiplication (handles sign) */
mp_err mp_mul(const mp_int* const a,
              const mp_int* const b,
              mp_int*       const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)
 DEBUG_CODE(mp_debug__check_int__light(c);)

 mp_err res;

 const mp_int::sign_type neg = ((a->sign == b->sign) ? MP_ZPOS : MP_NEG);

 /* use Toom-Cook? */
#ifdef BN_MP_TOOM_MUL_C
 if(MIN(a->used, b->used) >= TOOM_MUL_CUTOFF)
 {
  res = mp_toom_mul(a, b, c);
 }
 else
#endif
#ifdef BN_MP_KARATSUBA_MUL_C
 /* use Karatsuba? */
 if(MIN(a->used, b->used) >= KARATSUBA_MUL_CUTOFF)
 {
  res = mp_karatsuba_mul(a, b, c);
 }
 else
#endif
 {
  /* can we use the fast multiplier?
   *
   * The fast multiplier can be used if the output will
   * have less than MP_WARRAY digits and the number of
   * digits won't affect carry propagation
   */
  const mp_int::size_type digs = (a->used + b->used + 1);

  assert(digs > 0);

 #ifdef BN_FAST_S_MP_MUL_DIGS_C
  if ((digs < MP_WARRAY) &&
      MIN(a->used, b->used) <= (1 << ((CHAR_BIT * sizeof(mp_word)) - (2 * MP_DIGIT_BIT))))
  {
   res = fast_s_mp_mul_digs(a, b, c, digs);
  }
  else
 #endif
  {
 #ifdef BN_S_MP_MUL_DIGS_C
   res = s_mp_mul(a, b, c); /* uses s_mp_mul_digs */
 #else
   res = MP_VAL;
 #endif
  }//else or local
 }//else or local

 c->sign = ((c->used > 0) ? neg : MP_ZPOS);

 DEBUG_CODE(mp_debug__check_int__total(c);)

 return res;
}//mp_mul

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
