////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_sha1.cpp
//! \brief   Класс для работы с SHA1
//! \author  Kovalenko Dmitry
//! \date    01.06.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/structure/ibp_sha1.h"
#include <structure/t_zero.h>

namespace lcpi{namespace ibp{namespace sha1{
////////////////////////////////////////////////////////////////////////////////

// NIST Secure Hash Algorithm
// heavily modified by Uwe Hollerbach <uh@alumni.caltech edu>
// from Peter C. Gutmann's implementation as found in
// Applied Cryptography by Bruce Schneier
// This code is in the public domain

// Adapted and added to firebird svn tree - A.Peshkov, 2004

////////////////////////////////////////////////////////////////////////////////

/* (PD) 2001 The Bitzi Corporation
 * Please see file COPYING or http://web.archive.org/web/20120315075909/http://bitzi.com/publicdomain
 * for more info.
 *
 * NIST Secure Hash Algorithm
 * heavily modified by Uwe Hollerbach <uh@alumni.caltech edu>
 * from Peter C. Gutmann's implementation as found in
 * Applied Cryptography by Bruce Schneier
 * Further modifications to include the "UNRAVEL" stuff, below
 *
 * This code is in the public domain
 *
 */

// UNRAVEL should be fastest & biggest
// UNROLL_LOOPS should be just as big, but slightly slower
// both undefined should be smallest and slowest

////////////////////////////////////////////////////////////////////////////////

#define UNRAVEL
//#define UNROLL_LOOPS

////////////////////////////////////////////////////////////////////////////////
// SHA f()-functions

#define f1(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define f2(x, y, z) ((x) ^ (y) ^ (z))
#define f3(x, y, z) (((x) & (y)) | ((x) & (z)) | ((y) & (z)))
#define f4(x, y, z) ((x) ^ (y) ^ (z))

////////////////////////////////////////////////////////////////////////////////
// SHA constants

#define SHA1__CONST1      0x5a827999L
#define SHA1__CONST2      0x6ed9eba1L
#define SHA1__CONST3      0x8f1bbcdcL
#define SHA1__CONST4      0xca62c1d6L

////////////////////////////////////////////////////////////////////////////////
// truncate to 32 bits -- should be a null op on 32-bit machines

#define T32(x)  ((x) & 0xffffffffL)

// 32-bit rotate

#define R32(x, n)   T32((((x) << (n)) | ((x) >> (32 - (n)))))

// the generic case, for when the overall rotation is not unraveled

#define FG(n)   \
    T = T32(R32(A, 5) + f##n(B, C, D) + E + *(WP++) + SHA1__CONST##n);  \
    E = D; D = C; C = R32(B, 30); B = A; A = T

// specific cases, for when the overall rotation is unraveled

#define FA(n)   \
    T = T32(R32(A, 5) + f##n(B, C, D) + E + *(WP++) + SHA1__CONST##n); B = R32(B, 30)

#define FB(n)   \
    E = T32(R32(T, 5) + f##n(A, B, C) + D + *(WP++) + SHA1__CONST##n); A = R32(A, 30)

#define FC(n)   \
    D = T32(R32(E, 5) + f##n(T, A, B) + C + *(WP++) + SHA1__CONST##n); T = R32(T, 30)

#define FD(n)   \
    C = T32(R32(D, 5) + f##n(E, T, A) + B + *(WP++) + SHA1__CONST##n); E = R32(E, 30)

#define FE(n)   \
    B = T32(R32(C, 5) + f##n(D, E, T) + A + *(WP++) + SHA1__CONST##n); D = R32(D, 30)

#define FT(n)   \
    A = T32(R32(B, 5) + f##n(C, D, E) + T + *(WP++) + SHA1__CONST##n); C = R32(C, 30)

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha1

IBP_Sha1::IBP_Sha1()
{
 this->helper__sha_init();
}//IBP_Sha1

//------------------------------------------------------------------------
IBP_Sha1::~IBP_Sha1()
{
 //в целях безопасности
 this->helper__sha_clear();
}//IBP_Sha1

//------------------------------------------------------------------------
void IBP_Sha1::reset()
{
 this->helper__sha_init();
}//reset

//------------------------------------------------------------------------
void IBP_Sha1::process(size_t      const length,
                       const void* const bytes)
{
 assert(m_state==self_type::state__active);

 CHECK_READ_PTR(bytes,length);

 this->helper__sha_update
        (length,
         reinterpret_cast<const unsigned char*>(bytes));
}//process

//------------------------------------------------------------------------
void IBP_Sha1::process_str(structure::t_const_str_box const str)
{
 assert(m_state==self_type::state__active);

 CHECK_READ_PTR(str.ptr,str.len);

 this->helper__sha_update
        (str.byte_count(),
         reinterpret_cast<const unsigned char*>(str.ptr));
}//process_str

//------------------------------------------------------------------------
void IBP_Sha1::get_hash(SHA_RESULT* const hash)
{
 assert(hash);

 this->helper__sha_final();

 assert(m_state==self_type::state__finished);

 hash->m_value[ 0] = (unsigned char) ((m_handle.digest[0] >> 24) & 0xff);
 hash->m_value[ 1] = (unsigned char) ((m_handle.digest[0] >> 16) & 0xff);
 hash->m_value[ 2] = (unsigned char) ((m_handle.digest[0] >>  8) & 0xff);
 hash->m_value[ 3] = (unsigned char) ((m_handle.digest[0]      ) & 0xff);
 hash->m_value[ 4] = (unsigned char) ((m_handle.digest[1] >> 24) & 0xff);
 hash->m_value[ 5] = (unsigned char) ((m_handle.digest[1] >> 16) & 0xff);
 hash->m_value[ 6] = (unsigned char) ((m_handle.digest[1] >>  8) & 0xff);
 hash->m_value[ 7] = (unsigned char) ((m_handle.digest[1]      ) & 0xff);
 hash->m_value[ 8] = (unsigned char) ((m_handle.digest[2] >> 24) & 0xff);
 hash->m_value[ 9] = (unsigned char) ((m_handle.digest[2] >> 16) & 0xff);
 hash->m_value[10] = (unsigned char) ((m_handle.digest[2] >>  8) & 0xff);
 hash->m_value[11] = (unsigned char) ((m_handle.digest[2]      ) & 0xff);
 hash->m_value[12] = (unsigned char) ((m_handle.digest[3] >> 24) & 0xff);
 hash->m_value[13] = (unsigned char) ((m_handle.digest[3] >> 16) & 0xff);
 hash->m_value[14] = (unsigned char) ((m_handle.digest[3] >>  8) & 0xff);
 hash->m_value[15] = (unsigned char) ((m_handle.digest[3]      ) & 0xff);
 hash->m_value[16] = (unsigned char) ((m_handle.digest[4] >> 24) & 0xff);
 hash->m_value[17] = (unsigned char) ((m_handle.digest[4] >> 16) & 0xff);
 hash->m_value[18] = (unsigned char) ((m_handle.digest[4] >>  8) & 0xff);
 hash->m_value[19] = (unsigned char) ((m_handle.digest[4]      ) & 0xff);
}//get_hash

//------------------------------------------------------------------------
void IBP_Sha1::helper__sha_init()
{
 m_state = self_type::state__active;

 //---------
 m_handle.digest[0] = 0x67452301L;
 m_handle.digest[1] = 0xefcdab89L;
 m_handle.digest[2] = 0x98badcfeL;
 m_handle.digest[3] = 0x10325476L;
 m_handle.digest[4] = 0xc3d2e1f0L;

 m_handle.bytes_count = 0;

 m_handle.local       = 0;

 //! \todo
 //!  Раскомментировать?
 //std::fill(sha_info->data, _END_(sha_info->data), structure::zero);
}//helper__sha_init

//------------------------------------------------------------------------
void IBP_Sha1::helper__sha_clear()
{
 m_state = self_type::state__active;

 //---------
 m_handle.digest[0] = 0;
 m_handle.digest[1] = 0;
 m_handle.digest[2] = 0;
 m_handle.digest[3] = 0;
 m_handle.digest[4] = 0;

 m_handle.bytes_count = 0;

 m_handle.local       = 0;

 std::fill(m_handle.data, _END_(m_handle.data), structure::zero);
}//helper__sha_clear

//------------------------------------------------------------------------
void IBP_Sha1::helper__sha_transform()
{
 assert(m_state==self_type::state__active);

 W_TYPE W;

 /*
    the following makes sure that at least one code block below is
    traversed or an error is reported, without the necessity for nested
    preprocessor if/else/endif blocks, which are a great pain in the
    nether regions of the anatomy...
 */
 
 this->helper__sha_transform__build_W(W);

 //-----------------------------------------
 for(unsigned i=16;i<80;++i)
 {
  W[i]=W[i-3] ^ W[i-8] ^ W[i-14] ^ W[i-16];

//#if (SHA_VERSION == 1)
  
  assert_s(SHA_VERSION==1);
  
  W[i] = R32(W[i], 1);
//#endif // SHA_VERSION
 }//for

 SHA_ULONG A = m_handle.digest[0];
 SHA_ULONG B = m_handle.digest[1];
 SHA_ULONG C = m_handle.digest[2];
 SHA_ULONG D = m_handle.digest[3];
 SHA_ULONG E = m_handle.digest[4];

 W_TYPE::iterator WP=W.begin();

 SHA_ULONG T;

#ifdef UNRAVEL

 FA(1); FB(1); FC(1); FD(1); FE(1); FT(1); FA(1); FB(1); FC(1); FD(1);
 FE(1); FT(1); FA(1); FB(1); FC(1); FD(1); FE(1); FT(1); FA(1); FB(1);
 FC(2); FD(2); FE(2); FT(2); FA(2); FB(2); FC(2); FD(2); FE(2); FT(2);
 FA(2); FB(2); FC(2); FD(2); FE(2); FT(2); FA(2); FB(2); FC(2); FD(2);
 FE(3); FT(3); FA(3); FB(3); FC(3); FD(3); FE(3); FT(3); FA(3); FB(3);
 FC(3); FD(3); FE(3); FT(3); FA(3); FB(3); FC(3); FD(3); FE(3); FT(3);
 FA(4); FB(4); FC(4); FD(4); FE(4); FT(4); FA(4); FB(4); FC(4); FD(4);
 FE(4); FT(4); FA(4); FB(4); FC(4); FD(4); FE(4); FT(4); FA(4); FB(4);

 assert(WP==W.end());

 m_handle.digest[0] = T32(m_handle.digest[0] + E);
 m_handle.digest[1] = T32(m_handle.digest[1] + T);
 m_handle.digest[2] = T32(m_handle.digest[2] + A);
 m_handle.digest[3] = T32(m_handle.digest[3] + B);
 m_handle.digest[4] = T32(m_handle.digest[4] + C);

#else // !UNRAVEL
#ifdef UNROLL_LOOPS

 FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1);
 FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1); FG(1);
 FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2);
 FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2); FG(2);
 FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3);
 FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3); FG(3);
 FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4);
 FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4); FG(4);

#else // !UNROLL_LOOPS

 for (unsigned i =  0; i < 20; ++i) { FG(1); }
 for (unsigned i = 20; i < 40; ++i) { FG(2); }
 for (unsigned i = 40; i < 60; ++i) { FG(3); }
 for (unsigned i = 60; i < 80; ++i) { FG(4); }

#endif // !UNROLL_LOOPS

 m_handle.digest[0] = T32(m_handle.digest[0] + A);
 m_handle.digest[1] = T32(m_handle.digest[1] + B);
 m_handle.digest[2] = T32(m_handle.digest[2] + C);
 m_handle.digest[3] = T32(m_handle.digest[3] + D);
 m_handle.digest[4] = T32(m_handle.digest[4] + E);

#endif // !UNRAVEL
}//helper__sha_transform

//------------------------------------------------------------------------
//update the SHA digest

void IBP_Sha1::helper__sha_update(size_t               count,
                                  const unsigned char* buffer)
{
 assert(m_state==self_type::state__active);

 //! \note
 //!  Мы забиваем на факт возможного переполнения m_handle.bytes_count

 m_handle.bytes_count+=count;

 if(m_handle.local)
 {
  assert_s(sizeof(m_handle.data)==SHA_BLOCKSIZE);

  assert(m_handle.local<=SHA_BLOCKSIZE);

  size_t i=(SHA_BLOCKSIZE-m_handle.local);

  if(i>count)
   i=count;

  assert(i<=count);

  assert(m_handle.local<=sizeof(m_handle.data));
  assert(i<=(sizeof(m_handle.data)-m_handle.local));

  memcpy(m_handle.data+m_handle.local, buffer, i);

  count-=i;

  buffer+=i;

  m_handle.local+=i;

  assert(m_handle.local<=SHA_BLOCKSIZE);

  if(m_handle.local<SHA_BLOCKSIZE)
   return;

  this->helper__sha_transform();
 }//if m_handle.local
 
 assert_s(sizeof(m_handle.data)==SHA_BLOCKSIZE);

 while(count>=SHA_BLOCKSIZE)
 {
  memcpy(m_handle.data, buffer, SHA_BLOCKSIZE);

  buffer+=SHA_BLOCKSIZE;

  count-=SHA_BLOCKSIZE;

  this->helper__sha_transform();
 }//while

 assert_hint(count<SHA_BLOCKSIZE);

 memcpy(m_handle.data, buffer, count);

 m_handle.local=count;
}//helper__sha_update

//------------------------------------------------------------------------
void IBP_Sha1::helper__sha_final()
{
 assert_s(sizeof(SHA_LENGTH)==8);
 assert_s(sizeof(SHA_ULONG)==4);

 if(m_state==self_type::state__finished)
  return;

 assert(m_state==self_type::state__active);

 assert(m_handle.local<SHA_BLOCKSIZE);

 assert_s(SHA_BLOCKSIZE==_DIM_(m_handle.data));

 m_handle.data[m_handle.local++]=0x80;

 assert(m_handle.local<=SHA_BLOCKSIZE);

 assert_s(8<SHA_BLOCKSIZE);

 if((SHA_BLOCKSIZE-8)<m_handle.local)
 {
  assert_s(sizeof(m_handle.data)==SHA_BLOCKSIZE);

  std::fill(m_handle.data+m_handle.local,
            _END_(m_handle.data),
            structure::zero);

  this->helper__sha_transform();

  std::fill(m_handle.data,
            _END_(m_handle.data)-8,
            structure::zero);
 }
 else
 {
  assert(m_handle.local<=(SHA_BLOCKSIZE-8));

  assert_s(sizeof(m_handle.data)==SHA_BLOCKSIZE);

  std::fill(m_handle.data+m_handle.local,
            _END_(m_handle.data)-8,
            structure::zero);
 }//else

 assert_s(63<SHA_BLOCKSIZE);

 const SHA_LENGTH bits_count=(m_handle.bytes_count<<3);

 m_handle.data[56] = (unsigned char) ((bits_count >> 56) & 0xff);
 m_handle.data[57] = (unsigned char) ((bits_count >> 48) & 0xff);
 m_handle.data[58] = (unsigned char) ((bits_count >> 40) & 0xff);
 m_handle.data[59] = (unsigned char) ((bits_count >> 32) & 0xff);
 m_handle.data[60] = (unsigned char) ((bits_count >> 24) & 0xff);
 m_handle.data[61] = (unsigned char) ((bits_count >> 16) & 0xff);
 m_handle.data[62] = (unsigned char) ((bits_count >>  8) & 0xff);
 m_handle.data[63] = (unsigned char) ((bits_count >>  0) & 0xff);

 this->helper__sha_transform();

 m_state=self_type::state__finished;
}//helper__sha_final

////////////////////////////////////////////////////////////////////////////////
}/*nms sha1*/}/*nms ibp*/}/*nms lcpi*/
