////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 03.12.2023.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_add_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_add_CC_

#include <lcpi/infrastructure/os/lcpi.infrastructure.os-atomic_functions.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_add_n

template<size_t N>
class interlocked_add__impl_n LCPI_CPP_CFG__CLASS__FINAL
{
};//class interlocked_add__impl_n<N>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_add_n<4>

template<>
class interlocked_add__impl_n<sizeof(std::uint32_t)> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T exec(T volatile* const pAddend, T value)
  {
   using api_t=std::uint32_t;

   LCPI__assert(pAddend!=nullptr);

   LCPI__assert_s(sizeof(*pAddend)==sizeof(api_t));
   LCPI__assert_s(sizeof(value)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::LCPI_OS__InterlockedAdd32
               (reinterpret_cast<api_t volatile*>(pAddend),
                value);
  }//exec
};//class interlocked_add__impl_n<sizeof(std::uint32_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_add_n<8>

template<>
class interlocked_add__impl_n<sizeof(std::uint64_t)> LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T exec(T volatile* const pAddend, T value)
  {
   using api_t=std::uint64_t;

   LCPI__assert(pAddend!=nullptr);

   LCPI__assert_s(sizeof(*pAddend)==sizeof(api_t));
   LCPI__assert_s(sizeof(value)==sizeof(api_t));

   return (T) lcpi::infrastructure::os::LCPI_OS__InterlockedAdd64
               (reinterpret_cast<api_t volatile*>(pAddend),
                value);
  }//exec
};//class interlocked_add__impl_n<sizeof(std::uint64_t)>

////////////////////////////////////////////////////////////////////////////////
//class interlocked_add__impl

class interlocked_add__impl LCPI_CPP_CFG__CLASS__FINAL
{
 public:
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  using long_type  =signed long;
#endif

#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  using ulong_type =unsigned long;
#endif

  using int32_type =std::int32_t;
  using uint32_type=std::uint32_t;

  using int64_type =std::int64_t;
  using uint64_type=std::uint64_t;

 public:
#if (LCPI_CPP_CFG__CAN_USE__signed_long!=0)
  static long_type exec(long_type volatile* const pAddend,long_type const value)
  {
   return interlocked_add__impl_n<sizeof(*pAddend)>::exec(pAddend,value);
  }//exec
#endif

  //----------------------------------------------------------------------
#if (LCPI_CPP_CFG__CAN_USE__unsigned_long!=0)
  static ulong_type exec(ulong_type volatile* const pAddend,ulong_type const value)
  {
   return interlocked_add__impl_n<sizeof(*pAddend)>::exec(pAddend,value);
  }//exec
#endif

  //----------------------------------------------------------------------
  static int32_type exec(int32_type volatile* const pAddend,int32_type const value)
  {
   return interlocked_add__impl_n<sizeof(*pAddend)>::exec(pAddend,value);
  }//exec

  //----------------------------------------------------------------------
  static int64_type exec(int64_type volatile* const pAddend,int64_type const value)
  {
   return interlocked_add__impl_n<sizeof(*pAddend)>::exec(pAddend,value);
  }//exec

  //----------------------------------------------------------------------
  static uint32_type exec(uint32_type volatile* const pAddend,uint32_type const value)
  {
   return interlocked_add__impl_n<sizeof(*pAddend)>::exec(pAddend,value);
  }//exec

  //----------------------------------------------------------------------
  static uint64_type exec(uint64_type volatile* const pAddend,uint64_type const value)
  {
   return interlocked_add__impl_n<sizeof(*pAddend)>::exec(pAddend,value);
  }//exec
};//class interlocked_add__impl

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked

template<typename T>
T interlocked::add(T volatile* const pAddend,T value)
{
 LCPI__assert(pAddend);

 return detail::interlocked_add__impl::exec(pAddend,value);
}//add

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
