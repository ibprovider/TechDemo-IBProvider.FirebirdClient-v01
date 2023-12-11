////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__plugin_auth
//! \file    remote_fb__plugin_auth_srp_p13.cpp
//! \brief   Реализация плагина для SRP-аутентификации [Firebird 3.0]
//! \author  Kovalenko Dmitry
//! \date    12.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/plugins/auth/srp/remote_fb__plugin_auth_srp_p13.h"
#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__internal_crypt_key__symmetric.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/isc_base/isc_portable_format_to_integer.h"

#include "source/oledb/ibp_oledb__prop__names.h"

#include "source/error_services/ibp_error_bug_check.h"
#include "source/ibp_utils.h"

#include <lcpi/lib/structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace plugins{namespace auth{namespace srp{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Plugin_Auth_SRP_P13

RemoteFB__Plugin_Auth_SRP_P13::RemoteFB__Plugin_Auth_SRP_P13(RemoteFB__Plugin_Auth_SRP_P13_Data* pData)
 :m_spData(lib::structure::not_null_ptr(pData))
 ,m_step(0)
{
 assert(m_spData);
}//RemoteFB__Plugin_Auth_SRP_P13

//------------------------------------------------------------------------
RemoteFB__Plugin_Auth_SRP_P13::~RemoteFB__Plugin_Auth_SRP_P13()
{;}

//interface --------------------------------------------------------------
RemoteFB__Plugin_Auth_SRP_P13::name_type RemoteFB__Plugin_Auth_SRP_P13::get_name()const
{
 assert(m_spData);

 return m_spData->getPluginName();
}//get_name

//------------------------------------------------------------------------
void RemoteFB__Plugin_Auth_SRP_P13::def_auth_params_in_cpb
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
  //ERROR - некорректное использование плагина SRP-аутентификации. В строке подключения
  //не определен логин пользователя

  RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__NoCnParam
   (ibp_subsystem__remote_fb,
    this->get_name(),
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
 clientConnectBlock.m_spDsPropValues->Direct__SetValue
  (DBPROPSET_DATASOURCEINFO,
   DBPROP_USERNAME,
   DBPROPOPTIONS_REQUIRED,
   ole_lib::TVariant(strPropValue__UserID));
}//def_auth_params_in_cpb

//------------------------------------------------------------------------
void RemoteFB__Plugin_Auth_SRP_P13::authenticate
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__Plugin_Auth_SRP_P13::authenticate";

 //-----------------------------------------
 switch(m_step)
 {
  case 0:
  {
   //Проверяем наличие userID и password в clientConnectBlock.

   if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_USERID,nullptr,nullptr))
   {
    //ERROR - некорректное использование плагина SRP-аутентификации. В строке подключения
    //не определен логин пользователя

    RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__NoCnParam
     (ibp_subsystem__remote_fb,
      this->get_name(),
      IBP_DBPROP_NAME__INIT__USER_ID);
   }//if

   if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_PASSWORD,nullptr,nullptr))
   {
    //ERROR - некорректное использование плагина SRP-аутентификации. В строке подключения
    //не определен пароль пользователя

    RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__NoCnParam
     (ibp_subsystem__remote_fb,
      this->get_name(),
      IBP_DBPROP_NAME__INIT__PASSWORD);
   }//if

   //---------------------------------------------------------------------
   assert(m_spData);

   const std::string
    srpClientKey(m_spData->getClientKey());

   const size_t cbData
    =srpClientKey.size()*sizeof(*srpClientKey.c_str());

   clientConnectBlock.m_dataFromAuthPlugin.alloc(cbData);

   assert(clientConnectBlock.m_dataFromAuthPlugin.size()==cbData);

   memcpy(clientConnectBlock.m_dataFromAuthPlugin.buffer(),
          srpClientKey.c_str(),
          cbData);

   break;
  }//case 0

  case 1:
  {
   ole_lib::TVariant varPropValue__UserID;

   if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_USERID,nullptr,&varPropValue__UserID))
   {
    //ERROR - [BUG CHECK] user login is not defined!
    assert(false);

    IBP_ThrowBugCheck__CnPropNotDefined
     (c_bugcheck_src,
      L"#002",
      IBP_DBPROP_NAME__INIT__USER_ID);
   }//if

   assert(varPropValue__UserID.vt==VT_BSTR);

   const auto strPropValue__UserID
    =ole_lib::BStrToBox(varPropValue__UserID.bstrVal);

   //---------------------------------------
   ole_lib::TVariant varPropValue__UserPassword;

   if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_PASSWORD,nullptr,&varPropValue__UserPassword))
   {
    //ERROR - [BUG CHECK] user Password is not defined!
    assert(false);

    IBP_ThrowBugCheck__CnPropNotDefined
     (c_bugcheck_src,
      L"#002",
      IBP_DBPROP_NAME__INIT__PASSWORD);
   }//if

   assert(varPropValue__UserPassword.vt==VT_BSTR);

   const auto strPropValue__UserPassword
    =ole_lib::BStrToBox(varPropValue__UserPassword.bstrVal);

   //---------------------------------------
   std::string utf8UserID;

   if(!IBP_Utils::WStrToUtf8__Fast(strPropValue__UserID,&utf8UserID))
   {
    //ERROR - ошибка конвертирования имени пользователя в кодовую страницу UTF8

    IBP_ThrowCantConvertCnPropToUTF8
     (ibp_subsystem__remote_fb,
      IBP_DBPROP_NAME__INIT__USER_ID);
   }//if

   //---------------------------------------
   std::string utf8UserPassword;

   if(!IBP_Utils::WStrToUtf8__Fast(strPropValue__UserPassword,&utf8UserPassword))
   {
    //ERROR - ошибка конвертирования пароля пользователя в кодовую страницу UTF8

    IBP_ThrowCantConvertCnPropToUTF8
     (ibp_subsystem__remote_fb,
      IBP_DBPROP_NAME__INIT__PASSWORD);
   }//if

   //---------------------------------------
   assert(m_spData);

   const size_t c_expectedSaltAndKey
    =data_type::c_expectedSaltAndKeySize;

   size_t cbSaltAndKey=clientConnectBlock.m_dataForAuthPlugin.size();

   if((cbSaltAndKey<2) || (c_expectedSaltAndKey<cbSaltAndKey))
   {
    //ERROR - [BUG CHECK] Incorrect length of auth data for SRP authentication

    assert(false);

    RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
     (c_bugcheck_src,
      L"#001",
      cbSaltAndKey);
   }//if

   const unsigned char* pSaltAndKey
    =reinterpret_cast<const unsigned char*>(clientConnectBlock.m_dataForAuthPlugin.buffer());

   size_t saltSize;

   isc_base::isc_portable_format_to_integer::exec
    (2,
     pSaltAndKey,
     &saltSize,
     ibp_subsystem__remote_fb,
     L"srp::dataForPlugin::salt_size");

   cbSaltAndKey-=2;

   pSaltAndKey+=2;

   if(cbSaltAndKey<saltSize)
   {
    //ERROR - [BUG CHECK] Incorrect length of auth data for SRP authentication

    RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__TooLongAuthData
     (c_bugcheck_src,
      L"#002",
      saltSize,
      cbSaltAndKey);
   }//if

   const std::string salt(pSaltAndKey,pSaltAndKey+saltSize);

   pSaltAndKey+=saltSize;

   cbSaltAndKey-=saltSize;

   //---------------------------------------
   if(cbSaltAndKey<2)
   {
    //ERROR - [BUG CHECK] Incorrect length of auth data for SRP authentication

    RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
     (c_bugcheck_src,
      L"#003",
      cbSaltAndKey);
   }//if

   size_t keySize;

   isc_base::isc_portable_format_to_integer::exec
    (2,
     pSaltAndKey,
     &keySize,
     ibp_subsystem__remote_fb,
     L"srp::dataForPlugin::key_size");

   cbSaltAndKey-=2;

   pSaltAndKey+=2;

   if(keySize!=cbSaltAndKey)
   {
    //ERROR - [BUG CHECK] Incorrect length of auth data for SRP authentication

    RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
     (c_bugcheck_src,
      L"#004",
      keySize,
      cbSaltAndKey);
   }//if

   //в ключе не должны находиться нулевые байты
   if(std::find(pSaltAndKey,pSaltAndKey+keySize,0)!=(pSaltAndKey+keySize))
   {
    //ERROR - [BUG CHECK] Incorrect server Key

    RemoteFB__ErrorUtils::Throw_AuthSvcBugCheck__IncorrectServerKey
     (c_bugcheck_src,
      L"#005");
   }//if

   const std::string key(pSaltAndKey,pSaltAndKey+keySize);

   //---------------------------------------
   data_type::bytes_type sessionKey;

   std::string clientProof;

   m_spData->calcClientSessionKeyAndProof
    (&sessionKey,
     &clientProof,
     utf8UserID,
     salt,
     utf8UserPassword,
     key.c_str());

   //---------------------------------------
   clientConnectBlock.m_dataFromAuthPlugin.alloc
    (sizeof(*clientProof.c_str())*clientProof.size());

   assert(clientConnectBlock.m_dataFromAuthPlugin.size()
           ==(sizeof(*clientProof.c_str())*clientProof.size()));

   memcpy(clientConnectBlock.m_dataFromAuthPlugin.buffer(),
          clientProof.c_str(),
          sizeof(*clientProof.c_str())*clientProof.size());

   //---------------------------------------

   //Сохраняем sessionKey в виде ключа на уровне clientConnectBlock

   // ICryptKey* const cKey = cb->newKey(status);
   //
   // cKey->setSymmetric(status, "Symmetric", sessionKey.getCount(), sessionKey.begin());

   switch(clientConnectBlock.m_DsProp__WireCrypt)
   {
    case ibp_ipropval__remote__wire_crypt::disabled:
    {
     break;
    }//disabled

    case ibp_ipropval__remote__wire_crypt::default_:
    case ibp_ipropval__remote__wire_crypt::enabled:
    case ibp_ipropval__remote__wire_crypt::required:
    {
     const RemoteFB__InternalCryptKeyPtr
      spCryptKey
       (RemoteFB__InternalCryptKey__Symmetric::Create
         (sessionKey.size(),
          sessionKey.buffer()));

     clientConnectBlock.m_cryptKeys.push_back(spCryptKey);

     break;
    }//case enabled, required

    default:
    {
     //ERROR - [BUG CHECK] Неизвестное разрешение на шифрование подключения

     RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_crypt_permission
     (c_bugcheck_src,
      L"#006",
      lib::structure::to_underlying(clientConnectBlock.m_DsProp__WireCrypt));
    }//default
   }//switch

   break;
  }//case 1

  default:
  {
   assert(m_step==2);

   //ERROR - некорректное использование сервиса аутентификации

   assert(false);

   RemoteFB__ErrorUtils::Throw_AuthSvcErr__IncorrectUsage__AlreadyWasCompleted
    (ibp_subsystem__remote_fb,
     this->get_name());
  }//default
 }//switch m_step

  ++m_step;
}//authenticate

////////////////////////////////////////////////////////////////////////////////
}/*nms srp*/}/*nms auth*/}/*nms plugins*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/