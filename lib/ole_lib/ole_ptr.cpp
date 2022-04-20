////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_ptr.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//template class IPtr<IUnknown,&IID_IUnknown>

IPtr<IUnknown,&IID_IUnknown>::IPtr()
 :m_hr(E_POINTER)
 ,m_pI(NULL)
{;}

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::IPtr(const self_type& x)
 :m_hr(x.m_hr)
 ,m_pI(x.m_pI)
{
 assert(&x!=this); //this is my paranoia

 if(m_pI!=NULL)
  m_pI->AddRef();
}//copy constructor

//------------------------------------------------------------------------
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)
IPtr<IUnknown,&IID_IUnknown>::IPtr(self_type&& x)
 :m_hr(x.m_hr)
 ,m_pI(x.m_pI)
{
 assert(&x!=this); //this is my paranoia

 x.m_pI=NULL;
 x.m_hr=E_POINTER;
}//copy constructor
#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

//------------------------------------------------------------------------
#if 0 //2013-01-21
IPtr<IUnknown,&IID_IUnknown>::IPtr(interface_type* const pI,bool const call_AddRef)
 :m_hr(pI?NOERROR:E_POINTER)
 ,m_pI(pI)
{
 if(m_pI && call_AddRef)
  m_pI->AddRef();
}//IPtr
#endif //if 0

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

 assert(m_pI==NULL);

 return m_pI;
}//ref_ptr

//------------------------------------------------------------------------
IUnknown* &IPtr<IUnknown,&IID_IUnknown>::ref_unk_ptr()
{
 this->Release();

 assert(m_pI==NULL);

 return m_pI;
}//ref_unk_ptr

//------------------------------------------------------------------------
void** IPtr<IUnknown,&IID_IUnknown>::ppv()
{
 this->Release();

 assert(m_pI==NULL);

 return reinterpret_cast<void**>(&m_pI);
}//ppv

//------------------------------------------------------------------------
HRESULT IPtr<IUnknown,&IID_IUnknown>::CreateInstance
                                      (str_param_type const ProgID,
                                       IUnknown*      const pUnkOuter,
                                       DWORD          const clsContext)
{
 CLSID clsid;

 if((m_hr=string_to_clsid(ProgID,&clsid))!=S_OK)
  return m_hr;

 return this->CreateInstance(clsid,pUnkOuter,clsContext);
}//CreateInstance - ANSI ProgID

//------------------------------------------------------------------------
HRESULT IPtr<IUnknown,&IID_IUnknown>::CreateInstance
                                      (wstr_param_type const ProgID,
                                       IUnknown*       const pUnkOuter,
                                       DWORD           const clsContext)
{
 CLSID clsid;

 if((m_hr=string_to_clsid(ProgID,&clsid))!=S_OK)
  return m_hr;

 return this->CreateInstance(clsid,pUnkOuter,clsContext);
}//CreateInstance - UNICODE ProgID

//------------------------------------------------------------------------
HRESULT IPtr<IUnknown,&IID_IUnknown>::CreateInstance
                                      (REFCLSID        clsid,
                                       IUnknown* const pUnkOuter,
                                       DWORD     const clsContext)
{
 this->Release();

 interface_type* pI=NULL;

 m_hr=::CoCreateInstance(clsid,pUnkOuter,clsContext,iid(),reinterpret_cast<void**>(&pI));

 if(m_hr!=NOERROR)
  return m_hr;

 if(pI==NULL)
  return m_hr=E_FAIL;

 assert(m_pI==NULL);

 m_pI=pI;

 return m_hr;
}//CreateInstance

//------------------------------------------------------------------------
HRESULT IPtr<IUnknown,&IID_IUnknown>::QueryInterface(REFIID riid,void** const ppv,HRESULT null_ptr_hr)const
{
 return QueryComInterface(this->ptr(),riid,ppv,null_ptr_hr);
}//QueryInterface

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::Release()
{
 m_hr=E_POINTER;

 if(m_pI!=NULL)
 {
  //Such mechanism of release is necessary for the self-locking of the object in memory
  interface_type* const pOld(m_pI);

  m_pI=NULL;

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
#if(COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0)

IPtr<IUnknown,&IID_IUnknown>& IPtr<IUnknown,&IID_IUnknown>::operator = (self_type&& ptr)
{
 if(&ptr!=this)
 {
  interface_type* const pOld(m_pI);

  m_pI=ptr.m_pI;
  m_hr=ptr.m_hr;

  ptr.m_pI=NULL;
  ptr.m_hr=E_POINTER;

  if(pOld!=NULL)
   pOld->Release();
 }//if &ptr!=this

 return *this;
}//operator = move

#endif //COMP_CONF_SUPPORT_RVALUE_REFERENCE!=0

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
 assert(m_pI!=NULL);

 return m_pI;
}// operator ->

//------------------------------------------------------------------------
IPtr<IUnknown,&IID_IUnknown>::operator IPtr<IUnknown,&IID_IUnknown>::interface_type* () const
{
 return m_pI;
}

///////////////////////////////////////////////////////////////////////////////
}/*namespace ole_lib*/
