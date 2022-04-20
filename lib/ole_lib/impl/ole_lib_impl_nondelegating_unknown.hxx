////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//Nondelegating IUnknown interface - Nondelegating version of IUnknown

struct INondelegatingUnknown
{
 virtual HRESULT __stdcall NondelegatingQueryInterface(const IID& iid, void** ppv)=0;

 virtual ULONG   __stdcall NondelegatingAddRef()=0;

 virtual ULONG   __stdcall NondelegatingRelease()=0;
};//struct INondelegatingUnknown

////////////////////////////////////////////////////////////////////////////////
