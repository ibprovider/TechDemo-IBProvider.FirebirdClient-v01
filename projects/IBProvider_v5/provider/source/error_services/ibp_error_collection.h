////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_collection.h
//! \brief   Класс для создания коллекции ошибок
//! \author  Kovalenko Dmitry
//! \date    18.02.2003
#ifndef _ibp_error_collection_H_
#define _ibp_error_collection_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error_adapter.h"
#include "source/error_services/ibp_error_elements.h"
#include "source/error_services/ibp_error_records_r.h"
#include "source/ibp_memory.h"

#include <structure/t_smart_vector.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_ibp_error_collection;

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_collection

/// <summary>
///  Класс для создания коллекции ошибок
/// </summary>
class t_ibp_error_collection COMP_W000006_CLASS_FINAL
 :public t_ibp_error_adapter
 ,public t_ibp_error_records_r
{
 private:
  typedef t_ibp_error_collection                self_type;

  t_ibp_error_collection(const self_type&);
  self_type& operator = (const self_type&);

 public:
  /// <summary>
  ///  Конструктор по-умолчанию
  /// </summary>
  t_ibp_error_collection();

  /// <summary>
  ///  Деструктор
  /// </summary>
 ~t_ibp_error_collection();

  //container interface --------------------------------------------------

  bool empty()const;

  //t_err_records_r interface --------------------------------------------

  /// <summary>
  ///  Получение количества ошибок
  /// </summary>
  virtual size_t get_record_count()const COMP_W000004_OVERRIDE_FINAL; //abstract

  /// <summary>
  ///  Получение описания одиночной ошибки
  /// </summary>
  //! \param[in] record_num
  virtual structure::t_err_record::self_ptr get_record(size_t record_num)const COMP_W000004_OVERRIDE_FINAL; //abstract

  //t_ibp_error_records_r interface --------------------------------------

  /// <summary>
  ///  Получение индекса главной ошибки
  /// </summary>
  virtual size_type_N get_primary_err_idx()const COMP_W000004_OVERRIDE_FINAL;

 private:
  virtual void push_error(base_error_record_type* pError) COMP_W000004_OVERRIDE_FINAL;//abstract

 private:
  t_ibp_error_elements m_items;

  ///Индекс главной ошибки, которая будет выводится через интерфейс IErrorInfo
  size_type_N m_primary_err_idx;
};//class t_ibp_error_collection

////////////////////////////////////////////////////////////////////////////////
//class t_ibp_error_collection

inline bool t_ibp_error_collection::empty()const
{
 return m_items.empty();
}//empty

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
