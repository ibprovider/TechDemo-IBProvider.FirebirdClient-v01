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

#ifdef BN_MP_DIV_SMALL

/* slower bit-bang division... also smaller */
int mp_div(const mp_int* a, const mp_int* b, mp_int* c, mp_int* d)
{
   mp_int ta, tb, tq, q;
   int    res, n, n2;

  /* is divisor zero ? */
  if (mp_iszero (b) == 1) {
    return MP_VAL;
  }

  /* if a < b then q=0, r = a */
  if (mp_cmp_mag (a, b) == MP_LT) {
    if (d != NULL) {
      res = mp_copy (a, d);
    } else {
      res = MP_OKAY;
    }
    if (c != NULL) {
      mp_zero (c);
    }
    return res;
  }

  /* init our temps */
  if ((res = mp_init_multi(&ta, &tb, &tq, &q, NULL) != MP_OKAY)) {
     return res;
  }


  mp_set(&tq, 1);
  n = mp_count_bits(a) - mp_count_bits(b);
  if (((res = mp_abs(a, &ta)) != MP_OKAY) ||
      ((res = mp_abs(b, &tb)) != MP_OKAY) ||
      ((res = mp_mul_2d(&tb, n, &tb)) != MP_OKAY) ||
      ((res = mp_mul_2d(&tq, n, &tq)) != MP_OKAY)) {
      goto LBL_ERR;
  }

  while (n-- >= 0) {
     if (mp_cmp(&tb, &ta) != MP_GT) {
        if (((res = mp_sub(&ta, &tb, &ta)) != MP_OKAY) ||
            ((res = mp_add(&q, &tq, &q)) != MP_OKAY)) {
           goto LBL_ERR;
        }
     }
     if (((res = mp_div_2d(&tb, 1, &tb, NULL)) != MP_OKAY) ||
         ((res = mp_div_2d(&tq, 1, &tq, NULL)) != MP_OKAY)) {
           goto LBL_ERR;
     }
  }

  /* now q == quotient and ta == remainder */
  n  = a->sign;
  n2 = (a->sign == b->sign ? MP_ZPOS : MP_NEG);
  if (c != NULL) {
     mp_exch(c, &q);
     c->sign  = (mp_iszero(c) == MP_YES) ? MP_ZPOS : n2;
  }
  if (d != NULL) {
     mp_exch(d, &ta);
     d->sign = (mp_iszero(d) == MP_YES) ? MP_ZPOS : n;
  }
LBL_ERR:
   mp_clear_multi(&ta, &tb, &tq, &q, NULL);
   return res;
}

#else

/* integer signed division.
 * c*b + d == a [e.g. a/b, c=quotient, d=remainder]
 * HAC pp.598 Algorithm 14.20
 *
 * Note that the description in HAC is horribly
 * incomplete.  For example, it doesn't consider
 * the case where digits are removed from 'x' in
 * the inner loop.  It also doesn't consider the
 * case that y has fewer than three digits, etc..
 *
 * The overall algorithm is as described as
 * 14.20 from HAC but fixed to treat these cases.
*/
mp_err mp_div(const mp_int* const a,
              const mp_int* const b,
              mp_int*       const c,
              mp_int*       const d)
{
 DEBUG_CODE(mp_debug__check_int__total(a);)
 DEBUG_CODE(mp_debug__check_int__total(b);)

#ifndef NDEBUG
 if(c)
  mp_debug__check_int__light(c);

 if(d)
  mp_debug__check_int__light(d);
#endif

 /* is divisor zero ? */
 if(mp_iszero(b) == 1)
 {
  return MP_VAL;
 }

 assert(b->used > 0);

 /* if a < b then q=0, r = a */
 mp_err res;

 if(mp_cmp_mag(a, b) == MP_LT)
 {
  if(d != NULL)
  {
   res = mp_copy(a, d);
  }
  else
  {
   res = MP_OKAY;
  }

  if(c != NULL)
  {
   mp_zero(c);
  }

  return res;
 }//if

 assert(b->used > 0); //again
 assert(a->used > 0);
 assert(a->used >= b->used);

 mp_int_x q, x, y, t1, t2;

 //-----------
 if((res = mp_grow(&q, a->used + 2)) != MP_OKAY)
  return res;

 q.used = (a->used + 2);

 //-----------
 // if((res = mp_grow(&t1, 2)) != MP_OKAY)
 //  return res;

 //-----------
 // if((res = mp_grow(&t2, 3)) != MP_OKAY)
 //  return res;

 //-----------
 if((res = mp_copy(a, &x)) != MP_OKAY)
  return res;

 if((res = mp_copy(b, &y)) != MP_OKAY)
  return res;

 //-----------

 /* fix the sign */
 const mp_int::sign_type neg = (a->sign == b->sign) ? MP_ZPOS : MP_NEG;

 x.sign = y.sign = MP_ZPOS;

 /* normalize both x and y, ensure that y >= b/2, [b == 2**MP_DIGIT_BIT] */
 mp_int::size_type total_bits_in_y = 0;

 if((res = mp_count_bits_v2(&y, &total_bits_in_y)) != MP_OKAY)
  return res;

 assert(total_bits_in_y > 0); // y!=0

 mp_int::size_type norm = (total_bits_in_y % MP_DIGIT_BIT);

 assert_hint(norm < MP_DIGIT_BIT);

 if(norm < (MP_DIGIT_BIT - 1))
 {
  norm = ((MP_DIGIT_BIT - 1) - norm);

  assert_hint(norm > 0);

  if((res = mp_mul_2d(&x, norm, &x)) != MP_OKAY)
   return res;

  if((res = mp_mul_2d(&y, norm, &y)) != MP_OKAY)
   return res;
 }
 else
 {
  assert_hint(norm == (MP_DIGIT_BIT - 1));
  
  norm = 0;
 }//else

 /* note hac does 0 based, so if used==5 then its 0,1,2,3,4, e.g. use 4 */

 // [2016-05-29] Research asserts
 assert(x.used > 0);
 assert(y.used > 0);

 const mp_int::size_type n = (x.used - 1);
 const mp_int::size_type t = (y.used - 1);

 // [2016-05-29] Research asserts
 assert(t <= n);

 /* while (x >= y*b**n-t) do { q[n-t] += 1; x -= y*b**{n-t} } */
 if((res = mp_lshd(&y, n - t)) != MP_OKAY)
 {
  /* y = y*b**{n-t} */
  return res;
 }//if

 while(mp_cmp(&x, &y) != MP_LT)
 {
  ++(q.dp[n - t]);

  if((res = mp_sub(&x, &y, &x)) != MP_OKAY)
   return res;
 }//while

 /* reset y by shifting it back down */
 assert(t <= n);

 mp_rshd(&y, n - t);

 /* step 3. for i from n down to (t + 1) */
 //for(int i = n; i >= (t + 1); i--)
 for(mp_int::size_type i = n; i > t; --i)
 {
  assert_hint(i > 0);

  DEBUG_CODE(mp_debug__check_int__total(&x));

  if(i > x.used)
  {
   continue;
  }

  assert((i == x.used) || (i < x.used));

  assert_hint(x.used > 0); // [2017-03-14] Research assert

  assert(i < x.alloc); // [2017-03-14] Research assert. Can be removed. See get_safe
  assert(t < y.used);

  /* step 3.1 if xi == yt then set q{i-t-1} to b-1,
   * otherwise set q{i-t-1} to (xi*b + x{i-1})/yt */
  if(x.get_safe(i) == y.dp[t])
  {
   assert_hint(i > t);
   assert((i - t - 1) < q.alloc);
   assert((i - t - 1) < q.used);  // [2016-05-30] Research

   q.dp[i - t - 1] = ((((mp_digit)1) << MP_DIGIT_BIT) - 1);
  }
  else
  {
   mp_word tmp;

   assert_hint(i > 0);

   tmp  = ((mp_word)x.get_safe(i)) << ((mp_word)MP_DIGIT_BIT);
   tmp |= ((mp_word)x.dp[i - 1]);
   tmp /= ((mp_word)y.dp[t]);

   if (tmp > (mp_word)MP_MASK)
    tmp = MP_MASK;

   assert_hint(i > t);
   assert((i - t - 1) < q.alloc);
   assert((i - t - 1) < q.used);  // [2016-05-30] Research

   q.dp[i - t - 1] = (mp_digit)(tmp & (mp_word)(MP_MASK));
  }//else

  /* while (q{i-t-1} * (yt * b + y{t-1})) >
           xi * b**2 + xi-1 * b + xi-2

     do q{i-t-1} -= 1;
  */

  assert_hint(i > t);
  assert((i - t - 1) < q.alloc);
  assert((i - t - 1) < q.used);  // [2016-05-30] Research

  q.dp[i - t - 1] = (q.dp[i - t - 1] + 1) & MP_MASK;

  do
  {
   assert_hint(i > t);
   assert((i - t - 1) < q.alloc);
   assert((i - t - 1) < q.used);  // [2016-05-30] Research

   q.dp[i - t - 1] = (q.dp[i - t - 1] - 1) & MP_MASK;

   /* find left hand */
   if((res = mp_grow(&t1, 2)) != MP_OKAY)
    return res;

   mp_zero(&t1);

   assert(t1.alloc >= 2);

   assert(t < y.used);

   //assert(y.dp[t] != 0); //[2016-12-05]

   t1.dp[0] = (t < 1) ? 0 : y.dp[t - 1];
   t1.dp[1] = y.dp[t];
   t1.used  = 2;

   mp_clamp(&t1); // [2017-03-14]

   if((res = mp_mul_d(&t1, q.dp[i - t - 1], &t1)) != MP_OKAY)
    return res;

   /* find right hand */
   if((res = mp_grow(&t2, 3)) != MP_OKAY)
    return res;

   assert(t2.alloc >= 3);

   assert(t2.used <= 3); //[2016-05-30]

   assert(i < x.alloc); // [2017-03-14] Research assert. Can be removed. See get_safe

   //assert(x.dp[i] != 0); //[2016-12-05]

   //[2018-12-24] Research
   assert_hint(i > t); //Again
   assert_hint(i > 0); //So

   t2.dp[0] = (i < 2) ? 0 : x.dp[i - 2];
   t2.dp[1] = (i < 1) ? 0 : x.dp[i - 1]; // [2018-12-24] Always = x.dp[i - 1];
   t2.dp[2] = x.get_safe(i);
   t2.used  = 3;

   //[2018-12-24] Research
   assert(t2.dp[1]==x.dp[i - 1]);

   mp_clamp(&t2);  // [2017-03-14]
  }
  while (mp_cmp_mag(&t1, &t2) == MP_GT);

  /* step 3.3 x = x - q{i-t-1} * y * b**{i-t-1} */
  assert_hint(i > t);
  assert((i - t - 1) < q.alloc);
  assert((i - t - 1) < q.used);  // [2016-05-30] Research

  if((res = mp_mul_d(&y, q.dp[i - t - 1], &t1)) != MP_OKAY)
   return res;

  assert_hint(i > t);

  if((res = mp_lshd(&t1, i - t - 1)) != MP_OKAY)
   return res;

  if((res = mp_sub(&x, &t1, &x)) != MP_OKAY)
   return res;

  /* if x < 0 then { x = x + y*b**{i-t-1}; q{i-t-1} -= 1; } */
  if(x.sign == MP_NEG)
  {
   if((res = mp_copy(&y, &t1)) != MP_OKAY)
    return res;

   assert_hint(i > t);

   if((res = mp_lshd(&t1, i - t - 1)) != MP_OKAY)
    return res;

   if((res = mp_add(&x, &t1, &x)) != MP_OKAY)
    return res;

   assert_hint(i > t);
   assert((i - t - 1) < q.alloc);
   assert((i - t - 1) < q.used);  // [2016-05-30] Research

   q.dp[i - t - 1] = (q.dp[i - t - 1] - 1UL) & MP_MASK;
  }//if
 }//for i

 /* now q is the quotient and x is the remainder
  * [which we have to normalize]
  */

 /* get sign before writing to c */
 x.sign = ((x.used == 0) ? MP_ZPOS : a->sign);

 if(c != NULL)
 {
  mp_clamp(&q);

  mp_exch(&q, c);

  c->sign = neg;
 }//if

 if(d != NULL)
 {
  assert((norm == 0) || (norm > 0));

  if((res = mp_div_2d(&x, norm, &x, NULL)) != MP_OKAY)
   return res;

  mp_exch(&x, d);
 }//if

 assert(res == MP_OKAY);

#ifndef NDEBUG
 if(c)
  mp_debug__check_int__total(c);

 if(d)
  mp_debug__check_int__total(d);
#endif

 return MP_OKAY;
}//mp_div

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
