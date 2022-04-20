////////////////////////////////////////////////////////////////////////////////
//Base class of AVL trees.
//                                                 Kovalenko Dmitry. 09.02.2017.
#ifndef _t_tree_avl_base_H_
#define _t_tree_avl_base_H_

#include <structure/tree/t_tree_base.h>
#include <structure/tree/t_tree_avl_node.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_tree_avl_base

template<class T,class Compare,class Allocator>
class t_tree_avl_base:public t_tree_base<t_tree_avl_node<T>,Allocator>
{
 private:
  typedef t_tree_avl_base<T,Compare,Allocator>        self_type;
  typedef t_tree_base<t_tree_avl_node<T>,Allocator>   inherited;

  self_type& operator = (const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&&);
 #endif

 public: //typedefs ------------------------------------------------------
  typedef typename inherited::value_type              value_type;
  typedef typename inherited::node_type               node_type;
  typedef typename inherited::pnode_type              pnode_type;
  typedef typename inherited::size_type               size_type;

  typedef Compare                                     value_compare;

  typedef std::pair<node_type*,bool>                  pair_type;

 public:
  using inherited::m_head;

  value_compare m_cmp;

 public:
  t_tree_avl_base();

  t_tree_avl_base(const self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_tree_avl_base(self_type&&);
 #endif

  explicit t_tree_avl_base(const value_compare& cmp);

  void swap(self_type&);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  void assign_rv(self_type&& x);
 #endif

 public:
  template<class U>
  const node_type* find_node(const U&)const;

  template<class U>
  node_type* find_node(const U&);

  template<class U>
  const node_type* find_node_within(const node_type* top, const U&)const;

  template<class U>
  node_type* find_node_within(node_type* top, const U&);

  //modificators ---------------------------------------------------------
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  pair_type insert_node(const U&);
 #else
  pair_type insert_node(const value_type&);
 #endif

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE)
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  pair_type insert_node(U&&);
 #else
  pair_type insert_node(value_type&&);
 #endif
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE

 #if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)
  template<class... Args>
  pair_type emplace_node(Args&&...);
 #endif

  void erase_node(node_type*);

 public:
  void shift_left(node_type*);

  void shift_right(node_type*);

  void double_shift_left(node_type*);

  void double_shift_right(node_type*);

  void update_tree_balance(node_type*);

 public:
  static int get_left_balance(const node_type* node);

  static int get_right_balance(const node_type* node);

  static int count_node_balance(const node_type* node);

 private:
  template<class TREE,typename NODE,class U>
  static NODE* helper__find_node_within(TREE* pThis, NODE*, const U&);
};//class t_tree_avl_base

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/tree/t_tree_avl_base.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
