////////////////////////////////////////////////////////////////////////////////
//Charset: UTF8 without BOM!
#include <_pch_.h>
#pragma hdrstop

#include "source/test_services.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestServices

void TestServices::Helper__PSET01__HACK__DetachCn
                                 (TTSO_Tracer&                    tracer,
                                  remote_fb_connector_type* const pConnector)
{
 assert(pConnector);

 tracer<<L"[HACK][PSET01] Detach from database"<<send;

 {
  remote_fb::protocol::set01::PACKET_V01 packet;

  packet.operation=remote_fb::protocol::set01::op_detach;

  packet.p_rlse.p_rlse__object=pConnector->GetPort()->m_ID.get_value();

  remote_fb::RemoteFB__OperationContext portOpCtx;

  pConnector->GetPort()->send_packet(portOpCtx,
                                     packet);
 }

 {
  remote_fb::RemoteFB__MemoryPool Mem;

  remote_fb::RemoteFB__OperationContext portOpCtx(&Mem);

  remote_fb::protocol::set01::PACKET_V01 packet;

  pConnector->GetPort()->receive_packet(portOpCtx,packet);

  if(packet.operation==remote_fb::protocol::set01::op_response)
  {
   remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pConnector->GetData(),
     remote_fb::protocol::set01::op_detach,
     packet.p_resp,
     E_FAIL);
  }
  else
  {
   tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet.operation<<send;

   return;
  }//else
 }//local
}//Helper__PSET01__HACK__DetachCn

//------------------------------------------------------------------------
void TestServices::Helper__PSET01__HACK__DropDb
                                 (TTSO_Tracer&                    tracer,
                                  remote_fb_connector_type* const pConnector)
{
 assert(pConnector);

 tracer<<L"[HACK][PSET01] Drop database"<<send;

 {
  remote_fb::protocol::set01::PACKET_V01 packet;

  packet.operation=remote_fb::protocol::set01::op_drop_database;

  packet.p_rlse.p_rlse__object=pConnector->GetPort()->m_ID.get_value();

  remote_fb::RemoteFB__OperationContext portOpCtx;

  pConnector->GetPort()->send_packet(portOpCtx,
                                     packet); //throw
 }//local

 {
  remote_fb::RemoteFB__MemoryPool Mem;

  remote_fb::RemoteFB__OperationContext portOpCtx(&Mem);

  remote_fb::protocol::set01::PACKET_V01 packet;

  pConnector->GetPort()->receive_packet(portOpCtx,packet);

  if(packet.operation==remote_fb::protocol::set01::op_response)
  {
   remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pConnector->GetData(),
     remote_fb::protocol::set01::op_drop_database,
     packet.p_resp,
     E_FAIL);
  }
  else
  {
   tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet.operation<<send;

   return;
  }//else
 }//local
}//Helper__PSET01__HACK__DropDb

//------------------------------------------------------------------------
void TestServices::Helper__PSET01__HACK__DropStmt
                                 (TTSO_Tracer&                                    tracer,
                                  remote_fb_connector_type*                 const pConnector,
                                  remote_fb::handles::RemoteFB__StmtHandle* const pStmtHandle)
{
 assert(pConnector);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_ID.has_value());

 tracer<<L"[HACK][PSET01] Drop statement"<<send;

 try // сторож сбоев работы с подключением
 {
  {
   //---------------------------------------- 2. build packet
   remote_fb::protocol::set01::PACKET_V01 packet;

   packet.operation = remote_fb::protocol::set01::op_free_statement;

   //---------------------------------------- p_sqlfree_statement
   packet.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

   //---------------------------------------- p_sqlfree_statement
   packet.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_drop;

   //---------------------------------------- 3. send packet
   remote_fb::RemoteFB__OperationContext portOpCtx;

   pConnector->GetPort()->send_packet(portOpCtx,
                                      packet); //throw
  }//local

  if(pConnector->GetPort()->TestPortFlag__lazy())
  {
   //проталкиваем пакет на сервере

   const remote_fb::protocol::P_UCHAR data[]={isc_api::ibp_isc_info_end};

   remote_fb::protocol::set01::PACKET_V01 packet;

   packet.operation = remote_fb::protocol::set01::op_info_database;

   packet.p_info.p_info__object=pConnector->GetPort()->m_ID.get_value();

   packet.p_info.p_info__incarnation=0;

   packet.p_info.p_info__items.cstr_length=sizeof(data);

   packet.p_info.p_info__items.cstr_address=data;

   //FB 2.5 BUG: сервер обрабатывает это поле как signed short
   packet.p_info.p_info__buffer_length
    =structure::t_numeric_limits<remote_fb::protocol::P_SHORT>::max_value();

   //----------------------------------------  send packet
   remote_fb::RemoteFB__OperationContext portOpCtx;

   pConnector->GetPort()->send_packet(portOpCtx,
                                      packet); //throw
  }//if lazy
 }//local
 catch(...)
 {
  remote_fb::RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pConnector->GetPort()); //throw

  assert(false);
 }//catch

 //----------------------------------------- 4. get response
 {
  remote_fb::RemoteFB__MemoryPool memoryPool;

  remote_fb::RemoteFB__OperationContext portOpCtx(&memoryPool);

  remote_fb::protocol::set01::PACKET_V01 packet1;
  remote_fb::protocol::set01::PACKET_V01 packet2;

  try // сторож сбоев работы с подключением
  {
   pConnector->GetPort()->receive_packet(portOpCtx,
                                         packet1); //throw

   if(pConnector->GetPort()->TestPortFlag__lazy())
   {
    pConnector->GetPort()->receive_packet(portOpCtx,
                                          packet2); //throw
   }//if
  }
  catch(...)
  {
   remote_fb::RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pConnector->GetPort()); //throw

   assert(false);
  }//catch

  //----------------------------------------
  if(packet1.operation==remote_fb::protocol::set01::op_response)
  {
   remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pConnector->GetData(),
     remote_fb::protocol::set01::op_free_statement,
     packet1.p_resp,
     E_FAIL); //throw
  }//if - protocol::op_response
  else
  {
   tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet1.operation<<send;
  }//else

  //----------------------------------------
  if(pConnector->GetPort()->TestPortFlag__lazy())
  {
   if(packet2.operation==remote_fb::protocol::set01::op_response)
   {
    remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
     (pConnector->GetData(),
      remote_fb::protocol::set01::op_info_database,
      packet2.p_resp,
      E_FAIL); //throw
   }//if - protocol::op_response
   else
   {
    tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet2.operation<<send;
   }//else
  }//if lazy
 }//local
}//Helper__PSET01__HACK__DropStmt

//------------------------------------------------------------------------
void TestServices::Helper__PSET01__HACK__CloseStmt
                                  (TTSO_Tracer&                                    tracer,
                                   remote_fb_connector_type*                 const pConnector,
                                   remote_fb::handles::RemoteFB__StmtHandle* const pStmtHandle)
{
 assert(pConnector);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_ID.has_value());

 tracer<<L"[HACK][PSET01] Close statement"<<send;

 try // сторож сбоев работы с подключением
 {
  {
   //---------------------------------------- 2. build packet
   remote_fb::protocol::set01::PACKET_V01 packet;

   packet.operation = remote_fb::protocol::set01::op_free_statement;

   //---------------------------------------- p_sqlfree_statement
   packet.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

   //---------------------------------------- p_sqlfree_statement
   packet.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;

   //---------------------------------------- 3. send packet
   remote_fb::RemoteFB__OperationContext portOpCtx;

   pConnector->GetPort()->send_packet(portOpCtx,
                                      packet); //throw
  }//local

  if(pConnector->GetPort()->TestPortFlag__lazy())
  {
   //проталкиваем пакет на сервере

   const remote_fb::protocol::P_UCHAR data[]={isc_api::ibp_isc_info_end};

   remote_fb::protocol::set01::PACKET_V01 packet;

   packet.operation = remote_fb::protocol::set01::op_info_database;

   packet.p_info.p_info__object=pConnector->GetPort()->m_ID.get_value();

   packet.p_info.p_info__incarnation=0;

   packet.p_info.p_info__items.cstr_length=sizeof(data);

   packet.p_info.p_info__items.cstr_address=data;

   //FB 2.5 BUG: сервер обрабатывает это поле как signed short
   packet.p_info.p_info__buffer_length
    =structure::t_numeric_limits<remote_fb::protocol::P_SHORT>::max_value();

   //----------------------------------------  send packet
   remote_fb::RemoteFB__OperationContext portOpCtx;

   pConnector->GetPort()->send_packet(portOpCtx,
                                      packet); //throw
  }//if lazy
 }
 catch(...)
 {
  remote_fb::RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pConnector->GetPort()); //throw

  assert(false);
 }//catch

 //----------------------------------------- 4. get response
 {
  remote_fb::RemoteFB__MemoryPool memoryPool;

  remote_fb::RemoteFB__OperationContext portOpCtx(&memoryPool);

  remote_fb::protocol::set01::PACKET_V01 packet1;
  remote_fb::protocol::set01::PACKET_V01 packet2;

  try // сторож сбоев работы с подключением
  {
   pConnector->GetPort()->receive_packet(portOpCtx,
                                         packet1); //throw

   if(pConnector->GetPort()->TestPortFlag__lazy())
   {
    pConnector->GetPort()->receive_packet(portOpCtx,
                                          packet2); //throw
   }//if
  }
  catch(...)
  {
   remote_fb::RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pConnector->GetPort()); //throw

   assert(false);
  }//catch

  //----------------------------------------
  if(packet1.operation==remote_fb::protocol::set01::op_response)
  {
   remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pConnector->GetData(),
     remote_fb::protocol::set01::op_free_statement,
     packet1.p_resp,
     E_FAIL); //throw
  }//if - protocol::op_response
  else
  {
   tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet1.operation<<send;
  }//else

  //----------------------------------------
  if(pConnector->GetPort()->TestPortFlag__lazy())
  {
   if(packet2.operation==remote_fb::protocol::set01::op_response)
   {
    remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
     (pConnector->GetData(),
      remote_fb::protocol::set01::op_info_database,
      packet2.p_resp,
      E_FAIL); //throw
   }//if - protocol::op_response
   else
   {
    tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet2.operation<<send;
   }//else
  }//if lazy
 }//local
}//Helper__PSET01__HACK__CloseStmt

//------------------------------------------------------------------------
void TestServices::Helper__PSET01__HACK__UnprepareStmt
                                      (TTSO_Tracer&                                    tracer,
                                       remote_fb_connector_type*                 const pConnector,
                                       remote_fb::handles::RemoteFB__StmtHandle* const pStmtHandle)
{
 assert(pConnector);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_ID.has_value());

 tracer<<L"[HACK][PSET01] Unprepare statement"<<send;

 try // сторож сбоев работы с подключением
 {
  {
   //---------------------------------------- 2. build packet
   remote_fb::protocol::set01::PACKET_V01 packet;

   packet.operation = remote_fb::protocol::set01::op_free_statement;

   //---------------------------------------- p_sqlfree_statement
   packet.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

   //---------------------------------------- p_sqlfree_statement
   packet.p_sqlfree.p_sqlfree__option=4;// DSQL_unprepare

   //---------------------------------------- 3. send packet
   remote_fb::RemoteFB__OperationContext portOpCtx;

   pConnector->GetPort()->send_packet(portOpCtx,
                                      packet); //throw
  }//local

  if(pConnector->GetPort()->TestPortFlag__lazy())
  {
   //проталкиваем пакет на сервере

   const remote_fb::protocol::P_UCHAR data[]={isc_api::ibp_isc_info_end};

   remote_fb::protocol::set01::PACKET_V01 packet;

   packet.operation = remote_fb::protocol::set01::op_info_database;

   packet.p_info.p_info__object=pConnector->GetPort()->m_ID.get_value();

   packet.p_info.p_info__incarnation=0;

   packet.p_info.p_info__items.cstr_length=sizeof(data);

   packet.p_info.p_info__items.cstr_address=data;

   //FB 2.5 BUG: сервер обрабатывает это поле как signed short
   packet.p_info.p_info__buffer_length
    =structure::t_numeric_limits<remote_fb::protocol::P_SHORT>::max_value();

   //----------------------------------------  send packet
   remote_fb::RemoteFB__OperationContext portOpCtx;

   pConnector->GetPort()->send_packet(portOpCtx,
                                      packet); //throw
  }//if lazy
 }//local
 catch(...)
 {
  remote_fb::RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pConnector->GetPort()); //throw

  assert(false);
 }//catch

 //----------------------------------------- 4. get response
 {
  remote_fb::RemoteFB__MemoryPool memoryPool;

  remote_fb::RemoteFB__OperationContext portOpCtx(&memoryPool);

  remote_fb::protocol::set01::PACKET_V01 packet1;
  remote_fb::protocol::set01::PACKET_V01 packet2;

  try // сторож сбоев работы с подключением
  {
   pConnector->GetPort()->receive_packet(portOpCtx,
                                         packet1); //throw

   if(pConnector->GetPort()->TestPortFlag__lazy())
   {
    pConnector->GetPort()->receive_packet(portOpCtx,
                                          packet2); //throw
   }//if
  }//local
  catch(...)
  {
   remote_fb::RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pConnector->GetPort()); //throw

   assert(false);
  }//catch

  //----------------------------------------
  if(packet1.operation==remote_fb::protocol::set01::op_response)
  {
   remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pConnector->GetData(),
     remote_fb::protocol::set01::op_free_statement,
     packet1.p_resp,
     E_FAIL); //throw
  }//if - protocol::op_response
  else
  {
   tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet1.operation<<send;
  }//else

  //----------------------------------------
  if(pConnector->GetPort()->TestPortFlag__lazy())
  {
   if(packet2.operation==remote_fb::protocol::set01::op_response)
   {
    remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
     (pConnector->GetData(),
      remote_fb::protocol::set01::op_info_database,
      packet2.p_resp,
      E_FAIL); //throw
   }//if - protocol::op_response
   else
   {
    tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet2.operation<<send;
   }//else
  }//if lazy
 }//local
}//Helper__PSET01__HACK__UnprepareStmt

//------------------------------------------------------------------------
void TestServices::Helper__PSET01__HACK__CommitTr
                                 (TTSO_Tracer&                            tracer,
                                  remote_fb_connector_type*               pConnector,
                                  remote_fb::handles::RemoteFB__TrHandle* pTrHandle)
{
 assert(pConnector);
 assert(pTrHandle);
 assert(*pTrHandle);
 assert((*pTrHandle)->m_ID.has_value());

 tracer<<L"[HACK][PSET01] Commit transaction"<<send;

 {
  remote_fb::protocol::set01::PACKET_V01 packet;

  packet.operation=remote_fb::protocol::set01::op_commit;

  packet.p_rlse.p_rlse__object=(*pTrHandle)->m_ID.get_value();

  remote_fb::RemoteFB__OperationContext portOpCtx;

  pConnector->GetPort()->send_packet(portOpCtx,
                                     packet); //throw
 }//local

 {
  remote_fb::RemoteFB__MemoryPool Mem;

  remote_fb::RemoteFB__OperationContext portOpCtx(&Mem);

  remote_fb::protocol::set01::PACKET_V01 packet;

  pConnector->GetPort()->receive_packet(portOpCtx,packet);

  if(packet.operation==remote_fb::protocol::set01::op_response)
  {
   remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pConnector->GetData(),
     remote_fb::protocol::set01::op_commit,
     packet.p_resp,
     E_FAIL);
  }
  else
  {
   tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet.operation<<send;

   return;
  }//else
 }//local
}//Helper__PSET01__HACK__CommitTr

//------------------------------------------------------------------------
void TestServices::Helper__PSET01__HACK__CloseBlob
                                  (TTSO_Tracer&                              tracer,
                                   remote_fb_connector_type*                 pConnector,
                                   remote_fb::handles::RemoteFB__BlobHandle* pBlobHandle)
{
 assert(pConnector);
 assert(pBlobHandle);
 assert(*pBlobHandle);
 assert((*pBlobHandle)->m_ID.has_value());

 tracer<<L"[HACK][PSET01] Close blob"<<send;

 {
  remote_fb::protocol::set01::PACKET_V01 packet;

  packet.operation=remote_fb::protocol::set01::op_close_blob;

  packet.p_rlse.p_rlse__object=(*pBlobHandle)->m_ID.get_value();

  remote_fb::RemoteFB__OperationContext portOpCtx;

  pConnector->GetPort()->send_packet(portOpCtx,
                                     packet); //throw
 }//local

 {
  remote_fb::RemoteFB__MemoryPool Mem;

  remote_fb::RemoteFB__OperationContext portOpCtx(&Mem);

  remote_fb::protocol::set01::PACKET_V01 packet;

  pConnector->GetPort()->receive_packet(portOpCtx,packet);

  if(packet.operation==remote_fb::protocol::set01::op_response)
  {
   remote_fb::api::pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pConnector->GetData(),
     remote_fb::protocol::set01::op_close_blob,
     packet.p_resp,
     E_FAIL);
  }
  else
  {
   tracer(tso_msg_error,-1)<<L"Unexpected answer from server: "<<packet.operation<<send;

   return;
  }//else
 }//local
}//Helper__PSET01__HACK__CloseBlob

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
