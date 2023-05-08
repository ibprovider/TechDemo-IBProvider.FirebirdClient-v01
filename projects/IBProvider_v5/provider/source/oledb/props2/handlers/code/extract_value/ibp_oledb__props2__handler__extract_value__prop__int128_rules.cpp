////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__int128_rules.cpp
//! \brief   Реализация ExtractValue для свойства "int128_rules".
//! \author  Kovalenko Dmitry
//! \date    01.02.2023
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__int128_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_i4.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dbtimestamp_rules::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__int128_rules::tag_data
{
 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__int128_rules::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__int128_rules::tag_data::sm_Instance
  (_BEG_END_(ibprovider::g_IBP_PropValuesFor__int128_rules));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__int128_rules

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__int128_rules::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
