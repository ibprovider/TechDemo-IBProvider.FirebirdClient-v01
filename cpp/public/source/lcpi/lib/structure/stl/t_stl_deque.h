////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 04.03.2024
#ifndef _cpp_public_lcpi_lib_structure_stl__t_stl_deque_H_
#define _cpp_public_lcpi_lib_structure_stl__t_stl_deque_H_

#include <deque>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

//Helper structure to overcome C++17 requirements

template<class T,class allocator>
using t_stl_deque
 =std::deque
   <T,
    typename allocator::template rebind<T>::other>;

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
