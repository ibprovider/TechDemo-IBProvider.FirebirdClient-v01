////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 11.04.2024.
#ifndef _cpp_public_lcpi_lib_structure_utilities__string__call_to_string_H_
#define _cpp_public_lcpi_lib_structure_utilities__string__call_to_string_H_

#include <lcpi/lib/.config.h>
#include <string>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class call_to_string

template<typename charT>
class call_to_string
{
};//class call_to_string

////////////////////////////////////////////////////////////////////////////////
//class call_to_string<char>

template<>
class call_to_string<char>
{
 public:
  template<typename TArg>
  static LCPI_STL_DEF_BASIC_STRING(char) exec(TArg&& a)
  {
   return LCPI_STL_TO_STRING(LCPI_STL_FORWARD_VALUE(TArg,a));
  }//exec
};//class call_to_string<char>

////////////////////////////////////////////////////////////////////////////////
//class call_to_string<wchar_t>

template<>
class call_to_string<wchar_t>
{
 public:
  template<typename TArg>
  static LCPI_STL_DEF_BASIC_STRING(wchar_t) exec(TArg&& a)
  {
   return LCPI_STL_TO_WSTRING(LCPI_STL_FORWARD_VALUE(TArg,a));
  }//exec
};//class call_to_string<wchar_t>

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
