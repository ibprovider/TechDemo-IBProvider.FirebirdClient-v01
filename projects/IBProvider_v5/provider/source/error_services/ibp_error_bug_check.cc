////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_bug_check.cc
//! \brief   Конструкции для обработки внутренних ошибок
//! \author  Kovalenko Dmitry
//! \date    28.01.2017
#ifndef _ibp_error_bug_check_CC_
#define _ibp_error_bug_check_CC_

#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

template<typename T>
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__UnexpectedPropValue(const wchar_t* const place,
                                            const wchar_t* const point,
                                            const wchar_t* const prop_name,
                                            const T&             value)
{
 assert(place);
 assert(point);
 assert(prop_name);

 structure::wstr_formatter freason(me_bug_check__prop__unexpected_value_2);

 freason<<prop_name<<value;

 IBP_ThrowBugCheck(place,point,freason.c_str()); //throw!

#if(COMP_BUILD_UNUSED_CODE!=0)
 assert_hint(false);
#endif
}//IBP_ThrowBugCheck__UnexpectedPropValue

////////////////////////////////////////////////////////////////////////////////

template<typename TLength>
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__IncorrectDataLength(const wchar_t* const place,
                                            const wchar_t* const point,
                                            TLength        const length)
{
 assert(place);
 assert(point);

 structure::wstr_formatter
  freason(me_bug_check__incorrect_length_of_data_1);

 freason<<length;

 IBP_ThrowBugCheck(place,point,freason.c_str()); //throw!

#if(COMP_BUILD_UNUSED_CODE!=0)
 assert_hint(false);
#endif
}//IBP_ThrowBugCheck__IncorrectDataLength

////////////////////////////////////////////////////////////////////////////////

template<typename TLength,typename TBufSize>
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__TooLargeDataLength(const wchar_t* const place,
                                           const wchar_t* const point,
                                           TLength        const length,
                                           TBufSize       const bufSize)
{
 assert(place);
 assert(point);

 structure::wstr_formatter
  freason(me_bug_check__size_of_result_data_larger_than_buf_size_2);

 freason<<length<<bufSize;

 IBP_ThrowBugCheck(place,point,freason.c_str()); //throw!

#if(COMP_BUILD_UNUSED_CODE!=0)
 assert_hint(false);
#endif
}//IBP_ThrowBugCheck__TooLargeDataLength

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
