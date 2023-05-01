////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__initialize_crypt.h
//! \brief   Утилиты подключения. Инициализация шифрования подключения.
//! \author  Kovalenko Dmitry
//! \date    12.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__initialize_crypt.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.h"

#include "source/db_client/remote_fb/ports/streams/crypt/arc4/remote_fb__ports__streams__crypt_arc4.h"

#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"

#include "source/db_client/remote_fb/protocol/set02/remote_fb__protocol_set02.h"

#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/ibp_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__InitializeCrypt

void RemoteFB__P13__InitializeCrypt::exec(port_type*                       const pPort,
                                          const RemoteFB__ClientConnectBlock_v2& clientConnectBlock)
{
 assert(pPort);

 //Добавить возможность отключения шифрования через строку подключения.

 //-----------------------------------------
 if(clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::disabled)
 {
  //клиент отключил шифрование соединения

  //Research: кстати, наверное сервер не должен перечислять типы ключи для шифрования
  assert(clientConnectBlock.m_knownServerKeys.empty());

  //да и клиент тоже не должен делать лишние телодвижения в виде перечисления ключей
  assert(clientConnectBlock.m_cryptKeys.empty());

  return;
 }//if fb3_cfg__wire_crypt__disabled

 assert(clientConnectBlock.m_DsProp__WireCrypt!=ibp_ipropval__remote__wire_crypt::disabled);

 //-----------------------------------------
 if(clientConnectBlock.m_knownServerKeys.empty())
 {
  //сервер не предложил ключи для шифрования соединения

  //Если клиент требовал шифрование соединения, то нужно выкинуть ошибку

  if(clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::required)
  {
   //ERROR - сервер не перечислил поддерживаемые типы ключей шифрования
   RemoteFB__ErrorUtils::Throw__WireCryptImpossibled_NoKnownSrvKeys
    (ibp_subsystem__remote_fb__p13,
     clientConnectBlock.GetCurrentAuthPlugin()->get_name());
  }//if

  //не смогли так не смогли. не очень и хотелось.
  assert(clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::default_ ||
         clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::enabled);

  return;
 }//if clientConnectBlock.m_knownServerKeys.empty()

 assert(!clientConnectBlock.m_knownServerKeys.empty());

 //-----------------------------------------
 if(clientConnectBlock.m_cryptKeys.empty())
 {
  //плагин аутентификации не предложил ключи для шифрования соединения

  if(clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::required)
  {
   //ERROR - Поскольку клиент требовал шифрование соединения, то выкидываем ошибку

   RemoteFB__ErrorUtils::Throw__WireCryptImpossibled_NoCryptKeys
    (ibp_subsystem__remote_fb__p13,
     clientConnectBlock.GetCurrentAuthPlugin()->get_name());
  }//if

  assert(clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::default_ ||
         clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::enabled);

  return;
 }//if clientConnectBlock.m_cryptKeys.empty()

 //-----------------------------------------
 for(size_t i1=0,_c1=clientConnectBlock.m_cryptKeys.size();i1!=_c1;++i1)
 {
  const RemoteFB__InternalCryptKey* const pCryptKey=clientConnectBlock.m_cryptKeys[i1];

  assert(pCryptKey);

  for(size_t i2=0,_c2=clientConnectBlock.m_knownServerKeys.size();i2!=_c2;++i2)
  {
   const RemoteFB__KnownServerKey* const pKnownKey=clientConnectBlock.m_knownServerKeys[i2];

   assert(pKnownKey);

   if(pCryptKey->GetType()!=pKnownKey->wstrType)
    continue;

   //--------------------------------------- Пытаемся установить метод шифрования
   if(self_type::Helper__TryKey(pPort,
                                pKnownKey,
                                pCryptKey))
   {
    return;
   }
  }//for i2
 }//for i1

 //---------------------------------------

 //Если шифрование соединения не является обязательным, то
 //игнорируем возникшую проблему несогласованности ключей

 switch(clientConnectBlock.m_DsProp__WireCrypt)
 {
  case ibp_ipropval__remote__wire_crypt::default_:
  case ibp_ipropval__remote__wire_crypt::enabled:
   return;
 }//switch

 assert(clientConnectBlock.m_DsProp__WireCrypt==ibp_ipropval__remote__wire_crypt::required);

 //---------------------------------------
 //ERROR - не удалось установить зашифрованное соединение

 RemoteFB__ErrorUtils::Throw__WireCryptImpossibled_NoSupportForKnownServerKeys
  (ibp_subsystem__remote_fb__p13,
   clientConnectBlock.GetCurrentAuthPlugin()->get_name());
}//Helper__InitializeCrypt_P13

//------------------------------------------------------------------------
bool RemoteFB__P13__InitializeCrypt::Helper__TryKey
                                           (port_type*                        const pPort,
                                            const RemoteFB__KnownServerKey*   const pKnownServerKey,
                                            const RemoteFB__InternalCryptKey* const pCryptKey)
{
 assert(pPort);
 assert(pPort->m_spSocket);

 // [2016-09-13]
 //  Порт должен быть привязан к исходному, транспортному потоку!
 // [2020-01-10]
 //  Или к компрессору!
 assert(pPort->m_spSocket->GetStreamClass()==RemoteFB__PortStream::stream_class__transport ||
        pPort->m_spSocket->GetStreamClass()==RemoteFB__PortStream::stream_class__compressor);

 assert(pKnownServerKey);
 assert(!pKnownServerKey->wstrPlugin.empty());
 assert(!pKnownServerKey->wstrType.empty());

 assert(pCryptKey);

 assert(pKnownServerKey->wstrType==pCryptKey->GetType());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P13__InitializeCrypt::Helper__TryKey";

 //----------------------------------------- Запрашиваем поток с шифрованием
 const RemoteFB__PortStreamPtr
  spCryptStream
   (self_type::Helper__CreateNotBindedCryptStream
     (pPort,
      pKnownServerKey->wstrPlugin,
      pCryptKey));

 if(!spCryptStream)
  return false;

 //поток не привязан
 assert(!spCryptStream->GetParentStream());

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_crypt;

 //----------------------------------------------------- 1. SEND: op_crypt
 {
  protocol::set02::PACKET_V02 packet;

  packet.operation=c_OperationID;

  protocol::set02::P_OP_CRYPT& packet__p_crypt=packet.p_crypt;

  //---------------------------------------- p_crypt__plugin [UTF8]
  std::string tmp__utf8_pluginName;

  if(!IBP_Utils::WStrToUtf8__Fast(pKnownServerKey->wstrPlugin,
                                  &tmp__utf8_pluginName))
  {
   //ERROR - [BUG CHECK] ошибка конвертирования имени плагина в кодовую страницу UTF8

   assert(false);

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_mce_remote__bug_check__cant_translate_wire_crypt_service_name_4,
     c_bugcheck_src,
     L"#001",
     L"WSTR",
     L"UTF8");
  }//if

  RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
   (&packet__p_crypt.p_crypt__plugin,
    tmp__utf8_pluginName.length(),
    ibp_mce_remote__wire_crypt_svc_name_is_too_long_2);

  assert(packet__p_crypt.p_crypt__plugin.cstr_length==tmp__utf8_pluginName.length());

  assert_s(sizeof(*tmp__utf8_pluginName.c_str())==sizeof(*packet__p_crypt.p_crypt__plugin.cstr_address));

  packet__p_crypt.p_crypt__plugin.cstr_address=reinterpret_cast<const protocol::P_UCHAR*>(tmp__utf8_pluginName.c_str());

  //---------------------------------------- p_crypt__key [UTF8]
  std::string tmp__utf8_keyName;

  if(!IBP_Utils::WStrToUtf8__Fast(pKnownServerKey->wstrType,
                                  &tmp__utf8_keyName))
  {
   //ERROR - ошибка конвертирования имени типа ключа шифрования в кодовую страницу UTF8

   assert(false);

   RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_wstr_to_utf8
    (c_bugcheck_src,
     L"#002");
  }//if

  RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
   (&packet__p_crypt.p_crypt__key,
    tmp__utf8_keyName.length(),
    ibp_mce_remote__wire_crypt_key_type_name_is_too_long_2);

  assert(packet__p_crypt.p_crypt__key.cstr_length==tmp__utf8_keyName.length());

  assert_s(sizeof(*tmp__utf8_keyName.c_str())==sizeof(*packet__p_crypt.p_crypt__key.cstr_address));

  packet__p_crypt.p_crypt__key.cstr_address=reinterpret_cast<const protocol::P_UCHAR*>(tmp__utf8_keyName.c_str());

  //----------------------------------------
  RemoteFB__OperationContext portOpCtx;

  pPort->send_packet
   (portOpCtx,
    packet); //throw
 }//local - SEND

 //----------------------------------------------------- 3. Переключаемся на шифрованный поток
 assert(pPort);
 assert(pPort->m_spSocket);

 {
  structure::t_fix_vector<1,RemoteFB__PortStreamPtr> stack;

  RemoteFB__PortStreamPtr spStream(pPort->m_spSocket);

  assert(spStream);

  while(spStream->GetStreamClass()!=RemoteFB__PortStream::stream_class__transport)
  {
   //ожидается только поток компрессора
   assert(spStream->GetStreamClass()==RemoteFB__PortStream::stream_class__compressor);

   stack.push_back(spStream);

   _VERIFY(spStream=spStream->GetParentStream());

   //ожидается только транспортный поток
   assert(spStream->GetStreamClass()==RemoteFB__PortStream::stream_class__transport);
  }//while

  assert(spStream);
  assert(spStream->GetStreamClass()==RemoteFB__PortStream::stream_class__transport);

  //привязка к транспортному потоку
  spCryptStream->SetParentStream(spStream);

  if(stack.empty())
  {
   assert(pPort->m_spSocket->GetStreamClass()==RemoteFB__PortStream::stream_class__transport);

   pPort->m_spSocket=spCryptStream.not_null_ptr();
  }
  else
  {
   assert(pPort->m_spSocket->GetStreamClass()==RemoteFB__PortStream::stream_class__compressor);

   stack.back()->SetParentStream(spCryptStream);
  }//else
 }//local

 assert(pPort->m_spSocket);

 //мы должны слезть с транспортного потока
 assert(pPort->m_spSocket->GetStreamClass()!=RemoteFB__PortStream::stream_class__transport);

 //----------------------------------------------------- 2. RECEIVE responce
 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pPort->receive_packet(portOpCtx,
                        packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   try
   {
    api::pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
     (pPort,
      c_OperationID,
      packet.p_resp,
      E_FAIL); //throw
   }
   catch(t_ibp_error& exc)
   {
    //Добавляем сведения об устанавливаемом алгоритме шифрования

    exc.add_error
     (exc.com_code(),
      ibp_subsystem__remote_fb__p13,
      ibp_mce_remote__failed_to_start_wire_crypt_2);

    exc<<pKnownServerKey->wstrType
       <<pKnownServerKey->wstrPlugin;

    exc.raise_me();
   }//switch

   break;
  }//if op_responce

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pPort,
    c_bugcheck_src,
    L"E01",
    packet.operation);
 }//for[ever]

 return true;
}//Helper__InitializeCrypt_P13__TryKey

//------------------------------------------------------------------------
RemoteFB__PortStreamPtr
 RemoteFB__P13__InitializeCrypt::Helper__CreateNotBindedCryptStream
                                           (const port_type*                  const pPort,
                                            structure::t_const_wstr_box             cryptPluginName,
                                            const RemoteFB__InternalCryptKey* const pCryptKey)
{
 assert(pPort);
 assert(pPort->m_spSocket);
 assert(pCryptKey);

 size_t cbWriteBufSize=0;

 //ищем транспортный поток, чтобы определить размер буфера под данные
 for(RemoteFB__PortStreamPtr spStream=pPort->m_spSocket;;)
 {
  assert(spStream);

  if(spStream->GetStreamClass()==RemoteFB__PortStream::stream_class__transport)
  {
   cbWriteBufSize=spStream->GetWriteBufSize();
   break;
  }//if

  //здесь ожидается только поток компрессора
  assert(spStream->GetStreamClass()==RemoteFB__PortStream::stream_class__compressor);

  _VERIFY(spStream=spStream->GetParentStream());
 }//for[ever]

 assert(cbWriteBufSize>0);

 if(IBP_Utils::EqualAsciiStr_i(cryptPluginName,L"Arc4"))
 {
  return ports::streams::crypt::arc4::RemoteFB__PortStream__Crypt_Arc4::Create
          (pCryptKey->GetEncryptKey(),
           pCryptKey->GetDecryptKey(),
           cbWriteBufSize);
 }//if

 return nullptr;
}//Helper__CreateCryptPortStream

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
