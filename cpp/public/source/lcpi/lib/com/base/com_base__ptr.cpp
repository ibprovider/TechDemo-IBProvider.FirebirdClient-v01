////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#include <_pch_.h>
#pragma hdrstop

#include <lcpi/lib/com/base/com_base__ptr.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//template class IPtr<IUnknown,&IID_IUnknown>

IPtr<IUnknown,&IID_IUnknown>::IPtr()
 :m_hr(E_POINTER)
 ,m_pI(nullptr)
{;}

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::IPtr(const self_type& x)
 :m_hr(x.m_hr)
 ,m_pI(x.m_pI)
{
 assert(&x!=this); //this is my paranoia

 if(m_pI!=nullptr)
  m_pI->AddRef();
}//copy constructor

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::IPtr(self_type&& x)
 :m_hr(x.m_hr)
 ,m_pI(x.m_pI)
{
 assert(&x!=this); //this is my paranoia

 x.m_pI=nullptr;
 x.m_hr=E_POINTER;
}//copy constructor

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::IPtr(std::nullptr_t const x)
 :m_hr(E_POINTER)
 ,m_pI(x)
{
 assert(!m_pI);
}//IPtr nullptr_t

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::IPtr(interface_type* const pI)
 :m_hr(pI?NOERROR:E_POINTER)
 ,m_pI(pI)
{
 if(m_pI)
  m_pI->AddRef();
}//IPtr

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::~IPtr()
{
 this->Release();
}

//------------------------------------------------------------------------
typename IPtr<IUnknown,&IID_IUnknown>::interface_type* IPtr<IUnknown,&IID_IUnknown>::ptr() const
{
 return m_pI;
}//ptr

//------------------------------------------------------------------------
IUnknown* IPtr<IUnknown,&IID_IUnknown>::unk_ptr() const
{
 return m_pI;
}//unk_ptr

//------------------------------------------------------------------------
typename IPtr<IUnknown,&IID_IUnknown>::interface_type* &IPtr<IUnknown,&IID_IUnknown>::ref_ptr()
{
 this->Release();

 assert(m_pI==nullptr);

 return m_pI;
}//ref_ptr

//------------------------------------------------------------------------
IUnknown* &IPtr<IUnknown,&IID_IUnknown>::ref_unk_ptr()
{
 this->Release();

 assert(m_pI==nullptr);

 return m_pI;
}//ref_unk_ptr

//------------------------------------------------------------------------
void** IPtr<IUnknown,&IID_IUnknown>::ppv()
{
 this->Release();

 assert(m_pI==nullptr);

 return reinterpret_cast<void**>(&m_pI);
}//ppv

//------------------------------------------------------------------------
HRESULT IPtr<IUnknown,&IID_IUnknown>::QueryInterface(REFIID riid,void** const ppv,HRESULT null_ptr_hr)const
{
 return QueryComInterface(this->ptr(),riid,ppv,null_ptr_hr);
}//QueryInterface

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::Release()
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
HRESULT IPtr<IUnknown,&IID_IUnknown>::set(interface_type* const pI)
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
IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::operator = (const self_type& ptr)
{
 this->set(ptr.ptr());

 return *this;
}//operator = copy

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::operator = (self_type&& ptr)
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
IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::operator = (interface_type* const ptr)
{
 this->set(ptr);

 return *this;
}

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::operator = (std::nullptr_t const /*x*/)
{
 return this->Release();
}

//------------------------------------------------------------------------
void IPtr<IUnknown,&IID_IUnknown>::swap(self_type& x)
{
 std::swap(m_pI,x.m_pI);
 std::swap(m_hr,x.m_hr);
}//swap

//------------------------------------------------------------------------
void IPtr<IUnknown,&IID_IUnknown>::swap(interface_type* &x)
{
 std::swap(m_pI,x);

 m_hr=(m_pI?S_OK:E_POINTER);
}//swap

//------------------------------------------------------------------------
bool IPtr<IUnknown,&IID_IUnknown>::IsEqualObject(IUnknown* pUnk)const
{
 return IsEqualComObject(static_cast<IUnknown*>(this->ptr()),pUnk);
}//IsEqualObject

//------------------------------------------------------------------------
REFIID IPtr<IUnknown,&IID_IUnknown>::iid()
{
 return IID_IUnknown;
}//iid

//------------------------------------------------------------------------
typename IPtr<IUnknown,&IID_IUnknown>::interface_type* IPtr<IUnknown,&IID_IUnknown>::operator -> () const
{
 assert(m_pI!=nullptr);

 return m_pI;
}// operator ->

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::operator IPtr<IUnknown,&IID_IUnknown>::interface_type* () const
{
 return m_pI;
}

///////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
