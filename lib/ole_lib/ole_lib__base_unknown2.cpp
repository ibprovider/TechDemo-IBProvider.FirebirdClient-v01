////////////////////////////////////////////////////////////////////////////////
//C++ library for OLE.
//                                                Kovalenko Dmitry. 28.10.2022.
#include <_pch_.h>
#pragma hdrstop

#ifdef OLE_LIB_NO_COM_MODULE
# include <ole_lib/ole_lib__base_unknown2.h>
#else
# include <ole_lib/ole_lib__com_module.h>
#endif

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK

void TBaseUnknown2__SERVER_LINK::IncrementComponentCount()
{
 _Module.IncrementComponentCount();
}//IncrementComponentCount

//------------------------------------------------------------------------
void TBaseUnknown2__SERVER_LINK::DecrementComponentCount()
{
 _Module.DecrementComponentCount();
}//DecrementComponentCount

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
