////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Critical Section.
//                                                 Kovalenko Dmitry. 18.03.2024.
#ifndef _lcpi_infrastructure_os__critical_section_H_
#define _lcpi_infrastructure_os__critical_section_H_

#if _WIN32
# include <lcpi/infrastructure/os/.impl/windows/lcpi.infrastructure.os-critical_section.h>
#else
# include <lcpi/infrastructure/os/.impl/generic/lcpi.infrastructure.os-critical_section.h>
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#endif