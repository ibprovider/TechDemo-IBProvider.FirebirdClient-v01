////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p12_lazy_send
//! \file    remote_fb__api_p12_lazy_send__stmt__drop.cpp
//! \brief   Освобождение дескриптора запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    28.10.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p12/lazy_send/remote_fb__api_p12_lazy_send__stmt__drop.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p12{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P12_LAZY_SEND__DropStatement

RemoteFB__API_P12_LAZY_SEND__DropStatement RemoteFB__API_P12_LAZY_SEND__DropStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__DropStatement::RemoteFB__API_P12_LAZY_SEND__DropStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P12_LAZY_SEND__DropStatement::~RemoteFB__API_P12_LAZY_SEND__DropStatement()
{;}

//interface --------------------------------------------------------------
void RemoteFB__API_P12_LAZY_SEND__DropStatement::exec
                                           (RemoteFB__ConnectorData* const pData,
                                            stmt_handle_type*        const pStmtHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P12_LAZY_SEND__DropStatement::exec";

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

 //-----------------------------------------
 if((*pStmtHandle)->m_ID.is_defer())
 {
  //запрос НЕ БЫЛ создан на уровне сервера

  assert(!(*pStmtHandle)->m_PFlags.test(lib::structure::negative_one));
  assert(!(*pStmtHandle)->m_EFlags.test(lib::structure::negative_one));

  assert((*pStmtHandle)->m_pParentTr==nullptr);

  (*pStmtHandle)->m_ID.reset();

  pData->StmtList__Remove(*pStmtHandle);
 }//if is_defer
 else
 {
  //----------------------------------------- перемещаем в список запросов на удаление
  assert(!(*pStmtHandle)->m_ID.is_defer());
  assert((*pStmtHandle)->m_ID.has_value());

  //запоминаем серверный идентификатор запроса
  const stmt_data_type::id_type::value_type stmtID=(*pStmtHandle)->m_ID.get_value();

 //(*pStmtHandle) - это смарт указатель, удерживающий объект в памяти.

  //обнуляем идентификатор, используемый в основной работе.
  (*pStmtHandle)->Dangerous__DropHandle();

  assert((*pStmtHandle)->m_ID.is_null());

  //проверяем, что нам не грохнули данные для отложенного удаления
  (*pStmtHandle)->m_ID.set_wait_drop(&stmtID);

  assert((*pStmtHandle)->m_ID.is_wait_drop());
  assert((*pStmtHandle)->m_ID.get_wait_drop()==stmtID);

  //как минимум два владельца:
  // - вызывающая сторона
  // - список на уровне pData
  assert((*pStmtHandle)->get_cntRef()>1);

  //удаляем запрос из основного списка запросов
  pData->StmtList__Remove(*pStmtHandle);

  //добавляем в очередь на удаление
  pData->DeletedStmtList__Add(*pStmtHandle);

  //----------
  assert((*pStmtHandle)->m_ID.is_wait_drop());
  assert((*pStmtHandle)->m_ID.get_wait_drop()==stmtID);
 }//else

 //----------------------------------------- EXIT
 (*pStmtHandle)=nullptr;
}//class exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p12*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
