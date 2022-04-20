////////////////////////////////////////////////////////////////////////////////
//Output stream buffer base class.
//                                                Kovalenko Dmitry. 16.10.2011.
#ifndef _t_ostream_buffer_H_
#define _t_ostream_buffer_H_

#include <structure/stream/t_stream_buffer_traits__selector.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_basic_ostream_buffer

template<class T,class Traits=typename t_stream_buffer_traits__selector<T>::traits_type>
class t_basic_ostream_buffer;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_ostream_buffer

template<class T,class Traits>
class t_basic_ostream_buffer
{
 private:
  typedef t_basic_ostream_buffer<T,Traits>                      self_type;

  t_basic_ostream_buffer(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

  typedef T                                 value_type;
  typedef Traits                            traits_type;

  typedef value_type*                       pointer;
  typedef const value_type*                 const_pointer;

  typedef const value_type&                 const_reference;

 public:
  t_basic_ostream_buffer();

  t_basic_ostream_buffer(pointer buffer_beg,
                         pointer buffer_end);

  virtual ~t_basic_ostream_buffer();

  //----------------------------------------------------------------------
  bool put(const_reference value);

  void putn(const_pointer p,size_type n,size_type* actual_writed);

  void flush();

 protected:
  void set_ptrs(pointer buffer_beg,
                pointer buffer_end);

  pointer get_buffer_pos()const;

  pointer get_buffer_end()const;

 private:
  //for implementation
  // 1. flush data between [buffer_beg, buffer_pos)
  // 2. set new ptrs
  virtual void overflow()=0;

 private:
 #ifndef NDEBUG
  void debug__check_state()const;
 #endif

 private:
  pointer m_buffer_pos;
  pointer m_buffer_end;
};//class t_basic_ostream_buffer

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/stream/t_ostream_buffer.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
