////////////////////////////////////////////////////////////////////////////////
//Container for pointers to smart objects
//                                     Kovalenko Dmitry. February 3, 2001.
#ifndef _t_smart_vector_H_
#define _t_smart_vector_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/t_smart_object.h>
#include <structure/stl/t_stl_vector.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_smart_vector

#if(COMP_CONF_SUPPORT_TEMPLATE_USING!=0)

template<class T,class Allocator=t_void_allocator>
using t_smart_vector=t_stl_vector<t_smart_object_ptr<T>,Allocator>;

#else

template<class T,class Allocator=t_void_allocator>
class t_smart_vector:public std::vector<t_smart_object_ptr<T>,Allocator>
{
 private:
  typedef t_smart_vector<T,Allocator>                         self_type;
  typedef std::vector<t_smart_object_ptr<T>,Allocator>        inherited;

 public: //typedefs -----------------------------------------------------
  typedef typename inherited::size_type                       size_type;
  typedef typename inherited::iterator                        iterator;
  typedef typename inherited::const_iterator                  const_iterator;

  typedef typename inherited::value_type                      value_type;

 public:
  explicit t_smart_vector(const Allocator& alloc=Allocator());

  explicit t_smart_vector(size_type n,
                          const Allocator& alloc=Allocator());

  t_smart_vector(const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  t_smart_vector(self_type&& x);
 #endif

  t_smart_vector(size_type         n,
                 const value_type& x,
                 const Allocator&  alloc=Allocator());

 #if(COMP_CONF_SUPPORT_MEMBER_TEMPLATE)
  template<class InputIterator>
  t_smart_vector(InputIterator    first,
                 InputIterator    last,
                 const Allocator& alloc=Allocator());
 #else
  t_smart_vector(const_iterator   first,
                 const_iterator   last,
                 const Allocator& alloc=Allocator());
 #endif

  self_type& operator = (const self_type& x);

 #if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
  self_type& operator = (self_type&& x);
 #endif
};//class t_smart_vector

#endif

////////////////////////////////////////////////////////////////////////////////
}//namespace structure

#if(COMP_CONF_SUPPORT_TEMPLATE_USING==0)

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<class T,class Allocator>
void swap(structure::t_smart_vector<T,Allocator>& x1,
          structure::t_smart_vector<T,Allocator>& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std

#endif

////////////////////////////////////////////////////////////////////////////////
#include <structure/t_smart_vector.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
