////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 14.07.2009.
#ifndef _cpp_public_lcpi_lib_structure__t_simple_buffer_H_
#define _cpp_public_lcpi_lib_structure__t_simple_buffer_H_

#include <lcpi/lib/structure/t_memory.h>
#include <type_traits>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

#ifndef LCPI_STL_HAS_ENABLE_IF
# error LCPI_STL_HAS_ENABLE_IF is not defined!
#endif

#ifndef LCPI_STL_HAS_NEGATION
# error LCPI_STL_HAS_NEGATION is not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//content

template<class T,class Allocator>
class t_simple_buffer;

template<class Allocator>
using t_void_simple_buffer
 =t_simple_buffer<void,Allocator>;

#if(LCPI_STL_HAS_ENABLE_IF!=0 && LCPI_STL_HAS_NEGATION!=0)

// A variant with verification
template<class T,class Allocator>
using t_typed_simple_buffer
 =t_simple_buffer<typename std::enable_if<std::negation<std::is_same<T,void> >::value,T>::type,Allocator>;

#else

// A simple variant (VS2013)
template<class T,class Allocator>
using t_typed_simple_buffer
 =t_simple_buffer<T,Allocator>;

#endif

////////////////////////////////////////////////////////////////////////////////
//template class t_simple_buffer - void specialization

template<class Allocator>
class t_simple_buffer<void,Allocator> LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_simple_buffer;

  t_simple_buffer(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedef -------------------------------------------------------
  using value_type=void;

  using allocator_type=Allocator;

  using __value_alloc_type
   =typename allocator_type::template rebind<value_type>::other;

  using size_type
   =typename __value_alloc_type::size_type;

  using pointer
   =typename __value_alloc_type::pointer;

  using const_pointer
   =typename __value_alloc_type::const_pointer;

 public:
  t_simple_buffer();

  explicit t_simple_buffer(size_type const sz);

 ~t_simple_buffer();

 public: //selectors -----------------------------------------------------
  pointer       buffer()            {return m_buffer;}
  pointer       buffer_end()        {return static_cast<char*>(m_buffer)+m_size;}

  const_pointer buffer()      const {return m_buffer;}
  const_pointer buffer_end()  const {return static_cast<char*>(m_buffer)+m_size;}

  pointer       data()              {return m_buffer;}
  const_pointer data()        const {return m_buffer;}

  size_type     capacity()    const {return m_capacity;}

  size_type     size()        const {return m_size;}
  size_type     memory_size() const {return m_size;}

  bool          empty()       const {return m_size==0;}

 public: //accessors -----------------------------------------------------
  pointer ptr_at(size_type i)const;

 public: //buffer managements --------------------------------------------
  pointer alloc(size_type sz);

  void free();

  void swap(self_type& x);

  void truncate(size_type sz);

 private:
  __value_alloc_type   m_alloc;
  pointer              m_buffer;
  size_type            m_size;
  size_type            m_capacity;
};//class t_simple_buffer<void,Allocator>

////////////////////////////////////////////////////////////////////////////////
//template class t_simple_buffer

template<class T,class Allocator>
class t_simple_buffer LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_simple_buffer;

  t_simple_buffer(const self_type&)=delete;
  self_type& operator = (const self_type& x)=delete;

 public: //typedefs ------------------------------------------------------
  using value_type=T;

  using allocator_type=Allocator;

  using __value_alloc_type
   =typename Allocator::template rebind<value_type>::other;

  using size_type
   =typename __value_alloc_type::size_type;

  using difference_type
   =typename __value_alloc_type::difference_type;

  using pointer
   =typename __value_alloc_type::pointer;

  using const_pointer
   =typename __value_alloc_type::const_pointer;

  using reference
   =typename __value_alloc_type::reference;

  using const_reference
   =typename __value_alloc_type::const_reference;

 public:
  t_simple_buffer();

  t_simple_buffer(self_type&&);

  explicit t_simple_buffer(size_type const sz);

  t_simple_buffer(const value_type* s,size_type const n);

 ~t_simple_buffer();

 public: //selectors -----------------------------------------------------
  pointer       buffer()             {return m_buffer;}
  pointer       buffer_end()         {return m_buffer+m_size;}

  const_pointer buffer()       const {return m_buffer;}
  const_pointer buffer_end()   const {return m_buffer+m_size;}

  pointer       data()               {return m_buffer;}
  const_pointer data()         const {return m_buffer;}

  size_t        capacity()     const {return m_capacity;};

  size_type     size()         const {return m_size;}
  size_type     memory_size()  const {return m_size*sizeof(value_type);}

  bool          empty()        const {return m_size==0;}

 public: //accessors -----------------------------------------------------
  reference operator [] (size_type const i);

  const_reference operator [] (size_type const i)const;

  pointer ptr_at(size_type const i);

  const_pointer ptr_at(size_type const i)const;

  reference front();
  reference back();

  const_reference front()const;
  const_reference back()const;

 public: //buffer managements --------------------------------------------
  void     clear();

  pointer  alloc(size_type sz);
  pointer  realloc(size_type sz);

  pointer  reserve(size_type new_capacity);

  void     free();

  void     swap(self_type& x);

 private: //order of declarations is important!
  __value_alloc_type m_alloc;
  pointer            m_buffer;
  size_type          m_size;
  size_type          m_capacity;
};//class t_simple_buffer

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/

namespace std{
////////////////////////////////////////////////////////////////////////////////
//std::swap specialization

template<class T,class Allocator>
inline void swap(structure::t_simple_buffer<T,Allocator>& a,
                 structure::t_simple_buffer<T,Allocator>& b)
{
 a.swap(b);
}//swap - t_simple_buffer

////////////////////////////////////////////////////////////////////////////////
}//namespace std
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/t_simple_buffer.cc>
////////////////////////////////////////////////////////////////////////////////
