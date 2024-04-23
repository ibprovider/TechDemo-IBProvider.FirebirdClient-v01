////////////////////////////////////////////////////////////////////////////////
//Traits for convert several simple types to std::basic_string
//                                                 Dmitry Kovalenko. xx.04.2004
#ifndef _lcpi_lib_structure__t_str_args_traits_H_
#define _lcpi_lib_structure__t_str_args_traits_H_

#include <structure/t_str_args2_traits.h>
#include <structure/t_str_cvt_traits__unicode_or_ascii.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class charT>
using t_str_args_traits
 =t_str_args2_traits<charT,t_str_cvt_traits__unicode_or_ascii>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
