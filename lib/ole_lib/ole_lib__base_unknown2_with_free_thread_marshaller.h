////////////////////////////////////////////////////////////////////////////////
//C++ library for OLE.
//                                                Kovalenko Dmitry. 28.10.2022.
#ifndef _ole_lib__base_unknown2_with_free_thread_marshaller_H_
#define _ole_lib__base_unknown2_with_free_thread_marshaller_H_

#include <ole_lib/ole_lib__base_unknown2.h>

#include <lcpi/lib/com/base/com_base__base_unknown3__with_free_thread_marshaler.h>

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
//class TBaseUnknown2_WithFreeThreadMarshaler

using TBaseUnknown2_WithFreeThreadMarshaler
 =::lcpi::lib::com::base::TBaseUnknown3_WithFreeThreadMarshaler<TBaseUnknown2>;

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
#endif
