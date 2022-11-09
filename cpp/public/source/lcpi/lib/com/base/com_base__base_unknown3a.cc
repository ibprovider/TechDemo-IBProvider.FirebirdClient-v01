////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__base_unknown3a_CC_
#define _cpp_public_lcpi_lib_com_base__base_unknown3a_CC_

#include <lcpi/lib/com/base/com_base__ptr.h>
#include <lcpi/lib/com/base/com_base__guid_to_string.h>

#include <lcpi/lib/structure/debug/assert_msg.h>
#include <lcpi/lib/structure/debug/debug_code.h>

#include <lcpi/lib/structure/mt/interlocked.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown3A

#if defined(_MSC_VER)
# pragma warning (push)
# pragma warning (disable:4355)
#endif

//------------------------------------------------------------------------
template<class Allocator>
TBaseUnknown3A<Allocator>::TBaseUnknown3A(IUnknown* const pOuterUnknown)
 :m_pOuterUnknown(pOuterUnknown?pOuterUnknown:this->GetNondelegatingUnknown())
 ,m_NondelegatingCntRef(0)
#ifndef NDEBUG
 ,m_InterfaceCntRef__debug(0)
 ,m_COM_OBJECT_IS_DESTROY(false)
#endif
{
}//TBaseUnknown3A

//------------------------------------------------------------------------
#if defined(_MSC_VER)
# pragma warning (pop)
#endif

//------------------------------------------------------------------------
template<class Allocator>
TBaseUnknown3A<Allocator>::~TBaseUnknown3A()
{
#ifndef NDEBUG
 assert(!m_COM_OBJECT_IS_DESTROY);

 m_COM_OBJECT_IS_DESTROY=true;

 LCPI__assert_msg
  (m_InterfaceCntRef__debug==0,
   "m_cntInterfaceRef=="<<m_InterfaceCntRef__debug<<"\n"
   "this=0x"<<std::hex<<this);
#endif
}//~TBaseUnknown3A

//INondelegatingUnknown interface ----------------------------------------
template<class Allocator>
HRESULT __stdcall TBaseUnknown3A<Allocator>::NondelegatingQueryInterface
                                           (REFIID       riid,
                                            void** const ppv)
{
 OLE_LIB__IMETHOD_PROLOG

 assert(!m_COM_OBJECT_IS_DESTROY);

 if(ppv==nullptr)
  return E_POINTER;

 (*ppv)=nullptr;

 //
 // TBaseUnknown3A supports only IUnknown.
 //
 if(riid==IID_IUnknown)
 {
  OLE_LIB_TRACE_QUERY_INTERFACE("iid="<<guid_to_string(riid))

  return self_type::FinishQI_Static(this->GetNondelegatingUnknown(),ppv);
 }//if riid==IID_IUnknown

 OLE_LIB_TRACE_QUERY_INTERFACE_FAIL("iid="<<guid_to_string(riid))

 return E_NOINTERFACE;
}//NondelegatingQueryInterface

//------------------------------------------------------------------------
template<class Allocator>
ULONG __stdcall TBaseUnknown3A<Allocator>::NondelegatingAddRef()
{
 OLE_LIB__IMETHOD_PROLOG

 assert(!m_COM_OBJECT_IS_DESTROY);

 cnt_ref_traits::increment(&m_NondelegatingCntRef);

 return 1;
}//NondelegatingAddRef

//------------------------------------------------------------------------
template<class Allocator>
ULONG __stdcall TBaseUnknown3A<Allocator>::NondelegatingRelease()
{
 OLE_LIB__IMETHOD_PROLOG

 assert(!m_COM_OBJECT_IS_DESTROY);

 assert(m_NondelegatingCntRef>0);

 if(cnt_ref_traits::decrement(&m_NondelegatingCntRef))
  return 1;

 //Stopping of lifetime management through reference counter.
 LCPI__VERIFY_EQ(structure::mt::interlocked::exchange(&m_NondelegatingCntRef,1),0);

 try
 {
  this->FinalRelease();
 }
 catch(...)
 {
  assert(false);
 }//catch

 try
 {
  delete this;
 }
 catch(...)
 {
  assert(false);
 }//catch

 return 0;
}//NondelegatingRelease

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TBaseUnknown3A<Allocator>::Init()
{
 return S_OK;
}//Init

//------------------------------------------------------------------------
template<class Allocator>
REFCLSID TBaseUnknown3A<Allocator>::GetComponentClassID()const
{
 return CLSID_NULL;
}//GetComponentClassID

//------------------------------------------------------------------------
//FinalRelease - called by Release before it deletes the component

template<class Allocator>
void TBaseUnknown3A<Allocator>::FinalRelease()
{
}//FinalRelease

//------------------------------------------------------------------------
template<class Allocator>
IUnknown* TBaseUnknown3A<Allocator>::GetNondelegatingUnknown()
{
 return reinterpret_cast<IUnknown*>(static_cast<INondelegatingUnknown*>(this));
}//GetNondelegatingUnknown

//------------------------------------------------------------------------
template<class Allocator>
typename TBaseUnknown3A<Allocator>::cnt_ref_type TBaseUnknown3A<Allocator>::GetCntRef()const
{
 return m_NondelegatingCntRef;
}//GetCntRef

//------------------------------------------------------------------------
template<class Allocator>
IUnknown* TBaseUnknown3A<Allocator>::GetOuterUnknown()const
{
 return m_pOuterUnknown;
}//GetOuterUnknown

//------------------------------------------------------------------------
template<class Allocator>
bool TBaseUnknown3A<Allocator>::IsAggregated()const
{
 return m_pOuterUnknown!=reinterpret_cast<const IUnknown*>(static_cast<const INondelegatingUnknown*>(this));
}//IsAggregated

//------------------------------------------------------------------------
template<class Allocator>
void TBaseUnknown3A<Allocator>::SetOuterUnknown(IUnknown* pNewUnkOuter)
{
 assert(pNewUnkOuter);

 assert(this->Debug__GetInterfaceCntRef()==0);

 structure::mt::interlocked::exchange(&m_pOuterUnknown,pNewUnkOuter);
}//SetOuterUnknown

//------------------------------------------------------------------------
template<class Allocator>
void TBaseUnknown3A<Allocator>::ResetOuterUnknown()
{
 this->SetOuterUnknown(this->GetNondelegatingUnknown());
}//SetOuterUnknown

//------------------------------------------------------------------------
#ifndef NDEBUG

template<class Allocator>
typename TBaseUnknown3A<Allocator>::cnt_ref_type
 TBaseUnknown3A<Allocator>::Debug__GetNondelegatingCntRef()const
{
 return m_NondelegatingCntRef;
}//Debug__GetNondelegatingCntRef

#endif

//------------------------------------------------------------------------
#ifndef NDEBUG

template<class Allocator>
typename TBaseUnknown3A<Allocator>::cnt_ref_type
 TBaseUnknown3A<Allocator>::Debug__GetInterfaceCntRef()const
{
 return m_InterfaceCntRef__debug;
}//Debug__GetInterfaceCntRef

#endif

//Helper methods ---------------------------------------------------------
template<class Allocator>
HRESULT __stdcall TBaseUnknown3A<Allocator>::OuterUnknown__QueryInterface
                                           (REFIID       iid,
                                            void** const ppv)
{
 return this->GetOuterUnknown()->QueryInterface(iid,ppv);
}//OuterUnknown__QueryInterface

//------------------------------------------------------------------------
template<class Allocator>
ULONG __stdcall TBaseUnknown3A<Allocator>::OuterUnknown__AddRef()
{
#ifndef NDEBUG
 cnt_ref_traits::increment(&m_InterfaceCntRef__debug);
#endif

 return this->GetOuterUnknown()->AddRef();
}//OuterUnknown__AddRef

//------------------------------------------------------------------------
template<class Allocator>
ULONG __stdcall TBaseUnknown3A<Allocator>::OuterUnknown__Release()
{
 assert(m_InterfaceCntRef__debug>0);

#ifndef NDEBUG
 cnt_ref_traits::decrement(&m_InterfaceCntRef__debug);
#endif

 return this->GetOuterUnknown()->Release();
}//OuterUnknown__Release

//Helper methods ---------------------------------------------------------

template<class Allocator>
template<class tagComponent,class tagBaseUnknown>
HRESULT TBaseUnknown3A<Allocator>::FinishCreate(tagComponent*    const pNewObj,
                                                tagBaseUnknown** const ppObject)
{
 assert(ppObject!=nullptr);

 (*ppObject)=pNewObj;

 if(pNewObj==nullptr)
  return E_OUTOFMEMORY;

 pNewObj->NondelegatingAddRef();

 return NOERROR;
}//FinishCreate

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TBaseUnknown3A<Allocator>::FullCreate
                                           (TBaseUnknown3A* const pNewObj,
                                            REFIID                riid,
                                            void**          const ppv,
                                            HRESULT         const errAggregation)
{
 assert(ppv!=nullptr);

 if(ppv!=nullptr)
  (*ppv)=nullptr;

 if(pNewObj==nullptr)
  return E_OUTOFMEMORY;

 //
 // Capturing a new object.
 //
 INondelegatingPtr2<INondelegatingUnknown> const spNewObj(pNewObj);

 assert(spNewObj);

 if(ppv==nullptr)
  return E_POINTER;

 if(pNewObj->IsAggregated() && riid!=IID_IUnknown)
  return errAggregation;

 const HRESULT init_hr=pNewObj->Init(); //throw

 if(FAILED(init_hr))
  return init_hr;

 return pNewObj->NondelegatingQueryInterface(riid,ppv);
}//FullCreate

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TBaseUnknown3A<Allocator>::FinishQI(IUnknown* const pI,void** const ppv)
{
 if(ppv==nullptr)
  return E_POINTER;

 (*ppv)=pI;

 if(pI==nullptr)
 {
  ODS_LEVEL_3("FINISH2 QI pI==NULL !!");

  return E_OUTOFMEMORY;
 }//if

 pI->AddRef();

 return S_OK;
}//FinishQI

//------------------------------------------------------------------------
template<class Allocator>
HRESULT TBaseUnknown3A<Allocator>::FinishQI_Static(IUnknown* const pI,void** const ppv)
{
 assert(pI!=nullptr);

 if(ppv==nullptr)
  return E_POINTER;

 (*ppv)=pI;

 pI->AddRef();

 return S_OK;
}//FinishQI_Static

//------------------------------------------------------------------------
template<class Allocator>
bool TBaseUnknown3A<Allocator>::BaseUnknown__IsSupportedInterface(REFIID riid)const
{
 if(riid==IID_IUnknown)
  return true;

 return false;
}//BaseUnknown__IsSupportedInterface

//------------------------------------------------------------------------
template<class Allocator>
void* TBaseUnknown3A<Allocator>::operator new(size_t const sz)
{
 return raw_alloc_type::instance.allocate(sz);
}//operator new

//------------------------------------------------------------------------
template<class Allocator>
void TBaseUnknown3A<Allocator>::operator delete (void* const pv)
{
 return raw_alloc_type::instance.deallocate(pv,0);
}//operator delete

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif