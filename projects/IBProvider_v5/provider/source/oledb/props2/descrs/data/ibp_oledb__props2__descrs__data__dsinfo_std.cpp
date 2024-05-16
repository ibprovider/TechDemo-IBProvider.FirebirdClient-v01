////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dsinfo_std.cpp
//! \brief   Описание стандартных информационных свойств источника данных
//! \author  Kovalenko Dmitry
//! \date    28.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dsinfo_std.h"
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__helpers.h"
#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include "source/oledb/props2/handlers/code/prepare_get_value/ibp_oledb__props2__handler__prepare_get_value__prop__CnStatus.h"

#include "source/oledb/props2/handlers/code/get_value/ibp_oledb__props2__handler__get_value__prop__CnStatus.h"

#include "source/oledb/props2/handlers/code/get_default_value/ibp_oledb__props2__handler__get_default_value__prop__ProviderName.h"

#include "source/ibp_char.h"

#include "source/Version/ibp_v05_info_data.h"

namespace lcpi{namespace ibp{namespace oledb{namespace props2{namespace data{
////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
IBP_OLEDB_Props2__DescrData                                               \
 (InitTag,                                                                \
  PropId,                                                                 \
  PropDescr,                                                              \
  PropFlags,                                                              \
  PropRules,                                                              \
  ListOfAdditionalParams) POST_INIT_CALLS,

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD

const IBP_OLEDB_Props2__DescrData
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD::sm_descrs[]=
{
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_ACTIVESESSIONS,                   //3
   OLEDB_PDESCR2(L"Active Sessions"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   0L,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_ASYNCTXNCOMMIT,                   //4
   OLEDB_PDESCR2(L"Asynchable Commit"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_CATALOGLOCATION,                  //22
   OLEDB_PDESCR2(L"Catalog Location"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   0L,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR
  (DBPROP_CATALOGTERM,                      //23
   OLEDB_PDESCR2(L"Catalog Term"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   L"database",
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_CATALOGUSAGE,                     //24
   OLEDB_PDESCR2(L"Catalog Usage"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   0L,
   /*post init calls*/)

 //свойства с фиксированным значением
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_COLUMNDEFINITION,                 //32
   OLEDB_PDESCR2(L"Column Definition"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_CD_NOTNULL,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_CONCATNULLBEHAVIOR,               //36
   OLEDB_PDESCR2(L"NULL Concatenation Behavior"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_CB_NULL,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (DBPROP_DATASOURCENAME,                   //38
   OLEDB_PDESCR2(L"Data Source Name"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 //! \todo
 //!  RUNTIME VALUE!
 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL__EMPTY
  (DBPROP_DATASOURCEREADONLY,               //39
   OLEDB_PDESCR2(L"Read-Only Data Source"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 //! \todo
 //!  RUNTIME VALUE!
 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (DBPROP_DBMSNAME,                         //40
   OLEDB_PDESCR2(L"DBMS Name"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 //! \todo
 //!  RUNTIME VALUE!
 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (DBPROP_DBMSVER,                          //41
   OLEDB_PDESCR2(L"DBMS Version"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_GROUPBY,                          //44
   OLEDB_PDESCR2(L"GROUP BY Support"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_GB_CONTAINS_SELECT,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_HETEROGENEOUSTABLES,              //45
   OLEDB_PDESCR2(L"Heterogeneous Table Support"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   0L,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_IDENTIFIERCASE,                   //46
   OLEDB_PDESCR2(L"Identifier Case Sensitivity"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_IC_UPPER,
   /*post init calls*/)

 //! \todo Значение свойства "Maximum Index Size" зависит от
 //!  - версии сервера
 //!  - ODS базы данных
 //!  - размера страницы
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_MAXINDEXSIZE,                     //70
   OLEDB_PDESCR2(L"Maximum Index Size"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   252L,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_MAXROWSIZE,                       //74
   OLEDB_PDESCR2(L"Maximum Row Size"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   64*1024L,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_MAXROWSIZEINCLUDESBLOB,           //75
   OLEDB_PDESCR2(L"Maximum Row Size Includes BLOB"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_MAXTABLESINSELECT,                //76
   OLEDB_PDESCR2(L"Maximum Tables in SELECT"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   0L,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_MULTIPLESTORAGEOBJECTS,           //80
   OLEDB_PDESCR2(L"Multiple Storage Objects"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   true,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_MULTITABLEUPDATE,                 //81
   OLEDB_PDESCR2(L"Multi-Table Update"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_NULLCOLLATION,                    //83
   OLEDB_PDESCR2(L"NULL Collation Order"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_NC_LOW,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_OLEOBJECTS,                       //84
   OLEDB_PDESCR2(L"OLE Object Support"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_OO_BLOB,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_ORDERBYCOLUMNSINSELECT,           //85
   OLEDB_PDESCR2(L"ORDER BY Columns in Select List"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 //InterBase умеет работать с командами без переподготовки в новой транзакции
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_PREPAREABORTBEHAVIOR,             //91
   OLEDB_PDESCR2(L"Prepare Abort Behavior"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_CB_PRESERVE,
   /*post init calls*/)

 //InterBase умеет работать с командами без переподготовки в новой транзакции
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_PREPARECOMMITBEHAVIOR,            //92
   OLEDB_PDESCR2(L"Prepare Commit Behavior"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_CB_PRESERVE,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR
  (DBPROP_PROCEDURETERM,                    //93
   OLEDB_PDESCR2(L"Procedure Term"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   L"stored procedure",
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_DATA
  (IBP_OLEDB_Props2__DescrData::tag_init__empty(),
   DBPROP_PROVIDERNAME,                     //96
   OLEDB_PDESCR2(L"Provider Name"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   IBP_OLEDB_Props2__DescrData::rule_flag__ibp_runtime_default,
   VT_BSTR _LITER_COMMA_
   DBPROPOPTIONS_REQUIRED,
   .PostInit_SetHandler_GetDefaultValue(IBP_OLEDB_Props2__Handler__GetDefaultValue__Prop__ProviderName::GetInstancePtr()))

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR
  (DBPROP_PROVIDEROLEDBVER,                 //97
   OLEDB_PDESCR2(L"OLE DB Version"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   L"02.60",
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR
  (DBPROP_PROVIDERVER,                      //98
   OLEDB_PDESCR2(L"Provider Version"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   IBP_UCS2(IBP_VI_PRODUCT_VER_STRING1),
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_QUOTEDIDENTIFIERCASE,             //100
   OLEDB_PDESCR2(L"Quoted Identifier Sensitivity"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_IC_SENSITIVE,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR
  (DBPROP_SCHEMATERM,                       //106
   OLEDB_PDESCR2(L"Schema Term"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   L"owner",
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_SCHEMAUSAGE,                      //107
   OLEDB_PDESCR2(L"Schema Usage"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   0L,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (DBPROP_SQLSUPPORT,                       //109
   OLEDB_PDESCR2(L"SQL Support"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_STRUCTUREDSTORAGE,                //111
   OLEDB_PDESCR2(L"Structured Storage"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_SS_ISEQUENTIALSTREAM,
   /*post init calls*/)

 //! Commnon flags: DBPROPVAL_SQ_CORRELATEDSUBQUERIES|DBPROPVAL_SQ_IN|DBPROPVAL_SQ_EXISTS|DBPROPVAL_SQ_COMPARISON
 //! \todo
 //!  DBPROPVAL_SQ_TABLE for FB2.1+ and IB13
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (DBPROP_SUBQUERIES,                       //112
   OLEDB_PDESCR2(L"Subquery Support"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (DBPROP_SUPPORTEDTXNISOLEVELS,            //113
   OLEDB_PDESCR2(L"Isolation Levels"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4__EMPTY
  (DBPROP_SUPPORTEDTXNISORETAIN,            //114
   OLEDB_PDESCR2(L"Isolation Retention"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR
  (DBPROP_TABLETERM,                        //115
   OLEDB_PDESCR2(L"Table Term"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   L"table",
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (DBPROP_USERNAME,                         //118
   OLEDB_PDESCR2(L"User Name"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_BYREFACCESSORS,                   //120
   OLEDB_PDESCR2(L"Pass By Ref Accessors"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_SUPPORTEDTXNDDL,                  //161
   OLEDB_PDESCR2(L"Transaction DDL"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_TC_ALL,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_ASYNCTXNABORT,                    //168
   OLEDB_PDESCR2(L"Asynchable Abort"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_DSOTHREADMODEL,                   //169
   OLEDB_PDESCR2(L"Data Source Object Threading"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_RT_FREETHREAD|DBPROPVAL_RT_APTMTTHREAD,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_OUTPUTPARAMETERAVAILABILITY,      //184
   OLEDB_PDESCR2(L"Output Parameter Availability"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_OA_ATEXECUTE,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_PERSISTENTIDTYPE,                 //185
   OLEDB_PDESCR2(L"Persistent ID Type"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_PT_NAME,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_MULTIPLEPARAMSETS,                //191
   OLEDB_PDESCR2(L"Multiple Parameter Sets"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   true,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_ROWSETCONVERSIONSONCOMMAND,       //192
   OLEDB_PDESCR2(L"Rowset Conversions on Command"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   true,
   /*post init calls*/)

 //Провайдер поддерживаем объект TMultipleResults
 // - InterBase разрешает конкурентную выборку данных из разных курсоров
 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_MULTIPLERESULTS,                  //196
   OLEDB_PDESCR2(L"Multiple Results"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_MR_SUPPORTED|DBPROPVAL_MR_CONCURRENT,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__STR
  (DBPROP_PROVIDERFRIENDLYNAME,             //235
   OLEDB_PDESCR2(L"Provider Friendly Name"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   IBP_PROVIDER_DESCRIPTION_STRING,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_DATA
  (IBP_OLEDB_Props2__DescrData::tag_init__empty(),
   DBPROP_CONNECTIONSTATUS,                 //244
   OLEDB_PDESCR2(L"Connection Status"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   oledb_lib::OLEDB_Props2__Data__Descr::rule_flag__has_dynamic_value,
   VT_I4 _LITER_COMMA_
   DBPROPOPTIONS_REQUIRED,
   .PostInit_SetHandler_PrepareGetValue(IBP_OLEDB_Props2__Handler__PrepareGetValue__Prop__CnStatus::GetInstancePtr())
   .PostInit_SetHandler_GetValue(IBP_OLEDB_Props2__Handler__GetValue__Prop__CnStatus::GetInstancePtr()))

 IBP_OLEDB_PROPS2__DESCR_PARAM__WSTR__EMPTY
  (DBPROP_SERVERNAME,                       //250
   OLEDB_PDESCR2(L"Server Name"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_DATASOURCE_TYPE,                  //251
   OLEDB_PDESCR2(L"Data Source Type"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_DST_TDP,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__BOOL
  (DBPROP_PROVIDERMEMORY,                   //259
   OLEDB_PDESCR2(L"Provider Owned Memory"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   false,
   /*post init calls*/)

 IBP_OLEDB_PROPS2__DESCR_PARAM__I4
  (DBPROP_OPENROWSETSUPPORT,                //280
   OLEDB_PDESCR2(L"Open Rowset Support"),
   OLEDB_PROPFLAGS_DATASOURCEINFOR,
   DBPROPOPTIONS_REQUIRED,
   DBPROPVAL_ORS_TABLE|DBPROPVAL_ORS_STOREDPROC,
   /*post init calls*/)
};//IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD::sm_descrs

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD__sm_descrs()
{
 const auto r=IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD::GetDataRange();

 IBP_OLEDB_Props2__Utils::DEBUG__CheckOrder(r);

 for(auto x=r.first;x!=r.last;++x)
 {
  assert((*x).m_PropFlags==OLEDB_PROPFLAGS_DATASOURCEINFOR);
 }//for
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD__sm_descrs

STARTUP_CODE__DEBUG(DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD__sm_descrs)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD

IBP_OLEDB_Props2__DescrDataRange
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD::GetDataRange()
{
 return IBP_OLEDB_Props2__DescrDataRange(_BEG_END_(sm_descrs));
}//GetDataRange

//------------------------------------------------------------------------
const IBP_OLEDB_Props2__DescrData*
 IBP_OLEDB_Props2__Descrs__Data__DATASOURCEINFO_STD::Find(DBPROPID const propId)
{
 if(auto const x=IBP_OLEDB_Props2__Utils::Find(self_type::GetDataRange(),propId))
  return x;

 return nullptr;
}//Find

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
