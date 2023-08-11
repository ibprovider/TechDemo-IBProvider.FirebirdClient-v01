////////////////////////////////////////////////////////////////////////////////
#ifndef _t_mem_cluster_allocator_H_
#define _t_mem_cluster_allocator_H_

#include <structure/memory/t_mem_cluster_allocator_tag.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class T,class BaseAllocator>
class t_mem_cluster_allocator;

////////////////////////////////////////////////////////////////////////////////
//class t_mem_cluster_allocator__stats

class t_mem_cluster_allocator__stats
{
 public:
  size_t   cluster_count;
  size_t   used_block_count;
  size_t   free_block_count;

 public:
  t_mem_cluster_allocator__stats();

  void reset();
};//class t_mem_cluster_allocator__stats

////////////////////////////////////////////////////////////////////////////////
//class t_mem_cluster_allocator

template<class T,class BaseAllocator>
class t_mem_cluster_allocator:public tag_mem_cluster_allocator
{
 private:
  typedef t_mem_cluster_allocator<T,BaseAllocator>       self_type;

  t_mem_cluster_allocator(const self_type&);

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef size_t                                         size_type;
  typedef ptrdiff_t                                      difference_type;
  typedef T                                              value_type;
  typedef value_type*                                    pointer;
  typedef const value_type*                              const_pointer;

  typedef BaseAllocator                                  base_allocator_type;

  template <class U>
  struct rebind
  {
   typedef t_mem_cluster_allocator<U,base_allocator_type>      other;
  };//rebind

 public:
  enum
  {
   c_def_first_cluster_size =16,
   c_def_max_cluster_size   =1024,
  };

  typedef t_mem_cluster_allocator__stats                stats_type;

 public: //---------------------------------------------------------------
  explicit t_mem_cluster_allocator(size_type items_on_cluster=0);

 ~t_mem_cluster_allocator();

  //---------------------------------------- allocate / free
  pointer allocate_item(); //mandatory method

  void deallocate_item(pointer p); //mandatory method

  //---------------------------------------- additional members
  void swap(self_type&);

  void reset();

  const stats_type& get_stats()const;

  //---------------------------------------- work with free space
  size_type free_space_capacity()const; //mandatory method?

  void reserve_free_space(size_type n); //mandatory method?

 private: //internal typedefs --------------------------------------------
  struct tag_list_item
  {
   private:
    typedef tag_list_item  self_type;

   public:
    self_type*   m_next;
  };//struct tag_list_item

  typedef tag_list_item                                        cluster_type;
  typedef tag_list_item                                        free_node_type;

  typedef typename BaseAllocator::template rebind<char>::other allocator_type;

 private:
  void helper__allocate_cluster();

  void helper__allocate_cluster(size_type cluster_size);

 #ifndef NDEBUG
  void debug__check_state()const;
 #endif

 private:
  size_type const  m_item_size;
  size_type        m_cluster_size;

  allocator_type   m_allocator;

  cluster_type*    m_cluster;
  pointer          m_space_beg;
  pointer          m_space_end;

  free_node_type*  m_free_node;

  stats_type       m_stats;
};//class t_mem_cluster_allocator

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

////////////////////////////////////////////////////////////////////////////////
//specialize std::swap for t_mem_cluster_allocator

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<class T,class BaseAllocator>
inline void swap(structure::t_mem_cluster_allocator<T,BaseAllocator>& a,
                 structure::t_mem_cluster_allocator<T,BaseAllocator>& b)
{
 a.swap(b);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std

////////////////////////////////////////////////////////////////////////////////
#include <structure/memory/t_mem_cluster_allocator.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
