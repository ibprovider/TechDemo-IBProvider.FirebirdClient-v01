////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__sql_error_info.cpp
//! \brief   Компонента с интерфейсом ISQLErrorInfo
//! \author  Kovalenko Dmitry
//! \date    09.04.2010
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__sql_error_info.h"

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__SQLErrorInfo

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__SQLErrorInfo)

//------------------------------------------------------------------------
IBP_OLEDB__SQLErrorInfo::IBP_OLEDB__SQLErrorInfo
                                           (IUnknown*    const pUnkOuter,
                                            str_arg_type const strSQLState,
                                            LONG         const lNativeError)
 :inherited     (pUnkOuter)
 ,m_strSQLState (strSQLState.str())
 ,m_lNativeError(lNativeError)
{
 OLE_LIB__CREATE_COMPONENT()
}//IBP_OLEDB__SQLErrorInfo

//------------------------------------------------------------------------
IBP_OLEDB__SQLErrorInfo::~IBP_OLEDB__SQLErrorInfo()
{
 OLE_LIB__DESTROY_COMPONENT()
}//~IBP_OLEDB__SQLErrorInfo

//------------------------------------------------------------------------
ole_lib::IPtr2<ibprovider::IBP_IClone>
 IBP_OLEDB__SQLErrorInfo::Create(str_arg_type const strSQLState,
                                 LONG         const lNativeError)
{
 const ole_lib::IPtr2<self_type>
  spX
   (structure::not_null_ptr
     (new self_type
       (/*pUnkOuter*/nullptr,
        strSQLState,
        lNativeError)));

 assert(spX);

 const HRESULT hr=spX->Init();

 if(FAILED(hr))
  ole_lib::t_base_com_error::throw_error(hr);

 assert(hr==S_OK);

 return structure::not_null_ptr(spX.ptr());
}//Create

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__SQLErrorInfo)
 OLE_LIB__ROOT_STATIC_INTERFACE_NS(ibprovider::,IBP_IClone)
 OLE_LIB__ROOT_STATIC_INTERFACE(ISQLErrorInfo)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IBP_IClone interface ---------------------------------------------------
HRESULT __stdcall IBP_OLEDB__SQLErrorInfo::Clone(IUnknown*  const pUnkOuter,
                                                 IUnknown** const ppClone)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 //-----------------------------------------
 if(ppClone==nullptr)
  return E_INVALIDARG;

 //-----------------------------------------
 (*ppClone)=nullptr;

 //-----------------------------------------
 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  if(pUnkOuter==nullptr)
  {
   //возвращаем указатель на самого себя

   ole_lib::CopyComInterface2(this->GetOuterUnknown(),*ppClone);
  }
  else
  {
   //создаем агрегированный объект

   const ole_lib::INondelegatingPtr2<self_type>
    spX
     (structure::not_null_ptr
       (new self_type
         (pUnkOuter,
          m_strSQLState,
          m_lNativeError)));

   assert(spX);

   const HRESULT init_hr=spX->Init();

   if(FAILED(init_hr))
    ole_lib::t_base_com_error::throw_error(hr);

   assert(init_hr==S_OK);

   hr=spX.get_out(IID_IUnknown,ppClone);

   assert(hr==S_OK);
  }//else
 }
 _OLE_CATCHES2_CODE_

 return hr;
}//Clone

//ISQLErrorInfo interface ------------------------------------------------
HRESULT __stdcall IBP_OLEDB__SQLErrorInfo::GetSQLInfo
                                           (BSTR* const pbstrSQLState,
                                            LONG* const plNativeError)
{
 OLE_LIB_IMETHOD_PROLOG

 ::SetErrorInfo(0,nullptr);

 if(pbstrSQLState!=nullptr)
  (*pbstrSQLState)=nullptr;

 if(plNativeError!=nullptr)
  (*plNativeError)=0;

 if(pbstrSQLState==nullptr || plNativeError==nullptr)
  return E_INVALIDARG;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  ole_lib::TBSTR bstrSQLState(m_strSQLState); //throw

  //----
  (*pbstrSQLState)=bstrSQLState.Release();

  (*plNativeError)=m_lNativeError;
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetSQLInfo

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
