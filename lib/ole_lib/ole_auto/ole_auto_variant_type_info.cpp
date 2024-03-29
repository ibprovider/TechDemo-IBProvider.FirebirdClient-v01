////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_auto/ole_auto_variant_type_info.h>
#include <ole_lib/ole_auto/ole_auto_utils.h>
#include <ole_lib/ole_ptr.h>
#include <ole_lib/ole_base.h>
#include <oledb.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//Variant Clear Functions

static HRESULT Variant_Clear_SetEmpty(VARIANT* const pVariant)
{
 assert(pVariant);

 pVariant->vt=VT_EMPTY;

 return S_OK;
}//Variant_Clear_SetEmpty

//------------------------------------------------------------------------
static HRESULT Variant_Clear_BSTR(VARIANT* const pVariant)
{
 assert(pVariant);
 assert(pVariant->vt==VT_BSTR);

 ole_lib::FreeBStr(pVariant->bstrVal);

 pVariant->vt=VT_EMPTY;

 return S_OK;
}//Variant_Clear_BSTR

//------------------------------------------------------------------------
static HRESULT Variant_Clear_Unknown(VARIANT* const pVariant)
{
 assert(pVariant);
 assert(pVariant->vt==VT_UNKNOWN);

 ole_lib::ReleaseComInterface(pVariant->punkVal);

 pVariant->vt=VT_EMPTY;

 return S_OK;
}//Variant_Clear_Unknown

//------------------------------------------------------------------------
static HRESULT Variant_Clear_Dispatch(VARIANT* const pVariant)
{
 assert(pVariant);
 assert(pVariant->vt==VT_DISPATCH);

 ole_lib::ReleaseComInterface(pVariant->pdispVal);

 pVariant->vt=VT_EMPTY;

 return S_OK;
}//Variant_Clear_Dispatch

//------------------------------------------------------------------------
static HRESULT Variant_Clear_Array(VARIANT* const pVariant)
{
 assert(pVariant);
 assert((pVariant->vt&VT_ARRAY)==VT_ARRAY);

 if(pVariant->parray!=NULL)
 {
  const HRESULT destroy_sa_hr=ole_lib::SafeArray_Destroy(pVariant->parray);

  if(FAILED(destroy_sa_hr))
   return destroy_sa_hr;
 }//if

 pVariant->vt=VT_EMPTY;

 return S_OK;
}//Variant_Clear_Array

////////////////////////////////////////////////////////////////////////////////
//Variant Copy

static HRESULT Variant_Copy_Direct(VARIANT* pDest,const VARIANT* pSource)
{
 assert(pDest);
 assert(pSource);

 if(pDest==pSource)
  return S_OK;

 const VARIANT copySource=*pSource;

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 (*pDest)=copySource;

 return S_OK;
}//Variant_Copy_Direct

//------------------------------------------------------------------------
static HRESULT Variant_Copy_BSTR(VARIANT* pDest,const VARIANT* pSource)
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==VT_BSTR);

 if(pDest==pSource)
  return S_OK;

 ole_lib::TBSTR bstr;

 if(pSource->bstrVal!=NULL)
 {
  BSTR const tmp
   =LCPI_OS__SysAllocStringLen
     (pSource->bstrVal,
      LCPI_OS__SysStringLen(pSource->bstrVal));

  if(tmp==nullptr)
   return E_OUTOFMEMORY;

  bstr.ref_bstr()=tmp;
 }//if

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->bstrVal =bstr.Release();
 pDest->vt      =VT_BSTR;

 return S_OK;
}//Variant_Copy_BSTR

//------------------------------------------------------------------------
static HRESULT Variant_Copy_Dispatch(VARIANT* pDest,const VARIANT* pSource)
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==VT_DISPATCH);

 if(pDest==pSource)
  return S_OK;

 OLE_LIB__DECLARE_IPTR_TYPE(IDispatch);

 IDispatchPtr spDisp(pSource->pdispVal);

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 spDisp.MoveTo_Fast(&pDest->pdispVal);

 pDest->vt=VT_DISPATCH;

 return S_OK;
}//Variant_Copy_Dispatch

//------------------------------------------------------------------------
static HRESULT Variant_Copy_Unknown(VARIANT* pDest,const VARIANT* pSource)
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==VT_UNKNOWN);

 if(pDest==pSource)
  return S_OK;

 IUnknownPtr spUnk(pSource->punkVal);

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 spUnk.MoveTo_Fast(&pDest->punkVal);

 pDest->vt=VT_UNKNOWN;

 return S_OK;
}//Variant_Copy_Unknown

//------------------------------------------------------------------------
static HRESULT Variant_Copy_Array(VARIANT* pDest,const VARIANT* pSource)
{
 assert(pDest);
 assert(pSource);
 assert((pSource->vt&VT_ARRAY)==VT_ARRAY);

 if(pDest==pSource)
  return S_OK;

 SAFEARRAY* psa=NULL;

 const VARTYPE source_vt=pSource->vt;

 {
  const HRESULT copy_hr=ole_lib::SafeArray_Copy(pSource->parray,&psa);

  if(FAILED(copy_hr))
   return copy_hr;

  assert(copy_hr==S_OK);
 }//local

 try
 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }
 catch(...)
 {
  _VERIFY_EQ(ole_lib::SafeArray_Destroy(psa),S_OK);

  throw;
 }

 pDest->parray=psa;

 pDest->vt=source_vt;

 return S_OK;
}//Variant_Copy_Array

////////////////////////////////////////////////////////////////////////////////
//Variant Copy Indirect

HRESULT Variant_CopyInd_ByRef_I1(VARIANT* pDest,const VARIANT* pSource)   // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_I1));                                   // !!!

 signed char x;                                                           // !!!

 if(pSource->pcVal)                                                       // !!!
  x=*pSource->pcVal;                                                      // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->cVal =x;                                                          // !!!
 pDest->vt   =VT_I1;                                                      // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_I1                                               // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_I2(VARIANT* pDest,const VARIANT* pSource)   // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_I2));                                   // !!!

 signed short x;                                                          // !!!

 if(pSource->piVal)                                                       // !!!
  x=*pSource->piVal;                                                      // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->iVal =x;                                                          // !!!
 pDest->vt   =VT_I2;                                                      // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_I2                                               // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_I4(VARIANT* pDest,const VARIANT* pSource)   // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_I4));                                   // !!!

 signed long x;                                                           // !!!

 if(pSource->plVal)                                                       // !!!
  x=*pSource->plVal;                                                      // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->lVal =x;                                                          // !!!
 pDest->vt   =VT_I4;                                                      // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_I4                                               // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_I8(VARIANT* pDest,const VARIANT* pSource)   // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_I8));                                   // !!!

 signed __int64 x;                                                        // !!!

 if(pSource->pllVal)                                                      // !!!
  x=*pSource->pllVal;                                                     // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->llVal=x;                                                          // !!!
 pDest->vt   =VT_I8;                                                      // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_I8                                               // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_UI1(VARIANT* pDest,const VARIANT* pSource)  // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_UI1));                                  // !!!

 unsigned char x;                                                         // !!!

 if(pSource->pbVal)                                                       // !!!
  x=*pSource->pbVal;                                                      // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->bVal =x;                                                          // !!!
 pDest->vt   =VT_UI1;                                                     // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_UI1                                              // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_UI2(VARIANT* pDest,const VARIANT* pSource)  // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_UI2));                                  // !!!

 unsigned short x;                                                        // !!!

 if(pSource->puiVal)                                                      // !!!
  x=*pSource->puiVal;                                                     // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->uiVal =x;                                                         // !!!
 pDest->vt    =VT_UI2;                                                    // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_UI2                                              // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_UI4(VARIANT* pDest,const VARIANT* pSource)  // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_UI4));                                  // !!!

 unsigned long x;                                                         // !!!

 if(pSource->pulVal)                                                      // !!!
  x=*pSource->pulVal;                                                     // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->ulVal =x;                                                         // !!!
 pDest->vt    =VT_UI4;                                                    // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_UI4                                              // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_UI8(VARIANT* pDest,const VARIANT* pSource)  // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_UI8));                                  // !!!

 unsigned __int64 x;                                                      // !!!

 if(pSource->pullVal)                                                     // !!!
  x=*pSource->pullVal;                                                    // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->ullVal=x;                                                         // !!!
 pDest->vt    =VT_UI8;                                                    // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_UI8                                              // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_R4(VARIANT* pDest,const VARIANT* pSource)   // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_R4));                                   // !!!

 float x;                                                                 // !!!

 if(pSource->pfltVal)                                                     // !!!
  x=*pSource->pfltVal;                                                    // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->fltVal=x;                                                         // !!!
 pDest->vt    =VT_R4;                                                     // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_R4                                               // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_R8(VARIANT* pDest,const VARIANT* pSource)   // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_R8));                                   // !!!

 double x;                                                                // !!!

 if(pSource->pdblVal)                                                     // !!!
  x=*pSource->pdblVal;                                                    // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->dblVal=x;                                                         // !!!
 pDest->vt    =VT_R8;                                                     // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_R8                                               // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_CY(VARIANT* pDest,const VARIANT* pSource)   // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_CY));                                   // !!!

 tagCY x;                                                                 // !!!

 if(pSource->pcyVal)                                                      // !!!
  x=*pSource->pcyVal;                                                     // !!!
 else
  x.int64=0;                                                              // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->cyVal =x;                                                         // !!!
 pDest->vt    =VT_CY;                                                     // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_CY                                               // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_Decimal(VARIANT* pDest,const VARIANT* pSource)// !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_DECIMAL));                              // !!!

 tagDEC x;                                                                // !!!

 if(pSource->pdecVal)                                                     // !!!
  x=*pSource->pdecVal;                                                    // !!!
 else
  memset(&x,0,sizeof(x));                                                 // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->decVal=x;                                                         // !!!
 pDest->vt    =VT_DECIMAL;                                                // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_Decimal                                          // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_INT(VARIANT* pDest,const VARIANT* pSource)  // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_INT));                                  // !!!

 int x;                                                                   // !!!

 if(pSource->pintVal)                                                     // !!!
  x=*pSource->pintVal;                                                    // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->intVal=x;                                                         // !!!
 pDest->vt    =VT_INT;                                                    // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_INT                                              // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_UINT(VARIANT* pDest,const VARIANT* pSource) // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_UINT));                                 // !!!

 unsigned int x;                                                          // !!!

 if(pSource->puintVal)                                                    // !!!
  x=*pSource->puintVal;                                                   // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->uintVal=x;                                                        // !!!
 pDest->vt     =VT_UINT;                                                  // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_UINT                                             // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_ERROR(VARIANT* pDest,const VARIANT* pSource)// !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_ERROR));                                // !!!

 SCODE x;                                                                 // !!!

 if(pSource->pscode)                                                      // !!!
  x=*pSource->pscode;                                                     // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->scode =x;                                                         // !!!
 pDest->vt    =VT_ERROR;                                                  // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_ERROR                                            // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_BOOL(VARIANT* pDest,const VARIANT* pSource) // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_BOOL));                                 // !!!

 VARIANT_BOOL x;                                                          // !!!

 if(pSource->pboolVal)                                                    // !!!
  x=*pSource->pboolVal;                                                   // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->boolVal =x;                                                       // !!!
 pDest->vt      =VT_BOOL;                                                 // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_BOOL                                             // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_DATE(VARIANT* pDest,const VARIANT* pSource) // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_DATE));                                 // !!!

 DATE x;                                                                  // !!!

 if(pSource->pdate)                                                       // !!!
  x=*pSource->pdate;                                                      // !!!
 else
  x=0;                                                                    // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->date  =x;                                                         // !!!
 pDest->vt    =VT_DATE;                                                   // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_DATE                                             // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_Dispatch(VARIANT* pDest,const VARIANT* pSource) // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_DISPATCH));                             // !!!

 OLE_LIB__DECLARE_IPTR_TYPE(IDispatch);

 IDispatchPtr x;                                                          // !!!

 if(pSource->ppdispVal!=NULL)                                             // !!!
  x=*pSource->ppdispVal;                                                  // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 x.MoveTo_Fast(&pDest->pdispVal);                                         // !!!

 pDest->vt=VT_DISPATCH;                                                   // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_Dispatch                                         // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_Unknown(VARIANT* pDest,const VARIANT* pSource) // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_UNKNOWN));                              // !!!

 IUnknownPtr x;                                                           // !!!

 if(pSource->ppunkVal!=NULL)                                              // !!!
  x=*pSource->ppunkVal;                                                   // !!!

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 x.MoveTo_Fast(&pDest->punkVal);                                          // !!!

 pDest->vt=VT_UNKNOWN;                                                    // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_Unknown                                          // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_BSTR(VARIANT* pDest,const VARIANT* pSource) // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_BSTR));                                 // !!!

 TBSTR x;                                                                 // !!!

 if(pSource->pbstrVal!=NULL)                                              // !!!
 {
  if((*pSource->pbstrVal)!=NULL)                                          // !!!
  {
   BSTR const tmp
    =LCPI_OS__SysAllocStringLen
      (*(pSource->pbstrVal),
       LCPI_OS__SysStringLen(*(pSource->pbstrVal)));

   if(tmp==nullptr)
    return E_OUTOFMEMORY;

   x.ref_bstr()=tmp;
  }
 }//if

 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }//local

 pDest->bstrVal =x.Release();                                             // !!!
 pDest->vt      =VT_BSTR;                                                 // !!!

 return S_OK;
}//Variant_CopyInd_ByRef_BSTR                                             // !!!

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_VARIANT(VARIANT* pDest,const VARIANT* pSource) // !!!
{
 assert(pDest);
 assert(pSource);
 assert(pSource->vt==(VT_BYREF|VT_VARIANT));                              // !!!

 //------
 const VARIANT* pUnpackSource=NULL;

 //------
 VARIANT empty;

 empty.vt=VT_EMPTY;

 //------
 if(FAILED(Variant_Unpack(&pUnpackSource,pSource,&empty)))
  return E_FAIL;

 assert(pUnpackSource!=NULL);
 assert(pUnpackSource->vt!=(VT_BYREF|VT_VARIANT));

 return Variant_CopyInd(pDest,pUnpackSource);
}//Variant_CopyInd_ByRef_BSTR

//------------------------------------------------------------------------
HRESULT Variant_CopyInd_ByRef_Array(VARIANT* pDest,const VARIANT* pSource)
{
 assert(pDest);
 assert(pSource);
 assert((pSource->vt&(VT_BYREF|VT_ARRAY))==(VT_BYREF|VT_ARRAY));

 SAFEARRAY* psa=NULL;

 if(pSource->pparray!=NULL)
 {
  if((*pSource->pparray)!=NULL)
  {
   const HRESULT copy_array_hr=ole_lib::SafeArray_Copy(*pSource->pparray,&psa);

   if(FAILED(copy_array_hr))
    return copy_array_hr;

   assert(copy_array_hr==S_OK);
  }//if
 }//if

 const VARTYPE dest_vt=VARTYPE(pSource->vt&(~VT_BYREF));

 try
 {
  const HRESULT clear_hr=ole_lib::Variant_Clear(pDest);

  if(FAILED(clear_hr))
   return clear_hr;

  assert(clear_hr==S_OK);
 }
 catch(...)
 {
  _VERIFY_EQ(ole_lib::SafeArray_Destroy(psa),S_OK);

  throw;
 }

 assert(pDest->vt==VT_EMPTY);

 pDest->parray=psa;

 pDest->vt=dest_vt;

 return S_OK;
}//Variant_CopyInd_ByRef_Array

////////////////////////////////////////////////////////////////////////////////

#define MAKE_WTEXT(text) L##text

#define DEF_VAR_TYPE_INFO(name,                                          \
                          vt,                                            \
                          size,                                          \
                          oledb_type_id,                                 \
                          clear_func,                                    \
                          copy_func,                                     \
                          copy_ind_func)                                 \
static const TVariantTypeInfo g_VarTypeInfo_##name=                      \
{                                                                        \
 vt,                                                                     \
 MAKE_WTEXT(#vt),                                                        \
 size,                                                                   \
 oledb_type_id,                                                          \
 clear_func,                                                             \
 copy_func,                                                              \
 copy_ind_func,                                                          \
}

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(EMPTY,
                  VT_EMPTY,
                  0,
                  DBTYPE_EMPTY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(NULL,
                  VT_NULL,
                  0,
                  DBTYPE_NULL,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(I2,
                  VT_I2,
                  sizeof(signed short),
                  DBTYPE_I2,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(I4,
                  VT_I4,
                  sizeof(signed long),
                  DBTYPE_I4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(R4,
                  VT_R4,
                  sizeof(float),
                  DBTYPE_R4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(R8,
                  VT_R8,
                  sizeof(double),
                  DBTYPE_R8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(CY,
                  VT_CY,
                  sizeof(tagCY),
                  DBTYPE_CY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(DATE,
                  VT_DATE,
                  sizeof(DATE),
                  DBTYPE_DATE,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BSTR,
                  VT_BSTR,
                  sizeof(BSTR),
                  DBTYPE_BSTR,
                  Variant_Clear_BSTR,
                  Variant_Copy_BSTR,
                  Variant_Copy_BSTR);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(DISPATCH,
                  VT_DISPATCH,
                  sizeof(IDispatch*),
                  DBTYPE_IDISPATCH,
                  Variant_Clear_Dispatch,
                  Variant_Copy_Dispatch,
                  Variant_Copy_Dispatch);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ERROR,
                  VT_ERROR,
                  sizeof(SCODE),
                  DBTYPE_ERROR,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BOOL,
                  VT_BOOL,
                  sizeof(VARIANT_BOOL),
                  DBTYPE_BOOL,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(VARIANT,
                  VT_VARIANT,
                  sizeof(VARIANT),
                  DBTYPE_VARIANT,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(UNKNOWN,
                  VT_UNKNOWN,
                  sizeof(IUnknown*),
                  DBTYPE_IUNKNOWN,
                  Variant_Clear_Unknown,
                  Variant_Copy_Unknown,
                  Variant_Copy_Unknown);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(DECIMAL,
                  VT_DECIMAL,
                  sizeof(tagDEC),
                  DBTYPE_DECIMAL,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(I1,
                  VT_I1,
                  sizeof(signed char),
                  DBTYPE_I1,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(UI1,
                  VT_UI1,
                  sizeof(unsigned char),
                  DBTYPE_UI1,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(UI2,
                  VT_UI2,
                  sizeof(unsigned short),
                  DBTYPE_UI2,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(UI4,
                  VT_UI4,
                  sizeof(unsigned long),
                  DBTYPE_UI4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(I8,
                  VT_I8,
                  sizeof(signed __int64),
                  DBTYPE_I8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(UI8,
                  VT_UI8,
                  sizeof(unsigned __int64),
                  DBTYPE_UI8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(INT,
                  VT_INT,
                  sizeof(signed int),
                  DBTYPE_EMPTY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(UINT,
                  VT_UINT,
                  sizeof(unsigned int),
                  DBTYPE_EMPTY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_Copy_Direct);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(HRESULT,
                  VT_HRESULT,
                  sizeof(HRESULT),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(INT_PTR,
                  VT_INT_PTR,
                  sizeof(INT_PTR),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(UINT_PTR,
                  VT_UINT_PTR,
                  sizeof(UINT_PTR),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(FILETIME,
                  VT_FILETIME,
                  sizeof(FILETIME),
                  DBTYPE_FILETIME,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(CLSID,
                  VT_CLSID,
                  sizeof(GUID),
                  DBTYPE_GUID,
                  NULL,
                  NULL,
                  NULL);

////////////////////////////////////////////////////////////////////////////////
//VT_BYREF

DEF_VAR_TYPE_INFO(BYREF_I2,
                  VT_BYREF|VT_I2,
                  sizeof(signed short*),
                  DBTYPE_BYREF|DBTYPE_I2,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_I2);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_I4,
                  VT_BYREF|VT_I4,
                  sizeof(signed long*),
                  DBTYPE_BYREF|DBTYPE_I4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_I4);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_R4,
                  VT_BYREF|VT_R4,
                  sizeof(float*),
                  DBTYPE_BYREF|DBTYPE_R4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_R4);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_R8,
                  VT_BYREF|VT_R8,
                  sizeof(double*),
                  DBTYPE_BYREF|DBTYPE_R8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_R8);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_CY,
                  VT_BYREF|VT_CY,
                  sizeof(tagCY*),
                  DBTYPE_BYREF|DBTYPE_CY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_CY);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_DATE,
                  VT_BYREF|VT_DATE,
                  sizeof(DATE*),
                  DBTYPE_BYREF|DBTYPE_DATE,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_DATE);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_BSTR,
                  VT_BYREF|VT_BSTR,
                  sizeof(BSTR*),
                  DBTYPE_BYREF|DBTYPE_BSTR,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_BSTR);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_DISPATCH,
                  VT_BYREF|VT_DISPATCH,
                  sizeof(IDispatch**),
                  DBTYPE_BYREF|DBTYPE_IDISPATCH,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Dispatch);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ERROR,
                  VT_BYREF|VT_ERROR,
                  sizeof(SCODE*),
                  DBTYPE_BYREF|DBTYPE_ERROR,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_ERROR);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_BOOL,
                  VT_BYREF|VT_BOOL,
                  sizeof(VARIANT_BOOL*),
                  DBTYPE_BYREF|DBTYPE_BOOL,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_BOOL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_VARIANT,
                  VT_BYREF|VT_VARIANT,
                  sizeof(VARIANT*),
                  DBTYPE_BYREF|DBTYPE_VARIANT,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_VARIANT);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_UNKNOWN,
                  VT_BYREF|VT_UNKNOWN,
                  sizeof(IUnknown**),
                  DBTYPE_BYREF|DBTYPE_IUNKNOWN,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Unknown);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_DECIMAL,
                  VT_BYREF|VT_DECIMAL,
                  sizeof(tagDEC*),
                  DBTYPE_BYREF|DBTYPE_DECIMAL,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Decimal);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_I1,
                  VT_BYREF|VT_I1,
                  sizeof(signed char*),
                  DBTYPE_BYREF|DBTYPE_I1,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_I1);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_UI1,
                  VT_BYREF|VT_UI1,
                  sizeof(unsigned char*),
                  DBTYPE_BYREF|DBTYPE_UI1,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_UI1);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_UI2,
                  VT_BYREF|VT_UI2,
                  sizeof(unsigned short*),
                  DBTYPE_BYREF|DBTYPE_UI2,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_UI2);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_UI4,
                  VT_BYREF|VT_UI4,
                  sizeof(unsigned long*),
                  DBTYPE_BYREF|DBTYPE_UI4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_UI4);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_I8,
                  VT_BYREF|VT_I8,
                  sizeof(signed __int64*),
                  DBTYPE_BYREF|DBTYPE_I8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_I8);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_UI8,
                  VT_BYREF|VT_UI8,
                  sizeof(unsigned __int64*),
                  DBTYPE_BYREF|DBTYPE_UI8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_UI8);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_INT,
                  VT_BYREF|VT_INT,
                  sizeof(signed int*),
                  DBTYPE_EMPTY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_INT);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_UINT,
                  VT_BYREF|VT_UINT,
                  sizeof(unsigned int*),
                  DBTYPE_EMPTY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_UINT);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_HRESULT,
                  VT_BYREF|VT_HRESULT,
                  sizeof(HRESULT*),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_INT_PTR,
                  VT_BYREF|VT_INT_PTR,
                  sizeof(INT_PTR*),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_UINT_PTR,
                  VT_BYREF|VT_UINT_PTR,
                  sizeof(UINT_PTR*),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_FILETIME,
                  VT_BYREF|VT_FILETIME,
                  sizeof(FILETIME*),
                  DBTYPE(DBTYPE_BYREF)|DBTYPE(DBTYPE_FILETIME),
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_CLSID,
                  VT_BYREF|VT_CLSID,
                  sizeof(GUID*),
                  DBTYPE_BYREF|DBTYPE_GUID,
                  NULL,
                  NULL,
                  NULL);

/////////////////////////////////////////////////////////////////////////////////
//VT_ARRAY

DEF_VAR_TYPE_INFO(ARRAY_I1,
                  VT_ARRAY|VT_I1,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_I1,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_I2,
                  VT_ARRAY|VT_I2,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_I2,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_I4,
                  VT_ARRAY|VT_I4,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_I4,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_I8,
                  VT_ARRAY|VT_I8,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_I8,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_UI1,
                  VT_ARRAY|VT_UI1,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_UI1,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_UI2,
                  VT_ARRAY|VT_UI2,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_UI2,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_UI4,
                  VT_ARRAY|VT_UI4,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_UI4,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_UI8,
                  VT_ARRAY|VT_UI8,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_UI8,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_R4,
                  VT_ARRAY|VT_R4,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_R4,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_R8,
                  VT_ARRAY|VT_R8,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_R8,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_CY,
                  VT_ARRAY|VT_CY,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_CY,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_DECIMAL,
                  VT_ARRAY|VT_DECIMAL,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_DECIMAL,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_INT,
                  VT_ARRAY|VT_INT,
                  sizeof(SAFEARRAY*),
                  DBTYPE_EMPTY,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_UINT,
                  VT_ARRAY|VT_UINT,
                  sizeof(SAFEARRAY*),
                  DBTYPE_EMPTY,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_BOOL,
                  VT_ARRAY|VT_BOOL,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_BOOL,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_ERROR,
                  VT_ARRAY|VT_ERROR,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_ERROR,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_HRESULT,
                  VT_ARRAY|VT_HRESULT,
                  sizeof(SAFEARRAY*),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_BSTR,
                  VT_ARRAY|VT_BSTR,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_BSTR,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_DATE,
                  VT_ARRAY|VT_DATE,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_DATE,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_UNKNOWN,
                  VT_ARRAY|VT_UNKNOWN,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_IUNKNOWN,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_DISPATCH,
                  VT_ARRAY|VT_DISPATCH,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_IDISPATCH,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(ARRAY_VARIANT,
                  VT_ARRAY|VT_VARIANT,
                  sizeof(SAFEARRAY*),
                  DBTYPE_ARRAY|DBTYPE_VARIANT,
                  Variant_Clear_Array,
                  Variant_Copy_Array,
                  Variant_Copy_Array);

/////////////////////////////////////////////////////////////////////////////////
//VT_BYREF|VT_ARRAY

DEF_VAR_TYPE_INFO(BYREF_ARRAY_I1,
                  VT_BYREF|VT_ARRAY|VT_I1,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_I1,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_I2,
                  VT_BYREF|VT_ARRAY|VT_I2,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_I2,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_I4,
                  VT_BYREF|VT_ARRAY|VT_I4,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_I4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_I8,
                  VT_BYREF|VT_ARRAY|VT_I8,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_I8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_UI1,
                  VT_BYREF|VT_ARRAY|VT_UI1,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_UI1,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_UI2,
                  VT_BYREF|VT_ARRAY|VT_UI2,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_UI2,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_UI4,
                  VT_BYREF|VT_ARRAY|VT_UI4,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_UI4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_UI8,
                  VT_BYREF|VT_ARRAY|VT_UI8,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_UI8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_R4,
                  VT_BYREF|VT_ARRAY|VT_R4,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_R4,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_R8,
                  VT_BYREF|VT_ARRAY|VT_R8,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_R8,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_CY,
                  VT_BYREF|VT_ARRAY|VT_CY,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_CY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_DECIMAL,
                  VT_BYREF|VT_ARRAY|VT_DECIMAL,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_DECIMAL,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_INT,
                  VT_BYREF|VT_ARRAY|VT_INT,
                  sizeof(SAFEARRAY**),
                  DBTYPE_EMPTY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_UINT,
                  VT_BYREF|VT_ARRAY|VT_UINT,
                  sizeof(SAFEARRAY**),
                  DBTYPE_EMPTY,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_BOOL,
                  VT_BYREF|VT_ARRAY|VT_BOOL,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_BOOL,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_ERROR,
                  VT_BYREF|VT_ARRAY|VT_ERROR,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_ERROR,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_HRESULT,
                  VT_BYREF|VT_ARRAY|VT_HRESULT,
                  sizeof(SAFEARRAY**),
                  DBTYPE_EMPTY,
                  NULL,
                  NULL,
                  NULL);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_BSTR,
                  VT_BYREF|VT_ARRAY|VT_BSTR,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_BSTR,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_DATE,
                  VT_BYREF|VT_ARRAY|VT_DATE,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_DATE,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_UNKNOWN,
                  VT_BYREF|VT_ARRAY|VT_UNKNOWN,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_IUNKNOWN,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_DISPATCH,
                  VT_BYREF|VT_ARRAY|VT_DISPATCH,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_IDISPATCH,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

//------------------------------------------------------------------------
DEF_VAR_TYPE_INFO(BYREF_ARRAY_VARIANT,
                  VT_BYREF|VT_ARRAY|VT_VARIANT,
                  sizeof(SAFEARRAY**),
                  DBTYPE_BYREF|DBTYPE_ARRAY|DBTYPE_VARIANT,
                  Variant_Clear_SetEmpty,
                  Variant_Copy_Direct,
                  Variant_CopyInd_ByRef_Array);

////////////////////////////////////////////////////////////////////////////////
//struct TVariantTypeInfoBox

struct TVariantTypeInfoBox
{
 const TVariantTypeInfo* pSimple;
 const TVariantTypeInfo* pSimpleByRef;
 const TVariantTypeInfo* pArray;
 const TVariantTypeInfo* pArrayByRef;
};//struct TVariantTypeInfoBox

////////////////////////////////////////////////////////////////////////////////
//VARTYPE Table

#define VT_INFO(name) &g_VarTypeInfo_##name

#define ADD_VT_INFO_BOX(vt_simple,vt_byref,vt_array,vt_array_byref) \
 {vt_simple,vt_byref,vt_array,vt_array_byref},

const TVariantTypeInfoBox g_VarTypeInfoTable[]=
{
 /*  0*/ADD_VT_INFO_BOX(VT_INFO(EMPTY),
                        NULL,
                        NULL,
                        NULL)

 /*  1*/ADD_VT_INFO_BOX(VT_INFO(NULL),
                        NULL,
                        NULL,
                        NULL)

 /*  2*/ADD_VT_INFO_BOX(VT_INFO(I2),
                        VT_INFO(BYREF_I2),
                        VT_INFO(ARRAY_I2),
                        VT_INFO(BYREF_ARRAY_I2))

 /*  3*/ADD_VT_INFO_BOX(VT_INFO(I4),
                        VT_INFO(BYREF_I4),
                        VT_INFO(ARRAY_I4),
                        VT_INFO(BYREF_ARRAY_I4))

 /*  4*/ADD_VT_INFO_BOX(VT_INFO(R4),
                        VT_INFO(BYREF_R4),
                        VT_INFO(ARRAY_R4),
                        VT_INFO(BYREF_ARRAY_R4))

 /*  5*/ADD_VT_INFO_BOX(VT_INFO(R8),
                        VT_INFO(BYREF_R8),
                        VT_INFO(ARRAY_R8),
                        VT_INFO(BYREF_ARRAY_R8))

 /*  6*/ADD_VT_INFO_BOX(VT_INFO(CY),
                        VT_INFO(BYREF_CY),
                        VT_INFO(ARRAY_CY),
                        VT_INFO(BYREF_ARRAY_CY))

 /*  7*/ADD_VT_INFO_BOX(VT_INFO(DATE),
                        VT_INFO(BYREF_DATE),
                        VT_INFO(ARRAY_DATE),
                        VT_INFO(BYREF_ARRAY_DATE))

 /*  8*/ADD_VT_INFO_BOX(VT_INFO(BSTR),
                        VT_INFO(BYREF_BSTR),
                        VT_INFO(ARRAY_BSTR),
                        VT_INFO(BYREF_ARRAY_BSTR))

 /*  9*/ADD_VT_INFO_BOX(VT_INFO(DISPATCH),
                        VT_INFO(BYREF_DISPATCH),
                        VT_INFO(ARRAY_DISPATCH),
                        VT_INFO(BYREF_ARRAY_DISPATCH))

 /* 10*/ADD_VT_INFO_BOX(VT_INFO(ERROR),
                        VT_INFO(BYREF_ERROR),
                        VT_INFO(ARRAY_ERROR),
                        VT_INFO(BYREF_ARRAY_ERROR))

 /* 11*/ADD_VT_INFO_BOX(VT_INFO(BOOL),
                        VT_INFO(BYREF_BOOL),
                        VT_INFO(ARRAY_BOOL),
                        VT_INFO(BYREF_ARRAY_BOOL))

 /* 12*/ADD_VT_INFO_BOX(VT_INFO(VARIANT),
                        VT_INFO(BYREF_VARIANT),
                        VT_INFO(ARRAY_VARIANT),
                        VT_INFO(BYREF_ARRAY_VARIANT))

 /* 13*/ADD_VT_INFO_BOX(VT_INFO(UNKNOWN),
                        VT_INFO(BYREF_UNKNOWN),
                        VT_INFO(ARRAY_UNKNOWN),
                        VT_INFO(BYREF_ARRAY_UNKNOWN))

 /* 14*/ADD_VT_INFO_BOX(VT_INFO(DECIMAL),
                        VT_INFO(BYREF_DECIMAL),
                        VT_INFO(ARRAY_DECIMAL),
                        VT_INFO(BYREF_ARRAY_DECIMAL))

 /* 15*/{NULL},

 /* 16*/ADD_VT_INFO_BOX(VT_INFO(I1),
                        VT_INFO(BYREF_I1),
                        VT_INFO(ARRAY_I1),
                        VT_INFO(BYREF_ARRAY_I1))

 /* 17*/ADD_VT_INFO_BOX(VT_INFO(UI1),
                        VT_INFO(BYREF_UI1),
                        VT_INFO(ARRAY_UI1),
                        VT_INFO(BYREF_ARRAY_UI1))

 /* 18*/ADD_VT_INFO_BOX(VT_INFO(UI2),
                        VT_INFO(BYREF_UI2),
                        VT_INFO(ARRAY_UI2),
                        VT_INFO(BYREF_ARRAY_UI2))

 /* 19*/ADD_VT_INFO_BOX(VT_INFO(UI4),
                        VT_INFO(BYREF_UI4),
                        VT_INFO(ARRAY_UI4),
                        VT_INFO(BYREF_ARRAY_UI4))

 /* 20*/ADD_VT_INFO_BOX(VT_INFO(I8),
                        VT_INFO(BYREF_I8),
                        VT_INFO(ARRAY_I8),
                        VT_INFO(BYREF_ARRAY_I8))

 /* 21*/ADD_VT_INFO_BOX(VT_INFO(UI8),
                        VT_INFO(BYREF_UI8),
                        VT_INFO(ARRAY_UI8),
                        VT_INFO(BYREF_ARRAY_UI8))

 /* 22*/ADD_VT_INFO_BOX(VT_INFO(INT),
                        VT_INFO(BYREF_INT),
                        VT_INFO(ARRAY_INT),
                        VT_INFO(BYREF_ARRAY_INT))

 /* 23*/ADD_VT_INFO_BOX(VT_INFO(UINT),
                        VT_INFO(BYREF_UINT),
                        VT_INFO(ARRAY_UINT),
                        VT_INFO(BYREF_ARRAY_UINT))

 /* 24*/{NULL},                         //VT_VOID

 /* 25*/ADD_VT_INFO_BOX(VT_INFO(HRESULT),
                        VT_INFO(BYREF_HRESULT),
                        VT_INFO(ARRAY_HRESULT),
                        VT_INFO(BYREF_ARRAY_HRESULT))

 /* 26*/{NULL},                           //VT_PTR
 /* 27*/{NULL},                           //VT_SAFEARRAY
 /* 28*/{NULL},                           //VT_CARRAY
 /* 29*/{NULL},                           //VT_USERDEFINED
 /* 30*/{NULL},                           //VT_LPSTR
 /* 31*/{NULL},                           //VT_LPWSTR
 /* 32*/{NULL},
 /* 33*/{NULL},
 /* 34*/{NULL},
 /* 35*/{NULL},
 /* 36*/{NULL},                           //VT_RECORD

 /* 37*/ADD_VT_INFO_BOX(VT_INFO(INT_PTR),
                        VT_INFO(BYREF_INT_PTR),
                        NULL,
                        NULL)

 /* 38*/ADD_VT_INFO_BOX(VT_INFO(UINT_PTR),
                        VT_INFO(BYREF_UINT_PTR),
                        NULL,
                        NULL)

 /* 39*/{NULL},
 /* 40*/{NULL},
 /* 41*/{NULL},
 /* 42*/{NULL},
 /* 43*/{NULL},
 /* 44*/{NULL},
 /* 45*/{NULL},
 /* 46*/{NULL},
 /* 47*/{NULL},
 /* 48*/{NULL},
 /* 49*/{NULL},
 /* 50*/{NULL},
 /* 51*/{NULL},
 /* 52*/{NULL},
 /* 53*/{NULL},
 /* 54*/{NULL},
 /* 55*/{NULL},
 /* 56*/{NULL},
 /* 57*/{NULL},
 /* 58*/{NULL},
 /* 59*/{NULL},
 /* 60*/{NULL},
 /* 61*/{NULL},
 /* 62*/{NULL},
 /* 63*/{NULL},

 /* 64*/ADD_VT_INFO_BOX(VT_INFO(FILETIME),
                        VT_INFO(BYREF_FILETIME),
                        NULL,
                        NULL)

 /* 65*/{NULL},                           //VT_BLOB
 /* 66*/{NULL},                           //VT_STREAM
 /* 67*/{NULL},                           //VT_STORAGE
 /* 68*/{NULL},                           //VT_STREAMED_OBJECT
 /* 69*/{NULL},                           //VT_STORED_OBJECT
 /* 70*/{NULL},                           //VT_BLOB_OBJECT
 /* 71*/{NULL},                           //VT_CF

 /* 72*/ADD_VT_INFO_BOX(VT_INFO(CLSID),
                        VT_INFO(BYREF_CLSID),
                        NULL,
                        NULL)

 /* 73*/{NULL},                           //VT_VERSIONED_STREAM
};//g_VarTypeInfoTable

////////////////////////////////////////////////////////////////////////////////
//check g_VarTypeInfoTable

#ifndef NDEBUG

static void DebugCheck_g_VarTypeInfoTable()
{
 for(size_t i=0;i<_DIM_(g_VarTypeInfoTable);++i)
 {
  if(g_VarTypeInfoTable[i].pSimple!=NULL)
  {
   assert_msg(g_VarTypeInfoTable[i].pSimple->vt==VARTYPE(i),
              "i="<<i);
  }//if

  if(g_VarTypeInfoTable[i].pSimpleByRef!=NULL)
  {
   assert_msg(g_VarTypeInfoTable[i].pSimpleByRef->vt==(VT_BYREF|VARTYPE(i)),
              "i="<<i);
  }//if

  if(g_VarTypeInfoTable[i].pArray!=NULL)
  {
   assert_msg(g_VarTypeInfoTable[i].pArray->vt==(VT_ARRAY|VARTYPE(i)),
              "i="<<i);
  }//if

  if(g_VarTypeInfoTable[i].pArrayByRef!=NULL)
  {
   assert_msg(g_VarTypeInfoTable[i].pArrayByRef->vt==(VT_BYREF|VT_ARRAY|VARTYPE(i)),
              "i="<<i);
  }//if
 }//for
}//DebugCheck_g_VarTypeInfoTable

STARTUP_CODE__DEBUG(DebugCheck_g_VarTypeInfoTable)

#endif //NDEBUG

/////////////////////////////////////////////////////////////////////////////////

const TVariantTypeInfo* GetVariantTypeInfo(VARTYPE vt)
{
 const VARTYPE vt_indicator=VARTYPE(vt&(VT_ARRAY|VT_BYREF));
 const VARTYPE vt_simple   =VARTYPE(vt&~(VT_ARRAY|VT_BYREF));

 if(vt_indicator==(VT_ARRAY|VT_BYREF))
 {
  if(vt_simple<_DIM_(g_VarTypeInfoTable))
   return g_VarTypeInfoTable[vt_simple].pArrayByRef;

  return nullptr;
 }//if ARRAY_BYREF

 if(vt_indicator==VT_BYREF)
 {
  if(vt_simple<_DIM_(g_VarTypeInfoTable))
   return g_VarTypeInfoTable[vt_simple].pSimpleByRef;

  return nullptr;
 }//if BYREF

 if(vt_indicator==VT_ARRAY)
 {
  if(vt_simple<_DIM_(g_VarTypeInfoTable))
   return g_VarTypeInfoTable[vt_simple].pArray;

  return nullptr;
 }//if VT_ARRAY

 if(vt_simple<_DIM_(g_VarTypeInfoTable))
  return g_VarTypeInfoTable[vt_simple].pSimple;

 return nullptr;
}//GetVariantTypeInfo

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
