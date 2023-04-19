////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__p13_lazy_send__stmt_helper-FetchNextRows.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    15.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__p13_lazy_send__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__utilities.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v2.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P13_LAZY_SEND__StmtHelper

void RemoteFB__P13_LAZY_SEND__StmtHelper::FetchNextRows
                             (RemoteFB__P13__SrvOperation&   serverOperation,
                              RemoteFB__ConnectorData* const pData,
                              stmt_data_type*          const pStmt)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_pParentPort);
 assert(pStmt->m_pParentTr);
 assert(pStmt->m_spFetchResult);

 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P13_LAZY_SEND__StmtHelper::FetchNextRows";

 //-----------------------------------------
 //все загруженные записи были обработаны
 assert(pStmt->m_spFetchResult->ROWS__GetCount()==0);

 assert_msg
  (pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active ||
   pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__completed,
   "state: "<<int(pStmt->m_spFetchResult->m_State));

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID1__close =protocol::set02::op_free_statement;
 const protocol::set02::P_OP c_OperationID2__exec  =protocol::set02::op_execute;
 const protocol::set02::P_OP c_OperationID3__fetch =protocol::set02::op_fetch;

 bool send_op1__close=false;
 bool send_op2__exec=false;

 //-----------------------------------------
 if(pStmt->m_pClosingTr!=nullptr)
 {
  //нужно закрыть предыдущий курсор, потом открыть новый
  assert(pStmt->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

  send_op1__close =true;
  send_op2__exec  =true;
 }
 else
 if(pStmt->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED))
 {
  //сначало нужно открыть курсор

  send_op2__exec =true;
 }//else

 //-----------------------------------------
 {
  //Переинициализация для получения следующей порции записей
  pStmt->m_spFetchResult->Reactivate();

  assert(pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active);

  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

  //---------------------------------------- 2. build packets
  protocol::set02::PACKET_V02 packet1__close;
  protocol::set02::PACKET_V02 packet2__exec;
  protocol::set02::PACKET_V02 packet3__fetch;

  //---------------------------------------- 2.1 build packet for close op.
  if(send_op1__close)
  {
   packet1__close.operation = c_OperationID1__close;

   //--------------- p_sqlfree__statement
   packet1__close.p_sqlfree.p_sqlfree__statement=pStmt->m_ID.get_value();

   //--------------- p_sqlfree__option
   packet1__close.p_sqlfree.p_sqlfree__option=isc_api::ibp_isc_DSQL_close;
  }//if send_op1__close

  //---------------------------------------- 2.2 build packet for exec op
  RemoteFB__OpSvc__StmtExecuteData_v2
   stmtExecuteData;

  if(send_op2__exec)
  {
   stmtExecuteData.InMsg_BLR
    =pStmt->m_InParams__MSG_BLR;

   stmtExecuteData.InMsg_DATA_DESCRS
    =pStmt->m_InParams__MSG_DATA_DESCRS;

   stmtExecuteData.InMsg_DATA
    =pStmt->m_InParams__MSG_DATA;

   stmtExecuteData.InMsg_NULLS
    =pStmt->m_InParams__MSG_NULLS;

   RemoteFB__P13__StmtHelper::BuildPacket__op_execute
    (&packet2__exec,
     pStmt->m_pParentTr,
     pStmt,
     stmtExecuteData.InMsg_BLR);

   assert(packet2__exec.operation==c_OperationID2__exec);
  }//if send_op2__exec

  //---------------------------------------- 2.2 build packet for fetch op
  {
   packet3__fetch.operation = c_OperationID3__fetch;

   //--------------- p_sqldata_statement
   packet3__fetch.p_sqldata.p_sqldata__statement=pStmt->m_ID.get_value();

   //--------------- p_sqldata_blr
   RemoteFB__P13__Utilities::CheckAndSetLength__CSTRING_CONST_V2
    (&packet3__fetch.p_sqldata.p_sqldata__blr,
     pStmt->m_spFetchResult->m_OutMSG_BLR.size(),
     ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
     L"pOutXSQLDA");

   assert(packet3__fetch.p_sqldata.p_sqldata__blr.cstr_length==pStmt->m_spFetchResult->m_OutMSG_BLR.size());

   packet3__fetch.p_sqldata.p_sqldata__blr.cstr_address=pStmt->m_spFetchResult->m_OutMSG_BLR.buffer();

   //--------------- p_sqldata_message_number
   packet3__fetch.p_sqldata.p_sqldata__message_number=0;

   //--------------- p_sqldata_messages
   assert(structure::can_numeric_cast
           (&packet3__fetch.p_sqldata.p_sqldata__messages,
            pStmt->m_spFetchResult->m_RequestedFetchCount));

   structure::static_numeric_cast
           (&packet3__fetch.p_sqldata.p_sqldata__messages,
            pStmt->m_spFetchResult->m_RequestedFetchCount);

   assert(packet3__fetch.p_sqldata.p_sqldata__messages>0);
  }//local

  //---------------------------------------- 3. send packets
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc(pStmt->m_spFetchResult.ptr()); //no throw

  if(send_op2__exec)
   portOpCtx.reg_svc(&stmtExecuteData);

  //------ Let's define the boundaries of work with the server
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  try //сторож сбоев работы с портом
  {
   if(send_op1__close)
   {
    pStmt->m_pParentPort->send_packet_with_delay
     (portOpCtx,
      packet1__close); //throw
   }//if send_op1__close

   //--------------
   if(send_op2__exec)
   {
    pStmt->m_pParentPort->send_packet_with_delay
     (portOpCtx,
      packet2__exec); //throw
   }//if send_op2__exec

   //--------------
   {
    pStmt->m_pParentPort->send_packet
     (portOpCtx,
      packet3__fetch); //throw
   }//local
  }
  catch(...)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//catch

  sendFrame.complete(); //throw
 }//local - отправка пакетов

 //-----------------------------------------------------------------------
 assert(pStmt->m_spFetchResult);
 assert(pStmt->m_spFetchResult->m_RequestedFetchCount>0);
 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);
 assert(pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active);

 bool PortStateGuardIsActive=true;

 try //сторож сбоев работы с портом
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(pStmt->m_spFetchResult.ptr());

  protocol::set02::PACKET_V02 packet1__close;
  protocol::set02::PACKET_V02 packet2__exec;
  protocol::set02::PACKET_V02 packet3__fetch;

  //----------------------------------------
  if(send_op1__close)
  {
   pStmt->m_pParentPort->receive_packet
    (portOpCtx,
     packet1__close); //throw
  }//if send_op1__close

  if(send_op2__exec)
  {
   pStmt->m_pParentPort->receive_packet
    (portOpCtx,
     packet2__exec); //throw
  }//if send_op2__exec

  {
   pStmt->m_pParentPort->receive_packet
    (portOpCtx,
     packet3__fetch); //throw
  }//local

  //----------------------------------------
  t_ibp_error Errors(S_OK); //no throw

  //---------------------------------------- результаты CLOSE
  t_ibp_error_element::self_ptr spCloseSrvErr;

  if(send_op1__close)
  {
   if(packet1__close.operation==protocol::set02::op_response)
   {
    //Проверям ошибку
    spCloseSrvErr
     =pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
       (pData,
        c_OperationID1__close,
        packet1__close.p_resp,
        E_FAIL); //throw

    if(spCloseSrvErr)
    {
     Errors.add_error
      (spCloseSrvErr); //throw

     Errors.add_error
      (spCloseSrvErr->m_err_code,
       ibp_subsystem__remote_fb__p13,
       ibp_mce_cmd_close_stmt_0);
    }
    else
    {
     //завершаем отложенное закрытие курсора
     assert(pStmt->m_pClosingTr);

     pStmt->Dangerous__CloseCursorOfClosingTr();

     assert(!pStmt->m_pClosingTr);
    }//if
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    //отключаем сторожа сбоев
    PortStateGuardIsActive=false;

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pStmt->m_pParentPort,
      c_bugcheck_src,
      L"#001",
      packet1__close.operation);
   }//else
  }//if send_op1__close

  //---------------------------------------- результаты EXECUTE
  assert(pStmt->m_pParentTr);
  assert(pStmt->m_spFetchResult);

  t_ibp_error_element::self_ptr spExecuteSrvErr;

  if(send_op2__exec)
  {
   if(packet2__exec.operation==protocol::set02::op_response)
   {
    //Смотрим ошибку

    spExecuteSrvErr
     =pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
       (pData,
        c_OperationID2__exec,
        packet2__exec.p_resp,
        E_FAIL); //throw

    if(spExecuteSrvErr)
    {
     //мы не будем закрывать курсор, потому что пользователь не знает,
     //что выполнение было отложено.

     //поэтому не будем ему создавать проблемы с StmtClose.

     Errors.add_error
      (spExecuteSrvErr); //throw

     Errors.add_error
      (spExecuteSrvErr->m_err_code,
       ibp_subsystem__remote_fb__p13,
       ibp_mce_cmd_execute_SQL_stmt_0);
    }
    else
    if(packet2__exec.p_resp.p_resp__object!=pStmt->m_pParentTr->m_ID.get_value())
    {
     //ERROR - [BUG CHECK] У нас, ВНЕЗАПНО, изменилась транзакция!

     assert(false);

     //подключение будет переведено в "недействительное" состояние

     RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedChangeOfTransaction
      (c_bugcheck_src,
       L"#003",
       pStmt->m_pParentTr->m_ID.get_value(),
       packet2__exec.p_resp.p_resp__object);
    }
    else
    {
     //запрос выполнился без проблем.

     //сбрасываем признак отложенного выполнения запроса.

     pStmt->m_EFlags.clear(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED);

     //и принудительно завершаем отложенное закрытие курсора.
     if(spCloseSrvErr)
      pStmt->Dangerous__CloseCursorOfClosingTr();

     assert(pStmt->m_pClosingTr==nullptr);
    }//else
   }
   else
   {
    //ERROR - [BUG CHECK] unexpected answer from server

    RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
     (pStmt->m_pParentPort,
      c_bugcheck_src,
      L"#004",
      packet2__exec.operation);
   }//else
  }//if send_op2__exec

  //---------------------------------------- результаты FETCH

  //не зависимо от проблем на предыдущих этапах, запрос должен оставаться
  //в открытом состоянии!
  assert(pStmt->m_pParentTr);
  assert(pStmt->m_spFetchResult);

  if(spExecuteSrvErr)
  {
   //был сбой выполнения запроса.
   assert(send_op2__exec);

   assert(Errors.get_record_count()>0);

   if(packet3__fetch.operation==protocol::set02::op_response)
   {
    const t_ibp_error_element::self_ptr
     spFetchSrvRec
      =pset02::RemoteFB__PSET02__ErrorUtilites::BuildServerErrorRecord
        (pData,
         c_OperationID3__fetch,
         packet3__fetch.p_resp,
         E_FAIL); //throw

    //Мы ожидаем ошибку!
    if(!spFetchSrvRec)
    {
     assert(PortStateGuardIsActive);

     IBP_ErrorUtils::Throw__BugCheck__DEBUG
      (Errors,
       c_bugcheck_src,
       L"#005",
       me_bug_check__we_expected_the_error_0);
    }//if !spFetchSrvRec

    assert(spFetchSrvRec);

    PortStateGuardIsActive=false;

    //добавляем ошибку к нашей коллекции
    Errors.add_error(spFetchSrvRec); //throw

    //определяем код первой ошибки
    const HRESULT firstErrCode
     =IBP_MapErrorRecordToHRESULT(Errors.get_record(0));

    assert(FAILED(firstErrCode));

    //! \todo
    //!  Есть мысль обозначить что последняя операция с запросом завершилась
    //!  с ошибками и запрос надо закрыть и заново выполнить.
    //!
    //! [2016-02-02]
    //!  Не понятно при выполнении каких конкретно операций,
    //!  зависящих от текущей операции, нам потребуется эта информация о произошедшем
    //!  сбое и подсказка о необходимости "закрыть и заново выполнить запрос".
    //!  Так же непонятно - зачем нам это вообще нужно делать (закрывать и заново выполнять).

    //и выкидываем исключение
    Errors.raise_me(firstErrCode);
   }//if packet3__fetch.operation==protocol::op_response

   //напоминаем, что у нас был сбой EXECUTE
   assert(spExecuteSrvErr);
   assert(FAILED(spExecuteSrvErr->m_err_code)); //и кстати, да.

   if(packet3__fetch.operation==protocol::set02::op_fetch_response)
   {
    //FETCH, что-то там отработал.

    //смотрим на результаты выполнения CLOSE_STMT (если он выполнялся)
    if(spCloseSrvErr && spCloseSrvErr->m_err_code==DB_E_CANCELED)
    {
     //раз есть ошибка, значит была отправка команды на закрытие курсора
     assert(send_op1__close);

     assert(Errors.get_record_count()>0);
     assert(Errors.get_record(0)==spCloseSrvErr);

     // [2016-02-01]
     // 1. Во время выполнения группы из трех пакетов (close, execute, fetch) клиент
     //    произвёл отмену выполнения операции (он думает про FETCH)
     //
     // 2. Cancel отменил закрытие курсора (close)
     //
     // 3. Execute, соответственно так же не выполнился (reopen opened cursor).
     //
     // 4. А вот Fetch мог выполнится, потому что у нас не был закрыт предыдущий курсор.
     //
     // ------------------------------------
     // Скорее всего это и есть объяснение CORE-3984 [FB Tracker], когда при
     // работе через fbclient.dll мы получаем ошибку:
     //
     //  | Dynamic SQL Error
     //  | SQL error code = -502
     //  | Attempt to reopen an open cursor
     //
     // Здесь fbclient.dll тупо теряет информацию об ошибке закрытия курсора (DB_E_CANCELLED)
     // и сообщает об ошибке выполнения запроса.
     // ------------------------------------
     //
     // Так что, ситуация вроде под контролем
     //  - отключаем сторожа состояния порта
     //  - выкидываем исключение с сформированным списком ошибок

     PortStateGuardIsActive=false;

     //! \todo
     //!  По хорошему, нам стоит сообщить пользователю, что у нас дергался предыдущий
     //!  курсор запроса. Потому что пользователь свято верит, что курсор был
     //!  закрыт, а он какого-то гремлина продолжил работать.

     assert(spCloseSrvErr->m_err_code==DB_E_CANCELED); //еще раз напомним

     Errors.raise_me(spCloseSrvErr->m_err_code);
    }//if spCloseSrvErr && spCloseSrvErr->m_err_code==DB_E_CANCELED
   }//if packet3__fetch.operation==protocol::op_fetch_response

   //ERROR - [BUG CHECK] unexpected answer from server

   PortStateGuardIsActive=false;

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck2_UnexpectedServerAnswer
    (Errors,
     pStmt->m_pParentPort,
     c_bugcheck_src,
     L"#006",
     packet3__fetch.operation);
  }//if spExecuteSrvErr

  assert(!spExecuteSrvErr);

  for(bool firstIteration=true;;firstIteration=false)
  {
   assert(pStmt->m_pParentTr);
   assert(pStmt->m_spFetchResult);

   if(!firstIteration)
   {
    packet3__fetch.init();

    pStmt->m_pParentPort->receive_packet
     (portOpCtx,
      packet3__fetch); //throw
   }//if !firstIteration

   assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);

   if(packet3__fetch.operation==protocol::set02::op_fetch_response)
   {
    switch(packet3__fetch.p_sqldata.p_sqldata__status)
    {
     case 0:
     {
      if(packet3__fetch.p_sqldata.p_sqldata__messages==0)
      {
       //Получено нулевое количество рядов

       //мы можем выбрать меньше чем просили.
       // например, для запроса "select id from dual FOR UPDATE".

       //мы или загрузили все запрошенные записи, или загрузили строго одну запись.

       if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
       {
        //загружены все запрошеные ряды пакета. обработка завершена.

        pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__completed;

        PortStateGuardIsActive=false;

        return;
       }//if

       assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

       if(pStmt->m_spFetchResult->m_ProcessedFetchCount==1)
       {
        //загружен один ряд. обработка завершена.

        pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__completed;

        PortStateGuardIsActive=false;

        return;
       }//if

       assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

       //ERROR - преждевременное завершение групповой выборки данных.
       //Пустой пакет посылается после отправки всех запрошенных пакетов.

       IBP_ErrorUtils::Throw__BugCheck__DEBUG
        (c_bugcheck_src,
         L"#007",
         L"unexpected achievement of the rows group end. Expected: %1. Obtained: %2",
         pStmt->m_spFetchResult->m_RequestedFetchCount,
         pStmt->m_spFetchResult->m_ProcessedFetchCount);
      }//if packet.p_sqldata.p_sqldata_messages==0

      //получены данные ряда

      assert(packet3__fetch.p_sqldata.p_sqldata__messages==1);

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
      {
       //загружен последний пакет группы пакетов с данными

       //грузим завершающий "пустой" пакет.
       continue;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      //обработка НЕ завершена.

      //продолжаем загрузку пакетов ответа
      continue;
     }//case 0

     case 100:
     {
      //достигнут конец результирующего множества

      if(packet3__fetch.p_sqldata.p_sqldata__messages!=0)
      {
       assert(packet3__fetch.p_sqldata.p_sqldata__messages==1);

       //ERROR - [BUG CHECK] мы не должны одновременно получать EOF и данные ряда.

       IBP_ErrorUtils::Throw__BugCheck__DEBUG
        (c_bugcheck_src,
         L"#008",
         L"fetch_response packet contains EOF flag and row data");
      }//if

      assert(packet3__fetch.p_sqldata.p_sqldata__messages==0);

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
      {
       //ERROR - [BUG CHECK] вообще говоря, ожидается пустой пакет, обозначающий
       //конец группы рядов.

       IBP_ErrorUtils::Throw__BugCheck__DEBUG
        (c_bugcheck_src,
         L"#009",
         L"expected end-of-rows-group response packet");
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      //обработка завершена
      pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__eof;

      PortStateGuardIsActive=false;

      return;
     }//case 100 [EOF]

     default:
     {
      //ERROR - [BUG CHECK] неопознанный статус операции

      IBP_ErrorUtils::Throw__BugCheck__DEBUG
       (c_bugcheck_src,
        L"#010",
        L"unexpected sqldata status: %1",
        packet3__fetch.p_sqldata.p_sqldata__status);
     }//default - unexpected status
    }//switch

    //мы не должны попадать в эту точку
    assert(false);
   }//if - op_fetch_response

   //Ожидается ошибка выполнения запроса

   if(packet3__fetch.operation==protocol::set02::op_response)
   {
    //Мы ожидаем, что произошла ошибка выборки данных.

    //Выполняем отказоустойчивое (к нехватке памяти) завершение по ошибке.

    try
    {
     pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
      (pData,
       c_OperationID3__fetch,
       packet3__fetch.p_resp,
       E_FAIL); //throw

     //ERROR - [BUG CHECK] Неожиданный ответ от сервера. Ожидалась ошибка.
     assert(PortStateGuardIsActive);

     PortStateGuardIsActive=false;

     try // перехват исключения и перевод порта в недействительное состояние
     {
      IBP_ErrorUtils::Throw__BugCheck__DEBUG
       (c_bugcheck_src,
        L"#011",
        me_bug_check__we_expected_the_error_0);
     }
     catch(...)
     {
      RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
       (pData->GetPort());

      assert(false);
     }//catch
    }
    catch(const std::bad_alloc&)
    {
     pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__failed;

     pStmt->m_spFetchResult->m_FetchErr.clear_state(E_OUTOFMEMORY);
    }
    catch(t_ibp_error& exc)
    {
     assert(FAILED(exc.com_code()));

     pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__failed;

     pStmt->m_spFetchResult->m_FetchErr.swap(exc); //no throw!

     assert(FAILED(pStmt->m_spFetchResult->m_FetchErr.com_code()));
    }//catch exc

    break;
   }//if - protocol::op_response

   //ERROR - [BUG CHECK] unexpected answer from server

   assert(PortStateGuardIsActive);

   PortStateGuardIsActive=false;

   RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
    (pStmt->m_pParentPort,
     c_bugcheck_src,
     L"#012",
     packet3__fetch.operation);
  }//for[ever]
 }//local
 catch(...)
 {
  if(PortStateGuardIsActive)
  {
   RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

   assert(false);
  }//if

  throw;
 }//catch

 return;
}//helper__fetch_next_rows

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
