////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12_lazy_send__stmt_helper--Execute2__lazy_send.cpp
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
 RemoteFB__P12_LAZY_SEND__StmtHelper::Execute2__lazy_send
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
 assert(!(*pStmtHandle)->m_EFlags.test(lib::structure::negative_one));
 assert(pStmtExecData);

 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());

 assert(!pStmtExecData->OutMsg_BLR.empty());
 assert(!pStmtExecData->OutMsg_DATA.empty());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12_LAZY_SEND__StmtHelper::Execute2__lazy_send";

 //-----------------------------------------
 if((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE))
 {
  IBP_ErrorUtils::Throw__BugCheck__DEBUG
   (c_bugcheck_src,
    L"#000",
    me_bug_check__defer_execution_of_stmt_with_out_params_not_supported_0);
 }//if

 assert(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__DEFER_EXECUTE));

 //-----------------------------------------------------------------------

 //[2015-11-15]
 // ” нас может висеть невыполненна€ операци€ закрыти€ курсора.
 // IBProvider на текущий момент выполн€ет эту операцию без учета типа запроса.
 // ¬ будущем, предлагаю в отладочной сборке ругатьс€ на этот беспредел.

 bool send_op1_close=false;

 if((*pStmtHandle)->m_pClosingTr!=nullptr)
 {
  //нужно отправить команду на закрытие курсора.

  //[2015-11-15] –аскомментировать следующий ассерт!
  //[2016-10-08] јминь
  assert_msg(false,"stmtType="<<(*pStmtHandle)->m_PData__StmtTypeID.value_or_default(lib::structure::negative_one));

  //! \todo
  //!  [2016-10-10] ѕредлагаю выкидывать BUG-CHECK ошибку

  send_op1_close=true;
 }//if

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID1=protocol::set01::op_free_statement;
 const protocol::set01::P_OP c_OperationID2=protocol::set01::op_execute2;

 {
  //---------------------------------------- 2. build packets
  protocol::set01::PACKET_V01 packet1;
  protocol::set01::PACKET_V01 packet2;

  //---------------------------------------- 2.1 build packet1 CLOSE
  if(send_op1_close)
  {
   packet1.operation = c_OperationID1;

   //----- p_sqlfree__statement
   packet1.p_sqlfree.p_sqlfree__statement=(*pStmtHandle)->m_ID.get_value();

   //----- p_sqlfree__option
   packet1.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;
  }//if send_op1_close

  //---------------------------------------- 2.2 build packet2 EXECUTE2
  {
   packet2.operation = c_OperationID2;

   //---------------------------------------- p_sqldata_statement
   packet2.p_sqldata.p_sqldata__statement=(*pStmtHandle)->m_ID.get_value();

   //---------------------------------------- p_sqldata_transaction
   packet2.p_sqldata.p_sqldata__transaction=(*pTrHandle)?(*pTrHandle)->m_ID.get_value():0;

   //---------------------------------------- p_sqldata_blr
   if(!structure::can_numeric_cast(&packet2.p_sqldata.p_sqldata__blr.cstr_length,
                                   pStmtExecData->InMsg_BLR.size()))
   {
    //ERROR - BLR data of input parameters is too long.

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_subsystem__remote_fb__p12,
      ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
      L"pInXSQLDA",
      pStmtExecData->InMsg_BLR.size(),
      structure::get_numeric_limits(packet2.p_sqldata.p_sqldata__blr.cstr_length).max_value());
   }//if

   structure::static_numeric_cast
    (&packet2.p_sqldata.p_sqldata__blr.cstr_length,
     pStmtExecData->InMsg_BLR.size());

   packet2.p_sqldata.p_sqldata__blr.cstr_address=pStmtExecData->InMsg_BLR.data();

   //---------------------------------------- p_sqldata_message_number
   packet2.p_sqldata.p_sqldata__message_number=0;

   //---------------------------------------- p_sqldata_messages + p_sqldata_message_data
   packet2.p_sqldata.p_sqldata__messages=pStmtExecData->InMsg_BLR.empty()?0:1;

   //--------------------------------------- p_sqldata_out_blr [op_execute2]
   if(!structure::can_numeric_cast(&packet2.p_sqldata.p_sqldata__out_blr.cstr_length,
                                    pStmtExecData->OutMsg_BLR.size()))
   {
    //ERROR - BLR data of output parameters is too long.

    IBP_ErrorUtils::Throw__Error
     (E_FAIL,
      ibp_subsystem__remote_fb__p12,
      ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
      L"pOutXSQLDA",
      pStmtExecData->OutMsg_BLR.size(),
      structure::get_numeric_limits(packet2.p_sqldata.p_sqldata__blr.cstr_length).max_value());
   }//if

   structure::static_numeric_cast
    (&packet2.p_sqldata.p_sqldata__out_blr.cstr_length,
     pStmtExecData->OutMsg_BLR.size());

   packet2.p_sqldata.p_sqldata__out_blr.cstr_address=pStmtExecData->OutMsg_BLR.data();

   //--------------------------------------- p_sqldata_out_message_number [op_execute2]
   packet2.p_sqldata.p_sqldata__out_message_number=0;
  }//local - build packet2

  //---------------------------------------- 3. send packet
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
   }//if send_op1_close

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
#ifdef NDEBUG
 protocol::P_OBJCT TrID=0;
#else
 lib::structure::t_value_with_null<protocol::P_OBJCT> TrID;
#endif

 //флаг активности сторожа сбоев порта
 bool PortStateGuardIsActive=true;

 try // сторож сбоев работы с портом
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(pStmtExecData);

  //----------------------------------------- 4.1 get response1 - CLOSE
  t_ibp_error Errors(E_FAIL);

  bool close_was_failed=false;

  if(send_op1_close)
  {
   protocol::set01::PACKET_V01 packet1;

   pData->GetPort()->receive_packet(portOpCtx,packet1);//throw

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
     // [2015-11-15] я не знаю как протестировать данную ошибку.

     close_was_failed=true;

     Errors.add_error
      (spErrRec); //throw

     //дополнительна€ информаци€ о сбое.
     Errors.add_error
      (spErrRec->m_err_code,
       ibp_subsystem__remote_fb__p12,
       ibp_mce_cmd_close_stmt_0);
    }
    else
    {
     //операци€ была выполнена без ошибок.

     // стати, FB 2.5.5 не ругаетс€ на закрытие кусора дл€ (к примеру) "INSERT" запроса.
     //¬ообще, это весьма странно.

     (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
    }//else
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    //отключаем нашего сторожа от порта.
    PortStateGuardIsActive=false;

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#001",
      packet1.operation);

    assert(false);
   }//else
  }//send_op1_close

  //----------------------------------------- 4.2 get response2
  protocol::P_USHORT cOutMessages=0;

  {
   protocol::set01::PACKET_V01 packet2;

   pData->GetPort()->receive_packet
    (portOpCtx,
     packet2); //throw

   if(packet2.operation==protocol::set01::op_sql_response)
   {
    //обработка ответа от сервера

    cOutMessages=packet2.p_sqldata.p_sqldata__messages;

    //отсутствие или одно OUT-сообщение
    assert_msg(cOutMessages<2,"cOutMessages: "<<cOutMessages);
   }//if
   else//ќжидаетс€ ошибка выполнени€ запроса
   if(packet2.operation==protocol::set01::op_response)
   {
    if(const t_ibp_error_element::self_ptr
        spErrRec
         =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
           (pData,
            c_OperationID2,
            packet2.p_resp,
            E_FAIL)) //throw
    {
     assert(FAILED(spErrRec->m_err_code));

     //будем считать, что состо€ние порта стаблизировалось. все пакеты с ответом получены.
     PortStateGuardIsActive=false;

     Errors.add_error(spErrRec);

     //делаем ошибку выполнени€ запроса основной
     Errors.set_last_error_as_primary();

     Errors.raise_me(spErrRec->m_err_code);
    }//if spErrRec

    //ERROR - [BUG CHECK] Ќеожиданный ответ от сервера. ќжидалась ошибка.

    IBP_ErrorUtils::Throw__BugCheck__DEBUG
     (c_bugcheck_src,
      L"#002",
      me_bug_check__we_expected_the_error_0);

    assert(false);
   }//if - protocol::op_response
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    //отключаем нашего сторожа от порта.
    PortStateGuardIsActive=false;

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#003",
      packet2.operation);
   }//else
  }//local

  //----------------------------------------- 4.3 get response3
  {
   protocol::set01::PACKET_V01 packet3;

   pData->GetPort()->receive_packet
    (portOpCtx,
     packet3); //throw

   //состо€ние порта стаблизировано. получены все пакеты.
   PortStateGuardIsActive=false;

   if(packet3.operation==protocol::set01::op_response)
   {
    if(const t_ibp_error_element::self_ptr
        spErrRec
         =pset01::RemoteFB__PSET01__ErrorUtilites::BuildServerErrorRecord
           (pData,
            c_OperationID2,
            packet3.p_resp,
            E_FAIL)) //throw
    {
     assert(FAILED(spErrRec->m_err_code));

     Errors.add_error(spErrRec);

     //делаем ошибку выполнени€ запроса основной
     Errors.set_last_error_as_primary();

     Errors.raise_me(spErrRec->m_err_code);
    }//if spErrRec

    //все нормально - запрос выполнилс€ без ошибок.

    if(close_was_failed)
    {
     assert((*pStmtHandle)->m_pClosingTr);

     //принудительно закрываем курсор запроса
     (*pStmtHandle)->Dangerous__CloseCursorOfClosingTr();
    }//if

    assert((*pStmtHandle)->m_pClosingTr==nullptr);

    TrID=packet3.p_resp.p_resp__object;
   }//if - protocol::op_response
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pData->GetPort(),
      c_bugcheck_src,
      L"#004",
      packet3.operation);
   }//else
  }//local

  //-----------------------------------------
  if(cOutMessages!=1)
  {
   //ERROR - [BUG CHECK] Ќекорректное число OUT-результатов.

   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bugcheck_src,
     L"#005",
     L"Unexpected count of OUT-results: %1",
     cOutMessages);
  }//if
 }
 catch(...)
 {
  if(PortStateGuardIsActive)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//if

  throw;
 }//catch

 assert(!TrID.null());

 return TrID DEBUG_CODE(.value());
}//Execute2__lazy_send

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
