////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__close.cpp
//! \brief   Закрытие курсора запроса.
//! \author  Kovalenko Dmitry
//! \date    26.08.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__close.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__CloseStatement

RemoteFB__API_P12__CloseStatement RemoteFB__API_P12__CloseStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__CloseStatement::RemoteFB__API_P12__CloseStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__CloseStatement::~RemoteFB__API_P12__CloseStatement()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12__CloseStatement::exec(RemoteFB__ConnectorData* const pData,
                                             stmt_handle_type*        const pStmtHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__CloseStatement::exec";

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

 if(!(*pStmtHandle)->m_pParentTr)
 {
  //ERROR - Нет транзакции, значит запрос находится в закрытом состоянии.

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd__attempt_to_close_of_closed_cursor_0);
 }//if

 //мы закрываем ПОДГОТОВЛЕННЫЙ запрос
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_free_statement;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqlfree_statement
  packet.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

  //---------------------------------------- p_sqlfree__option
  packet.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;

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

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
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
 assert((*pStmtHandle)->m_pParentTr!=nullptr);

 (*pStmtHandle)->Dangerous__CloseCursorOfParentTr();

 assert((*pStmtHandle)->m_pParentTr==nullptr);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
