////////////////////////////////////////////////////////////////////////////////
//IBProvider tests. DirectFB.
//                                                 Kovalenko Dmitry. 02.02.2015.
#ifndef _check_error_services_H_
#define _check_error_services_H_

#include "source/test_base.h"

namespace lcpi{namespace ibp_tests{
////////////////////////////////////////////////////////////////////////////////
//class TestCheckErrors

class TestCheckErrors
{
 private:
  typedef TestCheckErrors                   self_type;

 public:
  typedef structure::t_const_str_box        str_box_type;
  typedef structure::t_const_wstr_box       wstr_box_type;

 public: //---------------------------------------------------------------
  static const LCID lcid__RUS=MAKELCID(MAKELANGID(LANG_RUSSIAN,SUBLANG_RUSSIAN_RUSSIA),SORT_DEFAULT);

  static const LCID lcid__ENG=MAKELCID(MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US),SORT_DEFAULT);

 public:
  static const char sm_srcID__IBProvider[];

  static const char sm_srcID__UnknownDBMS[];

  static const wchar_t sm_srcID_wstr__Firebird[];

  static const wchar_t sm_subsysID__remote_fb[];

  static const wchar_t sm_subsysID__remote_fb_inet[];

  static const wchar_t sm_subsysID__remote_fb_p10[];

  static const wchar_t sm_subsysID__remote_fb_p11[];

  static const wchar_t sm_subsysID__remote_fb_p12[];

  static const wchar_t sm_subsysID__remote_fb_p13[];

  static const wchar_t sm_subsysID__remote_fb_pset01[];

  static const wchar_t sm_subsysID__remote_fb_pset02[];

  static const wchar_t sm_subsysID__isc_api__fb2_5[];

  static const wchar_t sm_subsysID__isc_api__fb3_0[];

  static const wchar_t sm_subsysID__isc_api__fb4_0[];

 public:
  static void print_exception_ok(TTSO_Tracer&          tracer,
                                 const std::exception& exc);

 public:
  static void check_err_code(HRESULT actualHResult,
                             HRESULT expectedHResult);

  static void check_err_count(const structure::t_err_records_r& errs,
                              size_t                            reqCount);

 public:
  static bool check_err_rec__source
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Source);

  static bool check_err_rec__partially
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Source,
                 wstr_box_type                  ucs2MsgPart);

  static bool check_err_rec
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Source,
                 wstr_box_type                  ucs2Msg);

  static bool check_err_rec__bug_check
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  ucs2Reason);

 public:
  static bool check_err_rec__common_err__formed_buf_is_too_large
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_BufName,
                 size_t                         buf_size,
                 size_t                         max_size);

 public:
  static bool check_err_rec__bug_check__unknown_property_value
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point,
                 wstr_box_type                  propName,
                 wstr_box_type                  propValue);

 public:
  static bool check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__direct_fb__bad_format_of_str_for_inet_cn_to_db__no_port
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_host_sign);

  static bool check_err_rec__bug_check__mistake_in_parch_list
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point);

  static bool check_err_rec__bug_check__mult_enum_of_parch
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point,
                 wstr_box_type                  parch_name);

  static bool check_err_rec__bug_check__empty_list_of_parchs
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point);

  static bool check_err_rec__unsupported_protocol
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_PName);

  static bool check_err_rec__unsupported_protocol_architecture
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_PArchName);

  static bool check_err_rec___ibp_mce_remote__requested_protocol_type_not_supported_2
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_PTypeName,
                 unsigned                       EstablishedProtocolVersion);

  static bool check_err_rec___ibp_mce_remote__unsupported_protocol_type_2
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 unsigned                       EstablishedProtocolVersion,
                 unsigned                       ProtocolTypeID);

  static bool check_err_rec___ibp_mce_remote__unsupported_protocol_flags_2
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 unsigned                       EstablishedProtocolVersion,
                 unsigned                       ProtocolFlags);

  static bool check_err_rec___ibp_mce_remote__server_rejected_cn_compression_0
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec___ibp_mce_remote__server_required_cn_compression_0
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec___ibp_mce_remote__unsupported_wire_compression_type_1
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_TypeName);

  static bool check_err_rec___ibp_mce_remote__wire_compression_not_supported_0
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

 public:
  static bool check_err_rec__bug_check__cant_convert_auth_service_name_from_utf8_to_wstr
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point);

  static bool check_err_rec__bug_check__auth_service_already_was_used
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point,
                 wstr_box_type                  authServiceName);

  static bool check_err_rec__bug_check__auth_service_factory_already_was_registered
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point,
                 wstr_box_type                  authServiceName);

 public:
  static bool check_err_rec__winsock__cant_detect_host_address
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 int                            winsockError,
                 wstr_box_type                  ucs2_host_name,
                 wstr_box_type                  ucs2_port_name);

  static bool check_err_rec__winsock__failed_to_connect_to_server
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 int                            winsockError,
                 wstr_box_type                  ucs2_host,
                 wstr_box_type                  ucs2_port,
                 wstr_box_type                  ucs2_address,
                 int                            socket__family,
                 int                            socket__type,
                 int                            socket__protocol);

  static bool check_err_rec__winsock__failed_to_write_into_port
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 int                            winsockErrorCode);

 public:
  static bool check_err_rec__cn_err__cant_detect_auth_method
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID);

  static bool check_err_rec__cn_err__unk_auth_service_name
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  ucs2_AuthServiceName);

  static bool check_err_rec__cn_err__incorrect_auth_service_name
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  ucs2_AuthServiceName);

  static bool check_err_rec__cn_err__auth_service_not_supported
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  ucs2_AuthServiceName);

  static bool check_err_rec__cn_err__incompatible_auth_settings
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  ucs2_AuthServiceName,
                wstr_box_type                  ucs2_IntegratedSecurityValue);

  static bool check_err_rec__cn_err__integ_sec_not_supported
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID);

 public:
  static bool check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_key_type
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point,
                wstr_box_type                  ucs2FromCS,
                wstr_box_type                  ucs2ToCS);

  static bool check_err_rec__cn_err__bug_check__cant_translate_wire_crypt_svc_names
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point,
                wstr_box_type                  ucs2FromCS,
                wstr_box_type                  ucs2ToCS);

  static bool check_err_rec__cn_err__mult_def_known_server_key
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  ucs2_keyType,
                wstr_box_type                  ucs2_keyPlugin);

 public:
  static bool check_err_rec__cn_err__wire_crypt_not_possible__no_known_srv_keys
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  ucs2_authServiceName);

  static bool check_err_rec__cn_err__wire_crypt_not_possible__no_crypt_keys
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  ucs2_authServiceName);

  static bool check_err_rec__cn_err__wire_crypt_not_supported
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID);

 public:
  static bool check_err_rec__srv_err__bad_login
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__unk_db_name
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2ErrSrc,
                wstr_box_type                  pwszDbName);

  static bool check_err_rec__cn_err__db_name_is_too_long
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                size_t                         szDbName,
                size_t                         max_szDbName);

  static bool check_err_rec__cn_err__translate_db_name_to_utf8
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID);

  static bool check_err_rec__cn_err__translate_cn_param_to_utf8
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  pParamName);

  static bool check_err_rec__cn_err__cant_detect_cn_type
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID);

  static bool check_err_rec__cn_err__not_defined_req_init_prop
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  pSubSystemID,
                wstr_box_type                  pPropName);

  static bool check_err_rec__srv_err__incorrect_params_to_internal_func_INF_database_info
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__cn_err__bug_check__bad_cn_handle
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point);

  static bool check_err_rec__srv_err__failed_to_detach__has_active_tr
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2ErrSrc,
                size_t                         nTrs);

 public:
  static bool check_err_rec__srv_err__bad_tpb
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__bad_tpb_ver
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__bad_cn_handle
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__tr_err__bug_check__bad_tr_handle
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point);

  static bool check_err_rec__tr_err__bug_check__tr_handle_not_zero
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point);

  static bool check_err_rec__tr_err__prep_data_is_too_large
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 size_t                         buf_size,
                 size_t                         max_size);

  static bool check_err_rec__srv_err__bad_tr_handle
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

 public:
  static bool check_err_rec__stmt_err__bug_check__stmt_handle_not_zero
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point);

  static bool check_err_rec__stmt_err__bug_check__bad_stmt_handle
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point);

  static bool check_err_rec__srv_err__invalid_req_handle
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__stmt_err__failed_to_close_stmt
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__failed_to_close_stmt__reclose
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__failed_to_close_stmt__reclose__fb3
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__stmt_err__failed_to_prepare
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__attempt_to_execute_unprepared_sql_stmt__fb3
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

  static bool check_err_rec__stmt_err__not_prepared
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__stmt_err__errors_in_get_columns_operation
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__stmt_err__errors_in_get_parameters_operation
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__stmt_srv_err__execute_fail
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__op_was_cancelled
                (TTSO_Tracer&                   tracer,
                 wstr_box_type                  ucs2ErrSrc,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__stmt_err__defer_exec_stmt_requires_tr_context
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__stmt_err__attempt_to_reexecute_stmt_with_open_cursor
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__srv_err__attempt_to_reopen_cursor
                (TTSO_Tracer&                   tracer,
                 wstr_box_type                  ucs2ErrSrc,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__attempt_to_reopen_cursor__fb3
                (TTSO_Tracer&                   tracer,
                 wstr_box_type                  ucs2ErrSrc,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__prepare_stmt_with_open_cursor
                (TTSO_Tracer&                   tracer,
                 wstr_box_type                  ucs2ErrSrc,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__stmt_err__attempt_to_prepare_stmt_with_open_cursor
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__stmt_err__attempt_to_close_a_closed_cursor
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__stmt_err__fetch_from_closed_cursor
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__stmt_err__fetch_after_eof
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID);

  static bool check_err_rec__stmt_err__fetch_fail
                (TTSO_Tracer&                         tracer,
                 const structure::t_err_record* const pErrorRec);

  static bool check_err_rec__srv_err__cursor_is_not_open
                (TTSO_Tracer&                   tracer,
                 wstr_box_type                  ucs2ErrSrc,
                 const structure::t_err_record* pErrorRec);

  static bool check_err_rec__srv_err__cursor_is_not_open__fb3
                (TTSO_Tracer&                   tracer,
                 wstr_box_type                  ucs2ErrSrc,
                 const structure::t_err_record* pErrorRec);

 public:
  static bool check_err_rec__blob_err__bug_check__bad_blob_handle
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point);

  static bool check_err_rec__blob_err__bug_check__blob_handle_not_zero
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point);

  static bool check_err_rec__blob_err__bug_check__wrong_blob_handle_mode
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2Place,
                wstr_box_type                  ucs2Point,
                int                            blobHandleMode);

  static bool check_err_rec__blob_err__close_closed_blob
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2_SubsystemID);

  static bool check_err_rec__blob_err__cancel_closed_blob
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2_SubsystemID);

  static bool check_err_rec__blob_err__read_from_closed_blob
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2_SubsystemID);

  static bool check_err_rec__blob_err__write_into_closed_blob
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2_SubsystemID);

  static bool check_err_rec__blob_err__work_with_closed_blob
               (TTSO_Tracer&                   tracer,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  ucs2_SubsystemID);

  static bool check_err_rec__srv_err__invalid_blob_handle
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec);

 public:
  static bool check_err_rec__slice_err__get_fail__invalid_array_buffer_size
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  ucs2RelationName,
                 wstr_box_type                  ucs2FieldName,
                 size_t                         DefinedSize,
                 size_t                         ExpectedSize);

 public:
  static bool check_err_rec__xsqlda_err__incorrect_version
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  ucs2xsqldaName,
                 long                           version);

  static bool check_err_rec__xsqlda_err__too_many_vars
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  pSubSystemID,
                 size_t                         actualValue,
                 size_t                         maxValue);

  static bool check_err_rec__xsqlda_err__incorrect_sqllen
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  sqlTypeSign,
                 long                           sqlLen);

  static bool check_err_rec__xsqlda_err__incorrect_sqlscale
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  sqlBaseTypeSign,
                 long                           sqlScale);

  static bool check_err_rec__xsqlda_err__unknown_sqltype
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 long                           sqlType);

  static bool check_err_rec__xsqlda_err__incorrect_sqlind_ptr
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 long                           sqlType);

  static bool check_err_rec__xsqlda_err__incorrect_sqlind_value
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  place,
                 wstr_box_type                  point,
                 short                          sqlindValue);

  static bool check_err_rec__xsqlda_err__xsqlvar_not_supports_null_state
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 long                           sqlType);

  static bool check_err_rec__xsqlda_err__incorrect_varchar_data_length
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 long                           varcharLength);

  static bool check_err_rec__xsqlda_err__varchar_data_length_is_greater_than_buffer_size
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 long                           varcharLength,
                 size_t                         bufferSize);

  static bool check_err_rec__xsqlda_err__failed_to_process_xsqlvar_info_raw_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  pSubSystemID,
                 size_t                         index);

  static bool check_err_rec__xsqlda_err__failed_to_process_xsqlvar_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  pSubSystemID,
                 size_t                         index);

  static bool check_err_rec__xsqlda_err__bug_check__other_count_of_xvars
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 size_t                         actualCount,
                 size_t                         expectedCount);

  static bool check_err_rec__xsqlda_err__bug_check__other_sqltype_of_xvar
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 long                           actualSqlType,
                 long                           expectedSqlType);

  static bool check_err_rec__xsqlda_err__bug_check__other_sqlscale_of_xvar
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  sqlBaseTypeSign,
                 long                           actualSqlScale,
                 long                           expectedSqlScale);

  static bool check_err_rec__xsqlda_err__bug_check__other_sqllen_of_xvar
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  sqlTypeSign,
                 long                           actualSqlLen,
                 long                           expectedSqlLen);

  static bool check_err_rec__xsqlda_err__bug_check__incorrect_sqld
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_XSQLDA_Sign,
                 long                           sqld);

  static bool check_err_rec__xsqlda_err__bug_check__incorrect_sqln
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_XSQLDA_Sign,
                 long                           sqln,
                 long                           sqld);

  static bool check_err_rec__xsqlda_err__blr_data_is_too_long
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  ucs2_XSQLDA_Sign,
                 size_t                         actualLen,
                 size_t                         maxLen);

 public:
  static bool check_err_rec__sdl_err__no_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint);

  static bool check_err_rec__sdl_err__unk_version
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 unsigned                       sdlVersion);

  static bool check_err_rec__sdl_err__unexpected_end_of_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint);

  static bool check_err_rec__sdl_err__str_len_exceed_size_of_buffer_tail
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 unsigned                       strLen,
                 size_t                         bufferTailSize);

  static bool check_err_rec__sdl_err__mult_def_of_element_value
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 wstr_box_type                  ucs2_ElementTagID,
                 size_t                         ElementTagOffset);

  static bool check_err_rec__sdl_err__wrong_count_of_struct_fields
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 size_t                         fieldCount);

  static bool check_err_rec__sdl_err__wrong_index_of_bound
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 size_t                         boundIndex,
                 size_t                         maxBoundCount);

  static bool check_err_rec__sdl_err__mult_def_of_bound_range
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 size_t                         boundIndex);

  static bool check_err_rec__sdl_err__bad_bound_range
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 size_t                         boundIndex,
                 signed __int32                 lower,
                 signed __int32                 upper);

  static bool check_err_rec__sdl_err__unknown_kind_of_literal
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 unsigned                       literalKind,
                 size_t                         offset);

  static bool check_err_rec__sdl_err__wrong_count_of_element_fields
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 unsigned                       fieldCount);

  static bool check_err_rec__sdl_err__unexpected_tag
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 unsigned                       tagID,
                 size_t                         offset);

  static bool check_err_rec__sdl_err__incorrect_index_property_of_scalar_tag
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_CheckPlace,
                 wstr_box_type                  ucs2_CheckPoint,
                 unsigned                       index,
                 size_t                         offset);

  static bool check_err_rec__sdl_err__inconsistent_sizes_of_buffer_and_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 size_t                         bufferSize,
                 size_t                         dataSize);

  static bool check_err_rec__sdl_err__no_data_of_tag
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  ucs2TagID);

  static bool check_err_rec__sdl_err__no_data_of_dimensions
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point);

  static bool check_err_rec__sdl_err__no_data_of_dimension
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 size_t                         boundIndex);

  static bool check_err_rec__sdl_err__unknown_blr_type_id
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 unsigned                       blrTypeID,
                 size_t                         offset);

  static bool check_err_rec__sdl_err__invalid_element_length
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 size_t                         length,
                 wstr_box_type                  blrTypeSign);

 public:
  static bool check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_end
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point);

  static bool check_err_rec__xsqlda_info_data_bug_check__unexpected_buffer_truncation
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 size_t                         sqld);

  static bool check_err_rec__xsqlda_info_data_bug_check__incorrect_xsqlda_in_secondary_block
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 long                           actualSQL,
                 long                           expectedSQLD,
                 size_t                         startIndex);

  static bool check_err_rec__xsqlda_info_data_bug_check__xvar_seq_number_is_out_of_range
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 long                           seqNumber,
                 long                           sqld,
                 size_t                         index);

  static bool check_err_rec__xsqlda_info_data_bug_check__unexpected_xvars_for_xsqlda
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 size_t                         sqld);

  static bool check_err_rec__xsqlda_info_data_bug_check__unexpected_seq_number_of_xvar
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 long                           actualSeqNumber,
                 long                           expectedSeqNumber);

  static bool check_err_rec__xsqlda_info_data_bug_check__mult_def_of_xsqvar_field_value
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  fieldName);

  static bool check_err_rec__xsqlda_info_data_bug_check__not_def_xsqvar_field
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 wstr_box_type                  fieldName);

  static bool check_err_rec__xsqlda_info_data_bug_check__negative_sqllen
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 long                           actualLength);

  static bool check_err_rec__xsqlda_info_data_bug_check__incompleted_def_of_xvars
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 size_t                         actualCount,
                 size_t                         expectedCount);

 public:
  static bool check_err_rec__isc__parse_msg_buf_data__failed_to_process_element
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2_SubSystemID,
                 size_t                         elementIndex);

 public:
  static bool check_err_rec__info_buf_bug_check__unexpected_element
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 long                           elementID);

  static bool check_err_rec__info_buf_bug_check__unexpected_buffer_end
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point);

  static bool check_err_rec__info_buf_bug_check__bad_format
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  elementSign);

  static bool check_err_rec__info_buf_bug_check__too_large_value
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  elementSign,
                 size_t                         actualSize,
                 size_t                         maxSize);

  static bool check_err_rec__info_buf_err__transport_data_to_integer__size_t
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  pSubSystemID,
                 wstr_box_type                  elementSign,
                 size_t                         bufferSize);

 public:
  static bool check_err_rec__test_msg_bug_check__nullptr_to_descrs
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  msgSign,
                 size_t                         cDescrs);

  static bool check_err_rec__test_msg_bug_check__nullptr_to_blr
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  msgSign,
                 size_t                         szBlr);

  static bool check_err_rec__test_msg_bug_check__nullptr_to_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  msgSign,
                 size_t                         szData);

  static bool check_err_rec__test_msg_bug_check__unexpected_blr
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  msgSign,
                 size_t                         szBlr);

  static bool check_err_rec__test_msg_bug_check__unexpected_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  msgSign,
                 size_t                         szData);

  static bool check_err_rec__test_msg_bug_check__no_blr
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  msgSign,
                 size_t                         cDescrs);

  static bool check_err_rec__test_msg_bug_check__no_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  ucs2Place,
                 wstr_box_type                  ucs2Point,
                 wstr_box_type                  msgSign,
                 size_t                         cDescrs);

 public:
  static bool check_err_rec__common__internal_err__unk_sql_type
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  pSubSystemID,
                 size_t                         index,
                 long                           sqlType);

 public:
  static bool check_err_rec__srv_err__invalid_time_zone_region
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  regionName);

  static bool check_err_rec__srv_err__invalid_time_zone_ID
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec,
                unsigned                       timezoneID);

  static bool check_err_rec__srv_err__private_procedure
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  procName,
                wstr_box_type                  packageName);

  static bool check_err_rec__srv_err__private_function
               (TTSO_Tracer&                   tracer,
                wstr_box_type                  ucs2ErrSrc,
                const structure::t_err_record* pErrorRec,
                wstr_box_type                  funcName,
                wstr_box_type                  packageName);

 public:
  static bool error_rec__check_source
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 LCID                           lcid,
                 wstr_box_type                  wstrErrSrc);

  static bool error_rec__check_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 LCID                           lcid,
                 wstr_box_type                  wstrErrSrc,
                 wstr_box_type                  wstrErrDescr);

  static bool error_rec__check_data__utf8
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 LCID                           lcid,
                 str_box_type                   strUtf8_ErrSrc,
                 str_box_type                   strUtf8_ErrDescr);

  static bool error_rec__check_data__EN_RU
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  wstrErrSrc,
                 wstr_box_type                  wstrErrDescr__EN,
                 wstr_box_type                  wstrErrDescr__RU);

 public:
  static bool error_rec__check_partial_data
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 LCID                           lcid,
                 wstr_box_type                  wstrErrSrc,
                 wstr_box_type                  wstrErrDescr);

  static bool error_rec__check_partial_data__utf8
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 LCID                           lcid,
                 str_box_type                   strUtf8_ErrSrc,
                 str_box_type                   strUtf8_pszErrDescr);

 public:
  static bool error_rec__check_sqlstate_and_native_code
                (TTSO_Tracer&                   tracer,
                 const structure::t_err_record* pErrorRec,
                 wstr_box_type                  lpszSqlState,
                 LONG                           lNativeCode);

 public:
  static bool check_text(TTSO_Tracer&           tracer,
                         ibprovider::IBP_IText* pText,
                         LCID                   lcid,
                         wstr_box_type          pwszText);

  static bool check_text__utf8(TTSO_Tracer&           tracer,
                               ibprovider::IBP_IText* pText,
                               LCID                   lcid,
                               const char*            pszUtf8_Text);

 public:
  static std::wstring utf8_to_wstring(structure::t_const_str_box strboxUtf8);

 private:
  static void helper__replace_rn_to_n(std::wstring* pwstr);

 private:
  static bool helper__bug_check(TTSO_Tracer&                   tracer,
                                const structure::t_err_record* pErrorRec,
                                wstr_box_type                  ucs2Place,
                                wstr_box_type                  ucs2Point,
                                wstr_box_type                  ucs2Reason);

 private:
  template<size_t sz>
  static const wchar_t* get_unsigned_int_sign();

  template<>
  static const wchar_t* get_unsigned_int_sign<4>() {return L"unsigned __int32";};

  template<>
  static const wchar_t* get_unsigned_int_sign<8>() {return L"unsigned __int64";};

 private:
  static std::wstring IBP_EscapingText(structure::t_const_wstr_box text);
};//class TestCheckErrors

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp_tests*/}/*nms lcpi*/
#endif
