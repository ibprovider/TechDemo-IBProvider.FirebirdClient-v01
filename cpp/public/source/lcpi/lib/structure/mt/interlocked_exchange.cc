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
  using ulong_type =unsigned long;
  using uint32_type=unsigned __int32;
  using uint64_type=unsigned __int64;

 public:
  template<typename T>
  static T* exec(T* volatile* pDestination,std::nullptr_t newValue);

  template<typename T1,typename T2>
  static T1* exec(T1* volatile* pDestination,T2* newValue);

  static ulong_type exec(ulong_type volatile* pDestination,ulong_type newValue);

  static uint32_type exec(uint32_type volatile* pDestination,uint32_type newValue);

  static uint64_type exec(uint64_type volatile* pDestination,uint64_type newValue);
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
inline interlocked_exchange__impl::ulong_type
 interlocked_exchange__impl::exec
  (ulong_type volatile* const pDestination,
   ulong_type           const newValue)
{
 LCPI__assert(pDestination);

 return InterlockedExchange(pDestination,newValue);
}//exec - ulong_type

//------------------------------------------------------------------------
inline interlocked_exchange__impl::uint32_type
 interlocked_exchange__impl::exec
  (uint32_type volatile* const pDestination,
   uint32_type           const newValue)
{
 LCPI__assert(pDestination);

 return InterlockedExchange(pDestination,newValue);
}//exec - uint32_type

//------------------------------------------------------------------------
inline interlocked_exchange__impl::uint64_type
 interlocked_exchange__impl::exec
  (uint64_type volatile* const pDestination,
   uint64_type           const newValue)
{
 LCPI__assert(pDestination);

 return InterlockedExchange(pDestination,newValue);
}//exec - uint64_type

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
