////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 14.07.2003.
#ifndef _cpp_public_lcpi_lib_structure__t_fix_vector_CC_
#define _cpp_public_lcpi_lib_structure__t_fix_vector_CC_

#include <lcpi/lib/structure/t_algorithm.h>
#include <lcpi/lib/structure/t_memory.h>
#include <iterator>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//template class t_fix_vector_base

template<class T,size_t N>
inline t_fix_vector_base<T,N>::t_fix_vector_base()
 :m_size(0)
{
}

//------------------------------------------------------------------------
template<class T,size_t N>
t_fix_vector_base<T,N>::~t_fix_vector_base()
{
 this->clear();
}//~t_fix_vector_base

//------------------------------------------------------------------------
template<class T,size_t N>
void t_fix_vector_base<T,N>::clear()
{
 LCPI__assert(m_size<=self_type::num_of_elements);

 structure::__generic_destroyer_range(this->buffer(),this->buffer()+m_size);

 m_size=0;
}//clear

//------------------------------------------------------------------------
template<class T,size_t N>
inline typename t_fix_vector_base<T,N>::pointer t_fix_vector_base<T,N>::buffer()
{
 return reinterpret_cast<T*>(m_buffer);
}//buffer

//------------------------------------------------------------------------
template<class T,size_t N>
inline typename t_fix_vector_base<T,N>::const_pointer t_fix_vector_base<T,N>::buffer()const
{
 return reinterpret_cast<const T*>(m_buffer);
}//buffer - const

////////////////////////////////////////////////////////////////////////////////
//template class t_fix_vector

template<class T,size_t N>
inline t_fix_vector<T,N>::t_fix_vector()
{
}

//------------------------------------------------------------------------
template<class T,size_t N>
t_fix_vector<T,N>::t_fix_vector(size_type const n)
{
 this->resize(n);
}//t_fix_vector

//------------------------------------------------------------------------
template<class T,size_t N>
t_fix_vector<T,N>::t_fix_vector(const self_type& x)
{
 LCPI__assert(x.size()<=self_type::num_of_elements);

 structure::uninitialized_copy
  (x.begin(),
   x.end(),
   this->buffer(),
   this->buffer()+x.size());

 m_size=x.size();
}//t_fix_vector - copy

//------------------------------------------------------------------------
template<class T,size_t N>
template<typename Iterator>
t_fix_vector<T,N>::t_fix_vector(Iterator first,Iterator last)
{
 typedef std::iterator_traits<Iterator>::iterator_category __cat;

 this->construct(first,last,__cat());
}//t_fix_vector

//------------------------------------------------------------------------
template<class T,size_t N>
t_fix_vector<T,N>::~t_fix_vector()
{
}

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::self_type& t_fix_vector<T,N>::operator = (const self_type& x)
{
 this->assign(x.begin(),x.end());

 return *this;
}//operator =

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::iterator t_fix_vector<T,N>::begin()
{
#ifndef NDEBUG
 return iterator(this,this->buffer());
#else
 return iterator(this->buffer());
#endif
}//begin

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::iterator t_fix_vector<T,N>::end()
{
#ifndef NDEBUG
 return iterator(this,this->buffer()+this->size());
#else
 return iterator(this->buffer()+this->size());
#endif
}//end

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_iterator t_fix_vector<T,N>::cbegin()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer());
#else
 return const_iterator(this->buffer());
#endif
}//cbegin

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_iterator t_fix_vector<T,N>::cend()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer()+this->size());
#else
 return const_iterator(this->buffer()+this->size());
#endif
}//cend

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_iterator t_fix_vector<T,N>::begin()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer());
#else
 return const_iterator(this->buffer());
#endif
}//begin - const

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_iterator t_fix_vector<T,N>::end()const
{
#ifndef NDEBUG
 return const_iterator(this,this->buffer()+this->size());
#else
 return const_iterator(this->buffer()+this->size());
#endif
}//end - const

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::size_type t_fix_vector<T,N>::size()const
{
 LCPI__assert(m_size<=num_of_elements);

 return m_size;
}//size

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
bool t_fix_vector<T,N>::empty()const
{
 LCPI__assert(m_size<=num_of_elements);

 return m_size==0;
}//empty

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
bool t_fix_vector<T,N>::full()const
{
 LCPI__assert(m_size<=num_of_elements);

 return m_size==num_of_elements;
}//full

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::size_type t_fix_vector<T,N>::capacity()const
{
 LCPI__assert(m_size<=num_of_elements);

 return num_of_elements;
}//capacity

//------------------------------------------------------------------------
template<class T,size_t N>
typename t_fix_vector<T,N>::pointer t_fix_vector<T,N>::data()
{
 return this->buffer();
}//data

//------------------------------------------------------------------------
template<class T,size_t N>
typename t_fix_vector<T,N>::const_pointer t_fix_vector<T,N>::data()const
{
 return this->buffer();
}//data

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::reference t_fix_vector<T,N>::operator [] (size_type i)
{
 LCPI__assert_msg(i<this->size(),"i=="<<i<<"\nN=="<<this->size());
 return this->buffer()[i];
}//operator []

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_reference t_fix_vector<T,N>::operator [] (size_type i)const
{
 LCPI__assert_msg(i<num_of_elements,"i=="<<i<<"\nN=="<<num_of_elements);
 return this->buffer()[i];
}//operator [] - const

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::reference t_fix_vector<T,N>::at(size_type i)
{
 LCPI__assert_msg(i<num_of_elements,"i=="<<i<<"\nN=="<<num_of_elements);

 //TODO: by standart - use exception for invalid index

 return this->buffer()[i];
}//at

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_reference t_fix_vector<T,N>::at(size_type i)const
{
 LCPI__assert_msg(i<num_of_elements,"i=="<<i<<"\nN=="<<num_of_elements);

 //TODO: by standart - use exception for invalid index

 return this->buffer()[i];
}//at

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::reference t_fix_vector<T,N>::front()
{
 LCPI__assert(!this->empty());

 return this->buffer()[0];
}//front

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::reference t_fix_vector<T,N>::back()
{
 LCPI__assert(!this->empty());

 return this->buffer()[this->size()-1];
}//back

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_reference t_fix_vector<T,N>::front()const
{
 LCPI__assert(!this->empty());

 return this->buffer()[0];
}//front - const

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
typename t_fix_vector<T,N>::const_reference t_fix_vector<T,N>::back()const
{
 LCPI__assert(!this->empty());

 return this->buffer()[this->size()-1];
}//back - const

//------------------------------------------------------------------------
template<class T,size_t N>
template<typename Iterator>
void t_fix_vector<T,N>::assign(Iterator first,Iterator last)
{
 LCPI__assert(this->size()<=this->capacity());

 size_type const n(std::distance(first,last));

 if(this->capacity()<n)
  this->helper__throw_bad_alloc(n);

 std::pair<Iterator,iterator>
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
template<class T,size_t N>
void t_fix_vector<T,N>::push_back(const value_type& x)
{
 if(this->size()==this->capacity())
  this->helper__throw_bad_alloc(this->size()+1);

 __generic_construct(this->buffer()+m_size,x); //throw

 ++m_size;
}//push_back

//------------------------------------------------------------------------
template<class T,size_t N>
template<class... Args>
void t_fix_vector<T,N>::emplace_back(Args&&... args)
{
 if(this->size()==this->capacity())
  this->helper__throw_bad_alloc(this->size()+1);

 __generic_construct(this->buffer()+m_size,LCPI_STL_FORWARD_VALUE(Args,args)...); //throw

 ++m_size;
}//emplace_back

//------------------------------------------------------------------------
template<class T,size_t N>
LCPI__RELEASE_CODE(inline)
void t_fix_vector<T,N>::pop_back()
{
 LCPI__assert(m_size!=0);

 structure::__generic_destroy(this->buffer()+m_size-1);

 --m_size;
}//pop_back

//------------------------------------------------------------------------
template<class T,size_t N>
void t_fix_vector<T,N>::resize(size_t const n)
{
 LCPI__assert(this->size()<=this->capacity());

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
template<class T,size_t N>
typename t_fix_vector<T,N>::iterator
 t_fix_vector<T,N>::insert(iterator position,const value_type& x)
{
 LCPI__assert(this->begin()<=position);
 LCPI__assert(position<=this->end());

 if(this->size()==this->capacity())
  this->helper__throw_bad_alloc(this->size()+1);

 if(position==this->end())
 {
  __generic_construct(this->buffer()+m_size,x); //throw

  ++m_size;
 }
 else
 {
  LCPI__assert(m_size!=0);

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

  LCPI__assert(src==position);
  LCPI__assert(src!=this->end());

  (*position)=x;
 }//else

 return position;
}//insert

//------------------------------------------------------------------------
template<class T,size_t N>
typename t_fix_vector<T,N>::iterator
 t_fix_vector<T,N>::erase(iterator first,iterator last)
{
 LCPI__assert(first<=last);
 LCPI__assert(this->begin()<=first);
 LCPI__assert(last<=this->end());

 LCPI__assert(this->size()<=this->capacity());

 if(first==last)
  return last;

 //copying [last,end) -> [first,end]
 std::pair<iterator,iterator>
  const x(structure::copy(last,this->end(),first,this->end()));

 LCPI__assert(x.first==this->end());
 LCPI__assert(x.second!=this->end());

 //removing a tail
 structure::__generic_destroyer_range(x.second,this->end());

 m_size=static_cast<size_type>(x.second-this->begin());

 LCPI__assert(this->begin()<=first);
 LCPI__assert(first<=this->end());

 return first;
}//erase

//------------------------------------------------------------------------
template<class T,size_t N>
typename t_fix_vector<T,N>::iterator t_fix_vector<T,N>::erase(iterator x)
{
 LCPI__assert(this->begin()<=x);
 LCPI__assert(x<=this->end());

 if(x==this->end())
  return x;

 return this->erase(x,x+1);
}//erase

//------------------------------------------------------------------------
template<class T,size_t N>
template<typename Iterator>
void t_fix_vector<T,N>::construct(Iterator first,Iterator last,std::input_iterator_tag)
{
 LCPI__assert(this->empty());

 for(;first!=last;++first)
  this->push_back(*first); //throw
}//construct - input_iterator_tag

//------------------------------------------------------------------------
template<class T,size_t N>
template<typename Iterator>
void t_fix_vector<T,N>::construct(Iterator first,Iterator last,std::random_access_iterator_tag)
{
 LCPI__assert(first<=last);
 LCPI__assert(this->empty());

 const size_type n=static_cast<size_type>(last-first);

 if(this->capacity()<n)
  this->helper__throw_bad_alloc(n);

 typedef std::pair<Iterator,pointer>    copy_res_type;

 LCPI__DEBUG_CODE(const copy_res_type copy_res=)
  structure::uninitialized_copy
   (first,
    last,
    this->buffer(),
    this->buffer()+this->capacity());

 LCPI__assert(copy_res.first==last);
 LCPI__assert(copy_res.second==this->buffer()+n);

 m_size=n;
}//construct - random_access_iterator_tag

//------------------------------------------------------------------------
template<class T,size_t N>
void t_fix_vector<T,N>::helper__throw_bad_alloc(size_type /*n*/)
{
 throw std::bad_alloc();
}//helper__throw_bad_alloc

////////////////////////////////////////////////////////////////////////////////
//non-member operators

template<class T,size_t N>
inline bool operator == (const t_fix_vector<T,N>& a,const t_fix_vector<T,N>& b)
{
 return (a.size()==b.size())
         ?structure::equal(a.begin(),a.end(),b.begin(),b.end())
         :false;
}//operator ==

//------------------------------------------------------------------------
template<class T,size_t N>
inline bool operator != (const t_fix_vector<T,N>& a,const t_fix_vector<T,N>& b)
{
 return !(a==b);
}//operator !=

//------------------------------------------------------------------------
template<class T,size_t N>
bool operator < (const t_fix_vector<T,N>& a,const t_fix_vector<T,N>& b)
{
 return std::lexicographical_compare
         (a.begin(),a.end(),
          b.begin(),b.end(),
          std::less<T>());
}//operator <

//------------------------------------------------------------------------
template<class T,size_t N>
inline bool operator <= (const t_fix_vector<T,N>& a,const t_fix_vector<T,N>& b)
{
 return !(b<a);
}//operator <=

//------------------------------------------------------------------------
template<class T,size_t N>
inline bool operator >  (const t_fix_vector<T,N>& a,const t_fix_vector<T,N>& b)
{
 return b<a;
}//operator >

//------------------------------------------------------------------------
template<class T,size_t N>
inline bool operator >= (const t_fix_vector<T,N>& a,const t_fix_vector<T,N>& b)
{
 return !(a<b);
}//operator >=

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
