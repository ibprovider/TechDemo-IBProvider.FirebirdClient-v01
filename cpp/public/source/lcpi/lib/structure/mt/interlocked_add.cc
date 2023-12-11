////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 03.12.2023.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_add_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_add_CC_

#include <lcpi/lib/structure/debug/assert.h>
#include <lcpi/lib/structure/debug/assert_s.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_add__impl

class interlocked_add__impl LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=interlocked_add__impl;

 public:
  using long_type  =long;
  using int64_type =signed __int64;

  using ulong_type =unsigned long;
  using uint64_type=unsigned __int64;

 public:
  static long_type exec(long_type volatile* const pAddend,long_type const value)
  {
   LCPI__assert(pAddend);

   return self_type::helper__exec32(pAddend,value);
  }//exec

  //----------------------------------------------------------------------
  static ulong_type exec(ulong_type volatile* const pAddend,ulong_type const value)
  {
   LCPI__assert(pAddend);
   LCPI__assert_s(sizeof(ulong_type)==sizeof(long_type));

   return (ulong_type)self_type::helper__exec32(reinterpret_cast<long_type volatile*>(pAddend),(long_type)value);
  }//exec

  //----------------------------------------------------------------------
  static uint64_type exec(uint64_type volatile* const pAddend,uint64_type const value)
  {
   LCPI__assert(pAddend);
   LCPI__assert_s(sizeof(uint64_type)==sizeof(int64_type));

   return (uint64_type)self_type::helper_exec64(reinterpret_cast<int64_type volatile*>(pAddend),(int64_type)value);
  }//exec

 private:
  static long_type helper__exec32(long_type volatile* const pAddend,long_type const value)
  {
   LCPI__assert(pAddend);

   //return InterlockedAdd(pAddend,value);

   long_type Old;

   do
   {
    Old=*pAddend;
   }
   while(InterlockedCompareExchange(pAddend,Old+value,Old)!=Old);

   return Old+value;
  }//helper_exec32

  //----------------------------------------------------------------------
  static uint64_type helper_exec64(int64_type volatile* const pAddend,int64_type const value)
  {
   LCPI__assert(pAddend);

   //return InterlockedAdd64(pAddend,value);

   int64_type Old;

   do
   {
    Old=*pAddend;
   }
   while(InterlockedCompareExchange64(pAddend,Old+value,Old)!=Old);

   return Old+value;
  }//helper_exec64
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
