////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/ole_base.h>
#include <ole_lib/ole_ptr.h>
#include <win32lib/win32_registry.h>
#include <win32lib/win32_error.h>
//#include <structure/t_function.h>
#include <structure/t_fix_stream.h>
#include <structure/t_numeric_cast.h>

#include <structure/utilities/string/trim.h>
#include <structure/utilities/string/string_length.h>

#include <lcpi/lib/com/base/com_base__string_to_guid.h>

////////////////////////////////////////////////////////////////////////////////
#include <ole_lib/impl/ole_lib_impl_std_guids.cxx>
////////////////////////////////////////////////////////////////////////////////

namespace ole_lib{
////////////////////////////////////////////////////////////////////////////////
using namespace structure;

////////////////////////////////////////////////////////////////////////////////
//Include implementation files

#include <ole_lib/impl/ole_lib_impl_test_utils.cxx>
#include <ole_lib/impl/ole_lib_impl_guid_utils.cxx>

#include <ole_lib/impl/ole_lib_impl_bstr_utils.cxx>
#include <ole_lib/impl/ole_lib_impl_bstr.cxx>

#include <ole_lib/impl/ole_lib_impl_create_instance.cxx>

#include <ole_lib/impl/ole_lib_impl_error_utils.cxx>

#include <ole_lib/impl/ole_lib_impl_ole_status.cxx>
#include <ole_lib/impl/ole_lib_impl_base_com_error.cxx>
#include <ole_lib/impl/ole_lib_impl_base_ole_error.cxx>
#include <ole_lib/impl/ole_lib_impl_ole_error.cxx>

#include <ole_lib/impl/ole_lib_impl_connect_data2.cxx>

////////////////////////////////////////////////////////////////////////////////
}//namespace ole_lib
