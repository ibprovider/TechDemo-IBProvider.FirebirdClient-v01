////////////////////////////////////////////////////////////////////////////////
//Simple implementation of t_err_record
//                                                 Dmitry Kovalenko. 15.08.2004.
#ifndef _t_err_simple_record_H_
#define _t_err_simple_record_H_

#include <structure/error/t_err_simple_record2.h>
#include <structure/t_str_cvt_traits__unicode_or_ascii.h>
#include <structure/t_memory.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containing

template<class Allocator>
using t_err_basic_record_v2
 =t_err_simple_record2
   <t_str_cvt_traits__unicode_or_ascii,
    Allocator>;

////////////////////////////////////////////////////////////////////////////////
//typedefs

using t_err_simple_record
 =t_err_basic_record_v2
   <t_void_allocator>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
