////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_legacy_factory.cpp
//! \brief   Фабрика класса плагина Legacy-аутентификации
//! \author  Kovalenko Dmitry
//! \date    27.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/plugins/auth/legacy/remote_fb__plugin_auth_legacy_factory.h"
#include "source/db_client/remote_fb/plugins/auth/legacy/remote_fb__plugin_auth_legacy.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace legacy{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_Legacy_Factory

RemoteFB__Plugin_Auth_Legacy_Factory
 RemoteFB__Plugin_Auth_Legacy_Factory::sm_Instance;

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_Legacy_Factory::RemoteFB__Plugin_Auth_Legacy_Factory()
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_Legacy_Factory::~RemoteFB__Plugin_Auth_Legacy_Factory()
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_FactoryPtr
 RemoteFB__Plugin_Auth_Legacy_Factory::Create()
{
 return &sm_Instance;
}//Create

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_Legacy_Factory::name_type RemoteFB__Plugin_Auth_Legacy_Factory::GetName()
{
 return RemoteFB__Plugin_Auth_Legacy::GetName();
}//GetName

//factory interface ------------------------------------------------------
RemoteFB__Plugin_Auth_Legacy_Factory::name_type RemoteFB__Plugin_Auth_Legacy_Factory::get_name()const
{
 return self_type::GetName();
}//get_name

//------------------------------------------------------------------------
RemoteFB__Plugin_AuthPtr
 RemoteFB__Plugin_Auth_Legacy_Factory::create_plugin()const
{
 return RemoteFB__Plugin_Auth_Legacy::Create();
}//create_plugin

////////////////////////////////////////////////////////////////////////////////
}/*nms legacy*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
