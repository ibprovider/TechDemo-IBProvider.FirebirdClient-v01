////////////////////////////////////////////////////////////////////////////////
//Container for smart object pointers
//                                           Kovalenko Dmitry. February 3, 2001.
#ifndef _cpp_public_lcpi_lib_structure__t_smart_vector_H_
#define _cpp_public_lcpi_lib_structure__t_smart_vector_H_

#include <lcpi/lib/structure/t_smart_object_ptr.h>
#include <lcpi/lib/structure/t_memory.h>
#include <lcpi/lib/structure/stl/t_stl_vector.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_smart_vector

#ifndef LCPI_CPP_CFG__SUPPORT_TEMPLATE_USING
# error LCPI_CPP_CFG__SUPPORT_TEMPLATE_USING is not defined
#endif

#if(LCPI_CPP_CFG__SUPPORT_TEMPLATE_USING==0)
# error Compiler does not support 'using' statement.
#endif

template<class T,class Allocator=t_void_allocator>
using t_smart_vector=t_stl_vector<t_smart_object_ptr<T>,Allocator>;

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
#endif
