////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__string_length_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__string_length_H_

#include <lcpi/lib/.config.h>
#include <string>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class charT>
RELEASE_CODE(inline)
 size_t string_length(const charT* const s)
{
 assert(s!=nullptr);

 return std::char_traits<charT>::length(s);
}//string_length

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
