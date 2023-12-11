////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__values__datasource.cpp
//! \brief    онтейнер значений свойств источника данных
//! \author  Kovalenko Dmitry
//! \date    14.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/values/datasource/ibp_oledb__props2__values__datasource.h"

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_std.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_ext.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dsinfo_std.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dsinfo_ext.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dsinfo_sys.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__ds_std.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dscreate.h"

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_std.h"
#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__session_ext.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__first_week_day.h"

#include "source/oledb/ibp_oledb__prop__system_ids.h"
#include "source/oledb/ibp_oledb__prop__names.h"

#include "source/error_services/ibp_error_bug_check.h"

#include <structure/t_latin.h>

namespace lcpi{namespace ibp{namespace oledb{namespace props2{
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Values__DATASOURCE

IBP_OLEDB_Props2__Values__DATASOURCE::IBP_OLEDB_Props2__Values__DATASOURCE()
 :m_AllowedValuesKind(self_type::AllowedValuesKind__DbInit)
{
}//IBP_OLEDB_Props2__Values__DATASOURCE

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values__DATASOURCE::IBP_OLEDB_Props2__Values__DATASOURCE
                                           (const self_type*  const pX,
                                            tagCopyKind_Clone const copyTag)
 :inherited(pX,copyTag)
 ,m_AllowedValuesKind(self_type::AllowedValuesKind__DbInit)
{
 assert(pX->m_AllowedValuesKind==self_type::AllowedValuesKind__DbInit);

 this->OnGetConnectionStatus =pX->OnGetConnectionStatus;
 this->OnCanResetConnection  =pX->OnCanResetConnection;
}//IBP_OLEDB_Props2__Values__DATASOURCE

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values__DATASOURCE::IBP_OLEDB_Props2__Values__DATASOURCE
                                           (const self_type*  const pX,
                                            tagCopyKind_Child const copyTag)
 :inherited(pX,copyTag)
 ,m_AllowedValuesKind(self_type::AllowedValuesKind__DbInit)
{
 assert(pX->m_AllowedValuesKind==self_type::AllowedValuesKind__DbInit);

 this->OnGetConnectionStatus =pX->OnGetConnectionStatus;
 this->OnCanResetConnection  =pX->OnCanResetConnection;
}//IBP_OLEDB_Props2__Values__DATASOURCE

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values__DATASOURCE::~IBP_OLEDB_Props2__Values__DATASOURCE()
{
 assert(!this->OnGetConnectionStatus);
 assert(!this->OnCanResetConnection);
}//~IBP_OLEDB_Props2__Values__DATASOURCE

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values__DATASOURCE::self_ptr IBP_OLEDB_Props2__Values__DATASOURCE::Create()
{
 return lib::structure::not_null_ptr(new self_type());
}//Create

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values__DATASOURCE::self_ptr IBP_OLEDB_Props2__Values__DATASOURCE::CreateClone()const
{
 return lib::structure::not_null_ptr(new self_type(this,tagCopyKind_Clone()));
}//CreateClone

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Values__DATASOURCE::self_ptr IBP_OLEDB_Props2__Values__DATASOURCE::CreateChild()const
{
 assert(!this->DEBUG__IsChild());

 return lib::structure::not_null_ptr(new self_type(this,tagCopyKind_Child()));
}//CreateChild

//------------------------------------------------------------------------
void IBP_OLEDB_Props2__Values__DATASOURCE::ResetSinks()
{
 this->OnGetConnectionStatus=nullptr;

 this->OnCanResetConnection=nullptr;
}//ResetSinks

//interface --------------------------------------------------------------
bool IBP_OLEDB_Props2__Values__DATASOURCE::AllRequiredProps()const
{
 if(this->HasValueOrDefault(DBPROPSET_DBINIT,DBPROP_INIT_LOCATION))
 {
  //ok
 }
 else
 if(this->HasValueOrDefault(DBPROPSET_DBINIT,DBPROP_INIT_DATASOURCE))
 {
  //ok
 }
 else
 {
  return false;
 }//else

 return true;
}//AllRequiredProps

//------------------------------------------------------------------------
void IBP_OLEDB_Props2__Values__DATASOURCE::CheckRequiredProps()const//throw
{
 t_ibp_error error_builder(E_FAIL);

 if(this->HasValueOrDefault(DBPROPSET_DBINIT,DBPROP_INIT_LOCATION))
 {
  //ok
 }
 else
 if(this->HasValueOrDefault(DBPROPSET_DBINIT,DBPROP_INIT_DATASOURCE))
 {
  //ok
 }
 else
 {
  error_builder.add_error(E_FAIL,ibp_mce_no_def_req_init_prop_1)
   <<IBP_DBPROP_NAME__INIT__LOCATION;
 }//if

 //[2012-08-24] ќсновной код не должен изменитьс€
 assert(error_builder.com_code()==E_FAIL);

 if(error_builder.get_record_count())
  error_builder.raise_me();
}//CheckRequiredProps

//------------------------------------------------------------------------
HWND IBP_OLEDB_Props2__Values__DATASOURCE::GetWindowHandle()const
{
 const wchar_t* const c_bugcheck_src
  =L"IBP_OLEDB_Props2__Values__DATASOURCE::GetWindowHandle";

 //------------------------------------
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOptions=0;

 if(!this->Direct__GetValue(DBPROPSET_DBINIT,DBPROP_INIT_HWND,&propOptions,&propValue))
  return ::GetActiveWindow();

 //[2018-12-15]
 assert(propValue.vt!=VT_EMPTY);

#if  (IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)

 assert_s(sizeof(HWND)==_MEMBER_SIZE_(VARIANT,llVal));
 assert_s(sizeof(HWND)==_MEMBER_SIZE_(VARIANT,ullVal));

 switch(propValue.vt)
 {
  case VT_I8:
   return (HWND)propValue.llVal;

  case VT_UI8:
   return (HWND)propValue.ullVal;
 }//switch

#elif(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)

 assert_s(sizeof(HWND)==_MEMBER_SIZE_(VARIANT,lVal));
 assert_s(sizeof(HWND)==_MEMBER_SIZE_(VARIANT,ulVal));

 switch(propValue.vt)
 {
  case VT_I4:
   return (HWND)propValue.lVal;

  case VT_UI4:
   return (HWND)propValue.ulVal;
 }//switch

#else

# error Unknown IBP_PLATFORM_ID!

#endif

 IBP_ThrowBugCheck__UnexpectedPropValueType
  (c_bugcheck_src,
   L"001",
   IBP_DBPROP_NAME__INIT__HWND,
   propValue.vt);

#if(COMP_BUILD_UNUSED_CODE!=0)
 return nullptr;
#endif
}//GetWindowHandle

//------------------------------------------------------------------------
t_ibp_string IBP_OLEDB_Props2__Values__DATASOURCE::GetDbLibrary()const
{
 /// ¬ случае 64-битной сборки, значение свойства "dbclient_library_64" €вл€етс€
 /// приоритетным.

#if(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_AMD64)
 {
  t_ibp_string
   s(this->AUX__GetValue__wstr_e(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__DBCLIENT_LIBRARY_64));

  if(!s.empty())
   return s;
 }//local
#elif(IBP_PLATFORM_ID==IBP_PLATFORM_ID__WINNT_X86)
#else
# error Unknown IBP_PLATFORM_ID!
#endif

 //Other platforms (Windows 32bit)

 return this->AUX__GetValue__wstr_e(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__DBCLIENT_LIBRARY);
}//GetDbLibrary

//------------------------------------------------------------------------
std::wstring IBP_OLEDB_Props2__Values__DATASOURCE::GetDatabaseLocation_REQ(t_ibp_subsystem_id const subsystemID)const
{
 ole_lib::TVariant varPropValue__Database;

 if(this->Direct__GetValue(DBPROPSET_DBINIT,
                           DBPROP_INIT_LOCATION,
                           /*pOpt*/nullptr,
                           &varPropValue__Database))
 {
  assert(varPropValue__Database.vt==VT_BSTR);

  /*OK*/
 }//if
 else
 if(this->Direct__GetValue(DBPROPSET_DBINIT,
                           DBPROP_INIT_DATASOURCE,
                           nullptr,
                           &varPropValue__Database))
 {
  assert(varPropValue__Database.vt==VT_BSTR);

  /*OK*/
 }
 else
 {
  //DONE 3: Ќе определено им€ файла базы данных
  t_ibp_error exc(E_FAIL,
                  subsystemID,
                  ibp_mce_no_def_req_init_prop_1);

  exc<<IBP_DBPROP_NAME__INIT__LOCATION;

  exc.raise_me();
 }//else

 assert(varPropValue__Database.vt==VT_BSTR);

 return ole_lib::BStrToWStr(varPropValue__Database.bstrVal);
}//GetDatabaseLocation_REQ

//------------------------------------------------------------------------
ibp_ipropval__remote__wire_crypt
 IBP_OLEDB_Props2__Values__DATASOURCE::Get_Remote_WireCrypt()const
{
 const wchar_t* const c_bugcheck_src
  =L"IBP_OLEDB_Props2__Values__DATASOURCE::Get_Remote_WireCrypt";

 //-----------------------------------------
 ole_lib::TVariant varPropValue__WireCrypt;

 if(!this->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_CRYPT,nullptr,&varPropValue__WireCrypt))
  return ibp_ipropval__remote__wire_crypt::default_;

 assert(varPropValue__WireCrypt.vt==VT_BSTR);

 const auto strPropValue__WireCrypt
  =ole_lib::BStrToBox(varPropValue__WireCrypt.bstrVal);

 if(structure::equal_to_string(strPropValue__WireCrypt,ibprovider::ibp_propval__remote__wire_crypt__disabled))
  return ibp_ipropval__remote__wire_crypt::disabled;

 if(structure::equal_to_string(strPropValue__WireCrypt,ibprovider::ibp_propval__remote__wire_crypt__enabled))
  return ibp_ipropval__remote__wire_crypt::enabled;

 if(structure::equal_to_string(strPropValue__WireCrypt,ibprovider::ibp_propval__remote__wire_crypt__required))
  return ibp_ipropval__remote__wire_crypt::required;

 //ERROR: [BUG CHECK] неизвестное значение свойства инициализации

 IBP_ThrowBugCheck__UnexpectedPropValue
  (c_bugcheck_src,
   L"#001",
   IBP_DBPROP_NAME__INIT__REMOTE__WIRE_CRYPT,
   strPropValue__WireCrypt);
}//Get_Remote_WireCrypt

//------------------------------------------------------------------------
ibp_ipropval__remote__wire_compression
 IBP_OLEDB_Props2__Values__DATASOURCE::Get_Remote_WireCompression()const
{
 const wchar_t* const c_bugcheck_src
  =L"IBP_OLEDB_Props2__Values__DATASOURCE::Get_Remote_WireCompression";

 //-----------------------------------------
 ole_lib::TVariant varPropValue__WireCompression;

 if(!this->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION,nullptr,&varPropValue__WireCompression))
  return ibp_ipropval__remote__wire_compression::default_;

 assert(varPropValue__WireCompression.vt==VT_BSTR);

 const auto strPropValue__WireCompression
  =ole_lib::BStrToBox(varPropValue__WireCompression.bstrVal);

 if(structure::equal_to_string(strPropValue__WireCompression,ibprovider::ibp_propval__remote__wire_compression__disabled))
  return ibp_ipropval__remote__wire_compression::disabled;

 if(structure::equal_to_string(strPropValue__WireCompression,ibprovider::ibp_propval__remote__wire_compression__enabled))
  return ibp_ipropval__remote__wire_compression::enabled;

 if(structure::equal_to_string(strPropValue__WireCompression,ibprovider::ibp_propval__remote__wire_compression__required))
  return ibp_ipropval__remote__wire_compression::required;

 //ERROR: [BUG CHECK] неизвестное значение свойства инициализации

 IBP_ThrowBugCheck__UnexpectedPropValue
  (c_bugcheck_src,
   L"#001",
   IBP_DBPROP_NAME__INIT__REMOTE__WIRE_COMPRESSION,
   strPropValue__WireCompression);
}//Get_Remote_WireCompression

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values__DATASOURCE::TestValue__SchemaRestrictions
                                           (const ibprovider::IBP_CHAR* const pValue)const
{
 assert(pValue);

 return this->Helper__TestValue__normalized_str
         (ibprovider::IBP_DBPROPSET_INIT,
          ibprovider::IBP_DBPROP__INIT__SCHEMA_RESTRICTIONS,
          pValue);
}//TestValue__SchemaRestrictions

//IBP_OLEDB_Props2__Values interface -------------------------------------
const IBP_OLEDB_Props2__DescrData&
 IBP_OLEDB_Props2__Values__DATASOURCE::Internal__GetStaticPropData
                                           (REFGUID        propGuid,
                                            DBPROPID const propId)const
{
 const wchar_t* const c_bugcheck_src
  =L"IBP_OLEDB_Props2__Values__DATASOURCE::Internal__GetStaticPropData";

 //----------------------
 if(ole_lib::GuidEqual(propGuid,DBPROPSET_DBINIT))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__DBINIT_STD::Find(propId))
   return *x;
 }
 else
 if(ole_lib::GuidEqual(propGuid,ibprovider::IBP_DBPROPSET_INIT))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__DBINIT_EXT::Find(propId))
   return *x;
 }//if
 else
 if(ole_lib::GuidEqual(propGuid,DBPROPSET_DATASOURCEINFO))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD::Find(propId))
   return *x;
 }//if
 else
 if(ole_lib::GuidEqual(propGuid,ibprovider::IBP_DBPROPSET_DATASOURCEINFO))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_EXT::Find(propId))
   return *x;
 }//if
 else
 if(ole_lib::GuidEqual(propGuid,DBPROPSET_DATASOURCE))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__DATASOURCE_STD::Find(propId))
   return *x;
 }//if
 else
 if(ole_lib::GuidEqual(propGuid,ibprovider::IBP_DBPROPSET_DATASOURCECREATE))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__DATASOURCECREATE::Find(propId))
   return *x;
 }//if
 else
 if(ole_lib::GuidEqual(propGuid,IBP_DBPROPSET_SYS_DATASOURCEINFO))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_SYS::Find(propId))
   return *x;
 }//if
 else
 if(ole_lib::GuidEqual(propGuid,DBPROPSET_SESSION))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__SESSION_STD::Find(propId))
   return *x;
 }//if
 else
 if(ole_lib::GuidEqual(propGuid,ibprovider::IBP_DBPROPSET_SESSION))
 {
  if(auto* const x=data::IBP_OLEDB_Props2__Descrs__Data__SESSION_EXT::Find(propId))
   return *x;
 }//if

 //[2018-12-16] Unexpected situation
 IBP_BUG_CHECK__DEBUG
  (c_bugcheck_src,
   L"#001",
   L"unknown OLE DB property");

#if(COMP_BUILD_UNUSED_CODE!=0)
 assert_hint(false);
#endif
}//Internal__GetStaticPropData

//Helper methods ---------------------------------------------------------
IBP_OLEDB_Props2__Values__DATASOURCE::long_type_n IBP_OLEDB_Props2__Values__DATASOURCE::Helper__GetFirstDayNum()const
{
 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__FIRST_WEEK_DAY,&propOpt,&propValue))
  return long_type_n();

 return IBP_OLEDB_Props2__Handler__ExtractValue__Prop__first_week_day::GetFirstDayNum(propValue); //throw?
}//Helper__GetFirstDayNum

//------------------------------------------------------------------------
bool IBP_OLEDB_Props2__Values__DATASOURCE::Helper__TestValue__normalized_str
                                           (REFGUID                           propGuid,
                                            DBPROPID                    const propId,
                                            const ibprovider::IBP_CHAR* const pValue)const
{
 assert(pValue);

 ole_lib::TVariant propValue;
 DBPROPOPTIONS     propOpt=0;

 if(!this->Direct__GetValue(propGuid,propId,&propOpt,&propValue))
 {
  //[2019-01-07] очень странно
  assert(false);

  return false;
 }//if

 assert(propValue.vt!=VT_EMPTY);
 assert(propValue.vt==VT_BSTR);

 //[2019-01-07] propValue.bstrVal содержит непустую, нормализованную строку
 assert(propValue.bstrVal);

 const auto propValue_StrBox
  =ole_lib::BStrToBox(propValue.bstrVal);

 if(structure::equal_to_string(propValue_StrBox,pValue))
  return true;

 return false;
}//Helper__TestValue__normalized_str

////////////////////////////////////////////////////////////////////////////////
}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
