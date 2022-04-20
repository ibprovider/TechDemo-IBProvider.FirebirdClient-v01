////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//containings

class  TClassInstanceCreator;
class  TClassFactory;

class  TBaseClassFactoryData;
class  TClassFactoryData;
class  TAggregationClassFactoryData;

////////////////////////////////////////////////////////////////////////////////
//typedefs

typedef structure::t_smart_object_ptr<TBaseClassFactoryData>  TBaseClassFactoryDataPtr;

////////////////////////////////////////////////////////////////////////////////
//class TClassInstanceCreator

class COMP_CONF_DECLSPEC_NOVTABLE TClassInstanceCreator:public structure::t_smart_interface
{
 public:
  //interface ------------------------------------------------------------
  virtual HRESULT CreateInstance(IUnknown*       pUnkOuter,
                                 TBaseUnknown2** ppObject)=0;//throw
};//class TClassInstanceCreator

////////////////////////////////////////////////////////////////////////////////
//class TClassFactory - class factory for component based on TBaseUnknown2

//for EXE-server call private constructor of TBaseUnknown2 without
// increment component count
class TClassFactory:public IClassFactory
                   ,public TBaseUnknown2_WithFreeThreadMarshaler
{
 private:
  typedef TClassFactory                                 self_type;
  typedef TBaseUnknown2_WithFreeThreadMarshaler         inherited;

  TClassFactory(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TClassFactory();

 public:
  TClassFactory(TClassInstanceCreator* pData);

  //IUnknown interface ---------------------------------------------------
  OLE_LIB__DECLARE_IUNKNOWN

  //Root interface -------------------------------------------------------
  OLE_LIB__DECLARE_ROOT_INTERFACE

  //IClassFactory interface ----------------------------------------------
  virtual HRESULT __stdcall CreateInstance(IUnknown* pUnkOuter,
                                           REFIID    riid,
                                           void**    ppv) COMP_W000004_OVERRIDE_FINAL;

  virtual HRESULT __stdcall LockServer(BOOL flock) COMP_W000004_OVERRIDE_FINAL;

 private:
  typedef structure::t_smart_object_ptr<TClassInstanceCreator> creator_ptr;

 private:
  const creator_ptr m_spCreator;

 private:
  OLE_LIB__DECLARE_DEBUG_COM_LIVE(TClassFactory)
};//class TClassFactory

////////////////////////////////////////////////////////////////////////////////
//class TBaseClassFactoryData - base class for class factory data

class TBaseClassFactoryData
 :public structure::t_basic_smart_interface_impl__dynamic<TClassInstanceCreator,
                                                          TComObjectMemoryAllocator>
{
 private:
  typedef TBaseClassFactoryData                       self_type;

  TBaseClassFactoryData(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>    self_ptr;

 public://----------------------------------------------------------------
  const CLSID m_clsid;

  explicit TBaseClassFactoryData(REFCLSID clsid);

 protected:
  virtual ~TBaseClassFactoryData();

 public:
  //create class factory
  HRESULT CreateClassObject(REFIID riid,
                            void** ppv);//throw
};//class TBaseClassFactoryData

////////////////////////////////////////////////////////////////////////////////
//class TClassFactoryData

class TClassFactoryData:public TBaseClassFactoryData
{
 private:
  typedef TClassFactoryData                           self_type;
  typedef TBaseClassFactoryData                       inherited;

  TClassFactoryData(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TClassFactoryData();

 public: //typedefs ------------------------------------------------------
  typedef HRESULT (*FPCREATEINSTANCE)(TBaseUnknown2** ppObject);

 public:
  TClassFactoryData(REFCLSID         clsid,
                    FPCREATEINSTANCE fpCreateInstance);

  //TBaseClassFactoryData interface --------------------------------------
  virtual HRESULT CreateInstance(IUnknown*       pUnkOuter,
                                 TBaseUnknown2** ppObject) COMP_W000004_OVERRIDE_FINAL;

 private:
  const FPCREATEINSTANCE m_fpCreateInstance;
};//class TClassFactoryData

////////////////////////////////////////////////////////////////////////////////
//class TAggregationClassFactoryData

class TAggregationClassFactoryData:public TBaseClassFactoryData
{
 private:
  typedef TAggregationClassFactoryData                self_type;
  typedef TBaseClassFactoryData                       inherited;

  TAggregationClassFactoryData(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~TAggregationClassFactoryData();

 public: //typedefs ------------------------------------------------------
  typedef HRESULT (*FPCREATEINSTANCE2)(IUnknown*       pUnkOuter,
                                       TBaseUnknown2** ppObject);

 private:
  TAggregationClassFactoryData(REFCLSID          clsid,
                               FPCREATEINSTANCE2 fpCreateInstance);

 public:
  static self_ptr Create(REFCLSID          clsid,
                         FPCREATEINSTANCE2 fpCreateInstance);

  //interface ------------------------------------------------------------
  virtual HRESULT CreateInstance(IUnknown*       pUnkOuter,
                                 TBaseUnknown2** ppObject) COMP_W000004_OVERRIDE_FINAL;

 private:
  const FPCREATEINSTANCE2 m_fpCreateInstance;
};//class TAggregationClassFactoryData

////////////////////////////////////////////////////////////////////////////////