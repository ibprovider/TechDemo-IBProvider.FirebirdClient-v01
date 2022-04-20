////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                  Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2

#if defined(_DEBUG_COM_LIVE_) && (_DEBUG_COM_LIVE_>0)

//Generator of object ID
unsigned __int64 TBaseUnknown2::sm_debug_com_live___genInstanceID=0;

#endif

//------------------------------------------------------------------------
#if defined(_MSC_VER)
# pragma warning (push)
# pragma warning (disable:4355)
#endif

//------------------------------------------------------------------------
#ifdef OLE_LIB_OUTPROC_SERVER
TBaseUnknown2::TBaseUnknown2()    //constructor for EXE class factory
 :m_cntRef(0)
 ,m_IsClassFactory(true)
 ,m_pUnknownOuter(this->NonDelegating())
{
 DEBUG_CODE(m_cntInterfaceRef=0;)
 DEBUG_CODE(m_COM_OBJECT_IS_DESTROY=false;)
}
#endif //def OLE_LIB_OUTPROC_SERVER

//------------------------------------------------------------------------
TBaseUnknown2::TBaseUnknown2(IUnknown* const pUnknownOuter)
 :m_cntRef(0)
 #ifdef OLE_LIB_OUTPROC_SERVER
 ,m_IsClassFactory(false)
 #endif
 ,m_pUnknownOuter(pUnknownOuter?pUnknownOuter:this->NonDelegating())
{
 DEBUG_CODE(m_cntInterfaceRef=0;)
 DEBUG_CODE(m_COM_OBJECT_IS_DESTROY=false;)

 _Module.Lock();
}//TBaseUnknown2

//------------------------------------------------------------------------
#if defined(_MSC_VER)
# pragma warning (pop)
#endif

//------------------------------------------------------------------------
TBaseUnknown2::~TBaseUnknown2()
{
 assert(!m_COM_OBJECT_IS_DESTROY);

 DEBUG_CODE(m_COM_OBJECT_IS_DESTROY=true;)

#ifdef OLE_LIB_OUTPROC_SERVER
 if(!m_IsClassFactory)
#endif
 {
  _Module.Unlock();
 }

 assert_msg(m_cntInterfaceRef==0,
             "m_cntInterfaceRef=="<<m_cntInterfaceRef<<"\n"
             "this=0x"<<std::hex<<this);
}//~TBaseUnknown2

//INondelegatingUnknown interface ----------------------------------------
HRESULT __stdcall TBaseUnknown2::NondelegatingQueryInterface(REFIID       riid,
                                                             void** const ppv)
{
 OLE_LIB_IMETHOD_PROLOG

 assert(!m_COM_OBJECT_IS_DESTROY);

 if(ppv==NULL)
  return E_POINTER;

 (*ppv)=NULL;

 // TBaseUnknown2 supports only IUnknown.
 if(riid==IID_IUnknown)
 {
  OLE_LIB_TRACE_QUERY_INTERFACE("iid="<<structure::tstr_to_str(TestIID(riid)))

  return self_type::FinishQI_Static(this->NonDelegating(),ppv);
 }//if riid==IID_IUnknown

 OLE_LIB_TRACE_QUERY_INTERFACE_FAIL("iid="<<structure::tstr_to_str(TestIID(riid)))

 return E_NOINTERFACE;
}//NondelegatingQueryInterface

//------------------------------------------------------------------------
ULONG __stdcall TBaseUnknown2::NondelegatingAddRef()
{
 OLE_LIB_IMETHOD_PROLOG

 assert(!m_COM_OBJECT_IS_DESTROY);

 cnt_ref_traits::increment(&m_cntRef);

 return 1;
}//NondelegatingAddRef

//------------------------------------------------------------------------
ULONG __stdcall TBaseUnknown2::NondelegatingRelease()
{
 OLE_LIB_IMETHOD_PROLOG

 assert(!m_COM_OBJECT_IS_DESTROY);

 assert(m_cntRef>0);

 if(cnt_ref_traits::decrement(&m_cntRef))
  return 1;

 //Stopping of lifetime management through reference counter.
 _VERIFY_EQ(InterlockedExchange(&m_cntRef,1),0);

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
HRESULT TBaseUnknown2::Init()
{
 return S_OK;
}//Init

//------------------------------------------------------------------------
REFCLSID TBaseUnknown2::GetComponentClassID()const
{
 return CLSID_NULL;
}//GetComponentClassID

//------------------------------------------------------------------------
//FinalRelease - called by Release before it deletes the component

void TBaseUnknown2::FinalRelease()
{
}//FinalRelease

//Helper methods ---------------------------------------------------------
HRESULT __stdcall TBaseUnknown2::OuterUnknown__QueryInterface(REFIID       iid,
                                                              void** const ppv)
{
 return this->GetOuterUnknown()->QueryInterface(iid,ppv);
}//OuterUnknown__QueryInterface

//------------------------------------------------------------------------
ULONG __stdcall TBaseUnknown2::OuterUnknown__AddRef()
{
#ifndef NDEBUG
 cnt_ref_traits::increment(&m_cntInterfaceRef);
#endif

 return this->GetOuterUnknown()->AddRef();
}//OuterUnknown__AddRef

//------------------------------------------------------------------------
ULONG __stdcall TBaseUnknown2::OuterUnknown__Release()
{
 assert(m_cntInterfaceRef>0);

#ifndef NDEBUG
 cnt_ref_traits::decrement(&m_cntInterfaceRef);
#endif

 return this->GetOuterUnknown()->Release();
}//OuterUnknown__Release

//Helper methods ---------------------------------------------------------

//used in class-factory static function

HRESULT TBaseUnknown2::FinishCreate(TBaseUnknown2*  const pCreateObj,
                                    TBaseUnknown2** const ppObject)
{
 assert(ppObject!=NULL);

 (*ppObject)=pCreateObj;

 if(pCreateObj==NULL)
  return E_OUTOFMEMORY;

 pCreateObj->NondelegatingAddRef();

 return NOERROR;
}//FullCreate

//------------------------------------------------------------------------
//full creating of COM object

HRESULT TBaseUnknown2::FullCreate(TBaseUnknown2* const pCreateObj,
                                  REFIID               riid,
                                  void**         const ppv,
                                  HRESULT        const errAggregation)
{
 assert(ppv!=NULL);

 if(ppv!=NULL)
  (*ppv)=NULL;

 if(!pCreateObj)
  return E_OUTOFMEMORY;

 INondelegatingPtr2<TBaseUnknown2> const spCreateObj(pCreateObj);

 assert(spCreateObj);

 if(ppv==NULL)
  return E_POINTER;

 if(spCreateObj->IsAggregated() && riid!=IID_IUnknown)
  return errAggregation;

 const HRESULT hr=spCreateObj->Init();//throw

 if(FAILED(hr))
  return hr;

 return spCreateObj->NondelegatingQueryInterface(riid,ppv);
}//FullCreate

////////////////////////////////////////////////////////////////////////////////
