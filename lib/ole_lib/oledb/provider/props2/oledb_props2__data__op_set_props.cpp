////////////////////////////////////////////////////////////////////////////////
//! \ingroup  oledb_lib_provider
//! \file     oledb_props2__data__op_set_props.cpp
//! \brief    Контекст операций со свойствами
//! \author   Kovalenko Dmitry
//! \date     28.11.2018
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_set_props.h>
#include <structure/t_str_formatter.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__OpSetProps::tag_prop_data

OLEDB_Props2__Data__OpSetProps::tag_prop_data::tag_prop_data
                        (const DBPROP& DbProp,
                         REFGUID       DbPropGuid)
 :m_DbProp             (DbProp)
#ifndef NDEBUG
 ,m_DbPropGuid         (DbPropGuid)
#endif
 ,m_pNext              (nullptr)
 ,m_propID             (DbPropGuid,DbProp.dwPropertyID)
 ,m_valueKind          (value_kind__IsPrimary)
 ,m_condKind           (cond_kind__None)
 ,m_prepare_status     (DBSTATUS_S_OK)
 ,m_ignore_assign      (false)
#ifndef NDEBUG
 ,m_DEBUG_was_prepared (false)
#endif
{
}//tag_prop_data

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::tag_prop_data::tag_prop_data
                        (const self_type* const pMaster,
                         REFGUID                propGuid,
                         DBPROPID         const propId,
                         value_kind_type  const valueKind,
                         cond_kind_type   const condKind)
 :m_DbProp             (structure::not_null_ptr(pMaster)->m_DbProp)
#ifndef NDEBUG
 ,m_DbPropGuid         (structure::not_null_ptr(pMaster)->m_DbPropGuid)
#endif
 ,m_pNext              (nullptr)
 ,m_propID             (propGuid,propId)
 ,m_valueKind          (valueKind)
 ,m_condKind           (condKind)
 ,m_prepare_status     (DBSTATUS_S_OK)
 ,m_ignore_assign      (false)
#ifndef NDEBUG
 ,m_DEBUG_was_prepared (false)
#endif
{
}//tag_prop_data

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::tag_prop_data::~tag_prop_data()
{
}//~tag_prop_data

//interface --------------------------------------------------------------
bool OLEDB_Props2__Data__OpSetProps::tag_prop_data::TestValueKind__IsSuperPrimary()const
{
 return m_valueKind==value_kind__IsSuperPrimary;
}//TestValueKind__IsSuperPrimary

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__OpSetProps::tag_prop_data::TestValueKind__IsPrimary()const
{
 return m_valueKind==value_kind__IsPrimary;
}//TestValueKind__IsPrimary

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__OpSetProps::tag_prop_data::TestValueKind__IsRelated()const
{
 return m_valueKind==value_kind__IsRelated;
}//TestValueKind__IsRelated

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__OpSetProps::tag_prop_data::TestValueKind__IsRelated_Optional()const
{
 return m_valueKind==value_kind__IsRelated_Optional;
}//TestValueKind__IsRelated_Optional

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__OpSetProps::tag_prop_data::TestValueKind__IsRelated_Condition()const
{
 return m_valueKind==value_kind__IsRelated_Condition;
}//TestValueKind__IsRelated_Condition

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__OpSetProps::tag_prop_data::TestValueWeight__IsPriority()const
{
 if(m_valueKind==value_kind__IsSuperPrimary)
  return true;

 if(m_valueKind==value_kind__IsPrimary)
  return true;

 return false;
}//TestValueWeight__IsPriority

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__OpSetProps

const GUID OLEDB_Props2__Data__OpSetProps::sm_id
 ={0x3C7CEC49,0xB644,0x4EDF,{0x83,0x6C,0x33,0xBD,0x2D,0xA2,0xEE,0x6C}};

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::OLEDB_Props2__Data__OpSetProps()
 :m_MainList__pHead(nullptr)
 ,m_QueueList__pHead(nullptr)
 ,m_ConditionList__pHead(nullptr)
{
};//OLEDB_Props2__Data__OpSetProps

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::~OLEDB_Props2__Data__OpSetProps()
{
}//~OLEDB_Props2__Data__OpSetProps

//interface --------------------------------------------------------------
REFGUID OLEDB_Props2__Data__OpSetProps::GetID()
{
 return sm_id;
}//GetID

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::Add_Primary(const DBPROP& DbProp,
                                             REFGUID       DbPropGuid)
{
 m_items.emplace_back(DbProp,DbPropGuid);

 assert(!m_items.empty());

 assert(&m_items.back().m_DbProp==&DbProp);
 assert(ole_lib::GuidEqual(m_items.back().m_DbPropGuid,DbPropGuid));

 assert(ole_lib::GuidEqual(m_items.back().m_propID.guid,DbPropGuid));
 assert(m_items.back().m_propID.id==DbProp.dwPropertyID);

 assert(m_items.back().m_value.vt==VT_EMPTY);

 assert(m_items.back().m_prepare_status==DBPROPSTATUS_OK);
 assert(m_items.back().TestValueKind__IsPrimary());

 assert(!m_items.back().m_ignore_assign);
 assert(!m_items.back().m_DEBUG_was_prepared);

 //----------------------
 m_items.back().m_pNext=m_MainList__pHead;

 m_MainList__pHead=&m_items.back();

 return structure::not_null_ptr(m_MainList__pHead);
}//Add_Primary

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::AddFromQueue()
{
 if(!m_QueueList__pHead)
  return nullptr;

 auto x=m_QueueList__pHead;

 m_QueueList__pHead=x->m_pNext;

 x->m_pNext=m_MainList__pHead;

 m_MainList__pHead=x;

 return structure::not_null_ptr(x);
}//AddFromQueue

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::AddChildProp_Related
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)
{
 assert(m_master_prop_data);

 m_items.emplace_back(m_master_prop_data,propGuid,propId,self_type::value_kind__IsRelated);

 assert(!m_items.empty());

 assert(&m_items.back().m_DbProp==&m_master_prop_data->m_DbProp);
 assert(ole_lib::GuidEqual(m_items.back().m_DbPropGuid,m_master_prop_data->m_DbPropGuid));

 assert(ole_lib::GuidEqual(m_items.back().m_propID.guid,propGuid));
 assert(m_items.back().m_propID.id==propId);

 assert(m_items.back().m_value.vt==VT_EMPTY);

 assert(m_items.back().m_prepare_status==DBPROPSTATUS_OK);
 assert(m_items.back().TestValueKind__IsRelated());

 assert(!m_items.back().m_ignore_assign);
 assert(!m_items.back().m_DEBUG_was_prepared);

 //----------------------
 m_items.back().m_pNext=m_MainList__pHead;

 m_MainList__pHead=&m_items.back();

 return structure::not_null_ptr(m_MainList__pHead);
}//AddChildProp_Related

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::AddChildProp_Related_Optional
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)
{
 assert(m_master_prop_data);

 m_items.emplace_back(m_master_prop_data,propGuid,propId,self_type::value_kind__IsRelated_Optional);

 assert(!m_items.empty());

 assert(&m_items.back().m_DbProp==&m_master_prop_data->m_DbProp);
 assert(ole_lib::GuidEqual(m_items.back().m_DbPropGuid,m_master_prop_data->m_DbPropGuid));

 assert(ole_lib::GuidEqual(m_items.back().m_propID.guid,propGuid));
 assert(m_items.back().m_propID.id==propId);

 assert(m_items.back().m_value.vt==VT_EMPTY);

 assert(m_items.back().m_prepare_status==DBPROPSTATUS_OK);
 assert(m_items.back().TestValueKind__IsRelated_Optional());

 assert(!m_items.back().m_ignore_assign);
 assert(!m_items.back().m_DEBUG_was_prepared);

 //----------------------
 m_items.back().m_pNext=m_MainList__pHead;

 m_MainList__pHead=&m_items.back();

 return structure::not_null_ptr(m_MainList__pHead);
}//AddChildProp_Related_Optional

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::AddChildProp_Related_Condition__Eq
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)
{
 return this->Helper__AddChildProp_Related_Condition
         (propGuid,
          propId,
          self_type::cond_kind__Eq);
}//AddChildProp_Related_Condition__Eq

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::AddChildProp_Related_Condition__NotEq
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)
{
 return this->Helper__AddChildProp_Related_Condition
         (propGuid,
          propId,
          self_type::cond_kind__NotEq);
}//AddChildProp_Related_Condition__NotEq

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::Helper__AddChildProp_Related_Condition
                                           (REFGUID              propGuid,
                                            DBPROPID       const propId,
                                            cond_kind_type const condKind)
{
 assert(m_master_prop_data);
 assert(m_master_prop_data->TestValueKind__IsPrimary());
 assert(m_master_prop_data->m_propID.guid!=propGuid || m_master_prop_data->m_propID.id!=propId);

 m_items.emplace_back
  (m_master_prop_data,
   propGuid,
   propId,
   self_type::value_kind__IsRelated_Condition,
   condKind);

 assert(!m_items.empty());

 assert(&m_items.back().m_DbProp==&m_master_prop_data->m_DbProp);
 assert(ole_lib::GuidEqual(m_items.back().m_DbPropGuid,m_master_prop_data->m_DbPropGuid));

 assert(ole_lib::GuidEqual(m_items.back().m_propID.guid,propGuid));
 assert(m_items.back().m_propID.id==propId);

 assert(m_items.back().m_value.vt==VT_EMPTY);

 assert(m_items.back().m_prepare_status==DBPROPSTATUS_OK);
 assert(m_items.back().TestValueKind__IsRelated_Condition());

 assert(m_items.back().m_condKind==condKind);

 assert(!m_items.back().m_ignore_assign);
 assert(!m_items.back().m_DEBUG_was_prepared);

 //----------------------
 m_items.back().m_pNext=m_ConditionList__pHead;

 m_ConditionList__pHead=&m_items.back();

 return structure::not_null_ptr(m_ConditionList__pHead);
}//AddChildProp_Related_Condition__Eq

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::QueueChildProp_Primary
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)
{
 assert(m_master_prop_data);

 m_items.emplace_back(m_master_prop_data,propGuid,propId,self_type::value_kind__IsPrimary);

 assert(!m_items.empty());

 assert(&m_items.back().m_DbProp==&m_master_prop_data->m_DbProp);
 assert(ole_lib::GuidEqual(m_items.back().m_DbPropGuid,m_master_prop_data->m_DbPropGuid));

 assert(ole_lib::GuidEqual(m_items.back().m_propID.guid,propGuid));
 assert(m_items.back().m_propID.id==propId);

 assert(m_items.back().m_value.vt==VT_EMPTY);

 assert(m_items.back().m_prepare_status==DBPROPSTATUS_OK);
 assert(m_items.back().TestValueKind__IsPrimary());

 assert(!m_items.back().m_ignore_assign);
 assert(!m_items.back().m_DEBUG_was_prepared);

 //----------------------
 m_items.back().m_pNext=m_QueueList__pHead;

 m_QueueList__pHead=&m_items.back();

 return structure::not_null_ptr(m_QueueList__pHead);
}//QueueChildProp_Primary

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_ptr
 OLEDB_Props2__Data__OpSetProps::QueueChildProp_SuperPrimary
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)
{
 assert(m_master_prop_data);

 m_items.emplace_back(m_master_prop_data,propGuid,propId,self_type::value_kind__IsSuperPrimary);

 assert(!m_items.empty());

 assert(&m_items.back().m_DbProp==&m_master_prop_data->m_DbProp);
 assert(ole_lib::GuidEqual(m_items.back().m_DbPropGuid,m_master_prop_data->m_DbPropGuid));

 assert(ole_lib::GuidEqual(m_items.back().m_propID.guid,propGuid));
 assert(m_items.back().m_propID.id==propId);

 assert(m_items.back().m_value.vt==VT_EMPTY);

 assert(m_items.back().m_prepare_status==DBPROPSTATUS_OK);
 assert(m_items.back().TestValueKind__IsSuperPrimary());

 assert(!m_items.back().m_ignore_assign);
 assert(!m_items.back().m_DEBUG_was_prepared);

 //----------------------
 m_items.back().m_pNext=m_QueueList__pHead;

 m_QueueList__pHead=&m_items.back();

 return structure::not_null_ptr(m_QueueList__pHead);
}//QueueChildProp_SuperPrimary

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::const_iterator
 OLEDB_Props2__Data__OpSetProps::All_Begin()const
{
 return m_items.cbegin();
}//All_Begin

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::const_iterator
 OLEDB_Props2__Data__OpSetProps::All_End()const
{
 return m_items.cend();
}//All_End

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_cptr
 OLEDB_Props2__Data__OpSetProps::GetMainList_Head()const
{
 return m_MainList__pHead;
}//GetMainList_Head

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::prop_data_cptr
 OLEDB_Props2__Data__OpSetProps::GetConditionList_Head()const
{
 return m_ConditionList__pHead;
}//GetConditionList_Head

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__OpSetProps::tag_master_prop_data_setup

OLEDB_Props2__Data__OpSetProps::tag_master_prop_data_setup::tag_master_prop_data_setup
                                           (OLEDB_Props2__Data__OpSetProps* const pOpData,
                                            const tag_prop_data*            const pPropData)
 :m_spOpData(structure::not_null_ptr(pOpData))
#ifndef NDEBUG
 ,m_spPropData(structure::not_null_ptr(pPropData))
#endif
{
 assert(m_spOpData);
 assert(m_spPropData);

 assert(!m_spOpData->m_master_prop_data);

 m_spOpData->m_master_prop_data=structure::not_null_ptr(pPropData);
}//tag_master_prop_data_setup

//------------------------------------------------------------------------
OLEDB_Props2__Data__OpSetProps::tag_master_prop_data_setup::~tag_master_prop_data_setup()
{
 assert(m_spOpData);
 assert(m_spPropData);

 assert(m_spOpData->m_master_prop_data);

 assert(m_spOpData->m_master_prop_data==m_spPropData.ptr());

 m_spOpData->m_master_prop_data.Release();
}//~tag_master_prop_data_setup

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
