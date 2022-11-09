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

/* get the size for an unsigned equivalent */
size_t mp_unsigned_bin_size_v2(const mp_int* const a)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

 //---
 if(a->used == 0)
  return 0;

 assert_hint(a->used > 0);

 //---
 const size_t c_bits_in_digit = (CHAR_BIT * sizeof(mp_digit));

 assert_s(c_bits_in_digit > 0);

 assert_s(MP_DIGIT_BIT <= c_bits_in_digit);

 const size_t c_reserved = (c_bits_in_digit - MP_DIGIT_BIT);

 assert_s(c_reserved > 0);

 assert_s((c_bits_in_digit % c_reserved) == 0);

 //количество mp_digit, в котором набирается один пустой mp_digit
 const size_t c_blockSize = (c_bits_in_digit / c_reserved);

 assert_s(c_blockSize > 1);

 //-------------------
 assert_hint(a->used > 0);

 //последний элемент будет обработан отдельно
 const mp_int::size_type N=(a->used - 1);

 //количество блоков
 const size_t blockCount = (N / c_blockSize);

 assert(blockCount <= N);

 size_t result = (((c_blockSize - 1) *  blockCount) * sizeof(mp_digit));

 const mp_int::size_type tailCount = (N % c_blockSize);

 size_t tailBits = (tailCount * MP_DIGIT_BIT);

 assert(a->dp[N] > 0);

 for(mp_digit last = a->dp[N]; last != 0; last = (last / 2), ++tailBits);

 result += (tailBits / CHAR_BIT);

 if(tailBits % CHAR_BIT)
  ++result;

 return result;
}//mp_unsigned_bin_size_v2

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
