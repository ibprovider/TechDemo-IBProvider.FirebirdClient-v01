////////////////////////////////////////////////////////////////////////////////
//Win32 library implementation.
//                                               Dmitry Kovalenko. 13.08.2004.

////////////////////////////////////////////////////////////////////////////////

HGLOBAL Resource_LoadByLangEx(HINSTANCE         const hInstance,
                              LPCTSTR           const resType,
                              TResID            const resID,
                              DWORD*            const pcbResource,
                              structure::t_lcid const wLanguage);

////////////////////////////////////////////////////////////////////////////////
