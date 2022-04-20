////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__db_page_size.cpp
//! \brief   Реализация ExtractValue для свойства "IBP_NEWDB: Database Page Size".
//! \author  Kovalenko Dmitry
//! \date    30.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__db_page_size.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_i4.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size::tag_data
{
 public:
  static const ibprovider::IBP_LONG sm_values_for__provider_error_rules[];

  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size::tag_data

////////////////////////////////////////////////////////////////////////////////

const ibprovider::IBP_LONG
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size::tag_data::sm_values_for__provider_error_rules[]=
{
 1024*1,
 1024*2,
 1024*4,
 1024*8,
 1024*16,
 1024*32,
};//sm_values_for__provider_error_rules

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size::tag_data::sm_Instance
  (_BEG_END_(sm_values_for__provider_error_rules));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__db_page_size::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
