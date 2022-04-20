////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 12.09.2019.
#ifndef _cpp_public_lcpi_lib_structure_mt__interlocked_H_
#define _cpp_public_lcpi_lib_structure_mt__interlocked_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{namespace mt{
////////////////////////////////////////////////////////////////////////////////
//class interlocked

class interlocked LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  template<typename T>
  static T increment(T* pValue);

  template<typename T>
  static T decrement(T* pValue);
};//class interlocked

////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/mt/interlocked_increment.cc>
#include <lcpi/lib/structure/mt/interlocked_decrement.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
