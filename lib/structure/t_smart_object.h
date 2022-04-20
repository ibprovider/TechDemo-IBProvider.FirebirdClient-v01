////////////////////////////////////////////////////////////////////////////////
//Structures for implementation of smart object classes
//                                                Kovalenko Dmitry. 10.01.2013.
#ifndef _lcpi_lib__t_smart_object_H_
#define _lcpi_lib__t_smart_object_H_

#include <structure/t_smart_interface.h>
#include <structure/t_smart_object_ptr.h>

#include <structure/t_memory.h>

#include <lcpi/lib/structure/t_smart_object.h>

namespace structure{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup lib_structure
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

template<class TSmartInterface>
using t_basic_smart_interface_impl__static_v2
 =lcpi::lib::structure::t_basic_smart_interface_impl__static_v2<TSmartInterface>;

template<class TSmartInterface,class Allocator>
using t_basic_smart_interface_impl__dynamic
 =lcpi::lib::structure::t_basic_smart_interface_impl__dynamic<TSmartInterface,Allocator>;

template<class Allocator=t_void_allocator>
using t_basic_smart_object_base2
 =lcpi::lib::structure::t_basic_smart_object_base2<Allocator>;

////////////////////////////////////////////////////////////////////////////////

using t_smart_memory_object
 =t_basic_smart_interface_impl__dynamic<t_smart_interface,t_void_allocator>;

////////////////////////////////////////////////////////////////////////////////

#define SLIB__REDECLARE_SMART_OBJ_MANAGEMENT_METHODS                        \
 LCPI_CPP_LIB__REDECLARE_SMART_OBJ_MANAGEMENT_METHODS

//------------------------------------------------------------------------
#define SLIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS                          \
 LCPI_CPP_LIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS

//------------------------------------------------------------------------
#define SLIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS__FINAL                   \
 LCPI_CPP_LIB__DECLARE_SMART_OBJ_MANAGEMENT_METHODS__FINAL

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}//namespace structure
#endif
