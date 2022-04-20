 ////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 24.04.2013.

////////////////////////////////////////////////////////////////////////////////
//class TComInitialize2

TComInitialize2::TComInitialize2()
{
 DEBUG_CODE(m_is_initialized=false;)

 const HRESULT hr=::CoInitialize(NULL);

 if(FAILED(hr))
 {
  t_base_ole_error::throw_error(hr,"Failed to COM initialize");
 }

 DEBUG_CODE(m_is_initialized=true;)
}//TComInitialize2

//------------------------------------------------------------------------------
TComInitialize2::TComInitialize2(DWORD const dwCoInit)
{
 DEBUG_CODE(m_is_initialized=false;)

 const HRESULT hr=::CoInitializeEx(NULL,dwCoInit);

 if(FAILED(hr))
 {
  t_base_ole_error::throw_error(hr,"Failed to COM initialize");
 }

 DEBUG_CODE(m_is_initialized=true;)
}//TComInitialize2

//------------------------------------------------------------------------------
TComInitialize2::~TComInitialize2()
{
 assert(m_is_initialized);

 //FIX BUG in CoUninitialize
 ::SetErrorInfo(0,NULL);

 ::CoUninitialize();

 DEBUG_CODE(m_is_initialized=false;)
}//~TComInitialize2

////////////////////////////////////////////////////////////////////////////////
