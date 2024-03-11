////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 12.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_decrement_CC_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_decrement_CC_

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////
//class interlocked_decrement_impl

class interlocked_decrement_impl
{
 public:
  using long_type  =long;
  using ulong_type =unsigned long;
  using uint32_type=unsigned __int32;
  using uint64_type=unsigned __int64;

 public:
  static long_type exec(long_type volatile* const pValue)
  {
   return ::InterlockedDecrement(pValue);
  }//exec

  static ulong_type exec(ulong_type volatile* const pValue)
  {
   return ::InterlockedDecrement(pValue);
  }//exec

  static uint32_type exec(uint32_type volatile* const pValue)
  {
   return ::InterlockedDecrement(pValue);
  }//exec

  static uint64_type exec(uint64_type volatile* const pValue)
  {
   return ::InterlockedDecrement(pValue);
  }//exec
};//class interlocked_decrement_impl

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

////////////////////////////////////////////////////////////////////////////////
//class interlocked

template<typename T>
T interlocked::decrement(T volatile* const pValue)
{
 LCPI__assert(pValue);

 return detail::interlocked_decrement_impl::exec(pValue);
}//decrement

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
