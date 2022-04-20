////////////////////////////////////////////////////////////////////////////////
//Template class for managing a built-in array
//                                                 Kovalenko Dmitry. 18.09.2008.
#ifndef _t_built_in_array_H_
#define _t_built_in_array_H_

#include <structure/t_vector_debug_iterator.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_built_in_array

template<class T>
class t_built_in_array
{
 private:
  typedef t_built_in_array<T>                  self_type;

  t_built_in_array(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef T                                                value_type;

  typedef size_t                                           size_type;

  typedef ptrdiff_t                                        difference_type;

  typedef value_type*                                      pointer;
  typedef const value_type*                                const_pointer;

  typedef value_type&                                      reference;
  typedef const value_type&                                const_reference;

 #ifndef NDEBUG
   typedef t_vector_debug_iterator<self_type>              iterator;
   typedef t_vector_debug_const_iterator<self_type>        const_iterator;
 #else
  typedef value_type*                                      iterator;
  typedef const value_type*                                const_iterator;
 #endif

 public:
  t_built_in_array(pointer not_init_first,
                   pointer not_init_last);

  t_built_in_array(pointer       not_init_first,
                   pointer       not_init_last,
                   const_pointer source_first,
                   const_pointer source_last);

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<typename SourceIterator>
  t_built_in_array(pointer        not_init_first,
                   pointer        not_init_last,
                   SourceIterator source_first,
                   SourceIterator source_last);
 #endif

 ~t_built_in_array();

  //interface ------------------------------------------------------------
  self_type& release();

  //----------------------------------------------------------------------
  bool empty()const;

  size_type size()const;

  size_type capacity()const;

  reference operator [] (size_type i);

  const_reference operator [] (size_type i)const;

  reference at(size_type i);

  const_reference at(size_type i)const;

  //----------------------------------------------------------------------
  iterator begin();

  iterator end();

  const_iterator begin()const;

  const_iterator end()const;

  //----------------------------------------------------------------------
  reference front();

  const_reference front()const;

  reference back();

  const_reference back()const;

  //----------------------------------------------------------------------
  pointer data();

  const_pointer data()const;

 private:
  pointer m_first;
  pointer m_last;
};//class t_built_in_array

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_built_in_array.cc>
////////////////////////////////////////////////////////////////////////////////
#endif // _t_built_in_array_H_
