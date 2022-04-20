////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__auto_update_field_rule.cpp
//! \brief   Реализация ExtractValue для свойства "auto_update_field_rule".
//! \author  Kovalenko Dmitry
//! \date    19.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__auto_update_field_rule.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_i2.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_ENGINE_UPDATE_ROWSET==0)
# error Incorrect usage of file!
#endif

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_update_field_rule::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_update_field_rule::tag_data
{
 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i2
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_update_field_rule::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i2
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_update_field_rule::tag_data::sm_Instance
  (_BEG_END_(ibprovider::g_IBP_PropValuesFor__auto_update_field_rule));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_update_field_rule

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__auto_update_field_rule::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
