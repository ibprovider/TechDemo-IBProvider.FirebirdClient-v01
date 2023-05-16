////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_sha2.h
//! \brief   Класс для работы с SHA2
//! \author  Kovalenko Dmitry
//! \date    22.05.2019
#ifndef _ibp_sha2_H_
#define _ibp_sha2_H_

#include "source/ibp_memory.h"

#include <structure/t_const_str_box.h>
#include <structure/t_simple_buffer.h>

#include <array>

namespace lcpi{namespace ibp{namespace sha2{
////////////////////////////////////////////////////////////////////////////////

//
// The IBP_Sha2_Base class is an abstract class that is the ancestor for all
// the SHA-2 classes. It defines all public methods for the classes and
// a common model of use.
//
// When instatiated a SHA-2 class is already initialized for use. The message
// for which a digest is required is then fed to the class using one of
// the "process" methods, either as a single action or accumulatively.
//
// When the entire message has been input, the resulting digest is returned
// by a "getHash" method. Calling "getHash" also clears the digest and
// re-initializes the SHA-2 generator ready to compute a new digest.
//
// A SHA-2 generator can be cleared down and re-initialized at any time
// by calling the "reset" method.
//

////////////////////////////////////////////////////////////////////////////////

class IBP_Sha224_Traits;
class IBP_Sha256_Traits;
class IBP_Sha384_Traits;
class IBP_Sha512_Traits;

////////////////////////////////////////////////////////////////////////////////

static const size_t SHA224_DIGEST_SIZE  = ( 224 / 8);
static const size_t SHA256_DIGEST_SIZE  = ( 256 / 8);
static const size_t SHA384_DIGEST_SIZE  = ( 384 / 8);
static const size_t SHA512_DIGEST_SIZE  = ( 512 / 8);

static const size_t SHA256_BLOCK_SIZE   = ( 512 / 8);
static const size_t SHA512_BLOCK_SIZE   = (1024 / 8);
static const size_t SHA224_BLOCK_SIZE   = ( SHA256_BLOCK_SIZE );
static const size_t SHA384_BLOCK_SIZE   = ( SHA512_BLOCK_SIZE );

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha2_Result

class IBP_Sha2_Result
{
 public: //typedefs ------------------------------------------------------
  typedef structure::t_typed_simple_buffer<unsigned char,IBP_MemoryAllocator> data_type;

 public:
  data_type m_value;

 public: //selectors -----------------------------------------------------
  size_t size() const
  {
   return m_value.size();
  }//size

  const unsigned char* data() const
  {
   return m_value.buffer();
  }//data
};//class IBP_Sha2_Result

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha2_Types

class IBP_Sha2_Types
{
 public: //typedefs ------------------------------------------------------
  typedef unsigned char        uint8;
  typedef unsigned int         uint32;
  typedef unsigned long long   uint64;
};//class IBP_Sha2_Types

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha2_Base

template<class SHA_TRAITS>
class IBP_Sha2_Base LCPI_CPP_CFG__CLASS__FINAL:private IBP_Sha2_Types
{
 private:
  typedef IBP_Sha2_Base<SHA_TRAITS>      self_type;

  IBP_Sha2_Base(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef IBP_Sha2_Result                SHA_RESULT;

 private:
  typedef typename SHA_TRAITS::ctx_type  ctx_type;

 public:
  IBP_Sha2_Base();

 ~IBP_Sha2_Base();

 public:
  void reset();

  void process(size_t length, const void* bytes);

  void process_str(structure::t_const_str_box str);

  void get_hash(SHA_RESULT* hash);

 private:
  enum enum_state
  {
   state__active   =0,
   state__finished =1,
  };

  typedef enum_state  state_type;

 private:
  state_type m_state;

 private:
  ctx_type m_ctx;
};//class IBP_Sha2_Base

////////////////////////////////////////////////////////////////////////////////

typedef IBP_Sha2_Base<IBP_Sha224_Traits> IBP_Sha224;
typedef IBP_Sha2_Base<IBP_Sha256_Traits> IBP_Sha256;
typedef IBP_Sha2_Base<IBP_Sha384_Traits> IBP_Sha384;
typedef IBP_Sha2_Base<IBP_Sha512_Traits> IBP_Sha512;

////////////////////////////////////////////////////////////////////////////////
//struct IBP_Sha256_Ctx

struct IBP_Sha256_Ctx LCPI_CPP_CFG__CLASS__FINAL:private IBP_Sha2_Types
{
 public:
  typedef IBP_Sha2_Types::uint32 uint32;

  typedef std::array<uint32,8>   h_type;

 public:
  size_t        tot_len;
  size_t        len;
  unsigned char block[2*SHA256_BLOCK_SIZE];
  h_type        h;

 public:
  void transfer(const unsigned char* message,
                size_t               block_nb);
};//class IBP_Sha256_Ctx

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha224_Traits

class IBP_Sha224_Traits LCPI_CPP_CFG__CLASS__FINAL:private IBP_Sha2_Types
{
 public:
  typedef IBP_Sha256_Ctx ctx_type;

 public:
  static void sha_init(ctx_type *ctx);

  static void sha_clear(ctx_type *ctx);

  static void sha_update(ctx_type*            ctx,
                         size_t               length,
                         const unsigned char* message);

  static void sha_final(ctx_type*        ctx,
                        IBP_Sha2_Result* digest);
};//class IBP_Sha224_Traits

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha256_Traits

class IBP_Sha256_Traits LCPI_CPP_CFG__CLASS__FINAL:private IBP_Sha2_Types
{
 public:
  typedef IBP_Sha256_Ctx ctx_type;

 public:
  static void sha_init(ctx_type* ctx);

  static void sha_clear(ctx_type* ctx);

  static void sha_update(ctx_type*            ctx,
                         size_t               length,
                         const unsigned char* message);

  static void sha_final(ctx_type*        ctx,
                        IBP_Sha2_Result* digest);
};//class IBP_Sha256_Traits

////////////////////////////////////////////////////////////////////////////////
//struct IBP_Sha512_Ctx

struct IBP_Sha512_Ctx LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  typedef IBP_Sha2_Types::uint64 uint64;

  typedef std::array<uint64,8>   h_type;

 public:
  size_t        tot_len;
  size_t        len;
  unsigned char block[2*SHA512_BLOCK_SIZE];
  h_type        h;

 public:
  void transfer(const unsigned char* message,
                size_t               block_nb);
};//class IBP_Sha512_Ctx

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha384_Traits

class IBP_Sha384_Traits LCPI_CPP_CFG__CLASS__FINAL:private IBP_Sha2_Types
{
 public:
  typedef IBP_Sha512_Ctx ctx_type;

 public:
  static void sha_init(ctx_type* ctx);

  static void sha_clear(ctx_type* ctx);

  static void sha_update(ctx_type*            ctx,
                         size_t               length,
                         const unsigned char* message);

  static void sha_final(ctx_type*        ctx,
                        IBP_Sha2_Result* digest);
};//class IBP_Sha384_Traits

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha512_Traits

class IBP_Sha512_Traits LCPI_CPP_CFG__CLASS__FINAL:private IBP_Sha2_Types
{
 public:
  typedef IBP_Sha512_Ctx ctx_type;

 public:
  static void sha_init(ctx_type* ctx);

  static void sha_clear(ctx_type* ctx);

  static void sha_update(ctx_type*            ctx,
                         size_t               length,
                         const unsigned char* message);

  static void sha_final(ctx_type*        ctx,
                        IBP_Sha2_Result* digest);
};//class IBP_Sha512_Traits

////////////////////////////////////////////////////////////////////////////////
}/*nms sha2*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/structure/ibp_sha2.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
