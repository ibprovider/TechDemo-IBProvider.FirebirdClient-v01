////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_obj
//! \file    db_base.h
//! \brief   Forward-определение базовых конструкции, используемых при определения
//!          классов взаимодействия с базами данных.
//! \author  Kovalenko Dmitry
//! \date    26.04.2003
#ifndef _db_base_H_
#define _db_base_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error.h"
//#include "source/db_obj/db_memory.h"
#include "source/db_obj/db_svc.h"
#include "source/ibp_char.h"
//#include <structure/t_value_with_null.h>

namespace lcpi{namespace ibp{namespace db_obj{
////////////////////////////////////////////////////////////////////////////////

#define IBP_DEF_FWRD_DB_INTERFACE(interface_type)                           \
 class interface_type;                                                      \
                                                                            \
 typedef structure::t_smart_object_ptr<interface_type>                      \
  interface_type##_ptr;                                                     \
                                                                            \
 typedef structure::t_smart_object_ptr<const interface_type>                \
  interface_type##_const_ptr;

#define IBP_DEF_FWRD_DB_INTERFACE_EX(interface_type)                        \
 extern const GUID interface_type##_guid;                                   \
                                                                            \
 IBP_DEF_FWRD_DB_INTERFACE(interface_type)

////////////////////////////////////////////////////////////////////////////////

//макрос для использования в глобальном пространстве имен
#define IBP_DEF_DB_INTERFACE_ID(interface_type)                                 \
template<>                                                                      \
inline REFGUID LCPI_IBP_NMS::db_obj::__db_guid<LCPI_IBP_NMS::interface_type>()  \
{                                                                               \
 return LCPI_IBP_NMS::interface_type##_guid;                                    \
}

////////////////////////////////////////////////////////////////////////////////
//forward declaration

//db guard ---------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_guard)

//db lock guard ----------------------------------------------------------
class t_db_lock_guard;

//db guard RW ------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_guard_rw)

//object name ------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_object_name_ex)

//object property values snapshot ----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_property_values_snapshot)

//db provider ------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_provider)

//db service provider ----------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_service_provider)

//db services container --------------------------------------------------
class t_db_service_container__simple;

//db services manager ----------------------------------------------------
class t_db_service_manager_impl; //internal class

//db connection ----------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_connection)

//db transaction ---------------------------------------------------------

class t_db_transaction_params;

IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_transaction)

//db transaction node ----------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_transaction_node)

//db transaction sql reflex ----------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_transaction_sql_reflex)

//db transaction connection point ----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_transaction_cp)

class t_db_transaction_cp_data;

//db statement -----------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_statement)

//db result set ----------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_result_set)

//db value ---------------------------------------------------------------
struct t_db_value_data;
struct t_db_value;

//db column description --------------------------------------------------
class t_db_column_descr;

//column accessors -------------------------------------------------------
class t_db_field_accessor;

class t_db_field_accessor_rw;

//db row -----------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_row)

//db row factory ---------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_row_factory)

//db row data ------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_row_data)

//db row data map --------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_row_data_map)

//segment writer object --------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_seq_stream_writer)

//blob writer object -----------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_blob_writer)

//sequential stream reader object ----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_seq_stream_reader)

//blob reader object -----------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_blob_reader)

//array descr object -----------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_array_descr)

//array object -----------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_array)

//charset objects --------------------------------------------------------
class t_db_charset_info;

typedef structure::t_value_with_null<t_db_charset_info> t_db_charset_info_n;

IBP_DEF_FWRD_DB_INTERFACE(t_db_charset)

IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_charset_manager_v2)

IBP_DEF_FWRD_DB_INTERFACE(t_db_text_stream__mbc)

IBP_DEF_FWRD_DB_INTERFACE(t_db_text_stream__ucs2)

//services for retriver data-source informations -------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_info__get_literal_info)

IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_info__get_sql_keywords)

//parameter info builder -------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_param_info_builder)

//text services object ---------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_text_services)

//name services object ---------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_name_services)

//идентификатор сервиса имен для клиентских операций
extern const db_obj::t_db_svc_descr
 db_svc_descr__name_services__for_client;

//идентификатор сервиса имен для метаданных базы данных
extern const db_obj::t_db_svc_descr
 db_svc_descr__name_services__for_database;

//prepare services object ------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_prepare_services)

//blob services object ---------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_blob_services)

//------------------------------------------------------------------------

class t_db_meta_data_restriction;

class t_db_meta_data_restrictions;

//meta schema loader -----------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_schema_loader)

//meta data information services -----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_data_reader)

//execute trigger interface ----------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_exec_trigger)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_meta_svc__sp_info)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_svc__get_sp_info)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_svc__get_sp_in_param_names)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_svc__get_table_pkey_columns)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_svc__detect_autoinc_columns)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_svc__get_table_updatable_columns)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_svc__columns_rowset)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_meta_svc__meta_data_cache)

//unique identificator generator -----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_svc__gen_id)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_svc__timezone_names)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_svc__ts_with_tz_services)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_svc__timezone_services)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_svc__fb040_ts_with_tz_services)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_svc__fb040_tz_names)

//------------------------------------------------------------------------
#if(IBP_ENGINE_UPDATE_ROWSET!=0)

IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_pstmt_svc__sql_generator__for_insert)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_pstmt_svc__sql_generator__for_delete)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_pstmt_svc__sql_generator__for_update)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_db_pstmt_svc__sql_generator__for_refresh)

#endif //IBP_ENGINE_UPDATE_ROWSET!=0

//t_db_exec_triggers interface -------------------------------------------
class t_db_exec_triggers;

//operation context ------------------------------------------------------
class t_db_operation_context;

//database operation -----------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_db_operation)

//------------------------------------------------------------------------

IBP_DEF_FWRD_DB_INTERFACE(t_db_platform__datatype_encoders)

//идентификатор сервиса для упаковки типов данных В формат платформы СЕРВЕРА
extern const t_db_svc_descr
 db_svc_descr__datatype_encoders_to_server_platform;

//------------------------------------------------------------------------

IBP_DEF_FWRD_DB_INTERFACE(t_db_platform__datatype_decoders)

//идентификатор сервиса для распаковки типов данных ИЗ формата платформы СЕРВЕРА
extern const t_db_svc_descr
 db_svc_descr__datatype_decoders_from_server_platform;

////////////////////////////////////////////////////////////////////////////////
}/*nms db_obj*/}/*nms ibp*/}/*nms lcpi*/

////////////////////////////////////////////////////////////////////////////////

IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_transaction)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_row_factory)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_info__get_literal_info)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_info__get_sql_keywords)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_param_info_builder)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_text_services)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_prepare_services)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_blob_services)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_data_reader)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_charset_manager_v2)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_svc__get_sp_info)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_svc__get_sp_in_param_names)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_svc__get_table_pkey_columns)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_svc__detect_autoinc_columns)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_svc__get_table_updatable_columns)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_svc__columns_rowset)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_meta_svc__meta_data_cache)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_svc__gen_id)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_svc__timezone_names)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_svc__ts_with_tz_services)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_svc__timezone_services)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_svc__fb040_ts_with_tz_services)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_svc__fb040_tz_names)

#if(IBP_ENGINE_UPDATE_ROWSET!=0)

IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_pstmt_svc__sql_generator__for_insert)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_pstmt_svc__sql_generator__for_delete)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_pstmt_svc__sql_generator__for_update)
IBP_DEF_DB_INTERFACE_ID(db_obj::t_db_pstmt_svc__sql_generator__for_refresh)

#endif

////////////////////////////////////////////////////////////////////////////////
#endif
