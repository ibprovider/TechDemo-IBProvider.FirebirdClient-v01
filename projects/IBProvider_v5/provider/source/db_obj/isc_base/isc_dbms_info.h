////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_dbms_info.h
//! \brief   Структура для хранения описания ISC-сервера, ISC-клиента
//! \author  Kovalenko Dmitry
//! \date    24.06.2008
#ifndef _isc_dbms_info_H_
#define _isc_dbms_info_H_

#include "source/db_obj/isc_base/isc_dbms_ids.h"
#include "source/error_services/ibp_error_codes.h"
#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_dbms_info

/// <summary>
///  Описание ISC-сервера, ISC-клиента
/// </summary>
class t_isc_dbms_info LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=t_isc_dbms_info;

 public: //typedefs ------------------------------------------------------
  using string_type
   =std::string;

  using string_type_N
   =lib::structure::t_value_with_null<string_type>;

  class tag_push_descr_ex;

 public:
  ///Описание полученное из первоисточника (сервер, VersionInfo клиента)
  string_type_N   descr_Ex;

  ///Внутренний идентификатор DBMS
  t_isc_dbms_id   id;

  ///Имя DBMS
  string_type     name;

  ///Версия DBMS
  string_type     version;

 public:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  t_isc_dbms_info();

  /// <summary>
  ///  Конструктор копирования
  /// </summary>
  t_isc_dbms_info(const self_type&);

  /// <summary>
  ///  Оператор копирования
  /// </summary>
  self_type& operator = (const self_type&);

  /// <summary>
  ///  Сброс вначальное состояние
  /// </summary>
  self_type& reset();

  /// <summary>
  ///  Обмен значениями
  /// </summary>
  self_type& swap(self_type& x);

  /// <summary>
  ///  Формирование строки с описанием
  /// </summary>
  string_type get_title()const;
};//class t_isc_dbms_info

////////////////////////////////////////////////////////////////////////////////
//non-member operators

inline bool operator == (const t_isc_dbms_info& x1,const t_isc_dbms_info& x2)
{
 return x1.descr_Ex==x2.descr_Ex &&
        x1.id      ==x2.id       &&
        x1.name    ==x2.name     &&
        x1.version ==x2.version;
}//operator ==

////////////////////////////////////////////////////////////////////////////////
//class t_isc_dbms_info::tag_push_descr_ex

class t_isc_dbms_info::tag_push_descr_ex LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=tag_push_descr_ex;

  self_type& operator = (const self_type&)=delete;

 public:
  tag_push_descr_ex(const self_type& x)
   :m_dbms_info(x.m_dbms_info)
  {;}

  explicit tag_push_descr_ex(const t_isc_dbms_info& dbms_info)
   :m_dbms_info(dbms_info)
  {;}

  const t_isc_dbms_info& dbms_info()const
  {
   return m_dbms_info;
  }

 private:
  const t_isc_dbms_info& m_dbms_info;
};//class t_isc_dbms_info::tag_push_descr_ex

////////////////////////////////////////////////////////////////////////////////

inline t_isc_dbms_info::tag_push_descr_ex push_descr_ex(const t_isc_dbms_info& dbms_info)
{
 return t_isc_dbms_info::tag_push_descr_ex(dbms_info);
}//push_descr_ex

////////////////////////////////////////////////////////////////////////////////
//class t_isc_dbms_info::tag_push_descr_ex

template<class TErr>
TErr& operator << (TErr& err,const t_isc_dbms_info::tag_push_descr_ex& x)
{
 if(x.dbms_info().descr_Ex.null())
  return err<<ibp::ibp_mce_text__not_defined1_0;

 return err<<x.dbms_info().descr_Ex.value();
}//operator <<

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/

namespace std{
////////////////////////////////////////////////////////////////////////////////

template<>
inline void swap(LCPI_IBP_NMS::isc_base::t_isc_dbms_info& x1,
                 LCPI_IBP_NMS::isc_base::t_isc_dbms_info& x2)
{
 x1.swap(x2);
}//swap

////////////////////////////////////////////////////////////////////////////////
}//namespace std
#endif
