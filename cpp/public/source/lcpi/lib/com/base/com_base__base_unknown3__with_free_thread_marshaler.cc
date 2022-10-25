////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++
//                                                 Dmitry Kovalenko. 17.10.2022.
#ifndef _cpp_public_lcpi_lib_com_base__base_unknown3__with_free_thread_marshaler_CC_
#define _cpp_public_lcpi_lib_com_base__base_unknown3__with_free_thread_marshaler_CC_

#include <lcpi/lib/com/base/com_base__ptr.h>

#include <lcpi/infrastructure/os/windows-ole32.h>

namespace lcpi{namespace lib{namespace com{namespace base{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown3_WithFreeThreadMarshaler

template<class tagBaseUnknown>
template<class ...TARGS>
TBaseUnknown3_WithFreeThreadMarshaler<tagBaseUnknown>::TBaseUnknown3_WithFreeThreadMarshaler
                                            (TARGS&& ... args)
 :inherited(std::forward<TARGS>(args)...)
 ,m_pFreeThreadMarshaller(nullptr)
{
}

//------------------------------------------------------------------------
template<class tagBaseUnknown>
TBaseUnknown3_WithFreeThreadMarshaler<tagBaseUnknown>::~TBaseUnknown3_WithFreeThreadMarshaler()
{
 com::base::ReleaseComInterface(m_pFreeThreadMarshaller);
}//~TBaseUnknown3_WithFreeThreadMarshaler

//Root interface ---------------------------------------------------------
template<class tagBaseUnknown>
OLE_LIB__DEFINE_ROOT_INTERFACE(TBaseUnknown3_WithFreeThreadMarshaler<tagBaseUnknown>)
 if(riid==IID_IMarshal)
 {
  OLE_LIB_TRACE_QUERY_INTERFACE("iid=IMarshal [uses a STD Free Thread Marshaler]");

  if(m_pFreeThreadMarshaller==nullptr)
  {
   const HRESULT create_hr=this->Helper__Create_IMarshal(); //MT-SAFE, NO-THROW

   if(FAILED(create_hr))
    return create_hr;

   assert(create_hr==S_OK);
  }//if

  assert(m_pFreeThreadMarshaller!=nullptr);

  return m_pFreeThreadMarshaller->QueryInterface(riid,ppv);
 }//if riid==IID_IMarshal
OLE_LIB__END_ROOT_INTERFACE(inherited)

//------------------------------------------------------------------------
template<class tagBaseUnknown>
bool TBaseUnknown3_WithFreeThreadMarshaler<tagBaseUnknown>::BaseUnknown__IsSupportedInterface(REFIID riid)const
{
 if(riid==IID_IMarshal)
  return true;

 return inherited::BaseUnknown__IsSupportedInterface(riid);
}//BaseUnknown__IsSupportedInterface

//helper methods ---------------------------------------------------------
template<class tagBaseUnknown>
HRESULT TBaseUnknown3_WithFreeThreadMarshaler<tagBaseUnknown>::Helper__Create_IMarshal()
{
 IUnknown* pUnk(nullptr);

 const HRESULT hr
  =LCPI_OS__CoCreateFreeThreadedMarshaler
    (this->GetOuterUnknown(),
     &pUnk);

 if(FAILED(hr))
 {
  ODS_LEVEL_3("ERROR: Can't create free thread marshaler hr=0x"<<std::hex<<hr);
  return hr;
 }//if

 assert(hr==S_OK);

 if(pUnk==nullptr)
 {
  ODS_LEVEL_3("ERROR: CoCreateFreeThreadedMarshaler return NULL pointer");
  return E_NOINTERFACE;
 }//if

 assert(pUnk);

 const void* const pPrevPtr=
  lib::structure::mt::interlocked::compare_exchange
   (&m_pFreeThreadMarshaller,
    pUnk,
    nullptr);

 if(pPrevPtr!=nullptr)
 {
  assert(m_pFreeThreadMarshaller);

  assert(m_pFreeThreadMarshaller!=pUnk);

  com::base::ReleaseComInterface(pUnk);
 }
#ifndef NDEBUG
 else
 {
  assert_hint(pPrevPtr==nullptr);

  assert(m_pFreeThreadMarshaller==pUnk);
 }//else
#endif

 assert(pPrevPtr==nullptr);
 assert(m_pFreeThreadMarshaller!=nullptr);

 return S_OK;
}//Helper__Create_IMarshal

////////////////////////////////////////////////////////////////////////////////
}/*nms base*/}/*nms com*/}/*nms lib*/}/*nms lcpi*/
#endif
