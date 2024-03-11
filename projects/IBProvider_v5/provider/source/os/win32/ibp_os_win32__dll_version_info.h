////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_version_info.h
//! \brief   Класс для получения информации о версии DLL
//! \author  Kovalenko Dmitry
//! \date    11.09.2007
#ifndef _ibp_os_win32__dll_version_info_H_
#define _ibp_os_win32__dll_version_info_H_

#include <lcpi/lib/.config.h>

namespace lcpi{namespace ibp{namespace os{namespace win32{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_os_win32
//! @{
////////////////////////////////////////////////////////////////////////////////
//content

class t_ibp_os_win32__dll_version_info;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_os_win32__dll_version_info

/// <summary>
///  Класс для получения информации о версии DLL
/// </summary>
class t_ibp_os_win32__dll_version_info LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_ibp_os_win32__dll_version_info;

  t_ibp_os_win32__dll_version_info(const self_type&)=delete;
  self_type& operator = (const self_type&)=delete;

 public:
  /// VS_FIXEDFILEINFO::FileVersion
  std::wstring   m_file_version;

  /// VS_FIXEDFILEINFO::ProductVersion
  std::wstring   m_prod_version;

  /// Значение символьного параметра "ProductName"
  std::wstring   m_prod_name;

  /// Значение символьного параметра "FileDescription"
  std::wstring   m_file_descr;

  /// Значение символьного параметра "FileVersion"
  std::wstring   m_file_version_str;

  //! \brief Значение символьного параметра "ProductVersion"
  //!
  //! Это поле хранит реальную версию продукта
  std::wstring   m_prod_version_str;

 public:
  t_ibp_os_win32__dll_version_info();

 ~t_ibp_os_win32__dll_version_info();

  //interface ------------------------------------------------------------
  void swap(self_type& x);

  bool load(HINSTANCE hDLL);

  //selectors ------------------------------------------------------------
  /// <summary>
  ///  Возвращает строку с описанием модуля
  /// </summary>
  ///  В некоторых старых gds32.dll "ProductName" может быть пустым
  const std::wstring& prod_descr()const;

 private:
  struct tag_loader;
};//class t_ibp_os_win32__dll_version_info

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
