////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 29.01.2020
#ifndef _lcpi_lib_structure_stl__t_stl_map_H_
#define _lcpi_lib_structure_stl__t_stl_map_H_

#include <map>

namespace structure{
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
}//namespace structure
#endif
