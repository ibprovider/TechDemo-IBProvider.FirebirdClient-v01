////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 12.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_increment_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_increment_CC_

#include <assert.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_increment__impl

class interlocked_increment__impl
{
 public:
  static long exec(volatile long* const pValue)
  {
   return ::InterlockedIncrement(pValue);
  }//exec

  static unsigned int exec(volatile unsigned int* const pValue)
  {
   return ::InterlockedIncrement(pValue);
  }//exec

  static unsigned __int64 exec(volatile unsigned __int64* const pValue)
  {
   return ::InterlockedIncrement(pValue);
  }//exec
};//class interlocked_increment__impl

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked_increment

template<typename T>
T interlocked::increment(T* const pValue)
{
 assert(pValue);

 return detail::interlocked_increment__impl::exec(pValue);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
