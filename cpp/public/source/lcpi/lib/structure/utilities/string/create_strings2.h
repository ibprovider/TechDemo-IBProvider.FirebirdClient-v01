////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__create_strings2_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__create_strings2_H_

#include <lcpi/lib/.config.h>
#include <string>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class TContainer,class charT>
inline size_t create_strings2(TContainer&   container,
                              const charT*  str);

template<class TContainer,class charT>
inline size_t create_strings2(TContainer&                     container,
                              const std::basic_string<charT>& str);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/string/create_strings2.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
