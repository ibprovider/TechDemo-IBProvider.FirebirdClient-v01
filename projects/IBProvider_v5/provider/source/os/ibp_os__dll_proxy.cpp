////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll.cpp
//! \brief   The proxy of a dynamic library (DLL) loader.
//! \author  Kovalenko Dmitry
//! \date    30.08.2022
#include <_pch_.h>
#pragma hdrstop

#include "source/os/ibp_os__dll_proxy.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dll_proxy

t_ibp_os__dll_proxy::t_ibp_os__dll_proxy(t_ibp_os__dlls*     const        pDLLs,
                                         t_ibp_os__dll_loader::self_ptr&& spDllLoader)
 :m_spDLLs(structure::not_null_ptr(pDLLs))
 ,m_spDllLoader(__STL_MOVE_VALUE(spDllLoader))
{
 assert(m_spDLLs);
 assert(m_spDllLoader);

 //
 // 1. This is a reference from global list
 // 2. This is our reference
 //
 assert(m_spDllLoader->get_cntRef()>=2);
}//t_ibp_os__dll_proxy

//------------------------------------------------------------------------
t_ibp_os__dll_proxy::~t_ibp_os__dll_proxy()
{
 assert(m_spDllLoader);

 //
 // The protected release loader of DLL.
 //
 m_spDLLs->ReleaseDLL(&m_spDllLoader);

 assert(!m_spDllLoader);
}//~t_ibp_os__dll_proxy

//interface --------------------------------------------------------------
HINSTANCE t_ibp_os__dll_proxy::get_dll_handle()const
{
 assert(m_spDllLoader);

 return m_spDllLoader->get_dll_handle();
}//get_dll_handle

//------------------------------------------------------------------------
FARPROC t_ibp_os__dll_proxy::get_proc_address(LPCSTR point_name)const
{
 assert(m_spDllLoader);

 return m_spDllLoader->get_proc_address(point_name);
}//get_proc_address

//------------------------------------------------------------------------
FARPROC t_ibp_os__dll_proxy::try_get_proc_address(LPCSTR point_name)const
{
 assert(m_spDllLoader);

 return m_spDllLoader->try_get_proc_address(point_name);
}//try_get_proc_address

//------------------------------------------------------------------------
IBP_SmartInterfacePtr t_ibp_os__dll_proxy::get_service_obj
                             (REFGUID                 rServiceObjID,
                              pfn_service_obj_creator pfnServiceObjCreator)
{
 assert(m_spDllLoader);

 return m_spDllLoader->get_service_obj
          (rServiceObjID,
           pfnServiceObjCreator);
}//get_service_obj

////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
