////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__transaction.cpp
//! \brief   Конструкции для представления данных дескриптора транзакции.
//! \author  Kovalenko Dmitry
//! \date    16.02.2015
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/handles/remote_fb__handle_data__transaction.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Transaction

RemoteFB__HandleData_Transaction::RemoteFB__HandleData_Transaction()
 :m_pParentPort(nullptr)
 ,m_pPrevTr(nullptr)
 ,m_pNextTr(nullptr)
{;}

//------------------------------------------------------------------------
RemoteFB__HandleData_Transaction::~RemoteFB__HandleData_Transaction()
{
 assert(m_pParentPort==nullptr);
 assert(m_pPrevTr==nullptr);
 assert(m_pNextTr==nullptr);

 /// Освобождаем ссылки на связанные ресурсы подключения
 this->Helper__ReleaseAllResources();

 assert(m_Statements.empty());
 assert(m_NotClosedStatements.empty());
 assert(m_Blobs.empty());
}//~RemoteFB__HandleData_Transaction

//------------------------------------------------------------------------
RemoteFB__HandleData_Transaction::self_ptr
 RemoteFB__HandleData_Transaction::Create()
{
 return lib::structure::not_null_ptr(new self_type());
}//Create

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::StmtList__Add(stmt_data_type* const phStmtData)
{
 //транзакция должна находиться в списке ресурсов подключения
 assert(m_pParentPort!=nullptr);

 assert(phStmtData!=nullptr);

 //общее подключение у запроса и транзакции
 assert(phStmtData->m_pParentPort==m_pParentPort);

 assert(phStmtData->m_pParentTr==nullptr);

 m_Statements.push_back(stmt_list_traits(),phStmtData);

 phStmtData->m_pParentTr=this;

 phStmtData->add_ref();
}//StmtList__Add

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::StmtList__Remove(stmt_data_type* const phStmtData)
{
 assert(phStmtData!=nullptr);

 assert(phStmtData->m_pParentTr==this);

 m_Statements.remove(stmt_list_traits(),phStmtData);

 phStmtData->m_pParentTr=nullptr;

 phStmtData->release();
}//StmtList__Remove

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::NotClosedStmtList__Add(stmt_data_type* const phStmtData)
{
 //транзакция должна находиться в списке ресурсов подключения
 assert(m_pParentPort!=nullptr);

 assert(phStmtData!=nullptr);

 //общее подключение у запроса и транзакции
 assert(phStmtData->m_pParentPort==m_pParentPort);

 assert(phStmtData->m_pClosingTr==nullptr);

 m_NotClosedStatements.push_back(nclosed_stmt_list_traits(),phStmtData);

 phStmtData->m_pClosingTr=this;

 phStmtData->add_ref();
}//NotClosedStmtList__Add

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::NotClosedStmtList__Remove(stmt_data_type* const phStmtData)
{
 assert(phStmtData!=nullptr);

 assert(phStmtData->m_pClosingTr==this);

 m_NotClosedStatements.remove(nclosed_stmt_list_traits(),phStmtData);

 phStmtData->m_pClosingTr=nullptr;

 phStmtData->release();
}//NotClosedStmtList__Remove

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::BlobList__Add(blob_data_type* const phBlobData)
{
 //транзакция должна находиться в списке ресурсов подключения
 assert(m_pParentPort!=nullptr);

 assert(phBlobData!=nullptr);

 assert(phBlobData->m_pParentTr==nullptr);

 m_Blobs.push_back(blob_list_traits(),phBlobData);

 phBlobData->m_pParentTr=this;

 phBlobData->add_ref();
}//BlobList__Add

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::BlobList__Remove(blob_data_type* const phBlobData)
{
 assert(phBlobData!=nullptr);

 assert(phBlobData->m_pParentTr==this);

 m_Blobs.remove(blob_list_traits(),phBlobData);

 phBlobData->m_pParentTr=nullptr;

 phBlobData->release();
}//BlobList__Remove

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::CleanupTrResources()
{
 /// Сброс идентификатора транзакции
 m_ID.reset();

 /// Освобождение списка связанных запросов
 while(!m_Statements.empty())
 {
  assert(m_Statements.head());
  assert(m_Statements.head()->m_pParentTr==this);

  DEBUG_CODE(size_t const tmpS=m_Statements.size();)

  assert(tmpS>0);

  m_Statements.head()->Dangerous__CloseCursorOfParentTr();

  assert(m_Statements.size()==(tmpS-1));
 }//while

 /// Освобождение списка незакрытых курсоров транзакции
 while(!m_NotClosedStatements.empty())
 {
  assert(m_NotClosedStatements.head());
  assert(m_NotClosedStatements.head()->m_pClosingTr==this);

  DEBUG_CODE(size_t const tmpS=m_NotClosedStatements.size();)

  assert(tmpS>0);

  m_NotClosedStatements.head()->Dangerous__CloseCursorOfClosingTr();

  assert(m_NotClosedStatements.size()==(tmpS-1));
 }//while

 /// Освобождение списка связанных блобов
 while(!m_Blobs.empty())
 {
  assert(m_Blobs.head());
  assert(m_Blobs.head()->m_pParentTr==this);

  DEBUG_CODE(size_t const tmpS=m_Blobs.size();)

  assert(tmpS>0);

  m_Blobs.head()->Dangerous__DropHandle();

  assert(m_Blobs.size()==(tmpS-1));
 }//while
}//CleanupTrResources

//helper methods ---------------------------------------------------------
void RemoteFB__HandleData_Transaction::Helper__ReleaseAllResources()
{
 while(!m_Statements.empty())
  this->StmtList__Remove(m_Statements.head());

 while(!m_NotClosedStatements.empty())
  this->NotClosedStmtList__Remove(m_NotClosedStatements.head());

 while(!m_Blobs.empty())
  this->BlobList__Remove(m_Blobs.head());
}//Helper__ReleaseAllResources

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Transaction::tag_list_adapter

RemoteFB__HandleData_Transaction::tag_list_adapter::tag_list_adapter()
{;}

//interface --------------------------------------------------------------
RemoteFB__HandleData_Transaction::tag_list_adapter::node_ptr_type
 RemoteFB__HandleData_Transaction::tag_list_adapter::null_ptr()
{
 return nullptr;
}//null_ptr()

//------------------------------------------------------------------------
RemoteFB__HandleData_Transaction::tag_list_adapter::node_ptr_type
 RemoteFB__HandleData_Transaction::tag_list_adapter::get_prev
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pPrevTr;
}//get_prev

//------------------------------------------------------------------------
RemoteFB__HandleData_Transaction::tag_list_adapter::node_ptr_type
 RemoteFB__HandleData_Transaction::tag_list_adapter::get_next
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pNextTr;
}//get_next

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::tag_list_adapter::set_prev
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pPrevTr=x;
}//set_prev

//------------------------------------------------------------------------
void RemoteFB__HandleData_Transaction::tag_list_adapter::set_next
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pNextTr=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
