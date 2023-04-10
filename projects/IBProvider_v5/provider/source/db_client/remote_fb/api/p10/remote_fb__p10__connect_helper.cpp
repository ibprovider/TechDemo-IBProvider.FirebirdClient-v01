////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p10
//! \file    remote_fb__p10__connect_helper.cpp
//! \brief   ¬спомогательный класс с унифицированным кодом подключени€/создани€ базы данных.
//! \author  Kovalenko Dmitry
//! \date    03.12.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p10/remote_fb__p10__connect_helper.h"
#include "source/db_client/remote_fb/api/p10/remote_fb__p10__connect_op_ctx.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_utils.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p10{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P10__ConnectHelper

void RemoteFB__P10__ConnectHelper::exec(RemoteFB__Port*            const pPort,
                                        wstr_box_type              const ucs2_database_name,
                                        RemoteFB__ClientConnectBlock_v1& clientConnectBlock,
                                        protocol::set01::P_OP      const operationID)
{
 assert(pPort!=nullptr);
 assert(pPort->get_protocol_version()==protocol::FB_PROTOCOL_VERSION10);

 assert(pPort->m_ID.is_null());

 assert(operationID==protocol::set01::op_create ||
        operationID==protocol::set01::op_attach);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P10__ConnectHelper::exec";

 //-----------------------------------------
 typedef RemoteFB__P10__ConnectOpCtx ctx_type;

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
     ucs2_database_name.ptr,
     ucs2_database_name.len,
     &error);

   if(error)
   {
    //ERROR - ошибка конвертировани€ имени базы данных в системную кодовую страницу
    IBP_ThrowSimpleError
     (E_FAIL,
      ibp_subsystem__remote_fb__p10,
      ibp_mce_common__failed_to_convert_db_name_to_system_codepage_0);
   }//if
  }//local

  pset01::RemoteFB__PSET01__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_atch.p_atch__file,
    tmp__mbc_database_name.length(),
    ibp_subsystem__remote_fb__p10,
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
    ibp_subsystem__remote_fb__p10,
    ibp_mce_common__formed_param_buf_is_too_large_3);

  assert(packet.p_atch.p_atch__dpb.cstr_length==ctx.m_dpb.GetBufferLength());

  packet.p_atch.p_atch__dpb.cstr_address=ctx.m_dpb.GetBuffer();

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pPort->send_packet
   (portOpCtx,
    packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  //цикл обмена инициализационными пакетами с сервером.
  // - условие завершение: получение пакета op_response

  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet;

  pPort->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
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

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pPort,
    c_bugcheck_src,
    L"#001",
    packet.operation);
 }//for[ever]

 //OK. ћы подключились к базе данных.
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p10*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
