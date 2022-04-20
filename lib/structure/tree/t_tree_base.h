////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_base_H_
#define _t_tree_base_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/memory/t_mem_cluster_allocator_builder.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class TNode,class Allocator>
class t_tree_base;

////////////////////////////////////////////////////////////////////////////////
//class t_tree_base

#if !defined(NDEBUG) && !defined(_TEST_STRUCTURE_TREE)
# define _TEST_STRUCTURE_TREE
#endif

template<class TNode,class Allocator>
class t_tree_base
{
 private:
  typedef t_tree_base<TNode,Allocator>                          self_type;

  t_tree_base(const self_type&);

  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TNode                                                 node_type;
  typedef typename node_type::value_type                        value_type;
  typedef node_type*                                            pnode_type;

  typedef size_t                                                size_type;

 private:
  typedef typename t_mem_cluster_allocator_builder
             <node_type,Allocator>::allocator_type              allocator_type;

 public:
  t_tree_base();

 ~t_tree_base();

  void init_as_copy(const self_type& x);

  void clear();

  bool empty()const;

  size_type size()const;

  size_type capacity()const;

  void reserve(size_type n);

 public:
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  pnode_type internal_alloc_node__from_value(pnode_type parent,const U& x);
 #else
  pnode_type internal_alloc_node__from_value(pnode_type parent,const value_type& x);
 #endif

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  pnode_type internal_alloc_node__from_value(pnode_type parent,U&& rrx);
 #else
  pnode_type internal_alloc_node__from_value(pnode_type parent,value_type&& rrx);
 #endif
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  pnode_type internal_alloc_node__from_node(pnode_type parent,const node_type& x);

 #if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)
  template<class... Args>
  pnode_type internal_alloc_node__emplace(pnode_type parent,Args&&... args);
 #endif

  void internal_free_node2(pnode_type node);

  void swap(self_type&);

 public:
  pnode_type m_head;

 #ifdef _TEST_STRUCTURE_TREE
  size_t get_alloc_count() const {return m_alloc_count;}
 #endif //_TEST_STRUCTURE_TREE

 private:
  allocator_type m_alloc;

  size_t m_alloc_count;
};//class t_tree_base

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/tree/t_tree_base.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
