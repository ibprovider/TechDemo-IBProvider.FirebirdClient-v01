////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error_element_wrapper.cpp
//! \brief   COM-обертка для t_ibp_error_element
//! \author  Kovalenko Dmitry
//! \date    18.02.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__error_element_wrapper.h"

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__ErrorElementWrapper

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__ErrorElementWrapper)

//------------------------------------------------------------------------
IBP_OLEDB__ErrorElementWrapper::IBP_OLEDB__ErrorElementWrapper(const err_record_type* const pErrorRecord)
 :inherited(nullptr)
 ,m_spErrorRecord(structure::not_null_ptr(pErrorRecord))
{
 assert(m_spErrorRecord);

 OLE_LIB__CREATE_COMPONENT()
}//IBP_OLEDB__ErrorElementWrapper

//------------------------------------------------------------------------
IBP_OLEDB__ErrorElementWrapper::~IBP_OLEDB__ErrorElementWrapper()
{
 OLE_LIB__DESTROY_COMPONENT()
}//~IBP_OLEDB__ErrorElementWrapper

//------------------------------------------------------------------------
ole_lib::IUnknownPtr IBP_OLEDB__ErrorElementWrapper::Create(const err_record_type* const pErrorRecord)
{
 assert(pErrorRecord);

 const ole_lib::IPtr2<self_type>
  spThis(structure::not_null_ptr(new self_type(pErrorRecord)));

 assert(spThis);

 HRESULT const hr=spThis->Init();

 if(FAILED(hr))
  ole_lib::t_base_com_error::throw_error(hr);

 assert(hr==S_OK);

 return structure::not_null_ptr(spThis.ptr());
}//Create

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__ErrorElementWrapper)
 OLE_LIB__ROOT_STATIC_INTERFACE_NS(ibprovider::,IBP_IErrorExtendedParameter)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IBP_IErrorExtendedParameter interface ----------------------------------
HRESULT __stdcall IBP_OLEDB__ErrorElementWrapper::GetErrorDescription
                                           (LCID  const lcid,
                                            BSTR* const pbstrSource,
                                            BSTR* const pbstrDescription)
{
 OLE_LIB_IMETHOD_PROLOG

 LCPI_OS__SetErrorInfo(0,nullptr);

 if(pbstrSource!=NULL)
  (*pbstrSource)=NULL;

 if(pbstrDescription!=NULL)
  (*pbstrDescription)=NULL;

 HRESULT hr=S_OK;

 _OLE_TRY_
 {
  assert(m_spErrorRecord);

  for(;;)
  {
   ole_lib::TBSTR bstrSource;
   ole_lib::TBSTR bstrDescription;

   if(pbstrSource!=NULL)
   {
    err_record_type::string_type tmpWStr;

    if(!m_spErrorRecord->get_description(lcid,/*source*/&tmpWStr,NULL))
    {
     hr=E_FAIL;
     break;
    }

    bstrSource=tmpWStr;
   }//if pbstrSource!=NULL

   if(pbstrDescription!=NULL)
   {
    err_record_type::string_type tmpWStr;

    if(!m_spErrorRecord->get_description(lcid,NULL,/*description*/&tmpWStr))
    {
     hr=E_FAIL;
     break;
    }

    bstrDescription=tmpWStr;
   }//if bstrDescription!=NULL

   if(pbstrSource!=NULL)
    (*pbstrSource)=bstrSource.Release();

   if(pbstrDescription!=NULL)
    (*pbstrDescription)=bstrDescription.Release();

   break;
  }//for[ever]
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetErrorDescription

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
