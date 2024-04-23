////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Thread API.
//                                                 Kovalenko Dmitry. 15.03.2024.
#ifndef _lcpi_infrastructure_os_mt__thread_api_H_
#define _lcpi_infrastructure_os_mt__thread_api_H_

#ifdef _WIN32
# include <lcpi/infrastructure/os/.impl/windows/lcpi.infrastructure.os.mt-thread_api.h>
#elif defined(__linux__)
# include <lcpi/infrastructure/os/.impl/linux/lcpi.infrastructure.os.mt-thread_api.h>
#else
# error It is an unexpected platform.
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif
