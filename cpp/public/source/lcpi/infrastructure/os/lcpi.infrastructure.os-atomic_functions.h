////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Atomic functions.
//                                                 Kovalenko Dmitry. 15.03.2024.
#ifndef _lcpi_infrastructure_os__atomic_functions_H_
#define _lcpi_infrastructure_os__atomic_functions_H_

#include <lcpi/.config.h>

#include <cstdint>

namespace lcpi{namespace infrastructure{namespace os{
////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedIncrement32(std::uint32_t volatile* pValue);

std::uint64_t LCPI_OS__InterlockedIncrement64(std::uint64_t volatile* pValue);

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedDecrement32(std::uint32_t volatile* pValue);

std::uint64_t LCPI_OS__InterlockedDecrement64(std::uint64_t volatile* pValue);

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedExchange32
                        (std::uint32_t volatile* pValue,
                         std::uint32_t           NewValue);

std::uint64_t LCPI_OS__InterlockedExchange64
                        (std::uint64_t volatile* pValue,
                         std::uint64_t           NewValue);

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedCompareExchange32
                        (std::uint32_t volatile* pValue,
                         std::uint32_t           NewValue,
                         std::uint32_t           Comperand);

std::uint64_t LCPI_OS__InterlockedCompareExchange64
                        (std::uint64_t volatile* pValue,
                         std::uint64_t           NewValue,
                         std::uint64_t           Comperand);

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedExchangeAdd32
                        (std::uint32_t volatile* pAddend,
                         std::uint32_t           Value);

std::uint64_t LCPI_OS__InterlockedExchangeAdd64
                        (std::uint64_t volatile* pAddend,
                         std::uint64_t           Value);

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedAdd32
                        (std::uint32_t volatile* pAddend,
                         std::uint32_t           Value);

std::uint64_t LCPI_OS__InterlockedAdd64
                        (std::uint64_t volatile* pAddend,
                         std::uint64_t           Value);

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
