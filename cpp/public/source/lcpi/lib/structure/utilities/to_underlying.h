////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 09.09.2019
#ifndef _cpp_public_lcpi_lib_structure_utilities__to_underlying_H_
#define _cpp_public_lcpi_lib_structure_utilities__to_underlying_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

#ifndef COMP_CONF_SUPPORT_ENUM_CLASS
# error "COMP_CONF_SUPPORT_ENUM_CLASS not defiled"
#endif

////////////////////////////////////////////////////////////////////////////////

#if(COMP_CONF_SUPPORT_ENUM_CLASS!=0)

template<typename T>
inline typename std::underlying_type<T>::type to_underlying(T v)
{
 assert_s(std::is_enum<T>::value);

 return static_cast<typename std::underlying_type<T>::type>(v);
}//to_underlying

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
