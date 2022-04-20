////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_value__prop__CnStatus.cpp
//! \brief   Реализация GetValue для свойства "Connection Status".
//! \author  Kovalenko Dmitry
//! \date    20.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/get_value/ibp_oledb__props2__handler__get_value__prop__CnStatus.h"
#include "source/oledb/props2/handlers/data/ibp_oledb__props2__handler_data__CnStatus.h"

#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus

const IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus
 IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus::IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus()
{
}//IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus::~IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus()
{
}//~IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__GetValue* IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__GetValue interface --------------------------
bool IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus::GetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* const UNUSED_ARG(pValues),
                 oledb_lib::OLEDB_Props2__Data__OpCtx&              op_ctx,
                 REFGUID                                            DEBUG_CODE(propGuid),
                 DBPROPID                                     const DEBUG_CODE(propId),
                 DBPROPOPTIONS*                               const pResult_dwOptions,
                 VARIANT*                                     const pResult_Value)const
{
 assert(ole_lib::GuidEqual(propGuid,DBPROPSET_DATASOURCEINFO));
 assert(propId==DBPROP_CONNECTIONSTATUS);
 assert(pResult_dwOptions);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 typedef IBP_OLEDB_Props2__HandlerData__CnStatus data_type;

 const data_type::self_ptr
  spPreparedData(oledb_lib::OLEDB_Prop2__GetDBPropOpCtxItem<data_type>(op_ctx));

 assert(spPreparedData);

 ole_lib::TVariant(spPreparedData->GetCnStatus()).swap(*pResult_Value);

 assert(pResult_Value->vt==VT_I4);

 (*pResult_dwOptions)=DBPROPOPTIONS_REQUIRED;

 return true;
}//GetValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
