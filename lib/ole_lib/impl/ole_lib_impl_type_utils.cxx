////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//Function for loading type library

HRESULT CreateTypeLib(REFIID       LIBID,
                      WORD         wVerMajor,
                      WORD         wVerMinor,
                      HINSTANCE    hResource,
                      int          iResID,
                      ITypeLib**   ppTypeLib)
{
 if(ppTypeLib==NULL)
  return E_POINTER;

 *ppTypeLib=NULL;

 HRESULT hr=::LoadRegTypeLib(LIBID,wVerMajor,wVerMinor,0x00,ppTypeLib);

 if(hr!=S_OK && hResource!=NULL) //try load type library from resource
 {
  using structure::ansi_to_unicode;

  *ppTypeLib=NULL;

  TCHAR tmpStr[40];

  //TODO: проверить
  _VERIFY_EQ(_GCRT_itot_s(iResID,tmpStr,_DIM_(tmpStr),10),0L);

  t_string path(win32lib::GetModuleFileName(hResource));

  path+='\\';
  path+=tmpStr;

  if((hr=::LoadTypeLib(tstr_to_wstr(path).c_str(),ppTypeLib))!=NOERROR)
   *ppTypeLib=NULL;
 }//if

 assert(hr!=S_OK || *ppTypeLib!=NULL);

 if(SUCCEEDED(hr) && *ppTypeLib==NULL)
  hr=TYPE_E_CANTLOADLIBRARY;

 return hr;
}//CreateTypeLib

////////////////////////////////////////////////////////////////////////////////
//Function for loading type info (ITypeInfo)

HRESULT CreateTypeInfo(REFIID      LIBID,
                       USHORT      wVerMajor,
                       USHORT      wVerMinor,
                       HINSTANCE   hResource,
                       int         iResID,
                       REFIID      riid,
                       ITypeInfo** ppTypeInfo)
{
 DECLARE_IPTR_TYPE(ITypeLib);
 DECLARE_IPTR_TYPE(ITypeInfo);

 if(ppTypeInfo==NULL)
  return E_POINTER;

 *ppTypeInfo=NULL;

 ITypeLibPtr spTypeLib;
                                   //version number
 HRESULT hr=::LoadRegTypeLib(LIBID,wVerMajor,wVerMinor,0x00,&spTypeLib.ref_ptr());

 if(hr==NOERROR)
 {
  assert(spTypeLib);

  hr=spTypeLib->GetTypeInfoOfGuid(riid,ppTypeInfo);
 }

 if(hr!=NOERROR && hResource!=NULL) //try load type library from resource
 {
  using structure::ansi_to_unicode;

  *ppTypeInfo=NULL;

  TCHAR tmpStr[40];

  //TODO: проверить
  _VERIFY_EQ(_GCRT_itot_s(iResID,tmpStr,_DIM_(tmpStr),10),0L);

  t_string path(win32lib::GetModuleFileName(hResource));

  path+='\\';
  path+=tmpStr;

  if((hr=::LoadTypeLib(tstr_to_wstr(path).c_str(),&spTypeLib.ref_ptr()))!=NOERROR)
   return hr;

  assert(spTypeLib);

  if((hr=spTypeLib->GetTypeInfoOfGuid(riid,ppTypeInfo))!=NOERROR)
   *ppTypeInfo=NULL;
 }//if

 assert(hr!=S_OK || *ppTypeInfo!=NULL);

 if(SUCCEEDED(hr) && *ppTypeInfo==NULL)
  hr=E_FAIL;

 return hr;
}//CreateTypeInfo

////////////////////////////////////////////////////////////////////////////////
