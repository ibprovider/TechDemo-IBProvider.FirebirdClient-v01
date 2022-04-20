////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__connector_data.cpp
//! \brief   Класс контейнера данных подключения к FireBird.
//! \author  Kovalenko Dmitry
//! \date    25.02.2015.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__connector_data.h"
#include "source/db_client/remote_fb/remote_fb__error_utils.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ConnectorData

RemoteFB__ConnectorData::RemoteFB__ConnectorData(RemoteFB__Port* const pPort)
 :m_spPort(structure::not_null_ptr(pPort))
{
 assert(m_spPort);
}//RemoteFB__ConnectorData

//------------------------------------------------------------------------
RemoteFB__ConnectorData::~RemoteFB__ConnectorData()
{
 this->ReleaseAllResources();

 assert(m_Transactions.empty());
 assert(m_Statements.empty());
 assert(m_DeletedStatements.empty());
 assert(m_DeletedBlobs.empty());
}//~RemoteFB__ConnectorData

//------------------------------------------------------------------------
RemoteFB__ConnectorData::self_ptr RemoteFB__ConnectorData::Create(RemoteFB__Port* const pPort)
{
 assert(pPort!=nullptr);

 return structure::not_null_ptr(new self_type(pPort));
}//Create

//interface --------------------------------------------------------------

void RemoteFB__ConnectorData::RegService(REFGUID                         svcID,
                                         RemoteFB__SmartInterface* const pSvc)
{
 assert(pSvc);

 _VERIFY(m_Services.insert(services_type::value_type(svcID,pSvc)) DEBUG_CODE(.second));
}//RegService

//------------------------------------------------------------------------
RemoteFB__Port* RemoteFB__ConnectorData::GetPort()const
{
 assert(m_spPort);

 return m_spPort;
}//GetPort

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::TrList__Add(tr_data_type* const phTrData)
{
 assert(phTrData!=nullptr);
 assert(phTrData->m_pParentPort==nullptr);

 m_Transactions.push_back(tr_handle_list_traits(),phTrData);

 phTrData->m_pParentPort=m_spPort;

 phTrData->add_ref();
}//TrList__Add

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::TrList__Remove(tr_data_type* const phTrData)
{
 assert(phTrData!=nullptr);
 assert(phTrData->m_pParentPort==m_spPort);

 m_Transactions.remove(tr_handle_list_traits(),phTrData);

 phTrData->m_pParentPort=nullptr;

 phTrData->release();
}//TrList__Remove

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::StmtList__Add(stmt_data_type* const phStmtData)
{
 assert(phStmtData!=nullptr);
 assert(phStmtData->m_pParentPort==nullptr);
 assert(phStmtData->m_pvOwnerCnList==nullptr);

 m_Statements.push_back(stmt_handle_list_traits(),phStmtData);

 phStmtData->m_pParentPort=m_spPort;

#ifndef NDEBUG
 phStmtData->m_pvOwnerCnList=&m_Statements;
#endif

 phStmtData->add_ref();
}//StmtList__Add

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::StmtList__Remove(stmt_data_type* const phStmtData)
{
 assert(phStmtData!=nullptr);
 assert(phStmtData->m_pParentPort==m_spPort);
 assert(phStmtData->m_pvOwnerCnList==&m_Statements);

 m_Statements.remove(stmt_handle_list_traits(),phStmtData);

 phStmtData->m_pParentPort=nullptr;

#ifndef NDEBUG
 phStmtData->m_pvOwnerCnList=nullptr;
#endif

 phStmtData->release();
}//StmtList__Remove

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::DeletedStmtList__Add(stmt_data_type* const phStmtData)
{
 assert(phStmtData!=nullptr);
 assert(phStmtData->m_pParentPort==nullptr);
 assert(phStmtData->m_pvOwnerCnList==nullptr);

 m_DeletedStatements.push_back(stmt_handle_list_traits(),phStmtData);

#ifndef NDEBUG
 phStmtData->m_pvOwnerCnList=&m_DeletedStatements;
#endif

 phStmtData->add_ref();
}//DeletedStmtList__Add

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::DeletedStmtList__Remove(stmt_data_type* const phStmtData)
{
 assert(phStmtData!=nullptr);
 assert(phStmtData->m_pParentPort==nullptr);
 assert(phStmtData->m_pvOwnerCnList==&m_DeletedStatements);

 m_DeletedStatements.remove(stmt_handle_list_traits(),phStmtData);

#ifndef NDEBUG
 phStmtData->m_pvOwnerCnList=nullptr;
#endif

 phStmtData->release();
}//DeletedStmtList__Remove

//------------------------------------------------------------------------
RemoteFB__ConnectorData::stmt_data_type* RemoteFB__ConnectorData::DeletedStmtList__GetHead()const
{
 if(m_DeletedStatements.empty())
  return nullptr;

 return m_DeletedStatements.head();
}//DeletedStmtList__GetHead

//------------------------------------------------------------------------
size_t RemoteFB__ConnectorData::DeletedStmtList__GetCount()const
{
 return m_DeletedStatements.size();
}//DeletedStmtList__GetCount

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::DeletedBlobList__Add(blob_data_type* const phBlobData)
{
 assert(phBlobData!=nullptr);
 assert(phBlobData->m_pOwnerCnNClosedBlobList==nullptr);

 m_DeletedBlobs.push_back(nclosed_blob_list_traits(),phBlobData);

 phBlobData->m_pOwnerCnNClosedBlobList=this;

 phBlobData->add_ref();
}//DeletedBlobList__Add

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::DeletedBlobList__Remove(blob_data_type* const phBlobData)
{
 assert(phBlobData!=nullptr);
 assert(phBlobData->m_pOwnerCnNClosedBlobList==this);

 m_DeletedBlobs.remove(nclosed_blob_list_traits(),phBlobData);

 phBlobData->m_pOwnerCnNClosedBlobList=nullptr;

 phBlobData->release();
}//DeletedBlobList__Remove

//------------------------------------------------------------------------
RemoteFB__ConnectorData::blob_data_type* RemoteFB__ConnectorData::DeletedBlobList__GetHead()const
{
 if(m_DeletedBlobs.empty())
  return nullptr;

 return m_DeletedBlobs.head();
}//DeletedBlobList__GetHead

//------------------------------------------------------------------------
size_t RemoteFB__ConnectorData::DeletedBlobList__GetCount()const
{
 return m_DeletedBlobs.size();
}//DeletedBlobList__GetCount

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::ReleaseAllResources()
{
 //форсированное освобождение транзакций
 while(!m_Transactions.empty())
  this->TrList__Remove(m_Transactions.head());

 //форсированное освобождение активных запросов
 while(!m_Statements.empty())
  this->StmtList__Remove(m_Statements.head());

 //форсированное освобождение удаленных запросов
 while(!m_DeletedStatements.empty())
  this->DeletedStmtList__Remove(m_DeletedStatements.head());

 while(!m_DeletedBlobs.empty())
  this->DeletedBlobList__Remove(m_DeletedBlobs.head());
}//ReleaseAllResources

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::BugCheck__CheckTr(tr_data_type* const phTrData,
                                                const wchar_t*       const bugcheck_src,
                                                const wchar_t*       const bugcheck_point)const
{
 assert(phTrData!=nullptr);
 assert(bugcheck_src!=nullptr);
 assert(bugcheck_point!=nullptr);

 assert(m_spPort);

 if(phTrData->m_pParentPort!=m_spPort)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadTrHandle
   (bugcheck_src,
    bugcheck_point);
 }//if
}//BugCheck__CheckTr

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::BugCheck__CheckStmt(stmt_data_type* const phStmtData,
                                                  const wchar_t*         const bugcheck_src,
                                                  const wchar_t*         const bugcheck_point)const
{
 assert(phStmtData!=nullptr);
 assert(bugcheck_src!=nullptr);
 assert(bugcheck_point!=nullptr);

 assert(m_spPort);

 if(phStmtData->m_pParentPort!=m_spPort)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadStmtHandle
   (bugcheck_src,
    bugcheck_point);
 }//if
}//BugCheck__CheckStmt

//------------------------------------------------------------------------
void RemoteFB__ConnectorData::BugCheck__CheckBlob(blob_data_type* const phBlobData,
                                                  const wchar_t*  const bugcheck_src,
                                                  const wchar_t*  const bugcheck_point1,
                                                  const wchar_t*  const bugcheck_point2)const
{
 assert(phBlobData!=nullptr);
 assert(!phBlobData->m_ID.is_null());
 assert(!phBlobData->m_ID.is_wait_close());
 assert(!phBlobData->m_ID.is_wait_cancel());
 assert(bugcheck_src!=nullptr);
 assert(bugcheck_point1!=nullptr);
 assert(bugcheck_point2!=nullptr);

 assert(m_spPort);

 if(!phBlobData->m_pParentTr)
 {
  //эту ошибку можно обрабатывать как реальную проблему в коде
  //у нас действительный серверный идентификатор блоба и нулевой указатель
  //на родительскую транзакцию
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (bugcheck_src,
    bugcheck_point1);
 }//if

 if(phBlobData->m_pParentTr->m_pParentPort!=m_spPort)
 {
  assert(false);

  RemoteFB__ErrorUtils::Throw_BugCheck_BadBlobHandle
   (bugcheck_src,
    bugcheck_point2);
 }//if
}//BugCheck__CheckBlob

//t_db_service_provider interface ----------------------------------------
db_obj::t_db_object_ptr RemoteFB__ConnectorData::query_service(REFGUID rguidService)
{
 assert(m_spPort);

 const services_type::const_iterator x(m_Services.find(rguidService));

 if(x!=m_Services.cend())
 {
  assert((*x).second);

  return (*x).second;
 }//if

 return m_spPort->query_service(rguidService);
}//query_service

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
