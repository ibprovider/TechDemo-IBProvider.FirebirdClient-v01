////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 28.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_compare_exchange_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_compare_exchange_CC_

#include <type_traits>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_compare_exchange__impl

class interlocked_compare_exchange__impl
{
 public:
  using long_type  =long;
  using ulong_type =unsigned long;
  using uint32_type=unsigned __int32;
  using uint64_type=unsigned __int64;

 public:
  template<typename T1,typename T2>
  static T1* exec(T1* volatile* pValue,T2* newValue,std::nullptr_t testValue);

  template<typename T1,typename T2>
  static T1* exec(T1* volatile* pValue,T2* newValue,T1* testValue);

  static long_type exec(long_type volatile* pValue,long_type newValue,long_type testValue);

  static ulong_type exec(ulong_type volatile* pValue,ulong_type newValue,ulong_type testValue);

  static uint32_type exec(uint32_type volatile* pValue,uint32_type newValue,uint32_type testValue);

  static uint64_type exec(uint64_type volatile* pValue,uint64_type newValue,uint64_type testValue);
};//class interlocked_compare_exchange__impl

//------------------------------------------------------------------------
template<typename T1,typename T2>
T1* interlocked_compare_exchange__impl::exec(T1* volatile*  const pValue,
                                             T2*            const newValue,
                                             std::nullptr_t const testValue)
{
 LCPI__assert(pValue);

 using T1_x=typename std::remove_const<T1>::type;

 return (T1*)InterlockedCompareExchangePointer((void**)(pValue),const_cast<T1_x*>(static_cast<T1*>(newValue)),testValue);
}//exec - T1**, T2*, nullptr

//------------------------------------------------------------------------
template<typename T1,typename T2>
T1* interlocked_compare_exchange__impl::exec(T1* volatile*  const pValue,
                                             T2*            const newValue,
                                             T1*            const testValue)
{
 LCPI__assert(pValue);

 using T1_x=typename std::remove_const<T1>::type;

 return (T1*)InterlockedCompareExchangePointer((void**)(pValue),const_cast<T1_x*>(static_cast<T1*>(newValue)),testValue);
}//exec - T1**, T2*, T1*

//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::long_type
 interlocked_compare_exchange__impl::exec
  (long_type volatile* const pValue,
   long_type           const newValue,
   long_type           const testValue)
{
 LCPI__assert(pValue);

 return InterlockedCompareExchange(pValue,newValue,testValue);
}//exec - long_type

//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::ulong_type
 interlocked_compare_exchange__impl::exec
  (ulong_type volatile* const pValue,
   ulong_type           const newValue,
   ulong_type           const testValue)
{
 LCPI__assert(pValue);

 return InterlockedCompareExchange(pValue,newValue,testValue);
}//exec - ulong_type

//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::uint32_type
 interlocked_compare_exchange__impl::exec
  (uint32_type volatile* const pValue,
   uint32_type           const newValue,
   uint32_type           const testValue)
{
 LCPI__assert(pValue);

 return InterlockedCompareExchange(pValue,newValue,testValue);
}//exec - uint32_type

//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::uint64_type
 interlocked_compare_exchange__impl::exec
  (uint64_type volatile* const pValue,
   uint64_type           const newValue,
   uint64_type           const testValue)
{
 LCPI__assert(pValue);

 return InterlockedCompareExchange(pValue,newValue,testValue);
}//exec - uint64_type

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
