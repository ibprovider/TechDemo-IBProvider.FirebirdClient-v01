////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__simple_string.cpp
//! \brief   Реализация ExtractValue для простых строковых свойств.
//! \author  Kovalenko Dmitry
//! \date    16.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__simple_string.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"
#include "source/ibp_utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string

IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string::IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string::~IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Common__simple_string::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 if(!IBP_Utils::IsValidSimpleString(ole_lib::BStrToBox(tmpValue.bstrVal)))
  return false;

 tmpValue.swap(*pResultValue);

 assert(pResultValue->vt==VT_BSTR);

 return true;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
