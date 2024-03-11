////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 04.03.2024
#ifndef _cpp_public_lcpi_lib_structure_stl__t_stl_set_H_
#define _cpp_public_lcpi_lib_structure_stl__t_stl_set_H_

#include <set>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

//Helper structure to overcome C++17 requirements

template<class Key,class Less,class allocator>
using t_stl_set
 =std::set
   <Key,
    Less,
    typename allocator::template rebind<Key>::other>;

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
