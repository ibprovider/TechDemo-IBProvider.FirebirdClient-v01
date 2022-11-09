////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath_private.h"

namespace lcpi{namespace ibp{namespace external{namespace libtommath{namespace set01{
////////////////////////////////////////////////////////////////////////////////

mp_err mp_set_v2(mp_int* const a, mp_digit const b)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 //[2016-05-24]
 assert((b == 0) || (b > 0));
 assert(b <= MP_DIGIT_MAX);

 if(b == 0)
 {
  std::fill(a->dp, a->dp + a->used, 0);

  a->used = 0;
  a->sign = MP_ZPOS;

  DEBUG_CODE(mp_debug__check_int__total(a);)

  return MP_OKAY;
 }//if b == 0

 assert_hint(b > 0);

 const mp_err err = mp_grow(a,1);

 if(err != MP_OKAY)
  return err;

 assert(a->alloc > 0);

 a->dp[0] = b;

 if(a->used > 1)
 {
  std::fill(a->dp + 1, a->dp + a->used, 0);
 }//if

 a->used = 1;
 a->sign = MP_ZPOS;

 DEBUG_CODE(mp_debug__check_int__total(a);)

 return MP_OKAY;
}//mp_set_v2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
