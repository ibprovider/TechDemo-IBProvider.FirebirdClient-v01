////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector__init_p12_no_lazy.cpp
//! \brief   Инициализация 12-го протокола [NO LAZY MODE].
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector.h"

#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__get_info.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__detach.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__db__drop.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__trans__start.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__trans__prepare.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__trans__rollback.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__trans__rollback_retaining.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__trans__commit.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__trans__commit_retaining.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__dsql__execute_immediate.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__dsql__execute_immediate_m.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__allocate.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__drop.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__prepare.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__get_info.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__get_columns.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__get_parameters.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__execute.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__execute_m.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__fetch.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__fetch_m.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__stmt__close.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__open.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__create.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__close.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__cancel.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__get_info.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__read.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__write.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__blob__flush.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__array__put_slice.h"
#include "source/db_client/remote_fb/api/p12/remote_fb__api_p12__array__get_slice.h"

#include "source/db_client/remote_fb/api/p12/rpc/remote_fb__api_p12_rpc__blob__read.h"

#include "source/db_client/remote_fb/api/p12/remote_fb__api_svc_p12__db__cancel_operation.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__Connector

void RemoteFB__Connector::Helper__FinalInitialize__P12__no_lazy()
{
 assert(m_spData);
 assert(m_spData->GetPort());
 assert(m_spData->GetPort()->get_protocol_version()==protocol::FB_PROTOCOL_VERSION12);
 assert(!m_spData->GetPort()->TestPortFlag__lazy());

 //-----------------------------------------
 m_spData->m_API__DetachDatabase
  .init(&api::p12::RemoteFB__API_P12__DetachDatabase::Instance);

 //-----------------------------------------
 m_spData->m_API__DropDatabase
  .init(&api::p12::RemoteFB__API_P12__DropDatabase::Instance);

 //-----------------------------------------
 m_spData->m_API__GetDatabaseInfo
  .init(&api::p12::RemoteFB__API_P12__GetDatabaseInfo::Instance);

 //-----------------------------------------
 m_spData->m_API__StartTransaction
  .init(&api::p12::RemoteFB__API_P12__StartTransaction::Instance);

 //-----------------------------------------
 m_spData->m_API__PrepareTransaction
  .init(&api::p12::RemoteFB__API_P12__PrepareTransaction::Instance);

 //-----------------------------------------
 m_spData->m_API__Commit
  .init(&api::p12::RemoteFB__API_P12__Commit::Instance);

 //-----------------------------------------
 m_spData->m_API__CommitRetaining
  .init(&api::p12::RemoteFB__API_P12__CommitRetaining::Instance);

 //-----------------------------------------
 m_spData->m_API__Rollback
  .init(&api::p12::RemoteFB__API_P12__Rollback::Instance);

 //-----------------------------------------
 m_spData->m_API__RollbackRetaining
  .init(&api::p12::RemoteFB__API_P12__RollbackRetaining::Instance);

 //-----------------------------------------
 m_spData->m_API__ExecuteImmediate
  .init(&api::p12::RemoteFB__API_P12__ExecuteImmediate::Instance);

 //-----------------------------------------
 m_spData->m_API__ExecuteImmediate_M
  .init(&api::p12::RemoteFB__API_P12__ExecuteImmediate_M::Instance);

 //-----------------------------------------
 m_spData->m_API__AllocateStatement
  .init(&api::p12::RemoteFB__API_P12__AllocateStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__DropStatement
  .init(&api::p12::RemoteFB__API_P12__DropStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__PrepareStatement
  .init(&api::p12::RemoteFB__API_P12__PrepareStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__GetStatementInfo
  .init(&api::p12::RemoteFB__API_P12__GetStatementInfo::Instance);

 //-----------------------------------------
 m_spData->m_API__GetColumns
  .init(&api::p12::RemoteFB__API_P12__GetColumns::Instance);

 //-----------------------------------------
 m_spData->m_API__GetParameters
  .init(&api::p12::RemoteFB__API_P12__GetParameters::Instance);

 //-----------------------------------------
 m_spData->m_API__ExecuteStatement
  .init(&api::p12::RemoteFB__API_P12__ExecuteStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__ExecuteStatement_M
  .init(&api::p12::RemoteFB__API_P12__ExecuteStatement_M::Instance);

 //-----------------------------------------
 m_spData->m_API__FetchStatement
  .init(&api::p12::RemoteFB__API_P12__FetchStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__FetchStatement_M
  .init(&api::p12::RemoteFB__API_P12__FetchStatement_M::Instance);

 //-----------------------------------------
 m_spData->m_API__CloseStatement
  .init(&api::p12::RemoteFB__API_P12__CloseStatement::Instance);

 //-----------------------------------------
 m_spData->m_API__OpenBlob
  .init(&api::p12::RemoteFB__API_P12__OpenBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__CreateBlob
  .init(&api::p12::RemoteFB__API_P12__CreateBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__CloseBlob
  .init(&api::p12::RemoteFB__API_P12__CloseBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__CancelBlob
  .init(&api::p12::RemoteFB__API_P12__CancelBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__GetBlobInfo
  .init(&api::p12::RemoteFB__API_P12__GetBlobInfo::Instance);

 //-----------------------------------------
 if(m_spData->GetPort()->TestPortFlag__rpc())
 {
  m_spData->m_API__ReadBlob
   .init(&api::p12::RemoteFB__API_P12_RPC__ReadBlob::Instance);
 }
 else
 {
  m_spData->m_API__ReadBlob
   .init(&api::p12::RemoteFB__API_P12__ReadBlob::Instance);
 }//else

 //-----------------------------------------
 m_spData->m_API__WriteBlob
  .init(&api::p12::RemoteFB__API_P12__WriteBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__FlushBlob
  .init(&api::p12::RemoteFB__API_P12__FlushBlob::Instance);

 //-----------------------------------------
 m_spData->m_API__PutArraySlice
  .init(&api::p12::RemoteFB__API_P12__PutArraySlice::Instance);

 //-----------------------------------------
 m_spData->m_API__GetArraySlice
  .init(&api::p12::RemoteFB__API_P12__GetArraySlice::Instance);

 //-----------------------------------------------------------------------

 //! \note
 //!  Сервис отмены операций доступен только для INET-соединения

 m_spData->RegService
  (db_obj::__db_guid<api::RemoteFB__SVC__CancelDbOperation>(),
   &api::p12::RemoteFB__SVC_P12__CancelDbOperation::Instance);
}//Helper__FinalInitialize__P12__no_lazy

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
