////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_init_mutex.cpp
//! \brief   The mutex for DLL initialization.
//! \author  Kovalenko Dmitry
//! \date    31.08.2022
#include <_pch_.h>
#pragma hdrstop

#include "source/os/win32/ibp_os_win32__dll_init_mutex.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_init_mutex

t_ibp_os_win32__dll_init_mutex::t_ibp_os_win32__dll_init_mutex()
 :m_cInits(0)
{
}//t_ibp_os_win32__dll_init_mutex

//------------------------------------------------------------------------
t_ibp_os_win32__dll_init_mutex::~t_ibp_os_win32__dll_init_mutex()
{
 assert(m_cInits==0);
}//~t_ibp_os_win32__dll_init_mutex

//interface --------------------------------------------------------------
void t_ibp_os_win32__dll_init_mutex::do_initialize(op_func_type const op_func)
{
 assert(op_func);

 lock_guard_type __lock(m_InitGuard);

 if(m_cInits==0)
 {
  op_func(); //throw
 }//if

 ++m_cInits;
}//do_initialize

//------------------------------------------------------------------------
void t_ibp_os_win32__dll_init_mutex::do_uninitialize(op_func_type const op_func)
{
 assert(op_func);

 lock_guard_type __lock(m_InitGuard);

 assert(m_cInits>0);

 if(m_cInits==1)
 {
  op_func(); //throw
 }//if

 --m_cInits;
}//do_uninitialize

////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
