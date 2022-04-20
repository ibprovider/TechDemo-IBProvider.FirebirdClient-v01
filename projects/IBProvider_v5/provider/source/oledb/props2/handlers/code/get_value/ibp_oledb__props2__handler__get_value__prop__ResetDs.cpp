////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_value__prop__ResetDs.cpp
//! \brief   Реализация GetValue для свойства "Reset Datasource".
//! \author  Kovalenko Dmitry
//! \date    08.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/get_value/ibp_oledb__props2__handler__get_value__prop__ResetDs.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs

const IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs
 IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs::IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs()
{
}//IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs::~IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs()
{
}//~IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__GetValue* IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__GetValue interface --------------------------
bool IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs::GetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* const UNUSED_ARG(pValues),
                 oledb_lib::OLEDB_Props2__Data__OpCtx&              UNUSED_ARG(op_ctx),
                 REFGUID                                            DEBUG_CODE(propGuid),
                 DBPROPID                                     const DEBUG_CODE(propId),
                 DBPROPOPTIONS*                               const pResult_dwOptions,
                 VARIANT*                                     const pResult_Value)const
{
 assert(ole_lib::GuidEqual(propGuid,DBPROPSET_DATASOURCE));
 assert(propId==DBPROP_RESETDATASOURCE);
 assert(pResult_dwOptions);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 ole_lib::TVariant(0L).swap(*pResult_Value);

 assert(pResult_Value->vt==VT_I4);

 (*pResult_dwOptions)=DBPROPOPTIONS_OPTIONAL;

 return true;
}//GetValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
