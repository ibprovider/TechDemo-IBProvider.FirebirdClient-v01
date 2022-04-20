////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__not_empty_string.h
//! \brief   Реализация ExtractValue для непустых строковых свойств.
//! \author  Kovalenko Dmitry
//! \date    28.02.2019
#ifndef _ibp_oledb__props2__handler__extract_value__common__not_empty_string_H_
#define _ibp_oledb__props2__handler__extract_value__common__not_empty_string_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string

/// <summary>
///  Extract string value and decline value with zero length.
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string();

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string();

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const COMP_W000004_OVERRIDE_FINAL;

 private:
  static self_type sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
