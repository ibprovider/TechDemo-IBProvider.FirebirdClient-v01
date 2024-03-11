////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__thread_api.cpp
//! \brief   Thread API [Win32]
//! \author  Kovalenko Dmitry
//! \date    29.02.2024
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/ibp_os_win32__thread_api.h"

#include <lcpi/lib/code_gen.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//class ibp_os_win32__thread_api

ibp_os_win32__thread_api::thread_id_type
 ibp_os_win32__thread_api::GetCurrentThreadId()
{
 const auto id=::GetCurrentThreadId();

 LCPI__assert_s(std::is_same<self_type::thread_id_type LCPI__LITER_COMMA std::remove_const<decltype(id)>::type>::value);

 assert(id!=0);

 return id;
}//GetCurrentThreadId

////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
