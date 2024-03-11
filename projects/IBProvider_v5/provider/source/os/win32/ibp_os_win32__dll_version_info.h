////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_os_win32
//! \file    ibp_os_win32__dll_version_info.h
//! \brief   ����� ��� ��������� ���������� � ������ DLL
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
///  ����� ��� ��������� ���������� � ������ DLL
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

  /// �������� ����������� ��������� "ProductName"
  std::wstring   m_prod_name;

  /// �������� ����������� ��������� "FileDescription"
  std::wstring   m_file_descr;

  /// �������� ����������� ��������� "FileVersion"
  std::wstring   m_file_version_str;

  //! \brief �������� ����������� ��������� "ProductVersion"
  //!
  //! ��� ���� ������ �������� ������ ��������
  std::wstring   m_prod_version_str;

 public:
  t_ibp_os_win32__dll_version_info();

 ~t_ibp_os_win32__dll_version_info();

  //interface ------------------------------------------------------------
  void swap(self_type& x);

  bool load(HINSTANCE hDLL);

  //selectors ------------------------------------------------------------
  /// <summary>
  ///  ���������� ������ � ��������� ������
  /// </summary>
  ///  � ��������� ������ gds32.dll "ProductName" ����� ���� ������
  const std::wstring& prod_descr()const;

 private:
  struct tag_loader;
};//class t_ibp_os_win32__dll_version_info

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms win32*/}/*nms os*/}/*nms ibp*/}/*nms lcpi*/
#endif
