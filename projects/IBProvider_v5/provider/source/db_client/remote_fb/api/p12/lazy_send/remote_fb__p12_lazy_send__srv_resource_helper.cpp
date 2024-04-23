////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__p12_lazy_send__srv_resource_helper.cpp
//! \brief   Набор вспомогательных утилит для управления ресурсами подключения.
//! \author  Kovalenko Dmitry
//! \date    31.10.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__p12_lazy_send__srv_resource_helper.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12_LAZY_SEND__SrvResourceHelper

void RemoteFB__P12_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources__STMT
                                           (RemoteFB__ConnectorData* const pData)
{
 assert(pData!=nullptr);

 //---------
 self_type::Helper__DropStmts(pData);
}//ProcessDeferReleasedResources__STMT

//------------------------------------------------------------------------
void RemoteFB__P12_LAZY_SEND__SrvResourceHelper::ProcessDeferReleasedResources
                                           (RemoteFB__ConnectorData* const pData)
{
 assert(pData!=nullptr);

 //---------
 self_type::Helper__DropStmts(pData);

 self_type::Helper__ReleaseBlobs(pData);
}//ProcessDeferReleasedResources

//helper methods ---------------------------------------------------------
void RemoteFB__P12_LAZY_SEND__SrvResourceHelper::Helper__DropStmts
                                           (RemoteFB__ConnectorData* const pData)
{
 assert(pData);
 assert(pData->GetPort());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12_LAZY_SEND__SrvResourceHelper::Helper__DropStmts";

 //-----------------------------------------
 if(!pData->DeletedStmtList__GetHead())
 {
  assert(pData->DeletedStmtList__GetCount()==0);

  return;
 }//if

#ifndef NDEBUG
 const size_t cDeletedStmts=pData->DeletedStmtList__GetCount();
#endif

 assert(cDeletedStmts>0);

 try // сторож сбоев работы с портом.
 {
  { //--------------------------------------- 1. отправка пакетов
   RemoteFB__OperationContext portOpCtx;
 
   { //-------------------------------------- 1.1 DROP STMT
 
    //засылаем сразу всё. пусть он подавится.
 
   #ifndef NDEBUG
    size_t iDeletedStmt=0;
   #endif
 
    protocol::set01::PACKET_V01 packet1;
 
    packet1.operation=protocol::set01::op_free_statement;
 
    packet1.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_drop;
 
    for(RemoteFB__ConnectorData::stmt_data_type::self_ptr spStmt(pData->DeletedStmtList__GetHead());
        spStmt;
        spStmt=spStmt->m_pNextCnStmt DEBUG_CODE( _LITER_COMMA_ ++iDeletedStmt ) )
    {
     assert(iDeletedStmt<cDeletedStmts);
 
     assert(spStmt->m_ID.is_wait_drop());
 
     packet1.p_sqlfree.p_sqlfree__statement=spStmt->m_ID.get_wait_drop();
 
     pData->GetPort()->send_packet_with_delay(portOpCtx,
                                              const_cast<const protocol::set01::PACKET_V01&>(packet1));
    }//for pStmt
 
    assert(iDeletedStmt==cDeletedStmts);
   }//local
 
   { //-------------------------------------- 1.2 проталкивающий пакет
    const protocol::P_UCHAR empty_data[]={isc_api::ibp_isc_info_end};
 
    protocol::set01::PACKET_V01 packet2;
 
    packet2.operation = protocol::set01::op_info_database;
 
    packet2.p_info.p_info__object=pData->GetPort()->m_ID.get_value();
 
    packet2.p_info.p_info__incarnation=0;
 
    packet2.p_info.p_info__items.cstr_length=sizeof(empty_data);
 
    packet2.p_info.p_info__items.cstr_address=empty_data;
 
    //FB 2.5 BUG: сервер обрабатывает это поле как signed short
    packet2.p_info.p_info__buffer_length
     =structure::t_numeric_limits<protocol::P_SHORT>::max_value();
 
    pData->GetPort()->send_packet
     (portOpCtx,
      packet2); //throw
   }//local
  }//local - отправка пакетов
 
  { //--------------------------------------- 2. загрузка пакетов ответа
   RemoteFB__MemoryPool memoryPool;
 
   RemoteFB__OperationContext portOpCtx(&memoryPool);
 
   { //-------------------------------------- 2.1 DROP STMT
   #ifndef NDEBUG
    size_t iDeletedStmt=0;
   #endif
 
    for(RemoteFB__ConnectorData::stmt_data_type::self_ptr spStmt(pData->DeletedStmtList__GetHead());
        spStmt;
        DEBUG_CODE(++iDeletedStmt ) )
    {
     assert(iDeletedStmt<cDeletedStmts);
 
     assert(spStmt->m_ID.is_wait_drop());
 
     RemoteFB__ConnectorData::stmt_data_type::self_ptr const spNextStmt(spStmt->m_pNextCnStmt);
 
     //----
     protocol::set01::PACKET_V01 packet1;
 
     pData->GetPort()->receive_packet(portOpCtx,packet1); //throw
 
     if(packet1.operation==protocol::set01::op_response)
     {
      //в случае проблем с освобождением дескриптора запроса, переводим порт
      //в "недействительное" состояние.
 
      if(const t_ibp_error_element::self_ptr
          spErrRec
           =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
             (pData,
              protocol::set01::op_free_statement,
              packet1.p_resp,
              E_FAIL))
      {
       t_ibp_error exc(spErrRec);
 
       exc.add_error
        (exc.com_code(),
         ibp_subsystem__remote_fb__p12,
         ibp_mce_cmd_destroy_stmt_0);
 
       exc.raise_me();
      }//if
 
      //для порядка, сбросим идентификатор.
      spStmt->m_ID.reset();
     }
     else
     {
      //ERROR - [BUG CHECK] unexpected answer from server
 
      assert(packet1.operation!=protocol::set01::op_response);
 
      RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
       (pData->GetPort(),
        c_bugcheck_src,
        L"#001",
        packet1.operation);
     }//else
 
     //----
     assert(spStmt->m_ID.is_null());
 
     pData->DeletedStmtList__Remove(spStmt);
 
     spStmt=spNextStmt;
    }//for pStmt
 
    assert(iDeletedStmt==cDeletedStmts);
 
    //список должен опустошиться
    assert(pData->DeletedStmtList__GetCount()==0);
 
    assert(!pData->DeletedStmtList__GetHead());
   }//local - загрузка ответов на DROP STMT
 
   { //-------------------------------------- 2.2 ответ на проталкивающий пакет.
    protocol::set01::PACKET_V01 packet2;
 
    //! \todo
    //!  При получении пакета будет выполнено выделение небольшого блока динамической
    //!  памяти размером 1 байт. Формально, это можно избежать, предоставив
    //!  память из стека.
 
    pData->GetPort()->receive_packet(portOpCtx,packet2); //throw
 
    if(packet2.operation==protocol::set01::op_response)
    {
     //Формально, нам абсолютно всё равно, что там нам вернули.
    }
    else
    {
     //ERROR - [BUG CHECK] unexpected answer from server
 
     assert(packet2.operation!=protocol::set01::op_response);
 
     RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
      (pData->GetPort(),
       c_bugcheck_src,
       L"#002",
       packet2.operation);
    }//else
   }//local - загрузка ответа на проталкивающий ответ
  }//local - загрузка пакетов ответа
 
  //Ура, все дескрипторы запросов были освобождены.
 }
 catch(...)
 {
  RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort()); //throw

  assert(false);
 }//catch

 //----------------------------------------- EXIT.
}//Helper__DropStmts

//------------------------------------------------------------------------
void RemoteFB__P12_LAZY_SEND__SrvResourceHelper::Helper__ReleaseBlobs(RemoteFB__ConnectorData* pData)
{
 assert(pData);
 assert(pData->GetPort());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12_LAZY_SEND__SrvResourceHelper::Helper__ReleaseBlobs";

 //-----------------------------------------
 if(!pData->DeletedBlobList__GetHead())
 {
  assert(pData->DeletedBlobList__GetCount()==0);

  return;
 }//if

#ifndef NDEBUG
 const size_t cDeletedBlobs=pData->DeletedBlobList__GetCount();
#endif

 assert(cDeletedBlobs>0);

 try // сторож сбоев работы с портом.
 {
  { //--------------------------------------- 1. отправка пакетов
   RemoteFB__OperationContext portOpCtx;
 
   { //-------------------------------------- 1.1 CLOSE/CANCEL BLOB
 
    //засылаем сразу всё. пусть он подавится.
 
   #ifndef NDEBUG
    size_t iDeletedBlob=0;
   #endif
 
    protocol::set01::PACKET_V01 packet1;
 
    for(RemoteFB__ConnectorData::blob_data_type::self_ptr spBlob(pData->DeletedBlobList__GetHead());
        spBlob;
        spBlob=spBlob->m_pNextCnNClosedBlob DEBUG_CODE( _LITER_COMMA_ ++iDeletedBlob) )
    {
     assert(iDeletedBlob<cDeletedBlobs);
 
     assert(spBlob->m_ID.is_wait_close() || spBlob->m_ID.is_wait_cancel());
 
     assert(spBlob->m_pOwnerCnNClosedBlobList==pData);
 
     //блоб продолжает жить в рамках транзакции
     assert(spBlob->m_pParentTr);
 
     //----
     if(spBlob->m_ID.is_wait_close())
     {
      packet1.operation=protocol::set01::op_close_blob;
 
      packet1.p_rlse.p_rlse__object=spBlob->m_ID.get_wait_close();
     }
     else
     if(spBlob->m_ID.is_wait_cancel())
     {
      packet1.operation=protocol::set01::op_cancel_blob;
 
      packet1.p_rlse.p_rlse__object=spBlob->m_ID.get_wait_cancel();
     }
     else
     {
      Helper__ThrowBugCheck__UnkBlobHandleState
       (c_bugcheck_src,
        L"#001",
        spBlob->m_ID.get_state());
 
      assert(false);
     }//else
 
     pData->GetPort()->send_packet_with_delay
      (portOpCtx,
       const_cast<const protocol::set01::PACKET_V01&>(packet1));
    }//for spBlob
 
    assert(iDeletedBlob==cDeletedBlobs);
   }//local
 
   { //-------------------------------------- 1.2 проталкивающий пакет
    const protocol::P_UCHAR empty_data[]={isc_api::ibp_isc_info_end};
 
    protocol::set01::PACKET_V01 packet2;
 
    packet2.operation = protocol::set01::op_info_database;
 
    packet2.p_info.p_info__object=pData->GetPort()->m_ID.get_value();
 
    packet2.p_info.p_info__incarnation=0;
 
    packet2.p_info.p_info__items.cstr_length=sizeof(empty_data);
 
    packet2.p_info.p_info__items.cstr_address=empty_data;
 
    //FB 2.5 BUG: сервер обрабатывает это поле как signed short
    packet2.p_info.p_info__buffer_length
     =structure::t_numeric_limits<protocol::P_SHORT>::max_value();
 
    pData->GetPort()->send_packet
     (portOpCtx,
      packet2); //throw
   }//local
  }//local - отправка пакетов
 
  { //--------------------------------------- 2. загрузка пакетов ответа
   RemoteFB__MemoryPool memoryPool;
 
   RemoteFB__OperationContext portOpCtx(&memoryPool);
 
   { //-------------------------------------- 2.1 CLOSE/CANCEL BLOB
   #ifndef NDEBUG
    size_t iDeletedBlob=0;
   #endif
 
    for(RemoteFB__ConnectorData::blob_data_type::self_ptr spBlob(pData->DeletedBlobList__GetHead());
        spBlob;
        DEBUG_CODE(++iDeletedBlob ) )
    {
     assert(iDeletedBlob<cDeletedBlobs);
 
     assert(spBlob->m_ID.is_wait_close() || spBlob->m_ID.is_wait_cancel());
 
     assert(spBlob->m_pOwnerCnNClosedBlobList==pData);
 
     //блоб продолжает жить в рамках транзакции
     assert(spBlob->m_pParentTr);
 
     //----
     RemoteFB__ConnectorData::blob_data_type::self_ptr const spNextBlob=spBlob->m_pNextCnNClosedBlob;
 
     //----
     protocol::set01::PACKET_V01 packet1;
 
     pData->GetPort()->receive_packet(portOpCtx,packet1); //throw
 
     if(packet1.operation==protocol::set01::op_response)
     {
      //в случае проблем с освобождением дескриптора блоба, переводим порт
      //в "недействительное" состояние.
 
      protocol::set01::P_OP operation;
      ibp_msg_code_type     msg_code_0;
 
      if(spBlob->m_ID.is_wait_close())
      {
       operation  =protocol::set01::op_close_blob;
 
       msg_code_0 =ibp_mce_ibf_fail_close_blob_0;
      }
      else
      if(spBlob->m_ID.is_wait_cancel())
      {
       operation  =protocol::set01::op_cancel_blob;
 
       msg_code_0 =ibp_mce_ibf_fail_cancel_blob_0;
      }
      else
      {
       Helper__ThrowBugCheck__UnkBlobHandleState
        (c_bugcheck_src,
         L"#002",
         spBlob->m_ID.get_state());
 
       assert(false);
      }//else
 
      if(const t_ibp_error_element::self_ptr
          spErrRec
           =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
             (pData,
              operation,
              packet1.p_resp,
              E_FAIL))
      {
       t_ibp_error exc(spErrRec);
 
       exc.add_error
        (exc.com_code(),
         ibp_subsystem__remote_fb__p12,
         msg_code_0);
 
       exc.raise_me();
      }//if
 
      //pBlob->m_ID будет сброшен в pBlob->EvDropHandle
     }
     else
     {
      //ERROR - [BUG CHECK] unexpected answer from server
 
      assert(packet1.operation!=protocol::set01::op_response);
 
      RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
       (pData->GetPort(),
        c_bugcheck_src,
        L"#003",
        packet1.operation);
     }//else
 
     //----
     spBlob->Dangerous__DropHandle();
 
     spBlob=spNextBlob;
    }//for spBlob
 
    assert(iDeletedBlob==cDeletedBlobs);
 
    //список должен опустошиться
    assert(pData->DeletedBlobList__GetCount()==0);
 
    assert(!pData->DeletedBlobList__GetHead());
   }//local - загрузка ответов на CLOSE/CANCEL BLOB
 
   { //-------------------------------------- 2.2 ответ на проталкивающий пакет.
    protocol::set01::PACKET_V01 packet2;
 
    //! \todo
    //!  При получении пакета будет выполнено выделение небольшого блока динамической
    //!  памяти размером 1 байт. Формально, это можно избежать, предоставив
    //!  память из стека.
 
    pData->GetPort()->receive_packet(portOpCtx,packet2); //throw
 
    if(packet2.operation==protocol::set01::op_response)
    {
     //Формально, нам абсолютно всё равно, что там нам вернули.
    }
    else
    {
     //ERROR - [BUG CHECK] unexpected answer from server
 
     assert(packet2.operation!=protocol::set01::op_response);
 
     RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
      (pData->GetPort(),
       c_bugcheck_src,
       L"#004",
       packet2.operation);
    }//else
   }//local - загрузка ответа на проталкивающий ответ
  }//local - загрузка пакетов ответа
 
  //Ура, все (оба два, Карл!) дескрипторы блобов были освобождены.
 }
 catch(...)
 {
  RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

  assert(false);
 }//catch

 //----------------------------------------- EXIT.
}//Helper__ReleaseBlobs

//------------------------------------------------------------------------
void RemoteFB__P12_LAZY_SEND__SrvResourceHelper::Helper__ThrowBugCheck__UnkBlobHandleState
                                           (const wchar_t* const place,
                                            const wchar_t* const point,
                                            int            const blobState)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   L"unexpected blob handle state: %1",
   blobState);
}//Helper__ThrowBugCheck__UnkBlobHandleState

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
