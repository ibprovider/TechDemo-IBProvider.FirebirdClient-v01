///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Library.
//                                               Dmitry Kovalenko. 27.09.2022.
#ifndef _cpp_public_lcpi_lib__common_utilities_H_
#define _cpp_public_lcpi_lib__common_utilities_H_

#include <lcpi/lib/.config.h>

#include <type_traits>

///////////////////////////////////////////////////////////////////////////////

#define _LCPI_DIM_(arrayValue) \
 (std::extent                  \
    <std::enable_if            \
       <std::is_array<decltype(arrayValue)>::value && std::rank<decltype(arrayValue)>::value==1, \
        decltype(arrayValue)>  \
     ::type>                   \
  ::value)

///////////////////////////////////////////////////////////////////////////////

#define _LCPI_END_(arrayValue) \
 ((arrayValue)+_LCPI_DIM_(arrayValue))

///////////////////////////////////////////////////////////////////////////////
#endif
