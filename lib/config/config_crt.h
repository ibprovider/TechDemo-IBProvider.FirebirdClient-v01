///////////////////////////////////////////////////////////////////////////////
//C Library Configuration
//                                               Dmitry Kovalenko. 26.05.2006
#ifndef _config_crt_H_
#define _config_crt_H_

///////////////////////////////////////////////////////////////////////////////
//CRT Library IDs

#define __CRT_LIBRARY_ID_CBUILDER3                  0x20000030
#define __CRT_LIBRARY_ID_CBUILDER4                  0x20000040
#define __CRT_LIBRARY_ID_CBUILDER5                  0x20000050
#define __CRT_LIBRARY_ID_CBUILDER6                  0x20000060
#define __CRT_LIBRARY_ID_CBUILDER7                  0x20000070

#define __CRT_LIBRARY_ID_VISUALC_V60                0x40000060
#define __CRT_LIBRARY_ID_VISUALC_V70                0x40000070
#define __CRT_LIBRARY_ID_VISUALC_V80                0x40000080
#define __CRT_LIBRARY_ID_VISUALC_V90                0x40000090

///////////////////////////////////////////////////////////////////////////////
//Definitions

//_GCRT_itoa
//_GCRT_ultoa
//_GCRT_strcmpi
//_GCRT_getch

//Security versions ------------------------------------------------------

//_GCRT_itoa_s
//_GCRT_ltoa_s
//_GCRT_ultoa_s
//_GCRT_i64toa_s
//_GCRT_ui64toa_s

//_GCRT_itow_s
//_GCRT_ltow_s
//_GCRT_ultow_s
//_GCRT_i64tow_s
//_GCRT_ui64tow_s

//_GCRT_itot_s
//_GCRT_ltot_s
//_GCRT_ultot_s
//_GCRT_i64tot_s
//_GCRT_ui64tot_s

//_GCRT_strcpy_s
//_GCRT_wcscpy_s

//_GCRT_sXprintf_s_n1 (buffer,buffer_size,format,a1)
//_GCRT_sXprintf_s_n2 (buffer,buffer_size,format,a1,a2)
//_GCRT_sXprintf_s_n3 (buffer,buffer_size,format,a1,a2,a3)
//_GCRT_sXprintf_s_n4 (buffer,buffer_size,format,a1,a2,a3,a4)
//_GCRT_sXprintf_s_n5 (buffer,buffer_size,format,a1,a2,a3,a4,a5)
//_GCRT_sXprintf_s_n6 (buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)
//_GCRT_sXprintf_s_n7 (buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)

//_GCRT_localtime_s

//Assert implementation --------------------------------------------------

//_GCRT_run_assert (expr, message)

///////////////////////////////////////////////////////////////////////////////
//Detect CRT Library ID

#if !defined(__CRT_LIBRARY_ID)

# if !defined(__COMP_ID_CURRENT)
#  error "Unknown compiler"
# endif

# if    (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER3)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_CBUILDER3
# elif  (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER4)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_CBUILDER4
# elif  (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER5)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_CBUILDER5
# elif  (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER6)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_CBUILDER6
# elif  (__COMP_ID_CURRENT==__COMP_ID_BORLAND_CBUILDER7)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_CBUILDER7
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V60)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V60
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V70)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V70
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V80)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V80
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V90)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V90
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V100)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V90
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V110)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V90
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V120)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V90
# elif  (__COMP_ID_CURRENT==__COMP_ID_VISUALC_V140)
#  define __CRT_LIBRARY_ID                              __CRT_LIBRARY_ID_VISUALC_V90
# else
#  error "Can't detect CRT ID. Unknown complier."
# endif

#endif //__CRT_LIBRARY_ID

///////////////////////////////////////////////////////////////////////////////
//Config for current CRT

#if    (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_CBUILDER3)
# error BCB3 longer not supported
#elif  (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_CBUILDER5)
# include <config/crt/config_crt__bcb5.h>
#elif  (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_CBUILDER6)
# include <config/crt/config_crt__bcb6.h>
#elif  (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_CBUILDER7)
# include <config/crt/config_crt__bcb7.h>
#elif  (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_VISUALC_V60)
# include <config/crt/config_crt__vc6.h>
#elif  (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_VISUALC_V70)
# include <config/crt/config_crt__vc7.h>
#elif  (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_VISUALC_V80)
# include <config/crt/config_crt__vc8.h>
#elif  (__CRT_LIBRARY_ID==__CRT_LIBRARY_ID_VISUALC_V90)
# include <config/crt/config_crt__vc9.h>
#else
# error "Unknown CRT Library ID"
#endif

///////////////////////////////////////////////////////////////////////////////
#endif