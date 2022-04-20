////////////////////////////////////////////////////////////////////////////////
//OLEDB Internal Interfaces. Interface for OLEDB Errors Collection
//                                                 Kovalenko Dmitry. 26.01.2009
#ifndef _oledb_ex__db_primary_error_H_
#define _oledb_ex__db_primary_error_H_

#include <unknwn.h>

////////////////////////////////////////////////////////////////////////////////
//struct IDBPrimaryError

//6A0D3941-C846-11D2-A99A-00600852F914 [defined in oledb_guids.cpp]
EXTERN_C const IID IID_IDBPrimaryError;

struct IDBPrimaryError:IUnknown
{
 virtual HRESULT __stdcall SetPrimaryError(ULONG  PrimaryErrorIndex)=0;

 virtual HRESULT __stdcall GetPrimaryError(ULONG* pPrimaryErrorIndex)=0;
};//struct IDBPrimaryError

////////////////////////////////////////////////////////////////////////////////
#endif
