////////////////////////////////////////////////////////////////////////////////
//Base class of AVL trees.
//                                                 Kovalenko Dmitry. 09.02.2017.
#ifndef _t_tree_avl_base_CC_
#define _t_tree_avl_base_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_tree_avl_base

template<class T,class Compare,class Allocator>
t_tree_avl_base<T,Compare,Allocator>::t_tree_avl_base()
{
}

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
t_tree_avl_base<T,Compare,Allocator>::t_tree_avl_base(const self_type& x)
 :m_cmp(x.m_cmp)
{
 this->init_as_copy(x);
}

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
t_tree_avl_base<T,Compare,Allocator>::t_tree_avl_base(const value_compare& cmp)
 :m_cmp(cmp)
{
}

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T,class Compare,class Allocator>
t_tree_avl_base<T,Compare,Allocator>::t_tree_avl_base(self_type&& x)
{
 this->assign_rv(LCPI_STL_MOVE_VALUE(x));
}//t_tree_avl move

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
inline void t_tree_avl_base<T,Compare,Allocator>::swap(self_type& x)
{
 std::swap(m_cmp,x.m_cmp);

 inherited::swap(x);
}//swap

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

template<class T,class Compare,class Allocator>
RELEASE_CODE(inline)
void t_tree_avl_base<T,Compare,Allocator>::assign_rv(self_type&& x)
{
 if(this==&x)
  return;

 this->clear();

 this->swap(x);
}//assign_rv

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class U>
const typename t_tree_avl_base<T,Compare,Allocator>::node_type*
 t_tree_avl_base<T,Compare,Allocator>::find_node(const U& value)const
{
 return this->helper__find_node_within(this,m_head,value);
}//find_node - const

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class U>
typename t_tree_avl_base<T,Compare,Allocator>::node_type*
 t_tree_avl_base<T,Compare,Allocator>::find_node(const U& value)
{
 return this->helper__find_node_within(this,m_head,value);
}//find_node

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class U>
const typename t_tree_avl_base<T,Compare,Allocator>::node_type*
 t_tree_avl_base<T,Compare,Allocator>::find_node_within(const node_type* const top,const U& value)const
{
 assert(top);
 assert(m_head);
 assert(m_head==top->debug__get_tree_head());

 return this->helper__find_node_within(this,top,value);
}//find_node_within - const

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class U>
typename t_tree_avl_base<T,Compare,Allocator>::node_type*
 t_tree_avl_base<T,Compare,Allocator>::find_node_within(node_type* const top,const U& value)
{
 assert(top);
 assert(m_head);
 assert(m_head==top->debug__get_tree_head());

 return this->helper__find_node_within(this,top,value);
}//find_node_within

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class U>
const typename t_tree_avl_base<T,Compare,Allocator>::node_type*
 t_tree_avl_base<T,Compare,Allocator>::lower_bound_node(const U& value)const
{
 return this->helper__lower_bound_node(this,value);
}//lower_bound_node - const

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class U>
typename t_tree_avl_base<T,Compare,Allocator>::node_type*
 t_tree_avl_base<T,Compare,Allocator>::lower_bound_node(const U& value)
{
 return this->helper__lower_bound_node(this,value);
}//lower_bound_node

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class TREE,typename NODE,class U>
NODE*
 t_tree_avl_base<T,Compare,Allocator>::helper__find_node_within(TREE* const pThis,
                                                                NODE* const pTop,
                                                                const U&    value)
{
 assert(pThis);

 for(NODE* cur_node=pTop;cur_node;)
 {
  if(pThis->m_cmp(cur_node->m_key,value))
  {
   cur_node = cur_node->m_right;
  }
  else
  if(pThis->m_cmp(value,cur_node->m_key))
  {
   cur_node = cur_node->m_left;
  }
  else
  {
   return cur_node;
  }
 }//while

 return nullptr;
}//helper__find_node_within

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
template<class TREE,class U>
typename TREE::node_type*
 t_tree_avl_base<T,Compare,Allocator>::helper__lower_bound_node(TREE* const pThis,
                                                                const U&    value)
{
 assert(pThis);

 typename TREE::node_type* whereNode = nullptr;

 for(auto* cur_node = pThis->m_head; cur_node;)
 {
  if(pThis->m_cmp(cur_node->m_key,value))
  {
   cur_node = cur_node->m_right;
  }
  else
  {
   whereNode = cur_node;

   cur_node = cur_node->m_left;
  }
 }//for cur_node

 return whereNode;
}//helper__lower_bound_node

//modifictors ------------------------------------------------------------
template<class T,class Compare,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
typename t_tree_avl_base<T,Compare,Allocator>::pair_type
 t_tree_avl_base<T,Compare,Allocator>::insert_node(const U& value)
#else
typename t_tree_avl_base<T,Compare,Allocator>::pair_type
 t_tree_avl_base<T,Compare,Allocator>::insert_node(const value_type& value)
#endif
{
 if(!m_head)
 {
  m_head=this->internal_alloc_node__from_value(pnode_type(),value);

  this->update_tree_balance(m_head);

  return pair_type(m_head,true);
 }//if !m_head

 assert(m_head);

 node_type* cur_node=m_head;

 for(;;)
 {
  assert(cur_node);

  if(m_cmp(cur_node->m_key,value)) //cur_node->m_key<value
  {
   //insert to right

   if(!cur_node->m_right)
   {
    node_type* const new_node
     =this->internal_alloc_node__from_value(cur_node,value);

    assert(new_node->m_parent==cur_node);

    cur_node->m_right=new_node;

    this->update_tree_balance(new_node);

    return pair_type(new_node,true);
   }//if

   cur_node=cur_node->m_right;
  }//if
  else
  {
   assert(!m_cmp(cur_node->m_key,value));

   if(/*!m_cmp(cur_node->m_key,value) &&*/ !m_cmp(value,cur_node->m_key))
    return pair_type(cur_node,false);

   if(!cur_node->m_left)
   {
    node_type* const new_node
     =this->internal_alloc_node__from_value(cur_node,value);

    assert(new_node->m_parent==cur_node);

    cur_node->m_left=new_node;

    this->update_tree_balance(new_node);

    return pair_type(new_node,true);
   }//if

   cur_node=cur_node->m_left;
  }//else
 }//for[ever]
}//insert_node

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE)

template<class T,class Compare,class Allocator>
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
template<class U>
typename t_tree_avl_base<T,Compare,Allocator>::pair_type
 t_tree_avl_base<T,Compare,Allocator>::insert_node(U&& rrvalue)
{
 typedef U insert_value_type;

#else
typename t_tree_avl_base<T,Compare,Allocator>::pair_type
 t_tree_avl_base<T,Compare,Allocator>::insert_node(value_type&& rrvalue)
{
 typedef value_type insert_value_type;

#endif
 if(!m_head)
 {
  m_head
   =this->internal_alloc_node__from_value
     (pnode_type(),
      LCPI_STL_FORWARD_VALUE(insert_value_type,rrvalue));

  this->update_tree_balance(m_head);

  return pair_type(m_head,true);
 }//if !m_head

 assert(m_head);

 node_type* cur_node=m_head;

 for(;;)
 {
  assert(cur_node);

  if(m_cmp(cur_node->m_key,rrvalue)) //cur_node->m_key<rrvalue
  {
   //insert to right

   if(!cur_node->m_right)
   {
    node_type* const
     new_node
      =this->internal_alloc_node__from_value
        (cur_node,
         LCPI_STL_FORWARD_VALUE(insert_value_type,rrvalue));

    assert(new_node->m_parent==cur_node);

    cur_node->m_right=new_node;

    this->update_tree_balance(new_node);

    return pair_type(new_node,true);
   }//if !cur_node->m_right

   cur_node=cur_node->m_right;
  }//if
  else
  {
   assert(!m_cmp(cur_node->m_key,rrvalue));

   if(/*!m_cmp(cur_node->m_key,rrvalue) &&*/ !m_cmp(rrvalue,cur_node->m_key))
    return pair_type(cur_node,false);

   if(!cur_node->m_left)
   {
    node_type* const
     new_node
      =this->internal_alloc_node__from_value
        (cur_node,
         LCPI_STL_FORWARD_VALUE(insert_value_type,rrvalue));

    assert(new_node->m_parent==cur_node);

    cur_node->m_left=new_node;

    this->update_tree_balance(new_node);

    return pair_type(new_node,true);
   }//if

   cur_node=cur_node->m_left;
  }//else
 }//for[ever]
}//insert_node

#endif // COMP_CONF_SUPPORT_RVALUE_REFERENCE

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)

template<class T,class Compare,class Allocator>
template<class... Args>
typename t_tree_avl_base<T,Compare,Allocator>::pair_type
 t_tree_avl_base<T,Compare,Allocator>::emplace_node(Args&&... args)
{
 if(!m_head)
 {
  m_head
   =this->internal_alloc_node__emplace
     (pnode_type(),
      LCPI_STL_FORWARD_VALUE(Args,args)...);

  assert(m_head);

  this->update_tree_balance(m_head); //throw?

  return pair_type(m_head,true);
 }//if !m_head

 assert(m_head);

 node_type*
  new_node
   =this->internal_alloc_node__emplace
     (m_head,
      LCPI_STL_FORWARD_VALUE(Args,args)...);

 assert(new_node);

 try // catch
 {
  node_type* cur_node=m_head;

  for(;;)
  {
   assert(cur_node);

   if(m_cmp(cur_node->m_key,new_node->m_key)) //cur_node->m_key<new_node->m_key
   {
    //insert to right

    if(!cur_node->m_right)
    {
     new_node->m_parent=cur_node;

     cur_node->m_right=new_node;

     //----
     auto const r=new_node;

     new_node=nullptr;

     this->update_tree_balance(r); //throw?

     return pair_type(r,true);
    }//if !cur_node->m_right

    cur_node=cur_node->m_right;
   }//if
   else
   {
    assert(!m_cmp(cur_node->m_key,new_node->m_key));

    if(/*!m_cmp(cur_node->m_key,new_node->m_key) &&*/ !m_cmp(new_node->m_key,cur_node->m_key))
    {
     auto const tmp=new_node;

     new_node=nullptr;

     this->internal_free_node2(tmp);

     return pair_type(cur_node,false);
    }//if

    if(!cur_node->m_left)
    {
     new_node->m_parent=cur_node;

     cur_node->m_left=new_node;

     //----
     auto const r=new_node;

     new_node=nullptr;

     this->update_tree_balance(r); //throw?

     return pair_type(r,true);
    }//if

    cur_node=cur_node->m_left;
   }//else
  }//for[ever]
 }
 catch(...)
 {
  if(new_node)
   this->internal_free_node2(new_node);

  throw;
 }//catch
}//emplace_node

#endif // COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
void t_tree_avl_base<T,Compare,Allocator>::erase_node(node_type* const cur_node)
{
 assert(cur_node);

 assert(m_head);
 assert(m_head==cur_node->debug__get_tree_head());

 pnode_type* cur_node_parent_child=nullptr;

 pnode_type const parent_node=cur_node->m_parent;

 if(parent_node==nullptr)
 {
  assert(m_head==cur_node);

  cur_node_parent_child=&m_head;
 }
 else
 if(parent_node->m_left==cur_node)
 {
  cur_node_parent_child=&parent_node->m_left;
 }
 else
 {
  assert(parent_node->m_right==cur_node);

  cur_node_parent_child=&parent_node->m_right;
 }//else

 assert(cur_node_parent_child!=nullptr);

 pnode_type new_cur_node LCPI__DEBUG_CODE(=pnode_type());
 pnode_type update_node  LCPI__DEBUG_CODE(=pnode_type());

 if(cur_node->m_left==nullptr)
 {
  if(cur_node->m_right==nullptr)
  {
   (*cur_node_parent_child)=nullptr;

   this->internal_free_node2(cur_node);

   this->update_tree_balance(parent_node);

   return;
  }//if

  assert(cur_node->m_right!=nullptr);

  new_cur_node=cur_node->m_right;

  update_node=new_cur_node;

  assert(update_node!=nullptr);
 }
 else
 if(!cur_node->m_right)
 {
  assert(cur_node->m_left!=nullptr);

  new_cur_node=cur_node->m_left;

  update_node=new_cur_node;

  assert(update_node!=nullptr);
 }
 else
 {
  assert(cur_node->m_left);
  assert(cur_node->m_right);

  node_type* right_node =cur_node->m_right;
  node_type* left_node  =cur_node->m_left;

  for(;;)
  {
   assert(right_node!=nullptr);
   assert(left_node!=nullptr);

   if(right_node->m_left==nullptr)
   {
    new_cur_node=cur_node->m_right;

    right_node->m_left=cur_node->m_left;

    cur_node->m_left->m_parent= right_node;

    update_node=right_node;

    assert(update_node!=nullptr);

    break;
   }//if

   assert(right_node->m_left!=nullptr);

   if(left_node->m_right==nullptr)
   {
    new_cur_node=cur_node->m_left;

    left_node->m_right=cur_node->m_right;

    cur_node->m_right->m_parent=left_node;

    update_node=left_node;

    assert(update_node!=nullptr);

    break;
   }//if

   assert(left_node->m_right!=nullptr);

   right_node = right_node->m_left;
   left_node  = left_node->m_right;
  }//for[ever]
 }//else

 assert(new_cur_node!=nullptr);
 assert(update_node!=nullptr);
 assert(update_node!=cur_node);

 new_cur_node->m_parent=cur_node->m_parent;

 (*cur_node_parent_child)=new_cur_node;

 cur_node->m_right = nullptr;
 cur_node->m_left  = nullptr;

 this->internal_free_node2(cur_node);

 assert(update_node!=nullptr);

 this->update_tree_balance(update_node);
}//erase_node

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
void t_tree_avl_base<T,Compare,Allocator>::shift_left(node_type* const cur_node)
{
 assert(cur_node);

 assert(cur_node->m_parent);

 assert(cur_node->m_right);

 node_type* const parent_node = cur_node->m_parent;

 assert(parent_node->m_right==cur_node);

 {
  node_type* const parent_parent_node = parent_node->m_parent;

  if(parent_parent_node==nullptr)
  {
   assert(m_head==parent_node);

   m_head=cur_node;
  }
  else
  if(parent_parent_node->m_left==parent_node)
  {
   parent_parent_node->m_left=cur_node;
  }
  else
  {
   assert(parent_parent_node->m_right==parent_node);

   parent_parent_node->m_right=cur_node;
  }

  cur_node->m_parent=parent_parent_node;
 }//local

 parent_node->m_right = cur_node->m_left;

 if(parent_node->m_right)
  parent_node->m_right->m_parent = parent_node;

 cur_node->m_left = parent_node;

 parent_node->m_parent = cur_node;
}//shift_left

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
void t_tree_avl_base<T,Compare,Allocator>::shift_right(node_type* const cur_node)
{
 assert(cur_node);

 assert(cur_node->m_parent);

 assert(cur_node->m_left);

 node_type* const parent_node = cur_node->m_parent;

 assert(parent_node->m_left==cur_node);

 {
  node_type* const parent_parent_node=parent_node->m_parent;

  if(parent_parent_node==nullptr)
  {
   assert(m_head==parent_node);

   m_head=cur_node;
  }
  else
  if(parent_parent_node->m_left==parent_node)
  {
   parent_parent_node->m_left=cur_node;
  }
  else
  {
   assert(parent_parent_node->m_right==parent_node);

   parent_parent_node->m_right=cur_node;
  }

  cur_node->m_parent=parent_parent_node;
 }//local

 parent_node->m_left = cur_node->m_right;

 if(parent_node->m_left)
  parent_node->m_left->m_parent = parent_node;

 cur_node->m_right = parent_node;

 parent_node->m_parent = cur_node;
}//shift_right

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
void t_tree_avl_base<T,Compare,Allocator>::double_shift_left(node_type* const cur_node)
{
 assert(cur_node);
 assert(cur_node->m_parent);
 assert(cur_node->m_left);

 node_type* const parent_node=cur_node->m_parent;
 node_type* const new_parent_node =cur_node->m_left;

 assert(parent_node->m_right==cur_node);

 {
  node_type* const parent_parent_node=parent_node->m_parent;

  if(parent_parent_node==nullptr)
  {
   assert(m_head==parent_node);

   m_head=new_parent_node;
  }
  else
  if(parent_parent_node->m_left==parent_node)
  {
   parent_parent_node->m_left=new_parent_node;
  }
  else
  {
   assert(parent_parent_node->m_right==parent_node);

   parent_parent_node->m_right=new_parent_node;
  }

  new_parent_node->m_parent=parent_parent_node;
 }//local

 parent_node->m_right = new_parent_node->m_left;

 if(parent_node->m_right)
  parent_node->m_right->m_parent = parent_node;

 cur_node->m_left = new_parent_node->m_right;

 if(cur_node->m_left)
  cur_node->m_left->m_parent = cur_node;

 new_parent_node->m_right=cur_node;

 cur_node->m_parent = new_parent_node;

 new_parent_node->m_left=parent_node;

 parent_node->m_parent = new_parent_node;

 cur_node->m_balance = this->count_node_balance(cur_node);
}//double_shift_left

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
void t_tree_avl_base<T,Compare,Allocator>::double_shift_right(node_type* const cur_node)
{
 assert(cur_node);
 assert(cur_node->m_parent);
 assert(cur_node->m_right);

 node_type* const parent_node=cur_node->m_parent;
 node_type* const new_parent_node =cur_node->m_right;

 assert(parent_node->m_left==cur_node);

 {
  node_type* const parent_parent_node=parent_node->m_parent;

  if(parent_parent_node==nullptr)
  {
   assert(m_head==parent_node);

   m_head=new_parent_node;
  }
  else
  if(parent_parent_node->m_left==parent_node)
  {
   parent_parent_node->m_left=new_parent_node;
  }
  else
  {
   assert(parent_parent_node->m_right==parent_node);

   parent_parent_node->m_right=new_parent_node;
  }

  new_parent_node->m_parent=parent_parent_node;
 }//local

 parent_node->m_left = new_parent_node->m_right;

 if(parent_node->m_left)
  parent_node->m_left->m_parent = parent_node;

 cur_node->m_right = new_parent_node->m_left;

 if(cur_node->m_right)
  cur_node->m_right->m_parent = cur_node;

 new_parent_node->m_left = cur_node;

 cur_node->m_parent = new_parent_node;

 new_parent_node->m_right = parent_node;

 parent_node->m_parent = new_parent_node;

 cur_node->m_balance = this->count_node_balance(cur_node);
}//double_shift_right

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
void t_tree_avl_base<T,Compare,Allocator>::update_tree_balance(node_type* cur_node)
{
 while(cur_node!=nullptr)
 {
  const int left_balance  = this->get_left_balance(cur_node);
  const int right_balance = this->get_right_balance(cur_node);
  const int max_balance   = ((left_balance > right_balance)?left_balance:right_balance)+1;

  cur_node->m_balance = max_balance;

  const int diff = left_balance - right_balance;

  if(diff < -1)
  {
   assert(cur_node->m_right);

   node_type* const child_node = cur_node->m_right;

   const int child_diff
    =this->get_left_balance(child_node)-this->get_right_balance(child_node);

   if(child_diff < 1)
   {
    this->shift_left(child_node);
   }
   else
   {
    this->double_shift_left(child_node);
   }//if
  }//if(diff < -1)
  else
  if(diff > 1)
  {
   assert(cur_node->m_left);

   node_type* const child_node = cur_node->m_left;

   const int child_diff
    =this->get_left_balance(child_node)-this->get_right_balance(child_node);

   if(child_diff > -1)
   {
    this->shift_right(child_node);
   }
   else
   {
    this->double_shift_right(child_node);
   }//if
  }//if(diff > 1)
  else
  {
   assert(-1<=diff && diff<=1);

   cur_node=cur_node->m_parent;
  }//else
 }//while
}//update_tree_balance

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
RELEASE_CODE(inline)
int t_tree_avl_base<T,Compare,Allocator>::get_left_balance(const node_type* const node)
{
 assert(node);

 if(!node->m_left)
  return 0;

 assert(node->m_left->m_balance>0);

 return node->m_left->m_balance;
}//get_left_balance

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
RELEASE_CODE(inline)
int t_tree_avl_base<T,Compare,Allocator>::get_right_balance(const node_type* const node)
{
 assert(node);

 if(!node->m_right)
  return 0;

 assert(node->m_right->m_balance>0);

 return node->m_right->m_balance;
}//get_right_balance

//------------------------------------------------------------------------
template<class T,class Compare,class Allocator>
RELEASE_CODE(inline)
int t_tree_avl_base<T,Compare,Allocator>::count_node_balance(const node_type* const node)
{
 int const left_balance  = self_type::get_left_balance(node);
 int const right_balance = self_type::get_right_balance(node);

 return ((left_balance>right_balance)?left_balance:right_balance)+1;
}//count_node_balance

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
