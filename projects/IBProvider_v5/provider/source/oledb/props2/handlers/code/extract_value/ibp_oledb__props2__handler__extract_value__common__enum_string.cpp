////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__enum_string.cpp
//! \brief   Реализация ExtractValue для строковых свойств со списком допустимых значений.
//! \author  Kovalenko Dmitry
//! \date    17.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__enum_string.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <structure/t_latin.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string

IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string::IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string
                                           (const value_type* const first,
                                            const value_type* const last)
 :m_first(first)
 ,m_last(last)
{
 assert(m_first<m_last);
}

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string::~IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Common__enum_string::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 const auto strValue=structure::trim(ole_lib::BStrToBox(tmpValue.bstrVal));

 //
 // [2018-12-18] Disabled.
 //
 // if(strValue.empty())
 // {
 //  ole_lib::Variant_Clear_Throw(pResultValue);
 //
 //  assert(pResultValue->vt==VT_EMPTY);
 //
 //  return true;
 // }//local

 typedef structure::t_latin_equal_i<ibprovider::IBP_CHAR> eq_op;

 for(auto p=m_first;p!=m_last;++p)
 {
  assert(*p);

  if(structure::equal_to_string(strValue,*p,eq_op()))
  {
   tmpValue=*p; //throw

   assert(tmpValue.vt==VT_BSTR);
   assert(tmpValue.bstrVal);

   tmpValue.swap(*pResultValue);

   assert(pResultValue->vt==VT_BSTR);
   assert(pResultValue->bstrVal);

   return true;
  }//if
 }//for i

 return false;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
