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

/* store in unsigned [big endian] format */
mp_err mp_to_unsigned_bin(const mp_int*  const a,
                          unsigned char* const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 CHECK_WRITE_PTR(b,mp_unsigned_bin_size_v2(a));

 mp_err res;

 mp_int_x t;

 if((res = mp_copy(a, &t))!=MP_OKAY)
  return res;

 size_t x = 0;

 for(; mp_iszero(&t) == 0; ++x)
 {
  assert(b);

 #ifndef MP_8BIT
  b[x] = (unsigned char)(t.dp[0] & 255);
 #else
  b[x] = (unsigned char)(t.dp[0] | ((t.dp[1] & 0x01) << 7));
 #endif
 
  //! \todo
  //!  Думаю, надо порешать вопрос с этой восьмеркой (заменить на CHAR_BIT)

  if((res = mp_div_2d(&t, 8, &t, NULL))!=MP_OKAY)
   return res;
 }//for

 std::reverse(b, b+x);

 return MP_OKAY;
}//mp_to_unsigned_bin

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
