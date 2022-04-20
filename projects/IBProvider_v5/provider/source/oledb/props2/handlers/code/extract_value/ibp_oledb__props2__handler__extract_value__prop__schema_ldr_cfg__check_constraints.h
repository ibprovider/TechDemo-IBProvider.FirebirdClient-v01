////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__schema_ldr_cfg__check_constraints.h
//! \brief   Реализация ExtractValue для свойства "schema_ldr_cfg__check_constraints".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__schema_ldr_cfg__check_constraints_H_
#define _ibp_oledb__props2__handler__extract_value__prop__schema_ldr_cfg__check_constraints_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_EDITION_ID==IBP_EDITION_ID__FREE)
# error Incorrect usage of file!
#endif

////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__check_constraints

/// <summary>
///  Реализация ExtractValue для свойства "schema_ldr_cfg__check_constraints".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__check_constraints
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__check_constraints

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
