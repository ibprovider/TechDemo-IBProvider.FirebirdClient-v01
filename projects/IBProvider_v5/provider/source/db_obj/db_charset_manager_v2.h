////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_charset_manager_v2.h
//! \brief   Интерфейс управления кодовыми страницами [V2].
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
//Управляющие флаги для получения конвертора кодовой страницы

/// <summary>
///  Перечисление флагов получения конверторов кодовых страниц
/// </summary>
enum tag_db_cs_mng_flags
{
 db_cs_mng_flag__get_txt_cs_only     =0x01,
};//enum tag_db_cs_mng_flags

///Тип флагов для получения кодовых страниц
typedef DWORD t_db_cs_mng_flags;

////////////////////////////////////////////////////////////////////////////////
//enum class db_cs_id

/// <summary>
///  Идентификаторы категории кодовой страницы
/// </summary>
//! \attention
//!  Реализации t_db_charset_manager_v2 используют эти категории в качестве индексов.
enum class db_cs_id:unsigned
{
 //Кодовая страница подключения
 cn=0,

 //Кодовая страница пользователя
 user=1,

 //Кодовая страница для обработки NONE
 none=2,
 
 //Кодовая страница системных таблиц базы данных
 ods=3,
};//enum class db_cs_id

////////////////////////////////////////////////////////////////////////////////
//class t_db_charset_manager_v2

/// <summary>
///  Интерфейс управления кодовыми страницами [V2].
/// </summary>
class LCPI_CPP_CFG__DECLSPEC__NOVTABLE t_db_charset_manager_v2
 :public t_db_smart_interface
{
 public: //typedefs ------------------------------------------------------
  using cs_name_box_type
   =structure::t_basic_const_str_box<t_db_charset_info::charset_name_type::value_type>;

 public: //interface -----------------------------------------------------

  /// <summary>
  ///  Получение кодовой страницы по имени
  /// </summary>
  //! \param[in] cs_name
  //! \param[in] flags
  virtual t_db_charset_const_ptr get_charset(const cs_name_box_type& cs_name,
                                             t_db_cs_mng_flags       flags)=0;

  /// <summary>
  ///  Получение кодовой страницы по идентификатору
  /// </summary>
  //! \param[in] cs_id
  virtual t_db_charset_const_ptr get_charset(db_cs_id cs_id)=0;

 public: //вспомогательный интерфейс -------------------------------------

  /// <summary>
  ///  Получение кодовой страницы подключения
  /// </summary>
  t_db_charset_const_ptr get_cn_charset();

  /// <summary>
  ///  Получение кодовой страницы пользователя
  /// </summary>
  t_db_charset_const_ptr get_user_charset();

  /// <summary>
  ///  Получение кодовой страницы для обработки NONE
  /// </summary>
  t_db_charset_const_ptr get_none_charset();

  /// <summary>
  ///  Получение кодовой страницы ODS
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
