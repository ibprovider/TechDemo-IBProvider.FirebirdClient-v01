////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__stmt__close.cpp
//! \brief   Закрытие курсора запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    21.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__api_p13_lazy_send__stmt__close.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__CloseStatement

RemoteFB__API_P13_LAZY_SEND__CloseStatement RemoteFB__API_P13_LAZY_SEND__CloseStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__CloseStatement::RemoteFB__API_P13_LAZY_SEND__CloseStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__CloseStatement::~RemoteFB__API_P13_LAZY_SEND__CloseStatement()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__CloseStatement::exec
                                           (RemoteFB__ConnectorData* const pData,
                                            stmt_handle_type*        const pStmtHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__CloseStatement::exec";

 //----------------------------------------- проверка дескриптора запроса
 if((*pStmtHandle)==nullptr)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 if(!(*pStmtHandle)->m_ID.has_value() && !(*pStmtHandle)->m_ID.is_defer())
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
    ibp_subsystem__remote_fb__p13,
    ibp_mce_cmd__attempt_to_close_of_closed_cursor_0);
 }//if

 //мы закрываем ПОДГОТОВЛЕННЫЙ запрос
 assert((*pStmtHandle)->m_PFlags.test(stmt_data_type::PFLAG__PREPARED));

 assert((*pStmtHandle)->m_ID.has_value());

 //-----------------------------------------------------------------------
 if((*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED))
 {
  //Запрос пока еще находится в очереди на выполнение.

  (*pStmtHandle)->Dangerous__CloseCursorOfParentTr();

  assert(!(*pStmtHandle)->m_pParentTr);

  //Кстати, у запроса может быть отложенная команда на завершение ПРЕДЫДУЩЕГО курсора.
  //Так что, формально, у запроса все еще может висеть открытый курсор.
 }//if
 else
 {
  //запрос был выполнен.
  assert(!(*pStmtHandle)->m_EFlags.test(stmt_data_type::EFLAG__EXECUTION_WAS_DEFERRED));

  //у нас не должно быть отложенного закрытия курсора!
  assert((*pStmtHandle)->m_pClosingTr==nullptr);

  //добавляем курсор в список незакрытых курсоров транзакции
  (*pStmtHandle)->m_pParentTr->NotClosedStmtList__Add(*pStmtHandle);

  assert((*pStmtHandle)->m_pClosingTr);
  assert((*pStmtHandle)->m_pClosingTr==(*pStmtHandle)->m_pParentTr);

  //отключаемся от основной транзакции запроса
  (*pStmtHandle)->Dangerous__CloseCursorOfParentTr();

  assert((*pStmtHandle)->m_pClosingTr);
  assert(!(*pStmtHandle)->m_pParentTr);
 }//else

 //----------------------------------------- EXIT
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
