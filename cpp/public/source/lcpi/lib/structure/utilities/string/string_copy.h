////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__string_copy_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__string_copy_H_

#include <lcpi/lib/.config.h>

#include <utility>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class charT,class OutputIterator>
std::pair<const charT*,OutputIterator>
 string_copy(const charT*    source,
             OutputIterator  dest_first,
             OutputIterator  dest_last)
{
 if(source!=nullptr)
 {
  for(;(*source) && dest_first!=dest_last;++source,++dest_first)
   (*dest_first)=(*source);
 }

 return std::make_pair(source,dest_first);
}//string_copy

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
