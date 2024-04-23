////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 01.04.2024.
#ifndef _cpp_public_lcpi_lib_structure__cs_cvt__single_utf16_to_utf8_H_
#define _cpp_public_lcpi_lib_structure__cs_cvt__single_utf16_to_utf8_H_

#include <lcpi/lib/structure/charsets/cs_cvt_result.h>

namespace lcpi{namespace lib{namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////

template<class ForwardInputIterator,class ForwardOutputIterator>
cs_cvt_result<ForwardInputIterator,ForwardOutputIterator>
 cs_cvt__single_utf16_to_utf8
  (ForwardInputIterator  source_beg,
   ForwardInputIterator  source_end,
   ForwardOutputIterator target_beg,
   ForwardOutputIterator target_end);

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/charsets/cs_cvt__single_utf16_to_utf8.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
