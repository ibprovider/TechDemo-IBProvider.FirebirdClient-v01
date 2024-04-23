////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p11
//! \file    remote_fb__p11__connect_helper.cpp
//! \brief   ¬спомогательный класс с унифицированным кодом подключени€/создани€ базы данных.
//! \author  Kovalenko Dmitry
//! \date    11.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p11/remote_fb__p11__connect_helper.h"
#include "source/db_client/remote_fb/api/p11/remote_fb__p11__connect_op_ctx.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_utils.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p11{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P11__ConnectHelper

void RemoteFB__P11__ConnectHelper::exec(RemoteFB__Port*            const pPort,
                                        wstr_box_type              const ucs2_database_name,
                                        RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                        protocol::set01::P_OP      const operationID)
{
 assert(pPort!=nullptr);

 assert(pPort->m_ID.is_null());

 assert(operationID==protocol::set01::op_create ||
        operationID==protocol::set01::op_attach);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P11__ConnectHelper::exec";

 //-----------------------------------------
 using ctx_type=RemoteFB__P11__ConnectOpCtx;

 ctx_type ctx(clientConnectBlock,/*setNewDbParams*/operationID==protocol::set01::op_create);

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = operationID;

  //---------------------------------------- p_atch_file
  std::string tmp__mbc_database_name;

  {
   bool error=false;

   structure::tstr_to_tstr
    (&tmp__mbc_database_name,
     ucs2_database_name,
     &error);

   if(error)
   {
    //ERROR - ошибка конвертировани€ имени базы данных в системную кодовую страницу
    IBP_ThrowSimpleError
     (E_FAIL,
      ibp_subsystem__remote_fb__p11,
      ibp_mce_common__failed_to_convert_db_name_to_system_codepage_0);
   }//if
  }//local

  pset01::RemoteFB__PSET01__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_atch.p_atch__file,
    tmp__mbc_database_name.length(),
    ibp_subsystem__remote_fb__p11,
    ibp_mce_common__database_name_length_is_too_large_2);

  assert(packet.p_atch.p_atch__file.cstr_length==tmp__mbc_database_name.length());

  assert_s(sizeof(*tmp__mbc_database_name.c_str())==sizeof(*packet.p_atch.p_atch__file.cstr_address));

  structure::reinterpret_ptr_cast
   (&packet.p_atch.p_atch__file.cstr_address,
    tmp__mbc_database_name.c_str());

  //---------------------------------------- p_atch__dpb
  pset01::RemoteFB__PSET01__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_atch.p_atch__dpb,
    ctx.m_dpb.GetBufferLength(),
    ibp_subsystem__remote_fb__p11,
    ibp_mce_common__formed_param_buf_is_too_large_3);

  assert(packet.p_atch.p_atch__dpb.cstr_length==ctx.m_dpb.GetBufferLength());

  packet.p_atch.p_atch__dpb.cstr_address=ctx.m_dpb.GetBuffer();

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx__send;

  pPort->send_packet
   (portOpCtx__send,
    packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  //цикл обмена инициализационными пакетами с сервером.
  // - условие завершение: получение пакета op_response

  RemoteFB__MemoryPool memoryPool;

  protocol::set01::PACKET_V01 packet;

  {
   RemoteFB__OperationContext portOpCtx__receive(&memoryPool);

   pPort->receive_packet
    (portOpCtx__receive,
     packet); //throw
  }//local

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult2
    (pPort,
     operationID,
     packet.p_resp,
     E_FAIL); //throw

   //[2015-02-17]
   // ѕока будем провер€ть, что это поле содержит ноль.
   assert(packet.p_resp.p_resp__object==0);

   //[2015-02-16]
   // “екуща€ реализаци€ серверного клиента (FB2.5) этого не делает,
   // и просто устанавливает нулевое значение.
   pPort->m_ID.set_value(&packet.p_resp.p_resp__object);

   break;
  }//if - protocol::op_response

  if(packet.operation==protocol::set01::op_trusted_auth)
  {
   if(!ctx.cn_use_integ_auth())
   {
    //ERROR - [BUG CHECK] сервер внезапно запросил интегрированную аутентификацию

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pPort,
      c_bugcheck_src,
      L"#001",
      packet.operation);
   }//if

   if(ctx.auth_data_is_completed())
   {
    //ERROR - incorrect answer from server.

    // ‘ормально, мы завершили процесс формировани€ данных дл€ интегрированной аутентификации.
    // “ак что, суд€ по всему, у нас тупит сервер.

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pPort,
      c_bugcheck_src,
      L"#002",
      packet.operation);
   }//if

   assert_s(sizeof(protocol::P_UCHAR)==1);

   ctx_type::auth_output_type auth_data;

   ctx.request_auth_data
    (packet.p_trau.p_trau__data.cstr_length,
     packet.p_trau.p_trau__data.cstr_address,
     auth_data);

   //[2016-08-23] ќжидаетс€, что данные у нас точно есть
   assert(!auth_data.empty());

   packet.init();

   memoryPool.deallocate_all();

   //------
   packet.operation=protocol::set01::op_trusted_auth;

   pset01::RemoteFB__PSET01__Utilities::CheckAndSetLength__CSTRING_CONST
    (&packet.p_trau.p_trau__data,
     auth_data.size(),
     ibp_subsystem__remote_fb__p11,
     ibp_mce_common__auth_data_length_is_too_large_2);

   assert(packet.p_trau.p_trau__data.cstr_length==auth_data.size());

   structure::reinterpret_ptr_cast
    (&packet.p_trau.p_trau__data.cstr_address,
     auth_data.buffer());

   //-------
   RemoteFB__OperationContext portOpCtx__send;

   pPort->send_packet
    (portOpCtx__send,
     packet); //throw

   //-------
   continue;
  }//if op_trusted_auth

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pPort,
    c_bugcheck_src,
    L"#003",
    packet.operation);
 }//for[ever]

 //OK. ћы подключились к базе данных.
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p11*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
