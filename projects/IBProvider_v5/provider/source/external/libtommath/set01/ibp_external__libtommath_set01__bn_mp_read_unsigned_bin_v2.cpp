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

/* reads a unsigned char array, assumes the msb is stored first [big endian] */
mp_err mp_read_unsigned_bin_v2(mp_int*        const a,
                               const unsigned char* b,
                               size_t         const c)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 CHECK_READ_TYPED_PTR(b,c);

 mp_err res;

 /* zero the int */
 mp_zero(a);

 /* read the bytes in */
 for(const unsigned char* const _e = (b + c); b != _e; ++b)
 {
  //! \todo
  //!  Думаю, вместо восьмерки здесь следует использовать CHAR_BIT

  if((res = mp_mul_2d(a, 8, a)) != MP_OKAY)
   return res;

  assert(a->used <= a->alloc);

 #ifndef MP_8BIT
  if(*b)
  {
   if(a->used > 0)
   {
    a->dp[0] |= (*b);
   }
   else
   {
    assert_hint(a->used == 0);

    if((res = mp_grow(a, 1)) != MP_OKAY)
     return res;

    assert(a->alloc > 0);

    a->dp[0] = (*b);

    a->used = 1;
   }//else
  }//if
 #else
  #error not implemented / not tested

  a->dp[0] = (*b & MP_MASK);
  a->dp[1] |= ((*b++ >> 7U) & 1);
  a->used += 2;
 #endif
 }//for b

 DEBUG_CODE(mp_debug__check_int__total(a);)

 //[2016-05-17] Not requried
 //mp_clamp(a);

 return MP_OKAY;
}//mp_read_unsigned_bin_v2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
