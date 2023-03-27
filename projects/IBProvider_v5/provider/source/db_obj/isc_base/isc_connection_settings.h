////////////////////////////////////////////////////////////////////////////////
//! \ingroup isc_base
//! \file    isc_connection_settings.h
//! \brief   ��������� ����������� � ���� ������
//! \author  Kovalenko Dmitry
//! \date    29.07.2003
#ifndef _isc_connection_settings_H_
#define _isc_connection_settings_H_

#include "source/db_obj/isc_base/isc_types.h"             //t_ibp_isc_dialect
#include "source/db_obj/isc_base/isc_dbms_info.h"         //t_isc_dbms_info
#include "source/db_obj/isc_base/isc_max_obj_name_len.h"  //t_isc_max_obj_name_len
#include "source/db_obj/isc_base/isc_ods_id.h"            //t_isc_ods_id
#include "source/db_obj/isc_base/isc_api.h"               //t_ibp_isc_timestamp
#include "source/db_obj/platform/db_platform.h"
#include "source/db_obj/db_types.h"

#include <ole_lib/oledb/provider/props2/oledb_props2__data__values.h>

#include <structure/stl/t_stl_vector.h>

namespace lcpi{namespace ibp{namespace isc_base{
////////////////////////////////////////////////////////////////////////////////

#ifndef IBP_ENGINE_META_DATA_READER
# error IBP_ENGINE_META_DATA_READER is not defined
#endif

////////////////////////////////////////////////////////////////////////////////
//! \addtogroup isc_base
//! @{
////////////////////////////////////////////////////////////////////////////////
//containings

class t_isc_connection_settings;

////////////////////////////////////////////////////////////////////////////////
//enum tag_isc_svp_flags

/// <summary>
///  ������������ ������ ��������� ����� ����������
/// </summary>
enum tag_isc_svp_flags
{
 ///������ ������������ ����� ����������
 isc_svp_flag__supported                            =0x01,

 ///������ ����������� savepoint ����� "rollback to savepoint" (IB7)
 isc_svp_flag__release_after_rollback               =0x02,

 ///������������ ��������� ����� ���������� ��� ������������ ����� ���������� (IB7)
 isc_svp_flag__release_child_svps_of_recreated_svp  =0x04,
};//enum tag_isc_svp_flags

typedef long t_isc_svp_flags;

////////////////////////////////////////////////////////////////////////////////
//enum tag_isc_tr_flags

/// <summary>
///  ������������ ������ ��������� ����������
/// </summary>
enum tag_isc_tr_flags
{
 ///�������������� �������� ������ � ������������
 isc_tr_flag__support_rollback_retain               =0x01,
};//enum tag_isc_tr_flags

typedef long t_isc_tr_flags;

////////////////////////////////////////////////////////////////////////////////
//class t_isc_connection_settings

/// <summary>
///  ��������� �����������
/// </summary>
class t_isc_connection_settings
{
 private:
  typedef  t_isc_connection_settings                        self_type;

  self_type& operator = (const self_type&)=delete;

 public: //typedefs ------------------------------------------------------
  typedef t_ibp_isc_dialect                                 dialect_type;

  typedef structure::t_value_with_null<bool>                bool_type_N;
  typedef structure::t_value_with_null<long>                long_type_N;
  typedef structure::t_value_with_null<std::string>         str_type_N;
  typedef structure::t_value_with_null<dialect_type>        dialect_type_N;

  typedef structure::t_value_with_null<isc_api::t_ibp_isc_timestamp> ib_timestamp_type_N;

  typedef structure::t_value_with_null<t_isc_ods_id>        ods_id_type_N;

 public:
  class tag_db_info__impl
  {
   public:
    unsigned char          isc_implId;  //������������� ���������
    unsigned char          isc_classId; //������������� ������ ����������

   public:
    db_obj::t_db_impl_id   ibp_implId;
    db_obj::t_db_class_id  ibp_classId;

   public:
    tag_db_info__impl();
  };//class tag_db_info__impl

  typedef structure::t_stl_vector
           <tag_db_info__impl,
            db_obj::t_db_memory_allocator>                  db_info__impl_stack_type;

 private:
  void internal_init();

 public:
  /// <summary>
  ///  ����������� ��-���������.
  /// </summary>
  t_isc_connection_settings();

  /// <summary>
  ///  ����������� �����������.
  /// </summary>
  //! \param[in] x
  explicit t_isc_connection_settings(const self_type& x)=default;

  /// <summary>
  ///  ����� ������� � ��������� ���������
  /// </summary>
  void reset();

  /// <summary>
  ///  ��������� ���������� �����������
  /// </summary>
  //! \param[in] pDsPropValues
  void set_cn_params(const oledb_lib::OLEDB_Props2__Data__Values* pDsPropValues);

 public:
  /// <summary>
  ///  ������������ ������ ODS
  /// </summary>
  //! \param[in] id
  bool cur_ods_is_great_than(const t_isc_ods_id& id)const;

  /// <summary>
  ///  ������������ ������ ODS
  /// </summary>
  //! \param[in] id
  bool cur_ods_is_great_or_eq_than(const t_isc_ods_id& id)const;

  /// <summary>
  ///  �������� ������ ODS
  /// </summary>
  //! \param[in] req_id
  void check_cur_ods__is_great_or_eq(const t_isc_ods_id& req_id)const;

  /// <summary>
  ///  �������� ������ ODS
  /// </summary>
  //! \param[in] req_id
  void check_cur_ods__is_great(const t_isc_ods_id& req_id)const;

 public:
  /// <summary>
  ///  ������������ �������� ���� ������
  /// </summary>
  //! \param[in] dialect
  bool db_dialect_is_great_or_equal_than(dialect_type dialect)const;

  /// <summary>
  ///  �������� �������������� ������ � ���� BOOLEAN
  /// </summary>
  //! \param[in] domain_name
  bool is_boolean_domain(const db_obj::t_db_string& domain_name)const;

  /// <summary>
  ///  �������� �������������� ������ � ���� GUID
  /// </summary>
  //! \param[in] domain_name
  bool is_guid_domain(const db_obj::t_db_string& domain_name)const;

  /// <summary>
  ///  ���������� �� ����������� ��������
  /// </summary>
  bool enable_stmt_cache()const;

  /// <summary>
  ///  ��������������� ����� ����� ��������������� ������� � ���� ��������
  /// </summary>
  long get_adjust_req_life_time()const;

  /// <summary>
  ///  ��������� �������� �����������
  /// </summary>
  dialect_type get_client_dialect()const;

  /// <summary>
  ///  ���������� �������� ������� ��������� ���������� �����
  ///  ������ ������������ ����������
  /// </summary>
  bool nested_tr__enable_implicit_commit_by_tr()const;

  /// <summary>
  ///  ���������� �������� ������� ��������� ���������� �����
  ///  ������������ ������������ ����� ����������
  /// </summary>
  bool nested_tr__enable_implicit_commit_by_svp()const;

  /// <summary>
  ///  ������������ ������� ����� isc_svp_flag__release_child_svps_of_recreated_svp
  /// </summary>
  bool svp__release_child_svps_of_recreated_svp()const;

 #if(IBP_ENGINE_META_DATA_READER!=0)
  /// <summary>
  ///  ���������� �������� � CHECK-������������
  /// </summary>
  bool schema_ldr_cfg__can_publish_check_constraints()const;

 #endif // IBP_ENGINE_META_DATA_READER!=0

  /// <summary>
  ///  ��������� �������������� ���������� ���� ������.
  /// </summary>
  db_obj::t_db_impl_id get_database_implID()const;

  /// <summary>
  ///  ���������� �������������� ������� � ��������� ������
  /// </summary>
  bool err_rules__explain_dbms_error()const;

 public: //database and server informations ------------------------------
  //! \brief
  //!  ������ � ������������� ���� ������.
  std::wstring          db_location;

  //! \brief
  //!  �������� � ���������� ������� ���� ������
  //! \note
  //!  �������� ISC-��������������� ������� �� ���� ������� ���� ������.
  db_info__impl_stack_type  db_info__impl_stack;

  str_type_N             db_info__file_name_Ex;
  str_type_N             db_info__site_name_Ex;

  bool_type_N            db_read_only_Ex;

  ///������� ���� ������
  dialect_type_N         db_dialect_Ex;

  ///������� ���� ������ ��-��������� ��� �������� ��
  dialect_type_N         default_dialect_Ex;

  ///������� ������� ����������� � ���� ������
  dialect_type_N         client_dialect_Ex;

  ///������ �������� ���� ������
  long_type_N            db_page_size_Ex;

  //------------
  ///�������� � DBMS
  t_isc_dbms_info        dbms;

  ///�������� � �������
  t_isc_dbms_info        client;

  //------------
  ///������ ODS
  ods_id_type_N          db_ods_Ex;

  //------------
  ///���� �������� ���� ������ (Firebird)
  ib_timestamp_type_N    db_date_create_Ex;

  /// <summary>
  ///  �������� ��������� ����� ����������
  /// </summary>
  //! 0, ���� ������ �� ������������ ����� ����������
  //! <seealso cref="isc_base::tag_isc_svp_flags"/>
  t_isc_svp_flags        svp_flags;

  /// ��������� ����������
  t_isc_tr_flags         tr_flags;

  /// <summary>
  ///  ������������ ����� �������� ������� ���� ������
  /// </summary>
  t_isc_max_obj_name_len max_obj_name_len;

  //------------
  /// <summary>
  ///  ������������ ����� ������ SQL-�������
  /// </summary>
  size_t                 max_sql_len;

 public: //connection properties -----------------------------------------
  /// <summary>
  ///  ������� ������������ � ��������� ������
  /// </summary>
  //! \note
  //!  ���������� nullable-�������� ��� ����������� �������� ��������������������.
  long_type_N            provider_error_rules;

  ///Unicode �����
  bool                   unicode_mode;

  ///���������� ���������� ��������� ����������
  bool                   nested_trans;

  ///������� ���������� ���������� ������������
  long                   nested_trans_rules;

 #if(IBP_ENGINE_META_DATA_READER!=0)
  ///����� �������� �������� IBP_DBPROP__INIT__SCHEMA_LDR_CFG__DESCRIPTIONS
  long                   schema_ldr_cfg__descriptions;

  ///����� �������� �������� IBP_DBPROP__INIT__SCHEMA_LDR_CFG__CHECK_CONSTRAINTS
  long                   schema_ldr_cfg__check_constraints;

 #endif // IBP_ENGINE_META_DATA_READER!=0

  /// <summary>
  ///  ����� ����������� ����������
  /// </summary>
  ///  ��������� �������� ������������ � ibp::t_ibp_propval_schema_cache
  long                   schema_cache_mode;

  /// <summary>
  ///  ������� ���������� ��������.
  /// </summary>
  ///  ��������� �������� ����������� � ibp::t_ibp_propval_column_type_rules
  long                   array_type;

  ///Force nulls
  bool                   force_nulls;

  ///NUMERIC_I2 Rules
  long                   numeric_i2_rules;

  ///NUMERIC_I4 Rules
  long                   numeric_i4_rules;

  ///NUMERIC_I8 Rules
  long                   numeric_i8_rules;

  ///������ � ���� ������, ������������ ��� BOOLEAN
  ibp::t_ibp_string      boolean_domain_name;

  ///������ � ������ ������, ������������ ��� GUID
  ibp::t_ibp_string      guid_domain_name;

  /// <summary>
  ///  ����������� ����� ����� �������� � ����
  /// </summary>
  ///  ���� ������� ������������� ����� ��� ����, ������� �� ����������
  long                   stmt_cache__time;

  /// <summary>
  ///  ������ ���� ��������
  /// </summary>
  ///  - ���� ������ ����, �� ������� �� ����������
  ///  - ���� ������ ������������� ��������, �� ������ �� ���������
  long                   stmt_cache__size;

  /// <summary>
  ///  ����������� ����� ����� ��������������� ������� � ����
  /// </summary>
  long                   stmt_cache__req_life_time;

  ///Rules for datatype TIME
  long                   dbtime_rules;

  ///Rules for datatype TIMESTAMP
  long                   dbtimestamp_rules;

  ///Rules for datatype DATE
  long                   dbdate_rules;

 public:
  ///DBMS Rules for datatype GUID
  long                   dbms__guid_rules;

 private:
  COMP_CONF_DECLSPEC_NORETURN
  void helper__throw_err__not_support_database_ods(const t_isc_ods_id& req_id)const;
};//class t_isc_connection_settings

////////////////////////////////////////////////////////////////////////////////
//class t_isc_connection_settings

inline t_isc_connection_settings::dialect_type
 t_isc_connection_settings::get_client_dialect()const
{
 assert(!this->client_dialect_Ex.null());

 return this->client_dialect_Ex.value();
}//get_client_dialect

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms isc_base*/}/*nms ibp*/}/*nms lcpi*/
#endif
