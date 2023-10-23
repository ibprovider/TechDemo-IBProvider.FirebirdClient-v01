////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_factory.h
//! \brief   Интерфейс фабрики плагинов аутентификации
//! \author  Kovalenko Dmitry
//! \date    23.08.2016
#ifndef _remote_fb__plugin_auth_factory_H_
#define _remote_fb__plugin_auth_factory_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_Factory

/// <summary>
///  Интерфейс фабрики плагинов аутентификации
/// </summary>
class RemoteFB__Plugin_Auth_Factory:public RemoteFB__SmartInterface
{
 public: //typedefs ------------------------------------------------------
  using name_type=lib::structure::t_const_wstring;

 public:
  /// <summary>
  ///  Строка с именем сервиса аутентификации.
  /// </summary>
  //! \return
  //!  Непустая строка.
  virtual name_type get_name()const=0;

  /// <summary>
  ///  Создание плагина аутентифкации
  /// </summary>
  //! \return
  //!  Not null.
  virtual RemoteFB__Plugin_AuthPtr create_plugin()const=0;
};//class RemoteFB__Plugin_Auth_Factory

using RemoteFB__Plugin_Auth_FactoryPtr=lib::structure::t_smart_object_ptr<RemoteFB__Plugin_Auth_Factory>;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
