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
#include <lcpi/lib/structure/stl/t_stl_map.h>
#include <lcpi/lib/structure/mt/t_guard.h>
#include <lcpi/lib/structure/mt/t_lock_guard.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class t_ibp_os_win32__dll_loader;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_loader

/// <summary>
///  Загрузчик DLL
/// </summary>
class t_ibp_os_win32__dll_loader LCPI_CPP_CFG__CLASS__FINAL
 :public IBP_DEF_INTERFACE_IMPL_DYNAMIC(t_ibp_os__dll)
{
 private:
  using self_type=t_ibp_os_win32__dll_loader;

  t_ibp_os_win32__dll_loader(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  using self_ptr=lib::structure::t_smart_object_ptr<self_type>;

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
  virtual HINSTANCE get_dll_handle()const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Получение указателя на точку входа в DLL. THROW
  /// </summary>
  //! \param[in] point_name
  virtual FARPROC get_proc_address(LPCSTR point_name)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;//throw

  /// <summary>
  ///  Пытаемся получить указатель на точку входа в DLL.
  /// </summary>
  //! \param[in] point_name
  virtual FARPROC try_get_proc_address(LPCSTR point_name)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

  /// <summary>
  ///  Getting a DLL service object. THROW.
  /// </summary>
  //! \param[in] rSvcObjID
  //! \param[in] fnServiceObjCreator
  //!  The creator of a service object.
  //! \return
  //!  Not NULL.
  virtual IBP_SmartObjectPtr get_service_obj(REFGUID                  rSvcObjID,
                                             service_obj_creator_type fnServiceObjCreator) LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

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
  unsigned           m_NoUnLoad;

 private:
  using guard_type
   =lib::structure::mt::t_guard;

  using lock_guard_type
   =lib::structure::mt::t_lock_guard<guard_type>;

  using service_objects_map_type
   =lib::structure::t_stl_map
     <GUID,
      IBP_SmartObjectPtr,
      ole_lib::TGuidLess,
      IBP_MemoryAllocator>;

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
