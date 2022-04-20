////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 29.01.2020
#ifndef _lcpi_lib_structure_stl__t_stl_list_H_
#define _lcpi_lib_structure_stl__t_stl_list_H_

#include <list>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

//Helper structure to overcome C++17 requirements

template<class T,class allocator>
using t_stl_list
 =std::list
   <T,
    typename allocator::template rebind<T>::other>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
