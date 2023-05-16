////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp
//! \file    ibp_global_objects_data__dlls.cpp
//! \brief   Работа с глобальными данными. DLLs.
//! \author  Kovalenko Dmitry
//! \date    24.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/ibp_global_objects_data__dlls.h"

#ifndef IBP_BUILD_TESTCODE
# include "source/ibp_global_objects.h"
#else
# include "source/os/ibp_os__dlls.h"
#endif

#include <win32lib/win32lib.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//class IBP_GlobalObjectsData__DLLs::tagTestData

#ifdef IBP_BUILD_TESTCODE

class IBP_GlobalObjectsData__DLLs::tagTestData LCPI_CPP_CFG__CLASS__FINAL
{
 public:
  static os::t_ibp_os__dlls::self_ptr spDLLs;
};//class IBP_GlobalObjectsData__DLLs::tagTestData

//------------------------------------------------------------------------
os::t_ibp_os__dlls::self_ptr
 IBP_GlobalObjectsData__DLLs::tagTestData::spDLLs;

#endif //IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////
//class IBP_GlobalObjectsData__DLLs

#if defined(IBP_BUILD_TESTCODE) && !defined(NDEBUG)
structure::t_debug__mt_guard_rw IBP_GlobalObjectsData__DLLs::sm_TEST_CODE__GUARD_RW;
#endif

//------------------------------------------------------------------------
os::t_ibp_os__dll_ptr IBP_GlobalObjectsData__DLLs::GetDLL
                                           (t_ibp_str_box const DLL_Name,
                                            long          const DLL_Lock_Rule)
{
#ifndef IBP_BUILD_TESTCODE
 IBP_GlobalObjects::TDataAccessor dataAccessor;

 return dataAccessor.GetData()->m_spDLLs->GetDLL(DLL_Name,DLL_Lock_Rule);
#else

#ifndef NDEBUG
 structure::t_debug__mt_guard_rw_lock_r __lock_r(sm_TEST_CODE__GUARD_RW);
#endif

 assert(tagTestData::spDLLs);

 return tagTestData::spDLLs->GetDLL(DLL_Name,DLL_Lock_Rule);
#endif
}//GetDLL

//------------------------------------------------------------------------
void IBP_GlobalObjectsData__DLLs::ReleaseDLL(os::t_ibp_os__dll_loader::self_ptr* const pspDllLoader)
{
#ifndef IBP_BUILD_TESTCODE
 IBP_GlobalObjects::TDataAccessor dataAccessor;

 return dataAccessor.GetData()->m_spDLLs->ReleaseDLL(pspDllLoader);
#else

#ifndef NDEBUG
 structure::t_debug__mt_guard_rw_lock_r __lock_r(sm_TEST_CODE__GUARD_RW);
#endif

 assert(tagTestData::spDLLs);

 return tagTestData::spDLLs->ReleaseDLL(pspDllLoader);
#endif
}//ReleaseDLL

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

void IBP_GlobalObjectsData__DLLs::TEST_CODE__Initialize()
{
#ifndef NDEBUG
 structure::t_debug__mt_guard_rw_lock_w __lock_w(sm_TEST_CODE__GUARD_RW);
#endif

 assert(!tagTestData::spDLLs);

 tagTestData::spDLLs=new os::t_ibp_os__dlls();
}//TEST_CODE__Initialize

#endif

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

void IBP_GlobalObjectsData__DLLs::TEST_CODE__Deinitialize()
{
#ifndef NDEBUG
 structure::t_debug__mt_guard_rw_lock_w __lock_w(sm_TEST_CODE__GUARD_RW);
#endif

 assert(tagTestData::spDLLs);

 tagTestData::spDLLs.Release();
}//TEST_CODE__Deinitialize

#endif

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
