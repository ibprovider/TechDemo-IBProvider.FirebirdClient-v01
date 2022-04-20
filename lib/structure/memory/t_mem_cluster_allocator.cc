////////////////////////////////////////////////////////////////////////////////
#ifndef _t_mem_cluster_allocator_CC_
#define _t_mem_cluster_allocator_CC_

#include <structure/t_algorithm.h>
#include <structure/t_limits.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_mem_cluster_allocator__stats

inline t_mem_cluster_allocator__stats::t_mem_cluster_allocator__stats()
{
 this->reset();
}//t_mem_cluster_allocator__stats

//------------------------------------------------------------------------
inline void t_mem_cluster_allocator__stats::reset()
{
 this->cluster_count    =0;
 this->used_block_count =0;
 this->free_block_count =0;
}//reset

////////////////////////////////////////////////////////////////////////////////
//class t_mem_cluster_allocator

template<class T,class BaseAllocator>
t_mem_cluster_allocator<T,BaseAllocator>::t_mem_cluster_allocator(size_type const items_on_cluster)
 :m_item_size     (structure::align_up(sizeof(T),sizeof(free_node_type))),
  m_cluster_size  (items_on_cluster),
  m_cluster       (nullptr),
  m_space_beg     (nullptr),
  m_space_end     (nullptr),
  m_free_node     (nullptr)
{
 assert(m_item_size>=sizeof(T));
 assert(m_item_size>=sizeof(free_node_type));

 assert((m_item_size%sizeof(free_node_type))==0);
}//t_mem_cluster_allocator

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
t_mem_cluster_allocator<T,BaseAllocator>::~t_mem_cluster_allocator()
{
 this->reset();
}//~t_mem_cluster_allocator

//interface --------------------------------------------------------------
template<class T,class BaseAllocator>
typename t_mem_cluster_allocator<T,BaseAllocator>::pointer
t_mem_cluster_allocator<T,BaseAllocator>::allocate_item()
{
 DEBUG_CODE(this->debug__check_state();)

 if(m_free_node)
 {
  assert(m_stats.free_block_count>0);

  void* const x=m_free_node;

  m_free_node=m_free_node->m_next;

  --m_stats.free_block_count;

  ++m_stats.used_block_count;

  return static_cast<pointer>(x);
 }//if m_free_node

 //-----------------------------------------------------------------------
 if(m_space_beg==m_space_end)
  this->helper__allocate_cluster();

 assert(m_cluster!=nullptr);
 assert(m_space_beg!=nullptr);
 assert(m_space_end!=nullptr);

 assert(m_space_beg<m_space_end);

 ++m_stats.used_block_count;

 return m_space_beg++;
}//allocate_item

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
void t_mem_cluster_allocator<T,BaseAllocator>::deallocate_item(pointer const p)
{
 DEBUG_CODE(this->debug__check_state();)

 if(p==nullptr)
  return;

 assert(m_stats.used_block_count>0);

 reinterpret_cast<free_node_type*>(p)->m_next=m_free_node;

 m_free_node=reinterpret_cast<free_node_type*>(p);

 --m_stats.used_block_count;

 ++m_stats.free_block_count;
}//deallocate_item

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
RELEASE_CODE(inline)
void t_mem_cluster_allocator<T,BaseAllocator>::swap(self_type& x)
{
 DEBUG_CODE(x.debug__check_state();)
 DEBUG_CODE(this->debug__check_state();)

 assert(m_item_size==x.m_item_size);

 //std::swap(m_item_size     ,x.m_item_size);
 std::swap(m_cluster_size  ,x.m_cluster_size);

 m_allocator.swap(x.m_allocator);

 std::swap(m_cluster   ,x.m_cluster);
 std::swap(m_space_beg ,x.m_space_beg);
 std::swap(m_space_end ,x.m_space_end);
 std::swap(m_free_node ,x.m_free_node);

 std::swap(m_stats     ,x.m_stats);

 DEBUG_CODE(x.debug__check_state();)
 DEBUG_CODE(this->debug__check_state();)
}//swap

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
void t_mem_cluster_allocator<T,BaseAllocator>::reset()
{
 DEBUG_CODE(this->debug__check_state();)

 while(m_cluster)
 {
  assert(m_stats.cluster_count>0);

  cluster_type* const ptr=m_cluster;

  m_cluster=m_cluster->m_next;

  ptr->m_next=nullptr;

  m_allocator.deallocate(reinterpret_cast<char*>(ptr),0);

  DEBUG_CODE(--m_stats.cluster_count;)
 }//while m_cluster

 assert(m_stats.cluster_count==0);

 //-----------------------------------------
 m_space_beg=nullptr;
 m_space_end=nullptr;

 m_free_node=nullptr;

 //-----------------------------------------
 m_stats.reset();
}//reset

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
const typename t_mem_cluster_allocator<T,BaseAllocator>::stats_type&
 t_mem_cluster_allocator<T,BaseAllocator>::get_stats()const
{
 return m_stats;
}//get_stats

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
typename t_mem_cluster_allocator<T,BaseAllocator>::size_type
 t_mem_cluster_allocator<T,BaseAllocator>::free_space_capacity()const
{
 DEBUG_CODE(this->debug__check_state();)

 size_type const x1=m_stats.free_block_count;
 size_type const x2=m_space_end-m_space_beg;

 assert(x1<=structure::t_numeric_limits<size_type>::max_value());
 assert(x2<=structure::t_numeric_limits<size_type>::max_value());
 assert(x2<=(structure::t_numeric_limits<size_type>::max_value()-x1));

 return x1+x2;
}//free_space_capacity

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
void t_mem_cluster_allocator<T,BaseAllocator>::reserve_free_space(size_type const n)
{
 DEBUG_CODE(this->debug__check_state();)

 const size_type cur_free_space_capacity=this->free_space_capacity();

 if(n<=cur_free_space_capacity)
  return;

 assert_hint(cur_free_space_capacity<n);

 //move free_space on last cluster to free node list
 while(m_space_end!=m_space_beg)
 {
  --m_space_end;

  reinterpret_cast<free_node_type*>(m_space_end)->m_next=m_free_node;

  m_free_node=reinterpret_cast<free_node_type*>(m_space_end);

  ++m_stats.free_block_count;
 }//while

 assert(this->free_space_capacity()==cur_free_space_capacity);

 assert_hint(cur_free_space_capacity<n);

 this->helper__allocate_cluster(n-cur_free_space_capacity);

 DEBUG_CODE(this->debug__check_state();)
}//reserve_free_space

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
void t_mem_cluster_allocator<T,BaseAllocator>::helper__allocate_cluster()
{
 DEBUG_CODE(this->debug__check_state();)

 if(m_cluster_size>0)
  return this->helper__allocate_cluster(m_cluster_size);

 assert(c_def_first_cluster_size>0);

 if(m_stats.used_block_count==0)
  return this->helper__allocate_cluster(c_def_first_cluster_size);

 assert(c_def_max_cluster_size>0);

 if(m_stats.used_block_count>c_def_max_cluster_size/2)
  return this->helper__allocate_cluster(c_def_max_cluster_size);

 return this->helper__allocate_cluster(2*m_stats.used_block_count);
}//helper__allocate_cluster

//------------------------------------------------------------------------
template<class T,class BaseAllocator>
void t_mem_cluster_allocator<T,BaseAllocator>::helper__allocate_cluster
                                           (size_type const cluster_size)
{
 assert(cluster_size>0);
 assert(m_space_beg==m_space_end);

 assert(m_item_size>=sizeof(free_node_type));

 //----------------------------------------
 const size_type c_cluster_header_mem_sz
  =sizeof(cluster_type);

 const size_type c_cluster_data_mem_offset
  =c_cluster_header_mem_sz;

 {
  const size_type c_max_sz=m_allocator.max_size();

  if(c_max_sz<c_cluster_data_mem_offset)
   throw std::bad_alloc();

  const size_type c_max_cluster_size
   =c_max_sz/m_item_size;

  if(c_max_cluster_size<cluster_size)
   throw std::bad_alloc();
 }//local

 const size_type c_total_sz
  =c_cluster_data_mem_offset+cluster_size*m_item_size;

 //----------------------------------------
 char* const ptr=m_allocator.allocate(c_total_sz); //throw

 assert(ptr!=nullptr);

 ++m_stats.cluster_count;

 //-----
 reinterpret_cast<cluster_type*>(ptr)->m_next=m_cluster;

 m_cluster=reinterpret_cast<cluster_type*>(ptr);

 //-----
 m_space_beg=reinterpret_cast<pointer>(ptr+c_cluster_data_mem_offset);

 m_space_end=m_space_beg+cluster_size;

 //-----
 assert(reinterpret_cast<char*>(m_space_end)==ptr+c_total_sz);
}//helper__allocate_cluster

//------------------------------------------------------------------------
#ifndef NDEBUG

template<class T,class BaseAllocator>
void t_mem_cluster_allocator<T,BaseAllocator>::debug__check_state()const
{
 if(m_cluster==nullptr)
 {
  assert(m_stats.cluster_count==0);
  assert(m_stats.used_block_count==0);
  assert(m_stats.free_block_count==0);

  assert(m_space_beg==nullptr);
  assert(m_space_end==nullptr);
 }
 else
 {
  assert_hint(m_cluster!=nullptr);

  assert(m_stats.cluster_count>0);

  assert(m_space_beg!=nullptr);
  assert(m_space_end!=nullptr);

  assert(m_space_beg<=m_space_end);
 }//else

 //-----------------------------------------
 if(m_stats.free_block_count==0)
 {
  assert(m_free_node==nullptr);
 }
 else
 {
  assert(m_free_node!=nullptr);
 }//else
}//debug__check_state

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#endif
