////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 28.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_exchange_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_exchange_CC_

#include <lcpi/infrastructure/os/lcpi.infrastructure.os-atomic_functions.h>

#include <type_traits>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_exchange__impl_n

template<size_t N>
class interlocked_exchange__impl_n LCPI_CPP_CFG__CLASS__FINAL
{
};//class interlocked_exchange__impl_n<N>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_exchange__impl_n<4>

template<>
class interlocked_exchange__impl_n<sizeof(std::uint32_t)> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T exec(T volatile* const pValue,T const newValue)
  {
   using api_t=std::uint32_t;

   LCPI__assert(pValue!=nullptr);

   LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
   LCPI__assert_s(sizeof(newValue)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::LCPI_OS__InterlockedExchange32
               (reinterpret_cast<api_t volatile*>(pValue),
                (api_t)newValue);
  }//exec
};//class interlocked_exchange__impl_n<sizeof(std::uint32_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_exchange__impl_n<8>

template<>
class interlocked_exchange__impl_n<sizeof(std::uint64_t)> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T exec(T volatile* const pValue,T const newValue)
  {
   using api_t=std::uint64_t;

   LCPI__assert(pValue!=nullptr);

   LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
   LCPI__assert_s(sizeof(newValue)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::LCPI_OS__InterlockedExchange64
               (reinterpret_cast<api_t volatile*>(pValue),
                (api_t)newValue);
  }//exec
};//class interlocked_exchange__impl_n<sizeof(std::uint64_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_exchange__impl

class interlocked_exchange__impl LCPI_CPP_CFG__CLASS__FINAL
{
 public:
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  using long_type=signed long;
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  using ulong_type=unsigned long;
#endif

  using int32_type =std::int32_t;
  using int64_type =std::int64_t;

  using uint32_type=std::uint32_t;
  using uint64_type=std::uint64_t;

 public:
  template<typename T1>
  static T1* exec(T1* volatile* pDestination,T1* newValue);

#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static long_type exec(long_type volatile* pDestination,long_type newValue);
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  static ulong_type exec(ulong_type volatile* pDestination,ulong_type newValue);
#endif

  static int32_type exec(int32_type volatile* pDestination,int32_type newValue);

  static int64_type exec(int64_type volatile* pDestination,int64_type newValue);

  static uint32_type exec(uint32_type volatile* pDestination,uint32_type newValue);

  static uint64_type exec(uint64_type volatile* pDestination,uint64_type newValue);
};//class interlocked_exchange__impl

//------------------------------------------------------------------------
template<typename T1>
T1* interlocked_exchange__impl::exec(T1* volatile *  const pDestination,
                                     T1*             const newValue)
{
 return interlocked_exchange__impl_n<sizeof(*pDestination)>::exec(pDestination,static_cast<T1*>(newValue));
}//exec - T1**, T1*

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)

inline interlocked_exchange__impl::long_type
 interlocked_exchange__impl::exec
  (long_type volatile* const pDestination,
   long_type           const newValue)
{
 return interlocked_exchange__impl_n<sizeof(*pDestination)>::exec(pDestination,newValue);
}//exec - long_type

#endif

//------------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)

inline interlocked_exchange__impl::ulong_type
 interlocked_exchange__impl::exec
  (ulong_type volatile* const pDestination,
   ulong_type           const newValue)
{
 return interlocked_exchange__impl_n<sizeof(*pDestination)>::exec(pDestination,newValue);
}//exec - ulong_type

#endif

//------------------------------------------------------------------------
inline interlocked_exchange__impl::int32_type
 interlocked_exchange__impl::exec
  (int32_type volatile* const pDestination,
   int32_type           const newValue)
{
 return interlocked_exchange__impl_n<sizeof(*pDestination)>::exec(pDestination,newValue);
}//exec - int32_type

//------------------------------------------------------------------------
inline interlocked_exchange__impl::int64_type
 interlocked_exchange__impl::exec
  (int64_type volatile* const pDestination,
   int64_type           const newValue)
{
 return interlocked_exchange__impl_n<sizeof(*pDestination)>::exec(pDestination,newValue);
}//exec - int64_type

//------------------------------------------------------------------------
inline interlocked_exchange__impl::uint32_type
 interlocked_exchange__impl::exec
  (uint32_type volatile* const pDestination,
   uint32_type           const newValue)
{
 return interlocked_exchange__impl_n<sizeof(*pDestination)>::exec(pDestination,newValue);
}//exec - uint32_type

//------------------------------------------------------------------------
inline interlocked_exchange__impl::uint64_type
 interlocked_exchange__impl::exec
  (uint64_type volatile* const pDestination,
   uint64_type           const newValue)
{
 return interlocked_exchange__impl_n<sizeof(*pDestination)>::exec(pDestination,newValue);
}//exec - uint64_type

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked

template<typename T1,typename T2>
T1 interlocked::exchange(T1 volatile* const pDestination,T2 newValue)
{
 LCPI__assert(pDestination);

 using underlying1_t
  =typename detail::interlocked__impl__get_underlying_type<T1>::type;

 LCPI__assert_s(sizeof(underlying1_t)==sizeof(T1));

 T1 const newValue_as_t1=newValue;

 return static_cast<T1>
         (detail::interlocked_exchange__impl::exec
           (reinterpret_cast<underlying1_t volatile*>(pDestination),
            static_cast<underlying1_t>(newValue_as_t1)));
}//exchange

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
