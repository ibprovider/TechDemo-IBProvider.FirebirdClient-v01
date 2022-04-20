////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental C++ Library
//                                                 Dmitry Kovalenko. 29.01.2020
#ifndef _lcpi_lib_structure_stl__t_stl_deque_H_
#define _lcpi_lib_structure_stl__t_stl_deque_H_

#include <deque>

namespace structure{
////////////////////////////////////////////////////////////////////////////////

//Helper structure to overcome C++17 requirements

template<class T,class allocator>
using t_stl_deque
 =std::deque
   <T,
    typename allocator::template rebind<T>::other>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
