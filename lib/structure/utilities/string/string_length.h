////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__string_length_H_
#define _lcpi_lib_structure_utilities__string__string_length_H_

#include <structure/t_common.h>
#include <string>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class charT>
RELEASE_CODE(inline)
 size_t string_length(const charT* const s)
{
 assert(s!=nullptr);

 return std::char_traits<charT>::length(s);
}//string_length

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
