////////////////////////////////////////////////////////////////////////////////
//Перечисление и определение платформы, под которую компилируется провайдер.
//                                                 Kovalenko Dmitry. 13.02.2016.
#ifndef _ibp_cfg_compile__platform_ids_H_
#define _ibp_cfg_compile__platform_ids_H_

////////////////////////////////////////////////////////////////////////////////
//IBProvider Platforms

#define IBP_PLATFORM_ID__WINNT_X86          1
#define IBP_PLATFORM_ID__WINNT_AMD64        2

//------------------------------------------------------------------------

#ifdef _WIN64
# define IBP_PLATFORM_ID                    IBP_PLATFORM_ID__WINNT_AMD64
# define IBP_PLATFORM_ID_SIGN_T             "winnt_amd64"
#elif _WIN32
# define IBP_PLATFORM_ID                    IBP_PLATFORM_ID__WINNT_X86
# define IBP_PLATFORM_ID_SIGN_T             "winnt_x86"
#else
# error Unknown Target Platform!
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
