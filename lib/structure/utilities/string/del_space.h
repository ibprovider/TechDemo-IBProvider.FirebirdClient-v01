////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _lcpi_lib_structure_utilities__string__del_space_H_
#define _lcpi_lib_structure_utilities__string__del_space_H_

#include <structure/t_common.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//service templates for del_space functions

template<class TStr,class TSpaceComp>
TStr del_space(const TStr&,bool all,TSpaceComp is_space);

template<class TStr,class TSpaceComp>
TStr& self_del_space(TStr&,bool all,TSpaceComp is_space);

////////////////////////////////////////////////////////////////////////////////
//del_space functions

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 del_space(const std::basic_string<charT,traits,Allocator>& str,bool all=false);

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>
 total_del_space(const std::basic_string<charT,traits,Allocator>& str,bool all=false);

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 self_del_space(std::basic_string<charT,traits,Allocator>& str,bool all=false);

template<class charT,class traits,class Allocator>
inline std::basic_string<charT,traits,Allocator>&
 total_self_del_space(std::basic_string<charT,traits,Allocator>& str,bool all=false);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/
////////////////////////////////////////////////////////////////////////////////
#include <structure/utilities/string/del_space.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
