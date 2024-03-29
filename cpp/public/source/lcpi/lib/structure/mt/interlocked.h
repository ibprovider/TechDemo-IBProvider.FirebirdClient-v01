////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 12.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_H_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_H_

#include <lcpi/lib/.config.h>

#include <type_traits>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class interlocked

class interlocked LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T increment(T volatile* pValue);

  template<typename T>
  static T decrement(T volatile* pValue);

  template<typename T1,typename T2>
  static T1 exchange(T1 volatile* pDestination,T2 newValue);

  template<typename T1,typename T2,typename T3>
  static T1 compare_exchange(T1 volatile* pDestination,T2 newValue,T3 testValue);

  template<typename T>
  static T add(T volatile* pAddend,T value);
};//class interlocked

namespace detail{
////////////////////////////////////////////////////////////////////////////////

template<class T>
class interlocked__impl__get_underlying_type__enum LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using type=typename std::underlying_type<T>::type;
};//class interlocked__impl__get_underlying_type__enum

//------------------------------------------------------------------------
template<class T>
class interlocked__impl__get_underlying_type__std LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using type=T;
};//class interlocked__impl__get_underlying_type__std

//------------------------------------------------------------------------
template<typename T>
class interlocked__impl__get_underlying_type LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  using type
   =typename std::conditional
      <std::is_enum<T>::value,
       interlocked__impl__get_underlying_type__enum<T>,
       interlocked__impl__get_underlying_type__std<T>>::type::type;
};//class interlocked__impl__get_underlying_type

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/mt/interlocked_increment.cc>
#include <lcpi/lib/structure/mt/interlocked_decrement.cc>
#include <lcpi/lib/structure/mt/interlocked_exchange.cc>
#include <lcpi/lib/structure/mt/interlocked_compare_exchange.cc>
#include <lcpi/lib/structure/mt/interlocked_add.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
