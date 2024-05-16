////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__ds_std.cpp
//! \brief   ќписание стандартных свойств источника данных
//! \author  Kovalenko Dmitry
//! \date    28.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__ds_std.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__helpers.h"

#include "source/oledb/props2/handlers/code/prepare_set_value/ibp_oledb__props2__handler__prepare_set_value__prop__ResetDS.h"
#include "source/oledb/props2/handlers/code/get_value/ibp_oledb__props2__handler__get_value__prop__ResetDs.h"

#include "source/oledb/props2/ibp_oledb__props2__utils.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{namespace data{
////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
IBP_OLEDB_Props2__DescrData                                               \
 (InitTag,                                                                \
  PropId,                                                                 \
  PropDescr,                                                              \
  PropFlags,                                                              \
  PropRules,                                                              \
  ListOfAdditionalParams) POST_INIT_CALLS,

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD

const IBP_OLEDB_Props2__DescrData
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD::sm_descrs[]=
{
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_RESETDATASOURCE,
   OLEDB_PDESCR2(L"Reset Datasource"),
   OLEDB_PROPFLAGS_DATASOURCERW,
   DBPROPOPTIONS_OPTIONAL,
   0L,
   .PostInit_SetHandler_PrepareSetValue(IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ResetDS::GetInstancePtr())
   .PostInit_SetHandler_GetValue(IBP_OLEDB_Props2__Handler__GetValue__Prop__ResetDs::GetInstancePtr()))
};//IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD__sm_descrs()
{
 const auto r=IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD::GetDataRange();

 IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(r);

 for(auto x=r.first;x!=r.last;++x)
 {
  assert((*x).m_PropFlags==OLEDB_PROPFLAGS_DATASOURCERW);
 }//for
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD

IBP_OLEDB_Props2__DescrDataRange
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD::GetDataRange()
{
 return IBP_OLEDB_Props2__DescrDataRange(_BEG_END_(sm_descrs));
}//GetDataRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD::Find(DBPROPID const propId)
{
 assert_s(_DIM_(sm_descrs)==1);

 if(sm_descrs[0].m_PropId==propId)
  return &sm_descrs[0];

 return nullptr;
}//Find

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
