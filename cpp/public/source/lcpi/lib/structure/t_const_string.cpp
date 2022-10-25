////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                Dmitry Kovalenko. 03.10.2016.
#include <_pch_.h>
#pragma hdrstop

#include <lcpi/lib/structure/t_const_string.h>

namespace lcpi{namespace lib{namespace structure{
////////////////////////////////////////////////////////////////////////////////

#ifndef COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001
# error COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001 not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_helper<char>

#if(COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001!=0)

const char t_basic_const_string_helper<char>::sm_emptyStr[1]
 ={0};

#endif

////////////////////////////////////////////////////////////////////////////////
//class t_basic_const_string_helper<wchar_t>

#if(COMP_CONF_HAS_PROBLEM_WITH_TEMPLATE_001!=0)

const wchar_t t_basic_const_string_helper<wchar_t>::sm_emptyStr[1]
 ={0};

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms structure*/}/*nms lib*/}/*nms lcpi*/
