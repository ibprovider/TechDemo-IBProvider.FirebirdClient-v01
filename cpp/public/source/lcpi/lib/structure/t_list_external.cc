////////////////////////////////////////////////////////////////////////////////
#ifndef _cpp_public_lcpi_lib_structure__t_list_external_CC_
#define _cpp_public_lcpi_lib_structure__t_list_external_CC_

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_list_external_base__with_size

inline t_list_external_base__with_size::size_type
 t_list_external_base__with_size::size()const
{
 return m_size;
}//size

//------------------------------------------------------------------------
inline void t_list_external_base__with_size::set_size(size_type x)
{
 m_size=x;
}//set_size

//------------------------------------------------------------------------
inline void t_list_external_base__with_size::dec_size()
{
 --m_size;
}//dec_size

//------------------------------------------------------------------------
inline void t_list_external_base__with_size::inc_size()
{
 ++m_size;
}//inc_size

//------------------------------------------------------------------------
#ifndef NDEBUG
inline void t_list_external_base__with_size::debug__verify_size__eq(size_type x)const
{
 assert(m_size==x);
}//debug__verify_size__eq

//------------------------------------------------------------------------
inline void t_list_external_base__with_size::debug__verify_size__eq_or_large(size_type x)const
{
 assert(m_size>=x);
}//debug__verify_size__eq_or_large
#endif

////////////////////////////////////////////////////////////////////////////////
//class t_list_external

template<class ListTraits,class TBase>
LCPI__RELEASE_CODE(inline)
t_list_external<ListTraits,TBase>::t_list_external()
{
 this->clear();
}

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
LCPI__RELEASE_CODE(inline)
bool t_list_external<ListTraits,TBase>::empty()const
{
 return m_head==traits_type::null_ptr();
}//empty

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
LCPI__RELEASE_CODE(inline)
typename t_list_external<ListTraits,TBase>::node_ptr_type
 t_list_external<ListTraits,TBase>::head()const
{
 return m_head;
}//head

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
LCPI__RELEASE_CODE(inline)
typename t_list_external<ListTraits,TBase>::node_ptr_type
 t_list_external<ListTraits,TBase>::tail()const
{
 return m_tail;
}//tail

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
LCPI__RELEASE_CODE(inline)
void t_list_external<ListTraits,TBase>::clear()
{
 this->set_size(0);

 m_head =traits_type::null_ptr();
 m_tail =traits_type::null_ptr();
}//clear

//------------------------------------------------------------------------
#ifndef NDEBUG
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::debug__verify(const traits_type& traits)const
{
 if(m_head==traits.null_ptr())
 {
  assert(m_tail==traits.null_ptr());

  this->debug__verify_size__eq(0);
 }
 else
 {
  assert(m_tail!=traits.null_ptr());

  this->debug__verify_size__eq_or_large(1);

  //проверяем целостность концов списка
  this->debug__verify_item(traits,m_head);
  this->debug__verify_item(traits,m_tail);
 }
}//debug__verify

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::debug__verify_item
                             (const traits_type&  traits,
                              node_ptr_type const x)const
{
 assert(x!=traits.null_ptr());
 assert(m_head!=traits.null_ptr());
 assert(m_tail!=traits.null_ptr());

 assert(traits.get_prev(m_head)==traits.null_ptr());
 assert(traits.get_next(m_tail)==traits.null_ptr());

 node_ptr_type const x_prev=traits.get_prev(x);
 node_ptr_type const x_next=traits.get_next(x);

 if(x_prev==traits.null_ptr())
 {
  assert(x==m_head);

  this->debug__verify_size__eq_or_large(1);
 }
 else
 if(x_next==traits.null_ptr())
 {
  assert(x==m_tail);

  this->debug__verify_size__eq_or_large(1);
 }
 else
 {
  //x - не начало и не конец списка. Значит список больше одного элемента.
  // точнее - не меньше трех

  assert(m_head!=m_tail);

  this->debug__verify_size__eq_or_large(3);
 }

 //проверка связей
 if(x_prev!=traits.null_ptr())
 {
  assert(traits.get_next(x_prev)==x);
 }

 if(x_next!=traits.null_ptr())
 {
  assert(traits.get_prev(x_next)==x);
 }
}//debug__verify_item

#endif //NDEBUG

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::remove
                             (const traits_type&  traits,
                              node_ptr_type const x)
{
#ifndef NDEBUG
 this->debug__verify_size__eq_or_large(1);
 this->debug__verify(traits);
 this->debug__verify_item(traits,x);
#endif

 if(m_head==x)
 {
  //удаляем из головы списка

  if(m_tail==x)
  {
   //это последний элемент списка
   DEBUG_CODE(this->debug__verify_size__eq(1));

   this->clear();
  }
  else
  {
   assert(m_head!=m_tail);

   assert(traits.get_next(x)!=traits.null_ptr());

   DEBUG_CODE(this->debug__verify_size__eq_or_large(2));

   //set second item as first
   const node_ptr_type new_head=traits.get_next(x);

   traits.set_prev(new_head,traits.null_ptr());

   m_head=new_head;

   this->dec_size();
  }
 }
 else
 if(m_tail==x)
 {
  //remove last list item

  assert(m_head!=m_tail);

  assert(traits.get_prev(x)!=traits.null_ptr());

  DEBUG_CODE(this->debug__verify_size__eq_or_large(2));

  //делаем предпоследний элемент последним
  const node_ptr_type new_tail=traits.get_prev(x);

  traits.set_next(new_tail,traits.null_ptr());

  m_tail=new_tail;

  this->dec_size();
 }
 else
 {
  //remove middle list item
  assert(m_head!=m_tail);

  DEBUG_CODE(this->debug__verify_size__eq_or_large(3));

  assert(traits.get_prev(x)!=traits.null_ptr());
  assert(traits.get_next(x)!=traits.null_ptr());

  traits.set_next(traits.get_prev(x),traits.get_next(x));
  traits.set_prev(traits.get_next(x),traits.get_prev(x));

  this->dec_size();
 }//else

 traits.set_prev(x,traits.null_ptr());
 traits.set_next(x,traits.null_ptr());

#ifndef NDEBUG
 this->debug__verify(traits);
#endif
}//remove

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::insert
                             (const traits_type&  traits,
                              node_ptr_type const position,
                              node_ptr_type const x)
{
 assert(x!=traits.null_ptr());
 assert(x!=m_head);
 assert(x!=m_tail);
 assert(x!=position);

#ifndef NDEBUG
 this->debug__verify(traits);
#endif

 if(position==traits.null_ptr())
  return this->push_back(traits,x);

#ifndef NDEBUG
 this->debug__verify_item(traits,position);
#endif

 if(position==m_head)
 {
  traits.set_prev(x,traits.null_ptr());

  traits.set_next(x,position);

  traits.set_prev(position,x);

  m_head=x;
 }
 else
 {
  node_ptr_type const position_prev(traits.get_prev(position));

  traits.set_prev(x,position_prev);
  traits.set_next(x,position);

  traits.set_next(position_prev,x);
  traits.set_prev(position,x);
 }//else

 this->inc_size();

#ifndef NDEBUG
 this->debug__verify_item(traits,x);
 this->debug__verify_item(traits,position);
#endif
}//insert

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::push_front
                             (const traits_type&  traits,
                              node_ptr_type const x)
{
 assert(x!=traits.null_ptr());
 assert(x!=m_head);
 assert(x!=m_tail);

#ifndef NDEBUG
 this->debug__verify(traits);
#endif

 if(m_head==traits.null_ptr())
 {
  //empty list
  assert(m_tail==traits.null_ptr());

  DEBUG_CODE(this->debug__verify_size__eq(0));

  traits.set_prev(x,traits.null_ptr());
  traits.set_next(x,traits.null_ptr());

  m_head =x;
  m_tail =x;

  this->set_size(1);
 }
 else
 {
  //not empty list
  assert(m_head!=traits.null_ptr());
  assert(m_tail!=traits.null_ptr());

  DEBUG_CODE(this->debug__verify_size__eq_or_large(1));

  assert(traits.get_prev(m_head)==traits.null_ptr());
  assert(traits.get_next(m_tail)==traits.null_ptr());

  //помещаем элемент в начало списка

  traits.set_prev(x,traits.null_ptr());
  traits.set_next(x,m_head);

  traits.set_prev(m_head,x);

  m_head=x;

  this->inc_size();
 }//else - не пустой список элементов

#ifndef NDEBUG
 this->debug__verify(traits);
#endif
}//push_front

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::push_back
                             (const traits_type&  traits,
                              node_ptr_type const x)
{
 assert(x!=traits.null_ptr());
 assert(x!=m_head);
 assert(x!=m_tail);

#ifndef NDEBUG
 this->debug__verify(traits);
#endif

 if(m_tail==traits.null_ptr())
 {
  //empty list
  assert(m_head==traits.null_ptr());

  DEBUG_CODE(this->debug__verify_size__eq(0));

  traits.set_prev(x,traits.null_ptr());
  traits.set_next(x,traits.null_ptr());

  m_head =x;
  m_tail =x;

  this->set_size(1);
 }
 else
 {
  //not empty list
  assert(m_head!=traits.null_ptr());
  assert(m_tail!=traits.null_ptr());

  DEBUG_CODE(this->debug__verify_size__eq_or_large(1));

  assert(traits.get_prev(m_head)==traits.null_ptr());
  assert(traits.get_next(m_tail)==traits.null_ptr());

  //подключаем элемент к хвосту
  traits.set_next(m_tail,x);

  traits.set_prev(x,m_tail);

  traits.set_next(x,traits.null_ptr());

  m_tail=x;

  this->inc_size();
 }//else - не пустой список

#ifndef NDEBUG
 this->debug__verify(traits);
#endif
}//push_back

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::bring_to_front
                             (const traits_type&  traits,
                              node_ptr_type const x)
{
#ifndef NDEBUG
 this->debug__verify(traits);
 this->debug__verify_item(traits,x);
#endif

 if(m_head==x)
  return; //item in head already

 if(traits.get_next(x)==traits.null_ptr()) //item is list tail
 {
  m_tail=traits.get_prev(x); //set new tail
 }
 else
 {
  //attach next item to previous
  traits.set_prev(traits.get_next(x),traits.get_prev(x));
 }

 //attach previous item to next
 traits.set_next(traits.get_prev(x),traits.get_next(x));

 //устанавливаем элемент в начало списка
 traits.set_prev(x,traits.null_ptr());
 traits.set_next(x,m_head);

 traits.set_prev(m_head,x);

 m_head=x;

#ifndef NDEBUG
 this->debug__verify(traits);
#endif
}//bring_to_front

//------------------------------------------------------------------------
template<class ListTraits,class TBase>
void t_list_external<ListTraits,TBase>::move_tail_to_head
                             (const traits_type&  traits,
                              node_ptr_type const start_tail)
{
#ifndef NDEBUG
 this->debug__verify(traits);
 this->debug__verify_item(traits,start_tail);
#endif

 if(start_tail==m_head)
  return;

 assert(traits.get_prev(start_tail)!=traits.null_ptr());

 node_ptr_type const current_tail=m_tail;

 //set start_tail->prev as new tail --------------------------------------
 m_tail=traits.get_prev(start_tail);

 traits.set_next(m_tail,traits.null_ptr());

 traits.set_prev(start_tail,traits.null_ptr());

 //attach m_head to current_tail -----------------------------------------

 assert(m_head!=current_tail);

 assert(traits.get_prev(m_head)==traits.null_ptr());
 assert(traits.get_next(current_tail)==traits.null_ptr());

 traits.set_next(current_tail,m_head);
 traits.set_prev(m_head,current_tail);

 //устанавливаем x в начало списка ---------------------------------------
 m_head=start_tail;

 assert(m_head!=traits.null_ptr());

#ifndef NDEBUG
 this->debug__verify(traits);
#endif
}//move_tail_to_head

////////////////////////////////////////////////////////////////////////////////
//class t_list_external__traits_std

template<class TNode>
LCPI__RELEASE_CODE(inline)
t_list_external__traits_std<TNode>::t_list_external__traits_std()
{;}

//------------------------------------------------------------------------
template<class TNode>
LCPI__RELEASE_CODE(inline)
typename t_list_external__traits_std<TNode>::node_ptr_type
 t_list_external__traits_std<TNode>::null_ptr()
{
 return NULL;
}//null_ptr

//------------------------------------------------------------------------
template<class TNode>
LCPI__RELEASE_CODE(inline)
typename t_list_external__traits_std<TNode>::node_ptr_type
 t_list_external__traits_std<TNode>::get_prev
                             (node_ptr_type const node)const
{
 assert(node);

 return node->m_prev;
}//get_prev

//------------------------------------------------------------------------
template<class TNode>
LCPI__RELEASE_CODE(inline)
typename t_list_external__traits_std<TNode>::node_ptr_type
 t_list_external__traits_std<TNode>::get_next
                             (node_ptr_type const node)const
{
 assert(node);

 return node->m_next;
}//get_next

//------------------------------------------------------------------------
template<class TNode>
LCPI__RELEASE_CODE(inline)
void t_list_external__traits_std<TNode>::set_prev
                             (node_ptr_type const node,
                              node_ptr_type const x)const
{
 assert(node);

 node->m_prev=x;
}//set_prev

//------------------------------------------------------------------------
template<class TNode>
LCPI__RELEASE_CODE(inline)
void t_list_external__traits_std<TNode>::set_next
                             (node_ptr_type const node,
                              node_ptr_type const x)const
{
 assert(node);

 node->m_next=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
