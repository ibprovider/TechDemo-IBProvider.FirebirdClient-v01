////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__handler__prepare_set_value__prop__ExtProps.cpp
//! \brief   Реализация PrepareSetValue для свойства "Extended Properties".
//! \author  Kovalenko Dmitry
//! \date    20.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/handlers/code/prepare_set_value/ibp_oledb__props2__handler__prepare_set_value__prop__ExtProps.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit__all.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate__all.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session__all.h"

#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error_bug_check.h"

#include "source/ibp_parameter_list_parser.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_ctx.h>
#include <ole_lib/oledb/provider/props2/oledb_props2__data__op_set_props.h>
#include <ole_lib/ole_auto/ole_auto_variant.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps

const IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::sm_Instance;

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps()
{
}//IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::~IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps()
{
}//~IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__Handler__PrepareSetValue*
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::GetInstancePtr()
{
 return &sm_Instance;
}//GetInstancePtr

//IBP_OLEDB_Props2__Handler__PrepareSetValue interface -------------------
void IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::PrepareSetValue
                              (const oledb_lib::OLEDB_Props2__Data__Values* const pValues,
                               oledb_lib::OLEDB_Props2__Data__OpCtx&              op_ctx,
                               DBPROPOPTIONS                                const UNUSED_ARG(sourceOptions),
                               const VARIANT&                                     sourceValue,
                               DBPROPSTATUS*                                const pResult_dwStatus,
                               VARIANT*                                     const pResult_Value)const
{
 assert(pResult_dwStatus);
 assert(pResult_Value);
 assert(pResult_Value->vt==VT_EMPTY);

 //-----------------------------------------
 const wchar_t* const c_bug_check_src
  =L"IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::PrepareSetValue";

 const auto* const pxValues
  =dynamic_cast<const IBP_OLEDB_Props2__Values__DATASOURCE*>(pValues);

 IBP_BUG_CHECK__DETECT_BAD_OBJECT_NULL_PTR
  (pxValues,
   c_bug_check_src,
   L"#001")

 assert_hint(pxValues);

 //-----------------------------------------
 if(sourceValue.vt==VT_EMPTY)
 {
  ole_lib::Variant_Clear_Throw(pResult_Value);

  (*pResult_dwStatus)=DBPROPSTATUS_OK;

  return;
 }//if

 assert(sourceValue.vt==VT_BSTR);

 IBP_ParameterListParser_WSTR Params;

 try
 {
  Params.parse(ole_lib::BStrToBox(sourceValue.bstrVal)); //throw
 }
 catch(const t_ibp_error& exc)
 {
  if(exc.com_code()==E_INVALIDARG)
  {
   //! \todo
   //!  Добавлять перехваченное исключение в CallCtx

   //ошибка в данных или в структуре строки с параметрами
   (*pResult_dwStatus)=DBPROPSTATUS_BADVALUE;

   return;
  }//if

  throw;
 }//catch

 oledb_lib::OLEDB_Props2__Data__OpSetProps::self_ptr
  spOpData=oledb_lib::OLEDB_Prop2__GetDBPropOpCtxItem<oledb_lib::OLEDB_Props2__Data__OpSetProps>(op_ctx);

 assert(spOpData);

 //----------------------
 const auto pfnFind
  =self_type::Helper__SelectFindFunc(pxValues->m_AllowedValuesKind);

 assert(pfnFind);

 //----------------------
 IBP_ParameterListParser_WSTR unexpectedParams;

 for(auto iParam=std::cbegin(Params),_eParam=std::cend(Params);iParam!=_eParam;++iParam)
 {
  assert(std::find((*iParam).name().cbegin(),(*iParam).name().cend(),0)==(*iParam).name().cend());

  const auto r=pfnFind((*iParam).name());

  if(r.first)
  {
   //add parameter to queue
   assert(r.first);
   assert(r.second);

   //! \todo Process empty non-quoted value as RESET value?

   const auto pPropData
    =spOpData->QueueChildProp_SuperPrimary
      ((*r.first),
       (*r.second).m_PropId);

   assert(pPropData);

   pPropData->m_value=(*iParam).value();

   continue;
  }//if

  assert(!r.first);
  assert(!r.second);

  unexpectedParams.set(*iParam);
 }//for iParam

 if(unexpectedParams.empty())
 {
  ole_lib::Variant_Clear_Throw(pResult_Value);
 }
 else
 {
  ole_lib::TVariant(unexpectedParams.to_string()).CopyTo_Throw(pResult_Value);
 }//else

 (*pResult_dwStatus)=DBPROPSTATUS_OK;
}//PrepareSetValue

//Helper methods ---------------------------------------------------------

IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::PFnFind
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::Helper__SelectFindFunc
                                           (IBP_OLEDB_Props2__Values__DATASOURCE::enumAllowedValuesKind const valuesKind)
{
 const wchar_t* const c_bug_check_src
  =L"IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::Helper__SelectFindFunc";

 switch(valuesKind)
 {
  case IBP_OLEDB_Props2__Values__DATASOURCE::AllowedValuesKind__DbInit:
   return self_type::Helper__Find1__DbInit;

  case IBP_OLEDB_Props2__Values__DATASOURCE::AllowedValuesKind__DbInit_DsCreate:
   return self_type::Helper__Find2__DbInit_DsCreate;

  case IBP_OLEDB_Props2__Values__DATASOURCE::AllowedValuesKind__DbInit_DsCreate_Sess:
   return self_type::Helper__Find3__DbInit_DsCreate_Sess;

  default:
   break;
 }//switch

 IBP_BUG_CHECK__DEBUG
  (c_bug_check_src,
   L"#001",
   L"unexpected m_AllowedValuesKind");

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//Helper__SelectFindFunc

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::find_result_type
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::Helper__Find1__DbInit
                                           (const wstr_box_type& propName)
{
 return data::IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::Find(propName);
}//Helper__Find1__DbInit

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::find_result_type
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::Helper__Find2__DbInit_DsCreate
                                           (const wstr_box_type& propName)
{
 const auto
  r=self_type::Helper__Find1__DbInit(propName);

 if(r.first)
  return r;

 return data::IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE__ALL::Find(propName);
}//Helper__Find2__DbInit_DsCreate

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::find_result_type
 IBP_OLEDB_Props2__Handler__PrepareSetValue__Prop__ExtProps::Helper__Find3__DbInit_DsCreate_Sess
                                           (const wstr_box_type& propName)
{
 const auto
  r=self_type::Helper__Find2__DbInit_DsCreate(propName);

 if(r.first)
  return r;

 return data::IBP_OLEDB_Props2__Descrs__Data__SESSION__ALL::Find(propName);
}//Helper__Find3__DbInit_DsCreate_Sess

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
