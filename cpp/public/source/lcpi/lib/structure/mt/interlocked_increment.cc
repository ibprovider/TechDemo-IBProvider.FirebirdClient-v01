////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 12.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_increment_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_increment_CC_

#include <lcpi/lib/structure/debug/assert.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_increment__impl

class interlocked_increment__impl
{
 public:
  static long exec(long volatile* const pValue)
  {
   return ::InterlockedIncrement(pValue);
  }//exec

  static long exec(unsigned long volatile* const pValue)
  {
   return ::InterlockedIncrement(pValue);
  }//exec

  static unsigned int exec(unsigned int volatile* const pValue)
  {
   return ::InterlockedIncrement(pValue);
  }//exec

  static unsigned __int64 exec(unsigned __int64 volatile* const pValue)
  {
   return ::InterlockedIncrement(pValue);
  }//exec
};//class interlocked_increment__impl

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked

template<typename T>
T interlocked::increment(T volatile* const pValue)
{
 LCPI__assert(pValue);

 return detail::interlocked_increment__impl::exec(pValue);
}//increment

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
