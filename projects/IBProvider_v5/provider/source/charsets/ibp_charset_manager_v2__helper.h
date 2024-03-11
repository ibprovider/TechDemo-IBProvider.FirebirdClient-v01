////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_charset
//! \file    ibp_charset_manager_v2__helper.h
//! \brief   Определение вспомогательных классов t_ibp_charset_manager_v2
//! \author  Kovalenko Dmitry
//! \date    18.11.2010
#ifndef _ibp_charset_manager_v2__helper_H_
#define _ibp_charset_manager_v2__helper_H_

#include "source/charsets/ibp_charset_manager_v2.h"

#include <lcpi/lib/structure/utilities/string/string_compare.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_charset
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_ibp_charset_manager_v2::tag_own_cs

/// <summary>
///  Структура для статической таблицы описания кодовой страницы
/// </summary>
class t_ibp_charset_manager_v2::tag_own_cs
{
 public:
  typedef db_obj::t_db_charset_ptr (*pfn_cs_creator)(const t_ibp_charset_manager_v2* mng);

 public:
  ///Название
  charset_name_ptr         name;

  ///Указатель на фабрику класса кодовой страницы
  pfn_cs_creator           creator;

  ///Указатель на перечисление стандартных collations
  const t_ibp_char* const* std_collations;
};//class t_ibp_charset_manager_v2::tag_own_cs

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_charset_manager_v2::tag_aliase

/// <summary>
///  Структура для описания псевдонима кодовой страницы
/// </summary>
class t_ibp_charset_manager_v2::tag_aliase
{
 public: //typedefs ------------------------------------------------------
  using cs_name_box_type
   =structure::t_basic_const_str_box<db_obj::t_db_charset_info::charset_name_type::value_type>;

 public:
  ///Название
  cs_name_box_type        name;

  ///Указатель на описание кодовой страницы
  const tag_own_cs*       own_cs;
};//class t_ibp_charset_manager_v2::tag_aliase

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_charset_manager_v2::tag_aliase_less_by_name

class t_ibp_charset_manager_v2::tag_aliase_less_by_name
{
 public: //typedefs ------------------------------------------------------
  using cs_name_box_type
   =structure::t_basic_const_str_box<db_obj::t_db_charset_info::charset_name_type::value_type>;

 public:
  tag_aliase_less_by_name()
  {
  }

#ifndef NDEBUG
  bool operator () (const tag_aliase& aliase1,const tag_aliase& aliase2)const
  {
   assert(!aliase1.name.empty());
   assert(!aliase2.name.empty());

   return helper__less(aliase1.name,aliase2.name);
  }//aliase1<aliase2
#endif

  bool operator () (const tag_aliase& aliase,cs_name_box_type::pointer name)const=delete;
  bool operator () (cs_name_box_type::pointer name,const tag_aliase& aliase)const=delete;

  bool operator () (const tag_aliase& aliase,const cs_name_box_type& name)const
  {
   assert(!aliase.name.empty());

   return helper__less(aliase.name,name);
  }//aliase<name

  bool operator () (const cs_name_box_type& name,const tag_aliase& aliase)const
  {
   assert(!aliase.name.empty());

   return helper__less(name,aliase.name);
  }//name<aliase

 private:
  static bool helper__less(const cs_name_box_type& n1,const cs_name_box_type& n2)
  {
   return lib::structure::string_compare_v2
           (n1.data(),
            n1.size(),
            n2.data(),
            n2.size())<0;
  }//helper__less
};//class t_ibp_charset_manager_v2::tag_aliase_less_by_name

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
