////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//class TClassFactory

OLE_LIB__DEFINE_DEBUG_COM_LIVE(TClassFactory)

//------------------------------------------------------------------------
TClassFactory::TClassFactory(TClassInstanceCreator* const pCreator)
 :
 #ifndef OLE_LIB_OUTPROC_SERVER
  inherited(nullptr),        // increment component count
 #endif
  m_spCreator(structure::not_null_ptr(pCreator))
{
 assert_msg(m_spCreator,"No define class factory data");

 OLE_LIB__CREATE_COMPONENT()
}//TClassFactory

//------------------------------------------------------------------------
TClassFactory::~TClassFactory()
{
 OLE_LIB__DESTROY_COMPONENT()
}//~TClassFactory

//Root interface ---------------------------------------------------------
OLE_LIB__DEFINE_ROOT_INTERFACE(TClassFactory)
 OLE_LIB__ROOT_STATIC_INTERFACE(IClassFactory)
OLE_LIB__END_ROOT_INTERFACE(inherited)

//IClassFactory interface ------------------------------------------------
HRESULT __stdcall TClassFactory::CreateInstance(IUnknown* const pUnkOuter,
                                                REFIID          riid,
                                                void**    const ppv)
{
 OLE_LIB_IMETHOD_PROLOG

 assert(m_spCreator);

 if(ppv==nullptr)
  return E_POINTER;

 (*ppv)=nullptr;

 //Aggregate only if the requested IID is IID_IUnknown.
 if(pUnkOuter!=nullptr && riid!=IID_IUnknown)
  return CLASS_E_NOAGGREGATION;

 OLE_LIB__DECLARE_HR(S_OK);

 _OLE_TRY_
 {
  //Create the component.
  INondelegatingPtr2<TBaseUnknown2> spObject;

  //NondelegatingAddRef() call in CreateInstance
  hr=m_spCreator->CreateInstance(pUnkOuter,&spObject.ref_ptr());//throw

  assert(hr==S_OK || FAILED(hr));

  if(SUCCEEDED(hr))
  {
   //[2015-01-08]
   assert(spObject);

   if(!spObject)
   {
    hr=E_OUTOFMEMORY;
   }
   else
   {
    hr=spObject->Init(); //throw - Initialize the component.

    assert(hr==S_OK || FAILED(hr));

    if(SUCCEEDED(hr))    //Get the requested interface.
     hr=spObject->NondelegatingQueryInterface(riid, ppv);

    assert(hr==S_OK || FAILED(hr));
   }//else
  }//if
 }
 _OLE_CATCHES2_CODE_

 assert(hr==S_OK || FAILED(hr));

 assert(((bool)(SUCCEEDED(hr)))==((*ppv)!=nullptr));

 return hr;
}//CreateInstance

//------------------------------------------------------------------------
HRESULT __stdcall TClassFactory::LockServer(BOOL const flock)
{
 OLE_LIB_IMETHOD_PROLOG

 if(flock)
  _Module.Lock();
 else
  _Module.Unlock();

 return S_OK;
}//LockServer

////////////////////////////////////////////////////////////////////////////////
//class TBaseClassFactoryData

TBaseClassFactoryData::TBaseClassFactoryData(REFCLSID clsid)
 :m_clsid(clsid)
{;}

//------------------------------------------------------------------------
TBaseClassFactoryData::~TBaseClassFactoryData()
{;}

//------------------------------------------------------------------------
HRESULT TBaseClassFactoryData::CreateClassObject(REFIID       riid,
                                                 void** const ppv)
{
 return TBaseUnknown2::FullCreate(new TClassFactory(this),riid,ppv);
}//CreateClassObject

////////////////////////////////////////////////////////////////////////////////
//class TClassFactoryData

TClassFactoryData::TClassFactoryData(REFCLSID               clsid,
                                     FPCREATEINSTANCE const fpCreateInstance)
 :inherited(clsid)
 ,m_fpCreateInstance(fpCreateInstance)
{;}

//------------------------------------------------------------------------
TClassFactoryData::~TClassFactoryData()
{;}

//------------------------------------------------------------------------
HRESULT TClassFactoryData::CreateInstance(IUnknown*       const pUnkOuter,
                                          TBaseUnknown2** const ppObject)
{
 assert(m_fpCreateInstance!=nullptr);

 return pUnkOuter?CLASS_E_NOAGGREGATION:m_fpCreateInstance(ppObject);
}//CreateInstance

////////////////////////////////////////////////////////////////////////////////
//class TAggregationClassFactoryData

TAggregationClassFactoryData::TAggregationClassFactoryData
                                           (REFCLSID                clsid,
                                            FPCREATEINSTANCE2 const fpCreateInstance)
 :inherited(clsid)
 ,m_fpCreateInstance(fpCreateInstance)
{;}

//------------------------------------------------------------------------
TAggregationClassFactoryData::~TAggregationClassFactoryData()
{;}

//------------------------------------------------------------------------
TAggregationClassFactoryData::self_ptr
 TAggregationClassFactoryData::Create(REFCLSID                clsid,
                                      FPCREATEINSTANCE2 const fpCreateInstance)
{
 return structure::not_null_ptr
         (new self_type
           (clsid,
            fpCreateInstance));
}//Create

//------------------------------------------------------------------------
HRESULT TAggregationClassFactoryData::CreateInstance(IUnknown*       const pUnkOuter,
                                                     TBaseUnknown2** const ppObject)
{
 assert(m_fpCreateInstance!=nullptr);

 return m_fpCreateInstance(pUnkOuter,ppObject);
}//CreateInstance

////////////////////////////////////////////////////////////////////////////////
