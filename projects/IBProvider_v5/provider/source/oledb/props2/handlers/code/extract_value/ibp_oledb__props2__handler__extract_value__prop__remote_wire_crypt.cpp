////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__remote_wire_crypt.cpp
//! \brief   Реализация ExtractValue для свойства "remote:wire_crypt".
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_wire_crypt.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_string.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////

#if(IBP_ENGINE_DIRECT_FB==0)
# error Incorrect usage of file!
#endif

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_crypt::tag_data

class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_crypt::tag_data
{
 public:
  static const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
   sm_Instance;
};//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_crypt::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_crypt::tag_data::sm_Instance
  (_BEG_END_(ibprovider::g_IBP_PropValuesFor__remote__wire_crypt));

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_crypt

const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__remote_wire_crypt::GetInstancePtr()
{
 return &tag_data::sm_Instance;
}//GetInstancePtr

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
