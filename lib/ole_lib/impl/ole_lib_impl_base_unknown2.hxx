////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                  Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2 - base class for implementing IUnknown

class TBaseUnknown2:public INondelegatingUnknown
{
 private:
  typedef TBaseUnknown2                                  self_type;
  typedef void                                           inherited;

  TBaseUnknown2(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  typedef lcpi::lib::structure::cnt_ref_traits           cnt_ref_traits;
  typedef cnt_ref_traits::cnt_ref_type                   cnt_ref_type;

 private: //--------------------------------------------------------------
#ifdef OLE_LIB_OUTPROC_SERVER
  const bool m_IsClassFactory;

  TBaseUnknown2();        //constructor of EXE-class factory

  friend TClassFactory;   //do not call of _Module.Lock/Unlock
#endif

 public:
  explicit TBaseUnknown2(IUnknown* pUnknownOuter); //call _Module.Lock/Unlock

  virtual ~TBaseUnknown2();

  // INondelegatingUnknown interface ------------------------------------
  virtual HRESULT __stdcall NondelegatingQueryInterface(REFIID,void**)COMP_W000004_OVERRIDE;

  virtual ULONG   __stdcall NondelegatingAddRef()COMP_W000004_OVERRIDE;

  virtual ULONG   __stdcall NondelegatingRelease()COMP_W000004_OVERRIDE;

  // Initialization (especially for aggregates)
  virtual HRESULT Init();

  // Get component ID. Used in error processing infrastructure
  virtual REFCLSID GetComponentClassID()const;

 protected:
  // Notification to derived classes that we are releasing
  virtual void FinalRelease();

 public: //---------------------------------------------------------------
  IUnknown* NonDelegating()
  {
   return reinterpret_cast<IUnknown*>(static_cast<INondelegatingUnknown*>(this));
  }//NonDelegating

  cnt_ref_type GetCntRef()const
  {
   return m_cntRef;
  }//GetCntRef

  // Support for delegation ----------------------------------------------
  IUnknown* GetOuterUnknown()const
  {
   return m_pUnknownOuter;
  }//GetOuterUnknown

  HRESULT __stdcall OuterUnknown__QueryInterface(REFIID riid,void** ppv);

  ULONG   __stdcall OuterUnknown__AddRef();

  ULONG   __stdcall OuterUnknown__Release();

  bool IsAggregated()const
  {
   return m_pUnknownOuter!=reinterpret_cast<const IUnknown*>(static_cast<const INondelegatingUnknown*>(this));
  }//IsAggregated

 public: //Helper static function ----------------------------------------
  static HRESULT FinishCreate(TBaseUnknown2*  pCreateObj,
                              TBaseUnknown2** ppObject);

  static HRESULT FullCreate(TBaseUnknown2* const pCreateObj,
                            REFIID               riid,
                            void**         const ppv,
                            HRESULT        const errAggregation=CLASS_E_NOAGGREGATION);//throw

  static HRESULT FinishQI(IUnknown* pI,void** ppv);

  static HRESULT FinishQI_Static(IUnknown* pI,void** ppv);

#if defined(_DEBUG_COM_LIVE_) && (_DEBUG_COM_LIVE_>0)
  static unsigned __int64 DebugComLive__GenInstanceID()
  {
   return ::InterlockedIncrement(&sm_debug_com_live___genInstanceID);
  }//DebugComLive__GenInstanceID
#endif

 protected:
  bool BaseUnknown__IsSupportedInterface(REFIID riid);

 public: //---------------------------------------------------------------
  static void* operator new(size_t sz)
  {
   return ComObjectAllocMemory(sz);
  }

  static void operator delete (void* pv)
  {
   return ComObjectFreeMemory(pv);
  }

 private: //--------------------------------------------------------------
  IUnknown* const m_pUnknownOuter; //Pointer to (external) outer IUnknown

  cnt_ref_type m_cntRef; //Reference count for this object

 private:
#ifndef NDEBUG
  cnt_ref_type m_cntInterfaceRef;

  bool m_COM_OBJECT_IS_DESTROY;
#endif

 private:
#if defined(_DEBUG_COM_LIVE_) && (_DEBUG_COM_LIVE_>0)
  static unsigned __int64 sm_debug_com_live___genInstanceID; //Generator of object ID
#endif
};//class TBaseUnknown2

typedef INondelegatingPtr2<TBaseUnknown2>   TBaseUnknown2NPtr;

/////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2

inline HRESULT TBaseUnknown2::FinishQI(IUnknown* const pI,void** const ppv)
{
 if(ppv==NULL)
  return E_POINTER;

 (*ppv)=pI;

 if(pI==NULL)
 {
  ODS_LEVEL_3("FINISH2 QI pI==NULL !!");

  return E_OUTOFMEMORY;
 }//if

 pI->AddRef();

 return S_OK;
}//FinishQI

//------------------------------------------------------------------------
inline HRESULT TBaseUnknown2::FinishQI_Static(IUnknown* const pI,void** const ppv)
{
 assert(pI!=NULL);

 if(ppv==NULL)
  return E_POINTER;

 (*ppv)=pI;

 pI->AddRef();

 return S_OK;
}//FinishQI_Static

//------------------------------------------------------------------------
inline bool TBaseUnknown2::BaseUnknown__IsSupportedInterface(REFIID riid)
{
 if(riid==IID_IUnknown)
  return true;

 return false;
}//BaseUnknown__IsSupportedInterface

////////////////////////////////////////////////////////////////////////////////
