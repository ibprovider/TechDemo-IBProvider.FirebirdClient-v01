////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset02_v01__init_p13__accept_data.cpp
//! \brief   Инициализация порта для 13-го протокола.
//! \author  Kovalenko Dmitry
//! \date    13.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/initializers/pset02/v01/remote_fb__ports__base_v01__initializers__pset02_v01.h"

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__process_auth_response.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__add_server_keys.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__initialize_crypt.h"

#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"

#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13a__packet_stream.h"
#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13s__packet_stream.h"

#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"

#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__factories.h"

#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_messages.h"

#include "source/ibp_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset02{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET02_v01

void RemoteFB__PortInitializer_PSET02_v01::Helper__FinishConnect_P13__accept_data
                                           (port_type*               const     pPort,
                                            const protocol::set02::PACKET_V02& acceptPacket,
                                            wstr_box_type            const     ucs2_database_name,
                                            RemoteFB__ClientConnectBlock_v2&   clientConnectBlock,
                                            const tag_connect_finalizator&     FinalOpFuncs)
{
 assert(pPort);
 assert(!clientConnectBlock.m_authComplete);

 assert(acceptPacket.operation==protocol::set02::op_accept_data);
 assert(acceptPacket.p_acpd.p_acpt__version==protocol::FB_PROTOCOL_VERSION13);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__PortInitializer_PSET02_v01::Helper__FinishConnect_P13__accept_data";

 //еще раз.
 assert(acceptPacket.operation==protocol::set02::op_accept_data);

 switch(acceptPacket.p_acpd.p_acpt__architecture)
 {
  case protocol::FB_CURRENT_ARCHITECTURE:
  {
   self_type::Helper__Initialize__SetProtocolInfo_P13
    (pPort,
     clientConnectBlock,
     acceptPacket.p_acpd,
     &transmission::pset02::p13::RemoteFB__PSET02__P13S__PacketStream::Instance);

   break;
  }//case - current [симметричный протокол]

  case protocol::arch_generic:
  {
   self_type::Helper__Initialize__SetProtocolInfo_P13
    (pPort,
     clientConnectBlock,
     acceptPacket.p_acpd,
     &transmission::pset02::p13::RemoteFB__PSET02__P13A__PacketStream::Instance);

   break;
  }//case - generic [асимметричный протокол]

  default:
  {
   //ERROR - [BUG CHECK] accepted unexpected protocol architecture

   RemoteFB__ErrorUtils::Throw_BugCheck_AcceptedUnexpectedProtocolArchitecture
    (c_bugcheck_src,
     L"#001",
     acceptPacket.p_acpd.p_acpt__architecture);
  }//default
 }//switch packet.p_acpd.p_acpt__architecture

 //Регистрация сервисов --------------------------------------------------

 //1. Сервис для обработки ошибок
 pPort->RegService
  (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
   db_obj::dbms_fb::v03_0_0::create_svc__status_vector_utils());

 //-----------------------------------------------------------------------

 //обработка p_acpd с целью завершения процесса авторизации

 //по идее, op_cond_accept больше к нам не приедет.

 {
  // P_OP_ACPD
  //  - p_acpt__version
  //  - p_acpt__architecture
  //  - p_acpt__type
  //
  //  - p_acpd__data
  //  - p_acpd__plugin
  //  - p_acpd__authenticated
  //  - p_acpd__keys

  //----------------------------------------
  const protocol::set02::P_OP_ACPD* const p_acpd=&acceptPacket.p_acpd;

  //----------------------------------------
  if(p_acpd->p_acpd__authenticated!=0)
  {
   clientConnectBlock.m_authComplete=true;

   //---------------------------------------- p_acpd__plugin
   std::wstring serverAuthPluginName;

   if(!IBP_Utils::Utf8ToWStr__Fast(structure::make_str_box(p_acpd->p_acpd__plugin),
                                   &serverAuthPluginName))
   {
    //ERROR - ошибка конвертирования имени плагина из кодовой страницы UTF8

    RemoteFB__ErrorUtils::Throw_BugCheck__cant_convert_auth_service_name_from_utf8_to_wstr
     (c_bugcheck_src,
      L"#002");
   }//if

   assert(clientConnectBlock.GetCurrentAuthPlugin());

   if(!serverAuthPluginName.empty())
   {
    if(serverAuthPluginName!=clientConnectBlock.GetCurrentAuthPlugin()->get_name())
    {
     //Предлагают заюзать другой сервис аутентификации.

     //ERROR - [BUG CHECK] непонятно, это как это мы будем менять сервис аутентификации?

     assert(false);

     t_ibp_error exc(E_FAIL,
                     ibp_mce_remote__bug_check__unexpected_attempt_to_change_auth_service_4);

     exc<<c_bugcheck_src
        <<L"#003"
        <<clientConnectBlock.GetCurrentAuthPlugin()->get_name()
        <<serverAuthPluginName;

     exc.raise_me();
    }//if
   }//if

   assert(clientConnectBlock.GetCurrentAuthPlugin());

   //---------------------------------------- p_acpd__data
   if(p_acpd->p_acpd__data.cstr_length!=0)
   {
    //Нихера не понятно что нам с этими данными делать?

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#004",
      me_bug_check__unexpected_situation_0);
   }//if

   //---------------------------------------- p_acpd__keys
   api::p13::RemoteFB__P13__AddServerKeys::exec
    (clientConnectBlock,
     p_acpd->p_acpd__keys.cstr_length,
     p_acpd->p_acpd__keys.cstr_address);

   //---------------------------------------- инициализация шифрования подключения
   api::p13::RemoteFB__P13__InitializeCrypt::exec
    (pPort,
     clientConnectBlock);
  }
  else
  {
   assert(p_acpd->p_acpd__authenticated==0);

   api::p13::RemoteFB__P13__ProcessAuthResponse::exec
    (clientConnectBlock,
     &p_acpd->p_acpd__plugin,
     &p_acpd->p_acpd__data); //throw

   if(p_acpd->p_acpd__keys.cstr_length!=0)
   {
    //ERROR - [BUG CHECK] Установка серверных ключей ответа авторизации не реализована.

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#004",
      L"processing of p_acpd__keys does not implemented");
   }//if
  }//else
 }//local

 //-----------------------------------------------------------------------
 assert(FinalOpFuncs.P13);

 //здесь мы можем добавить специфические для INET-соединения параметры подключения

 FinalOpFuncs.P13
  (pPort,
   ucs2_database_name,
   clientConnectBlock); //throw

 assert(pPort->m_ID.has_value());
}//Helper__FinishConnect_P13__accept_data

////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset02*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
