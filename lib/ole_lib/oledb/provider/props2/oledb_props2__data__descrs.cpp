////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 20.11.2018.
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__data__descrs.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Descrs::tag_item_less

bool OLEDB_Props2__Data__Descrs::tag_item_less::operator ()
                                           (const item_type& x1,
                                            const item_type& x2)const
{
 return x1.GetPropId()<x2.GetPropId();
}//x1<x2

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Descrs::tag_item_less::operator ()
                                           (const item_type& x,
                                            DBPROPID  const id)const
{
 return x.GetPropId()<id;
}//x<id

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Descrs::tag_item_less::operator ()
                                           (DBPROPID   const id,
                                            const item_type& x)const
{
 return id<x.GetPropId();
}//id<x

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Descrs

OLEDB_Props2__Data__Descrs::OLEDB_Props2__Data__Descrs(REFGUID      Guid,
                                                       REFGUID      SpecialGuid,
                                                       size_t const nCapacity)
 :m_Guid(Guid)
 ,m_SpecialGuid(SpecialGuid)
{
 m_items.reserve(nCapacity); //throw
}//OLEDB_Props2__Data__Descrs

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descrs::~OLEDB_Props2__Data__Descrs()
{
}//~OLEDB_Props2__Data__Descrs

//interface --------------------------------------------------------------
bool OLEDB_Props2__Data__Descrs::IsGuid(REFGUID Guid) const
{
 return ole_lib::GuidEqual(m_Guid,Guid);
}//IsGuid

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Descrs::IsSpecialGuid(REFCLSID SpecialGuid) const
{
 return ole_lib::GuidEqual(m_SpecialGuid,SpecialGuid);
}//IsSpecialGuid

//------------------------------------------------------------------------
size_t OLEDB_Props2__Data__Descrs::Count()const
{
 return m_items.size();
}//Count

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descrs::const_iterator OLEDB_Props2__Data__Descrs::cbegin()const
{
 return m_items.cbegin();
}//cbegin

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descrs::const_iterator OLEDB_Props2__Data__Descrs::cend()const
{
 return m_items.cend();
}//cend

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descrs::const_iterator OLEDB_Props2__Data__Descrs::begin()const
{
 return m_items.begin();
}//begin - const

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descrs::const_iterator OLEDB_Props2__Data__Descrs::end()const
{
 return m_items.end();
}//end - const

//------------------------------------------------------------------------
OLEDB_Props2__Data__Descrs::const_iterator OLEDB_Props2__Data__Descrs::find(DBPROPID propId)const
{
 return m_items.find(propId);
}//Find

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Descrs::Add(DBPROPID        const dwPropID,
                                     DBPROPFLAGS     const dwFlags,
                                     VARTYPE         const VarType,
                                     wms_type        const wmsDescription,
                                     rule_flags_type const ruleFlags)
{
 _VERIFY(m_items.emplace
          (dwPropID,
           wmsDescription,
           dwFlags,
           VarType,
           ruleFlags) DEBUG_CODE(.second));
}//Add

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
