////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__prepare_set_value__prop__ResetDS.cpp
//! \brief   –еализаци€ PrepareSetValue дл€ свойства "Reset Datasource".
//! \author  Kovalenko Dmitry
//! \date    20.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/prepare_set_value/ibp_oledb__props2__handler__prepare_set_value__prop__ResetDS.h"
#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

#include "source/error_services/ibp_error_bug_check.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS

const IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS::IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS()
{
}//IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS::~IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS()
{
}//~IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__PrepareSetValue*
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__PrepareSetValue interface -------------------
void IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS::PrepareSetValue
                              (const oledb_lib::OLEDB_Props2__Data__Values* const pValues,
                               oledb_lib::OLEDB_Props2__Data__OpCtx&              UNUSED_ARG(op_ctx),
                               DBPROPOPTIONS                                const UNUSED_ARG(sourceOptions),
                               const VARIANT&                                     sourceValue,
                               DBPROPSTATUS*                                const pResult_dwStatus,
                               VARIANT*                                     const pResult_Value)const
{
 assert(pValues);
 assert(dynamic_cast<const IBP_OLEDB_Props2__Values__DATASOURCE*>(pValues));

 assert(pResult_dwStatus);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS::PrepareSetValue";

 const auto* const pxValues
  =dynamic_cast<const IBP_OLEDB_Props2__Values__DATASOURCE*>(pValues);

 IBP_BUG_CHECK__DETECT_BAD_OBJECT_NULL_PTR
  (pxValues,
   c_bug_check_src,
   L"#001")

 assert_hint(pxValues);
 assert_hint(pxValues->OnCanResetConnection);

 //-----------------------------------------
 if(sourceValue.vt==VT_EMPTY)
 {
  ole_lib::Variant_Clear_Throw(pResult_Value);

  (*pResult_dwStatus)=DBPROPSTATUS_OK;

  return;
 }//if

 assert(sourceValue.vt==VT_I4);

 //-----------------------------------------
 if(sourceValue.lVal!=DBPROPVAL_RD_RESETALL)
 {
  (*pResult_dwStatus)=DBPROPSTATUS_BADVALUE;

  return;
 }//if

 //-----------------------------------------
 if(!pxValues->OnCanResetConnection())
 {
  (*pResult_dwStatus)=DBPROPSTATUS_NOTSET;

  return;
 }//if

 //-----------------------------------------

 //ѕосле завершени€ установки значений, источник данных должен посмотреть
 //на состо€ние значени€ свойства "Reset Datasource" и выполнить переинициализацию
 //своего состони€.

 ole_lib::Variant_Copy_Throw(pResult_Value,&sourceValue);

 (*pResult_dwStatus)=DBPROPSTATUS_OK;
}//PrepareSetValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
