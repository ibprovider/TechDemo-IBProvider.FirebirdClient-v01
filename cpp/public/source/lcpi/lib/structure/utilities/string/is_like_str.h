////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 23.11.2022
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__is_like_str_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__is_like_str_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename charT,typename StringIteratorT,typename PatterIteratorT>
bool is_like_str(charT           any_sym,
                 charT           any_seq,
                 StringIteratorT b_str,
                 StringIteratorT e_str,
                 PatterIteratorT b_pattern,
                 PatterIteratorT e_pattern);

//------------------------------------------------------------------------
template<typename charT,class stringT,class patternT>
bool is_like_str(charT           any_sym,
                 charT           any_seq,
                 const stringT&  str,
                 const patternT& pattern);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/

////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/string/is_like_str.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
