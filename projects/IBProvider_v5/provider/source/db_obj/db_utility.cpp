////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_utility.cpp
//! \brief   Сервисные конструкции низкоуровневой библиотеки доступа к серверу БД.
//! \author  Kovalenko Dmitry
//! \date    28.07.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/db_utility.h"

#include "source/error_services/ibp_error.h"

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////
//обработка ошибок

void throw_cantconvertvalue(t_dbtype const src_dbtype,
                            t_dbtype const dest_type)
{
 //DONE 3: Обработка ошибки конвертирования. Генерация понятного сообщения

 t_ibp_error exc(DB_E_CANTCONVERTVALUE,
                 ibp_mce_dbobj_cant_convert_value_between_internal_types_2);

 exc<<get_dbtype_name(src_dbtype)
    <<get_dbtype_name(dest_type);

 exc.raise_me();
}//throw_cantconvertvalue

////////////////////////////////////////////////////////////////////////////////
//выделение подстроки с версией

std::string extract_substr_with_version(const char* str)
{
 assert(str);

 if(!str)
  return std::string();

 //-------
 typedef structure::t_char_traits2<char> ch_traits2;

 //находим начало строки с номером версии
 for(;;++str)
 {
  if((*str)==0)
   return std::string();

  if(ch_traits2::is_digit(*str))
   break;
 }//for[ever]

 assert((*str)!=0);
 assert(ch_traits2::is_digit(*str));

 const char* const ver_s=str;

 for(++str;;str+=2)
 {
  for(;ch_traits2::is_digit(*str);++str);

  // if((*str)==0)
  //  break;

  if((*str)!='.')
   break;

  //смотрим, что у нас находится за точкой

  if(!ch_traits2::is_digit(str[1]))
   break;
 }//for[ever]

 assert(ver_s<str);

 //выдираем номер версии
 return std::string(ver_s,str);
}//extract_substr_with_version

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/
