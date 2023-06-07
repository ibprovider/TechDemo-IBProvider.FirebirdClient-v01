////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 14.11.2022.
#ifndef _cpp_public_lcpi_lib_structure__t_numeric_utils_H_
#define _cpp_public_lcpi_lib_structure__t_numeric_utils_H_

#ifndef NDEBUG
# include <lcpi/lib/structure/t_vector_debug_iterator.h>
#else
# include <lcpi/lib/.config.h>
#endif

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_numeric_bytes

class t_numeric_bytes_accessor
{
 private:
  typedef t_numeric_bytes_accessor                    self_type;

 public:
  typedef unsigned __int8                             byte_type;

  typedef size_t                                      size_type;
  typedef ptrdiff_t                                   difference_type;

  typedef byte_type                                   value_type;
  typedef const value_type*                           pointer;
  typedef const value_type&                           reference;

 #ifndef NDEBUG
  typedef t_vector_debug_iterator<const self_type>    iterator;
 #else
  typedef pointer                                     iterator;
 #endif

 public:
  t_numeric_bytes_accessor();

  t_numeric_bytes_accessor(pointer first,pointer last);

  //selectors ------------------------------------------------------------
  size_type size()const;

  //accessors ------------------------------------------------------------
  reference operator [] (size_type i)const;

  //iterators ------------------------------------------------------------
  iterator begin()const;
  iterator end()const;

 private:
  pointer m_first;
  pointer m_last;
};//class t_numeric_bytes_accessor

////////////////////////////////////////////////////////////////////////////////
//class t_numeric_bytes

template<size_t N>
class t_numeric_bytes
{
 private:
  typedef t_numeric_bytes<N>                          self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned __int8                             byte_type;

  typedef size_t                                      size_type;
  typedef ptrdiff_t                                   difference_type;

  typedef byte_type                                   value_type;
  typedef value_type*                                 pointer;
  typedef const value_type*                           const_pointer;
  typedef value_type&                                 reference;
  typedef const value_type&                           const_reference;

 #ifndef NDEBUG
  typedef t_vector_debug_iterator<self_type>          iterator;
  typedef t_vector_debug_const_iterator<self_type>    const_iterator;
 #else
  typedef pointer                                     iterator;
  typedef const_pointer                               const_iterator;
 #endif

  typedef t_numeric_bytes_accessor                    accessor_type;

 public:
  t_numeric_bytes();

  //selectors ------------------------------------------------------------
  size_type size()const;

  accessor_type accessor()const;

  //accessors ------------------------------------------------------------
  reference operator [] (size_type i);

  const_reference operator [] (size_type i)const;

  //iterators ------------------------------------------------------------
  iterator begin();
  iterator end();

  const_iterator begin()const;
  const_iterator end()const;

  const_iterator cbegin()const;
  const_iterator cend()const;

 private:
  byte_type m_bytes[N];
};//struct t_numeric_bytes

////////////////////////////////////////////////////////////////////////////////

template<typename T>
t_numeric_bytes<sizeof(T)> get_numeric_bytes(T numeric);

////////////////////////////////////////////////////////////////////////////////
//specialization - unsigned

template<>
inline t_numeric_bytes<sizeof(unsigned __int8)>
 get_numeric_bytes(unsigned __int8 numeric);

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(unsigned __int16)>
 get_numeric_bytes(unsigned __int16 numeric);

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(unsigned __int32)>
 get_numeric_bytes(unsigned __int32 numeric);

//------------------------------------------------------------------------
template<>
inline t_numeric_bytes<sizeof(unsigned __int64)>
 get_numeric_bytes(unsigned __int64 numeric);

////////////////////////////////////////////////////////////////////////////////
//specialization - signed

template<>
inline t_numeric_bytes<sizeof(signed __int8)>
 get_numeric_bytes(signed __int8 numeric);

template<>
inline t_numeric_bytes<sizeof(signed __int16)>
 get_numeric_bytes(signed __int16 numeric);

template<>
inline t_numeric_bytes<sizeof(signed __int32)>
 get_numeric_bytes(signed __int32 numeric);

template<>
inline t_numeric_bytes<sizeof(signed __int64)>
 get_numeric_bytes(signed __int64 numeric);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/t_numeric_utils.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
