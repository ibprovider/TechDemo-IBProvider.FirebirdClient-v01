////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dsinfo_ext.cpp
//! \brief   Описание расгиренных информационных свойств источника данных
//! \author  Kovalenko Dmitry
//! \date    28.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dsinfo_ext.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__helpers.h"
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
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT

const IBP_OLEDB_Props2__DescrData
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT::sm_descrs[]=
{
 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY                      //65475
  (ibprovider::IBP_DBPROP__INFO__IB_BASE,
   OLEDB_PDESCR2(L"IB Base"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_DATABASE_DIALECT,
   OLEDB_PDESCR2(L"IB Database Dialect"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_DATABASE_PAGE_SIZE,
   OLEDB_PDESCR2(L"IB Database Page Size"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_DATA
  (IBP_OLEDB_Props2__DescrData::tag_init__empty(),
   ibprovider::IBP_DBPROP__INFO__IB_DATABASE_CREATION_DATE,
   OLEDB_PDESCR2(L"IB Database Creation Date"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   0,
   VT_DATE _LITER_COMMA_
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_SAVEPOINT_SUPPORT,
   OLEDB_PDESCR2(L"IB Savepoint Support"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_CLIENT,
   OLEDB_PDESCR2(L"IB Client"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_CLIENT_VERSION,
   OLEDB_PDESCR2(L"IB Client Version"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_CLIENT_NAME,
   OLEDB_PDESCR2(L"IB Client Name"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_CONNECTION_DIALECT,        //65489
   OLEDB_PDESCR2(L"IB Connection Dialect"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (ibprovider::IBP_DBPROP__INFO__IB_DATABASE_ODS_VERSION,      //65490
   OLEDB_PDESCR2(L"IB Database ODS Version"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)
};//IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT__sm_descrs()
{
 const auto r=IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT::GetDataRange();

 IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(r);

 for(auto x=r.first;x!=r.last;++x)
 {
  assert((*x).m_PropFlags==OLEDB_PROPFLAGS_DATASOURCEINFOR);
 }//for
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT

IBP_OLEDB_Props2__DescrDataRange
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT::GetDataRange()
{
 return IBP_OLEDB_Props2__DescrDataRange(_BEG_END_(sm_descrs));
}//GetDataRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT::Find(DBPROPID const propId)
{
 if(auto const x=IBP_OLEDB_Props2__Utils::Find(self_type::GetDataRange(),propId))
  return x;

 return nullptr;
}//Find

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
