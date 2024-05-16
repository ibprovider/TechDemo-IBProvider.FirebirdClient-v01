////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 28.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_compare_exchange_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_compare_exchange_CC_

#include <lcpi/infrastructure/os/lcpi.infrastructure.os.mt-atomic_functions.h>

#include <type_traits>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_compare_exchange__impl_n

template<size_t N>
class interlocked_compare_exchange__impl_n
{
};//class interlocked_compare_exchange__impl_n<N>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_compare_exchange__impl_n<4>

template<>
class interlocked_compare_exchange__impl_n<sizeof(std::uint32_t)>
{
 public:
  template<typename T>
  static T exec(T volatile* pValue,
                T           newValue,
                T           testValue)
  {
   using api_t=std::uint32_t;

   LCPI__assert(pValue!=nullptr);

   LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
   LCPI__assert_s(sizeof(newValue)==sizeof(api_t));
   LCPI__assert_s(sizeof(testValue)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::mt::LCPI_OS__InterlockedCompareExchange32
               (reinterpret_cast<api_t volatile*>(pValue),
                (api_t)newValue,
                (api_t)testValue);
  }//exec
};//class interlocked_compare_exchange__impl_n<sizeof(std::uint32_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_compare_exchange__impl_n<8>

template<>
class interlocked_compare_exchange__impl_n<sizeof(std::uint64_t)>
{
 public:
  template<typename T>
  static T exec(T volatile* pValue,
                T           newValue,
                T           testValue)
  {
   using api_t=std::uint64_t;

   LCPI__assert(pValue!=nullptr);

   LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
   LCPI__assert_s(sizeof(newValue)==sizeof(api_t));
   LCPI__assert_s(sizeof(testValue)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::mt::LCPI_OS__InterlockedCompareExchange64
               (reinterpret_cast<api_t volatile*>(pValue),
                (api_t)newValue,
                (api_t)testValue);
  }//exec
};//class interlocked_compare_exchange__impl_n<sizeof(std::uint64_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_compare_exchange__impl

class interlocked_compare_exchange__impl LCPI_CPP_CFG__CLASS__FINAL
{
 public:
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  using long_type=signed long;
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  using ulong_type=unsigned long;
#endif

  using int32_type=std::int32_t;
  using int64_type=std::int64_t;

  using uint32_type=std::uint32_t;
  using uint64_type=std::uint64_t;

 public:
  template<typename T1>
  static T1* exec(T1* volatile* pValue,T1* newValue,T1* testValue);

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static long_type exec(long_type volatile* pValue,long_type newValue,long_type testValue);
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  static ulong_type exec(ulong_type volatile* pValue,ulong_type newValue,ulong_type testValue);
#endif

  static int32_type exec(int32_type volatile* pValue,int32_type newValue,int32_type testValue);
  static int64_type exec(int64_type volatile* pValue,int64_type newValue,int64_type testValue);

  static uint32_type exec(uint32_type volatile* pValue,uint32_type newValue,uint32_type testValue);
  static uint64_type exec(uint64_type volatile* pValue,uint64_type newValue,uint64_type testValue);
};//class interlocked_compare_exchange__impl

//------------------------------------------------------------------------
template<typename T1>
T1* interlocked_compare_exchange__impl::exec(T1* volatile*  const pValue,
                                             T1*            const newValue,
                                             T1*            const testValue)
{
 return interlocked_compare_exchange__impl_n<sizeof(*pValue)>::exec
         (pValue,
          newValue,
          testValue);
}//exec - T1**, T1*, T1*

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

inline interlocked_compare_exchange__impl::long_type
 interlocked_compare_exchange__impl::exec
  (long_type volatile* const pValue,
   long_type           const newValue,
   long_type           const testValue)
{
 return interlocked_compare_exchange__impl_n<sizeof(*pValue)>::exec
         (pValue,
          newValue,
          testValue);
}//exec - long_type

#endif

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

inline interlocked_compare_exchange__impl::ulong_type
 interlocked_compare_exchange__impl::exec
  (ulong_type volatile* const pValue,
   ulong_type           const newValue,
   ulong_type           const testValue)
{
 return interlocked_compare_exchange__impl_n<sizeof(*pValue)>::exec
         (pValue,
          newValue,
          testValue);
}//exec - ulong_type

#endif
 
//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::int32_type
 interlocked_compare_exchange__impl::exec
  (int32_type volatile* const pValue,
   int32_type           const newValue,
   int32_type           const testValue)
{
 return interlocked_compare_exchange__impl_n<sizeof(*pValue)>::exec
         (pValue,
          newValue,
          testValue);
}//exec - int32_type

//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::int64_type
 interlocked_compare_exchange__impl::exec
  (int64_type volatile* const pValue,
   int64_type           const newValue,
   int64_type           const testValue)
{
 return interlocked_compare_exchange__impl_n<sizeof(*pValue)>::exec
         (pValue,
          newValue,
          testValue);
}//exec - int64_type

//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::uint32_type
 interlocked_compare_exchange__impl::exec
  (uint32_type volatile* const pValue,
   uint32_type           const newValue,
   uint32_type           const testValue)
{
 return interlocked_compare_exchange__impl_n<sizeof(*pValue)>::exec
         (pValue,
          newValue,
          testValue);
}//exec - uint32_type

//------------------------------------------------------------------------
inline interlocked_compare_exchange__impl::uint64_type
 interlocked_compare_exchange__impl::exec
  (uint64_type volatile* const pValue,
   uint64_type           const newValue,
   uint64_type           const testValue)
{
 return interlocked_compare_exchange__impl_n<sizeof(*pValue)>::exec
         (pValue,
          newValue,
          testValue);
}//exec - uint64_type

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked

template<typename T1,typename T2,typename T3>
T1 interlocked::compare_exchange(T1 volatile* const pDestination,T2 newValue,T3 testValue)
{
 LCPI__assert(pDestination);

 using underlying1_t
  =typename detail::interlocked__impl__get_underlying_type<T1>::type;

 LCPI__assert_s(sizeof(underlying1_t)==sizeof(T1));

 T1 const newValue_as_t1=newValue;
 T1 const testValue_as_t1=testValue;

 return static_cast<T1>
         (detail::interlocked_compare_exchange__impl::exec
          (reinterpret_cast<underlying1_t volatile*>(pDestination),
           static_cast<underlying1_t>(newValue_as_t1),
           static_cast<underlying1_t>(testValue_as_t1)));
}//compare_exchange

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
