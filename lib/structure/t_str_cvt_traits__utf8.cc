////////////////////////////////////////////////////////////////////////////////
//LCPI instrumental C++ library.
//                                                 Dmitry Kovalenko. 11.04.2024.
#ifndef _lcpi_lib_structure__t_str_cvt_traits__utf8_CC_
#define _lcpi_lib_structure__t_str_cvt_traits__utf8_CC_

#include <structure/charsets/cs_cvt__wchar_to_utf8.h>
#include <type_traits>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_str_cvt_traits__utf8

template<class charTraits,class Allocator>
void t_str_cvt_traits__utf8::tstr_to_tstr
                        (std::basic_string<char,charTraits,Allocator>* const pDest,
                         t_const_wstr_box                              const src)
{
 assert(pDest!=nullptr);

 using dest_type=typename std::remove_reference<decltype(*pDest)>::type;

 LCPI__assert_s(std::is_same<typename dest_type::value_type LCPI__LITER_COMMA char>::value);

 dest_type dest;

 const auto r
  =structure::charsets::cs_cvt__wchar_to_utf8
    (src.begin(),
     src.end(),
     std::back_inserter(dest));

 if(r.code!=structure::charsets::cs_cvt_result_code::ok)
 {
  self_type::helper__throw_error("WSTR string has not converted int UTF8");
 }

 assert(r.input==src.end());

 pDest->swap(dest);
}//tstr_to_tstr

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
