////////////////////////////////////////////////////////////////////////////////
//Utility classes
//                                                  Dmitry Kovalenko. 04.09.2016
#ifndef _t_first_last_H_
#define _t_first_last_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_first_last

template<typename T>
class t_first_last
{
 private:
  typedef t_first_last<T>          self_type;

 public: //typedefs
  typedef T                        value_type;

 public:
  value_type first;
  value_type last;

  t_first_last();

  t_first_last(const self_type& x);

  t_first_last(const value_type& f,const value_type& l);

 ~t_first_last();

  self_type& operator = (const self_type& x);

  bool empty()const;
};//class t_first_last

////////////////////////////////////////////////////////////////////////////////

template<typename T>
t_first_last<T> make_first_last(const T& first,const T& last)
{
 return t_first_last<T>(first,last);
}//make_first_last

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/t_first_last.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
