////////////////////////////////////////////////////////////////////////////////
//LCPI C++ Infrastructure. OS API. COM interfaces for work with Registry Storage
//                                                 Kovalenko Dmitry. 16.12.2022.
#ifndef _lcpi_infrastructure_os__lcpi_svc_registry_storage_H_
#define _lcpi_infrastructure_os__lcpi_svc_registry_storage_H_

#include <lcpi/infrastructure/os/windows-ole32.h>

namespace lcpi{namespace infrastructure{namespace os{namespace lcpi_svcs{namespace registry_storage{
////////////////////////////////////////////////////////////////////////////////
//content

struct LCPI_IRegistryStorageNames;
struct LCPI_IRegistryStorage;

////////////////////////////////////////////////////////////////////////////////
//Registry Storage Access Masks

enum LCPI_RSAccess
{
 rsaRead      =0x1,
 rsaWrite     =0x2,
 rsaReadWrite =rsaRead|rsaWrite,
 rsaAllAccess =0x4,
};//enum LCPI_RSAccess

////////////////////////////////////////////////////////////////////////////////
//Registry Storage Value Types

enum LCPI_RSVT
{
 rsvt_None           =0,

 rsvt_I4             =10,
 rsvt_I8             =11,
 rsvt_WString        =12,
 rsvt_Binary         =13,

 rsvt_UI4            =16,
 rsvt_UI8            =17,

 //
 // Windows Registry Types
 //
 rsvt_WString_Multi  =20,
 rsvt_WString_Expand =21,
};//enum LCPI_RSVT

////////////////////////////////////////////////////////////////////////////////
//interface LCPI_IRegistryStorageNames

// AC3EC6A5-7D2A-11ED-9757-80A589A03F33
extern const IID IID_LCPI_IRegistryStorageNames;

struct LCPI_IRegistryStorageNames:IUnknown
{
 virtual HRESULT __stdcall GetCount(SIZE_T* pCount)=0;

 virtual HRESULT __stdcall Restart()=0;

 /// <summary>
 ///  Fetching the name.
 /// </summary>
 /// <param name="pName">
 ///  Not null. The pointer to the pointer of returned string.
 /// </param>
 /// <returns>
 ///  - S_OK
 ///  - S_FALSE
 ///  - E_INVALIDARG
 ///  - E_OUTOFMEMORY
 /// </returns>
 ///
 ///  Use LCPI_OS__CoTaskMemFree for releasing the memory of allocated string.
 ///
 virtual HRESULT __stdcall Fetch(LPWSTR* pName)=0;

 virtual HRESULT __stdcall Rename(LPCWSTR OldName,LPCWSTR NewName)=0;

 virtual HRESULT __stdcall Refresh()=0;

 virtual HRESULT __stdcall Exists(LPCWSTR Name)=0;

 virtual HRESULT __stdcall Delete(LPCWSTR Name)=0;
};//struct LCPI_IRegistryStorageNames

////////////////////////////////////////////////////////////////////////////////
//interface LCPI_IRegistryStorage

// AC3EC6A6-7D2A-11ED-9757-80A589A03F33
extern const IID IID_LCPI_IRegistryStorage;

struct LCPI_IRegistryStorage:IUnknown
{
 virtual HRESULT __stdcall GetSubStorageNames
                             (REFIID     riid,
                              IUnknown** ppNames)=0;

 virtual HRESULT __stdcall GetValueNames
                             (REFIID     riid,
                              IUnknown** ppNames)=0;

 virtual HRESULT __stdcall Open(LPCWSTR       Path,
                                LCPI_RSAccess OpenAccess,
                                BOOL          Create,
                                REFIID        riid,
                                IUnknown**    ppStorage)=0;

 virtual HRESULT __stdcall Close()=0;

 virtual HRESULT __stdcall Clone(LCPI_RSAccess NewAccess,
                                 REFIID        riid,
                                 IUnknown**    ppStorage)=0;

 /// <summary>
 ///  Getting the parameter value.
 /// </summary>
 ///  Use LCPI_OS__CoTaskMemFree for releasing the memory of allocated data.
 virtual HRESULT __stdcall ReadValue(LPCWSTR    Name,
                                     LCPI_RSVT* pValueType,
                                     SIZE_T*    pcbValueSize,
                                     LPVOID*    ppData)=0;

 /// <summary>
 ///  Writting the parameter value.
 /// </summary>
 virtual HRESULT __stdcall WriteValue(LPCWSTR   Name,
                                      LCPI_RSVT ValueType,
                                      SIZE_T    cbValueSize,
                                      LPCVOID   pData)=0;
};//struct LCPI_IRegistryStorage

////////////////////////////////////////////////////////////////////////////////
}/*nms registry_storage*/}/*nms lcpi_svcs*/}/*nms os*/}/*nms infrastructure*/}/*nms lcpi*/
#endif
