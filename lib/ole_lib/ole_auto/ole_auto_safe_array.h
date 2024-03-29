////////////////////////////////////////////////////////////////////////////////
//! \ingroup ole_lib
//! \file    ole_auto_safe_array.h
//! \brief   Wrappers for work with SAFEARRAY structure
//! \author  Kovalenko Dmitry
//! \date    14.12.2007
#ifndef _ole_auto_safe_array_H_
#define _ole_auto_safe_array_H_

#include <lcpi/lib/.config.h>

#include <lcpi/infrastructure/os/windows-oleaut32.h>

#include <vector>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//content

class TSafeArrayAutoUnAccessData;
class TSafeArrayBound;
class TSafeArrayAccessor;
class TBaseSafeArray;
class TSafeArray;

template<class T,VARTYPE VT>
 class TemplateSafeArray;

////////////////////////////////////////////////////////////////////////////////
//class TSafeArrayAutoUnAccessData

class TSafeArrayAutoUnAccessData LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TSafeArrayAutoUnAccessData;

  TSafeArrayAutoUnAccessData(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  explicit TSafeArrayAutoUnAccessData(SAFEARRAY* lpsa);

 ~TSafeArrayAutoUnAccessData();

  HRESULT UnAccess();

 private:
  SAFEARRAY* m_lpsa;
};//class TSafeArrayAutoUnAccessData

////////////////////////////////////////////////////////////////////////////////
//class TSafeArrayBound

class TSafeArrayBound LCPI_CPP_CFG__CLASS__FINAL
 :public SAFEARRAYBOUND
{
 public:
  TSafeArrayBound()
   {
    this->lLbound   =0;
    this->cElements =0;
   }

  TSafeArrayBound(LONG const Lower,ULONG const Count)
   {
    this->lLbound   =Lower;
    this->cElements =Count;
   }

  LONG  lower() const {return this->lLbound;}
  LONG  upper() const {return this->lLbound+this->cElements-1;}
  ULONG count() const {return this->cElements;}
};//class TSafeArrayBound

////////////////////////////////////////////////////////////////////////////////
//class TSafeArrayAccessor - блокировщик SAFEARRAY для доступа к данным

class TSafeArrayAccessor LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=TSafeArrayAccessor;

  TSafeArrayAccessor(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  TSafeArrayAccessor(LPSAFEARRAY lpsa,bool throw_error);
 ~TSafeArrayAccessor();

  operator bool () const
  {
   return m_lpsa!=NULL;
  }

  void* Data()const
  {
   assert(m_lpsa!=NULL);
   assert(m_pData!=NULL);
   return m_pData;
  }

  HRESULT ReleaseData();

 private:
  LPSAFEARRAY m_lpsa; //NULL если не удалось заблокировать SAFEARRAY
  void*       m_pData;//указатель на начало массива
};//class TSafeArrayAccessor

////////////////////////////////////////////////////////////////////////////////
//class TBaseSafeArray

class TBaseSafeArray
{
 private:
  using self_type=TBaseSafeArray;

  TBaseSafeArray(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using LPSAFEARRAY  =SAFEARRAY*;
  using LPCSAFEARRAY =const SAFEARRAY*;

 public:
  TBaseSafeArray();
 ~TBaseSafeArray();

 public:
  operator LPSAFEARRAY ();

  operator LPCSAFEARRAY ()const;

 public:
  LPSAFEARRAY sa();

  LPCSAFEARRAY sa()const;

 public:
  HRESULT Destroy();

  LPSAFEARRAY Release();

  LPSAFEARRAY& ref_sa(bool destroy=true);

 protected:
  LPSAFEARRAY m_psa;
};//class TBaseSafeArray

////////////////////////////////////////////////////////////////////////////////
//class TSafeArray

class TSafeArray:public TBaseSafeArray
{
 private:
  using self_type=TSafeArray;

  TSafeArray(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  TSafeArray();

  TSafeArray(VARTYPE vt,LONG lower,ULONG count);// throw(bad_alloc)

  TSafeArray(VARTYPE vt,UINT cDim,const SAFEARRAYBOUND* const rgsaBound);// throw(bad_alloc)

 public: //selectors -----------------------------------------------------
  UINT GetDim()const;

  LONG GetLBound(UINT nDim)const;//nDim in [1..N]

  LONG GetUBound(UINT nDim)const;//nDim in [1..N]

 public: //modificators --------------------------------------------------
  //создание вектора с нижним индексом lower и числом элементов count
  void Create(VARTYPE vt,LONG lower,ULONG count);// throw(bad_alloc);

  void Create(VARTYPE vt,UINT cDim,const SAFEARRAYBOUND* const rgsaBound);// throw(bad_alloc);

 protected:
  DEBUG_CODE(void CheckIndex(const LONG* pIndices,LPCSTR lpComment);)

  void GetElement(const LONG* pIndices,void*       data);// throw(bad_alloc);
  void PutElement(const LONG* pIndices,const void* data);// throw(bad_alloc);
};//class TSafeArray

////////////////////////////////////////////////////////////////////////////////
//template class TemplateSafeArray - шаблон для работы с SAFEARRAY

template<class T,VARTYPE VT>
class TemplateSafeArray:private TSafeArray
{
 private:
  using self_type=TemplateSafeArray<T,VT>;
  using inherited=TSafeArray;

  TemplateSafeArray(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  using LPSAFEARRAY=SAFEARRAY*;
  using LPCSAFEARRAY=const SAFEARRAY*;

 public:
  using inherited::GetDim;
  using inherited::GetLBound;
  using inherited::GetUBound;

  using inherited::ref_sa;
  using inherited::sa;

 public:
  TemplateSafeArray();

  explicit TemplateSafeArray(ULONG count); //throw(bad_alloc)

  TemplateSafeArray(LONG lower,ULONG count); //throw(bad_alloc)

  TemplateSafeArray(UINT cDim,const SAFEARRAYBOUND* const rgsaBound); //throw(bad_alloc)

 public:
  void Create(ULONG count);//throw
  void Create(LONG lower,ULONG count); //throw(bad_alloc);
  void Create(UINT cDim,const SAFEARRAYBOUND* const rgsaBound); //throw(bad_alloc);

  using inherited::Destroy;

  using inherited::Release;

 public:
  operator LPSAFEARRAY ();

  operator LPCSAFEARRAY ()const;

 public:
  //work with single-dimensions array
  void Get(LONG i1,T* data);
  void Put(LONG i1,const T* data);

  //work with multi-dimensions array
  void GetN(size_t cPoints,const LONG* pPoints,T* data);
  void PutN(size_t cPoints,const LONG* pPoints,const T* data);

  void GetN(const std::vector<LONG>& x,T* data);

  void PutN(const std::vector<LONG>& x,const T* data);
};//template class TemplateSafeArray

using TVariantSafeArray=TemplateSafeArray<VARIANT,VT_VARIANT>;

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/ole_auto/ole_auto_safe_array.cc>
////////////////////////////////////////////////////////////////////////////////
#endif
