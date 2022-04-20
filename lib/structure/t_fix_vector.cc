////////////////////////////////////////////////////////////////////////////////
//Реализация шаблона <structure/t_fix_vector.cc>
//                                        Коваленко Дмитрий. 14 июля 2003 года.
#ifndef _t_fix_vector_CC_
#define _t_fix_vector_CC_

#include <structure/t_algorithm.h>
#include <structure/t_memory.h>
#include <iterator>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template class t_fix_vector_base

template<size_t N,class T>
inline t_fix_vector_base<N,T>::t_fix_vector_base()
 :m_size(0)
{
}

//------------------------------------------------------------------------
template<size_t N,class T>
t_fix_vector_base<N,T>::~t_fix_vector_base()
{
 this->clear();
}//~t_fix_vector_base

//------------------------------------------------------------------------
template<size_t N,class T>
void t_fix_vector_base<N,T>::clear()
{
 assert(m_size<=self_type::num_of_elements);

 structure::__generic_destroyer_range(this->buffer(),this->buffer()+m_size);

 m_size=0;
}//clear

//------------------------------------------------------------------------
template<size_t N,class T>
inline typename t_fix_vector_base<N,T>::pointer t_fix_vector_base<N,T>::buffer()
{
 return reinterpret_cast<T*>(m_buffer);
}//buffer

//------------------------------------------------------------------------
template<size_t N,class T>
inline typename t_fix_vector_base<N,T>::const_pointer t_fix_vector_base<N,T>::buffer()const
{
 return reinterpret_cast<const T*>(m_buffer);
}//buffer - const

////////////////////////////////////////////////////////////////////////////////
//template class t_fix_vector

template<size_t N,class T>
inline t_fix_vector<N,T>::t_fix_vector()
{
}

//------------------------------------------------------------------------
template<size_t N,class T>
t_fix_vector<N,T>::t_fix_vector(size_type const n)
{
 this->resize(n);
}//t_fix_vector

//------------------------------------------------------------------------
template<size_t N,class T>
t_fix_vector<N,T>::t_fix_vector(const self_type& x)
{
 assert(x.size()<=self_type::num_of_elements);

 structure::uninitialized_copy
  (x.begin(),
   x.end(),
   this->buffer(),
   this->buffer()+x.size());

 m_size=x.size();
}//t_fix_vector - copy

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)

template<size_t N,class T>
template<typename Iterator>
t_fix_vector<N,T>::t_fix_vector(Iterator first,Iterator last)
{
 typedef std::iterator_traits<Iterator>::iterator_category __cat;

 this->construct(first,last,__cat());
}//t_fix_vector

#else //!COMP_CONF_SUPPORT_MEMBER_TEMPLATE

template<size_t N,class T>
t_fix_vector<N,T>::t_fix_vector(const_iterator first,const_iterator last)
{
 this->construct(first,last);
}//t_fix_vector

#endif //!COMP_CONF_SUPPORT_MEMBER_TEMPLATE

//------------------------------------------------------------------------
template<size_t N,class T>
t_fix_vector<N,T>::~t_fix_vector()
{
}

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::self_type& t_fix_vector<N,T>::operator = (const self_type& x)
{
 this->assign(x.begin(),x.end());

 return *this;
}//operator =

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::iterator t_fix_vector<N,T>::begin()
{
#ifndef NDEBUG
 return iterator(this,this->buffer());
#else
 return iterator(this->buffer());
#endif
}//begin

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::iterator t_fix_vector<N,T>::end()
{
#ifndef NDEBUG
 return iterator(this,this->buffer()+this->size());
#else
 return iterator(this->buffer()+this->size());
#endif
}//end

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_iterator t_fix_vector<N,T>::cbegin()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer());
#else
 return const_iterator(this->buffer());
#endif
}//cbegin

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_iterator t_fix_vector<N,T>::cend()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer()+this->size());
#else
 return const_iterator(this->buffer()+this->size());
#endif
}//cend

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_iterator t_fix_vector<N,T>::begin()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer());
#else
 return const_iterator(this->buffer());
#endif
}//begin - const

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_iterator t_fix_vector<N,T>::end()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer()+this->size());
#else
 return const_iterator(this->buffer()+this->size());
#endif
}//end - const

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::size_type t_fix_vector<N,T>::size()const
{
 assert(m_size<=num_of_elements);

 return m_size;
}//size

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
bool t_fix_vector<N,T>::empty()const
{
 assert(m_size<=num_of_elements);

 return m_size==0;
}//empty

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
bool t_fix_vector<N,T>::full()const
{
 assert(m_size<=num_of_elements);

 return m_size==num_of_elements;
}//full

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::size_type t_fix_vector<N,T>::capacity()const
{
 assert(m_size<=num_of_elements);

 return num_of_elements;
}//capacity

//------------------------------------------------------------------------
template<size_t N,class T>
typename t_fix_vector<N,T>::pointer t_fix_vector<N,T>::data()
{
 return this->buffer();
}//data

//------------------------------------------------------------------------
template<size_t N,class T>
typename t_fix_vector<N,T>::const_pointer t_fix_vector<N,T>::data()const
{
 return this->buffer();
}//data

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::reference t_fix_vector<N,T>::operator [] (size_type i)
{
 assert_msg(i<this->size(),"i=="<<i<<"\nN=="<<this->size());
 return this->buffer()[i];
}//operator []

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_reference t_fix_vector<N,T>::operator [] (size_type i)const
{
 assert_msg(i<num_of_elements,"i=="<<i<<"\nN=="<<num_of_elements);
 return this->buffer()[i];
}//operator [] - const

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::reference t_fix_vector<N,T>::at(size_type i)
{
 assert_msg(i<num_of_elements,"i=="<<i<<"\nN=="<<num_of_elements);

 //TODO: by standart - use exception for invalid index

 return this->buffer()[i];
}//at

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_reference t_fix_vector<N,T>::at(size_type i)const
{
 assert_msg(i<num_of_elements,"i=="<<i<<"\nN=="<<num_of_elements);

 //TODO: by standart - use exception for invalid index

 return this->buffer()[i];
}//at

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::reference t_fix_vector<N,T>::front()
{
 assert(!this->empty());

 return this->buffer()[0];
}//front

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::reference t_fix_vector<N,T>::back()
{
 assert(!this->empty());

 return this->buffer()[this->size()-1];
}//back

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_reference t_fix_vector<N,T>::front()const
{
 assert(!this->empty());

 return this->buffer()[0];
}//front - const

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
typename t_fix_vector<N,T>::const_reference t_fix_vector<N,T>::back()const
{
 assert(!this->empty());

 return this->buffer()[this->size()-1];
}//back - const

//------------------------------------------------------------------------
template<size_t N,class T>
void t_fix_vector<N,T>::assign(const_iterator first,const_iterator last)
{
 assert(this->size()<=this->capacity());

 size_type const n(std::distance(first,last));

 if(this->capacity()<n)
  this->helper__throw_bad_alloc(n);

 std::pair<const_iterator,iterator>
  x(structure::copy(first,last,this->begin(),this->end()));

 if(x.first!=last)
 {
  for(;x.first!=last;++x.first)
   this->push_back(*x.first);
 }
 else
 if(x.second!=this->end())
 {
  this->erase(x.second,this->end());
 }
}//assign

//------------------------------------------------------------------------
template<size_t N,class T>
void t_fix_vector<N,T>::push_back(const value_type& x)
{
 if(this->size()==this->capacity())
  this->helper__throw_bad_alloc(this->size()+1);

 __generic_construct(this->buffer()+m_size,x); //throw

 ++m_size;
}//push_back

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0)

template<size_t N,class T>
template<class... Args>
void t_fix_vector<N,T>::emplace_back(Args&&... args)
{
 if(this->size()==this->capacity())
  this->helper__throw_bad_alloc(this->size()+1);

 __generic_construct(this->buffer()+m_size,__STL_FORWARD_VALUE(Args,args)...); //throw

 ++m_size;
}//emplace_back

#endif //COMP_CONF_SUPPORT_VARIADIC_TEMPLATES!=0

//------------------------------------------------------------------------
template<size_t N,class T>
RELEASE_CODE(inline)
void t_fix_vector<N,T>::pop_back()
{
 assert(m_size!=0);

 __STL_DESTROYER_FUNC(this->buffer()+m_size-1);

 --m_size;
}//pop_back

//------------------------------------------------------------------------
template<size_t N,class T>
void t_fix_vector<N,T>::resize(size_t const n)
{
 assert(this->size()<=this->capacity());

 if(n<m_size)
 {
  this->erase(this->begin()+n,this->end());
 }
 else
 if(m_size<n)
 {
  if(this->capacity()<n)
   this->helper__throw_bad_alloc(n);

  std::uninitialized_fill(this->buffer()+m_size,this->buffer()+n,value_type());

  m_size=n;
 }//if
}//resize

//------------------------------------------------------------------------
template<size_t N,class T>
typename t_fix_vector<N,T>::iterator
 t_fix_vector<N,T>::insert(iterator position,const value_type& x)
{
 assert(this->begin()<=position);
 assert(position<=this->end());

 if(this->size()==this->capacity())
  this->helper__throw_bad_alloc(this->size()+1);

 if(position==this->end())
 {
  __generic_construct(this->buffer()+m_size,x); //throw

  ++m_size;
 }
 else
 {
  assert(m_size!=0);

  pointer        dest(this->buffer()+m_size);
  const_iterator src(this->end()-1);

  //create new back element
  __generic_construct(dest,*src);

  ++m_size;

  while(src!=position)
  {
   --dest;
   --src;

   (*dest)=*src;
  }//while

  assert(src==position);
  assert(src!=this->end());

  (*position)=x;
 }//else

 return position;
}//insert

//------------------------------------------------------------------------
template<size_t N,class T>
typename t_fix_vector<N,T>::iterator
 t_fix_vector<N,T>::erase(iterator first,iterator last)
{
 assert(first<=last);
 assert(this->begin()<=first);
 assert(last<=this->end());

 assert(this->size()<=this->capacity());

 if(first==last)
  return last;

 //copying [last,end) -> [first,end]
 std::pair<iterator,iterator>
  const x(structure::copy(last,this->end(),first,this->end()));

 assert(x.first==this->end());
 assert(x.second!=this->end());

 //removing a tail
 structure::__generic_destroyer_range(x.second,this->end());

 m_size=static_cast<size_type>(x.second-this->begin());

 assert(this->begin()<=first);
 assert(first<=this->end());

 return first;
}//erase

//------------------------------------------------------------------------
template<size_t N,class T>
typename t_fix_vector<N,T>::iterator t_fix_vector<N,T>::erase(iterator x)
{
 assert(this->begin()<=x);
 assert(x<=this->end());

 if(x==this->end())
  return x;

 return this->erase(x,x+1);
}//erase

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)

template<size_t N,class T>
template<typename Iterator>
void t_fix_vector<N,T>::construct(Iterator first,Iterator last,std::input_iterator_tag)
{
 assert(this->empty());

 for(;first!=last;++first)
  this->push_back(*first); //throw
}//construct - input_iterator_tag

#endif //COMP_CONF_SUPPORT_MEMBER_TEMPLATE

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)

template<size_t N,class T>
template<typename Iterator>
void t_fix_vector<N,T>::construct(Iterator first,Iterator last,std::random_access_iterator_tag)

#else

template<size_t N,class T>
void t_fix_vector<N,T>::construct(const_iterator first,const_iterator last)

#endif //!COMP_CONF_SUPPORT_MEMBER_TEMPLATE
{
 assert(first<=last);
 assert(this->empty());

 const size_type n=static_cast<size_type>(last-first);

 if(this->capacity()<n)
  this->helper__throw_bad_alloc(n);

 typedef std::pair<Iterator,pointer>    copy_res_type;

 DEBUG_CODE(const copy_res_type copy_res=)
  structure::uninitialized_copy
   (first,
    last,
    this->buffer(),
    this->buffer()+this->capacity());

 assert(copy_res.first==last);
 assert(copy_res.second==this->buffer()+n);

 m_size=n;
}//construct - random_access_iterator_tag

//------------------------------------------------------------------------
template<size_t N,class T>
void t_fix_vector<N,T>::helper__throw_bad_alloc(size_type /*n*/)
{
 throw std::bad_alloc();
}//helper__throw_bad_alloc

////////////////////////////////////////////////////////////////////////////////
//non-member operators

template<size_t N,class T>
inline bool operator == (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b)
{
 return (a.size()==b.size())
         ?structure::equal(a.begin(),a.end(),b.begin(),b.end())
         :false;
}//operator ==

//------------------------------------------------------------------------
template<size_t N,class T>
inline bool operator != (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b)
{
 return !(a==b);
}//operator !=

//------------------------------------------------------------------------
template<size_t N,class T>
bool operator < (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b)
{
 return std::lexicographical_compare(a.begin(),a.end(),
                                     b.begin(),b.end(),
                                     std::less<T>());
}//operator <

//------------------------------------------------------------------------
template<size_t N,class T>
inline bool operator <= (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b)
{
 return !(b<a);
}//operator <=

//------------------------------------------------------------------------
template<size_t N,class T>
inline bool operator >  (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b)
{
 return b<a;
}//operator >

//------------------------------------------------------------------------
template<size_t N,class T>
inline bool operator >= (const t_fix_vector<N,T>& a,const t_fix_vector<N,T>& b)
{
 return !(a<b);
}//operator >=

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
