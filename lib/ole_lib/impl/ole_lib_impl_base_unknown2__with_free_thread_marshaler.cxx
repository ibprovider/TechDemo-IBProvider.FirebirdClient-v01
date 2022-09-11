////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 25.06.2009.

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2_WithFreeThreadMarshaler

TBaseUnknown2_WithFreeThreadMarshaler::TBaseUnknown2_WithFreeThreadMarshaler
                                            (IUnknown* const pUnkOuter)
 :inherited(pUnkOuter)
 ,m_pFreeThreadMarshaller(NULL)
{
}

//------------------------------------------------------------------------
TBaseUnknown2_WithFreeThreadMarshaler::~TBaseUnknown2_WithFreeThreadMarshaler()
{
 ole_lib::ReleaseComInterface(m_pFreeThreadMarshaller);
}//~TBaseUnknown2_WithFreeThreadMarshaler

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(TBaseUnknown2_WithFreeThreadMarshaler)
 if(riid==IID_IMarshal)
 {
  OLE_LIB_TRACE_QUERY_INTERFACE("iid=IMarshal [uses a STD Free Thread Marshaler]");

  if(m_pFreeThreadMarshaller==NULL)
  {
   const HRESULT create_hr=this->Helper__Create_IMarshal(); //MT-SAFE, NO-THROW

   if(FAILED(create_hr))
    return create_hr;

   assert(create_hr==S_OK);
  }//if

  assert(m_pFreeThreadMarshaller!=NULL);

  return m_pFreeThreadMarshaller->QueryInterface(riid,ppv);
 }//if riid==IID_IMarshal
OLE_LIB__END_ROOT_INTERFACE(inherited)

//------------------------------------------------------------------------
bool TBaseUnknown2_WithFreeThreadMarshaler::BaseUnknown__IsSupportedInterface(REFIID riid)
{
 if(riid==IID_IMarshal)
  return true;

 return inherited::BaseUnknown__IsSupportedInterface(riid);
}//BaseUnknown__IsSupportedInterface

//helper methods ---------------------------------------------------------
HRESULT TBaseUnknown2_WithFreeThreadMarshaler::Helper__Create_IMarshal()
{
 IUnknown* pUnk(NULL);

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

 if(pUnk==NULL)
 {
  ODS_LEVEL_3("ERROR: CoCreateFreeThreadedMarshaler return NULL pointer");
  return E_NOINTERFACE;
 }//if

 assert(pUnk);

 const void* const pPrevPtr=
  InterlockedCompareExchangePointer
   (reinterpret_cast<void**>(&m_pFreeThreadMarshaller),
    pUnk,
    NULL);

 if(pPrevPtr!=NULL)
 {
  assert(m_pFreeThreadMarshaller);

  assert(m_pFreeThreadMarshaller!=pUnk);

  ole_lib::ReleaseComInterface(pUnk);
 }
#ifndef NDEBUG
 else
 {
  assert_hint(pPrevPtr==NULL);

  assert(m_pFreeThreadMarshaller==pUnk);
 }//else
#endif

 assert(pPrevPtr==NULL);
 assert(m_pFreeThreadMarshaller!=NULL);

 return S_OK;
}//Helper__Create_IMarshal

////////////////////////////////////////////////////////////////////////////////
