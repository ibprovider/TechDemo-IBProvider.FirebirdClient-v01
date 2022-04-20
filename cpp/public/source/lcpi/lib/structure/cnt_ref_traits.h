////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 23.04.2020.
#ifndef _cpp_public_lcpi_lib_structure__cnt_ref_traits_H_
#define _cpp_public_lcpi_lib_structure__cnt_ref_traits_H_

#include <lcpi/lib/structure/mt/interlocked.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class cnt_ref_traits

class cnt_ref_traits LCPI_CPP_CFG__CLASS__FINAL
{
 public: //typedefs ------------------------------------------------------
  using cnt_ref_type=unsigned __int64;

 public:
  static void increment(cnt_ref_type* const pCntRef)
  {
#ifndef NDEBUG
   const auto r=
#endif
    mt::interlocked::increment(pCntRef);

   assert(r>0);
  }//increment

  static cnt_ref_type decrement(cnt_ref_type* const pCntRef)
  {
   assert(pCntRef);
   assert((*pCntRef)>0);

   return mt::interlocked::decrement(pCntRef);
  }//decrement
};//class cnt_ref_traits

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
