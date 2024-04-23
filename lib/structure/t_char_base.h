////////////////////////////////////////////////////////////////////////////////
//Base header of library for work with chars
//                                                 Dmitry Kovalenko. 19.04.2004.
#ifndef _lcpi_lib_structure__t_char_base_H_
#define _lcpi_lib_structure__t_char_base_H_

#include <lcpi/lib/.config.h>

#include <string>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//declare target types

#ifndef _UNICODE

using t_char=char;

#define LCPI_CPP_LIB__TEXT(x) x

#else

using t_char=wchar_t;

#define LCPI_CPP_LIB__TEXT(x) L ## x

#endif //UNICODE

using t_string=LCPI_STL_DEF_BASIC_STRING(t_char);

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif