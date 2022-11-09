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

static int s_is_power_of_two(mp_digit          const b,
                             mp_int_size_type* const p)
{
 (*p) = 0;

 /* fast return if no power of two */
 if((b == 0) || (b & (b - 1)))
 {
  return 0;
 }

 for(mp_int_size_type x = 0; x != MP_DIGIT_BIT; ++x)
 {
  if(b == (((mp_digit)1) << x))
  {
   (*p) = x;

   return 1;
  }
 }//for

 return 0;
}//s_is_power_of_two

//------------------------------------------------------------------------

/* single digit division (based on routine from MPI) */
mp_err mp_div_d(const mp_int* const a,
                mp_digit      const b,
                mp_int*       const c,
                mp_digit*     const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)

#ifndef NDEBUG
 if(c)
  mp_debug__check_int__light(c);
#endif

 /* cannot divide by zero */
 if(b == 0)
 {
  return MP_VAL;
 }

 assert_hint(b>0);

 /* quick outs */
 if((b == 1) || (mp_iszero(a) == 1)) //! \todo use MP_YES
 {
  if(d != NULL)
  {
   (*d) = 0;
  }

  if(c != NULL)
  {
   return mp_copy(a, c);
  }

  return MP_OKAY;
 }//if

 assert_hint(b>1);

 /* power of two ? */
 {
  mp_int_size_type power_of_two;

  if(s_is_power_of_two(b, &power_of_two) == 1)
  {
   assert(power_of_two > 0);
   assert(power_of_two < MP_DIGIT_BIT);

   if(d != NULL)
   {
    (*d) = (a->dp[0] & ((((mp_digit)1) << power_of_two) - 1));
   }

   if(c != NULL)
   {
    return mp_div_2d(a, power_of_two, c, NULL);
   }

   return MP_OKAY;
  }//if
 }//local

 #ifdef BN_MP_DIV_3_C
 /* three? */
 if(b == 3)
 {
  return mp_div_3(a, c, d);
 }
 #endif

 /* no easy answer [c'est la vie].  Just division */
 mp_int_x q;

 mp_err res;

 if((res = mp_grow(&q, a->used)) != MP_OKAY)
  return res;

 assert_hint(res == MP_OKAY);

 q.used = a->used;
 q.sign = a->sign;

 mp_word w = 0;
 
 for(mp_int::size_type ix = a->used ; ix > 0;)
 {
  --ix;

  w = ((w << ((mp_word)MP_DIGIT_BIT)) | ((mp_word)a->dp[ix]));

  mp_digit t;

  if(w >= b)
  {
   t = (mp_digit)(w / b);

   w -= (((mp_word)t) * ((mp_word)b));
  }
  else
  {
   t = 0;
  }

  assert(t <= MP_DIGIT_MAX);

  q.dp[ix] = t;
 }//for

 if(d != NULL)
 {
  assert((w == 0) || (w > 0));
  assert(w <= MP_DIGIT_MAX);

  (*d) = (mp_digit)w;
 }//if

 if(c != NULL)
 {
  mp_clamp(&q);

  mp_exch(&q, c);
 }//if

 assert_hint(res == MP_OKAY);

 return res;
}//mp_div_d

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
