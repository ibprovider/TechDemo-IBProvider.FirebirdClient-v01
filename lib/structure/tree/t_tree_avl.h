////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_avl_H_
#define _t_tree_avl_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/tree/t_tree_avl_base.h>
#include <structure/tree/t_tree_iterators.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

//Allocator - use structure::t_mem_cluster_allocator !

template<class T,class Compare,class Allocator>
class t_tree_avl;

////////////////////////////////////////////////////////////////////////////////
//class t_tree_avl

template<class T,class Compare,class Allocator>
class t_tree_avl LCPI_CPP_CFG__CLASS__FINAL
 :private t_tree_avl_base<T,Compare,Allocator>
{
 private:
  typedef t_tree_avl<T,Compare,Allocator>             self_type;
  typedef t_tree_avl_base<T,Compare,Allocator>        inherited;

 public:
  typedef typename inherited::value_type              value_type;
  typedef typename inherited::node_type               node_type;
  typedef typename inherited::size_type               size_type;
  typedef typename inherited::value_compare           value_compare;

  typedef t_tree_iterator<self_type>                  iterator;
  typedef t_tree_const_iterator<self_type>            const_iterator;
  typedef Allocator                                   allocator_type;
  typedef std::pair<iterator,bool>                    pair_type;

 public: // constructors ---------------------------------------------
  t_tree_avl();

  t_tree_avl(const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_tree_avl(self_type&& x);
 #endif

  explicit t_tree_avl(const value_compare&);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class ForwardIterator>
  t_tree_avl(ForwardIterator first,ForwardIterator last);
 #else
  t_tree_avl(const_iterator first,const_iterator last);
 #endif

  self_type& operator = (const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif

  //selectors ------------------------------------------------------------
  iterator begin();
  iterator end();

  const_iterator begin()const;
  const_iterator end()const;

  const_iterator cbegin()const;
  const_iterator cend()const;

  template<class U>
  iterator find(const U&);

  template<class U>
  const_iterator find(const U&)const;

  template<class U>
  iterator find_within(iterator top,const U&);

  template<class U>
  const_iterator find_within(const_iterator top,const U&)const;

  template<class U>
  iterator lower_bound(const U&);

  template<class U>
  const_iterator lower_bound(const U&)const;

  //modificators ---------------------------------------------------------
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  pair_type insert(const U&);
 #else
  pair_type insert(const value_type&);
 #endif

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE)
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  pair_type insert(U&&);
 #else
  pair_type insert(value_type&&);
 #endif
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class InputIterator>
  size_type insert(InputIterator first,InputIterator last);
 #else
  size_type insert(const_iterator first,const_iterator last);
 #endif

 #if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)
  template<class... Args>
  pair_type emplace(Args&&... args);
 #endif

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  bool erase(const U&);
 #else
  bool erase(const value_type&);
 #endif

  void erase(iterator);

  COMP_W000003_USING inherited::clear;

  void swap(self_type&);

  value_compare value_comp()const;

  COMP_W000003_USING inherited::empty;
  COMP_W000003_USING inherited::size;
  COMP_W000003_USING inherited::capacity;
  COMP_W000003_USING inherited::reserve;

  #ifdef _TEST_STRUCTURE_TREE
  COMP_W000003_USING inherited::get_alloc_count;
 #endif

 public:
  const node_type* head()const;

 private:
  friend iterator;

  node_type* head();

 private:
  using inherited::m_cmp;
  using inherited::m_head;
};//class t_tree_avl

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/tree/t_tree_avl.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
