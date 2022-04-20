////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_charset_info.h
//! \brief   ����������� ��� �������� �������� ������� ���������
//! \author  Kovalenko Dmitry
//! \date    05.10.2008
#ifndef _db_charset_info_H_
#define _db_charset_info_H_

#include "source/db_obj/db_charset_types.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������ ������� �������
/// </summary>
enum enum_db_charset_info_flag
{
 /// \brief ��� NONE ���������. ������� �������� ����������� �� �� �� ������
 db_charset_info_flag__is_none         =0x0001,

 /// \brief ��� OCTETS ���������. �������� ������.
 db_charset_info_flag__is_octets       =0x0002,

 /// \brief ��� UNICODE ���������.
 db_charset_info_flag__is_unicode      =0x0004,

 /// \brief ��� ���������� ���������, �� ������� �� ������ ������� �������� �����������.
 db_charset_info_flag__is_stable       =0x0010,
};//enum enum_db_charset_info_flag

/// <summary>
///  ��� ��� �������� ������ ������� ��������
/// </summary>
typedef DWORD t_db_charset_info_flag;

////////////////////////////////////////////////////////////////////////////////
//class t_db_charset_info

/// <summary>
///  �������� ������� ��������
/// </summary>
class t_db_charset_info
{
 private:
  typedef t_db_charset_info                      self_type;

 public: //typedefs ------------------------------------------------------
  ///��� �������, ��������� ��� ������� ��������
  using charset_name_type
   =std::basic_string<db_charset_types::name_char_type>;

  using cs_name_box_type
   =structure::t_basic_const_str_box<db_charset_types::name_char_type>;

  ///��������� ���� ��� �������� ������
  using flags_type
   =t_db_charset_info_flag;

 public:
  ///�������� ������� ��������
  charset_name_type name;

  ///����� ������� ��������
  flags_type flags;

  ///���������� ���� �� ���� ������
  BYTE bytes_per_char;

  ///����������� ���������� ���� �� ���� ������
  BYTE min_bytes_per_char;

  ///������������ ����� UCS2 �������� �� ���� ������ ������� ��������
  BYTE ucs2_for_char;

 public:
  /// </summary>
  ///  ����������� ��-���������
  /// </summary>
  t_db_charset_info();

  /// <summary>
  ///  ����������
  /// </summary>
 ~t_db_charset_info();

 public:
  /// <summary>
  ///  ��������� � ������ ������� ��������
  /// </summary>
  //! \param[in] x
  bool equal_name(const cs_name_box_type& x)const
  {
   //! \attention
   //!  ����������� ������ (������) ��������� ���� ������� �������

   return x.equal(this->name);
  }//equal_name

  /// <summary>
  ///  ������������ ��������������� �� �����
  /// </summary>
  //! \param[in] x
  bool equal_name(const self_type& x)const
  {
   return this->equal_name(x.name);
  }//equal_name

 public:
  /// <summary>
  ///  �������������� � NONE-���������
  /// </summary>
  bool is_none()const
  {
   const flags_type f=db_charset_info_flag__is_none;

   return (this->flags&f)==f;
  }//is_none

  /// <summary>
  ///  �������������� � OCTETS-���������
  /// </summary>
  bool is_octets()const
  {
   const flags_type f=db_charset_info_flag__is_octets;

   return (this->flags&f)==f;
  }//is_octets

  /// <summary>
  ///  �������������� � UNICODE-���������
  /// </summary>
  bool is_unicode()const
  {
   const flags_type f=db_charset_info_flag__is_unicode;

   return (this->flags&f)==f;
  }//is_unicode

  /// <summary>
  ///  �������������� � ���������� ������� ���������
  /// </summary>
  bool is_stable()const
  {
   const flags_type f=db_charset_info_flag__is_stable;

   return (this->flags&f)==f;
  }//is_stable
};//class t_db_charset_info

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
