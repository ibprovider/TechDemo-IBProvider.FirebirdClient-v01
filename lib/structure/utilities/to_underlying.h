////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 09.09.2019
#ifndef _lcpi_lib_structure_utilities__to_underlying_H_
#define _lcpi_lib_structure_utilities__to_underlying_H_

#include <structure/t_common.h>

namespace structure{
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
}//namespace structure
#endif
