////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__statement.cpp
//! \brief   Конструкции для представления данных дескриптора запроса.
//! \author  Kovalenko Dmitry
//! \date    24.02.2015
#include <_pch_.h>
#pragma hdrstop

//#include "source/db_client/remote_fb/handles/remote_fb__handle_data__statement.h"
#include "source/db_client/remote_fb/handles/remote_fb__handle_data__transaction.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__FetchResult

RemoteFB__FetchResult::RemoteFB__FetchResult(size_type const RequestedFetchCount,
                                             size_type const cbRowData,
                                             size_type const cbRowDataAlign)
 :m_RequestedFetchCount(RequestedFetchCount)
 ,m_ProcessedFetchCount(0)
 ,m_State(state__active)
 ,m_FetchErr(S_OK)
 ,m_cbRowData(cbRowData)
 ,m_cbRowBlock(cbRowData)
 ,m_RowsDataBufferManager(0,RequestedFetchCount)
{
 assert(m_RequestedFetchCount>0);

 if(!structure::align_memory_size(m_cbRowBlock,cbRowDataAlign))
  throw std::bad_alloc();

 assert(m_cbRowData<=m_cbRowBlock);

 //--------------
 if(m_cbRowBlock>0)
 {
  const size_t c_max_mem=structure::t_numeric_limits<size_t>::max_value();

  const size_t maxN=c_max_mem/m_cbRowBlock;

  if(maxN<RequestedFetchCount)
   throw std::bad_alloc();

  m_RowsDataBuffer.alloc(m_cbRowBlock*RequestedFetchCount);
 }//if
}//RemoteFB__FetchResult

//------------------------------------------------------------------------
RemoteFB__FetchResult::~RemoteFB__FetchResult()
{;}

//------------------------------------------------------------------------
RemoteFB__FetchResult::self_ptr
 RemoteFB__FetchResult::Create(size_type const RequestedFetchCount,
                               size_type const cbRowData,
                               size_type const cbRowDataAlign)
{
 return structure::not_null_ptr(new self_type(RequestedFetchCount,
                                              cbRowData,
                                              cbRowDataAlign));
}//Create

//interface --------------------------------------------------------------
RemoteFB__FetchResult::size_type
 RemoteFB__FetchResult::ROWS__GetCount()const
{
 return m_RowsDataBufferManager.size();
}//ROWS__GetCount

//------------------------------------------------------------------------
RemoteFB__FetchResult::size_type
 RemoteFB__FetchResult::ROWS__GetDataSize()const
{
 return m_cbRowData;
}//ROWS__GetDataSize

//------------------------------------------------------------------------
RemoteFB__FetchResult::byte_type*
 RemoteFB__FetchResult::ROWS__AllocBlock()
{
 assert(!m_RowsDataBufferManager.full());

 m_RowsDataBufferManager.push_back();

 assert(m_RowsDataBufferManager.back()<m_RequestedFetchCount);

 byte_type* const p=m_RowsDataBuffer.ptr_at(m_RowsDataBufferManager.back()*m_cbRowBlock);

 assert(m_RowsDataBuffer.buffer()<=p);
 assert(p<m_RowsDataBuffer.buffer_end());
 assert(m_cbRowBlock<=size_t(m_RowsDataBuffer.buffer_end()-p));

 memset(p,0,m_cbRowBlock);

 return p;
}//ROWS__AllocBlock

//------------------------------------------------------------------------
const RemoteFB__FetchResult::byte_type*
 RemoteFB__FetchResult::ROWS__GetFirstBlock()const
{
 assert(!m_RowsDataBufferManager.empty());

 assert(m_RowsDataBufferManager.front()<m_RequestedFetchCount);

 const byte_type* const p=m_RowsDataBuffer.ptr_at(m_RowsDataBufferManager.front()*m_cbRowBlock);

 assert(m_RowsDataBuffer.buffer()<=p);
 assert(p<m_RowsDataBuffer.buffer_end());
 assert(m_cbRowBlock<=size_t(m_RowsDataBuffer.buffer_end()-p));

 return p;
}//ROWS__GetFirstBlock

//------------------------------------------------------------------------
void RemoteFB__FetchResult::ROWS__FreeFirstBlock()
{
 assert(!m_RowsDataBufferManager.empty());

 m_RowsDataBufferManager.pop_front();
}//ROWS__FreeFirstBlock

//------------------------------------------------------------------------
void RemoteFB__FetchResult::ROWS__FreeLastBlock()
{
 assert(!m_RowsDataBufferManager.empty());

 m_RowsDataBufferManager.pop_back();
}//ROWS__FreeLastBlock

//------------------------------------------------------------------------
void RemoteFB__FetchResult::Reactivate()
{
 m_State=state__active;

 m_ProcessedFetchCount=0;
}//Reactivate

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement

const GUID RemoteFB__HandleData_Statement::svcID
 ={0xF5C6BAAE,0x27BE,0x4480,{0x90,0x1C,0x18,0xC8,0xAD,0xB9,0x0F,0x3A}};

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::RemoteFB__HandleData_Statement()
 :m_pParentPort(nullptr)
#ifndef NDEBUG
 ,m_pvOwnerCnList(nullptr)
#endif
 ,m_pPrevCnStmt        (nullptr)
 ,m_pNextCnStmt        (nullptr)
 ,m_pParentTr          (nullptr)
 ,m_pPrevTrStmt        (nullptr)
 ,m_pNextTrStmt        (nullptr)
 ,m_pClosingTr         (nullptr)
 ,m_pPrevNotClosedStmt (nullptr)
 ,m_pNextNotClosedStmt (nullptr)
 ,m_OutParams__MSG_DATA_SIZE(0)
 ,m_OutParams__MSG_DATA_ALIGN(0)
{
}

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::~RemoteFB__HandleData_Statement()
{
 assert(m_pParentPort==nullptr);
 assert(m_pvOwnerCnList==nullptr);
 assert(m_pPrevCnStmt==nullptr);
 assert(m_pNextCnStmt==nullptr);

 assert(m_pParentTr==nullptr);
 assert(m_pPrevTrStmt==nullptr);
 assert(m_pNextTrStmt==nullptr);

 assert(m_pClosingTr==nullptr);
 assert(m_pPrevNotClosedStmt==nullptr);
 assert(m_pNextNotClosedStmt==nullptr);
}//~RemoteFB__HandleData_Statement

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::self_ptr
 RemoteFB__HandleData_Statement::Create()
{
 return structure::not_null_ptr(new self_type());
}//Create

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::ResetPrepareState()
{
 const self_ptr __selfLockInMemory(this);

 //-----------------------------------------
 m_PFlags.reset();

 m_PData__StmtTypeID.reset();

 m_PData__BatchFetch.reset();

 m_PData__ColumnsData.free();

 m_PData__ParametersData.free();

 //----------
 m_EFlags.reset();

 m_InParams__MSG_BLR.free();

 m_InParams__MSG_DATA.free();

 m_InParams__MSG_DATA_DESCRS.clear();

 m_InParams__MSG_NULLS.free();

 m_OutParams__MSG_BLR.free();

 m_OutParams__MSG_DATA_DESCRS.clear();

 m_OutParams__MSG_DATA.free();

 m_OutParams__MSG_DATA_SIZE=0;

 m_OutParams__MSG_DATA_ALIGN=0;

 m_OutParams__MSG_NULLS.free();

 //----------
 m_spFetchResult.Release();

 //----------
 if(m_pParentTr)
  m_pParentTr->StmtList__Remove(this);

 assert(m_pParentTr==nullptr);
}//ResetPrepareState

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::ResetExecuteState()
{
 const self_ptr __selfLockInMemory(this);

 //-----------------------------------------
 m_EFlags.reset();

 m_InParams__MSG_BLR.alloc(0);

 m_InParams__MSG_DATA.alloc(0);

 m_InParams__MSG_DATA_DESCRS.clear();

 m_InParams__MSG_NULLS.alloc(0);

 m_OutParams__MSG_BLR.alloc(0);

 m_OutParams__MSG_DATA_DESCRS.clear();

 m_OutParams__MSG_DATA.alloc(0);

 m_OutParams__MSG_DATA_SIZE=0;

 m_OutParams__MSG_DATA_ALIGN=0;

 m_OutParams__MSG_NULLS.alloc(0);

 //----------
 m_spFetchResult.Release();

 //----------
 if(m_pParentTr)
  m_pParentTr->StmtList__Remove(this);

 assert(m_pParentTr==nullptr);
}//ResetExecuteState

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::Dangerous__CloseCursorOfParentTr()
{
 const self_ptr __selfLockInMemory(this);

 //-----------------------------------------
 assert(m_ID.has_value());

 //У НАС ОТКРЫТЫЙ КУРСОР, значит он подключен к транзакции.
 assert(m_pParentTr!=nullptr);

 //проверяем, что у нас НЕ УСТАНОВЛЕНЫ EXEC-флаги, про которые мы не знаем.
 assert(m_EFlags.test(~(EFLAG__PAST_EOF|
                        EFLAG__EXECUTION_WAS_DEFERRED))==0);

 //----------

 //сбрасываем все флаги описывающие состояние выполнения запроса.
 m_EFlags.reset();

 m_spFetchResult.Release();

 //----------
 m_pParentTr->StmtList__Remove(this);

 assert(m_pParentTr==nullptr);
}//Dangerous__CloseCursorOfParentTr

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::Dangerous__CloseCursorOfClosingTr()
{
 const self_ptr __selfLockInMemory(this);

 //-----------------------------------------
 assert(m_ID.has_value());

 //WE HAVE AN UNCLOSED CURSOR, it means that it's connected to the transaction.
 assert(m_pClosingTr!=nullptr);

 //----------
 m_pClosingTr->NotClosedStmtList__Remove(this);

 assert(m_pClosingTr==nullptr);
}//Dangerous__CloseCursorOfClosingTr

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::Dangerous__DropHandle()
{
 const self_ptr __selfLockInMemory(this);

 //-----------------------------------------
 assert(m_ID.has_value());

 //сброс идентификатора запроса
 m_ID.reset();

 //сброс конструкций, описывающих подготовленный запрос
 this->ResetPrepareState();

 assert(m_pParentTr==nullptr);

 //отключаемся от транзакции, закрывающей курсор запроса
 if(m_pClosingTr!=nullptr)
  m_pClosingTr->NotClosedStmtList__Remove(this);

 assert(m_pClosingTr==nullptr);
}//Dangerous__DropHandle

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_cn_list_adapter

RemoteFB__HandleData_Statement::tag_cn_list_adapter::tag_cn_list_adapter()
{;}

//interface --------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_cn_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_cn_list_adapter::null_ptr()
{
 return nullptr;
}//null_ptr()

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_cn_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_cn_list_adapter::get_prev
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pPrevCnStmt;
}//get_prev

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_cn_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_cn_list_adapter::get_next
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pNextCnStmt;
}//get_next

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::tag_cn_list_adapter::set_prev
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pPrevCnStmt=x;
}//set_prev

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::tag_cn_list_adapter::set_next
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pNextCnStmt=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_tr_list_adapter

RemoteFB__HandleData_Statement::tag_tr_list_adapter::tag_tr_list_adapter()
{;}

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_tr_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_tr_list_adapter::null_ptr()
{
 return nullptr;
}//null_ptr

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_tr_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_tr_list_adapter::get_prev
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pPrevTrStmt;
}//get_prev

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_tr_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_tr_list_adapter::get_next
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pNextTrStmt;
}//get_next

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::tag_tr_list_adapter::set_prev
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pPrevTrStmt=x;
}//set_prev

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::tag_tr_list_adapter::set_next
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pNextTrStmt=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter

RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::tag_nclosed_stmt_list_adapter()
{;}

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::null_ptr()
{
 return nullptr;
}//null_ptr

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::get_prev
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pPrevNotClosedStmt;
}//get_prev

//------------------------------------------------------------------------
RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::node_ptr_type
 RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::get_next
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pNextNotClosedStmt;
}//get_next

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::set_prev
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pPrevNotClosedStmt=x;
}//set_prev

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::tag_nclosed_stmt_list_adapter::set_next
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pNextNotClosedStmt=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
