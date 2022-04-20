////////////////////////////////////////////////////////////////////////////////
//LCPI Instrumental Library for C++.
//                                                 Dmitry Kovalenko. 20.11.2018.
#include <_pch_.h>
#pragma hdrstop

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>
#include <structure/t_handle.h>

namespace oledb_lib{
////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Values::tag_prop_value

OLEDB_Props2__Data__Values::tag_prop_value::tag_prop_value(DBPROPID const propId)
 :m_dwOptions(DBPROPOPTIONS_REQUIRED)
 ,m_propId(propId)
{
}//tag_prop_value

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::tag_prop_value::tag_prop_value(const self_type& x)
 :m_dwOptions(x.m_dwOptions)
 ,m_varValue(x.m_varValue)
 ,m_propId(x.m_propId)
{
}//tag_item - copy

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::tag_prop_value::~tag_prop_value()
{
}//~tag_prop_value

//------------------------------------------------------------------------
DBPROPID OLEDB_Props2__Data__Values::tag_prop_value::GetPropId()const
{
 return m_propId;
}//GetPropId

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Values::tag_prop_value_less

bool OLEDB_Props2__Data__Values::tag_prop_value_less::operator()
                                           (const tag_prop_value& x1,
                                            const tag_prop_value& x2)const
{
 return x1.GetPropId()<x2.GetPropId();
}//x1<x2

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::tag_prop_value_less::operator()
                                           (const tag_prop_value&  x,
                                            DBPROPID const         id)const
{
 return x.GetPropId()<id;
}//x<id

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::tag_prop_value_less::operator()
                                           (DBPROPID const         id,
                                            const tag_prop_value&  x)const
{
 return id<x.GetPropId();
}//id<x

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Values::tag_prop_set

OLEDB_Props2__Data__Values::tag_prop_set::tag_prop_set(const self_type& x)
 :m_PropSetGuid(x.m_PropSetGuid)
 ,m_PropValues(x.m_PropValues)
{
}

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::tag_prop_set::tag_prop_set(REFGUID propSetGuid)
 :m_PropSetGuid(propSetGuid)
{
}

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::tag_prop_set::operator == (REFGUID propSetGuid)const
{
 return ole_lib::GuidEqual(m_PropSetGuid,propSetGuid);
}//operator ==

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Values::tag_prop_sets

OLEDB_Props2__Data__Values::tag_prop_sets::tag_prop_sets()
{
}//tag_prop_sets

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::tag_prop_sets::tag_prop_sets(const self_type& x)
 :m_items(x.m_items)
{
}//tag_prop_sets

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::tag_prop_sets::~tag_prop_sets()
{
}//~tag_items

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::tag_prop_sets::self_ptr
 OLEDB_Props2__Data__Values::tag_prop_sets::clone()const
{
 return structure::not_null_ptr(new tag_prop_sets(*this));
}//clone

////////////////////////////////////////////////////////////////////////////////
//class OLEDB_Props2__Data__Values

OLEDB_Props2__Data__Values::OLEDB_Props2__Data__Values()
 :m_is_read_only(false)
#ifndef NDEBUG
 ,m_DEBUG__in_reset_top_values(false)
#endif
{
 m_stack.emplace_back(nullptr);
}//OLEDB_Props2__Data__Values

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::OLEDB_Props2__Data__Values
                                           (const self_type*  const pX,
                                            tagCopyKind_Clone const UNUSED_ARG(copyKind))
 :m_stack(structure::not_null_ptr(pX)->m_stack)
 ,m_is_read_only(pX->m_is_read_only)
#ifndef NDEBUG
 ,m_DEBUG__in_reset_top_values(false)
#endif
{
 assert(!m_stack.empty());
}//OLEDB_Props2__Data__Values - Clone

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::OLEDB_Props2__Data__Values
                                           (const self_type*  const pX,
                                            tagCopyKind_Child const UNUSED_ARG(copyKind))
 :m_stack(structure::not_null_ptr(pX)->m_stack)
 ,m_is_read_only(false)
#ifndef NDEBUG
 ,m_DEBUG__in_reset_top_values(false)
#endif
{
 assert(!m_stack.empty());

 m_stack.emplace_back(nullptr);
}//OLEDB_Props2__Data__Values - Child

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::OLEDB_Props2__Data__Values
                                           (const self_type*     const pX,
                                            tagCopyKind_ReadOnly const UNUSED_ARG(copyKind))
 :m_stack(structure::not_null_ptr(pX)->m_stack)
 ,m_is_read_only(true)
#ifndef NDEBUG
 ,m_DEBUG__in_reset_top_values(false)
#endif
{
 assert(!m_stack.empty());
}//OLEDB_Props2__Data__Values - ReadOnly

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::~OLEDB_Props2__Data__Values()
{
 assert(!m_DEBUG__in_reset_top_values);
}//~OLEDB_Props2__Data__Values

//interface --------------------------------------------------------------
bool OLEDB_Props2__Data__Values::HasValueOrDefault
                        (REFGUID                   propGuid,
                         DBPROPID            const propId)const
{
 return this->Internal__HasValueOrDefault
         (propGuid,
          propId);
}//HasValueOrDefault

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::PrepareGetValue
                        (OLEDB_Props2__Data__OpCtx& op_ctx,
                         REFGUID                    propGuid,
                         DBPROPID             const propId)const
{
 return this->Internal__PrepareGetValue
         (op_ctx,
          propGuid,
          propId);
}//PrepareGetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::GetValue
                        (OLEDB_Props2__Data__OpCtx& op_ctx,
                         REFGUID                    propGuid,
                         DBPROPID             const propId,
                         DBPROPOPTIONS*       const pResult_dwOptions,
                         VARIANT*             const pResult_Value)const
{
 assert(pResult_dwOptions);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 return this->Internal__GetValue
         (op_ctx,
          propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//GetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::ExtractValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         VARTYPE        const propVarType,
                         const VARIANT&       sourceValue,
                         VARIANT*       const pResultValue)const
{
 return this->Internal__ExtractValue
         (propGuid,
          propId,
          propVarType,
          sourceValue,
          pResultValue);
}//ExtractValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::PrepareSetValue
                        (OLEDB_Props2__Data__OpCtx& op_ctx,
                         REFGUID                    propGuid,
                         DBPROPID            const  propId,
                         DBPROPOPTIONS       const  dwOptions,
                         const VARIANT&             Value,
                         DBPROPSTATUS*       const  pResult_dwStatus,
                         VARIANT*            const  pResult_Value)const
{
 return this->Internal__PrepareSetValue
         (op_ctx,
          propGuid,
          propId,
          dwOptions,
          Value,
          pResult_dwStatus,
          pResult_Value);
}//PrepareSetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Direct__GetValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         DBPROPOPTIONS* const pResult_dwOptions,
                         VARIANT*       const pResult_Value)const
{
 return this->Internal__Direct__GetValue
         (propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//Direct__GetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Direct__GetDefaultValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         VARIANT*       const pResult_Value)const
{
 return this->Internal__Direct__GetDefaultValue
         (propGuid,
          propId,
          pResult_Value);
}//Direct__GetDefaultValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Direct__SetValue
                        (REFGUID             propGuid,
                         DBPROPID      const propId,
                         DBPROPOPTIONS const dwOptions,
                         const VARIANT&      Value)
{
 assert(!m_is_read_only);

 return this->Internal__Direct__SetValue
         (propGuid,
          propId,
          dwOptions,
          Value);
}//Direct__SetValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Direct__ForceResetTopValues()
{
 assert(!m_is_read_only);

 return this->Internal__Direct__ForceResetTopValues();
}//Direct__ForceResetTopValues

//AUX interface ----------------------------------------------------------
OLEDB_Props2__Data__Values::ids1_type
 OLEDB_Props2__Data__Values::AUX__GetAllIDs
                        (PFnFilter_ByGuid const pfnFilter)const
{
 ids1_type result;

 for(auto i1=m_stack.cbegin(),_e1=m_stack.cend();i1!=_e1;++i1)
 {
  if(!(*i1))
   continue;

  for(auto i2=(*i1)->m_items.cbegin(),_e2=(*i1)->m_items.cend();i2!=_e2;++i2)
  {
   if(pfnFilter && !pfnFilter((*i2).m_PropSetGuid))
    continue;

   if((*i2).m_PropValues.empty())
    continue;

   auto& result_set1=result[(*i2).m_PropSetGuid];

   for(auto i3=(*i2).m_PropValues.cbegin(),_e3=(*i2).m_PropValues.cend();i3!=_e3;++i3)
   {
    result_set1.insert((*i3).GetPropId());
   }//for i3
  }//for i2
 }//for i1

 return result;
}//AUX__GetAllIDs

//------------------------------------------------------------------------
std::wstring OLEDB_Props2__Data__Values::AUX__GetValue__wstr
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 const char c_bug_check_src[]
  ="OLEDB_Props2__Data__Values::AUX__GetValue__wstr";

 //-----------------------------------------
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  this->Helper__ThrowBugCheck__NoValue
   (c_bug_check_src,
    propGuid,
    propId);

#if(COMP_BUILD_UNUSED_CODE!=0)
   //недостижимая точка
   assert_hint(false);
#endif
  }//if

 if(propValue.vt==VT_BSTR)
 {
  return ole_lib::BStrToWStr(propValue.bstrVal);
 }//if

 this->Helper__ThrowBugCheck__BadValueType
  (c_bug_check_src,
   propGuid,
   propId,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE!=0)
 //недостижимая точка
 assert_hint(false);
#endif
}//AUX__GetValue__wstr

//------------------------------------------------------------------------
std::wstring OLEDB_Props2__Data__Values::AUX__GetValue__wstr_e
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 const char c_bug_check_src[]
  ="OLEDB_Props2__Data__Values::AUX__GetValue__wstr_e";

 //-----------------------------------------
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  return std::wstring();
 }//if

 if(propValue.vt==VT_BSTR)
 {
  return ole_lib::BStrToWStr(propValue.bstrVal);
 }//if

 this->Helper__ThrowBugCheck__BadValueType
  (c_bug_check_src,
   propGuid,
   propId,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE!=0)
 //недостижимая точка
 assert_hint(false);
#endif
}//AUX__GetValue__wstr_e

//------------------------------------------------------------------------
SHORT OLEDB_Props2__Data__Values::AUX__GetValue__short
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 const char c_bug_check_src[]
  ="OLEDB_Props2__Data__Values::AUX__GetValue__short";

 //-----------------------------------------
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  this->Helper__ThrowBugCheck__NoValue
   (c_bug_check_src,
    propGuid,
    propId);

#if(COMP_BUILD_UNUSED_CODE!=0)
   //недостижимая точка
   assert_hint(false);
#endif
  }//if

 if(propValue.vt==VT_I2)
 {
  return propValue.iVal;
 }//if

 this->Helper__ThrowBugCheck__BadValueType
  (c_bug_check_src,
   propGuid,
   propId,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE)
 //недостижимая точка
 assert_hint(false);
#endif
}//AUX__GetValue__short

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::short_type_n OLEDB_Props2__Data__Values::AUX__GetValue__short_n
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 const char c_bug_check_src[]
  ="OLEDB_Props2__Data__Values::AUX__GetValue__short_n";

 //-----------------------------------------
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  return short_type_n();
  }//if

 if(propValue.vt==VT_I2)
 {
  return short_type_n(propValue.iVal);
 }//if

 this->Helper__ThrowBugCheck__BadValueType
  (c_bug_check_src,
   propGuid,
   propId,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE!=0)
 //недостижимая точка
 assert_hint(false);
#endif
}//AUX__GetValue__short_n

//------------------------------------------------------------------------
LONG OLEDB_Props2__Data__Values::AUX__GetValue__long
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 const char c_bug_check_src[]
  ="OLEDB_Props2__Data__Values::AUX__GetValue__long";

 //-----------------------------------------
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  this->Helper__ThrowBugCheck__NoValue
   (c_bug_check_src,
    propGuid,
    propId);

#if(COMP_BUILD_UNUSED_CODE!=0)
   //недостижимая точка
   assert_hint(false);
#endif
  }//if

 if(propValue.vt==VT_I4)
 {
  return propValue.lVal;
 }//if

 this->Helper__ThrowBugCheck__BadValueType
  (c_bug_check_src,
   propGuid,
   propId,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE!=0)
 //недостижимая точка
 assert_hint(false);
#endif
}//AUX__GetValue__long

//------------------------------------------------------------------------
OLEDB_Props2__Data__Values::long_type_n OLEDB_Props2__Data__Values::AUX__GetValue__long_n
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 const char c_bug_check_src[]
  ="OLEDB_Props2__Data__Values::AUX__GetValue__long_n";

 //-----------------------------------------
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  return long_type_n();
  }//if

 if(propValue.vt==VT_I4)
 {
  return long_type_n(propValue.lVal);
 }//if

 this->Helper__ThrowBugCheck__BadValueType
  (c_bug_check_src,
   propGuid,
   propId,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE!=0)
 //недостижимая точка
 assert_hint(false);
#endif
}//AUX__GetValue__long_n

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::AUX__GetValue__bool
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 return this->Helper__AUX__GetValue__bool
         (propGuid,
          propId,
          "OLEDB_Props2__Data__Values::AUX__GetValue__bool"); //throw
}//AUX__GetValue__bool

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Helper__AUX__GetValue__bool
                        (REFGUID        propGuid,
                         DBPROPID const propId,
                         const char     bugcheck_src[])const
{
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  this->Helper__ThrowBugCheck__NoValue
   (bugcheck_src,
    propGuid,
    propId);

#if(COMP_BUILD_UNUSED_CODE!=0)
   //недостижимая точка
   assert_hint(false);
#endif
  }//if

 if(propValue.vt==VT_BOOL)
 {
  return propValue.boolVal!=VARIANT_FALSE;
 }//if

 this->Helper__ThrowBugCheck__BadValueType
  (bugcheck_src,
   propGuid,
   propId,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE!=0)
 //недостижимая точка
 assert_hint(false);
#endif
}//Helper__AUX__GetValue__bool

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::AUX__SetValue__req
                        (REFGUID             propGuid,
                         DBPROPID      const propId,
                         const VARIANT&      Value)
{
 assert(!m_is_read_only);

 //[2019-01-15] Req and EMPTY - for me it is incorrect.
 assert(Value.vt!=VT_EMPTY);

 return this->Internal__Direct__SetValue
         (propGuid,
          propId,
          DBPROPOPTIONS_REQUIRED,
          Value);
}//AUX__SetValue__req - unicode

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::AUX__SetValue__req__bstr
                        (REFGUID             propGuid,
                         DBPROPID      const propId,
                         wstr_box_type const Value)
{
 assert(!m_is_read_only);

 return this->Internal__Direct__SetValue
         (propGuid,
          propId,
          DBPROPOPTIONS_REQUIRED,
          ole_lib::TVariant(Value));
}//AUX__SetValue__req__bstr

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::AUX__SetValue__req__bstr
                        (REFGUID             propGuid,
                         DBPROPID      const propId,
                         str_box_type  const Value)
{
 assert(!m_is_read_only);

 return this->Internal__Direct__SetValue
         (propGuid,
          propId,
          DBPROPOPTIONS_REQUIRED,
          ole_lib::TVariant(Value));
}//AUX__SetValue__req__bstr - ansi

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::AUX__SetValue__req__bool
                        (REFGUID             propGuid,
                         DBPROPID      const propId,
                         bool          const Value)
{
 assert(!m_is_read_only);

 return this->Internal__Direct__SetValue
         (propGuid,
          propId,
          DBPROPOPTIONS_REQUIRED,
          ole_lib::TVariant(Value));
}//AUX__SetValue__req__bool

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::AUX__SetValue__req__short
                        (REFGUID             propGuid,
                         DBPROPID      const propId,
                         SHORT         const Value)
{
 assert(!m_is_read_only);

 return this->Internal__Direct__SetValue
         (propGuid,
          propId,
          DBPROPOPTIONS_REQUIRED,
          ole_lib::TVariant(Value));
}//AUX__SetValue__req__short

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::AUX__SetValue__req__long
                        (REFGUID             propGuid,
                         DBPROPID      const propId,
                         LONG          const Value)
{
 assert(!m_is_read_only);

 return this->Internal__Direct__SetValue
         (propGuid,
          propId,
          DBPROPOPTIONS_REQUIRED,
          ole_lib::TVariant(Value));
}//AUX__SetValue__req__long

//Internal interface -----------------------------------------------------
bool OLEDB_Props2__Data__Values::Internal__HasValueOrDefault
                        (REFGUID        propGuid,
                         DBPROPID const propId)const
{
 assert(!m_stack.empty());

 return this->Internal__Direct__GetValue
         (propGuid,
          propId,
          /*pResult_dwOption*/nullptr,
          /*pResult_Value*/nullptr);
}//Internal__HasValueOrDefault

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Internal__PrepareGetValue
                        (OLEDB_Props2__Data__OpCtx& UNUSED_ARG(op_ctx),
                         REFGUID                    UNUSED_ARG(propGuid),
                         DBPROPID             const UNUSED_ARG(propId))const
{
}//Internal__PrepareGetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Internal__GetValue
                        (OLEDB_Props2__Data__OpCtx& UNUSED_ARG(op_ctx),
                         REFGUID                    propGuid,
                         DBPROPID             const propId,
                         DBPROPOPTIONS*       const pResult_dwOptions,
                         VARIANT*             const pResult_Value)const
{
 assert(pResult_dwOptions);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 return this->Internal__Direct__GetValue
         (propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//Internal__GetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Internal__ExtractValue
                        (REFGUID              UNUSED_ARG(propGuid),
                         DBPROPID       const UNUSED_ARG(propId),
                         VARTYPE        const propVarType,
                         const VARIANT&       sourceValue,
                         VARIANT*       const pResultValue)const
{
 assert(sourceValue.vt!=VT_EMPTY);
 assert(pResultValue!=nullptr);

 HRESULT const hr
  =::VariantChangeType
    (pResultValue,
     const_cast<VARIANT*>(&sourceValue),
     0,
     propVarType);

 assert(hr==S_OK || FAILED(hr));

 if(hr==E_OUTOFMEMORY)
  throw std::bad_alloc();

 if(FAILED(hr))
  return false;

 assert(hr==S_OK);
 assert(pResultValue->vt==propVarType);

 return true;
}//Internal__ExtractValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Internal__PrepareSetValue
                        (OLEDB_Props2__Data__OpCtx& UNUSED_ARG(op_ctx),
                         REFGUID                    UNUSED_ARG(propGuid),
                         DBPROPID          const    UNUSED_ARG(propId),
                         DBPROPOPTIONS     const    UNUSED_ARG(dwOptions),
                         const VARIANT&             Value,
                         DBPROPSTATUS*     const    pResult_dwStatus,
                         VARIANT*          const    pResult_Value)const
{
 assert(pResult_dwStatus);
 assert(pResult_Value);

 ole_lib::Variant_CopyInd_Throw(pResult_Value,&Value); //throw

 (*pResult_dwStatus)=DBPROPSTATUS_OK;
}//Internal__PrepareSetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Internal__Direct__GetValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         DBPROPOPTIONS* const pResult_dwOptions,
                         VARIANT*       const pResult_Value)const
{
 return this->Helper__GetValue
         (propGuid,
          propId,
          pResult_dwOptions,
          pResult_Value);
}//Internal__Direct__GetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Internal__Direct__GetDefaultValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         VARIANT*       const pResult_Value)const
{
 return this->Helper__GetDefaultValue
         (propGuid,
          propId,
          pResult_Value);
}//Internal__Direct__GetDefaultValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Internal__Direct__SetValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         DBPROPOPTIONS  const dwOptions,
                         const VARIANT&       Value)
{
 assert(dwOptions==DBPROPOPTIONS_REQUIRED ||
        dwOptions==DBPROPOPTIONS_OPTIONAL);

 assert(!m_is_read_only);

 assert(!m_stack.empty());

 if(Value.vt==VT_EMPTY)
 {
  if(!m_stack.back())
   return;

  if(m_stack.back()->get_cntRef()>1)
  {
   m_stack.back()=m_stack.back()->clone(); //throw
  }//if

  assert(m_stack.back());
  assert(m_stack.back()->get_cntRef()==1);

  tag_prop_sets* const pBackSets=m_stack.back();

  assert(pBackSets);

  const auto x1
   =std::find(pBackSets->m_items.begin(),pBackSets->m_items.end(),propGuid);

  if(x1==pBackSets->m_items.end())
   return;

  assert((*x1)==propGuid);

  (*x1).m_PropValues.erase(propId);

  return;
 }//if Value.vt==VT_EMPTY

 assert(!m_DEBUG__in_reset_top_values);

 assert(Value.vt!=VT_EMPTY);

 ole_lib::TVariant propValueCopy;

 ole_lib::Variant_CopyInd_Throw(&propValueCopy,&Value); //throw

 assert(propValueCopy.vt!=VT_EMPTY);

 if(!m_stack.back())
 {
  m_stack.back()=structure::not_null_ptr(new tag_prop_sets()); //throw
 }
 else
 if(m_stack.back()->get_cntRef()>1)
 {
  m_stack.back()=m_stack.back()->clone(); //throw
 }//if

 assert(m_stack.back());
 assert(m_stack.back()->get_cntRef()==1);

 tag_prop_sets* const pBackSets=m_stack.back().ptr();

 assert(pBackSets);

 const auto x1
  =std::find(pBackSets->m_items.begin(),pBackSets->m_items.end(),propGuid);

 tag_prop_set* pPropSet;

 if(x1!=pBackSets->m_items.end())
 {
  pPropSet=&*x1;
 }
 else
 {
  pBackSets->m_items.emplace_back(propGuid); //no throw

  pPropSet=&pBackSets->m_items.back();
 }//else

 assert((*pPropSet)==propGuid);

 const auto x2=pPropSet->m_PropValues.insert(propId); //throw

 assert((*x2.first).GetPropId()==propId);

 (*x2.first).m_varValue.swap(propValueCopy); //no throw

 (*x2.first).m_dwOptions=dwOptions; //no throw
}//Internal__Direct__SetValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Internal__Direct__ForceResetTopValues()
{
 assert(!m_is_read_only);

 assert(!m_stack.empty());

 tag_prop_sets::self_ptr top;

 top.swap(m_stack.back());

 assert(!m_stack.back());

 if(top)
 {
  assert(!m_DEBUG__in_reset_top_values);

#ifndef NDEBUG
  const structure::t_auto_switch<bool>
   DEBUG__set_in_reset_top_values_flag(m_DEBUG__in_reset_top_values,true);
#endif

  assert(m_DEBUG__in_reset_top_values);

  for(auto i1=top->m_items.cbegin(),_e1=top->m_items.cend();i1!=_e1;++i1)
  {
   for(auto i2=(*i1).m_PropValues.cbegin(),_e2=(*i1).m_PropValues.cend();i2!=_e2;++i2)
   {
    this->Direct__SetValue
     ((*i1).m_PropSetGuid,
      (*i2).GetPropId(),
      DBPROPOPTIONS_OPTIONAL,
      ole_lib::TVariant::empty_variant); //no throw?

    //[2019-01-16] Expected that
    assert(!m_stack.empty());
    assert(!m_stack.back());
   }//for i2
  }//for i1

  assert(m_DEBUG__in_reset_top_values);
 }//if top
}//Internal__Direct__ForceResetTopValues

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Helper__GetValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         DBPROPOPTIONS* const pResult_dwOptions,
                         VARIANT*       const pResult_Value)const
{
 assert(!m_stack.empty());

 for(size_t iS=m_stack.size();iS!=0;)
 {
  --iS;

  const tag_prop_sets* const pPropSets=m_stack[iS].ptr();

  if(!pPropSets)
   continue;

  assert(pPropSets);

  const auto x1=std::find(pPropSets->m_items.cbegin(),pPropSets->m_items.cend(),propGuid);

  if(x1==pPropSets->m_items.cend())
   continue;

  assert((*x1)==propGuid);

  const auto x2=(*x1).m_PropValues.find(propId);

  if(x2==(*x1).m_PropValues.cend())
   continue;

  assert((*x2).GetPropId()==propId);

  if(pResult_Value)
   ole_lib::Variant_CopyInd_Throw(pResult_Value,&(*x2).m_varValue); //throw

  if(pResult_dwOptions)
   (*pResult_dwOptions)=(*x2).m_dwOptions;

  return true;
 }//for iS

 return false;
}//Helper__GetValue

//------------------------------------------------------------------------
bool OLEDB_Props2__Data__Values::Helper__GetDefaultValue
                        (REFGUID              propGuid,
                         DBPROPID       const propId,
                         VARIANT*       const pResult_Value)const
{
 assert(pResult_Value);

 assert(!m_stack.empty());

 for(size_t iS=m_stack.size()-1;iS!=0;)
 {
  --iS;

  const tag_prop_sets* const pPropSets=m_stack[iS].ptr();

  if(!pPropSets)
   continue;

  assert(pPropSets);

  const auto x1=std::find(pPropSets->m_items.cbegin(),pPropSets->m_items.cend(),propGuid);

  if(x1==pPropSets->m_items.cend())
   continue;

  assert((*x1)==propGuid);

  const auto x2=(*x1).m_PropValues.find(propId);

  if(x2==(*x1).m_PropValues.cend())
   continue;

  assert((*x2).GetPropId()==propId);

  ole_lib::Variant_CopyInd_Throw(pResult_Value,&(*x2).m_varValue); //throw

  return true;
 }//for iS

 return false;
}//Helper__GetDefaultValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Helper__ThrowBugCheck__NoValue
                                           (const char* const place,
                                            REFGUID           propGuid,
                                            DBPROPID    const propId)
{
 assert(place);

 structure::str_formatter
  fmsg("[BUG CHECK] No value of property [guid: %2][id: %3]. Check point: [%1].");

 fmsg<<place
     <<ole_lib::guid_to_string(propGuid)
     <<propId;

 assert_msg(false,fmsg.str());

 throw std::runtime_error(fmsg.str());
}//Helper__ThrowBugCheck__NoValue

//------------------------------------------------------------------------
void OLEDB_Props2__Data__Values::Helper__ThrowBugCheck__BadValueType
                                           (const char* const place,
                                            REFGUID           propGuid,
                                            DBPROPID    const propId,
                                            VARTYPE     const actualVarType)
{
 assert(place);

 structure::str_formatter
  fmsg("[BUG CHECK] Unexpected value type of property [guid: %2][id: %3]: %4. Check point: [%1].");

 fmsg<<place
     <<ole_lib::guid_to_string(propGuid)
     <<propId
     <<actualVarType;

 assert_msg(false,fmsg.str());

 throw std::runtime_error(fmsg.str());
}//Helper__ThrowBugCheck__BadValueType

////////////////////////////////////////////////////////////////////////////////
}//namespace oledb_lib
