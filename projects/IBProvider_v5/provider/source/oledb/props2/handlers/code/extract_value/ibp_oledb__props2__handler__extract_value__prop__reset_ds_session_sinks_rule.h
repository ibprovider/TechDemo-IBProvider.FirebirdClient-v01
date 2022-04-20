////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__reset_ds_session_sinks_rule.h
//! \brief   Реализация ExtractValue для свойства "reset_ds_session_sinks_rule".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__reset_ds_session_sinks_rule_H_
#define _ibp_oledb__props2__handler__extract_value__prop__reset_ds_session_sinks_rule_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__reset_ds_session_sinks_rule

/// <summary>
///  Реализация ExtractValue для свойства "reset_ds_session_sinks_rule".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__reset_ds_session_sinks_rule
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__reset_ds_session_sinks_rule

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
