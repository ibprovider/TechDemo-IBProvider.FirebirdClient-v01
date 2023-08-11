////////////////////////////////////////////////////////////////////////////////
//Input stream buffer iterator
//                                                 Kovalenko Dmitry. 14.10.2011.
#ifndef _t_istream_buffer_iterator_H_
#define _t_istream_buffer_iterator_H_

#include <structure/stream/t_istream_buffer.h>
#include <iterator>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<typename T,class Traits=typename t_stream_buffer_traits__selector<T>::traits_type>
class t_basic_istream_buffer_iterator;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_istream_buffer_iterator

template<typename T,class Traits>
class t_basic_istream_buffer_iterator
{
 private:
  typedef t_basic_istream_buffer_iterator<T,Traits>        self_type;

 public: //typedefs ------------------------------------------------------
  typedef std::input_iterator_tag                          iterator_category;
  typedef T                                                value_type;
  typedef std::ptrdiff_t                                   difference_type;
  typedef const T*                                         pointer;
  typedef const T&                                         reference;

  typedef t_basic_istream_buffer<T,Traits>                 buffer_type;

 public:
  t_basic_istream_buffer_iterator();

  t_basic_istream_buffer_iterator(buffer_type* buf);

  t_basic_istream_buffer_iterator(buffer_type& buf);

  reference operator * ()const;

  self_type& operator ++ ();

  bool equal(const self_type& x)const;

 private:
  void make_ok()const;

 private:
  mutable buffer_type*  m_buf;
  mutable value_type    m_value;
  mutable bool          m_ok;
};//class t_basic_istream_buffer_iterator

////////////////////////////////////////////////////////////////////////////////
//non-member operators

template<typename T,class Traits>
bool operator == (const t_basic_istream_buffer_iterator<T,Traits>& x1,
                  const t_basic_istream_buffer_iterator<T,Traits>& x2)
{
 return x1.equal(x2);
}//operator ==

//------------------------------------------------------------------------
template<typename T,class Traits>
bool operator != (const t_basic_istream_buffer_iterator<T,Traits>& x1,
                  const t_basic_istream_buffer_iterator<T,Traits>& x2)
{
 return !x1.equal(x2);
}//operator !=

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/stream/t_istream_buffer_iterator.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
