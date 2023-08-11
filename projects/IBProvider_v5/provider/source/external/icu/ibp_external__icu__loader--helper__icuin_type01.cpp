////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/icu/ibp_external__icu__loader.h"
#include "source/error_services/ibp_error_utils.h"

#include "source/ibp_global_objects_data__dlls.h"

#include <win32lib/win32lib.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader

ICU__Loader::tag_dll_ptr ICU__Loader::helper__create_icuin__type01
                             (os::t_ibp_os__dll* const pICUIN_DLL,
                              const std::wstring&      dllVersion)
{
 assert(pICUIN_DLL);

 //
 // ICUIN requiring the explicit initialization of ICUUC.
 //
 const tag_dll_ptr
  spICUUC_DLL
   =this->helper__get_icuuc();

 if(!spICUUC_DLL)
 {
  //ERROR - ICUIN DLL is requiring the initialization of ICUUC DLL. Please define ICUUC in connection string.

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_icu__icuin_is_requiring_explicit_initialization_of_icuuc_2,
    win32lib::GetModuleFileName(pICUIN_DLL->get_dll_handle()),
    dllVersion);
 }//if

 assert(spICUUC_DLL);

 if(spICUUC_DLL->get_dll_version()!=dllVersion)
 {
  //ERROR - ICUUC and ICUIN have different versions

  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    ibp_mce_icu__icuin_and_icuuc_have_different_versions_4,
    win32lib::GetModuleFileName(pICUIN_DLL->get_dll_handle()),
    dllVersion,
    win32lib::GetModuleFileName(spICUUC_DLL->get_dll_handle()),
    spICUUC_DLL->get_dll_version());
 }//if

 //
 // ICUUC can contain pointers to ICUIN!
 //
 // So, it needs to release (1) at first ICUUC (2) then ICUIN
 //

 IBP_GlobalObjectsData__DLLs::DefUnloadOrder
  (spICUUC_DLL,
   pICUIN_DLL); // throw

 return lib::structure::not_null_ptr
         (new tag_dll
           (pICUIN_DLL,
            dllVersion)); //throw
}//helper__create_icuin

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
