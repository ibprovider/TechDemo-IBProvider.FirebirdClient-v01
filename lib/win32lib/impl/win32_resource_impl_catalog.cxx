////////////////////////////////////////////////////////////////////////////////
//Win32 library implementation.
//                                                Dmitry Kovalenko. 08.02.2005.

////////////////////////////////////////////////////////////////////////////////
//class TResourceCatalog::TNamePushBacker

class TResourceCatalog::TNamePushBacker
{
 private:
  typedef TNamePushBacker                    self_type;

  TNamePushBacker(const self_type&);
  self_type& operator = (const self_type&);

 public:
  TNamePushBacker(resid_vector& Names);

  static BOOL CALLBACK CallBackProc(HINSTANCE hInstance,
                                    LPCTSTR   lpszType,
                                    LPTSTR    lpszName,
                                    LONG_PTR  lParam);

 private:
  resid_vector& m_Names;
};//class TNamePushBacker

////////////////////////////////////////////////////////////////////////////////
//class TResourceCatalog::TNamePushBacker

inline TResourceCatalog::TNamePushBacker::TNamePushBacker(resid_vector& Names)
 :m_Names(Names)
{
}

//------------------------------------------------------------------------
BOOL CALLBACK TResourceCatalog::TNamePushBacker::CallBackProc(HINSTANCE /*hInstance*/,
                                                              LPCTSTR   /*lpszType*/,
                                                              LPTSTR    lpszName,
                                                              LONG_PTR  lParam)
{
 assert(lParam!=NULL);

 reinterpret_cast<self_type*>(lParam)->m_Names.push_back(lpszName);

 return TRUE;
}//CallBackProc

////////////////////////////////////////////////////////////////////////////////
//class TResourceCatalog

BOOL TResourceCatalog::EnumNames(HINSTANCE        const hInstance,
                                 const char_type* const szTypes,
                                 resid_vector&          Names)
{
 TNamePushBacker PushBacker(Names);

 assert(sizeof(&PushBacker)==sizeof(LONG_PTR));

 return EnumResourceNames
         (hInstance,
          szTypes,
          PushBacker.CallBackProc,
          reinterpret_cast<LONG_PTR>(&PushBacker));
}//EnumNames

////////////////////////////////////////////////////////////////////////////////

