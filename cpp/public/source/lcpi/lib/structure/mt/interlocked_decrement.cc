////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 12.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_decrement_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_decrement_CC_

#include <assert.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_decrement_impl

class interlocked_decrement_impl
{
 public:
  static long exec(volatile long* const pValue)
  {
   return ::InterlockedDecrement(pValue);
  }//exec

  static unsigned int exec(volatile unsigned int* const pValue)
  {
   return ::InterlockedDecrement(pValue);
  }//exec

  static unsigned __int64 exec(volatile unsigned __int64* const pValue)
  {
   return ::InterlockedDecrement(pValue);
  }//exec
};//class interlocked_decrement_impl

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked_decrement

template<typename T>
T interlocked::decrement(T* const pValue)
{
 assert(pValue);

 return detail::interlocked_decrement_impl::exec(pValue);
}//exec

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
