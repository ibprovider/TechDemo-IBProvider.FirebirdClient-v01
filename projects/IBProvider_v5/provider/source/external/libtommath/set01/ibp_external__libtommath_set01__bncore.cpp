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

/* Known optimal configurations

 CPU                    /Compiler     /MUL CUTOFF/SQR CUTOFF
-------------------------------------------------------------
 Intel P4 Northwood     /GCC v3.4.1   /        88/       128/LTM 0.32 ;-)
 AMD Athlon64           /GCC v3.4.4   /        80/       120/LTM 0.35

*/

const mp_int_size_type KARATSUBA_MUL_CUTOFF = 80;      /* Min. number of digits before Karatsuba multiplication is used. */
const mp_int_size_type KARATSUBA_SQR_CUTOFF = 120;     /* Min. number of digits before Karatsuba squaring is used. */

const mp_int_size_type TOOM_MUL_CUTOFF      = 350;      /* no optimal values of these are known yet so set em high */
const mp_int_size_type TOOM_SQR_CUTOFF      = 400;

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
