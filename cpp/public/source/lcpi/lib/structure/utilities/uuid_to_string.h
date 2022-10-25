////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_structure_utilities__uuid_to_string_H_
#define _cpp_public_lcpi_lib_structure_utilities__uuid_to_string_H_

#include <lcpi/lib/.config.h>

#include <utility> //std::pair

#include <guiddef.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

template<typename OutputIterator>
OutputIterator uuid_to_string(REFGUID uuid,OutputIterator dest);

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include <lcpi/lib/structure/utilities/uuid_to_string.cc>
////////////////////////////////////////////////////////////////////////////////
#endif //_cpp_public_lcpi_lib_structure_utilities__uuid_to_string_H_

