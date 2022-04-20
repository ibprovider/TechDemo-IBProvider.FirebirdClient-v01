////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////

HRESULT SafeCreateInstance(structure::wstr_parameter const str_clsid,
                           LPUNKNOWN                 const pUnkOuter,
                           DWORD                     const dwClsContext,
                           LPUNKNOWN*                const ppUnk)
{
 return SafeCreateInstance
         (str_clsid,
          pUnkOuter,
          dwClsContext,
          IID_IUnknown,
          reinterpret_cast<void**>(ppUnk));
}//SafeCreateInstance

//------------------------------------------------------------------------
HRESULT SafeCreateInstance(structure::str_parameter const str_clsid,
                           LPUNKNOWN                const pUnkOuter,
                           DWORD                    const dwClsContext,
                           LPUNKNOWN*               const ppUnk)
{
 return SafeCreateInstance
         (str_clsid,
          pUnkOuter,
          dwClsContext,
          IID_IUnknown,
          reinterpret_cast<void**>(ppUnk));
}//SafeCreateInstance

////////////////////////////////////////////////////////////////////////////////

HRESULT SafeCreateInstance(structure::wstr_parameter const str_clsid,
                           LPUNKNOWN                 const pUnkOuter,
                           DWORD                     const dwClsContext,
                           REFIID                          riid,
                           void**                    const ppv)
{
 assert(ppv!=nullptr);

 (*ppv)=nullptr;

 CLSID clsid;

 const HRESULT cvt_hr=ole_lib::string_to_clsid(str_clsid,&clsid);

 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 return SafeCreateInstance
         (clsid,
          pUnkOuter,
          dwClsContext,
          riid,
          ppv);
}//SafeCreateInstance

//-------------------------------------------------------------------------
HRESULT SafeCreateInstance(structure::str_parameter const str_clsid,
                           LPUNKNOWN                const pUnkOuter,
                           DWORD                    const dwClsContext,
                           REFIID                         riid,
                           void**                   const ppv)
{
 assert(ppv!=nullptr);

 (*ppv)=nullptr;

 CLSID clsid;

 const HRESULT cvt_hr=ole_lib::string_to_clsid(str_clsid,&clsid);

 if(FAILED(cvt_hr))
  return cvt_hr;

 assert(cvt_hr==S_OK);

 return SafeCreateInstance
         (clsid,
          pUnkOuter,
          dwClsContext,
          riid,
          ppv);
}//SafeCreateInstance

//------------------------------------------------------------------------
HRESULT SafeCreateInstance(REFCLSID        clsid,
                           LPUNKNOWN const pUnkOuter,
                           DWORD     const dwClsContext,
                           REFIID          riid,
                           void**    const ppv)
{
 assert(ppv!=nullptr);

 (*ppv)=nullptr;

 const HRESULT hr
  =::CoCreateInstance
      (clsid,
       pUnkOuter,
       dwClsContext,
       riid,
       ppv);

 if(hr!=S_OK)
 {
  (*ppv)=nullptr;
  return hr;
 }

 if((*ppv)==nullptr)
  return E_FAIL;

 return hr;
}//SafeCreateInstance

//------------------------------------------------------------------------
HRESULT SafeCreateInstance(REFCLSID         clsid,
                           LPUNKNOWN  const pUnkOuter,
                           DWORD      const dwClsContext,
                           LPUNKNOWN* const ppUnk)
{
 assert(ppUnk!=nullptr);

 return SafeCreateInstance
         (clsid,
          pUnkOuter,
          dwClsContext,
          IID_IUnknown,
          reinterpret_cast<void**>(ppUnk));
}//SafeCreateInstance

////////////////////////////////////////////////////////////////////////////////
