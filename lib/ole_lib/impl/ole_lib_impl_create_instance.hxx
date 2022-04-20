////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//Function for create COM Object

HRESULT SafeCreateInstance(structure::wstr_parameter str_clsid,
                           LPUNKNOWN                 pUnkOuter,
                           DWORD                     dwClsContext,
                           LPUNKNOWN*                ppUnk);

HRESULT SafeCreateInstance(structure::str_parameter str_clsid,
                           LPUNKNOWN                pUnkOuter,
                           DWORD                    dwClsContext,
                           LPUNKNOWN*               ppUnk);

HRESULT SafeCreateInstance(structure::wstr_parameter str_clsid,
                           LPUNKNOWN                 pUnkOuter,
                           DWORD                     dwClsContext,
                           REFIID                    riid,
                           void**                    ppv);

HRESULT SafeCreateInstance(structure::str_parameter str_clsid,
                           LPUNKNOWN                pUnkOuter,
                           DWORD                    dwClsContext,
                           REFIID                   riid,
                           void**                   ppv);

HRESULT SafeCreateInstance(REFCLSID  clsid,
                           LPUNKNOWN pUnkOuter,
                           DWORD     dwClsContext,
                           REFIID    riid,
                           void**    ppv);

HRESULT SafeCreateInstance(REFCLSID   clsid,
                           LPUNKNOWN  pUnkOuter,
                           DWORD      dwClsContext,
                           LPUNKNOWN* ppUnk);

////////////////////////////////////////////////////////////////////////////////
