////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_loader.h
//! \brief   Реализация загрузчика DLL
//! \author  Kovalenko Dmitry
//! \date    29.06.2003
#ifndef _ibp_os_win32__dll_loader_H_
#define _ibp_os_win32__dll_loader_H_

#include "source/os/ibp_os__dll.h"
#include "source/ibp_char.h"

#include <ole_lib/ole_base.h>
#include <structure/stl/t_stl_map.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_ibp_os_win32__dll_loader;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_loader

/// <summary>
///  Загрузчик DLL
/// </summary>
class t_ibp_os_win32__dll_loader COMP_W000006_CLASS_FINAL
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(t_ibp_os__dll)
{
 private:
  typedef t_ibp_os_win32__dll_loader                  self_type;

  t_ibp_os_win32__dll_loader(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_smart_object_ptr<self_type>    self_ptr;

 public:
  /// <summary>
  ///  Конструктор инициализации. THROW
  /// </summary>
  explicit t_ibp_os_win32__dll_loader(t_ibp_str_box DLL_Name);

 private:
  /// <summary>
  ///  Деструктор
  /// </summary>
  virtual ~t_ibp_os_win32__dll_loader();

 public:
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
  //! \param[in] rSvcObjID
  //! \param[in] pfnServiceObjCreator
  //!  Pointer to the creator of a service object.
  //! \return
  //!  Not NULL.
  virtual IBP_SmartObjectPtr get_service_obj(REFGUID                 rSvcObjID,
                                             pfn_service_obj_creator pfnServiceObjCreator) COMP_W000004_OVERRIDE_FINAL;

 public:
  /// <summary>
  ///  Запрещаем выгрузку DLL из памяти
  /// </summary>
  void lock_in_memory();

  bool is_locked_in_memory()const;

 private:
  ///Название модуля
  const t_ibp_string m_DLL_Name;

  ///Дескриптор модуля
  HINSTANCE          m_hDLL;

  ///Признак заблокированности DLL в памяти
  LONG               m_NoUnLoad;

 private:
  typedef structure::t_multi_thread_traits                 thread_traits;
  typedef thread_traits::guard_type                        guard_type;
  typedef thread_traits::lock_guard_type                   lock_guard_type;

  typedef structure::t_stl_map
           <GUID,
            IBP_SmartObjectPtr,
            ole_lib::TGuidLess,
            IBP_MemoryAllocator>                           service_objects_map_type;

 private:
  guard_type                  m_ServiceObjs_Guard;
  service_objects_map_type    m_ServiceObjs;
};//class t_ibp_os_win32__dll_loader

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_loader

inline HINSTANCE t_ibp_os_win32__dll_loader::get_dll_handle()const
{
 return m_hDLL;
}//get_dll_handle

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
