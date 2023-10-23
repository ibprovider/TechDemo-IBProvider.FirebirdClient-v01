////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_win_sspi.cpp
//! \brief   –еализаци€ плагина дл€ WIN_SSPI-аутентификации [Firebird 2.1]
//! \author  Kovalenko Dmitry
//! \date    23.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/plugins/auth/win_sspi/remote_fb__plugin_auth_win_sspi.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/ibp_global_objects_data__dlls.h"

#include <structure/t_latin.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace win_sspi{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_WinSSPI

RemoteFB__Plugin_Auth_WinSSPI::RemoteFB__Plugin_Auth_WinSSPI()
 :m_step(0)
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_WinSSPI::~RemoteFB__Plugin_Auth_WinSSPI()
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_AuthPtr RemoteFB__Plugin_Auth_WinSSPI::Create()
{
 return lib::structure::not_null_ptr(new self_type());
}//Create

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_WinSSPI::name_type RemoteFB__Plugin_Auth_WinSSPI::GetName()
{
 return name_type::create<ibprovider::ibp_propval__remote__auth__Win_Sspi>();
}//GetName

//interface --------------------------------------------------------------
RemoteFB__Plugin_Auth_WinSSPI::name_type RemoteFB__Plugin_Auth_WinSSPI::get_name()const
{
 return self_type::GetName();
}//get_name

//------------------------------------------------------------------------
void RemoteFB__Plugin_Auth_WinSSPI::def_auth_params_in_cpb
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 self_type::helper__check_valid_usage(clientConnectBlock);

 /*нам ничего специфического добавл€ть не надо*/

 //----------------------------------------- возвращаем USER NAME
 clientConnectBlock.m_spDsPropValues->Direct__SetValue
  (DBPROPSET_DATASOURCEINFO,
   DBPROP_USERNAME,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(RemoteFB__Utils::BuildWinSspiUserName()));
}//def_auth_params_in_cpb

//------------------------------------------------------------------------
void RemoteFB__Plugin_Auth_WinSSPI::authenticate
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 if(!m_spAuthProvider)
 {
  assert(m_step==0);

  //ѕервоначально, у нас не должно быть никаких данных
  assert(clientConnectBlock.m_dataForAuthPlugin.empty());

  //----------------------------------------
  using provider_type=auth_provider_type;

  using dll_ptr=os::t_ibp_os__dll_ptr;

  const dll_ptr
   spDll
    (IBP_GlobalObjectsData__DLLs::GetDLL
      (IBP_T("secur32.dll"),
       ibprovider::ibp_propval_dll_lock_rule__unload));

  assert(spDll);

  m_spAuthProvider=provider_type::create(spDll);

  assert(m_spAuthProvider);
 }//if !m_spAuthProvider

 assert(m_spAuthProvider);

 //-----------------------------------------
 if(m_step==0)
 {
  //однократна€ проверка допустимости использовани€ сервиса

  self_type::helper__check_valid_usage(clientConnectBlock);
 }//if m_step==0

 if(m_AuthData.is_completed())
 {
  //ERROR - некорректное использование сервиса аутентификации

  assert(m_step>1);

  assert(false);

  RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__AlreadyWasCompleted
   (ibp_subsystem__remote_fb,
    self_type::GetName());
 }//if

 assert(!m_AuthData.is_completed());

 m_AuthData.request
  (m_spAuthProvider,
   clientConnectBlock.m_dataForAuthPlugin.size(),
   clientConnectBlock.m_dataForAuthPlugin.buffer(),
   clientConnectBlock.m_dataFromAuthPlugin); //throw

 ++m_step;
}//authenticate

//helper methods ---------------------------------------------------------
void RemoteFB__Plugin_Auth_WinSSPI::helper__check_valid_usage
                                           (const RemoteFB__ClientConnectBlock_v2& UNUSED_ARG(clientConnectBlock))
{
 // [2016-09-13]
 //  »значально здесь планировалась проверка согласованности с "Integrated Security",
 //  в котором должна быть указана SSPI-аутентификаци€.
 //
 //  Ќо, тогда, в этом случае все остальные плагины аутентификации тоже должны
 //  выполн€ть аналогичные проверки. „то, по хорошему, не правильно.
 //
 //  “ак что, все проверки отсюда удалены.
 //
 //  —огласованность провер€етс€ на уровне вызывающего кода, который выбирает и
 //  создает сервисы аутентификации.
}//helper__check_valid_usage

////////////////////////////////////////////////////////////////////////////////
}/*nms win_sspi*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
