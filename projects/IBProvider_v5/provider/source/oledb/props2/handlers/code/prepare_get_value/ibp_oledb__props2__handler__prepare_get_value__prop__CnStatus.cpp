////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__prepare_get_value__prop__CnStatus.cpp
//! \brief   Реализация PrepareSetValue для свойства "Connection Status".
//! \author  Kovalenko Dmitry
//! \date    30.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/prepare_get_value/ibp_oledb__props2__handler__prepare_get_value__prop__CnStatus.h"
#include "source/oledb/props2/handlers/data/ibp_oledb__props2__handler_data__CnStatus.h"
#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

#include "source/error_services/ibp_error_bug_check.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_ctx.h>
#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_set_props.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus

const IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus
 IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus::IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus()
{
}//IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus::~IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus()
{
}//~IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__PrepareGetValue*
 IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__PrepareSetValue interface -------------------
void IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus::PrepareGetValue
                        (const oledb_lib::OLEDB_Props2__Data__Values* const pValues,
                         oledb_lib::OLEDB_Props2__Data__OpCtx&              op_ctx,
                         REFGUID                                            /*propGuid*/,
                         DBPROPID                                           /*propId*/)const
{
 assert(pValues);
 assert(dynamic_cast<const IBP_OLEDB_Props2__Values__DATASOURCE*>(pValues));

 const wchar_t* const c_bug_check_src
  =L"IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus::PrepareGetValue";

 const auto* const pxValues
  =dynamic_cast<const IBP_OLEDB_Props2__Values__DATASOURCE*>(pValues);

 IBP_BUG_CHECK__DETECT_BAD_OBJECT_NULL_PTR
  (pxValues,
   c_bug_check_src,
   L"#001")

 assert_hint(pxValues);
 assert_hint(pxValues->OnGetConnectionStatus);

 typedef IBP_OLEDB_Props2__HandlerData__CnStatus data_type;

 if(oledb_lib::OLEDB_Prop2__GetDBPropOpCtxItem<data_type>(op_ctx))
 {
  //данные уже сформированы и помещены в кэш
  return;
 }//if

 LONG const
  CnStatus=pxValues->OnGetConnectionStatus();

 data_type::self_ptr const
  spData(data_type::Create(CnStatus));

 _VERIFY(oledb_lib::OLEDB_Prop2__AddDBPropOpCtxItem
          (op_ctx,
           spData.ptr()));
}//PrepareGetValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
