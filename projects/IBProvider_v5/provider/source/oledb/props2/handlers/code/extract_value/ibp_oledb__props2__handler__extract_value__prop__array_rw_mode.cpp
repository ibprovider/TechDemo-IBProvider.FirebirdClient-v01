////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__array_rw_mode.cpp
//! \brief   Реализация ExtractValue для свойства "array_rw_mode".
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__array_rw_mode.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_string.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_rw_mode::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_rw_mode::tag_data
{
 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_rw_mode::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_rw_mode::tag_data::sm_Instance
  (_BEG_END_(ibprovider::g_IBP_PropValuesFor__array_rw_mode));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_rw_mode

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__array_rw_mode::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
