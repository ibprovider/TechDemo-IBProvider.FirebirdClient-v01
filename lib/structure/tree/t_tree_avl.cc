////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_avl_CC_
#define _t_tree_avl_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_tree_avl

template<class T,class Compare,class Allocator>
inline t_tree_avl<T,Compare,Allocator>::t_tree_avl()
{;}

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
t_tree_avl<T,Compare,Allocator>::t_tree_avl(const self_type& tree)
 :inherited(tree)
{
}//t_tree_avl copy

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T,class Compare,class Allocator>
t_tree_avl<T,Compare,Allocator>::t_tree_avl(self_type&& x)
 :inherited(__STL_MOVE_VALUE(x))
{
}//t_tree_avl move

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
t_tree_avl<T,Compare,Allocator>::t_tree_avl(const value_compare &cmp)
 :inherited(cmp)
{;}

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
 template<class ForwardIterator>
 t_tree_avl<T,Compare,Allocator>::t_tree_avl(ForwardIterator first,ForwardIterator last)
#else
 t_tree_avl<T,Compare,Allocator>::t_tree_avl(const_iterator first,const_iterator last)
#endif
{
 for(;first!=last;++first)
 {
  this->insert(*first);
 }
}//t_tree_avl (first,last)

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::self_type&
t_tree_avl<T,Compare,Allocator>::operator = (const self_type& tree)
{
 self_type tmp(tree);

 this->swap(tmp);

 return *this;
}//copy operator

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T,class Compare,class Allocator>
t_tree_avl<T,Compare,Allocator>&
 t_tree_avl<T,Compare,Allocator>::operator = (self_type&& x)
{
 this->assign_rv(__STL_MOVE_VALUE(x));

 return *this;
}//move operator

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//selectors --------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::iterator
t_tree_avl<T,Compare,Allocator>::begin()
{
 node_type* left=m_head;

 if(left)
 {
  while(left->m_left)
   left=left->m_left;
 }//while

 return iterator(this,left);
}//begin

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::iterator
t_tree_avl<T,Compare,Allocator>::end()
{
 return iterator(this,nullptr);
}//end

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::const_iterator
t_tree_avl<T,Compare,Allocator>::begin()const
{
 const node_type* left=m_head;

 if(left)
 {
  while(left->m_left)
   left=left->m_left;
 }//while

 return const_iterator(this,left);
}//begin

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::const_iterator
t_tree_avl<T,Compare,Allocator>::end()const
{
 return const_iterator(this,nullptr);
}//end

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::const_iterator
t_tree_avl<T,Compare,Allocator>::cbegin()const
{
 return const_cast<const self_type*>(this)->begin();
}//cbegin

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::const_iterator
t_tree_avl<T,Compare,Allocator>::cend()const
{
 return const_cast<const self_type*>(this)->end();
}//cend

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
 template<class U>
 inline
 typename t_tree_avl<T,Compare,Allocator>::iterator
 t_tree_avl<T,Compare,Allocator>::find(const U& value)
{
 return iterator(this,this->find_node(value));
}//find

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
 template<class U>
 inline
 typename t_tree_avl<T,Compare,Allocator>::const_iterator
 t_tree_avl<T,Compare,Allocator>::find(const U& value)const
{
 return const_iterator(this,this->find_node(value));
}//find

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
 template<class U>
 inline
 typename t_tree_avl<T,Compare,Allocator>::iterator
 t_tree_avl<T,Compare,Allocator>::find_within(iterator const top,const U& value)
{
 assert(top.get_tree()==this);
 assert(top.get_current());
 assert(top.get_current()->debug__get_tree_head()==m_head);

 return iterator(this,this->find_node_within(top.get_current(),value));
}//find

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
 template<class U>
 inline
 typename t_tree_avl<T,Compare,Allocator>::const_iterator
 t_tree_avl<T,Compare,Allocator>::find_within(const_iterator const top,const U& value)const
{
 assert(top.get_tree()==this);
 assert(top.get_current());
 assert(top.get_current()->debug__get_tree_head()==m_head);

 return const_iterator(this,this->find_node_within(top.get_current(),value));
}//find

//modifictors ------------------------------------------------------------
template<class T,class Compare,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
typename t_tree_avl<T,Compare,Allocator>::pair_type
 t_tree_avl<T,Compare,Allocator>::insert(const U& value)
#else
typename t_tree_avl<T,Compare,Allocator>::pair_type
 t_tree_avl<T,Compare,Allocator>::insert(const value_type& value)
#endif
{
 const inherited::pair_type r=this->insert_node(value);

 assert(r.first);

 return pair_type(iterator(this,r.first),r.second);
}//insert

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE)

template<class T,class Compare,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
typename t_tree_avl<T,Compare,Allocator>::pair_type
 t_tree_avl<T,Compare,Allocator>::insert(U&& rrvalue)
{
 typedef U insert_value_type;

#else
typename t_tree_avl<T,Compare,Allocator>::pair_type
 t_tree_avl<T,Compare,Allocator>::insert(value_type&& rrvalue)
{
 typedef value_type insert_value_type;

#endif

 const inherited::pair_type r
  =this->insert_node(__STL_FORWARD_VALUE(insert_value_type,rrvalue));

 assert(r.first);

 return pair_type(iterator(this,r.first),r.second);
}//insert

#endif // COMP_CONF_SUPPORT_RVALUE_REFERENCE

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class InputIterator>
typename t_tree_avl<T,Compare,Allocator>::size_type
 t_tree_avl<T,Compare,Allocator>::insert(InputIterator       first,
                                         InputIterator const last)
#else
typename t_tree_avl<T,Compare,Allocator>::size_type
 t_tree_avl<T,Compare,Allocator>::insert(const_iterator       first,
                                         const_iterator const last)
#endif
{
 size_type n=0;

 for(;first!=last;++first)
 {
  if(this->insert(*first).second)
   ++n;
 }//for

 return n;
}//insert range

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)

template<class T,class Compare,class Allocator>
template<class... Args>
typename t_tree_avl<T,Compare,Allocator>::pair_type
 t_tree_avl<T,Compare,Allocator>::emplace(Args&&... args)
{
 const inherited::pair_type r
  =this->emplace_node(__STL_FORWARD_VALUE(Args,args)...);

 assert(r.first);

 return pair_type(iterator(this,r.first),r.second);
}//emplace

#endif // COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
 bool t_tree_avl<T,Compare,Allocator>::erase(const U& value)
#else
template<class T,class Compare,class Allocator>
 bool t_tree_avl<T,Compare,Allocator>::erase(const value_type& value)
#endif
{
 iterator const find_it(this->find(value));

 if(find_it.get_current())
 {
  this->erase_node(find_it.get_current());

  return true;
 }

 return false;
}//erase

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
RELEASE_CODE(inline)
void t_tree_avl<T,Compare,Allocator>::erase(iterator it)
{
 assert(it.get_tree()==this);
 assert(it.get_current());
 assert(it.get_current()->debug__get_tree_head()==m_head);

 this->erase_node(it.get_current());
}//erase

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
inline void t_tree_avl<T,Compare,Allocator>::swap(self_type& x)
{
 inherited::swap(x);
}//swap

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::value_compare
t_tree_avl<T,Compare,Allocator>::value_comp()const
{
 return m_cmp;
}//value_comp

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
const typename t_tree_avl<T,Compare,Allocator>::node_type*
t_tree_avl<T,Compare,Allocator>::head()const
{
 return m_head;
}//head

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
typename t_tree_avl<T,Compare,Allocator>::node_type*
t_tree_avl<T,Compare,Allocator>::head()
{
 return m_head;
}//head

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
