////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_memory.h
//! \brief   Конструкции для управления памятью.
//! \author  Kovalenko Dmitry.
//! \date    01.12.2014
#ifndef _ibp_memory_H_
#define _ibp_memory_H_

#include <ole_lib/oledb/oledb_memory.h>

#include <structure/t_smart_object_ptr.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//typedefs

using IBP_MemoryAllocator
 =oledb_lib::TOLEDBMemoryAllocator;

//------------------------------------------------------------------------
using IBP_SmartInterface
 =lcpi::infrastructure::core::structure::t_smart_interface;

//------------------------------------------------------------------------
#define IBP_DEF_INTERFACE_IMPL_DYNAMIC(Interface)                         \
 lcpi::lib::structure::t_basic_smart_interface_impl__dynamic              \
  <Interface,ibp::IBP_MemoryAllocator>

//------------------------------------------------------------------------
#define IBP_DEF_INTERFACE_IMPL_STATIC(Interface)                          \
 lcpi::lib::structure::t_basic_smart_interface_impl__static_v2            \
  <Interface>

////////////////////////////////////////////////////////////////////////////////

using IBP_SmartObject
 =IBP_SmartInterface;

//------------------------------------------------------------------------
using IBP_SmartObjectPtr
 =lcpi::infrastructure::core::structure::t_smart_object_ptr<IBP_SmartObject>;

//------------------------------------------------------------------------
using IBP_SmartMemoryObject
 =IBP_DEF_INTERFACE_IMPL_DYNAMIC(IBP_SmartObject);

////////////////////////////////////////////////////////////////////////////////
//class IBP_MemoryWithDebugChecks

class IBP_MemoryWithDebugChecks COMP_W000006_CLASS_FINAL
{
 public:
  typedef IBP_MemoryWithDebugChecks                    self_type;

 public:
  static void* Alloc(size_t sz); //throw

  static void Free(void* pv); //throw

#ifndef NDEBUG
  static void Debug__CheckBlock(const void* pv);
#endif

 private:
  static void* Helper__AllocMemory(size_t sz); //throw

  static void Helper__FreeMemory(void* pv); //throw

 private:
#ifndef NDEBUG
  class tag_debug_data;
#endif
};//class IBP_MemoryWithDebugChecks

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
