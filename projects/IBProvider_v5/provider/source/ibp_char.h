////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_char.h
//! \brief   ����������� ��������� ����� ��� ������ � ��������
//! \author  Kovalenko Dmitry
//! \date    11.11.2008
#ifndef _ibp_char_H_
#define _ibp_char_H_

#include <lcpi/lib/structure/t_const_str_box.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////

///��� ��������� ������� ��� ����� ������
using t_ibp_char
 =wchar_t;

///����� ��� ������ �� ��������
using t_ibp_string
 =LCPI_STL_DEF_BASIC_STRING(t_ibp_char);

///����� ��� ������ �� ��������
using t_ibp_str_box
 =lib::structure::t_basic_const_str_box<t_ibp_char>;

///����� ��� ������ �� UNICODE-��������
using t_ibp_wstr_box
 =lib::structure::t_basic_const_str_box<wchar_t>;

///����� ��� ������ �� ANSI-��������
using t_ibp_astr_box
 =lib::structure::t_basic_const_str_box<char>;

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
