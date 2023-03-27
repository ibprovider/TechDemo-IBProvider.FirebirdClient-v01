////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__schema_ldr_cfg__descriptions.cpp
//! \brief   Реализация ExtractValue для свойства "schema_ldr_cfg__descriptions".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__schema_ldr_cfg__descriptions.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_i4.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_ENGINE_META_DATA_READER==0)
# error The incorrect usage of file!
#endif

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__descriptions::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__descriptions::tag_data
{
 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__descriptions::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__descriptions::tag_data::sm_Instance
  (_BEG_END_(ibprovider::g_IBP_PropValuesFor__schema_ldr_cfg__descriptions));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__descriptions

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__schema_ldr_cfg__descriptions::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
