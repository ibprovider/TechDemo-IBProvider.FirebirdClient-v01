////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__session_std.cpp
//! \brief   Описание стандартных свойств сессии
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_std.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session__all.h"

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
&IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::STD::sm_DescrFor__##PropId,

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__SESSION_STD

const IBP_OLEDB_Props2__DescrData* const
 IBP_OLEDB_Props2__Descrs__Data__SESSION_STD::sm_descrs[]=
{

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_std.dat"

};//IBP_OLEDB_Props2__Descrs__Data__SESSION_STD::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION_STD__sm_descrs()
{
 IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(IBP_OLEDB_Props2__Descrs__Data__SESSION_STD::GetDataPtrRange());
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION_STD__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION_STD__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__SESSION_STD

IBP_OLEDB_Props2__DescrDataPtrRange
 IBP_OLEDB_Props2__Descrs__Data__SESSION_STD::GetDataPtrRange()
{
 return IBP_OLEDB_Props2__DescrDataPtrRange(_BEG_END_(sm_descrs));
}//GetDataPtrRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__SESSION_STD::Find(DBPROPID const propId)
{
 assert_s(_DIM_(sm_descrs)==1);

 assert(sm_descrs[0]);

 if(sm_descrs[0]->m_PropId==propId)
  return sm_descrs[0];

 return nullptr;
}//Find

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
