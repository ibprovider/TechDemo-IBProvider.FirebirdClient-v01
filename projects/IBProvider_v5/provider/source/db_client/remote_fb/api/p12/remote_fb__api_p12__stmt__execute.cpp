////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12
//! \file    remote_fb__api_p12__stmt__execute.cpp
//! \brief   Выполнение запроса.
//! \author  Kovalenko Dmitry
//! \date    05.05.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__execute.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__stmt_helper.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__srv_operation.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__p12__utilities.h"
#include "source/db_client/remote_fb/api/pset01/remote_fb__pset01__error_utilities.h"
#include "source/db_client/remote_fb/api/helpers/xsqlda/v01/remote_fb__api_hlp__xsqlda_v01__utilities.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/db_obj/db_operation_reg.h"
#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_messages.h"
#include <structure/t_pointer_cast.h>

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12__ExecuteStatement

RemoteFB__API_P12__ExecuteStatement RemoteFB__API_P12__ExecuteStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12__ExecuteStatement::RemoteFB__API_P12__ExecuteStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12__ExecuteStatement::~RemoteFB__API_P12__ExecuteStatement()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12__ExecuteStatement::exec(db_obj::t_db_operation_context& OpCtx,
                                               RemoteFB__ConnectorData*  const pData,
                                               tr_handle_type*           const pTrHandle,
                                               stmt_handle_type*         const pStmtHandle,
                                               const isc_api::XSQLDA_V1* const pInXSQLDA,
                                               const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(!pData->GetPort()->TestPortFlag__lazy());
 assert(pTrHandle!=nullptr);
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__ExecuteStatement::exec";

 //-----------------------------------------
 RemoteFB__P12__SrvOperation serverOperation(pData);

 db_obj::t_db_operation_reg regServerOperation(OpCtx,&serverOperation);

 //----------------------------------------- проверка дескриптора транзакции
 if((*pTrHandle)!=nullptr)
 {
  if(!(*pTrHandle)->m_ID.has_value())
  {
   assert(false);

   RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
    (c_bugcheck_src,
     L"#001");
  }//if

  pData->BugCheck__CheckTr
   ((*pTrHandle),
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

 if(!(*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED))
 {
  IBP_ThrowSimpleError
   (DB_E_NOTPREPARED,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_cmd_not_prepared_0);
 }//if

 //-----------------------------------------
 (*pStmtHandle)->ResetExecuteState();

 assert((*pStmtHandle)->m_pParentTr==nullptr);

 //-----------------------------------------
 bool HasInParams=false;

 if(pInXSQLDA!=nullptr)
 {
  if(pInXSQLDA->version!=pInXSQLDA->c_version_num)
  {
   RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
    (c_bugcheck_src,
     L"#006",
     L"pInXSQLDA",
     pInXSQLDA->version);
  }//if

  if(pInXSQLDA->sqld<0)
  {
   //ERROR - [BUG CHECK] incorrect input XSQLDA::sqld

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
    (ibp_subsystem__remote_fb__p12,
     L"pInXSQLDA",
     pInXSQLDA->sqld);
  }//if

  if(pInXSQLDA->sqln<pInXSQLDA->sqld)
  {
   //ERROR - [BUG CHECK] incorrect input XSQLDA::sqln

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
    (ibp_subsystem__remote_fb__p12,
     L"pInXSQLDA",
     pInXSQLDA->sqln,
     pInXSQLDA->sqld);
  }//if

  //----
  HasInParams=(pInXSQLDA->sqld>0);
 }//if pInXSQLDA

 //-----------------------------------------
 bool HasOutParams=false;

 if(pOutXSQLDA!=nullptr)
 {
  if(pOutXSQLDA->version!=pOutXSQLDA->c_version_num)
  {
   RemoteFB__ErrorUtils::ThrowBugCheck_Incorrect_XSQLDA_Version
    (c_bugcheck_src,
     L"#007",
     L"pOutXSQLDA",
     pOutXSQLDA->version);
  }//if

  if(pOutXSQLDA->sqld<0)
  {
   //ERROR - [BUG CHECK] incorrect output XSQLDA::sqld

   assert_msg(false,"pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
    (ibp_subsystem__remote_fb__p12,
     L"pOutXSQLDA",
     pOutXSQLDA->sqld);
  }//if

  if(pOutXSQLDA->sqln<pOutXSQLDA->sqld)
  {
   //ERROR - [BUG CHECK] incorrect output XSQLDA::sqln

   assert_msg(false,"pOutXSQLDA->sqln: "<<pOutXSQLDA->sqln<<". pOutXSQLDA->sqld: "<<pOutXSQLDA->sqld);

   RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqln
    (ibp_subsystem__remote_fb__p12,
     L"pOutXSQLDA",
     pOutXSQLDA->sqln,
     pOutXSQLDA->sqld);
  }//if

  HasOutParams=(pOutXSQLDA->sqld>0);
 }//if pOutXSQLDA

 //-----------------------------------------
 //подготавливаем объект дескриптора транзакции

 if(!pData->m_spPreCreatedTr)
  pData->m_spPreCreatedTr=handles::RemoteFB__HandleData_Transaction::Create();

 assert(pData->m_spPreCreatedTr!=nullptr);
 assert(pData->m_spPreCreatedTr->get_cntRef()==1);

 //-----------------------------------------
 protocol::P_OBJCT TrID=0;

 if(!HasOutParams)
 {
  TrID=helper__execute(serverOperation,
                       pData,
                       pTrHandle,
                       pStmtHandle,
                       pInXSQLDA); //throw
 }
 else
 {
  TrID=helper__execute2(serverOperation,
                        pData,
                        pTrHandle,
                        pStmtHandle,
                        pInXSQLDA,
                        pOutXSQLDA); //throw
 }//else

 //----------------------------------------- EXIT
 for(;;)
 {
  if(TrID==0)
  {
   if((*pTrHandle))
   {
    //очистка ресурсов транзакции
    (*pTrHandle)->CleanupTrResources();

    //удаляем транзакцию из списка
    pData->TrList__Remove(*pTrHandle);

    //обнуляем дескриптор
    (*pTrHandle)=nullptr;
   }//if

   break;
  }//if

  assert(TrID!=0);

  if(!(*pTrHandle))
  {
   //запоминаем идентификатор дескриптора транзакции
   handles::RemoteFB__TrHandle newTrHandle;

   assert(!newTrHandle);
   assert(pData->m_spPreCreatedTr);
   assert(pData->m_spPreCreatedTr->get_cntRef()==1);

   pData->m_spPreCreatedTr.swap(newTrHandle);

   assert(!pData->m_spPreCreatedTr);
   assert(newTrHandle);
   assert(newTrHandle->get_cntRef()==1);

   assert(newTrHandle->m_ID.is_null());

   newTrHandle->m_ID.set_value(&TrID);

   //регистрируем транзакцию в списке
   pData->TrList__Add(newTrHandle); //no throw

   //возвращаем дескриптор вызывающей стороне
   (*pTrHandle)=__STL_MOVE_VALUE(newTrHandle);
  }//if
  else
  if((*pTrHandle)->m_ID.get_value()!=TrID)
  {
   // [2015-05-07]
   //  Произошла смена идентификатора транзакции. Как поступать в данной ситуации
   //  пока не понятно. Так что пока будем обрабатывать как BUG CHECK ошибку.

   try // перехват исключения и перевод порта в недействительное состояние
   {
    RemoteFB__ErrorUtils::Throw_BugCheck_UnexpectedChangeOfTransaction
     (c_bugcheck_src,
      L"#008",
      /*oldTrID*/(*pTrHandle)->m_ID.get_value(),
      /*newTrID*/TrID);

    assert(false);
   }
   catch(...)
   {
    RemoteFB__ProcessCurrentException_SetInvalidPortState_Raise(pData->GetPort());

    assert(false);
   }//catch
  }//(*pTrHandle)->m_ID.get_value()!=TrID

  //Привязка запроса к транзакции, если транзакция все еще существует.

  if(*pTrHandle)
   (*pTrHandle)->StmtList__Add(*pStmtHandle);

  break;
 }//for[ever]
}//exec

//------------------------------------------------------------------------
protocol::P_USHORT RemoteFB__API_P12__ExecuteStatement::helper__execute
                                           (RemoteFB__P12__SrvOperation&    serverOperation,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            const isc_api::XSQLDA_V1* const pInXSQLDA)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__ExecuteStatement::helper__execute";

 //-----------------------------------------
 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_BLR
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_BLR); //throw

 assert((pInXSQLDA==nullptr || pInXSQLDA->sqld==0)==((*pStmtHandle)->m_InParams__MSG_BLR.empty()));

 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_DATA);

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_execute;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  RemoteFB__P12__StmtHelper::BuildPacket__op_execute
   (&packet,
    pTrHandle?*pTrHandle:nullptr,
    *pStmtHandle);

  assert(packet.operation==c_OperationID);

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc((*pStmtHandle).ptr());

  //------ Let's define the boundaries of work with the server
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response
 protocol::P_OBJCT TrID=0;

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

   TrID=packet.p_resp.p_resp__object;

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#001",
    packet.operation);
 }//for[ever]

 return TrID;
}//helper__execute

//------------------------------------------------------------------------
protocol::P_OBJCT RemoteFB__API_P12__ExecuteStatement::helper__execute2
                                           (RemoteFB__P12__SrvOperation&    serverOperation,
                                            RemoteFB__ConnectorData*  const pData,
                                            tr_handle_type*           const pTrHandle,
                                            stmt_handle_type*         const pStmtHandle,
                                            const isc_api::XSQLDA_V1* const pInXSQLDA,
                                            const isc_api::XSQLDA_V1* const pOutXSQLDA)
{
 assert(pTrHandle);
 assert(pStmtHandle);
 assert(*pStmtHandle);

 assert(pOutXSQLDA!=nullptr);
 assert(pOutXSQLDA->sqld>0);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12__ExecuteStatement::helper__execute2";

 //-----------------------------------------
 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_BLR
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_BLR); //throw

 assert((pInXSQLDA==nullptr || pInXSQLDA->sqld==0)==((*pStmtHandle)->m_InParams__MSG_BLR.empty()));

 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA
  (pInXSQLDA,
   (*pStmtHandle)->m_InParams__MSG_DATA);

 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_BLR
  (pOutXSQLDA,
   (*pStmtHandle)->m_OutParams__MSG_BLR); //throw

 assert(!(*pStmtHandle)->m_OutParams__MSG_BLR.empty());

 helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Build_XSQLDA_MSG_DATA_DESCRS
  (pOutXSQLDA,
   (*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
   &(*pStmtHandle)->m_OutParams__MSG_DATA_SIZE,
   &(*pStmtHandle)->m_OutParams__MSG_DATA_ALIGN); //throw

 (*pStmtHandle)->m_OutParams__MSG_DATA.alloc((*pStmtHandle)->m_OutParams__MSG_DATA_SIZE);

 //! \todo
 //!  Проверить состояние XVAR-элементов в pOutXSQLDA.
 //!  - указатели на данные
 //!  - указатели на индикаторы
 //!  - допустимость типов (нельзя запрашивать SQL_NULL)

 //-----------------------------------------
 const protocol::set01::P_OP c_OperationID=protocol::set01::op_execute2;

 {
  //---------------------------------------- 2. build packet
  protocol::set01::PACKET_V01 packet;

  packet.operation = c_OperationID;

  //---------------------------------------- p_sqldata_statement
  packet.p_sqldata.p_sqldata__statement=(*pStmtHandle)->m_ID.get_value();

  //---------------------------------------- p_sqldata_transaction
  packet.p_sqldata.p_sqldata__transaction=(*pTrHandle)?(*pTrHandle)->m_ID.get_value():0;

  //---------------------------------------- p_sqldata_blr
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqldata.p_sqldata__blr,
    (*pStmtHandle)->m_InParams__MSG_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pInXSQLDA");

  assert(packet.p_sqldata.p_sqldata__blr.cstr_length==(*pStmtHandle)->m_InParams__MSG_BLR.size());

  packet.p_sqldata.p_sqldata__blr.cstr_address=(*pStmtHandle)->m_InParams__MSG_BLR.buffer();

  //---------------------------------------- p_sqldata_message_number
  packet.p_sqldata.p_sqldata__message_number=0;

  //---------------------------------------- p_sqldata_messages + p_sqldata_message_data
  packet.p_sqldata.p_sqldata__messages=(*pStmtHandle)->m_InParams__MSG_BLR.empty()?0:1;

  //--------------------------------------- p_sqldata_out_blr [op_execute2]
  RemoteFB__P12__Utilities::CheckAndSetLength__CSTRING_CONST
   (&packet.p_sqldata.p_sqldata__out_blr,
    (*pStmtHandle)->m_OutParams__MSG_BLR.size(),
    ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3,
    L"pOutXSQLDA");

  assert(packet.p_sqldata.p_sqldata__out_blr.cstr_length==(*pStmtHandle)->m_OutParams__MSG_BLR.size());

  packet.p_sqldata.p_sqldata__out_blr.cstr_address=(*pStmtHandle)->m_OutParams__MSG_BLR.buffer();

  //--------------------------------------- p_sqldata_out_message_number [op_execute2]
  packet.p_sqldata.p_sqldata__out_message_number=0;

  //---------------------------------------- 3. send packet
  RemoteFB__OperationContext portOpCtx;

  portOpCtx.reg_svc((*pStmtHandle).ptr());

  //------ Let's define the boundaries of work with the server
  RemoteFB__P12__SrvOperation::tag_send_frame sendFrame(&serverOperation); //throw

  pData->GetPort()->send_packet
   (portOpCtx,
    packet); //throw

  sendFrame.complete(); //throw
 }//local

 //----------------------------------------- 4. get response1
 protocol::P_USHORT cOutMessages=0;

 for(;;)
 {
  RemoteFB__MemoryPool memoryPool;

  RemoteFB__OperationContext portOpCtx(&memoryPool);

  portOpCtx.reg_svc((*pStmtHandle).ptr());

  protocol::set01::PACKET_V01 packet;

  pData->GetPort()->receive_packet
   (portOpCtx,
    packet); //throw

  if(packet.operation==protocol::set01::op_sql_response)
  {
   //обработка ответа от сервера

   cOutMessages=packet.p_sqldata.p_sqldata__messages;

   //отсутствие или одно OUT-сообщение
   assert_msg(cOutMessages<2,"cOutMessages: "<<cOutMessages);

   break;
  }//if

  //Ожидается ошибка выполнения запроса

  if(packet.operation==protocol::set01::op_response)
  {
   pset01::RemoteFB__PSET01__ErrorUtilites::ProcessServerResult
    (pData,
     c_OperationID,
     packet.p_resp,
     E_FAIL); //throw

   //ERROR - [BUG CHECK] Неожиданный ответ от сервера. Ожидалась ошибка.

   IBP_BUG_CHECK__DEBUG
    (c_bugcheck_src,
     L"#001",
     me_bug_check__we_expected_the_error_0);

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#002",
    packet.operation);
 }//for[ever]

 //----------------------------------------- 4. get response2
 protocol::P_OBJCT TrID=0;

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

   //все нормально - запрос выполнился без ошибок.

   TrID=packet.p_resp.p_resp__object;

   break;
  }//if - protocol::op_response

  //ERROR - [BUG CHECK] unexpected answer from server

  RemoteFB__ErrorUtils::SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
   (pData->GetPort(),
    c_bugcheck_src,
    L"#003",
    packet.operation);
 }//for[ever]

 //-----------------------------------------
 if(cOutMessages!=1)
 {
  //ERROR - [BUG CHECK] Некорректное число OUT-результатов.

  structure::wstr_formatter freason(L"Unexpected count of OUT-results: %1");

  freason<<cOutMessages;

  IBP_BUG_CHECK__DEBUG
   (c_bugcheck_src,
    L"#004",
    freason.c_str());
 }//if

 //Сохраняем полученные результаты в pOutXSQLDA

 try
 {
  helpers::RemoteFB__API_HLP__XSQLDA_V01__Utilities::Parse_XSQLDA_MSG_DATA
   ((*pStmtHandle)->m_OutParams__MSG_DATA_DESCRS,
    (*pStmtHandle)->m_OutParams__MSG_DATA.size(),
    (*pStmtHandle)->m_OutParams__MSG_DATA.buffer(),
     pOutXSQLDA);
 }
 catch(const std::exception& e)
 {
  t_ibp_error exc(e);

  //Добавляем информацию о текущей операции (установка значений OUT-параметров)

  //Как протестировать этот обработчик - непонятно.

  exc.add_error
   (E_FAIL,
    ibp_subsystem__remote_fb__p12,
    ibp_mce_isc__failed_to_set_xsqlda_xvalues_1);

  exc<<L"pOutXSQLDA";

  exc.raise_me();
 }//catch

 //-----------------------------------------
 return TrID;
}//helper__execute2

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
