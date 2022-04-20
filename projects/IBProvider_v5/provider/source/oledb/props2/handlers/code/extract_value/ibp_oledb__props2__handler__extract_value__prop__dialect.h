////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__dialect.h
//! \brief   Реализация ExtractValue для свойства "dialect".
//! \author  Kovalenko Dmitry
//! \date    19.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__dialect_H_
#define _ibp_oledb__props2__handler__extract_value__prop__dialect_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect

/// <summary>
///  Реализация ExtractValue для свойства "dialect".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
