///////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 08.12.2018.
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__manager__values.h>
#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_set_props.h>
#include <ole_lib/ole_auto/ole_auto_variant_compare.h>

#include <structure/utilities/to_underlying.h>

#include <structure/stl/t_stl_set.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx

OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx::tag_internal_set_props_ctx
                                (OLEDB_Props2__Data__Values* const pValues)
 :m_spValues(structure::not_null_ptr(pValues))
 ,m_external_ctx()
 ,m_get_op_ctx(pValues)
{
 OLEDB_Prop2__AddDBPropOpCtxItem
  (m_external_ctx,
   &m_op_data);
}//tag_internal_set_props_ctx

//------------------------------------------------------------------------
OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx::~tag_internal_set_props_ctx()
{
}//~tag_internal_set_props_ctx

//------------------------------------------------------------------------
void OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx::prepare_prop_data
                        (OLEDB_Props2__Data__OpSetProps::tag_prop_data* const pPropData,
                         const VARIANT&                                       propValue)
{
 assert(pPropData);
 assert(m_spValues);

 assert(pPropData->m_prepare_status==DBPROPSTATUS_OK);

 //[2018-12-11] Expected that IsPrimary
 //[2019-01-20] Added IsSuperPrimary
 assert(pPropData->TestValueKind__IsPrimary() || pPropData->TestValueKind__IsSuperPrimary());

 assert(!pPropData->m_DEBUG_was_prepared);

#ifndef NDEBUG
 pPropData->m_DEBUG_was_prepared=true;
#endif

 const OLEDB_Props2__Data__OpSetProps::tag_master_prop_data_setup
  master_prop_data_setup(&m_op_data,pPropData);

 m_spValues->PrepareSetValue
  (m_external_ctx,
   pPropData->m_propID.guid,
   pPropData->m_propID.id,
   pPropData->m_DbProp.dwOptions,
   propValue,
   &pPropData->m_prepare_status,
   &pPropData->m_value);
}//prepare_prop_data

//------------------------------------------------------------------------
void OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx::set_result_dbprop_status
                                           (const DBPROP* const pDbProp,
                                            DBPROPSTATUS  const dwPropStatus)
{
 assert(pDbProp);

  // [2018-12-09] Test bad dbpropstatus value. Must be expected.
#ifndef NDEBUG
 if(dwPropStatus!=DBPROPSTATUS_OK)
  tag_set_op_helper::Get_DbPropStatus_Level(dwPropStatus);
#endif

 const auto x
  =m_ResultDbPropStatuses.insert
    (std::make_pair(pDbProp,tag_internal_set_prop_result_state(dwPropStatus)));

 if(x.second)
  return;

 //correction of dbpropstatus

 (*x.first).second.correct_status(dwPropStatus);
}//set_result_dbprop_status

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values::tag_internal_set_prop_data::tag_internal_set_prop_data

OLEDB_Props2__Manager__Values::tag_internal_set_prop_data::tag_internal_set_prop_data(const TDBPropID& propID)
 :m_propID(propID)
 ,m_cPrimary(0)
 ,m_cSuperPrimary(0)
 ,m_isConflict(false)
{
}

//------------------------------------------------------------------------
OLEDB_Props2__Manager__Values::tag_internal_set_prop_data::~tag_internal_set_prop_data()
{
}

////////////////////////////////////////////////////////////////////////////////
//OLEDB_Props2__Manager__Values

void OLEDB_Props2__Manager__Values::tag_set_op_helper::RebuildSetOpResults__statuses
                                     (tag_internal_set_props_ctx& op_ctx)
{
 //Mark all DBPROPS which linked with conflicted values
 for(auto pPropData=op_ctx.m_op_data.All_Begin(),_ePropData=op_ctx.m_op_data.All_End();
     pPropData!=_ePropData;
     ++pPropData)
 {
  if(op_ctx.m_PropsWithConflictedValues.find((*pPropData).m_propID)==op_ctx.m_PropsWithConflictedValues.end())
   continue;

  op_ctx.set_result_dbprop_status(&(*pPropData).m_DbProp,DBPROPSTATUS_CONFLICTING);
 }//for pPropData
}//RebuildSetOpResults__statuses

//------------------------------------------------------------------------
void OLEDB_Props2__Manager__Values::tag_set_op_helper::RebuildSetOpResults
                                     (tag_internal_set_props_ctx& op_ctx)
{
 self_type::RebuildSetOpResults__statuses(op_ctx);

 //----------------------------------------- 4. Rebuild Value List
 op_ctx.m_ResultPropValues.clear();

 for(auto pPropData=op_ctx.m_op_data.GetMainList_Head();
     pPropData;
     pPropData=pPropData->m_pNext)
 {
  auto const iPropData_DbProp_ResultStatus
   =op_ctx.m_ResultDbPropStatuses.find(&(*pPropData).m_DbProp);

  assert(iPropData_DbProp_ResultStatus!=op_ctx.m_ResultDbPropStatuses.end());

  if(!(*iPropData_DbProp_ResultStatus).second.is_ok())
   continue; //пропускаем свойства, привязанные к проблемным DBPROP

  assert((*pPropData).m_prepare_status==DBPROPSTATUS_OK);

  const auto x=op_ctx.m_ResultPropValues.insert(&*pPropData);

  if(x.second)
   continue;

  assert(*x.first);
  assert((*x.first)->m_propID==(*pPropData).m_propID);

  if(pPropData->TestValueKind__IsRelated_Optional())
   continue; //пропускаем опциональные значения

  if((*x.first)->TestValueKind__IsRelated_Optional())
  {
   //замещаем опциональные значения
   (*x.first)=structure::not_null_ptr(&*pPropData);

   continue;
  }//if

  if((*x.first)->m_DbProp.dwOptions!=(*pPropData).m_DbProp.dwOptions)
  {
   if((*x.first)->m_DbProp.dwOptions==DBPROPOPTIONS_REQUIRED)
    continue;

   (*x.first)=structure::not_null_ptr(&*pPropData);

   continue;
  }//if

  assert(((*x.first)->m_DbProp.dwOptions==(*pPropData).m_DbProp.dwOptions));

  if((*x.first)->TestValueWeight__IsPriority())
  {
   //[2019-01-04] Primary value has priority

   //[2019-01-04] Not allowed!
   assert(!pPropData->TestValueWeight__IsPriority());

   continue;
  }//if

  assert_hint(!(*x.first)->TestValueWeight__IsPriority());

  if(pPropData->TestValueWeight__IsPriority())
  {
   //[2019-01-04] Primary value has priority
  }//if
  else
  if((*x.first)->m_value.vt==VT_EMPTY)
  {
   continue;
  }//else

  (*x.first)=structure::not_null_ptr(&*pPropData);
 }//for iPropData
}//RebuildSetOpResults

//------------------------------------------------------------------------
bool OLEDB_Props2__Manager__Values::tag_set_op_helper::TestCondition
                                     (const OLEDB_Props2__Data__Values* const pValues,
                                      const set_prop_data_type*         const pCondData,
                                      const VARIANT&                          propValue)
{
 assert(pValues);
 assert(pCondData);
 assert(pCondData->TestValueKind__IsRelated_Condition());

 switch(pCondData->m_condKind)
 {
  case OLEDB_Props2__Data__OpSetProps::cond_kind__Eq:
  {
   return self_type::TestCondition__Eq(pValues,pCondData->m_propID,propValue,pCondData->m_value);
  }//case cond_kind__Eq

  case OLEDB_Props2__Data__OpSetProps::cond_kind__NotEq:
  {
   return !self_type::TestCondition__Eq(pValues,pCondData->m_propID,propValue,pCondData->m_value);
  }//case cond_kind__NotEq

  default:
  {
   break;
  }//default
 }//switch pSetPropData->m_condKind

 self_type::ThrowBugCheck__UnknownCondKind(pCondData); //throw!

#if(COMP_BUILD_UNUSED_CODE!=0)
 assert_hint(false);

 return false;
#endif
}//TestCondition

//------------------------------------------------------------------------
bool OLEDB_Props2__Manager__Values::tag_set_op_helper::TestCondition__Eq
                                     (const OLEDB_Props2__Data__Values* const pValues,
                                      const TDBPropID&                        propID,
                                      const VARIANT&                          propValue1,
                                      const VARIANT&                          propValue2)
{
 if(propValue1.vt==VT_EMPTY && propValue2.vt==VT_EMPTY)
 {
  //ok. equal values
  return true;
 }//if

 const VARIANT* pv1=&propValue1;
 const VARIANT* pv2=&propValue2;

 ole_lib::TVariant defaultValue;

 //take into account the "Reset"-values
 if(pv1->vt==VT_EMPTY || pv2->vt==VT_EMPTY)
 {
  const bool get_r=
   pValues->Direct__GetDefaultValue
    (propID.guid,
     propID.id,
     &defaultValue);

  if(!get_r)
  {
   //default значение не определено
   return false;
  }//if

  assert(get_r);
  assert(defaultValue.vt!=VT_EMPTY);

  if(pv1->vt==VT_EMPTY)
   pv1=&defaultValue;

  if(pv2->vt==VT_EMPTY)
   pv2=&defaultValue;
 }//if

 assert(pv1->vt!=VT_EMPTY);
 assert(pv2->vt!=VT_EMPTY);

 switch(const auto cmp_r=ole_lib::Variant_Compare(*pv1,*pv2))
 {
  case ole_lib::VariantCmpCode__ok__equal:
   return true;

  case ole_lib::VariantCmpCode__ok__not_equal:
  case ole_lib::VariantCmpCode__ok__less:
  case ole_lib::VariantCmpCode__ok__great:
   return false;

  default:
   self_type::ThrowBugCheck__UnexpectedVarCompareResult
    (propID,
     pv1->vt,
     pv2->vt,
     cmp_r);
 }//switch cmp_r

#if(COMP_BUILD_UNUSED_CODE!=0)
 return false;
#endif
}//TestCondition__Eq

//------------------------------------------------------------------------
DBPROPSTATUS OLEDB_Props2__Manager__Values::tag_set_op_helper::Select_Bad_DbPropStatus
                                           (DBPROPSTATUS const status1,
                                            DBPROPSTATUS const status2)
{
 assert(status1!=DBPROPSTATUS_NOTSUPPORTED);
 assert(status2!=DBPROPSTATUS_NOTSUPPORTED);

 if(status1==DBPROPSTATUS_OK)
  return status2;

 if(status2==DBPROPSTATUS_OK)
  return status1;

 const size_t level1
  =self_type::Get_DbPropStatus_Level(status1);

 const size_t level2
  =self_type::Get_DbPropStatus_Level(status2);

 if(level1<level2)
  return status1;

 return status2;
}//Select_Bad_DbPropStatus

//------------------------------------------------------------------------
const DBPROPSTATUS OLEDB_Props2__Manager__Values::tag_set_op_helper::sm_DBStatusFromBadToGood[]=
{
 //DBPROPSTATUS_NOTSUPPORTED,
 DBPROPSTATUS_BADOPTION,
 DBPROPSTATUS_CONFLICTING,
 DBPROPSTATUS_BADCOLUMN,
 DBPROPSTATUS_BADVALUE,
 DBPROPSTATUS_NOTSETTABLE,
 DBPROPSTATUS_NOTSET,
 DBPROPSTATUS_CONFLICTING,
};//sm_DBStatusFromBadToGood

//------------------------------------------------------------------------
size_t OLEDB_Props2__Manager__Values::tag_set_op_helper::Get_DbPropStatus_Level
                                           (DBPROPSTATUS const status)
{
 // [2018-12-09]
 assert(status!=DBPROPSTATUS_NOTSUPPORTED);

 const auto p
  =std::find(std::begin(sm_DBStatusFromBadToGood),std::end(sm_DBStatusFromBadToGood),status);

 // [2018-12-09]
 //  Detect unexpected status
 assert_msg(p!=std::end(sm_DBStatusFromBadToGood),
            "status="<<status);

 return p-std::begin(sm_DBStatusFromBadToGood);
}//Get_DbPropStatus_Level

//------------------------------------------------------------------------
void OLEDB_Props2__Manager__Values::tag_set_op_helper::ThrowBugCheck__QueuedUnknownProperty
                                           (const TDBPropID& propID)
{
 structure::str_formatter
  fmsg("[BUG CHECK] OLEDB_Props2__Manager__Values. Queued unknown property [guid: %1][id: %2].");

 fmsg<<ole_lib::guid_to_string(propID.guid)<<propID.id;

 assert_msg(false,fmsg.c_str());

 throw std::runtime_error(fmsg.str());
}//ThrowBugCheck__QueuedUnknownProperty

//------------------------------------------------------------------------
void OLEDB_Props2__Manager__Values::tag_set_op_helper::ThrowBugCheck__UnknownCondKind
                                     (const set_prop_data_type* const pCondData)
{
 assert(pCondData);

 structure::str_formatter
  fmsg("[BUG CHECK] OLEDB_Props2__Manager__Values. Unknown condition kind [%1] for property [guid: %2][id: %3].");

 fmsg
  <<structure::to_underlying(pCondData->m_condKind)
  <<ole_lib::guid_to_string(pCondData->m_propID.guid)
  <<pCondData->m_propID.id;

 assert_msg(false,fmsg.c_str());

 throw std::runtime_error(fmsg.str());
}//ThrowBugCheck__UnknownCondKind

//------------------------------------------------------------------------
void OLEDB_Props2__Manager__Values::tag_set_op_helper::ThrowBugCheck__UnexpectedVarCompareResult
                                     (const TDBPropID& propID,
                                      VARTYPE   const  vt1,
                                      VARTYPE   const  vt2,
                                      int       const  resultCode)
{
 structure::str_formatter
  fmsg("[BUG CHECK] OLEDB_Props2__Manager__Values. Compare values of property [guid: %1][id: %2]. VT1: %3. VT2: %4. Result Code: %5.");

 fmsg
  <<ole_lib::guid_to_string(propID.guid)
  <<propID.id
  <<int(vt1)
  <<int(vt2)
  <<resultCode;

 assert_msg(false,fmsg.c_str());

 throw std::runtime_error(fmsg.str());
}//ThrowBugCheck__UnexpectedVarCompareResult

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
