////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset02_v01.cpp
//! \brief   Утилиты для настройки порта подключения (P13)
//! \author  Kovalenko Dmitry
//! \date    31.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/initializers/pset02/v01/remote_fb__ports__base_v01__initializers__pset02_v01.h"

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__db__attach.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__db__create.h"

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__initialize_compressor.h"

#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"

#include "source/db_client/remote_fb/plugins/auth/win_sspi/remote_fb__plugin_auth_win_sspi_factory.h"
#include "source/db_client/remote_fb/plugins/auth/srp/remote_fb__plugin_auth_srp_factory.h"
#include "source/db_client/remote_fb/plugins/auth/legacy/remote_fb__plugin_auth_legacy_factory.h"

#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__factories.h"
#include "source/db_obj/fb_base/fb_api.h"

#include "source/db_obj/db_utility.h"
#include "source/error_services/ibp_error_messages.h"
#include "source/ibp_utils.h"

#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset02{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET02_v01

const RemoteFB__PortInitializer_PSET02_v01::tagAcceptConnectFuncs
 RemoteFB__PortInitializer_PSET02_v01::sm_accept_funcs__cond_accept=
{
 /*P13*/RemoteFB__PortInitializer_PSET02_v01::Helper__FinishConnect_P13__cond_accept,
};//sm_accept_funcs__cond_accept

//------------------------------------------------------------------------
const RemoteFB__PortInitializer_PSET02_v01::tagAcceptConnectFuncs
 RemoteFB__PortInitializer_PSET02_v01::sm_accept_funcs__accept_data=
{
 /*P13*/RemoteFB__PortInitializer_PSET02_v01::Helper__FinishConnect_P13__accept_data,
};//sm_accept_funcs__accept_data

//------------------------------------------------------------------------
const RemoteFB__PortInitializer_PSET02_v01::tag_connect_finalizator
 RemoteFB__PortInitializer_PSET02_v01::sm_finalizator_for_create=
{
 /*P13*/api::p13::RemoteFB__API_P13__CreateDatabase::exec,
};//sm_finalizator_for_create

//------------------------------------------------------------------------
const RemoteFB__PortInitializer_PSET02_v01::tag_connect_finalizator
 RemoteFB__PortInitializer_PSET02_v01::sm_finalizator_for_attach=
{
 /*P13*/api::p13::RemoteFB__API_P13__AttachToDatabase::exec,
};//sm_finalizator_for_attach

//------------------------------------------------------------------------
bool RemoteFB__PortInitializer_PSET02_v01::TryConnectToDatabase
      (port_type*                                           const pPort,
       wstr_box_type                                        const ucs2_database_name,
       oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues)
{
 assert(pPort!=nullptr);
 assert(pDsPropValues);

 return self_type::Helper__TryConnect
         (pPort,
          ucs2_database_name,
          pDsPropValues,
          sm_finalizator_for_attach);
}//TryConnectToDatabase

//------------------------------------------------------------------------
bool RemoteFB__PortInitializer_PSET02_v01::TryCreateDatabase
      (port_type*                                           const pPort,
       wstr_box_type                                        const ucs2_database_name,
       oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues)
{
 assert(pPort!=nullptr);
 assert(pDsPropValues);

 return self_type::Helper__TryConnect
         (pPort,
          ucs2_database_name,
          pDsPropValues,
          sm_finalizator_for_create);
}//TryCreateDatabase

//helper methods ---------------------------------------------------------
bool RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect
      (port_type*                                           const pPort,
       wstr_box_type                                        const ucs2_database_name,
       oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
       const tag_connect_finalizator&                             FinalOpFuncs)
{
 assert(pDsPropValues);
 assert(pPort!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect";

 //-----------------------------------------
 RemoteFB__ClientConnectBlock_v2
  clientConnectBlock(pDsPropValues);

 //-----------------------------------------
 ole_lib::TVariant varPropValue__AuthName;

 if(pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,
                                    ibprovider::IBP_DBPROP__INIT__REMOTE__AUTH,
                                    nullptr,
                                    &varPropValue__AuthName))
 {
  //пользователь явно указал имя сервиса аутентификации

  assert(varPropValue__AuthName.vt==VT_BSTR);

  const auto strPropValue__AuthName
   =ole_lib::BStrToBox(varPropValue__AuthName.bstrVal);

  Helper__TryConnect__SetAuthPlugin(clientConnectBlock,strPropValue__AuthName); //throw
 }
 else
 {
  //регистрация сервисов аутентификации по-умолчанию

  Helper__TryConnect__RegDefaultAuthPlugin(clientConnectBlock); //throw
 }//local

 //-----------------------------------------

 //запрашиваем начальные данные аутентификации
 clientConnectBlock.GetCurrentAuthPlugin()->authenticate(clientConnectBlock); //throw

 //-------------------------------------------------------- 1. SEND: op_connect
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_connect;

 {
  protocol::set02::PACKET_V02 packet;

  packet.operation                = protocol::set02::op_connect;
  packet.p_cnct.p_cnct__operation = protocol::set02::op_attach;
  packet.p_cnct.p_cnct__cversion  = protocol::FB_CONNECT_VERSION3;
  packet.p_cnct.p_cnct__client    = protocol::FB_CURRENT_ARCHITECTURE;

  //---------------------------------------- p_cnct__file [в UTF8]
  std::string tmp__utf8_database_name;

  if(!IBP_Utils::WStrToUtf8__Fast(ucs2_database_name,
                                  &tmp__utf8_database_name))
  {
   //ERROR - ошибка конвертирования имени базы данных в кодовую страницу UTF8
   IBP_ThrowSimpleError
    (E_FAIL,
     ibp_subsystem__remote_fb__pset02,
     ibp_mce_common__failed_to_convert_db_name_to_utf8_0);
  }//if

  {
   const size_t ch_file_name=tmp__utf8_database_name.length();

   if(!structure::can_numeric_cast(&packet.p_cnct.p_cnct__file.cstr_length,ch_file_name))
   {
    //ERROR - database name length too large

    t_ibp_error exc(E_FAIL,
                    ibp_subsystem__remote_fb__pset02,
                    ibp_mce_common__database_name_length_is_too_large_2);

    exc<<ch_file_name
       <<structure::get_numeric_limits(packet.p_cnct.p_cnct__file.cstr_length).max_value();

    exc.raise_me();
   }//if

   structure::static_numeric_cast(&packet.p_cnct.p_cnct__file.cstr_length,ch_file_name);
  }//local

  assert_s(sizeof(*tmp__utf8_database_name.c_str())==sizeof(*packet.p_cnct.p_cnct__file.cstr_address));

  packet.p_cnct.p_cnct__file.cstr_address=reinterpret_cast<const protocol::P_UCHAR*>(tmp__utf8_database_name.c_str());

  //---------------------------------------- p_cnct__user_id

  //Нужно добавить следующие элементы:
  // 1. P_CNCT_user [UTF8]
  // 2. P_CNCT_host [UTF8]
  // 3. P_CNCT_user_verification
  // 4. P_CNCT_login [UTF8]
  // 5. P_CNCT_plugin_name [UTF8] "Srp"
  // 6. P_CNCT_plugin_list [UTF8] "Srp, Win_Sspi, Legacy_Auth"
  // 7. P_CNCT_specific_data
  // 8. P_CNCT_client_crypt

  //------------ 1. P_CNCT_user
  clientConnectBlock.m_CPB.AppendMbcString_AsUTF8
   (protocol::set02::P_CNCT_user,
    L"protocol::set02::P_CNCT_user",
    RemoteFB__Utils::GetSystemUserName());

  //------------ 2. P_CNCT_host
  clientConnectBlock.m_CPB.AppendMbcString_AsUTF8
   (protocol::set02::P_CNCT_host,
    L"protocol::set02::P_CNCT_host",
    RemoteFB__Utils::GetComputerName());

  //------------ 3. P_CNCT_user_verification
  clientConnectBlock.m_CPB.AppendTag
   (protocol::set02::P_CNCT_user_verification);

  //----------- 4. P_CNCT_login [SRP, Legacy аутентификация]
  clientConnectBlock.GetCurrentAuthPlugin()->def_auth_params_in_cpb
   (clientConnectBlock);

  //----------- 5. P_CNCT_plugin_name
  clientConnectBlock.m_CPB.AppendMbcString_AsUTF8
   (protocol::set02::P_CNCT_plugin_name,
    L"protocol::set02::P_CNCT_plugin_name",
    clientConnectBlock.GetCurrentAuthPlugin()->get_name());

  //----------- 6. P_CNCT_plugin_list
  clientConnectBlock.m_CPB.AppendMbcString_AsUTF8
   (protocol::set02::P_CNCT_plugin_list,
    L"protocol::set02::P_CNCT_plugin_list",
    clientConnectBlock.GetAuthPluginNames());

  //----------- 7. P_CNCT_specific_data
  clientConnectBlock.m_CPB.AppendMultiPartParameter
   (protocol::set02::P_CNCT_specific_data,
    L"protocol::set02::P_CNCT_specific_data",
    clientConnectBlock.m_dataFromAuthPlugin.size(),
    clientConnectBlock.m_dataFromAuthPlugin.buffer()); //throw

  //----------- 8. P_CNCT_client_crypt

  //В fbclient эта настройка берется из конфигурационного файла.

  //! \note
  //!  Была мысль, что эту настройку нужно указывать внутри плагина SRP-аутентификации.
  //!  Но по-факту, шифрование это отдельная тема. Плагин аутентификации
  //!  может просто выругаться, что шифрование подключения он не поддерживает.
  //!  В настоящий момент, Legacy_Auth и Win_Sspi эту настройку не проверяют.

  switch(clientConnectBlock.m_DsProp__WireCrypt)
  {
   case ibp_ipropval__remote__wire_crypt::disabled:
   {
    clientConnectBlock.m_CPB.AppendInt
     (protocol::set02::P_CNCT_client_crypt,
      fb_api::ibp_frb_wire_crypt__disabled);

    break;
   }//case disabled

   case ibp_ipropval__remote__wire_crypt::default_:
   case ibp_ipropval__remote__wire_crypt::enabled:
   {
    clientConnectBlock.m_CPB.AppendInt
     (protocol::set02::P_CNCT_client_crypt,
      fb_api::ibp_frb_wire_crypt__enabled);

    break;
   }//case enabled

   case ibp_ipropval__remote__wire_crypt::required:
   {
    clientConnectBlock.m_CPB.AppendInt
     (protocol::set02::P_CNCT_client_crypt,
      fb_api::ibp_frb_wire_crypt__required);

    break;
   }//case required

   default:
   {
    RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_crypt_permission
     (c_bugcheck_src,
      L"#001",
      structure::to_underlying(clientConnectBlock.m_DsProp__WireCrypt));
   }//default
  }//switch

  //Формирование user_id завершено

  {
   const isc_base::t_isc_param_buffer_v1_builder::size_type
    cpb_BufferLength=clientConnectBlock.m_CPB.GetBufferLength();

   if(!structure::can_numeric_cast(&packet.p_cnct.p_cnct__user_id.cstr_length,cpb_BufferLength))
   {
    //ERROR - buffer with user information is too long

    IBP_ThrowErr_FormedParamBufIsTooLarge
     (ibp_subsystem__remote_fb__pset02,
      clientConnectBlock.m_CPB.GetBufferTypeName(),
      cpb_BufferLength,
      structure::get_numeric_limits(packet.p_cnct.p_cnct__user_id.cstr_length).max_value());
   }//if

   structure::static_numeric_cast
    (&packet.p_cnct.p_cnct__user_id.cstr_length,
     cpb_BufferLength);

   packet.p_cnct.p_cnct__user_id.cstr_address=clientConnectBlock.m_CPB.GetBuffer();
  }//local

  //---------------------------------------- p_cnct_versions
  {
   //Формируем список версий протоколов
   pversions_type pversions;

   {
    ole_lib::TVariant varPropValue__Protocol;

    if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL,nullptr,&varPropValue__Protocol))
    {
     pversions.push_back(protocol::FB_PROTOCOL_VERSION13);
    }
    else
    {
     assert(varPropValue__Protocol.vt==VT_BSTR);

     const auto strPropValue__Protocol
      =ole_lib::BStrToBox(varPropValue__Protocol.bstrVal);

  #ifdef IBP_BUILD_TESTCODE
     if(structure::equal_to_string(strPropValue__Protocol,ibprovider::ibp_propval__remote__protocol__set02))
     {
      pversions.push_back(protocol::FB_PROTOCOL_VERSION13);
     }
     else
  #endif
     if(structure::equal_to_string(strPropValue__Protocol,ibprovider::ibp_propval__remote__protocol__13))
     {
      pversions.push_back(protocol::FB_PROTOCOL_VERSION13);
     }
     else
     {
      //ERROR - [BUG CHECK] unknown remote protocol identifier

      // [2016-09-06]
      //  По идее мы сюда вообще не должны попадать.
      //  Вызывающая сторона должна это обеспечить.
      assert(false);

      RemoteFB__ErrorUtils::Throw__RequestedProtocolNotSupported
       (ibp_subsystem__remote_fb__pset02,
        strPropValue__Protocol);
     }//else
    }//else
   }//local

   //Получаем список архитектур протокола
   parchs_type parchs;

   self_type::Helper__TryConnect__GetProtocolArchitectures
    (clientConnectBlock.m_spDsPropValues,
     parchs);

   assert(!parchs.empty());

   //Определяем тип (режим работы) протокола
   protocol::P_USHORT minPType=0;
   protocol::P_USHORT maxPType=0;

   self_type::Helper__TryConnect__GetProtocolType
    (clientConnectBlock.m_spDsPropValues,
     &clientConnectBlock.m_expectedPTypeDescr,
     &minPType,
     &maxPType);

   //---------- сжатие данных
   switch(clientConnectBlock.m_DsProp__WireCompression)
   {
    case ibp_ipropval__remote__wire_compression::default_:
    case ibp_ipropval__remote__wire_compression::disabled:
    {
     break;
    }

    case ibp_ipropval__remote__wire_compression::enabled:
    case ibp_ipropval__remote__wire_compression::required:
    {
     maxPType|=protocol::set02::pflag_compress;
     break;
    }

    default:
    {
     RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_compression_rule
      (c_bugcheck_src,
       L"#002",
       structure::to_underlying(clientConnectBlock.m_DsProp__WireCompression));
    }//default
   }//switch x

   //---------- на всякий случай, указываем вес в положительной части short-диапазона
   protocol::P_USHORT w=structure::t_numeric_limits<protocol::P_SHORT>::max_value();

   for(pversions_type::size_type iVer=0,_cVer(pversions.size());iVer!=_cVer;++iVer)
   {
    for(parchs_type::size_type iArch=0,_cArch(parchs.size());iArch!=_cArch;++iArch)
    {
     //до нуля мы опуститься не должны
     assert(w>0);

     packet.p_cnct.add_cntr_version
      (pversions[iVer],
       parchs[iArch],
       minPType,
       maxPType,
       /*weight=*/w);

     --w;
    }//for iArch
   }//for iVersion
  }//local

  //----------------------------------------
  RemoteFB__OperationContext portOpCtx;

  pPort->send_packet(portOpCtx,
                     packet); //throw
 }//local - SEND

 //-------------------------------------------------------- 2. RECV: answer for op_connect
 assert(pPort);

 // - Получаем ответ от сервера
 // - Вызываем функцию завершения инициализации подключения

 const tagAcceptConnectFuncs* pAcceptConnectFuncs=nullptr;

 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pPort->receive_packet(portOpCtx,
                        packet); //throw

  switch(packet.operation)
  {
   case protocol::set02::op_reject:
   {
    //FAIL. connection has been rejected
    return false;
   }//op_reject

   //! \note
   //!  В fbclient.dll v3 в этой точке еще обрабатываются
   //!  - op_accept_data. допускаю такую возможность...
   //!  - op_accept. это если подключаемся к старым серверам.
   //!  - op_response. не понятно - тут должно быть сообщение об ошибке авторизации?

   case protocol::set02::op_accept_data:
   {
    pAcceptConnectFuncs=&sm_accept_funcs__accept_data;
    break;
   }//case - op_accept_data

   case protocol::set02::op_cond_accept:
   {
    pAcceptConnectFuncs=&sm_accept_funcs__cond_accept;
    break;
   }//case - op_cond_accept

   case protocol::set02::op_response:
   {
    //Мы ожидаем ошибку. Исходим из того, что мы имеем дело с FB3.

    //В данную точку можно попасть, если указать очень длинное имя файла базы данных.
    // FB3 возвращает ошибку (isc_random): "Firebird::string - length exceeds predefined limit"

    //Настраиваем сервис для обработки серверных ошибок.
    pPort->RegService
     (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
      db_obj::dbms_fb::v03_0_0::create_svc__status_vector_utils());

    api::pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
     (pPort,
      c_OperationID,
      packet.p_resp,
      E_FAIL); //throw!

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#003",
      me_bug_check__we_expected_the_error_0);
   }//case - op_response

   default:
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pPort,
      c_bugcheck_src,
      L"#004",
      packet.operation);
   }//default
  }//switch

  //----------------------------------------
  assert(pAcceptConnectFuncs);

  switch(packet.p_acpd.p_acpt__version)
  {
   case protocol::FB_PROTOCOL_VERSION13:
   {
    assert(pAcceptConnectFuncs->P13);

    pAcceptConnectFuncs->P13
     (pPort,
      packet,
      ucs2_database_name,
      clientConnectBlock,
      FinalOpFuncs);

    break;
   }//case protocol::PROTOCOL_VERSION13

   default:
   {
    //ERROR - [BUG CHECK] accepted unexpected protocol version

    RemoteFB__ErrorUtils::Throw_BugCheck_AcceptedUnexpectedProtocolVersion
     (c_bugcheck_src,
      L"#005",
      packet.p_acpd.p_acpt__version);
   }//default
  }//switch packet.p_acpd.p_acpt_version
 }//local - RECV

 //-------------------------------------------------------- 3. EXIT
 return true;
}//Helper__TryConnect

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                                            const wstr_box_type              authPluginName)
{
 if(RemoteFB__Utils::EqualPluginNames(authPluginName,plugins::auth::win_sspi::RemoteFB__Plugin_Auth_WinSSPI_Factory::GetName()))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Win_Sspi(clientConnectBlock);
 }
 else
 if(RemoteFB__Utils::EqualPluginNames(authPluginName,plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP::GetName()))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Srp(clientConnectBlock);
 }
 else
 if(RemoteFB__Utils::EqualPluginNames(authPluginName,plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP224::GetName()))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Srp224(clientConnectBlock);
 }
 else
 if(RemoteFB__Utils::EqualPluginNames(authPluginName,plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP256::GetName()))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Srp256(clientConnectBlock);
 }
 else
 if(RemoteFB__Utils::EqualPluginNames(authPluginName,plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP384::GetName()))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Srp384(clientConnectBlock);
 }
 else
 if(RemoteFB__Utils::EqualPluginNames(authPluginName,plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP512::GetName()))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Srp512(clientConnectBlock);
 }
 else
 if(RemoteFB__Utils::EqualPluginNames(authPluginName,plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::GetName()))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Legacy_Auth(clientConnectBlock);
 }
 else
 {
  // Неподдерживаемый сервис аутентификации. Само имя может быть известно. Но вот
  // только в данной подсистеме оно не поддерживается.

  RemoteFB__ErrorUtils::Throw__AuthServiceNotSupported
   (ibp_subsystem__remote_fb__pset02,
    authPluginName);
 }//else

 assert(clientConnectBlock.GetCurrentAuthPlugin());

 //------------- проверка согласованности свойств инициализации
 ole_lib::TVariant varPropValue__IntegratedAuth;

 if(clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_INTEGRATED,nullptr,&varPropValue__IntegratedAuth))
 {
  assert(varPropValue__IntegratedAuth.vt==VT_BSTR);

  const auto strPropValue__IntegratedAuth
   =ole_lib::BStrToBox(varPropValue__IntegratedAuth.bstrVal);

  //нам еще указали и интегрированную аутентификацию
  if(IBP_Utils::IsSSPI(strPropValue__IntegratedAuth))
  {
   //SSPI-аутентификация

   if(clientConnectBlock.GetCurrentAuthPlugin()->get_name()==
      plugins::auth::win_sspi::RemoteFB__Plugin_Auth_WinSSPI_Factory::GetName())
   {
    //настройки согласованы. задействуем SSPI-аутентификацию

    return;
   }//if

   //ERROR - конфликт сервиса интегрированной аутентификации и явно указанного
   //сервиса аутентификации.

   t_ibp_error exc(DB_SEC_E_AUTH_FAILED,
                   ibp_subsystem__remote_fb__pset02,
                   ibp_mce_remote__incompatible_auth_services_2,
                   IBP_CreateCustomErrorFor_AuthFailed());

   exc<<authPluginName
      <<ibprovider::g_IBP_IntegratedAuth__SSPI;

   exc.raise_me();
  }//if IsSSPI

  assert(!IBP_Utils::IsSSPI(strPropValue__IntegratedAuth));

  IBP_ThrowUnknownNameOfIntegratedAuth
   (ibp_subsystem__remote_fb__pset02,
    strPropValue__IntegratedAuth);
 }//if - есть настройка интегрированной аутентификации

 // "Intergrated Security" в строке подключения отсутствует
}//Helper__TryConnect__SetAuthPlugin

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin__Win_Sspi
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 clientConnectBlock.RegAuthPluginFactory
  (plugins::auth::win_sspi::RemoteFB__Plugin_Auth_WinSSPI_Factory::Create());

 _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2
          (plugins::auth::win_sspi::RemoteFB__Plugin_Auth_WinSSPI_Factory::GetName()));
}//Helper__TryConnect__SetAuthPlugin__Win_Sspi

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin__Srp
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 typedef plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP
  factory_type;

 clientConnectBlock.RegAuthPluginFactory
  (factory_type::Create());

 _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2
  (factory_type::GetName()));
}//Helper__TryConnect__SetAuthPlugin__Srp

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin__Srp224
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 typedef plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP224
  factory_type;

 clientConnectBlock.RegAuthPluginFactory
  (factory_type::Create());

 _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2
  (factory_type::GetName()));
}//Helper__TryConnect__SetAuthPlugin__Srp224

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin__Srp256
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 typedef plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP256
  factory_type;

 clientConnectBlock.RegAuthPluginFactory
  (factory_type::Create());

 _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2
  (factory_type::GetName()));
}//Helper__TryConnect__SetAuthPlugin__Srp256

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin__Srp384
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 typedef plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP384
  factory_type;

 clientConnectBlock.RegAuthPluginFactory
  (factory_type::Create());

 _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2
  (factory_type::GetName()));
}//Helper__TryConnect__SetAuthPlugin__Srp384

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin__Srp512
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 typedef plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP512
  factory_type;

 clientConnectBlock.RegAuthPluginFactory
  (factory_type::Create());

 _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2
  (factory_type::GetName()));
}//Helper__TryConnect__SetAuthPlugin__Srp512

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__SetAuthPlugin__Legacy_Auth
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 clientConnectBlock.RegAuthPluginFactory
  (plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::Create());

 _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2
  (plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::GetName()));
}//Helper__TryConnect__SetAuthPlugin__Legacy_Auth

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__RegDefaultAuthPlugin
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 //----------------------------------------- WIN_SSPI
 for(;;)
 {
  ole_lib::TVariant varPropValue__IntegratedAuth;

  if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_INTEGRATED,nullptr,&varPropValue__IntegratedAuth))
   break;

  assert(varPropValue__IntegratedAuth.vt==VT_BSTR);

  const auto strPropValue__IntegratedAuth
   =ole_lib::BStrToBox(varPropValue__IntegratedAuth.bstrVal);

  if(IBP_Utils::IsSSPI(strPropValue__IntegratedAuth))
   return Helper__TryConnect__SetAuthPlugin__Win_Sspi(clientConnectBlock);

  //ERROR - неизвестный способ интегрированной аутентификации

  IBP_ThrowUnknownNameOfIntegratedAuth
   (ibp_subsystem__remote_fb__pset02,
    strPropValue__IntegratedAuth);
 }//for[ever]

 //----------------------------------------- SRP256, SRP, Legacy
 for(;;)
 {
  if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_USERID,nullptr,nullptr))
   break;

  if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_PASSWORD,nullptr,nullptr))
   break;

  clientConnectBlock.RegAuthPluginFactory
   (plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP256::Create());

  clientConnectBlock.RegAuthPluginFactory
   (plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP::Create());

  clientConnectBlock.RegAuthPluginFactory
   (plugins::auth::legacy::RemoteFB__Plugin_Auth_Legacy_Factory::Create());

  _VERIFY(clientConnectBlock.SetCurrentAuthPlugin2(plugins::auth::srp::RemoteFB__Plugin_Auth_SRP_Factory__SRP256::GetName()));

  return;
 }//for[ever]

 //----------------------------------------- ERROR

 //ERROR - не удалось определить сервис аутентификации.
 //Укажите его явно или определите в строке подключения логин и пароль пользователя.

 t_ibp_error exc(DB_SEC_E_AUTH_FAILED,
                 ibp_subsystem__remote_fb__pset02,
                 ibp_mce_remote__cant_detect_auth_service_0,
                 IBP_CreateCustomErrorFor_AuthFailed());

 exc.raise_me();
}//Helper__TryConnect__RegDefaultAuthPlugin

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__GetProtocolArchitectures
      (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
       parchs_type&                                                     parchs)
{
 assert(pDsPropValues);

 parchs.clear();

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__GetProtocolArchitectures";

 //-----------------------------------------
 ole_lib::TVariant varPropValue__PArch;

 if(!pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL_ARCHITECTURE,nullptr,&varPropValue__PArch))
 {
  //используем настройки по умолчанию.

  parchs.push_back(protocol::arch_generic);
  parchs.push_back(protocol::FB_CURRENT_ARCHITECTURE);

  return;
 }//if

 assert(varPropValue__PArch.vt==VT_BSTR);

 const auto strPropValue__PArch
  =ole_lib::BStrToBox(varPropValue__PArch.bstrVal);

 //----------------------------------------- TRIM
 auto sPropValue=strPropValue__PArch.begin();
 auto ePropValue=strPropValue__PArch.end();

 sPropValue=structure::miss_space(sPropValue,ePropValue);

 ePropValue=structure::miss_space_back(sPropValue,ePropValue);

 assert(sPropValue<=ePropValue);

 //-----------------------------------------

 for(;;)
 {
  //ищем начало данных
  sPropValue=structure::miss_space(sPropValue,ePropValue);

  //особый случай: пустая строка
  if(parchs.empty() && sPropValue==ePropValue)
   break;

  auto const sName(sPropValue);

  sPropValue=std::find(sPropValue,ePropValue,IBP_T(','));

  //игнорируем хвостовые пробелы
  auto const eName(structure::miss_space_back(sName,sPropValue));

  assert(sName<=eName);

  if(sName==eName)
  {
   //ERROR - ошибка в строке с перечислением архитектур протокола

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#001",
     me_bug_check__mistake_in_list_with_protocol_architectures_0);
  }//if

  protocol::P_ARCH p_arch;

  if(structure::equal_to_string(sName,eName,ibprovider::ibp_propval__remote__parch__generic))
  {
   p_arch=protocol::arch_generic;
  }
  else
  if(structure::equal_to_string(sName,eName,ibprovider::ibp_propval__remote__parch__symmetric))
  {
   p_arch=protocol::FB_CURRENT_ARCHITECTURE;
  }
  else
  {
   //ERROR - unexpected name protocol architecture

   t_ibp_error exc(DB_E_NOTSUPPORTED,
                   ibp_subsystem__remote_fb__pset02,
                   ibp_mce_remote__unsupported_protocol_architecture_1);

   exc<<t_ibp_string(sName,eName);

   exc.raise_me();
  }//else

  if(std::find(parchs.begin(),parchs.end(),p_arch)!=parchs.end())
  {
   //ERROR - многократное указание архитектуры протокола

   structure::wstr_formatter
    freason(me_bug_check__mult_enum_of_protocol_architecture_1);

   freason<<t_ibp_string(sName,eName);

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#002",
     freason.c_str());
  }//if

  assert(!parchs.full());

  parchs.push_back(p_arch);

  //-------
  if(sPropValue==ePropValue)
   break;

  //пропуск запятой
  assert((*sPropValue)==IBP_T(','));

  ++sPropValue;
 }//for[ever]

 if(parchs.empty())
 {
  //ERROR - отсутствует определение допустимых архитектур протокола

  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#003",
    me_bug_check__empty_list_of_protocol_architectures_0);
 }//if

 assert(!parchs.empty());
}//Helper__TryConnect__GetProtocolArchitectures

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__TryConnect__GetProtocolType
      (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
       expected_ptype_descr_type_N*                               const pExpectedProtocolType,
       protocol::P_USHORT*                                        const pMinProtocolType,
       protocol::P_USHORT*                                        const pMaxProtocolType)
{
 assert(pDsPropValues);
 assert(pExpectedProtocolType!=nullptr);
 assert(pMinProtocolType!=nullptr);
 assert(pMaxProtocolType!=nullptr);

 //-----------------------------------------
 //настройка по умолчанию

 pExpectedProtocolType->reset();

 (*pMinProtocolType)=protocol::set02::ptype_batch_send;
 (*pMaxProtocolType)=protocol::set02::ptype_lazy_send;

 //-----------------------------------------
 ole_lib::TVariant varPropValue__PType;

 if(!pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL_TYPE,nullptr,&varPropValue__PType))
  return;

 assert(varPropValue__PType.vt==VT_BSTR);

 const auto strPropValue__PType
  =ole_lib::BStrToBox(varPropValue__PType.bstrVal);

 //-----------------------------------------

 //! \note
 //!  13-ый протокол (FB3) не поддерживает rpc тип соединения.

 if(structure::equal_to_string(strPropValue__PType,ibprovider::ibp_propval__remote__ptype__batch_send))
 {
  (*pMinProtocolType)=protocol::set02::ptype_batch_send;
  (*pMaxProtocolType)=protocol::set02::ptype_batch_send;

  (*pExpectedProtocolType)=expected_ptype_descr_type
                             (protocol::set02::ptype_batch_send,
                              ibprovider::ibp_propval__remote__ptype__batch_send);
  return;
 }//if - batch_send

 if(structure::equal_to_string(strPropValue__PType,ibprovider::ibp_propval__remote__ptype__out_of_band))
 {
  (*pMinProtocolType)=protocol::set02::ptype_out_of_band;
  (*pMaxProtocolType)=protocol::set02::ptype_out_of_band;

  (*pExpectedProtocolType)=expected_ptype_descr_type
                             (protocol::set02::ptype_out_of_band,
                              ibprovider::ibp_propval__remote__ptype__out_of_band);
  return;
 }//if - out_of_band

 if(structure::equal_to_string(strPropValue__PType,ibprovider::ibp_propval__remote__ptype__lazy_send))
 {
  (*pMinProtocolType)=protocol::set02::ptype_lazy_send;
  (*pMaxProtocolType)=protocol::set02::ptype_lazy_send;

  (*pExpectedProtocolType)=expected_ptype_descr_type
                             (protocol::set02::ptype_lazy_send,
                              ibprovider::ibp_propval__remote__ptype__lazy_send);
  return;
 }//if - lazy_send

 //настройка по умолчанию.
 //указываем имя желаемого типа протокола подключения.

 (*pExpectedProtocolType)=expected_ptype_descr_type(strPropValue__PType);

 return;
}//Helper__TryConnect__GetProtocolType

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET02_v01::Helper__Initialize__SetProtocolInfo_P13
                                           (port_type*                            const pPort,
                                            const RemoteFB__ClientConnectBlock_v2&      clientConnectBlock,
                                            const protocol::set02::P_OP_ACPT&           acpt,
                                            transmission::RemoteFB__PacketStream* const pPacketStream)
{
 assert(pPort);
 assert(pPacketStream!=nullptr);

 assert(pPort->m_ProtocolVersion.null());
 assert(pPort->m_PortFlags.null());

 //-----------------------------------------
 const wchar_t c_bugcheck_src[]
  =L"RemoteFB__PortInitializer_PSET02_v01::Helper__Initialize__SetProtocolInfo_P13";

 //-----------------------------------------
 pPort->m_ProtocolVersion=acpt.p_acpt__version;

 pPort->m_ProtocolArchitecture=acpt.p_acpt__architecture;

 //-----------------------------------------
 const protocol::P_USHORT
  protocolTypeId
   =acpt.p_acpt__type&protocol::set02::ptype_MASK;

 const protocol::P_USHORT
  protocolFlags
   =acpt.p_acpt__type&~protocol::set02::ptype_MASK;

 //-----------------------------------------
 port_type::port_flags_type PortFlags=0;

 if(acpt.p_acpt__architecture==protocol::FB_CURRENT_ARCHITECTURE)
  PortFlags|=port_type::PortFlag__symmetric;

 if(protocolTypeId!=protocol::set02::ptype_out_of_band)
  PortFlags|=port_type::PortFlag__no_oob;

 switch(protocolTypeId)
 {
  case protocol::set02::ptype_batch_send:
  case protocol::set02::ptype_out_of_band:
   break;

  case protocol::set02::ptype_lazy_send:
   PortFlags|=port_type::PortFlag__lazy;
   break;

  default:
  {
   //ERROR - [BUG CHECK] Сервер вернул неизвестный тип протокола

   RemoteFB__ErrorUtils::Throw__UnsupportedProtocolTypeID
    (ibp_subsystem__remote_fb__pset02,
     acpt.p_acpt__version&protocol::FB_PROTOCOL_MASK,
     protocolTypeId);
  }//default
 }//switch

 //-----------------------------------------
 if(!clientConnectBlock.m_expectedPTypeDescr.null())
 {
  //пользователь запрашивал конкретный тип протокола

  if(clientConnectBlock.m_expectedPTypeDescr.value()!=protocolTypeId)
  {
   RemoteFB__ErrorUtils::Throw__ReqProtocolTypeIdDoesNotSupported
    (ibp_subsystem__remote_fb__pset02,
     acpt.p_acpt__version&protocol::FB_PROTOCOL_MASK,
     clientConnectBlock.m_expectedPTypeDescr.value().ptypeSign);
  }//if

  assert_hint(clientConnectBlock.m_expectedPTypeDescr.value()==protocolTypeId);
 }//if

 //----------------------------------------- CHECK PTYPE FLAGS
 {
  auto protocolFlags_x=protocolFlags;

  if(protocolFlags_x&protocol::set02::pflag_compress)
  {
   protocolFlags_x&=~protocol::set02::pflag_compress;

   switch(clientConnectBlock.m_DsProp__WireCompression)
   {
    case ibp_ipropval__remote__wire_compression::default_:
    case ibp_ipropval__remote__wire_compression::enabled:
    case ibp_ipropval__remote__wire_compression::required:
    {
     api::p13::RemoteFB__P13__InitializeCompressor::exec
      (pPort,
       clientConnectBlock); //throw

     break;
    }

    case ibp_ipropval__remote__wire_compression::disabled:
    {
     //ERROR - server required compression.

     RemoteFB__ErrorUtils::Throw__ServerRequiredConnectionCompression
      (ibp_subsystem__remote_fb__pset02);
    }//case disabled

    default:
    {
     RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_compression_rule
      (c_bugcheck_src,
       L"#001",
       structure::to_underlying(clientConnectBlock.m_DsProp__WireCompression));
    }//default
   }//switch x
  }//if
  else
  {
   assert((protocolFlags_x&protocol::set02::pflag_compress)==0);

   switch(clientConnectBlock.m_DsProp__WireCompression)
   {
    case ibp_ipropval__remote__wire_compression::default_:
    case ibp_ipropval__remote__wire_compression::disabled:
    case ibp_ipropval__remote__wire_compression::enabled:
     break;

    case ibp_ipropval__remote__wire_compression::required:
    {
     //ERROR - compression not supported.

     RemoteFB__ErrorUtils::Throw__ServerRejectedConnectionCompression
      (ibp_subsystem__remote_fb__pset02);
    }//case required

    default:
    {
     RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_compression_rule
      (c_bugcheck_src,
       L"#002",
       structure::to_underlying(clientConnectBlock.m_DsProp__WireCompression));
    }//default
   }//switch

   if(protocolFlags_x!=0)
   {
    //ERROR - UNEXPECTED PROTOCOL FLAGS

    RemoteFB__ErrorUtils::Throw__UnsupportedProtocolFlags
     (ibp_subsystem__remote_fb__pset02,
      acpt.p_acpt__version&protocol::FB_PROTOCOL_MASK,
      protocolFlags_x);
   }//if

   assert_hint(protocolFlags_x==0);
  }//else
 }//local

 //-----------------------------------------
 pPort->m_PortFlags=PortFlags;

 //-----------------------------------------
 pPort->m_pPacketStream=pPacketStream;
}//Helper__Initialize__SetProtocolInfo_P13

////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset02*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
