////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__session__all.cpp
//! \brief   Определение описаний всех свойств сессии
//! \author  Kovalenko Dmitry
//! \date    31.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session__all.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__tr_iso_level.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__schema_cache.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__auto_commit_ddl.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__tr_abort_flags.h"

//------------------------------------------------------------------------
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__index_by_name.h"

#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include "source/oledb/ibp_oledb__prop__value_var_types.h"
#include "source/oledb/ibp_oledb__prop__names.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{namespace data{
////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
const IBP_OLEDB_Props2__DescrData                                         \
 IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::STD::sm_DescrFor__##PropId  \
  =IBP_OLEDB_Props2__DescrData                                            \
    (InitTag,                                                             \
     PropId,                                                              \
     PropDescr,                                                           \
     PropFlags,                                                           \
     PropRules,                                                           \
     ListOfAdditionalParams) POST_INIT_CALLS;

////////////////////////////////////////////////////////////////////////////////

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_std.dat"

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
const IBP_OLEDB_Props2__DescrData                                         \
 IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::EXT::sm_DescrFor__##PropId  \
  =IBP_OLEDB_Props2__DescrData                                            \
    (InitTag,                                                             \
     ibprovider::PropId,                                                  \
     PropDescr,                                                           \
     PropFlags,                                                           \
     PropRules,                                                           \
     ListOfAdditionalParams) POST_INIT_CALLS;

////////////////////////////////////////////////////////////////////////////////

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_ext.dat"

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

#define DEF_INDEX_ITEM(GROUP,PropId,NameIdx,ExpectedName)                 \
{                                                                         \
 IBP_OLEDB_Props2__Utils::GetWmsItem(GROUP::sm_DescrFor__##PropId.m_PropDescr,NameIdx),     \
 &GROUP::sm_DescrFor__##PropId,                                           \
 L##ExpectedName,                                                         \
},

#else

#define DEF_INDEX_ITEM(GROUP,PropId,NameIdx,ExpectedName)                 \
{                                                                         \
 IBP_OLEDB_Props2__Utils::GetWmsItem(GROUP::sm_DescrFor__##PropId.m_PropDescr,NameIdx),     \
 &GROUP::sm_DescrFor__##PropId                                            \
},

#endif

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data

class IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data
{
 public:
  static const IBP_OLEDB_Props2__DescrData_IndexByName_Item sm_IndexByName__std[];
  static const IBP_OLEDB_Props2__DescrData_IndexByName_Item sm_IndexByName__ext[];
};//class IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__DescrData_IndexByName_Item
 IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data::sm_IndexByName__std[]=
{
 DEF_INDEX_ITEM(STD,DBPROP_SESS_AUTOCOMMITISOLEVELS                       ,0,"Autocommit Isolation Levels")
};//sm_IndexByName__std

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL__tag_data__sm_IndexByName__std()
{
 IBP_OLEDB_Props2__DescrData_IndexByName_Item::DEBUG_Check_Range
  (IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data::sm_IndexByName__std,
   _END_(IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data::sm_IndexByName__std));
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL__tag_data__sm_IndexByName__std

STARTUP_CODE__DEBUG
 (DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL__tag_data__sm_IndexByName__std)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__DescrData_IndexByName_Item
 IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data::sm_IndexByName__ext[]=
{
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__SESSION__AUTO_COMMIT              ,0,"Session AutoCommit")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__SESSION__AUTO_COMMIT_DDL          ,0,"Session AutoCommit DDL")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__SESSION__AUTO_COMMIT_DDL_LEVEL    ,0,"Session AutoCommit DDL Level")

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__SESSION__INNER_TRANS              ,0,"Session InnerTrans")

#if(IBP_EDITION_ID!=IBP_EDITION_ID__FREE)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__SESSION__SCHEMA_CACHE             ,0,"Session Schema Cache")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__SESSION__TR_ABORT_FLAGS           ,0,"Session Transaction Abort Flags")
};//sm_IndexByName__ext

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL__tag_data__sm_IndexByName__ext()
{
 IBP_OLEDB_Props2__DescrData_IndexByName_Item::DEBUG_Check_Range
  (IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data::sm_IndexByName__ext,
   _END_(IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::tag_data::sm_IndexByName__ext));
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL__tag_data__sm_IndexByName__ext

STARTUP_CODE__DEBUG
 (DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL__tag_data__sm_IndexByName__ext)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
#undef DEF_INDEX_ITEM
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL

IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::find_result_type
 IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::Find(const wstr_box_type& Name)
{
 CHECK_READ_TYPED_PTR(Name.ptr,Name.len);

 if(auto const r=structure::lower_search(std::begin(tag_data::sm_IndexByName__std),
                                         std::end(tag_data::sm_IndexByName__std),
                                         Name,
                                         IBP_OLEDB_Props2__DescrData_IndexByName_Less()))
 {
  assert((*r.position).pDescr);

  return find_result_type(&DBPROPSET_SESSION,(*r.position).pDescr);
 }//if

 if(auto const r=structure::lower_search(std::begin(tag_data::sm_IndexByName__ext),
                                         std::end(tag_data::sm_IndexByName__ext),
                                         Name,
                                         IBP_OLEDB_Props2__DescrData_IndexByName_Less()))
 {
  assert((*r.position).pDescr);

  return find_result_type(&ibprovider::IBP_DBPROPSET_SESSION,(*r.position).pDescr);
 }//if

 return find_result_type(nullptr,nullptr);
}//Find - wstr_box

//------------------------------------------------------------------------
#ifndef NDEBUG

void IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::DEBUG__Check_sm_IndexByName()
{
 //----------------------------------------- check index for all descrs
#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
 for(const wchar_t* p=PropDescr.ptr();*p;p+=wcslen(p)+1)                  \
 {                                                                        \
  auto const x=self_type::Find(p);                                        \
                                                                          \
  assert(x.first);                                                        \
  assert(ole_lib::GuidEqual(*x.first,DBPROPSET_SESSION));                 \
  assert(x.second);                                                       \
  assert(x.second->m_PropId==PropId);                                     \
 }

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_std.dat"

#undef IBP_OLEDB_PROPS2__DESCR_DATA

 //-----------------------------------------
#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
 for(const wchar_t* p=PropDescr.ptr();*p;p+=wcslen(p)+1)                  \
 {                                                                        \
  auto const x=self_type::Find(p);                                        \
                                                                          \
  assert(x.first);                                                        \
  assert(ole_lib::GuidEqual(*x.first,ibprovider::IBP_DBPROPSET_SESSION)); \
  assert(x.second);                                                       \
  assert(x.second->m_PropId==ibprovider::PropId);                         \
 }

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_ext.dat"

#undef IBP_OLEDB_PROPS2__DESCR_DATA

 //-----------------------------------------
 for(auto x=std::begin(tag_data::sm_IndexByName__std);x!=std::end(tag_data::sm_IndexByName__std);++x)
 {
  auto const r=self_type::Find((*x).pName);

  assert(r.second==(*x).pDescr);
 }//for x

 //-----------------------------------------
 for(auto x=std::begin(tag_data::sm_IndexByName__ext);x!=std::end(tag_data::sm_IndexByName__ext);++x)
 {
  auto const r=self_type::Find((*x).pName);

  assert(r.second==(*x).pDescr);
 }//for x
}//DEBUG__Check_sm_IndexByName

#endif // NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::DEBUG__items_range_type
 IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::DEBUG__GetRange_STD()
{
 return DEBUG__items_range_type(tag_data::sm_IndexByName__std,_END_(tag_data::sm_IndexByName__std));
}//DEBUG__GetRange_STD

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::DEBUG__items_range_type
 IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::DEBUG__GetRange_EXT()
{
 return DEBUG__items_range_type(tag_data::sm_IndexByName__ext,_END_(tag_data::sm_IndexByName__ext));
}//DEBUG__GetRange_EXT

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
