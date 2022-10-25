////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 27.09.2022.
#ifndef _cpp_public_lcpi_lib_structure_utilities__string_to_uuid_H_
#define _cpp_public_lcpi_lib_structure_utilities__string_to_uuid_H_

#include <lcpi/lib/.config.h>

#include <utility> //std::pair

#include <guiddef.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename Iterator>
std::pair<Iterator,bool> string_to_uuid(Iterator beg,Iterator end,GUID* pUUID);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/string_to_uuid.cc>
////////////////////////////////////////////////////////////////////////////////
#endif //_cpp_public_lcpi_lib_structure_utilities__string_to_uuid_H_
