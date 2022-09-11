////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_text.cpp
//! \brief   Реализация интерфейса IBP_IText для err-сообщения без параметров
//! \author  Kovalenko Dmitry
//! \date    01.02.2011
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__error_text.h"

#include "source/error_services/ibp_error_build_message.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////

ole_lib::IUnknownPtr IBP_CreateErrorText(ibp_msg_code_type const mce_code_0)
{
 return IBP_OLEDB__ErrorText::Create(mce_code_0);
}//IBP_CreateErrorText

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorText

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorText)

//------------------------------------------------------------------------
IBP_OLEDB__ErrorText::IBP_OLEDB__ErrorText(mce_code_type const mce_code_0)
 :inherited(nullptr)
 ,m_mce_code_0(mce_code_0)
{
 OLE_LIB__CREATE_COMPONENT();
}//IBP_OLEDB__ErrorText

//------------------------------------------------------------------------
IBP_OLEDB__ErrorText::~IBP_OLEDB__ErrorText()
{
 OLE_LIB__DESTROY_COMPONENT();
}//~IBP_OLEDB__ErrorText

//------------------------------------------------------------------------
ole_lib::IUnknownPtr IBP_OLEDB__ErrorText::Create(mce_code_type const mce_code_0)
{
 const ole_lib::IPtr2<self_type>
  spThis(structure::not_null_ptr(new self_type(mce_code_0)));

 assert(spThis);

 const HRESULT hr=spThis->Init();

 if(FAILED(hr))
  ole_lib::t_base_com_error::throw_error(hr);

 assert(hr==S_OK);

 return spThis.ptr();
}//Create

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__ErrorText)
 OLE_LIB__ROOT_STATIC_INTERFACE_NS(ibprovider::,IBP_IText)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IBP_IText interface ----------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorText::GetText(LCID  const lcid,
                                                BSTR* const pbstrText)
{
 OLE_LIB_IMETHOD_PROLOG

 LCPI_OS__SetErrorInfo(0,nullptr);

 if(pbstrText==nullptr)
  return E_INVALIDARG;

 (*pbstrText)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  std::wstring wstr;

  if(!TIBP_MessageTextBuilder::Build(&wstr,
                                     ole_lib::TVariant::empty_variant,
                                     m_mce_code_0,
                                     lcid,
                                     0,
                                     reinterpret_cast<const oledb_lib::DBVARIANT*>(NULL),
                                     E_FAIL))
  {
   hr=DB_E_BADLOOKUPID;
  }
  else
  {
   (*pbstrText)=ole_lib::WStrToBStr(wstr); //throw
  }//else
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetText

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
