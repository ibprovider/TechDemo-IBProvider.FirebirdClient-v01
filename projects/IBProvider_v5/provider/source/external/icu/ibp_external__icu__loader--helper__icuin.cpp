////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/icu/ibp_external__icu__loader.h"
#include "source/error_services/ibp_error_utils.h"

#include "source/os/ibp_os__dll_version_info.h"

#include "source/ibp_global_objects_data__dlls.h"

#include <win32lib/win32lib.h>

#include <structure/t_str_version.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader

ICU__Loader::tag_dll_ptr ICU__Loader::helper__get_icuin()
{
 DEBUG_CODE(m_guard.debug__CheckCurrentThreadIsOwner());

 if(m_dll__icuin)
  return m_dll__icuin.not_null_ptr();

 if(m_icuin_library.empty())
  return nullptr;

 const os::t_ibp_os__dll_ptr
  spICUIN_DLL
   (IBP_GlobalObjectsData__DLLs::GetDLL
     (m_icuin_library,
      ibprovider::ibp_propval_dll_lock_rule__force_unload));

 assert(spICUIN_DLL);

 m_dll__icuin
  =self_type::helper__create_icuin
    (spICUIN_DLL);

 return m_dll__icuin;
}//helper__get_icuin

//------------------------------------------------------------------------
ICU__Loader::tag_dll_ptr ICU__Loader::helper__create_icuin
                             (os::t_ibp_os__dll* const pICUIN_DLL)
{
 assert(pICUIN_DLL);

 const wchar_t* const c_ICUIN=L"ICUIN";

 os::t_ibp_os__dll_version_info dll_ver_info;

 if(!dll_ver_info.load(pICUIN_DLL->get_dll_handle()))
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_common__dll_not_has_versioninfo_1,
    win32lib::GetModuleFileName(pICUIN_DLL->get_dll_handle()));
 }//if

 //-----------------------------------------  read module descr
 if(dll_ver_info.m_file_descr.empty())
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_common__dll_versioninfo_not_has_file_descr_1,
    win32lib::GetModuleFileName(pICUIN_DLL->get_dll_handle()));
 }//if

 assert(!dll_ver_info.m_file_descr.empty());

 //-----------------------------------------  read module version
 if(dll_ver_info.m_prod_version.empty())
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_common__dll_versioninfo_not_has_prod_version_1,
    win32lib::GetModuleFileName(pICUIN_DLL->get_dll_handle()));
 }//if

 assert(!dll_ver_info.m_prod_version.empty());

 if(dll_ver_info.m_file_descr==L"ICU I18N DLL")
 {
  //Это ICU из FB4+
  const structure::wstr_version ver(dll_ver_info.m_prod_version);

  if(structure::eq_str_version_prefix(ver,L"63.1"))
   return this->helper__create_icuin__type01(pICUIN_DLL,dll_ver_info.m_prod_version);

  //ERROR - This version of DLL is not supported.

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_icu__unsupported_module_version_4,
    c_ICUIN,
    win32lib::GetModuleFileName(pICUIN_DLL->get_dll_handle()),
    dll_ver_info.m_file_descr,
    dll_ver_info.m_prod_version);
 }//if

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_icu__unknown_module_version_4,
   c_ICUIN,
   win32lib::GetModuleFileName(pICUIN_DLL->get_dll_handle()),
   dll_ver_info.m_file_descr,
   dll_ver_info.m_prod_version);
}//helper__create_icuin

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
