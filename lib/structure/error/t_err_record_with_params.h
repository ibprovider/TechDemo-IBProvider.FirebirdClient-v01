////////////////////////////////////////////////////////////////////////////////
//exception record with template message
//                                                 Dmitry Kovalenko. 15.08.2004.
#ifndef _t_err_record_with_params_H_
#define _t_err_record_with_params_H_

#include <structure/error/t_err_record_with_params2.h>
#include <structure/t_str_cvt_traits__unicode_or_ascii.h>
#include <structure/t_memory.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//content

template<class record_traits,class charT=wchar_t,class Allocator=t_void_allocator>
using t_err_record_with_params
 =t_err_record_with_params2
   <record_traits,
    charT,
    t_str_cvt_traits__unicode_or_ascii,
    Allocator>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif

