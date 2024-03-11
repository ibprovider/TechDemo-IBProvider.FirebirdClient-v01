////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tree_base_CC_
#define _t_tree_base_CC_

#include <structure/t_memory.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_tree_base

template<class TNode,class Allocator>
t_tree_base<TNode,Allocator>::t_tree_base()
 :m_head        (nullptr)
 ,m_alloc_count (0)
{;}

//------------------------------------------------------------------------
template<class TNode,class Allocator>
t_tree_base<TNode,Allocator>::~t_tree_base()
{
 this->clear();

 assert_msg(m_alloc_count==0,"m_alloc_count=="<<m_alloc_count);

 assert(m_head==nullptr);
}//~t_tree_base

//------------------------------------------------------------------------
template<class TNode,class Allocator>
void t_tree_base<TNode,Allocator>::init_as_copy(const self_type& tree)
{
 assert(this!=&tree);
 assert(this->empty());

 if(tree.empty())
  return;

 this->reserve(tree.size());

#ifndef NDEBUG
 size_type debug__node_count=1;
#endif

 m_head = this->internal_alloc_node__from_node(pnode_type(),*tree.m_head);

 pnode_type from_node = tree.m_head;
 pnode_type to_node   = m_head;

 while(from_node)
 {
  assert(from_node);

  while(from_node->m_left)
  {
   from_node = from_node->m_left;

   assert(from_node);
   assert(to_node);
   assert(to_node->m_left==nullptr);

   assert(this->size()<this->capacity());

   to_node->m_left = this->internal_alloc_node__from_node(to_node,*from_node);

   assert(to_node->m_left!=nullptr);
   assert(to_node->m_left->m_parent==to_node);

   DEBUG_CODE(++debug__node_count;)

   to_node=to_node->m_left;
  }//while left

  if(from_node->m_right)
  {
   from_node=from_node->m_right;

   assert(from_node);
   assert(to_node);
   assert(to_node->m_right==nullptr);

   assert(this->size()<this->capacity());

   to_node->m_right = this->internal_alloc_node__from_node(to_node,*from_node);

   assert(to_node->m_right!=nullptr);
   assert(to_node->m_right->m_parent==to_node);

   DEBUG_CODE(++debug__node_count;)

   to_node=to_node->m_right;

   continue;
  }//if right

  //раскрутка вверх
  for(;;)
  {
   pnode_type const old_from_node(from_node);

   assert(from_node);

   from_node=from_node->m_parent;

   assert(to_node);

   to_node=to_node->m_parent;

   if(!from_node)
   {
    //типа выскочили за начальный элемент просматриваемого дерева

    assert(!to_node);

    break;
   }//if

   assert(from_node);

   //пришли слева            и   есть правый элемент
   if(old_from_node == from_node->m_left && from_node->m_right)
   {
    from_node=from_node->m_right;//переходим на правый элемент

    assert(from_node);
    assert(to_node);
    assert(to_node->m_right==nullptr);

    assert(this->size()<this->capacity());

    to_node->m_right = this->internal_alloc_node__from_node(to_node,*from_node);

    assert(to_node->m_right!=nullptr);
    assert(to_node->m_right->m_parent==to_node);

    DEBUG_CODE(++debug__node_count;)

    to_node=to_node->m_right;

    break;
   }//пришли справа

  }//for[ever]

 }//while(from_node!=NULL)

 assert(debug__node_count==tree.size());
 assert(debug__node_count==this->size());
}//init_as_copy

//------------------------------------------------------------------------
template<class TNode,class Allocator>
void t_tree_base<TNode,Allocator>::clear()
{
 if(!m_head)
  return;

 assert(!m_head->m_parent);

 pnode_type cur_node=m_head;

 for(;;)
 {
  //tree is still alive
  assert(m_head);

  for(;;)
  {
   while(cur_node->m_left)
   {
    cur_node=cur_node->m_left;
   }

   assert(cur_node);

   if(!cur_node->m_right)
    break;

   cur_node = cur_node->m_right;
  }//for[ever]

  pnode_type const remove_node=cur_node;

  cur_node=cur_node->m_parent;

  if(!cur_node)
  {
   assert(remove_node==m_head);

   m_head=nullptr;

   this->internal_free_node2(remove_node);

   assert(!m_head);

   return;
  }//if !cur_node

  assert(cur_node);

  assert(remove_node!=m_head);

  if(cur_node->m_left==remove_node)
  {
   cur_node->m_left=pnode_type();
  }
  else
  {
   assert(cur_node->m_right==remove_node);

   cur_node->m_right=pnode_type();
  }//else

  assert(m_head!=remove_node);

  this->internal_free_node2(remove_node);
 }//for[ever]
}//clear

//------------------------------------------------------------------------
template<class TNode,class Allocator>
RELEASE_CODE(inline)
bool t_tree_base<TNode,Allocator>::empty()const
{
 return this->size()==0;
}//empty

//------------------------------------------------------------------------
template<class TNode,class Allocator>
RELEASE_CODE(inline)
typename t_tree_base<TNode,Allocator>::size_type
 t_tree_base<TNode,Allocator>::size()const
{
#ifndef NDEBUG
 if(m_head==nullptr)
 {
  assert(m_alloc_count==0);
 }
 else
 {
  assert(m_alloc_count>0);
 }//else
#endif //NDEBUG

 return m_alloc_count;
}//size

//------------------------------------------------------------------------
template<class TNode,class Allocator>
RELEASE_CODE(inline)
typename t_tree_base<TNode,Allocator>::size_type
 t_tree_base<TNode,Allocator>::capacity()const
{
 return this->size()+m_alloc.free_space_capacity();
}//capacity

//------------------------------------------------------------------------
template<class TNode,class Allocator>
void t_tree_base<TNode,Allocator>::reserve(size_type const n)
{
 const size_type s=this->size(); //ignore m_alloc.free_space_capacity()

 if(s<n)
  m_alloc.reserve_free_space(n-s);

 assert(n<=this->capacity());
}//reserve

//------------------------------------------------------------------------
template<class TNode,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
typename t_tree_base<TNode,Allocator>::pnode_type
t_tree_base<TNode,Allocator>::internal_alloc_node__from_value(pnode_type const parent,
                                                              const U&         x)
#else
typename t_tree_base<TNode,Allocator>::pnode_type
t_tree_base<TNode,Allocator>::internal_alloc_node__from_value(pnode_type const  parent,
                                                              const value_type& x)
#endif
{
 node_type* const p=m_alloc.allocate_item();

 try
 {
  new(p) node_type(parent,node_type::tag_from_value(),x); //throw
 }
 catch(...)
 {
  m_alloc.deallocate_item(p);
  throw;
 }

 ++m_alloc_count;

 return p;
}//internal_alloc_node__from_value

//------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class TNode,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
typename t_tree_base<TNode,Allocator>::pnode_type
t_tree_base<TNode,Allocator>::internal_alloc_node__from_value(pnode_type const parent,
                                                              U&&              rrx)
{
 typedef U rrx_type;

#else
typename t_tree_base<TNode,Allocator>::pnode_type
t_tree_base<TNode,Allocator>::internal_alloc_node__from_value(pnode_type const parent,
                                                              value_type&&     rrx)
{
 typedef value_type rrx_type;

#endif
 node_type* const p=m_alloc.allocate_item();

 try
 {
  new(p) node_type(parent,
                   node_type::tag_from_value(),
                   LCPI_STL_FORWARD_VALUE(rrx_type,rrx)); //no-throw
 }
 catch(...)
 {
  m_alloc.deallocate_item(p);
  throw;
 }

 ++m_alloc_count;

 return p;
}//internal_alloc_node__from_value

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------
template<class TNode,class Allocator>
typename t_tree_base<TNode,Allocator>::pnode_type
t_tree_base<TNode,Allocator>::internal_alloc_node__from_node(pnode_type const parent,
                                                             const node_type& x)
{
 node_type* const p=m_alloc.allocate_item();

 try
 {
  new(p) node_type(parent,node_type::tag_from_node(),x); //throw
 }
 catch(...)
 {
  m_alloc.deallocate_item(p);
  throw;
 }

 ++m_alloc_count;

 return p;
}//internal_alloc_node__from_node

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)

template<class TNode,class Allocator>
template<class... Args>
typename t_tree_base<TNode,Allocator>::pnode_type
t_tree_base<TNode,Allocator>::internal_alloc_node__emplace(pnode_type parent,
                                                           Args&&...  args)
{
 node_type* const p=m_alloc.allocate_item();

 try
 {
  new(p) node_type(parent,
                   node_type::tag_from_emplace(),
                   LCPI_STL_FORWARD_VALUE(Args,args)...); //throw
 }
 catch(...)
 {
  m_alloc.deallocate_item(p);
  throw;
 }

 ++m_alloc_count;

 return p;
}//internal_alloc_node__emplace

#endif // COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0

//------------------------------------------------------------------------
template<class TNode,class Allocator>
void t_tree_base<TNode,Allocator>::internal_free_node2(pnode_type const node)
{
 assert(node);
 assert(!node->m_right);
 assert(!node->m_left);

 assert(m_alloc_count>0);

 structure::__generic_destroy(node);

 --m_alloc_count;

 m_alloc.deallocate_item(node);
}//internal_free_node2

//------------------------------------------------------------------------
template<class TNode,class Allocator>
void t_tree_base<TNode,Allocator>::swap(self_type& x)
{
 m_alloc.swap(x.m_alloc);

 std::swap(m_head,x.m_head);

 std::swap(m_alloc_count,x.m_alloc_count);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#endif
