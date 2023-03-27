////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13__connect_helper.cpp
//! \brief   Вспомогательный класс с унифицированным кодом подключения/создания базы данных.
//! \author  Kovalenko Dmitry
//! \date    17.08.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__connect_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__connect_op_ctx.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__initialize_crypt.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__process_auth_response.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__client_connect_block_v2.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

#include "source/ibp_utils.h"

#include <structure/t_pointer_cast.h>

#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13__ConnectHelper

void RemoteFB__P13__ConnectHelper::exec(ports::base_v01::RemoteFB__Port_BASE_v01* const pPort,
                                        wstr_box_type                             const ucs2_database_name,
                                        RemoteFB__ClientConnectBlock_v2&                clientConnectBlock,
                                        protocol::set02::P_OP                           operationID)
{
 assert(pPort!=nullptr);

 assert(pPort->m_ID.is_null());

 assert(operationID==protocol::set02::op_create ||
        operationID==protocol::set02::op_attach);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P13__ConnectHelper::exec";

 //-----------------------------------------

 {
  RemoteFB__P13__ConnectOpCtx ctx(clientConnectBlock,/*setNewDbParams*/operationID==protocol::set02::op_create);

  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = operationID;

  //---------------------------------------- p_atch_file
  std::string tmp__utf8_database_name;

  if(!IBP_Utils::WStrToUtf8__Fast(ucs2_database_name,&tmp__utf8_database_name))
  {
   //ERROR - ошибка конвертирования имени базы данных в кодовую страницу UTF8

   IBP_ThrowSimpleError
    (E_FAIL,
     ibp_subsystem__remote_fb__p13,
     ibp_mce_common__failed_to_convert_db_name_to_utf8_0);
  }//if

  if(!structure::can_numeric_cast(&packet.p_atch.p_atch__file.cstr_length,tmp__utf8_database_name.length()))
  {
   //ERROR - database name length too large

   IBP_ErrorUtils::Throw__Error 
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_common__database_name_length_is_too_large_2,
    tmp__utf8_database_name.length(),
    structure::get_numeric_limits(packet.p_atch.p_atch__file.cstr_length).max_value());
  }//if

  structure::static_numeric_cast
   (&packet.p_atch.p_atch__file.cstr_length,
    tmp__utf8_database_name.length());

  assert_s(sizeof(*tmp__utf8_database_name.c_str())==sizeof(*packet.p_atch.p_atch__file.cstr_address));

  structure::reinterpret_ptr_cast
   (&packet.p_atch.p_atch__file.cstr_address,
    tmp__utf8_database_name.c_str());

  //---------------------------------------- p_atch__dpb
  {
   const auto dpb_BufferLength=ctx.m_dpb.GetBufferLength();

   if(!structure::can_numeric_cast(&packet.p_atch.p_atch__dpb.cstr_length,dpb_BufferLength))
   {
    //ERROR - database parameter buffer is too large

    IBP_ThrowErr_FormedParamBufIsTooLarge
     (ibp_subsystem__remote_fb__p13,
      ctx.m_dpb.GetBufferTypeName(),
      dpb_BufferLength,
      structure::get_numeric_limits(packet.p_atch.p_atch__dpb.cstr_length).max_value());
   }//if

   structure::static_numeric_cast
    (&packet.p_atch.p_atch__dpb.cstr_length,
     dpb_BufferLength);

   packet.p_atch.p_atch__dpb.cstr_address=ctx.m_dpb.GetBuffer();
  }//local

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pPort->send_packet(portOpCtx,
                     packet); //throw
 }//local

 //----------------------------------------- 4. get response
 size_t reAuthCount=0;

 for(;;)
 {
  //цикл обмена инициализационными пакетами с сервером.
  // - условие завершение: получение пакета op_response

  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pPort->receive_packet(portOpCtx,
                        packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pPort,
     operationID,
     packet.p_resp,
     E_FAIL); //throw

   //[2015-02-17]
   // Пока будем проверять, что это поле содержит ноль.
   assert(packet.p_resp.p_resp__object==0);

   //[2015-02-16]
   // Текущая реализация серверного клиента (FB2.5) этого не делает,
   // и просто устанавливает нулевое значение.
   pPort->m_ID.set_value(&packet.p_resp.p_resp__object);

   if(clientConnectBlock.m_authComplete)
   {
    if(packet.p_resp.p_resp__data.cstr_length!=0)
    {
     //[2016-08-17]
     // похоже сервер нам передал данные для настройки шифрования.
     //
     // но мы это уже должны были сделать раньше, в процессе настройки
     // подключения к СЕРВЕРУ.
     //
     // кроме того, мы НЕ ПЕРЕДАВАЛИ в DPB данных для аутентификации
     // (fbclient.dll передает login/pswd и ему в этой точке снова приходят
     // данные для конфигурации шифрования, которые он в конечно счете игнорирует).
     //
     // так что здесь мы просто выкинем BUG-CHECK ошибку. Сработает - будем разбираться.

     //[2016-09-12]
     // Ситуация изменилась. По замыслу серверописателей, в некоторых случаях
     // (Win_Sspi, Wire_Crypt=Disabled), мы таки должны продолжить авторизацию
     // на данном этапе подключения. То есть в DPB иногда все таки будут присутствовать
     // некоторые данные аутентификацию.
     //
     // Но мы пока все равно будем продолжать выкидывать BUG-CHECK ошибку.

     IBP_BUG_CHECK__DEBUG
      (c_bugcheck_src,
       L"#U01",
       me_bug_check__unexpected_situation_0)
    }//if packet.p_resp.p_resp__data.cstr_length!=0

    assert(packet.p_resp.p_resp__data.cstr_length==0);
   }
   else
   {
    assert(!clientConnectBlock.m_authComplete);

    if(packet.p_resp.p_resp__data.cstr_length!=0)
    {
     //[2016-09-12]
     // Ситуация изменилась. По замыслу серверописателей, в некоторых случаях
     // (Win_Sspi, Wire_Crypt=Disabled), мы таки должны продолжить авторизацию
     // на данном этапе подключения. То есть, в DPB иногда все таки будут
     // присутствовать некоторые данные аутентификацию.
     //
     // Но мы пока все равно будем продолжать выкидывать BUG-CHECK ошибку.

     //[2019-05-13]
     // Мы (в этом методе) можем выполнять повторную аутентификацию.
     // Так что нам могут приехать полезные данные.
     //
     // Но мы пока все равно будем продолжать выкидывать BUG-CHECK ошибку.

     IBP_BUG_CHECK__DEBUG
      (c_bugcheck_src,
       L"#U02",
       me_bug_check__unexpected_situation_0);
    }//if packet.p_resp.p_resp__data.cstr_length!=0

    assert(packet.p_resp.p_resp__data.cstr_length==0);

    clientConnectBlock.m_authComplete=true;

    //--------------------------------------
    api::p13::RemoteFB__P13__InitializeCrypt::exec
     (pPort,
      clientConnectBlock);

    // [2016-09-13]
    //  Если я все правильно понимаю, то поток должен остаться незашифрованным.

    assert(pPort);
    assert(pPort->m_spSocket);
    assert(pPort->m_spSocket->GetStreamClass()==RemoteFB__PortStream::stream_class__transport ||
           pPort->m_spSocket->GetStreamClass()==RemoteFB__PortStream::stream_class__compressor);
   }//else

   assert(clientConnectBlock.m_authComplete);

   break;
  }//if - protocol::op_response

  if(clientConnectBlock.m_authComplete)
  {
   //[2019-05-12] Предполагается, что аутентификация не завершена.

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#A02",
     me_bug_check__unexpected_situation_0);

   assert_hint(false);
  }//if

  assert_hint(!clientConnectBlock.m_authComplete);

  if(packet.operation==protocol::set02::op_cont_auth)
  {
   {
    // struct P_OP_AUTH_CONT
    //   P_CSTRING_CONST_V2 p_auth_cont__data;
    //   P_CSTRING_CONST_V2 p_auth_cont__name;
    //   P_CSTRING_CONST_V2 p_auth_cont__list;
    //   P_CSTRING_CONST_V2 p_auth_cont__keys;

    const protocol::set02::P_OP_AUTH_CONT* const p_auth_cont=&packet.p_auth_cont;

    api::p13::RemoteFB__P13__ProcessAuthResponse::exec
     (clientConnectBlock,
      &p_auth_cont->p_auth_cont__name,
      &p_auth_cont->p_auth_cont__data);

    assert(clientConnectBlock.GetCurrentAuthPlugin());

    if(p_auth_cont->p_auth_cont__keys.cstr_length!=0)
    {
     //ERROR - [BUG CHECK] Установка серверных ключей ответа авторизации не реализована.

     IBP_BUG_CHECK__DEBUG
      (c_bugcheck_src,
       L"#B01",
       L"processing of p_auth_cont__keys does not implemented");
    }//if
   }//local

   //-------------------------------------- отправка пакета для повторной аутентификации
   self_type::send__cont_auth
    (pPort,
     clientConnectBlock); //throw

   operationID=protocol::set02::op_cont_auth;

   ++reAuthCount;

   continue;
  }//if op_cont_auth

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pPort,
    c_bugcheck_src,
    L"#001",
    packet.operation);
 }//for[ever]

 //OK. Мы подключились к базе данных.
 assert(clientConnectBlock.m_authComplete);
}//exec

//-----------------------------------------------------------------------
void RemoteFB__P13__ConnectHelper::send__cont_auth
                (ports::base_v01::RemoteFB__Port_BASE_v01* const pPort,
                 RemoteFB__ClientConnectBlock_v2&                clientConnectBlock)
{
 assert(pPort);

 //--------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P13__ConnectHelper::send__cont_auth";

 //-------------------------------------- отправка пакета для повторной аутентификации
 const protocol::set02::P_OP c_OperationID
  =protocol::set02::op_cont_auth;

 protocol::set02::PACKET_V02 packet;

 packet.operation=c_OperationID;

 // struct P_OP_AUTH_CONT
 //  P_CSTRING_CONST p_auth_cont__data;
 //  P_CSTRING_CONST p_auth_cont__name;
 //  P_CSTRING_CONST p_auth_cont__list;
 //  P_CSTRING_CONST p_auth_cont__keys;

 //---------------------- p_auth_cont__data

 assert(clientConnectBlock.GetCurrentAuthPlugin());

 clientConnectBlock.GetCurrentAuthPlugin()->authenticate(clientConnectBlock); //throw

 {
  const size_t cb=clientConnectBlock.m_dataFromAuthPlugin.size();

  if(!structure::can_numeric_cast(&packet.p_auth_cont.p_auth_cont__data.cstr_length,cb))
  {
   //ERROR - auth data length too large

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__pset02,
     ibp_mce_remote__auth_data_too_long_3,
     clientConnectBlock.GetCurrentAuthPlugin()->get_name(),
     cb,
     structure::get_numeric_limits(packet.p_auth_cont.p_auth_cont__data.cstr_length).max_value());
  }//if

  assert(structure::can_numeric_cast(&packet.p_auth_cont.p_auth_cont__data.cstr_length,cb));

  structure::static_numeric_cast(&packet.p_auth_cont.p_auth_cont__data.cstr_length,cb);
 }//local

 assert_s(1==sizeof(*packet.p_auth_cont.p_auth_cont__data.cstr_address));

 packet.p_auth_cont.p_auth_cont__data.cstr_address=reinterpret_cast<const protocol::P_UCHAR*>(clientConnectBlock.m_dataFromAuthPlugin.buffer());

 //---------------------- p_auth_cont__name
 std::string tmp__utf8_pluginName;

 if(!IBP_Utils::WStrToUtf8__Fast(clientConnectBlock.GetCurrentAuthPlugin()->get_name(),
                                 &tmp__utf8_pluginName))
 {
  //ERROR - ошибка конвертирования имени плагина аутентификации в кодовую страницу UTF8

  RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_auth_service_name_from_wstr_to_utf8
   (c_bugcheck_src,
    L"#001");
 }//if

 assert(!tmp__utf8_pluginName.empty());

 {
  const size_t cch=tmp__utf8_pluginName.length();

  if(!structure::can_numeric_cast(&packet.p_auth_cont.p_auth_cont__name.cstr_length,cch))
  {
   //ERROR - auth plugin name length too large

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__pset02,
     ibp_mce_remote__auth_svc_name_too_long_2,
     cch,
     structure::get_numeric_limits(packet.p_auth_cont.p_auth_cont__name.cstr_length).max_value());
  }//if

  structure::static_numeric_cast(&packet.p_auth_cont.p_auth_cont__name.cstr_length,cch);
 }//local

 assert_s(sizeof(*tmp__utf8_pluginName.c_str())==sizeof(*packet.p_auth_cont.p_auth_cont__name.cstr_address));

 packet.p_auth_cont.p_auth_cont__name.cstr_address
  =reinterpret_cast<const protocol::P_UCHAR*>(tmp__utf8_pluginName.c_str());

 //---------------------- p_auth_cont__list
 std::string tmp__utf8_clientAuthPlugins;

 if(!IBP_Utils::WStrToUtf8__Fast(clientConnectBlock.GetAuthPluginNames(),
                                 &tmp__utf8_clientAuthPlugins))
 {
  //ERROR - ошибка конвертирования списка имен плагинов аутентификации в кодовую страницу UTF8

  RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_auth_service_names_from_wstr_to_utf8
   (c_bugcheck_src,
    L"#002");
 }//if

 assert(!tmp__utf8_clientAuthPlugins.empty());

 {
  const size_t cch=tmp__utf8_clientAuthPlugins.length();

  if(!structure::can_numeric_cast(&packet.p_auth_cont.p_auth_cont__list.cstr_length,cch))
  {
   //ERROR - length of list with auth plugin names too large

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__pset02,
     ibp_mce_remote__auth_svc_names_too_long_2,
     cch,
     packet.p_auth_cont.p_auth_cont__list.cstr_length);
  }//if

  structure::static_numeric_cast(&packet.p_auth_cont.p_auth_cont__list.cstr_length,cch);
 }//local

 assert_s(sizeof(*tmp__utf8_clientAuthPlugins.c_str())==sizeof(*packet.p_auth_cont.p_auth_cont__list.cstr_address));

 packet.p_auth_cont.p_auth_cont__list.cstr_address
  =reinterpret_cast<const protocol::P_UCHAR*>(tmp__utf8_clientAuthPlugins.c_str());

 //---------------------- p_auth_cont__keys

 //NONE

 //--------------------------------------

 //отправка пакета

 RemoteFB__OperationContext portOpCtx;

 pPort->send_packet(portOpCtx,
                    packet); //throw
}//send__cont_auth

//helper methods ---------------------------------------------------------

#if 0 // [2019-02-17]

void RemoteFB__P13__ConnectHelper::Helper__BuildDPB
                                           (RemoteFB__ClientConnectBlock_v2& clientConnectBlock,
                                            dpb_type* const                  pDPB)
{
 assert(pDPB);

 //-----------------------------------------------------------------------
 typedef db_obj::t_dbprop_container         dbprops_type;
 typedef dbprops_type::value_type           dbprop_value_type;
 typedef dbprops_type::const_iterator       dbprop_iterator;

 //-----------------------------------------------------------------------

 /// Текстовые данные передаются в кодовой странице UTF8

 pDPB->AppendTag(fb_api::ibp_frb_dpb_utf8_filename);

 //-----------------------------------------------------------------------
 for(dbprop_iterator i(clientConnectBlock.m_CnParams.begin()),
                  _end(clientConnectBlock.m_CnParams.end());
     i!=_end;
     ++i)
 {
  if((*i).first==db_obj::dbprop_init__location)
  {
   continue;
  }

  // if((*i).first==db_obj::dbprop_init__user_id)
  // {
  //  if(use_integrated_auth)
  //   continue;
  //
  //  pDPB->AppendMbcString_AsUTF8(isc_api::ibp_isc_dpb_user_name,
  //                               L"isc_dpb_user_name",
  //                               (*i).second);
  //
  //  continue;
  // }//if - dbprop_init__user_id

  // if((*i).first==db_obj::dbprop_init__password)
  // {
  //  if(use_integrated_auth)
  //   continue;
  //
  //  string mbc_str;
  //
  //  {
  //   namespace utf8=structure::charsets::cs_utf8;
  //
  //   utf8::t_cs_cvt_result cvt_result=utf8::cs_cvt_result__ok;
  //
  //   utf8::ucs2_to_utf8((*i).second.begin(),
  //                      (*i).second.end(),
  //                      std::back_inserter(mbc_str),
  //                      &cvt_result);
  //
  //   if(cvt_result!=utf8::cs_cvt_result__ok)
  //   {
  //    //ERROR - ошибка конвертирования
  //    t_ibp_error exc(E_FAIL,
  //                    ibp_subsystem__remote_fb__p13,
  //                    ibp_mce_common__failed_to_convert_cn_param_to_utf8_1);
  //
  //    exc<<L"Password";
  //
  //    exc.raise_me();
  //   }//if
  //  }//local
  //
  //  char pwt[64/*MAX_PASSWORD_LENGTH*/ + 2];
  //
  //  RemoteFB__ENC_crypt::ENC_crypt(pwt,
  //                                 sizeof pwt,
  //                                 mbc_str.c_str(),
  //                                 /*PASSWORD_SALT*/"9z");
  //
  //  const char* const password_b=pwt+2;
  //  const char* const password_e=std::find(password_b,const_cast<const char*>(_END_(pwt)),0);
  //
  //  const size_t password_sz=(password_e-password_b);
  //
  //  //декларативная проверка
  //  assert((password_e-pwt)<=RemoteFB__ENC_crypt::c_RESULT_SIZE);
  //
  //  pDPB->AppendMbcString(isc_api::ibp_isc_dpb_password_enc,
  //                        L"isc_dpb_password_enc",
  //                        dpb_type::mbc_str_box_type(password_b,password_sz));
  //
  //  continue;
  // }//if - dbprop_init__password

  if((*i).first==db_obj::dbprop_init__ctype)
  {
   if((*i).second.empty())
    continue;

   //передаем в текущей системной кодировке

   pDPB->AppendMbcString(isc_api::ibp_isc_dpb_lc_ctype,
                         L"isc_dpb_lc_ctype",
                         (*i).second);
   continue;
  }//if - dbprop_init__ctype

  if((*i).first==db_obj::dbprop_init__role)
  {
   if((*i).second.empty())
    continue;

   pDPB->AppendMbcString_AsUTF8(isc_api::ibp_isc_dpb_sql_role_name,
                                L"isc_dpb_sql_role_name",
                                (*i).second);
   continue;
  }//if - isc_dpb_sql_role_name

  if((*i).first==db_obj::dbprop_init__garbage_collect)
  {
   if(db_obj::get_dbprop_as_bool((*i).second))
    continue;

   pDPB->AppendTag(isc_api::ibp_isc_dpb_no_garbage_collect);

   continue;
  }//if - dbprop_init__garbage_collect

  if((*i).first==db_obj::dbprop_init__num_buffers)
  {
   const long x=db_obj::get_dbprop_as_long((*i).second);

   pDPB->AppendInt(isc_api::ibp_isc_dpb_num_buffers,x);

   continue;
  }//if - dbprop_init__num_buffers

  // if((*i).first==db_obj::dbprop_init__integrated_auth)
  // {
  //  t_ibp_string auth_type(structure::trim((*i).second));
  //
  //  std::transform(auth_type.begin(),
  //                 auth_type.end(),
  //                 auth_type.begin(),
  //                 structure::t_latin_upper<t_ibp_char>());
  //
  //  if(!auth_type.empty() && auth_type!=ibp::g_IBP_IntegratedAuth__SSPI)
  //  {
  //   t_ibp_error exc(E_FAIL,ibp_mce_ds__unk_integrated_auth_service_name_1);
  //
  //   exc<<auth_type;
  //
  //   exc.raise_me();
  //  }//if
  //
  //  dpb_type::byte_type auth_data[dpb_type::c_max_tag_size];
  //
  //  const size_t sz_auth_data=this->request_auth_auth_data
  //                                          (0,
  //                                           nullptr,
  //                                           sizeof(auth_data),
  //                                           auth_data);
  //
  //  assert(sz_auth_data<=sizeof(auth_data));
  //
  //  pDPB->AppendBytes(fb_api::ibp_frb_dpb_trusted_auth,
  //                    L"frb_dpb_trusted_auth",
  //                    sz_auth_data,
  //                    auth_data);
  //  continue;
  // }//if - dbprop_init__integrated_auth

  if((*i).first==db_obj::dbprop_init__enable_db_triggers)
  {
   //допускаем использование любого клиента Firebird

   if(db_obj::get_dbprop_as_bool((*i).second))
    continue;

   pDPB->AppendByte(fb_api::ibp_frb_dpb_no_db_triggers,
                    1);
   continue;
  }//if - dbprop_init__enable_db_triggers

  //----------------------------------------  New Database Parameters
  if((*i).first==db_obj::dbprop_newdb__page_size)
  {
   const long x=db_obj::get_dbprop_as_long((*i).second);

   pDPB->AppendInt(isc_api::ibp_isc_dpb_page_size,x);

   continue;
  }//if - dbprop_newdb__page_size

  if((*i).first==db_obj::dbprop_newdb__db_dialect)
  {
   const long x=db_obj::get_dbprop_as_long((*i).second);

   pDPB->AppendInt(isc_api::ibp_isc_dpb_SQL_dialect,x);

   continue;
  }//if - dbprop_newdb__db_dialect

  if((*i).first==db_obj::dbprop_newdb__type_of_db_users)
  {
   const long x=db_obj::get_dbprop_as_long((*i).second);

   if(x==ibprovider::ibp_propval__newdb__type_of_db_users__server)
    continue;

   IBP_ThrowInitPropCantProcessCurrentDBClient_I4
    (ibp_subsystem__remote_fb__p13,
     IBP_DBPROP_NAME__DSCREATE__TYPE_OF_DATABASE_USERS,
     IBP_SUBSYSTEM_SIGN__REMOTE_FB,
     IBP_VI_PRODUCT_VER_STRING1,
     x); //throw
  }//if - dbprop_newdb__type_of_db_users

  if((*i).first==db_obj::dbprop_init__sys_encrypt_password)
  {
   IBP_ThrowInitPropCantPassIntoDBClient
    (ibp_subsystem__remote_fb__p13,
     IBP_DBPROP_NAME__INIT__SYS_ENCRYPT_PASSWORD,
     IBP_SUBSYSTEM_SIGN__REMOTE_FB,
     IBP_VI_PRODUCT_VER_STRING1); //throw
  }//if - dbprop_init__sys_encrypt_password
 }//for i - просматриваем параметры подключения

 //-----------------------------------------------------------------------
 //параметры аутентификации

 if(!clientConnectBlock.m_authComplete)
 {
  //продолжаем процесс передачи данных аутентификации на сервера.

  //такое возможно для Win_SSPI и Wire_Crypt=Disabled.

  //халтура, конечно. но вот так вот оно спроектировано в FB3.

  //---------- запрашиваем данные у сервиса аутентификации
  assert(clientConnectBlock.GetCurrentAuthPlugin());

  clientConnectBlock.GetCurrentAuthPlugin()->authenticate(clientConnectBlock); //throw

  //--------- упаковываем данные в DPB

  //запихиваем имя плагина
  pDPB->AppendMbcString_AsUTF8
   (fb_api::ibp_frb_dpb_auth_plugin_name,
    L"frb_dpb_auth_plugin_name",
    clientConnectBlock.GetCurrentAuthPlugin()->get_name());

  //запихиваем имя плагина как единственный элемент списка доступных плагинов
  pDPB->AppendMbcString_AsUTF8
   (fb_api::ibp_frb_dpb_auth_plugin_list,
    L"frb_dpb_auth_plugin_list",
    clientConnectBlock.GetCurrentAuthPlugin()->get_name());

  //запихиваем данные аутентификации

  //[2016-09-12] Ожидается, что данные точно есть.
  assert(!clientConnectBlock.m_dataFromAuthPlugin.empty());

  pDPB->AppendBytes
   (fb_api::ibp_frb_dpb_specific_auth_data,
    L"frb_dpb_specific_auth_data",
    clientConnectBlock.m_dataFromAuthPlugin.size(),
    clientConnectBlock.m_dataFromAuthPlugin.buffer());
 }//if !clientConnectBlock.m_authComplete

 //-----------------------------------------------------------------------
 //other_params

 //-----------------------------------------------------------------------
 //isc_dpb_dummy_packet_interval
 // [2015-02-11] пока забъем. будут проблемы, добавим.

 //-----------------------------------------------------------------------
 pDPB->AppendInt
  (fb_api::ibp_frb_dpb_process_id,
   ::GetCurrentProcessId());

 pDPB->AppendMbcString_AsUTF8
  (fb_api::ibp_frb_dpb_process_name,
   L"frb_dpb_process_name",
   RemoteFB__Utils::GetCurrentProcessName());

 pDPB->AppendMbcString_AsUTF8
  (fb_api::ibp_frb_dpb_client_version,
   L"frb_dpb_client_version",
   RemoteFB__Utils::BuildFbClientSign());

 //-----------------------------------------------------------------------
 //isc_dpb_working_directory для locahost-подключения

 // [2015-02-01] После размышлений, решил его не передавать.
 // причина - херня какая-та. Мы подключаемся по сети.
 // Наверное не факт, что localhost это именно локальный компьютер...
}//Helper__BuildDPB

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
