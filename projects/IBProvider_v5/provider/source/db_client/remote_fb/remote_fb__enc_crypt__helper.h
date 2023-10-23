////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__enc_crypt__helper.h
//! \brief   Вспомогательные конструкции утилиты шифрования.
//! \author  Kovalenko Dmitry
//! \date    09.02.2015.
#ifndef _remote_fb__enc_crypt__helper_H_
#define _remote_fb__enc_crypt__helper_H_

#include "source/db_client/remote_fb/remote_fb__enc_crypt.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//Configuration

//
// define "MUST_ALIGN" if your compiler cannot load/store
// long integers at arbitrary (e.g. odd) memory locations.
// (Either that or never pass unaligned addresses to des_cipher!)
//
#define MUST_ALIGN

#ifdef CHAR_BITS
# if CHAR_BITS != 8
#  error C_block structure assumes 8 bit characters
# endif
#endif

////////////////////////////////////////////////////////////////////////////////
// Convert twenty-four-bit long in host-order
// to six bits (and 2 low-order zeroes) per char little-endian format.

#define TO_SIX_BIT(rslt, src)                     \
 {                                                \
  C_block cvt;                                    \
  cvt.b[0] = (unsigned char)src; src >>= 6;       \
  cvt.b[1] = (unsigned char)src; src >>= 6;       \
  cvt.b[2] = (unsigned char)src; src >>= 6;       \
  cvt.b[3] = (unsigned char)src;                  \
  rslt = (cvt.b32.i0 & 0x3f3f3f3fL) << 2;         \
 }

////////////////////////////////////////////////////////////////////////////////
//union RemoteFB__ENC_crypt::C_block

union RemoteFB__ENC_crypt::C_block LCPI_CPP_CFG__CLASS__FINAL
{
 unsigned char b[8];

 struct
 {
  /* long is often faster than a 32-bit bit field */
  SLONG i0;
  SLONG i1;
 } b32;
};//union RemoteFB__ENC_crypt::C_block

////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__ENC_crypt::C_block2

struct RemoteFB__ENC_crypt::C_block2 LCPI_CPP_CFG__CLASS__FINAL
{
 struct
 {
  /* long is often faster than a 32-bit bit field */
  SLONG i0;
  SLONG i1;
 } b32;
};//struct RemoteFB__ENC_crypt::C_block2

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ENC_crypt::tag_data

class RemoteFB__ENC_crypt::tag_data LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static const char c_PASSWORD_EFMT1='#';

  /* "small data" */
  static const size_t c_LGCHUNKBITS           =2;
  static const size_t c_CHUNKBITS             =(1<<c_LGCHUNKBITS);
  static const size_t c_LEFT_SHIFT_CHUNKBITS  =(1<<c_CHUNKBITS);

 public:
  /* encryption constant */
  static const C_block constdatablock;

 public:
  static const unsigned char Rotates[];

 public:
  static const unsigned char itoa64[];

 public: //Tables that are initialized at run time
  static const unsigned char a64toi[128];   /* ascii-64 => 0..63 */

  /* Initial key schedule permutation */
  static const C_block2 PC1ROT[64 / c_CHUNKBITS][c_LEFT_SHIFT_CHUNKBITS];

  /* Subsequent key schedule rotation permutations */
  static const C_block2 PC2ROT[2][64 / c_CHUNKBITS][c_LEFT_SHIFT_CHUNKBITS];

  /* Initial permutation/expansion table */
  static const C_block2 IE3264[32 / c_CHUNKBITS][c_LEFT_SHIFT_CHUNKBITS];

  /* Table that combines the S, P, and E operations.  */
  static const SLONG SPE[2][8][64];

  /* compressed/interleaved => final permutation table */
  static const C_block2 CF6464[64 / c_CHUNKBITS][c_LEFT_SHIFT_CHUNKBITS];
};//class RemoteFB__ENC_crypt::tag_data

////////////////////////////////////////////////////////////////////////////////
//struct RemoteFB__ENC_crypt::tag_ctx

struct RemoteFB__ENC_crypt::tag_ctx LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static const size_t c_KS_SIZE=16;

  C_block KS[c_KS_SIZE];
};//struct tag_ctx

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
