////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__named_param_prefix.h
//! \brief   Реализация ExtractValue для свойства "named_param_prefix".
//! \author  Kovalenko Dmitry
//! \date    16.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__named_param_prefix_H_
#define _ibp_oledb__props2__handler__extract_value__prop__named_param_prefix_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix

/// <summary>
///  Реализация ExtractValue для свойства "named_param_prefix".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix
 :public IBP_OLEDB_Props2__Handler__ExtractValue
{
 private:
  typedef IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix   self_type;

  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix(const self_type&);
  self_type& operator = (const self_type&);

 private:
  IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix();

 ~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix();

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();

  //IBP_OLEDB_Props2__Handler__ExtractValue interface --------------------
  virtual bool ExtractValue(const VARIANT&  sourceValue,
                            VARIANT*        pResultValue)const LCPI_CPP_CFG__METHOD__OVERRIDE_FINAL;

 private:
  static IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
