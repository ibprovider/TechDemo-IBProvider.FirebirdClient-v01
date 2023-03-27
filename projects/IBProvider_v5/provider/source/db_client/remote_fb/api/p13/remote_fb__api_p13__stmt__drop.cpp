////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__drop.cpp
//! \brief   Освобождение дескриптора запроса.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__drop.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__DropStatement

RemoteFB__API_P13__DropStatement RemoteFB__API_P13__DropStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__DropStatement::RemoteFB__API_P13__DropStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__DropStatement::~RemoteFB__API_P13__DropStatement()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P13__DropStatement::exec(RemoteFB__ConnectorData* const pData,
                                            stmt_handle_type*        const pStmtHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__DropStatement::exec";

 //----------------------------------------- проверка дескриптора запроса
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#002");
 }//if

 pData->BugCheck__CheckStmt
  (*pStmtHandle,
   c_bugcheck_src,
   L"#003");

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_free_statement;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqlfree__statement
  packet.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

  //---------------------------------------- p_sqlfree__option
  packet.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_drop;

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
   pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#004",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT
 (*pStmtHandle)->Dangerous__DropHandle();

 //удаляем из списка
 pData->StmtList__Remove(*pStmtHandle);

 //обнуляем дескриптор
 (*pStmtHandle)=nullptr;
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
