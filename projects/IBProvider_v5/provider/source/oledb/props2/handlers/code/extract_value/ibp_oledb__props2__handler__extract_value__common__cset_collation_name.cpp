////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__cset_collation_name.cpp
//! \brief   Реализация ExtractValue для имен правил сортировки кодовых страниц.
//! \author  Kovalenko Dmitry
//! \date    20.02.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__cset_collation_name.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"
#include "source/ibp_utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>
#include <structure/t_latin_upper.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name

IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name::IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name::~IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Common__cset_collation_name::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__BSTR(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_BSTR);

 {
  const auto tmpValue_str=ole_lib::BStrToBox(tmpValue.bstrVal);

  if(tmpValue_str.empty())
  {
   //Преобразуем пустую строку в EMPTY значение

   ole_lib::Variant_Clear_Throw(pResultValue);

   return true;
  }//if

  if(!IBP_Utils::IsValidCharsetCollationName(ole_lib::BStrToBox(tmpValue.bstrVal)))
  {
   return false;
  }//if
 }//local

 {
  wchar_t*       p=tmpValue.bstrVal;
  wchar_t* const e=p+(tmpValue.bstrVal?LCPI_OS__SysStringLen(tmpValue.bstrVal):0);

  //[2019-02-20] Problem with VS2015 [Secure iterators...]
  //std::transform(p,e,p,structure::t_latin_upper<wchar_t>());

  for(;p!=e;++p)
   (*p)=structure::latin_upper(*p);
 }//local

 tmpValue.swap(*pResultValue);

 assert(pResultValue->vt==VT_BSTR);

 return true;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
