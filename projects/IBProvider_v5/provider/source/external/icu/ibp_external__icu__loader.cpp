////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/icu/ibp_external__icu__loader.h"

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader

ICU__Loader::ICU__Loader(const string_type& icuuc_library,
                         const string_type& icuin_library)
 :m_icuuc_library(icuuc_library)
 ,m_icuin_library(icuin_library)
{
}//ICU__Loader

//------------------------------------------------------------------------
ICU__Loader::~ICU__Loader()
{
}//~ICU__Loader

//------------------------------------------------------------------------
ICU__Loader::self_ptr ICU__Loader::create(const string_type& icuuc_library,
                                          const string_type& icuin_library)
{
 return lib::structure::not_null_ptr
         (new self_type
           (icuuc_library,icuin_library));
}//create

//interface --------------------------------------------------------------
ICU__Dll_Ptr ICU__Loader::get_dll__icuuc()
{
 const lock_guard_type __lock(m_guard);

 return this->helper__get_icuuc();
}//get_dll__icuuc

//------------------------------------------------------------------------
ICU__Dll_Ptr ICU__Loader::get_dll__icuin()
{
 const lock_guard_type __lock(m_guard);

 return this->helper__get_icuin();
}//get_dll__icuin

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll

ICU__Loader::tag_dll::tag_dll(os::t_ibp_os__dll* const pDLL,
                              const std::wstring&      dllVersion)
 :m_spDLL(lib::structure::not_null_ptr(pDLL))
 ,m_DllVersion(dllVersion)
{
 assert(m_spDLL);
}//tag_dll

//------------------------------------------------------------------------
ICU__Loader::tag_dll::~tag_dll()
{
}//~tag_dll

//------------------------------------------------------------------------
const std::wstring& ICU__Loader::tag_dll::get_dll_version()const
{
 return m_DllVersion;
}//get_dll_version

//dll interface ----------------------------------------------------------
HINSTANCE ICU__Loader::tag_dll::get_dll_handle()const
{
 assert(m_spDLL);

 return m_spDLL->get_dll_handle();
}//get_dll_handle

//------------------------------------------------------------------------
FARPROC ICU__Loader::tag_dll::get_proc_address(LPCSTR point_name)const
{
 assert(m_spDLL);

 return m_spDLL->get_proc_address(point_name);
}//get_proc_address

//------------------------------------------------------------------------
FARPROC ICU__Loader::tag_dll::try_get_proc_address(LPCSTR point_name)const
{
 assert(m_spDLL);

 return m_spDLL->try_get_proc_address(point_name);
}//try_get_proc_address

//------------------------------------------------------------------------
IBP_SmartObjectPtr ICU__Loader::tag_dll::get_service_obj
                             (REFGUID                        rServiceObjID,
                              service_obj_creator_type const fnServiceObjCreator)
{
 assert(m_spDLL);
 assert(fnServiceObjCreator);

 return m_spDLL->get_service_obj
          (rServiceObjID,
           fnServiceObjCreator);
}//get_service_obj

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
