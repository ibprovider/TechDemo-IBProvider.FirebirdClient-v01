////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 28.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_exchange_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_exchange_CC_

#include <lcpi/lib/structure/debug/assert.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_exchange__impl

class interlocked_exchange__impl
{
 public:
  template<typename T>
  static T* exec(T* volatile* pDestination,std::nullptr_t newValue);
};//class interlocked_exchange__impl

//------------------------------------------------------------------------
template<typename T>
T* interlocked_exchange__impl::exec(T* volatile *  const pDestination,
                                    std::nullptr_t const newValue)
{
 LCPI__assert(pDestination);

 return (T*)InterlockedExchangePointer((void**)(pDestination),newValue);
}//exec - T**, nullptr

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked

template<typename T1,typename T2>
T1 interlocked::exchange(T1 volatile* const pDestination,T2 newValue)
{
 LCPI__assert(pDestination);

 return detail::interlocked_exchange__impl::exec
         (pDestination,
          newValue);
}//exchange

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
