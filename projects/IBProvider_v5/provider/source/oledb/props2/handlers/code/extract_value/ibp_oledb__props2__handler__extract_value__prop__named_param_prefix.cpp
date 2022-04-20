////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__named_param_prefix.cpp
//! \brief   Реализация ExtractValue для свойства "named_param_prefix".
//! \author  Kovalenko Dmitry
//! \date    16.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__named_param_prefix.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix

IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix::IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix::~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Prop__named_param_prefix::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 const size_t sz=tmpValue.bstrVal?::SysStringLen(tmpValue.bstrVal):0;

 if(sz==0)
 {
  //ok
 }
 else
 if(sz==1 && structure::not_null_ptr(tmpValue.bstrVal)[0]==L':')
 {
  //ok
 }
 else
 if(sz==1 && structure::not_null_ptr(tmpValue.bstrVal)[0]==L'@')
 {
  //ok
 }
 else
 {
  return false;
 }//else

 /*ok*/

 tmpValue.swap(*pResultValue);

 assert(pResultValue->vt==VT_BSTR);
 assert(pResultValue->bstrVal);

 return true;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
