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
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v1.h"
#include "source/db_client/remote_fb/remote_fb__op_svc__stmt_execute_data_v2.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Statement

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
void RemoteFB__HandleData_Statement::SaveInParams(const RemoteFB__OpSvc__StmtExecuteData_v1* const pStmtExecData)
{
 assert(pStmtExecData);

 self_type::Helper__Save
  (&m_InParams__MSG_BLR,
   pStmtExecData->InMsg_BLR);

 self_type::Helper__Save
  (&m_InParams__MSG_DATA,
   pStmtExecData->InMsg_DATA);
}//SaveInParams - RemoteFB__OpSvc__StmtExecuteData_v1

//------------------------------------------------------------------------
void RemoteFB__HandleData_Statement::SaveInParams(const RemoteFB__OpSvc__StmtExecuteData_v2* const pStmtExecData)
{
 assert(pStmtExecData);

 self_type::Helper__Save
  (&m_InParams__MSG_BLR,
   pStmtExecData->InMsg_BLR);

 self_type::Helper__Save
  (&m_InParams__MSG_DATA,
   pStmtExecData->InMsg_DATA);

 self_type::Helper__Save
  (&m_InParams__MSG_DATA_DESCRS,
   pStmtExecData->InMsg_DATA_DESCRS);

 self_type::Helper__Save
  (&m_InParams__MSG_NULLS,
   pStmtExecData->InMsg_NULLS);
}//SaveInParams - RemoteFB__OpSvc__StmtExecuteData_v2

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

//Helper methods ---------------------------------------------------------
template<typename T,class Allocator>
static void RemoteFB__HandleData_Statement::Helper__Save
              (structure::t_typed_simple_buffer<T,Allocator>* const pDest,
               const ibp::IBP_BufferView<const T>&                  Source)
{
 assert(pDest);

 assert_s
  (std::is_same
    <typename std::remove_const<typename std::remove_reference<decltype(*pDest->data())>::type>::type _LITER_COMMA_
     typename std::remove_const<typename std::remove_reference<decltype(*Source.data())>::type>::type>::value);

 if(pDest->data()==Source.data())
 {
  //it is the same data!

  assert(pDest->size()==Source.size());
 }
 else
 {
  assert(pDest->data()!=Source.data());

#ifndef NDEBUG
  //
  // Let's check an intersection
  //
  if((Source.data()+Source.size())<pDest->data())
  {
   //OK
  }
  else
  if((pDest->data()+pDest->capacity())<Source.data())
  {
   //OK
  }
  else
  {
   //It is a real problem!

   assert(false);
  }
#endif

  pDest->alloc(Source.size()); //throw

  assert(pDest->size()==Source.size());

  std::copy
   (Source.data(),
    Source.data()+Source.size(),
    pDest->data());
 }//else

 //One more time
 assert(pDest->size()==Source.size());

 //Let's tell our paranoia that all is ok.

 assert(size_t(pDest->buffer_end()-pDest->buffer())==Source.size());

 assert(lib::structure::equal(pDest->buffer(),pDest->buffer_end(),Source.data(),Source.data()+Source.size()));
}//Helper__Save - structure::t_typed_simple_buffer

//------------------------------------------------------------------------
template<typename T,class Allocator>
static void RemoteFB__HandleData_Statement::Helper__Save
              (std::vector<T,Allocator>*     const pDest,
               const ibp::IBP_BufferView<const T>& Source)
{
 assert(pDest);

 assert_s
  (std::is_same
    <typename std::remove_const<typename std::remove_reference<decltype(*pDest->data())>::type>::type _LITER_COMMA_
     typename std::remove_const<typename std::remove_reference<decltype(*Source.data())>::type>::type>::value);

 if(pDest->data()==Source.data())
 {
  //it is the same data!

  assert(pDest->size()==Source.size());
 }
 else
 {
  assert(pDest->data()!=Source.data());

#ifndef NDEBUG
  //
  // Let's check an intersection
  //
  if((Source.data()+Source.size())<pDest->data())
  {
   //OK
  }
  else
  if((pDest->data()+pDest->capacity())<Source.data())
  {
   //OK
  }
  else
  {
   //It is a real problem!

   assert(false);
  }
#endif

  pDest->assign(Source.data(),Source.data()+Source.size()); //throw

  assert(pDest->size()==Source.size());
 }//else

 //One more time
 assert(pDest->size()==Source.size());

 //Let's tell our paranoia that all is ok.

 assert(size_t(pDest->cend()-pDest->cbegin())==Source.size());

 assert(lib::structure::equal(pDest->cbegin(),pDest->cend(),Source.data(),Source.data()+Source.size()));
}//Helper__Save - std::vector

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
