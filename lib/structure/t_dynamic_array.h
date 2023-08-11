////////////////////////////////////////////////////////////////////////////////
//Implementation of dynamic array with fixed length
//                                                Dmitry Kovalenko. 12.06.2004
#ifndef _t_dynamic_array_H_
#define _t_dynamic_array_H_

# include <structure/t_simple_buffer.h>

#ifndef NDEBUG
# include <structure/t_vector_debug_iterator.h>
#endif

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class T,class Allocator=std::allocator<T> >
class t_dynamic_array;

////////////////////////////////////////////////////////////////////////////////
//class t_dynamic_array

template<class T,class Allocator>
class t_dynamic_array
{
 private:
  typedef t_dynamic_array<T,Allocator>                     self_type;

  t_dynamic_array(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef T                                                value_type;

  typedef t_typed_simple_buffer<value_type,Allocator>      buffer_type;

  typedef typename buffer_type::size_type                  size_type;
  typedef typename buffer_type::difference_type            difference_type;

  typedef typename buffer_type::pointer                    pointer;
  typedef typename buffer_type::const_pointer              const_pointer;

  typedef typename buffer_type::reference                  reference;
  typedef typename buffer_type::const_reference            const_reference;

 #ifndef NDEBUG //debug code
  typedef t_vector_debug_iterator<self_type>               iterator;
  typedef t_vector_debug_const_iterator<self_type>         const_iterator;
 #else
  typedef pointer                                          iterator;
  typedef const_pointer                                    const_iterator;
 #endif

 public:
  t_dynamic_array();

  explicit t_dynamic_array(size_type n);

 ~t_dynamic_array();

  //selectors ------------------------------------------------------------
  size_type size()const;

  bool empty()const;

  pointer data();

  const_pointer data()const;

  iterator begin();
  iterator end();

  const_iterator begin()const;
  const_iterator end()const;

  const_iterator cbegin();
  const_iterator cend();

  reference       operator [] (size_type i);
  const_reference operator [] (size_type i)const;

  reference       at(size_type i);
  const_reference at(size_type i)const;

  //modificators ---------------------------------------------------------
  void clear();

  void init(size_type n);

  void swap(self_type& x);

 private:
  COMP_CONF_DECLSPEC_NORETURN
  void helper__throw_range_error(size_type i)const;//throw

 private:
  buffer_type m_buffer;
};//class t_dynamic_array

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_dynamic_array.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
