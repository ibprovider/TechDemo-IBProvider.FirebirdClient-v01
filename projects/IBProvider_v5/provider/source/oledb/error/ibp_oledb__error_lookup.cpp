////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_lookup.cpp
//! \brief   —ервис ошибок OLEDB провайдера
//! \author  Kovalenko Dmitry
//! \date    02.02.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__error_lookup.h"
#include "source/oledb/error/ibp_oledb__error_param_idxs.h"

#include "source/error_services/ibp_error_build_message.h"

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorLookup

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorLookup)

//------------------------------------------------------------------------
IBP_OLEDB__ErrorLookup::IBP_OLEDB__ErrorLookup(IUnknown* const pUnkOuter)
 :inherited(pUnkOuter)
{
 OLE_LIB__CREATE_COMPONENT()
}//IBP_OLEDB__ErrorLookup

//------------------------------------------------------------------------
IBP_OLEDB__ErrorLookup::~IBP_OLEDB__ErrorLookup()
{
 OLE_LIB__DESTROY_COMPONENT()
}//~IBP_OLEDB__ErrorLookup

//------------------------------------------------------------------------
HRESULT IBP_OLEDB__ErrorLookup::Create(IUnknown*                const pUnkOuter,
                                       ole_lib::TBaseUnknown2** const ppObject)
{
 return FinishCreate(new self_type(pUnkOuter),ppObject);
}//Create

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__ErrorLookup)
 OLE_LIB__ROOT_STATIC_INTERFACE(IErrorLookup)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IErrorLookup interface -------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorLookup::GetErrorDescription
                                           (HRESULT     const hrError,
                                            DWORD       const dwLookupID,
                                            DISPPARAMS* const pdispparams,
                                            LCID        const lcid,
                                            BSTR*       const pbstrSource,
                                            BSTR*       const pbstrDescription)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 if(pbstrSource!=nullptr)
  (*pbstrSource)=nullptr;

 if(pbstrDescription!=nullptr)
  (*pbstrDescription)=nullptr;

 if(pbstrSource==nullptr || pbstrDescription==nullptr)
  return E_INVALIDARG;

 if(pdispparams!=nullptr)
 {
  if(pdispparams->cArgs!=0 && pdispparams->rgvarg==nullptr)
   return E_INVALIDARG;
 }//if

 HRESULT hr=S_OK;

 _OLE_TRY_
 {
  assert(ibp_oledb_err_param_idx__subsystem_id<ibp_oledb_err_param_idx__arg0);

  //провер€ем массив с параметрами
  if(pdispparams==nullptr || pdispparams->cArgs<ibp_oledb_err_param_idx__arg0)
  {
   //ERROR - incorrect params of oledb error message

   ole_lib::t_base_com_error::throw_error(E_FAIL);
  }//if

  assert_hint(pdispparams!=nullptr);
  assert_hint(ibp_oledb_err_param_idx__arg0<=pdispparams->cArgs);

  //формируем им€ источника ошибки
  ole_lib::TBSTR bstrSource;

  {
   std::wstring source;

   if(!TIBP_MessageTextBuilder::BuildSrc(&source,
                                         pdispparams->rgvarg[ibp_oledb_err_param_idx__source_id]))
   {
    ole_lib::t_base_com_error::throw_error(E_FAIL);
   }

   bstrSource=source;
  }//local

  //формируем описание ошибки
  ole_lib::TBSTR bstrDescription;

  {
   std::wstring description;

   if(!TIBP_MessageTextBuilder::Build(&description,
                                      pdispparams->rgvarg[ibp_oledb_err_param_idx__subsystem_id],
                                      dwLookupID,
                                      lcid,
                                      pdispparams->cArgs-ibp_oledb_err_param_idx__arg0,
                                      pdispparams->rgvarg+ibp_oledb_err_param_idx__arg0,
                                      hrError))
   {
    ole_lib::t_base_com_error::throw_error(DB_E_BADLOOKUPID);
   }

   bstrDescription=description;
  }//local

  assert(pbstrSource!=nullptr);
  assert(pbstrDescription!=nullptr);

  (*pbstrSource)      =bstrSource.Release();
  (*pbstrDescription) =bstrDescription.Release();
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetErrorDescription

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorLookup::GetHelpInfo
                                           (HRESULT  const /*hrError*/,
                                            DWORD    const /*dwLookupID*/,
                                            LCID     const /*lcid*/,
                                            BSTR*    const pbstrHelpFile,
                                            DWORD*   const pdwHelpContext)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 if(pbstrHelpFile!=nullptr)
  (*pbstrHelpFile)=nullptr;

 if(pdwHelpContext!=nullptr)
  (*pdwHelpContext)=0;

 if(pbstrHelpFile==nullptr || pdwHelpContext==nullptr)
  return E_INVALIDARG;

 return S_OK;
}//GetHelpInfo

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorLookup::ReleaseErrors
                                           (const DWORD /*dwDynamicErrorID*/)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 return S_OK;
}//ReleaseErrors

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
