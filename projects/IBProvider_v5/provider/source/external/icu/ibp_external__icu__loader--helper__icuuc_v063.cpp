////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/icu/ibp_external__icu__loader.h"
#include "source/external/icu/v063/ibp_external__icu_v063__api.h"

#include "source/os/ibp_os__dll_entry_point.h"
#include "source/os/ibp_os__dll_init_mutex.h"
#include "source/os/ibp_os__path_utils.h"

#include "source/error_services/ibp_error_bug_check.h"

#include <win32lib/win32lib.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll__icuuc_v063

#define DEF_ICU_POINT(func_name)                                          \
 ibp::os::ibp_os__dll_entry_point<icu::v063::api::t_fn_##func_name*> m_##func_name

class ICU__Loader::tag_dll__icuuc_v063 LCPI_CPP_CFG__CLASS__FINAL
 :public ICU__Loader::tag_dll
{
 private:
  using self_type=tag_dll__icuuc_v063;
  using inherited=ICU__Loader::tag_dll;

  tag_dll__icuuc_v063(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~tag_dll__icuuc_v063();

 public:
  tag_dll__icuuc_v063(os::t_ibp_os__dll*  pDLL,
                      const std::wstring& dllVersion);

 private:
  typedef os::t_ibp_os__dll_init_mutex           dll_init_mutex_type;
  typedef os::t_ibp_os__dll_init_mutex::self_ptr dll_init_mutex_ptr;

 private:
  static t_ibp_subsystem_id get_subsystem_id()
  {
   return ibp_subsystem__icu_api_v063;
  }

 private:
  static dll_init_mutex_ptr helper__get_dll_init_mutex(os::t_ibp_os__dll* pDLL);

  static IBP_SmartObjectPtr helper__create_dll_init_mutex();

  void helper__init_op();

  void helper__uninit_op();

 private:
  DEF_ICU_POINT(u_setDataDirectory);
  DEF_ICU_POINT(u_setTimeZoneFilesDirectory);

  DEF_ICU_POINT(u_init);
  DEF_ICU_POINT(u_cleanup);

 private:
  /// DLL initialization mutex
  dll_init_mutex_ptr const m_spDllInitMutex;

 private:
  static const GUID sm_DllInitSvcObjID;
};//class ICU__Loader::tag_dll__icuuc_v063

#undef DEF_ICU_POINT

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll__icuuc_v063

const GUID ICU__Loader::tag_dll__icuuc_v063::sm_DllInitSvcObjID
 ={0xB5CC69C8,0xD5CD,0x4A07,{0x8D,0x0B,0x42,0x1A,0x0A,0x0A,0x6D,0xB7}};

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll__icuuc_v063

#define INIT_ICU_POINT(func_name)  \
 m_##func_name(pDLL,#func_name"_63")

ICU__Loader::tag_dll__icuuc_v063::tag_dll__icuuc_v063
                             (os::t_ibp_os__dll* const pDLL,
                              const std::wstring&      dllVersion)
 :inherited(pDLL,dllVersion)
 ,INIT_ICU_POINT(u_setDataDirectory)
 ,INIT_ICU_POINT(u_setTimeZoneFilesDirectory)
 ,INIT_ICU_POINT(u_init)
 ,INIT_ICU_POINT(u_cleanup)
 ,m_spDllInitMutex(helper__get_dll_init_mutex(pDLL))
{
 assert(m_spDllInitMutex);
 assert(pDLL!=this);

 //---------------------------
 //
 // Initialization of pointers to primary functions.
 //

 m_u_setDataDirectory.point();
 m_u_setTimeZoneFilesDirectory.point();
 m_u_init.point();
 m_u_cleanup.point();

 //---------------------------
 m_spDllInitMutex->do_initialize
  (structure::make_closure_r(this,&self_type::helper__init_op)); //throw
}//tag_dll__icuuc_v063

#undef INIT_ICU_POINT

//------------------------------------------------------------------------
ICU__Loader::tag_dll__icuuc_v063::~tag_dll__icuuc_v063()
{
 assert(m_spDllInitMutex);

 try
 {
  m_spDllInitMutex->do_uninitialize
   (structure::make_closure_r(this,&self_type::helper__uninit_op));
 }
 catch(...)
 {
  assert(false);
 }
}//~tag_dll__icuuc_v063

//helper methods ---------------------------------------------------------
ICU__Loader::tag_dll__icuuc_v063::dll_init_mutex_ptr
 ICU__Loader::tag_dll__icuuc_v063::helper__get_dll_init_mutex(os::t_ibp_os__dll* const pDLL)
{
 assert(pDLL);

 const wchar_t* const c_bugcheck_src
  =L"ICU__Loader::tag_dll__icuuc_v063::helper__get_dll_init_mutex";

 IBP_SmartObjectPtr
  spSvcObj
   (pDLL->get_service_obj
     (sm_DllInitSvcObjID,
      structure::make_closure_r(helper__create_dll_init_mutex)));

 assert(spSvcObj);

 dll_init_mutex_ptr
  spSvc
   (dynamic_cast<dll_init_mutex_type*>(spSvcObj.ptr()));

 IBP_BUG_CHECK__DETECT_BAD_OBJECT_NULL_PTR
  (spSvc,
   c_bugcheck_src,
   L"#001");

 return spSvc;
}//helper__get_dll_init_mutex

//------------------------------------------------------------------------
IBP_SmartObjectPtr ICU__Loader::tag_dll__icuuc_v063::helper__create_dll_init_mutex()
{
 return lib::structure::not_null_ptr
         (new dll_init_mutex_type());
}//helper__create_dll_init_mutex

//------------------------------------------------------------------------
void ICU__Loader::tag_dll__icuuc_v063::helper__init_op()
{
 icu::v063::api::UErrorCode icu_status
  =icu::v063::api::U_ZERO_ERROR;
 
 for(;;)
 {
  const t_ibp_string modulePath
   =win32lib::GetModuleFileName(this->get_dll_handle());

  const t_ibp_string moduleDir
   =os::t_ibp_os__path_utils::GetParentDir
     (modulePath).make_str();

  if(moduleDir.empty())
   break;

  assert(structure::test_prefix
            (modulePath.cbegin(),
             modulePath.cend(),
             moduleDir.cbegin(),
             moduleDir.cend())==moduleDir.cend());

  m_u_setDataDirectory.point()
   (structure::tstr_to_str(moduleDir).c_str());
 
  //define timefone files directory
  const t_ibp_string tzdataDir
   =os::t_ibp_os__path_utils::Concat
     (moduleDir,
      IBP_T("tzdata"));

  //! \todo [2023-07-29] maybe it need to check that this directory really exists?

  m_u_setTimeZoneFilesDirectory.point()
   (structure::tstr_to_str(tzdataDir).c_str(),
    &icu_status);

  if(icu_status!=icu::v063::api::U_ZERO_ERROR)
  {
   IBP_ErrorUtils::Throw__Error
    (E_FAIL,
     this->get_subsystem_id(),
     ibp_mce_icu__failed_to_tzdata_files_dir_1,
     icu_status);
  }//if

  break;
 }//for[ever]

 //-----------------------------------------
 m_u_init.point()
  (&icu_status);

 if(icu_status!=icu::v063::api::U_ZERO_ERROR)
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    this->get_subsystem_id(),
    ibp_mce_icu__failed_to_initialize_1,
    icu_status);
 }//if
}//helper__init_op

//------------------------------------------------------------------------
void ICU__Loader::tag_dll__icuuc_v063::helper__uninit_op()
{
 m_u_cleanup.point()();
}//helper__uninit_op

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader

ICU__Loader::tag_dll_ptr ICU__Loader::helper__create_icuuc_v063
                             (os::t_ibp_os__dll* const pICUUC_DLL,
                              const std::wstring&      dllVersion)
{
 assert(pICUUC_DLL);

 return lib::structure::not_null_ptr
         (new tag_dll__icuuc_v063
           (pICUUC_DLL,
            dllVersion));
}//helper__create_icuuc_v063

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
