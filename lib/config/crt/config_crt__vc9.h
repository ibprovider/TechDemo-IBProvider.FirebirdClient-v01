///////////////////////////////////////////////////////////////////////////////
//CRT Configuration for VC9
//                                               Dmitry Kovalenko. 30.09.2009
#ifndef _config_crt__vc9_H_
#define _config_crt__vc9_H_

///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdio>
#include <locale.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////

#define _GCRT_itoa                        _itoa
#define _GCRT_ultoa                       _ultoa

#define _GCRT_strcmpi                     _strcmpi

#define _GCRT_getch                       _getch
#define _GCRT_kbhit                       _kbhit

///////////////////////////////////////////////////////////////////////////////
//Secure versions

#define _GCRT_itoa_s                      _itoa_s
#define _GCRT_ltoa_s                      _ltoa_s
#define _GCRT_ultoa_s                     _ultoa_s
#define _GCRT_i64toa_s                    _i64toa_s
#define _GCRT_ui64toa_s                   _ui64toa_s

#define _GCRT_itow_s                      _itow_s
#define _GCRT_ltow_s                      _ltow_s
#define _GCRT_ultow_s                     _ultow_s
#define _GCRT_i64tow_s                    _i64tow_s
#define _GCRT_ui64tow_s                   _ui64tow_s

#define _GCRT_itot_s                      _itot_s
#define _GCRT_ltot_s                      _ltot_s
#define _GCRT_ultot_s                     _ultot_s
#define _GCRT_i64tot_s                    _i64tot_s
#define _GCRT_ui64tot_s                   _ui64tot_s

#define _GCRT_strcpy_s                    strcpy_s
#define _GCRT_wcscpy_s                    wcscpy_s

#define _GCRT_stricmp                     _stricmp
#define _GCRT_wcsicmp                     _wcsicmp

#define _GCRT_memcpy_s                    memcpy_s

///////////////////////////////////////////////////////////////////////////////
//Secure version of sprintf

#define _GCRT_sprintf_s_n1(buffer,buffer_size,format,a1)                    \
  sprintf_s(buffer,buffer_size,format,a1)

#define _GCRT_sprintf_s_n2(buffer,buffer_size,format,a1,a2)                 \
  sprintf_s(buffer,buffer_size,format,a1,a2)

#define _GCRT_sprintf_s_n3(buffer,buffer_size,format,a1,a2,a3)              \
  sprintf_s(buffer,buffer_size,format,a1,a2,a3)

#define _GCRT_sprintf_s_n4(buffer,buffer_size,format,a1,a2,a3,a4)           \
  sprintf_s(buffer,buffer_size,format,a1,a2,a3,a4)

#define _GCRT_sprintf_s_n5(buffer,buffer_size,format,a1,a2,a3,a4,a5)        \
  sprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5)

#define _GCRT_sprintf_s_n6(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)     \
  sprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)

#define _GCRT_sprintf_s_n7(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)  \
  sprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)

///////////////////////////////////////////////////////////////////////////////
//Secure version of swprintf

#define _GCRT_swprintf_s_n1(buffer,buffer_size,format,a1)                      \
  swprintf_s(buffer,buffer_size,format,a1)

#define _GCRT_swprintf_s_n2(buffer,buffer_size,format,a1,a2)                   \
  swprintf_s(buffer,buffer_size,format,a1,a2)

#define _GCRT_swprintf_s_n3(buffer,buffer_size,format,a1,a2,a3)                \
  swprintf_s(buffer,buffer_size,format,a1,a2,a3)

#define _GCRT_swprintf_s_n4(buffer,buffer_size,format,a1,a2,a3,a4)             \
  swprintf_s(buffer,buffer_size,format,a1,a2,a3,a4)

#define _GCRT_swprintf_s_n5(buffer,buffer_size,format,a1,a2,a3,a4,a5)          \
  swprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5)

#define _GCRT_swprintf_s_n6(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)       \
  swprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)

#define _GCRT_swprintf_s_n7(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)    \
  swprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)

#define _GCRT_swprintf_s_n8(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7,a8) \
  swprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7,a8)

///////////////////////////////////////////////////////////////////////////////
//Secure version of stprintf

#define _GCRT_stprintf_s_n1(buffer,buffer_size,format,a1)                   \
  _stprintf_s(buffer,buffer_size,format,a1)

#define _GCRT_stprintf_s_n2(buffer,buffer_size,format,a1,a2)                \
  _stprintf_s(buffer,buffer_size,format,a1,a2)

#define _GCRT_stprintf_s_n3(buffer,buffer_size,format,a1,a2,a3)             \
  _stprintf_s(buffer,buffer_size,format,a1,a2,a3)

#define _GCRT_stprintf_s_n4(buffer,buffer_size,format,a1,a2,a3,a4)          \
  _stprintf_s(buffer,buffer_size,format,a1,a2,a3,a4)

#define _GCRT_stprintf_s_n5(buffer,buffer_size,format,a1,a2,a3,a4,a5)       \
  _stprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5)

#define _GCRT_stprintf_s_n6(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)    \
  _stprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)

#define _GCRT_stprintf_s_n7(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7) \
  _stprintf_s(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)

///////////////////////////////////////////////////////////////////////////////
//Secure version of localtime

#define _GCRT_localtime_s                 localtime_s

///////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG
static void _GCRT_run_assert__impl(const wchar_t* const expr,
                                   const char*          message,
                                   const wchar_t* const file,
                                   unsigned       const line)
{
 wchar_t  wm[512];

 size_t   wm_c=0;

 if(!message)
  message="";

 size_t message_c=strlen(message);

 if(message_c>(_DIM_(wm)-1))
  message_c=(_DIM_(wm)-1);

 setlocale(LC_CTYPE,"");

 if(mbstowcs_s(&wm_c,&wm[0],_DIM_(wm),message,message_c)==0)
 {
  wm[_DIM_(wm)-1]=0;

  _wassert(wm,file,line);
 }//if

 _wassert(expr,file,line);
}//_GCRT_run_assert__impl

#endif

#define _GCRT_run_assert(expr,message)                                  \
{                                                                       \
 _GCRT_run_assert__impl(_CRT_WIDE(#expr),                               \
                        message,                                        \
                        _CRT_WIDE(__FILE__),                            \
                        __LINE__);                                      \
}

///////////////////////////////////////////////////////////////////////////////
#endif
