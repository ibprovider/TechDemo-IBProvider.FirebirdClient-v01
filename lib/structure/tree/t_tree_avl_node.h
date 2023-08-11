////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_avl_node_H_
#define _t_tree_avl_node_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class T>
class t_tree_avl_node;

////////////////////////////////////////////////////////////////////////////////
//class t_tree_avl_node

template<class T>
class t_tree_avl_node LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef t_tree_avl_node<T>                   self_type;

  t_tree_avl_node(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef T                                    value_type;

  class tag_from_value{};
  class tag_from_node{};
  class tag_from_emplace{};

 public:
  self_type*   m_right;
  self_type*   m_left;
  self_type*   m_parent;
  value_type   m_key;
  int          m_balance; //by fact - it is tree height!

 public:
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  t_tree_avl_node(self_type*        parent,
                  tag_from_value    from_sign,
                  const U&          key);
 #else
  t_tree_avl_node(self_type*        parent,
                  tag_from_value    from_sign,
                  const value_type& key);
 #endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class U>
  t_tree_avl_node(self_type*        parent,
                  tag_from_value    from_sign,
                  U&&               key);
 #else
  t_tree_avl_node(self_type*        parent,
                  tag_from_value    from_sign,
                  value_type&&      key);
 #endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE
 #endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

  t_tree_avl_node(self_type*        parent,
                  tag_from_node     from_sign,
                  const self_type&  node);

 #if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)
  template<class... Args>
  t_tree_avl_node(self_type*        parent,
                  tag_from_emplace  from_sign,
                  Args&&...         args);
 #endif

 ~t_tree_avl_node();

#ifndef NDEBUG
  const self_type* debug__get_tree_head()const;
#endif
};//t_tree_avl_node

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/tree/t_tree_avl_node.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
