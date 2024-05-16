////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__session_ext.cpp
//! \brief   ќписание специализированных свойств сессии
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_ext.h"
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
&IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::EXT::sm_DescrFor__##PropId,

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT

const IBP_OLEDB_Props2__DescrData* const
 IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT::sm_descrs[]=
{

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_ext.dat"

};//IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT__sm_descrs()
{
 IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT::GetDataPtrRange());
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT

IBP_OLEDB_Props2__DescrDataPtrRange
 IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT::GetDataPtrRange()
{
 return IBP_OLEDB_Props2__DescrDataPtrRange(_BEG_END_(sm_descrs));
}//GetDataPtrRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT::Find(DBPROPID const propId)
{
 assert_s(_DIM_(sm_descrs)<16);

 for(size_t i=0;i!=_DIM_(sm_descrs);++i)
 {
  assert(sm_descrs[i]);

  if(sm_descrs[i]->m_PropId==propId)
   return sm_descrs[i];
 }//for i

 return nullptr;
}//Find

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
