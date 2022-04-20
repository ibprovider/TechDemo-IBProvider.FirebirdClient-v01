////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset01_v01.cpp
//! \brief   Утилиты для настройки порта подключения (P10, P11, P12)
//! \author  Kovalenko Dmitry
//! \date    29.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/initializers/pset01/v01/remote_fb__ports__base_v01__initializers__pset01_v01.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__attach.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__create.h"
#include "source/db_client/remote_fb/api/p11/remote_fb__api_p11__db__attach.h"
#include "source/db_client/remote_fb/api/p11/remote_fb__api_p11__db__create.h"
#include "source/db_client/remote_fb/api/p10/remote_fb__api_p10__db__attach.h"
#include "source/db_client/remote_fb/api/p10/remote_fb__api_p10__db__create.h"

#include "source/db_client/remote_fb/protocol/set01/remote_fb__protocol_set01.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__utils.h"

#include "source/db_obj/isc_base/isc_param_buffer_v1_builder.h"
#include "source/db_obj/db_utility.h"

#include "source/error_services/ibp_error_messages.h"
#include "source/ibp_utils.h"

#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset01{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET01_v01

const RemoteFB__PortInitializer_PSET01_v01::tag_connect_finalizator
 RemoteFB__PortInitializer_PSET01_v01::sm_finalizator_for_create=
{
 /*P10*/api::p10::RemoteFB__API_P10__CreateDatabase::exec,
 /*P11*/api::p11::RemoteFB__API_P11__CreateDatabase::exec,
 /*P12*/api::p12::RemoteFB__API_P12__CreateDatabase::exec,
};//sm_finalizator_for_create

//------------------------------------------------------------------------
const RemoteFB__PortInitializer_PSET01_v01::tag_connect_finalizator
 RemoteFB__PortInitializer_PSET01_v01::sm_finalizator_for_attach=
{
 /*P10*/api::p10::RemoteFB__API_P10__AttachToDatabase::exec,
 /*P11*/api::p11::RemoteFB__API_P11__AttachToDatabase::exec,
 /*P12*/api::p12::RemoteFB__API_P12__AttachToDatabase::exec,
};//sm_finalizator_for_attach

//------------------------------------------------------------------------
bool RemoteFB__PortInitializer_PSET01_v01::TryConnectToDatabase
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
bool RemoteFB__PortInitializer_PSET01_v01::TryCreateDatabase
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
bool RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect
      (port_type*                                           const pPort,
       wstr_box_type                                        const ucs2_database_name,
       oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
       const tag_connect_finalizator&                             FinalOpFuncs)
{
 assert(pPort!=nullptr);
 assert(pDsPropValues);

 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect";

 //-----------------------------------------------------------------------
 RemoteFB__ClientConnectBlock_v1
  clientConnectBlock(pDsPropValues);

 //-----------------------------------------
 switch(const auto x=clientConnectBlock.m_spDsPropValues->Get_Remote_WireCrypt())
 {
  case ibp_ipropval__remote__wire_crypt::default_:
  case ibp_ipropval__remote__wire_crypt::disabled:
   //мы и так не поддерживаем шифрование подключения
   break;

  case ibp_ipropval__remote__wire_crypt::enabled:
   //шифрование разрешено, но мы его не поддерживаем.
   break;

  case ibp_ipropval__remote__wire_crypt::required:
  {
   //ERROR - шифрование соединения не поддерживается

   IBP_ThrowSimpleError
    (DB_E_NOTSUPPORTED,
     ibp_subsystem__remote_fb__pset01,
     ibp_mce_remote__wire_crypt_not_supported_0);
  }//case

  default:
  {
   RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_crypt_permission
    (c_bugcheck_src,
     L"#001",
     structure::to_underlying(x));
  }//default
 }//switch x

 //-----------------------------------------
 switch(const auto x=clientConnectBlock.m_spDsPropValues->Get_Remote_WireCompression())
 {
  case ibp_ipropval__remote__wire_compression::default_:
  case ibp_ipropval__remote__wire_compression::disabled:
   //мы и так не поддерживаем сжатие подключения
   break;

  case ibp_ipropval__remote__wire_compression::enabled:
   //сжатие разрешено, но мы его не поддерживаем.
   break;

  case ibp_ipropval__remote__wire_compression::required:
  {
   //ERROR - Сжатие соединения не поддерживается

   IBP_ThrowSimpleError
    (DB_E_NOTSUPPORTED,
     ibp_subsystem__remote_fb__pset01,
     ibp_mce_remote__wire_compression_not_supported_0);
  }//case

  default:
  {
   RemoteFB__ErrorUtils::Throw_BugCheck__unknown_wire_compression_rule
    (c_bugcheck_src,
     L"#002",
     structure::to_underlying(x));
  }//default
 }//switch x

 //-----------------------------------------
 ole_lib::TVariant varPropValue__AuthName;

 if(clientConnectBlock.m_spDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,
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

 //-------------------------------------------------------- 1. SEND: op_connect
 {
  protocol::set01::PACKET_V01 packet;

  packet.operation                = protocol::set01::op_connect;
  packet.p_cnct.p_cnct__operation = protocol::set01::op_attach;
  packet.p_cnct.p_cnct__cversion  = protocol::FB_CONNECT_VERSION2;
  packet.p_cnct.p_cnct__client    = protocol::FB_CURRENT_ARCHITECTURE;

  //---------------------------------------- p_cnct__file
#if 0
  // [2014-11-23]
  // Работает и без этих данных. В op_attach можно передавать имя файла в UTF8-формате.

  {
   size_t ch_file_name=structure::string_length(database_name);

   if(!structure::can_numeric_cast(&packet.p_cnct.p_cnct_file.cstr_length,ch_file_name))
   {
    //ERROR - database name length too long

    assert(false);
   }//if

   structure::static_numeric_cast(&packet.p_cnct.p_cnct_file.cstr_length,ch_file_name);
  }//local

  assert_s(sizeof(*database_name)==sizeof(*packet.p_cnct.p_cnct_file.cstr_address));

  packet.p_cnct.p_cnct_file.cstr_address=reinterpret_cast<const protocol::P_UCHAR*>(database_name);
#endif

  //---------------------------------------- p_cnct__user_id
  isc_base::t_isc_param_buffer_v1_builder user_id(L"user_id");

  // Нужно выяснить зачем нужны эти данные. И если они все таки нужны,
  // То может имеет смысл из передать через DPB в UTF8-формате?

  // [2015-02-03] Firebird 2.5
  //  - Через DPB эти данные передать не получится
  //
  //  - Сервер использует P_CNCT_user и P_CNCT_user_verification для
  //    формирования rem_port::port_user_name.
  //    Если их не передать, то сервер сформирует и установит строку "guest.-1.-1"
  //
  //    Если сервер отклонит подключение, то port_user_name будет использован
  //    при формировании сообщения об ошибке, которое запишут в лог.
  //
  //  - В attach_database2, rem_port::port_user_name будет
  //     - проверено на непустоту (а это поле не пустое)
  //     - упаковано в UTF8
  //     - добавлено в DPB с тегом isc_dpb_sys_user_name.
  //
  //  - В DatabaseOptions::get [isc_dpb_sys_user_name] будут сохранены в
  //    DatabaseOptions::dpb_sys_user_name.
  //
  //  - В getUserInfo (jrd.cpp) DatabaseOptions::dpb_sys_user_name может быть
  //    использован для извления имени пользователя (например, Embedded сервера (?))
  //    через функцию ISC_get_user.
  //
  //    При этом WinNT-версия ISC_get_user не использует эти данные,
  //    а тупо вызывает GetUserName и получает имя текущего пользователя.
  //
  // В итоге.
  //  - Будем передавать эти данные также как это делает fbclient.dll.
  //    Хотя, формально, это какая-та бесмысленная охинея.

  user_id.AppendMbcString
   (protocol::set01::P_CNCT_user,
    L"protocol::set01::P_CNCT_user",
    RemoteFB__Utils::GetSystemUserName());

  // [2015-02-03] Вот эти данные в FB2.5 вообще не используются
  user_id.AppendMbcString
   (protocol::set01::P_CNCT_host,
    L"protocol::set01::P_CNCT_host",
    RemoteFB__Utils::GetComputerName());

  user_id.AppendTag
   (protocol::set01::P_CNCT_user_verification);

  {
   const isc_base::t_isc_param_buffer_v1_builder::size_type
    user_id_BufferLength=user_id.GetBufferLength();

   if(!structure::can_numeric_cast(&packet.p_cnct.p_cnct__user_id.cstr_length,user_id_BufferLength))
   {
    //ERROR - buffer with user information is too long

    IBP_ThrowErr_FormedParamBufIsTooLarge
     (ibp_subsystem__remote_fb__pset01,
      user_id.GetBufferTypeName(),
      user_id_BufferLength,
      structure::get_numeric_limits(packet.p_cnct.p_cnct__user_id.cstr_length).max_value());
   }//if

   structure::static_numeric_cast
    (&packet.p_cnct.p_cnct__user_id.cstr_length,
     user_id_BufferLength);

   packet.p_cnct.p_cnct__user_id.cstr_address=user_id.GetBuffer();
  }//local

  //---------------------------------------- p_cnct__versions
  {
   //Формируем список версий протоколов
   pversions_type pversions;

   {
    ole_lib::TVariant varPropValue__Protocol;

    if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL,nullptr,&varPropValue__Protocol))
    {
     pversions.push_back(protocol::FB_PROTOCOL_VERSION12);
     pversions.push_back(protocol::FB_PROTOCOL_VERSION11);
     pversions.push_back(protocol::FB_PROTOCOL_VERSION10);
    }
    else
    {
     assert(varPropValue__Protocol.vt==VT_BSTR);

     const auto strPropValue__Protocol
      =ole_lib::BStrToBox(varPropValue__Protocol.bstrVal);

  #ifdef IBP_BUILD_TESTCODE
     if(structure::equal_to_string(strPropValue__Protocol,ibprovider::ibp_propval__remote__protocol__set01))
     {
      pversions.push_back(protocol::FB_PROTOCOL_VERSION12);
      pversions.push_back(protocol::FB_PROTOCOL_VERSION11);
      pversions.push_back(protocol::FB_PROTOCOL_VERSION10);
     }
     else
  #endif
     if(structure::equal_to_string(strPropValue__Protocol,ibprovider::ibp_propval__remote__protocol__10))
     {
      pversions.push_back(protocol::FB_PROTOCOL_VERSION10);
     }
     else
     if(structure::equal_to_string(strPropValue__Protocol,ibprovider::ibp_propval__remote__protocol__11))
     {
      pversions.push_back(protocol::FB_PROTOCOL_VERSION11);
     }
     else
     if(structure::equal_to_string(strPropValue__Protocol,ibprovider::ibp_propval__remote__protocol__12))
     {
      pversions.push_back(protocol::FB_PROTOCOL_VERSION12);
     }
     else
     {
      //ERROR - [BUG CHECK] unknown remote protocol identifier

      // [2016-09-06]
      //  По идее мы сюда вообще не должны попадать.
      //  Вызывающая сторона должна это обеспечить.
      assert(false);

      RemoteFB__ErrorUtils::Throw__RequestedProtocolNotSupported
       (ibp_subsystem__remote_fb__pset01,
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

   self_type::Helper__TryConnect__GetProtocolType__P10_P11_P12
    (clientConnectBlock.m_spDsPropValues,
     &clientConnectBlock.m_expectedPTypeDescr,
     &minPType,
     &maxPType);

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

  pPort->send_packet
   (portOpCtx,
    packet); //throw
 }//local - SEND

 //-------------------------------------------------------- 2. RECV: answer for op_connect
 assert(pPort);

 // - Получаем ответ от сервера
 // - Вызываем функцию завершения инициализации подключения

 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet;

  pPort->receive_packet
   (portOpCtx,
    packet); //throw

  switch(packet.operation)
  {
   case protocol::set01::op_accept:
   {
    //OK. connection has been accepted

    break;
   }//op_accept

   case protocol::set01::op_reject:
   {
    //FAIL. connection has been rejected
    return false;
   }//op_reject

   default:
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pPort,
      c_bugcheck_src,
      L"#003",
      packet.operation);
   }//default
  }//switch packet.p_operation

  //----------------------------------------
  assert(packet.operation==protocol::set01::op_accept);

  switch(packet.p_acpt.p_acpt__version)
  {
   case protocol::FB_PROTOCOL_VERSION10:
   {
    Helper__FinishConnect_P10
     (pPort,
      packet,
      ucs2_database_name,
      clientConnectBlock,
      FinalOpFuncs);

    break;
   }//case protocol::PROTOCOL_VERSION10

   case protocol::FB_PROTOCOL_VERSION11:
   {
    Helper__FinishConnect_P11
     (pPort,
      packet,
      ucs2_database_name,
      clientConnectBlock,
      FinalOpFuncs);

    break;
   }//case protocol::PROTOCOL_VERSION11

   case protocol::FB_PROTOCOL_VERSION12:
   {
    Helper__FinishConnect_P12
     (pPort,
      packet,
      ucs2_database_name,
      clientConnectBlock,
      FinalOpFuncs);

    break;
   }//case protocol::PROTOCOL_VERSION12

   default:
   {
    //ERROR - [BUG CHECK] accepted unexpected protocol version

    RemoteFB__ErrorUtils::Throw_BugCheck_AcceptedUnexpectedProtocolVersion
     (c_bugcheck_src,
      L"#004",
      packet.p_acpt.p_acpt__version);
   }//default
  }//switch packet.p_acpt.p_acpt_version
 }//local - RECV

 //-------------------------------------------------------- 3. EXIT
 return true;
}//Helper__TryConnect

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__SetAuthPlugin
                                           (RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                            const wstr_box_type              authPluginName)
{
 if(IBP_Utils::EqualAsciiStr_i(authPluginName,ibprovider::ibp_propval__remote__auth__Win_Sspi))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Win_Sspi(clientConnectBlock);
 }
 else
 if(IBP_Utils::EqualAsciiStr_i(authPluginName,ibprovider::ibp_propval__remote__auth__Legacy_Auth))
 {
  self_type::Helper__TryConnect__SetAuthPlugin__Legacy_Auth(clientConnectBlock);
 }
 else
 {
  // Неподдерживаемый сервис аутентификации. Само имя может быть известно. Но вот
  // только в данной подсистеме оно не поддерживается.

  RemoteFB__ErrorUtils::Throw__AuthServiceNotSupported
   (ibp_subsystem__remote_fb__pset01,
    authPluginName);
 }//else

 assert(clientConnectBlock.m_AuthKind!=RemoteFB__ClientConnectBlock_v1::auth_kind__none);

 //------------- проверка согласованности свойств инициализации
 ole_lib::TVariant varPropValue__IntegratedAuth;

 if(clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_INTEGRATED,nullptr,&varPropValue__IntegratedAuth))
 {
  //нам еще указали и интегрированную аутентификацию

  assert(varPropValue__IntegratedAuth.vt==VT_BSTR);

  const auto strPropValue__IntegratedAuth
   =ole_lib::BStrToBox(varPropValue__IntegratedAuth.bstrVal);

  if(IBP_Utils::IsSSPI(strPropValue__IntegratedAuth))
  {
   //SSPI-аутентификация

   if(clientConnectBlock.m_AuthKind==RemoteFB__ClientConnectBlock_v1::auth_kind__sspi)
   {
    //настройки согласованы. задействуем SSPI-аутентификацию

    return;
   }//if

   //ERROR - конфликт сервиса интегрированной аутентификации и явно указанного
   //сервиса аутентификации.

   t_ibp_error exc(DB_SEC_E_AUTH_FAILED,
                   ibp_subsystem__remote_fb__pset01,
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

 // "Integrated Security" в строке подключения отсутствует
}//Helper__TryConnect__SetAuthPlugin

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__SetAuthPlugin__Win_Sspi
                                           (RemoteFB__ClientConnectBlock_v1& clientConnectBlock)
{
 assert(clientConnectBlock.m_AuthKind==RemoteFB__ClientConnectBlock_v1::auth_kind__none);

 clientConnectBlock.m_AuthKind=RemoteFB__ClientConnectBlock_v1::auth_kind__sspi;
}//Helper__TryConnect__SetAuthPlugin__Win_Sspi

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__SetAuthPlugin__Legacy_Auth
                                           (RemoteFB__ClientConnectBlock_v1& clientConnectBlock)
{
 assert(clientConnectBlock.m_AuthKind==RemoteFB__ClientConnectBlock_v1::auth_kind__none);

 clientConnectBlock.m_AuthKind=RemoteFB__ClientConnectBlock_v1::auth_kind__legacy;
}//Helper__TryConnect__SetAuthPlugin__Legacy_Auth

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__RegDefaultAuthPlugin
                                           (RemoteFB__ClientConnectBlock_v1& clientConnectBlock)
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
   (ibp_subsystem__remote_fb__pset01,
    strPropValue__IntegratedAuth);
 }//for[ever]

 //----------------------------------------- Legacy
 for(;;)
 {
  if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_USERID,nullptr,nullptr))
   break;

  if(!clientConnectBlock.m_spDsPropValues->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_AUTH_PASSWORD,nullptr,nullptr))
   break;

  return Helper__TryConnect__SetAuthPlugin__Legacy_Auth(clientConnectBlock);
 }//for[ever]

 //----------------------------------------- ERROR

 //ERROR - не удалось определить сервис аутентификации.
 //Укажите его явно или определите в строке подключения логин и пароль пользователя.

 t_ibp_error exc(DB_SEC_E_AUTH_FAILED,
                 ibp_subsystem__remote_fb__pset01,
                 ibp_mce_remote__cant_detect_auth_service_0,
                 IBP_CreateCustomErrorFor_AuthFailed());

 exc.raise_me();
}//Helper__TryConnect__RegDefaultAuthPlugin

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__GetProtocolArchitectures
      (const oledb::props2::IBP_OLEDB_Props2__Values__DATASOURCE* const pDsPropValues,
       parchs_type&                                                     parchs)
{
 assert(pDsPropValues);

 parchs.clear();

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__GetProtocolArchitectures";

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
                   ibp_subsystem__remote_fb__pset01,
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
void RemoteFB__PortInitializer_PSET01_v01::Helper__TryConnect__GetProtocolType__P10_P11_P12
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

 (*pMinProtocolType)=protocol::set01::ptype_rpc;
 (*pMaxProtocolType)=protocol::set01::ptype_lazy_send;

 //-----------------------------------------
 ole_lib::TVariant varPropValue__PType;

 if(!pDsPropValues->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__PROTOCOL_TYPE,nullptr,&varPropValue__PType))
  return;

 assert(varPropValue__PType.vt==VT_BSTR);

 const auto
  strPropValue__PType
   =ole_lib::BStrToBox(varPropValue__PType.bstrVal);

 //-----------------------------------------
 if(structure::equal_to_string(strPropValue__PType,ibprovider::ibp_propval__remote__ptype__rpc))
 {
  (*pMinProtocolType)=protocol::set01::ptype_rpc;
  (*pMaxProtocolType)=protocol::set01::ptype_rpc;

  (*pExpectedProtocolType)=expected_ptype_descr_type
                             (protocol::set01::ptype_rpc,
                              ibprovider::ibp_propval__remote__ptype__rpc);
  return;
 }//if - rpc

 if(structure::equal_to_string(strPropValue__PType,ibprovider::ibp_propval__remote__ptype__batch_send))
 {
  (*pMinProtocolType)=protocol::set01::ptype_batch_send;
  (*pMaxProtocolType)=protocol::set01::ptype_batch_send;

  (*pExpectedProtocolType)=expected_ptype_descr_type
                             (protocol::set01::ptype_batch_send,
                              ibprovider::ibp_propval__remote__ptype__batch_send);
  return;
 }//if - batch_send

 if(structure::equal_to_string(strPropValue__PType,ibprovider::ibp_propval__remote__ptype__out_of_band))
 {
  (*pMinProtocolType)=protocol::set01::ptype_out_of_band;
  (*pMaxProtocolType)=protocol::set01::ptype_out_of_band;

  (*pExpectedProtocolType)=expected_ptype_descr_type
                             (protocol::set01::ptype_out_of_band,
                              ibprovider::ibp_propval__remote__ptype__out_of_band);
  return;
 }//if - out_of_band

 if(structure::equal_to_string(strPropValue__PType,ibprovider::ibp_propval__remote__ptype__lazy_send))
 {
  (*pMinProtocolType)=protocol::set01::ptype_lazy_send;
  (*pMaxProtocolType)=protocol::set01::ptype_lazy_send;

  (*pExpectedProtocolType)=expected_ptype_descr_type
                             (protocol::set01::ptype_lazy_send,
                              ibprovider::ibp_propval__remote__ptype__lazy_send);
  return;
 }//if - lazy_send

 //настройка по умолчанию.
 //указываем имя желаемого типа протокола подключения.

 (*pExpectedProtocolType)=expected_ptype_descr_type(strPropValue__PType);

 return;
}//Helper__TryConnect__GetProtocolType__P10_P11_P12

//------------------------------------------------------------------------
void RemoteFB__PortInitializer_PSET01_v01::Helper__Initialize__SetProtocolInfo_P10_P11_P12
                                           (port_type*                            const pPort,
                                            const RemoteFB__ClientConnectBlock_v1&      clientConnectBlock,
                                            const protocol::set01::P_OP_ACPT&           acpt,
                                            transmission::RemoteFB__PacketStream* const pPacketStream)
{
 assert(pPort);
 assert(pPacketStream!=nullptr);

 assert(pPort->m_ProtocolVersion.null());
 assert(pPort->m_PortFlags.null());

 pPort->m_ProtocolVersion=acpt.p_acpt__version;

 pPort->m_ProtocolArchitecture=acpt.p_acpt__architecture;

 //-----------------------------------------
 port_type::port_flags_type PortFlags=0;

 if(acpt.p_acpt__architecture==protocol::FB_CURRENT_ARCHITECTURE)
  PortFlags|=port_type::PortFlag__symmetric;

 if(acpt.p_acpt__type!=protocol::set01::ptype_out_of_band)
  PortFlags|=port_type::PortFlag__no_oob;

 switch(acpt.p_acpt__type)
 {
  case protocol::set01::ptype_rpc:
   PortFlags|=port_type::PortFlag__rpc;
   break;

  case protocol::set01::ptype_batch_send:
  case protocol::set01::ptype_out_of_band:
   break;

  case protocol::set01::ptype_lazy_send:
   PortFlags|=port_type::PortFlag__lazy;
   break;

  default:
  {
   //ERROR - [BUG CHECK] Сервер вернул неизвестный тип протокола

   RemoteFB__ErrorUtils::Throw__UnsupportedProtocolTypeID
    (ibp_subsystem__remote_fb__pset01,
     acpt.p_acpt__version&protocol::FB_PROTOCOL_MASK,
     acpt.p_acpt__type);
  }//default
 }//switch

 pPort->m_PortFlags=PortFlags;

 //-----------------------------------------
 if(!clientConnectBlock.m_expectedPTypeDescr.null())
 {
  //пользователь запрашивал конкретный тип протокола

  if(clientConnectBlock.m_expectedPTypeDescr.value()!=acpt.p_acpt__type)
  {
   RemoteFB__ErrorUtils::Throw__ReqProtocolTypeIdDoesNotSupported
    (ibp_subsystem__remote_fb__pset01,
     acpt.p_acpt__version&protocol::FB_PROTOCOL_MASK,
     clientConnectBlock.m_expectedPTypeDescr.value().ptypeSign);
  }//if

  assert(clientConnectBlock.m_expectedPTypeDescr.value()==acpt.p_acpt__type);
 }//if

 //-----------------------------------------
 pPort->m_pPacketStream=pPacketStream;
}//Helper__Initialize__SetProtocolInfo_P10_P11_P12

////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset01*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
