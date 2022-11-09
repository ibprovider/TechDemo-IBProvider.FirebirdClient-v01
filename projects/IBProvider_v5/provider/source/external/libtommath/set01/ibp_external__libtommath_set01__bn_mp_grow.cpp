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

/* grow as required */
mp_err mp_grow(mp_int*    const a,
               mp_int_size_type size)
{
 DEBUG_CODE(mp_debug__check_int__light(a);)

 //[2016-05-15] Research assert
 assert((size == 0) || (size > 0));

 /* if the alloc size is smaller alloc more ram */
 if(a->alloc < size)
 {
  /* ensure there are always at least MP_PREC digits extra on top */
  size += (MP_PREC * 2) - (size % MP_PREC);

  assert(size > 0);

  /* reallocate the array a->dp
   *
   * We store the return in a temporary variable
   * in case the operation failed we don't want
   * to overwrite the dp member of a.
   */
  mp_digit* tmp = OPT_CAST(mp_digit) mp_mem__malloc(sizeof(mp_digit) * size);

  if(tmp == NULL)
   return MP_MEM;

  memcpy(tmp, a->dp, a->alloc * sizeof(mp_digit));

  /* reallocation succeeded so set a->dp */
  std::swap(a->dp, tmp);

  mp_mem__free(tmp);

  /* zero excess digits */
  std::fill(a->dp + a->alloc, a->dp + size, 0);

  a->alloc = size;
 }//if

 assert(a->alloc >= size);

 return MP_OKAY;
}//mp_grow

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
