////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_legacy.h
//! \brief   Реализация плагина для Legacy-аутентификации
//! \author  Kovalenko Dmitry
//! \date    27.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/plugins/auth/legacy/remote_fb__plugin_auth_legacy.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__enc_crypt.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/oledb/ibp_oledb__prop__names.h"

#include "source/error_services/ibp_error_utils.h"
#include "source/ibp_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace legacy{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_Legacy

RemoteFB__Plugin_Auth_Legacy::RemoteFB__Plugin_Auth_Legacy()
 :m_step(0)
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_Legacy::~RemoteFB__Plugin_Auth_Legacy()
{;}

//------------------------------------------------------------------------
RemoteFB__Plugin_AuthPtr RemoteFB__Plugin_Auth_Legacy::Create()
{
 return lib::structure::not_null_ptr(new self_type());
}//Create

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_Legacy::name_type RemoteFB__Plugin_Auth_Legacy::GetName()
{
 return name_type::create<ibprovider::ibp_propval__remote__auth__Legacy_Auth>();
}//GetName

//interface --------------------------------------------------------------
RemoteFB__Plugin_Auth_Legacy::name_type RemoteFB__Plugin_Auth_Legacy::get_name()const
{
 return self_type::GetName();
}//get_name

//------------------------------------------------------------------------
void RemoteFB__Plugin_Auth_Legacy::def_auth_params_in_cpb
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 //! \todo
 //!  В clientConnectBlock нужно хранить информацию о версиях протоколов, которые
 //!  мы будем пытаться применить к устанавливаемому соединению.
 //!
 //!  А в этой точке мы должны проверить, что эти версии допустимы.
 //!
 //!  Это необходимо сделать, потому что здесь модифицируется clientConnectBlock.m_CPB

 //Проверяем наличие userID и password в clientConnectBlock.

 ole_lib::TVariant varPropValue__UserID;

 if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_USERID,nullptr,&varPropValue__UserID))
 {
  //ERROR - некорректное использование плагина Legacy-аутентификации. В строке подключения
  //не определен логин пользователя

  RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__NoCnParam
   (ibp_subsystem__remote_fb,
    self_type::GetName(),
    IBP_DBPROP_NAME__INIT__USER_ID);
 }//if

 assert(varPropValue__UserID.vt==VT_BSTR);

 const auto strPropValue__UserID
  =ole_lib::BStrToBox(varPropValue__UserID.bstrVal);

 //-----------------------------------------
 clientConnectBlock.m_CPB.AppendMbcString_AsUTF8
  (protocol::set02::P_CNCT_login,
   L"protocol::set02::P_CNCT_login",
   strPropValue__UserID);

 //----------------------------------------- возвращаем USER NAME
 //Прводим имя к верхнему регистру

 RemoteFB__Utils::System_CharUpperBStr
  (varPropValue__UserID.bstrVal,
   L"DbUserName");

 clientConnectBlock.m_spDsPropValues->Direct__SetValue
  (DBPROPSET_DATASOURCEINFO,
   DBPROP_USERNAME,
   DBPROPOPTIONS_REQUIRED,
   varPropValue__UserID);
}//def_auth_params_in_cpb

//------------------------------------------------------------------------
void RemoteFB__Plugin_Auth_Legacy::authenticate(RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 switch(m_step)
 {
  case 0:
  {
   //Проверяем наличие userID и password в clientConnectBlock.
   ole_lib::TVariant varPropValue__UserPassword;

   if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_PASSWORD,nullptr,&varPropValue__UserPassword))
   {
    //ERROR - некорректное использование плагина SRP-аутентификации. В строке подключения
    //не определен пароль пользователя

    RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__NoCnParam
     (ibp_subsystem__remote_fb,
      self_type::GetName(),
      IBP_DBPROP_NAME__INIT__PASSWORD);
   }//if

   assert(varPropValue__UserPassword.vt==VT_BSTR);

   const auto strPropValue__UserPassword
    =ole_lib::BStrToBox(varPropValue__UserPassword.bstrVal);

   //---------------------------------------------------------------------
   std::string mbc_str;

   if(!IBP_Utils::WStrToUtf8__Fast(strPropValue__UserPassword,&mbc_str))
   {
    //ERROR - ошибка конвертирования
    IBP_ThrowCantConvertCnPropToUTF8
     (ibp_subsystem__remote_fb,
      IBP_DBPROP_NAME__INIT__PASSWORD);
   }//if

   char pwt[64/*MAX_PASSWORD_LENGTH*/ + 2];

   RemoteFB__ENC_crypt::ENC_crypt
    (pwt,
     sizeof(pwt),
     mbc_str.c_str(),
     /*PASSWORD_SALT*/"9z");

   const char* const password_b=(pwt+2);
   const char* const password_e=std::find(password_b,const_cast<const char*>(_END_(pwt)),0);

   const size_t password_sz=(password_e-password_b);

   //декларативная проверка
   assert((password_e-pwt)<=RemoteFB__ENC_crypt::c_RESULT_SIZE);

   clientConnectBlock.m_dataFromAuthPlugin.alloc(password_sz); //throw

   assert(clientConnectBlock.m_dataFromAuthPlugin.size()==password_sz);

   memcpy(clientConnectBlock.m_dataFromAuthPlugin.buffer(),
          password_b,
          password_sz);

   break;
  }//case 0

  default:
  {
   assert(m_step==1);

   //ERROR - некорректное использование сервиса аутентификации

   assert(false);

   RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__AlreadyWasCompleted
    (ibp_subsystem__remote_fb,
     self_type::GetName());
  }//default
 }//switch m_step

 ++m_step;
}//authenticate

////////////////////////////////////////////////////////////////////////////////
}/*nms legacy*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
