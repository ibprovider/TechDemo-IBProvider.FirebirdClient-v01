////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__sql_cache__scope.h
//! \brief   Реализация ExtractValue для свойства "sql_cache__scope".
//! \author  Kovalenko Dmitry
//! \date    06.10.2020
#ifndef _ibp_oledb__props2__handler__extract_value__prop__sql_cache__scope_H_
#define _ibp_oledb__props2__handler__extract_value__prop__sql_cache__scope_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__sql_cache__scope

/// <summary>
///  Реализация ExtractValue для свойства "sql_cache__scope".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__sql_cache__scope
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__sql_cache__scope

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
