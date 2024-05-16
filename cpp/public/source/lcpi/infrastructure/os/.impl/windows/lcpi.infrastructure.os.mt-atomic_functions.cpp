////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Atomic functions.
//                                                 Kovalenko Dmitry. 15.03.2024.
#include <_pch_.h>
//#pragma hdrstop

#include <lcpi/infrastructure/os/lcpi.infrastructure.os.mt-atomic_functions.h>

namespace lcpi{namespace infrastructure{namespace os{namespace mt{
////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedIncrement32(std::uint32_t volatile* pValue)
{
 using api_t=ULONG32;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));

 return (std::uint32_t)::InterlockedIncrement(reinterpret_cast<api_t volatile*>(pValue));
}//LCPI_OS__InterlockedIncrement32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedIncrement64(std::uint64_t volatile* pValue)
{
 using api_t=ULONG64;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));

 return (std::uint64_t)::InterlockedIncrement(reinterpret_cast<api_t volatile*>(pValue));
}//LCPI_OS__InterlockedIncrement64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedDecrement32(std::uint32_t volatile* pValue)
{
 using api_t=ULONG32;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));

 return (std::uint32_t)::InterlockedDecrement(reinterpret_cast<api_t volatile*>(pValue));
}//LCPI_OS__InterlockedDecrement32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedDecrement64(std::uint64_t volatile* pValue)
{
 using api_t=ULONG64;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));

 return (std::uint64_t)::InterlockedDecrement(reinterpret_cast<api_t volatile*>(pValue));
}//LCPI_OS__InterlockedDecrement64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedExchange32(std::uint32_t volatile* pValue, std::uint32_t NewValue)
{
 using api_t=ULONG32;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
 LCPI__assert_s(sizeof(NewValue)==sizeof(api_t));

 return (std::uint32_t)::InterlockedExchange(reinterpret_cast<api_t volatile*>(pValue), (api_t)NewValue);
}//LCPI_OS__InterlockedExchange32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedExchange64(std::uint64_t volatile* pValue, std::uint64_t NewValue)
{
 using api_t=ULONG64;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
 LCPI__assert_s(sizeof(NewValue)==sizeof(api_t));

 return (std::uint64_t)::InterlockedExchange(reinterpret_cast<api_t volatile*>(pValue), (api_t)NewValue);
}//LCPI_OS__InterlockedExchange64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedCompareExchange32
                        (std::uint32_t volatile* pValue,
                         std::uint32_t           NewValue,
                         std::uint32_t           Comperand)
{
 using api_t=ULONG32;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
 LCPI__assert_s(sizeof(NewValue)==sizeof(api_t));
 LCPI__assert_s(sizeof(Comperand)==sizeof(api_t));

 return (std::uint32_t)::InterlockedCompareExchange
                             (reinterpret_cast<api_t volatile*>(pValue),
                              (api_t)NewValue,
                              (api_t)Comperand);
}//LCPI_OS__InterlockedCompareExchange32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedCompareExchange64
                        (std::uint64_t volatile* pValue,
                         std::uint64_t           NewValue,
                         std::uint64_t           Comperand)
{
 using api_t=ULONG64;

 LCPI__assert_s(sizeof(*pValue)==sizeof(api_t));
 LCPI__assert_s(sizeof(NewValue)==sizeof(api_t));
 LCPI__assert_s(sizeof(Comperand)==sizeof(api_t));

 return (std::uint64_t)::InterlockedCompareExchange
                             (reinterpret_cast<api_t volatile*>(pValue),
                              (api_t)NewValue,
                              (api_t)Comperand);
}//LCPI_OS__InterlockedCompareExchange64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedExchangeAdd32
                        (std::uint32_t volatile* pAddend,
                         std::uint32_t           Value)
{
 return ::InterlockedExchangeAdd(pAddend,Value);
}//LCPI_OS__InterlockedExchangeAdd32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedExchangeAdd64
                        (std::uint64_t volatile* pAddend,
                         std::uint64_t           Value)
{
 return ::InterlockedExchangeAdd(pAddend,Value);
}//LCPI_OS__InterlockedExchangeAdd64

////////////////////////////////////////////////////////////////////////////////

std::uint32_t LCPI_OS__InterlockedAdd32
                        (std::uint32_t volatile* pAddend,
                         std::uint32_t           Value)
{
 return LCPI_OS__InterlockedExchangeAdd32(pAddend,Value) + Value;
}//LCPI_OS__InterlockedExchangeAdd32

//------------------------------------------------------------------------
std::uint64_t LCPI_OS__InterlockedAdd64
                        (std::uint64_t volatile* pAddend,
                         std::uint64_t           Value)
{
 return LCPI_OS__InterlockedExchangeAdd64(pAddend,Value) + Value;
}//LCPI_OS__InterlockedExchangeAdd64

////////////////////////////////////////////////////////////////////////////////
#ifndef NDEBUG
#include <lcpi/infrastructure/os/.tests/lcpi.infrastructure.os.mt-atomic_functions-debug_tests.cxx>
#endif
////////////////////////////////////////////////////////////////////////////////
}/*nms mt*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
