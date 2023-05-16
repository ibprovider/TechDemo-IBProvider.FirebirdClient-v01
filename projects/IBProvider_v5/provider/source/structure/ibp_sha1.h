////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_sha1.h
//! \brief   Класс для работы с SHA1
//! \author  Kovalenko Dmitry
//! \date    01.06.2016
#ifndef _ibp_sha1_H_
#define _ibp_sha1_H_

#include "source/ibp_memory.h"
#include <structure/t_const_str_box.h>
#include <array>

namespace lcpi{namespace ibp{namespace sha1{
////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////

static const unsigned int SHA1_DIGESTSIZE=20;

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha1_Result

class IBP_Sha1_Result LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  typedef std::array<unsigned char,SHA1_DIGESTSIZE>  data_type;

 public: 
  data_type m_value;

 public: 
  //selectors ------------------------------------------------------------
  size_t size() const
  {
   return m_value.size();
  }//size

  const unsigned char* data() const
  {
   return m_value.data();
  }//data
};//class IBP_Sha1_Result

////////////////////////////////////////////////////////////////////////////////
//class IBP_Sha1

/// <summary>
///  Класс для работы с SHA1
/// </summary>
class IBP_Sha1 LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef IBP_Sha1                          self_type;

  IBP_Sha1(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef IBP_Sha1_Result                   SHA_RESULT;

 public:
  IBP_Sha1();

 ~IBP_Sha1();

  void reset();

  void process(size_t length, const void* bytes);

  void process_str(structure::t_const_str_box str);

  void get_hash(SHA_RESULT* hash);

 private:
  static const unsigned int SHA_BLOCKSIZE=64;

  static const unsigned int SHA_W_SIZE=80;

  static const unsigned int SHA_VERSION=1;

 private:
  typedef unsigned __int32                  SHA_ULONG;
  typedef unsigned __int64                  SHA_LENGTH;

  typedef std::array<SHA_ULONG,SHA_W_SIZE>  W_TYPE;

  struct SHA_INFO
  {
   typedef std::array<SHA_ULONG,5>          digest_type;
   
   typedef unsigned __int64                 count_type;

   digest_type   digest;                // message digest
   SHA_LENGTH    bytes_count;    
   unsigned char data[SHA_BLOCKSIZE];   // SHA data buffer
   size_t        local;                 // unprocessed amount in data
  };//struct SHA_INFO

 private:
  void helper__clear();

 private:
  //initialize the SHA digest
  void helper__sha_init();
  
  void helper__sha_clear();

  void helper__sha_transform();

  void helper__sha_transform__build_W(W_TYPE& W)const;

  //finish computing the SHA digest
  void helper__sha_update(size_t               count,
                          const unsigned char* buffer);

  void helper__sha_final();

 private:
  enum enum_state
  {
   state__active   =0,
   state__finished =1,
  };

  typedef enum_state  state_type;

 private:
  state_type m_state;

  SHA_INFO m_handle;
};//class IBP_Sha1

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms sha1*/}/*nms ibp*/}/*nms lcpi*/
#endif
