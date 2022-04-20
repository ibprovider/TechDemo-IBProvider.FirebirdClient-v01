////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 30.09.2020.
#ifndef _cpp_public_lcpi_lib_structure_debug__assert_s_H_
#define _cpp_public_lcpi_lib_structure_debug__assert_s_H_

#include <lcpi/lib/.config.h>

///////////////////////////////////////////////////////////////////////////////

#define LCPI__assert_s(cond) static_assert(cond,#cond)

///////////////////////////////////////////////////////////////////////////////
#endif
