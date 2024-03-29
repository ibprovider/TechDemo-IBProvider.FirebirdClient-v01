////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Atomic functions.
//                                                 Kovalenko Dmitry. 15.03.2024.
#include <_pch_.h>
//#pragma hdrstop

#include <lcpi/infrastructure/os/lcpi.infrastructure.os-atomic_functions.h>
#include <cassert>

namespace lcpi{namespace infrastructure{namespace os{
////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedIncrement32(std::uint32_t volatile* pValue)
{
 return __sync_add_and_fetch(pValue,1);
}//LCPI_OS__InterlockedIncrement32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedIncrement64(std::uint64_t volatile* pValue)
{
 return __sync_add_and_fetch(pValue,1);
}//LCPI_OS__InterlockedIncrement64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedDecrement32(std::uint32_t volatile* pValue)
{
 return __sync_sub_and_fetch(pValue,1);
}//LCPI_OS__InterlockedDecrement32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedDecrement64(std::uint64_t volatile* pValue)
{
 return __sync_sub_and_fetch(pValue,1);
}//LCPI_OS__InterlockedDecrement64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedExchange32
                        (std::uint32_t volatile* pValue,
                         std::uint32_t           NewValue)
{
 return __sync_lock_test_and_set(pValue,NewValue);
}//LCPI_OS__InterlockedExchange32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedExchange64
                        (std::uint64_t volatile* pValue,
                         std::uint64_t           NewValue)
{
 return __sync_lock_test_and_set(pValue,NewValue);
}//LCPI_OS__InterlockedExchange64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedCompareExchange32
                        (std::uint32_t volatile* pValue,
                         std::uint32_t           NewValue,
                         std::uint32_t           Comperand)
{
 return __sync_val_compare_and_swap(pValue,Comperand,NewValue);
}//LCPI_OS__InterlockedCompareExchange32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedCompareExchange64
                        (std::uint64_t volatile* pValue,
                         std::uint64_t           NewValue,
                         std::uint64_t           Comperand)
{
 return __sync_val_compare_and_swap(pValue,Comperand,NewValue);
}//LCPI_OS__InterlockedCompareExchange64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedExchangeAdd32
                        (std::uint32_t volatile* pAddend,
                         std::uint32_t           Value)
{
 return __sync_fetch_and_add(pAddend,Value);
}//LCPI_OS__InterlockedExchangeAdd32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedExchangeAdd64
                        (std::uint64_t volatile* pAddend,
                         std::uint64_t           Value)
{
 return __sync_fetch_and_add(pAddend,Value);
}//LCPI_OS__InterlockedExchangeAdd64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedAdd32
                        (std::uint32_t volatile* pAddend,
                         std::uint32_t           Value)
{
 return __sync_add_and_fetch(pAddend,Value);
}//LCPI_OS__InterlockedExchangeAdd32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedAdd64
                        (std::uint64_t volatile* pAddend,
                         std::uint64_t           Value)
{
 return __sync_add_and_fetch(pAddend,Value);
}//LCPI_OS__InterlockedExchangeAdd64

////////////////////////////////////////////////////////////////////////////////
#ifndef NDEBUG
#include <lcpi/infrastructure/os/.tests/lcpi.infrastructure.os-atomic_functions-debug_tests.cxx>
#endif
////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
