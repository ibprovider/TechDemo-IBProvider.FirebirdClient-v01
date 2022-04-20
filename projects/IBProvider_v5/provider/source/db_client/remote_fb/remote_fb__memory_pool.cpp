////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__memory_pool.cpp
//! \brief   Класс для управления пулом памяти.
//! \author  Kovalenko Dmitry
//! \date    23.11.2014.
#include <_pch_.h>
#pragma hdrstop

#include "source/db_client/remote_fb/remote_fb__memory_pool.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__MemoryPool

RemoteFB__MemoryPool::RemoteFB__MemoryPool()
 :m_ptr(nullptr)
{;}

//------------------------------------------------------------------------
RemoteFB__MemoryPool::~RemoteFB__MemoryPool()
{
 this->deallocate_all();
}//~RemoteFB__MemoryPool

//interface --------------------------------------------------------------
void* RemoteFB__MemoryPool::allocate(enumMemoryID const /*memID*/,
                                     size_t       const sz)
{
 if(sz==0)
  return nullptr;

 size_t block_sz=sizeof(tag_cluster);

 block_sz-=_MEMBER_SIZE_(tag_cluster,data);

 assert(block_sz<raw_allocator_type::instance.max_size());

 if((raw_allocator_type::instance.max_size()-block_sz)<sz)
  throw std::bad_alloc();

 block_sz+=sz;

 tag_cluster* const p
  =reinterpret_cast<tag_cluster*>(raw_allocator_type::instance.allocate(block_sz));

 assert(p!=nullptr);

 p->next=m_ptr;

 m_ptr=p;

 return m_ptr->data;
}//allocate

//------------------------------------------------------------------------
void RemoteFB__MemoryPool::deallocate_all()
{
 while(m_ptr!=nullptr)
 {
  tag_cluster* p=m_ptr;

  m_ptr=m_ptr->next;

  raw_allocator_type::instance.deallocate(p,0);
 }//while
}//deallocate_all

////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
