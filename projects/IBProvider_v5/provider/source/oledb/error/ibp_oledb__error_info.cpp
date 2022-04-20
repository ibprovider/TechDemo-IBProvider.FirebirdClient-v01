////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_info.cpp
//! \brief   Реализация интерфейса IErrorInfo для получения сведений об ошибке
//! \author  Kovalenko Dmitry
//! \date    19.10.2008 00:05
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__error_info.h"

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorInfo

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorInfo)

//------------------------------------------------------------------------
IBP_OLEDB__ErrorInfo::IBP_OLEDB__ErrorInfo(IUnknown* const pUnkOuter)
 :inherited(pUnkOuter)
 ,m_guid(GUID_NULL)
 ,m_dwHelpContext(0)
{
 OLE_LIB__CREATE_COMPONENT();
}//IBP_OLEDB__ErrorInfo

//------------------------------------------------------------------------
IBP_OLEDB__ErrorInfo::~IBP_OLEDB__ErrorInfo()
{
 OLE_LIB__DESTROY_COMPONENT()
}//~IBP_OLEDB__ErrorInfo

//------------------------------------------------------------------------
IBP_OLEDB__ErrorInfo::self_ptr
 IBP_OLEDB__ErrorInfo::CreateInstance(IUnknown* const pUnkOuter)
{
 return structure::not_null_ptr(new self_type(pUnkOuter));
}//CreateInstance

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__ErrorInfo)
 OLE_LIB__ROOT_STATIC_INTERFACE(IErrorInfo)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IErrorInfo interface ---------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorInfo::GetSource(BSTR* const pbstrSource)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pbstrSource==nullptr)
  return E_INVALIDARG;

 (*pbstrSource)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  (*pbstrSource)=ole_lib::WStrToBStr(m_wstrSource,/*create_empty*/true); //throw
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetSource

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorInfo::GetDescription(BSTR* const pbstrDescription)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pbstrDescription==nullptr)
  return E_INVALIDARG;

 (*pbstrDescription)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  (*pbstrDescription)=ole_lib::WStrToBStr(m_wstrDescription,/*create empty*/true); //throw
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetDescription

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorInfo::GetGUID(GUID* const pguid)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pguid==nullptr)
  return E_INVALIDARG;

 (*pguid)=GUID_NULL;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  (*pguid)=m_guid;
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetGUID

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorInfo::GetHelpContext(DWORD* const pdwHelpContext)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pdwHelpContext==nullptr)
  return E_INVALIDARG;

 (*pdwHelpContext)=0;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  (*pdwHelpContext)=m_dwHelpContext;
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetHelpContext

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorInfo::GetHelpFile(BSTR* const pbstrHelpFile)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pbstrHelpFile==nullptr)
  return E_INVALIDARG;

 (*pbstrHelpFile)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  (*pbstrHelpFile)=ole_lib::WStrToBStr(m_wstrHelpFile,/*create empty*/true); //throw
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetHelpFile

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
