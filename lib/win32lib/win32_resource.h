////////////////////////////////////////////////////////////////////////////////
//Sevices for work with WIN32-Resources
//                                                Dmitry Kovalenko. 12.08.2004
#ifndef _win32_resource_H_
#define _win32_resource_H_

#include <win32lib/win32_base.h>
#include <structure/t_lcid.h>
#include <structure/t_message_entry.h>
#include <vector>

namespace win32lib{
////////////////////////////////////////////////////////////////////////////////
//Include files with implementation.h

#include <win32lib/impl/win32_resource_impl_id.hxx>
#include <win32lib/impl/win32_resource_impl_base.hxx>
#include <win32lib/impl/win32_resource_impl_loader.hxx>
#include <win32lib/impl/win32_resource_impl_msg_table.hxx>
#include <win32lib/impl/win32_resource_impl_msg_table_loader.hxx>

#include <win32lib/impl/win32_resource_impl_catalog.hxx>

////////////////////////////////////////////////////////////////////////////////
}//namespace win32lib
#endif
