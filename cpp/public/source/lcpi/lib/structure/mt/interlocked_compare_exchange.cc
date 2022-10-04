////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 28.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_compare_exchange_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_compare_exchange_CC_

#include <lcpi/lib/structure/debug/assert.h>

#include <type_traits>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_compare_exchange__impl

class interlocked_compare_exchange__impl
{
 public:
  template<typename T1,typename T2>
  static T1* exec(T1* volatile* pValue,T2* newValue,std::nullptr_t testValue);
};//class interlocked_compare_exchange__impl

//------------------------------------------------------------------------
template<typename T1,typename T2>
T1* interlocked_compare_exchange__impl::exec(T1* volatile*  const pDestination,
                                             T2*            const newValue,
                                             std::nullptr_t const testValue)
{
 LCPI__assert(pDestination);

 using T1_x=typename std::remove_const<T1>::type;

 return (T1*)InterlockedCompareExchangePointer((void**)(pDestination),const_cast<T1_x*>(static_cast<T1*>(newValue)),testValue);
}//exec - T1**, T2*, nullptr

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked

template<typename T1,typename T2,typename T3>
T1 interlocked::compare_exchange(T1 volatile* const pDestination,T2 newValue,T3 testValue)
{
 LCPI__assert(pDestination);

 return detail::interlocked_compare_exchange__impl::exec
         (pDestination,
          newValue,
          testValue);
}//compare_exchange

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
