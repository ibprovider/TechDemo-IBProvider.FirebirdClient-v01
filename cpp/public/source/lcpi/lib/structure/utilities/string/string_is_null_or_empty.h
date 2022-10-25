////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__string_is_null_or_empty_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__string_is_null_or_empty_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class charT>
RELEASE_CODE(inline)
 bool string_is_null_or_empty(const charT* const s)
{
 if(s==nullptr)
  return true;

 assert(s!=nullptr);

 if((*s)==0)
  return true;

 return false;
}//string_is_null_or_empty

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
