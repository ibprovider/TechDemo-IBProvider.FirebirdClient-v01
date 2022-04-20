////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                Dmitry Kovalenko. 13.08.2004
#ifndef _ole_ptr_std_H_
#define _ole_ptr_std_H_

#include <ole_lib/ole_ptr.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//declare type of standart smart-pointers

DECLARE_IPTR_TYPE(IClassFactory);

DECLARE_IPTR_TYPE(IFontDisp);

DECLARE_IPTR_TYPE(IOleObject);
DECLARE_IPTR_TYPE(IOleControl);
DECLARE_IPTR_TYPE(IDataObject);
DECLARE_IPTR_TYPE(IViewObject);
DECLARE_IPTR_TYPE(IViewObject2);
DECLARE_IPTR_TYPE(IOleInPlaceObject);
DECLARE_IPTR_TYPE(IOleInPlaceActiveObject);
DECLARE_IPTR_TYPE(IObjectWithSite);

DECLARE_IPTR_TYPE(IDropTarget);
DECLARE_IPTR_TYPE(IDropSource);

DECLARE_IPTR_TYPE(IDispatch);
DECLARE_IPTR_TYPE(ITypeLib);
DECLARE_IPTR_TYPE(ITypeInfo);
DECLARE_IPTR_TYPE(ICreateErrorInfo);
DECLARE_IPTR_TYPE(IErrorInfo);

DECLARE_IPTR_TYPE(IOleWindow);
DECLARE_IPTR_TYPE(IAdviseSink);
DECLARE_IPTR_TYPE(IOleClientSite);
DECLARE_IPTR_TYPE(IOleControlSite);
DECLARE_IPTR_TYPE(IOleInPlaceUIWindow);
DECLARE_IPTR_TYPE(IOleInPlaceFrame);
DECLARE_IPTR_TYPE(IOleContainer);

DECLARE_IPTR_TYPE(IStorage);
DECLARE_IPTR_TYPE(IStream);
DECLARE_IPTR_TYPE(ISequentialStream);
DECLARE_IPTR_TYPE(ILockBytes);

DECLARE_IPTR_TYPE(IPersist);
DECLARE_IPTR_TYPE(IPersistFile);
DECLARE_IPTR_TYPE(IPersistMemory);
DECLARE_IPTR_TYPE(IPersistStorage);
DECLARE_IPTR_TYPE(IPersistStream);
DECLARE_IPTR_TYPE(IPersistStreamInit);

DECLARE_IPTR_TYPE(IEnumUnknown);
DECLARE_IPTR_TYPE(IEnumVARIANT);
DECLARE_IPTR_TYPE(IEnumFORMATETC);

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
