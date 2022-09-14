////////////////////////////////////////////////////////////////////////////////
//! \ingroup ole_lib
//! \file    ole_auto_safe_array.cpp
//! \brief   Wrappers for work with SAFEARRAY structure
//! \author  Kovalenko Dmitry
//! \date    14.12.2007
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_auto/ole_auto_safe_array.h>
#include <ole_lib/ole_auto/ole_auto_utils.h>
#include <ole_lib/ole_base.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TSafeArrayAutoUnAccessData

TSafeArrayAutoUnAccessData::TSafeArrayAutoUnAccessData(SAFEARRAY* const lpsa)
 :m_lpsa(lpsa)
{;}

//------------------------------------------------------------------------
TSafeArrayAutoUnAccessData::~TSafeArrayAutoUnAccessData()
{
 _VERIFY_EQ(this->UnAccess(),S_OK);
}//~TSafeArrayAutoUnAccessData

//------------------------------------------------------------------------
HRESULT TSafeArrayAutoUnAccessData::UnAccess()
{
 if(m_lpsa==NULL)
  return S_OK;

 const HRESULT hr=LCPI_OS__SafeArrayUnaccessData(m_lpsa);

 assert(hr==S_OK || FAILED(hr));

 if(SUCCEEDED(hr))
  m_lpsa=NULL;

 return hr;
}//UnAccess

////////////////////////////////////////////////////////////////////////////////
//class TSafeArrayAccessor

TSafeArrayAccessor::TSafeArrayAccessor(LPSAFEARRAY const lpsa,
                                       bool        const throw_error)
 :m_lpsa (NULL)
 ,m_pData(NULL)
{
 assert(lpsa!=NULL);

 const HRESULT hr=LCPI_OS__SafeArrayAccessData(lpsa,&m_pData);

 if(FAILED(hr))
 {
  if(throw_error)
   t_base_ole_error::throw_error(hr,"TSafeArrayAccessor::TSafeArrayAccessor");
 }
 else
 {
  assert(hr==S_OK);

  m_lpsa=lpsa;
 }//else
}//TSafeArrayAccessor

//------------------------------------------------------------------------
TSafeArrayAccessor::~TSafeArrayAccessor()
{
 _VERIFY_EQ(this->ReleaseData(),S_OK);
}//~TSafeArrayAccessor

//------------------------------------------------------------------------
HRESULT TSafeArrayAccessor::ReleaseData()
{
 if(m_lpsa==NULL)
  return S_OK;

 const HRESULT hr=LCPI_OS__SafeArrayUnaccessData(m_lpsa);

 assert(hr==S_OK || FAILED(hr));

 if(SUCCEEDED(hr))
 {
  m_lpsa=NULL;
  m_pData=NULL;
 }//if

 return hr;
}//ReleaseData

////////////////////////////////////////////////////////////////////////////////
// class TBaseSafeArray

TBaseSafeArray::~TBaseSafeArray()
{
 _VERIFY_EQ(this->Destroy(),S_OK);
}//~TBaseSafeArray

//------------------------------------------------------------------------
HRESULT TBaseSafeArray::Destroy()
{
 if(m_psa==NULL)
  return S_OK;

 const HRESULT hr=ole_lib::SafeArray_Destroy(m_psa);

 assert_msg(hr==S_OK,"hr==0x"<<std::hex<<hr);

 if(SUCCEEDED(hr))
  m_psa=NULL;

 return hr;
}//Destroy

//------------------------------------------------------------------------
SAFEARRAY* TBaseSafeArray::Release()
{
 SAFEARRAY* const tmp=m_psa;

 m_psa=NULL;

 return tmp;
}//Release

//------------------------------------------------------------------------
LPSAFEARRAY& TBaseSafeArray::ref_sa(bool const destroy)
{
 if(m_psa && destroy)
 {
  HRESULT const hr=this->Destroy();

  if(FAILED(hr))
   t_base_ole_error::throw_error(hr,"TBaseSafeArray::ref_sa");
 }//if

 return m_psa;
}//ref_sa

////////////////////////////////////////////////////////////////////////////////
//class TSafeArray

UINT TSafeArray::GetDim()const
{
 if(m_psa==nullptr)
 {
  assert(false);

  throw std::runtime_error("[BUG CHECK] TSafeArray::GetDim - m_psa is null.");
 }//if

 assert(m_psa!=nullptr);

 return LCPI_OS__SafeArrayGetDim(m_psa);
}//GetDim

//------------------------------------------------------------------------
LONG TSafeArray::GetLBound(UINT const nDim)const
{
 assert(m_psa!=NULL);

 assert_msg(nDim>0 && nDim<=this->GetDim(),
              "nDim=="<<nDim<<"\n"
                                           "GetDim()=="<<this->GetDim());

 LONG lBound;

 DEBUG_CODE(const HRESULT hr=)LCPI_OS__SafeArrayGetLBound(m_psa,nDim,&lBound);

 assert_msg(hr==NOERROR,"nDim=="<<nDim<<"\nGetDim()=="<<this->GetDim());

 return lBound;
}//GetLBound

//------------------------------------------------------------------------
LONG TSafeArray::GetUBound(UINT const nDim)const
{
 assert(m_psa!=NULL);

 assert_msg(nDim>0 && nDim<=this->GetDim(),
              "nDim=="<<nDim<<"\n"
                                           "GetDim()=="<<this->GetDim());

 LONG uBound;

 DEBUG_CODE(const HRESULT hr=)LCPI_OS__SafeArrayGetUBound(m_psa,nDim,&uBound);

 assert_msg(hr==NOERROR,"nDim=="<<nDim<<"\nGetDim()=="<<this->GetDim());

 return uBound;
}//GetUBound

//------------------------------------------------------------------------
void TSafeArray::Create(VARTYPE const vt,
                        LONG    const lower,
                        ULONG   const count) //throw(bad_alloc)
{
 const TSafeArrayBound Bound(lower,count);

 this->Create(vt,1,&Bound);
}//Create

//------------------------------------------------------------------------
void TSafeArray::Create(VARTYPE               const vt,
                        UINT                  const cDim,
                        const SAFEARRAYBOUND* const rgsaBound) //throw(bad_alloc)
{
 assert(cDim>0);
 assert(rgsaBound!=NULL);
 assert(vt!=VT_EMPTY);
 assert(vt!=VT_NULL);
 assert((vt&VT_BYREF)==0);
 assert((vt&VT_ARRAY)==0);
 CHECK_READ_TYPED_PTR(rgsaBound,cDim);

 this->Destroy();

 m_psa
  =reinterpret_cast<SAFEARRAY*>
    (LCPI_OS__SafeArrayCreate
      (vt,
       cDim,
       const_cast<SAFEARRAYBOUND*>(rgsaBound)));

 if(m_psa==NULL)
  throw std::bad_alloc();
}//Create

//------------------------------------------------------------------------
#ifndef NDEBUG
void TSafeArray::CheckIndex(const LONG* const pIndices,LPCSTR const lpComment)
{
 assert_msg(m_psa!=NULL,lpComment);
 assert_msg(pIndices!=NULL,lpComment);

 for(UINT nDim=1,_c(this->GetDim());nDim<=_c;++nDim)
 {
  const LONG lower=this->GetLBound(nDim);
  const LONG upper=this->GetUBound(nDim);

  assert_msg(lower<=pIndices[nDim-1] && pIndices[nDim-1]<=upper,
             lpComment<<"\n"
             "nDim=="<<nDim<<"\n"
             "lower=="<<lower<<"\n"
             "upper=="<<upper<<"\n"
             "index=="<<pIndices[nDim-1]);
 }//for
}//CheckIndex
#endif

//------------------------------------------------------------------------
void TSafeArray::GetElement(const LONG* const pIndices,
                            void*       const pv) //throw(bad_alloc)
{
 DEBUG_CODE(this->CheckIndex(pIndices,"get");)

 const HRESULT hr
  =LCPI_OS__SafeArrayGetElement
    (m_psa,
     const_cast<LONG*>(pIndices),
     pv);

 if(hr==E_OUTOFMEMORY)
  throw std::bad_alloc();

 if(FAILED(hr))
  t_base_ole_error::throw_error(hr,"TSafeArray::GetElement");

 assert_msg(hr==NOERROR,"hr==0x"<<std::hex<<hr);
}//GetElement

//------------------------------------------------------------------------
void TSafeArray::PutElement(const LONG* const pIndices,
                            const void* const pv) //throw(bad_alloc)
{
 DEBUG_CODE(this->CheckIndex(pIndices,"put");)

 const HRESULT hr
  =LCPI_OS__SafeArrayPutElement
    (m_psa,
     const_cast<LONG*>(pIndices),
     const_cast<void*>(pv));

 if(hr==E_OUTOFMEMORY)
  throw std::bad_alloc();

 if(FAILED(hr))
  t_base_ole_error::throw_error(hr,"TSafeArray::PutElement");

 assert_msg(hr==NOERROR,"hr==0x"<<std::hex<<hr);
}//PutElement

////////////////////////////////////////////////////////////////////////////////
}//namespace safe_array
