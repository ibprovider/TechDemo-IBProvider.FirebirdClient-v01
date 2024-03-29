////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__ptr_CC_
#define _cpp_public_lcpi_lib_com_base__ptr_CC_

#include <utility>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//helper functions

template<class ISource,class IDest>
HRESULT CopyComInterface(ISource* const pISource,IDest** const ppIDest)
{
 assert(ppIDest!=nullptr);
 //assert((*ppIDest)==nullptr); //[2012-09-11] it does not work in real world

 if(ppIDest==nullptr)
  return E_INVALIDARG;

 CopyComInterface2(pISource,*ppIDest);

 return S_OK;
}//CopyComInterface

//------------------------------------------------------------------------
template<class ISource,class IDest>
HRESULT MoveComInterface(ISource* &rpISource,IDest** const ppIDest)
{
 assert(ppIDest!=nullptr);
 //assert((*ppIDest)==nullptr); //[2012-09-11] it does not work in real world
 assert(reinterpret_cast<void**>(ppIDest)!=reinterpret_cast<void**>(&rpISource));

 if(ppIDest==nullptr)
  return E_INVALIDARG;

 MoveComInterface2(rpISource,*ppIDest);

 assert(rpISource==nullptr);

 return S_OK;
}//MoveComInterface

//------------------------------------------------------------------------
template<class ISource,class IDest>
inline
void CopyComInterface2(ISource* const pISource,IDest* &rpIDest)
{
 //assert(rpIDest==nullptr); //[2012-09-11] it does not work in real world

 if(pISource!=nullptr)
  static_cast<IDest*>(pISource)->AddRef();

 rpIDest=static_cast<IDest*>(pISource);
}//CopyComInterface2

//------------------------------------------------------------------------
template<class ISource,class IDest>
inline
void MoveComInterface2(ISource* &rpISource,IDest* &rpIDest)
{
 //assert(rpIDest==nullptr); //[2012-09-11] it does not work in real world
 assert(reinterpret_cast<void**>(&rpIDest)!=reinterpret_cast<void**>(&rpISource));

 rpIDest=rpISource;

 rpISource=nullptr;
}//MoveComInterface2

//------------------------------------------------------------------------
template<class I1,class I2>
bool IsEqualComObject(I1* const p1,I2* const p2)
{
 if(!p1 && !p2)
  return true;

 if(!p1 || !p2)
  return false;

 IUnknownPtr2 spUnk1;
 IUnknownPtr2 spUnk2;

 //� ���������� ������ ��������� ��� � ���...
 LCPI__DEBUG_CODE(HRESULT hr);

 LCPI__DEBUG_CODE(hr=)p1->QueryInterface(IID_IUnknown,reinterpret_cast<void**>(&spUnk1.ref_ptr()));
 assert(hr==S_OK);
 assert(spUnk1);

 LCPI__DEBUG_CODE(hr=)p2->QueryInterface(IID_IUnknown,reinterpret_cast<void**>(&spUnk2.ref_ptr()));
 assert(hr==S_OK);
 assert(spUnk2);

 return spUnk1.ptr()==spUnk2.ptr();
}//IsEqualComObject

//------------------------------------------------------------------------
//������������ � ���������� NULL
template<class I>
void ReleaseComInterface(I* &pI)
{
 if(pI!=nullptr)
 {
  //Such mechanism of release is necessary for the self-locking of the object in memory
  I* const _pI(pI);

  pI=nullptr;

  _pI->Release();
 }
}//ReleaseComInterface

//------------------------------------------------------------------------
template<class T>
HRESULT QueryComInterface(T* const ptr,REFIID riid,void** const ppv,HRESULT const null_ptr_hr=E_FAIL)
{
 if(ppv==nullptr)
  return E_POINTER;

 (*ppv)=nullptr;

 if(ptr)
  return ptr->QueryInterface(riid,ppv);

 return null_ptr_hr/*E_FAIL*/;
}//QueryComInterface

////////////////////////////////////////////////////////////////////////////////
//template class IPtr

template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
IPtr<T,piid>::IPtr()
 :m_hr(E_POINTER)
 ,m_pI(nullptr)
{
}

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
IPtr<T,piid>::IPtr(const self_type& x)
 :m_hr(x.m_hr)
 ,m_pI(x.m_pI)
{
 assert(&x!=this); //this is my paranoia

 if(m_pI!=nullptr)
  m_pI->AddRef();
}//copy constructor

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
IPtr<T,piid>::IPtr(self_type&& x)
 :m_hr(x.m_hr)
 ,m_pI(x.m_pI)
{
 assert(&x!=this); //this is my paranoia

 x.m_pI=nullptr;
 x.m_hr=E_POINTER;
}//copy constructor

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
IPtr<T,piid>::IPtr(std::nullptr_t const x)
 :m_hr(E_POINTER)
 ,m_pI(x)
{
 assert(!m_pI);
}//IPtr nullptr_t

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
IPtr<T,piid>::IPtr(interface_type* const pI)
 :m_hr(pI?NOERROR:E_POINTER)
 ,m_pI(pI)
{
 if(m_pI)
  m_pI->AddRef();
}//IPtr

//------------------------------------------------------------------------
template<class T,const IID* piid>
template<class U>
LCPI__RELEASE_CODE(inline)
IPtr<T,piid>::IPtr(const structure::t_not_null_ptr<U>& nn_ptr)
 :m_hr(NOERROR)
 ,m_pI(nn_ptr.ptr())
{
 assert(m_pI);

 m_pI->AddRef();
}//IPtr nn_ptr

//------------------------------------------------------------------------
template<class T,const IID* piid>
IPtr<T,piid>::IPtr(IUnknown* const pI)
 :m_hr(E_POINTER)
 ,m_pI(nullptr)
{
 if(pI)
 {
  interface_type* pNew(nullptr);

  m_hr=pI->QueryInterface(*piid,reinterpret_cast<void**>(&pNew));

  if(SUCCEEDED(m_hr))
  {
   if(pNew)
    m_pI=pNew;
   else
    m_hr=E_FAIL;
  }//if
 }//if pI
}//IPtr

//------------------------------------------------------------------------
template<class T,const IID* piid>
IPtr<T,piid>::IPtr(const structure::t_not_null_ptr<IUnknown>& nn_ptr)
 :m_hr(E_POINTER)
 ,m_pI(nullptr)
{
 interface_type* pNew(nullptr);

 m_hr=nn_ptr->QueryInterface(*piid,reinterpret_cast<void**>(&pNew));

 if(SUCCEEDED(m_hr))
 {
  if(pNew)
   m_pI=pNew;
  else
   m_hr=E_FAIL;
 }//if
}//IPtr

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline
IPtr<T,piid>::~IPtr()
{
 this->Release();
}

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline
typename IPtr<T,piid>::interface_type* IPtr<T,piid>::ptr() const
{
 return m_pI;
}//ptr

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline
IUnknown* IPtr<T,piid>::unk_ptr() const
{
 return m_pI;
}//unk_ptr

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
typename IPtr<T,piid>::interface_type* &IPtr<T,piid>::ref_ptr()
{
 this->Release();

 assert(m_pI==nullptr);

 return m_pI;
}//ref_ptr

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
IUnknown* &IPtr<T,piid>::ref_unk_ptr()
{
 this->Release();

 assert(m_pI==nullptr);

 return *reinterpret_cast<IUnknown**>(&m_pI);
}//ref_unk_ptr

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
void** IPtr<T,piid>::ppv ()
{
 this->Release();

 assert(m_pI==nullptr);

 return reinterpret_cast<void**>(&m_pI);
}//ppv

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline
HRESULT IPtr<T,piid>::QueryInterface(REFIID riid,void** const ppv,HRESULT null_ptr_hr)const
{
 return QueryComInterface(this->ptr(),riid,ppv,null_ptr_hr);
}//QueryInterface

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
IPtr<T,piid>& IPtr<T,piid>::Release()
{
 m_hr=E_POINTER;

 if(m_pI!=nullptr)
 {
  //Such mechanism of release is necessary for the self-locking of the object in memory
  interface_type* const pOld(m_pI);

  m_pI=nullptr;

  pOld->Release();
 }//if

 return *this;
}//Release

//------------------------------------------------------------------------
template<class T,const IID* piid>
HRESULT IPtr<T,piid>::set(interface_type* const pI)
{
 interface_type* const pOld(m_pI);

 m_pI=pI;

 if(m_pI)
 {
  m_pI->AddRef();

  m_hr=NOERROR;
 }
 else
 {
  m_hr=E_POINTER;
 }//else

 //after release of m_pI we NOT access the m_hr
 const HRESULT hr=m_hr;

 if(pOld)
 {
  pOld->Release();
 }//if

 return hr;
}//set

//------------------------------------------------------------------------
template<class T,const IID* piid>
HRESULT IPtr<T,piid>::set(IUnknown* const pI)
{
 if(!pI)
 {
  this->Release(); //assign m_hr to E_POINTER

  return E_POINTER;
 }//if

 interface_type*       pNew(nullptr);
 interface_type* const pOld(m_pI);

 m_pI=nullptr;

 m_hr=pI->QueryInterface(*piid,reinterpret_cast<void**>(&pNew));

 assert(m_hr==S_OK || FAILED(m_hr));

 if(SUCCEEDED(m_hr))
 {
  if(pNew)
   m_pI=pNew;
  else
   m_hr=E_FAIL;
 }//if

 //After releasing of pOld, we do not touch m_hr
 const HRESULT hr=m_hr;

 if(pOld)
  pOld->Release();

 return hr;
}//set

//------------------------------------------------------------------------
template<class T,const IID* piid>
template<typename U>
HRESULT IPtr<T,piid>::set(const structure::t_not_null_ptr<U>& nn_ptr)
{
 interface_type* const pOld(m_pI);

 m_pI=nn_ptr;

 assert(m_pI);

 m_pI->AddRef();

 m_hr=NOERROR;

 if(pOld)
 {
  pOld->Release();
 }//if

 //after release of m_pI we NOT access the m_hr
 return NOERROR;
}//set nn_ptr

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline IPtr<T,piid>& IPtr<T,piid>::operator = (const self_type& ptr)
{
 this->set(ptr.ptr());

 return *this;
}//operator = copy

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline IPtr<T,piid>& IPtr<T,piid>::operator = (self_type&& ptr)
{
 if(&ptr!=this)
 {
  interface_type* const pOld(m_pI);

  m_pI=ptr.m_pI;
  m_hr=ptr.m_hr;

  ptr.m_pI=nullptr;
  ptr.m_hr=E_POINTER;

  if(pOld!=nullptr)
   pOld->Release();
 }//if &ptr!=this

 return *this;
}//operator = move

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline IPtr<T,piid>& IPtr<T,piid>::operator = (interface_type* const ptr)
{
 this->set(ptr);

 return *this;
}

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline IPtr<T,piid>& IPtr<T,piid>::operator = (IUnknown* const pUnknown)
{
 this->set(pUnknown);

 return *this;
}

//------------------------------------------------------------------------
template<class T,const IID* piid>
template<typename U>
inline IPtr<T,piid>& IPtr<T,piid>::operator = (const structure::t_not_null_ptr<U>& nn_ptr)
{
 this->set(nn_ptr);

 return *this;
}

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline IPtr<T,piid>& IPtr<T,piid>::operator = (std::nullptr_t const /*x*/)
{
 return this->Release();
}

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline void IPtr<T,piid>::swap(self_type& x)
{
 std::swap(m_pI,x.m_pI);
 std::swap(m_hr,x.m_hr);
}//swap

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline void IPtr<T,piid>::swap(interface_type* &x)
{
 std::swap(m_pI,x);

 m_hr=(m_pI?S_OK:E_POINTER);
}//swap

//------------------------------------------------------------------------
template<class T,const IID* piid>
template<class U>
inline HRESULT IPtr<T,piid>::MoveTo(U** const pptr)
{
 const HRESULT hr=MoveComInterface(m_pI,pptr); //no throw

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);
 assert(m_pI==nullptr);

 m_hr=E_POINTER;

 return hr;
}//MoveTo

//------------------------------------------------------------------------
template<class T,const IID* piid>
template<class U>
LCPI__RELEASE_CODE(inline) void IPtr<T,piid>::MoveTo_Fast(U** const pptr)
{
 assert(pptr);
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_pI));

 (*pptr)=m_pI;

 m_pI=nullptr;

 m_hr=E_POINTER;
}//MoveTo_Fast

//------------------------------------------------------------------------
template<class T,const IID* piid>
template<class U>
inline HRESULT IPtr<T,piid>::CopyTo(U** const pptr)const
{
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_pI));

 return CopyComInterface(m_pI,pptr);
}//CopyTo

//------------------------------------------------------------------------
template<class T,const IID* piid>
template<class U>
LCPI__RELEASE_CODE(inline)
void IPtr<T,piid>::CopyTo_Fast(U** const pptr)const
{
 assert(pptr);
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_pI));

 CopyComInterface2(m_pI,*pptr);
}//CopyTo_Fast

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline bool IPtr<T,piid>::IsEqualObject(IUnknown* pUnk)const
{
 return IsEqualComObject(static_cast<IUnknown*>(this->ptr()),pUnk);
}//IsEqualObject

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline REFIID IPtr<T,piid>::iid()
{
 return *piid;
}//iid

//------------------------------------------------------------------------
template<class T,const IID* piid>
LCPI__RELEASE_CODE(inline)
typename IPtr<T,piid>::interface_type* IPtr<T,piid>::operator -> () const
{
 assert(m_pI!=nullptr);

 return m_pI;
}// operator ->

//------------------------------------------------------------------------
template<class T,const IID* piid>
inline IPtr<T,piid>::operator typename IPtr<T,piid>::interface_type* () const
{
 return m_pI;
}

////////////////////////////////////////////////////////////////////////////////
//template class IPtr<IUnknown,&IID_IUnknown>

template<class U>
IPtr<IUnknown,&IID_IUnknown>::IPtr(const structure::t_not_null_ptr<U>& nn_ptr)
 :m_hr(NOERROR)
 ,m_pI(nn_ptr.ptr())
{
 assert(m_pI);

 m_pI->AddRef();
}//IPtr nn_ptr

//------------------------------------------------------------------------
template<typename U>
HRESULT IPtr<IUnknown,&IID_IUnknown>::set(const structure::t_not_null_ptr<U>& nn_ptr)
{
 interface_type* const pOld(m_pI);

 m_pI=nn_ptr;

 assert(m_pI);

 m_pI->AddRef();

 m_hr=NOERROR;

 if(pOld)
 {
  pOld->Release();
 }//if

 //after release of m_pI we NOT access the m_hr
 return NOERROR;
}//set nn_ptr

//------------------------------------------------------------------------
template<typename U>
IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::operator = (const structure::t_not_null_ptr<U>& nn_ptr)
{
 this->set(nn_ptr);

 return *this;
}
//------------------------------------------------------------------------
template<class U>
HRESULT IPtr<IUnknown,&IID_IUnknown>::MoveTo(U** const pptr)
{
 const HRESULT hr=MoveComInterface(m_pI,pptr); //no throw

 if(FAILED(hr))
  return hr;

 assert(hr==S_OK);
 assert(m_pI==nullptr);

 m_hr=E_POINTER;

 return hr;
}//MoveTo

//------------------------------------------------------------------------
template<class U>
void IPtr<IUnknown,&IID_IUnknown>::MoveTo_Fast(U** const pptr)
{
 assert(pptr);
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_pI));

 (*pptr)=m_pI;

 m_pI=nullptr;

 m_hr=E_POINTER;
}//MoveTo_Fast

//------------------------------------------------------------------------
template<class U>
HRESULT IPtr<IUnknown,&IID_IUnknown>::CopyTo(U** const pptr)const
{
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_pI));

 return CopyComInterface(m_pI,pptr);
}//CopyTo

//------------------------------------------------------------------------
template<class U>
void IPtr<IUnknown,&IID_IUnknown>::CopyTo_Fast(U** const pptr)const
{
 assert(pptr);
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_pI));

 return CopyComInterface2(m_pI,*pptr);
}//CopyTo_Fast

////////////////////////////////////////////////////////////////////////////////
//template class IPtr2

template<class T>
LCPI__RELEASE_CODE(inline) IPtr2<T>::IPtr2()
 :m_ptr(nullptr)
{;}

//------------------------------------------------------------------------
template<class T>
LCPI__RELEASE_CODE(inline) IPtr2<T>::IPtr2(const self_type& x)
 :m_ptr(x.m_ptr)
{
 assert(&x!=this); //this is my paranoia

 if(m_ptr)
  m_ptr->AddRef();
}//copy constructor

//------------------------------------------------------------------------
template<class T>
LCPI__RELEASE_CODE(inline) IPtr2<T>::IPtr2(self_type&& x)
 :m_ptr(x.m_ptr)
{
 assert(&x!=this); //this is my paranoia

 x.m_ptr=nullptr;

 assert(!x);
}//move constructor

//------------------------------------------------------------------------
template<class T>
template<class U>
LCPI__RELEASE_CODE(inline) IPtr2<T>::IPtr2(IPtr2<U>&& x)
 :m_ptr(nullptr)
{
 x.MoveTo_Fast(&m_ptr);

 assert(!x);
}//template move constructor

//------------------------------------------------------------------------
template<class T>
LCPI__RELEASE_CODE(inline) IPtr2<T>::IPtr2(interface_type* const ptr)
 :m_ptr(ptr)
{
 if(m_ptr)
  m_ptr->AddRef();
}//IPtr2

//------------------------------------------------------------------------
template<class T>
template<typename U>
LCPI__RELEASE_CODE(inline) IPtr2<T>::IPtr2(const structure::t_not_null_ptr<U>& nn_ptr)
 :m_ptr(nn_ptr)
{
 assert(m_ptr);

 m_ptr->AddRef();
}//IPtr2

//------------------------------------------------------------------------
template<class T>
LCPI__RELEASE_CODE(inline) IPtr2<T>::IPtr2(std::nullptr_t const x)
 :m_ptr(x)
{
 assert(!m_ptr);
}//IPtr2 null_ptr

//------------------------------------------------------------------------
template<class T>
inline IPtr2<T>::~IPtr2()
{
 this->Release();
}//~IPtr2

//------------------------------------------------------------------------
template<class T>
inline
HRESULT IPtr2<T>::QueryInterface(REFIID riid,void** const ppv,HRESULT const null_ptr_hr)const
{
 return QueryComInterface(this->ptr(),riid,ppv,null_ptr_hr/*E_FAIL*/);
}//QueryInterface

//------------------------------------------------------------------------
template<class T>
IPtr2<T>& IPtr2<T>::Release()
{
 if(m_ptr)
 {
  //Such mechanism of release is necessary for the self-locking of the object in memory
  T* const ptr(m_ptr);

  m_ptr=nullptr;

  ptr->Release();
 }//if

 return *this;
}//Release

//------------------------------------------------------------------------
template<class T>
void IPtr2<T>::Terminate()
{
 m_ptr=nullptr;
}//Terminate

//------------------------------------------------------------------------
template<class T>
IPtr2<T>& IPtr2<T>::set(interface_type* const ptr)
{
 if(ptr==m_ptr)
  return *this;

 interface_type* const pOld(m_ptr);

 m_ptr=ptr;

 if(m_ptr)
  m_ptr->AddRef();

 if(pOld)
  pOld->Release();

 return *this;
}//set

//------------------------------------------------------------------------
template<class T>
template<typename U>
IPtr2<T>& IPtr2<T>::set(const structure::t_not_null_ptr<U>& nn_ptr)
{
 if(nn_ptr==m_ptr)
  return *this;

 interface_type* const pOld(m_ptr);

 m_ptr=nn_ptr;

 assert(m_ptr);

 m_ptr->AddRef();

 if(pOld)
  pOld->Release();

 return *this;
}//set

//------------------------------------------------------------------------
template<class T>
inline IPtr2<T>& IPtr2<T>::operator = (const self_type& x)
{
 return this->set(x.ptr());
}//copy operator

//------------------------------------------------------------------------
template<class T>
inline IPtr2<T>& IPtr2<T>::operator = (self_type&& x)
{
 if(&x!=this)
 {
  interface_type* const pOld(m_ptr);

  m_ptr=x.m_ptr;

  x.m_ptr=nullptr;

  assert(!x);

  if(pOld!=nullptr)
   pOld->Release();
 }//if &x!=this

 return *this;
}//move operator

//------------------------------------------------------------------------
template<class T>
template<class U>
inline IPtr2<T>& IPtr2<T>::operator = (IPtr2<U>&& x)
{
 if(reinterpret_cast<void*>(&x)!=reinterpret_cast<void*>(this))
 {
  interface_type* const pOld(m_ptr);

  m_ptr=nullptr;

  x.MoveTo_Fast(&m_ptr);

  assert(!x);

  if(pOld!=nullptr)
   pOld->Release();
 }//if &x!=this
#ifndef NDEBUG
 else
 {
  assert(false); //[2012-09-11] WTF BUG CHECK.
 }
#endif

 return *this;
}//template move operator

//------------------------------------------------------------------------
template<class T>
inline IPtr2<T>& IPtr2<T>::operator = (interface_type* const ptr)
{
 return this->set(ptr);
}//operator = ptr

//------------------------------------------------------------------------
template<class T>
template<class U>
inline IPtr2<T>& IPtr2<T>::operator = (const structure::t_not_null_ptr<U>& nn_ptr)
{
 return this->set(nn_ptr);
}//operator = nn_ptr

//------------------------------------------------------------------------
template<class T>
inline IPtr2<T>& IPtr2<T>::operator = (std::nullptr_t const /*x*/)
{
 return this->Release();
}//operator = null_ptr

//------------------------------------------------------------------------
template<class T>
inline void IPtr2<T>::swap(self_type& x)
{
 std::swap(m_ptr,x.m_ptr);
}//swap

//------------------------------------------------------------------------
template<class T>
template<class U>
inline HRESULT IPtr2<T>::CopyTo(U** const pptr)const
{
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_ptr));

 return CopyComInterface(m_ptr,pptr);
}//CopyTo

//------------------------------------------------------------------------
template<class T>
template<class U>
LCPI__RELEASE_CODE(inline) void IPtr2<T>::CopyTo_Fast(U** const pptr)const
{
 assert(pptr);
 assert(reinterpret_cast<const void* const*>(pptr)!=reinterpret_cast<const void* const*>(&m_ptr));

 CopyComInterface2(m_ptr,*pptr);
}//CopyTo_Fast

//------------------------------------------------------------------------
template<class T>
template<class U>
inline HRESULT IPtr2<T>::MoveTo(U** const pptr)
{
 return MoveComInterface(m_ptr,pptr);
}//MoveTo

//------------------------------------------------------------------------
template<class T>
template<class U>
LCPI__RELEASE_CODE(inline) void IPtr2<T>::MoveTo_Fast(U** const pptr)
{
 assert(pptr);

 MoveComInterface2(m_ptr,*pptr);

 assert(m_ptr==nullptr);
}//MoveTo_Fast

//selectors --------------------------------------------------------------
template<class T>
LCPI__RELEASE_CODE(inline)
typename IPtr2<T>::interface_type* IPtr2<T>::operator -> () const
{
 assert(m_ptr!=nullptr);

 return m_ptr;
}//operator ->

//------------------------------------------------------------------------
template<class T>
inline
IPtr2<T>::operator typename IPtr2<T>::interface_type* () const
{
 return m_ptr;
}

//------------------------------------------------------------------------
template<class T>
inline
typename IPtr2<T>::interface_type* IPtr2<T>::ptr() const
{
 return m_ptr;
}//ptr

//------------------------------------------------------------------------
template<class T>
inline typename IPtr2<T>::interface_type*& IPtr2<T>::ref_ptr()
{
 this->Release();

 return m_ptr;
}//ref_ptr

//------------------------------------------------------------------------
template<class T>
inline IUnknown** IPtr2<T>::ppUnk()
{
 this->Release();

 return reinterpret_cast<IUnknown**>(&m_ptr);
}//ppUnk

//------------------------------------------------------------------------
template<class T>
inline void** IPtr2<T>::ppv()
{
 this->Release();

 return reinterpret_cast<void**>(&m_ptr);
}//ppv

//------------------------------------------------------------------------
template<class T>
inline
structure::t_not_null_ptr<T> IPtr2<T>::not_null_ptr()const
{
 return structure::not_null_ptr(m_ptr);
}//not_null_ptr

//------------------------------------------------------------------------
template<class T>
inline bool IPtr2<T>::IsEqualObject(IUnknown* const pUnk)const
{
 return IsEqualComObject(static_cast<IUnknown*>(m_ptr),pUnk);
}//IsEqualObject

////////////////////////////////////////////////////////////////////////////////
//template class INondelegatingPtr2

template<class T>
inline INondelegatingPtr2<T>::INondelegatingPtr2()
 :m_ptr(nullptr)
{;}

//------------------------------------------------------------------------
template<class T>
inline INondelegatingPtr2<T>::INondelegatingPtr2(interface_type* const ptr)
 :m_ptr(ptr)
{
 if(m_ptr)
  m_ptr->NondelegatingAddRef();
}

//------------------------------------------------------------------------
template<class T>
template<class U>
inline INondelegatingPtr2<T>::INondelegatingPtr2(const structure::t_not_null_ptr<U>& nn_ptr)
 :m_ptr(nn_ptr)
{
 assert(m_ptr);

 m_ptr->NondelegatingAddRef();
}//INondelegatingPtr2

//------------------------------------------------------------------------
template<class T>
inline INondelegatingPtr2<T>::~INondelegatingPtr2()
{
 this->Release();
}

//------------------------------------------------------------------------
template<class T>
INondelegatingPtr2<T>& INondelegatingPtr2<T>::Release()
{
 if(m_ptr)
 {
  interface_type* const ptr(m_ptr);

  m_ptr=nullptr;

  ptr->NondelegatingRelease();
 }

 return *this;
}//Release

//------------------------------------------------------------------------
template<class T>
HRESULT INondelegatingPtr2<T>::set(interface_type* const ptr,bool const init)
{
 assert(m_ptr==nullptr);

 if(ptr==nullptr)
  return E_OUTOFMEMORY;

 (m_ptr=ptr)->NondelegatingAddRef();

 return init?m_ptr->Init():NOERROR;
}//set

//------------------------------------------------------------------------
template<class T>
HRESULT INondelegatingPtr2<T>::get_out(REFIID        riid,
                                       void**  const ppv,
                                       HRESULT const errAggregation)const
{
 assert(FAILED(errAggregation));

 if(ppv==nullptr)
  return E_POINTER;

 (*ppv)=nullptr;

 if(m_ptr==nullptr)
  return E_OUTOFMEMORY;

 if(m_ptr->IsAggregated() && riid!=IID_IUnknown)
  return errAggregation;

 return m_ptr->NondelegatingQueryInterface(riid,ppv);
}//get_out

//------------------------------------------------------------------------
template<class T>
inline HRESULT INondelegatingPtr2<T>::get_out
                                      (REFIID           riid,
                                       IUnknown** const ppUnk,
                                       HRESULT    const errAggregation)const
{
 return this->get_out
         (riid,
          reinterpret_cast<void**>(ppUnk),
          errAggregation);
}//get_out

//------------------------------------------------------------------------
template<class T>
LCPI__RELEASE_CODE(inline)
typename INondelegatingPtr2<T>::interface_type*
 INondelegatingPtr2<T>::operator -> () const
{
 assert(m_ptr!=nullptr);

 return m_ptr;
}//operator ->

//------------------------------------------------------------------------
template<class T>
inline INondelegatingPtr2<T>::operator typename INondelegatingPtr2<T>::interface_type* () const
{
 return m_ptr;
}

//------------------------------------------------------------------------
template<class T>
inline typename INondelegatingPtr2<T>::interface_type* INondelegatingPtr2<T>::ptr() const
{
 return m_ptr;
}//ptr

//------------------------------------------------------------------------
template<class T>
inline typename INondelegatingPtr2<T>::interface_type* &INondelegatingPtr2<T>::ref_ptr()
{
 assert(m_ptr==nullptr);

 return m_ptr;
}//ref_ptr

//------------------------------------------------------------------------
template<class T>
inline HRESULT INondelegatingPtr2<T>::CopyTo(interface_type** const pptr)const
{
 return CopyComInterface(m_ptr,pptr);
}//CopyTo

//------------------------------------------------------------------------
template<class T>
inline void INondelegatingPtr2<T>::swap(self_type& x)
{
 std::swap(m_ptr,x.m_ptr);
}//swap

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif
