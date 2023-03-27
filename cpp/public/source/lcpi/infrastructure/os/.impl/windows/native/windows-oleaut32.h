////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Windows. OLE Automation
//                                                 Kovalenko Dmitry. 06.09.2022.
#ifndef _lcpi_infrastructure_os_impl_windows_native__windows_oleaut32_H_
#define _lcpi_infrastructure_os_impl_windows_native__windows_oleaut32_H_

#include <windows.h>
#include <OleAuto.h>

////////////////////////////////////////////////////////////////////////////////

#define LCPI_OS__VariantInit \
 ::VariantInit

#define LCPI_OS__VariantClear \
 ::VariantClear

#define LCPI_OS__VariantCopy \
 ::VariantCopy

#define LCPI_OS__VariantCopyInd \
 ::VariantCopyInd

#define LCPI_OS__VariantChangeType \
 ::VariantChangeType

#define LCPI_OS__SysAllocStringLen \
 ::SysAllocStringLen

#define LCPI_OS__SysFreeString \
 ::SysFreeString

#define LCPI_OS__SysStringLen \
 ::SysStringLen

#define LCPI_OS__SysStringByteLen \
 ::SysStringByteLen

#define LCPI_OS__SysAllocStringByteLen \
 ::SysAllocStringByteLen

#define LCPI_OS__SafeArrayCreate \
 ::SafeArrayCreate

#define LCPI_OS__SafeArrayDestroy \
 ::SafeArrayDestroy

#define LCPI_OS__SafeArrayGetDim \
 ::SafeArrayGetDim

#define LCPI_OS__SafeArrayGetElemsize \
 ::SafeArrayGetElemsize

#define LCPI_OS__SafeArrayGetLBound \
 ::SafeArrayGetLBound

#define LCPI_OS__SafeArrayGetUBound \
 ::SafeArrayGetUBound

#define LCPI_OS__SafeArrayAccessData \
 ::SafeArrayAccessData

#define LCPI_OS__SafeArrayUnaccessData \
 ::SafeArrayUnaccessData

#define LCPI_OS__SafeArrayGetElement \
 ::SafeArrayGetElement

#define LCPI_OS__SafeArrayPutElement \
 ::SafeArrayPutElement

#define LCPI_OS__SafeArrayCopy \
 ::SafeArrayCopy

#define LCPI_OS__SafeArrayAllocDescriptor \
 ::SafeArrayAllocDescriptor

#define LCPI_OS__SafeArrayAllocDescriptorEx \
 ::SafeArrayAllocDescriptorEx

#define LCPI_OS__SafeArrayDestroyDescriptor \
 ::SafeArrayDestroyDescriptor

#define LCPI_OS__SafeArrayAllocData \
 ::SafeArrayAllocData

#define LCPI_OS__SafeArrayDestroyData \
 ::SafeArrayDestroyData

#define LCPI_OS__SafeArrayGetVartype \
 ::SafeArrayGetVartype

#define LCPI_OS__SystemTimeToVariantTime \
 ::SystemTimeToVariantTime

#define LCPI_OS__VariantTimeToSystemTime \
 ::VariantTimeToSystemTime

#define LCPI_OS__SetErrorInfo \
 ::SetErrorInfo

#define LCPI_OS__GetErrorInfo \
 ::GetErrorInfo

#define LCPI_OS__CreateErrorInfo \
 ::CreateErrorInfo

////////////////////////////////////////////////////////////////////////////////
#endif
