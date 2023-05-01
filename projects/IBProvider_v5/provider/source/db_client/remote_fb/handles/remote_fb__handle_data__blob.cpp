////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb__handles
//! \file    remote_fb__handle_data__blob.h
//! \brief   Конструкции для представления данных дескриптора блоба.
//! \author  Kovalenko Dmitry
//! \date    11.09.2015
#include <_pch_.h>
#pragma hdrstop

//#include "source/db_client/remote_fb/handles/remote_fb__handle_data__blob.h"
//#include "source/db_client/remote_fb/handles/remote_fb__handle_data__transaction.h"
#include "source/db_client/remote_fb/remote_fb__connector_data.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{namespace handles{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob

RemoteFB__HandleData_Blob::RemoteFB__HandleData_Blob(enumBlobMode const BlobMode)
 :m_BlobMode                   (BlobMode)
 ,m_pParentTr                  (nullptr)
 ,m_pPrevTrBlob                (nullptr)
 ,m_pNextTrBlob                (nullptr)
 ,m_pOwnerCnNClosedBlobList    (nullptr)
 ,m_pPrevCnNClosedBlob         (nullptr)
 ,m_pNextCnNClosedBlob         (nullptr)
 ,m_ReadMode__BufferActualSize (0)
 ,m_ReadMode__BufferPos        (0)
 ,m_ReadMode__FragmentTailSize (0)
 ,m_ReadMode__State            (ReadState__None)
 ,m_WriteMode__BufferPos       (0)
 ,m_WriteMode__State           (WriteState__None)
 ,m_spExc                      (nullptr)
{;}

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::~RemoteFB__HandleData_Blob()
{
 assert(m_pParentTr==nullptr);
 assert(m_pPrevTrBlob==nullptr);
 assert(m_pNextTrBlob==nullptr);

 assert(m_pOwnerCnNClosedBlobList==nullptr);
 assert(m_pPrevCnNClosedBlob==nullptr);
 assert(m_pNextCnNClosedBlob==nullptr);
}//~RemoteFB__HandleData_Blob

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::self_ptr RemoteFB__HandleData_Blob::Create(enumBlobMode const BlobMode)
{
 return structure::not_null_ptr(new self_type(BlobMode));
}//Create

//------------------------------------------------------------------------
void RemoteFB__HandleData_Blob::Dangerous__DropHandle()
{
 //блокируем себя в памяти на время деинициализации.
 const self_ptr __selfLockInMemory(this);              // <---- LOCK

 //-----------------------------------------
 assert(!m_ID.is_null());
 assert(m_pParentTr!=nullptr);

 //отключаемся от транзакции
 m_pParentTr->BlobList__Remove(this); //release

 assert(m_pParentTr==nullptr);

 //удаляем себя из списка незакрытых блобов подключения
 if(m_pOwnerCnNClosedBlobList!=nullptr)
 {
  assert(m_ID.is_wait_close() || m_ID.is_wait_cancel());

  m_pOwnerCnNClosedBlobList->DeletedBlobList__Remove(this); //release
 }//if

 assert(m_pOwnerCnNClosedBlobList==nullptr);

 //сброс серверного идентификатор дескриптора блоба
 m_ID.reset();

 assert(m_ID.is_null());
}//Dangerous__DropHandle

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob::tag_tr_list_adapter

RemoteFB__HandleData_Blob::tag_tr_list_adapter::tag_tr_list_adapter()
{;}

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::tag_tr_list_adapter::node_ptr_type
 RemoteFB__HandleData_Blob::tag_tr_list_adapter::null_ptr()
{
 return nullptr;
}//null_ptr

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::tag_tr_list_adapter::node_ptr_type
 RemoteFB__HandleData_Blob::tag_tr_list_adapter::get_prev
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pPrevTrBlob;
}//get_prev

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::tag_tr_list_adapter::node_ptr_type
 RemoteFB__HandleData_Blob::tag_tr_list_adapter::get_next
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pNextTrBlob;
}//get_next

//------------------------------------------------------------------------
void RemoteFB__HandleData_Blob::tag_tr_list_adapter::set_prev
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pPrevTrBlob=x;
}//set_prev

//------------------------------------------------------------------------
void RemoteFB__HandleData_Blob::tag_tr_list_adapter::set_next
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pNextTrBlob=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter

RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::tag_nclosed_blob_list_adapter()
{;}

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::node_ptr_type
 RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::null_ptr()
{
 return nullptr;
}//null_ptr

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::node_ptr_type
 RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::get_prev
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pPrevCnNClosedBlob;
}//get_prev

//------------------------------------------------------------------------
RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::node_ptr_type
 RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::get_next
                                           (node_ptr_type const node)const
{
 assert(node);

 return node->m_pNextCnNClosedBlob;
}//get_next

//------------------------------------------------------------------------
void RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::set_prev
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pPrevCnNClosedBlob=x;
}//set_prev

//------------------------------------------------------------------------
void RemoteFB__HandleData_Blob::tag_nclosed_blob_list_adapter::set_next
                                           (node_ptr_type const node,
                                            node_ptr_type const x)const
{
 assert(node);

 node->m_pNextCnNClosedBlob=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
}/*nms handles*/}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
