////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_charset_info.h
//! \brief   Конструкция для хранения описания кодовой страницей
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
///  Перечисление флагов кодовых страниц
/// </summary>
enum enum_db_charset_info_flag
{
 /// \brief Это NONE кодировка. Кодовая страница подключения на неё не влияет
 db_charset_info_flag__is_none         =0x0001,

 /// \brief Это OCTETS кодировка. Бинарные данные.
 db_charset_info_flag__is_octets       =0x0002,

 /// \brief Это UNICODE кодировка.
 db_charset_info_flag__is_unicode      =0x0004,

 /// \brief Это стабильная кодировка, на которую не влияет кодовая страница подключения.
 db_charset_info_flag__is_stable       =0x0010,
};//enum enum_db_charset_info_flag

/// <summary>
///  Тип для хранения флагов кодовой страницы
/// </summary>
typedef DWORD t_db_charset_info_flag;

////////////////////////////////////////////////////////////////////////////////
//class t_db_charset_info

/// <summary>
///  Описание кодовой страницы
/// </summary>
class t_db_charset_info
{
 private:
  typedef t_db_charset_info                      self_type;

 public: //typedefs ------------------------------------------------------
  ///тип объекта, хранящего имя кодовой страницы
  using charset_name_type
   =std::basic_string<db_charset_types::name_char_type>;

  using cs_name_box_type
   =structure::t_basic_const_str_box<db_charset_types::name_char_type>;

  ///Псевдоним типа для хранения флагов
  using flags_type
   =t_db_charset_info_flag;

 public:
  ///Название кодовой страницы
  charset_name_type name;

  ///Флаги кодовой страницы
  flags_type flags;

  ///Количество байт на один символ
  BYTE bytes_per_char;

  ///Минимальное количество байт на один символ
  BYTE min_bytes_per_char;

  ///Максимальное число UCS2 символов на один символ кодовой страницы
  BYTE ucs2_for_char;

 public:
  /// </summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  t_db_charset_info();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~t_db_charset_info();

 public:
  /// <summary>
  ///  Сравнение с именем кодовой страницы
  /// </summary>
  //! \param[in] x
  bool equal_name(const cs_name_box_type& x)const
  {
   //! \attention
   //!  Применяется прямое (точное) сравнение имен кодовых страниц

   return x.equal(this->name);
  }//equal_name

  /// <summary>
  ///  Тестирование эквивалентности по имени
  /// </summary>
  //! \param[in] x
  bool equal_name(const self_type& x)const
  {
   return this->equal_name(x.name);
  }//equal_name

 public:
  /// <summary>
  ///  Принадлежность к NONE-кодировке
  /// </summary>
  bool is_none()const
  {
   const flags_type f=db_charset_info_flag__is_none;

   return (this->flags&f)==f;
  }//is_none

  /// <summary>
  ///  Принадлежность к OCTETS-кодировке
  /// </summary>
  bool is_octets()const
  {
   const flags_type f=db_charset_info_flag__is_octets;

   return (this->flags&f)==f;
  }//is_octets

  /// <summary>
  ///  Принадлежность к UNICODE-кодировке
  /// </summary>
  bool is_unicode()const
  {
   const flags_type f=db_charset_info_flag__is_unicode;

   return (this->flags&f)==f;
  }//is_unicode

  /// <summary>
  ///  Принадлежность к стабильным кодовым страницам
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
