////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__timezones_source.cpp
//! \brief   Реализация ExtractValue для свойства "timezones_source".
//! \author  Kovalenko Dmitry
//! \date    26.07.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__timezones_source.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_string.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source::tag_data
{
 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source::tag_data::sm_Instance
  (_BEG_END_(ibprovider::g_IBP_PropValuesFor__timezones_source));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__timezones_source::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
