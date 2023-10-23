////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_srp_p13.cc
//! \brief   Реализация плагина для SRP-аутентификации [Firebird 3.0]
//! \author  Kovalenko Dmitry
//! \date    29.05.2019
#ifndef _remote_fb__plugin_auth_srp_p13_CC_
#define _remote_fb__plugin_auth_srp_p13_CC_

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace srp{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_P13_Data_Impl

template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::RemoteFB__Plugin_Auth_SRP_P13_Data_Impl()
{
}//RemoteFB__Plugin_Auth_SRP_P13_Data_Impl

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::~RemoteFB__Plugin_Auth_SRP_P13_Data_Impl()
{
}//~RemoteFB__Plugin_Auth_SRP_P13_Data_Impl

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
typename RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::self_ptr
 RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::Create()
{
 return lib::structure::not_null_ptr(new self_type());
}//Create

//RemoteFB__Plugin_Auth_SRP_P13_Data interface ---------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
typename RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::name_type
 RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::getPluginName()const
{
 return name_type::create<pName>();
}//getPluginName

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
std::string RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::getClientKey()const
{
 return m_RemotePswd.getClientKey();
}//getClientKey

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
void RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::calcClientSessionKeyAndProof
                                              (bytes_type*                const pSessionKey,
                                               std::string*               const pClientProof,
                                               structure::t_const_str_box const account,
                                               structure::t_const_str_box const salt,
                                               structure::t_const_str_box const password,
                                               const char*                const serverPubKey)const
{
 return m_RemotePswd.calcClientSessionKeyAndProof
         (pSessionKey,
          pClientProof,
          account,
          salt,
          password,
          serverPubKey);
}//calcClientSessionKeyAndProof

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_P13

template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_AuthPtr
 RemoteFB__Plugin_Auth_SRP_P13::Create()
{
 const data_ptr
  spData
   (RemoteFB__Plugin_Auth_SRP_P13_Data_Impl<SecureHashAlgorithms,pName>::Create());

 assert(spData);

 return lib::structure::not_null_ptr(new self_type(spData));
}//Create

////////////////////////////////////////////////////////////////////////////////
}/*nms srp*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
