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
//class OLEDB_Props2__Manager__Values::tag_set_op_helper

class OLEDB_Props2__Manager__Values::tag_set_op_helper
{
 private:
  typedef tag_set_op_helper                             self_type;

 public:
  typedef OLEDB_Props2__Data__OpSetProps::tag_prop_data set_prop_data_type;

 public:
  static void RebuildSetOpResults__statuses
          (tag_internal_set_props_ctx& op_ctx);

  static void RebuildSetOpResults
          (tag_internal_set_props_ctx& op_ctx);

 public:
  static bool TestCondition
          (const OLEDB_Props2__Data__Values* pValues,
           const set_prop_data_type*         pCondData,
           const VARIANT&                    propValue);

  static bool TestCondition__Eq
          (const OLEDB_Props2__Data__Values* pValues,
           const TDBPropID&                  propID,
           const VARIANT&                    propValue1,
           const VARIANT&                    propValue2);

  static void PrepareSetValue
          (tag_internal_set_props_ctx&       op_ctx,
           REFGUID                           propGuid,
           const OLEDB_Props2__Data__Descr&  Descr,
           set_prop_data_type*               pSetPropData,
           const VARIANT&                    PropValue);

  static DBPROPSTATUS Select_Bad_DbPropStatus
          (DBPROPSTATUS status1,
           DBPROPSTATUS status2);

  static size_t Get_DbPropStatus_Level
          (DBPROPSTATUS status);

 public:
  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__QueuedUnknownProperty
          (const TDBPropID& propID);

  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__UnknownCondKind
          (const set_prop_data_type* pCondData);

  COMP_CONF_DECLSPEC_NORETURN
  static void ThrowBugCheck__UnexpectedVarCompareResult
          (const TDBPropID& propID,
           VARTYPE          vt1,
           VARTYPE          vt2,
           int              resultCode);

 private:
  static const DBPROPSTATUS sm_DBStatusFromBadToGood[];
};//class OLEDB_Props2__Manager__Values::tag_set_op_helper

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values::tag_set_prop_data_less_by_id

class OLEDB_Props2__Manager__Values::tag_set_prop_data_less_by_id COMP_W000006_CLASS_FINAL
{
 public:
  typedef OLEDB_Props2__Data__OpSetProps::tag_prop_data  data_type;

 public:
  bool operator () (const data_type* const data1,
                    const data_type* const data2)const
  {
   assert(data1);
   assert(data2);

   return data1->m_propID<data2->m_propID;
  }//data1 < data2

  //----------------------------------------------------------------------
  bool operator () (const data_type* const data,
                    const TDBPropID&       propID)const
  {
   assert(data);

   return data->m_propID<propID;
  }//data < propID

  //----------------------------------------------------------------------
  bool operator () (const TDBPropID&       propID,
                    const data_type* const data)const
  {
   assert(data);

   return propID<data->m_propID;
  }//propID < data
};//class tag_set_prop_data_less_by_id

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values::tag_internal_set_prop_result_state
 
class OLEDB_Props2__Manager__Values::tag_internal_set_prop_result_state COMP_W000006_CLASS_FINAL
{
 public:
  DBPROPSTATUS status;
  bool         ignore;

  explicit tag_internal_set_prop_result_state(DBPROPSTATUS const s)
  {
   this->status=s;
   this->ignore=false;
  }

  bool is_ok()const
  {
   if(this->status!=DBPROPSTATUS_OK)
    return false;

   if(this->ignore)
    return false;

   return true;
  }//is_ok

  void correct_status(DBPROPSTATUS const newStatus)
  {
   this->status
    =tag_set_op_helper::Select_Bad_DbPropStatus(this->status,newStatus);
  }//correct_status
};//struct OLEDB_Props2__Manager__Values::tag_internal_set_prop_result_state

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx

class OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx COMP_W000006_CLASS_FINAL
{
 private:
  typedef tag_internal_set_props_ctx        self_type;

  tag_internal_set_props_ctx(const self_type&);
  self_type& operator = (const self_type&);

 public: //typedefs ------------------------------------------------------
  typedef structure::t_stl_set
           <TDBPropID,
            std::less<TDBPropID>,
            TOLEDBMemoryAllocator>          propids_type;

  typedef structure::t_stl_map
           <const DBPROP*,
            tag_internal_set_prop_result_state,
            std::less<const DBPROP*>,
            TOLEDBMemoryAllocator>          dbprop_statuses_type;

  typedef structure::t_tree_avl
           <OLEDB_Props2__Data__OpSetProps::prop_data_cptr,
            tag_set_prop_data_less_by_id,
            TOLEDBMemoryAllocator>          prop_datas_type;

 public: //ATTENTION: ORDER MATTERS. DO NOT CHANGE!
  const OLEDB_Props2__Data__Values::self_ptr m_spValues;

  OLEDB_Props2__Data__OpSetProps m_op_data;

  OLEDB_Props2__Data__OpCtx m_external_ctx;

  //Identifier of properties with conflicted values
  propids_type m_PropsWithConflictedValues;

  //Aggregated DBPROPSTATUS for each DBPROP
  dbprop_statuses_type m_ResultDbPropStatuses;

  prop_datas_type m_ResultPropValues;

  tag_internal_get_props_ctx m_get_op_ctx;

 public:
  explicit tag_internal_set_props_ctx(OLEDB_Props2__Data__Values* pValues);

 ~tag_internal_set_props_ctx();

  //interface ------------------------------------------------------------
  void prepare_prop_data
        (OLEDB_Props2__Data__OpSetProps::tag_prop_data* pPropData,
         const VARIANT&                                 propValue);

  void set_result_dbprop_status
        (const DBPROP* pDbProp,
         DBPROPSTATUS  dwPropStatus);
};//class OLEDB_Props2__Manager__Values::tag_internal_set_props_ctx

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
//class OLEDB_Props2__Manager__Values::tag_internal_set_prop_data

class OLEDB_Props2__Manager__Values::tag_internal_set_prop_data COMP_W000006_CLASS_FINAL
{
 private:
  typedef tag_internal_set_prop_data        self_type;

  tag_internal_set_prop_data(const self_type&);
  self_type& operator = (const self_type&);

 public:
  const TDBPropID m_propID;

  //May be null
  OLEDB_Props2__Data__OpSetProps::prop_data_cptr m_spData;

  size_t m_cPrimary;
  size_t m_cSuperPrimary;

  bool m_isConflict;

 public:
  explicit tag_internal_set_prop_data(const TDBPropID& propID);

 ~tag_internal_set_prop_data();
};//class OLEDB_Props2__Manager__Values::tag_internal_set_prop_data

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
//class OLEDB_Props2__Manager__Values::tag_internal_set_prop_data_less

class OLEDB_Props2__Manager__Values::tag_internal_set_prop_data_less_by_id COMP_W000006_CLASS_FINAL
{
 public:
  typedef tag_internal_set_prop_data        data_type;

 public:
  bool operator () (const data_type& data1,const data_type& data2)const
  {
   return data1.m_propID<data2.m_propID;
  }//data1<data2

  bool operator () (const data_type& data,const TDBPropID& id)const
  {
   return data.m_propID<id;
  }//data<id

  bool operator () (const TDBPropID& id,const data_type& data)const
  {
   return id<data.m_propID;
  }
};//class tag_internal_set_prop_data_less_by_id

////////////////////////////////////////////////////////////////////////////////
//OLEDB_Props2__Manager__Values

HRESULT OLEDB_Props2__Manager__Values::SetProperties
                        (OLEDB_Props2__Data__Values* const pValues,
                         ULONG                       const cPropertySets,
                         const DBPROPSET                   rgPropertySets[],
                         bool                        const Captious,
                         PFnFilter                   const pfnSetFilter,
                         SetPropValueTriggerType     const setPropValueTrigger__OnBefore,
                         SetPropValueTriggerType     const setPropValueTrigger__OnAfter)
{
 assert(pValues);

 if(cPropertySets!=0 && rgPropertySets==NULL)
  return E_INVALIDARG;

 const DBPROPSET* const pEndSrcDbSet=rgPropertySets+cPropertySets;

 {
  //! \todo
  //!  Выявлять пересекающиеся массивы значений.

  for(const DBPROPSET* pCurSrcDbSet=rgPropertySets;
      pCurSrcDbSet!=pEndSrcDbSet;
      ++pCurSrcDbSet)
  {
   if(pCurSrcDbSet->cProperties!=0 && pCurSrcDbSet->rgProperties==nullptr)
   {
    return E_INVALIDARG;
   }//if
  }//for pCurSrcDbSet
 }//local

 //----------------------------------------- 1. подготовка контекста операции
 tag_internal_set_props_ctx op_ctx(pValues);

 //Обработка значений из основного набора

 for(const DBPROPSET* pCurSrcDbSet=rgPropertySets;
     pCurSrcDbSet!=pEndSrcDbSet;
     ++pCurSrcDbSet)
 {
  if(const OLEDB_Props2__Data__Descrs* const pDescrs=this->Helper__FindDescrs(pCurSrcDbSet->guidPropertySet))
  {
   if(pfnSetFilter)
   {
    switch(DEBUG_CODE(const auto r=)pfnSetFilter(pDescrs))
    {
     case DBPROPSTATUS_OK:
      break;

     default:
      assert_msg(false,"r="<<r);

     case DBPROPSTATUS_NOTSUPPORTED:
     case DBPROPSTATUS_NOTSETTABLE:
      continue;
    }//switch
   }//if pfnSetFilter

   CHECK_READ_TYPED_PTR(pCurSrcDbSet->rgProperties,pCurSrcDbSet->cProperties);

   const DBPROP*       pDbProp=pCurSrcDbSet->rgProperties;
   const DBPROP* const eDbProp=pDbProp+pCurSrcDbSet->cProperties;

   for(;pDbProp!=eDbProp;++pDbProp)
   {
    auto const xDescr=pDescrs->find(pDbProp->dwPropertyID);

    if(xDescr==pDescrs->cend())
     continue;

    assert(xDescr!=pDescrs->cend());

    auto const pPropData=op_ctx.m_op_data.Add_Primary(*pDbProp,pDescrs->m_Guid);

    assert(pPropData);

    //------------------------------------- check options
    switch(pDbProp->dwOptions)
    {
     case DBPROPOPTIONS_REQUIRED:
     case DBPROPOPTIONS_OPTIONAL:
      break;

     default:
     {
      ODS_LEVEL_3
       ("ERR:Property "
        "\""<<structure::tstr_to_str((*xDescr).GetPropDescr())<<"\" "
        "has bad options: ["<<pDbProp->dwOptions<<"]");

      pPropData->m_prepare_status=DBPROPSTATUS_BADOPTION;
      continue;
     }//default
    }//switch pDbProp->dwOptions

    //------------------------------------- check columnid
    if(!TDBID::IsEqual(pDbProp->colid,DB_NULLID))
    {
     ODS_LEVEL_3
      ("ERR:Property "
       "\""<<structure::tstr_to_str((*xDescr).GetPropDescr())<<"\" "
       "has bad columnid: ["<<TDBID::Print(pDbProp->colid)<<"]");

     pPropData->m_prepare_status=DBPROPSTATUS_BADCOLUMN;
     continue;
    }//if

    //--------------------------------------
    tag_set_op_helper::PrepareSetValue
     (op_ctx,
      pDescrs->m_Guid,
      *xDescr,
      pPropData.ptr(),
      pDbProp->vValue); // throw
   }//for pDbProp

   assert(pDbProp==eDbProp);
  }//if pDescrs
 }//for pCurSrcDbSet

 //Обработка установки косвенных свойств
 while(const auto pPropData=op_ctx.m_op_data.AddFromQueue())
 {
  auto const pDescrs=this->Helper__FindDescrs(pPropData->m_propID.guid);

  if(!pDescrs)
   tag_set_op_helper::ThrowBugCheck__QueuedUnknownProperty(pPropData->m_propID);

  assert(pDescrs);
  assert(ole_lib::GuidEqual(pDescrs->m_Guid,pPropData->m_propID.guid));

  auto const xDescr=pDescrs->find(pPropData->m_propID.id);

  if(xDescr==pDescrs->cend())
   tag_set_op_helper::ThrowBugCheck__QueuedUnknownProperty(pPropData->m_propID);

  assert(xDescr!=pDescrs->cend());
  assert((*xDescr).GetPropId()==pPropData->m_propID.id);

  //----
  const ole_lib::TVariant copyValue(std::move(pPropData->m_value));

  assert(pPropData->m_value.vt==VT_EMPTY);

  pPropData->m_value.Clear();

  //----------------------------------------
  tag_set_op_helper::PrepareSetValue
   (op_ctx,
    pDescrs->m_Guid,
    *xDescr,
    pPropData.ptr(),
    copyValue); // throw
 }//while pPropData

 //----------------------------------------- 2. вычисление статуса каждого DBPROP

 //вычисляем базовый агрегированный DBPROPSTATUS для каждого DBPROP

 for(auto pPropData=op_ctx.m_op_data.GetMainList_Head();
     pPropData;
     pPropData=pPropData->m_pNext)
 {
#ifndef NDEBUG
  switch(pPropData->m_valueKind)
  {
   case OLEDB_Props2__Data__OpSetProps::value_kind__IsSuperPrimary:
   case OLEDB_Props2__Data__OpSetProps::value_kind__IsPrimary:
   case OLEDB_Props2__Data__OpSetProps::value_kind__IsRelated:
   case OLEDB_Props2__Data__OpSetProps::value_kind__IsRelated_Optional:
    break;

   default:
    assert(false);
  }//switch pPropData->m_valueKind
#endif

  op_ctx.set_result_dbprop_status(&(*pPropData).m_DbProp,(*pPropData).m_prepare_status);
 }//for pPropData

 //-----------------------------------------
 {
  structure::t_tree_avl
   <tag_internal_set_prop_data,
    tag_internal_set_prop_data_less_by_id,
    TOLEDBMemoryAllocator> ResultPropValues1;

  for(auto pPropData=op_ctx.m_op_data.GetMainList_Head();
      pPropData;
      pPropData=pPropData->m_pNext)
  {
   const auto x=ResultPropValues1.insert((*pPropData).m_propID);

   if(pPropData->TestValueKind__IsSuperPrimary())
   {
    ++(*x.first).m_cSuperPrimary;
   }
   else
   if(pPropData->TestValueKind__IsPrimary())
   {
    ++(*x.first).m_cPrimary;
   }
  }//for pPropData

  //---------------------------------------- CONFLICTS IN SUPER-PRIMARY AND PRIMARY
  for(auto pPropData=op_ctx.m_op_data.GetMainList_Head();
      pPropData;
      pPropData=pPropData->m_pNext)
  {
   assert(op_ctx.m_ResultDbPropStatuses.find(&(*pPropData).m_DbProp)!=op_ctx.m_ResultDbPropStatuses.end());

   auto& iPropData_DbProp_ResultStatus
    =(*op_ctx.m_ResultDbPropStatuses.find(&(*pPropData).m_DbProp)).second;

   //---------------------------------------
   const auto x=ResultPropValues1.find((*pPropData).m_propID);

   assert(x!=ResultPropValues1.end());

   //---------------------------------------
   if((*x).m_isConflict)
   {
    //пропускаем свойство, которое уже было помечено как конфликтное

    assert(op_ctx.m_PropsWithConflictedValues.find((*pPropData).m_propID)!=op_ctx.m_PropsWithConflictedValues.end());

    continue;
   }//if((*x).m_isConflict)

   //--------------------------------------- detect conflict of PRIMARY values at first
   if((*pPropData).TestValueKind__IsSuperPrimary())
   {
    if((*x).m_cSuperPrimary>1)
    {
     //Conflict at layer with super-primary values

     _VERIFY(op_ctx.m_PropsWithConflictedValues.insert((*pPropData).m_propID) DEBUG_CODE(.second));

     (*x).m_isConflict=true;

     continue;
    }//if
   }//if IsSuperPrimary
   else
   if((*pPropData).TestValueKind__IsPrimary())
   {
    if((*x).m_cPrimary>1)
    {
     //Conflict at layer with primary values

     _VERIFY(op_ctx.m_PropsWithConflictedValues.insert((*pPropData).m_propID) DEBUG_CODE(.second));

     (*x).m_isConflict=true;

     continue;
    }//if

    if((*x).m_cSuperPrimary>0)
    {
     //игнорируем primary-значения, если есть SUPER-primary значение

     iPropData_DbProp_ResultStatus.ignore=true;
    }//if
   }//if IsPrimary
  }//for pPropData

  tag_set_op_helper::RebuildSetOpResults__statuses(op_ctx);

  //---------------------------------------- detect all conflicts at value level

  for(auto pPropData=op_ctx.m_op_data.GetMainList_Head();
      pPropData;
      pPropData=pPropData->m_pNext)
  {
   assert(op_ctx.m_ResultDbPropStatuses.find(&(*pPropData).m_DbProp)!=op_ctx.m_ResultDbPropStatuses.end());

   auto& iPropData_DbProp_ResultStatus
    =(*op_ctx.m_ResultDbPropStatuses.find(&(*pPropData).m_DbProp)).second;

   //---------------------------------------
   if(!iPropData_DbProp_ResultStatus.is_ok())
   {
    //пропускаем свойства, привязанные к проблемным DBPROP
    continue;
   }//if

   assert((*pPropData).m_prepare_status==DBPROPSTATUS_OK);

   //---------------------------------------
   const auto x=ResultPropValues1.find((*pPropData).m_propID);

   assert(x!=ResultPropValues1.end());

   if((*x).m_isConflict)
   {
    assert(op_ctx.m_PropsWithConflictedValues.find((*pPropData).m_propID)!=op_ctx.m_PropsWithConflictedValues.end());

    continue;
   }//if

   assert(!(*x).m_isConflict);

   //---------------------------------------
   if(!(*x).m_spData)
   {
    (*x).m_spData=structure::not_null_ptr(&*pPropData);

    continue;
   }//if

   assert((*x).m_spData);
   assert((*x).m_spData->m_prepare_status==DBPROPSTATUS_OK);

   //---------------------------------------
   if(pPropData->TestValueKind__IsRelated_Optional())
   {
    //пропускаем опциональное значение
    continue;
   }//if

   assert(!pPropData->TestValueKind__IsRelated_Optional());

   //---------------------------------------
   if((*x).m_spData->TestValueKind__IsRelated_Optional())
   {
    //замещаем опциональное значение
    (*x).m_spData=structure::not_null_ptr(&*pPropData);

    continue;
   }//if

   assert(!(*x).m_spData->TestValueKind__IsRelated_Optional());

   //---------------------------------------
   if(!tag_set_op_helper::TestCondition__Eq
                           (pValues,
                            (*pPropData).m_propID,
                            (*x).m_spData->m_value,
                            (*pPropData).m_value))
   {
    _VERIFY(op_ctx.m_PropsWithConflictedValues.insert((*pPropData).m_propID) DEBUG_CODE(.second));

    (*x).m_isConflict=true;

    continue;
   }//if !TestCondition__Eq

   //equal values
  }//for pPropData
 }//local

 //----------------------------------------- 4. Rebuild Results
 tag_set_op_helper::RebuildSetOpResults(op_ctx);

 //----------------------------------------- 4.1 Check Conditions
 if(auto pPropCond=op_ctx.m_op_data.GetConditionList_Head())
 {
  //has conditions
  bool NeedRebuildResults=false;

  for(;;)
  {
   assert(pPropCond);
   assert(pPropCond->TestValueKind__IsRelated_Condition());

   //check new data
   const auto xNewPropData=op_ctx.m_ResultPropValues.find(pPropCond->m_propID);

   if(xNewPropData!=op_ctx.m_ResultPropValues.end())
   {
    assert(pPropCond->m_propID==(*xNewPropData)->m_propID);

    if(!tag_set_op_helper::TestCondition
                         (pValues,
                          pPropCond,
                          (*xNewPropData)->m_value))
    {
     //Failed. Installed another value that required. Process as conflict.
     NeedRebuildResults=true;

     _VERIFY(op_ctx.m_PropsWithConflictedValues.insert(pPropCond->m_propID) DEBUG_CODE(.second));
    }//if
   }//if - нашли в ResultPropValues
   else
   {
    //get current value in pValues
    ole_lib::TVariant currentPropValue;

    pValues->Direct__GetValue
     (pPropCond->m_propID.guid,
      pPropCond->m_propID.id,
      /*pResult_dwOption*/nullptr,
      &currentPropValue);

    if(!tag_set_op_helper::TestCondition
                          (pValues,
                           pPropCond,
                           currentPropValue))
    {
     //Failed. Installed another value that required. Process as conflict
     NeedRebuildResults=true;

     //[2019-01-14]
     //  May be duplicated. For example, failed cond for DBPROP_IDBAsynchStatus and ISSRowsetAsynch.
     op_ctx.m_PropsWithConflictedValues.insert(pPropCond->m_propID);
    }//if
   }//else

   pPropCond=pPropCond->m_pNext;

   if(!pPropCond)
    break;
  }//for[ever]

  //---------------------------------------- 4.2 Rebuild Results
  if(NeedRebuildResults)
  {
   tag_set_op_helper::RebuildSetOpResults(op_ctx);
  }//if
 }//if pPropCond

 //----------------------------------------- 5. Install Values

 //ResultPropValues contains only OK values!

 for(auto iValue=op_ctx.m_ResultPropValues.cbegin(),_eValue=op_ctx.m_ResultPropValues.cend();
     iValue!=_eValue;
     ++iValue)
 {
  assert(*iValue);

#ifndef NDEBUG
  {
   auto const debug_x=op_ctx.m_ResultDbPropStatuses.find(&(*iValue)->m_DbProp);

   assert(debug_x!=op_ctx.m_ResultDbPropStatuses.end());

   assert((*debug_x).second.is_ok());
  }//local
#endif

  //Если DBPROP не помечен как проблемный, значит и само значение OK.
  assert((*iValue)->m_prepare_status==DBPROPSTATUS_OK);

  //пропускаем Read-Only свойства
  if((*iValue)->m_ignore_assign)
   continue;

  //----------------------------------------
  if(setPropValueTrigger__OnBefore)
  {
   setPropValueTrigger__OnBefore
    (pValues,
     (*iValue)->m_propID.guid,
     (*iValue)->m_propID.id,
     (*iValue)->m_DbProp.dwOptions,
     (*iValue)->m_value); //throw
  }//if setPropValueTrigger__OnBefore

  //----------------------------------------
  pValues->Direct__SetValue
   ((*iValue)->m_propID.guid,
    (*iValue)->m_propID.id,
    (*iValue)->m_DbProp.dwOptions,
    (*iValue)->m_value); //throw

  //----------------------------------------
  if(setPropValueTrigger__OnAfter)
  {
   setPropValueTrigger__OnAfter
    (pValues,
     (*iValue)->m_propID.guid,
     (*iValue)->m_propID.id,
     (*iValue)->m_DbProp.dwOptions,
     (*iValue)->m_value); //throw
  }//if setPropValueTrigger__OnAfter
 }//for iValue

 //----------------------------------------- 6. Install Statuses
#ifndef NDEBUG
 size_t DEBUG__cTotalSrcDbProps_0=op_ctx.m_ResultDbPropStatuses.size();
#endif

 for(auto x=op_ctx.m_ResultDbPropStatuses.begin(),_e=op_ctx.m_ResultDbPropStatuses.end();
     x!=_e;
     ++x)
 {
  const_cast<DBPROP*>((*x).first)->dwStatus=(*x).second.status;
 }//for x

 //Process not supported DBPROP
 ULONG cNotSupportedDbSets=0;

 for(const DBPROPSET* pCurSrcDbSet=rgPropertySets;
     pCurSrcDbSet!=pEndSrcDbSet;
     ++pCurSrcDbSet)
 {
  CHECK_READ_TYPED_PTR(pCurSrcDbSet->rgProperties,pCurSrcDbSet->cProperties);

  if(const OLEDB_Props2__Data__Descrs* const pDescrs=this->Helper__FindDescrs(pCurSrcDbSet->guidPropertySet))
  {
   auto const FilterResult=(pfnSetFilter?pfnSetFilter(pDescrs):DBPROPSTATUS_OK);

   if(FilterResult==DBPROPSTATUS_OK)
   {
    DBPROP*             pDbProp=pCurSrcDbSet->rgProperties;
    const DBPROP* const eDbProp=pDbProp+pCurSrcDbSet->cProperties;

    for(;pDbProp!=eDbProp;++pDbProp)
    {
     if(op_ctx.m_ResultDbPropStatuses.find(pDbProp)!=op_ctx.m_ResultDbPropStatuses.end())
      continue;

#ifndef NDEBUG
     ++DEBUG__cTotalSrcDbProps_0;
#endif

     pDbProp->dwStatus=DBPROPSTATUS_NOTSUPPORTED;
    }//for pDbProp

    continue;
   }//if FilterResult==DBPROPSTATUS_OK

   assert_hint(FilterResult!=DBPROPSTATUS_OK);

   if(FilterResult==DBPROPSTATUS_NOTSETTABLE)
   {
    DBPROP*             pDbProp=pCurSrcDbSet->rgProperties;
    const DBPROP* const eDbProp=pDbProp+pCurSrcDbSet->cProperties;

    for(;pDbProp!=eDbProp;++pDbProp)
    {
     assert(op_ctx.m_ResultDbPropStatuses.find(pDbProp)==op_ctx.m_ResultDbPropStatuses.end());

     if(pDescrs->find(pDbProp->dwPropertyID)!=pDescrs->cend())
      pDbProp->dwStatus=FilterResult;
     else
      pDbProp->dwStatus=DBPROPSTATUS_NOTSUPPORTED;

#ifndef NDEBUG
     ++DEBUG__cTotalSrcDbProps_0;
#endif
    }//for pDbProp

    continue;
   }//if FilterResult==DBPROPSTATUS_NOTSETTABLE

   assert_hint(FilterResult!=DBPROPSTATUS_NOTSETTABLE);

   /*not supported DBPROPSET*/
   assert_msg(FilterResult==DBPROPSTATUS_NOTSUPPORTED,"FilterResult="<<FilterResult);
  }//if pDescrs

  /*Not supported DBPROPSET*/
  ++cNotSupportedDbSets;

#ifndef NDEBUG
  _VERIFY(structure::append_memory_size(DEBUG__cTotalSrcDbProps_0,pCurSrcDbSet->cProperties));
#endif

  DBPROP*             pDbProp=pCurSrcDbSet->rgProperties;
  const DBPROP* const eDbProp=pDbProp+pCurSrcDbSet->cProperties;

  for(;pDbProp!=eDbProp;++pDbProp)
  {
   assert(op_ctx.m_ResultDbPropStatuses.find(pDbProp)==op_ctx.m_ResultDbPropStatuses.end());

   pDbProp->dwStatus=DBPROPSTATUS_NOTSUPPORTED;
  }//for
 }//for pCurSrcDbSet

 //----------------------------------------- обработка результатов установки значений свойств
 OLE_LIB__DECLARE_HR(S_OK);

 {
  //анализ количества свойств, вызвавших сбой

  size_t cTotal=0;
  size_t cNotSet=0;
  size_t cNotSet_Req=0;
  size_t cNotSet_Opt=0;
  size_t cBadOpt=0;

  for(const DBPROPSET* pCurSrcDbSet=rgPropertySets;
      pCurSrcDbSet!=pEndSrcDbSet;
      ++pCurSrcDbSet)
  {
   assert(pCurSrcDbSet->cProperties==0 || pCurSrcDbSet->rgProperties!=NULL);

   DBPROP*             pDbProp=pCurSrcDbSet->rgProperties;
   const DBPROP* const eDbProp=pCurSrcDbSet->rgProperties+pCurSrcDbSet->cProperties;

   for(;pDbProp!=eDbProp;++pDbProp,++cTotal)
   {
    switch(pDbProp->dwStatus)
    {
     case DBPROPSTATUS_OK:
      continue;

     case DBPROPSTATUS_BADOPTION:
      ++cBadOpt;
      break;
    }//switch

    ++cNotSet;

    switch(pDbProp->dwOptions)
    {
     case DBPROPOPTIONS_REQUIRED:
      ++cNotSet_Req;
      break;

     case DBPROPOPTIONS_OPTIONAL:
      ++cNotSet_Opt;
      break;
    }//switch
   }//for pDbProp

   assert(pDbProp==eDbProp);
  }//for pCurSrcDbSet

  assert(cTotal==DEBUG__cTotalSrcDbProps_0);

  assert(cNotSet<=cTotal);

  if(cNotSet!=0)
  {
   if(!Captious)
   {
    if(cNotSet<cTotal)
     hr=DB_S_ERRORSOCCURRED;
    else
     hr=DB_E_ERRORSOCCURRED;
   }
   else
   {
    assert(Captious);

    if(cNotSet_Req!=0 || cBadOpt!=0)
     hr=DB_E_ERRORSOCCURRED;
    else
    if(cNotSet_Opt!=0)
     hr=DB_S_ERRORSOCCURRED;
   }//else
  }
  else
  if(cNotSupportedDbSets!=0)
  {
   hr=DB_S_ERRORSOCCURRED;
  }
 }//local

 return hr;
}//SetProperties

//Helper methods ---------------------------------------------------------
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
void OLEDB_Props2__Manager__Values::tag_set_op_helper::PrepareSetValue
                                     (tag_internal_set_props_ctx&      op_ctx,
                                      REFGUID                          propGuid,
                                      const OLEDB_Props2__Data__Descr& Descr,
                                      set_prop_data_type*        const pPropData,
                                      const VARIANT&                   PropValue)
{
 assert(pPropData);
 assert(Descr.GetPropId()==pPropData->m_propID.id);

 //-----------------------------------------
 assert(pPropData);
 assert(pPropData->m_prepare_status==DBPROPSTATUS_OK);
 assert(pPropData->m_value.vt==VT_EMPTY);
 assert(!pPropData->m_ignore_assign);

 //-----------------------------------------------------------------------
 
 // [2020-04-10] Завязываем с этим извращением.
 //const VARIANT* pAssignValue=ole_lib::Variant_Unpack(&PropValue);

 const VARIANT* pAssignValue=&PropValue;

 assert(pAssignValue);

 ole_lib::TVariant tmpValue;

 //need restore default value?
 if(pAssignValue->vt!=VT_EMPTY)
 {
  if(!op_ctx.m_spValues->ExtractValue
      (propGuid,
       Descr.GetPropId(),
       Descr.GetPropVarType(),
       *pAssignValue,
       &tmpValue))
  {
   ODS_LEVEL_3
    ("ERR: Property "
     "\""<<structure::tstr_to_str(Descr.GetPropDescr())<<"\" "
     "has bad new value: ["<<ole_lib::print(*pAssignValue)<<"]");

   pPropData->m_prepare_status=DBPROPSTATUS_BADVALUE;
   return;
  }//if

  pAssignValue=&tmpValue;
 }//pAssignValue->vt!=VT_EMPTY

 assert(pAssignValue);

 //[2020-04-10]
 assert(pAssignValue->vt==VT_EMPTY || pAssignValue->vt==Descr.GetPropVarType());

 for(;;)
 {
  if(Descr.TestPropFlag__IsWrite())
  {
   break;
  }//if

  assert(!Descr.TestPropFlag__IsWrite());

  //------------------------------------------------------------
  if(pAssignValue->vt==VT_EMPTY) //restore default value
  {
   //игнорируем сброс свойства без поддержки установки нового значения и с динамическим значением.
   pPropData->m_ignore_assign=Descr.TestRuleFlag__has_dynamic_value();
   break;
  }//if

  assert_hint(pAssignValue->vt!=VT_EMPTY);

  //------------------------------------------------------------
  if(!Descr.TestPropFlag__IsRead())
  {
   //
   // [2020-04-10]
   //  Это ненормальный случай.
   //
   //  Но мы его оставляем для обработки свойств, полученных неизвестно откуда.
   //

   ODS_LEVEL_3
    ("ERR: Property \""<<structure::tstr_to_str(Descr.GetPropDescr())<<"\" "
     "not settable");

   pPropData->m_prepare_status=DBPROPSTATUS_NOTSETTABLE;
   return;
  }//if !Descr.TestPropFlag__IsRead()

  assert_hint(Descr.TestPropFlag__IsRead());

  //------------------------------------------------------------
  //RTFM: Consumers can set the value of a read-only property to its current value

  ole_lib::TVariant currentValue;
  DBPROPOPTIONS     currentOptions=0;

  try
  {
   op_ctx.m_spValues->PrepareGetValue
    (op_ctx.m_get_op_ctx.m_external_ctx,
     propGuid,
     Descr.GetPropId()); //throw

   if(!op_ctx.m_spValues->GetValue(op_ctx.m_get_op_ctx.m_external_ctx,
                                   propGuid,
                                   Descr.GetPropId(),
                                   &currentOptions,
                                   &currentValue) /*throw*/)
   {
    //No default value! Process this situation as error.

    ODS_LEVEL_3
     ("ERR: Property \""<<structure::tstr_to_str(Descr.GetPropDescr())<<"\" "
      "is read only and not has default value. New value:"<<ole_lib::print(*pAssignValue));

    pPropData->m_prepare_status=DBPROPSTATUS_NOTSETTABLE;

    return;
   }//if
  }
  catch(std::exception& /*e*/)
  {
   ODS_LEVEL_3
    ("ERR: Failed to read property \""<<structure::tstr_to_str(Descr.GetPropDescr())<<"\" value");

   pPropData->m_prepare_status=DBPROPSTATUS_NOTAVAILABLE;

   return;
  }//catch

  switch(ole_lib::Variant_Compare(currentValue,*pAssignValue))
  {
   case ole_lib::VariantCmpCode__ok__equal:
   {
    pPropData->m_ignore_assign=true;
    break;
   }

   default:
   {
    ODS_LEVEL_3
     ("ERR: Property \""<<structure::tstr_to_str(Descr.GetPropDescr())<<"\" "
      "Read Only - new value:"<<ole_lib::print(*pAssignValue));

    pPropData->m_prepare_status=DBPROPSTATUS_NOTSETTABLE;
    return;
   }//default
  }//switch

  break;
 }//for[ever]

 assert(pPropData->m_prepare_status==DBPROPSTATUS_OK);

 op_ctx.prepare_prop_data
  (pPropData,
   *pAssignValue);

 return;
}//PrepareSetValue

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
