////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__enum_string.h
//! \brief   Реализация ExtractValue для строковых свойств со списком допустимых значений.
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__common__enum_string_H_
#define _ibp_oledb__props2__handler__extract_value__common__enum_string_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string

/// <summary>
///  Реализация ExtractValue для строковых свойств со списком допустимых значений.
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string(const self_type&);
  self_type& operator = (const self_type&);

 public:
  typedef const ibprovider::IBP_CHAR*       value_type;

 public:
  IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
                                           (const value_type* first,
                                            const value_type* last);

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const COMP_W000004_OVERRIDE_FINAL;

 private:
  const value_type* const m_first;
  const value_type* const m_last;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
