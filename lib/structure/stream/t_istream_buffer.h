////////////////////////////////////////////////////////////////////////////////
//Input stream buffer base class.
//                                                Kovalenko Dmitry. 13.10.2011.
#ifndef _t_istream_buffer_H_
#define _t_istream_buffer_H_

#include <structure/stream/t_stream_buffer_traits__selector.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//contaings

template<typename T,class Traits=typename t_stream_buffer_traits__selector<T>::traits_type>
class t_basic_istream_buffer;

////////////////////////////////////////////////////////////////////////////////
//class t_basic_istream_buffer

template<typename T,class Traits>
class t_basic_istream_buffer
{
 private:
  typedef t_basic_istream_buffer<T,Traits>  self_type;

  t_basic_istream_buffer(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

  typedef T                                 value_type;
  typedef Traits                            traits_type;

  typedef value_type*                       pointer;
  typedef const value_type*                 const_pointer;

  typedef value_type&                       reference;

  typedef unsigned __int64                  stream_size_type;

 public:
  t_basic_istream_buffer();

  t_basic_istream_buffer(const_pointer buffer_beg,
                         const_pointer buffer_end);

  virtual ~t_basic_istream_buffer();

  //interface ------------------------------------------------------------
  bool eof();
  
  bool get(pointer value);

  bool cur(pointer value);

  void getn(pointer p,size_type n,size_type* actual_readed);

  //----------------------------------------
  bool skip();

  void skipn(stream_size_type  n,
             stream_size_type* actual_skiped);

 protected:
  void set_ptrs(const_pointer buffer_beg,
                const_pointer buffer_end);

 private:
  virtual void underflow()=0;

 private:
#ifndef NDEBUG
  void debug__check_state()const;
#endif

 private:
  const_pointer m_buffer_pos;
  const_pointer m_buffer_end;
};//class t_basic_istream_buffer

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/stream/t_istream_buffer.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
