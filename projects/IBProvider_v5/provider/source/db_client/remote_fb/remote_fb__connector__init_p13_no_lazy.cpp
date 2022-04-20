////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector__init_p13_no_lazy.cpp
//! \brief   Инициализация 13-го протокола [NO LAZY MODE].
//! \author  Kovalenko Dmitry
//! \date    14.09.2016
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector.h"

#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__db__get_info.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__db__detach.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__db__drop.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__start.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__prepare.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__rollback.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__rollback_retaining.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__commit.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__trans__commit_retaining.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__allocate.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__drop.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__prepare.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__get_info.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__get_columns.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__get_parameters.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__execute.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__stmt__close.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__open.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__create.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__close.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__cancel.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__get_info.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__read.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__write.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__blob__flush.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__array__put_slice.h"
#include "source/db_client/remote_fb/api/p13/remote_fb__api_p13__array__get_slice.h"

#include "source/db_client/remote_fb/api/p13/remote_fb__api_svc_p13__db__cancel_operation.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

void RemoteFB__Connector::Helper__FinalInitialize__P13__no_lazy()
{
 assert(m_spData);
 assert(m_spData->GetPort());
 assert(m_spData->GetPort()->get_protocol_version()==protocol::FB_PROTOCOL_VERSION13);
 assert(!m_spData->GetPort()->TestPortFlag__lazy());
 assert(!m_spData->GetPort()->TestPortFlag__rpc()); //deprecated

 //-----------------------------------------
 m_spData->m_API__DetachDatabase
  .init(&api::p13::RemoteFB__API_P13__DetachDatabase::Instance);

 //-----------------------------------------
 m_spData->m_API__DropDatabase
  .init(&api::p13::RemoteFB__API_P13__DropDatabase::Instance);

 //-----------------------------------------
 m_spData->m_API__GetDatabaseInfo
  .init(&api::p13::RemoteFB__API_P13__GetDatabaseInfo::Instance);
 
 //-----------------------------------------
 m_spData->m_API__StartTransaction
  .init(&api::p13::RemoteFB__API_P13__StartTransaction::Instance);

 //-----------------------------------------
 m_spData->m_API__PrepareTransaction
  .init(&api::p13::RemoteFB__API_P13__PrepareTransaction::Instance);

 //-----------------------------------------
 m_spData->m_API__Commit
  .init(&api::p13::RemoteFB__API_P13__Commit::Instance);

 //-----------------------------------------
 m_spData->m_API__CommitRetaining
  .init(&api::p13::RemoteFB__API_P13__CommitRetaining::Instance);
 
 //-----------------------------------------
 m_spData->m_API__Rollback
  .init(&api::p13::RemoteFB__API_P13__Rollback::Instance);

 //-----------------------------------------
 m_spData->m_API__RollbackRetaining
  .init(&api::p13::RemoteFB__API_P13__RollbackRetaining::Instance);

 //-----------------------------------------
 m_spData->m_API__ExecuteImmediate
  .init(&api::p13::RemoteFB__API_P13__ExecuteImmediate::Instance);

 //-----------------------------------------
 m_spData->m_API__AllocateStatement
  .init(&api::p13::RemoteFB__API_P13__AllocateStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__DropStatement
  .init(&api::p13::RemoteFB__API_P13__DropStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__PrepareStatement
  .init(&api::p13::RemoteFB__API_P13__PrepareStatement::Instance);
 
 //-----------------------------------------
 m_spData->m_API__GetStatementInfo
  .init(&api::p13::RemoteFB__API_P13__GetStatementInfo::Instance);

 //-----------------------------------------
 m_spData->m_API__GetColumns
  .init(&api::p13::RemoteFB__API_P13__GetColumns::Instance);

 //-----------------------------------------
 m_spData->m_API__GetParameters
  .init(&api::p13::RemoteFB__API_P13__GetParameters::Instance);

 //-----------------------------------------
 m_spData->m_API__ExecuteStatement
  .init(&api::p13::RemoteFB__API_P13__ExecuteStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__FetchStatement
  .init(&api::p13::RemoteFB__API_P13__FetchStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__CloseStatement
  .init(&api::p13::RemoteFB__API_P13__CloseStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__OpenBlob
  .init(&api::p13::RemoteFB__API_P13__OpenBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__CreateBlob
  .init(&api::p13::RemoteFB__API_P13__CreateBlob::Instance);
 
 //-----------------------------------------
 m_spData->m_API__CloseBlob
  .init(&api::p13::RemoteFB__API_P13__CloseBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__CancelBlob
  .init(&api::p13::RemoteFB__API_P13__CancelBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__GetBlobInfo
  .init(&api::p13::RemoteFB__API_P13__GetBlobInfo::Instance);

 //-----------------------------------------
 assert(!m_spData->GetPort()->TestPortFlag__rpc());
 
 m_spData->m_API__ReadBlob
  .init(&api::p13::RemoteFB__API_P13__ReadBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__WriteBlob
  .init(&api::p13::RemoteFB__API_P13__WriteBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__FlushBlob
  .init(&api::p13::RemoteFB__API_P13__FlushBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__PutArraySlice
  .init(&api::p13::RemoteFB__API_P13__PutArraySlice::Instance);

 //-----------------------------------------
 m_spData->m_API__GetArraySlice
  .init(&api::p13::RemoteFB__API_P13__GetArraySlice::Instance);

 //-----------------------------------------------------------------------

 //! \note
 //!  Сервис отмены операций доступен только для INET-соединения

 m_spData->RegService(db_obj::__db_guid<api::RemoteFB__SVC__CancelDbOperation>(),
                      &api::p13::RemoteFB__SVC_P13__CancelDbOperation::Instance);
}//Helper__FinalInitialize__P13__no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
