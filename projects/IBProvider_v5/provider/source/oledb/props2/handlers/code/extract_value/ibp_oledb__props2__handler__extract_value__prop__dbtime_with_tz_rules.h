////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__dbtime_with_tz_rules.h
//! \brief   Реализация ExtractValue для свойства "dbtime_with_tz_rules".
//! \author  Kovalenko Dmitry
//! \date    31.01.2023
#ifndef _ibp_oledb__props2__handler__extract_value__prop__dbtime_with_tz_rules_H_
#define _ibp_oledb__props2__handler__extract_value__prop__dbtime_with_tz_rules_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dbtime_with_tz_rules

/// <summary>
///  Реализация ExtractValue для свойства "dbtime_with_tz_rules".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dbtime_with_tz_rules
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dbtime_with_tz_rules

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
