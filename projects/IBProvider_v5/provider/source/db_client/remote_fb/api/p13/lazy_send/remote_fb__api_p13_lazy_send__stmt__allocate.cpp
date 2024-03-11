////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__api_p13_lazy_send
//! \file    remote_fb__api_p13_lazy_send__stmt__allocate.cpp
//! \brief   Создание дескриптора запроса. Версия для lazy_send-протокола.
//! \author  Kovalenko Dmitry
//! \date    17.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/api/p13/lazy_send/remote_fb__api_p13_lazy_send__stmt__allocate.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__operation_context.h"
#include "source/db_client/remote_fb/remote_fb__memory_pool.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace api{namespace p13{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__API_P13_LAZY_SEND__AllocateStatement

RemoteFB__API_P13_LAZY_SEND__AllocateStatement RemoteFB__API_P13_LAZY_SEND__AllocateStatement::Instance;

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__AllocateStatement::RemoteFB__API_P13_LAZY_SEND__AllocateStatement()
{;}

//------------------------------------------------------------------------
RemoteFB__API_P13_LAZY_SEND__AllocateStatement::~RemoteFB__API_P13_LAZY_SEND__AllocateStatement()
{;}

//------------------------------------------------------------------------
void RemoteFB__API_P13_LAZY_SEND__AllocateStatement::exec
                                           (RemoteFB__ConnectorData* const pData,
                                            stmt_handle_type*        const pStmtHandle)
{
 assert(pData!=nullptr);
 assert(pData->GetPort());
 assert(pData->GetPort()->TestPortFlag__lazy());
 assert(pStmtHandle!=nullptr);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"RemoteFB__API_P13_LAZY_SEND__AllocateStatement::exec";

 //----------------------------------------- проверка идентификатора подключения
 if(!pData->GetPort()->m_ID.has_value())
 {
  //ERROR - недействительный дескриптор подключения

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadCnHandle
   (c_bugcheck_src,
    L"#001");
 }//if

 //-----------------------------------------
 if((*pStmtHandle)!=nullptr)
 {
  //ERROR - [BUG CHECK] ненулевое значение дескриптора запроса

  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_StmtHandleNotZero
   (c_bugcheck_src,
    L"#002");
 }//if

 //-----------------------------------------
 //подготавливаем объект дескриптора транзакции

 stmt_handle_type
  NewStmtHandle(handles::RemoteFB__HandleData_Statement::Create()); //throw

 assert(NewStmtHandle!=nullptr);

 //-----------------------------------------
 NewStmtHandle->m_ID.set_defer();

 //----------------------------------------- EXIT

 // регистрация запроса в списке
 pData->StmtList__Add(NewStmtHandle);

 // возвращаем дескриптор вызывающей стороне
 (*pStmtHandle)=LCPI_STL_MOVE_VALUE(NewStmtHandle);

 assert(*pStmtHandle);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms p13*/}/*nms api*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
