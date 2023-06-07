////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Library.
//                                                 Dmitry Kovalenko. 13.08.2002.
#ifndef _cpp_public_lcpi_lib_structure__t_memory_CC_
#define _cpp_public_lcpi_lib_structure__t_memory_CC_

#include <lcpi/lib/structure/t_negative_one.h>
#include <limits>
#include <new> // std::bad_alloc

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_raw_allocator

template<class RawMemManager>
t_raw_allocator<RawMemManager>
 t_raw_allocator<RawMemManager>::instance;

//------------------------------------------------------------------------
template<class RawMemManager>
inline t_raw_allocator<RawMemManager>::t_raw_allocator()
{;}

//------------------------------------------------------------------------
template<class RawMemManager>
inline t_raw_allocator<RawMemManager>::t_raw_allocator(const self_type& /*x*/)
{;}

//------------------------------------------------------------------------
template<class RawMemManager>
template<class U>
inline t_raw_allocator<RawMemManager>::t_raw_allocator(const structure::t_allocator_interface<self_type,U>&)
{;}

//------------------------------------------------------------------------
template<class RawMemManager>
inline t_raw_allocator<RawMemManager>&
 t_raw_allocator<RawMemManager>::operator = (const self_type& /*x*/)
{
 return *this;
}//operator =

//------------------------------------------------------------------------
template<class RawMemManager>
inline bool t_raw_allocator<RawMemManager>::operator == (const self_type& /*x*/)const
{
 return true;
}//operator ==

//------------------------------------------------------------------------
template<class RawMemManager>
inline bool t_raw_allocator<RawMemManager>::operator != (const self_type& x)const
{
 return false;
}//operator !=

//------------------------------------------------------------------------
template<class RawMemManager>
inline typename t_raw_allocator<RawMemManager>::pointer
 t_raw_allocator<RawMemManager>::allocate(size_type const n,
                                          pointer   const LCPI__DEBUG_CODE(ptr))
{
 LCPI__assert(ptr==nullptr);

 return adapter::raw_allocate(n);
}//allocate

//------------------------------------------------------------------------
template<class RawMemManager>
inline void t_raw_allocator<RawMemManager>::deallocate(pointer   const p,
                                                       size_type const /*size*/)
{
 return adapter::raw_deallocate(p);
}//deallocate

//------------------------------------------------------------------------
template<class RawMemManager>
inline typename t_raw_allocator<RawMemManager>::size_type
 t_raw_allocator<RawMemManager>::max_size()const
{
 return structure::negative_one;
}//max_size

//------------------------------------------------------------------------
template<class RawMemManager>
inline typename t_raw_allocator<RawMemManager>::size_type
 t_raw_allocator<RawMemManager>::max_size(size_type const size)const
{
 LCPI__assert(size>0);

 const size_type n(this->max_size()/size);

 return (0<n)?n:1;
}//max_size

//------------------------------------------------------------------------
template<class RawMemManager>
inline void t_raw_allocator<RawMemManager>::swap(self_type& /*x*/)
{;}

////////////////////////////////////////////////////////////////////////////////
//template class t_allocator_interface

template <class Allocator,class T>
t_allocator_interface<Allocator,T>
 t_allocator_interface<Allocator,T>::instance;

//------------------------------------------------------------------------
template <class Allocator,class T>
inline t_allocator_interface<Allocator,T>::t_allocator_interface()
{;}

//------------------------------------------------------------------------
template <class Allocator,class T>
inline t_allocator_interface<Allocator,T>::t_allocator_interface(const self_type& /*x*/)
{;}

//------------------------------------------------------------------------
template <class Allocator,class T>
template<class U>
inline
t_allocator_interface<Allocator,T>::t_allocator_interface(const t_allocator_interface<Allocator,U>& /*x*/)
{;}

//------------------------------------------------------------------------
template <class Allocator,class T>
inline
t_allocator_interface<Allocator,T>::t_allocator_interface(const Allocator& /*a*/)
{;}

//------------------------------------------------------------------------
template <class Allocator,class T>
inline t_allocator_interface<Allocator,T>&
 t_allocator_interface<Allocator,T>::operator = (const self_type& /*x*/)
{
 return *this;
}//operator =

//------------------------------------------------------------------------
template <class Allocator,class T>
inline typename t_allocator_interface<Allocator,T>::pointer
 t_allocator_interface<Allocator,T>::address(reference x)const
{
 return static_cast<pointer>(&x);
}//address

//------------------------------------------------------------------------
template <class Allocator,class T>
inline typename t_allocator_interface<Allocator,T>::size_type
 t_allocator_interface<Allocator,T>::max_size()const
{
 return raw_allocator_type::instance.max_size(sizeof(value_type));
}//max_size

//------------------------------------------------------------------------
template <class Allocator,class T>
inline typename t_allocator_interface<Allocator,T>::pointer
 t_allocator_interface<Allocator,T>::allocate(size_type const n,
                                              pointer   const p)
{
 if(this->max_size()<n)
  throw std::bad_alloc();

 return static_cast<pointer>(raw_allocator_type::instance.allocate(n*sizeof(value_type),p));
}//allocate

//------------------------------------------------------------------------
template <class Allocator,class T>
inline void t_allocator_interface<Allocator,T>::deallocate(pointer   const p,
                                                           size_type const n)
{
 LCPI__assert(n<=this->max_size());

 raw_allocator_type::instance.deallocate(p,n*sizeof(value_type));
}//deallocate

//------------------------------------------------------------------------
template<class Allocator,class T>
template<class... Args>
inline void
 t_allocator_interface<Allocator,T>::construct(pointer const p,
                                               Args&&...     args)
{
 __generic_construct(p,__STL_FORWARD_VALUE(Args,args)...);
}//construct

//------------------------------------------------------------------------
template<class Allocator,class T>
inline void t_allocator_interface<Allocator,T>::destroy(pointer const p)
{
 __generic_destroy(p);
}//destroy

//------------------------------------------------------------------------
template<class Allocator,class T>
inline void t_allocator_interface<Allocator,T>::swap(self_type& LCPI__UNUSED_ARG(x))
{
 /*nop*/
}//swap

////////////////////////////////////////////////////////////////////////////////
//class t_void_allocator_adapter

inline void* t_void_allocator_adapter::raw_allocate(size_t const n)
{
 if(n==0)
  return nullptr;

 if(void* const p=static_cast<void*>(::operator new(n)))
  return p;

 throw std::bad_alloc();
}//raw_allocate

//------------------------------------------------------------------------
inline void t_void_allocator_adapter::raw_deallocate(void* const p)
{
 if(p)
  ::operator delete(p);
}//raw_deallocate

////////////////////////////////////////////////////////////////////////////////
//memory management utilities

// one for all
template<class T,class... Args>
inline void __generic_construct(T* const p,Args&&... args)
{
 ::new(reinterpret_cast<void*>(p)) T(std::forward<Args>(args)...);
}//__generic_construct

//------------------------------------------------------------------------
template<class T>
inline void __generic_destroy(T* const p)
{
 p->~T();
}//__generic_destroy

//------------------------------------------------------------------------
template<class ForwardIterator>
void __generic_destroyer_range(ForwardIterator first,ForwardIterator last)
{
 for(;first!=last;++first)
 {
  __generic_destroy(&*first);
 }
}//__generic_destroyer_range

//------------------------------------------------------------------------
template<class ForwardIterator>
ForwardIterator uninitialize_init(ForwardIterator first,ForwardIterator last)
{
 const ForwardIterator start(first);

 try
 {
  for(;first!=last;++first)
   structure::__generic_construct(&*first);
 }
 catch(...)
 {
  __generic_destroyer_range(start,first);

  throw;
 }//catch

 return first;
}//uninitialize_init

//------------------------------------------------------------------------
template<class InputIterator,class ForwardIterator>
std::pair<InputIterator,ForwardIterator>
 uninitialized_copy(InputIterator   first,
                    InputIterator   last,
                    ForwardIterator dest_first,
                    ForwardIterator dest_last)
{
 const ForwardIterator dest_start(dest_first);

 try
 {
  for(;first!=last && dest_first!=dest_last;++first,++dest_first)
   structure::__generic_construct(&*dest_first,*first);
 }
 catch(...)
 {
  __generic_destroyer_range(dest_start,dest_first);

  throw;
 }//catch

 return std::make_pair(first,dest_first);
}//uninitialized_copy

////////////////////////////////////////////////////////////////////////////////

inline bool append_memory_size(size_t& s,size_t const delta)
{
 const size_t c_max_sz=(::std::numeric_limits<size_t>::max)();

 LCPI__assert(s<=c_max_sz);

 if((c_max_sz-s)<delta)
  return false;

 s+=delta;

 return true;
}//append_memory_size

////////////////////////////////////////////////////////////////////////////////

inline bool append_array_memory_size(size_t&      s,
                                     size_t const element_size,
                                     size_t const element_count)
{
 LCPI__assert(element_size>0);

 const size_t c_max_sz=(::std::numeric_limits<size_t>::max)();

 LCPI__assert(s<=c_max_sz);
 LCPI__assert(element_size<=c_max_sz);
 LCPI__assert(element_count<=c_max_sz);

 if(((c_max_sz-s)/element_size)<element_count)
  return false;

 const size_t array_mem_size=element_size*element_count;

 s+=array_mem_size;

 return true;
}//append_array_memory_size

////////////////////////////////////////////////////////////////////////////////

inline bool align_memory_size(size_t& s,size_t const a)
{
 LCPI__assert(a>0);

 const size_t mod=size_t(s%a);

 if(mod==0)
  return true;

 LCPI__assert(mod<=s);
 LCPI__assert(mod<a);

 return append_memory_size(s, (a-mod));
}//align_memory_size

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
