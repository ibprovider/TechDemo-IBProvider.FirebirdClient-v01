////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_memory.h
//! \brief   Конструкции для управления памятью.
//! \author  Kovalenko Dmitry
//! \date    09.08.2006.
#ifndef _db_memory_H_
#define _db_memory_H_

#include <ole_lib/oledb/oledb_common.h>
#include <structure/t_smart_object.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//memory allocator

/// <summary>
///  Основной распределитель памяти
/// </summary>
using t_db_memory_allocator
 =oledb_lib::TOLEDBMemoryAllocator;

////////////////////////////////////////////////////////////////////////////////
//class t_db_smart_memory_object

/// <summary>
///  Базовый интерфейс смарт-объектов
/// </summary>
using t_db_smart_interface
 =lib::structure::t_smart_interface;

//------------------------------------------------------------------------
#define IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(Interface)                      \
 lib::structure::t_basic_smart_interface_impl__dynamic                    \
  <Interface,ibp::db_obj::t_db_memory_allocator>

//------------------------------------------------------------------------
#define IBP_DEF_DB_INTERFACE_IMPL_STATIC(Interface)                       \
 lib::structure::t_basic_smart_interface_impl__static_v2<Interface>

////////////////////////////////////////////////////////////////////////////////
//aliases

using t_db_object=t_db_smart_interface;

using t_db_object_ptr=lib::structure::t_smart_object_ptr<t_db_object>;

using t_db_object_const_ptr=lib::structure::t_smart_object_ptr<const t_db_object>;

////////////////////////////////////////////////////////////////////////////////
//class t_db_smart_memory_object

/// <summary>
///  Базовый класс smart-объектов
/// </summary>
using t_db_smart_memory_object
 =IBP_DEF_DB_INTERFACE_IMPL_DYNAMIC(t_db_object);

////////////////////////////////////////////////////////////////////////////////

using t_db_smart_object_base2
 =lib::structure::t_basic_smart_object_base2<t_db_memory_allocator>;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
