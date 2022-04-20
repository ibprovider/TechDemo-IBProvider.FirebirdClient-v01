////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj__dbms_fb__v03_0_0
//! \file    db_obj__dbms_fb__v03_0_0__auth__srp_remote_password.cc
//! \brief   Класс для генерации данных SRP-аутентификации.
//! \author  Kovalenko Dmitry
//! \date    08.07.2016
#ifndef _db_obj__dbms_fb__v03_0_0__auth__srp_remote_password_CC_
#define _db_obj__dbms_fb__v03_0_0__auth__srp_remote_password_CC_

namespace lcpi{namespace ibp{namespace db_obj{namespace dbms_fb{namespace v03_0_0{
////////////////////////////////////////////////////////////////////////////////
//class fb_v03_0_0__auth__srp_remote_password

template<class SecureHashAlgorithms>
fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::fb_v03_0_0__auth__srp_remote_password()
 :m_group_prime(_DIM_(sm_primeStr),sm_primeStr)
 ,m_group_generator(_DIM_(sm_genStr),sm_genStr)
 ,m_group_k(_DIM_(sm_kStr),sm_kStr)
{
 //SRP TEST
 //m_privateKey=IBP_BigInteger("60975527035CF2AD1989806F0407210BC81EDC04E2762A56AFD529DDDA2D4393",16);

 m_privateKey.random(self_type::SRP_KEY_SIZE);

 m_privateKey%=m_group_prime;

 m_clientPublicKey=this->m_group_generator.modPow(m_privateKey,m_group_prime);
}//fb_v03_0_0__auth__srp_remote_password

//------------------------------------------------------------------------
template<class SecureHashAlgorithms>
fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::~fb_v03_0_0__auth__srp_remote_password()
{
}

//interface --------------------------------------------------------------
template<class SecureHashAlgorithms>
std::string fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::getClientKey()const
{
 return this->m_clientPublicKey.get_text(16);
}//getClientKey

//------------------------------------------------------------------------
template<class SecureHashAlgorithms>
void fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::calcClientSessionKeyAndProof
                                           (bytes_type*                const pSessionKey,
                                            std::string*               const pClientProof,
                                            structure::t_const_str_box const account,
                                            structure::t_const_str_box const salt,
                                            structure::t_const_str_box const password,
                                            const char*                const serverPubKey)const
{
 assert(pSessionKey);
 assert(pClientProof);

 //---------
 const IBP_BigInteger serverPublicKey(serverPubKey,16);

 bytes_type tmp_bytes;

 //--------- computeScramble
 {
  sha1_type sha1;

  self_type::helper__processStrippedInt
   (tmp_bytes,
    m_clientPublicKey,
    &sha1);

  self_type::helper__processStrippedInt
   (tmp_bytes,
    serverPublicKey,
    &sha1);

  const IBP_BigInteger scramble=self_type::helper__getInt(&sha1);

  //---------
  const IBP_BigInteger x
   =self_type::helper__getUserHash
     (account,
      salt,
      password);                                                          // x

  //---------
  const IBP_BigInteger gx   = m_group_generator.modPow(x, m_group_prime); // g^x

  const IBP_BigInteger kgx  = (m_group_k * gx) % m_group_prime;           // kg^x

  const IBP_BigInteger diff = (serverPublicKey - kgx) % m_group_prime;    // B - kg^x

  const IBP_BigInteger ux   = (scramble * x) % m_group_prime;             // ux

  const IBP_BigInteger aux  = (m_privateKey + ux) % m_group_prime;        // A + ux

  const IBP_BigInteger sessionSecret=diff.modPow(aux, m_group_prime);     // (B - kg^x) ^ (a + ux)

  //--------
  sha1.reset();

  self_type::helper__processStrippedInt
   (tmp_bytes,
    sessionSecret,
    &sha1);

  sha1_type::SHA_RESULT sha1_hash;

  sha1.get_hash(&sha1_hash);

  memcpy(pSessionKey->alloc(sha1_hash.m_value.size()),
         sha1_hash.data(),
         sha1_hash.size());

  assert(pSessionKey->size()==sha1_hash.m_value.size());
 }//local

 //----------------------------------------- calculation clientProof
 // H(H(prime) ^ H(g), H(I), s, A, B, K)

 {
  sha1_type sha1;

  self_type::helper__processInt(tmp_bytes,m_group_prime,&sha1);

  IBP_BigInteger n1=self_type::helper__getInt(&sha1);

  sha1.reset();

  self_type::helper__processInt(tmp_bytes,m_group_generator,&sha1);

  IBP_BigInteger n2=self_type::helper__getInt(&sha1);

  n1=n1.modPow(n2,m_group_prime);

  sha1.reset();

  sha1.process_str(account);

  n2=self_type::helper__getInt(&sha1);

  shaX_type shaX;

  self_type::helper__processInt(tmp_bytes,n1,&shaX);                  // H(prime) ^ H(g)
  self_type::helper__processInt(tmp_bytes,n2,&shaX);                  // H(I)
  shaX.process_str(salt);                                             // s
  self_type::helper__processInt(tmp_bytes,m_clientPublicKey,&shaX);   // A
  self_type::helper__processInt(tmp_bytes,serverPublicKey,&shaX);     // B
  shaX.process(pSessionKey->size(),pSessionKey->buffer());            // K

  (*pClientProof)=self_type::helper__getInt(&shaX).get_text(16);
 }//local
}//calcClientSessionKeyAndProof

//helper methods ---------------------------------------------------------
template<class SecureHashAlgorithms>
IBP_BigInteger
 fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::helper__getUserHash
                                           (structure::t_const_str_box const account,
                                            structure::t_const_str_box const salt,
                                            structure::t_const_str_box const password)
{
 sha1_type sha1;

 //--------
 sha1.process_str(account);
 sha1.process_str(":");
 sha1.process_str(password);

 sha1_type::SHA_RESULT sha_hash;

 sha1.get_hash(&sha_hash);

 //--------
 sha1.reset();
 sha1.process_str(salt);
 sha1.process(sha_hash.size(),sha_hash.data());

 return helper__getInt(&sha1);
}//helper__getUserHash

//------------------------------------------------------------------------
template<class SecureHashAlgorithms>
template<class SHA>
IBP_BigInteger
 fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::helper__getInt
                                           (SHA* const pSHA)
{
 assert(pSHA);

 typename SHA::SHA_RESULT sha_hash;

 pSHA->get_hash(&sha_hash);

 return IBP_BigInteger(sha_hash.size(),sha_hash.data());
}//helper__getInt

//------------------------------------------------------------------------
template<class SecureHashAlgorithms>
template<class SHA>
void fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::helper__processInt
                                       (bytes_type&           tmp_bytes,
                                        const IBP_BigInteger& data,
                                        SHA*            const pSHA)
{
 assert(pSHA);

 data.get_unsigned_bin(tmp_bytes);

 pSHA->process(tmp_bytes.size(),tmp_bytes.buffer());
}//helper__processInt

//------------------------------------------------------------------------
template<class SecureHashAlgorithms>
template<class SHA>
void fb_v03_0_0__auth__srp_remote_password<SecureHashAlgorithms>::helper__processStrippedInt
                                           (bytes_type&           tmp_bytes,
                                            const IBP_BigInteger& data,
                                            SHA*            const pSHA)
{
 assert(pSHA);

 data.get_unsigned_bin(tmp_bytes);

 if(!tmp_bytes.empty())
 {
  const unsigned int n=(tmp_bytes[0]==0)?1u:0u;

  pSHA->process(tmp_bytes.size()-n,tmp_bytes.buffer()+n);
 }//if
}//helper__processStrippedInt

////////////////////////////////////////////////////////////////////////////////
}/*nms v03_0_0*/}/*nms dbms_fb*/}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
