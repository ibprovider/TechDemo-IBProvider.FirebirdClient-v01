////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13
//! \file    remote_fb__api_p13__stmt__fetch.cpp
//! \brief   Выборка результатов выполнения запроса.
//! \author  Kovalenko Dmitry
//! \date    22.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__xsqlda_utilities.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__srv_operation.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__p13__stmt_helper.h"
#include "source/db_client/remote_fb/api/pset02/remote_fb__pset02__error_utilities.h"
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
//class RemoteFB__API_P13__FetchStatement

RemoteFB__API_P13__FetchStatement RemoteFB__API_P13__FetchStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13__FetchStatement::RemoteFB__API_P13__FetchStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13__FetchStatement::~RemoteFB__API_P13__FetchStatement()
{;}

//interface --------------------------------------------------------------
bool RemoteFB__API_P13__FetchStatement::exec(db_obj::t_db_operation_context& OpCtx,
                                             RemoteFB__ConnectorData*  const pData,
                                             stmt_handle_type*         const pStmtHandle,
                                             const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(!pData->GetPort()->TestPortFlag__rpc());   //deprecated
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__FetchStatement::exec";

 //-----------------------------------------
 RemoteFB__P13__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

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

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED))
 {
  IBP_ThrowSimpleError
   (DB_E_NOTPREPARED,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd_not_prepared_0);
 }//if

 //Запрос должен быть привязан к транзакции.
 //Иначе считается что он находится в закрытом состоянии.
 if((*pStmtHandle)->m_pParentTr==nullptr)
 {
  //[2015-09-08]
  // На текущий момент это очень жестоко. Возможно в будущем
  // IBProvider научится отслеживать закрытие курсоров через завершение транзакций.
  //
  //[2019-05-15]
  // Вроде мы его уже научили отслеживать косвенные закрытия курсора. Так что
  // теперь будем тормозить отладочные сборки.
  //

#ifdef IBP_BUILD_TESTCODE
  //[2019-05-28]
  // Исключаем из модульных тестов, которые тестируют данную ошибку.
#else
  assert(false);
#endif

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd__cant_fetch_from_closed_cursor_0);
 }//if

 //-----------------------------------------
 assert(pOutXSQLDA!=nullptr); //check again

 if(pOutXSQLDA->version!=pOutXSQLDA->c_version_num)
 {
  RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
   (c_bugcheck_src,
    L"#004",
    L"pOutXSQLDA",
    pOutXSQLDA->version);
 }//if

 if(pOutXSQLDA->sqld<=0)
 {
  //ERROR - [BUG CHECK] incorrect output XSQLDA::sqld

  assert_msg(false,"pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

  RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
   (ibp_subsystem__remote_fb__p13,
    L"pOutXSQLDA",
    pOutXSQLDA->sqld);
 }//if

 if(pOutXSQLDA->sqln<pOutXSQLDA->sqld)
 {
  //ERROR - [BUG CHECK] incorrect output XSQLDA::sqln

  assert_msg(false,"pOutXSQLDA->sqln: "<<pOutXSQLDA->sqln<<". pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

  RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
   (ibp_subsystem__remote_fb__p13,
    L"pOutXSQLDA",
    pOutXSQLDA->sqln,
    pOutXSQLDA->sqld);
 }//if

 //-----------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF))
 {
  //ERROR - synchronization error. fetch after EOF!

  assert(false);

  IBP_ThrowSimpleError
   (E_FAIL,
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd__cant_fetch_after_eof_0);
 }//if

 assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF));

 //-----------------------------------------
 if(!(*pStmtHandle)->m_spFetchResult)
 {
  //it is first fetch from cursor

  assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF));

  //---------
  RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_BLR
   (pOutXSQLDA,
   (*pStmtHandle)->m_OutParams__MSG_BLR); //throw

  assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

  RemoteFB__P13__XSQLDA_Utilities::Build_XSQLDA_MSG_DATA_DESCRS
   (pOutXSQLDA,
    (*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
    &(*pStmtHandle)->m_OutParams__MSG_DATA_SIZE,
    &(*pStmtHandle)->m_OutParams__MSG_DATA_ALIGN); //throw

  assert(!(*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.empty());

  RemoteFB__P13__XSQLDA_Utilities::Alloc_XSQLDA_MSG_NULLS
   (pOutXSQLDA,
    (*pStmtHandle)->m_OutParams__MSG_NULLS);

  assert(!(*pStmtHandle)->m_OutParams__MSG_NULLS.empty());

  //---------
  protocol::P_USHORT cBatchRows DEBUG_CODE(=0);

  assert(!pData->GetPort()->TestPortFlag__rpc());

  if(!(*pStmtHandle)->m_BatchFetch.value_or_default(true))
  {
   //сервер будет возвращать по одной записи.
   cBatchRows=1;
  }
  else
  if(pData->GetPort()->TestPortFlag__symmetric())
  {
   cBatchRows=RemoteFB__P13__StmtHelper::ComputeBatchSize((*pStmtHandle)->m_OutParams__MSG_DATA_SIZE);
  }
  else
  {
   const size_t szMsgData=RemoteFB__P13__XSQLDA_Utilities::Calc_XSQLDA_MAX_XDR_SIZE(pOutXSQLDA);

   assert(szMsgData>0);

   cBatchRows=RemoteFB__P13__StmtHelper::ComputeBatchSize(szMsgData);
  }//else

  assert(cBatchRows>0);

  //---------
  handles::RemoteFB__FetchResult::self_ptr spFetchResult
   (handles::RemoteFB__FetchResult::Create(cBatchRows,
                                           (*pStmtHandle)->m_OutParams__MSG_DATA_SIZE,
                                           (*pStmtHandle)->m_OutParams__MSG_DATA_ALIGN));

  assert(spFetchResult);
  assert(spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);
  assert(spFetchResult->m_ProcessedFetchCount==0);
  assert(spFetchResult->ROWS__GetCount()==0);

  //--------- подготовка завершена
  (*pStmtHandle)->m_spFetchResult.swap(spFetchResult);

  assert((*pStmtHandle)->m_spFetchResult);
 }
 else
 {
  assert((*pStmtHandle)->m_spFetchResult);

  //! \todo
  //!  Проверка стабильности количества и описаний в pOutXSQLDA.
  //!  Если выявлены изменения, то выкидывать BUG-CHECK ошибку.

  assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

  assert(pOutXSQLDA);
  assert(pOutXSQLDA->sqld>0);
  assert((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS.size()==size_t(pOutXSQLDA->sqld));

  assert(!(*pStmtHandle)->m_OutParams__MSG_NULLS.empty());
 }//else (*pStmtHandle)->m_spFetchResult

 assert((*pStmtHandle)->m_spFetchResult);

 assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__PAST_EOF));

 //-----------------------------------------------------------------------
 //! \todo
 //!  Проверить состояние XVAR-элементов в pOutXSQLDA.
 //!  - указатели на данные
 //!  - указатели на индикаторы
 //!  - допустимость типов (нельзя запрашивать SQL_NULL)

 //-----------------------------------------------------------------------
 for(DEBUG_CODE(bool OpFetchWasSended=false);;)
 {
  if((*pStmtHandle)->m_spFetchResult->ROWS__GetCount()>0)
  {
   //Сохраняем полученные результаты в pOutXSQLDA

   try
   {
    RemoteFB__P13__XSQLDA_Utilities::Parse_XSQLDA_MSG_DATA
       ((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
        (*pStmtHandle)->m_spFetchResult->ROWS__GetDataSize(),
        (*pStmtHandle)->m_spFetchResult->ROWS__GetFirstBlock(),
         pOutXSQLDA);
   }
   catch(const std::exception& e)
   {
    t_ibp_error exc(e);

    //Добавляем информацию о текущей операции (установка значений колонок)

    //Как протестировать этот обработчик - непонятно.

    exc.add_error(E_FAIL,
                  ibp_subsystem__remote_fb__p13,
                  ibp_mce_isc__failed_to_set_xsqlda_xvalues_1);

    exc<<L"pOutXSQLDA";

    exc.raise_me();
   }//catch

   (*pStmtHandle)->m_spFetchResult->ROWS__FreeFirstBlock();

   return true;
  }//if (*pStmtHandle)->m_spFetchResult->ROWS__GetCount()>0

  assert((*pStmtHandle)->m_spFetchResult->ROWS__GetCount()==0);

  //----------------------------------------
  if((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__eof)
  {
   (*pStmtHandle)->m_EFlags.set(stmt_data_type::EFLAG__PAST_EOF);

   //Этот объект нам больше не нужен
   (*pStmtHandle)->m_spFetchResult.Release();

   return false;
  }//if EOF

  //----------------------------------------
  if((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__failed)
  {
   //ERROR - генерировать ошибку выборки данных

   assert(FAILED((*pStmtHandle)->m_spFetchResult->m_FetchErr.com_code()));

   (*pStmtHandle)->m_spFetchResult->m_FetchErr.raise();
  }//if FAILED

  assert_msg((*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active ||
             (*pStmtHandle)->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__completed,
             "state: "<<int((*pStmtHandle)->m_spFetchResult->m_State));

  //----------------------------------------
  //инициируем выборку новой партии записей

  //в эту точку мы должны попадать только один раз
  assert(!OpFetchWasSended);

  self_type::helper__fetch_next_rows(serverOperation,
                                     pData,
                                     *pStmtHandle); //throw

  DEBUG_CODE(OpFetchWasSended=true;)

  //----------------------------------------

  //запрос НЕ БЫЛ закрыт
  assert((*pStmtHandle)->m_pParentTr);

  assert((*pStmtHandle)->m_spFetchResult);
 }//for[ever]
}//exec

//helper methods ---------------------------------------------------------
void RemoteFB__API_P13__FetchStatement::helper__fetch_next_rows
                                           (RemoteFB__P13__SrvOperation&   serverOperation,
                                            RemoteFB__ConnectorData* const pData,
                                            stmt_data_type*          const pStmt)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_pParentPort);
 assert(pStmt->m_spFetchResult);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13__FetchStatement::helper__fetch_next_rows";

 //-----------------------------------------
 //все загруженные записи были обработаны
 assert(pStmt->m_spFetchResult->ROWS__GetCount()==0);

 assert_msg(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active ||
            pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__completed,
            "state: "<<int(pStmt->m_spFetchResult->m_State));

 //-----------------------------------------
 const protocol::set02::P_OP c_OperationID=protocol::set02::op_fetch;

 //Переинициализация для получения следующей порции записей
 pStmt->m_spFetchResult->Reactivate();

 assert(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);

 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

 {
  //---------------------------------------- 2. build packet
  protocol::set02::PACKET_V02 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqldata_statement
  packet.p_sqldata.p_sqldata__statement=pStmt->m_ID.get_value();

  //---------------------------------------- p_sqldata_blr
  if(!structure::can_numeric_cast(&packet.p_sqldata.p_sqldata__blr.cstr_length,
                                  pStmt->m_OutParams__MSG_BLR.size()))
  {
   //ERROR - BLR data of input parameters is too long.

   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     ibp_subsystem__remote_fb__p13,
     ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
     L"pOutXSQLDA",
     pStmt->m_OutParams__MSG_BLR.size(),
     structure::get_numeric_limits(packet.p_sqldata.p_sqldata__blr.cstr_length).max_value());
  }//if

  structure::static_numeric_cast(&packet.p_sqldata.p_sqldata__blr.cstr_length,
                                 pStmt->m_OutParams__MSG_BLR.size());

  packet.p_sqldata.p_sqldata__blr.cstr_address=pStmt->m_OutParams__MSG_BLR.buffer();

  //---------------------------------------- p_sqldata_message_number
  packet.p_sqldata.p_sqldata__message_number=0;

  //---------------------------------------- p_sqldata_messages
  assert(structure::can_numeric_cast
          (&packet.p_sqldata.p_sqldata__messages,
           pStmt->m_spFetchResult->m_RequestedFetchCount));

  structure::static_numeric_cast
          (&packet.p_sqldata.p_sqldata__messages,
           pStmt->m_spFetchResult->m_RequestedFetchCount);

  assert(packet.p_sqldata.p_sqldata__messages>0);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  //------ обозначаем рамки начала операции с сервером
  RemoteFB__P13__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pStmt->m_pParentPort->send_packet(portOpCtx,
                                    packet); //throw
  sendFrame.complete(); //throw
 }//local - отправка пакета

 //----------------------------------------- загрузка пакетов ответа
 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

 for(;;)
 {
  assert(pStmt);
  assert(pStmt->m_spFetchResult);
  assert(pStmt->m_spFetchResult->m_RequestedFetchCount>0);
  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);
  assert(pStmt->m_spFetchResult->m_State==handles::RemoteFB__FetchResult::state__active);

  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(pStmt);

  protocol::set02::PACKET_V02 packet;

  pStmt->m_pParentPort->receive_packet(portOpCtx,
                                       packet); //throw

  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);

  if(packet.operation==protocol::set02::op_fetch_response)
  {
   switch(packet.p_sqldata.p_sqldata__status)
   {
    case 0:
    {
     if(packet.p_sqldata.p_sqldata__messages==0)
     {
      //Получено нулевое количество рядов

      //мы можем выбрать меньше чем просили.
      // например, для запроса "select id from dual FOR UPDATE".

      //мы или загрузили все запрошенные записи, или загрузили строго одну запись.

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
      {
       //загружены все запрошеные ряды пакета. обработка завершена.

       pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__completed;

       return;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==1)
      {
       //загружен один ряд. обработка завершена.

       pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__completed;

       return;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      //ERROR - преждевременное завершение групповой выборки данных.
      //Пустой пакет посылается после отправки всех запрошенных пакетов.

      try // перехват исключения и перевод порта в недействительное состояние
      {
       structure::wstr_formatter
        freason(L"unexpected achievement of the rows group end. Expected: %1. Obtained: %2");

       freason<<pStmt->m_spFetchResult->m_RequestedFetchCount
              <<pStmt->m_spFetchResult->m_ProcessedFetchCount;

       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#001",
         freason.c_str())

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

       assert(false);
      }//catch
     }//if packet.p_sqldata.p_sqldata_messages==0

     //получены данные ряда

     assert(packet.p_sqldata.p_sqldata__messages==1);

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

     if(packet.p_sqldata.p_sqldata__messages!=0)
     {
      assert(packet.p_sqldata.p_sqldata__messages==1);

      //ERROR - [BUG CHECK] мы не должны одновременно получать EOF и данные ряда.

      try // перехват исключения и перевод порта в недействительное состояние
      {
       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#002",
         L"fetch_response packet contains EOF flag and row data")

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
        (pData->GetPort());

       assert(false);
      }//catch
     }//if packet.p_sqldata.p_sqldata__messages!=0

     assert(packet.p_sqldata.p_sqldata__messages==0);

     if(pStmt->m_spFetchResult->m_ProcessedFetchCount==pStmt->m_spFetchResult->m_RequestedFetchCount)
     {
      //ERROR - [BUG CHECK] вообще говоря, ожидается пустой пакет, обозначающий
      //конец группы рядов.

      try // перехват исключения и перевод порта в недействительное состояние
      {
       IBP_BUG_CHECK__DEBUG
        (c_bugcheck_src,
         L"#003",
         L"expected end-of-rows-group response packet");

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
        (pData->GetPort());

       assert(false);
      }//catch
     }//if m_ProcessedFetchCount==m_RequestedFetchCount

     assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

     //обработка завершена
     pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__eof;

     return;
    }//case 100 [EOF]

    default:
    {
     //ERROR - [BUG CHECK] неопознанный статус операции

     try // перехват исключения и перевод порта в недействительное состояние
     {
      structure::wstr_formatter freason(L"unexpected sqldata status: %1");

      freason<<packet.p_sqldata.p_sqldata__status;

      IBP_BUG_CHECK__DEBUG
       (c_bugcheck_src,
        L"#004",
        freason.c_str());

      assert(false);
     }
     catch(...)
     {
      RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

      assert(false);
     }//catch
    }//default - unexpected status
   }//switch

   //мы не должны попадать в эту точку
   assert(false);
  }//if - op_fetch_response

  //Ожидается ошибка выполнения запроса

  if(packet.operation==protocol::set02::op_response)
  {
   //Мы ожидаем, что произошла ошибка выборки данных.

   //Выполняем отказоустойчивое (к нехватке памяти) завершение по ошибке.

   try
   {
    pset02::RemoteFB__PSET02__ErrorUtilites::ProcessServerResult
     (pData,
      c_OperationID,
      packet.p_resp,
      E_FAIL); //throw

    //ERROR - [BUG CHECK] Неожиданный ответ от сервера. Ожидалась ошибка.

    try // перехват исключения и перевод порта в недействительное состояние
    {
     IBP_BUG_CHECK__DEBUG
      (c_bugcheck_src,
       L"#005",
       me_bug_check__we_expected_the_error_0);

     assert(false);
    }
    catch(...)
    {
     RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

     assert(false);
    }//catch
   }
   catch(const std::bad_alloc&)
   {
    pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__failed;

    pStmt->m_spFetchResult->m_FetchErr.clear_state(E_OUTOFMEMORY);

    return;
   }
   catch(t_ibp_error& exc)
   {
    assert(FAILED(exc.com_code()));

    pStmt->m_spFetchResult->m_State=handles::RemoteFB__FetchResult::state__failed;

    pStmt->m_spFetchResult->m_FetchErr.swap(exc); //no throw!

    assert(FAILED(pStmt->m_spFetchResult->m_FetchErr.com_code()));

    return;
   }//catch exc

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pStmt->m_pParentPort,
    c_bugcheck_src,
    L"#006",
    packet.operation);
 }//for[ever]

 return;
}//helper__fetch_next_rows

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
