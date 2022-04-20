////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_char.h
//! \brief   Определение первичных типов для работы с строками
//! \author  Kovalenko Dmitry
//! \date    11.11.2008
#ifndef _ibp_char_H_
#define _ibp_char_H_

#include <structure/t_const_str_box.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////

///Тип основного символа для строк модуля
typedef wchar_t                                          t_ibp_char;

///Класс для работы со строками
typedef __STL_DEF_BASIC_STRING(t_ibp_char)               t_ibp_string;

///Класс для работы со строками
typedef structure::t_basic_const_str_box<t_ibp_char>     t_ibp_str_box;

///Класс для работы со UNICODE-строками
typedef structure::t_basic_const_str_box<wchar_t>        t_ibp_wstr_box;

///Класс для работы со ANSI-строками
typedef structure::t_basic_const_str_box<char>           t_ibp_astr_box;

///Макрос для формирования юникодной строки
#define IBP_MAKE_UNICODE_TEXT(text) L##text

///Макрос для формирования массива символов
#define IBP_T(text) IBP_MAKE_UNICODE_TEXT(text)

#define IBP_UCS2(text) IBP_MAKE_UNICODE_TEXT(text)

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
