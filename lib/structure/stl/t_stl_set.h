////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 29.01.2020
#ifndef _lcpi_lib_structure_stl__t_stl_set_H_
#define _lcpi_lib_structure_stl__t_stl_set_H_

#include <set>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

//Helper structure to overcome C++17 requirements

template<class Key,class Less,class allocator>
using t_stl_set
 =std::set
   <Key,
    Less,
    typename allocator::template rebind<Key>::other>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
