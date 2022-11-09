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
 * Tom St Denis, tomstdenis@gmail.com, http://math.libtomcrypt.com
 */
#ifndef _ibp_external__libtommath_set01__tommath_H_
#define _ibp_external__libtommath_set01__tommath_H_

#include <string>

namespace lcpi{namespace ibp{namespace external{namespace libtommath{namespace set01{
/////////////////////////////////////////////////////////////////////////////////

typedef unsigned long         mp_digit;
typedef unsigned __int64      mp_word;

/////////////////////////////////////////////////////////////////////////////////

typedef size_t mp_int_size_type;

/////////////////////////////////////////////////////////////////////////////////

typedef int mp_int_sign_type;

enum
{
 MP_ZPOS  = 0, // positive integer
 MP_NEG   = 1, // negative
};//enum

////////////////////////////////////////////////////////////////////////////////
//Result codes

typedef int mp_err;

enum
{
 MP_OKAY    =   0,      // ok result
 MP_MEM     =  -2,      // out of mem
 MP_VAL     =  -3,      // invalid input
 MP_RANGE   =  MP_VAL,
};//enum

////////////////////////////////////////////////////////////////////////////////

enum
{
 MP_LT = -1,   // less than
 MP_EQ =  0,   // equal to
 MP_GT =  1,   // greater than
};//enum

////////////////////////////////////////////////////////////////////////////////
//struct mp_int

struct mp_int
{
 public: //typedefs ------------------------
  typedef mp_int_size_type    size_type;
  typedef mp_int_sign_type    sign_type;

 public:
  size_type used;

  size_type alloc;

  sign_type sign;

  mp_digit* dp;
};//struct mp_int

////////////////////////////////////////////////////////////////////////////////

std::wstring mp_dump_w(const mp_int* x);

////////////////////////////////////////////////////////////////////////////////

/* init a bignum */
void mp_init_v3(mp_int* a);

/* free a bignum */
void mp_clear_v3(mp_int* a);

////////////////////////////////////////////////////////////////////////////////

/* copy, b = a */
mp_err mp_copy(const mp_int* a, mp_int* b);

////////////////////////////////////////////////////////////////////////////////

/* compare a to b */
int mp_cmp(const mp_int* a, const mp_int* b);

////////////////////////////////////////////////////////////////////////////////

/* c = a + b */
mp_err mp_add(const mp_int* a, const mp_int* b, mp_int* c);

/* c = a - b */
mp_err mp_sub(const mp_int* a, const mp_int* b, mp_int* c);

/* c = a * b */
mp_err mp_mul(const mp_int* a, const mp_int* b, mp_int* c);

/* b = a*a  */
mp_err mp_sqr(const mp_int* a, mp_int* b);

/* a/b => cb + d == a */
mp_err mp_div(const mp_int* a, const mp_int* b, mp_int* c, mp_int* d);

/* c = a mod b, 0 <= c < b  */
mp_err mp_mod(const mp_int* a, const mp_int* b, mp_int* c);

////////////////////////////////////////////////////////////////////////////////

/* d = a**b (mod c) */
mp_err mp_exptmod(const mp_int* a, const mp_int* b, const mp_int* c, mp_int* d);

////////////////////////////////////////////////////////////////////////////////

mp_err mp_read_unsigned_bin_v2(mp_int* a, const unsigned char* b, size_t c);

size_t mp_unsigned_bin_size_v2(const mp_int* a);

mp_err mp_to_unsigned_bin(const mp_int* a, unsigned char* b);

////////////////////////////////////////////////////////////////////////////////

mp_err mp_read_radix(mp_int* a, const char* str, mp_digit radix);

mp_err mp_toradix_n(const mp_int*  a, char* str, mp_digit radix, size_t maxlen);

mp_err mp_radix_size(const mp_int* a, int radix, size_t* size);

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
