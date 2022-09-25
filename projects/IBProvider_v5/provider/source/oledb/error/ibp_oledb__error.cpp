////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__err
//! \file    ibp_oledb__error.cpp
//! \brief   COM Object for store the OLEDB Errors
//! \author  Kovalenko Dmitry
//! \date    17.10.2008
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/error/ibp_oledb__error.h"
#include "source/oledb/error/ibp_oledb__error_info.h"
#include "source/oledb/error/ibp_oledb__error_lookup.h"

#include "source/ibp_resources.h"

#include <win32lib/win32_registry.h>
#include <structure/t_str_formatter.h>
#include <structure/t_numeric_cast.h>

namespace lcpi{namespace ibp{namespace oledb{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__Error::tag_item

const ERRORINFO IBP_OLEDB__Error::tag_item::sm_zero_errorinfo={};

const DISPPARAMS IBP_OLEDB__Error::tag_item::sm_zero_dispparams={};

//------------------------------------------------------------------------
IBP_OLEDB__Error::tag_item::tag_item(const ERRORINFO&        ErrorInfo,
                                     DWORD             const dwLookupID,
                                     const VARIANTARG* const pVarArgs,
                                     size_t            const nVarArgs,
                                     const DISPID*     const pArgsIDs,
                                     size_t            const nArgsIDs,
                                     IUnknown*         const pCustomError,
                                     DWORD             const dwDynamicErrorID,
                                     void*             const pvBegin_BuiltInVarArgs,
                                     void*             const pvBegin_BuildInArgsIDs)
 :m_ErrorInfo        (ErrorInfo)
 ,m_dwLookupID       (dwLookupID)
 ,m_spCustomError    (pCustomError)
 ,m_dwDynamicErrorID (dwDynamicErrorID)
 ,m_VarArgs          (reinterpret_cast<ole_lib::TVariant*>(pvBegin_BuiltInVarArgs),
                      reinterpret_cast<ole_lib::TVariant*>(pvBegin_BuiltInVarArgs)+nVarArgs,
                      pVarArgs,
                      pVarArgs+nVarArgs)
 ,m_ArgsIDs          (reinterpret_cast<DISPID*>(pvBegin_BuildInArgsIDs),
                      reinterpret_cast<DISPID*>(pvBegin_BuildInArgsIDs)+nArgsIDs,
                      pArgsIDs,
                      pArgsIDs+nArgsIDs)
{;}

//------------------------------------------------------------------------
IBP_OLEDB__Error::tag_item::~tag_item()
{;}

//------------------------------------------------------------------------
IBP_OLEDB__Error::tag_item::self_ptr
 IBP_OLEDB__Error::tag_item::create(const ERRORINFO*  const pErrorInfo,
                                    DWORD             const dwLookupID,
                                    const DISPPARAMS*       pdispparams,
                                    IUnknown*         const punkCustomError,
                                    DWORD             const dwDynamicErrorID)
{
 if(pdispparams==nullptr)
  pdispparams=&sm_zero_dispparams;

 //-----------------------------------------
 assert(pdispparams!=nullptr);

 //-----------------------------------------
 const size_t base_sz
  =sizeof(self_type);

 //-----------------------------------------
 //! \todo
 //!  Добавить контроль переполнения

 //-----------------------------------------
 const size_t varargs_offset__first
  =base_sz;

 const size_t varargs_offset__last
  =varargs_offset__first+sizeof(item_type::vargs_type::value_type)*(pdispparams->cArgs);

 //-----------------------------------------
 const size_t argsIDs_offset__first
  =varargs_offset__last;

 const size_t argsIDs_offset__last
  =argsIDs_offset__first+sizeof(item_type::args_ids_type::value_type)*(pdispparams->cNamedArgs);

 //-----------------------------------------
 const size_t total_sz
  =argsIDs_offset__last;

 void* const pv=raw_allocator_type::instance.allocate(total_sz);

 try
 {
  new(pv) self_type(pErrorInfo?*pErrorInfo:sm_zero_errorinfo,
                    dwLookupID,
                    pdispparams->rgvarg,
                    pdispparams->cArgs,
                    pdispparams->rgdispidNamedArgs,
                    pdispparams->cNamedArgs,
                    punkCustomError,
                    dwDynamicErrorID,
                    reinterpret_cast<char*>(pv)+varargs_offset__first,
                    reinterpret_cast<char*>(pv)+argsIDs_offset__first);
 }
 catch(...)
 {
  raw_allocator_type::instance.deallocate(pv,total_sz);

  throw;
 }//catch

 /*attention: no any other code!*/

 assert(pv);

 /*attention: no any other code!*/

 return structure::not_null_ptr(reinterpret_cast<self_type*>(pv));
}//create

//------------------------------------------------------------------------
void* IBP_OLEDB__Error::tag_item::operator new (size_t const /*sz*/,void* const pv)
{
 return pv;
}//operator new

//------------------------------------------------------------------------
void IBP_OLEDB__Error::tag_item::operator delete (void* const pv)
{
 raw_allocator_type::instance.deallocate(pv,0);
}//operator delete

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB__Error

OLE_LIB__DEFINE_DEBUG_COM_LIVE(IBP_OLEDB__Error)

//------------------------------------------------------------------------
IBP_OLEDB__Error::IBP_OLEDB__Error(IUnknown* const pUnkOuter)
 :inherited(pUnkOuter)
 ,m_guard() // [2018-12-22] for PVS-Studio
{
 OLE_LIB__CREATE_COMPONENT()
}//IBP_OLEDB__Error

//------------------------------------------------------------------------
IBP_OLEDB__Error::~IBP_OLEDB__Error()
{
 try
 {
  for(items_type::const_iterator i(m_items.begin()),_e(m_items.end());i!=_e;++i)
  {
   this->Helper__ReleaseDynamicErrorData(*i);
  }
 }
 catch(...)
 {;}

 OLE_LIB__DESTROY_COMPONENT()
}//~IBP_OLEDB__Error

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(IBP_OLEDB__Error)
 OLE_LIB__ROOT_STATIC_INTERFACE(IErrorInfo)
 OLE_LIB__ROOT_STATIC_INTERFACE(IErrorRecords)
 OLE_LIB__ROOT_STATIC_INTERFACE(IDBPrimaryError)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IErrorInfo interface ---------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetSource(BSTR* const pbstrSource)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pbstrSource==nullptr)
  return E_INVALIDARG;

 (*pbstrSource)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(!m_items.empty())
  {
   const ULONG ErrIdx
    =m_primary_err_idx.value_or_default(0);

   assert(ErrIdx<m_items.size());
   assert(m_items[ErrIdx]);

   this->Helper__GetErrorDescription
    (m_items[ErrIdx],
     IBP_GetUserDefaultLCID(),
     pbstrSource,
     nullptr);
  }//if
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetSource

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetDescription(BSTR* const pbstrDescription)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pbstrDescription==nullptr)
  return E_INVALIDARG;

 (*pbstrDescription)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(!m_items.empty())
  {
   const ULONG ErrIdx
    =m_primary_err_idx.value_or_default(0);

   assert(ErrIdx<m_items.size());
   assert(m_items[ErrIdx]);

   this->Helper__GetErrorDescription
    (m_items[ErrIdx],
     IBP_GetUserDefaultLCID(),
     nullptr,
     pbstrDescription);
  }//if
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetDescription

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetGUID(GUID* const pguid)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pguid==nullptr)
  return E_INVALIDARG;

 (*pguid)=CLSID_NULL;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(!m_items.empty())
  {
   const ULONG ErrIdx
    =m_primary_err_idx.value_or_default(0);

   assert(ErrIdx<m_items.size());
   assert(m_items[ErrIdx]);

   (*pguid)=m_items[ErrIdx]->m_ErrorInfo.iid;
  }
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetGUID

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetHelpContext(DWORD* const pdwHelpContext)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pdwHelpContext==nullptr)
  return E_INVALIDARG;

 (*pdwHelpContext)=0;

 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(!m_items.empty())
  {
   const ULONG ErrIdx
    =m_primary_err_idx.value_or_default(0);

   assert(ErrIdx<m_items.size());
   assert(m_items[ErrIdx]);

   this->Helper__GetHelpInfo
    (m_items[ErrIdx],
     IBP_GetUserDefaultLCID(),
     nullptr,
     pdwHelpContext);
  }//if
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetHelpContext

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetHelpFile(BSTR* const pbstrHelpFile)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pbstrHelpFile==nullptr)
  return E_INVALIDARG;

 (*pbstrHelpFile)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(!m_items.empty())
  {
   const ULONG ErrIdx
    =m_primary_err_idx.value_or_default(0);

   assert(ErrIdx<m_items.size());
   assert(m_items[ErrIdx]);

   this->Helper__GetHelpInfo
    (m_items[ErrIdx],
     IBP_GetUserDefaultLCID(),
     pbstrHelpFile,
     nullptr);
  }//if
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetHelpFile

//IErrorRecords interface ------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::AddErrorRecord(ERRORINFO*  const pErrorInfo,
                                                   DWORD       const dwLookupID,
                                                   DISPPARAMS* const pdispparams,
                                                   IUnknown*   const punkCustomError,
                                                   DWORD       const dwDynamicErrorID)
{
 OLE_LIB_IMETHOD_PROLOG

 //------
 if(pErrorInfo==nullptr)
  return E_INVALIDARG;

 if(pdispparams!=nullptr)
 {
  if(pdispparams->cArgs!=0 && pdispparams->rgvarg==nullptr)
   return E_INVALIDARG;

  if(pdispparams->cNamedArgs!=0 && pdispparams->rgdispidNamedArgs==nullptr)
   return E_INVALIDARG;
 }//if

 //------
 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  item_type::self_ptr
   spNewItem
    (item_type::create
      (pErrorInfo,
       dwLookupID,
       pdispparams,
       punkCustomError,
       dwDynamicErrorID));

  assert(spNewItem);

  m_items.push_back(__STL_MOVE_VALUE(spNewItem));
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//AddErrorRecord

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetBasicErrorInfo(ULONG      const ulRecordNum,
                                                      ERRORINFO* const pErrorInfo)
{
 OLE_LIB_IMETHOD_PROLOG

 //------
 if(pErrorInfo==nullptr)
  return E_INVALIDARG;

 //------
 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(ulRecordNum>=m_items.size())
  {
   hr=DB_E_BADRECORDNUM;
  }
  else
  {
   assert(m_items[ulRecordNum]);

   (*pErrorInfo)=m_items[ulRecordNum]->m_ErrorInfo;
  }//else
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetBasicErrorInfo

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetCustomErrorObject(ULONG      const ulRecordNum,
                                                         REFIID           riid,
                                                         IUnknown** const ppObject)
{
 OLE_LIB_IMETHOD_PROLOG

 //------
 if(ppObject==nullptr)
  return E_INVALIDARG;

 (*ppObject)=nullptr;

 //------
 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(ulRecordNum>=m_items.size())
  {
   hr=DB_E_BADRECORDNUM;
  }
  else
  {
   assert(m_items[ulRecordNum]);

   hr=m_items[ulRecordNum]->m_spCustomError
       .QueryInterface(riid,reinterpret_cast<void**>(ppObject),S_OK);
  }//else
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetCustomErrorObject

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetErrorInfo(ULONG        const ulRecordNum,
                                                 LCID         const lcid,
                                                 IErrorInfo** const ppErrorInfo)
{
 OLE_LIB_IMETHOD_PROLOG

 if(ppErrorInfo==nullptr)
  return E_INVALIDARG;

 (*ppErrorInfo)=nullptr;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(ulRecordNum>=m_items.size())
  {
   hr=DB_E_BADRECORDNUM;
  }
  else
  {
   IBP_OLEDB__ErrorInfo::self_ptr
    spErrorInfo(IBP_OLEDB__ErrorInfo::CreateInstance(nullptr));

   {
    const HRESULT init_hr=spErrorInfo->Init();

    if(FAILED(init_hr))
     ole_lib::t_base_com_error::throw_error(init_hr);

    assert(init_hr==S_OK);
   }

   //----
   ole_lib::TBSTR bstrSource;
   ole_lib::TBSTR bstrDescription;
   ole_lib::TBSTR bstrHelpFile;
   DWORD dwHelpContext=0;

   assert(m_items[ulRecordNum]);

   this->Helper__GetErrorDescription
          (m_items[ulRecordNum],
           lcid,
           &bstrSource.ref_bstr(),
           &bstrDescription.ref_bstr());

   this->Helper__GetHelpInfo
          (m_items[ulRecordNum],
           lcid,
           &bstrHelpFile.ref_bstr(),
           &dwHelpContext);

   //----
   spErrorInfo->m_wstrSource      =bstrSource.wstr();
   spErrorInfo->m_wstrDescription =bstrDescription.wstr();
   spErrorInfo->m_wstrHelpFile    =bstrHelpFile.wstr();
   spErrorInfo->m_dwHelpContext   =dwHelpContext;
   spErrorInfo->m_guid            =m_items[ulRecordNum]->m_ErrorInfo.iid;

   //----
   spErrorInfo.MoveTo_Fast(ppErrorInfo);

   assert_hint(hr==S_OK);
  }//else
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetErrorInfo

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetErrorParameters(ULONG       const ulRecordNum,
                                                       DISPPARAMS* const pdispparams)
{
 OLE_LIB_IMETHOD_PROLOG

 if(pdispparams==nullptr)
  return E_INVALIDARG;

 CHECK_WRITE_PTR(pdispparams,sizeof(*pdispparams));

 memset(pdispparams,0,sizeof(*pdispparams));

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(ulRecordNum>=m_items.size())
  {
   hr=DB_E_BADRECORDNUM;
  }
  else
  {
   const item_type::self_cptr spItem(m_items[ulRecordNum]);

   assert(spItem);

   //allocate memory -----------------------------------------------------
   CO_MEM_POINTER3(VARIANT)
    spVarArgs(ole_lib::CoTaskMemAllocate2<VARIANT>(spItem->m_VarArgs.size())); //throw

   CO_MEM_POINTER3(DISPID)
    spArgsIDs(ole_lib::CoTaskMemAllocate2<DISPID>(spItem->m_ArgsIDs.size()));//throw

   //fills the out-buffers -----------------------------------------------
   assert_s(sizeof(ole_lib::TVariant)==sizeof(VARIANT));

   structure::t_built_in_array<ole_lib::TVariant>
    VarArgs
     (reinterpret_cast<ole_lib::TVariant*>(spVarArgs.ptr()),
      reinterpret_cast<ole_lib::TVariant*>(spVarArgs.ptr())+spItem->m_VarArgs.size(),
      spItem->m_VarArgs.begin(),
      spItem->m_VarArgs.end());

   structure::copy
    (spItem->m_ArgsIDs.begin(),
     spItem->m_ArgsIDs.end(),
     spArgsIDs.ptr(),
     spArgsIDs.ptr()+spItem->m_ArgsIDs.size());

   //assign out-pointers -------------------------------------------------
   assert(structure::can_numeric_cast(&pdispparams->cArgs,spItem->m_VarArgs.size()));

   structure::static_numeric_cast(&pdispparams->cArgs,spItem->m_VarArgs.size());

   VarArgs.release();//detach built_in_array

   pdispparams->rgvarg=spVarArgs.release();

   //--------
   assert(structure::can_numeric_cast(&pdispparams->cNamedArgs,spItem->m_ArgsIDs.size()));

   structure::static_numeric_cast(&pdispparams->cNamedArgs,spItem->m_ArgsIDs.size());

   pdispparams->rgdispidNamedArgs=spArgsIDs.release();
  }//else
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetErrorParameters

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetRecordCount(ULONG* const pcRecords)
{
 OLE_LIB_IMETHOD_PROLOG

 //------
 if(pcRecords==nullptr)
  return E_INVALIDARG;

 (*pcRecords)=0;

 //------
 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(!structure::can_numeric_cast(pcRecords,m_items.size()))
   hr=DISP_E_OVERFLOW;
  else
   structure::static_numeric_cast(pcRecords,m_items.size());
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//GetRecordCount

//IDBPrimaryError interface ----------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::SetPrimaryError(ULONG const PrimaryErrorIndex)
{
 OLE_LIB_IMETHOD_PROLOG

 //------
 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(m_items.size()<PrimaryErrorIndex)
   hr=DB_E_BADRECORDNUM;
  else
   m_primary_err_idx=PrimaryErrorIndex;
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 return hr;
}//SetPrimaryError

//------------------------------------------------------------------------
HRESULT __stdcall IBP_OLEDB__Error::GetPrimaryError(ULONG* const pPrimaryErrorIndex)
{
 OLE_LIB_IMETHOD_PROLOG

 //------
 if(pPrimaryErrorIndex==nullptr)
  return E_INVALIDARG;

 (*pPrimaryErrorIndex)=0;

 //------
 OLE_LIB__DECLARE_HR(S_OK)

 _OLE_TRY_
 {
  const lock_guard_type lock(m_guard);

  if(m_primary_err_idx.null())
   hr=S_FALSE;
  else
   (*pPrimaryErrorIndex)=m_primary_err_idx.value();
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || hr==S_FALSE || FAILED(hr));

 return hr;
}//GetPrimaryError

//Helper methods ---------------------------------------------------------
void IBP_OLEDB__Error::Helper__GetErrorDescription(const item_type* const pItem,
                                                   LCID             const lcid,
                                                   BSTR*            const pbstrSource,
                                                   BSTR*            const pbstrDescription)
{
 assert(pItem);

 //-----------------------------------------------------------------------
 if(pbstrSource!=nullptr)
  (*pbstrSource)=nullptr;

 if(pbstrDescription!=nullptr)
  (*pbstrDescription)=nullptr;

 if(pbstrSource==nullptr && pbstrDescription==nullptr)
  return;

 //-----------------------------------------------------------------------
 ole_lib::TBSTR tmpSource;
 ole_lib::TBSTR tmpDescription;

 try
 {
  DISPPARAMS dispparams;

  //-------
  assert(structure::can_numeric_cast(&dispparams.cArgs,pItem->m_VarArgs.size()));

  structure::static_numeric_cast(&dispparams.cArgs,pItem->m_VarArgs.size());

  dispparams.rgvarg=const_cast<ole_lib::TVariant*>(pItem->m_VarArgs.data());

  //-------
  assert(structure::can_numeric_cast(&dispparams.cNamedArgs,pItem->m_ArgsIDs.size()));

  structure::static_numeric_cast(&dispparams.cNamedArgs,pItem->m_ArgsIDs.size());

  dispparams.rgdispidNamedArgs=const_cast<DISPID*>(pItem->m_ArgsIDs.data());

  //-------
  const HRESULT hr
   =this
     ->Helper__GetErrorLookup(pItem) //throw
     ->GetErrorDescription
        (pItem->m_ErrorInfo.hrError,
         pItem->m_dwLookupID,
         &dispparams,
         lcid,
         &tmpSource.ref_bstr(),
         &tmpDescription.ref_bstr());

  if(FAILED(hr))
   ole_lib::t_base_com_error::throw_error(hr);
 }
 catch(...)
 {
  tmpSource       =L"#Source is unavailable";                //throw
  tmpDescription  =L"#Error description is unavailable";     //throw
 }//catch

 //-----------------------------------------------------------------------
 if(pbstrSource!=nullptr)
  (*pbstrSource)=tmpSource.Release();

 if(pbstrDescription!=nullptr)
  (*pbstrDescription)=tmpDescription.Release();
}//Helper__GetErrorDescription

//------------------------------------------------------------------------
void IBP_OLEDB__Error::Helper__GetHelpInfo(const item_type* const pItem,
                                           LCID             const lcid,
                                           BSTR*            const pbstrHelpFile,
                                           DWORD*           const pdwHelpContext)
{
 assert(pItem);

 //-----------------------------------------------------------------------
 if(pbstrHelpFile!=nullptr)
  (*pbstrHelpFile)=nullptr;

 if(pdwHelpContext!=nullptr)
  (*pdwHelpContext)=0;

 if(pbstrHelpFile==nullptr && pdwHelpContext==nullptr)
  return;

 //-----------------------------------------------------------------------
 ole_lib::TBSTR tmpHelpFile;
 DWORD          tmpHelpCtx=0;

 try
 {
  const HRESULT hr
   =this
    ->Helper__GetErrorLookup(pItem)
    ->GetHelpInfo
       (pItem->m_ErrorInfo.hrError,
        pItem->m_dwLookupID,
        lcid,
        &tmpHelpFile.ref_bstr(),
        &tmpHelpCtx);

  if(FAILED(hr))
   ole_lib::t_base_com_error::throw_error(hr);

  if(pbstrHelpFile!=nullptr)
   (*pbstrHelpFile)=tmpHelpFile.Release();

  if(pdwHelpContext!=nullptr)
   (*pdwHelpContext)=tmpHelpCtx;
 }
 catch(...)
 {;}
}//Helper__GetHelpInfo

//------------------------------------------------------------------------
void IBP_OLEDB__Error::Helper__ReleaseDynamicErrorData(const item_type* const pItem)
{
 assert(pItem);

 if(pItem->m_dwDynamicErrorID==0)
  return;

 try
 {
  this
   ->Helper__GetErrorLookup(pItem) //throw
   ->ReleaseErrors(pItem->m_dwDynamicErrorID);
 }
 catch(...)
 {;}
}//Helper__ReleaseDynamicErrorData

//------------------------------------------------------------------------
const oledb_lib::IErrorLookupPtr&
 IBP_OLEDB__Error::Helper__GetErrorLookup(const item_type* const pItem)
{
 assert(pItem);

#ifndef NDEBUG
 // [2014-10-18]
 //  Контролируем монопольный вызов данного метода.
 t_ibp_debug__mt_guard_lock __debug_lock(m_err_lookups__debug_guard);
#endif

 {//ишем обработчик ошибки в локальном кэше
  const err_lookup_map_type::const_iterator x(m_err_lookups.find(pItem->m_ErrorInfo.clsid));

  if(x!=m_err_lookups.end())
  {
   assert((*x).second);

   return (*x).second;
  }
 }//local

 //----
 const err_lookup_map_type::value_type
  new_err_info
   (pItem->m_ErrorInfo.clsid,
    this->Helper__CreateErrorLookup(pItem->m_ErrorInfo.clsid));

 assert(new_err_info.second);

 const std::pair<err_lookup_map_type::iterator,bool>
  x(m_err_lookups.insert(new_err_info));

 assert(x.second);

 assert((*(x.first)).second);

 return (*(x.first)).second;
}//Helper__GetErrorLookup

//------------------------------------------------------------------------
oledb_lib::IErrorLookupPtr IBP_OLEDB__Error::Helper__CreateErrorLookup(REFCLSID ProviderClsID)
{
 if(ProviderClsID==_Module.Get_CLSID_IBProvider__private())
  return Helper__CreateErrorLookup_Direct();

 if(const oledb_lib::IErrorLookupPtr x=Helper__CreateErrorLookup_Reg_NoThrow(ProviderClsID))
  return x;

 if(ProviderClsID==_Module.Get_CLSID_IBProvider())
 {
  if(_Module.Get_CLSID_IBProviderErrors()!=CLSID_NULL)
  {
   oledb_lib::IErrorLookupPtr x;

   if(SUCCEEDED(ole_lib::SafeCreateInstance
                  (_Module.Get_CLSID_IBProviderErrors(),
                   nullptr,
                   CLSCTX_INPROC_SERVER,
                   x.iid(),
                   x.ppv())))
   {
    assert(x);

    if(x)
     return x;
   }//if
  }//if

  return Helper__CreateErrorLookup_Direct();
 }//if - this is IBProvider

 ole_lib::t_base_com_error::throw_error(E_FAIL);

#if(COMP_BUILD_UNUSED_CODE)
 return nullptr;
#endif
}//Helper__CreateErrorLookup

//------------------------------------------------------------------------
oledb_lib::IErrorLookupPtr IBP_OLEDB__Error::Helper__CreateErrorLookup_Reg_NoThrow(REFCLSID ProviderClsID)
{
 oledb_lib::IErrorLookupPtr spErrLookup;

 try
 {
  spErrLookup=Helper__CreateErrorLookup_Reg(ProviderClsID); //throw
 }
 catch(...)
 {;}

 return spErrLookup;
}//Helper__CreateErrorLookup_Reg_NoThrow

//------------------------------------------------------------------------
oledb_lib::IErrorLookupPtr IBP_OLEDB__Error::Helper__CreateErrorLookup_Reg(REFCLSID ProviderClsID)
{
 //поиск в реестре сведений об обработчике ошибок
 structure::t_basic_str_formatter<win32lib::t_char> fpath(_T("CLSID\\%1\\ExtendedErrors"));

 fpath<<ole_lib::guid_to_wstring(ProviderClsID);

 win32lib::TRegistry Reg(HKEY_CLASSES_ROOT);

 //KEY_ENUMERATE_SUB_KEYS недостаточно [Vista x64]
 if(Reg.OpenKeyEx(fpath.c_str(),KEY_READ,false)!=NOERROR)
  ole_lib::t_base_com_error::throw_error(E_FAIL);

 win32lib::TRegistry::TRegKeyInfo RegKeyInfo;

 if(Reg.GetKeyInfo(RegKeyInfo)!=NOERROR)
  ole_lib::t_base_com_error::throw_error(E_FAIL);

 if(RegKeyInfo.NumSubKeys!=1)
  ole_lib::t_base_com_error::throw_error(E_FAIL);

 if(RegKeyInfo.MaxSubKeyLen==structure::get_numeric_limits(RegKeyInfo.MaxSubKeyLen).max_value())
  ole_lib::t_base_com_error::throw_error(E_FAIL);

 structure::t_typed_simple_buffer<win32lib::t_char,IBP_MemoryAllocator>
  name_buf(RegKeyInfo.MaxSubKeyLen+1);

 DWORD len=static_cast<DWORD>(name_buf.size());

 if(::RegEnumKeyEx(Reg.CurrentKey,0,name_buf.buffer(),&len,0,0,0,0)!=NOERROR)
  ole_lib::t_base_com_error::throw_error(E_FAIL);

 assert(len<name_buf.size());

 if(!(len<name_buf.size()))
  ole_lib::t_base_com_error::throw_error(E_FAIL);

 //на всякий случай установим терминальный ноль
 name_buf[len]=0;

 oledb_lib::IErrorLookupPtr spErrorLookup;

 if(SUCCEEDED(ole_lib::SafeCreateInstance
               (name_buf.buffer(),
                nullptr,
                CLSCTX_INPROC_SERVER,
                spErrorLookup.iid(),
                spErrorLookup.ppv())))
 {
  assert(spErrorLookup);

  if(spErrorLookup)
   return spErrorLookup;
 }//if

 ole_lib::t_base_com_error::throw_error(E_FAIL);
}//Helper__CreateErrorLookup_Reg

//------------------------------------------------------------------------
oledb_lib::IErrorLookupPtr IBP_OLEDB__Error::Helper__CreateErrorLookup_Direct()
{
 const ole_lib::IPtr2<IBP_OLEDB__ErrorLookup>
  x(structure::not_null_ptr(new IBP_OLEDB__ErrorLookup(nullptr)));

 if(FAILED(x->Init()))
  ole_lib::t_base_com_error::throw_error(E_FAIL);

 return structure::not_null_ptr(x.ptr());
}//Helper__CreateErrorLookup_Direct

////////////////////////////////////////////////////////////////////////////////
}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
