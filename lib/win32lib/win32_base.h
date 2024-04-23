////////////////////////////////////////////////////////////////////////////////
#ifndef _win32_base_H_
#define _win32_base_H_

#include <structure/t_char_converter.h>

#include <type_traits>
#include <tchar.h>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//UNICODE support

//typedefs
using structure::t_char;
using structure::t_string;

//functions for convert between char sets
using structure::tstr_to_str;
using structure::tstr_to_wstr;

using structure::str_to_tstr;
using structure::wstr_to_tstr;

////////////////////////////////////////////////////////////////////////////////

LCPI__assert_s(std::is_same<win32lib::t_char LCPI__LITER_COMMA TCHAR>::value);

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib

////////////////////////////////////////////////////////////////////////////////
//BCB3

#if defined(__BORLANDC__)

# if(__BORLANDC__<=0x0530)   //BCB3

   //typedes -------------------------------------------------------------
   typedef DWORD             ULONG_PTR;
   typedef LONG              LONG_PTR;
   typedef DWORD             DWORD_PTR;
   typedef int               INT_PTR;

   //macros --------------------------------------------------------------
#  define IS_INTRESOURCE(_r) (((ULONG_PTR)(_r) >> 16) == 0)

# endif //BCB3

#endif

////////////////////////////////////////////////////////////////////////////////
#endif