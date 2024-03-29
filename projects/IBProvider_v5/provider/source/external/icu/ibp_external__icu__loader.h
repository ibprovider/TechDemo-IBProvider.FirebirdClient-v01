////////////////////////////////////////////////////////////////////////////////
//ICU Library Helpers.
//                                                 Kovalenko Dmitry. 26.06.2023.
#ifndef _ibp_external__icu__loader_H_
#define _ibp_external__icu__loader_H_

#include "source/external/icu/ibp_external__icu__dll.h"
#include "source/ibp_char.h"

#include <lcpi/lib/structure/mt/t_guard.h>
#include <lcpi/lib/structure/mt/t_lock_guard.h>

namespace lcpi{namespace ibp{namespace external{namespace icu{
////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader

class ICU__Loader LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_SmartMemoryObject
{
 private:
  using self_type=ICU__Loader;

  ICU__Loader(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

  typedef t_ibp_string        string_type;

 private:
  ICU__Loader(const string_type& icuuc_library,
              const string_type& icuin_library);

 ~ICU__Loader();

 public:
  static self_ptr create(const string_type& icuuc_library,
                         const string_type& icuin_library);

  //interface ------------------------------------------------------------
  ICU__Dll_Ptr get_dll__icuuc();

  ICU__Dll_Ptr get_dll__icuin();

 private:
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

 private:
  class tag_dll;

  using tag_dll_ptr=lib::structure::t_smart_object_ptr<tag_dll>;

  class tag_dll__icuuc_v003;
  class tag_dll__icuuc_v052;
  class tag_dll__icuuc_v063;

 private:
  tag_dll_ptr helper__get_icuuc();
  tag_dll_ptr helper__get_icuin();

 private:
  static tag_dll_ptr helper__create_icuuc
                             (os::t_ibp_os__dll* pICUUC_DLL);

  static tag_dll_ptr helper__create_icuuc_v003
                             (os::t_ibp_os__dll*  pICUUC_DLL,
                              const std::wstring& dllVersion);

  static tag_dll_ptr helper__create_icuuc_v052
                             (os::t_ibp_os__dll*  pICUUC_DLL,
                              const std::wstring& dllVersion);

  static tag_dll_ptr helper__create_icuuc_v063
                             (os::t_ibp_os__dll*  pICUUC_DLL,
                              const std::wstring& dllVersion);

 private:
  tag_dll_ptr helper__create_icuin
                      (os::t_ibp_os__dll*  pICUIN_DLL);

  tag_dll_ptr helper__create_icuin__type01
                      (os::t_ibp_os__dll*  pICUIN_DLL,
                       const std::wstring& dllVersion);

 private:
  const string_type m_icuin_library;
  const string_type m_icuuc_library;

 private:
  guard_type m_guard;

  tag_dll_ptr m_dll__icuin;
  tag_dll_ptr m_dll__icuuc;
};//class ICU__Loader

////////////////////////////////////////////////////////////////////////////////
//class ICU__Loader::tag_dll

class ICU__Loader::tag_dll
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(ICU__Dll)
{
 private:
  using self_type=tag_dll;

  tag_dll(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

 protected:
  virtual ~tag_dll();

 public:
  tag_dll(os::t_ibp_os__dll*  pDLL,
          const std::wstring& dllVersion);

  //own interface --------------------------------------------------------
  const std::wstring& get_dll_version()const;

  //dll interface --------------------------------------------------------
  virtual HINSTANCE get_dll_handle()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual FARPROC get_proc_address(LPCSTR point_name)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;//throw

  virtual FARPROC try_get_proc_address(LPCSTR point_name)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  virtual IBP_SmartObjectPtr get_service_obj(REFGUID                  rServiceObjID,
                                             service_obj_creator_type fnServiceObjCreator) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  os::t_ibp_os__dll_ptr const m_spDLL;
  std::wstring          const m_DllVersion;
};//class ICU__Loader::tag_dll

////////////////////////////////////////////////////////////////////////////////
}/*nms icu*/}/*nms external*/}/*nms ibp*/}/*nms lcpi*/
#endif
