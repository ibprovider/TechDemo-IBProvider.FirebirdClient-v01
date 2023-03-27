////////////////////////////////////////////////////////////////////////////////
//LCPI OLEDB Provider for InterBase/Firebird SDK.
//                                                 Kovalenko Dmitry. 25.01.2019
#ifndef _lcpi_sdk__ibprovider__v05__props_values_H_
#define _lcpi_sdk__ibprovider__v05__props_values_H_

#include <lcpi/sdk/ibprovider/v05/lcpi_sdk__ibprovider__v05__types.h>
#include <Transact.h>

namespace lcpi{namespace sdk{namespace ibprovider{namespace v05{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_oledb__propval
//! @{
////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__unicode_mode__default
 =true;

////////////////////////////////////////////////////////////////////////////////

//
// Initial value was 'true'.
// 
// [2021-11-18] [IBP v5.25] Switched to 'false'.
//
const bool ibp_propval__truncate_char__default
 =false;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__support_odbc_query__default
 =false;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__force_prepare_stmt__default
 =false;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__ignore_unprepare__default
 =true;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__clear_param_info__default
 =true;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__auto_param_describe__default
 =true;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__exec_sp_named_param__default
 =false;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__nested_trans__default
 =false;

////////////////////////////////////////////////////////////////////////////////

const bool ibp_propval__force_nulls__default
 =true;

////////////////////////////////////////////////////////////////////////////////

//��������� �������� �������� "Integrated Security" ��� ������� ������� � DataLink
extern const IBP_CHAR g_IBP_IntegratedAuth__NONE[];

extern const IBP_CHAR g_IBP_IntegratedAuth__SSPI[];

////////////////////////////////////////////////////////////////////////////////

extern const IBP_SHORT g_IBP_PropValuesFor__Prompt[4];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_schema_cache

/// <summary>
///  ����� ����������� ����������
/// </summary>
enum t_ibp_propval_schema_cache
{
 ///����������� ���������
 ibp_propval_schema_cache_disable     =0,

 ///�� ������ ��������� ������ (default)
 ibp_propval_schema_cache_data_source =1,

 ///�� ������ ������
 ibp_propval_schema_cache_session     =2,
};//enum t_ibp_propval_schema_cache

const IBP_LONG ibp_propval_schema_cache__default
 =ibp_propval_schema_cache_data_source;

extern const IBP_LONG g_IBP_PropValuesFor__schema_cache[3];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_auto_commit_ddl

/// <summary>
///  ������ ������������� DDL ��������
/// </summary>
enum t_ibp_propval_auto_commit_ddl
{
 ///������ �� ������
 ibp_propval_auto_commit_ddl_none         =0,

 ///��������� DDL ������� � ��������� ����������
 ibp_propval_auto_commit_ddl_separate_tr  =1,

 ///������������ ���������� ����� ������� DDL �������
 ibp_propval_auto_commit_ddl_commit_ret   =2,
};//enum t_ibp_propval_auto_commit_ddl

/// <summary>
///  ����� ������������� DDL-��������. �������� ��-���������.
/// </summary>
const IBP_LONG ibp_propval_auto_commit_ddl__default
 =ibp_propval_auto_commit_ddl_none;

extern const IBP_LONG g_IBP_PropValuesFor__auto_commit_ddl[3];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������� �������� ���������� ���������� ��� DDL-��������. �������� ��-���������.
/// </summary>
const IBP_LONG ibp_propval_auto_commit_ddl_level__default
 =ISOLATIONLEVEL_READCOMMITTED;

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_ignore_err_param

/// <summary>
///  ����� ������������� ������ � ���������� �������.
/// </summary>
enum t_ibp_propval_ignore_err_param
{
 ///������������ IN-�������� � ����������� ������
 ibp_propval_ignore_err_param__IN_param_with_unk_name    =0x0001,

 ///������������ IN-�������� � ������������ ���������� �������
 ibp_propval_ignore_err_param__IN_param_with_bad_pos     =0x0002,

 ///������������� IN-�������� ��� OUT-���������
 ibp_propval_ignore_err_param__IN_value_for_OUT_param    =0x0004,
};//class t_ibp_propval_ignore_err_param

extern const IBP_LONG g_IBP_PropFlagsFor__ignore_err_param[3];

const IBP_LONG ibp_propval__ignore_err_param__default=0;

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_support_square_delim_name

/// <summary>
///  ������ ��������� ������������� ���� �������� �� � �������������� ���������� ������
/// </summary>
enum t_ibp_propval_support_square_delim_name
{
 ///�� �������� �������������� � ����������� � ������� �������� ��
 ibp_propval_support_square_delim_name___none       =0,

 ///���������� ���������. � ����� ��������� ��� ���������� ������
 ibp_propval_support_square_delim_name___simple     =1,

 ///����������� ���������. ��������� ����������� ������������� ���������� ������ ���
 /// ������ �����. ��������, ��� ������� � ��������� �������.
 ibp_propval_support_square_delim_name___adv        =2,
};//enum t_ibp_propval_support_square_delim_name

extern const IBP_LONG g_IBP_PropValuesFor__support_square_delim_name[3];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_keywords_list

/// <summary>
///  ������ ���������� �������� ���� ����� IDBInfo::GetKeywords
/// </summary>
enum t_ibp_propval_keywords_list
{
 /// �������� ����������� �������� �����
 ibp_propval_keywords_list__include_std    =0x01,
};//enum t_ibp_propval_keywords_list

extern const IBP_LONG g_IBP_PropFlagsFor__keywords_list[1];

static const IBP_LONG ibp_propval_keywords_list__default=0;

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_tr_abort_flags

/// <summary>
///  ����� ������ ����������
/// </summary>
enum t_ibp_propval_tr_abort_flags
{
 /// ������������ ����� ���������� ���������� [������ ��� ITransactionLocal::Abort]
 ibp_propval_tr_abort_flags__ignore_for_inactive    =0x0001,
};//enum t_ibp_propval_tr_abort_flags

extern const IBP_LONG g_IBP_PropFlagsFor__tr_abort_flags[1];

static const IBP_LONG ibp_propval_tr_abort_flags__default=0;

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_reset_ds_tr_rule

/// <summary>
///  ������������ ������ ������ ��������� ��������� ������ ��� ������� �������� ����������
/// </summary>
enum t_ibp_propval_reset_ds_tr_rule
{
 /// ���������� ��������� ����������
 ibp_propval_reset_ds_tr_rule__ignore                =0,

 /// ���������� ������ - "����� ��������� ������ ����������"
 ibp_propval_reset_ds_tr_rule__not_set               =1,

 /// ����������� �� ����������. ��� �������� ���������� ����� �������� rollback
 ibp_propval_reset_ds_tr_rule__detach                =2,
};//enum t_ibp_propval_reset_ds_tr_rule

/// <summary>
///  �������� ��-��������� ��� �������� "reset_ds_tr_rule".
/// </summary>
const IBP_LONG ibp_propval_reset_ds_tr_rule__default
 =ibp_propval_reset_ds_tr_rule__not_set;

extern const IBP_LONG g_IBP_PropValuesFor__reset_ds_tr_rule[3];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_reset_ds_session_sinks_rule

/// <summary>
///  ������������ ������ ������ ��������� ��������� ������ ��� ������� �����������
///  �� ����������� ������
/// </summary>
enum t_ibp_propval_reset_ds_session_sinks_rule
{
 /// ���������� ������� ����������� �� ����������� ������
 ibp_propval_reset_ds_session_sinks_rule__ignore     =0,

 /// ���������� ������ - "����� ��������� ������ ����������"
 ibp_propval_reset_ds_session_sinks_rule__not_set    =1,

 /// ����������� �� �����������.
 ibp_propval_reset_ds_session_sinks_rule__detach     =2,
};//enum t_ibp_propval_reset_ds_session_sinks_rule

/// <summary>
///  �������� ��-��������� ��� �������� "reset_ds_session_sinks_rule".
/// </summary>
const IBP_LONG ibp_propval_reset_ds_session_sinks_rule__default
 =ibp_propval_reset_ds_session_sinks_rule__not_set;

extern const IBP_LONG g_IBP_PropValuesFor__reset_ds_session_sinks_rule[3];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_column_type_rules

/// <summary>
///  ������������ ������ ������������ �������� ������� � ���������� � ���������
/// </summary>
enum t_ibp_propval_column_type_rules
{
 ///���������� ���������� ���� �������
 ibp_propval_column_type_rules__native             =0x00,

 ///��� ��������� ������� ���������� � VT-������������
 ibp_propval_column_type_rules__vt_compatible      =0x01,

 ///������ ���������
 ibp_propval_column_type_rules__variant            =0x02,

 ///������� ��� �������� ����� ��� VARIANT
 ibp_propval_column_type_rules__array_as_variant   =0x10,
};//enum t_ibp_propval_column_type_rules

/// <summary>
///  ������������ ���� ������� � ���������� � ���������. �������� ��-���������.
/// </summary>
const IBP_LONG ibp_propval_array_type__default
 =ibp_propval_column_type_rules__vt_compatible;

extern const IBP_LONG g_IBP_PropValuesFor__array_type[5];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  �������� ��-��������� �������� "rowset_vm_using"
/// </summary>
static const IBP_LONG ibp_propval_rowset_vm_using__default=-1;

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_rowset_file_sys_flags

/// <summary>
///  ������������ ��������� ������ ��� ������ �������� �����
/// </summary>
enum t_ibp_propval_rowset_file_sys_flags
{
 ///WIN32: FILE_FLAG_NO_BUFFERING
 ibp_propval_rowset_file_sys_flag__no_buffering        =0x01,

 ///WIN32: FILE_FLAG_WRITE_THROUGH
 ibp_propval_rowset_file_sys_flag__write_through       =0x02,
};//enum t_ibp_propval_rowset_file_sys_flags

/// <summary>
///  ��������� ����� ��� ������ �������� ����� ��-���������
/// </summary>
static const IBP_LONG ibp_propval_rowset_file_sys_flags__default=0;

extern const IBP_LONG g_IBP_PropFlagsFor__rowset_file_sys_flags[2];

////////////////////////////////////////////////////////////////////////////////

static const IBP_LONG ibp_propval_rowset_file__write_block_size__default=0;

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_numeric_rules

/// <summary>
///  ������������ ������, �������� �� ��������� NUMERIC-����� ������
/// </summary>
enum t_ibp_propval_numeric_rules
{
 ///������ �� ���������
 ibp_propval_numeric_rules__default                  =0,

 ///������������ ������� �������. ������ ����� ������������ � �������������� �������� ����
 ibp_propval_numeric_rules__ignore_zero_scale        =0x01,

 ///������������ �������� �������� ����
 ibp_propval_numeric_rules__use_base_type_precision  =0x02,
};//t_ibp_propval_numeric_rules

extern const IBP_LONG g_IBP_PropFlagsFor__numeric_rules[2];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������, �������� �� ��������� TIME-����� ������
/// </summary>
enum t_ibp_propval_dbtime_rules
{
 /// \brief
 ///  ������������ DBTYPE_DBTIME [DBTIME]
 ibp_propval_dbtime_rules__as_dbtime                 =0,

 /// \brief
 ///  ������������ DBTYPE_DBTIME2 [DBTIME2]
 ibp_propval_dbtime_rules__as_dbtime2                =1,

 /// \brief
 ///  ������������ DBTYPE_WSTR
 ibp_propval_dbtime_rules__as_wstr                   =2,
};//enum t_ibp_propval_dbtime_rules

/// <summary>
///  �������� ��-���������
/// </summary>
static const IBP_LONG ibp_propval_dbtime_rules__default
 =ibp_propval_dbtime_rules__as_dbtime;

extern const IBP_LONG g_IBP_PropValuesFor__dbtime_rules[3];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������, �������� �� ��������� DBTIMESTAMP-����� ������
/// </summary>
enum t_ibp_propval_dbtimestamp_rules
{
 /// \brief
 ///  ������������ DBTYPE_DBTIMESTAMP [DBTIMESTAMP]
 ibp_propval_dbtimestamp_rules__as_dbtimestamp            =0,

 /// \brief
 ///  ������������ DBTYPE_WSTR
 ibp_propval_dbtimestamp_rules__as_wstr                   =2,
};//enum t_ibp_propval_dbtimestamp_rules

/// <summary>
///  �������� ��-���������
/// </summary>
static const IBP_LONG ibp_propval_dbtimestamp_rules__default
 =ibp_propval_dbtimestamp_rules__as_dbtimestamp;

extern const IBP_LONG g_IBP_PropValuesFor__dbtimestamp_rules[2];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������, �������� �� ��������� DBDATE-����� ������
/// </summary>
enum t_ibp_propval_dbdate_rules
{
 /// \brief
 ///  ������������ DBTYPE_DBDATE [DBDATE]
 ibp_propval_dbdate_rules__as_dbdate                      =0,

 /// \brief
 ///  ������������ DBTYPE_WSTR
 ibp_propval_dbdate_rules__as_wstr                        =2,
};//enum t_ibp_propval_dbdate_rules

/// <summary>
///  �������� ��-���������
/// </summary>
static const IBP_LONG ibp_propval_dbdate_rules__default
 =ibp_propval_dbdate_rules__as_dbdate;

extern const IBP_LONG g_IBP_PropValuesFor__dbdate_rules[2];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Flag enumeration, which affect on processing of GUID data type
/// </summary>
enum t_ibp_propval_guid_rules
{
 /// \brief
 ///  Text form uses lower case symbols
 ibp_propval__guid_rules__txt_with_lower_case        =1,

 /// \brief
 ///  Text form has figure bracket
 ibp_propval__guid_rules__txt_with_fbracket          =2,
};//enum t_ibp_propval_guid_rules

/// <summary>
///  Default value
/// </summary>
static const IBP_LONG ibp_propval__guid_rules__default
 =0;

/// <summary>
///  Static settings. Describes behaviour of ISC DBMS.
/// </summary>
static const IBP_LONG ibp_propval__guid_rules__default_for_isc
 =0;

extern const IBP_LONG g_IBP_PropFlagsFor__guid_rules[2];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval_dll_lock_rule

/// <summary>
///  ������������ ������ ������������ ������� DLL
/// </summary>
enum t_ibp_propval_dll_lock_rule
{
 /// \brief ������������� ��������
 ibp_propval_dll_lock_rule__force_unload             =0,

 /// \brief ���������� � ������ �� �������� ������ ����������
 ibp_propval_dll_lock_rule__unload                   =1,

 /// \brief �� ���������
 ibp_propval_dll_lock_rule__no_unload                =2,
};//enum t_ibp_propval_dll_lock_rule

extern const IBP_LONG g_IBP_PropValuesFor__dll_lock_rules[3];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval__deferred_data_rule

/// <summary>
///  ������������ ������ ������ � ����������� ���������� �������
/// </summary>
enum t_ibp_propval__deferred_data_rule
{
 /// \brief
 ///  ���������� �������� ������ ���������.
 ibp_propval__deferred_data_rule__disabled               =0,

 /// \brief
 ///  ���������������� ����������. ���������� �������� ������ ���������.
 ibp_propval__deferred_data_rule__enabled_for_user_tr    =1,

 /// \brief
 ///  �������������� ����������. ���������� �������� ������ ���������.
 ibp_propval__deferred_data_rule__enabled_for_auto_tr    =2,

 /// \brief
 ///  ���������� �������� ������ ���������.
 ibp_propval__deferred_data_rule__enabled=
  ibp_propval__deferred_data_rule__enabled_for_user_tr|
  ibp_propval__deferred_data_rule__enabled_for_auto_tr
};//enum t_ibp_propval__deferred_data_rule

/// �������� ��-��������� �������� "deferred_data"
const IBP_LONG ibp_propval__deferred_data__default
 =ibp_propval__deferred_data_rule__enabled;

/// �������� ��-��������� �������� "deferred_out_param"
const IBP_LONG ibp_propval__deferred_out_param__default
 =ibp_propval__deferred_data_rule__enabled_for_user_tr;

extern const IBP_LONG g_IBP_PropFlagsFor__deferred_data_rules[2];

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval__newdb__type_of_db_users

/// <summary>
///  ������������ ����� ������������� ���� ������
/// </summary>
enum t_ibp_propval__newdb__type_of_db_users
{
 /// \brief
 ///  ������������ ������������, ������������ �� ������ ������� ��.
 ibp_propval__newdb__type_of_db_users__server      =0,

 /// \brief
 ///  ������������ ������������, ������������ �� ������ ��.
 ibp_propval__newdb__type_of_db_users__embedded    =1,
};//enum t_ibp_propval__newdb__type_of_db_users

extern const IBP_LONG g_IBP_PropValuesFor__newdb__type_of_db_users[2];

////////////////////////////////////////////////////////////////////////////////

/// ����� ����� ������� � ����. �������� ��-���������.
static const IBP_LONG ibp_propval_stmt_cache_time__default=60;

/// ������ ���� ��������. �������� ��-���������.
static const IBP_LONG ibp_propval_stmt_cache_size__default=1024;

/// ����� ����� ��������������� ������� � ����. �������� ��-���������.
static const IBP_LONG ibp_propval_stmt_cache_req_life_time__default=30;

////////////////////////////////////////////////////////////////////////////////

/// SQL Cache. ����� ����� �������� � ����. �������� ��-���������.
static const IBP_LONG ibp_propval__sql_cache__time__default=60;

/// SQL Cache. ������ ����. �������� ��-���������.
static const IBP_LONG ibp_propval__sql_cache__size__default=1024;

//------------------------------------------------------------------------
extern const IBP_CHAR ibp_propval__sql_cache__scope__empty[];

extern const IBP_CHAR ibp_propval__sql_cache__scope__cn[];

extern const IBP_CHAR ibp_propval__sql_cache__scope__db[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__sql_cache__scope[3];

extern const IBP_CHAR* const ibp_propval__sql_cache__scope__default;

////////////////////////////////////////////////////////////////////////////////

#if !defined(IBP_ENGINE_UPDATE_ROWSET) || (IBP_ENGINE_UPDATE_ROWSET!=0)
////////////////////////////////////////////////////////////////////////////////

//��� ���������� ������������ ��� ����������� ������
enum t_ibp_modify_trans_type
{
 //���� ����� ������ � �������������� ���������� - ��� ��������� ������ �����
 // �������������� ��������� ���������� (ibp_modify_trans_separate)
 //����� - ��������� ����������� � �������� ���������� �������������
 // ������� ������ (ibp_modify_trans_main)
 ibp_modify_trans_mutable       =0, //default

 //���� ��������� ������������� � �������������� ����������, �� ��� ���������
 //����� ������������� ����� ������������ ������ �����.
 //���� ������������ ���� ��������� ����������, �� ��������� ����� �������������
 //����� ����� ������������� ��� ����� ����������
 ibp_modify_trans_main          =1,

 //��� ����������� ������������ ��������� ����������, ������� �����������
 //����� ��������� ������� ����
 ibp_modify_trans_separate      =2,
};//enum t_ibp_modify_trans_type

extern const IBP_SHORT g_IBP_PropValuesFor__modify_trans_type[3];

////////////////////////////////////////////////////////////////////////////////

//��� ���������� ������������ ��� ������������� ������
enum t_ibp_refresh_trans_type
{
 //���� ����� ������ � �������������� ���������� - ��� ������������� ������ �����
 // �������������� ��������� ���������� (ibp_refresh_trans_separate)
 //����� - ������������� ����������� � �������� ���������� �������������
 // ������� ������ (ibp_refresh_trans_main)
 ibp_refresh_trans_mutable       =0, //default

 //������������� ������ �������������� � ����������� ���������� ���������
 ibp_refresh_trans_main          =1,

 //��� ������������� ������������ ��������� ����������
 ibp_refresh_trans_separate      =2,
};//enum t_ibp_refresh_trans_type

extern const IBP_SHORT g_IBP_PropValuesFor__refresh_trans_type[3];

////////////////////////////////////////////////////////////////////////////////
//��������� ��������������� ������ ���������� ���������

enum
{
 //������������ ������� ��� ������� ������ ����
 ibp_auto_insert_field_rule__all         =0, //��� ������� [default]
 ibp_auto_insert_field_rule__installed   =1, //��� ������� ���������� ������
 ibp_auto_insert_field_rule__not_null    =2, //�� NULL
};

extern const IBP_PROP__AUTO_INSERT_FIELD_RULE g_IBP_PropValuesFor__auto_insert_field_rule[3];

//------------------------------------------------------------------------
enum
{
 ibp_auto_update_field_rule__all         =0,
 ibp_auto_update_field_rule__installed   =1,
};

extern const IBP_PROP__AUTO_UPDATE_FIELD_RULE g_IBP_PropValuesFor__auto_update_field_rule[2];

////////////////////////////////////////////////////////////////////////////////
//������� ��� ��������� ������ ����������� �������� ����������� ��������

enum
{
 // ������������ �������� ������� ������ ����
 ibp_propval__server_data_back_read__insert          =1,

 // ������������ �������� ������� ������������ ����
 ibp_propval__server_data_back_read__update          =2,
};

static const IBP_LONG ibp_propval__server_data_back_read__default=0;

extern const IBP_LONG g_IBP_PropFlagsFor__server_data_back_read[2];

////////////////////////////////////////////////////////////////////////////////
#endif //(IBP_ENGINE_UPDATE_ROWSET!=0)

////////////////////////////////////////////////////////////////////////////////
//enum t_ibp_propval__multi_stmts_exec_rules

/// <summary>
///  ������������ ������ ���������� ��������
/// </summary>
enum t_ibp_propval__multi_stmts_exec_rules
{
 //! \brief ���������� ���������� ������� ����� ������
 ibp_propval__multi_stmts_exec_rules__continue_after_error =0x01,
};//enum t_ibp_propval__multi_stmts_exec_rules

/// <summary>
///  ������� ���������� ��������. �������� ��-���������.
/// </summary>
static const IBP_LONG ibp_propval__multi_stmts_exec_rules__default=0;

extern const IBP_LONG g_IBP_PropFlagsFor__multi_stmts_exec_rules[1];

////////////////////////////////////////////////////////////////////////////////
//InterBase isolation levels

extern const wchar_t ibp_propval__ib_tr_params__read_committed__default[];

extern const wchar_t ibp_propval__ib_tr_params__repeatable_read__default[];

extern const wchar_t ibp_propval__ib_tr_params__serializable__default[];

////////////////////////////////////////////////////////////////////////////////

///�������� ��-��������� ��� �������� "open_rowset__sql"
static const bool ibp_propval__open_rowset__sql__default=false;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������� ��������� ����������� ���������� � ������ �������
/// </summary>
enum t_ibp_propval__named_param_rules
{
 /// ��������� ������� � ����� ���������
 ibp_propval__named_param_rules__save_prefix            =0x0001,
};//enum t_ibp_propval__named_param_rules

/// �������� ��-��������� ��� �������� "named_param_rules"
static const IBP_LONG ibp_propval__named_param_rules__default=0;

extern const IBP_LONG g_IBP_PropFlagsFor__named_param_rules[1];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������������ ������� ������� ����������� ��������
/// </summary>
enum t_ibp_propval__asynch_fetch
{
 /// ������� ����������� �������� ���������
 ibp_propval__asynch_fetch__disabled                    =0,

 /// ������� ����������� �������� ������ ��������
 ibp_propval__asynch_fetch__enabled                     =1,

 /// ������� ����������� �������� ���������� ����� ��������� ������� ����������� �������������
 ibp_propval__asynch_fetch__turn_on_when_asynch_init    =2,
};//enum t_ibp_propval__asynch_fetch

extern const IBP_LONG g_IBP_PropValuesFor__asynch_fetch[3];

/// <summary>
///  �������� ��-��������� ��� �������� "asynch_fetch"
/// </summary>
static const IBP_LONG ibp_propval__asynch_fetch__default=ibp_propval__asynch_fetch__disabled;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������� ���������� ���������� ������������
/// </summary>
enum t_ibp_propval__nested_trans_rules
{
 /// ���������� ����� ������ ��������� ��������� ����������
 ibp_propval__nested_trans_rules__implicit_commit_by_tr   =0x0001,

 /// ����� ���������� ����� ������ ��������� ��������� ����������
 ibp_propval__nested_trans_rules__implicit_commit_by_svp  =0x0002,
};//enum t_ibp_propval__nested_trans_rules

/// �������� ��-��������� ��� �������� "nested_trans_rules"
static const IBP_LONG ibp_propval__nested_trans_rules__default=0;

extern const IBP_LONG g_IBP_PropFlagsFor__nested_trans_rules[2];

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������� ���������� �������� � CHECK-������������.
/// </summary>
enum t_ibp_propval__schema_ldr_cfg__check_constraints
{
 /// ��������� �������� � CHECK-������������
 ibp_propval__schema_ldr_cfg__check_constraints__no       =0,

 /// ��������� �������� � CHECK-������������
 ibp_propval__schema_ldr_cfg__check_constraints__yes      =1,
};//enum t_ibp_propval__schema_ldr_cfg__check_constraints

extern const IBP_LONG g_IBP_PropValuesFor__schema_ldr_cfg__check_constraints[2];

/// <summary>
///  �������� ��-��������� ��� �������� "schema_ldr_cfg__check_constraints"
/// </summary>
static const IBP_LONG ibp_propval__schema_ldr_cfg__check_constraints__default
 =ibp_propval__schema_ldr_cfg__check_constraints__yes;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ������� ���������� �������� �������� � ������ ����������.
/// </summary>
enum t_ibp_propval__schema_ldr_cfg__descriptions
{
 /// ��������� �������� � CHECK-������������
 ibp_propval__schema_ldr_cfg__descriptions__no            =0,

 /// ��������� �������� � CHECK-������������
 ibp_propval__schema_ldr_cfg__descriptions__yes           =1,
};//enum t_ibp_propval__schema_ldr_cfg__descriptions

extern const IBP_LONG g_IBP_PropValuesFor__schema_ldr_cfg__descriptions[2];

/// <summary>
///  �������� ��-��������� ��� �������� "schema_ldr_cfg__descriptions"
/// </summary>
static const IBP_LONG ibp_propval__schema_ldr_cfg__descriptions__default
 =ibp_propval__schema_ldr_cfg__descriptions__yes;

////////////////////////////////////////////////////////////////////////////////
// ���� ����������, ������������ ����������� � ����������� ��������� ��������

extern const IBP_CHAR ibp_propval__remote__ptype__rpc[];

extern const IBP_CHAR ibp_propval__remote__ptype__batch_send[];

extern const IBP_CHAR ibp_propval__remote__ptype__out_of_band[];

extern const IBP_CHAR ibp_propval__remote__ptype__lazy_send[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__ptype[4];

////////////////////////////////////////////////////////////////////////////////

// �������� �������� � ������ ���������� (������� �������� ������) ���������
// �������������� ������������ ������� � �������� ���� ������

extern const IBP_CHAR ibp_propval__remote__parch__generic[];

extern const IBP_CHAR ibp_propval__remote__parch__symmetric[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__parch[2];

////////////////////////////////////////////////////////////////////////////////

// �������� �������� � �������� ���������� ���������� ������� � �������

extern const IBP_CHAR ibp_propval__remote__wire_crypt__disabled[];

extern const IBP_CHAR ibp_propval__remote__wire_crypt__enabled[];

extern const IBP_CHAR ibp_propval__remote__wire_crypt__required[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__wire_crypt[3];

////////////////////////////////////////////////////////////////////////////////

// ����������� ��������������� �������������� ���������� �����������

extern const IBP_CHAR ibp_propval__remote__protocol__10[];

extern const IBP_CHAR ibp_propval__remote__protocol__11[];

extern const IBP_CHAR ibp_propval__remote__protocol__12[];

extern const IBP_CHAR ibp_propval__remote__protocol__13[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__protocol[4];

//------------------------------------------------------------------------
#ifdef IBP_BUILD_TESTCODE

extern const IBP_CHAR ibp_propval__remote__protocol__set01[];

extern const IBP_CHAR ibp_propval__remote__protocol__set02[];

#endif //IBP_BUILD_TESTCODE

////////////////////////////////////////////////////////////////////////////////

// ����������� ��������������� ���������� �������� ��������������

extern const IBP_CHAR ibp_propval__remote__auth__Legacy_Auth[];

extern const IBP_CHAR ibp_propval__remote__auth__Win_Sspi[];

extern const IBP_CHAR ibp_propval__remote__auth__Srp[];

extern const IBP_CHAR ibp_propval__remote__auth__Srp224[];

extern const IBP_CHAR ibp_propval__remote__auth__Srp256[];

extern const IBP_CHAR ibp_propval__remote__auth__Srp384[];

extern const IBP_CHAR ibp_propval__remote__auth__Srp512[];

////////////////////////////////////////////////////////////////////////////////

// �������� �������� ������ ������ ������ �����������

extern const IBP_CHAR ibp_propval__remote__wire_compression_type__zlib1_dll[];

extern const IBP_CHAR ibp_propval__remote__wire_compression_type__zlib1_builtin[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__wire_compression_type[2];

////////////////////////////////////////////////////////////////////////////////

// �������� �������� ��������� ������ ������ �����������

extern const IBP_CHAR ibp_propval__remote__wire_compression__disabled[];

extern const IBP_CHAR ibp_propval__remote__wire_compression__enabled[];

extern const IBP_CHAR ibp_propval__remote__wire_compression__required[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__remote__wire_compression[3];

////////////////////////////////////////////////////////////////////////////////
// ������ ������/������ �������� ���� ������

extern const IBP_CHAR ibp_propval__array_rw_mode__direct[];

extern const IBP_CHAR ibp_propval__array_rw_mode__api[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__array_rw_mode[2];

////////////////////////////////////////////////////////////////////////////////

static const IBP_LONG ibp_propval__provider_error_rules__default
 =-1;

////////////////////////////////////////////////////////////////////////////////

static const IBP_LONG ibp_propval__wchars_in_utf8_symbol__default
 =1; //ONE WCHAR for ONE UTF8.

extern const IBP_LONG g_IBP_PropValuesFor__wchars_in_utf8_symbol[2];

////////////////////////////////////////////////////////////////////////////////
// ��������� ����������� ���� ����������

extern const IBP_CHAR ibp_propval__schema_restrictions__all[];

extern const IBP_CHAR ibp_propval__schema_restrictions__valid_only[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__schema_restrictions[2];

extern const IBP_CHAR* const ibp_propval__schema_restrictions__default;

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR* const g_IBP_PropValuesFor__first_week_day[7];

////////////////////////////////////////////////////////////////////////////////

extern const IBP_CHAR ibp_propval__dbclient_type__ib[];
extern const IBP_CHAR ibp_propval__dbclient_type__fb[];
extern const IBP_CHAR ibp_propval__dbclient_type__fb_direct[];
extern const IBP_CHAR ibp_propval__dbclient_type__ya[];

extern const IBP_CHAR* const g_IBP_PropValuesFor__dbclient_type[4];

extern const IBP_CHAR* const ibp_propval__dbclient_type__default;

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms v05*/}/*nms ibprovider*/}/*nms sdk*/}/*nms lcpi*/
#endif
