////////////////////////////////////////////////////////////////////////////////
//Library for thread's configurations
//                                               Dmitry Kovalenko. 21.04.2004
#ifndef _lcpi_lib_structure__t_threads_H_
#define _lcpi_lib_structure__t_threads_H_

#include <structure/t_thread_traits__single.h>
#include <structure/t_thread_traits__multi.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//typedefs

using t_single_thread_traits
 =t_thread_traits__single;

using t_multi_thread_traits
 =t_thread_traits__multi;

using t_def_thread_traits
 =t_multi_thread_traits;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
