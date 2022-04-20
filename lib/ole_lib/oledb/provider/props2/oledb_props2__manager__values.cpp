////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 24.11.2018.
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__manager__values.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values

OLEDB_Props2__Manager__Values::OLEDB_Props2__Manager__Values()
{
}//OLEDB_Props2__Manager__Values

//------------------------------------------------------------------------
OLEDB_Props2__Manager__Values::OLEDB_Props2__Manager__Values(const self_type& x)
 :m_descr_sets(x.m_descr_sets)
{
}//OLEDB_Props2__Manager__Values - copy

//------------------------------------------------------------------------
OLEDB_Props2__Manager__Values::~OLEDB_Props2__Manager__Values()
{
}//~OLEDB_Props2__Manager__Values

//------------------------------------------------------------------------
OLEDB_Props2__Manager__Values& OLEDB_Props2__Manager__Values::operator = (const self_type& x)
{
 m_descr_sets=x.m_descr_sets;

 return *this;
}//copy operator

//interface --------------------------------------------------------------
void OLEDB_Props2__Manager__Values::AddInfo(const OLEDB_Props2__Data__Descrs* const pDescrs)
{
 assert(pDescrs);

 assert(!this->Helper__FindDescrs(pDescrs->m_Guid));

 m_descr_sets.emplace_back(structure::not_null_ptr(pDescrs));
}//AddInfo

//Helper methods ---------------------------------------------------------
const OLEDB_Props2__Data__Descrs* OLEDB_Props2__Manager__Values::Helper__FindDescrs(REFGUID Guid)const
{
 for(auto x=m_descr_sets.cbegin(),_e=m_descr_sets.cend();x!=_e;++x)
 {
  assert(*x);

  if((*x)->IsGuid(Guid))
   return *x;
 }//for x

 return nullptr;
}//Helper__FindDescrs

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
