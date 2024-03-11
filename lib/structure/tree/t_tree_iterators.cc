////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_iterators_CC_
#define _t_tree_iterators_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_tree_iterator

template<class TTree>
RELEASE_CODE(inline)
t_tree_iterator<TTree>::t_tree_iterator()
 :m_tree(nullptr)
 ,m_cur_node(nullptr)
{
}

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_iterator<TTree>::t_tree_iterator(ptree_type const tree,
                                        pnode_type const cur_node)
 :m_tree(tree)
 ,m_cur_node(cur_node)
{
}

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_iterator<TTree>::t_tree_iterator(const self_type& it)
 :m_tree(it.m_tree)
 ,m_cur_node(it.m_cur_node)
{
}

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_iterator<TTree>& t_tree_iterator<TTree>::operator = (const self_type& it)
{
 m_tree      = it.m_tree;
 m_cur_node  = it.m_cur_node;

 return *this;
}//operator = copy

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_iterator<TTree>::operator == (const self_type& it)const
{
 assert(m_tree == it.get_tree());

 return m_cur_node == it.m_cur_node;
}//operator==

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_iterator<TTree>::operator != (const self_type& it)const
{
 return !((*this) == it);
}//operator !=

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_iterator<TTree>::operator == (const r_iterator_type& it)const
{
 assert(m_tree == it.get_tree());

 return m_cur_node == it.get_current();
}//operator==

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_iterator<TTree>::operator != (const r_iterator_type& it)const
{
 return !((*this) == it);
}//operator !=

//------------------------------------------------------------------------
template<class TTree>
t_tree_iterator<TTree>& t_tree_iterator<TTree>::operator ++ ()
{
 assert(m_tree);

 m_cur_node=tree_iterator_forward3(m_tree->head(),m_cur_node);

 return *this;
}//++()

//------------------------------------------------------------------------
template<class TTree>
t_tree_iterator<TTree> t_tree_iterator<TTree>::operator ++ (int)
{
 const self_type tmp(*this);

 ++(*this);

 return tmp;
}//++(int)

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
typename t_tree_iterator<TTree>::reference
 t_tree_iterator<TTree>::operator * ()const
{
 assert(m_tree);
 assert(m_cur_node);

 return m_cur_node->m_key;
}//operator*

//------------------------------------------------------------------------
template<class TTree>
t_tree_iterator<TTree>& t_tree_iterator<TTree>::operator -- ()
{
 assert(m_tree);

 m_cur_node=tree_iterator_back3(m_tree->head(),m_cur_node);

 return *this;
}//--()

//------------------------------------------------------------------------
template<class TTree>
t_tree_iterator<TTree> t_tree_iterator<TTree>::operator -- (int)
{
 const self_type tmp(*this);

 --(*this);

 return tmp;
}//--(int)

//-----------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
typename t_tree_iterator<TTree>::ptree_type
 t_tree_iterator<TTree>::get_tree()const
{
 return m_tree;
}//get_tree

//-----------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
typename t_tree_iterator<TTree>::pnode_type
 t_tree_iterator<TTree>::get_current()const
{
 return m_cur_node;
}//get_current

////////////////////////////////////////////////////////////////////////////////
//class t_tree_const_iterator

template<class TTree>
RELEASE_CODE(inline)
t_tree_const_iterator<TTree>::t_tree_const_iterator()
 :m_tree(nullptr)
 ,m_cur_node(nullptr)
{
}

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_const_iterator<TTree>::t_tree_const_iterator(ptree_type const tree,
                                                    pnode_type const cur_node)
 :m_tree(tree)
 ,m_cur_node(cur_node)
{
 assert(m_tree);
}

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_const_iterator<TTree>::t_tree_const_iterator(const self_type& it)
 :m_tree(it.m_tree)
 ,m_cur_node(it.m_cur_node)
{
}

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_const_iterator<TTree>::t_tree_const_iterator(const rw_iterator_type& it)
 :m_tree(it.get_tree())
 ,m_cur_node(it.get_current())
{
}

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_const_iterator<TTree>&
 t_tree_const_iterator<TTree>::operator = (const self_type& it)
{
 m_tree      = it.m_tree;
 m_cur_node  = it.m_cur_node;

 return *this;
}//operator = copy

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
t_tree_const_iterator<TTree>& t_tree_const_iterator<TTree>::operator =(const rw_iterator_type& it)
{
 m_tree      = it.get_tree();
 m_cur_node  = it.get_current();

 return *this;
}//operator =

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_const_iterator<TTree>::operator == (const self_type& it)const
{
 assert(m_tree == it.m_tree);

 return (m_cur_node == it.m_cur_node);
}//operator==

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_const_iterator<TTree>::operator != (const self_type& it)const
{
 return !((*this) == it);
}//operator !=

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_const_iterator<TTree>::operator == (const rw_iterator_type& it)const
{
 assert(m_tree == it.get_tree());

 return (m_cur_node == it.get_current());
}//operator==

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
bool t_tree_const_iterator<TTree>::operator != (const rw_iterator_type& it)const
{
 return !((*this) == it);
}//operator !=

//------------------------------------------------------------------------
template<class TTree>
t_tree_const_iterator<TTree>& t_tree_const_iterator<TTree>::operator ++ ()
{
 assert(m_tree);

 m_cur_node=tree_iterator_forward3(m_tree->head(),m_cur_node);

 return *this;
}//++()

//------------------------------------------------------------------------
template<class TTree>
t_tree_const_iterator<TTree> t_tree_const_iterator<TTree>::operator ++ (int)
{
 const self_type tmp(*this);

 ++(*this);

 return tmp;
}//++(int)

//------------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
typename t_tree_const_iterator<TTree>::reference
 t_tree_const_iterator<TTree>::operator * ()const
{
 assert(m_tree);
 assert(m_cur_node);

 return m_cur_node->m_key;
}//operator *

//------------------------------------------------------------------------
template<class TTree>
t_tree_const_iterator<TTree>& t_tree_const_iterator<TTree>::operator -- ()
{
 assert(m_tree);

 m_cur_node=tree_iterator_back3(m_tree->head(),m_cur_node);

 return *this;
}//--()

//------------------------------------------------------------------------
template<class TTree>
t_tree_const_iterator<TTree> t_tree_const_iterator<TTree>::operator -- (int)
{
 const self_type tmp(*this);

 --(*this);

 return tmp;
}//--(int)

//-----------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
typename t_tree_const_iterator<TTree>::ptree_type
 t_tree_const_iterator<TTree>::get_tree()const
{
 return m_tree;
}//get_tree

//-----------------------------------------------------------------------
template<class TTree>
RELEASE_CODE(inline)
typename t_tree_const_iterator<TTree>::pnode_type
 t_tree_const_iterator<TTree>::get_current()const
{
 return m_cur_node;
}//get_current

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#endif
