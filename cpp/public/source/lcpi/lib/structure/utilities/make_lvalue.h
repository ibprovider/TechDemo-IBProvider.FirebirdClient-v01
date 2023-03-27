////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 02.10.2019
#ifndef _cpp_public_lcpi_lib_structure_utilities__make_lvalue_H_
#define _cpp_public_lcpi_lib_structure_utilities__make_lvalue_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

//
// Usage:
//  string func1();
//  void func2(string& s);
//
//  func2(structure::make_lvalue(func1());
//
// Author:
//  rg45 (rsdn.org)
//
template<typename T>
inline T& make_lvalue(T&& v)
{
 return v;
}//make_lvalue

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
