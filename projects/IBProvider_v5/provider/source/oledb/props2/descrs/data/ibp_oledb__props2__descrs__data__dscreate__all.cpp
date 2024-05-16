////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dscreate__all.cpp
//! \brief   Определение описаний всех свойств инициализации подключения
//! \author  Kovalenko Dmitry
//! \date    30.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate__all.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__cset_name.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__cset_collation_name.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__type_of_db_users.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__db_page_size.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__dialect.h"

//------------------------------------------------------------------------
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__index_by_name.h"

#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include "source/oledb/ibp_oledb__prop__names.h"

#include <structure/t_latin_lower.h>

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
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::EXT::sm_DescrFor__##PropId  \
  =IBP_OLEDB_Props2__DescrData                                            \
    (InitTag,                                                             \
     ibprovider::PropId,                                                  \
     PropDescr,                                                           \
     PropFlags,                                                           \
     PropRules,                                                           \
     ListOfAdditionalParams) POST_INIT_CALLS;

////////////////////////////////////////////////////////////////////////////////

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate.dat"

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
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::tag_data

class IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::tag_data
{
 public:
  static const IBP_OLEDB_Props2__DescrData_IndexByName_Item sm_IndexByName__ext[];
};//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__DescrData_IndexByName_Item
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::tag_data::sm_IndexByName__ext[]=
{
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__DSCREATE__DATABASE_DIALECT                ,0,"IBP_NEWDB: Database Dialect")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__DSCREATE__DATABASE_PAGE_SIZE              ,0,"IBP_NEWDB: Database Page Size")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__DSCREATE__DEFAULT_CHARSET                 ,0,"IBP_NEWDB: Default Charset")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__DSCREATE__DEFAULT_CHARSET_COLLATION       ,0,"IBP_NEWDB: Default Charset Collation")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__DSCREATE__TYPE_OF_DATABASE_USERS          ,0,"IBP_NEWDB: Type Of Database Users")
};//sm_IndexByName__ext

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL__tag_data__sm_IndexByName__ext()
{
 IBP_OLEDB_Props2__DescrData_IndexByName_Item::DEBUG_Check_Range
  (IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::tag_data::sm_IndexByName__ext,
   _END_(IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::tag_data::sm_IndexByName__ext));
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL__tag_data__sm_IndexByName__ext

STARTUP_CODE__DEBUG
 (DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL__tag_data__sm_IndexByName__ext)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
#undef DEF_INDEX_ITEM
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL

IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::find_result_type
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::Find(const wstr_box_type& Name)
{
 CHECK_READ_TYPED_PTR(Name.ptr,Name.len);

 if(auto const r
     =lib::structure::lower_search
       (_BEG_END_(tag_data::sm_IndexByName__ext),
        Name,
        IBP_OLEDB_Props2__DescrData_IndexByName_Less()))
 {
  assert((*r.position).pDescr);

  return find_result_type(&ibprovider::IBP_DBPROPSET_DATASOURCECREATE,(*r.position).pDescr);
 }//if

 return find_result_type(nullptr,nullptr);
}//Find - wstr_box

//------------------------------------------------------------------------
#ifndef NDEBUG

void IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::DEBUG__Check_sm_IndexByName()
{
 struct tag_check LCPI_CPP_CFG__CLASS__FINAL
 {
  public:
   static void exec(const wchar_t* propDescr,REFGUID setId,DBPROPID propId)
   {
    assert(propDescr);

    for(const wchar_t* p=propDescr;*p;p+=wcslen(p)+1)
    {
     auto const x=self_type::Find(p);

     assert(x.first);
     assert(ole_lib::GuidEqual(*x.first,setId));
     assert(x.second);
     assert(x.second->m_PropId==propId);
    }//for
   }//exec
 };//struct tag_check

 //----------------------------------------- check index for all descrs
#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
 tag_check::exec(PropDescr.ptr(),ibprovider::IBP_DBPROPSET_DATASOURCECREATE,ibprovider::PropId);

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate.dat"

#undef IBP_OLEDB_PROPS2__DESCR_DATA

 //-----------------------------------------
 for(auto x=std::begin(tag_data::sm_IndexByName__ext);x!=std::end(tag_data::sm_IndexByName__ext);++x)
 {
  auto const r=self_type::Find((*x).pName);

  assert(r.second==(*x).pDescr);
 }//for x
}//DEBUG__Check_sm_IndexByName

//------------------------------------------------------------------------
STARTUP_CODE_EX__DEBUG
 (IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL__DEBUG__Check_sm_IndexByName,
  IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::DEBUG__Check_sm_IndexByName);

#endif // NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::DEBUG__items_range_type
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::DEBUG__GetRange_EXT()
{
 return DEBUG__items_range_type(_BEG_END_(tag_data::sm_IndexByName__ext));
}//DEBUG__GetRange_EXT

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
