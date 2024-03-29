////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dbinit_std.cpp
//! \brief   �������� ����������� ������� ������������� �����������
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_std.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit__all.h"

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__index_by_name.h"

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
&IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::STD::sm_DescrFor__##PropId,

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD

const IBP_OLEDB_Props2__DescrData* const
 IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD::sm_descrs[]=
{

# include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_std.dat"

};//IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD__sm_descrs()
{
 {
  const auto range=IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD::GetDataPtrRange();

  IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(range);

  //�������� ������� �������� �������
  for(auto pp=range.first,_ep=range.last;pp!=_ep;++pp)
  {
   assert(*pp);

   assert((**pp).m_PropDescr);

   const wchar_t* s=(**pp).m_PropDescr;

   assert(s);
   assert(*s);

   for(;*s;s+=wcslen(s)+1)
   {
    const auto x1=IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::Find(s);

    assert(x1.first);
    assert(x1.second);

    assert((*x1.first)==DBPROPSET_DBINIT);
    assert(x1.second==*pp);
   }//for s
  }//for pp
 }//local

 {
  //�������� �������� ������� ����
  const auto range=IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::DEBUG__GetRange_STD();

  for(auto p=range.first,_e=range.last;p!=_e;++p)
  {
   assert(p);
   assert(p->pDescr);

   auto const x1=IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD::Find(p->pDescr->m_PropId);

   assert(x1);

   assert(x1==p->pDescr);
  }//for p
 }//local
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD

IBP_OLEDB_Props2__DescrDataPtrRange
 IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD::GetDataPtrRange()
{
 return IBP_OLEDB_Props2__DescrDataPtrRange(sm_descrs,_END_(sm_descrs));
}//GetDataPtrRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD::Find(DBPROPID const propId)
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
