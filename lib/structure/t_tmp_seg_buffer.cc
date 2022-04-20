////////////////////////////////////////////////////////////////////////////////
#ifndef _t_tmp_seg_buffer_CC_
#define _t_tmp_seg_buffer_CC_

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer_traits

template<typename T>
inline void t_tmp_seg_buffer_traits<T>::copy(pointer       const dest,
                                             const_pointer const src,
                                             size_type     const cnt)
{
 assert(sizeof(*src)==sizeof(*dest));

 memcpy(dest,src,cnt*sizeof(*src));
}//copy

//------------------------------------------------------------------------
template<typename T>
inline
typename t_tmp_seg_buffer_traits<T>::size_type
 t_tmp_seg_buffer_traits<T>::copy_binary(void*         const dest,
                                         size_type     const dest_size,
                                         const_pointer const src,
                                         size_type     const src_cnt)
{
 const size_type copy_cb=min(dest_size,src_cnt*sizeof(*src));

 memcpy(dest,src,copy_cb);

 return copy_cb;
}//copy_binary

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer__header

template<typename T>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer__header<T>::pointer
 t_tmp_seg_buffer__header<T>::data()
{
 return reinterpret_cast<pointer>(this+1);
}//data

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer__header<T>::const_pointer
 t_tmp_seg_buffer__header<T>::data()const
{
 return reinterpret_cast<const_pointer>(this+1);
}//data

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer__iterator

template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__iterator<T>::t_tmp_seg_buffer__iterator()
 :m_segment(NULL),
  m_pos(0)
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__iterator<T>::t_tmp_seg_buffer__iterator
                                           (segment_ptr const segment,
                                            pos_type    const pos)
 :m_segment (segment),
  m_pos     (pos)
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__iterator<T>::t_tmp_seg_buffer__iterator
                                           (const self_type& x)
 :m_segment (x.m_segment),
  m_pos     (x.m_pos)
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__iterator<T>::~t_tmp_seg_buffer__iterator()
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__iterator<T>&
 t_tmp_seg_buffer__iterator<T>::operator = (const self_type& x)
{
 m_segment = x.m_segment;
 m_pos     = x.m_pos;

 return *this;
}//operator =

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer__iterator<T>::reference
 t_tmp_seg_buffer__iterator<T>::operator * ()const
{
 assert(m_segment);
 assert(m_segment->used<=m_segment->size);
 assert(m_pos<m_segment->used);

 return m_segment->data()[m_pos];
}//operator *

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__iterator<T>
 t_tmp_seg_buffer__iterator<T>::operator ++ (int)
{
 const self_type tmp(*this);

 ++(*this);

 return tmp;
}//operator ++ (int)

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__iterator<T>&
 t_tmp_seg_buffer__iterator<T>::operator ++ ()
{
 assert(m_segment);
 assert(m_segment->used<=m_segment->size);
 assert(m_pos<m_segment->used);

 ++m_pos;

 while(m_pos==m_segment->used && m_segment->next!=NULL)
 {
  m_pos=0;
  m_segment=m_segment->next;
 }//while

 return *this;
}//operator ++ ()

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__iterator<T>
 t_tmp_seg_buffer__iterator<T>::operator -- (int)
{
 const self_type tmp(*this);

 --(*this);

 return tmp;
}//operator -- (int)

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__iterator<T>&
 t_tmp_seg_buffer__iterator<T>::operator -- ()
{
 assert(m_segment);
 assert(m_segment->used<=m_segment->size);
 assert(m_pos<=m_segment->used);

 while(m_pos==0)
 {
  assert(m_segment->prev!=NULL);

  m_segment=m_segment->prev;

  m_pos=m_segment->used;
 }//while

 --m_pos;

 return *this;
}//operator -- ()

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
bool t_tmp_seg_buffer__iterator<T>::eq(const self_type& x)const
{
 DEBUG_CODE(x.check_state();)
 DEBUG_CODE(this->check_state();)
 DEBUG_CODE(this->check_other_it(x);)

 return m_segment==x.m_segment && m_pos==x.m_pos;
}//eq

//------------------------------------------------------------------------
#ifndef NDEBUG
template<typename T>
void t_tmp_seg_buffer__iterator<T>::check_state()const
{
 if(m_segment==NULL)
 {
  assert(m_pos==0);
 }
}//check_state

//------------------------------------------------------------------------
template<typename T>
void t_tmp_seg_buffer__iterator<T>::check_other_it
                                           (const self_type& x)const
{
 if(m_segment==NULL || x.m_segment==NULL)
  return;

 typedef const segment_type* segment_cptr;

 segment_cptr n1=m_segment;
 segment_cptr n2=x.m_segment;

 while(n1)
 {
  if(n1==x.m_segment)
   return;

  if(n1->prev==NULL)
   break;

  n1=n1->prev;
 }//while

 while(n2)
 {
  if(n2==m_segment)
   return;

  if(n2->prev==NULL)
   break;

  n2=n2->prev;
 }//while

 assert(n1==n2);
}//check_other_it
#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer__const_iterator

template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__const_iterator<T>::t_tmp_seg_buffer__const_iterator()
 :m_segment(NULL),
  m_pos(0)
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__const_iterator<T>::t_tmp_seg_buffer__const_iterator
                                           (segment_ptr const segment,
                                            pos_type    const pos)
 :m_segment (segment),
  m_pos     (pos)
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__const_iterator<T>::t_tmp_seg_buffer__const_iterator
                                           (const self_type& x)
 :m_segment (x.m_segment),
  m_pos     (x.m_pos)
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__const_iterator<T>::t_tmp_seg_buffer__const_iterator
                                           (const rw_iterator_type& x)
 :m_segment (x.m_segment),
  m_pos     (x.m_pos)
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__const_iterator<T>::~t_tmp_seg_buffer__const_iterator()
{;}

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
t_tmp_seg_buffer__const_iterator<T>&
 t_tmp_seg_buffer__const_iterator<T>::operator = (const self_type& x)
{
 m_segment = x.m_segment;
 m_pos     = x.m_pos;

 return *this;
}//operator =

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer__const_iterator<T>::reference
 t_tmp_seg_buffer__const_iterator<T>::operator * ()const
{
 assert(m_segment);
 assert(m_segment->used<=m_segment->size);
 assert(m_pos<m_segment->used);

 return m_segment->data()[m_pos];
}//operator *

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__const_iterator<T>
 t_tmp_seg_buffer__const_iterator<T>::operator ++ (int)
{
 const self_type tmp(*this);

 ++(*this);

 return tmp;
}//operator ++ (int)

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__const_iterator<T>&
 t_tmp_seg_buffer__const_iterator<T>::operator ++ ()
{
 assert(m_segment);
 assert(m_segment->used<=m_segment->size);
 assert(m_pos<m_segment->used);

 ++m_pos;

 while(m_pos==m_segment->used && m_segment->next!=NULL)
 {
  m_pos=0;
  m_segment=m_segment->next;
 }//while

 return *this;
}//operator ++ ()

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__const_iterator<T>
 t_tmp_seg_buffer__const_iterator<T>::operator -- (int)
{
 const self_type tmp(*this);

 --(*this);

 return tmp;
}//operator -- (int)

//------------------------------------------------------------------------
template<typename T>
t_tmp_seg_buffer__const_iterator<T>&
 t_tmp_seg_buffer__const_iterator<T>::operator -- ()
{
 assert(m_segment);
 assert(m_segment->used<=m_segment->size);
 assert(m_pos<=m_segment->used);

 while(m_pos==0)
 {
  assert(m_segment->prev!=NULL);

  m_segment=m_segment->prev;

  m_pos=m_segment->used;
 }//while

 --m_pos;

 return *this;
}//operator -- ()

//------------------------------------------------------------------------
template<typename T>
RELEASE_CODE(inline)
bool t_tmp_seg_buffer__const_iterator<T>::eq(const self_type& x)const
{
 DEBUG_CODE(x.check_state();)
 DEBUG_CODE(this->check_state();)
 DEBUG_CODE(this->check_other_it(x);)

 return m_segment==x.m_segment && m_pos==x.m_pos;
}//eq

//------------------------------------------------------------------------
#ifndef NDEBUG
template<typename T>
void t_tmp_seg_buffer__const_iterator<T>::check_state()const
{
 if(m_segment==NULL)
 {
  assert(m_pos==0);
 }
}//check_state

//------------------------------------------------------------------------
template<typename T>
void t_tmp_seg_buffer__const_iterator<T>::check_other_it
                                           (const self_type& x)const
{
 if(m_segment==NULL || x.m_segment==NULL)
  return;

 typedef const segment_type* segment_cptr;

 segment_cptr n1=m_segment;
 segment_cptr n2=x.m_segment;

 while(n1)
 {
  if(n1==x.m_segment)
   return;

  if(n1->prev==NULL)
   break;

  n1=n1->prev;
 }//while

 while(n2)
 {
  if(n2==m_segment)
   return;

  if(n2->prev==NULL)
   break;

  n2=n2->prev;
 }//while

 assert(n1==n2);
}//check_other_it
#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer::tag_fix_seg_N

template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_fix_seg_N::tag_fix_seg_N()
{
 assert_s(FixBufSize>0);

 this->init();
}//tag_fix_seg_N

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_fix_seg_N::init()
{
 assert_s(FixBufSize>0);

 this->size =_DIM_(m_data);
 this->used =0;
 this->prev =NULL;
 this->next =NULL;
}//init

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer::tag_fix_seg_0

template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_fix_seg_0::tag_fix_seg_0()
{
 assert_s(FixBufSize==0);

 this->init();
}//tag_fix_seg_0

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_fix_seg_0::init()
{
 assert_s(FixBufSize==0);

 this->size =0;
 this->used =0;
 this->prev =NULL;
 this->next =NULL;
}//init

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer::tag_seg_list_traits

template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::node_ptr_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::null_ptr()
{
 return NULL;
}//null_ptr

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::node_ptr_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::get_prev
                                           (node_ptr_type node)const
{
 assert(node);

 return node->prev;
}//get_prev

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::node_ptr_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::get_next
                                           (node_ptr_type node)const
{
 assert(node);

 return node->next;
}//get_next

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::set_prev
                                           (node_ptr_type node,
                                            node_ptr_type x)const
{
 assert(node);

 node->prev=x;
}//set_prev

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tag_seg_list_traits::set_next
                                           (node_ptr_type node,
                                            node_ptr_type x)const
{
 assert(node);

 node->next=x;
}//set_next

////////////////////////////////////////////////////////////////////////////////
//class t_tmp_seg_buffer

template<typename T,size_t FixBufSize,class Allocator,class Traits>
t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::t_tmp_seg_buffer()
 :m_size(0),
  m_lock_cnt(0),
  m_min_seg_size(c_def_min_seg_size)
{;}

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::t_tmp_seg_buffer(size_type min_seg_size)
 :m_size(0),
  m_lock_cnt(0),
  m_min_seg_size(min_seg_size)
{;}

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::~t_tmp_seg_buffer()
{
 this->clear();
}//~t_tmp_seg_buffer

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
inline
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::size_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::fix_seg_size()const
{
 return FixBufSize;
}//fix_seg_size

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
inline
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::size_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::min_seg_size()const
{
 return m_min_seg_size;
}//min_seg_size

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
inline
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::size_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::size()const
{
 return m_size;
}//size

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
inline
bool t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::empty()const
{
 return m_size==0;
}//empty

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
const typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::seg_header_type*
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::head()const
{
 assert(m_lock_cnt==0);

 return m_seg_list.head();
}//head

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
const typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::seg_header_type*
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::tail()const
{
 assert(m_lock_cnt==0);

 return m_seg_list.tail();
}//tail

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::size_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::copy_binary
                                           (void*     const dest,
                                            size_type const dest_size)const
{
 CHECK_WRITE_PTR(dest,dest_size);

 const seg_header_type* seg=this->head();

 assert(sizeof(char)==1);

 void*       i_dest=dest;
 void* const e_dest=reinterpret_cast<char*>(dest)+dest_size;

 assert(i_dest<=e_dest);

 for(;seg!=NULL && i_dest<e_dest;seg=seg->next)
 {
  assert(seg->size!=0);
  assert(seg->used<=seg->size);

  const size_type
   free_cb=reinterpret_cast<char*>(e_dest)-reinterpret_cast<char*>(i_dest);

  const size_type
   copy_cb=traits_type::copy_binary(i_dest,
                                    free_cb,
                                    seg->data(),
                                    seg->used);

  i_dest=reinterpret_cast<char*>(i_dest)+copy_cb;
 }//for

 return reinterpret_cast<char*>(i_dest)-reinterpret_cast<char*>(dest);
}//copy_binary

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::size_type
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::copy(pointer   const dest,
                                                       size_type const dest_size)const
{
 CHECK_WRITE_TYPED_PTR(dest,dest_size);

 const seg_header_type* seg=this->head();

 value_type*       i_dest=dest;
 value_type* const e_dest=dest+dest_size;

 assert(size_t(e_dest-i_dest)==dest_size);

 for(;seg!=NULL && i_dest<e_dest;seg=seg->next)
 {
  assert(seg->size!=0);
  assert(seg->used<=seg->size);

  const size_type cnt=min(size_type(e_dest-i_dest),seg->used);

  traits_type::copy(i_dest,seg->data(),cnt);

  i_dest+=cnt;
 }//for

 return i_dest-dest;
}//copy

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
template<class TContainer>
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::append_to(TContainer& dest)
{
 for(const seg_header_type* seg=this->head();seg!=NULL;seg=seg->next)
 {
  assert(seg->size!=0);
  assert(seg->used<=seg->size);

  dest.append(seg->data(),seg->used);
 }//for
}//append_to

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::clear()
{
 while(!m_seg_list.empty())
 {
  this->remove_segment(m_seg_list.tail());
 }//for

 assert(m_size==0);
 assert(m_seg_list.empty());

 m_fix_segment.init();

 m_size=0;

 m_lock_cnt=0;
}//clear

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::reference
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::front()
{
 assert(!this->empty());

 return *this->begin();
}//front

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::reference
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::back()
{
 assert(!this->empty());

 return *(--this->end());
}//back

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::const_reference
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::front()const
{
 assert(!this->empty());

 return *this->begin();
}//front - const

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::const_reference
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::back()const
{
 assert(!this->empty());

 return *(--this->end());
}//back - const

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::iterator
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::begin()
{
 seg_header_ptr seg(m_seg_list.head());

 if(seg!=NULL)
 {
  while(seg->used==0 && seg->next!=NULL)
  {
   seg=seg->next;
  }//while
 }//if

 return iterator(seg,0);
}//begin

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::iterator
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::end()
{
 seg_header_ptr const seg(m_seg_list.tail());

 if(seg!=NULL)
  return iterator(seg,seg->used);

 return iterator();
}//end

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::const_iterator
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::begin()const
{
 seg_header_cptr seg(m_seg_list.head());

 if(seg!=NULL)
 {
  while(seg->used==0 && seg->next!=NULL)
  {
   seg=seg->next;
  }//while
 }//if

 return const_iterator(seg,0);
}//begin - const

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::const_iterator
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::end()const
{
 seg_header_cptr const seg(m_seg_list.tail());

 if(seg!=NULL)
  return const_iterator(seg,seg->used);

 return const_iterator();
}//end - const

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::const_iterator
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::cbegin()const
{
 return this->begin();
}//cbegin

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::const_iterator
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::cend()const
{
 return this->end();
}//cend

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
RELEASE_CODE(inline)
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::push_back(const value_type& x)
{
 assert(m_lock_cnt==0);

 return this->write(&x,1);
}//push_back

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::pop_back()
{
 assert(m_lock_cnt==0);

 for(;;)
 {
  assert(!this->empty());
  assert(!m_seg_list.empty());

  if(m_seg_list.tail()->used!=0)
   break;

  this->remove_segment(m_seg_list.tail());
 }//for[ever]

 assert(!this->empty());
 assert(!m_seg_list.empty());
 assert(m_seg_list.tail()->used!=0);
 assert(m_seg_list.tail()->used<=m_seg_list.tail()->size);

 --m_seg_list.tail()->used;
 --m_size;

 if(m_seg_list.tail()->used==0)
  this->remove_segment(m_seg_list.tail());
}//pop_back

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::write(const_pointer const ptr,
                                                            size_type     const cnt)
{
 assert(m_lock_cnt==0);

 CHECK_READ_TYPED_PTR(ptr,cnt);

 //assert(m_fix_segment.size!=0);
 assert(m_fix_segment.size<=sizeof(m_fix_segment)-sizeof(seg_header_type));
 assert(m_fix_segment.used<=m_fix_segment.size);

 assert(sizeof(seg_header_type)<m_alloc.max_size());

 if(cnt==0)
  return;

 if(m_alloc.max_size()<sizeof(seg_header_type))
  throw std::bad_alloc();

 if(cnt>((m_alloc.max_size()-sizeof(seg_header_type))/sizeof(value_type)))
  throw std::bad_alloc();

 if(m_seg_list.empty())
 {
  //assert(m_fix_segment.size!=0);
  assert(m_fix_segment.used==0);
  assert(m_fix_segment.next==NULL);
  assert(m_size==0);

  this->append_new_seg(cnt,ptr,cnt);

  assert(m_seg_list.head()==m_seg_list.tail());
  assert(m_size==cnt);
  assert(m_seg_list.tail()->used==cnt);
  assert(m_seg_list.tail()->used<=m_seg_list.tail()->size);

  return;
 }//if - empty buffer

 assert(!m_seg_list.empty());
 assert(m_seg_list.tail()->size!=0);
 assert(m_seg_list.tail()->used<=m_seg_list.tail()->size);

 if((m_seg_list.tail()->size-m_seg_list.tail()->used)==0)
 {
  this->append_new_seg(cnt,ptr,cnt);

  return;
 }//if

 size_type write_cnt=m_seg_list.tail()->size-m_seg_list.tail()->used;

 if(write_cnt>cnt)
  write_cnt=cnt;

 traits_type::copy(m_seg_list.tail()->data()+m_seg_list.tail()->used,ptr,write_cnt);

 seg_header_type* const copy_tail=m_seg_list.tail();

 if(write_cnt<cnt)
 {
  //allocate new segment
  this->append_new_seg(cnt-write_cnt,
                       ptr+write_cnt,
                       cnt-write_cnt); //throw
 }//if

 //append_new_seq without exception

 copy_tail->used+=write_cnt;

 m_size+=write_cnt;
}//write

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::pointer
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::lock(size_type const req_cnt)
{
 assert(m_lock_cnt==0);

 if(req_cnt==0)
  return NULL;

 while(m_seg_list.empty() || (m_seg_list.tail()->size-m_seg_list.tail()->used)<req_cnt)
 {
  if(m_seg_list.tail() && m_seg_list.tail()->used==0)
  {
   this->remove_segment(m_seg_list.tail());

   continue;
  }//if

  this->append_new_seg(req_cnt,NULL,0);

  assert(m_seg_list.tail());
  assert(m_seg_list.tail()->used==0);
  assert(req_cnt<=m_seg_list.tail()->size);

  break;
 }//while

 assert(m_seg_list.head()!=NULL);
 assert(m_seg_list.tail()->size!=0);
 assert(m_seg_list.tail()->used<m_seg_list.tail()->size);
 assert(req_cnt<=m_seg_list.tail()->size-m_seg_list.tail()->used);

 m_lock_cnt=req_cnt;

 return m_seg_list.tail()->data()+m_seg_list.tail()->used;
}//lock

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::unlock(size_type const used_bytes)
{
 assert(used_bytes<=m_lock_cnt);

 if(m_lock_cnt==0)
  return;

 assert(!m_seg_list.empty());
 assert(used_bytes<=m_seg_list.tail()->size-m_seg_list.tail()->used);

 m_seg_list.tail()->used+=used_bytes;

 m_size+=used_bytes;

 m_lock_cnt=0;
}//unlock

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::pointer
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::make_flat(bool const final)
{
 if(m_size==0)
  return NULL;

 assert(!m_seg_list.empty());

 if(m_seg_list.head()==m_seg_list.tail()) //one segment
  return m_seg_list.head()->data();

 {
  size_type alloc_cnt=m_size;

  if(!final && alloc_cnt<m_min_seg_size)
   alloc_cnt=m_min_seg_size;

  seg_header_type* const flat_seg(this->allocate_new_seg(alloc_cnt));

  assert(flat_seg->next==NULL);

  //copy data to new segment
  flat_seg->used=this->copy(flat_seg->data(),m_size);

  assert(flat_seg->used==m_size);

  //clear current state
  this->clear();

  assert(m_seg_list.empty());

  //install new segment
  m_seg_list.push_back(tag_seg_list_traits(),flat_seg);

  m_size=flat_seg->used;
 }//local

 return m_seg_list.head()->data();
}//make_flat

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
typename t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::seg_header_type*
 t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::allocate_new_seg(size_type const cnt)
{
 seg_header_type* const
  tmp=reinterpret_cast<seg_header_type*>
       (m_alloc.allocate(sizeof(seg_header_type)+sizeof(value_type)*cnt));

 tmp->size=cnt;

 tmp->used=0;

 tmp->prev=NULL;
 tmp->next=NULL;

 return tmp;
}//allocate_new_seg

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::append_new_seg
                                           (size_type           alloc_cnt,
                                            const_pointer const ptr,
                                            size_type     const cnt)
{
 assert(alloc_cnt);
 assert(cnt<=alloc_cnt);
 //assert(m_fix_segment.size!=0);

 seg_header_type* tmp;

#ifndef NDEBUG
 if(m_fix_segment.used==0)
 {
  assert(m_fix_segment.next==NULL);
  assert(m_fix_segment.prev==NULL);
 }
#endif

 if(m_fix_segment.used==0     &&
    m_fix_segment.next==NULL  &&
    m_fix_segment.prev==NULL  &&
    alloc_cnt<=m_fix_segment.size)
 {
  //append fix_segment
  tmp=&m_fix_segment;
 }
 else
 {
  if(alloc_cnt<m_min_seg_size)
   alloc_cnt=m_min_seg_size;

  tmp=this->allocate_new_seg(alloc_cnt);
 }//else

 assert(tmp->size!=0);
 assert(tmp->used==0);
 assert(cnt<=tmp->size);

 tmp->prev=NULL;
 tmp->next=NULL;

 m_seg_list.push_back(tag_seg_list_traits(),tmp);

 if(cnt!=0)
 {
  traits_type::copy(tmp->data(),ptr,cnt);
 }

 tmp->used=cnt;

 m_size+=cnt;
}//append_new_seg

//------------------------------------------------------------------------
template<typename T,size_t FixBufSize,class Allocator,class Traits>
void t_tmp_seg_buffer<T,FixBufSize,Allocator,Traits>::remove_segment
                                           (seg_header_type* const seg)
{
 assert(seg);
 assert(seg->used<=seg->size);
 assert(seg->used<=m_size);

 m_size-=seg->used;

 seg->used=0;

 m_seg_list.remove(tag_seg_list_traits(),seg);

 if(seg!=&m_fix_segment)
  m_alloc.deallocate(reinterpret_cast<char*>(seg),0);
}//remove_segment

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif