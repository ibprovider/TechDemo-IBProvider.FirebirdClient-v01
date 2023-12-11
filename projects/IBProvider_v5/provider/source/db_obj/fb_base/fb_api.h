////////////////////////////////////////////////////////////////////////////////
//! \ingroup fb_api
//! \file    fb_api.h
//! \brief   Firebird. Определение конструкций общих для всех версий Firebird
//! \author  Kovalenko Dmitry
//! \date    15.05.2006
#ifndef _fb_api_H_
#define _fb_api_H_

#include <structure/t_common.h>

namespace lcpi{namespace ibp{namespace fb_api{
//////////////////////////////////////////////////////////////////////////
//! \addtogroup fb_api
//! @{
//////////////////////////////////////////////////////////////////////////
//Database parameter block stuff

enum
{
 ibp_frb_dbp_version1                   = 1,
 ibp_frb_dbp_version2                   = 2, //FB3

 //Firebird 2.1
 ibp_frb_dpb_process_id                 = 71,
 ibp_frb_dpb_no_db_triggers             = 72,
 ibp_frb_dpb_trusted_auth               = 73,
 ibp_frb_dpb_process_name               = 74,

 //Firebird 2.5
 ibp_frb_dpb_utf8_filename              = 77,

 //Firebird 3.0
 ibp_frb_dpb_auth_block                 = 79,
 ibp_frb_dpb_client_version             = 80,
 ibp_frb_dpb_remote_protocol            = 81,
 ibp_frb_dpb_host_name                  = 82,
 ibp_frb_dpb_os_user                    = 83,
 ibp_frb_dpb_specific_auth_data         = 84,
 ibp_frb_dpb_auth_plugin_list           = 85,
 ibp_frb_dpb_auth_plugin_name           = 86,
 ibp_frb_dpb_config                     = 87,
 ibp_frb_dpb_nolinger                   = 88,
 ibp_frb_dpb_reset_icu                  = 89,
 ibp_frb_dpb_map_attach                 = 90,
};//enum

////////////////////////////////////////////////////////////////////////////////
//Connection crypt

enum
{
 ibp_frb_wire_crypt__disabled           = 0,
 ibp_frb_wire_crypt__enabled            = 1,
 ibp_frb_wire_crypt__required           = 2,
};

////////////////////////////////////////////////////////////////////////////////
//Database information items

enum
{
 //firebird 1.5
 ibp_frb_info_att_charset               = 101,
 ibp_frb_info_db_class                  = 102,
 ibp_frb_info_firebird_version          = 103,
 ibp_frb_info_oldest_transaction        = 104,
 ibp_frb_info_oldest_active             = 105,
 ibp_frb_info_oldest_snapshot           = 106,
 ibp_frb_info_next_transaction          = 107,
 ibp_frb_info_db_provider               = 108,
 ibp_frb_info_active_transactions       = 109,

 //firebird 2.0
 ibp_frb_info_active_tran_count         = 110,
 ibp_frb_info_creation_date             = 111,
};//enum

////////////////////////////////////////////////////////////////////////////////
//Procedure parameter mechanism

enum
{
 //firebird 2.1
 ibp_fb_prm_mech_normal    = 0,
 ibp_fb_prm_mech_type_of   = 1,
};//enum

////////////////////////////////////////////////////////////////////////////////
//UDF argument mechanism

// Parameter passing mechanism for UDFs.
// Also used for returning values, except for scalar_array.

// enum FUN_T
// {
//  FUN_value,
//  FUN_reference,
//  FUN_descriptor,
//  FUN_blob_struct,
//  FUN_scalar_array,
//  FUN_ref_with_null
// };

enum
{
 ibp_fb_udf_arg_mech__by_value                       = 0, //IB4
 ibp_fb_udf_arg_mech__by_reference                   = 1, //IB4
 ibp_fb_udf_arg_mech__by_vms_description             = 2, //IB4? [есть в IB6]
 ibp_fb_udf_arg_mech__by_blob_struct                 = 3, //IB4
 ibp_fb_udf_arg_mech__by_scalar_array_description    = 4, //IB4? [есть в IB6]

 ibp_fb_udf_arg_mech__by_reference_with_null         = 5, //FB2.0
};//enum

////////////////////////////////////////////////////////////////////////////////

enum
{
 ibp_fb_cancel_disable                =1,
 ibp_fb_cancel_enable                 =2,
 ibp_fb_cancel_raise                  =3,
 ibp_fb_cancel_abort                  =4,
};//enum

////////////////////////////////////////////////////////////////////////////////

enum
{
 //процедура возвращает множество рядов (содержит SUSPEND).
 ibp_fb_proc_type__selectable =1,

 //процедура возвращает OUT-параметры.
 ibp_fb_proc_type__executable =2,
};

////////////////////////////////////////////////////////////////////////////////

enum
{
 ibp_fb_info_sql_stmt_select          =1,
 ibp_fb_info_sql_stmt_insert          =2,
 ibp_fb_info_sql_stmt_update          =3,
 ibp_fb_info_sql_stmt_delete          =4,
 ibp_fb_info_sql_stmt_ddl             =5,
 ibp_fb_info_sql_stmt_get_segment     =6,
 ibp_fb_info_sql_stmt_put_segment     =7,
 ibp_fb_info_sql_stmt_exec_procedure  =8,
 ibp_fb_info_sql_stmt_start_trans     =9,
 ibp_fb_info_sql_stmt_commit          =10,
 ibp_fb_info_sql_stmt_rollback        =11,
 ibp_fb_info_sql_stmt_select_for_upd  =12,
 ibp_fb_info_sql_stmt_set_generator   =13,

 /*Firebird 1.5*/
 ibp_fb_info_sql_stmt_savepoint       =14,
};//enum

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms fb_api*/}/*nms ibp*/}/*nms lcpi*/
#endif
