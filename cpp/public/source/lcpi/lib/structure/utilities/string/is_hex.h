////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__is_hex_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__is_hex_H_

#include <lcpi/lib/structure/t_char_traits2.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class charT>
bool is_hex(const charT c)
{
 return t_char_traits2<charT>::is_hex(c);
}//is_hex

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
