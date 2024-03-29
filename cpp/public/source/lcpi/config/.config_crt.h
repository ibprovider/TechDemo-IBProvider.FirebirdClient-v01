///////////////////////////////////////////////////////////////////////////////
//LCPI C++ Library.
//                                               Dmitry Kovalenko. 30.09.2020.
#ifndef _cpp_public_lcpi_config__config_crt_H_
#define _cpp_public_lcpi_config__config_crt_H_

#include <lcpi/config/.config_compiler.h>

///////////////////////////////////////////////////////////////////////////////
//CRT Library IDs

#define LCPI_CRT_LIBRARY_ID__VISUALC_V90                0x40000090

///////////////////////////////////////////////////////////////////////////////
//Definitions
//
// LCPI_GCRT_itoa
// LCPI_GCRT_ultoa
// LCPI_GCRT_strcmpi
// LCPI_GCRT_getch
//
//Security versions ------------------------------------------------------
//
// LCPI_GCRT_itoa_s
// LCPI_GCRT_ltoa_s
// LCPI_GCRT_ultoa_s
// LCPI_GCRT_i64toa_s
// LCPI_GCRT_ui64toa_s
//
// LCPI_GCRT_itow_s
// LCPI_GCRT_ltow_s
// LCPI_GCRT_ultow_s
// LCPI_GCRT_i64tow_s
// LCPI_GCRT_ui64tow_s
//
// LCPI_GCRT_itot_s
// LCPI_GCRT_ltot_s
// LCPI_GCRT_ultot_s
// LCPI_GCRT_i64tot_s
// LCPI_GCRT_ui64tot_s
//
// LCPI_GCRT_strcpy_s
// LCPI_GCRT_wcscpy_s
//
// X: <none>|w|t
//
// LCPI_GCRT_sXprintf_s_n1 (buffer,buffer_size,format,a1)
// LCPI_GCRT_sXprintf_s_n2 (buffer,buffer_size,format,a1,a2)
// LCPI_GCRT_sXprintf_s_n3 (buffer,buffer_size,format,a1,a2,a3)
// LCPI_GCRT_sXprintf_s_n4 (buffer,buffer_size,format,a1,a2,a3,a4)
// LCPI_GCRT_sXprintf_s_n5 (buffer,buffer_size,format,a1,a2,a3,a4,a5)
// LCPI_GCRT_sXprintf_s_n6 (buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)
// LCPI_GCRT_sXprintf_s_n7 (buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)
//
// LCPI_GCRT_localtime_s
//
//Assert implementation --------------------------------------------------
//
// LCPI_GCRT_run_assert (expr, message)
//
///////////////////////////////////////////////////////////////////////////////
//Detect CRT Library ID

#if !defined(LCPI_CRT_LIBRARY_ID)

# if !defined(LCPI_CPP_COMP_ID__CURRENT)
#  error "Unknown compiler"
# endif

# if    (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V120)
#  define LCPI_CRT_LIBRARY_ID                              LCPI_CRT_LIBRARY_ID__VISUALC_V90
# elif  (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V140)
#  define LCPI_CRT_LIBRARY_ID                              LCPI_CRT_LIBRARY_ID__VISUALC_V90
# elif  (LCPI_CPP_COMP_ID__CURRENT==LCPI_CPP_COMP_ID__VISUALC_V150)
#  define LCPI_CRT_LIBRARY_ID                              LCPI_CRT_LIBRARY_ID__VISUALC_V90
# else
#  error "Can't detect CRT ID. Unknown complier."
# endif

#endif //LCPI_CRT_LIBRARY_ID

///////////////////////////////////////////////////////////////////////////////
//Config for current CRT

#if    (LCPI_CRT_LIBRARY_ID==LCPI_CRT_LIBRARY_ID__VISUALC_V90)
# include <lcpi/config/crt/.config_crt__vc9.h>
#else
# error "Unknown CRT Library ID"
#endif

///////////////////////////////////////////////////////////////////////////////
//Verifications

#ifndef LCPI_GCRT_itoa
# error LCPI_GCRT_itoa not defined
#endif

#ifndef LCPI_GCRT_ultoa
# error LCPI_GCRT_ultoa not defined
#endif

#ifndef LCPI_GCRT_strcmpi
# error LCPI_GCRT_strcmpi not defined
#endif

#ifndef LCPI_GCRT_getch
# error LCPI_GCRT_getch not defined
#endif

//Security versions ------------------------------------------------------

#ifndef LCPI_GCRT_itoa_s
# error LCPI_GCRT_itoa_s not defined
#endif

#ifndef LCPI_GCRT_ltoa_s
# error LCPI_GCRT_ltoa_s not defined
#endif

#ifndef LCPI_GCRT_ultoa_s
# error LCPI_GCRT_ultoa_s not defined
#endif

#ifndef LCPI_GCRT_i64toa_s
# error LCPI_GCRT_i64toa_s not defined
#endif

#ifndef LCPI_GCRT_ui64toa_s
# error LCPI_GCRT_ui64toa_s not defined
#endif

#ifndef LCPI_GCRT_itow_s
# error LCPI_GCRT_itow_s not defined
#endif

#ifndef LCPI_GCRT_ltow_s
# error LCPI_GCRT_ltow_s not defined
#endif

#ifndef LCPI_GCRT_ultow_s
# error LCPI_GCRT_ultow_s not defined
#endif

#ifndef LCPI_GCRT_i64tow_s
# error LCPI_GCRT_i64tow_s not defined
#endif

#ifndef LCPI_GCRT_ui64tow_s
# error LCPI_GCRT_ui64tow_s not defined
#endif

#ifndef LCPI_GCRT_itot_s
# error LCPI_GCRT_itot_s not defined
#endif

#ifndef LCPI_GCRT_ltot_s
# error LCPI_GCRT_ltot_s not defined
#endif

#ifndef LCPI_GCRT_ultot_s
# error LCPI_GCRT_ultot_s not defined
#endif

#ifndef LCPI_GCRT_i64tot_s
# error LCPI_GCRT_i64tot_s not defined
#endif

#ifndef LCPI_GCRT_ui64tot_s
# error LCPI_GCRT_ui64tot_s not defined
#endif

#ifndef LCPI_GCRT_strcpy_s
# error LCPI_GCRT_strcpy_s not defined
#endif

#ifndef LCPI_GCRT_wcscpy_s
# error LCPI_GCRT_wcscpy_s not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_GCRT_sprintf_s_n1
# error LCPI_GCRT_sprintf_s_n1 not defined
#endif

#ifndef LCPI_GCRT_sprintf_s_n2
# error LCPI_GCRT_sprintf_s_n2 not defined
#endif

#ifndef LCPI_GCRT_sprintf_s_n3
# error LCPI_GCRT_sprintf_s_n3 not defined
#endif

#ifndef LCPI_GCRT_sprintf_s_n4
# error LCPI_GCRT_sprintf_s_n4 not defined
#endif

#ifndef LCPI_GCRT_sprintf_s_n5
# error LCPI_GCRT_sprintf_s_n5 not defined
#endif

#ifndef LCPI_GCRT_sprintf_s_n6
# error LCPI_GCRT_sprintf_s_n6 not defined
#endif

#ifndef LCPI_GCRT_sprintf_s_n7
# error LCPI_GCRT_sprintf_s_n7 not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_GCRT_swprintf_s_n1
# error LCPI_GCRT_swprintf_s_n1 not defined
#endif

#ifndef LCPI_GCRT_swprintf_s_n2
# error LCPI_GCRT_swprintf_s_n2 not defined
#endif

#ifndef LCPI_GCRT_swprintf_s_n3
# error LCPI_GCRT_swprintf_s_n3 not defined
#endif

#ifndef LCPI_GCRT_swprintf_s_n4
# error LCPI_GCRT_swprintf_s_n4 not defined
#endif

#ifndef LCPI_GCRT_swprintf_s_n5
# error LCPI_GCRT_swprintf_s_n5 not defined
#endif

#ifndef LCPI_GCRT_swprintf_s_n6
# error LCPI_GCRT_swprintf_s_n6 not defined
#endif

#ifndef LCPI_GCRT_swprintf_s_n7
# error LCPI_GCRT_swprintf_s_n7 not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_GCRT_stprintf_s_n1
# error LCPI_GCRT_stprintf_s_n1 not defined
#endif

#ifndef LCPI_GCRT_stprintf_s_n2
# error LCPI_GCRT_stprintf_s_n2 not defined
#endif

#ifndef LCPI_GCRT_stprintf_s_n3
# error LCPI_GCRT_stprintf_s_n3 not defined
#endif

#ifndef LCPI_GCRT_stprintf_s_n4
# error LCPI_GCRT_stprintf_s_n4 not defined
#endif

#ifndef LCPI_GCRT_stprintf_s_n5
# error LCPI_GCRT_stprintf_s_n5 not defined
#endif

#ifndef LCPI_GCRT_stprintf_s_n6
# error LCPI_GCRT_stprintf_s_n6 not defined
#endif

#ifndef LCPI_GCRT_stprintf_s_n7
# error LCPI_GCRT_stprintf_s_n7 not defined
#endif

//------------------------------------------------------------------------
#ifndef LCPI_GCRT_localtime_s
# error LCPI_GCRT_localtime_s not defined
#endif

//Assert implementation --------------------------------------------------

#ifndef LCPI_GCRT_run_assert
# error LCPI_GCRT_run_assert not defined
#endif

///////////////////////////////////////////////////////////////////////////////
#endif
