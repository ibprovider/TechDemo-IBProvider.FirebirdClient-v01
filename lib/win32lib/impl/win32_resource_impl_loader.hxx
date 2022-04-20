////////////////////////////////////////////////////////////////////////////////
//Win32 Library implementation.
//                                               Dmitry Kovalenko. 05.09.2004.

////////////////////////////////////////////////////////////////////////////////
//containings

class TResourceLoader;

////////////////////////////////////////////////////////////////////////////////
//class TResourceLoader

class TResourceLoader
{
 private:
  typedef TResourceLoader                              self_type;

  TResourceLoader(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef self_type*                                   self_ptr;
  typedef structure::t_lcid                            lcid_type;

 public:
  TResourceLoader()
   :m_hInstance(NULL)
  {;}

  explicit TResourceLoader(HINSTANCE const hInstance)
   :m_hInstance(hInstance)
  {;}

 ~TResourceLoader()
  {;}

  //----------------------------------------------------------------------
  bool Init(HINSTANCE const hInstance)
  {
   m_hInstance=hInstance;

   return true;
  }//Init

  //----------------------------------------------------------------------
  HGLOBAL LoadResourceLangEx(LPCTSTR   const resType,
                             TResID    const resID,
                             DWORD*    const pcbResource,
                             lcid_type const lcid)const
  {
   assert(m_hInstance!=NULL);

   return Resource_LoadByLangEx(m_hInstance,
                                resType,
                                resID,
                                pcbResource,
                                lcid);
  }//LoadResourceLangEx

  //----------------------------------------------------------------------
  HGLOBAL LoadResourceLangEx(LPCTSTR   const resType,
                             TResID    const resID,
                             DWORD*    const pcbResource=NULL)const
  {
   assert(m_hInstance!=NULL);

   return this->LoadResourceLangEx(resType,
                                   resID,
                                   pcbResource,
                                   LOCALE_NEUTRAL);
  }//LoadResourceLangEx

 private:
  HINSTANCE m_hInstance;
};//class TResourceLoader

////////////////////////////////////////////////////////////////////////////////
