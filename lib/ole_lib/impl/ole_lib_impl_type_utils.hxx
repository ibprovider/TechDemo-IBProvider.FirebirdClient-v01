////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//Function for loading type library

HRESULT CreateTypeLib(REFIID       LIBID,     //information for search
                      WORD         wVerMajor, //in system registry
                      WORD         wVerMinor,
                      HINSTANCE    hResource, //information for load
                      int          iResID,    //from resource
                      ITypeLib**   ppTypeLib);

////////////////////////////////////////////////////////////////////////////////
//Function for loading type info (ITypeInfo)

HRESULT CreateTypeInfo(REFIID      LIBID,
                       WORD        wVerMajor,
                       WORD        wVerMinor,
                       HINSTANCE   hResource,
                       int         iResID,
                       REFIID      riid,
                       ITypeInfo** ppTypeInfo);

////////////////////////////////////////////////////////////////////////////////
