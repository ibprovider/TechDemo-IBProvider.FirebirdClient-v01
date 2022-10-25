////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 25.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__string_to_guid_H_
#define _cpp_public_lcpi_lib_com_base__string_to_guid_H_

#include <lcpi/lib/structure/t_const_str_box.h>

#include <lcpi/lib/.config.h>

#include <guiddef.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////

inline bool string_to_guid(structure::t_const_str_box str,GUID* pGUID);

inline bool string_to_guid(structure::t_const_wstr_box str,GUID* pGUID);

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/com/base/com_base__string_to_guid.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
