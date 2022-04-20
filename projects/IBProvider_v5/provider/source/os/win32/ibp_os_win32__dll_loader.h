////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_loader.h
//! \brief   Реализация загрузчика DLL
//! \author  Kovalenko Dmitry
//! \date    29.06.2003
#ifndef _ibp_os_win32__dll_loader_H_
#define _ibp_os_win32__dll_loader_H_

#include "source/ibp_char.h"
#include "source/ibp_memory.h"

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
class t_ibp_os_win32__dll_loader:public IBP_SmartMemoryObject
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
  ///  Фабрика класса
  /// </summary>
  //! \param[in] DLL_Name
  //! \param[in] DLL_Lock_Rule
  //!  Правила блокировки DLL в памяти.
  //!
  //! <seealso cref="ibp::t_ibp_propval_dll_lock_rule"/>
  static self_ptr create(t_ibp_str_box DLL_Name,
                         long          DLL_Lock_Rule);

 public:
  /// <summary>
  ///  Получение дескриптора DLL
  /// </summary>
  HINSTANCE get_dll_handle()const;

  /// <summary>
  ///  Получение указателя на точку входа в DLL. THROW
  /// </summary>
  //! \param[in] point_name
  FARPROC get_proc_address(LPCSTR point_name)const;//throw

  /// <summary>
  ///  Пытаемся получить указатель на точку входа в DLL.
  /// </summary>
  //! \param[in] point_name
  FARPROC try_get_proc_address(LPCSTR point_name)const;

 private:
  /// <summary>
  ///  Запрещаем выгрузку DLL из памяти
  /// </summary>
  void lock_in_memory();

 private:
  ///Название модуля
  const t_ibp_string m_DLL_Name;

  ///Дескриптор модуля
  HINSTANCE          m_hDLL;

  ///Признак заблокированности DLL в памяти
  LONG               m_NoUnLoad;
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
