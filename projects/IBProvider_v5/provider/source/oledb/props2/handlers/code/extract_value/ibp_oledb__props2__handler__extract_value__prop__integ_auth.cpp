////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__prop__integ_auth.cpp
//! \brief   Реализация ExtractValue для свойства "Integrated Security".
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__integ_auth.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <structure/t_latin.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth

IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth::IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth::~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Prop__integ_auth::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 const auto tmpStrValue=structure::trim(ole_lib::BStrToBox(tmpValue.bstrVal));

 if(tmpStrValue.empty())
 {
  //ok - reset to default
  ole_lib::Variant_Clear_Throw(pResultValue); //throw
  return true;
 }//if

 typedef structure::t_latin_equal_i<ibprovider::IBP_CHAR> eq_op;

 if(structure::equal_to_string(tmpStrValue,ibprovider::g_IBP_IntegratedAuth__NONE,eq_op()))
 {
  //ok - reset to default
  ole_lib::Variant_Clear_Throw(pResultValue); //throw
  return true;
 }//if

 if(structure::equal_to_string(tmpStrValue,ibprovider::g_IBP_IntegratedAuth__SSPI,eq_op()))
 {
  //ok
  tmpValue=ibprovider::g_IBP_IntegratedAuth__SSPI; //throw
 }
 else
 {
  return false;
 }//else

 /*ok*/
 assert(tmpValue.vt==VT_BSTR);
 assert(tmpValue.bstrVal);

 tmpValue.swap(*pResultValue);

 assert(pResultValue->vt==VT_BSTR);
 assert(pResultValue->bstrVal);

 return true;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
