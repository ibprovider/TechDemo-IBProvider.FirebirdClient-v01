////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__get_value__common__SecData.cpp
//! \brief   Реализация GetValue для свойств с секретными данными.
//! \author  Kovalenko Dmitry
//! \date    20.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/get_value/ibp_oledb__props2__handler__get_value__common__SecData.h"
#include "source/error_services/ibp_error_bug_check.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__GetValue__Common__SecData

const IBP_OLEDB_Props2__Handler__GetValue__Common__SecData
 IBP_OLEDB_Props2__Handler__GetValue__Common__SecData::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetValue__Common__SecData::IBP_OLEDB_Props2__Handler__GetValue__Common__SecData()
{
}//IBP_OLEDB_Props2__Handler__GetValue__Common__SecData

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__GetValue__Common__SecData::~IBP_OLEDB_Props2__Handler__GetValue__Common__SecData()
{
}//~IBP_OLEDB_Props2__Handler__GetValue__Common__SecData

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__GetValue* IBP_OLEDB_Props2__Handler__GetValue__Common__SecData::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__GetValue interface --------------------------
bool IBP_OLEDB_Props2__Handler__GetValue__Common__SecData::GetValue
                (const oledb_lib::OLEDB_Props2__Data__Values* const pValues,
                 oledb_lib::OLEDB_Props2__Data__OpCtx&              UNUSED_ARG(op_ctx),
                 REFGUID                                            propGuid,
                 DBPROPID                                     const propId,
                 DBPROPOPTIONS*                               const pResult_dwOptions,
                 VARIANT*                                     const pResult_Value)const
{
 assert(pResult_dwOptions);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 if(!pValues->Direct__GetValue
               (propGuid,
                propId,
                pResult_dwOptions,
                nullptr))
 {
  return false;
 }//if

 ole_lib::TVariant(L"********").swap(*pResult_Value);

 return true;
}//GetValue

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
