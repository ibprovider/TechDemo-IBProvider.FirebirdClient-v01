////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__not_empty_string.cpp
//! \brief   Реализация ExtractValue для непустых строковых свойств.
//! \author  Kovalenko Dmitry
//! \date    28.02.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__not_empty_string.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"
#include "source/ibp_utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string

IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string::IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string::~IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Common__not_empty_string::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 const auto tmpValue_str=ole_lib::BStrToBox(tmpValue.bstrVal);

 if(tmpValue_str.empty())
 {
  ole_lib::Variant_Clear_Throw(pResultValue);

  return true;
 }//if

 assert_hint(!tmpValue_str.empty());

 if(IBP_Utils::IsValidSimpleString(tmpValue_str))
 {
  tmpValue.swap(*pResultValue);

  assert(pResultValue->vt==VT_BSTR);

  return true;
 }//if

 return false;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
