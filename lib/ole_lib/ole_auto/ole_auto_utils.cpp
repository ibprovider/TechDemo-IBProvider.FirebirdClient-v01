////////////////////////////////////////////////////////////////////////////////
//! \ingroup  ole_lib
//! \file     ole_auto_utils.cpp
//! \brief    Utilities for work with OLE Automation structures/objects
//! \author   Kovalenko Dmitry
//! \date     05.04.2004.
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_auto/ole_auto_utils.h>
#include <ole_lib/ole_auto/ole_auto_safe_array.h>
#include <ole_lib/ole_auto/ole_auto_variant_type_info.h>
#include <ole_lib/ole_ptr.h>
#include <structure/t_str_formatter.h>

#include <vector>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//messages

static const char* const msg_cycle_in_VARIANT_0=
 "Detect a cycle in variant references";

static const char* const msg_cant_clear_VARIANT_1=
 "Can't clear the variant [vt: %1]";

static const char* const msg_cant_copy_VARIANT_2=
 "Can't copy the variant [source_vt: %1] [dest_vt: %2]";

static const char* const msg_cant_copyInd_VARIANT_2=
 "Can't make the [indirection] copy of variant [source_vt: %1] [dest_vt: %2]";

////////////////////////////////////////////////////////////////////////////////
//const

static const ULONG c_SafeArrayDataFeaturesMask=FADF_BSTR|
                                               FADF_UNKNOWN|
                                               FADF_DISPATCH|
                                               FADF_VARIANT;

////////////////////////////////////////////////////////////////////////////////
//Unpack VARIANT structure. Remove VT_VARIANT|VT_BYREF levels

HRESULT Variant_Unpack(const VARIANT** const ppResult,
                       const VARIANT*  const pVariant,
                       const VARIANT*  const NullPtr)
{
 assert(ppResult!=NULL);

 //------------
 if(pVariant==NULL)
 {
  (*ppResult)=NullPtr;

  return S_OK;
 }//if

 //------------
 if(pVariant->vt!=(VT_BYREF|VT_VARIANT))
 {
  (*ppResult)=pVariant;

  return S_OK;
 }//if

 //------------
 const VARIANT* x1=pVariant;
 const VARIANT* x2=pVariant;

 for(bool step_x1=false;x2!=NULL && x2->vt==(VT_BYREF|VT_VARIANT);step_x1=!step_x1)
 {
  if(step_x1)
  {
   assert(x1);
   assert(x1->vt==(VT_BYREF|VT_VARIANT));

   x1=x1->pvarVal;
  }//if

  assert(x2);
  assert(x2->vt==(VT_BYREF|VT_VARIANT));

  x2=x2->pvarVal;

  if(x2==x1)
   return E_FAIL;
 }//for

 (*ppResult)=(x2?x2:NullPtr);

 return S_OK;
}//Variant_Unpack

//------------------------------------------------------------------------------
const VARIANT* Variant_Unpack(const VARIANT* const pVariant,
                              const VARIANT* const NullPtr)
{
 const VARIANT* pResult=NULL;

 if(FAILED(Variant_Unpack(&pResult,pVariant,NullPtr)))
  throw std::runtime_error(msg_cycle_in_VARIANT_0);

 return pResult;
}//Variant_Unpack

////////////////////////////////////////////////////////////////////////////////

HRESULT Variant_Clear(VARIANT* const pVariant)
{
 assert(pVariant!=NULL);

 if(pVariant==NULL)
  return E_INVALIDARG;

 const TVariantTypeInfo*
  const pVariantTypeInfo=GetVariantTypeInfo(pVariant->vt);

 if(pVariantTypeInfo && pVariantTypeInfo->pfVariantClear)
  return pVariantTypeInfo->pfVariantClear(pVariant);

 return LCPI_OS__VariantClear(pVariant);
}//Variant_Clear

//------------------------------------------------------------------------
HRESULT Variant_Copy(VARIANT* const pDest,const VARIANT* const pSource)
{
 assert(pDest);
 assert(pSource);

 if(pDest==NULL || pSource==NULL)
  return E_INVALIDARG;

 if(pDest==pSource)
  return S_OK;

 const TVariantTypeInfo*
  const pVariantTypeInfo=GetVariantTypeInfo(pSource->vt);

 if(pVariantTypeInfo && pVariantTypeInfo->pfVariantCopy)
  return pVariantTypeInfo->pfVariantCopy(pDest,pSource);

 return LCPI_OS__VariantCopy(pDest,const_cast<VARIANT*>(pSource));
}//Variant_Copy

//------------------------------------------------------------------------
HRESULT Variant_CopyInd(VARIANT* const pDest,const VARIANT* const pSource)
{
 assert(pDest);
 assert(pSource);

 if(pDest==NULL || pSource==NULL)
  return E_INVALIDARG;

 const TVariantTypeInfo*
  const pVariantTypeInfo=GetVariantTypeInfo(pSource->vt);

 if(pVariantTypeInfo && pVariantTypeInfo->pfVariantCopyInd)
  return pVariantTypeInfo->pfVariantCopyInd(pDest,pSource);

 return LCPI_OS__VariantCopyInd(pDest,const_cast<VARIANT*>(pSource));
}//Variant_CopyInd

////////////////////////////////////////////////////////////////////////////////
//Throw version

void Variant_Clear_Throw(VARIANT* const pVariant)
{
 assert(pVariant!=NULL);

 VARTYPE const vt=pVariant?pVariant->vt:VARTYPE(VT_EMPTY);

 const HRESULT hr=ole_lib::Variant_Clear(pVariant);

 if(FAILED(hr))
 {
  structure::str_formatter fmsg(msg_cant_clear_VARIANT_1);

  if(pVariant)
   fmsg<<vt;
  else
   fmsg<<"???";

  t_base_ole_error::throw_error(hr,fmsg.str());
 }

 assert(hr==S_OK);
}//Variant_Clear_Throw

//------------------------------------------------------------------------
void Variant_Copy_Throw(VARIANT* const pDest,const VARIANT* const pSource)
{
 assert(pDest);
 assert(pSource);

 VARTYPE const source_vt=pSource?pSource->vt:VARTYPE(VT_EMPTY);
 VARTYPE const dest_vt  =pDest?pDest->vt:VARTYPE(VT_EMPTY);

 const HRESULT hr=ole_lib::Variant_Copy(pDest,pSource);

 if(FAILED(hr))
 {
  structure::str_formatter fmsg(msg_cant_copy_VARIANT_2);

  if(pSource)
   fmsg<<source_vt;
  else
   fmsg<<"???";

  if(pDest)
   fmsg<<dest_vt;
  else
   fmsg<<"???";

  t_base_ole_error::throw_error(hr,fmsg.str());
 }//if FAILED

 assert(hr==S_OK);
}//Variant_Copy_Throw

//------------------------------------------------------------------------
void Variant_CopyInd_Throw(VARIANT* const pDest,const VARIANT* const pSource)
{
 assert(pDest);
 assert(pSource);

 VARTYPE const source_vt=pSource?pSource->vt:VARTYPE(VT_EMPTY);
 VARTYPE const dest_vt  =pDest?pDest->vt:VARTYPE(VT_EMPTY);

 const HRESULT hr=ole_lib::Variant_CopyInd(pDest,pSource);

 if(FAILED(hr))
 {
  structure::str_formatter fmsg(msg_cant_copyInd_VARIANT_2);

  if(pSource)
   fmsg<<source_vt;
  else
   fmsg<<"???";

  if(pDest)
   fmsg<<dest_vt;
  else
   fmsg<<"???";

  t_base_ole_error::throw_error(hr,fmsg.str());
 }//if FAILED

 assert(hr==S_OK);
}//Variant_CopyInd_Throw

////////////////////////////////////////////////////////////////////////////////
//SafeArray Destroy Functions

static HRESULT SafeArray_ClearElement_VARIANT(void*  const pElement,
                                              size_t const DEBUG_CODE(cbElement))
{
 assert(pElement!=NULL);
 assert(cbElement==sizeof(VARIANT));

 CHECK_READ_WRITE_PTR(pElement,cbElement);

 return ole_lib::Variant_Clear(reinterpret_cast<VARIANT*>(pElement));
}//SafeArray_ClearElement_VARIANT

//------------------------------------------------------------------------
static HRESULT SafeArray_ClearElement_BSTR(void*  const pElement,
                                           size_t const DEBUG_CODE(cbElement))
{
 assert(pElement!=NULL);
 assert(cbElement==sizeof(BSTR));

 CHECK_READ_WRITE_PTR(pElement,cbElement);

 ole_lib::FreeBStr(*reinterpret_cast<BSTR*>(pElement));

 return S_OK;
}//SafeArray_ClearElement_BSTR

//------------------------------------------------------------------------
static HRESULT SafeArray_ClearElement_ComObject(void*  const pElement,
                                                size_t const DEBUG_CODE(cbElement))
{
 assert(pElement!=NULL);
 assert(cbElement==sizeof(IUnknown*));

 CHECK_READ_WRITE_PTR(pElement,cbElement);

 ole_lib::ReleaseComInterface(*reinterpret_cast<IUnknown**>(pElement));

 return S_OK;
}//SafeArray_ClearElement_ComObject

//------------------------------------------------------------------------
typedef HRESULT (*PFSafeArray_Cleaner)(void* pElement,size_t cbElement);

HRESULT SafeArray_ClearElements(SAFEARRAY*          const pSA,
                                PFSafeArray_Cleaner const pfCleaner)
{
 assert(pSA);
 assert(pfCleaner);

 const UINT cDim=LCPI_OS__SafeArrayGetDim(pSA);

 size_t n=cDim?1:0;

 for(UINT iDim=0;iDim!=cDim;++iDim)
 {
  n=n*pSA->rgsabound[iDim].cElements;
 }//for iDim

 const UINT cbElement=LCPI_OS__SafeArrayGetElemsize(pSA);

 if(cbElement==0)
  return E_FAIL;

 TSafeArrayAccessor sa_accessor(pSA,false);

 if(!sa_accessor)
  return E_FAIL;

 char* pElement=reinterpret_cast<char*>(sa_accessor.Data());

 for(;n;--n)
 {
  if(pElement==NULL)
   return E_FAIL;

  const HRESULT clear_hr=pfCleaner(pElement,cbElement);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);

  pElement+=cbElement;
 }//for n

 return S_OK;
}//SafeArray_ClearElements

//------------------------------------------------------------------------
HRESULT SafeArray_Destroy(SAFEARRAY* const pSA)
{
 if(pSA==NULL)
  return S_OK;

 const UINT cbElement=LCPI_OS__SafeArrayGetElemsize(pSA);

 PFSafeArray_Cleaner pfCleaner=NULL;

 switch(pSA->fFeatures&c_SafeArrayDataFeaturesMask)
 {
  case FADF_BSTR:
  {
   if(cbElement==sizeof(BSTR))
    pfCleaner=SafeArray_ClearElement_BSTR;

   break;
  }//case FADF_BSTR

  case FADF_UNKNOWN:
  case FADF_DISPATCH:
  {
   if(cbElement==sizeof(void*))
    pfCleaner=SafeArray_ClearElement_ComObject;

   break;
  }//case FADF_UNKNOWN

  case FADF_VARIANT:
  {
   if(cbElement==sizeof(VARIANT))
    pfCleaner=SafeArray_ClearElement_VARIANT;

   break;
  }//case FADF_VARIANT
 }//switch

 if(pfCleaner!=NULL)
 {
  const HRESULT clear_hr=ole_lib::SafeArray_ClearElements(pSA,pfCleaner);

  if(FAILED(clear_hr))
   return clear_hr;
 }//if

 return LCPI_OS__SafeArrayDestroy(pSA);
}//SafeArray_Destroy

////////////////////////////////////////////////////////////////////////////////
//SafeArray Copy Functions

static HRESULT SafeArray_Copy_Variant(SAFEARRAY*  const pSA,
                                      SAFEARRAY** const pout)
{
 assert(pSA);
 assert(pout);

 (*pout)=NULL;

 const UINT cbSourceElement=LCPI_OS__SafeArrayGetElemsize(pSA);

 if(cbSourceElement!=sizeof(VARIANT))
  return E_FAIL;

 const UINT cDim=LCPI_OS__SafeArrayGetDim(pSA);

 size_t n=cDim?1:0;

 std::vector<SAFEARRAYBOUND> bound_vector;

 bound_vector.reserve(cDim);

 for(UINT x=0;x!=cDim;++x)
 {
  n*=pSA->rgsabound[x].cElements;

  bound_vector.push_back(pSA->rgsabound[cDim-x-1]);
 }//if

 TBaseSafeArray target_sa;

 target_sa.ref_sa()
  =LCPI_OS__SafeArrayCreate
    (VT_VARIANT,
     cDim,
     bound_vector.data());

 if(target_sa.sa()==NULL)
  return E_OUTOFMEMORY;

 const UINT cbTargetElement=LCPI_OS__SafeArrayGetElemsize(target_sa);

 assert(cbTargetElement==sizeof(VARIANT));

 if(cbTargetElement!=sizeof(VARIANT))
  return E_FAIL;

 //----------------
#ifndef NDEBUG
 {
  assert(LCPI_OS__SafeArrayGetDim(target_sa)==cDim);

  for(UINT x=0;x!=cDim;++x)
  {
   assert(target_sa.sa()->rgsabound[cDim-x-1].cElements==bound_vector[x].cElements);
   assert(target_sa.sa()->rgsabound[cDim-x-1].lLbound  ==bound_vector[x].lLbound);
  }
 }
#endif

 //----------------
 TSafeArrayAccessor target_sa_accessor(target_sa,false);

 if(!target_sa_accessor)
  return E_FAIL;

 TSafeArrayAccessor source_sa_accessor(pSA,false);

 if(!source_sa_accessor)
  return E_FAIL;

 //----------------
 const char* pSourceData=reinterpret_cast<const char*>(source_sa_accessor.Data());
 char*       pTargetData=reinterpret_cast<char*>(target_sa_accessor.Data());

 if(n)
 {
  assert_hint(n>0);

  if(pSourceData==NULL || pTargetData==NULL)
   return E_FAIL;

  for(;;)
  {
   assert(n>0);
   assert(pSourceData);
   assert(pTargetData);

   const HRESULT
    copy_hr=ole_lib::Variant_Copy(reinterpret_cast<VARIANT*>(pTargetData),
                                  reinterpret_cast<const VARIANT*>(pSourceData));

   assert(copy_hr==S_OK || FAILED(copy_hr));

   if(FAILED(copy_hr))
    return copy_hr;

   pSourceData+=cbSourceElement;
   pTargetData+=cbTargetElement;

   --n;

   if(n==0)
    break;
  }//for[ever]
 }//if n

 assert_hint(n==0);

 //----------------
 (*pout)=target_sa.Release();

 return S_OK;
}//SafeArray_Copy_Variant

//------------------------------------------------------------------------
HRESULT SafeArray_Copy(SAFEARRAY*  const pSA,
                       SAFEARRAY** const pout)
{
 assert(pout!=NULL);

 (*pout)=NULL;

 if(pSA==NULL)
  return S_OK;

 VARTYPE vt=VT_EMPTY;

 const HRESULT get_vt_hr=ole_lib::SafeArray_GetVarType(pSA,&vt);

 assert(FAILED(get_vt_hr) || get_vt_hr==S_OK);

 if(get_vt_hr==S_OK && vt==VT_VARIANT)
  return ole_lib::SafeArray_Copy_Variant(pSA,pout);

 return LCPI_OS__SafeArrayCopy(pSA,pout);
}//SafeArray_Copy

////////////////////////////////////////////////////////////////////////////////
//SafeArray Functions

HRESULT SafeArray_GetVarType(SAFEARRAY* const psa,
                             VARTYPE*   const pElementType)
{
 if(psa==NULL || pElementType==NULL)
  return E_INVALIDARG;

 const UINT cbElement=LCPI_OS__SafeArrayGetElemsize(psa);

 switch(psa->fFeatures&c_SafeArrayDataFeaturesMask)
 {
  case FADF_BSTR:
  {
   if(cbElement!=sizeof(BSTR))
    return E_FAIL;

   (*pElementType)=VT_BSTR;

   return S_OK;
  }//case FADF_BSTR

  case FADF_UNKNOWN:
  {
   if(cbElement!=sizeof(IUnknown*))
    return E_FAIL;

   (*pElementType)=VT_UNKNOWN;

   return S_OK;
  }//case FADF_UNKNOWN

  case FADF_DISPATCH:
  {
   if(cbElement!=sizeof(IDispatch*))
    return E_FAIL;

   (*pElementType)=VT_DISPATCH;

   return S_OK;
  }//case FADF_DISPATCH

  case FADF_VARIANT:
  {
   if(cbElement!=sizeof(VARIANT))
    return E_FAIL;

   (*pElementType)=VT_VARIANT;

   return S_OK;
  }//case FADF_VARIANT
 }//switch

 return LCPI_OS__SafeArrayGetVartype(psa,pElementType);
}//SafeArray_GetVarType

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
