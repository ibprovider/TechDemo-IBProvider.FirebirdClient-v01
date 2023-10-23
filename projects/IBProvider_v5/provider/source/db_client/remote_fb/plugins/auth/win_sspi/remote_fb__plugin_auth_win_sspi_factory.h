////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_win_sspi_factory.h
//! \brief   ������� ������ ������� WIN_SSPI-��������������
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

class RemoteFB__Plugin_Auth_WinSSPI_Factory LCPI_CPP_CFG__CLASS__FINAL
 :public REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(RemoteFB__Plugin_Auth_Factory)
{
 private:
  using self_type=RemoteFB__Plugin_Auth_WinSSPI_Factory;

  RemoteFB__Plugin_Auth_WinSSPI_Factory(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 private:
  /// <summary>
  ///  ����������� ��-���������
  /// </summary>
  RemoteFB__Plugin_Auth_WinSSPI_Factory();

  /// <summary>
  ///  ����������
  /// </summary>
 ~RemoteFB__Plugin_Auth_WinSSPI_Factory();

 public:
  static RemoteFB__Plugin_Auth_FactoryPtr Create();

  static name_type GetName();

  //factory interface ----------------------------------------------------
  virtual name_type get_name()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual RemoteFB__Plugin_AuthPtr create_plugin()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  /// ������������ ��������� ������
  static self_type sm_Instance;
};//class RemoteFB__Plugin_Auth_WinSSPI_Factory

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win_sspi*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
