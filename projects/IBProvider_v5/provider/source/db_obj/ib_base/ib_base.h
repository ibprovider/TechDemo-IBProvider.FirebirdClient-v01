////////////////////////////////////////////////////////////////////////////////
//! \ingroup ib_base
//! \file    ib_base.h
//! \brief   Forward-объявления конструкций, общих для всех версий InterBase
//! \author  Kovalenko Dmitry
//! \date    12.02.2004
#ifndef _ib_base_H_
#define _ib_base_H_

#include "source/db_obj/isc_base/isc_base.h"

namespace lcpi{namespace ibp{namespace ib_base{
////////////////////////////////////////////////////////////////////////////////
//forward declarations

class t_ib_row;
class t_ib_row_column;

class t_ib_xrow;

//ib array descr ---------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_ib_array_descr)

//ib array ---------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_ib_array)

//meta_svc: gets a codepage element information --------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_meta_svc__get_charset_info)

//meta svc: gets a domain information ------------------------------------
class t_ib_meta_svc__domain_info;

IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_meta_svc__get_domain_info)

//meta_svc: gets a stored procedure source code --------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_meta_svc__get_sp_source)

//meta_svc:: gets a UDF declaration text ---------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_meta_svc__get_udf_source)

//meta svc: get a character set data (from system table) -----------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_meta_svc__get_charset_data)

//meta svc: get a collate character set data (from system table) ---------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_meta_svc__get_collate_data)

//meta svc: get a RDB$DATABASE row ---------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_meta_svc__get_database_data)

//------------------------------------------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_ib_api_svc__array_sdl_generator);

////////////////////////////////////////////////////////////////////////////////
//meta data description

class t_ib_meta_data_descr__domain;
class t_ib_meta_data_descr__charset;
class t_ib_meta_data_descr__collate;
class t_ib_meta_data_descr__database;

class t_ib_meta_data_ddl_gen__context;

////////////////////////////////////////////////////////////////////////////////
//создание сервиса загрузки списка первичных ключей

db_obj::t_db_object_ptr
 create_meta_svc__get_table_pkey_columns();

////////////////////////////////////////////////////////////////////////////////
//создание сервиса загрузки обновляемых колонок таблицы

db_obj::t_db_object_ptr
 create_meta_svc__get_table_updatable_columns();

////////////////////////////////////////////////////////////////////////////////

db_obj::t_db_object_ptr
 create_svc__gen_id(const isc_base::t_isc_connection_settings& cns);

////////////////////////////////////////////////////////////////////////////////
}/*nms ib_base*/}/*nms ibp*/}/*nms lcpi*/

////////////////////////////////////////////////////////////////////////////////
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_meta_svc__get_charset_info)
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_meta_svc__get_domain_info)
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_meta_svc__get_sp_source)
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_meta_svc__get_udf_source)
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_meta_svc__get_charset_data)
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_meta_svc__get_collate_data)
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_meta_svc__get_database_data)
IBP_DEF_DB_INTERFACE_ID(ib_base::t_ib_api_svc__array_sdl_generator)
////////////////////////////////////////////////////////////////////////////////
#endif
