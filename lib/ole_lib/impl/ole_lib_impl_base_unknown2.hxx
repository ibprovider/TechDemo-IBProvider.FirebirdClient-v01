////////////////////////////////////////////////////////////////////////////////
//OLE Library implementation.
//                                                  Dmitry Kovalenko. 13.08.2004

////////////////////////////////////////////////////////////////////////////////
//class class TBaseUnknown2__SERVER_LINK

class TBaseUnknown2__SERVER_LINK LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static void IncrementComponentCount();

  static void DecrementComponentCount();
};//class TBaseUnknown2__SERVER_LINK

////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2 - base class for implementing IUnknown

using TBaseUnknown2
 =TBaseUnknown3<TBaseUnknown2__SERVER_LINK,TComObjectMemoryAllocator>;

using TBaseUnknown2NPtr
 =INondelegatingPtr2<TBaseUnknown2>;

////////////////////////////////////////////////////////////////////////////////
