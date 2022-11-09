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
#ifndef _ibp_external__libtommath_set01__tommath_private_H_
#define _ibp_external__libtommath_set01__tommath_private_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath.h"
#include "source/external/libtommath/set01/ibp_external__libtommath_set01__tommath_class.h"

namespace lcpi{namespace ibp{namespace external{namespace libtommath{namespace set01{
////////////////////////////////////////////////////////////////////////////////
//Configuration

// MP_CFG__USE_DEBUG_MEM
//  0 - direct usage of malloc/realloc/free
//  1 - usage of special debug version of malloc/realloc/free

////////////////////////////////////////////////////////////////////////////////
//Default configuration

//------------------------------------------------------------------------
#ifndef MP_CFG__USE_DEBUG_MEM

#if !defined(NDEBUG) && defined(IBP_BUILD_TESTCODE)
# define MP_CFG__USE_DEBUG_MEM              1
#else
# define MP_CFG__USE_DEBUG_MEM              0
#endif

#endif // ndefined MP_CFG__USE_DEBUG_MEM

////////////////////////////////////////////////////////////////////////////////

#ifndef MIN
   #define MIN(x,y) ((x)<(y)?(x):(y))
#endif

#ifndef MAX
   #define MAX(x,y) ((x)>(y)?(x):(y))
#endif

/* C++ compilers don't like assigning void* to mp_digit* */
#define  OPT_CAST(x)  (x*)

////////////////////////////////////////////////////////////////////////////////

/* define heap functions */

void* mp_mem__malloc  (size_t n); // throw
void  mp_mem__free    (void* p);

#if(MP_CFG__USE_DEBUG_MEM!=0 && !defined(NDEBUG))
 void mp_mem__debug_check_block(const void* p);
#endif

////////////////////////////////////////////////////////////////////////////////

static const size_t   MP_DIGIT_BIT    = ((CHAR_BIT * sizeof(mp_digit)) - 4);

static const mp_digit MP_MASK         = ((((mp_digit)1)<<((mp_digit)MP_DIGIT_BIT))-((mp_digit)1));

static const mp_digit MP_DIGIT_MAX    = MP_MASK;

//////////////////////////////////////////////////////////////////////////

#define MP_YES        1   /* yes response */
#define MP_NO         0   /* no response */

/* Primality generation flags */
#define LTM_PRIME_BBS      0x0001 /* BBS style prime */
#define LTM_PRIME_SAFE     0x0002 /* Safe prime (p-1)/2 == prime */
#define LTM_PRIME_2MSB_ON  0x0008 /* force 2nd MSB to 1 */

/* you'll have to tune these... */
extern const mp_int_size_type KARATSUBA_MUL_CUTOFF;
extern const mp_int_size_type KARATSUBA_SQR_CUTOFF;
extern const mp_int_size_type TOOM_MUL_CUTOFF;
extern const mp_int_size_type TOOM_SQR_CUTOFF;

/* define this to use lower memory usage routines (exptmods mostly) */
/* #define MP_LOW_MEM */

/* default precision */
#ifndef MP_PREC
   #ifndef MP_LOW_MEM
      #define MP_PREC                 32     /* default digits of precision */
   #else
      #define MP_PREC                 8      /* default digits of precision */
   #endif
#endif

/* size of comba arrays, should be at least 2 * 2**(BITS_PER_WORD - BITS_PER_DIGIT*2) */
static const size_t MP_WARRAY = (1 << (sizeof(mp_word) * CHAR_BIT - 2 * MP_DIGIT_BIT + 1));

/* callback for mp_prime_random, should fill dst with random bytes and return how many read [upto len] */
typedef int ltm_prime_callback(unsigned char *dst, int len, void *dat);

//#define USED(m)    ((m)->used)
//#define DIGIT(m,k) ((m)->dp[(k)])
//#define SIGN(m)    ((m)->sign)

/* error code to char* string */
char* mp_error_to_string(int code);

/* ---> init and deinit bignum functions <--- */

/* init a null terminated series of arguments */
//int mp_init_multi_v2(mp_int* mp, ...);

/* clear a null terminated series of arguments */
//void mp_clear_multi(mp_int* mp, ...);

/* exchange two ints */
void mp_exch(mp_int* a, mp_int* b);

/* shrink ram required for a bignum */
int mp_shrink(mp_int* a);

/* grow an int to a given size */
mp_err mp_grow(mp_int* a, mp_int_size_type size);

/* init to a given number of digits */
//mp_err mp_init_size(mp_int* a, int size);

/* ---> Basic Manipulations <--- */
#define mp_iszero(a) (((a)->used == 0) ? MP_YES : MP_NO)
#define mp_iseven(a) (((a)->used > 0 && (((a)->dp[0] & 1) == 0)) ? MP_YES : MP_NO)
#define mp_isodd(a)  (((a)->used > 0 && (((a)->dp[0] & 1) == 1)) ? MP_YES : MP_NO)

/* set to zero */
void mp_zero(mp_int* a);

/* set to a digit */
mp_err mp_set_v2(mp_int* a, mp_digit b);

/* set a 32-bit const */
int mp_set_int(mp_int* a, unsigned long b);

/* get a 32-bit value */
unsigned long mp_get_int(mp_int*  a);

/* initialize and set a digit */
int mp_init_set (mp_int* a, mp_digit b);

/* initialize and set 32-bit value */
int mp_init_set_int (mp_int* a, unsigned long b);

/* inits and copies, a = b */
// WITH_BUG: int mp_init_copy(mp_int* a, mp_int* b);

/* trim unused digits */
void mp_clamp(mp_int* a);

/* ---> digit manipulation <--- */

/* right shift by "b" digits */
void mp_rshd(mp_int* a, mp_int_size_type b);

/* left shift by "b" digits */
mp_err mp_lshd(mp_int* a, mp_int_size_type b);

/* c = a / 2**b */
mp_err mp_div_2d(const mp_int* a, mp_int_size_type b, mp_int* c, mp_int* d);

/* b = a/2 */
mp_err mp_div_2(const mp_int* a, mp_int* b);

/* c = a * 2**b */
mp_err mp_mul_2d(const mp_int* a, mp_int_size_type b, mp_int* c);

/* b = a*2 */
mp_err mp_mul_2(const mp_int* a, mp_int* b);

/* c = a mod 2**d */
mp_err mp_mod_2d(const mp_int* a, mp_int_size_type b, mp_int* c);

/* computes a = 2**b */
mp_err mp_2expt(mp_int* a, mp_int_size_type b);

/* Counts the number of lsbs which are zero before the first zero bit */
int mp_cnt_lsb(mp_int* a);

/* I Love Earth! */

/* makes a pseudo-random int of a given size */
int mp_rand(mp_int* a, int digits);

/* ---> binary operations <--- */
/* c = a XOR b  */
int mp_xor(mp_int* a, mp_int* b, mp_int* c);

/* c = a OR b */
int mp_or(mp_int* a, mp_int* b, mp_int* c);

/* c = a AND b */
int mp_and(mp_int* a, mp_int* b, mp_int* c);

/* ---> Basic arithmetic <--- */

/* b = -a */
int mp_neg(const mp_int* a, mp_int* b);

/* b = |a| */
mp_err mp_abs(const mp_int* a, mp_int* b);

/* compare |a| to |b| */
int mp_cmp_mag(const mp_int* a, const mp_int* b);

/* ---> single digit functions <--- */

/* compare against a single digit */
int mp_cmp_d(const mp_int* a, mp_digit b);

/* c = a + b */
mp_err mp_add_d(const mp_int* a, mp_digit b, mp_int* c);

/* c = a - b */
mp_err mp_sub_d(const mp_int* a, mp_digit b, mp_int* c);

/* c = a * b */
mp_err mp_mul_d(const mp_int* a, mp_digit b, mp_int* c);

/* a/b => cb + d == a */
mp_err mp_div_d(const mp_int* a, const mp_digit b, mp_int* c, mp_digit* d);

/* a/3 => 3c + d == a */
mp_err mp_div_3(const mp_int* a, mp_int* c, mp_digit* d);

/* c = a**b */
int mp_expt_d(const mp_int* a, mp_digit b, mp_int* c);

/* c = a mod b, 0 <= c < b  */
int mp_mod_d(const mp_int* a, mp_digit b, mp_digit* c);

/* ---> number theory <--- */

/* d = a + b (mod c) */
int mp_addmod(mp_int* a, mp_int* b, mp_int* c, mp_int* d);

/* d = a - b (mod c) */
int mp_submod(mp_int* a, mp_int* b, mp_int* c, mp_int* d);

/* d = a * b (mod c) */
mp_err mp_mulmod(const mp_int* a, const mp_int* b, const mp_int* c, mp_int* d);

/* c = a * a (mod b) */
int mp_sqrmod(mp_int* a, mp_int* b, mp_int* c);

/* c = 1/a (mod b) */
mp_err mp_invmod(const mp_int* a, const mp_int* b, mp_int* c);

/* c = (a, b) */
int mp_gcd(mp_int* a, mp_int* b, mp_int* c);

/* produces value such that U1*a + U2*b = U3 */
int mp_exteuclid(mp_int* a, mp_int* b, mp_int* U1, mp_int* U2, mp_int* U3);

/* c = [a, b] or (a*b)/(a, b) */
int mp_lcm(mp_int* a, mp_int* b, mp_int* c);

/* finds one of the b'th root of a, such that |c|**b <= |a|
 *
 * returns error if a < 0 and b is even
 */
int mp_n_root(mp_int* a, mp_digit b, mp_int* c);

/* special sqrt algo */
int mp_sqrt(mp_int* arg, mp_int* ret);

/* is number a square? */
int mp_is_square(mp_int* arg, int* ret);

/* computes the jacobi c = (a | n) (or Legendre if b is prime)  */
int mp_jacobi(mp_int* a, mp_int* n, int* c);

/* used to setup the Barrett reduction for a given modulus b */
mp_err mp_reduce_setup(mp_int* a, const mp_int* b);

/* Barrett Reduction, computes a (mod b) with a precomputed value c
 *
 * Assumes that 0 < a <= b*b, note if 0 > a > -(b*b) then you can merely
 * compute the reduction as -1 * mp_reduce(mp_abs(a)) [pseudo code].
 */
mp_err mp_reduce(mp_int* a, const mp_int* b, const mp_int* c);

/* setups the montgomery reduction */
mp_err mp_montgomery_setup(const mp_int* a, mp_digit* mp);

/* computes a = B**n mod b without division or multiplication useful for
 * normalizing numbers in a Montgomery system.
 */
mp_err mp_montgomery_calc_normalization(mp_int* a, const mp_int* b);

/* computes x/R == x (mod N) via Montgomery Reduction */
mp_err mp_montgomery_reduce(mp_int* a, const mp_int* m, mp_digit mp);

/* returns 1 if a is a valid DR modulus */
int mp_dr_is_modulus(const mp_int* a);

/* sets the value of "d" required for mp_dr_reduce */
void mp_dr_setup(const mp_int* a, mp_digit* d);

/* reduces a modulo b using the Diminished Radix method */
mp_err mp_dr_reduce(mp_int* a, const mp_int* b, mp_digit mp);

/* returns true if a can be reduced with mp_reduce_2k */
int mp_reduce_is_2k(const mp_int* a);

/* determines k value for 2k reduction */
mp_err mp_reduce_2k_setup(const mp_int* a, mp_digit* d);

/* reduces a modulo b where b is of the form 2**p - k [0 <= a] */
mp_err mp_reduce_2k(mp_int* a, const mp_int* n, mp_digit d);

/* returns true if a can be reduced with mp_reduce_2k_l */
int mp_reduce_is_2k_l(const mp_int* a);

/* determines k value for 2k reduction */
mp_err mp_reduce_2k_setup_l(const mp_int* a, mp_int* d);

/* reduces a modulo b where b is of the form 2**p - k [0 <= a] */
mp_err mp_reduce_2k_l(mp_int* a, const mp_int* n, const mp_int* d);

/* ---> Primes <--- */

/* number of primes */
#ifdef MP_8BIT
   #define PRIME_SIZE      31
#else
   #define PRIME_SIZE      256
#endif

/* table of first PRIME_SIZE primes */
extern const mp_digit ltm_prime_tab[];

/* result=1 if a is divisible by one of the first PRIME_SIZE primes */
int mp_prime_is_divisible(mp_int* a, int* result);

/* performs one Fermat test of "a" using base "b".
 * Sets result to 0 if composite or 1 if probable prime
 */
int mp_prime_fermat(mp_int* a, mp_int* b, int* result);

/* performs one Miller-Rabin test of "a" using base "b".
 * Sets result to 0 if composite or 1 if probable prime
 */
int mp_prime_miller_rabin(mp_int* a, mp_int* b, int* result);

/* This gives [for a given bit size] the number of trials required
 * such that Miller-Rabin gives a prob of failure lower than 2^-96
 */
int mp_prime_rabin_miller_trials(int size);

/* performs t rounds of Miller-Rabin on "a" using the first
 * t prime bases.  Also performs an initial sieve of trial
 * division.  Determines if "a" is prime with probability
 * of error no more than (1/4)**t.
 *
 * Sets result to 1 if probably prime, 0 otherwise
 */
int mp_prime_is_prime(mp_int* a, int t, int* result);

/* finds the next prime after the number "a" using "t" trials
 * of Miller-Rabin.
 *
 * bbs_style = 1 means the prime must be congruent to 3 mod 4
 */
int mp_prime_next_prime(mp_int* a, int t, int bbs_style);

/* makes a truly random prime of a given size (bytes),
 * call with bbs = 1 if you want it to be congruent to 3 mod 4
 *
 * You have to supply a callback which fills in a buffer with random bytes.  "dat" is a parameter you can
 * have passed to the callback (e.g. a state or something).  This function doesn't use "dat" itself
 * so it can be NULL
 *
 * The prime generated will be larger than 2^(8*size).
 */
#define mp_prime_random(a, t, size, bbs, cb, dat) mp_prime_random_ex(a, t, ((size) * 8) + 1, ((bbs)==1)?LTM_PRIME_BBS:0, cb, dat)

/* makes a truly random prime of a given size (bits),
 *
 * Flags are as follows:
 *
 *   LTM_PRIME_BBS      - make prime congruent to 3 mod 4
 *   LTM_PRIME_SAFE     - make sure (p-1)/2 is prime as well (implies LTM_PRIME_BBS)
 *   LTM_PRIME_2MSB_OFF - make the 2nd highest bit zero
 *   LTM_PRIME_2MSB_ON  - make the 2nd highest bit one
 *
 * You have to supply a callback which fills in a buffer with random bytes.  "dat" is a parameter you can
 * have passed to the callback (e.g. a state or something).  This function doesn't use "dat" itself
 * so it can be NULL
 *
 */
int mp_prime_random_ex(mp_int* a, int t, int size, int flags, ltm_prime_callback cb, void *dat);

/* ---> radix conversion <--- */
mp_err mp_count_bits_v2(const mp_int* a,mp_int_size_type* c);

int mp_to_unsigned_bin_n (const mp_int* a, unsigned char* b, unsigned long* outlen);

int mp_signed_bin_size(mp_int* a);
int mp_read_signed_bin(mp_int* a, const unsigned char* b, int c);
int mp_to_signed_bin(mp_int* a,  unsigned char* b);
int mp_to_signed_bin_n (mp_int* a, unsigned char* b, unsigned long* outlen);

int mp_toradix(const mp_int* a, char* str, int radix);

int mp_fread(mp_int* a, int radix, FILE* stream);
int mp_fwrite(mp_int* a, int radix, FILE* stream);

#define mp_read_raw(mp, str, len) mp_read_signed_bin((mp), (str), (len))
#define mp_raw_size(mp)           mp_signed_bin_size(mp)
#define mp_toraw(mp, str)         mp_to_signed_bin((mp), (str))
#define mp_read_mag(mp, str, len) mp_read_unsigned_bin((mp), (str), (len))
#define mp_mag_size(mp)           mp_unsigned_bin_size(mp)
#define mp_tomag(mp, str)         mp_to_unsigned_bin((mp), (str))

#define mp_tobinary(M, S)  mp_toradix((M), (S), 2)
#define mp_tooctal(M, S)   mp_toradix((M), (S), 8)
#define mp_todecimal(M, S) mp_toradix((M), (S), 10)
#define mp_tohex(M, S)     mp_toradix((M), (S), 16)

/* lowlevel functions, do not call! */
mp_err s_mp_add(const mp_int* a, const mp_int* b, mp_int* c);
mp_err s_mp_sub(const mp_int* a, const mp_int* b, mp_int* c);
#define s_mp_mul(a, b, c) s_mp_mul_digs(a, b, c, (a)->used + (b)->used + 1)
mp_err fast_s_mp_mul_digs(const mp_int* a, const mp_int* b, mp_int* c, mp_int_size_type digs);
mp_err s_mp_mul_digs(const mp_int* a, const mp_int* b, mp_int* c, mp_int_size_type digs);
mp_err fast_s_mp_mul_high_digs(const mp_int* a, const mp_int* b, mp_int* c, mp_int_size_type digs);
mp_err s_mp_mul_high_digs(const mp_int* a, const mp_int* b, mp_int* c, mp_int_size_type digs);
mp_err fast_s_mp_sqr(const mp_int* a, mp_int* b);
mp_err s_mp_sqr(const mp_int* a, mp_int* b);
mp_err mp_karatsuba_mul(const mp_int* a, const mp_int* b, mp_int* c);
mp_err mp_toom_mul(const mp_int* a, const mp_int* b, mp_int* c);
mp_err mp_karatsuba_sqr(const mp_int* a, mp_int* b);
mp_err mp_toom_sqr(const mp_int* a, mp_int* b);
mp_err fast_mp_invmod (const mp_int* a, const mp_int* b, mp_int* c);
mp_err mp_invmod_slow (const mp_int* a, const mp_int* b, mp_int* c);
mp_err fast_mp_montgomery_reduce(mp_int* a, const mp_int* m, mp_digit mp);
mp_err mp_exptmod_fast(const mp_int* G, const mp_int* X, const mp_int* P, mp_int* Y, int mode);
mp_err s_mp_exptmod   (const mp_int* G, const mp_int* X, const mp_int* P, mp_int* Y, int mode);

#ifndef NDEBUG
void mp_debug__check_int__light(const mp_int* a);
void mp_debug__check_int__total(const mp_int* a);
#endif

char mp_upper7(char ch);

extern const char mp_s_rmap[64];

////////////////////////////////////////////////////////////////////////////////
//class mp_int_x

class mp_int_x:public mp_int
{
 private:
  typedef mp_int_x        self_type;

  mp_int_x(const self_type&);
  self_type& operator = (const self_type&);

 public:
  mp_int_x();

 ~mp_int_x();

  mp_digit get_safe(size_type const i)const
  {
   assert(this->used <= this->alloc);

   CHECK_READ_TYPED_PTR(this->dp,this->alloc);

   if(i < this->used)
    return this->dp[i];

   return 0;
  }//get_safe
};//class mp_int_x

////////////////////////////////////////////////////////////////////////////////
}/*nms set01*/}/*nms libtommath*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
