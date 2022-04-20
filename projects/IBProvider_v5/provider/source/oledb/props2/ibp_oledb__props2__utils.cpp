////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__utils.cpp
//! \brief   ¬спомогательные утилиты
//! \author  Kovalenko Dmitry
//! \date    14.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/ibp_oledb__props2__utils.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Utils

#ifndef NDEBUG

void IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(const IBP_OLEDB_Props2__DescrDataRange& DescrDataRange)
{
 assert(DescrDataRange.first<DescrDataRange.last);

 IBP_OLEDB_Props2__DescrData::tag_ref_less less_op;

 for(auto x=DescrDataRange.first,prevX=x;x!=DescrDataRange.last;prevX=x,++x)
 {
  assert(x);

  if(x==DescrDataRange.first)
   continue;

  assert_msg
   ((*prevX).m_PropId<(*x).m_PropId,
    "descr2: "<<structure::tstr_to_str((*x).m_PropDescr));

  assert_msg
   (less_op((*prevX).m_PropId,*x),
    "descr2: "<<structure::tstr_to_str((*x).m_PropDescr));

  assert_msg
   (less_op(*prevX,*x),
    "descr2: "<<structure::tstr_to_str((*x).m_PropDescr));

  assert_msg
   (!less_op(*x,(*prevX).m_PropId),
    "descr2: "<<structure::tstr_to_str((*x).m_PropDescr));

  assert_msg
   (!less_op(*x,*prevX),
    "descr2: "<<structure::tstr_to_str((*x).m_PropDescr));
 }//for x

 //-----------------------------------------
 for(auto x=DescrDataRange.first;x!=DescrDataRange.last;++x)
 {
  if(x->m_Default.typeID!=IBP_OLEDB_Props2__DescrData::DefaultValueTypeID__wstr)
   continue;

  assert(x->m_PropVarType==VT_BSTR);

  assert_msg
   (x->m_Default.value.valWStr!=nullptr,
    "descr: "<<structure::tstr_to_str((*x).m_PropDescr));

  //try to detect the length of string
  assert(wcslen(x->m_Default.value.valWStr)>0);
 }//for x
}//DEBUG__CheckOrder - REF

#endif // !NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

void IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(const IBP_OLEDB_Props2__DescrDataPtrRange& DescrDataPtrRange)
{
 assert(DescrDataPtrRange.first<DescrDataPtrRange.last);

 IBP_OLEDB_Props2__DescrData::tag_ref_less less_op;

 for(auto x=DescrDataPtrRange.first,prevX=x;x!=DescrDataPtrRange.last;prevX=x,++x)
 {
  assert(x);
  assert(*x);

  if(x==DescrDataPtrRange.first)
   continue;

  assert_msg
   ((**prevX).m_PropId<(**x).m_PropId,
    "descr2: "<<structure::tstr_to_str((**x).m_PropDescr));

  assert_msg
   (less_op((**prevX).m_PropId,**x),
    "descr2: "<<structure::tstr_to_str((**x).m_PropDescr));

  assert_msg
   (less_op(**prevX,**x),
    "descr2: "<<structure::tstr_to_str((**x).m_PropDescr));

  assert_msg
   (!less_op(**x,(**prevX).m_PropId),
    "descr2: "<<structure::tstr_to_str((**x).m_PropDescr));

  assert_msg
   (!less_op(**x,**prevX),
    "descr2: "<<structure::tstr_to_str((**x).m_PropDescr));
 }//for x

 //-----------------------------------------
 for(auto x=DescrDataPtrRange.first;x!=DescrDataPtrRange.last;++x)
 {
  assert(x);
  assert(*x);

  if((**x).m_Default.typeID!=IBP_OLEDB_Props2__DescrData::DefaultValueTypeID__wstr)
   continue;

  assert((**x).m_PropVarType==VT_BSTR);

  assert_msg
   ((**x).m_Default.value.valWStr!=nullptr,
    "descr: "<<structure::tstr_to_str((**x).m_PropDescr));

  //try to detect the length of string
  assert(wcslen((**x).m_Default.value.valWStr)>0);
 }//for x
}//DEBUG__CheckOrder - PTR

#endif // !NDEBUG

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Utils::Find(const IBP_OLEDB_Props2__DescrDataRange& DescrDataRange,
                               DBPROPID                          const propId)
{
 assert(DescrDataRange.first<DescrDataRange.last);

 if(const auto x=structure::lower_search(DescrDataRange.first,DescrDataRange.last,propId,IBP_OLEDB_Props2__DescrData::tag_ref_less()))
 {
  assert(x.position);
  assert(x.position->m_PropId==propId);;

  return x.position;
 }//if x

 return nullptr;
}//Find - REF

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Utils::Find(const IBP_OLEDB_Props2__DescrDataPtrRange& DescrDataPtrRange,
                               DBPROPID                             const propId)
{
 assert(DescrDataPtrRange.first<DescrDataPtrRange.last);

 if(const auto x=structure::lower_search(DescrDataPtrRange.first,DescrDataPtrRange.last,propId,IBP_OLEDB_Props2__DescrData::tag_ptr_less()))
 {
  assert(x.position);
  assert(*x.position);
  assert((*x.position)->m_PropId==propId);;

  return *x.position;
 }//if x

 return nullptr;
}//Find - PTR

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(const VARIANT& srcVariant,
                                                 VARIANT* const pResult_Variant)
{
 assert(pResult_Variant);

 HRESULT const hr
  =::VariantChangeType
    (pResult_Variant,
     const_cast<VARIANT*>(&srcVariant),
     0,
     VT_BSTR);

 assert(hr==S_OK || FAILED(hr));

 if(hr==E_OUTOFMEMORY)
  throw std::bad_alloc();

 assert(hr!=S_OK || pResult_Variant->vt==VT_BSTR);

 return hr==S_OK;
}//ExtractValue__BSTR

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Utils::ExtractValue__I2(const VARIANT& srcVariant,
                                               VARIANT* const pResult_Variant)
{
 assert(pResult_Variant);

 HRESULT const hr
  =::VariantChangeType
    (pResult_Variant,
     const_cast<VARIANT*>(&srcVariant),
     0,
     VT_I2);

 assert(hr==S_OK || FAILED(hr));

 if(hr==E_OUTOFMEMORY)
  throw std::bad_alloc();

 assert(hr!=S_OK || pResult_Variant->vt==VT_I2);

 return hr==S_OK;
}//ExtractValue__I2

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Utils::ExtractValue__I4(const VARIANT& srcVariant,
                                               VARIANT* const pResult_Variant)
{
 assert(pResult_Variant);

 HRESULT const hr
  =::VariantChangeType
    (pResult_Variant,
     const_cast<VARIANT*>(&srcVariant),
     0,
     VT_I4);

 assert(hr==S_OK || FAILED(hr));

 if(hr==E_OUTOFMEMORY)
  throw std::bad_alloc();

 assert(hr!=S_OK || pResult_Variant->vt==VT_I4);

 return hr==S_OK;
}//ExtractValue__I4

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Utils::TestDbPropSetGuid__IsSessionPropSet(REFGUID rGuid)
{
 //! \note
 //!  ћы используем стандартные средства сравнени€ GUID. Amen.

 if(rGuid==DBPROPSET_SESSION)
  return true;

 if(rGuid==ibprovider::IBP_DBPROPSET_SESSION)
  return true;

 return false;
}//TestDbPropSetGuid__IsSessionPropSet

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Utils::TestDbPropSetGuid__IsDbInitPropSet(REFGUID rGuid)
{
 //! \note
 //!  ћы используем стандартные средства сравнени€ GUID. Amen.

 if(rGuid==DBPROPSET_DBINIT)
  return true;

 if(rGuid==ibprovider::IBP_DBPROPSET_INIT)
  return true;

 return false;
}//TestDbPropSetGuid__IsDbInitPropSet

//Helper methods ---------------------------------------------------------
const wchar_t* IBP_OLEDB_Props2__Utils::GetWmsItem
                                           (const oledb_lib::tagOLEDB_WMS& wms,
                                            size_t                         index)
{
 const wchar_t* p=wms.ptr();

 assert(p);

 DEBUG_CODE(const size_t DEBUG__index_copy=index);

 for(;*p;--index)
 {
  if(index==0)
   return p;

  p+=wcslen(p)+1;
 }//while *p

 assert_msg
  (false,
   "name: "<<structure::tstr_to_str(wms)<<". bad index: "<<DEBUG__index_copy);

 return nullptr;
}//GetWmsItem

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
