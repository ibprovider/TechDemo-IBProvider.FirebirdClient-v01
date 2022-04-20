////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__create_strings2_H_
#define _lcpi_lib_structure_utilities__string__create_strings2_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<class TContainer,class charT>
inline size_t create_strings2(TContainer&   container,
                              const charT*  str);

template<class TContainer,class charT>
inline size_t create_strings2(TContainer&                          container,
                              const __STL_DEF_BASIC_STRING(charT)& str);

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
////////////////////////////////////////////////////////////////////////////////
#include <structure/utilities/string/create_strings2.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
