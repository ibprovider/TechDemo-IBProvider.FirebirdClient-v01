////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 04.03.2024
#ifndef _cpp_public_lcpi_lib_structure_stl__t_stl_map_H_
#define _cpp_public_lcpi_lib_structure_stl__t_stl_map_H_

#include <map>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

//Helper structure to overcome C++17 requirements

template<class Key,class T,class Less,class allocator>
using t_stl_map
 =std::map
   <Key,
    T,
    Less,
    typename allocator::template rebind<std::pair<const Key,T>>::other>;

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
