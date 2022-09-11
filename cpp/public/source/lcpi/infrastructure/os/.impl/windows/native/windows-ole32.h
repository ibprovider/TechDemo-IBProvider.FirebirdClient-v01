////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. Windows. OLE Automation
//                                                 Kovalenko Dmitry. 06.09.2022.
#ifndef _lcpi_infrastructure_os_impl_windows_native__windows_ole32_H_
#define _lcpi_infrastructure_os_impl_windows_native__windows_ole32_H_

#include <windows.h>
#include <ObjBase.h>

////////////////////////////////////////////////////////////////////////////////

#define LCPI_OS__CLSIDFromProgID \
 ::CLSIDFromProgID

#define LCPI_OS__CLSIDFromString \
 ::CLSIDFromString

#define LCPI_OS__CoCreateFreeThreadedMarshaler \
 ::CoCreateFreeThreadedMarshaler

#define LCPI_OS__CoCreateInstance \
 ::CoCreateInstance

#define LCPI_OS__CoGetClassObject \
 ::CoGetClassObject

#define LCPI_OS__CoInitialize \
 ::CoInitialize

#define LCPI_OS__CoInitializeEx \
 ::CoInitializeEx

#define LCPI_OS__CoMarshalInterface \
 ::CoMarshalInterface

#define LCPI_OS__CoReleaseMarshalData \
 ::CoReleaseMarshalData

#define LCPI_OS__CoTaskMemAlloc \
 ::CoTaskMemAlloc

#define LCPI_OS__CoTaskMemFree \
 ::CoTaskMemFree

#define LCPI_OS__CoUninitialize \
 ::CoUninitialize

#define LCPI_OS__CoUnmarshalInterface \
 ::CoUnmarshalInterface

#define LCPI_OS__CreateStreamOnHGlobal \
 ::CreateStreamOnHGlobal

#define LCPI_OS__OleInitialize \
 ::OleInitialize

#define LCPI_OS__OleUninitialize \
 ::OleUninitialize

#define LCPI_OS__StringFromGUID2 \
 ::StringFromGUID2

#define LCPI_OS__ProgIDFromCLSID \
 ::ProgIDFromCLSID

#define LCPI_OS__GetClassFile \
 ::GetClassFile

////////////////////////////////////////////////////////////////////////////////
#endif
