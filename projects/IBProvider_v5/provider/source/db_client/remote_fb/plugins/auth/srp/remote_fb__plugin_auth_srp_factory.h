////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_srp_factory.h
//! \brief   Фабрика класса плагина SRP-аутентификации
//! \author  Kovalenko Dmitry
//! \date    23.08.2016
#ifndef _remote_fb__plugin_auth_srp_factory_H_
#define _remote_fb__plugin_auth_srp_factory_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth_factory.h"

#include "source/structure/ibp_sha1.h"
#include "source/structure/ibp_sha2.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace srp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_Factory

template<class SecureHashAlgorithms,const wchar_t* pName>
class RemoteFB__Plugin_Auth_SRP_Factory
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__Plugin_Auth_Factory)
{
 private:
  typedef RemoteFB__Plugin_Auth_SRP_Factory     self_type;

  RemoteFB__Plugin_Auth_SRP_Factory(const self_type&);
  self_type& operator = (const self_type&);

 private:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  RemoteFB__Plugin_Auth_SRP_Factory();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~RemoteFB__Plugin_Auth_SRP_Factory();

 public:
  static RemoteFB__Plugin_Auth_FactoryPtr Create();

  static name_type GetName();

  //factory interface ----------------------------------------------------
  virtual name_type get_name()const COMP_W000004_OVERRIDE_FINAL;

  virtual RemoteFB__Plugin_AuthPtr create_plugin()const COMP_W000004_OVERRIDE_FINAL;

 private:
  /// Единственный экземпляр класса
  static self_type sm_Instance;
};//class RemoteFB__Plugin_Auth_SRP_Factory

////////////////////////////////////////////////////////////////////////////////
//typedefs

using RemoteFB__Plugin_Auth_SRP_Factory__SRP
 =RemoteFB__Plugin_Auth_SRP_Factory<sha1::IBP_Sha1,ibprovider::ibp_propval__remote__auth__Srp>;

using RemoteFB__Plugin_Auth_SRP_Factory__SRP224
 =RemoteFB__Plugin_Auth_SRP_Factory<sha2::IBP_Sha224,ibprovider::ibp_propval__remote__auth__Srp224>;

using RemoteFB__Plugin_Auth_SRP_Factory__SRP256
 =RemoteFB__Plugin_Auth_SRP_Factory<sha2::IBP_Sha256,ibprovider::ibp_propval__remote__auth__Srp256>;

using RemoteFB__Plugin_Auth_SRP_Factory__SRP384
 =RemoteFB__Plugin_Auth_SRP_Factory<sha2::IBP_Sha384,ibprovider::ibp_propval__remote__auth__Srp384>;

using RemoteFB__Plugin_Auth_SRP_Factory__SRP512
 =RemoteFB__Plugin_Auth_SRP_Factory<sha2::IBP_Sha512,ibprovider::ibp_propval__remote__auth__Srp512>;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms srp*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/db_client/remote_fb/plugins/auth/srp/remote_fb__plugin_auth_srp_factory.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
