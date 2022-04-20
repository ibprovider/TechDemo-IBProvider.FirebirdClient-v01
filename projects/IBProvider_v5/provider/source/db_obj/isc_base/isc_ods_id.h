////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_ods_id.h
//! \brief   Конструкция для представления идентификатора ODS
//! \author  Kovalenko Dmitry
//! \date    18.11.2009
#ifndef _isc_ods_id_H_
#define _isc_ods_id_H_

#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_ods_id

/// <summary>
///  Идентификатор версии ODS
/// </summary>
class t_isc_ods_id
{
 private:
  typedef t_isc_ods_id                      self_type;

 public: //typedefs ------------------------------------------------------
  typedef unsigned long                     num_type;

 public:
  ///Старший номер версии
  num_type  major_num;

  ///Младший номер версии
  num_type  minor_num;

 public:
  //! \brief
  //!  Конструктор по-умолчанию
  t_isc_ods_id()
   :major_num(0)
   ,minor_num(0)
  {;}

  //! \brief
  //!  Конструктор инициализации
  //! \param[in] _major_num
  //! \param[in] _minor_num
  t_isc_ods_id(num_type const _major_num,
               num_type const _minor_num)
   :major_num(_major_num)
   ,minor_num(_minor_num)
  {;}

  //! \brief
  //!  Получение версии ODS в виде WSTR-строки
  std::wstring as_wstr()const
  {
   return structure::wstr_formatter(L"%1.%2")
           <<this->major_num
           <<this->minor_num
           <<structure::str;
  }//as_wstr

  //! \brief
  //!  Получение версии ODS в виде STR-строки
  std::string as_str()const
  {
   return structure::str_formatter("%1.%2")
           <<this->major_num
           <<this->minor_num
           <<structure::str;
  }//as_str

  //! \brief
  //!  Оператор сравнения '<'
  //! \param[in] x
  bool operator < (const self_type& x)const
  {
   if(this->major_num<x.major_num)
    return true;

   if(x.major_num<this->major_num)
    return false;

   assert(x.major_num==this->major_num);

   return this->minor_num<x.minor_num;
  }//operator <

  //! \brief
  //!  Оператор сравнения '<='
  //! \param[in] x
  bool operator <= (const self_type& x)const
  {
   if(this->major_num<x.major_num)
    return true;

   if(x.major_num<this->major_num)
    return false;

   assert(x.major_num==this->major_num);

   return this->minor_num<=x.minor_num;
  }//operator <=
};//class t_isc_ods_id

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
