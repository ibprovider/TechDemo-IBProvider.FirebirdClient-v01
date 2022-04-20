////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 20.11.2018.
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__data__descr.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Descr

OLEDB_Props2__Data__Descr::OLEDB_Props2__Data__Descr
                                           (DBPROPID        const propId,
                                            wms_type        const propDescr,
                                            DBPROPFLAGS     const propFlags,
                                            VARTYPE         const propVarType,
                                            rule_flags_type const ruleFlags)
 :m_PropId(propId)
 ,m_PropDescr(propDescr)
 ,m_PropFlags(propFlags)
 ,m_PropVarType(propVarType)
 ,m_RuleFlags(ruleFlags)
{
 assert(m_PropVarType!=VT_EMPTY);

#ifndef NDEBUG
 if((m_RuleFlags&self_type::rule_flag__has_dynamic_value)==self_type::rule_flag__has_dynamic_value)
 {
  assert((m_PropFlags&DBPROPFLAGS_READ)==DBPROPFLAGS_READ);
 }
#endif
}//OLEDB_Props2__Data__Descr

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descr::~OLEDB_Props2__Data__Descr()
{
}//~OLEDB_Props2__Data__Descr

//interface --------------------------------------------------------------
DBPROPID OLEDB_Props2__Data__Descr::GetPropId()const
{
 return m_PropId;
}//GetPropId

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descr::wms_type OLEDB_Props2__Data__Descr::GetPropDescr()const
{
 return m_PropDescr;
}//GetPropDescr

//------------------------------------------------------------------------
DBPROPFLAGS OLEDB_Props2__Data__Descr::GetPropFlags()const
{
 return m_PropFlags;
}//GetPropFlags

//------------------------------------------------------------------------
VARTYPE OLEDB_Props2__Data__Descr::GetPropVarType()const
{
 return m_PropVarType;
}//GetPropVarType

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descr::rule_flags_type OLEDB_Props2__Data__Descr::GetRuleFlags()const
{
 return m_RuleFlags;
}//GetRuleFlags

//test methods -----------------------------------------------------------
bool OLEDB_Props2__Data__Descr::TestPropFlag__IsWrite()const
{
 return (m_PropFlags&DBPROPFLAGS_WRITE)==DBPROPFLAGS_WRITE;
}//TestPropFlag__IsWrite

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Descr::TestPropFlag__IsRead()const
{
 return (m_PropFlags&DBPROPFLAGS_READ)==DBPROPFLAGS_READ;
}//TestPropFlag__IsRead

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Descr::TestRuleFlag__has_dynamic_value()const
{
 return (m_RuleFlags&self_type::rule_flag__has_dynamic_value)==self_type::rule_flag__has_dynamic_value;
}//TestRuleFlag__has_dynamic_value

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
