////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_legacy.h
//! \brief   Реализация плагина для Legacy-аутентификации
//! \author  Kovalenko Dmitry
//! \date    27.08.2016
#ifndef _remote_fb__plugin_auth_legacy_H_
#define _remote_fb__plugin_auth_legacy_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace legacy{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_Legacy

/// <summary>
///  Реализация плагина для Legacy-аутентификации
/// </summary>
class RemoteFB__Plugin_Auth_Legacy
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__Plugin_Auth)
{
 private:
  typedef RemoteFB__Plugin_Auth_Legacy     self_type;

  RemoteFB__Plugin_Auth_Legacy(const self_type&);
  self_type& operator = (const self_type&);

 private:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  RemoteFB__Plugin_Auth_Legacy();

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__Plugin_Auth_Legacy();

 public:
  /// <summary>
  ///  Фабрика класса.
  /// </summary>
  static RemoteFB__Plugin_AuthPtr Create();

  /// <summary>
  ///  Получение строки с именем плагина аутентификации.
  /// </summary>
  static name_type GetName();

  //interface ------------------------------------------------------------
  /// <summary>
  ///  Строка с именем сервиса аутентификации.
  /// </summary>
  //! \return
  //!  Непустая строка.
  virtual name_type get_name()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Определение данных аутентификации в буфере с параметрами инициализации подключения.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void def_auth_params_in_cpb(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Установка данных аутентификации.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void authenticate(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// Порядковый номер вызова метода authenticate
  unsigned m_step;
};//class RemoteFB__Plugin_Auth_Legacy

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms legacy*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
