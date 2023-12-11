////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/external/icu/ibp_external__icu__loader.h"
#include "source/external/icu/v003/ibp_external__icu_v003__api.h"

#include "source/os/ibp_os__dll_entry_point.h"
#include "source/os/ibp_os__dll_init_mutex.h"
#include "source/os/ibp_os__path_utils.h"

#include "source/error_services/ibp_error_bug_check.h"

#include <win32lib/win32lib.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll__icuuc_v003

#define DEF_ICU_POINT(func_name)                                          \
 ibp::os::ibp_os__dll_entry_point<icu::v003::api::t_fn_##func_name*> m_##func_name

class ICU__Loader::tag_dll__icuuc_v003 LCPI_CPP_CFG__CLASS__FINAL
 :public ICU__Loader::tag_dll
{
 private:
  using self_type=tag_dll__icuuc_v003;
  using inherited=ICU__Loader::tag_dll;

  tag_dll__icuuc_v003(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

  virtual ~tag_dll__icuuc_v003();

 public:
  tag_dll__icuuc_v003(os::t_ibp_os__dll*  pDLL,
                      const std::wstring& dllVersion);

 private:
  typedef os::t_ibp_os__dll_init_mutex           dll_init_mutex_type;
  typedef os::t_ibp_os__dll_init_mutex::self_ptr dll_init_mutex_ptr;

 private:
  static t_ibp_subsystem_id get_subsystem_id()
  {
   return ibp_subsystem__icu_api_v003;
  }//get_subsystem_id

 private:
  static dll_init_mutex_ptr helper__get_dll_init_mutex(os::t_ibp_os__dll* pDLL);

  static IBP_SmartObjectPtr helper__create_dll_init_mutex();

  void helper__init_op();

  void helper__uninit_op();

 private:
  DEF_ICU_POINT(u_setDataDirectory);

  DEF_ICU_POINT(u_init);
  DEF_ICU_POINT(u_cleanup);

 private:
  /// DLL initialization mutex
  dll_init_mutex_ptr const m_spDllInitMutex;

 private:
  static const GUID sm_DllInitSvcObjID;
};//class ICU__Loader::tag_dll__icuuc_v003

#undef DEF_ICU_POINT

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll__icuuc_v003

const GUID ICU__Loader::tag_dll__icuuc_v003::sm_DllInitSvcObjID
 ={0x1D9FB5DF,0xD560,0x42A2,{0xB9,0x88,0x68,0x30,0xA1,0xE8,0x6E,0xB3}};

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll__icuuc_v003

#define INIT_ICU_POINT(func_name)  \
 m_##func_name(pDLL,#func_name"_3_0")

ICU__Loader::tag_dll__icuuc_v003::tag_dll__icuuc_v003
                             (os::t_ibp_os__dll* const pDLL,
                              const std::wstring&      dllVersion)
 :inherited(pDLL,dllVersion)
 ,INIT_ICU_POINT(u_setDataDirectory)
 ,INIT_ICU_POINT(u_init)
 ,INIT_ICU_POINT(u_cleanup)
 ,m_spDllInitMutex(helper__get_dll_init_mutex(pDLL))
{
 assert(m_spDllInitMutex);

 //---------------------------
 //
 // Initialization of pointers to primary functions.
 //

 m_u_setDataDirectory.point();
 m_u_init.point();
 m_u_cleanup.point();

 //---------------------------
 m_spDllInitMutex->do_initialize
  (structure::make_closure_r(this,&self_type::helper__init_op)); //throw
}//tag_dll__icuuc_v003

#undef INIT_ICU_POINT

//------------------------------------------------------------------------
ICU__Loader::tag_dll__icuuc_v003::~tag_dll__icuuc_v003()
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
}//~tag_dll__icuuc_v003

//helper methods ---------------------------------------------------------
ICU__Loader::tag_dll__icuuc_v003::dll_init_mutex_ptr
 ICU__Loader::tag_dll__icuuc_v003::helper__get_dll_init_mutex(os::t_ibp_os__dll* const pDLL)
{
 assert(pDLL);

 const wchar_t* const c_bugcheck_src
  =L"ICU__Loader::tag_dll__icuuc_v003::helper__get_dll_init_mutex";

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
IBP_SmartObjectPtr ICU__Loader::tag_dll__icuuc_v003::helper__create_dll_init_mutex()
{
 return lib::structure::not_null_ptr
         (new dll_init_mutex_type());
}//helper__create_dll_init_mutex

//------------------------------------------------------------------------
void ICU__Loader::tag_dll__icuuc_v003::helper__init_op()
{
 {
  const t_ibp_string modulePath
   =win32lib::GetModuleFileName(this->get_dll_handle());

  const t_ibp_string moduleDir
   =os::t_ibp_os__path_utils::GetParentDir
     (modulePath).make_str();

  if(!moduleDir.empty())
  {
   assert(structure::test_prefix
            (modulePath.cbegin(),
             modulePath.cend(),
             moduleDir.cbegin(),
             moduleDir.cend())==moduleDir.cend());

   m_u_setDataDirectory.point()(structure::tstr_to_str(moduleDir).c_str());
  }//if
 }//local

 //-----------------------------------------
 icu::v003::api::UErrorCode icu_status=icu::v003::api::U_ZERO_ERROR;

 m_u_init.point()(&icu_status);

 if(icu_status!=icu::v003::api::U_ZERO_ERROR)
 {
  IBP_ErrorUtils::Throw__Error
   (E_FAIL,
    this->get_subsystem_id(),
    ibp_mce_icu__failed_to_initialize_1,
    icu_status);
 }//if
}//helper__init_op

//------------------------------------------------------------------------
void ICU__Loader::tag_dll__icuuc_v003::helper__uninit_op()
{
 m_u_cleanup.point()();
}//helper__uninit_op

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader

ICU__Loader::tag_dll_ptr ICU__Loader::helper__create_icuuc_v003
                             (os::t_ibp_os__dll* const pICUUC_DLL,
                              const std::wstring&      dllVersion)
{
 assert(pICUUC_DLL);

 return lib::structure::not_null_ptr
         (new tag_dll__icuuc_v003
           (pICUUC_DLL,
            dllVersion));
}//helper__create_icuuc_v003

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
