////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                  Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//class class TBaseUnknown2__SERVER_LINK

void TBaseUnknown2__SERVER_LINK::IncrementComponentCount()
{
 _Module.Lock();
}//IncrementComponentCount

//------------------------------------------------------------------------
void TBaseUnknown2__SERVER_LINK::DecrementComponentCount()
{
 _Module.Unlock();
}//DecrementComponentCount

////////////////////////////////////////////////////////////////////////////////
