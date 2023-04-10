////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__prepare.cpp
//! \brief   Подготовка запроса.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__prepare.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/set01/remote_fb__api_hlp__xsqlda_set01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13__PrepareStatement

RemoteFB__API_P13__PrepareStatement RemoteFB__API_P13__PrepareStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__PrepareStatement::RemoteFB__API_P13__PrepareStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__PrepareStatement::~RemoteFB__API_P13__PrepareStatement()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13__PrepareStatement::exec
                                           (db_obj::t_db_operation_context& OpCtx,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            protocol::P_USHORT        const SQL_dialect,
                                            sql_str_box_type          const SQL_str,
                                            unsigned long*            const pStmtTypeID)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);
 assert(pStmtTypeID!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__PrepareStatement::exec";

 //-----------------------------------------
 (*pStmtTypeID)=0;

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- проверка дескриптора транзакции
 if(pTrHandle!=nullptr && (*pTrHandle)!=nullptr)
 {
  if(!(*pTrHandle)->m_ID.has_value())
  {
   assert(false);

   RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
    (c_bugcheck_src,
     L"#001");
  }//if

  pData->BugCheck__CheckTr
   (*pTrHandle,
    c_bugcheck_src,
    L"#002");
 }//if - передали ненулевой дескриптор транзакции

 //----------------------------------------- проверка дескриптора запроса
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#003");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value())
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#004");
 }//if

 pData->BugCheck__CheckStmt
  (*pStmtHandle,
   c_bugcheck_src,
   L"#005");

 //-----------------------------------------------------------------------
 //
 // Формально, запрос должен находится в закрытом состоянии. В противном случае,
 // сервер генерирует ошибку "The prepare statement identifies a prepare
 // statement with an open cursor".
 //
 // Но на текущий момент [2015-08-26] нет возможности определить у запроса
 // наличие открытого курсора. Все что мы можем сделать - это проверить,
 // что отсутствие FETCH-операций.
 //
 // Поэтому ограничимся номинальной проверкой в отладочной сборке.

 assert(!(*pStmtHandle)->m_spFetchResult);

 //-----------------------------------------------------------------------
 (*pStmtHandle)->ResetPrepareState();

 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));

 assert(!(*pStmtHandle)->m_pParentTr);

 //-----------------------------------------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_prepare_statement;

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  RemoteFB__P13__StmtHelper::BuildPacket__op_prepare_statement
   (&packet,
    pTrHandle,
    (*pStmtHandle)->m_ID.get_value(),
    SQL_dialect,
    SQL_str);

  assert(packet.operation==c_OperationID);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ Let's define the boundaries of work with the server
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
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

   if(packet.p_resp.p_resp__object)
   {
    //Пока не понятно когда такой случай возникает и что потом с ним делать.
    //Поэтому просто обработает как BUG-CHECK ошибку.

    //(*pStmtHandle)->m_PFlags.set(stmt_data_type::PFLAG__BLOB);

    IBP_BUG_CHECK__DEBUG
     (c_bugcheck_src,
      L"#006",
      me_bug_check__unsupported_stmt_kind__BLOB_0)
   }//if

   //обработка информационного буфера
   api::helpers::RemoteFB__API_HLP__XSQLDA_SET01__Utilities::Process_PrepareInfoBuf
    (*pStmtHandle,
     packet.p_resp.p_resp__data.cstr_length,
     packet.p_resp.p_resp__data.cstr_address);

   assert(!(*pStmtHandle)->m_PData__StmtTypeID.null());

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#007",
    packet.operation);
 }//for[ever]

 //----------------------------------------- EXIT
 (*pStmtHandle)->m_PFlags.set(stmt_data_type::PFLAG__PREPARED);

 //-----------------------------------------
 assert(!(*pStmtHandle)->m_PData__StmtTypeID.null());

 (*pStmtTypeID)=(*pStmtHandle)->m_PData__StmtTypeID.value();
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
