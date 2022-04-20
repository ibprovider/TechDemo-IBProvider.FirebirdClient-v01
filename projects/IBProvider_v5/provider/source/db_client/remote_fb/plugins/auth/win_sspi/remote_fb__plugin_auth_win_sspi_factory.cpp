////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_win_sspi_factory.cpp
//! \brief   Фабрика класса плагина WIN_SSPI-аутентификации
//! \author  Kovalenko Dmitry
//! \date    23.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/plugins/auth/win_sspi/remote_fb__plugin_auth_win_sspi_factory.h"
#include "source/db_client/remote_fb/plugins/auth/win_sspi/remote_fb__plugin_auth_win_sspi.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace win_sspi{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_WinSSPI_Factory

RemoteFB__Plugin_Auth_WinSSPI_Factory
 RemoteFB__Plugin_Auth_WinSSPI_Factory::sm_Instance;

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_WinSSPI_Factory::RemoteFB__Plugin_Auth_WinSSPI_Factory()
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_WinSSPI_Factory::~RemoteFB__Plugin_Auth_WinSSPI_Factory()
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_FactoryPtr
 RemoteFB__Plugin_Auth_WinSSPI_Factory::Create()
{
 return &sm_Instance;
}//Create

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_WinSSPI_Factory::name_type RemoteFB__Plugin_Auth_WinSSPI_Factory::GetName()
{
 return RemoteFB__Plugin_Auth_WinSSPI::GetName();
}//GetName

//factory interface ------------------------------------------------------
RemoteFB__Plugin_Auth_WinSSPI_Factory::name_type RemoteFB__Plugin_Auth_WinSSPI_Factory::get_name()const
{
 return self_type::GetName();
}//get_name

//------------------------------------------------------------------------
RemoteFB__Plugin_AuthPtr
 RemoteFB__Plugin_Auth_WinSSPI_Factory::create_plugin()const
{
 return RemoteFB__Plugin_Auth_WinSSPI::Create();
}//create_plugin

////////////////////////////////////////////////////////////////////////////////
}/*nms win_sspi*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
