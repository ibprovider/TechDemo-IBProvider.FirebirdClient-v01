////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 12.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_increment_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_increment_CC_

#include <lcpi/infrastructure/os/lcpi.infrastructure.os.mt-atomic_functions.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_increment_n

template<size_t N>
class interlocked_increment__impl_n LCPI_CPP_CFG__CLASS__FINAL
{
};//class interlocked_increment__impl_n<N>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_increment_n<4>

template<>
class interlocked_increment__impl_n<sizeof(std::uint32_t)> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T exec(T volatile* const pValue)
  {
   using api_t=std::uint32_t;

   LCPI__assert(pValue!=nullptr);

   LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::mt::LCPI_OS__InterlockedIncrement32
               (reinterpret_cast<api_t volatile*>(pValue));
  }//exec
};//class interlocked_increment__impl_n<sizeof(std::uint32_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_increment_n<8>

template<>
class interlocked_increment__impl_n<sizeof(std::uint64_t)> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T exec(T volatile* const pValue)
  {
   using api_t=std::uint64_t;

   LCPI__assert(pValue!=nullptr);

   LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::mt::LCPI_OS__InterlockedIncrement64
               (reinterpret_cast<api_t volatile*>(pValue));
  }//exec
};//class interlocked_increment__impl_n<sizeof(std::uint64_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_increment__impl

class interlocked_increment__impl LCPI_CPP_CFG__CLASS__FINAL
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
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static long_type exec(long_type volatile* const pValue)
  {
   return interlocked_increment__impl_n<sizeof(*pValue)>::exec(pValue);
  }//exec
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  static ulong_type exec(ulong_type volatile* const pValue)
  {
   return interlocked_increment__impl_n<sizeof(*pValue)>::exec(pValue);
  }//exec
#endif

  static int32_type exec(int32_type volatile* const pValue)
  {
   return interlocked_increment__impl_n<sizeof(*pValue)>::exec(pValue);
  }//exec

  static uint32_type exec(uint32_type volatile* const pValue)
  {
   return interlocked_increment__impl_n<sizeof(*pValue)>::exec(pValue);
  }//exec

  static int64_type exec(int64_type volatile* const pValue)
  {
   return interlocked_increment__impl_n<sizeof(*pValue)>::exec(pValue);
  }//exec

  static uint64_type exec(uint64_type volatile* const pValue)
  {
   return interlocked_increment__impl_n<sizeof(*pValue)>::exec(pValue);
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
