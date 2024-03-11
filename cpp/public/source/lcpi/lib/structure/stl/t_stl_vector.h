////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 04.03.2024
#ifndef _cpp_public_lcpi_lib_structure_stl__t_stl_vector_H_
#define _cpp_public_lcpi_lib_structure_stl__t_stl_vector_H_

#include <vector>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

//Helper structure to overcome C++17 requirements

template<class T,class allocator>
using t_stl_vector
 =std::vector
   <T,
    typename allocator::template rebind<T>::other>;

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
