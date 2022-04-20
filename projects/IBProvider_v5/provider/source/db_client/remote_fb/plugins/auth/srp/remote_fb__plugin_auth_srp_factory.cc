////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_srp_factory.cc
//! \brief   Фабрика класса плагина SRP-аутентификации
//! \author  Kovalenko Dmitry
//! \date    23.08.2016
#ifndef _remote_fb__plugin_auth_srp_factory_CC_
#define _remote_fb__plugin_auth_srp_factory_CC_

#include "source/db_client/remote_fb/plugins/auth/srp/remote_fb__plugin_auth_srp_p13.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace srp{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_Factory

template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>
 RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::sm_Instance;

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::RemoteFB__Plugin_Auth_SRP_Factory()
{
}

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::~RemoteFB__Plugin_Auth_SRP_Factory()
{
}

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_Auth_FactoryPtr
 RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::Create()
{
 return &sm_Instance;
}//Create

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
typename RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::name_type
 RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::GetName()
{
 return name_type::create<pName>();
}//GetName

//factory interface ------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
typename RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::name_type
 RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::get_name()const
{
 return self_type::GetName();
}//get_name

//------------------------------------------------------------------------
template<class SecureHashAlgorithms,const wchar_t* pName>
RemoteFB__Plugin_AuthPtr
 RemoteFB__Plugin_Auth_SRP_Factory<SecureHashAlgorithms,pName>::create_plugin()const
{
 return RemoteFB__Plugin_Auth_SRP_P13::Create<SecureHashAlgorithms,pName>();
}//create_plugin

////////////////////////////////////////////////////////////////////////////////
}/*nms srp*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
