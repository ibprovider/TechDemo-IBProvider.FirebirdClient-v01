////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__del_spaces_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__del_spaces_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//service templates for del_spaces functions

template<class TStr,class TSpaceComp>
TStr del_spaces(const TStr&,bool all,TSpaceComp is_space);

template<class TStr,class TSpaceComp>
TStr& self_del_spaces(TStr&,bool all,TSpaceComp is_space);

////////////////////////////////////////////////////////////////////////////////
//del_spaces functions

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 del_spaces(const std::basic_string<charT,traits,Allocator>& str,bool all=false);

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 total_del_spaces(const std::basic_string<charT,traits,Allocator>& str,bool all=false);

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 self_del_spaces(std::basic_string<charT,traits,Allocator>& str,bool all=false);

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 total_self_del_spaces(std::basic_string<charT,traits,Allocator>& str,bool all=false);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/string/del_spaces.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
