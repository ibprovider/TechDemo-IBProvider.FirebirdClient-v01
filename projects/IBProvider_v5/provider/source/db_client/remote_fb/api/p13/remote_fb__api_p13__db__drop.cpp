////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__db__drop.cpp
//! \brief   Удаление базы данных.
//! \author  Kovalenko Dmitry
//! \date    15.09.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__db__drop.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/dbms_fb/v03_0_0/api/db_obj__dbms_fb__v03_0_0__api__error_codes.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////

namespace fb_v03_0_0__api=ibp::db_obj::dbms_fb::v03_0_0::api;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__DropDatabase

RemoteFB__API_P13__DropDatabase RemoteFB__API_P13__DropDatabase::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__DropDatabase::RemoteFB__API_P13__DropDatabase()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__DropDatabase::~RemoteFB__API_P13__DropDatabase()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13__DropDatabase::exec(RemoteFB__ConnectorData* const pData)
{
 assert(pData!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__DropDatabase::exec";

 //----------------------------------------- проверка идентификатора подключения
 if(!pData->GetPort()->m_ID.has_value())
 {
  //ERROR - недействительный дескриптор подключения

  RemoteFB__ErrorUtils::Throw_BugCheck_BadCnHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 assert(pData->GetPort()->m_ID.has_value());

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_drop_database;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_rlse_object
  packet.p_rlse.p_rlse__object=pData->GetPort()->m_ID.get_value();

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw
 }//local

 //----------------------------------------- 4. get response
 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set02::PACKET_V02 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set02::op_response)
  {
   const isc_api::t_ibp_isc_status
    iscError=pset02::RemoteFB__PSET02__ErrorUtilites::GetResultCode
              (pData,
               c_OperationID,
               packet.p_resp);

   switch(iscError)
   {
    case 0:
     break; //no error

    // [2015-02-21]
    //  Вот реально тупорылая ошибка. какого хера это не варнинг?
    case fb_v03_0_0__api::ibp_fb_v30_err__drdb_completed_with_errs:
     break;

    default:
    {
     pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
      (pData,
       c_OperationID,
       packet.p_resp,
       E_FAIL); //throw

     IBP_BUG_CHECK__DEBUG
      (c_bugcheck_src,
       L"#002",
       me_bug_check__we_expected_the_error_0);
    }//default
   }//switch iscError

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#003",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT

 //сброс идентификатора подключения
 pData->GetPort()->m_ID.reset();

 //отключаем все ресурсы подключения
 pData->ReleaseAllResources();
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
