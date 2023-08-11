////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__timezones_source.h
//! \brief   Реализация ExtractValue для свойства "timezones_source".
//! \author  Kovalenko Dmitry
//! \date    26.07.2023
#ifndef _ibp_oledb__props2__handler__extract_value__prop__timezones_source_H_
#define _ibp_oledb__props2__handler__extract_value__prop__timezones_source_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source

/// <summary>
///  The implementation of ExtractValue for "timezones_source" property.
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
