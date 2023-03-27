////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_connection_settings.cpp
//! \brief   Настройки подключения к базе данных
//! \author  Kovalenko Dmitry
//! \date    29.07.2003
#include <_pch_.h>
#pragma hdrstop

#include "source/db_obj/isc_base/isc_connection_settings.h"
#include "source/ibp_utils.h"

#include <lcpi/lib/structure/utilities/string/is_like_str.h>
#include <sstream>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////
//class t_isc_connection_settings::tag_db_info__impl

t_isc_connection_settings::tag_db_info__impl::tag_db_info__impl()
 :isc_implId(0)
 ,isc_classId(0)
 ,ibp_implId(db_obj::db_impl__unknown)
 ,ibp_classId(db_obj::db_class__unknown)
{;}

////////////////////////////////////////////////////////////////////////////////
//class t_isc_connection_settings

t_isc_connection_settings::t_isc_connection_settings()
{
 this->internal_init();
}//t_isc_connection_settings

//------------------------------------------------------------------------
void t_isc_connection_settings::internal_init()
{
 this->svp_flags           =0;

 this->tr_flags            =0;

 this->max_obj_name_len    .reset();

 this->max_sql_len         =0;

 this->unicode_mode        =ibprovider::ibp_propval__unicode_mode__default;
 this->nested_trans        =ibprovider::ibp_propval__nested_trans__default;
 this->nested_trans_rules  =ibprovider::ibp_propval__nested_trans_rules__default;

#if(IBP_ENGINE_META_DATA_READER!=0)
 this->schema_ldr_cfg__descriptions         =ibprovider::ibp_propval__schema_ldr_cfg__descriptions__default;
 this->schema_ldr_cfg__check_constraints    =ibprovider::ibp_propval__schema_ldr_cfg__check_constraints__default;

#endif // IBP_ENGINE_META_DATA_READER!=0

 this->schema_cache_mode                    =ibprovider::ibp_propval_schema_cache__default;

 this->array_type                           =ibprovider::ibp_propval_array_type__default;

 this->force_nulls                          =ibprovider::ibp_propval__force_nulls__default;

 this->numeric_i2_rules                     =ibprovider::ibp_propval_numeric_rules__default;
 this->numeric_i4_rules                     =ibprovider::ibp_propval_numeric_rules__default;
 this->numeric_i8_rules                     =ibprovider::ibp_propval_numeric_rules__default;

 this->stmt_cache__time                     =ibprovider::ibp_propval_stmt_cache_time__default;
 this->stmt_cache__size                     =ibprovider::ibp_propval_stmt_cache_size__default;
 this->stmt_cache__req_life_time            =ibprovider::ibp_propval_stmt_cache_req_life_time__default;

 this->dbtime_rules               = ibprovider::ibp_propval_dbtime_rules__default;
 this->dbtimestamp_rules          = ibprovider::ibp_propval_dbtimestamp_rules__default;
 this->dbdate_rules               = ibprovider::ibp_propval_dbdate_rules__default;

 this->dbms__guid_rules           = ibprovider::ibp_propval__guid_rules__default_for_isc;
}//internal_init

//------------------------------------------------------------------------
void t_isc_connection_settings::reset()
{
 this->internal_init();

 this->provider_error_rules       .reset();

 this->db_location                .clear();

 this->db_info__impl_stack        .clear();

 this->db_info__file_name_Ex      .reset();
 this->db_info__site_name_Ex      .reset();

 this->db_read_only_Ex            .reset();

 this->db_dialect_Ex              .reset();

 this->default_dialect_Ex         .reset();

 this->client_dialect_Ex          .reset();

 this->db_page_size_Ex            .reset();

 this->dbms                       .reset();
 this->client                     .reset();

 this->db_ods_Ex                  .reset();

 this->db_date_create_Ex          .reset();

 this->boolean_domain_name        .erase();
 this->guid_domain_name           .erase();
}//reset

//------------------------------------------------------------------------
void t_isc_connection_settings::set_cn_params(const oledb_lib::OLEDB_Props2__Data__Values* const pDsPropValues)
{
 assert(pDsPropValues);

 //правила обработки серверных ошибок ------------------------------------
 this->provider_error_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__PROVIDER_ERROR_RULES);

 //разрешение на создание вложенных транзакций ---------------------------
 this->nested_trans
  =pDsPropValues->AUX__GetValue__bool(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__NESTED_TRANS);

 this->nested_trans_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__NESTED_TRANS_RULES);

 //-----------------------------------------------------------------------
 this->unicode_mode
  =pDsPropValues->AUX__GetValue__bool(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__UNICODE_MODE);

 //-----------------------------------------------------------------------
 this->numeric_i2_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__NUMERIC_I2_RULES);

 this->numeric_i4_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__NUMERIC_I4_RULES);

 this->numeric_i8_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__NUMERIC_I8_RULES);

 //-----------------------------------------------------------------------
 this->array_type
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__ARRAY_TYPE);

 //-----------------------------------------------------------------------
 this->force_nulls
  =pDsPropValues->AUX__GetValue__bool(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__FORCE_NULLS);

 //-----------------------------------------------------------------------
#if(IBP_ENGINE_META_DATA_READER!=0)
 //загрузка описаний объектов
 this->schema_ldr_cfg__descriptions
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__SCHEMA_LDR_CFG__DESCRIPTIONS);

 //загрузка сведений о CHECK-ограничениях
 this->schema_ldr_cfg__check_constraints
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__SCHEMA_LDR_CFG__CHECK_CONSTRAINTS);

#endif // IBP_ENGINE_META_DATA_READER!=0

 //режим кэширования метаданных
 this->schema_cache_mode
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__SCHEMA_CACHE);

 //настройка кэша запросов -----------------------------------------------
 this->stmt_cache__time
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__STMT_CACHE__TIME);

 this->stmt_cache__size
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__STMT_CACHE__SIZE);

 this->stmt_cache__req_life_time
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__STMT_CACHE__REQ_LIFE_TIME);

 //шаблон домена, эмулирующего тип BOOLEAN -------------------------------
 this->boolean_domain_name
  =pDsPropValues->AUX__GetValue__wstr_e(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__USER_TYPE_BOOLEAN);

 //шаблон домена, эмулирующего тип GUID ----------------------------------
 this->guid_domain_name
  =pDsPropValues->AUX__GetValue__wstr_e(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__USER_TYPE_GUID);

 //-----------------------------------------------------------------------
 this->dbtime_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__DBTIME_RULES);

 this->dbtimestamp_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__DBTIMESTAMP_RULES);

 this->dbdate_rules
  =pDsPropValues->AUX__GetValue__long(ibprovider::IBP_DBPROPSET_INIT,ibprovider::IBP_DBPROP__INIT__DBDATE_RULES);
}//set_cn_params

//------------------------------------------------------------------------
bool t_isc_connection_settings::cur_ods_is_great_than(const t_isc_ods_id& id)const
{
 assert(!this->db_ods_Ex.null());

 if(id<this->db_ods_Ex.value())
  return true;

 return false;
}//cur_ods_is_great_than

//------------------------------------------------------------------------
bool t_isc_connection_settings::cur_ods_is_great_or_eq_than(const t_isc_ods_id& id)const
{
 assert(!this->db_ods_Ex.null());

 if(this->db_ods_Ex.value()<id)
  return false;

 return true;
}//cur_ods_is_great_or_eq_than

//------------------------------------------------------------------------
void t_isc_connection_settings::check_cur_ods__is_great_or_eq(const t_isc_ods_id& req_id)const
{
 assert(!this->db_ods_Ex.null());

 if(this->cur_ods_is_great_or_eq_than(req_id))
  return;

 this->helper__throw_err__not_support_database_ods(req_id);
}//check_cur_ods__is_great_or_eq

//------------------------------------------------------------------------
void t_isc_connection_settings::check_cur_ods__is_great(const t_isc_ods_id& req_id)const
{
 assert(!this->db_ods_Ex.null());

 if(this->cur_ods_is_great_than(req_id))
  return;

 this->helper__throw_err__not_support_database_ods(req_id);
}//check_cur_ods__is_great

//------------------------------------------------------------------------
bool t_isc_connection_settings::db_dialect_is_great_or_equal_than(dialect_type const dialect)const
{
 if(this->db_dialect_Ex.null())
  return false;

 return this->db_dialect_Ex.value()>=dialect;
}//db_dialect_is_great_or_equal_than

//------------------------------------------------------------------------
bool t_isc_connection_settings::is_boolean_domain(const db_obj::t_db_string& domain_name)const
{
 if(this->boolean_domain_name.empty())
  return false;

 return lib::structure::is_like_str
         (_SQL_T('?'),
          _SQL_T('*'),
          domain_name,
          this->boolean_domain_name);
}//is_boolean_domain

//------------------------------------------------------------------------
bool t_isc_connection_settings::is_guid_domain(const db_obj::t_db_string& domain_name)const
{
 if(this->guid_domain_name.empty())
  return false;

 return lib::structure::is_like_str
         (_SQL_T('?'),
          _SQL_T('*'),
          domain_name,
          this->guid_domain_name);
}//is_guid_domain

//------------------------------------------------------------------------
bool t_isc_connection_settings::enable_stmt_cache()const
{
 return this->stmt_cache__time!=0 && this->stmt_cache__size!=0;
}//enable_stmt_cache

//------------------------------------------------------------------------
long t_isc_connection_settings::get_adjust_req_life_time()const
{
 long req_life_time=this->stmt_cache__req_life_time;

 //---------------
 if(req_life_time<0)
 {
  //время жизни подготовленного запроса совпадает с временем жизни ресурса
  req_life_time=this->stmt_cache__time;
 }//if

 if(this->stmt_cache__time>=0)
 {
  assert(req_life_time>=0);

  //подготовленный запрос не может
  if(this->stmt_cache__time<req_life_time)
   req_life_time=this->stmt_cache__time;
 }//if

 return req_life_time;
}//get_adjust_req_life_time

//------------------------------------------------------------------------
bool t_isc_connection_settings::nested_tr__enable_implicit_commit_by_tr()const
{
 const long c_test_flag
  =ibprovider::ibp_propval__nested_trans_rules__implicit_commit_by_tr;

 return (this->nested_trans_rules&c_test_flag)==c_test_flag;
}//nested_tr__enable_implicit_commit_by_tr

//------------------------------------------------------------------------
bool t_isc_connection_settings::nested_tr__enable_implicit_commit_by_svp()const
{
 const long c_test_flag
  =ibprovider::ibp_propval__nested_trans_rules__implicit_commit_by_svp;

 return (this->nested_trans_rules&c_test_flag)==c_test_flag;
}//nested_tr__enable_implicit_commit_by_svp

//------------------------------------------------------------------------
bool t_isc_connection_settings::svp__release_child_svps_of_recreated_svp()const
{
 const long c_test_flag
  =isc_svp_flag__release_child_svps_of_recreated_svp;

 return (this->svp_flags&c_test_flag)==c_test_flag;
}//svp__release_child_svps_of_recreated_svp

//------------------------------------------------------------------------
#if(IBP_ENGINE_META_DATA_READER!=0)

bool t_isc_connection_settings::schema_ldr_cfg__can_publish_check_constraints()const
{
 return this->schema_ldr_cfg__check_constraints==ibprovider::ibp_propval__schema_ldr_cfg__check_constraints__yes;
}//schema_ldr_cfg__can_publish_check_constraints

#endif // IBP_ENGINE_META_DATA_READER!=0

//------------------------------------------------------------------------
db_obj::t_db_impl_id t_isc_connection_settings::get_database_implID()const
{
 if(db_info__impl_stack.empty())
  return db_obj::db_impl__unknown;

 // [2016-02-02]
 //  Описание реализации базы данных должно идти в начале списка!

 if(db_info__impl_stack.front().ibp_classId==db_obj::db_class__access)
  return db_info__impl_stack.front().ibp_implId;

 return db_obj::db_impl__unknown;
}//get_database_implID

//------------------------------------------------------------------------
bool t_isc_connection_settings::err_rules__explain_dbms_error()const
{
 assert(!this->provider_error_rules.null());

 return ibp::IBP_Utils::TestProviderErrorRules__explain_dbms_error
         (this->provider_error_rules.value());
}//err_rules__explain_dbms_error

//------------------------------------------------------------------------  
void t_isc_connection_settings::helper__throw_err__not_support_database_ods
                                      (const t_isc_ods_id& req_id)const
{
 t_ibp_error exc(E_FAIL,ibp_mce_dbobj__not_support_database_ods_4);

 exc<<this->db_ods_Ex.value().as_wstr()
    <<req_id.as_wstr()
    <<push_descr_ex(this->dbms)
    <<_Module.GetModuleVersion();

 exc.raise_me();
}//helper__throw_err__not_support_database_ods

////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
