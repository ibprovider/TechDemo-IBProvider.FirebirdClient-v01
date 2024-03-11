////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__auth__srp_remote_password.h
//! \brief   Класс для генерации данных SRP-аутентификации.
//! \author  Kovalenko Dmitry
//! \date    08.07.2016
#ifndef _db_obj__dbms_fb__v03_0_0__auth__srp_remote_password_H_
#define _db_obj__dbms_fb__v03_0_0__auth__srp_remote_password_H_

#include "source/structure/ibp_biginteger.h"
#include "source/structure/ibp_sha1.h"
#include "source/ibp_forward.h"

#include <lcpi/lib/structure/t_const_str_box.h>

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj__dbms_fb__v03_0_0
//! @{
////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__auth__srp_remote_password_data

class fb_v03_0_0__auth__srp_remote_password_data
{
 public:
  static const unsigned SRP_KEY_SIZE      = 128;
  //static const unsigned SRP_VERIFIER_SIZE = SRP_KEY_SIZE;
  static const unsigned SRP_SALT_SIZE     = 32;

 public:
  static const unsigned char sm_primeStr[128];

  static const unsigned char sm_genStr[1];

  static const unsigned char sm_kStr[20];
};//class fb_v03_0_0__auth__srp_remote_password_data

////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__auth__srp_remote_password

/// <summary>
///  Класс для генерации данных SRP-аутентификации.
/// </summary>
template<class SecureHashAlgorithms>
class fb_v03_0_0__auth__srp_remote_password
 :private fb_v03_0_0__auth__srp_remote_password_data
{
 private:
  typedef fb_v03_0_0__auth__srp_remote_password            self_type;

  fb_v03_0_0__auth__srp_remote_password(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef IBP_BigInteger::bytes_type                       bytes_type;

 public:
  /// <summary>
  ///  Конструктор по-умолчанию.
  /// </summary>
  fb_v03_0_0__auth__srp_remote_password();

  /// <summary>
  ///  Деструктор.
  /// </summary>
 ~fb_v03_0_0__auth__srp_remote_password();

  //interface ------------------------------------------------------------
  std::string getClientKey()const;

  void calcClientSessionKeyAndProof
        (bytes_type*                     pSessionKey,
         std::string*                    pClientProof,
         lib::structure::t_const_str_box account,
         lib::structure::t_const_str_box salt,
         lib::structure::t_const_str_box password,
         const char*                     serverPubKey)const;

 private:
  typedef sha1::IBP_Sha1          sha1_type;
  typedef SecureHashAlgorithms    shaX_type;

 private:
  static IBP_BigInteger helper__getUserHash
                         (structure::t_const_str_box account,
                          structure::t_const_str_box salt,
                          structure::t_const_str_box password);

 private:
  template<class SHA>
  static IBP_BigInteger helper__getInt
               (SHA* pSHA);

  template<class SHA>
  static void helper__processInt(bytes_type&           tmp_bytes,
                                 const IBP_BigInteger& data,
                                 SHA*                  pSHA);

  template<class SHA>
  static void helper__processStrippedInt
               (bytes_type&           tmp_bytes,
                const IBP_BigInteger& data,
                SHA*                  pSHA);

 private:
  const IBP_BigInteger m_group_prime;
  const IBP_BigInteger m_group_generator;
  const IBP_BigInteger m_group_k;

  IBP_BigInteger       m_privateKey;
  IBP_BigInteger       m_clientPublicKey;
};//class fb_v03_0_0__auth__srp_remote_password

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__auth__srp_remote_password.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
