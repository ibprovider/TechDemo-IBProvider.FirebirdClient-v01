////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_default_value__prop__ProviderName.cpp
//! \brief   Реализация GetDefaultValue для свойства "Provider Name".
//! \author  Kovalenko Dmitry
//! \date    14.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/get_default_value/ibp_oledb__props2__handler__get_default_value__prop__ProviderName.h"

#include "source/error_services/ibp_error_bug_check.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName

const IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName
 IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName::IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName()
{
}//IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName::~IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName()
{
}//~IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__GetDefaultValue* IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__GetValue interface --------------------------
bool IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName::GetDefaultValue
                (const oledb_lib::OLEDB_Props2__Data__Values* const UNUSED_ARG(pValues),
                 DBPROPOPTIONS*                               const pResult_dwOptions,
                 VARIANT*                                     const pResult_Value)const
{
 if(pResult_Value)
 {
  ole_lib::TVariant(_Module.GetModuleName()).swap(*pResult_Value);
 }//if pResult_Value

 if(pResult_dwOptions)
 {
  (*pResult_dwOptions)=DBPROPOPTIONS_REQUIRED;
 }//if pResult_dwOptions

 return true;
}//GetDefaultValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
