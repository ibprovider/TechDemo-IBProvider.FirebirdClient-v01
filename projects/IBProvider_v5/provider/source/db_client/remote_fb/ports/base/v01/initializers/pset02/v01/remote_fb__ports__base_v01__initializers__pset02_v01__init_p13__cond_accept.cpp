////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__ports__base_v01
//! \file    remote_fb__ports__base_v01__initializers__pset02_v01__init_p13__cond_accept.cpp
//! \brief   Инициализация порта для 13-го протокола.
//! \author  Kovalenko Dmitry
//! \date    13.07.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/ports/base/v01/initializers/pset02/v01/remote_fb__ports__base_v01__initializers__pset02_v01.h"

#include "source/db_client/remote_fb/api/p13/remote_fb__p13__process_auth_response.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__add_server_keys.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__initialize_crypt.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__connect_helper.h"

#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"

#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13a__packet_stream.h"
#include "source/db_client/remote_fb/transmission/pset02/p13/remote_fb__transmission__pset02__p13s__packet_stream.h"

#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"

#include "source/db_obj/dbms_fb/v03_0_0/db_obj__dbms_fb__v03_0_0__factories.h"
#include "source/db_obj/ib_base/ib_sys_data.h"
#include "source/db_obj/isc_base/isc_initialize_utils.h"

#include "source/external/icu/ibp_external__icu__loader_factory.h"

#include "source/error_services/ibp_error_utils.h"
#include "source/error_services/ibp_error_messages.h"

#include "source/ibp_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace ports{namespace base_v01{namespace initializers{namespace pset02{namespace v01{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__PortInitializer_PSET02_v01

void RemoteFB__PortInitializer_PSET02_v01::Helper__FinishConnect_P13__cond_accept
                        (const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues,
                         port_type*                                   const pPort,
                         const protocol::set02::PACKET_V02&                 acceptPacket,
                         wstr_box_type                                const ucs2_database_name,
                         RemoteFB__ClientConnectBlock_v2&                   clientConnectBlock,
                         const tag_connect_finalizator&                     FinalOpFuncs)
{
 assert(pDsPropValues);
 assert(pPort);
 assert(!clientConnectBlock.m_authComplete);

 assert(acceptPacket.operation==protocol::set02::op_cond_accept);
 assert(acceptPacket.p_acpd.p_acpt__version==protocol::FB_PROTOCOL_VERSION13);

 //-----------------------------------------------------------------------
 const wchar_t* const c_bugcheck_src=
  L"RemoteFB__PortInitializer_PSET02_v01::Helper__FinishConnect_P13__cond_accept";

 //еще раз.
 assert(acceptPacket.operation==protocol::set02::op_cond_accept);

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

 const external::icu::ICU__Loader::self_ptr
  spIcuLoader
   (external::icu::create_icu_loader
     (pDsPropValues));

 assert(spIcuLoader);

 const db_obj::t_db_charset_manager_v2_ptr
  spCsMng
   (isc_base::isc_create_charset_manager_v2
     (pDsPropValues,
      spIcuLoader,
      ib_base::g_ods_cs__ib04_0_0));

 assert(spCsMng);

 //1. Сервис для обработки ошибок
 pPort->RegService
  (db_obj::__db_guid<db_obj::dbms_fb::common::fb_common__svc__status_vector_utils>(),
   db_obj::dbms_fb::v03_0_0::create_svc__status_vector_utils(spCsMng));

 //-----------------------------------------------------------------------

 //обработка p_acpd с целью продолжения процесса авторизации

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
   //ERROR - [BUG CHECK] одношаговая аутентификация не поддерживается.
   //Непонятно что нам делать дальше.

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#002",
     me_bug_check__unexpected_situation_0)
  }//if

  //----------------------------------------
  api::p13::RemoteFB__P13__ProcessAuthResponse::exec
   (clientConnectBlock,
    &p_acpd->p_acpd__plugin,
    &p_acpd->p_acpd__data); //throw

  if(p_acpd->p_acpd__keys.cstr_length!=0)
  {
   //ERROR - [BUG CHECK] Установка серверных ключей ответа авторизации не реализована.

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#003",
     L"processing of p_acpd__keys does not implemented");
   }//if
 }//local

 //-----------------------------------------------------------------------

 //продолжаем процесс аутентификации

 // [2016-07-14] Предполагаем что процесс аутентификации пока не завершен.
 assert(!clientConnectBlock.m_authComplete);

 while(!clientConnectBlock.m_authComplete)
 {
  const protocol::set02::P_OP c_OperationID
   =protocol::set02::op_cont_auth;

  //--------------------------------------- отправка пакета
  api::p13::RemoteFB__P13__ConnectHelper::send__cont_auth
   (pPort,
    clientConnectBlock);

  //--------------------------------------- обработка ответа

  {
   RemoteFB__MemoryPool memoryPool;

   RemoteFB__OperationContext portOpCtx(&memoryPool);

   protocol::set02::PACKET_V02 packet;

   pPort->receive_packet(portOpCtx,
                         packet); //throw

   switch(packet.operation)
   {
    case protocol::set02::op_cont_auth:
    {
     const protocol::set02::P_OP_AUTH_CONT* const p_auth_cont=&packet.p_auth_cont;

     api::p13::RemoteFB__P13__ProcessAuthResponse::exec
      (clientConnectBlock,
       &p_auth_cont->p_auth_cont__name,
       &p_auth_cont->p_auth_cont__data);

     if(p_auth_cont->p_auth_cont__keys.cstr_length!=0)
     {
      //ERROR - [BUG CHECK] Установка серверных ключей ответа авторизации не реализована.

      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#006",
        L"processing of p_auth_cont__keys does not implemented");
     }//if

     assert_hint(!clientConnectBlock.m_authComplete);

     break;
    }//op_cont_auth

    case protocol::set02::op_response:
    {
     api::pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult2
      (pPort,
       c_OperationID,
       packet.p_resp,
       E_FAIL);

     clientConnectBlock.m_authComplete=true;

     // установим в FinalOpFuncs
     // pPort->m_ID.set_value
     //  (&packet.p_resp.p_resp__object);

     api::p13::RemoteFB__P13__AddServerKeys::exec
      (clientConnectBlock,
       packet.p_resp.p_resp__data.cstr_length,
       packet.p_resp.p_resp__data.cstr_address);

     break;
    }//case - op_response

    default:
    {
     //ERROR - [BUG CHECK] unexpected answer from server

     RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
      (pPort,
       c_bugcheck_src,
       L"E01",
       packet.operation);
    }//default
   }//switch packet.operation
  }//local - RECEIVE
 }//while !clientConnectBlock.m_authComplete

 assert(clientConnectBlock.m_authComplete);

 //-----------------------------------------------------------------------
 assert(pPort);

 api::p13::RemoteFB__P13__InitializeCrypt::exec
  (pPort,
   clientConnectBlock);

 //-----------------------------------------------------------------------
 assert(FinalOpFuncs.P13);

 //здесь мы можем добавить специфические для INET-соединения параметры подключения

 FinalOpFuncs.P13
  (pPort,
   ucs2_database_name,
   clientConnectBlock); //throw

 assert(pPort->m_ID.has_value());
}//Helper__FinishConnect_P13__cond_accept

////////////////////////////////////////////////////////////////////////////////
}/*nms v01*/}/*nms pset02*/}/*nms initializers*/}/*nms base_v01*/}/*nms ports*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
