////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_char.h
//! \brief   ����������� ��������� ����� ��� ������ � ��������
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

///��� ��������� ������� ��� ����� ������
typedef wchar_t                                          t_ibp_char;

///����� ��� ������ �� ��������
typedef __STL_DEF_BASIC_STRING(t_ibp_char)               t_ibp_string;

///����� ��� ������ �� ��������
typedef structure::t_basic_const_str_box<t_ibp_char>     t_ibp_str_box;

///����� ��� ������ �� UNICODE-��������
typedef structure::t_basic_const_str_box<wchar_t>        t_ibp_wstr_box;

///����� ��� ������ �� ANSI-��������
typedef structure::t_basic_const_str_box<char>           t_ibp_astr_box;

///������ ��� ������������ ��������� ������
#define IBP_MAKE_UNICODE_TEXT(text) L##text

///������ ��� ������������ ������� ��������
#define IBP_T(text) IBP_MAKE_UNICODE_TEXT(text)

#define IBP_UCS2(text) IBP_MAKE_UNICODE_TEXT(text)

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
