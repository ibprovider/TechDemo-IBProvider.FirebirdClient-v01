////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12_lazy_send__stmt_helper-Execute__lazy_send.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    12.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__p12_lazy_send__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v1.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12_LAZY_SEND__StmtHelper

protocol::P_OBJCT
 RemoteFB__P12_LAZY_SEND__StmtHelper::Execute__lazy_send
                             (RemoteFB__P12__SrvOperation&               serverOperation,
                              RemoteFB__ConnectorData*             const pData,
                              tr_handle_type*                      const pTrHandle,
                              stmt_handle_type*                    const pStmtHandle,
                              RemoteFB__OpSvc__StmtExecuteData_v1* const pStmtExecData)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));
 assert(!(*pStmtHandle)->m_EFlags.test(structure::negative_one));
 assert(pStmtExecData);

 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());

 assert(pStmtExecData->OutMsg_BLR.empty());
 assert(pStmtExecData->OutMsg_DATA.empty());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12_LAZY_SEND__StmtHelper::Execute__lazy_send";

 //-----------------------------------------
 if((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE))
 {
  if(!pTrHandle || !(*pTrHandle))
  {
   //запросы с отложенным выполнением должны выполняться в рамках транзакции

   //такие запросы выполняются при фетче, а фетч требует транзакцию.

   //В отладочной сборке сразу остановим выполнение программы.
   assert(false);

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__p12,
     ibp_mce_cmd__stmt_with_defer_exec_requires_tr_context_0);
  }//if - не указана транзакция

  assert(pTrHandle);
  assert((*pTrHandle));
  assert((*pTrHandle)->m_ID.has_value());

  //It needs to save IN-parameters to pStmtHandle.
  // - InMsg_BLR
  // - InMsg_DATA
  (*pStmtHandle)->SaveInParams(pStmtExecData); //throw

  //отложенное выполнение запроса
  (*pStmtHandle)->m_EFlags.set(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED);

  return (*pTrHandle)->m_ID.get_value();
 }//if (*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE)

 assert(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE));

 //-----------------------------------------------------------------------

 //[2015-11-15]
 // У нас может висеть невыполненная операция закрытия курсора.
 // IBProvider на текущий момент выполняет эту операцию без учета типа запроса.
 // В будущем, предлагаю в отладочной сборке ругаться на этот беспредел.

 bool send_op1_close=false;

 if((*pStmtHandle)->m_pClosingTr!=nullptr)
 {
  //нужно отправить команду на закрытие курсора.

  //[2015-11-15] Раскомментировать следующий ассерт!
  assert_msg(false,"stmtType="<<(*pStmtHandle)->m_PData__StmtTypeID.value_or_default(structure::negative_one));

  send_op1_close=true;
 }//if

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID1=protocol::set01::op_free_statement;
 const protocol::set01::P_OP c_OperationID2=protocol::set01::op_execute;

 {
  //---------------------------------------- 2. build packets
  protocol::set01::PACKET_V01 packet1;
  protocol::set01::PACKET_V01 packet2;

  //---------------------------------------- 2.1 build packet1
  if(send_op1_close)
  {
   packet1.operation = c_OperationID1;

   //------- p_sqlfree__statement
   packet1.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

   //------- p_sqlfree__option
   packet1.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;
  }//if send_op1_close

  //---------------------------------------- 2.2 build packet2
  {
   RemoteFB__P12__StmtHelper::BuildPacket__op_execute
    (&packet2,
     pTrHandle?*pTrHandle:nullptr,
     *pStmtHandle,
     pStmtExecData->InMsg_BLR);

   assert(packet2.operation==c_OperationID2);
  }//build packet2

  //---------------------------------------- 3. send packets
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc(pStmtExecData);

  //------ Let's define the boundaries of work with the server
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try //сторож сбоев работы с портом
  {
   if(send_op1_close)
   {
    pData->GetPort()->send_packet
     (portOpCtx,
      packet1); //throw
   }//if

   pData->GetPort()->send_packet
    (portOpCtx,
     packet2); //throw
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//catch

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get responses
 protocol::P_OBJCT TrID=0;

 t_ibp_error Errors(E_FAIL);

 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  protocol::set01::PACKET_V01 packet1;
  protocol::set01::PACKET_V01 packet2;

  try //сторож сбоев работы с портом
  {
   if(send_op1_close)
   {
    pData->GetPort()->receive_packet
     (portOpCtx,
      packet1); //throw
   }//if

   pData->GetPort()->receive_packet
    (portOpCtx,
     packet2); //throw
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//catch

  //все пакеты с ответами получены. состояние порта стабилизировано.

  //---------------------------------------- обработка ответа CLOSE
  bool close_was_failed=false;

  if(send_op1_close)
  {
   if(packet1.operation==protocol::set01::op_response)
   {
    assert((*pStmtHandle)->m_pClosingTr);

    if(const t_ibp_error_element::self_ptr
        spErrRec
         =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
           (pData,
            c_OperationID1,
            packet1.p_resp,
            E_FAIL))
    {
     // [2015-11-15] Я не знаю как протестировать данную ошибку.

     close_was_failed=true;

     Errors.add_error
      (spErrRec); //throw

     //дополнительная информация о сбое.
     Errors.add_error
      (spErrRec->m_err_code,
       ibp_subsystem__remote_fb__p12,
       ibp_mce_cmd_close_stmt_0);
    }
    else
    {
     //операция была выполнена без ошибок.

     //Кстати, FB 2.5.5 не ругается на закрытие кусора для (к примеру) "INSERT" запроса.
     //Вообще, это весьма странно.

     (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
    }//else
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#002",
      packet1.operation);

    assert(false);
   }//else
  }//if send_op1_close

  //---------------------------------------- обработка ответа EXECUTE
  if(packet2.operation==protocol::set01::op_response)
  {
   if(const t_ibp_error_element::self_ptr
       spErrRec
        =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
          (pData,
           c_OperationID2,
           packet2.p_resp,
           E_FAIL))
   {
    Errors.add_error(spErrRec);

    //делаем ошибку выполнения запроса основной
    Errors.set_last_error_as_primary();

    Errors=spErrRec->m_err_code;

    //----
    Errors.raise_me();
   }//if

   if(close_was_failed)
   {
    //раз запрос выполнился без проблем, то проигнорируем ошибку закрытия курсора.

    assert((*pStmtHandle)->m_pClosingTr);

    (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
   }//if close_was_failed

   assert((*pStmtHandle)->m_pClosingTr==nullptr);

   TrID=packet2.p_resp.p_resp__object;
  }//if - protocol::op_response
  else
  {
   //ERROR - [BUG CHECK] unexpected answer from server

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pData->GetPort(),
     c_bugcheck_src,
     L"#003",
     packet2.operation);

   assert(false);
  }//else
 }//local

 return TrID;
}//Execute__lazy_send

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
