////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descr_data.cpp
//! \brief   —туктура дл€ статического описани€ OLEDB свойства
//! \author  Kovalenko Dmitry
//! \date    13.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data.h"
#include "source/error_services/ibp_error_utils.h"
#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__DescrData::tag_ref_less

bool IBP_OLEDB_Props2__DescrData::tag_ref_less::operator ()
                        (const IBP_OLEDB_Props2__DescrData& x1,
                         const IBP_OLEDB_Props2__DescrData& x2)const
{
 return x1.m_PropId<x2.m_PropId;
}//x1<x2

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__DescrData::tag_ref_less::operator ()
                        (const IBP_OLEDB_Props2__DescrData& x,
                         DBPROPID                     const id)const
{
 return x.m_PropId<id;
}//x<id

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__DescrData::tag_ref_less::operator ()
                        (DBPROPID                     const id,
                         const IBP_OLEDB_Props2__DescrData& x)const
{
 return id<x.m_PropId;
}//id<x

////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__DescrData::tag_ptr_less

bool IBP_OLEDB_Props2__DescrData::tag_ptr_less::operator ()
                        (const IBP_OLEDB_Props2__DescrData* const p1,
                         const IBP_OLEDB_Props2__DescrData* const p2)const
{
 return p1->m_PropId<p2->m_PropId;
}//p1<p2

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__DescrData::tag_ptr_less::operator ()
                        (const IBP_OLEDB_Props2__DescrData* const p,
                         DBPROPID                           const id)const
{
 return p->m_PropId<id;
}//p<id

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__DescrData::tag_ptr_less::operator ()
                        (DBPROPID                           const id,
                         const IBP_OLEDB_Props2__DescrData* const p)const
{
 return id<p->m_PropId;
}//id<p

////////////////////////////////////////////////////////////////////////////////
//struct IBP_OLEDB_Props2__DescrData

IBP_OLEDB_Props2__DescrData::IBP_OLEDB_Props2__DescrData
                                           (tag_init__empty,
                                            DBPROPID          const PropId,
                                            wms_type          const PropDescr,
                                            DBPROPFLAGS       const PropFlags,
                                            rule_flags_type   const RuleFlags,
                                            VARTYPE           const PropVarType,
                                            DBPROPOPTIONS     const DefaultOpt)
 :m_PropId(PropId)
 ,m_PropDescr(PropDescr)
 ,m_PropFlags(PropFlags)
 ,m_RuleFlags(RuleFlags)
 ,m_PropVarType(PropVarType)
 ,m_DefaultOpt(DefaultOpt)
 ,m_Default()
 ,m_pHandler__ExtractValue(nullptr)
 ,m_pHandler__PrepareSetValue(nullptr)
 ,m_pHandler__PrepareGetValue(nullptr)
 ,m_pHandler__GetValue(nullptr)
 ,m_pHandler__GetDefaultValue(nullptr)
{
 assert(m_PropVarType!=VT_EMPTY);

 m_Default.typeID=DefaultValueTypeID__empty;
}//IBP_OLEDB_Props2__DescrData

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData::IBP_OLEDB_Props2__DescrData
                                           (tag_init__i2,
                                            DBPROPID          const PropId,
                                            wms_type          const PropDescr,
                                            DBPROPFLAGS       const PropFlags,
                                            rule_flags_type   const RuleFlags,
                                            DBPROPOPTIONS     const DefaultOpt,
                                            value_i2_type     const DefaultValue)
 :m_PropId(PropId)
 ,m_PropDescr(PropDescr)
 ,m_PropFlags(PropFlags)
 ,m_RuleFlags(RuleFlags)
 ,m_PropVarType(VT_I2)
 ,m_DefaultOpt(DefaultOpt)
 ,m_Default()
 ,m_pHandler__ExtractValue(nullptr)
 ,m_pHandler__PrepareSetValue(nullptr)
 ,m_pHandler__PrepareGetValue(nullptr)
 ,m_pHandler__GetValue(nullptr)
 ,m_pHandler__GetDefaultValue(nullptr)
{
 assert(m_PropVarType!=VT_EMPTY);

 m_Default.typeID      =DefaultValueTypeID__i2;
 m_Default.value.valI2 =DefaultValue;
}//IBP_OLEDB_Props2__DescrData - i2

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData::IBP_OLEDB_Props2__DescrData
                                           (tag_init__i4,
                                            DBPROPID          const PropId,
                                            wms_type          const PropDescr,
                                            DBPROPFLAGS       const PropFlags,
                                            rule_flags_type   const RuleFlags,
                                            DBPROPOPTIONS     const DefaultOpt,
                                            value_i4_type     const DefaultValue)
 :m_PropId(PropId)
 ,m_PropDescr(PropDescr)
 ,m_PropFlags(PropFlags)
 ,m_RuleFlags(RuleFlags)
 ,m_PropVarType(VT_I4)
 ,m_DefaultOpt(DefaultOpt)
 ,m_Default()
 ,m_pHandler__ExtractValue(nullptr)
 ,m_pHandler__PrepareSetValue(nullptr)
 ,m_pHandler__PrepareGetValue(nullptr)
 ,m_pHandler__GetValue(nullptr)
 ,m_pHandler__GetDefaultValue(nullptr)
{
 assert(m_PropVarType!=VT_EMPTY);

 m_Default.typeID      =DefaultValueTypeID__i4;
 m_Default.value.valI4 =DefaultValue;
}//IBP_OLEDB_Props2__DescrData - i4

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData::IBP_OLEDB_Props2__DescrData
                                           (tag_init__bool,
                                            DBPROPID          const PropId,
                                            wms_type          const PropDescr,
                                            DBPROPFLAGS       const PropFlags,
                                            rule_flags_type   const RuleFlags,
                                            DBPROPOPTIONS     const DefaultOpt,
                                            bool              const DefaultValue)
 :m_PropId(PropId)
 ,m_PropDescr(PropDescr)
 ,m_PropFlags(PropFlags)
 ,m_RuleFlags(RuleFlags)
 ,m_PropVarType(VT_BOOL)
 ,m_DefaultOpt(DefaultOpt)
 ,m_Default()
 ,m_pHandler__ExtractValue(nullptr)
 ,m_pHandler__PrepareSetValue(nullptr)
 ,m_pHandler__PrepareGetValue(nullptr)
 ,m_pHandler__GetValue(nullptr)
 ,m_pHandler__GetDefaultValue(nullptr)
{
 assert(m_PropVarType!=VT_EMPTY);

 m_Default.typeID        =DefaultValueTypeID__bool;
 m_Default.value.valBool =DefaultValue;
}//IBP_OLEDB_Props2__DescrData - bool

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData::IBP_OLEDB_Props2__DescrData
                                           (tag_init__wstr,
                                            DBPROPID          const PropId,
                                            wms_type          const PropDescr,
                                            DBPROPFLAGS       const PropFlags,
                                            rule_flags_type   const RuleFlags,
                                            DBPROPOPTIONS     const DefaultOpt,
                                            value_wstr_type   const staticDefaultValue)
 :m_PropId(PropId)
 ,m_PropDescr(PropDescr)
 ,m_PropFlags(PropFlags)
 ,m_RuleFlags(RuleFlags)
 ,m_PropVarType(VT_BSTR)
 ,m_DefaultOpt(DefaultOpt)
 ,m_Default()
 ,m_pHandler__ExtractValue(nullptr)
 ,m_pHandler__PrepareSetValue(nullptr)
 ,m_pHandler__PrepareGetValue(nullptr)
 ,m_pHandler__GetValue(nullptr)
 ,m_pHandler__GetDefaultValue(nullptr)
{
 assert(m_PropVarType!=VT_EMPTY);

 m_Default.typeID        =DefaultValueTypeID__wstr;
 m_Default.value.valWStr =staticDefaultValue;
}//IBP_OLEDB_Props2__DescrData - wstr

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData::IBP_OLEDB_Props2__DescrData
                                           (tag_init__str,
                                            DBPROPID          const PropId,
                                            wms_type          const PropDescr,
                                            DBPROPFLAGS       const PropFlags,
                                            rule_flags_type   const RuleFlags,
                                            DBPROPOPTIONS     const DefaultOpt,
                                            value_str_type    const staticDefaultValue)
 :m_PropId(PropId)
 ,m_PropDescr(PropDescr)
 ,m_PropFlags(PropFlags)
 ,m_RuleFlags(RuleFlags)
 ,m_PropVarType(VT_BSTR)
 ,m_DefaultOpt(DefaultOpt)
 ,m_Default()
 ,m_pHandler__ExtractValue(nullptr)
 ,m_pHandler__PrepareSetValue(nullptr)
 ,m_pHandler__PrepareGetValue(nullptr)
 ,m_pHandler__GetValue(nullptr)
 ,m_pHandler__GetDefaultValue(nullptr)
{
 assert(m_PropVarType!=VT_EMPTY);

 m_Default.typeID        =DefaultValueTypeID__str;
 m_Default.value.valStr  =staticDefaultValue;
}//IBP_OLEDB_Props2__DescrData - str

//Post init interface ----------------------------------------------------
IBP_OLEDB_Props2__DescrData&
 IBP_OLEDB_Props2__DescrData::PostInit_SetHandler_ExtractValue
                        (phandler__extract_value const pHandler)
{
 assert(pHandler);
 assert(!m_pHandler__ExtractValue);

 m_pHandler__ExtractValue=pHandler;

 return *this;
}//PostInit_SetHandler_ExtractValue

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData&
 IBP_OLEDB_Props2__DescrData::PostInit_SetHandler_PrepareSetValue
                        (phandler__prepare_set_value const pHandler)
{
 assert(pHandler);
 assert(!m_pHandler__PrepareSetValue);

 m_pHandler__PrepareSetValue=pHandler;

 return *this;
}//PostInit_SetHandler_PrepareSetValue

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData&
 IBP_OLEDB_Props2__DescrData::PostInit_SetHandler_PrepareGetValue
                        (phandler__prepare_get_value const pHandler)
{
 assert(pHandler);
 assert(!m_pHandler__PrepareGetValue);

 m_pHandler__PrepareGetValue=pHandler;

 return *this;
}//PostInit_SetHandler_PrepareGetValue

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData&
 IBP_OLEDB_Props2__DescrData::PostInit_SetHandler_GetValue
                        (phandler__get_value const pHandler)
{
 assert(pHandler);
 assert(!m_pHandler__GetValue);

 m_pHandler__GetValue=pHandler;

 return *this;
}//PostInit_SetHandler_GetValue

//------------------------------------------------------------------------
IBP_OLEDB_Props2__DescrData&
 IBP_OLEDB_Props2__DescrData::PostInit_SetHandler_GetDefaultValue
                        (phandler__get_default_value const pHandler)
{
 assert(pHandler);
 assert(!m_pHandler__GetDefaultValue);

 m_pHandler__GetDefaultValue=pHandler;

 return *this;
}//PostInit_SetHandler_GetDefaultValue

//interface --------------------------------------------------------------
void IBP_OLEDB_Props2__DescrData::CopyDefaultValueTo(VARIANT* const pResult_Value)const
{
 assert(pResult_Value);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"IBP_OLEDB_Props2__DescrData::CopyDefaultValueTo";

 //-----------------------------------------
 ole_lib::TVariant tmpValue;

 switch(m_Default.typeID)
 {
  case self_type::DefaultValueTypeID__empty:
   break;

  case self_type::DefaultValueTypeID__i2:
   assert(tmpValue.vt==VT_EMPTY);
   tmpValue.iVal=m_Default.value.valI2;
   tmpValue.vt=VT_I2;
   break;

  case self_type::DefaultValueTypeID__i4:
   assert(tmpValue.vt==VT_EMPTY);
   tmpValue.lVal=m_Default.value.valI4;
   tmpValue.vt=VT_I4;
   break;

  case self_type::DefaultValueTypeID__bool:
   tmpValue=m_Default.value.valBool; //throw

   assert(tmpValue.vt==VT_BOOL);
   break;

  case self_type::DefaultValueTypeID__wstr:
   tmpValue=m_Default.value.valWStr; //throw

   assert(tmpValue.vt==VT_BSTR);
   assert(tmpValue.bstrVal);
   break;

  case self_type::DefaultValueTypeID__str:
   tmpValue=m_Default.value.valStr; //throw

   assert(tmpValue.vt==VT_BSTR);
   assert(tmpValue.bstrVal);
   break;

  default:
  {
   IBP_ErrorUtils::Throw__BugCheck__DEBUG
    (c_bug_check_src,
     L"#001",
     L"Unknown typeID: %1",
     (int)m_Default.typeID);
  }//default
 }//switch(m_Default.typeID)

 tmpValue.swap(*pResult_Value);

 return;
}//CopyDefaultValueTo

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
