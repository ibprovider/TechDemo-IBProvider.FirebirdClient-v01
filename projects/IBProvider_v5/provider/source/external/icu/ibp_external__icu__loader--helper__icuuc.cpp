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

ICU__Loader::tag_dll_ptr ICU__Loader::helper__get_icuuc()
{
 DEBUG_CODE(m_guard.debug__CheckCurrentThreadIsOwner());

 if(m_dll__icuuc)
  return m_dll__icuuc.not_null_ptr();

 if(m_icuuc_library.empty())
  return nullptr;

 const os::t_ibp_os__dll_ptr
  spICUUC_DLL
   (IBP_GlobalObjectsData__DLLs::GetDLL
     (m_icuuc_library,
      ibprovider::ibp_propval_dll_lock_rule__force_unload));

 assert(spICUUC_DLL);

 m_dll__icuuc
  =self_type::helper__create_icuuc
    (spICUUC_DLL);

 return m_dll__icuuc;
}//helper__get_icuuc

//------------------------------------------------------------------------
ICU__Loader::tag_dll_ptr ICU__Loader::helper__create_icuuc(os::t_ibp_os__dll* const pICUUC_DLL)
{
 assert(pICUUC_DLL);

 const wchar_t* const c_ICUUC=L"ICUUC";

 //-----------------------------------------
 os::t_ibp_os__dll_version_info dll_ver_info;

 if(!dll_ver_info.load(pICUUC_DLL->get_dll_handle()))
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_common__dll_not_has_versioninfo_1,
    win32lib::GetModuleFileName(pICUUC_DLL->get_dll_handle()));
 }//if

 //-----------------------------------------  read module descr
 if(dll_ver_info.m_file_descr.empty())
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_common__dll_versioninfo_not_has_file_descr_1,
    win32lib::GetModuleFileName(pICUUC_DLL->get_dll_handle()));
 }//if

 assert(!dll_ver_info.m_file_descr.empty());

 //-----------------------------------------  read module version
 if(dll_ver_info.m_prod_version.empty())
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_common__dll_versioninfo_not_has_prod_version_1,
    win32lib::GetModuleFileName(pICUUC_DLL->get_dll_handle()));
 }//if

 assert(!dll_ver_info.m_prod_version.empty());

 if(dll_ver_info.m_file_descr==L"IBM ICU Common DLL")
 {
  //This is ICU of FB2.1, FB2.5
  const structure::wstr_version ver(dll_ver_info.m_prod_version);

  if(structure::eq_str_version_prefix(ver,L"3.0"))
   return self_type::helper__create_icuuc_v003(pICUUC_DLL,dll_ver_info.m_prod_version);

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_icu__unsupported_module_version_4,
    c_ICUUC,
    win32lib::GetModuleFileName(pICUUC_DLL->get_dll_handle()),
    dll_ver_info.m_file_descr,
    dll_ver_info.m_prod_version);
 }//if

 if(dll_ver_info.m_file_descr==L"ICU Common DLL")
 {
  //This is ICU of FB3+
  const structure::wstr_version ver(dll_ver_info.m_prod_version);

  if(structure::eq_str_version_prefix(ver,L"63.1"))
   return self_type::helper__create_icuuc_v063(pICUUC_DLL,dll_ver_info.m_prod_version);

  if(structure::eq_str_version_prefix(ver,L"52.1"))
   return self_type::helper__create_icuuc_v052(pICUUC_DLL,dll_ver_info.m_prod_version);

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_icu__unsupported_module_version_4,
    c_ICUUC,
    win32lib::GetModuleFileName(pICUUC_DLL->get_dll_handle()),
    dll_ver_info.m_file_descr,
    dll_ver_info.m_prod_version);
 }//if

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_icu__unknown_module_version_4,
   c_ICUUC,
   win32lib::GetModuleFileName(pICUUC_DLL->get_dll_handle()),
   dll_ver_info.m_file_descr,
   dll_ver_info.m_prod_version);
}//helper__create_icuuc

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
