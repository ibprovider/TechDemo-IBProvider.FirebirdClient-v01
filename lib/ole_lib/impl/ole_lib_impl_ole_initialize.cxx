////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 26.12.2015

////////////////////////////////////////////////////////////////////////////////
//class TOleInitialize2

TOleInitialize2::TOleInitialize2()
{
 const HRESULT init_hr=::OleInitialize(NULL);

 if(FAILED(init_hr))
 {
  t_base_ole_error::throw_error(init_hr,"Failed to OLE initialize");
 }
}//TOleInitialize2

//------------------------------------------------------------------------
TOleInitialize2::~TOleInitialize2()
{
 //Force Fix BUG in ::CoUnitialize
 ::SetErrorInfo(0,NULL);

 ::OleUninitialize();
}//~TOleInitialize2

////////////////////////////////////////////////////////////////////////////////
