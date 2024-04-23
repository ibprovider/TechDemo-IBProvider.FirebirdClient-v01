////////////////////////////////////////////////////////////////////////////////
//Base class for string arguments/parameters managements
//                                                 Dmitry Kovalenko. 05.04.2004
#ifndef _lcpi_lib_structure__t_str_args_H_
#define _lcpi_lib_structure__t_str_args_H_

#include <structure/t_str_args2.h>
#include <structure/t_str_args_traits.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class charT,class t_outer>
using t_basic_str_args
 =t_basic_str_args2<charT,t_outer,t_str_args_traits<charT> >;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
