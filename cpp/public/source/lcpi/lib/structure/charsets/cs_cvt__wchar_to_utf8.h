////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 02.04.2024.
#ifndef _cpp_public_lcpi_lib_structure__cs_cvt__wchar_to_utf8_H_
#define _cpp_public_lcpi_lib_structure__cs_cvt__wchar_to_utf8_H_

#include <lcpi/lib/structure/charsets/cs_cvt__utf16_to_utf8.h>

namespace lcpi{namespace lib{namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//cs_cvt__wchar_to_utf8

template<class ForwardInputIterator,class ForwardOutputIterator>
cs_cvt_result<ForwardInputIterator,ForwardOutputIterator>
 cs_cvt__wchar_to_utf8
  (ForwardInputIterator  source_beg,
   ForwardInputIterator  source_end,
   ForwardOutputIterator dest)
{
 LCPI__assert(sizeof(wchar_t)==2);

 return cs_cvt__utf16_to_utf8(source_beg,source_end,dest);
}//cs_cvt__wchar_to_utf8

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
