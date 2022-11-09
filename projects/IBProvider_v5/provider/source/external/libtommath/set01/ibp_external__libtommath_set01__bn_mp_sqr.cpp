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

/* computes b = a*a */
mp_err mp_sqr(const mp_int* const a,
              mp_int*       const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__light(b);)

 mp_err res;

#ifdef BN_MP_TOOM_SQR_C
 /* use Toom-Cook? */
 if(a->used >= TOOM_SQR_CUTOFF)
 {
  res = mp_toom_sqr(a, b);
  /* Karatsuba? */
 }
 else
#endif
#ifdef BN_MP_KARATSUBA_SQR_C
 if(a->used >= KARATSUBA_SQR_CUTOFF)
 {
  res = mp_karatsuba_sqr(a, b);
 }
 else
#endif
 {
 #ifdef BN_FAST_S_MP_SQR_C
  /* can we use the fast comba multiplier? */
  if((a->used * 2 + 1) < MP_WARRAY &&
      a->used < (1 << (sizeof(mp_word) * CHAR_BIT - 2 * MP_DIGIT_BIT - 1)))
  {
   res = fast_s_mp_sqr(a, b);
  }
  else
  {
 #endif
 #ifdef BN_S_MP_SQR_C
   res = s_mp_sqr(a, b);
 #else
   res = MP_VAL;
 #endif
  }//else or local
 }//else or local

 b->sign = MP_ZPOS;

 return res;
}//mp_sqr

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
