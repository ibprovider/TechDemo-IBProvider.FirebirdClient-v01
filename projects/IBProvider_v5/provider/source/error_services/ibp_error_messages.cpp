////////////////////////////////////////////////////////////////////////////////
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_messages.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//XML Config Loader Messages

#if(IBP_CFG_HAS_MODULE_CONFIG!=0)

extern const char me_xcfg_unk_tag_3[]
 ="[xcfg] unknown tag [%1].\n"
  "line %2. column %3.";

extern const char me_xcfg_unk_symbols_2[]
 ="[xcfg] unknown symbols. line %1. column %2.";

//key name, attr name, line, col
extern const char me_xcfg_fail_read_attr_4[]
 ="[xcfg] fail read attribute [%2] of key [%1].\n"
  "line %3. column %4.";

//key name, attr name, line, col
extern const char me_xcfg_fail_bad_attr_value_4[]
 ="[xcfg] bad value of attribute [%1] of key [%1].\n"
  "line %3. column %4.";

//param name, line, col
extern const char me_xcfg_multi_decl_of_param_3[]
 ="[xcfg] multiple declaration for parameter [%1].\n"
  "line %3. column %4.";

//param, line, col
extern const char me_xcfg_param_not_found_3[]
 ="[xcfg] parameter [%1] not found.\n"
  "line %2. column %3.";

#endif // IBP_CFG_HAS_MODULE_CONFIG!=0

////////////////////////////////////////////////////////////////////////////////
//Hash Segment File Errors

extern const wchar_t me_ibp_hsf__wrong_writer_thread_wait_result_code_1[]
 =L"[ibp hsf] Wrong wait result code in writer thread: %1";

////////////////////////////////////////////////////////////////////////////////
//BUG CHECKS

extern const wchar_t me_bug_check__bad_name_of_database_default_charset_0[]
 =L"bad name of database default charset";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__bad_name_of_database_default_charset_collation_0[]
 =L"bad name of database default charset collation";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__unexpected_connection_dialect_1[]
 =L"unexpected connection dialect [%1]";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__unexpected_database_dialect_1[]
 =L"unexpected database dialect [%1]";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__database_dialect_not_defined_0[]
 =L"database dialect not defined";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__no_data_source[]
 =L"no data source";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__unexpected_situation_0[]
 =L"unexpected situation";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__incorrect_usage_of_method_0[]
 =L"incorrect usage of method";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__pstmt_not_support_IColumnsRowset_0[]
 =L"Current pstmt does not support the IColumnsRowset";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__result_set_not_support_IColumnsRowset_0[]
 =L"ResultSet does not support the IColumnsRowset";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__rw_rowset__pending_list__double_linked_list_is_corrupted_0[]
 =L"Double linked list of pending changes is corrupted";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__rw_rowset__row_list__double_linked_list_is_corrupted_0[]
 =L"Double linked list of rows is corrupted";

//------------------------------------------------------------------------
//Неизвестное состояние значения поля
//Params: column name, state
extern const wchar_t me_bug_check__rw_rowset__unexpected_field_state_2[]
 =L"Unexpected state of column field [%1]: %2";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__unexpected_dbvariant_compare_result_1[]
 =L"Unexpected result of DBVARIANT comparison [%1]";

//------------------------------------------------------------------------
//Неизвестный идентификатор маркера запроса
//Params: marker kind id
extern const wchar_t me_bug_check__unexpected_cmd_parameter_marker_kind_id_1[]
 =L"Unexpected command parameter marker kind id [%1]";

//------------------------------------------------------------------------
//No numeric value scale
extern const wchar_t me_bug_check__no_numeric_value_scale_0[]
  =L"no numeric value scale";

//------------------------------------------------------------------------
//Wrong numeric value scale
//Params: actual scale, expected scale
extern const wchar_t me_bug_check__wrong_numeric_value_scale_2[]
  =L"wrong numeric value scale: %1. Expected scale: %2";

//------------------------------------------------------------------------
//The unexpected internal dbtype
//Params: type sign
extern const wchar_t me_bug_check__unexpected_internal_dbtype_1[]
  =L"the unexpected internal dbtype [%1]";

//------------------------------------------------------------------------
//The internal dbtype is not supported
//Params: type sign
extern const wchar_t me_bug_check__internal_dbtype_is_not_supported_1[]
  =L"the internal dbtype [%1] is not supported";

//------------------------------------------------------------------------
//The unknown write mode of column values
//Params: write mode id
extern const wchar_t me_bug_check__unknown__row_write_mode_1[]
 =L"the unknown write mode of column values [%1]";

//------------------------------------------------------------------------
//The unexpected write mode of column values
//Params: write mode id
extern const wchar_t me_bug_check__unexpected__row_write_mode_1[]
 =L"the unexpected write mode of column values [%1]";

//------------------------------------------------------------------------
//The columns were not described after second attempt
//Params: sqln, sqld
extern const wchar_t
 me_bug_check__columns_were_not_described_after_second_attempt_2[]
  =L"columns were not described after second attempt [sqln: %1; sqld: %2]";

//------------------------------------------------------------------------
//The parameters were not described after second attempt
//Params: sqln, sqld
extern const wchar_t
 me_bug_check__parameters_were_not_described_after_second_attempt_2[]
  =L"parameters were not described after second attempt [sqln: %1; sqld: %2]";

//------------------------------------------------------------------------
//The unstable sqld of row
//Params: sqld1, sqld2
extern const wchar_t
 me_bug_check__unstable_row_sqld_2[]
  =L"an unstable sqld of row: [%1] and [%2]";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__prop__unexpected_value_type_2[]
 =L"unexpected setting [%1] value type: %2";

extern const wchar_t me_bug_check__prop__unexpected_value_2[]
 =L"unknown value [%2] in [%1] setting";

extern const wchar_t me_bug_check__prop__not_defined_1[]
 =L"value of property \"%1\" not defined";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__varchar__incorrect_length_1[]
 =L"incorrect length of varchar data: %1";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__varchar__length_is_greater_than_buffer_size_2[]
 =L"the length of varchar data (%1) is greater than the buffer length (%2)";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__size_of_result_data_larger_than_buf_size_2[]
 =L"the size [%1] of the resulting data is larger than the buffer size [%2]";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__size_of_result_data_larger_than_buf_size_3[]
 =L"the size [%2] of the resulting data [tag: %1] is larger than the buffer size [%3]";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__incorrect_length_of_data_1[]
 =L"incorrect length [%1] of data";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__incorrect_length_of_data_2[]
 =L"incorrect length [%2] of data [tag: %1]";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__incorrect_format_of_element_1[]
 =L"incorrect format of element [tag: %1]";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__unexpected_block_count_2[]
 =L"unexpected number of blocks: %1. expected: %2";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__unexpected_end_of_buffer_0[]
 =L"unexpected end of buffer";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__unk_element_in_info_buffer_1[]
 =L"the unexpected element [tag: %1] in the information buffer";

//------------------------------------------------------------------------
extern const wchar_t me_bug_check__mult_def_of_element_in_info_buf_1[]
 =L"the multiple definition of element [tag: %1] in the information buffer";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__send_packet_with_unk_operation_1[]
 =L"sending of packet with unexpected operation id: %1";

extern const wchar_t me_bug_check__unexpected_protocol_version_1[]
 =L"unexpected protocol version: %1";

extern const wchar_t me_bug_check__mistake_in_list_with_protocol_architectures_0[]
 =L"mistake in list with protocol architectures";

extern const wchar_t me_bug_check__mult_enum_of_protocol_architecture_1[]
 =L"multiple enumerations of protocol architecture [%1]";

extern const wchar_t me_bug_check__empty_list_of_protocol_architectures_0[]
 =L"empty list of valid architectures for connection protocol";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__no_active_connection_0[]
 =L"no active connection";

extern const wchar_t me_bug_check__bad_cn_handle_0[]
 =L"bad connection handle";

extern const wchar_t me_bug_check__bad_tr_handle_0[]
 =L"bad transaction handle";

extern const wchar_t me_bug_check__tr_handle_not_zero_0[]
 =L"transaction handle not zero";

extern const wchar_t me_bug_check__bad_stmt_handle_0[]
 =L"bad statement handle";

extern const wchar_t me_bug_check__stmt_handle_not_zero_0[]
 =L"statement handle not zero";

extern const wchar_t me_bug_check__blob_handle_not_zero_0[]
 =L"blob handle not zero";

extern const wchar_t me_bug_check__bad_blob_handle_0[]
 =L"bad blob handle";

extern const wchar_t me_bug_check__incorect_blob_handle_mode_1[]
 =L"incorrect blob handle mode: %1";

extern const wchar_t me_bug_check__empty_block_with_blob_data_0[]
 =L"empty block with blob data";

extern const wchar_t me_bug_check__incorrect_blob_data_buffer_format_0[]
 =L"incorrect blob data buffer format";

extern const wchar_t me_bug_check__incorrect_blob_data_buffer_format__wrong_fragment_length_2[]
 =L"incorrect blob data buffer format. fragment length: %1. buffer tail length: %2";

extern const wchar_t me_bug_check__unexpected_blob_read_result_1[]
 =L"unexpected blob read result: %1";

extern const wchar_t me_bug_check__target_buffer_length_less_than_required_2[]
 =L"target buffer size [%1] less than required [%2]";

extern const wchar_t me_bug_check__array_slice_size_not_equal_to_expected_2[]
 =L"array slice size [%1] is not equal to the expected [%2]";

extern const wchar_t me_bug_check__detected_a_recursive_processing_of_pending_response_packets_0[]
 =L"detected a recursive processing of pending response packets";

extern const wchar_t me_bug_check__we_expected_the_error_0[]
 =L"we expected the error";

extern const wchar_t me_bug_check__garbage_in_alignment_bytes_1[]
 =L"the garbage in alignment bytes of [%1]";

extern const wchar_t me_bug_check__defer_execution_of_stmt_with_out_params_not_supported_0[]
 =L"deferred execution of statement with OUT-parameters not supported";

extern const wchar_t me_bug_check__unsupported_stmt_kind__BLOB_0[]
 =L"unsupported statement kind [BLOB]";

extern const wchar_t me_bug_check__no_write_func_for_array_elements_1[]
 =L"no write function for array elements with dbtype [%1]";

extern const wchar_t me_bug_check__too_large_number_of_RPT_elements_2[]
 =L"too large number of RPT elements: %1. max: %2";

////////////////////////////////////////////////////////////////////////////////

//params: length
extern const wchar_t me_bug_check__too_large_length_of_network_address_1[]
 =L"too large address length: %1";

////////////////////////////////////////////////////////////////////////////////

//params: gspi code, sp name
extern const wchar_t me_bug_check__unexpected_gspi_code_2[]
 =L"unexpected gspi-code: %1. sp name: [%2]";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__unknown_wire_crypt_permission_1[]
 =L"unknown wire crypt permission: %1";

extern const wchar_t me_bug_check__unknown_wire_compression_rule_1[]
 =L"unknown wire compression rule: %1";

extern const wchar_t me_bug_check__crypt_key_cant_be_empty_0[]
 =L"cryptographic key can not be empty";

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t me_bug_check__auth_err__incorrect_length_of_auth_data_1[]
 =L"incorrect length of auth data: %1";

extern const wchar_t me_bug_check__auth_err__incorrect_length_of_auth_data_2[]
 =L"incorrect length of auth data: %1, expected length: %2";

extern const wchar_t me_bug_check__auth_err__too_long_auth_data_2[]
 =L"incorrect length of auth data: %1, max allowed length: %2";

extern const wchar_t me_bug_check__auth_err__incorrect_server_key_0[]
 =L"incorrect server key";

////////////////////////////////////////////////////////////////////////////////
//Win32 Errors

//params: temp path
extern const wchar_t me_bug_check__win32_err__incorrect_work_of_GetTempFileName_1[]
 =L"incorrect work of GetTempFileName";

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
