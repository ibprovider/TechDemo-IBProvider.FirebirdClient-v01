////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 28.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_exchange_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_exchange_CC_

#include <lcpi/lib/structure/debug/assert.h>

#include <type_traits>

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

  template<typename T1,typename T2>
  static T1* exec(T1* volatile* pDestination,T2* newValue);

  static unsigned __int64 exec(unsigned __int64 volatile* pDestination,unsigned __int64 newValue);
};//class interlocked_exchange__impl

//------------------------------------------------------------------------
template<typename T>
T* interlocked_exchange__impl::exec(T* volatile *  const pDestination,
                                    std::nullptr_t const newValue)
{
 LCPI__assert(pDestination);

 return (T*)InterlockedExchangePointer((void**)(pDestination),newValue);
}//exec - T**, nullptr

//------------------------------------------------------------------------
template<typename T1,typename T2>
T1* interlocked_exchange__impl::exec(T1* volatile *  const pDestination,
                                     T2*             const newValue)
{
 LCPI__assert(pDestination);

 using T1_x=typename std::remove_const<T1>::type;

 return (T1*)InterlockedExchangePointer((void**)(pDestination),const_cast<T1_x*>(static_cast<T1*>(newValue)));
}//exec - T1**, T2*

//------------------------------------------------------------------------
inline unsigned __int64 interlocked_exchange__impl::exec
                             (unsigned __int64 volatile* const pDestination,
                              unsigned __int64           const newValue)
{
 LCPI__assert(pDestination);

 return InterlockedExchange(pDestination,newValue);
}//exec - unsigned __int64

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
