////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__enc_crypt.cpp
//! \brief   Утилита для шифрования.
//! \author  Kovalenko Dmitry
//! \date    09.02.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__enc_crypt__helper.h"
#include <structure/t_numeric_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
/*
 * Cipher-block representation (Bob Baldwin):
 *
 * DES operates on groups of 64 bits, numbered 1..64 (sigh).  One
 * representation is to store one bit per byte in an array of bytes.  Bit N of
 * the NBS spec is stored as the LSB of the Nth byte (index N-1) in the array.
 * Another representation stores the 64 bits in 8 bytes, with bits 1..8 in the
 * first byte, 9..16 in the second, and so on.  The DES spec apparently has
 * bit 1 in the MSB of the first byte, but that is particularly noxious so we
 * bit-reverse each byte so that bit 1 is the LSB of the first byte, bit 8 is
 * the MSB of the first byte.  Specifically, the 64-bit input data and key are
 * converted to LSB format, and the output 64-bit block is converted back into
 * MSB format.
 *
 * DES operates internally on groups of 32 bits which are expanded to 48 bits
 * by permutation E and shrunk back to 32 bits by the S boxes.  To speed up
 * the computation, the expansion is applied only once, the expanded
 * representation is maintained during the encryption, and a compression
 * permutation is applied only at the end.  To speed up the S-box lookups,
 * the 48 bits are maintained as eight 6 bit groups, one per byte, which
 * directly feed the eight S-boxes.  Within each byte, the 6 bits are the
 * most significant ones.  The low two bits of each byte are zero.  (Thus,
 * bit 1 of the 48 bit E expansion is stored as the "4"-valued bit of the
 * first byte in the eight byte representation, bit 2 of the 48 bit value is
 * the "8"-valued bit, and so on.)  In fact, a combined "SPE"-box lookup is
 * used, in which the output is the 64 bit result of an S-box lookup which
 * has been permuted by P and expanded by E, and is ready for use in the next
 * iteration.  Two 32-bit wide tables, SPE[0] and SPE[1], are used for this
 * lookup.  Since each byte in the 48 bit path is a multiple of four, indexed
 * lookup of SPE[0] and SPE[1] is simple and fast.  The key schedule and
 * "salt" are also converted to this 8*(6+2) format.  The SPE table size is
 * 8*64*8 = 4K bytes.
 *
 * To speed up bit-parallel operations (such as XOR), the 8 byte
 * representation is "union"ed with 32 bit values "i0" and "i1", and, on
 * machines which support it, a 64 bit value "b64".  This data structure,
 * "C_block", has two problems.  First, alignment restrictions must be
 * honored.  Second, the byte-order (e.g. little-endian or big-endian) of
 * the architecture becomes visible.
 *
 * The byte-order problem is unfortunate, since on the one hand it is good
 * to have a machine-independent C_block representation (bits 1..8 in the
 * first byte, etc.), and on the other hand it is good for the LSB of the
 * first byte to be the LSB of i0.  We cannot have both these things, so we
 * currently use the "little-endian" representation and avoid any multi-byte
 * operations that depend on byte order.  This largely precludes use of the
 * 64-bit datatype since the relative order of i0 and i1 are unknown.  It
 * also inhibits grouping the SPE table to look up 12 bits at a time.  (The
 * 12 bits can be stored in a 16-bit field with 3 low-order zeroes and 1
 * high-order zero, providing fast indexing into a 64-bit wide SPE.)  On the
 * other hand, 64-bit datatypes are currently rare, and a 12-bit SPE lookup
 * requires a 128 kilobyte table, so perhaps this is not a big loss.
 *
 * Permutation representation (Jim Gillogly):
 *
 * A transformation is defined by its effect on each of the 8 bytes of the
 * 64-bit input.  For each byte we give a 64-bit output that has the bits in
 * the input distributed appropriately.  The transformation is then the OR
 * of the 8 sets of 64-bits.  This uses 8*256*8 = 16K bytes of storage for
 * each transformation.  Unless LARGEDATA is defined, however, a more compact
 * table is used which looks up 16 4-bit "chunks" rather than 8 8-bit chunks.
 * The smaller table uses 16*16*8 = 2K bytes for each transformation.  This
 * is slower but tolerable, particularly for password encryption in which
 * the SPE transformation is iterated many times.  The small tables total 9K
 * bytes, the large tables total 72K bytes.
 *
 * The transformations used are:
 * IE3264: MSB->LSB conversion, initial permutation, and expansion.
 *  This is done by collecting the 32 even-numbered bits and applying
 *  a 32->64 bit transformation, and then collecting the 32 odd-numbered
 *  bits and applying the same transformation.  Since there are only
 *  32 input bits, the IE3264 transformation table is half the size of
 *  the usual table.
 * CF6464: Compression, final permutation, and LSB->MSB conversion.
 *  This is done by two trivial 48->32 bit compressions to obtain
 *  a 64-bit block (the bit numbering is given in the "CIFP" table)
 *  followed by a 64->64 bit "cleanup" transformation.  (It would
 *  be possible to group the bits in the 64-bit block so that 2
 *  identical 32->32 bit transformations could be used instead,
 *  saving a factor of 4 in space and possibly 2 in time, but
 *  byte-ordering and other complications rear their ugly head.
 *  Similar opportunities/problems arise in the key schedule
 *  transforms.)
 * PC1ROT: MSB->LSB, PC1 permutation, rotate, and PC2 permutation.
 *  This admittedly baroque 64->64 bit transformation is used to
 *  produce the first code (in 8*(6+2) format) of the key schedule.
 * PC2ROT[0]: Inverse PC2 permutation, rotate, and PC2 permutation.
 *  It would be possible to define 15 more transformations, each
 *  with a different rotation, to generate the entire key schedule.
 *  To save space, however, we instead permute each code into the
 *  next by using a transformation that "undoes" the PC2 permutation,
 *  rotates the code, and then applies PC2.  Unfortunately, PC2
 *  transforms 56 bits into 48 bits, dropping 8 bits, so PC2 is not
 *  invertible.  We get around that problem by using a modified PC2
 *  which retains the 8 otherwise-lost bits in the unused low-order
 *  bits of each byte.  The low-order bits are cleared when the
 *  codes are stored into the key schedule.
 * PC2ROT[1]: Same as PC2ROT[0], but with two rotations.
 *  This is faster than applying PC2ROT[0] twice,
 *
 * The Bell Labs "salt" (Bob Baldwin):
 *
 * The salting is a simple permutation applied to the 48-bit result of E.
 * Specifically, if bit i (1 <= i <= 24) of the salt is set then bits i and
 * i+24 of the result are swapped.  The salt is thus a 24 bit number, with
 * 16777216 possible values.  (The original salt was 12 bits and could not
 * swap bits 13..24 with 36..48.)
 *
 * It is possible, but ugly, to warp the SPE table to account for the salt
 * permutation.  Fortunately, the conditional bit swapping requires only
 * about four machine instructions and can be done on-the-fly with about an
 * 8% performance penalty.
 */

////////////////////////////////////////////////////////////////////////////////

/*
 * These macros may someday permit efficient use of 64-bit integers.
 */
#define ZERO(d, d0, d1)                 d0 = 0, d1 = 0
#define LOAD(d, d0, d1, bl)             d0 = (bl).b32.i0, d1 = (bl).b32.i1
#define LOADREG(d, d0, d1, s, s0, s1)   d0 = s0, d1 = s1
#define OR(d, d0, d1, bl)               d0 |= (bl).b32.i0, d1 |= (bl).b32.i1
#define STORE(s, s0, s1, bl)            (bl).b32.i0 = s0, (bl).b32.i1 = s1
#define DCL_BLOCK(d, d0, d1)            SLONG d0, d1

#define PERM6464(d, d0, d1, cpp, p)         \
 { C_block tblk; helper__permute(cpp, &tblk, p, 8); LOAD (d, d0, d1, tblk); }

#define PERM3264(d, d0, d1, cpp, p)         \
 { C_block tblk; helper__permute(cpp, &tblk, p, 4); LOAD (d, d0, d1, tblk); }

//------------------------------------------------------------------------
// Create data consisting of the "setting" followed by
// an encryption produced by the "key" and "setting".

void RemoteFB__ENC_crypt::ENC_crypt(TEXT*  const buf,
                                    size_t const DEBUG_CODE(bufSize),
                                    const TEXT*  key,
                                    const TEXT*  setting)
{
 assert(key);
 assert(bufSize >= c_RESULT_SIZE);

 //-----------------------------------------------------------------------
 //int t;
 int num_iter;
 C_block keyblock;

 for (size_t i = 0; i != 8; ++i)
 {
  const auto t=(2*(unsigned char)(*key));

  if (t != 0)
      key++;

  structure::static_numeric_cast(&keyblock.b[i], t);
 }//for

 tag_ctx ctx;

 if (helper__des_setkey(ctx,keyblock.b)) /* also initializes "a64toi" */
 {
  buf[0] = 0;
  return;
 }

 TEXT* encp = buf;

 size_t salt_size2=0; 

 switch (*setting)
 {
  case tag_data::c_PASSWORD_EFMT1:
  {
   //Involve the rest of the password 8 characters at a time.

   while (*key)
   {
    if (helper__des_cipher(ctx, &keyblock, &keyblock, 0L, 1))
    {
        buf[0] = 0;
        return;
    }

    for (size_t i = 0; i != 8; ++i)
    {
        const auto t=(2 * (unsigned char) (*key));

        if (t != 0)
            key++;

        keyblock.b[i] ^= t;
    }//for

    if (helper__des_setkey(ctx, keyblock.b))
    {
        buf[0] = 0;
        return;
    }
   }//while

   *encp++ = *setting++;

   /* get iteration count */
   num_iter = 0;

   for (size_t i = 4; i != 0;)
   {
       --i;

       auto t=(unsigned char) setting[i];

       if (t == '\0')
           t = '.';

       encp[i] = t;

       num_iter = (num_iter << 6) | tag_data::a64toi[t];
   }//for

   setting += 4;

   encp += 4;

   salt_size2 = 4;

   break;
  }//case

  default:
   num_iter = 25;
   salt_size2 = 2;
 }//switch

 assert(salt_size2 > 0);

 SLONG salt = 0;

 for (size_t i = salt_size2; i != 0;)
 {
  --i;

  auto t=(unsigned char) setting[i];

  if (t == '\0')
      t = '.';

  encp[i] = t;

  salt = (salt << 6) | tag_data::a64toi[t];
 }//for

 encp += salt_size2;

 C_block rsltblock;

 // This constdatablock is never initialized, except by zeroes
 if (helper__des_cipher(ctx,&tag_data::constdatablock, &rsltblock, salt, num_iter))
 {
  buf[0] = 0;
  return;
 }

 /*
  * Encode the 64 cipher bits as 11 ascii characters.
  */
 /* i = ((SLONG)((rsltblock.b[0]<<8) | rsltblock.b[1])<<8) | rsltblock.b[2]; */
 SLONG i;

 ULONG a = rsltblock.b[0];
 a = a << 8;
 ULONG b = rsltblock.b[1];
 b |= a;
 b = b << 8;
 ULONG d = rsltblock.b[2];
 b |= d;
 i = b;
 encp[3] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[2] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[1] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[0] = tag_data::itoa64[i];
 encp += 4;

 /* i = ((SLONG)((rsltblock.b[3]<<8) | rsltblock.b[4])<<8) | rsltblock.b[5]; */
 a = rsltblock.b[3];
 a = a << 8;
 b = rsltblock.b[4];
 b |= a;
 b = b << 8;
 d = rsltblock.b[5];
 b |= d;
 i = b;
 encp[3] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[2] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[1] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[0] = tag_data::itoa64[i];
 encp += 4;

/*  i = ((SLONG)((rsltblock.b[6])<<8) | rsltblock.b[7])<<2; */
 a = rsltblock.b[6];
 a = a << 8;
 b = rsltblock.b[7];
 b |= a;
 b = b << 2;
 i = b;
 encp[2] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[1] = tag_data::itoa64[i & 0x3f];
 i >>= 6;
 encp[0] = tag_data::itoa64[i];

 encp[3] = 0;

 return;
}//ENC_crypt

//------------------------------------------------------------------------
//Set up the key schedule from the key.

int RemoteFB__ENC_crypt::helper__des_setkey(tag_ctx&       ctx,
                                            unsigned char* key)
{
 DCL_BLOCK(K, K0, K1);

 PERM6464(K, K0, K1, key, reinterpret_cast<const C_block*>(tag_data::PC1ROT));

 key = (unsigned char *) &ctx.KS[0];

 STORE(K & ~0x03030303L, K0 & ~0x03030303L, K1, *reinterpret_cast<C_block*>(key));

 for (int i = 1; i < 16; i++)
 {
  key += sizeof(C_block);

  STORE(K, K0, K1, *(C_block *) key);

  const C_block* ptabp = reinterpret_cast<const C_block*>(tag_data::PC2ROT[tag_data::Rotates[i] - 1]);

  PERM6464(K, K0, K1, key, ptabp);

  STORE(K & ~0x03030303L, K0 & ~0x03030303L, K1, *reinterpret_cast<C_block*>(key));
 }//for

 return (0);
}//helper__des_setkey

//------------------------------------------------------------------------
// Encrypt (or decrypt if num_iter < 0) the 8 chars at "in" with abs(num_iter)
// iterations of DES, using the the given 24-bit salt and the pre-computed key
// schedule, and store the resulting 8 chars at "out" (in == out is permitted).
//
// NOTE: the performance of this routine is critically dependent on your
// compiler and machine architecture.

int RemoteFB__ENC_crypt::helper__des_cipher(tag_ctx&             ctx,
                                            const C_block* const in,
                                            C_block*             out,
                                            SLONG                salt,
                                            int                  num_iter)
{
 /* variables that we want in registers, most important first */
 SLONG L1;
 C_block B;

 SLONG L0 = salt;
 TO_SIX_BIT(salt, L0);       /* convert to 4*(6+2) format */

#define SALT salt

#if defined(MUST_ALIGN)
 B.b[0] = in->b[0];
 B.b[1] = in->b[1];
 B.b[2] = in->b[2];
 B.b[3] = in->b[3];
 B.b[4] = in->b[4];
 B.b[5] = in->b[5];
 B.b[6] = in->b[6];
 B.b[7] = in->b[7];
 LOAD(L, L0, L1, B);
#else
 LOAD(L, L0, L1, *in);
#endif
 SLONG R0, R1;
 LOADREG(R, R0, R1, L, L0, L1);
 L0 &= 0x55555555L;
 L1 &= 0x55555555L;
 L0 = (L0 << 1) | L1;        /* L0 is the even-numbered input bits */
 R0 &= 0xaaaaaaaaL;
 R1 = (R1 >> 1) & 0x55555555L;
 L1 = R0 | R1;               /* L1 is the odd-numbered input bits */
 STORE(L, L0, L1, B);
 PERM3264(L, L0, L1, B.b, reinterpret_cast<const C_block*>(tag_data::IE3264));  /* even bits */
 PERM3264(R, R0, R1, B.b + 4, reinterpret_cast<const C_block *>(tag_data::IE3264)); /* odd bits */

 const C_block *kp;
 int ks_inc;

 if (num_iter >= 0)
 {       /* encryption */
     kp = &ctx.KS[0];
     ks_inc = sizeof(*kp);
 }
 else
 {                       /* decryption */
     num_iter = -num_iter;
     kp = &ctx.KS[ctx.c_KS_SIZE - 1];
     ks_inc = -(int) sizeof(*kp);
 }

 SLONG k;
 while (--num_iter >= 0)
 {
  int loop_count = 8;

  do
  {
#define SPTAB(t, i) (*reinterpret_cast<const SLONG *>(reinterpret_cast<const unsigned char *>(t) + i * (sizeof(SLONG) / 4)))

            /* use this if "k" is allocated to a register ... */
#define DOXOR(x, y, i)  k = B.b[i]; x ^= SPTAB(tag_data::SPE[0][i], k); y ^= SPTAB(tag_data::SPE[1][i], k);

#define CRUNCH(p0, p1, q0, q1)                      \
            k = (q0 ^ q1) & SALT;                   \
            B.b32.i0 = k ^ q0 ^ kp->b32.i0;         \
            B.b32.i1 = k ^ q1 ^ kp->b32.i1;         \
            kp = reinterpret_cast<const C_block *>(reinterpret_cast<const char *>(kp) + ks_inc);  \
                                                    \
            DOXOR(p0, p1, 0);                       \
            DOXOR(p0, p1, 1);                       \
            DOXOR(p0, p1, 2);                       \
            DOXOR(p0, p1, 3);                       \
            DOXOR(p0, p1, 4);                       \
            DOXOR(p0, p1, 5);                       \
            DOXOR(p0, p1, 6);                       \
            DOXOR(p0, p1, 7);

   CRUNCH(L0, L1, R0, R1);
   CRUNCH(R0, R1, L0, L1);

#undef CRUNCH
#undef DOXOR
#undef SPTAB
  }
  while (--loop_count != 0);

  kp = reinterpret_cast<const C_block *>(reinterpret_cast<const char *>(kp) - (ks_inc * ctx.c_KS_SIZE));

  /* swap L and R */
  L0 ^= R0;
  L1 ^= R1;
  R0 ^= L0;
  R1 ^= L1;
  L0 ^= R0;
  L1 ^= R1;
 }//while

 /* store the encrypted (or decrypted) result */
 L0 = ((L0 >> 3) & 0x0f0f0f0fL) | ((L1 << 1) & 0xf0f0f0f0L);
 L1 = ((R0 >> 3) & 0x0f0f0f0fL) | ((R1 << 1) & 0xf0f0f0f0L);

 STORE(L, L0, L1, B);

 PERM6464(L, L0, L1, B.b, reinterpret_cast<const C_block *>(tag_data::CF6464));

#if defined(MUST_ALIGN)
 STORE(L, L0, L1, B);
 out->b[0] = B.b[0];
 out->b[1] = B.b[1];
 out->b[2] = B.b[2];
 out->b[3] = B.b[3];
 out->b[4] = B.b[4];
 out->b[5] = B.b[5];
 out->b[6] = B.b[6];
 out->b[7] = B.b[7];
#else
 STORE(L, L0, L1, *out);
#endif

#undef SALT

 return (0);
}//helper__des_cipher

//------------------------------------------------------------------------
void RemoteFB__ENC_crypt::helper__permute(const unsigned char* cp,
                                          C_block*             out,
                                          const C_block*       p,
                                          int                  chars_in)
{
 DCL_BLOCK(D, D0, D1);

 ZERO(D, D0, D1);

 do
 {
  const int t = *cp++;

  const C_block* tp = &p[t & 0xf];

  OR(D, D0, D1, *tp);

  p += (tag_data::c_LEFT_SHIFT_CHUNKBITS);

  tp = &p[t >> 4];

  OR(D, D0, D1, *tp);

  p += (tag_data::c_LEFT_SHIFT_CHUNKBITS);
 }
 while (--chars_in > 0);

 STORE(D, D0, D1, *out);
}//helper__permute

#undef ZERO
#undef STORE

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
