////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__memory.h
//! \brief   Конструкции для управления памятью.
//! \author  Kovalenko Dmitry
//! \date    29.10.2014.
#ifndef _remote_fb__memory_H_
#define _remote_fb__memory_H_

#include "source/ibp_memory.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//Memory Allocator

/// <summary>
///  Основной распределитель памяти
/// </summary>
using RemoteFB__MemoryAllocator
 =IBP_MemoryAllocator;

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__SmartInterface

/// <summary>
///  Базовый интерфейс смарт-объектов
/// </summary>
using RemoteFB__SmartInterface
 =IBP_SmartInterface;

//------------------------------------------------------------------------

using RemoteFB__SmartObjectPtr
 =structure::t_smart_object_ptr<RemoteFB__SmartInterface>                   ;

//------------------------------------------------------------------------
#define REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(Interface)                  \
 lcpi::lib::structure::t_basic_smart_interface_impl__dynamic              \
  <Interface,                                                             \
   ibp::db_client::remote_fb::RemoteFB__MemoryAllocator>

//------------------------------------------------------------------------
#define REMOTE_FB__DEF_INTERFACE_IMPL_STATIC(Interface)                   \
 lcpi::lib::structure::t_basic_smart_interface_impl__static_v2            \
  <Interface>

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///   Базовый класс smart-объектов
/// </summary>
using RemoteFB__SmartMemoryObject
 =REMOTE_FB__DEF_INTERFACE_IMPL_DYNAMIC(RemoteFB__SmartInterface); 

////////////////////////////////////////////////////////////////////////////////

using RemoteFB__SmartObjectBase2
 =lcpi::lib::structure::t_basic_smart_object_base2<RemoteFB__MemoryAllocator>;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
