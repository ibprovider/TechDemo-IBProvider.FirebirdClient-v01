////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_base.h
//! \brief   Forward-определение конструкций, связанных с ISC-совместимыми БД
//! \author  Kovalenko Dmitry
//! \date    18.06.2008
#ifndef _isc_base_H_
#define _isc_base_H_

#include "source/db_obj/db_base.h"

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////

class t_isc_param_buffer_v1_builder;

class t_isc_ods_id;

class t_isc_error_code_descr;
class t_isc_error_code_descr2;

class t_isc_status_vector;
class t_isc_dbms_info;
class t_isc_connection_settings;

struct t_isc_ods_data__database;

//интерфейсы сервисов для работы xrow ------------------------------------
IBP_DEF_FWRD_DB_INTERFACE(t_isc_meta_svc__xsqlvar_v1);
IBP_DEF_FWRD_DB_INTERFACE(t_isc_meta_svc__xsqlvar_v2);

//интерфейс для транслирования текста SQL запроса ------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_stmt_text_translator);

//интерфейс для загрузки массивов ----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__array_reader);

//интерфейс для выгрузки массивов ----------------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__array_writer);

//интерфейс для создания загрузчика BLOB ---------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__blob_reader_factory);

//интерфейс для создания писателя BLOB -----------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__blob_writer_factory);

//интерфейс сервиса для отмена запросов ----------------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_api_svc__cancel_statement);

//интерфейс для получения настроек подключения ---------------------------
IBP_DEF_FWRD_DB_INTERFACE_EX(t_isc_svc__get_connection_settings);

//интерфейс сервис для сканирования SUSPEND в реализации хранимой процедуры

IBP_DEF_FWRD_DB_INTERFACE(t_isc_meta_svc__sp_suspend_detecter);

//идентификатор сервиса для поиска SUSPEND в BLR хранимой процедуры
extern const db_obj::t_db_svc_descr
 isc_meta_svc_descr__sp_suspend_detecter__blr;

//идентификатор сервиса для поиска SUSPEND в SRC хранимой процедуры
extern const db_obj::t_db_svc_descr
 isc_meta_svc_descr__sp_suspend_detecter__src;

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/

////////////////////////////////////////////////////////////////////////////////

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_stmt_text_translator)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__array_reader)
IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__array_writer)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__blob_reader_factory)
IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__blob_writer_factory)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_api_svc__cancel_statement)

IBP_DEF_DB_INTERFACE_ID(isc_base::t_isc_svc__get_connection_settings)

////////////////////////////////////////////////////////////////////////////////
#endif
