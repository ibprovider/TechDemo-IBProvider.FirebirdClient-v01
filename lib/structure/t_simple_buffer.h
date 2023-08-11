////////////////////////////////////////////////////////////////////////////////
//Templates of simple buffers at memory
//                                                 Kovalenko Dmitry. 14.07.2009
#ifndef _t_simple_buffer_H_
#define _t_simple_buffer_H_

#include <structure/t_memory.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class Allocator>
class t_void_simple_buffer;

template<class T,class Allocator>
class t_typed_simple_buffer;

////////////////////////////////////////////////////////////////////////////////
//template class t_void_simple_buffer

template<class Allocator>
class t_void_simple_buffer
{
 private:
  typedef t_void_simple_buffer<Allocator>               self_type;

  t_void_simple_buffer(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedef -------------------------------------------------------
  typedef Allocator                                     allocator_type;

  typedef typename __STLS_ALLOCATOR_REBIND(allocator_type,
                                           char)        __value_alloc_type;

  typedef typename __value_alloc_type::size_type        size_type;

  typedef void                                          value_type;
  typedef value_type*                                   pointer;
  typedef const value_type*                             const_pointer;

 public:
  t_void_simple_buffer();

  explicit t_void_simple_buffer(size_type const sz);

 ~t_void_simple_buffer();

 public: //selectors -----------------------------------------------------
  pointer       buffer()            {return m_buffer;}
  pointer       buffer_end()        {return static_cast<char*>(m_buffer)+m_size;}

  const_pointer buffer()      const {return m_buffer;}
  const_pointer buffer_end()  const {return static_cast<char*>(m_buffer)+m_size;}

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
};//class t_void_simple_buffer

////////////////////////////////////////////////////////////////////////////////
//template class t_typed_simple_buffer

template<class T,class Allocator>
class t_typed_simple_buffer
{
 private:
  typedef t_typed_simple_buffer<T,Allocator>                      self_type;

  t_typed_simple_buffer(const self_type&);
  self_type& operator = (const self_type& x);

 public: //typedefs ------------------------------------------------------
  typedef T                                                       value_type;
  typedef Allocator                                               allocator_type;

  typedef typename __STLS_ALLOCATOR_REBIND(Allocator,value_type)  __value_alloc_type;

  typedef typename __value_alloc_type::size_type                  size_type;
  typedef typename __value_alloc_type::difference_type            difference_type;

  typedef typename __value_alloc_type::pointer                    pointer;
  typedef typename __value_alloc_type::const_pointer              const_pointer;
  typedef typename __value_alloc_type::reference                  reference;
  typedef typename __value_alloc_type::const_reference            const_reference;

 public:
  t_typed_simple_buffer();

  t_typed_simple_buffer(self_type&&);

  explicit t_typed_simple_buffer(size_type const sz);

  t_typed_simple_buffer(const value_type* s,size_type const n);

 ~t_typed_simple_buffer();

 public: //selectors -----------------------------------------------------
  pointer       buffer()             {return m_buffer;}
  pointer       buffer_end()         {return m_buffer+m_size;}

  const_pointer buffer()       const {return m_buffer;}
  const_pointer buffer_end()   const {return m_buffer+m_size;}

  pointer       data()               {return m_buffer;}
  const_pointer data()         const {return m_buffer;}

  size_type     size()         const {return m_size;}
  size_type     memory_size()  const {return m_size*sizeof(value_type);}

  size_t        capacity()     const {return m_capacity;};

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
};//class t_typed_simple_buffer

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

namespace std{
////////////////////////////////////////////////////////////////////////////////
//std::swap specialization

template<class Allocator>
inline void swap(structure::t_void_simple_buffer<Allocator>& a,
                 structure::t_void_simple_buffer<Allocator>& b)
{
 a.swap(b);
}//swap - t_void_simple_buffer

//------------------------------------------------------------------------
template<class T,class Allocator>
inline void swap(structure::t_typed_simple_buffer<T,Allocator>& a,
                 structure::t_typed_simple_buffer<T,Allocator>& b)
{
 a.swap(b);
}//swap - t_typed_simple_buffer

////////////////////////////////////////////////////////////////////////////////
}//namespace std
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_simple_buffer.cc>
////////////////////////////////////////////////////////////////////////////////
