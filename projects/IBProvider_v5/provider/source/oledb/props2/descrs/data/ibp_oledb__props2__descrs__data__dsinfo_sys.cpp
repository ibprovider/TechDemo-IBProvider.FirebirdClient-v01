////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dsinfo_sys.cpp
//! \brief   Описание расгиренных информационных свойств источника данных
//! \author  Kovalenko Dmitry
//! \date    28.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dsinfo_sys.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__helpers.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include "source/oledb/ibp_oledb__prop__system_ids.h"

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
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS

const IBP_OLEDB_Props2__DescrData
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS::sm_descrs[]=
{
 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_INSERT,
   OLEDB_PDESCR2(L"IBP:SYSTEM-CAN_GET_SERVER_DATA_ON_INSERT"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_UPDATE,
   OLEDB_PDESCR2(L"IBP:SYSTEM-CAN_GET_SERVER_DATA_ON_UPDATE"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (IBP_DBPROP__SYS_DSINFO__CAN_GET_SERVER_DATA_ON_DELETE,
   OLEDB_PDESCR2(L"IBP:SYSTEM-CAN_GET_SERVER_DATA_ON_DELETE"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)
};//IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS__sm_descrs()
{
 const auto r=IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS::GetDataRange();

 IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(r);

 for(auto x=r.first;x!=r.last;++x)
 {
  assert((*x).m_PropFlags==OLEDB_PROPFLAGS_DATASOURCEINFOR);
 }//for
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS

IBP_OLEDB_Props2__DescrDataRange
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS::GetDataRange()
{
 return IBP_OLEDB_Props2__DescrDataRange(sm_descrs,_END_(sm_descrs));
}//GetDataRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS::Find(DBPROPID const propId)
{
 if(auto const x=IBP_OLEDB_Props2__Utils::Find(self_type::GetDataRange(),propId))
  return x;

 return nullptr;
}//Find

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
