////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__auto_insert_field_rule.h
//! \brief   Реализация ExtractValue для свойства "auto_insert_field_rule".
//! \author  Kovalenko Dmitry
//! \date    19.12.2018
#ifndef _ibp_oledb__props2__handler__extract_value__prop__auto_insert_field_rule_H_
#define _ibp_oledb__props2__handler__extract_value__prop__auto_insert_field_rule_H_

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_ENGINE_UPDATE_ROWSET==0)
# error Incorrect usage of file!
#endif

////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__props2
//! @{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_insert_field_rule

/// <summary>
///  Реализация ExtractValue для свойства "auto_insert_field_rule".
/// </summary>
class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_insert_field_rule
{
 private:
  class tag_data;

 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue* GetInstancePtr();
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_insert_field_rule

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
#endif
