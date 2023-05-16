////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_legacy_factory.h
//! \brief   ������� ������ ������� Legacy-��������������
//! \author  Kovalenko Dmitry
//! \date    27.08.2016
#ifndef _remote_fb__plugin_auth_legacy_factory_H_
#define _remote_fb__plugin_auth_legacy_factory_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth_factory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace legacy{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_Legacy_Factory

class RemoteFB__Plugin_Auth_Legacy_Factory
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__Plugin_Auth_Factory)
{
 private:
  typedef RemoteFB__Plugin_Auth_Legacy_Factory     self_type;

  RemoteFB__Plugin_Auth_Legacy_Factory(const self_type&);
  self_type& operator = (const self_type&);

 private:
  /// <summary>
  ///  ����������� ��-���������
  /// </summary>
  RemoteFB__Plugin_Auth_Legacy_Factory();

  /// <summary>
  ///  ����������
  /// </summary>
 ~RemoteFB__Plugin_Auth_Legacy_Factory();

 public:
  static RemoteFB__Plugin_Auth_FactoryPtr Create();

  static name_type GetName();

  //factory interface ----------------------------------------------------
  virtual name_type get_name()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual RemoteFB__Plugin_AuthPtr create_plugin()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// ������������ ��������� ������
  static self_type sm_Instance;
};//class RemoteFB__Plugin_Auth_Legacy_Factory

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms legacy*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
