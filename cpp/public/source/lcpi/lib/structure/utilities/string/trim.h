////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 28.01.2020
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__trim_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__trim_H_

#include <lcpi/lib/.config.h>

#include <string>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//service templates for trim operations

//TTrimComp(TUnsignedChar) - unary function for detect trimming symbol
// return true - for trim symbol

template<class TStr,class TTrimComp>
 TStr trimr(const TStr& str,TTrimComp is_trim_char);

template<class TStr,class TTrimComp>
 TStr triml(const TStr& str,TTrimComp is_trim_char);

template<class TStr,class TTrimComp>
 TStr trim(const TStr& str,TTrimComp is_trim_char);

template<class TStr,class TTrimComp>
 TStr& self_trimr(TStr& str,TTrimComp is_trim_char);

template<class TStr,class TTrimComp>
 TStr& self_triml(TStr& str,TTrimComp is_trim_char);

template<class TStr,class TTrimComp>
 TStr& self_trim(TStr& str,TTrimComp is_trim_char);

////////////////////////////////////////////////////////////////////////////////
//trim string functions (implementation in t_char.cc)

//GENERIC trimXXX
template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>
 trimr(const std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>
 triml(const std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>
 trim(const std::basic_string<charT,traits,Allocator>& str);

//GENERIC self_trimXXX
template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>&
 self_trimr(std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>&
 self_triml(std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>&
 self_trim(std::basic_string<charT,traits,Allocator>& str);

//GENERIC total_trimXXX
template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>
 total_trimr(const std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>
 total_triml(const std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>
 total_trim(const std::basic_string<charT,traits,Allocator>& str);

//GENERIC total_self_trimXXX
template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>&
 total_self_trimr(std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>&
 total_self_triml(std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
std::basic_string<charT,traits,Allocator>&
 total_self_trim(std::basic_string<charT,traits,Allocator>& str);

////////////////////////////////////////////////////////////////////////////////
//detect empty trimed string

template<class charT,class traits,class Allocator>
bool trim_empty(const std::basic_string<charT,traits,Allocator>& str);

template<class charT,class traits,class Allocator>
bool total_trim_empty(const std::basic_string<charT,traits,Allocator>& str);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/string/trim.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
