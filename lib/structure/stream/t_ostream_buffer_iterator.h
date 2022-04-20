////////////////////////////////////////////////////////////////////////////////
//Iterator for structure.t_basic_ostream_buffer
//                                                Kovalenko Dmitry. 16.10.2011.
#ifndef _t_ostream_buffer_iterator_H_
#define _t_ostream_buffer_iterator_H_

#include <structure/stream/t_ostream_buffer.h>
#include <iterator>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class T,class Traits=typename t_stream_buffer_traits__selector<T>::traits_type>
class t_basic_ostream_buffer_iterator;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_ostream_buffer_iterator

template<typename T,class Traits>
class t_basic_ostream_buffer_iterator
{
 private:
  typedef t_basic_ostream_buffer_iterator<T,Traits>         self_type;

 public: //typedefs ------------------------------------------------------
  typedef std::output_iterator_tag                          iterator_cattegory;
  typedef T                                                 value_type;
  typedef std::ptrdiff_t                                    difference_type;
  typedef T*                                                pointer;
  typedef T&                                                reference;

  typedef t_basic_ostream_buffer<T,Traits>                  buffer_type;

  typedef const value_type&                                 const_reference;

 public:
  t_basic_ostream_buffer_iterator(buffer_type& Buf);

  //----------------------------------------
  self_type& operator = (const_reference x);

  self_type& operator * ();

  self_type& operator ++ ();

  bool failed()const;

 private:
  buffer_type* m_buf;
  bool         m_failed;
};//class t_basic_ostream_buffer_iterator

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/stream/t_ostream_buffer_iterator.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
