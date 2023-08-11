////////////////////////////////////////////////////////////////////////////////
//Selector of traits for stream buffer
//                                             Kovalenko Dmitry. 13.10.2011
#ifndef _t_stream_buffer_traits__selector_H_
#define _t_stream_buffer_traits__selector_H_

#include <structure/stream/t_stream_buffer_traits.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<typename T>
class t_stream_buffer_traits__selector;

template<>
class t_stream_buffer_traits__selector<char>;

template<>
class t_stream_buffer_traits__selector<wchar_t>;

////////////////////////////////////////////////////////////////////////////////
//class t_stream_buffer_traits__selector

template<typename T>
class t_stream_buffer_traits__selector
{
 public:
  typedef t_stream_buffer_traits__generic<T>              traits_type;
};//class t_stream_buffer_traits__selector

////////////////////////////////////////////////////////////////////////////////
//class t_stream_buffer_traits__selector<char>

template<>
class t_stream_buffer_traits__selector<char>
{
 public:
  typedef t_stream_buffer_traits__binary<char>            traits_type;
};//class t_stream_buffer_traits__selector<char>

////////////////////////////////////////////////////////////////////////////////
//class t_stream_buffer_traits__selector<wchar_t>

template<>
class t_stream_buffer_traits__selector<wchar_t>
{
 public:
  typedef t_stream_buffer_traits__binary<wchar_t>         traits_type;
};//class t_stream_buffer_traits__selector<wchar_t>

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
