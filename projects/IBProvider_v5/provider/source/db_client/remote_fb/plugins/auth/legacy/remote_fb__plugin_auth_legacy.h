////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_legacy.h
//! \brief   ���������� ������� ��� Legacy-��������������
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
///  ���������� ������� ��� Legacy-��������������
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
  ///  ����������� ��-���������
  /// </summary>
  RemoteFB__Plugin_Auth_Legacy();

  /// <summary>
  ///  ����������
  /// </summary>
  virtual ~RemoteFB__Plugin_Auth_Legacy();

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
  /// ���������� ����� ������ ������ authenticate
  unsigned m_step;
};//class RemoteFB__Plugin_Auth_Legacy

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms legacy*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
