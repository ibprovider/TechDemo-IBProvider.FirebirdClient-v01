////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_text__for_win32_error_msg.cpp
//! \brief   Реализация интерфейса IBP_IText для формирование сообщения WIN32-ошибки.
//! \author  Kovalenko Dmitry
//! \date    17.03.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__error_text__for_win32_error_msg.h"

#include "source/error_services/ibp_error_build_message.h"

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////

ole_lib::IUnknownPtr IBP_CreateErrorText_ForWin32ErrorMsg(DWORD const errorCode)
{
 return IBP_OLEDB__ErrorText__ForWin32ErrorMsg::Create(errorCode);
}//IBP_CreateErrorText_ForWin32ErrorMsg

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorText__ForWin32ErrorMsg

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorText__ForWin32ErrorMsg)

//------------------------------------------------------------------------
IBP_OLEDB__ErrorText__ForWin32ErrorMsg::IBP_OLEDB__ErrorText__ForWin32ErrorMsg(DWORD const errorCode)
 :inherited(nullptr)
 ,m_errorCode(errorCode)
{
 OLE_LIB__CREATE_COMPONENT();
}//IBP_OLEDB__ErrorText__ForWin32ErrorMsg

//------------------------------------------------------------------------
IBP_OLEDB__ErrorText__ForWin32ErrorMsg::~IBP_OLEDB__ErrorText__ForWin32ErrorMsg()
{
 OLE_LIB__DESTROY_COMPONENT();
}//~IBP_OLEDB__ErrorText__ForWin32ErrorMsg

//------------------------------------------------------------------------
ole_lib::IUnknownPtr IBP_OLEDB__ErrorText__ForWin32ErrorMsg::Create(DWORD const errorCode)
{
 const ole_lib::IPtr2<self_type>
  spThis(structure::not_null_ptr(new self_type(errorCode)));

 assert(spThis);

 const HRESULT hr=spThis->Init();

 if(FAILED(hr))
  ole_lib::t_base_com_error::throw_error(hr);

 assert(hr==S_OK);

 return spThis.ptr();
}//Create

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__ErrorText__ForWin32ErrorMsg)
 OLE_LIB__ROOT_STATIC_INTERFACE_NS(ibprovider::,IBP_IText)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IBP_IText interface ----------------------------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorText__ForWin32ErrorMsg::GetText
                                           (LCID  const lcid,
                                            BSTR* const pbstrText)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 if(pbstrText==nullptr)
  return E_INVALIDARG;

 (*pbstrText)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const std::wstring
   wstr(TIBP_MessageTextBuilder::GetSystemErrorMsg
         (lcid,
          m_errorCode));

  (*pbstrText)=ole_lib::WStrToBStr(wstr); //throw
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetText

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
