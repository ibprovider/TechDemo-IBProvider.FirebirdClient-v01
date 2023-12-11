////////////////////////////////////////////////////////////////////////////////
//LCPI OLEDB Provider for InterBase/Firebird SDK.
//                                                 Kovalenko Dmitry. 25.01.2019
#include <_pch_.h>
#pragma hdrstop

#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05__props_values.h>

namespace lcpi{namespace sdk{namespace ibprovider{namespace v05{
////////////////////////////////////////////////////////////////////////////////

#define IBP_T(x) L##x

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR g_IBP_IntegratedAuth__NONE[] = IBP_T("NONE");

extern const IBP_CHAR g_IBP_IntegratedAuth__SSPI[] = IBP_T("SSPI");

////////////////////////////////////////////////////////////////////////////////

extern const IBP_SHORT g_IBP_PropValuesFor__Prompt[4]=
{
 DBPROMPT_PROMPT,
 DBPROMPT_COMPLETE,
 DBPROMPT_COMPLETEREQUIRED,
 DBPROMPT_NOPROMPT,
};//g_IBP_PropValuesFor__Prompt

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__schema_cache[3]=
{
 ibp_propval_schema_cache_disable,
 ibp_propval_schema_cache_data_source,
 ibp_propval_schema_cache_session,
};//g_IBP_PropValuesFor__schema_cache

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__auto_commit_ddl[3]=
{
 ibp_propval_auto_commit_ddl_none,
 ibp_propval_auto_commit_ddl_separate_tr,
 ibp_propval_auto_commit_ddl_commit_ret,
};//g_IBP_PropValuesFor__auto_commit_ddl

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__ignore_err_param[3]=
{
 ibp_propval_ignore_err_param__IN_param_with_unk_name,
 ibp_propval_ignore_err_param__IN_param_with_bad_pos,
 ibp_propval_ignore_err_param__IN_value_for_OUT_param,
};//g_IBP_PropFlagsFor__ignore_err_param

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__support_square_delim_name[3]=
{
 ibp_propval_support_square_delim_name___none,
 ibp_propval_support_square_delim_name___simple,
 ibp_propval_support_square_delim_name___adv,
};//g_IBP_PropValuesFor__support_square_delim_name

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__keywords_list[1]=
{
 ibp_propval_keywords_list__include_std,
};//g_IBP_PropFlagsFor__keywords_list

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__tr_abort_flags[1]=
{
 ibp_propval_tr_abort_flags__ignore_for_inactive,
};//g_IBP_PropFlagsFor__tr_abort_flags

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Перечисление допустимых значений свойства "reset_ds_tr_rule"
/// </summary>
extern const IBP_LONG g_IBP_PropValuesFor__reset_ds_tr_rule[3]=
{
 ibp_propval_reset_ds_tr_rule__ignore,
 ibp_propval_reset_ds_tr_rule__not_set,
 ibp_propval_reset_ds_tr_rule__detach,
};//g_IBP_PropValuesFor__reset_ds_tr_rule

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Перечисление допустимых значений свойства "reset_ds_session_sinks_rule"
/// </summary>
extern const IBP_LONG g_IBP_PropValuesFor__reset_ds_session_sinks_rule[3]=
{
 ibp_propval_reset_ds_session_sinks_rule__ignore,
 ibp_propval_reset_ds_session_sinks_rule__not_set,
 ibp_propval_reset_ds_session_sinks_rule__detach,
};//g_IBP_PropValuesFor__reset_ds_session_sinks_rule

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__array_type[5]=
{
 /*0*/
 ibp_propval_column_type_rules__native,

 /*1*/
 ibp_propval_column_type_rules__vt_compatible,

 /*2*/
 ibp_propval_column_type_rules__variant,

 /*17*/
 ibp_propval_column_type_rules__array_as_variant|
 ibp_propval_column_type_rules__vt_compatible,

 /*18*/
 ibp_propval_column_type_rules__array_as_variant|
 ibp_propval_column_type_rules__variant
};//g_IBP_PropValuesFor__array_type

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__rowset_file_sys_flags[2]=
{
 ibp_propval_rowset_file_sys_flag__no_buffering,
 ibp_propval_rowset_file_sys_flag__write_through,
};//g_IBP_PropFlagsFor__rowset_file_sys_flags

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__dbtime_rules[3]=
{
 ibp_propval_dbtime_rules__as_dbtime,
 ibp_propval_dbtime_rules__as_dbtime2,
 ibp_propval_dbtime_rules__as_wstr,
};//g_IBP_PropValuesFor__dbtime_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__dbtimestamp_rules[2]=
{
 ibp_propval_dbtimestamp_rules__as_dbtimestamp,
 ibp_propval_dbtimestamp_rules__as_wstr
};//g_IBP_PropValuesFor__dbtimestamp_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__dbdate_rules[2]=
{
 ibp_propval_dbdate_rules__as_dbdate,
 ibp_propval_dbdate_rules__as_wstr
};//g_IBP_PropValuesFor__dbdate_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__guid_rules[2]=
{
 ibp_propval__guid_rules__txt_with_lower_case,
 ibp_propval__guid_rules__txt_with_fbracket,
};//g_IBP_PropFlagsFor__guid_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__dbtimestamp_with_tz_rules[2]=
{
 ibp_propval_dbtimestamp_with_tz_rules__as_dbtimestampoffset,
 ibp_propval_dbtimestamp_with_tz_rules__as_wstr
};//g_IBP_PropValuesFor__dbtimestamp_with_tz_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__dbtime_with_tz_rules[1]=
{
 ibp_propval_dbtime_with_tz_rules__as_wstr
};//g_IBP_PropValuesFor__dbtime_with_tz_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__int128_rules[2]=
{
 ibp_propval_int128_rules__as_numeric,
 ibp_propval_int128_rules__as_wstr,
};//g_IBP_PropValuesFor__int128_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__decfloat_rules[1]=
{
 ibp_propval_decfloat_rules__as_wstr
};//g_IBP_PropValuesFor__decfloat_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__dll_lock_rules[3]=
{
 ibp_propval_dll_lock_rule__force_unload,
 ibp_propval_dll_lock_rule__unload,
 ibp_propval_dll_lock_rule__no_unload,
};//g_IBP_PropValuesFor__dll_lock_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__deferred_data_rules[2]=
{
 ibp_propval__deferred_data_rule__enabled_for_user_tr,
 ibp_propval__deferred_data_rule__enabled_for_auto_tr,
};//g_IBP_PropFlagsFor__deferred_data_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__newdb__type_of_db_users[2]=
{
 ibp_propval__newdb__type_of_db_users__server,
 ibp_propval__newdb__type_of_db_users__embedded,
};//g_IBP_PropValuesFor__newdb__type_of_db_users

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR ibp_propval__sql_cache__scope__empty[]
 =IBP_T("empty");

extern const IBP_CHAR ibp_propval__sql_cache__scope__cn[]
 =IBP_T("cn");

extern const IBP_CHAR ibp_propval__sql_cache__scope__db[]
 =IBP_T("db");

extern const IBP_CHAR* const g_IBP_PropValuesFor__sql_cache__scope[3]=
{
 ibp_propval__sql_cache__scope__empty,
 ibp_propval__sql_cache__scope__cn,
 ibp_propval__sql_cache__scope__db,
};//g_IBP_PropValuesFor__sql_cache__scope

extern const IBP_CHAR* const ibp_propval__sql_cache__scope__default
 =ibp_propval__sql_cache__scope__cn;

////////////////////////////////////////////////////////////////////////////////

#if !defined(IBP_ENGINE_UPDATE_ROWSET) || (IBP_ENGINE_UPDATE_ROWSET!=0)

extern const IBP_SHORT g_IBP_PropValuesFor__modify_trans_type[3]=
{
 ibp_modify_trans_mutable,
 ibp_modify_trans_main,
 ibp_modify_trans_separate,
};//g_IBP_PropValuesFor__modify_trans_type

////////////////////////////////////////////////////////////////////////////////

extern const IBP_SHORT g_IBP_PropValuesFor__refresh_trans_type[3]=
{
 ibp_refresh_trans_mutable,
 ibp_refresh_trans_main,
 ibp_refresh_trans_separate,
};//g_IBP_PropValuesFor__refresh_trans_type

////////////////////////////////////////////////////////////////////////////////

extern const IBP_PROP__AUTO_INSERT_FIELD_RULE g_IBP_PropValuesFor__auto_insert_field_rule[3]=
{
 ibp_auto_insert_field_rule__all,
 ibp_auto_insert_field_rule__installed,
 ibp_auto_insert_field_rule__ok,
};//g_IBP_PropValuesFor__auto_insert_field_rule

////////////////////////////////////////////////////////////////////////////////

extern const IBP_PROP__AUTO_UPDATE_FIELD_RULE g_IBP_PropValuesFor__auto_update_field_rule[4]=
{
 ibp_auto_update_field_rule__all,
 ibp_auto_update_field_rule__modified,
 ibp_auto_update_field_rule__all2,
 ibp_auto_update_field_rule__modified2,
};//g_IBP_PropValuesFor__auto_update_field_rule

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__server_data_back_read[2]=
{
 ibp_propval__server_data_back_read__insert,
 ibp_propval__server_data_back_read__update,
};//g_IBP_PropFlagsFor__server_data_back_read

#endif // !defined(IBP_ENGINE_UPDATE_ROWSET) || (IBP_ENGINE_UPDATE_ROWSET!=0)

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__multi_stmts_exec_rules[1]=
{
 ibp_propval__multi_stmts_exec_rules__continue_after_error,
};//g_IBP_PropFlagsFor__multi_stmts_exec_rules

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Настройки уровня изоляции InterBase "read committed"
/// </summary>
extern const wchar_t ibp_propval__ib_tr_params__read_committed__default[]
 =L"write read_committed rec_version nowait";

/// <summary>
///  Настройки уровня изоляции InterBase "repeatable read"
/// </summary>
extern const wchar_t ibp_propval__ib_tr_params__repeatable_read__default[]
 =L"write concurrency nowait";

/// <summary>
///  Настройки уровня изоляции InterBase "serializable"
/// </summary>
extern const wchar_t ibp_propval__ib_tr_params__serializable__default[]
 =L"write consistency nowait";

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__named_param_rules[1]=
{
 ibp_propval__named_param_rules__save_prefix,
};//g_IBP_PropFlagsFor__named_param_rules

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Массив режимов неявной асинхронной загрузки
/// <summary>
extern const IBP_LONG g_IBP_PropValuesFor__asynch_fetch[3]=
{
 ibp_propval__asynch_fetch__disabled,
 ibp_propval__asynch_fetch__enabled,
 ibp_propval__asynch_fetch__turn_on_when_asynch_init,
};//g_IBP_PropValuesFor__asynch_fetch

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropFlagsFor__nested_trans_rules[2]=
{
 ibp_propval__nested_trans_rules__implicit_commit_by_tr,
 ibp_propval__nested_trans_rules__implicit_commit_by_svp,
};//g_IBP_PropFlagsFor__nested_trans_rules

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__schema_ldr_cfg__check_constraints[2]=
{
 ibp_propval__schema_ldr_cfg__check_constraints__no,
 ibp_propval__schema_ldr_cfg__check_constraints__yes,
};//g_IBP_PropValuesFor__schema_ldr_cfg__check_constraints

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__schema_ldr_cfg__descriptions[2]=
{
 ibp_propval__schema_ldr_cfg__descriptions__no,
 ibp_propval__schema_ldr_cfg__descriptions__yes,
};//g_IBP_PropValuesFor__schema_ldr_cfg__descriptions

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR ibp_propval__remote__ptype__rpc[]
 =IBP_T("rpc");

extern const IBP_CHAR ibp_propval__remote__ptype__batch_send[]
 =IBP_T("batch_send");

extern const IBP_CHAR ibp_propval__remote__ptype__out_of_band[]
 =IBP_T("out_of_band");

extern const IBP_CHAR ibp_propval__remote__ptype__lazy_send[]
 =IBP_T("lazy_send");

//------------------------------------------------------------------------
extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__ptype[4]=
{
 ibp_propval__remote__ptype__rpc,
 ibp_propval__remote__ptype__batch_send,
 ibp_propval__remote__ptype__out_of_band,
 ibp_propval__remote__ptype__lazy_send,
};//g_IBP_PropValuesFor__remote__ptype

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR ibp_propval__remote__parch__generic[]
 =IBP_T("generic");

extern const IBP_CHAR ibp_propval__remote__parch__symmetric[]
 =IBP_T("symmetric");

//------------------------------------------------------------------------
extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__parch[2]=
{
 ibp_propval__remote__parch__generic,
 ibp_propval__remote__parch__symmetric,
};//g_IBP_PropValuesFor__remote_parch

////////////////////////////////////////////////////////////////////////////////

// Значения констант с режимами шифрования соединения клиента и сервера

extern const IBP_CHAR ibp_propval__remote__wire_crypt__disabled[]
 =IBP_T("disabled");

extern const IBP_CHAR ibp_propval__remote__wire_crypt__enabled[]
 =IBP_T("enabled");

extern const IBP_CHAR ibp_propval__remote__wire_crypt__required[]
 =IBP_T("required");

//------------------------------------------------------------------------
extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__wire_crypt[3]=
{
 ibp_propval__remote__wire_crypt__disabled,
 ibp_propval__remote__wire_crypt__enabled,
 ibp_propval__remote__wire_crypt__required,
};//g_IBP_PropValuesFor__remote__wire_crypt

////////////////////////////////////////////////////////////////////////////////

// Определение идентификаторов поддерживаемых протоколов подключения

extern const IBP_CHAR ibp_propval__remote__protocol__10[]
 =IBP_T("10");

extern const IBP_CHAR ibp_propval__remote__protocol__11[]
 =IBP_T("11");

extern const IBP_CHAR ibp_propval__remote__protocol__12[]
 =IBP_T("12");

extern const IBP_CHAR ibp_propval__remote__protocol__13[]
 =IBP_T("13");

//------------------------------------------------------------------------
extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__protocol[4]=
{
 ibp_propval__remote__protocol__10,
 ibp_propval__remote__protocol__11,
 ibp_propval__remote__protocol__12,
 ibp_propval__remote__protocol__13,
};//g_IBP_PropValuesFor__remote__protocol

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

extern const IBP_CHAR ibp_propval__remote__protocol__set01[]
 =IBP_T("set01");

extern const IBP_CHAR ibp_propval__remote__protocol__set02[]
 =IBP_T("set02");

#endif //IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////

// Определение идентификаторов встроенных сервисов аутентификации

extern const IBP_CHAR ibp_propval__remote__auth__Legacy_Auth[]
 =IBP_T("Legacy_Auth");

extern const IBP_CHAR ibp_propval__remote__auth__Win_Sspi[]
 =IBP_T("Win_Sspi");

extern const IBP_CHAR ibp_propval__remote__auth__Srp[]
 =IBP_T("Srp");

extern const IBP_CHAR ibp_propval__remote__auth__Srp224[]
 =IBP_T("Srp224");

extern const IBP_CHAR ibp_propval__remote__auth__Srp256[]
 =IBP_T("Srp256");

extern const IBP_CHAR ibp_propval__remote__auth__Srp384[]
 =IBP_T("Srp384");

extern const IBP_CHAR ibp_propval__remote__auth__Srp512[]
 =IBP_T("Srp512");

////////////////////////////////////////////////////////////////////////////////

// Значения констант метода сжатия данных подключения

extern const IBP_CHAR ibp_propval__remote__wire_compression_type__zlib1_dll[]
 =IBP_T("zlib1.dll");

extern const IBP_CHAR ibp_propval__remote__wire_compression_type__zlib1_builtin[]
 =IBP_T("zlib1.builtin");

extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__wire_compression_type[2]=
{
 ibp_propval__remote__wire_compression_type__zlib1_dll,
 ibp_propval__remote__wire_compression_type__zlib1_builtin,
};//g_IBP_PropValuesFor__remote__wire_compression_type

////////////////////////////////////////////////////////////////////////////////

// Значения констант настройки сжатия данных

extern const IBP_CHAR ibp_propval__remote__wire_compression__disabled[]
 =IBP_T("disabled");

extern const IBP_CHAR ibp_propval__remote__wire_compression__enabled[]
 =IBP_T("enabled");

extern const IBP_CHAR ibp_propval__remote__wire_compression__required[]
 =IBP_T("required");

//------------------------------------------------------------------------
extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__wire_compression[3]=
{
 ibp_propval__remote__wire_compression__disabled,
 ibp_propval__remote__wire_compression__enabled,
 ibp_propval__remote__wire_compression__required,
};//g_IBP_PropValuesFor__remote__wire_compression

////////////////////////////////////////////////////////////////////////////////
// Режимы чтения/записи массивов базы данных

extern const IBP_CHAR ibp_propval__array_rw_mode__direct[]
 =IBP_T("direct");

extern const IBP_CHAR ibp_propval__array_rw_mode__api[]
 =IBP_T("api");

extern const IBP_CHAR* const g_IBP_PropValuesFor__array_rw_mode[2]=
{
 ibp_propval__array_rw_mode__direct,
 ibp_propval__array_rw_mode__api,
};//g_IBP_PropValuesFor__array_rw_mode

////////////////////////////////////////////////////////////////////////////////

extern const IBP_LONG g_IBP_PropValuesFor__wchars_in_utf8_symbol[2]=
{
 1,
 2,
};//g_IBP_PropValuesFor__wchars_in_utf8_symbol

////////////////////////////////////////////////////////////////////////////////
// Обработка ограничений схем метаданных

extern const IBP_CHAR ibp_propval__schema_restrictions__all[]
 =IBP_T("all");

extern const IBP_CHAR ibp_propval__schema_restrictions__valid_only[]
 =IBP_T("valid_only");

extern const IBP_CHAR* const g_IBP_PropValuesFor__schema_restrictions[2]=
{
 ibp_propval__schema_restrictions__all,
 ibp_propval__schema_restrictions__valid_only,
};//g_IBP_PropValuesFor__schema_restrictions

extern const IBP_CHAR* const ibp_propval__schema_restrictions__default
 =ibp_propval__schema_restrictions__all;

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR* const g_IBP_PropValuesFor__first_week_day[7]=
{
 IBP_T("monday"   ),
 IBP_T("tuesday"  ),
 IBP_T("wednesday"),
 IBP_T("thursday" ),
 IBP_T("friday"   ),
 IBP_T("saturday" ),
 IBP_T("sunday"   ),
};//g_IBP_PropValuesFor__first_week_day

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR ibp_propval__dbclient_type__ib[]
 =IBP_T("ib");

extern const IBP_CHAR ibp_propval__dbclient_type__fb[]
 =IBP_T("fb");

extern const IBP_CHAR ibp_propval__dbclient_type__fb_direct[]
 =IBP_T("fb.direct");

extern const IBP_CHAR ibp_propval__dbclient_type__ya[]
 =IBP_T("ya");

extern const IBP_CHAR* const g_IBP_PropValuesFor__dbclient_type[4]=
{
 ibp_propval__dbclient_type__ib,
 ibp_propval__dbclient_type__fb,
 ibp_propval__dbclient_type__fb_direct,
 ibp_propval__dbclient_type__ya,
};//g_IBP_PropValuesFor__dbclient_type

extern const IBP_CHAR* const ibp_propval__dbclient_type__default
 =ibp_propval__dbclient_type__ib;

////////////////////////////////////////////////////////////////////////////////

// Configuration of timezones source

extern const IBP_CHAR ibp_propval__timezones_source__icu[]
 =L"icu";

extern const IBP_CHAR ibp_propval__timezones_source__server[]
 =L"server";

extern const IBP_CHAR* const g_IBP_PropValuesFor__timezones_source[2]=
{
 ibp_propval__timezones_source__icu,
 ibp_propval__timezones_source__server,
};//g_IBP_PropValuesFor__timezones_source

////////////////////////////////////////////////////////////////////////////////
}/*nms v05*/}/*nms ibprovider*/}/*nms sdk*/}/*nms lcpi*/
