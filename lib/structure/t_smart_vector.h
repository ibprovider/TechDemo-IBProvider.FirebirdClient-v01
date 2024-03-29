////////////////////////////////////////////////////////////////////////////////
//Container for smart object pointers
//                                           Kovalenko Dmitry. February 3, 2001.
#ifndef _t_smart_vector_H_
#define _t_smart_vector_H_

#include <structure/t_smart_object_ptr.h>
#include <structure/t_memory.h>
#include <structure/stl/t_stl_vector.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//class t_smart_vector

#if(COMP_CONF_SUPPORT_TEMPLATE_USING==0)
# error Compiler does not support 'using' statement.
#endif

template<class T,class Allocator=t_void_allocator>
using t_smart_vector=t_stl_vector<t_smart_object_ptr<T>,Allocator>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
