////////////////////////////////////////////////////////////////////////////////
//exception class for t_err_record_with_params
//                                                 Dmitry Kovalenko. 16.08.2004
#ifndef _t_err_exception_with_params_H_
#define _t_err_exception_with_params_H_

#include <structure/error/t_err_exception_with_params2.h>
#include <structure/t_str_cvt_traits__unicode_or_ascii.h>
#include <structure/t_memory.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//containings

template<class t_record,class charT=wchar_t,class Allocator=t_void_allocator>
using t_err_exception_with_params
 =t_err_exception_with_params2
   <t_record,
    charT,
    t_str_cvt_traits__unicode_or_ascii,
    Allocator>;

////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
