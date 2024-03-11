////////////////////////////////////////////////////////////////////////////////
//Stream buffer traits
//                                                 Kovalenko Dmitry. 13.10.2011.
#ifndef _t_stream_buffer_traits_H_
#define _t_stream_buffer_traits_H_

#include <lcpi/lib/.config.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_stream_buffer_traits__binary

template<typename T>
class t_stream_buffer_traits__binary
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

  typedef T                                 value_type;
  
  typedef value_type*                       pointer;
  typedef const value_type*                 const_pointer;
 
 public:
  //! \param[in,out] dest
  //!  Not NULL.
  //! \param[in,out] source
  //!  Not NULL.
  //! \param[in]     n
  //! \param[in,out] actual_readed_accum
  //!  Not NULL.
  static void copy(pointer*       dest,
                   const_pointer* source,
                   size_type      n,
                   size_type*     actual_readed_accum);
};//class t_stream_buffer_traits__binary

////////////////////////////////////////////////////////////////////////////////
//class t_stream_buffer_traits__generic

template<typename T>
class t_stream_buffer_traits__generic
{
 public: //typedefs ------------------------------------------------------
  typedef size_t                            size_type;

  typedef T                                 value_type;
  
  typedef value_type*                       pointer;
  typedef const value_type*                 const_pointer;
 
 public:
  //! \param[in,out] dest
  //!  Not NULL.
  //! \param[in,out] source
  //!  Not NULL.
  //! \param[in]     n
  //! \param[in,out] actual_readed_accum
  //!  Not NULL.
  static void copy(pointer*       dest,
                   const_pointer* source,
                   size_type      n,
                   size_type*     actual_readed_accum);
};//class t_stream_buffer_traits__generic

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/stream/t_stream_buffer_traits.cc>
////////////////////////////////////////////////////////////////////////////////
#endif