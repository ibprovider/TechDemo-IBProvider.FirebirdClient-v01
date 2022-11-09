////////////////////////////////////////////////////////////////////////////////
//C++ library for OLE.
//                                                Kovalenko Dmitry. 28.10.2022.
#ifndef _ole_lib__base_unknown2_H_
#define _ole_lib__base_unknown2_H_

#include <ole_lib/ole_lib__memory_allocator.h>
#include <ole_lib/ole_ptr.h>
#include <ole_lib/ole_base.h>

#include <lcpi/lib/com/base/com_base__base_unknown3.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2__SERVER_LINK

#ifndef OLE_LIB_NO_BASE_UNKNOWN2

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

#endif //OLE_LIB_NO_BASE_UNKNOWN2

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
