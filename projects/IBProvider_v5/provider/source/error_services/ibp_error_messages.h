////////////////////////////////////////////////////////////////////////////////
//Шаблоны служебных сообщений об ошибках модуля.
//                                               Коваленко Дмитрий. 26.10.2005.
#ifndef _ibp_error_messages_H_
#define _ibp_error_messages_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

#ifndef IBP_CFG_HAS_MODULE_CONFIG
# error IBP_CFG_HAS_MODULE_CONFIG not defined!
#endif

////////////////////////////////////////////////////////////////////////////////
//XML Config Loader Messages

#if(IBP_CFG_HAS_MODULE_CONFIG!=0)

extern const char me_xcfg_unk_tag_3[];

extern const char me_xcfg_unk_symbols_2[];

extern const char me_xcfg_fail_read_attr_4[]; //key name, attr name, line, col

extern const char me_xcfg_fail_bad_attr_value_4[]; //key name, attr name, line, col

extern const char me_xcfg_multi_decl_of_param_3[]; //param name, line, col

extern const char me_xcfg_param_not_found_3[]; //param, line, col

#endif

////////////////////////////////////////////////////////////////////////////////
//Hash Segment File Errors

extern const wchar_t me_ibp_hsf__wrong_writer_thread_wait_result_code_1[];

////////////////////////////////////////////////////////////////////////////////
//BUG CHECKS

extern const wchar_t
 me_bug_check__bad_name_of_database_default_charset_0[];

extern const wchar_t
 me_bug_check__bad_name_of_database_default_charset_collation_0[];

//params: dialect
extern const wchar_t
 me_bug_check__unexpected_connection_dialect_1[];

//params: dialect
extern const wchar_t
 me_bug_check__unexpected_database_dialect_1[];

extern const wchar_t
 me_bug_check__database_dialect_not_defined_0[];

extern const wchar_t
 me_bug_check__no_data_source[];

//непонятная ситуация
extern const wchar_t
 me_bug_check__unexpected_situation_0[];

//некорректное использование метода
extern const wchar_t
 me_bug_check__incorrect_usage_of_method_0[];

//PStmt объект не предоставляет поддержку для IColumnsRowset
extern const wchar_t
 me_bug_check__pstmt_not_support_IColumnsRowset_0[];

//Курсор результирующего множества не поредоставляет поддержку для IColumnsRowset
extern const wchar_t
 me_bug_check__result_set_not_support_IColumnsRowset_0[];

//Поврежден двунаправленный список отложенных изменений
extern const wchar_t
 me_bug_check__rw_rowset__pending_list__double_linked_list_is_corrupted_0[];

//Поврежден двунаправленный список рядов
extern const wchar_t
 me_bug_check__rw_rowset__row_list__double_linked_list_is_corrupted_0[];

//Неизвестное состояние значения поля
//Params: column name, state
extern const wchar_t
 me_bug_check__rw_rowset__unexpected_field_state_2[];

//Неожиданный результат сравнения двух DBVARIANT
//params: result_code
extern const wchar_t
 me_bug_check__unexpected_dbvariant_compare_result_1[];

//Неизвестный идентификатор маркера запроса
//Params: marker kind id
extern const wchar_t
 me_bug_check__unexpected_cmd_parameter_marker_kind_id_1[];

//No numeric value scale
extern const wchar_t
 me_bug_check__no_numeric_value_scale_0[];

//Wrong numeric value scale
//Params: actual scale, expected scale
extern const wchar_t
 me_bug_check__wrong_numeric_value_scale_2[];

//The unexpected internal dbtype
//Params: dbtype sign
extern const wchar_t
 me_bug_check__unexpected_internal_dbtype_1[];

//The internal dbtype is not supported
//Params: dbtype sign
extern const wchar_t
 me_bug_check__internal_dbtype_is_not_supported_1[];

//The unknown write mode of column values
//Params: write mode id
extern const wchar_t
 me_bug_check__unknown__row_write_mode_1[];

//The unexpected write mode of column values
//Params: write mode id
extern const wchar_t
 me_bug_check__unexpected__row_write_mode_1[];

//The columns were not described after second attempt
//Params: sqln, sqld
extern const wchar_t
 me_bug_check__columns_were_not_described_after_second_attempt_2[];

//The parameters were not described after second attempt
//Params: sqln, sqld
extern const wchar_t
 me_bug_check__parameters_were_not_described_after_second_attempt_2[];

//The unstable sqld of row
//Params: sqld1, sqld2
extern const wchar_t
 me_bug_check__unstable_row_sqld_2[];

////////////////////////////////////////////////////////////////////////////////

//Неизвестный тип значения свойства
// prop_name, prop_value_type
extern const wchar_t
 me_bug_check__prop__unexpected_value_type_2[];

//Неизвестное значение свойства
// prop_name, prop_value
extern const wchar_t
 me_bug_check__prop__unexpected_value_2[];

//Неопределено значение свойства
// prop_name
extern const wchar_t
 me_bug_check__prop__not_defined_1[];

////////////////////////////////////////////////////////////////////////////////

//некорректная (отрицательная?) длина данных
//params: varchar length
extern const wchar_t
 me_bug_check__varchar__incorrect_length_1[];

//длина varchar данных превышает размер буфера
//params: varchar length, buffer length
extern const wchar_t
 me_bug_check__varchar__length_is_greater_than_buffer_size_2[];

////////////////////////////////////////////////////////////////////////////////

//Размер полученных данных больше размера буфера
//params: data size, buffer size
extern const wchar_t
 me_bug_check__size_of_result_data_larger_than_buf_size_2[];

//Размер полученных данных больше размера буфера
//params: data id, data size, buffer size
extern const wchar_t
 me_bug_check__size_of_result_data_larger_than_buf_size_3[];

//Некорректный размер данных
//params: length
extern const wchar_t
 me_bug_check__incorrect_length_of_data_1[];

//Некорректный размер данных
//params: data id, length
extern const wchar_t
 me_bug_check__incorrect_length_of_data_2[];

//Некорректные формат элемента
//params: data id
extern const wchar_t
 me_bug_check__incorrect_format_of_element_1[];

//Неожиданное количество блоков
//params: actualCount, expectedCount
extern const wchar_t
 me_bug_check__unexpected_block_count_2[];

////////////////////////////////////////////////////////////////////////////////

//Неожиданное завершение буфера
extern const wchar_t
 me_bug_check__unexpected_end_of_buffer_0[];

//Неизвестный элемент в информационном буфере
//params: cluster id
extern const wchar_t
 me_bug_check__unk_element_in_info_buffer_1[];

//Многократное определение элемента в информационном буфере
extern const wchar_t
 me_bug_check__mult_def_of_element_in_info_buf_1[];

////////////////////////////////////////////////////////////////////////////////

//Отправка пакета с неизвестным идентификатором операции
//params: operation id
extern const wchar_t
 me_bug_check__send_packet_with_unk_operation_1[];

//Неизвестная версия протокола взаимодействия
//params: version id
extern const wchar_t
 me_bug_check__unexpected_protocol_version_1[];

//ошибка в списке архитектур протокола соединения
extern const wchar_t
 me_bug_check__mistake_in_list_with_protocol_architectures_0[];

//многократное указание архитектуры протокола подключения
//params: name of architecture
extern const wchar_t
 me_bug_check__mult_enum_of_protocol_architecture_1[];

//пустой список с перечислением архитектур протокола
extern const wchar_t
 me_bug_check__empty_list_of_protocol_architectures_0[];

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t
 me_bug_check__no_active_connection_0[];

extern const wchar_t
 me_bug_check__bad_cn_handle_0[];

extern const wchar_t
 me_bug_check__bad_tr_handle_0[];

extern const wchar_t
 me_bug_check__tr_handle_not_zero_0[];

extern const wchar_t
 me_bug_check__bad_stmt_handle_0[];

extern const wchar_t
 me_bug_check__stmt_handle_not_zero_0[];

extern const wchar_t
 me_bug_check__blob_handle_not_zero_0[];

extern const wchar_t
 me_bug_check__bad_blob_handle_0[];

extern const wchar_t
 me_bug_check__incorect_blob_handle_mode_1[];

extern const wchar_t
 me_bug_check__empty_block_with_blob_data_0[];

extern const wchar_t
 me_bug_check__incorrect_blob_data_buffer_format_0[];

//params: fragment length, buffer tail length
extern const wchar_t
 me_bug_check__incorrect_blob_data_buffer_format__wrong_fragment_length_2[];

extern const wchar_t
 me_bug_check__unexpected_blob_read_result_1[];

//params: buffer capacity, required size
extern const wchar_t
 me_bug_check__target_buffer_length_less_than_required_2[];

//params: slice size, expected size
extern const wchar_t
 me_bug_check__array_slice_size_not_equal_to_expected_2[];

extern const wchar_t
 me_bug_check__detected_a_recursive_processing_of_pending_response_packets_0[];

extern const wchar_t
 me_bug_check__we_expected_the_error_0[];

//params: data sign
extern const wchar_t
 me_bug_check__garbage_in_alignment_bytes_1[];

extern const wchar_t
 me_bug_check__defer_execution_of_stmt_with_out_params_not_supported_0[];

extern const wchar_t
 me_bug_check__unsupported_stmt_kind__BLOB_0[];

//params: dbtypeID
extern const wchar_t
 me_bug_check__no_write_func_for_array_elements_1[];

//params: actualCount, maxCount
extern const wchar_t
 me_bug_check__too_large_number_of_RPT_elements_2[];

////////////////////////////////////////////////////////////////////////////////

//params: length
extern const wchar_t
 me_bug_check__too_large_length_of_network_address_1[];

////////////////////////////////////////////////////////////////////////////////

//params: gspi code, sp name
extern const wchar_t
 me_bug_check__unexpected_gspi_code_2[];

////////////////////////////////////////////////////////////////////////////////

extern const wchar_t
 me_bug_check__unknown_wire_crypt_permission_1[];

extern const wchar_t
 me_bug_check__unknown_wire_compression_rule_1[];

extern const wchar_t
 me_bug_check__crypt_key_cant_be_empty_0[];

////////////////////////////////////////////////////////////////////////////////

//params: length
extern const wchar_t
 me_bug_check__auth_err__incorrect_length_of_auth_data_1[];

//params: length, expected length
extern const wchar_t
 me_bug_check__auth_err__incorrect_length_of_auth_data_2[];

//params: length, max length
extern const wchar_t
 me_bug_check__auth_err__too_long_auth_data_2[];

extern const wchar_t
 me_bug_check__auth_err__incorrect_server_key_0[];

////////////////////////////////////////////////////////////////////////////////
//Win32 Errors

//params: temp path
extern const wchar_t
 me_bug_check__win32_err__incorrect_work_of_GetTempFileName_1[];

////////////////////////////////////////////////////////////////////////////////

//params: oledb type id
extern const wchar_t
 me_bug_check__unknown_oledb_type_id_1[];

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
