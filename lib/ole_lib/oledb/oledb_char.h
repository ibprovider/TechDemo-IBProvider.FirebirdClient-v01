////////////////////////////////////////////////////////////////////////////////
//OLEDB Library. ANSI/UNICODE Configurations
//                                              Коваленко Дмитрий. 12.12.2006.
#ifndef _oledb_char_H_
#define _oledb_char_H_

#include <structure/t_str_parameter.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//Configurations
//
// _OLEDB_LIB_CFG__UNICODE
//  - <not defined>   Check exists of system macros _UNICODE
//  - 0               use ANSI strings
//  - 1               use UNICODE strings
//

////////////////////////////////////////////////////////////////////////////////
//oledb-strings configurations

//Auto configurations
#ifndef _OLEDB_LIB_CFG__UNICODE
# ifdef _UNICODE
#  define _OLEDB_LIB_CFG__UNICODE 1
# else
#  define _OLEDB_LIB_CFG__UNICODE 0
# endif
#endif

//------------------------------------------------------------------------
#if(_OLEDB_LIB_CFG__UNICODE==0)
typedef char                         t_oledb_char;

# define _OLEDB_LIB_T(text)                               text

# define _OLEDB_LIB_lstrcmpi                              lstrcmpiA
# define _OLEDB_LIB_strcmp                                strcmp
# define _OLEDB_LIB_stricmp                               LCPI_GCRT_stricmp
# define _OLEDB_LIB_itot_s                                LCPI_GCRT_itoa_s
# define _OLEDB_LIB_ltot_s                                LCPI_GCRT_ltoa_s

#else
typedef wchar_t                      t_oledb_char;

# define _OLEDB_LIB_T(text)                               L##text

# define _OLEDB_LIB_lstrcmpi                              lstrcmpiW
# define _OLEDB_LIB_strcmp                                wcscmp
# define _OLEDB_LIB_stricmp                               LCPI_GCRT_wcsicmp
# define _OLEDB_LIB_itot_s                                LCPI_GCRT_itow_s
# define _OLEDB_LIB_ltot_s                                LCPI_GCRT_ltow_s

#endif

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef structure::t_str_parameter
         <t_oledb_char>                                   t_oledb_str_arg;

typedef std::basic_string
         <t_oledb_char,std::char_traits<t_oledb_char> >   t_oledb_string;

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif