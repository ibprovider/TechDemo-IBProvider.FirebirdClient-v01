////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_oledb__props2
//! \file    ibp_oledb__props2__descrs__data__dbinit__all.cpp
//! \brief   Определение описаний всех свойств инициализации подключения
//! \author  Kovalenko Dmitry
//! \date    21.12.2018
#include <_pch_.h>
#pragma hdrstop

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit__all.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__simple_string.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__not_empty_string.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__non_negative_i4.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__neg1_zero_positive_i4.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__tr_iso_level.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__numeric_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__dll_lock_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__deferred_data_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__common__cset_name.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__integ_auth.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__prompt.h"

#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__named_param_prefix.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__named_param_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__first_week_day.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__array_rw_mode.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__rowset_file__sys_flags.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__array_type.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__reset_ds_tr_rule.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__reset_ds_session_sinks_rule.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__schema_cache.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__auto_commit_ddl.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__dbtime_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__dbtimestamp_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__dbdate_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__guid_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__asynch_fetch.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__wchars_in_utf8_symbol.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__provider_error_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__ignore_err_param.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__nested_trans_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__dbclient_type.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__support_square_delim_name.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__keywords_list.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__tr_abort_flags.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__multi_stmts_exec_rules.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__dialect.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__sql_cache__scope.h"

#include "source/oledb/props2/handlers/code/prepare_set_value/ibp_oledb__props2__handler__prepare_set_value__prop__ExtProps.h"

//------------------------------------------------------------------------
#include "source/oledb/props2/handlers/code/get_value/ibp_oledb__props2__handler__get_value__common__SecData.h"

//------------------------------------------------------------------------
#if(IBP_ENGINE_META_DATA_READER!=0)
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__schema_restrictions.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__schema_ldr_cfg__check_constraints.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__schema_ldr_cfg__descriptions.h"
#endif

//------------------------------------------------------------------------
#if(IBP_ENGINE_UPDATE_ROWSET!=0)
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__server_data_back_read.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__auto_insert_field_rule.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__auto_update_field_rule.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__modify_trans_type.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__refresh_trans_type.h"
#endif

//------------------------------------------------------------------------
#if(IBP_ENGINE_DIRECT_FB!=0)
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_protocol_type.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_protocol.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_wire_crypt.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_protocol_arch.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_wire_compression.h"
#include "source/oledb/props2/handlers/code/extract_value/ibp_oledb__props2__handler__extract_value__prop__remote_wire_compression_type.h"
#endif

//------------------------------------------------------------------------
#include "source/oledb/props2/descrs/ibp_oledb__props2__descr_data__index_by_name.h"

#include "source/oledb/props2/ibp_oledb__props2__utils.h"

#include "source/oledb/ibp_oledb__prop__value_var_types.h"
#include "source/oledb/ibp_oledb__prop__names.h"

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
 IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::STD::sm_DescrFor__##PropId  \
  =IBP_OLEDB_Props2__DescrData                                            \
    (InitTag,                                                             \
     PropId,                                                              \
     PropDescr,                                                           \
     PropFlags,                                                           \
     PropRules,                                                           \
     ListOfAdditionalParams) POST_INIT_CALLS;

////////////////////////////////////////////////////////////////////////////////

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_std.dat"

////////////////////////////////////////////////////////////////////////////////
#undef IBP_OLEDB_PROPS2__DESCR_DATA
////////////////////////////////////////////////////////////////////////////////

#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
const IBP_OLEDB_Props2__DescrData                                         \
 IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::EXT::sm_DescrFor__##PropId  \
  =IBP_OLEDB_Props2__DescrData                                            \
    (InitTag,                                                             \
     ibprovider::PropId,                                                  \
     PropDescr,                                                           \
     PropFlags,                                                           \
     PropRules,                                                           \
     ListOfAdditionalParams) POST_INIT_CALLS;

////////////////////////////////////////////////////////////////////////////////

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_ext.dat"

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
//class IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data

class IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data
{
 public:
  static const IBP_OLEDB_Props2__DescrData_IndexByName_Item sm_IndexByName__std[];
  static const IBP_OLEDB_Props2__DescrData_IndexByName_Item sm_IndexByName__ext[];
};//class IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__DescrData_IndexByName_Item
 IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data::sm_IndexByName__std[]=
{
 DEF_INDEX_ITEM(STD,DBPROP_INIT_DATASOURCE                                ,0,"Data Source")
 DEF_INDEX_ITEM(STD,DBPROP_INIT_PROVIDERSTRING                            ,0,"Extended Properties")
 DEF_INDEX_ITEM(STD,DBPROP_AUTH_INTEGRATED                                ,0,"Integrated Security")
 DEF_INDEX_ITEM(STD,DBPROP_INIT_LOCATION                                  ,0,"Location")
 DEF_INDEX_ITEM(STD,DBPROP_INIT_OLEDBSERVICES                             ,0,"OLE DB Services")
 DEF_INDEX_ITEM(STD,DBPROP_AUTH_PASSWORD                                  ,0,"Password")
 DEF_INDEX_ITEM(STD,DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO                ,0,"Persist Security Info")
 DEF_INDEX_ITEM(STD,DBPROP_INIT_PROMPT                                    ,0,"Prompt")
 DEF_INDEX_ITEM(STD,DBPROP_AUTH_PASSWORD                                  ,1,"PSWD")
 DEF_INDEX_ITEM(STD,DBPROP_AUTH_USERID                                    ,1,"User")
 DEF_INDEX_ITEM(STD,DBPROP_AUTH_USERID                                    ,0,"User ID")
 DEF_INDEX_ITEM(STD,DBPROP_INIT_HWND                                      ,0,"Window Handle")
};//sm_IndexByName__std

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL__tag_data__sm_IndexByName__std()
{
 IBP_OLEDB_Props2__DescrData_IndexByName_Item::DEBUG_Check_Range
  (IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data::sm_IndexByName__std,
   _END_(IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data::sm_IndexByName__std));
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL__tag_data__sm_IndexByName__std

STARTUP_CODE__DEBUG
 (DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL__tag_data__sm_IndexByName__std)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////

const IBP_OLEDB_Props2__DescrData_IndexByName_Item
 IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data::sm_IndexByName__ext[]=
{
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ARRAY_RW_MODE                       ,0,"array_rw_mode")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ARRAY_TYPE                          ,0,"array_type")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ASYNCH_FETCH                        ,0,"asynch_fetch")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__AUTOCOMMIT                          ,0,"auto_commit")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__AUTO_COMMIT_DDL                     ,0,"auto_commit_ddl")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__AUTO_COMMIT_DDL_LEVEL               ,0,"auto_commit_ddl_level")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__AUTOCOMMITLEVEL                     ,0,"auto_commit_level")

#if(IBP_ENGINE_UPDATE_ROWSET!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__AUTO_INSERT_FIELD_RULE              ,0,"auto_insert_field_rule")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__AUTO_PARAM_DESCRIBE                 ,0,"auto_param_describe")

#if(IBP_ENGINE_UPDATE_ROWSET!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__AUTO_UPDATE_FIELD_RULE              ,0,"auto_update_field_rule")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__BICURSOR                            ,0,"bicursor")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__CTYPE                               ,1,"charset")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__CLEAR_PARAM_INFO                    ,0,"clear_param_info")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__CTYPE                               ,0,"ctype")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__CTYPE_NONE                          ,0,"ctype_none")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__CTYPE_USER                          ,0,"ctype_user")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DBCLIENT_LIBRARY                    ,0,"dbclient_library")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DBCLIENT_LIBRARY_64                 ,0,"dbclient_library_64")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DBCLIENT_LOCK_RULES                 ,0,"dbclient_lock_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DBCLIENT_TYPE                       ,0,"dbclient_type")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DBDATE_RULES                        ,0,"dbdate_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DBTIME_RULES                        ,0,"dbtime_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DBTIMESTAMP_RULES                   ,0,"dbtimestamp_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DEFERRED_DATA                       ,0,"deferred_data")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__DEFERRED_OUT_PARAM                  ,0,"deferred_out_param")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SQL_DIALECT                         ,0,"dialect")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ENABLE_DB_TRIGGERS                  ,0,"enable_db_triggers")

#if(IBP_ENGINE_UPDATE_ROWSET!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ENABLE_UPDATABLE_ROWSET             ,0,"enable_updatable_rowset")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__EXEC_SP_NAMED_PARAM                 ,0,"exec_sp_named_param")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__FIRST_WEEK_DAY                      ,0,"first_week_day")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__FORCE_NULLS                         ,0,"force_nulls")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__FORCE_PREPARE_STMT                  ,0,"force_prepare_stmt")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__GARBAGE_COLLECT                     ,0,"garbage_collect")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__GUID_RULES                          ,0,"guid_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__IB_TR_PARAMS__READ_COMMITTED        ,0,"ib_tr_params__read_committed")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__IB_TR_PARAMS__REPEATABLE_READ       ,0,"ib_tr_params__repeatable_read")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__IB_TR_PARAMS__SERIALIZABLE          ,0,"ib_tr_params__serializable")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ICU_LIBRARY                         ,0,"icu_library")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ICU_LIBRARY_64                      ,0,"icu_library_64")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__IGNORE_ERR_PARAM                    ,0,"ignore_err_param")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__IGNORE_UNPREPARE                    ,0,"ignore_unprepare")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__INNER_TRANS                         ,0,"inner_trans")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__KEYWORDS_LIST                       ,0,"keywords_list")

#if(IBP_ENGINE_UPDATE_ROWSET!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__MODIFY_TRANS_LEVEL                  ,0,"modify_trans_level")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__MODIFY_TRANS_TYPE                   ,0,"modify_trans_type")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__MULTI_STMTS_EXEC_RULES              ,0,"multi_stmts_exec_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NAMED_PARAM_PREFIX                  ,0,"named_param_prefix")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NAMED_PARAM_RULES                   ,0,"named_param_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NESTED_TRANS                        ,0,"nested_trans")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NESTED_TRANS_RULES                  ,0,"nested_trans_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NUM_BUFFERS                         ,0,"num_buffers")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NUMERIC_I2_RULES                    ,0,"numeric_i2_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NUMERIC_I4_RULES                    ,0,"numeric_i4_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__NUMERIC_I8_RULES                    ,0,"numeric_i8_rules")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__OPEN_ROWSET__SQL                    ,0,"open_rowset__sql")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__PROVIDER_ERROR_RULES                ,0,"provider_error_rules")

#if(IBP_ENGINE_UPDATE_ROWSET!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REFRESH_TRANS_LEVEL                 ,0,"refresh_trans_level")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REFRESH_TRANS_TYPE                  ,0,"refresh_trans_type")
#endif

#if(IBP_ENGINE_DIRECT_FB!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__AUTH                        ,0,"remote:auth")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__PROTOCOL                    ,0,"remote:protocol")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__PROTOCOL_ARCHITECTURE       ,0,"remote:protocol_arch")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__PROTOCOL_TYPE               ,0,"remote:protocol_type")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION            ,0,"remote:wire_compression")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY    ,0,"remote:wire_compression_library")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_LIBRARY_64 ,0,"remote:wire_compression_library_64")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__WIRE_COMPRESSION_TYPE       ,0,"remote:wire_compression_type")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__REMOTE__WIRE_CRYPT                  ,0,"remote:wire_crypt")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__RESET_DS_SESSION_SINKS_RULE         ,0,"reset_ds_session_sinks_rule")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__RESET_DS_TR_RULE                    ,0,"reset_ds_tr_rule")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ROLENAME                            ,0,"role")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ROWSET__MEMORY_USAGE                ,0,"rowset__memory_usage")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ROWSET_FILE__SYS_FLAGS              ,0,"rowset_file__sys_flags")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ROWSET_FILE__WRITE_BLOCK_SIZE       ,0,"rowset_file__write_block_size")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__ROWSET_VM_USING                     ,0,"rowset_vm_using")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SCHEMA_CACHE                        ,0,"schema_cache")

#if(IBP_ENGINE_META_DATA_READER!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SCHEMA_LDR_CFG__CHECK_CONSTRAINTS   ,0,"schema_ldr_cfg__check_constraints")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SCHEMA_LDR_CFG__DESCRIPTIONS        ,0,"schema_ldr_cfg__descriptions")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SCHEMA_RESTRICTIONS                 ,0,"schema_restrictions")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SYS_ENCRYPT_PASSWORD                ,1,"sep")

#if(IBP_ENGINE_UPDATE_ROWSET!=0)
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SERVER_DATA_BACK_READ               ,0,"server_data_back_read")
#endif

 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SQL_CACHE__INSTANCE_ID              ,0,"sql_cache__instance_id")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SQL_CACHE__MAX_LEN                  ,0,"sql_cache__max_len")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SQL_CACHE__SCOPE                    ,0,"sql_cache__scope")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SQL_CACHE__SIZE                     ,0,"sql_cache__size")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SQL_CACHE__TIME                     ,0,"sql_cache__time")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__STMT_CACHE__REQ_LIFE_TIME           ,0,"stmt_cache__req_life_time")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__STMT_CACHE__SIZE                    ,0,"stmt_cache__size")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__STMT_CACHE__TIME                    ,0,"stmt_cache__time")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SUPPORT_ODBC_QUERY                  ,0,"support_odbc_query")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SUPPORT_SQUARE_DELIM_NAME           ,0,"support_square_delim_name")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__SYS_ENCRYPT_PASSWORD                ,0,"sys_encrypt_password")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__TEMP_FILE_DIR                       ,0,"temp_file_dir")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__TEMP_STG__MEMORY_USAGE              ,0,"temp_stg__memory_usage")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__TR_ABORT_FLAGS                      ,0,"tr_abort_flags")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__TRUNCATE_CHAR                       ,0,"truncate_char")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__UNICODE_MODE                        ,0,"unicode_mode")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__USER_TYPE_BOOLEAN                   ,0,"user_type_boolean")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__USER_TYPE_GUID                      ,0,"user_type_guid")
 DEF_INDEX_ITEM(EXT,IBP_DBPROP__INIT__WCHARS_IN_UTF8_SYMBOL               ,0,"wchars_in_utf8_symbol")
};//sm_IndexByName__ext

////////////////////////////////////////////////////////////////////////////////

#ifndef NDEBUG

static void DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL__tag_data__sm_IndexByName__ext()
{
 IBP_OLEDB_Props2__DescrData_IndexByName_Item::DEBUG_Check_Range
  (IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data::sm_IndexByName__ext,
   _END_(IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::tag_data::sm_IndexByName__ext));
}//DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL__tag_data__sm_IndexByName__ext

STARTUP_CODE__DEBUG
 (DEBUG__check_IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL__tag_data__sm_IndexByName__ext)

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
#undef DEF_INDEX_ITEM
////////////////////////////////////////////////////////////////////////////////
//class IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL

IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::find_result_type
 IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::Find(const wstr_box_type& Name)
{
 CHECK_READ_TYPED_PTR(Name.ptr,Name.len);

 if(auto const r=structure::lower_search(std::begin(tag_data::sm_IndexByName__std),
                                         std::end(tag_data::sm_IndexByName__std),
                                         Name,
                                         IBP_OLEDB_Props2__DescrData_IndexByName_Less()))
 {
  assert((*r.position).pDescr);

  return find_result_type(&DBPROPSET_DBINIT,(*r.position).pDescr);
 }//if

 if(auto const r=structure::lower_search(std::begin(tag_data::sm_IndexByName__ext),
                                         std::end(tag_data::sm_IndexByName__ext),
                                         Name,
                                         IBP_OLEDB_Props2__DescrData_IndexByName_Less()))
 {
  assert((*r.position).pDescr);

  return find_result_type(&ibprovider::IBP_DBPROPSET_INIT,(*r.position).pDescr);
 }//if

 return find_result_type(nullptr,nullptr);
}//Find - wstr_box

//------------------------------------------------------------------------
#ifndef NDEBUG

void IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::DEBUG__Check_sm_IndexByName()
{
 //----------------------------------------- check index for all descrs
#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
 for(const wchar_t* p=PropDescr.ptr();*p;p+=wcslen(p)+1)                  \
 {                                                                        \
  auto const x=self_type::Find(p);                                        \
                                                                          \
  assert(x.first);                                                        \
  assert(ole_lib::GuidEqual(*x.first,DBPROPSET_DBINIT));                  \
  assert(x.second);                                                       \
  assert(x.second->m_PropId==PropId);                                     \
 }

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_std.dat"

#undef IBP_OLEDB_PROPS2__DESCR_DATA

 //-----------------------------------------
#define IBP_OLEDB_PROPS2__DESCR_DATA(InitTag,                             \
                                     PropId,                              \
                                     PropDescr,                           \
                                     PropFlags,                           \
                                     PropRules,                           \
                                     ListOfAdditionalParams,              \
                                     POST_INIT_CALLS)                     \
 for(const wchar_t* p=PropDescr.ptr();*p;p+=wcslen(p)+1)                  \
 {                                                                        \
  auto const x=self_type::Find(p);                                        \
                                                                          \
  assert(x.first);                                                        \
  assert(ole_lib::GuidEqual(*x.first,ibprovider::IBP_DBPROPSET_INIT));    \
  assert(x.second);                                                       \
  assert(x.second->m_PropId==ibprovider::PropId);                         \
 }

#include "source/oledb/props2/descrs/data/ibp_oledb__props2__descrs__data__dbinit_ext.dat"

#undef IBP_OLEDB_PROPS2__DESCR_DATA

 //-----------------------------------------
 for(auto x=std::begin(tag_data::sm_IndexByName__std);x!=std::end(tag_data::sm_IndexByName__std);++x)
 {
  auto const r=self_type::Find((*x).pName);

  assert(r.second==(*x).pDescr);
 }//for x

 //-----------------------------------------
 for(auto x=std::begin(tag_data::sm_IndexByName__ext);x!=std::end(tag_data::sm_IndexByName__ext);++x)
 {
  auto const r=self_type::Find((*x).pName);

  assert(r.second==(*x).pDescr);
 }//for x
}//DEBUG__Check_sm_IndexByName

#endif // NDEBUG

//------------------------------------------------------------------------
#ifndef NDEBUG

IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::DEBUG__items_range_type
 IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::DEBUG__GetRange_STD()
{
 return DEBUG__items_range_type(tag_data::sm_IndexByName__std,_END_(tag_data::sm_IndexByName__std));
}//DEBUG__GetRange_STD

//------------------------------------------------------------------------
IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::DEBUG__items_range_type
 IBP_OLEDB_Props2__Descrs__Data__DBINIT__ALL::DEBUG__GetRange_EXT()
{
 return DEBUG__items_range_type(tag_data::sm_IndexByName__ext,_END_(tag_data::sm_IndexByName__ext));
}//DEBUG__GetRange_EXT

#endif //NDEBUG

////////////////////////////////////////////////////////////////////////////////
}/*nms data*/}/*nms props2*/}/*nms oledb*/}/*nms ibp*/}/*nms lcpi*/
