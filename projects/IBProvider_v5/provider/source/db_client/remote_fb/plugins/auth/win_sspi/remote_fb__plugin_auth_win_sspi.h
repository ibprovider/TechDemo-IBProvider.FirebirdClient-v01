////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_win_sspi.h
//! \brief   Реализация плагина для WIN_SSPI-аутентификации [Firebird 2.1]
//! \author  Kovalenko Dmitry
//! \date    23.08.2016
#ifndef _remote_fb__plugin_auth_win_sspi_H_
#define _remote_fb__plugin_auth_win_sspi_H_

#include "source/db_client/remote_fb/plugins/auth/remote_fb__plugin_auth.h"
#include "source/os/win32/auth/ibp_os_win32_auth__descr_builder.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace win_sspi{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb__plugin_auth
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_WinSSPI

/// <summary>
///  Реализация плагина для WIN_SSPI-аутентификации [Firebird 2.1]
/// </summary>
class RemoteFB__Plugin_Auth_WinSSPI
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__Plugin_Auth)
{
 private:
  typedef RemoteFB__Plugin_Auth_WinSSPI     self_type;

  RemoteFB__Plugin_Auth_WinSSPI(const self_type&);
  self_type& operator = (const self_type&);

 private:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  RemoteFB__Plugin_Auth_WinSSPI();

  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~RemoteFB__Plugin_Auth_WinSSPI();

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
  virtual name_type get_name()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Определение данных аутентификации в буфере с параметрами инициализации подключения.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void def_auth_params_in_cpb(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Установка данных аутентификации.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void authenticate(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)COMP_W000004_OVERRIDE_FINAL;

 private:
  /// <summary>
  ///  Проверка допустимости использования
  /// </summary>
  //! \param[in] clientConnectBlock
  static void helper__check_valid_usage(const RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

 private:
  /// Порядковый номер вызова метода authenticate
  unsigned m_step;

 private:
  typedef ibp::os::win32::auth::t_auth__provider        auth_provider_type;
  typedef ibp::os::win32::auth::t_auth__descr_builder   auth_descr_builder_type;

 private:
  auth_provider_type::self_ptr m_spAuthProvider;
  auth_descr_builder_type      m_AuthData;
};//class RemoteFB__Plugin_Auth_WinSSPI

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win_sspi*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
