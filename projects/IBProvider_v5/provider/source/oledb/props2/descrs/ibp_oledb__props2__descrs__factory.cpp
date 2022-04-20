////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__factory__dbinit_std.h
//! \brief   Фабрика набора описаний свойств
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/ibp_oledb__props2__descrs__factory.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs_Factory

void IBP_OLEDB_Props2__Descrs_Factory::AppendDescrs
                        (oledb_lib::OLEDB_Props2__Data__Descrs* const pDescrs,
                         IBP_OLEDB_Props2__DescrDataRange       const dataRange)
{
 assert(pDescrs);
 assert(dataRange.first<dataRange.last);

 auto const c_rule_flag__ibp_runtime_descr
  =IBP_OLEDB_Props2__DescrData::rule_flag__ibp_runtime_descr;

 for(auto p=dataRange.first,_e=dataRange.last;
     p!=_e;
     ++p)
 {
  assert(p);

  if(((*p).m_RuleFlags&c_rule_flag__ibp_runtime_descr)==c_rule_flag__ibp_runtime_descr)
   continue;

  pDescrs->Add
   ((*p).m_PropId,
    (*p).m_PropFlags,
    (*p).m_PropVarType,
    (*p).m_PropDescr,
    (*p).m_RuleFlags); //throw
 }//for p
}//AppendDescrs - REF

//------------------------------------------------------------------------
void IBP_OLEDB_Props2__Descrs_Factory::AppendDescrs
                        (oledb_lib::OLEDB_Props2__Data__Descrs* const pDescrs,
                         IBP_OLEDB_Props2__DescrDataPtrRange    const dataPtrRange)
{
 assert(pDescrs);
 assert(dataPtrRange.first<dataPtrRange.last);

 auto const c_rule_flag__ibp_runtime_descr
  =IBP_OLEDB_Props2__DescrData::rule_flag__ibp_runtime_descr;

 for(auto p=dataPtrRange.first,_e=dataPtrRange.last;
     p!=_e;
     ++p)
 {
  assert(p);
  assert(*p);

  if(((**p).m_RuleFlags&c_rule_flag__ibp_runtime_descr)==c_rule_flag__ibp_runtime_descr)
   continue;

  pDescrs->Add
   ((**p).m_PropId,
    (**p).m_PropFlags,
    (**p).m_PropVarType,
    (**p).m_PropDescr,
    (**p).m_RuleFlags); //throw
 }//for p
}//AppendDescrs - REF

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
