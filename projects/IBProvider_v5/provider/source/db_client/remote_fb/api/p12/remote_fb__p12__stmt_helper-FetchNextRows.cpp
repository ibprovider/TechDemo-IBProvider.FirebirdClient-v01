////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__p12__stmt_helper-FetchNextRows.cpp
//! \brief   Auxiliary class for working with statements.
//! \author  Kovalenko Dmitry
//! \date    16.04.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__P12__StmtHelper

void RemoteFB__P12__StmtHelper::FetchNextRows
                             (RemoteFB__P12__SrvOperation&   serverOperation,
                              RemoteFB__ConnectorData* const pData,
                              stmt_data_type*          const pStmt)
{
 assert(pData);
 assert(pStmt);
 assert(pStmt->m_pParentPort);
 assert(pStmt->m_spFetchResult);

 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__P12__StmtHelper::FetchNextRows";

 //-----------------------------------------
 //все загруженные записи были обработаны
 assert(pStmt->m_spFetchResult->ROWS__GetCount()==0);

 assert_msg
  (pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active ||
   pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__completed,
   "state: "<<int(pStmt->m_spFetchResult->m_State));

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_fetch;

 //Переинициализация для получения следующей порции записей
 pStmt->m_spFetchResult->Reactivate();

 assert(pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active);

 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqldata_statement
  packet.p_sqldata.p_sqldata__statement=pStmt->m_ID.get_value();

  //---------------------------------------- p_sqldata_blr
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqldata.p_sqldata__blr,
    pStmt->m_spFetchResult->m_OutMSG_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pOutXSQLDA");

  assert(packet.p_sqldata.p_sqldata__blr.cstr_length==pStmt->m_spFetchResult->m_OutMSG_BLR.size());

  packet.p_sqldata.p_sqldata__blr.cstr_address=pStmt->m_spFetchResult->m_OutMSG_BLR.buffer();

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

  //------ Let's define the boundaries of work with the server
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pStmt->m_pParentPort->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local - sending a packet

 //----------------------------------------- загрузка пакетов ответа
 assert(pStmt->m_spFetchResult->m_ProcessedFetchCount==0);

 for(;;)
 {
  assert(pStmt);
  assert(pStmt->m_spFetchResult);
  assert(pStmt->m_spFetchResult->m_RequestedFetchCount>0);
  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);
  assert(pStmt->m_spFetchResult->m_State==RemoteFB__FetchResult::state__active);

  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc(pStmt->m_spFetchResult.ptr());

  protocol::set01::PACKET_V01 packet;

  pStmt->m_pParentPort->receive_packet
   (portOpCtx,
    packet); //throw

  assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<=pStmt->m_spFetchResult->m_RequestedFetchCount);

  if(packet.operation==protocol::set01::op_fetch_response)
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

       pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__completed;

       return;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      if(pStmt->m_spFetchResult->m_ProcessedFetchCount==1)
      {
       //загружен один ряд. обработка завершена.

       pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__completed;

       return;
      }//if

      assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

      //ERROR - преждевременное завершение групповой выборки данных.
      //Пустой пакет посылается после отправки всех запрошенных пакетов.

      try // перехват исключения и перевод порта в недействительное состояние
      {
       IBP_ErrorUtils::Throw__BugCheck__DEBUG
        (c_bugcheck_src,
         L"#001",
         L"unexpected achievement of the rows group end. Expected: %1. Obtained: %2",
         pStmt->m_spFetchResult->m_RequestedFetchCount,
         pStmt->m_spFetchResult->m_ProcessedFetchCount);

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
       IBP_ErrorUtils::Throw__BugCheck__DEBUG
        (c_bugcheck_src,
         L"#002",
         L"fetch_response packet contains EOF flag and row data");

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

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
       IBP_ErrorUtils::Throw__BugCheck__DEBUG
        (c_bugcheck_src,
         L"#003",
         L"expected end-of-rows-group response packet");

       assert(false);
      }
      catch(...)
      {
       RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

       assert(false);
      }//catch
     }//if m_ProcessedFetchCount==m_RequestedFetchCount

     assert(pStmt->m_spFetchResult->m_ProcessedFetchCount<pStmt->m_spFetchResult->m_RequestedFetchCount);

     //обработка завершена
     pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__eof;

     return;
    }//case 100 [EOF]

    default:
    {
     //ERROR - [BUG CHECK] неопознанный статус операции

     try // перехват исключения и перевод порта в недействительное состояние
     {
      IBP_ErrorUtils::Throw__BugCheck__DEBUG
       (c_bugcheck_src,
        L"#004",
        L"unexpected sqldata status: %1",
        packet.p_sqldata.p_sqldata__status);

      assert(false);
     }
     catch(...)
     {
      RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
       (pData->GetPort());

      assert(false);
     }//catch
    }//default - unexpected status
   }//switch

   //мы не должны попадать в эту точку
   assert(false);
  }//if - op_fetch_response

  //Ожидается ошибка выполнения запроса

  if(packet.operation==protocol::set01::op_response)
  {
   //Мы ожидаем, что произошла ошибка выборки данных.

   //Выполняем отказоустойчивое (к нехватке памяти) завершение по ошибке.

   try
   {
    pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
     (pData,
      c_OperationID,
      packet.p_resp,
      E_FAIL); //throw

    //ERROR - [BUG CHECK] Неожиданный ответ от сервера. Ожидалась ошибка.

    try // перехват исключения и перевод порта в недействительное состояние
    {
     IBP_ErrorUtils::Throw__BugCheck__DEBUG
      (c_bugcheck_src,
       L"#005",
       me_bug_check__we_expected_the_error_0);

     assert(false);
    }
    catch(...)
    {
     RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise
      (pData->GetPort());

     assert(false);
    }//catch
   }
   catch(...)
   {
    pStmt->m_spFetchResult->m_State=RemoteFB__FetchResult::state__failed;

    pStmt->m_spFetchResult->m_spFetchExc=std::current_exception();

    assert(pStmt->m_spFetchResult->m_spFetchExc);

    return;
   }//catch

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
}//FetchNextRows

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
