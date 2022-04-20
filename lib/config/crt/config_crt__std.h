///////////////////////////////////////////////////////////////////////////////
//CRT Standart Configuration for many compilers
//                                               Dmitry Kovalenko. 26.05.2006.
#ifndef _config_crt__std_H_
#define _config_crt__std_H_

///////////////////////////////////////////////////////////////////////////////

#define _GCRT_itoa                        itoa
#define _GCRT_ultoa                       ultoa

#define _GCRT_strcmpi                     strcmpi

#define _GCRT_getch                       getch
#define _GCRT_kbhit                       kbhit

///////////////////////////////////////////////////////////////////////////////
//Secure version

#define _GCRT_itoa_s(value,s,n,radix)     (    itoa(value,s,(n,radix)),0L)
#define _GCRT_ltoa_s(value,s,n,radix)     (   _ltoa(value,s,(n,radix)),0L)
#define _GCRT_ultoa_s(value,s,n,radix)    (   ultoa(value,s,(n,radix)),0L)
#define _GCRT_i64toa_s(value,s,n,radix)   ( _i64toa(value,s,(n,radix)),0L)
#define _GCRT_ui64toa_s(value,s,n,radix)  (_ui64toa(value,s,(n,radix)),0L)

#define _GCRT_itow_s(value,s,n,radix)     (   _itow(value,s,(n,radix)),0L)
#define _GCRT_ltow_s(value,s,n,radix)     (   _ltow(value,s,(n,radix)),0L)
#define _GCRT_ultow_s(value,s,n,radix)    (  _ultow(value,s,(n,radix)),0L)
#define _GCRT_i64tow_s(value,s,n,radix)   ( _i64tow(value,s,(n,radix)),0L)
#define _GCRT_ui64tow_s(value,s,n,radix)  (_ui64tow(value,s,(n,radix)),0L)

#define _GCRT_itot_s(value,s,n,radix)     (   _itot(value,s,(n,radix)),0L)
#define _GCRT_ltot_s(value,s,n,radix)     (   _ltot(value,s,(n,radix)),0L)
#define _GCRT_ultot_s(value,s,n,radix)    (  _ultot(value,s,(n,radix)),0L)
#define _GCRT_i64tot_s(value,s,n,radix)   ( _i64tot(value,s,(n,radix)),0L)
#define _GCRT_ui64tot_s(value,s,n,radix)  (_ui64tot(value,s,(n,radix)),0L)

#define _GCRT_strcpy_s(dest,dest_size,src)   (strcpy(dest,(dest_size,src)),0L)
#define _GCRT_wcscpy_s(dest,dest_size,src)   (wcscpy(dest,(dest_size,src)),0L)

#define _GCRT_memcpy_s(dest,dest_size,src,src_size) (memcpy(dest,src,src_size),0L)

///////////////////////////////////////////////////////////////////////////////
//Secure version of sprintf

#define _GCRT_sprintf_s_n1(buffer,buffer_size,format,a1)                       \
  sprintf(buffer,(buffer_size,format),a1)

#define _GCRT_sprintf_s_n2(buffer,buffer_size,format,a1,a2)                    \
  sprintf(buffer,(buffer_size,format),a1,a2)

#define _GCRT_sprintf_s_n3(buffer,buffer_size,format,a1,a2,a3)                 \
  sprintf(buffer,(buffer_size,format),a1,a2,a3)

#define _GCRT_sprintf_s_n4(buffer,buffer_size,format,a1,a2,a3,a4)              \
  sprintf(buffer,(buffer_size,format),a1,a2,a3,a4)

#define _GCRT_sprintf_s_n5(buffer,buffer_size,format,a1,a2,a3,a4,a5)           \
  sprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5)

#define _GCRT_sprintf_s_n6(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)        \
  sprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6)

#define _GCRT_sprintf_s_n7(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)     \
  sprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6,a7)

#define _GCRT_sprintf_s_n8(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7,a8)  \
  sprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6,a7,a8)

///////////////////////////////////////////////////////////////////////////////
//Secure version of swprintf

#define _GCRT_swprintf_s_n1(buffer,buffer_size,format,a1)                      \
  swprintf(buffer,(buffer_size,format),a1)

#define _GCRT_swprintf_s_n2(buffer,buffer_size,format,a1,a2)                   \
  swprintf(buffer,(buffer_size,format),a1,a2)

#define _GCRT_swprintf_s_n3(buffer,buffer_size,format,a1,a2,a3)                \
  swprintf(buffer,(buffer_size,format),a1,a2,a3)

#define _GCRT_swprintf_s_n4(buffer,buffer_size,format,a1,a2,a3,a4)             \
  swprintf(buffer,(buffer_size,format),a1,a2,a3,a4)

#define _GCRT_swprintf_s_n5(buffer,buffer_size,format,a1,a2,a3,a4,a5)          \
  swprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5)

#define _GCRT_swprintf_s_n6(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)       \
  swprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6)

#define _GCRT_swprintf_s_n7(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)    \
  swprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6,a7)

#define _GCRT_swprintf_s_n8(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7,a8) \
  swprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6,a7,a8)

///////////////////////////////////////////////////////////////////////////////
//Secure version of stprintf

#define _GCRT_stprintf_s_n1(buffer,buffer_size,format,a1)                      \
  _stprintf(buffer,(buffer_size,format),a1)

#define _GCRT_stprintf_s_n2(buffer,buffer_size,format,a1,a2)                   \
  _stprintf(buffer,(buffer_size,format),a1,a2)

#define _GCRT_stprintf_s_n3(buffer,buffer_size,format,a1,a2,a3)                \
  _stprintf(buffer,(buffer_size,format),a1,a2,a3)

#define _GCRT_stprintf_s_n4(buffer,buffer_size,format,a1,a2,a3,a4)             \
  _stprintf(buffer,(buffer_size,format),a1,a2,a3,a4)

#define _GCRT_stprintf_s_n5(buffer,buffer_size,format,a1,a2,a3,a4,a5)          \
  _stprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5)

#define _GCRT_stprintf_s_n6(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6)       \
  _stprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6)

#define _GCRT_stprintf_s_n7(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7)    \
  _stprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6,a7)

#define _GCRT_stprintf_s_n8(buffer,buffer_size,format,a1,a2,a3,a4,a5,a6,a7,a8) \
  _stprintf(buffer,(buffer_size,format),a1,a2,a3,a4,a5,a6,a7,a8)

///////////////////////////////////////////////////////////////////////////////
//Secure version of localtime

#define _GCRT_localtime_s(_tm,time)       ((*(_tm)=*localtime((time))),0L)

///////////////////////////////////////////////////////////////////////////////
#endif