////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_entry_point.h
//! \brief   Конструкции для подключения к точкам входа DLL.
//! \author  Kovalenko Dmitry
//! \date    26.04.2003
#ifndef _ibp_os_win32__dll_entry_point_H_
#define _ibp_os_win32__dll_entry_point_H_

#include "source/os/win32/ibp_os_win32__dll_loader.h"

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//contanings

template<class TFunc>
class t_ibp_os_win32__dll_entry_point;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_entry_point

/// <summary>
///  Шаблон подключения к точке входа DLL
/// </summary>
template<class TFunc>
class t_ibp_os_win32__dll_entry_point
{
 private:
  typedef t_ibp_os_win32__dll_entry_point<TFunc>         self_type;

  t_ibp_os_win32__dll_entry_point(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef TFunc                                          func_type;

  typedef t_ibp_os_win32__dll_loader                     dll_type;

  typedef dll_type::self_ptr                             dll_ptr;

 public: //---------------------------------------------------------------
  /// <summary>
  ///  Конструктор инициализации
  /// </summary>
  //! \param[in] pDLL
  //! \param[in] point_name
  t_ibp_os_win32__dll_entry_point(dll_type* const pDLL,
                                  LPCSTR    const point_name)
   :m_spDLL(structure::not_null_ptr(pDLL))
   ,m_point_name(point_name)
   ,m_point(nullptr)
  {
   assert(m_spDLL);
   assert(m_point_name!=nullptr);
   assert(m_point==nullptr); // :)
  }

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~t_ibp_os_win32__dll_entry_point()
  {
  }

  /// <summary>
  ///  Символьное имя функции
  /// </summary>
  LPCSTR point_name()const
  {
   return m_point_name;
  }//point_name

  /// <summary>
  ///  Получение указателя на экспортируемую функцию. THROW
  /// </summary>
  //! \return
  //!  Function's pointer
  //!
  //! Если точка входа отсутствует, то генерируется исключение
  const func_type point() const
  {
   if(m_point==nullptr)
   {
    InterlockedCompareExchangePointer
     (reinterpret_cast<void* volatile*>(&m_point),
      m_spDLL->get_proc_address(m_point_name), //throw
      NULL);
   }//if

   assert(m_point!=nullptr);

   return m_point;
  }//point

  /// <summary>
  ///  Тестирование наличия у DLL экспортируемой функции
  /// </summary>
  bool test_point() const
  {
   if(m_point==nullptr)
   {
    if(FARPROC const p=m_spDLL->try_get_proc_address(m_point_name))
    {
     //запоминаем полученный адрес
     InterlockedCompareExchangePointer
      (reinterpret_cast<void* volatile*>(&m_point),
       p,
       NULL);
    }//if
   }//if

   return m_point!=nullptr;
  }//test_point

 private:
  ///Указатель на загрузчик DLL
  dll_ptr const m_spDLL;

  ///Имя точки входа
  LPCSTR  const m_point_name;

  ///Указатель на точку входа
  mutable func_type volatile m_point;
};//class t_ibp_os_win32__dll_entry_point

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
