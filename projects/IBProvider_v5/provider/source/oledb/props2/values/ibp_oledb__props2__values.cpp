////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__values.cpp
//! \brief   Базовый класс контейнера значений свойств
//! \author  Kovalenko Dmitry
//! \date    01.01.2019
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/values/ibp_oledb__props2__values.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"

#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__prepare_get_value.h"
#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__get_value.h"
#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__extract_value.h"
#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__prepare_set_value.h"
#include "source/oledb/props2/handlers/ibp_oledb__props2__handler__get_default_value.h"

#include "source/error_services/ibp_error_utils.h"

#include <ole_lib/ole_auto/ole_auto_variant_compare.h>

#include <structure/utilities/to_underlying.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Values

IBP_OLEDB_Props2__Values::IBP_OLEDB_Props2__Values()
#ifndef NDEBUG
 :m_DEBUG__IsChild(false)
#endif
{
}//IBP_OLEDB_Props2__Values

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values::IBP_OLEDB_Props2__Values
                                           (const self_type*  const pX,
                                            tagCopyKind_Clone const copyTag)
 :inherited(pX,copyTag)
#ifndef NDEBUG
 ,m_DEBUG__IsChild(pX->m_DEBUG__IsChild)
#endif
{
}//IBP_OLEDB_Props2__Values

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values::IBP_OLEDB_Props2__Values
                                           (const self_type*  const pX,
                                            tagCopyKind_Child const copyTag)
 :inherited(pX,copyTag)
#ifndef NDEBUG
 ,m_DEBUG__IsChild(true)
#endif
{
}//IBP_OLEDB_Props2__Values

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values::~IBP_OLEDB_Props2__Values()
{
}//~IBP_OLEDB_Props2__Values

//interface --------------------------------------------------------------
#ifndef NDEBUG

bool IBP_OLEDB_Props2__Values::DEBUG__IsChild()const
{
 return m_DEBUG__IsChild;
}//DEBUG__IsChild

#endif //NDEBUG

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values::HasEqualPropValue
                                           (const IBP_OLEDB_Props2__Values* pOtherValues,
                                            REFGUID                         propGuid,
                                            DBPROPID                        propId)const
{
 assert(pOtherValues);

 //-----------------------------------------
 const wchar_t* const c_bugcheck_src
  =L"IBP_OLEDB_Props2__Values::HasEqualPropValue";

 //-----------------------------------------
 ole_lib::TVariant prop1_Value;

 const bool prop1_Has=this->Direct__GetValue(propGuid,propId,/*propOpt*/nullptr,&prop1_Value);

 ole_lib::TVariant prop2_Value;

 const bool prop2_Has=pOtherValues->Direct__GetValue(propGuid,propId,/*propOpt*/nullptr,&prop2_Value);

 if(!prop1_Has)
  return false;

 if(!prop2_Has)
  return false;

 if(prop1_Value.vt!=prop2_Value.vt)
  return false;

 const auto r=ole_lib::Variant_Compare(prop1_Value,prop2_Value);

 switch(r)
 {
  case ole_lib::VariantCmpCode__ok__equal:
   return true;

  case ole_lib::VariantCmpCode__ok__not_equal:
  case ole_lib::VariantCmpCode__ok__less:
  case ole_lib::VariantCmpCode__ok__great:
   return false;
 }//switch r

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (c_bugcheck_src,
   L"#001",
   L"Failed to compare property [%1].[%2] values. VarType: %3. Result Code: %4.",
   ole_lib::guid_to_wstring(propGuid),
   propId,
   prop1_Value.vt,
   structure::to_underlying(r));
}//HasEqualPropValue

//------------------------------------------------------------------------
oledb_lib::tagOLEDB_WMS IBP_OLEDB_Props2__Values::GetPropName
                                           (REFGUID  propGuid,
                                            DBPROPID propId)const
{
 return this->Internal__GetStaticPropData(propGuid,propId).m_PropDescr;
}//GetPropName

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values::Direct__GetUserValue
                                           (REFGUID               propGuid,
                                            DBPROPID        const propId,
                                            DBPROPOPTIONS*  const pResult_dwOptions,
                                            VARIANT*        const pResult_Value)const
{
#ifndef NDEBUG
 //[2019-01-11] Check propGuid and propId
 const auto& staticData=this->Internal__GetStaticPropData(propGuid,propId);

 assert(staticData.m_PropId==propId);
#endif

 return inherited::Internal__Direct__GetValue
         (propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//Direct__GetUserValue

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

bool IBP_OLEDB_Props2__Values::TESTCODE__Base__GetValue
                                           (REFGUID              propGuid,
                                            DBPROPID       const propId,
                                            DBPROPOPTIONS* const pResult_dwOptions,
                                            VARIANT*       const pResult_Value)const
{
 return inherited::Internal__Direct__GetValue
         (propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//TESTCODE__Base__GetValue

#endif //IBP_BUILD_TESTCODE

//OLEDB_Props2__Data__Values interface -----------------------------------
bool IBP_OLEDB_Props2__Values::Internal__HasValueOrDefault
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)const
{
#ifndef NDEBUG
 {
  //[2019-01-12] Check propGuid and propId
  const auto& staticData=this->Internal__GetStaticPropData(propGuid,propId);

  assert(staticData.m_PropId==propId);
 }
#endif

 if(inherited::Internal__HasValueOrDefault(propGuid,propId))
  return true;

 const auto& staticPropData
  =this->Internal__GetStaticPropData(propGuid,propId);

 auto const c_has_dynamic_value
  =oledb_lib::OLEDB_Props2__Data__Descr::rule_flag__has_dynamic_value;

 if((staticPropData.m_RuleFlags&c_has_dynamic_value)==c_has_dynamic_value)
  return true;

 if(staticPropData.m_Default.typeID!=IBP_OLEDB_Props2__DescrData::DefaultValueTypeID__empty)
  return true;

 return false;
}//Internal__HasValueOrDefault

//------------------------------------------------------------------------
void IBP_OLEDB_Props2__Values::Internal__PrepareGetValue
                                           (oledb_lib::OLEDB_Props2__Data__OpCtx& op_ctx,
                                            REFGUID                               propGuid,
                                            DBPROPID                      const   propId)const
{
 if(auto* const pHandler=this->Internal__GetStaticPropData(propGuid,propId).m_pHandler__PrepareGetValue)
 {
  return pHandler->PrepareGetValue
          (this,
           op_ctx,
           propGuid,
           propId); //throw
 }//if pHandler

 return inherited::Internal__PrepareGetValue
         (op_ctx,
          propGuid,
          propId);
}//Internal__PrepareGetValue

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values::Internal__GetValue
                                           (oledb_lib::OLEDB_Props2__Data__OpCtx& op_ctx,
                                            REFGUID                               propGuid,
                                            DBPROPID                       const  propId,
                                            DBPROPOPTIONS*                 const  pResult_dwOptions,
                                            VARIANT*                       const  pResult_Value)const
{
 assert(pResult_dwOptions);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 if(auto* const pHandler=this->Internal__GetStaticPropData(propGuid,propId).m_pHandler__GetValue)
 {
  return pHandler->GetValue
          (this,
           op_ctx,
           propGuid,
           propId,
           pResult_dwOptions,
           pResult_Value);
 }//if

 return inherited::Internal__GetValue
         (op_ctx,
          propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//Internal__GetValue

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values::Internal__ExtractValue
                                           (REFGUID            propGuid,
                                            DBPROPID     const propId,
                                            VARTYPE      const propVarType,
                                            const VARIANT&     sourceValue,
                                            VARIANT*     const pResultValue)const
{
 const auto& staticPropData
  =this->Internal__GetStaticPropData(propGuid,propId);

 if(staticPropData.m_pHandler__ExtractValue)
 {
  return staticPropData.m_pHandler__ExtractValue->ExtractValue
          (sourceValue,
           pResultValue);
 }//if

 //все строковые свойства должны пропускаться через специализированные обработчики
 assert(staticPropData.m_PropVarType!=VT_BSTR || (staticPropData.m_PropFlags&DBPROPFLAGS_WRITE)==0);

 return inherited::Internal__ExtractValue
         (propGuid,
          propId,
          propVarType,
          sourceValue,
          pResultValue);
}//Internal__ExtractValue

//------------------------------------------------------------------------
void IBP_OLEDB_Props2__Values::Internal__PrepareSetValue
                                           (oledb_lib::OLEDB_Props2__Data__OpCtx& op_ctx,
                                            REFGUID                               propGuid,
                                            DBPROPID                        const propId,
                                            DBPROPOPTIONS                   const dwOptions,
                                            const VARIANT&                        Value,
                                            DBPROPSTATUS*                   const pResult_dwStatus,
                                            VARIANT*                        const pResult_Value)const
{
 const auto& staticPropData
  =this->Internal__GetStaticPropData(propGuid,propId);

 assert(Value.vt==VT_EMPTY || Value.vt==staticPropData.m_PropVarType);

 assert(dwOptions==DBPROPOPTIONS_REQUIRED || dwOptions==DBPROPOPTIONS_OPTIONAL);

 if(staticPropData.m_pHandler__PrepareSetValue)
 {
  return staticPropData.m_pHandler__PrepareSetValue->PrepareSetValue
          (this,
           op_ctx,
           dwOptions,
           Value,
           pResult_dwStatus,
           pResult_Value);
 }//if

 return inherited::Internal__PrepareSetValue
         (op_ctx,
          propGuid,
          propId,
          dwOptions,
          Value,
          pResult_dwStatus,
          pResult_Value);
}//Internal__PrepareSetValue

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values::Internal__Direct__GetValue
                                           (REFGUID              propGuid,
                                            DBPROPID       const propId,
                                            DBPROPOPTIONS* const pResult_dwOptions,
                                            VARIANT*       const pResult_Value)const
{
#ifndef NDEBUG
 //[2019-01-12] Check propGuid and propId
 const auto& staticData=this->Internal__GetStaticPropData(propGuid,propId);

 assert(staticData.m_PropId==propId);
#endif

 if(inherited::Internal__Direct__GetValue
     (propGuid,
      propId,
      pResult_dwOptions,
      pResult_Value))
 {
  return true;
 }//if

 return self_type::Helper__GetValueFromStaticPropData
         (propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//Internal__Direct__GetValue

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values::Internal__Direct__GetDefaultValue
                                           (REFGUID        propGuid,
                                            DBPROPID const propId,
                                            VARIANT* const pResult_Value)const
{
#ifndef NDEBUG
 //[2019-01-11] Check propGuid and propId
 const auto& staticData=this->Internal__GetStaticPropData(propGuid,propId);

 assert(staticData.m_PropId==propId);
#endif

 assert(pResult_Value);

 if(inherited::Internal__Direct__GetDefaultValue
     (propGuid,
      propId,
      pResult_Value))
 {
  return true;
 }//if

 return self_type::Helper__GetValueFromStaticPropData
         (propGuid,
          propId,
          /*pResult_dwOptions*/nullptr,
          pResult_Value);
}//Internal__Direct__GetDefaultValue

//------------------------------------------------------------------------
void IBP_OLEDB_Props2__Values::Internal__Direct__SetValue
                                           (REFGUID             propGuid,
                                            DBPROPID      const propId,
                                            DBPROPOPTIONS const dwOptions,
                                            const VARIANT&      Value)
{
#ifndef NDEBUG
 //[2019-01-11] Check propGuid and propId
 const auto& staticData=this->Internal__GetStaticPropData(propGuid,propId);

 assert(staticData.m_PropId==propId);

 //[2019-01-16] Check value type
 assert(Value.vt==VT_EMPTY || Value.vt==staticData.m_PropVarType);
#endif

 return inherited::Internal__Direct__SetValue
         (propGuid,
          propId,
          dwOptions,
          Value);
}//Internal__Direct__SetValue

//Helper interface -------------------------------------------------------
bool IBP_OLEDB_Props2__Values::Helper__GetValueFromStaticPropData
                                           (REFGUID              propGuid,
                                            DBPROPID       const propId,
                                            DBPROPOPTIONS* const pResult_dwOptions,
                                            VARIANT*       const pResult_Value)const
{
 const auto& staticPropData=this->Internal__GetStaticPropData(propGuid,propId);

 assert(staticPropData.m_PropId==propId);

#ifndef NDEBUG
 auto const c_rule_flag__ibp_runtime_default
  =IBP_OLEDB_Props2__DescrData::rule_flag__ibp_runtime_default;
#endif

 if(staticPropData.m_pHandler__GetDefaultValue)
 {
  return staticPropData.m_pHandler__GetDefaultValue->GetDefaultValue
          (this,
           pResult_dwOptions,
           pResult_Value);
 }//if

 //Runtime value!
 assert((staticPropData.m_RuleFlags&c_rule_flag__ibp_runtime_default)==0);

 if(staticPropData.m_Default.typeID==IBP_OLEDB_Props2__DescrData::DefaultValueTypeID__empty)
 {
  return false;
 }//if

 if(pResult_Value)
 {
  staticPropData.CopyDefaultValueTo(pResult_Value); //throw

  assert(pResult_Value->vt==staticPropData.m_PropVarType);
 }//if

 if(pResult_dwOptions)
 {
  (*pResult_dwOptions)=staticPropData.m_DefaultOpt;
 }//if

 return true;
}//Helper__GetValueFromStaticPropData

//------------------------------------------------------------------------
void IBP_OLEDB_Props2__Values::Helper__Direct__CopyUserValue
                                 (const IBP_OLEDB_Props2__Values* const pSourceValues,
                                  REFGUID                               sourcePropGuid,
                                  DBPROPID                        const sourcePropId,
                                  REFGUID                               targetPropGuid,
                                  DBPROPID                        const targetPropId)
{
 ole_lib::TVariant propValue;
 DBROWOPTIONS      propOpt=0;

#ifndef NDEBUG
 //контроль согласованности типов источника и получателя.

 const auto& debug__t=this->Internal__GetStaticPropData(targetPropGuid,targetPropId);
 const auto& debug__s=pSourceValues->Internal__GetStaticPropData(sourcePropGuid,sourcePropId);

 assert(debug__s.m_PropVarType==debug__t.m_PropVarType);
#endif

 if(!pSourceValues->Direct__GetUserValue(sourcePropGuid,sourcePropId,&propOpt,&propValue))
  return;

 assert(propValue.vt!=VT_EMPTY);

 assert(propValue.vt==debug__s.m_PropVarType);

 this->Direct__SetValue(targetPropGuid,targetPropId,propOpt,propValue);
}//Helper__Direct__SetCopy

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
