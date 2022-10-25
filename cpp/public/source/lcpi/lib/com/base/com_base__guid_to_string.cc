////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__guid_to_string_CC_
#define _cpp_public_lcpi_lib_com_base__guid_to_string_CC_

#include <lcpi/lib/structure/utilities/uuid_to_string.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////

namespace detail{
////////////////////////////////////////////////////////////////////////////////

template<typename charT>
std::basic_string<charT> guid_to_text(REFGUID rguid)
{
 //12345678901234567890123456789012345678  38
 //{xxXXxxXX-xxXX-xxXX-xxXX-xxXXxxXXxxXX}

 std::basic_string<charT> result;

 result.resize(38);

 typedef structure::t_char_traits2<charT> char_traits2;

 auto p=result.begin();

 (*p)=char_traits2::ch_open_fbracket(); ++p;

 p=structure::uuid_to_string(rguid,p);

 assert(p==result.begin()+37);

 (*p)=char_traits2::ch_close_fbracket();

#ifndef NDEBUG
  ++p;

  assert(p==result.end());
#endif

 return result;
}//guid_to_text

////////////////////////////////////////////////////////////////////////////////
}//namespace detail

inline std::string guid_to_string(REFGUID rguid)
{
 return detail::guid_to_text<char>(rguid);
}//guid_to_string

//------------------------------------------------------------------------
inline std::wstring guid_to_wstring(REFGUID rguid)
{
 return detail::guid_to_text<wchar_t>(rguid);
}//guid_to_wstring

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif
