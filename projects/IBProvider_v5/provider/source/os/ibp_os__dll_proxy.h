////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os
//! \file    ibp_os__dll.h
//! \brief   The proxy of a dynamic library (DLL) loader.
//! \author  Kovalenko Dmitry
//! \date    30.08.2022
#ifndef _ibp_os__dll_proxy_H_
#define _ibp_os__dll_proxy_H_

#include "source/os/ibp_os__dlls.h"

namespace lcpi{namespace ibp{namespace os{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os__dll_proxy

/// <summary>
///  The proxy of a dynamic library (DLL) loader.
/// </summary>
class t_ibp_os__dll_proxy COMP_W000006_CLASS_FINAL
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(t_ibp_os__dll)
{
 private:
  typedef t_ibp_os__dll_proxy                              self_type;

  t_ibp_os__dll_proxy(const self_type&);
  self_type& operator = (const self_type&);

  virtual ~t_ibp_os__dll_proxy();

 public:
  t_ibp_os__dll_proxy(t_ibp_os__dlls*                  pDLLs,
                      t_ibp_os__dll_loader::self_ptr&& spDllLoader);
  
  //interface -------------------------------------------------------
  /// <summary>
  ///  Получение дескриптора DLL
  /// </summary>
  virtual HINSTANCE get_dll_handle()const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Получение указателя на точку входа в DLL. THROW
  /// </summary>
  //! \param[in] point_name
  virtual FARPROC get_proc_address(LPCSTR point_name)const COMP_W000004_OVERRIDE_FINAL;//throw

  /// <summary>
  ///  Пытаемся получить указатель на точку входа в DLL.
  /// </summary>
  //! \param[in] point_name
  virtual FARPROC try_get_proc_address(LPCSTR point_name)const COMP_W000004_OVERRIDE_FINAL;

  /// <summary>
  ///  Getting a DLL service object. THROW.
  /// </summary>
  //! \param[in] rServiceObjID
  //! \param[in] pfnServiceObjCreator
  //!  Pointer to the creator of a service object.
  //! \return
  //!  Not NULL.
  virtual IBP_SmartInterfacePtr get_service_obj(REFGUID                 rServiceObjID,
                                                pfn_service_obj_creator pfnServiceObjCreator) COMP_W000004_OVERRIDE_FINAL;

 private:
  t_ibp_os__dlls::self_ptr const m_spDLLs;

  t_ibp_os__dll_loader::self_ptr m_spDllLoader;
};//class t_ibp_os__dll_proxy

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
