////////////////////////////////////////////////////////////////////////////////
//! \ingroup oledb_lib
//! \file    oledb_variant_array.cc
//! \brief   Implementation of basic_dbvariant methods for work with array
//! \author  Kovalenko Dmitry
//! \date    06.08.2001.
#ifndef _oledb_xvariant_array_CC_
#define _oledb_xvariant_array_CC_

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//template class basic_dbvariant - implementation of methods for working with array

template<class Allocator>
HRESULT basic_dbvariant<Allocator>::CreateArray_HR(DBTYPE    const             wElementType,
                                                   size_t    const             ElementLength,
                                                   REFIID                      ElementIID,
                                                   size_t    const             cDim,
                                                   const SAFEARRAYBOUND* const rgsaBound)
{
 const IID copyElementIID=ElementIID;

 ole_lib::TBaseSafeArray sa;

 HRESULT const hr
  =DBVariant_CreateArray
    (wElementType,
     ElementLength,
     cDim,
     rgsaBound,
     &sa.ref_sa());

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);

 //Setup a pointer to array

 this->Clear(); //throw?, can erase ElementIID.

 this->arrayVal2.ptr=sa.Release();

 this->arrayVal2.element_iid=copyElementIID;

 this->wType=DBTYPE(DBTYPE_ARRAY|wElementType);

 return S_OK;
}//CreateArray_HR

//------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::CreateArray_HR(DBTYPE    const             wElementType,
                                                   size_t    const             ElementLength,
                                                   size_t    const             cDim,
                                                   const SAFEARRAYBOUND* const rgsaBound)
{
 IID ElementIID;

 if(OLEDB_EXTRACT_SIMPLE_DBTYPE(wElementType)==DBTYPE_IUNKNOWN)
  ElementIID=IID_IUnknown;
 else
  ElementIID=IID_NULL;

 return this->CreateArray_HR(wElementType,
                             ElementLength,
                             ElementIID,
                             cDim,
                             rgsaBound);
}//CreateArray_HR

//------------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::SetArray_HR(DBTYPE       const wElementType,
                                                REFIID             ElementIID,
                                                LPCSAFEARRAY const lpArray)
{
 assert_msg((wElementType&DBTYPE_ARRAY)==0,"wElementType==0x"<<std::hex<<wElementType);
 assert_msg((wElementType&DBTYPE_BYREF)==0,"wElementType==0x"<<std::hex<<wElementType);

 if((this->wType&DBTYPE_ARRAY)==DBTYPE_ARRAY && this->arrayVal2.ptr==lpArray)
 {
  //self copy
  assert_msg(this->wType==(wElementType|DBTYPE_ARRAY),
             "wType==0x"<<std::hex<<this->wType<<"\n"
             "wElementType==0x"<<std::hex<<wElementType<<"\n");

  assert(this->arrayVal2.element_iid==ElementIID); //really?

  //set new IID
  this->arrayVal2.element_iid=ElementIID;

  return S_OK;
 }//if

 const IID copyElementIID=ElementIID;

 //запрашиваем описание wElementType
 LPCTYPEINFO const lpTypeInfo(this->GetInfo(wElementType));

 if(lpTypeInfo==NULL)
  return E_UNEXPECTED;

 if(lpArray!=NULL &&
    lpTypeInfo->FixedLen() &&
    lpTypeInfo->Size!=LCPI_OS__SafeArrayGetElemsize(const_cast<LPSAFEARRAY>(lpArray)))
 {
  ODS_LEVEL_3("[ERR]: dbvariant::SetArray. Need size="<<lpTypeInfo->Size<<" "
              "Obtained="<<LCPI_OS__SafeArrayGetElemsize(const_cast<LPSAFEARRAY>(lpArray)));

  return E_UNEXPECTED;//bad size of array element
 }

 if(lpArray==NULL)
 {
  this->Clear();

  this->arrayVal2.ptr=NULL;
 }
 else
 {
  ole_lib::TBaseSafeArray CopyArray;

  const HRESULT hr=ole_lib::SafeArray_Copy(const_cast<LPSAFEARRAY>(lpArray),&CopyArray.ref_sa());

  if(FAILED(hr))
   return hr;

  assert(hr==S_OK);

  this->Clear();

  this->arrayVal2.ptr=CopyArray.Release();
 }//else

 this->wType=DBTYPE(DBTYPE_ARRAY|wElementType);

 this->arrayVal2.element_iid=copyElementIID;

 return S_OK;
}//SetArray_HR

//------------------------------------------------------------------------------
template<class Allocator>
HRESULT basic_dbvariant<Allocator>::SetArray_HR(DBTYPE       const wElementType,
                                                LPCSAFEARRAY const lpArray)
{
 IID ElementIID;

 if(OLEDB_EXTRACT_SIMPLE_DBTYPE(wElementType)==DBTYPE_IUNKNOWN)
  ElementIID=IID_IUnknown;
 else
  ElementIID=IID_NULL;

 return this->SetArray_HR(wElementType,
                          ElementIID,
                          lpArray);
}//SetArray_HR

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::CreateArray(DBTYPE                const wElementType,
                                         size_t                const ElementLength,
                                         size_t                const cDim,
                                         const SAFEARRAYBOUND* const rgsaBound)
{
 const HRESULT hr=this->CreateArray_HR(wElementType,ElementLength,cDim,rgsaBound);

 if(FAILED(hr))
  ole_lib::t_base_ole_error::throw_error(hr,"basic_dbvariant::CreateArray");

 assert(hr==S_OK);

 return *this;
}//CreateArray

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetArray(DBTYPE       const wElementType,
                                      REFIID             ElementIID,
                                      LPCSAFEARRAY const lpArray)
{
 const HRESULT hr=this->SetArray_HR(wElementType,ElementIID,lpArray);

 if(FAILED(hr))
  ole_lib::t_base_ole_error::throw_error(hr,"basic_dbvariant::SetArray");

 assert(hr==S_OK);

 return *this;
}//SetArray

//------------------------------------------------------------------------------
template<class Allocator>
basic_dbvariant<Allocator>&
 basic_dbvariant<Allocator>::SetArray(DBTYPE       const wElementType,
                                      LPCSAFEARRAY const lpArray)
{
 const HRESULT hr=this->SetArray_HR(wElementType,lpArray);

 if(FAILED(hr))
  ole_lib::t_base_ole_error::throw_error(hr,"basic_dbvariant::SetArray");

 assert(hr==S_OK);

 return *this;
}//SetArray

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
#endif
