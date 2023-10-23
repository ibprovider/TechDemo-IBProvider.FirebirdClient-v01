////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_win_sspi.h
//! \brief   ���������� ������� ��� WIN_SSPI-�������������� [Firebird 2.1]
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
///  ���������� ������� ��� WIN_SSPI-�������������� [Firebird 2.1]
/// </summary>
class RemoteFB__Plugin_Auth_WinSSPI LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__Plugin_Auth)
{
 private:
  using self_type=RemoteFB__Plugin_Auth_WinSSPI;

  RemoteFB__Plugin_Auth_WinSSPI(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  /// <summary>
  ///  ����������� ��-���������
  /// </summary>
  RemoteFB__Plugin_Auth_WinSSPI();

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__Plugin_Auth_WinSSPI();

 public:
  /// <summary>
  ///  ������� ������.
  /// </summary>
  static RemoteFB__Plugin_AuthPtr Create();

  /// <summary>
  ///  ��������� ������ � ������ ������� ��������������.
  /// </summary>
  static name_type GetName();

  //interface ------------------------------------------------------------
  /// <summary>
  ///  ������ � ������ ������� ��������������.
  /// </summary>
  //! \return
  //!  �������� ������.
  virtual name_type get_name()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ����������� ������ �������������� � ������ � ����������� ������������� �����������.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void def_auth_params_in_cpb(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  ��������� ������ ��������������.
  /// </summary>
  //! \param[in,out] clientConnectBlock
  virtual void authenticate(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// <summary>
  ///  �������� ������������ �������������
  /// </summary>
  //! \param[in] clientConnectBlock
  static void helper__check_valid_usage(const RemoteFB__ClientConnectBlock_v2& clientConnectBlock);

 private:
  /// ���������� ����� ������ ������ authenticate
  unsigned m_step;

 private:
  using auth_provider_type
   =ibp::os::win32::auth::t_auth__provider;

  using auth_descr_builder_type
   =ibp::os::win32::auth::t_auth__descr_builder;

 private:
  auth_provider_type::self_ptr m_spAuthProvider;
  auth_descr_builder_type      m_AuthData;
};//class RemoteFB__Plugin_Auth_WinSSPI

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win_sspi*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
