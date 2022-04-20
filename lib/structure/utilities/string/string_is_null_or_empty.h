////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__string_is_null_or_empty_H_
#define _lcpi_lib_structure_utilities__string__string_is_null_or_empty_H_

#include <structure/t_common.h>

namespace structure{
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
}//namespace structure
#endif
