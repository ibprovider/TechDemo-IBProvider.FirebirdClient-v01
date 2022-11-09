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

/* determines the setup value */
void mp_dr_setup(const mp_int* const a,
                 mp_digit*     const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 //[2016-05-15] See mp_exptmod, call of mp_exptmod_fast.
 assert(a->used > 0);
 assert(d);

 /* the casts are required if MP_DIGIT_BIT is one less than
  * the number of bits in a mp_digit [e.g. MP_DIGIT_BIT==31]
  */

 (*d) = (mp_digit)((((mp_word)1) << ((mp_word)MP_DIGIT_BIT)) -
                   ((mp_word)a->dp[0]));
}//mp_dr_setup

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
