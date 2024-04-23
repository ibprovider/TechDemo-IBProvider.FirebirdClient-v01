////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Kovalenko Dmitry. 01.04.2024.
#ifndef _cpp_public_lcpi_lib_structure__cs_cvt__utf8_to_utf16_H_
#define _cpp_public_lcpi_lib_structure__cs_cvt__utf8_to_utf16_H_

#include <lcpi/lib/structure/charsets/cs_cvt__single_utf8_to_utf16.h>
#include <array>

namespace lcpi{namespace lib{namespace structure{namespace charsets{
////////////////////////////////////////////////////////////////////////////////
//cs_cvt__utf8_to_utf16

template<class ForwardInputIterator,class ForwardOutputIterator>
cs_cvt_result<ForwardInputIterator,ForwardOutputIterator>
 cs_cvt__utf8_to_utf16
  (ForwardInputIterator  source_beg,
   ForwardInputIterator  source_end,
   ForwardOutputIterator dest)
{
 std::array<cs_traits__utf16::UTF16,2> result_buf;

 for(;;)
 {
  if(source_beg==source_end)
   break;

  const auto
   result
    =cs_cvt__single_utf8_to_utf16
      (source_beg,
       source_end,
       result_buf.begin(),
       result_buf.end());

  if(result.code!=cs_cvt_result_code::ok)
  {
   LCPI__assert(result.code!=cs_cvt_result_code::small_output);

   return detail::make_cs_cvt_result
    (result.code,
     source_beg,
     dest);
  }//if

  source_beg=result.input;

  LCPI__assert(result.output!=result_buf.begin());

  for(auto x=result_buf.begin();x!=result.output;++x,++dest)
   (*dest)=(*x);
 }//for[ever]

 return detail::make_cs_cvt_result
  (cs_cvt_result_code::ok,
   source_beg,
   dest);
}//cs_cvt__utf8_to_utf16

////////////////////////////////////////////////////////////////////////////////
}/*nms charsets*/}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
