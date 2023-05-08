////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_api
//! \file    isc_api.h
//! \brief   Описание конструкций ISC API
//! \author  Kovalenko Dmitry
//! \date    23.11.2003
#ifndef _isc_api_H_
#define _isc_api_H_

#include "source/db_obj/db_data_types.h"

namespace lcpi{namespace ibp{namespace isc_api{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_api
//! @{
////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Тип для кодов возврата и элементов статус вектора
/// </summary>
typedef INT_PTR                             t_ibp_isc_status;

////////////////////////////////////////////////////////////////////////////////

/// Количество байт, отведенных под поле с размером данных информационного тега
const size_t ibp_isc__info_tag__data_length__byte_count=2;

////////////////////////////////////////////////////////////////////////////////

enum
{
 ibp_isc_err_code__segment             = 335544366L,
 ibp_isc_err_code__segstr_eof          = 335544367L,
};//enum

////////////////////////////////////////////////////////////////////////////////
//Common, structural codes

enum
{
 ibp_isc_info_end                      = 1,
 ibp_isc_info_truncated                = 2,
 ibp_isc_info_error                    = 3,
 ibp_isc_info_data_not_ready           = 4
};//enum

////////////////////////////////////////////////////////////////////////////////
//Database parameter block stuff

enum
{
 ibp_isc_dpb_version1                  =1,

 ibp_isc_dpb_cdd_pathname              =1,
 ibp_isc_dpb_allocation                =2,
 ibp_isc_dpb_journal                   =3,
 ibp_isc_dpb_page_size                 =4,
 ibp_isc_dpb_num_buffers               =5,
 ibp_isc_dpb_buffer_length             =6,
 ibp_isc_dpb_debug                     =7,
 ibp_isc_dpb_garbage_collect           =8,
 ibp_isc_dpb_verify                    =9,
 ibp_isc_dpb_sweep                     =10,
 ibp_isc_dpb_enable_journal            =11,
 ibp_isc_dpb_disable_journal           =12,
 ibp_isc_dpb_dbkey_scope               =13,
 ibp_isc_dpb_number_of_users           =14,
 ibp_isc_dpb_trace                     =15,
 ibp_isc_dpb_no_garbage_collect        =16,
 ibp_isc_dpb_damaged                   =17,
 ibp_isc_dpb_license                   =18,
 ibp_isc_dpb_sys_user_name             =19,
 ibp_isc_dpb_encrypt_key               =20,
 ibp_isc_dpb_activate_shadow           =21,
 ibp_isc_dpb_sweep_interval            =22,
 ibp_isc_dpb_delete_shadow             =23,
 ibp_isc_dpb_force_write               =24,
 ibp_isc_dpb_begin_log                 =25,
 ibp_isc_dpb_quit_log                  =26,
 ibp_isc_dpb_no_reserve                =27,
 ibp_isc_dpb_user_name                 =28,
 ibp_isc_dpb_password                  =29,
 ibp_isc_dpb_password_enc              =30,
 ibp_isc_dpb_sys_user_name_enc         =31,
 ibp_isc_dpb_interp                    =32,
 ibp_isc_dpb_online_dump               =33,
 ibp_isc_dpb_old_file_size             =34,
 ibp_isc_dpb_old_num_files             =35,
 ibp_isc_dpb_old_file                  =36,
 ibp_isc_dpb_old_start_page            =37,
 ibp_isc_dpb_old_start_seqno           =38,
 ibp_isc_dpb_old_start_file            =39,
 ibp_isc_dpb_drop_walfile              =40,
 ibp_isc_dpb_old_dump_id               =41,
 ibp_isc_dpb_wal_backup_dir            =42,
 ibp_isc_dpb_wal_chkptlen              =43,
 ibp_isc_dpb_wal_numbufs               =44,
 ibp_isc_dpb_wal_bufsize               =45,
 ibp_isc_dpb_wal_grp_cmt_wait          =46,
 ibp_isc_dpb_lc_messages               =47,
 ibp_isc_dpb_lc_ctype                  =48,
 ibp_isc_dpb_cache_manager             =49,
 ibp_isc_dpb_shutdown                  =50,
 ibp_isc_dpb_online                    =51,
 ibp_isc_dpb_shutdown_delay            =52,
 ibp_isc_dpb_reserved                  =53,
 ibp_isc_dpb_overwrite                 =54,
 ibp_isc_dpb_sec_attach                =55,
 ibp_isc_dpb_disable_wal               =56,
 ibp_isc_dpb_connect_timeout           =57,
 ibp_isc_dpb_dummy_packet_interval     =58,
 ibp_isc_dpb_gbak_attach               =59,
 ibp_isc_dpb_sql_role_name             =60,
 ibp_isc_dpb_set_page_buffers          =61,
 ibp_isc_dpb_working_directory         =62,
 ibp_isc_dpb_SQL_dialect               =63,
 ibp_isc_dpb_set_db_readonly           =64,
 ibp_isc_dpb_set_db_SQL_dialect        =65,
 ibp_isc_dpb_gfix_attach               =66,
 ibp_isc_dpb_gstat_attach              =67
};//enum

////////////////////////////////////////////////////////////////////////////////
//Database information items

enum
{
 ibp_isc_info_db_id                    = 4,
 ibp_isc_info_reads                    = 5,
 ibp_isc_info_writes                   = 6,
 ibp_isc_info_fetches                  = 7,
 ibp_isc_info_marks                    = 8,
 ibp_isc_info_implementation           = 11,
 ibp_isc_info_version                  = 12,
 ibp_isc_info_base_level               = 13,
 ibp_isc_info_page_size                = 14,
 ibp_isc_info_num_buffers              = 15,
 ibp_isc_info_limbo                    = 16,
 ibp_isc_info_current_memory           = 17,
 ibp_isc_info_max_memory               = 18,
 ibp_isc_info_window_turns             = 19,
 ibp_isc_info_license                  = 20,
 ibp_isc_info_allocation               = 21,
 ibp_isc_info_attachment_id            = 22,
 ibp_isc_info_read_seq_count           = 23,
 ibp_isc_info_read_idx_count           = 24,
 ibp_isc_info_insert_count             = 25,
 ibp_isc_info_update_count             = 26,
 ibp_isc_info_delete_count             = 27,
 ibp_isc_info_backout_count            = 28,
 ibp_isc_info_purge_count              = 29,
 ibp_isc_info_expunge_count            = 30,
 ibp_isc_info_sweep_interval           = 31,
 ibp_isc_info_ods_version              = 32,
 ibp_isc_info_ods_minor_version        = 33,
 ibp_isc_info_no_reserve               = 34,
 ibp_isc_info_logfile                  = 35,
 ibp_isc_info_cur_logfile_name         = 36,
 ibp_isc_info_cur_log_part_offset      = 37,
 ibp_isc_info_num_wal_buffers          = 38,
 ibp_isc_info_wal_buffer_size          = 39,
 ibp_isc_info_wal_ckpt_length          = 40,
 ibp_isc_info_wal_cur_ckpt_interval    = 41,
 ibp_isc_info_wal_prv_ckpt_fname       = 42,
 ibp_isc_info_wal_prv_ckpt_poffset     = 43,
 ibp_isc_info_wal_recv_ckpt_fname      = 44,
 ibp_isc_info_wal_recv_ckpt_poffset    = 45,
 ibp_isc_info_wal_grpc_wait_usecs      = 47,
 ibp_isc_info_wal_num_io               = 48,
 ibp_isc_info_wal_avg_io_size          = 49,
 ibp_isc_info_wal_num_commits          = 50,
 ibp_isc_info_wal_avg_grpc_size        = 51,
 ibp_isc_info_forced_writes            = 52,
 ibp_isc_info_user_names               = 53,
 ibp_isc_info_page_errors              = 54,
 ibp_isc_info_record_errors            = 55,
 ibp_isc_info_bpage_errors             = 56,
 ibp_isc_info_dpage_errors             = 57,
 ibp_isc_info_ipage_errors             = 58,
 ibp_isc_info_ppage_errors             = 59,
 ibp_isc_info_tpage_errors             = 60,
 ibp_isc_info_set_page_buffers         = 61,
 ibp_isc_info_db_SQL_dialect           = 62,
 ibp_isc_info_db_read_only             = 63,
 ibp_isc_info_db_size_in_pages         = 64
};//enum

////////////////////////////////////////////////////////////////////////////////
//Blob information items

enum
{
 ibp_isc_info_blob_num_segments         =4,
 ibp_isc_info_blob_max_segment          =5,
 ibp_isc_info_blob_total_length         =6,
 ibp_isc_info_blob_type                 =7,
};//enum

////////////////////////////////////////////////////////////////////////////////
//Blob Parameter Block

enum
{
 ibp_isc_bpb_version1                  =1,
 ibp_isc_bpb_source_type               =1,
 ibp_isc_bpb_target_type               =2,
 ibp_isc_bpb_type                      =3,
 ibp_isc_bpb_source_interp             =4,
 ibp_isc_bpb_target_interp             =5,
 ibp_isc_bpb_filter_parameter          =6,
 ibp_isc_bpb_storage                   =7,
};//enum

enum
{
 ibp_isc_bpb_type_segmented            =0x0,
 ibp_isc_bpb_type_stream               =0x1,
 ibp_isc_bpb_storage_main              =0x0,
 ibp_isc_bpb_storage_temp              =0x2,
};//enum

////////////////////////////////////////////////////////////////////////////////

enum
{
 ibp_isc_DSQL_close     =1,
 ibp_isc_DSQL_drop      =2,

 ibp_ib065_DSQL_cancel  =4,
};

////////////////////////////////////////////////////////////////////////////////
//Request information items

enum
{
 ibp_isc_info_number_messages          =4,
 ibp_isc_info_max_message              =5,
 ibp_isc_info_max_send                 =6,
 ibp_isc_info_max_receive              =7,
 ibp_isc_info_state                    =8,
 ibp_isc_info_message_number           =9,
 ibp_isc_info_message_size             =10,
 ibp_isc_info_request_cost             =11,
 ibp_isc_info_access_path              =12,
 ibp_isc_info_req_select_count         =13,
 ibp_isc_info_req_insert_count         =14,
 ibp_isc_info_req_update_count         =15,
 ibp_isc_info_req_delete_count         =16,
};//enum

////////////////////////////////////////////////////////////////////////////////
// SQL information items

enum
{
 ibp_isc_info_sql_select               =4,
 ibp_isc_info_sql_bind                 =5,
 ibp_isc_info_sql_num_variables        =6,
 ibp_isc_info_sql_describe_vars        =7,
 ibp_isc_info_sql_describe_end         =8,
 ibp_isc_info_sql_sqlda_seq            =9,
 ibp_isc_info_sql_message_seq          =10,
 ibp_isc_info_sql_type                 =11,
 ibp_isc_info_sql_sub_type             =12,
 ibp_isc_info_sql_scale                =13,
 ibp_isc_info_sql_length               =14,
 ibp_isc_info_sql_null_ind             =15,
 ibp_isc_info_sql_field                =16,
 ibp_isc_info_sql_relation             =17,
 ibp_isc_info_sql_owner                =18,
 ibp_isc_info_sql_alias                =19,
 ibp_isc_info_sql_sqlda_start          =20,
 ibp_isc_info_sql_stmt_type            =21,
 ibp_isc_info_sql_get_plan             =22,
 ibp_isc_info_sql_records              =23,
 ibp_isc_info_sql_batch_fetch          =24,
};//enum

////////////////////////////////////////////////////////////////////////////////
//Transaction parameter block stuff

enum
{
 ibp_isc_tpb_version1                  =1,
 ibp_isc_tpb_version3                  =3,
 ibp_isc_tpb_consistency               =1,
 ibp_isc_tpb_concurrency               =2,
 ibp_isc_tpb_shared                    =3,
 ibp_isc_tpb_protected                 =4,
 ibp_isc_tpb_exclusive                 =5,
 ibp_isc_tpb_wait                      =6,
 ibp_isc_tpb_nowait                    =7,
 ibp_isc_tpb_read                      =8,
 ibp_isc_tpb_write                     =9,
 ibp_isc_tpb_lock_read                 =10,
 ibp_isc_tpb_lock_write                =11,
 ibp_isc_tpb_verb_time                 =12,
 ibp_isc_tpb_commit_time               =13,
 ibp_isc_tpb_ignore_limbo              =14,
 ibp_isc_tpb_read_committed            =15,
 ibp_isc_tpb_autocommit                =16,
 ibp_isc_tpb_rec_version               =17,
 ibp_isc_tpb_no_rec_version            =18,
 ibp_isc_tpb_restart_requests          =19,
 ibp_isc_tpb_no_auto_undo              =20,
};//enum

////////////////////////////////////////////////////////////////////////////////
//Array slice description language (SDL)

enum
{
 ibp_isc_sdl_version1                  =1,
 ibp_isc_sdl_eoc                       =255,
 ibp_isc_sdl_relation                  =2,
 ibp_isc_sdl_rid                       =3,
 ibp_isc_sdl_field                     =4,
 ibp_isc_sdl_fid                       =5,
 ibp_isc_sdl_struct                    =6,
 ibp_isc_sdl_variable                  =7,
 ibp_isc_sdl_scalar                    =8,
 ibp_isc_sdl_tiny_integer              =9,
 ibp_isc_sdl_short_integer             =10,
 ibp_isc_sdl_long_integer              =11,
 ibp_isc_sdl_literal                   =12,
 ibp_isc_sdl_add                       =13,
 ibp_isc_sdl_subtract                  =14,
 ibp_isc_sdl_multiply                  =15,
 ibp_isc_sdl_divide                    =16,
 ibp_isc_sdl_negate                    =17,
 ibp_isc_sdl_eql                       =18,
 ibp_isc_sdl_neq                       =19,
 ibp_isc_sdl_gtr                       =20,
 ibp_isc_sdl_geq                       =21,
 ibp_isc_sdl_lss                       =22,
 ibp_isc_sdl_leq                       =23,
 ibp_isc_sdl_and                       =24,
 ibp_isc_sdl_or                        =25,
 ibp_isc_sdl_not                       =26,
 ibp_isc_sdl_while                     =27,
 ibp_isc_sdl_assignment                =28,
 ibp_isc_sdl_label                     =29,
 ibp_isc_sdl_leave                     =30,
 ibp_isc_sdl_begin                     =31,
 ibp_isc_sdl_end                       =32,
 ibp_isc_sdl_do3                       =33,
 ibp_isc_sdl_do2                       =34,
 ibp_isc_sdl_do1                       =35,
 ibp_isc_sdl_element                   =36,
};

////////////////////////////////////////////////////////////////////////////////

enum
{
 ibp_isc_sp_param_direction__input     =0,
 ibp_isc_sp_param_direction__output    =1,
};//enum

////////////////////////////////////////////////////////////////////////////////
//Идентификаторы стандартных кодовых страниц

enum
{
 /// Кодовая страница NONE
 ibp_isc_cs_id__NONE          =0,

 /// Кодовая страница OCTETS
 ibp_isc_cs_id__OCTETS        =1,

 /// Кодовая страница UNICODE_FSS
 ibp_isc_cs_id__ASCII         =2,

 /// Кодовая страница UNICODE_FSS
 ibp_isc_cs_id__UNICODE_FSS   =3,

 /// [FB4] Кодовая страница UTF8 
 ibp_fb040_cs_id__UTF8        =4,

 /// Идентификатор кодовой страницы подключения
 ibp_isc_cs_id__DYNAMIC       =127,
};//enum

////////////////////////////////////////////////////////////////////////////////
//consts

const long isc_time_seconds_precision=db_obj::isc_time_seconds_precision;

////////////////////////////////////////////////////////////////////////////////
//enumerate standart InterBase data types

enum
{
 ibp_isc_sql_varying      =448,
 ibp_isc_sql_text         =452,
 ibp_isc_sql_double       =480,
 ibp_isc_sql_float        =482,
 ibp_isc_sql_long         =496,
 ibp_isc_sql_short        =500,
 ibp_isc_sql_timestamp    =510,
 ibp_isc_sql_blob         =520,
 //ibp_isc_sql_d_float      =530,
 ibp_isc_sql_array        =540,
 ibp_isc_sql_quad         =550,
 ibp_isc_sql_type_time    =560,  //t_ibp_isc_time
 ibp_isc_sql_type_date    =570,  //t_ibp_isc_date
 ibp_isc_sql_int64        =580,

 ibp_ib070_sql_boolean    =590,  //t_ibp_ib070_bool

 ibp_fb025_sql_null       =32766,

 ibp_fb030_sql_boolean    =32764, //t_ibp_fb030_bool

 ibp_fb040_sql_int128            =32752, //t_ibp_fb40_int128
 ibp_fb040_sql_timestamp_with_tz =32754, //t_ibp_fb040_timestamp_with_tz
 ibp_fb040_sql_time_with_tz      =32756, //t_ibp_fb040_time_with_tz
 ibp_fb040_sql_decfloat16        =32760, //
 ibp_fb040_sql_decfloat34        =32762, //
};//enum

////////////////////////////////////////////////////////////////////////////////
//BLR data types

enum
{
 ibp_isc_blr_dtype__text         =14  ,
 ibp_isc_blr_dtype__text2        =15  ,
 ibp_isc_blr_dtype__short        =7   ,
 ibp_isc_blr_dtype__long         =8   ,
 ibp_isc_blr_dtype__quad         =9   ,
 ibp_isc_blr_dtype__int64        =16  ,
 ibp_isc_blr_dtype__float        =10  ,
 ibp_isc_blr_dtype__double       =27  ,
 //ibp_isc_blr_dtype__d_float      =11  ,
 ibp_isc_blr_dtype__timestamp    =35  ,
 ibp_isc_blr_dtype__varying      =37  ,
 ibp_isc_blr_dtype__varying2     =38  ,
 ibp_isc_blr_dtype__blob         =261 ,
 ibp_isc_blr_dtype__cstring      =40  ,
 ibp_isc_blr_dtype__cstring2     =41  ,
 ibp_isc_blr_dtype__blob_id      =45  ,
 ibp_isc_blr_dtype__sql_date     =12  ,
 ibp_isc_blr_dtype__sql_time     =13  ,

 ibp_ib070_blr_dtype__bool                 =17  , //t_ibp_ib070_bool

 ibp_fb030_blr_dtype__bool                 =23  , //t_ibp_fb030_bool

 ibp_fb040_blr_dtype__decfloat16           =24  , //
 ibp_fb040_blr_dtype__decfloat34           =25  , //
 ibp_fb040_blr_dtype__int128               =26  , //t_ibp_fb40_int128
 ibp_fb040_blr_dtype__time_with_tz         =28  , //t_ibp_fb040_time_with_tz
 ibp_fb040_blr_dtype__timestamp_with_tz    =29  , //t_ibp_fb040_timestamp_with_tz
};//enum

////////////////////////////////////////////////////////////////////////////////
//BLR codes

enum
{
 ibp_isc_blr_begin               =2,
 ibp_isc_blr_message             =4,

 ibp_isc_blr_version4            =4,
 ibp_isc_blr_version5            =5,
 ibp_isc_blr_eoc                 =76,
 ibp_isc_blr_end                 =255,
};//enum

////////////////////////////////////////////////////////////////////////////////
//internal data type ids

enum
{
 //ibp_isc_internal_dtype__unknown   =0,
 ibp_isc_internal_dtype__text      =1,
 //ibp_isc_internal_dtype__cstring   =2,
 ibp_isc_internal_dtype__varying   =3,

 //ibp_isc_internal_dtype__packed    =6,
 //ibp_isc_internal_dtype__byte      =7,
 ibp_isc_internal_dtype__short     =8,
 ibp_isc_internal_dtype__long      =9,
 //ibp_isc_internal_dtype__quad      =10,
 ibp_isc_internal_dtype__real      =11,
 ibp_isc_internal_dtype__double    =12,
 //ibp_isc_internal_dtype__d_float   =13,
 ibp_isc_internal_dtype__sql_date  =14,
 ibp_isc_internal_dtype__sql_time  =15,
 ibp_isc_internal_dtype__timestamp =16,
 //ibp_isc_internal_dtype__blob      =17,
 //ibp_isc_internal_dtype__array     =18,
 ibp_isc_internal_dtype__int64     =19,
 //ibp_isc_internal_dtype__dbkey     =20,

 ibp_ib070_internal_dtype__bool    =20, //2 bytes

 ibp_fb030_internal_dtype__bool    =21, //1 byte
};

////////////////////////////////////////////////////////////////////////////////
//IB7-boolean data type

using t_ibp_ib070_bool=db_obj::t_dbvalue__bool_i2;

const t_ibp_ib070_bool ibp_ib070_false =db_obj::dbvalue__bool_i2_false;
const t_ibp_ib070_bool ibp_ib070_true  =db_obj::dbvalue__bool_i2_true;

////////////////////////////////////////////////////////////////////////////////
//FB30-boolean data type

using t_ibp_fb030_bool=db_obj::t_dbvalue__bool_i1;

const t_ibp_fb030_bool ibp_fb030_false =db_obj::dbvalue__bool_i1_false;
const t_ibp_fb030_bool ibp_fb030_true  =db_obj::dbvalue__bool_i1_true;

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  Перечисление максимальных длин ISC-типов данных
/// </summary>
enum enum_ibp_isc_max_datatype_length
{
 /// \brief Максимальное количество БАЙТ в CHAR-значении
 ibp_isc_max_char_length                 =32767,

 /// \brief Максимальное количество БАЙТ в VARCHAR-значении
 ibp_isc_max_varchar_length              =32765,

 /// \brief Максимальное количество БАЙТ в CSTRING-значении
 ibp_isc_max_cstring_length              =32767,
};//enum enum_ibp_isc_max_datatype_length

////////////////////////////////////////////////////////////////////////////////

typedef db_obj::t_dbvalue__isc_date         t_ibp_isc_date;
typedef db_obj::t_dbvalue__isc_time         t_ibp_isc_time;

typedef db_obj::t_dbvalue__isc_timestamp    t_ibp_isc_timestamp;

////////////////////////////////////////////////////////////////////////////////

extern const t_ibp_isc_date      __null__isc_date;
extern const t_ibp_isc_time      __null__isc_time;
extern const t_ibp_isc_timestamp __null__isc_timestamp;

////////////////////////////////////////////////////////////////////////////////

using t_ibp_fb040_time_with_tz
 =db_obj::t_dbvalue__fb040_time_with_tz;

using t_ibp_fb040_timestamp_with_tz
 =db_obj::t_dbvalue__fb040_timestamp_with_tz;

////////////////////////////////////////////////////////////////////////////////

using t_ibp_fb040_int128
 =db_obj::t_dbvalue__fb040_int128;

////////////////////////////////////////////////////////////////////////////////

using t_ibp_fb040_decfloat16
 =db_obj::t_dbvalue__fb040_decfloat16;

////////////////////////////////////////////////////////////////////////////////

using t_ibp_fb040_decfloat34
 =db_obj::t_dbvalue__fb040_decfloat34;

////////////////////////////////////////////////////////////////////////////////
//enumerate standart InterBase blob sub-types

enum
{
 /* types less than zero are reserved for customer use */
 ibp_isc_blob_untyped                   =0,

 /* internal subtypes */
 ibp_isc_blob_text                      =1,
 ibp_isc_blob_blr                       =2,
 ibp_isc_blob_acl                       =3,
 ibp_isc_blob_ranges                    =4,
 ibp_isc_blob_summary                   =5,
 ibp_isc_blob_format                    =6,
 ibp_isc_blob_tra                       =7,
 ibp_isc_blob_extfile                   =8,

 /* the range 20-30 is reserved for dBASE and Paradox types */
 ibp_isc_blob_formatted_memo            =20,
 ibp_isc_blob_paradox_ole               =21,
 ibp_isc_blob_graphic                   =22,
 ibp_isc_blob_dbase_ole                 =23,
 ibp_isc_blob_typed_binary              =24,
};//enum

////////////////////////////////////////////////////////////////////////////////
//enumerate subtypes of NUMERIC and DECIMAL data types

enum
{
 ibp_isc_subtype__numeric   =1,
 ibp_isc_subtype__decimal   =2,
};//enum

////////////////////////////////////////////////////////////////////////////////

bool isc_ignore_numeric_scale(long numeric_rules,
                              long sqlscale,
                              long sqlsubtype);

////////////////////////////////////////////////////////////////////////////////

#define ISC_EXPORT_V5                     __stdcall
#define ISC_EXPORT_VARARG_V5              __cdecl

////////////////////////////////////////////////////////////////////////////////

enum
{
 isc_status_vector_size=20
};

typedef long                                 isc_long;
typedef unsigned long                        isc_ulong;

typedef unsigned short                       isc_ushort;
typedef signed short                         isc_sshort;
typedef signed short                         isc_short;
typedef t_ibp_isc_status                     isc_status;

struct isc_status_20
{
 isc_status items[isc_status_vector_size];
};//struct isc_status_20

typedef char                                 isc_char;

//! \todo переименовать и сделать беззнаковым
typedef short                                isc_varchar_size_type;

typedef void*                                isc_blob_handle;
typedef void*                                isc_db_handle;
typedef void*                                isc_stmt_handle;
typedef void*                                isc_tr_handle;

enum
{
 isc_metadatalen_v1      =32,
 isc_metadatalen_v2      =68,
};

enum
{
 isc_max_array_dimensions_v1 =16,
 isc_max_array_dimensions_v2 =16,
};

////////////////////////////////////////////////////////////////////////////////
//Константы выравнивания типов данных в памяти
// - используется в подсистеме RemoteFB

//константа используется для выравнивания блока памяти с данными
const unsigned char ibp_isc_type_align__generic
 =8;

const unsigned char ibp_isc_type_align__short
 =sizeof(db_obj::t_dbvalue__i2);

const unsigned char ibp_isc_type_align__long
 =sizeof(db_obj::t_dbvalue__i4);

const unsigned char ibp_isc_type_align__int64
 =sizeof(db_obj::t_dbvalue__i8);

const unsigned char ibp_isc_type_align__float
 =sizeof(db_obj::t_dbvalue__r4);

const unsigned char ibp_isc_type_align__double
 =sizeof(db_obj::t_dbvalue__r8);

const unsigned char ibp_isc_type_align__time
 =sizeof(t_ibp_isc_time);

const unsigned char ibp_isc_type_align__date
 =sizeof(t_ibp_isc_date);

const unsigned char ibp_isc_type_align__timestamp
 =sizeof(t_ibp_isc_date);

const unsigned char ibp_isc_type_align__text
 =1;

const unsigned char ibp_isc_type_align__varying
 =sizeof(isc_api::isc_varchar_size_type);

const unsigned char ibp_isc_type_align__quad
 =_MEMBER_SIZE_(db_obj::DB_IBQUAD,low);

const unsigned char ibp_fb025_type_align__sql_null
 =1;

const unsigned char ibp_fb030_type_align__bool
 =sizeof(t_ibp_fb030_bool);

const unsigned char ibp_ib070_type_align__bool
 =sizeof(t_ibp_ib070_bool);

const unsigned char ibp_fb040_type_align__timestamp_with_tz
 =sizeof(t_ibp_isc_date);

const unsigned char ibp_fb040_type_align__time_with_tz
 =sizeof(t_ibp_isc_time);

const unsigned char ibp_fb040_type_align__int128
 =sizeof(db_obj::t_dbvalue__i8);

const unsigned char ibp_fb040_type_align__decfloat16
 =sizeof(db_obj::t_dbvalue__i8);   // FB4: sizeof(Firebird::Decimal64)

const unsigned char ibp_fb040_type_align__decfloat34
 =sizeof(db_obj::t_dbvalue__i8);   // FB4: sizeof(Firebird::Decimal64)

////////////////////////////////////////////////////////////////////////////////

struct XSQLDA_V1;
struct XSQLVAR_V1;

struct XSQLDA_V1_EXT;
struct XSQLVAR_V1_EXT;

struct XSQLDA_V2;
struct XSQLVAR_V2;

struct XSQLDA_V2_EXT;
struct XSQLVAR_V2_EXT;

typedef isc_status (ISC_EXPORT_V5 t_isc_attach_database)
 (
  isc_status_20&,
  short,
  const char*,
  isc_db_handle*,
  short,
  const unsigned char*
 );//t_isc_attach_database

typedef isc_status (ISC_EXPORT_V5 t_isc_detach_database)
 (
  isc_status_20&,
  isc_db_handle*
 );//t_isc_detach_database

typedef isc_status (ISC_EXPORT_V5 t_isc_create_database)
 (
  isc_status_20&       status,
  short                db_name_len,
  const char*          db_name,
  isc_db_handle*       db_handle,
  short                dpb_len,
  const unsigned char* dpb,
  short            /*db_type*/
 );//t_isc_create_database

typedef isc_status (ISC_EXPORT_V5 t_isc_drop_database)
 (
  isc_status_20&,
  isc_db_handle*
 );//t_isc_drop_database

typedef isc_status (ISC_EXPORT_V5 t_isc_database_info)
 (
  isc_status_20&,
  isc_db_handle*,
  short,
  const unsigned char*,
  short,
  unsigned char*
 );//t_isc_database_info

typedef void (ISC_EXPORT_V5 t_isc_sql_interprete)
 (
  short,
  char*,
  short
 );//t_isc_sql_interprete

//DONE: просмотреть места использования
typedef isc_long (ISC_EXPORT_V5 t_isc_interprete)
 (
  isc_char*    buf,
  isc_status** status
 );//t_isc_interprete

typedef isc_long (ISC_EXPORT_V5 t_fb_interpret)
 (
  isc_char*     buf,
  unsigned int  bufsize,
  isc_status**  status
 );//t_fb_interpret

typedef isc_status (ISC_EXPORT_VARARG_V5 t_isc_start_transaction)
 (
  isc_status_20&,
  isc_tr_handle*,
  short,
  ...
 );//t_isc_start_transaction

typedef isc_status (ISC_EXPORT_V5 t_isc_prepare_transaction2)
 (
  isc_status_20&,
  isc_tr_handle*,
  isc_ushort,
  const isc_char*
 );

typedef isc_status (ISC_EXPORT_V5 t_isc_commit_retaining)
 (
  isc_status_20&,
  isc_tr_handle*
 );//t_isc_commit_retaining

typedef isc_status (ISC_EXPORT_V5 t_isc_commit_transaction)
 (
  isc_status_20&,
  isc_tr_handle*
 );//t_isc_commit_transaction

typedef isc_status (ISC_EXPORT_V5 t_isc_rollback_retaining)
 (
  isc_status_20&,
  isc_tr_handle*
 );//t_isc_rollback_retaining

typedef isc_status (ISC_EXPORT_V5 t_isc_rollback_transaction)
 (
  isc_status_20&,
  isc_tr_handle*
 );//t_isc_rollback_transaction

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_allocate_statement)
 (
  isc_status_20&,
  isc_db_handle*,
  isc_stmt_handle*
 );//t_isc_dsql_allocate_statement

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_prepare)
 (
  isc_status_20&,
  isc_tr_handle*,
  isc_stmt_handle*,
  unsigned short,
  const char*,
  unsigned short dialect,
  XSQLDA_V1*
 );//t_isc_dsql_prepare

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_prepare_m)
 (
  isc_status_20&,
  isc_tr_handle*,
  isc_stmt_handle *,
  unsigned short,
  const char*,
  unsigned short,
  unsigned short,
  const unsigned char*,
  unsigned short,
  unsigned char*
 );//t_isc_dsql_prepare_m

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_describe)
 (
  isc_status_20&,
  isc_stmt_handle*,
  unsigned short dialect,
  XSQLDA_V1*
 );//t_isc_dsql_describe

typedef t_isc_dsql_describe t_isc_dsql_describe_bind;

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_free_statement)
 (
  isc_status_20&,
  isc_stmt_handle*,
  unsigned short
 );//t_isc_dsql_free_statement

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_execute)
 (
  isc_status_20&,
  isc_tr_handle*,
  isc_stmt_handle*,
  unsigned short,
  const XSQLDA_V1*
 );//t_isc_dsql_execute

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_execute2)
 (
  isc_status_20&,
  isc_tr_handle*,
  isc_stmt_handle*,
  unsigned short,
  const XSQLDA_V1*,
  const XSQLDA_V1*
 );//t_isc_dsql_execute2

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_execute2_m)
 (isc_status_20&,
  isc_tr_handle*,
  isc_stmt_handle*,
  unsigned short       inBlrLength,
  const unsigned char* inBlr,
  unsigned short       inMsgType,
  unsigned short       inMsgLength,
  const unsigned char* inMsg,
  unsigned short       outBlrLength,
  const unsigned char* outBlr,
  unsigned short       outMsgType,
  unsigned short       outMsgLength,
  unsigned char*       outMsg
 );//t_isc_dsql_execute2_m

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_execute_immediate)
 (
  isc_status_20&   status,
  isc_db_handle*   db_handle,
  isc_tr_handle*   tra_handle,
  unsigned short   length,
  char*            string,
  unsigned short   dialect,
  const XSQLDA_V1* xsqlda
 );//t_isc_dsql_execute_immediate

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_exec_immed3_m)
 (
  isc_status_20& status,
  isc_db_handle* db_handle,
  isc_tr_handle* tra_handle,
  isc_ushort     length,
  const char*    string,
  isc_ushort     dialect,
  isc_ushort     in_blr_length,
  char*          in_blr,
  isc_ushort     in_msg_type,
  isc_ushort     in_msg_length,
  const char*    in_msg,
  isc_ushort     out_blr_length,
  char*          out_blr,
  isc_ushort     out_msg_type,
  isc_ushort     out_msg_length,
  char*          out_msg
 );//isc_dsql_exec_immed3_m

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_fetch)
 (
  isc_status_20&,
  isc_stmt_handle*,
  unsigned short,
  const XSQLDA_V1*
 );//t_isc_dsql_fetch

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_fetch_m)
 (
  isc_status_20&,
  isc_stmt_handle*, 
  unsigned short       blrLength, 
  const unsigned char* blr, 
  unsigned short       msgType, 
  unsigned short       msgLength, 
  unsigned char*       msg
 );//t_isc_dsql_fetch_m

typedef isc_status (ISC_EXPORT_V5 t_isc_dsql_sql_info)
 (
  isc_status_20&,
  isc_stmt_handle*,
  short,
  const unsigned char*,
  short,
  unsigned char*
 );//t_isc_dsql_sql_info

typedef isc_status (ISC_EXPORT_V5 t_isc_create_blob2)
 (
  isc_status_20&       status,
  isc_db_handle*       db_handle,
  isc_tr_handle*       tr_handle,
  isc_blob_handle*     blob_handle,
  db_obj::DB_IBBLOBID* blob_id,
  short                bpb_size,
  const unsigned char* bpb
 );//t_isc_create_blob2

typedef isc_status (ISC_EXPORT_V5 t_isc_open_blob2)
 (
  isc_status_20&,
  isc_db_handle*,
  isc_tr_handle*,
  isc_blob_handle*,
  const db_obj::DB_IBBLOBID*,
  short,
  const unsigned char*
 );//t_isc_open_blob2

typedef isc_status (ISC_EXPORT_V5 t_isc_close_blob)
 (
  isc_status_20&,
  isc_blob_handle*
 );//t_isc_close_blob

typedef isc_status (ISC_EXPORT_V5 t_isc_put_segment)
 (
  isc_status_20&,
  isc_blob_handle*,
  unsigned short,
  const void*
 );//t_isc_put_segment

typedef isc_status (ISC_EXPORT_V5 t_isc_get_segment)
 (
  isc_status_20&,
  isc_blob_handle*,
  unsigned short*,
  unsigned short,
  void*
 );//t_isc_get_segment

typedef isc_status (ISC_EXPORT_V5 t_isc_cancel_blob)
 (
  isc_status_20&,
  isc_blob_handle*
 );//t_isc_cancel_blob

typedef isc_status (ISC_EXPORT_V5 t_isc_blob_info)
 (
  isc_status_20&,
  isc_blob_handle*,
  short,
  const unsigned char*,
  short,
  unsigned char*
 );//t_isc_blob_info

typedef isc_status (ISC_EXPORT_V5 t_isc_put_slice)
 (isc_status_20&        user_status,
  isc_db_handle*        db_handle,
  isc_tr_handle*        tra_handle,
  db_obj::DB_IBARRAYID* array_id,
  isc_short             sdl_length,
  const unsigned char*  sdl,
  short                 param_length,
  isc_long*             param,
  isc_long              slice_length,
  const void*           slice);

typedef isc_status (ISC_EXPORT_V5 t_isc_get_slice)
 (isc_status_20&               user_status,
  isc_db_handle*               db_handle,
  isc_tr_handle*               tra_handle,
  const db_obj::DB_IBARRAYID*  array_id,
  isc_short                    sdl_length,
  const unsigned char*         sdl,
  short                        param_length,
  const isc_long*              param,
  isc_long                     slice_length,
  void*                        slice,
  isc_long*                    return_length);

 typedef void (t_isc_print_blr_callback)
 (
  void*        user_arg,
  isc_short    offset,
  const char*  str
 );//t_isc_print_blr_callback

typedef isc_status (ISC_EXPORT_V5 t_isc_print_blr)
 (
  const isc_char*,
  t_isc_print_blr_callback*,
  void*,
  short
 );//t_isc_print_blr

//FB API ---------------------------------------------------------------
typedef isc_status (ISC_EXPORT_V5 t_fb_cancel_operation)
 (
  isc_status_20& status_vector,
  isc_db_handle* db_handle,
  isc_ushort     option
 );//t_fb_cancel_operation

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V1

/// <summary>
///  Структура для определения значений колонок/параметров
/// </summary>
struct XSQLVAR_V1
{
 public: //typedefs ------------------------------------------------------
  typedef short                   sqltype_type;
  typedef short                   sqlsubtype_type;
  typedef short                   sqlscale_type;
  typedef short                   sqllen_type;

 private:
  static const sqltype_type c_sqltype_null_flag=1;
  static const sqltype_type c_sqltype_id_mask  =(sqltype_type)~c_sqltype_null_flag;

 public: //---------------------------------------------------------------
  //! Datatype of field
  sqltype_type        sqltype;

  //! Scale factor
  sqlscale_type       sqlscale;

  //! Datatype subtype - BLOBs & Text types only
  sqlsubtype_type     sqlsubtype;

  //! Length of data area
  sqllen_type         sqllen;

  //! Address of data
  char*  sqldata;

  //! Address of indicator variable
  short* sqlind;

  //! Length of sqlname field
  short  sqlname_length;

  //! Name of field, name length + space for NULL
  char   sqlname [isc_metadatalen_v1];

  //! Length of relation name
  short  relname_length;

  //! Field's relation name + space for NULL
  char   relname [isc_metadatalen_v1];

  //! Length of owner name
  short  ownname_length;

  //! Relation's owner name + space for NULL
  char   ownname [isc_metadatalen_v1];

  //! Length of alias name
  short  aliasname_length;

  //! Relation's alias name + space for NULL
  char   aliasname [isc_metadatalen_v1];

 public:
  //! \brief Псевдоним дескриптора константной строки
  typedef structure::t_const_str_box        name_box_type;

  //! \brief Получение имени таблицы в виде дескриптора
  name_box_type get_xsqlvar_relname_box()const;

  //! \brief Получение имени колонки в виде дескриптора
  name_box_type get_xsqlvar_sqlname_box()const;

  //! \brief Получение имени псевдонима в виде дескриптора
  name_box_type get_xsqlvar_aliasname_box()const;

 public:
  //! \brief Получение идентификатора типа.
  sqltype_type get_typeID()const;

  //! \brief Тестирование возможности установки NULL-значения
  bool get_value_may_be_null()const;

  void set_value_may_be_null();

 public:
  //! \brief Тестирование наличия NULL-значения
  bool get_value_is_null__std()const;

 public:
  //! \brief установка null-состояния значения. стандартная версия
  //! \param[in] nullState
  void set_value_null_state__std(bool nullState);
};//struct XSQLVAR_V1

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V1

/// <summary>
///  Структура для описания набора колонок/параметров
/// </summary>
struct XSQLDA_V1
{
 public: //typedefs ------------------------------------------------------
  typedef short                             count_type;

 public:
  //! Номер версии структуры.
  static const short c_version_num=1;

 public:
  //! Version of this XSQLDA==1
  short      version;

  //! XSQLDA name field
  char       sqldaid [8];

  //! Length in bytes of SQLDA
  isc_long   sqldabc;

  //! Number of fields allocated
  count_type sqln;

  //! Actual number of fields
  count_type sqld;

  //! First field address
  XSQLVAR_V1 sqlvar[1];

 public:
  static size_t LENGTH(size_t n);
};//XSQLDA_V1

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V1_EXT

/// <summary>
///  Дополнительное описание колонки
/// </summary>
struct XSQLVAR_V1_EXT
{
 public: //typedefs ------------------------------------------------------
  typedef XSQLVAR_V1::sqltype_type       sqltype_type;
  typedef XSQLVAR_V1::sqlsubtype_type    sqlsubtype_type;
  typedef XSQLVAR_V1::sqlscale_type      sqlscale_type;
  typedef XSQLVAR_V1::sqllen_type        sqllen_type;

 public:
  //! Datatype of field
  sqltype_type        original__sqltype;

  //! Scale factor
  sqlscale_type       original__sqlscale;

  //! Datatype subtype - BLOBs & Text types only
  sqlsubtype_type     original__sqlsubtype;

  //! Length of data area
  sqllen_type         original__sqllen;

 public:
  ///Длина имени кодовой страницы данных
  unsigned short sqldata_charsetname_length;

  ///Имя кодовой страницы данных
  wchar_t        sqldata_charsetname[isc_metadatalen_v1];

  ///Длина имени базовой кодовой страницы
  unsigned short base_charsetname_length;

  ///Имя базовой кодовой страницы
  wchar_t        base_charsetname[isc_metadatalen_v1];

 public:
  //! \brief Получение идентификатора кодовой страницы. Только для CHAR/VARCHAR.
  long original__get_char_codepageID()const;

  //! \brief Получение идентификатора кодовой страницы. Только для BLOB [Firebird 2.1+].
  long original__get_blob_codepageID__fb021()const;

  //! \brief Получение идентификатора типа.
  sqltype_type original__get_typeID()const;

  //! \brief Тестирование возможности установки NULL-значения
  bool original__value_may_be_null()const;

 public:
  //! \brief Псевдоним дескриптора константной строки
  typedef structure::t_const_wstr_box       name_box_type;

  /// <summary>
  ///  Получение имени кодовой страницы данных, упакованного в StrBox
  /// </summary>
  name_box_type get_xsqlvar_sqldata_charsetname_box()const;

  /// <summary>
  ///  Получение имени базовой кодовой страницы, упакованного в StrBox
  /// </summary>
  name_box_type get_xsqlvar_base_charsetname_box()const;

 public:
  /// <summary>
  ///  Копирование оригинального описания типа
  /// </summary>
  //! \param[in] xsqlvar
  void set_original_fields(const XSQLVAR_V1& xsqlvar);
};//struct XSQLVAR_V1_EXT

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V1_EXT

/// <summary>
///  Дополнительное описание набора колонок
/// </summary>
struct XSQLDA_V1_EXT
{
 public:
  XSQLVAR_V1_EXT  sqlvar[1];

 public:
  static size_t LENGTH(size_t n);
};//struct XSQLDA_V1_EXT

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V2

/// <summary>
///  Структура для определения значений колонок/параметров
/// </summary>
struct XSQLVAR_V2
{
 public: //typedefs ------------------------------------------------------
  typedef short                   sqltype_type;
  typedef short                   sqlsubtype_type;
  typedef short                   sqlscale_type;
  typedef short                   sqllen_type;

 private:
  static const sqltype_type c_sqltype_null_flag=1;
  static const sqltype_type c_sqltype_id_mask  =(sqltype_type)~c_sqltype_null_flag;

 public:
  //! datatype of field
  sqltype_type     sqltype;

  //! scale factor
  sqlscale_type    sqlscale;

  //! precision : Reserved for future
  short            sqlprecision;

  //! datatype subtype
  sqlsubtype_type  sqlsubtype;

  //! length of data area
  sqllen_type      sqllen;

  //! address of data
  char*            sqldata;

  //! address of indicator variable
  short*           sqlind;

  //! length of sqlname field
  short            sqlname_length;

  //! name of field, name length + space for NULL
  char             sqlname[isc_metadatalen_v2];

  //! length of relation name
  short            relname_length;

  //! field's relation name + space for NULL
  char             relname[isc_metadatalen_v2];

  //! length of owner name
  short            ownname_length;

  //! relation's owner name + space for NULL
  char             ownname[isc_metadatalen_v2];

  //! length of alias name
  short            aliasname_length;

  //! relation's alias name + space for NULL
  char             aliasname[isc_metadatalen_v2];

 public:
  //! \brief Псевдоним дескриптора константной строки
  typedef structure::t_const_str_box        name_box_type;

  //! \brief Получение имени таблицы в виде дескриптора
  name_box_type get_xsqlvar_relname_box()const;

  //! \brief Получение имени колонки в виде дескриптора
  name_box_type get_xsqlvar_sqlname_box()const;

  //! \brief Получение имени псевдонима в виде дескриптора
  name_box_type get_xsqlvar_aliasname_box()const;

 public:
  //! \brief Получение идентификатора типа.
  sqltype_type get_typeID()const;

  //! \brief Тестирование возможности установки NULL-значения
  bool get_value_may_be_null()const;

  void set_value_may_be_null();

 public:
  //! \brief Тестирование наличия NULL-значения
  bool get_value_is_null__std()const;

  //! \brief установка null-состояния значения. стандартная версия
  //! \param[in] nullState
  void set_value_null_state__std(bool nullState);
};//struct XSQLVAR_V2

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V1

/// <summary>
///  Структура для описания набора колонок/параметров
/// </summary>
struct XSQLDA_V2
{
 public: //typedefs ------------------------------------------------------
  typedef short                             count_type;

 public:
  //! Номер версии структуры.
  static const short c_version_num=2;

 public:
  //! Version of this XSQLDA==2
  short      version;

  //! XSQLDA name field
  char       sqldaid [8];

  //! Length in bytes of SQLDA
  isc_long   sqldabc;

  //! Number of fields allocated
  count_type sqln;

  //! Actual number of fields
  count_type sqld;

  //! First field address
  XSQLVAR_V2 sqlvar[1];

 public:
  static size_t LENGTH(size_t n);
};//XSQLDA_V2

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V2_EXT

/// <summary>
///  Дополнительное описание колонки
/// </summary>
struct XSQLVAR_V2_EXT
{
 public: //typedefs ------------------------------------------------------
  typedef XSQLVAR_V2::sqltype_type          sqltype_type;
  typedef XSQLVAR_V2::sqlsubtype_type       sqlsubtype_type;
  typedef XSQLVAR_V2::sqlscale_type         sqlscale_type;
  typedef XSQLVAR_V2::sqllen_type           sqllen_type;

 public:
  //! datatype of field
  sqltype_type     original__sqltype;

  //! scale factor
  sqlscale_type    original__sqlscale;

  //! precision : Reserved for future
  short            original__sqlprecision;

  //! datatype subtype
  sqlsubtype_type  original__sqlsubtype;

  //! length of data area
  sqllen_type      original__sqllen;

 public:
  ///Длина имени кодовой страницы данных
  unsigned short sqldata_charsetname_length;

  ///Имя кодовой страницы данных
  wchar_t        sqldata_charsetname[isc_metadatalen_v2];

  ///Длина имени базовой кодовой страницы
  unsigned short base_charsetname_length;

  ///Имя базовой кодовой страницы
  wchar_t        base_charsetname[isc_metadatalen_v2];

 public:
  //! \brief Получение идентификатора кодовой страницы. Только для CHAR/VARCHAR.
  long original__get_char_codepageID()const;

  //! \brief Получение идентификатора типа.
  sqltype_type original__get_typeID()const;

  //! \brief Тестирование возможности установки NULL-значения
  bool original__value_may_be_null()const;

 public:
  //! \brief Псевдоним дескриптора константной строки
  typedef structure::t_const_wstr_box       name_box_type;

  /// <summary>
  ///  Получение имени кодовой страницы данных, упакованного в StrBox
  /// </summary>
  name_box_type get_xsqlvar_sqldata_charsetname_box()const;

  /// <summary>
  ///  Получение имени базовой кодовой страницы, упакованного в StrBox
  /// </summary>
  name_box_type get_xsqlvar_base_charsetname_box()const;

 public:
  /// <summary>
  ///  Копирование оригинального описания типа
  /// </summary>
  //! \param[in] xsqlvar
  void set_original_fields(const XSQLVAR_V2& xsqlvar);
};//struct XSQLVAR_V2_EXT

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V2_EXT

/// <summary>
///  Дополнительное описание набора колонок
/// </summary>
struct XSQLDA_V2_EXT
{
 public:
  XSQLVAR_V2_EXT  sqlvar[1];

 public:
  static size_t LENGTH(size_t n);
};//struct XSQLDA_V2_EXT

////////////////////////////////////////////////////////////////////////////////
#undef ISC_EXPORT_V5
#undef ISC_EXPORT_VARARG_V5

////////////////////////////////////////////////////////////////////////////////
//struct INTERNAL_ARRAY_DESCR_V1

//16+24=40
struct INTERNAL_ARRAY_DESCR_V1
{
 public:
  static const db_obj::t_dbvalue__ui1 c_version_id=1;

  //12 байт
  struct tag_iad_descriptor
  {
   public:
    db_obj::t_dbvalue__ui1  dsc_internal_dtype;
    db_obj::t_dbvalue__i1   dsc_scale;
    db_obj::t_dbvalue__ui2  dsc_length;
    db_obj::t_dbvalue__i2   dsc_sub_type;
    db_obj::t_dbvalue__ui2  dsc_flags;
    db_obj::t_dbvalue__ui4  dsc_offset;

    //! \brief Получение идентификатора кодовой страницы. Только для CHAR/VARCHAR.
    long get_char_codepageID()const;
  };//struct tag_iad_descriptor

  //12+12=24 байта
  struct tag_iad_repeat
  {
   tag_iad_descriptor    iad_desc;          // Element descriptor
   db_obj::t_dbvalue__i4 iad_length;        // Length of "vector" element
   db_obj::t_dbvalue__i4 iad_lower;         // Lower bound
   db_obj::t_dbvalue__i4 iad_upper;         // Upper bound
  };//struct tag_iad_repeat

 public:
  db_obj::t_dbvalue__ui1  iad_version;        // Array descriptor version number
  db_obj::t_dbvalue__ui1  iad_dimensions;     // Dimensions of array
  db_obj::t_dbvalue__ui2  iad_struct_count;   // Number of struct elements
  db_obj::t_dbvalue__ui2  iad_element_length; // Length of array element
  db_obj::t_dbvalue__ui2  iad_length;         // Length of array descriptor
  db_obj::t_dbvalue__i4   iad_count;          // Total number of elements
  db_obj::t_dbvalue__i4   iad_total_length;   // Total length of array

  tag_iad_repeat iad_rpt[1];
};//struct INTERNAL_ARRAY_DESCR_V1

////////////////////////////////////////////////////////////////////////////////
//inline implementation

inline XSQLVAR_V1::sqltype_type XSQLVAR_V1::get_typeID()const
{
 return this->sqltype&c_sqltype_id_mask;
}//get_typeID

//------------------------------------------------------------------------
inline bool XSQLVAR_V1::get_value_may_be_null()const
{
 return (this->sqltype&c_sqltype_null_flag)!=0;
}//get_value_may_be_null

//------------------------------------------------------------------------
inline void XSQLVAR_V1::set_value_may_be_null()
{
 this->sqltype|=c_sqltype_null_flag;
}//set_value_may_be_null

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V1

inline size_t XSQLDA_V1::LENGTH(size_t const n)
{
 return n?(sizeof(XSQLDA_V1)+(n-1)*sizeof(XSQLVAR_V1)):0;
}//LENGTH

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V1_EXT

inline long XSQLVAR_V1_EXT::original__get_char_codepageID()const
{
 ///Идентификатор кодовой страницы хранится в младшем байте sqlsubtype

 const unsigned char id=static_cast<unsigned char>(this->original__sqlsubtype&0xFF);

 return static_cast<long>(id);
}//original__get_char_codepageID

//------------------------------------------------------------------------
inline long XSQLVAR_V1_EXT::original__get_blob_codepageID__fb021()const
{
 ///Идентификатор кодовой страницы хранится в младшем байте sqlscale

 const unsigned char id=static_cast<unsigned char>(this->original__sqlscale&0xFF);

 return static_cast<long>(id);
}//original__get_blob_codepageID__fb021

//------------------------------------------------------------------------
inline XSQLVAR_V1_EXT::sqltype_type XSQLVAR_V1_EXT::original__get_typeID()const
{
 return static_cast<sqltype_type>(this->original__sqltype-(this->original__sqltype%2));
}//original__get_typeID

//------------------------------------------------------------------------
inline bool XSQLVAR_V1_EXT::original__value_may_be_null()const
{
 return (this->original__sqltype%2)!=0;
}//original__value_may_be_null

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V1_EXT

inline size_t XSQLDA_V1_EXT::LENGTH(size_t const n)
{
 return n?(sizeof(XSQLDA_V1_EXT)+(n-1)*sizeof(XSQLVAR_V1_EXT)):0;
}//LENGTH

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V2

inline XSQLVAR_V2::sqltype_type XSQLVAR_V2::get_typeID()const
{
 return this->sqltype&c_sqltype_id_mask;
}//get_typeID

//------------------------------------------------------------------------
inline bool XSQLVAR_V2::get_value_may_be_null()const
{
 return (this->sqltype&c_sqltype_null_flag)!=0;
}//get_value_may_be_null

//------------------------------------------------------------------------
inline void XSQLVAR_V2::set_value_may_be_null()
{
 this->sqltype|=c_sqltype_null_flag;
}//set_value_may_be_null

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V2

inline size_t XSQLDA_V2::LENGTH(size_t n)
{
 return n?(sizeof(XSQLDA_V2)+(n-1)*sizeof(XSQLVAR_V2)):0;
}//LENGTH

////////////////////////////////////////////////////////////////////////////////
//struct XSQLVAR_V2_EXT

inline long XSQLVAR_V2_EXT::original__get_char_codepageID()const
{
 ///Идентификатор кодовой страницы хранится в младшем байте sqlsubtype
 const unsigned char id=static_cast<unsigned char>(this->original__sqlsubtype&0xFF);

 return static_cast<long>(id);
}//original__get_char_codepageID

//------------------------------------------------------------------------
inline XSQLVAR_V2_EXT::sqltype_type XSQLVAR_V2_EXT::original__get_typeID()const
{
 return static_cast<sqltype_type>(this->original__sqltype-(this->original__sqltype%2));
}//original__get_typeID

//------------------------------------------------------------------------
inline bool XSQLVAR_V2_EXT::original__value_may_be_null()const
{
 return (this->original__sqltype%2)!=0;
}//original__value_may_be_null

////////////////////////////////////////////////////////////////////////////////
//struct XSQLDA_V2_EXT

inline size_t XSQLDA_V2_EXT::LENGTH(size_t const n)
{
 return n?(sizeof(XSQLDA_V2_EXT)+(n-1)*sizeof(XSQLVAR_V2_EXT)):0;
}//LENGTH

////////////////////////////////////////////////////////////////////////////////

inline long INTERNAL_ARRAY_DESCR_V1::tag_iad_descriptor::get_char_codepageID()const
{
 ///Идентификатор кодовой страницы хранится в младшем байте dsc_sub_type

 const unsigned char id=static_cast<unsigned char>(this->dsc_sub_type&0xFF);

 return static_cast<long>(id);
}//get_char_codepageID

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_api*/}/*nms ibp*/}/*nms lcpi*/
#endif
