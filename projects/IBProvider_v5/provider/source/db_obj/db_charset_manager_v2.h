////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_charset_manager_v2.h
//! \brief   ��������� ���������� �������� ���������� [V2].
//! \author  Kovalenko Dmitry
//! \date    05.10.2008
#ifndef _db_charset_manager_v2_H_
#define _db_charset_manager_v2_H_

#include <source/db_obj/db_charset.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////
//����������� ����� ��� ��������� ���������� ������� ��������

/// <summary>
///  ������������ ������ ��������� ����������� ������� �������
/// </summary>
enum tag_db_cs_mng_flags
{
 db_cs_mng_flag__get_txt_cs_only     =0x01,
};//enum tag_db_cs_mng_flags

///��� ������ ��� ��������� ������� �������
typedef DWORD t_db_cs_mng_flags;

////////////////////////////////////////////////////////////////////////////////
//enum class db_cs_id

/// <summary>
///  �������������� ��������� ������� ��������
/// </summary>
//! \attention
//!  ���������� t_db_charset_manager_v2 ���������� ��� ��������� � �������� ��������.
enum class db_cs_id:unsigned
{
 //������� �������� �����������
 cn=0,

 //������� �������� ������������
 user=1,

 //������� �������� ��� ��������� NONE
 none=2,
 
 //������� �������� ��������� ������ ���� ������
 ods=3,
};//enum class db_cs_id

////////////////////////////////////////////////////////////////////////////////
//class t_db_charset_manager_v2

/// <summary>
///  ��������� ���������� �������� ���������� [V2].
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_db_charset_manager_v2
 :public t_db_smart_interface
{
 public: //typedefs ------------------------------------------------------
  using cs_name_box_type
   =structure::t_basic_const_str_box<t_db_charset_info::charset_name_type::value_type>;

 public: //interface -----------------------------------------------------

  /// <summary>
  ///  ��������� ������� �������� �� �����
  /// </summary>
  //! \param[in] cs_name
  //! \param[in] flags
  virtual t_db_charset_const_ptr get_charset(const cs_name_box_type& cs_name,
                                             t_db_cs_mng_flags       flags)=0;

  /// <summary>
  ///  ��������� ������� �������� �� ��������������
  /// </summary>
  //! \param[in] cs_id
  virtual t_db_charset_const_ptr get_charset(db_cs_id cs_id)=0;

 public: //��������������� ��������� -------------------------------------

  /// <summary>
  ///  ��������� ������� �������� �����������
  /// </summary>
  t_db_charset_const_ptr get_cn_charset();

  /// <summary>
  ///  ��������� ������� �������� ������������
  /// </summary>
  t_db_charset_const_ptr get_user_charset();

  /// <summary>
  ///  ��������� ������� �������� ��� ��������� NONE
  /// </summary>
  t_db_charset_const_ptr get_none_charset();

  /// <summary>
  ///  ��������� ������� �������� ODS
  /// </summary>
  t_db_charset_const_ptr get_ods_charset();
};//class t_db_charset_manager_v2

////////////////////////////////////////////////////////////////////////////////
//class t_db_charset_manager_v2

inline t_db_charset_const_ptr t_db_charset_manager_v2::get_cn_charset()
{
 return this->get_charset(db_cs_id::cn);
}//get_cn_charset

//------------------------------------------------------------------------
inline t_db_charset_const_ptr t_db_charset_manager_v2::get_user_charset()
{
 return this->get_charset(db_cs_id::user);
}//get_user_charset

//------------------------------------------------------------------------
inline t_db_charset_const_ptr t_db_charset_manager_v2::get_none_charset()
{
 return this->get_charset(db_cs_id::none);
}//get_none_charset

//------------------------------------------------------------------------
inline t_db_charset_const_ptr t_db_charset_manager_v2::get_ods_charset()
{
 return this->get_charset(db_cs_id::ods);
}//get_ods_charset

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
