////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dscreate.cpp
//! \brief   Описание свойств нового источника данных
//! \author  Kovalenko Dmitry
//! \date    29.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate__all.h"

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
&IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::EXT::sm_DescrFor__##PropId,

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE

const IBP_OLEDB_Props2__DescrData* const
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE::sm_descrs[]=
{
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate.dat"
};//IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__sm_descrs()
{
 const auto r=IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE::GetDataPtrRange();

 IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(r);

 for(auto x=r.first;x!=r.last;++x)
 {
  assert((*x));
  assert((*x)->m_PropFlags==OLEDB_PROPFLAGS_DATASOURCECREATEW);
 }//for x
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE

IBP_OLEDB_Props2__DescrDataPtrRange
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE::GetDataPtrRange()
{
 return IBP_OLEDB_Props2__DescrDataPtrRange(_BEG_END_(sm_descrs));
}//GetDataPtrRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE::Find(DBPROPID const propId)
{
 if(auto const x=IBP_OLEDB_Props2__Utils::Find(self_type::GetDataPtrRange(),propId))
  return x;

 return nullptr;
}//Find

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
