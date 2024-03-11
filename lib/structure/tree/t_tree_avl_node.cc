////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_avl_node_CC_
#define _t_tree_avl_node_CC_

#include <structure/tree/t_tree_avl_node.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template class t_tree_avl_node

template<class T>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
t_tree_avl_node<T>::t_tree_avl_node(self_type*     const parent,
                                    tag_from_value const /*from_sign*/,
                                    const U&             key)
#else
t_tree_avl_node<T>::t_tree_avl_node(self_type*     const parent,
                                    tag_from_value const /*from_sign*/,
                                    const value_type&    key)
#endif
 :m_right   (nullptr)
 ,m_left    (nullptr)
 ,m_parent  (parent)
 ,m_key     (key)
 ,m_balance (0)
{;}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)

template<class T>
template<class U>
t_tree_avl_node<T>::t_tree_avl_node(self_type*     const parent,
                                    tag_from_value const /*from_sign*/,
                                    U&&                  key)
 :m_right   (nullptr)
 ,m_left    (nullptr)
 ,m_parent  (parent)
 ,m_key     (LCPI_STL_FORWARD_VALUE(U,key))
 ,m_balance (0)
{
}

#else // !COMP_CONF_SUPPORT_MEMBER_TEMPLATE

template<class T>
t_tree_avl_node<T>::t_tree_avl_node(self_type*     const parent,
                                    tag_from_value const /*from_sign*/,
                                    value_type&&         key)
 :m_right   (nullptr)
 ,m_left    (nullptr)
 ,m_parent  (parent)
 ,m_key     (LCPI_STL_MOVE_VALUE(key))
 ,m_balance (0)
{
}

#endif // !COMP_CONF_SUPPORT_MEMBER_TEMPLATE

#endif // COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T>
t_tree_avl_node<T>::t_tree_avl_node(self_type*    const parent,
                                    tag_from_node const /*from_sign*/,
                                    const self_type&    node)
 :m_right   (nullptr)
 ,m_left    (nullptr)
 ,m_parent  (parent)
 ,m_key     (node.m_key)
 ,m_balance (node.m_balance)
{
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)

template<class T>
template<class... Args>
t_tree_avl_node<T>::t_tree_avl_node(self_type*       const parent,
                                    tag_from_emplace const /*from_sign*/,
                                    Args&&...              args)
 :m_right   (nullptr)
 ,m_left    (nullptr)
 ,m_parent  (parent)
 ,m_key     (LCPI_STL_FORWARD_VALUE(Args,args)...)
 ,m_balance (0)
{
}//t_tree_avl_node

#endif // COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0

//------------------------------------------------------------------------
template<class T>
t_tree_avl_node<T>::~t_tree_avl_node()
{
}

//-----------------------------------------------------------------------
#ifndef NDEBUG

template<class T>
const t_tree_avl_node<T>* t_tree_avl_node<T>::debug__get_tree_head()const
{
 const self_type* cur_node=this;

 for(;cur_node->m_parent!=nullptr;cur_node=cur_node->m_parent);

 return cur_node;
}//debug__get_tree_head

#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
