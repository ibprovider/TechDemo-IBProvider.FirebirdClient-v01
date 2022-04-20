////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_win_sspi_factory.h
//! \brief   Фабрика класса плагина WIN_SSPI-аутентификации
//! \author  Kovalenko Dmitry
//! \date    23.08.2016
#ifndef _remote_fb__plugin_auth_win_sspi_factory_H_
#define _remote_fb__plugin_auth_win_sspi_factory_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth_factory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace win_sspi{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_WinSSPI_Factory

class RemoteFB__Plugin_Auth_WinSSPI_Factory
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__Plugin_Auth_Factory)
{
 private:
  typedef RemoteFB__Plugin_Auth_WinSSPI_Factory     self_type;

  RemoteFB__Plugin_Auth_WinSSPI_Factory(const self_type&);
  self_type& operator = (const self_type&);

 private:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  RemoteFB__Plugin_Auth_WinSSPI_Factory();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~RemoteFB__Plugin_Auth_WinSSPI_Factory();

 public:
  static RemoteFB__Plugin_Auth_FactoryPtr Create();

  static name_type GetName();

  //factory interface ----------------------------------------------------
  virtual name_type get_name()const COMP_W000004_OVERRIDE_FINAL;

  virtual RemoteFB__Plugin_AuthPtr create_plugin()const COMP_W000004_OVERRIDE_FINAL;

 private:
  /// Единственный экземпляр класса
  static self_type sm_Instance;
};//class RemoteFB__Plugin_Auth_WinSSPI_Factory

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win_sspi*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
