////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__extract_value__common__non_negative_i4.cpp
//! \brief   Реализация ExtractValue для неотрицательных I4-свойств.
//! \author  Kovalenko Dmitry
//! \date    18.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__non_negative_i4.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4

IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4::IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4()
{
}//IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4::~IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4()
{
}//~IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__ExtractValue*
 IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__ExtractValue interface ----------------------
bool IBP_OLEDB_Props2__Handler__ExtractValue__Common__non_negative_i4::ExtractValue
                                           (const VARIANT& sourceValue,
                                            VARIANT* const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 ole_lib::TVariant tmpValue;

 if(!IBP_OLEDB_Props2__Utils::ExtractValue__I4(sourceValue,&tmpValue)) //throw
  return false;

 assert(tmpValue.vt==VT_I4);

 LCPI__assert_s(sizeof(tmpValue.lVal)==sizeof(value_type));
 LCPI__assert_s(sizeof(tmpValue.lVal)==4);

 if(tmpValue.lVal<0)
  return false;

 tmpValue.swap(*pResultValue);

 assert(pResultValue->vt==VT_I4);

 return true;
}//ExtractValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
