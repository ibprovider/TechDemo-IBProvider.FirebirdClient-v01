////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 07.08.2004

////////////////////////////////////////////////////////////////////////////////
//Data copy utilities

HRESULT CopyBSTR(BSTR Source,BSTR* pTarget,bool FreeTarget)
{
 assert(pTarget!=NULL);

 if(pTarget==NULL)
  return E_POINTER;

 if(Source==*pTarget)
  return S_OK;

 if(FreeTarget && *pTarget!=NULL)
  ::SysFreeString(*pTarget);

 *pTarget=NULL;

 if(Source!=NULL && (*pTarget=::SysAllocStringLen(Source,::SysStringLen(Source)))==NULL)
  return E_OUTOFMEMORY;

 return S_OK;
}//CopyBSTR

////////////////////////////////////////////////////////////////////////////////
