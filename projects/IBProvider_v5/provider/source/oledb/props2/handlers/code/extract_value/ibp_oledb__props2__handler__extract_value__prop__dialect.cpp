////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__dialect.cpp
//! \brief   Реализация ExtractValue для свойства "dialect".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__dialect.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_i4.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect::tag_data
{
 public:
  static const ibprovider::IBP_LONG sm_values_for__dialect[];

  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect::tag_data

////////////////////////////////////////////////////////////////////////////////

const ibprovider::IBP_LONG
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect::tag_data::sm_values_for__dialect[]=
{
 //[2018-12-19] All known dialects of FB/IB/YA
 1,
 2,
 3,
};//sm_values_for__dialect

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_i4
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect::tag_data::sm_Instance
  (_BEG_END_(sm_values_for__dialect));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__dialect::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
