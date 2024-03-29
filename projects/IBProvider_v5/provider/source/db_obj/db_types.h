////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_types.h
//! \brief   Определение описаний и идентификаторов типов данных
//! \author  Kovalenko Dmitry
//! \date    18.03.2003
#ifndef _db_types_H_
#define _db_types_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/db_obj/db_datatypes.h"
#include "source/db_obj/db_memory.h"

#include <lcpi/lib/structure/t_value_with_null.h>
#include <lcpi/lib/structure/stl/t_stl_vector.h>
#include <string>
#include <cstdint>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! @{
////////////////////////////////////////////////////////////////////////////////

#define _SQL_T(text)                                L##text

#define _SQL_WCSCHR(str,symbol)                     wcschr(str,symbol)

////////////////////////////////////////////////////////////////////////////////
//Тип, используемый для определения имен объектов базы данных

/// Тип для определения названия объекта БД
using t_db_object_name
 =std::wstring;

/// Тип для определения названия объекта БД с NULL-состоянием
using t_db_object_name_n
 =lib::structure::t_value_with_null<t_db_object_name>;

/// Тип для представления строки
using t_db_string
 =std::wstring;

/// Тип для представления строки с NULL-состоянием
using t_db_string_n
 =lib::structure::t_value_with_null<t_db_string>;

/// Тип для представления символа
using t_db_char
 =t_db_string::value_type;

using t_db_utf32
 =std::uint32_t;

/// Контейнер для хранения имен объектов БД
using t_db_object_name_array
 =lib::structure::t_stl_vector<t_db_object_name,t_db_memory_allocator>;

////////////////////////////////////////////////////////////////////////////////
//struct t_db_sql_traits

struct t_db_sql_traits LCPI_CPP_CFG__CLASS__FINAL
{
 using char_type
  =t_db_char;

 using input_type
  =const lib::structure::t_basic_const_str_box<char_type>;

 using input_iterator
  =input_type::iterator;
};//struct t_db_sql_traits

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Тип для представления уровня изоляции транзакции
/// </summary>
typedef ISOLEVEL t_db_tr_isolevel;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Перечисление типов транзакции
/// </summary>
enum t_db_tr_kind
{
 ///Не определено
 db_tr_kind__none        =0,

 ///Обычная транзакция
 db_tr_kind__std         =1,

 ///Участник распределенной транзакции
 db_tr_kind__dtc         =2,
};//enum t_db_tr_kind

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Перечисление идентификаторов флагов состояния данных
/// </summary>
enum tag_enum_dbstatus
{
 dbstatus2__ok                =0,
 dbstatus2__is_null           =1,
 dbstatus2__default           =2,
};//enum tag_enum_dbstatus

typedef tag_enum_dbstatus  t_dbstatus;

const wchar_t* get_dbstatus2_name(t_dbstatus status);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
#endif
