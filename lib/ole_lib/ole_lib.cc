////////////////////////////////////////////////////////////////////////////////
//Base library for creating COM-objects
//                                                 Dmitry Kovalenko. 21.11.2019.
#ifndef _ole_lib_CC_
#define _ole_lib_CC_

#include <structure/t_str_formatter.h>
#include <structure/t_locale.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TTypeInfoAccelerator::tag_pname_info

#ifndef OLE_LIB_NO_OLE_AUTO

template<class Allocator>
TTypeInfoAccelerator<Allocator>::tag_pname_info::tag_pname_info()
 :m_DispID(DISPID_UNKNOWN)
{;}

//------------------------------------------------------------------------
template<class Allocator>
TTypeInfoAccelerator<Allocator>::tag_pname_info::tag_pname_info
                                           (const self_type& x)
 :m_Name   (x.m_Name)
 ,m_DispID (x.m_DispID)
{;}

//------------------------------------------------------------------------
template<class Allocator>
TTypeInfoAccelerator<Allocator>::tag_pname_info::~tag_pname_info()
{;}

//------------------------------------------------------------------------
template<class Allocator>
typename TTypeInfoAccelerator<Allocator>::tag_pname_info&
 TTypeInfoAccelerator<Allocator>::tag_pname_info::operator =
                                           (const self_type& x)
{
 m_Name    =x.m_Name;
 m_DispID  =x.m_DispID;

 return *this;
}//operator

////////////////////////////////////////////////////////////////////////////////
//class TTypeInfoAccelerator::tag_pname_info

template<class Allocator>
inline
TTypeInfoAccelerator<Allocator>::tag_pname_info_less::tag_pname_info_less()
{;}

//------------------------------------------------------------------------
template<class Allocator>
inline
bool TTypeInfoAccelerator<Allocator>::tag_pname_info_less::operator ()
                                           (const tag_pname_info& x1,
                                            const tag_pname_info& x2)const
{
 return _wcsicmp(x1.m_Name.c_str(),x2.m_Name.c_str())<0;
}//x1<x2

////////////////////////////////////////////////////////////////////////////////
//class tag_pname_info__eq_name

template<class Allocator>
inline
TTypeInfoAccelerator<Allocator>::tag_pname_info__eq_name::tag_pname_info__eq_name()
{}

//------------------------------------------------------------------------
template<class Allocator>
inline
bool TTypeInfoAccelerator<Allocator>::tag_pname_info__eq_name::operator ()
                                           (const tag_pname_info& x1,
                                            const tag_pname_info& x2)const
{
 return _wcsicmp(x1.m_Name.c_str(),x2.m_Name.c_str())==0;
}//x1==x2

////////////////////////////////////////////////////////////////////////////////
//class TTypeInfoAccelerator

template<class Allocator>
TTypeInfoAccelerator<Allocator>::TTypeInfoAccelerator
                                     (ITypeInfo*            const pTypeInfo,
                                      proc_count_type       const cProcNames,
                                      const name_char_cptr* const ppProcNames,
                                      dispid_cptr           const pDispIDs)
 :m_spTypeInfo   (pTypeInfo)
 ,m_cProcNames   (cProcNames)
 ,m_ppProcNames  (ppProcNames)
 ,m_pProcDispIDs (pDispIDs)
{
 assert(m_spTypeInfo);

 CHECK_READ_TYPED_PTR(m_ppProcNames,m_cProcNames);

 CHECK_READ_TYPED_PTR(m_pProcDispIDs,m_cProcNames);
}//TTypeInfoAccelerator

//------------------------------------------------------------------------
template<class Allocator>
TTypeInfoAccelerator<Allocator>::~TTypeInfoAccelerator()
{;}

//------------------------------------------------------------------------
template<class Allocator>
typename TTypeInfoAccelerator<Allocator>::self_ptr
 TTypeInfoAccelerator<Allocator>::create(ITypeInfo* const pTypeInfo)
{
 //! \todo
 //!  »«Õ»◊“Œ∆»“‹!
 typedef structure::t_char_lower<name_char_type>  lower_op_type;

 const lower_op_type lower_op("C");

 //----------------------------------------- Load Proc Names
 const TTypeInfoAttrPtr spTypeInfoAttr(pTypeInfo);

 assert(spTypeInfoAttr.ptr());

 const_cast<const proc_count_type*>(&spTypeInfoAttr->cFuncs);

 pname_info_vector_type ProcNames(spTypeInfoAttr->cFuncs);

 TBSTR bstrName;

 for(proc_count_type iFunc(0),_cFunc(spTypeInfoAttr->cFuncs);iFunc!=_cFunc;++iFunc)
 {
  const TTypeInfoFuncDescPtr spFuncDesc(pTypeInfo,iFunc);

  assert(spFuncDesc.ptr());

  const HRESULT get_doc_hr=pTypeInfo->GetDocumentation(spFuncDesc->memid,
                                                       &bstrName.ref_bstr(),
                                                       NULL,
                                                       NULL,
                                                       NULL);
  if(FAILED(get_doc_hr))
  {
   t_base_com_error::throw_error(get_doc_hr);
  }

  //----------------------------------------
  tag_pname_info& rProcNameInfo=ProcNames[_cFunc-iFunc-1];

  rProcNameInfo.m_DispID=spFuncDesc->memid;

  bstrName.copy_to(&rProcNameInfo.m_Name);

  //-----
  for(name_string_type::iterator i(rProcNameInfo.m_Name.begin()),
                                _e(rProcNameInfo.m_Name.end());
      i!=_e;
      ++i)
  {
   (*i)=lower_op(*i);
  }//for
 }//for iFunc

 //-----------------------------------------
 std::stable_sort(ProcNames.begin(),
                  ProcNames.end(),
                  tag_pname_info_less());

 //remove duplicate entries
 ProcNames.erase(std::unique(ProcNames.begin(),
                             ProcNames.end(),
                             tag_pname_info__eq_name()),
                 ProcNames.end());

 //-----------------------------------------
 const size_type target_cProcNames=ProcNames.size();

 assert(structure::can_numeric_cast<proc_count_type>(target_cProcNames));

 size_type target_cSymbols=0;

 for(auto pProcName(ProcNames.cbegin()),eProcName(ProcNames.cend());
     pProcName!=eProcName;
     ++pProcName)
 {
  target_cSymbols+=(*pProcName).m_Name.size()+1;
 }//for pProcName

 //-----------------------------------------
 const size_type self_sz=sizeof(self_type);

 const size_type offset_ProcNames
  =structure::align_up(self_sz,sizeof(name_char_cptr));

 const size_type offset_ProcDispIDs
  =structure::align_up(offset_ProcNames+target_cProcNames*sizeof(name_char_cptr),
                       sizeof(dispid_type));

 const size_type offset_Symbols
  =structure::align_up(offset_ProcDispIDs+sizeof(dispid_type)*target_cProcNames,
                       sizeof(name_char_type));

 const size_type total_sz
  =offset_Symbols+sizeof(name_char_type)*target_cSymbols;

 //-----------------------------------------
 char* const pvObj=reinterpret_cast<char*>(raw_alloc_type::instance.allocate(total_sz));

 try
 {
  memset(pvObj,0,total_sz);

  //----
  name_char_ptr* const target_ppProcNames
   =reinterpret_cast<name_char_ptr*>(pvObj+offset_ProcNames);

  dispid_ptr const target_pProcDispIDs
   =reinterpret_cast<dispid_ptr>(pvObj+offset_ProcDispIDs);

  name_char_ptr const target_pSymbols
   =reinterpret_cast<name_char_ptr>(pvObj+offset_Symbols);

  //----
 #ifndef NDEBUG
  const name_char_cptr* const target_peProcNames
   =target_ppProcNames+target_cProcNames;

  dispid_cptr const target_eProcDispIDs
   =target_pProcDispIDs+target_cProcNames;
 #endif

  name_char_ptr const target_eSymbols
   =target_pSymbols+target_cSymbols;

  //----
  name_char_ptr* target_ppCurProcName
   =target_ppProcNames;

  dispid_ptr target_pCurProcDispID
   =target_pProcDispIDs;

  name_char_ptr target_pCurSymbol
   =target_pSymbols;

  //----
  for(auto pProcName(ProcNames.cbegin()),eProcName(ProcNames.cend());
      pProcName!=eProcName;
      ++pProcName)
  {
   assert(target_ppCurProcName<target_peProcNames);
   assert(target_pCurProcDispID<target_eProcDispIDs);
   assert(target_pCurSymbol<target_eSymbols);

   //----
   (*target_ppCurProcName)=target_pCurSymbol;

   (*target_pCurProcDispID)=(*pProcName).m_DispID;

   //----
   _VERIFY_EQ(structure::copy((*pProcName).m_Name.begin(),
                              (*pProcName).m_Name.end(),
                              target_pCurSymbol,
                              target_eSymbols).first,
              (*pProcName).m_Name.end());

   //----
   ++target_ppCurProcName;

   ++target_pCurProcDispID;

   target_pCurSymbol+=(*pProcName).m_Name.size()+1;
  }//for pProcName

  assert(target_ppCurProcName==target_peProcNames);
  assert(target_pCurProcDispID==target_eProcDispIDs);
  assert(target_pCurSymbol==target_eSymbols);

  //----
  new(pvObj)self_type(pTypeInfo,
                      static_cast<proc_count_type>(target_cProcNames),
                      const_cast<const name_char_cptr*>(target_ppProcNames),
                      const_cast<dispid_cptr>(target_pProcDispIDs));
 }
 catch(...)
 {
  raw_alloc_type::instance.deallocate(pvObj,0);

  throw;
 }//catch

 return structure::not_null_ptr(reinterpret_cast<self_type*>(pvObj));
}//create

//------------------------------------------------------------------------
template<class Allocator>
RELEASE_CODE(inline)
const typename TTypeInfoAccelerator<Allocator>::ITypeInfoPtr&
 TTypeInfoAccelerator<Allocator>::GetTypeInfo()const
{
 return m_spTypeInfo;
}//GetTypeInfo

//------------------------------------------------------------------------
template<class Allocator>
DISPID TTypeInfoAccelerator<Allocator>::GetIDsOfNames
                                           (name_char_cptr pProcName)const
{
 if(pProcName==NULL)
  pProcName=L"";

 proc_count_type b=0;
 proc_count_type len=m_cProcNames;

 while(len>0)
 {
  proc_count_type const half=static_cast<proc_count_type>(len/2);
  proc_count_type const i   =static_cast<proc_count_type>(b+half);

  assert(b<=i);
  assert(i<m_cProcNames);
  assert(m_ppProcNames[i]!=NULL);

  if(int const x=_wcsicmp(m_ppProcNames[i],pProcName))
  {
   if(x<0)
   {
    b   =static_cast<proc_count_type>(i+1);
    len-=static_cast<proc_count_type>(half+1);
   }
   else
   {
    len=half;
   }
  }
  else
  {
   return m_pProcDispIDs[i];
  }
 }//while

 return DISPID_UNKNOWN;
}//GetIDsOfNames

////////////////////////////////////////////////////////////////////////////////
//class TTypeInfoCacheItem

template<class Allocator>
TTypeInfoCacheItem<Allocator>::TTypeInfoCacheItem
                                           (REFIID          libid,
                                            USHORT    const ver_major,
                                            USHORT    const ver_minor,
                                            ITypeLib* const pTypeLib)
 :m_libid      (libid)
 ,m_ver_major  (ver_major)
 ,m_ver_minor  (ver_minor)
 ,m_spTypeLib  (pTypeLib)
{
 assert(m_spTypeLib);
}

//------------------------------------------------------------------------
template<class Allocator>
TTypeInfoCacheItem<Allocator>::~TTypeInfoCacheItem()
{;}

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TTypeInfoCacheItem<Allocator>::GetTypeInfo
                                           (REFIID            riid,
                                            ITypeInfo** const ppTypeInfo)
{
 assert(ppTypeInfo!=NULL);

 (*ppTypeInfo)=NULL;

 assert(m_spTypeLib);

 const lock_guard_type lock(m_TypeInfoMapGuard);

 {
  const type_info_map::const_iterator x(m_TypeInfoMap.find(riid));

  if(x!=m_TypeInfoMap.end())
  {
   assert((*x).second);

   return (*x).second.CopyTo(ppTypeInfo);
  }//if
 }//local

 //load type information
 const HRESULT hr=m_spTypeLib->GetTypeInfoOfGuid(riid,ppTypeInfo);

 if(FAILED(hr))
  return hr;

 if((*ppTypeInfo)==NULL)
  return E_FAIL;

 //save pointer to type info
 const type_info_map::value_type x(riid,*ppTypeInfo);

 _VERIFY(m_TypeInfoMap.insert(x).second);

 return hr;
}//GetTypeInfo

//------------------------------------------------------------------------
template<class Allocator>
typename TTypeInfoCacheItem<Allocator>::type_info_accel_ptr
 TTypeInfoCacheItem<Allocator>::GetTypeInfoAccel(REFIID riid)
{
 const lock_guard_type lock(m_TypeInfoAccelMapGuard);

 {
  const type_info_accel_map::const_iterator x(m_TypeInfoAccelMap.find(riid));

  if(x!=m_TypeInfoAccelMap.end())
  {
   assert((*x).second);

   return (*x).second;
  }
 }//local

 ITypeInfoPtr spTypeInfo;

 const HRESULT hr=this->GetTypeInfo(riid,&spTypeInfo.ref_ptr());

 if(FAILED(hr))
 {
  structure::str_formatter fmsg("Can't get the type info for iid:%1.\n"
                                "Type library %2 version %3.%4.");

  fmsg<<clsid_to_string(riid)
      <<clsid_to_string(m_libid)
      <<m_ver_major
      <<m_ver_minor;

  t_base_ole_error exc(hr,fmsg.str());

  exc.raise();
 }//if

 assert(spTypeInfo);

 const type_info_accel_ptr spTypeInfoAccel(type_info_accel_type::create(spTypeInfo));

 const type_info_accel_map::value_type x(riid,spTypeInfoAccel);

 _VERIFY(m_TypeInfoAccelMap.insert(x).second);

 return spTypeInfoAccel;
}//GetTypeInfoAccel

////////////////////////////////////////////////////////////////////////////////
//class TTypeInfoCache

template<class Allocator>
TTypeInfoCache<Allocator>::TTypeInfoCache()
{;}

//------------------------------------------------------------------------
template<class Allocator>
TTypeInfoCache<Allocator>::~TTypeInfoCache()
{;}

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TTypeInfoCache<Allocator>::GetTypeLib
                                           (REFIID           LIBID,
                                            WORD       const wVerMajor,
                                            WORD       const wVerMinor,
                                            HINSTANCE  const hResource,
                                            int        const iResID,
                                            ITypeLib** const ppTypeLib)
{
 assert(ppTypeLib!=NULL);

 (*ppTypeLib)=NULL;

 item_ptr spData;

 const HRESULT hr=this->GetData(LIBID,wVerMajor,wVerMinor,hResource,iResID,&spData);

 if(FAILED(hr))
  return hr;

 assert(spData);

 if(!spData)
  return E_FAIL;

 assert(spData->m_spTypeLib);

 return spData->m_spTypeLib.CopyTo(ppTypeLib);
}//GetTypeLib

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TTypeInfoCache<Allocator>::GetTypeInfo
                                           (REFIID            LIBID,
                                            WORD        const wVerMajor,
                                            WORD        const wVerMinor,
                                            HINSTANCE   const hResource,
                                            int         const iResID,
                                            REFIID            riid,
                                            ITypeInfo** const ppTypeInfo)
{
 assert(ppTypeInfo!=NULL);

 (*ppTypeInfo)=NULL;

 item_ptr spData;

 const HRESULT hr=this->GetData(LIBID,wVerMajor,wVerMinor,hResource,iResID,&spData);

 if(FAILED(hr))
  return hr;

 assert(spData);

 if(!spData)
  return E_FAIL;

 return spData->GetTypeInfo(riid,ppTypeInfo);
}//GetTypeInfo

//------------------------------------------------------------------------
template<class Allocator>
typename TTypeInfoCache<Allocator>::type_info_accel_ptr
 TTypeInfoCache<Allocator>::GetTypeInfoAccel
                                           (REFIID          LIBID,
                                            WORD      const wVerMajor,
                                            WORD      const wVerMinor,
                                            HINSTANCE const hResource,
                                            int       const iResID,
                                            REFIID          riid)
{
 item_ptr spData;

 const HRESULT hr=this->GetData(LIBID,wVerMajor,wVerMinor,hResource,iResID,&spData);

 if(FAILED(hr))
 {
  structure::str_formatter fmsg("Can't load type library [guid:%1 ver:%2.%3].");

  fmsg<<clsid_to_string(LIBID)<<wVerMajor<<wVerMinor;

  t_base_ole_error::throw_error(hr,fmsg.c_str());
 }//if

 assert(spData);

 return spData->GetTypeInfoAccel(riid);
}//GetTypeInfoAccel

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TTypeInfoCache<Allocator>::GetData(REFIID          LIBID,
                                           USHORT    const wVerMajor,
                                           USHORT    const wVerMinor,
                                           HINSTANCE const hResource,
                                           int       const iResID,
                                           item_ptr* const pspData)
{
 assert(pspData!=NULL);

 const guard_type::lock_type __lock(m_guard);

 pspData->Release();

 for(auto i(m_items.cbegin()),_e(m_items.cend());i!=_e;++i)
 {
  assert(*i);

  if((*i)->m_libid==LIBID && (*i)->m_ver_major==wVerMajor && (*i)->m_ver_minor==wVerMinor)
  {
   (*pspData)=(*i);

   return S_OK;
  }
 }//for

 //load type library
 ITypeLibPtr spTypeLib;

 const HRESULT hr=ole_lib::CreateTypeLib(LIBID,wVerMajor,wVerMinor,hResource,iResID,&spTypeLib.ref_ptr());

 if(FAILED(hr))
  return hr;

 assert(spTypeLib);

 (*pspData)=structure::not_null_ptr(new item_type(LIBID,wVerMajor,wVerMinor,spTypeLib));

 m_items.push_back(*pspData);

 return hr;
}//GetData

#endif //OLE_LIB_NO_OLE_AUTO

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
