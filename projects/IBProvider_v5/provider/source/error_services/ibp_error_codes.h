////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_codes.h
//! \brief   Список идентификаторов ошибок
//! \author  Kovalenko Dmitry
//! \date    31.10.2005
#ifndef _ibp_error_codes_H_
#define _ibp_error_codes_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include <structure/t_common.h>
#include "rc/ibp_msg_err_ids.rh"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//Коды ошибок

/// <summary>
///  Типизированные идентификаторы ошибок
/// </summary>
//! \attention
//!  Желательно синхронизировать с константой ibp_limc_MaxErrorArgsCount
enum ibp_msg_code_type
{
 //код ошибки, передающей свое описание в параметрах
 //[0] - Description
 ibp_mce_unknown_error_1
  =IBP_MCE_UNKNOWN_ERROR_1,

 /// \brief
 ///  Ошибка WIN32.<br>
 /// \b
 ///  Params: error code, error message
 ibp_mce__error_from_win32_2
  =IBP_MCE__ERROR_FROM_WIN32_2,

 /// \brief
 ///  Ошибка DOS.<br>
 /// \b
 ///  Params: error code
 ibp_mce__error_from_dos_1
  =IBP_MCE__ERROR_FROM_DOS_1,

 /// \brief
 ///  Ошибка NeXt/Mach.<br>
 /// \b
 ///  Params: error code
 ibp_mce__error_from_next_mach_1
  =IBP_MCE__ERROR_FROM_NEXT_MACH_1,

 /// \brief
 ///  Ошибка UNIX.<br>
 /// \b
 ///  Params: error code, error msg
 ibp_mce__error_from_unix_2
  =IBP_MCE__ERROR_FROM_UNIX_2,

 /// \brief
 ///  Неизвестная ISC-ошибка.<br>
 /// \b
 ///  Params: error code
 ibp_mce__unexpected_isc_error_1
  =IBP_MCE__UNEXPECTED_ISC_ERROR_1,

 /// \brief
 ///  Неизвестное ISC-предупреждение.<br>
 /// \b
 ///  Params: warning code
 ibp_mce__unexpected_isc_warning_1
  =IBP_MCE__UNEXPECTED_ISC_WARNING_1,

 //text ------------------------------------------------------------------
 /// \brief Не определена
 ibp_mce_text__not_defined1_0
  =IBP_MCE_TEXT__NOT_DEFINED1_0,

 /// \brief Не определен
 ibp_mce_text__not_defined2_0
  =IBP_MCE_TEXT__NOT_DEFINED2_0,

 /// \brief Не определено
 ibp_mce_text__not_defined3_0
  =IBP_MCE_TEXT__NOT_DEFINED3_0,

 /// \brief Не определены
 ibp_mce_text__not_defined4_0
  =IBP_MCE_TEXT__NOT_DEFINED4_0,

 //-----------------------------------------
 /// \brief массив
 ibp_mce_text__array_0
  =IBP_MCE_TEXT__ARRAY_0,

 /// \brief не массив
 ibp_mce_text__not_array_0
  =IBP_MCE_TEXT__NOT_ARRAY_0,

 //-----------------------------------------
 /// \brief Недоступно
 ibp_mce_text__unavailable_0
  =IBP_MCE_TEXT__UNAVAILABLE_0,

 //-----------------------------------------
 /// \brief Неизвестная ошибка
 ibp_mce_text__unknown_error1_0
  =IBP_MCE_TEXT__UNKNOWN_ERROR1_0,

 //-----------------------------------------
 ibp_mce_text__addition_0
  =IBP_MCE_TEXT__ADDITION_0,

 //-----------------------------------------
 ibp_mce_text__subtraction_0
  =IBP_MCE_TEXT__SUBTRACTION_0,

 //-----------------------------------------
 ibp_mce_text__multiplication_0
  =IBP_MCE_TEXT__MULTIPLICATION_0,

 //-----------------------------------------
 ibp_mce_text__division_0
  =IBP_MCE_TEXT__DIVISION_0,

 //features errors -------------------------------------------------------
 ibp_mce_fe_features_not_available_in_free_edition_1
  =IBP_MCE_FE_FEATURES_NOT_AVAILABLE_IN_FREE_EDITION_1,

 ibp_mce_fe_trial_expired_1
  =IBP_MCE_FE_TRIAL_EXPIRED_1,

 ibp_mce_fe_free_edition_not_support_this_server_3
  =IBP_MCE_FE_FREE_EDITION_NOT_SUPPORT_THIS_SERVER_3,

 //User interface errors -------------------------------------------------
 ibp_mce_ui__fail_create_provider_1
  =IBP_MCE_UI__FAIL_CREATE_PROVIDER_1,

 ibp_mce_ui__fail_query_interface_2
  =IBP_MCE_UI__FAIL_QUERY_INTERFACE_2,

 ibp_mce_ui__fail_set_property_3
  =IBP_MCE_UI__FAIL_SET_PROPERTY_3,

 ibp_mce_ui__fail_initalize_2
  =IBP_MCE_UI__FAIL_INITALIZE_2,

 ibp_mce_ui__fail_uninitalize_2
  =IBP_MCE_UI__FAIL_UNINITALIZE_2,

 ibp_mce_ui__error_text_unavailable_0
  =IBP_MCE_UI__ERROR_TEXT_UNAVAILABLE_0,

 ///////////////////////////////////////////////////////////////////////////////
 //Common errors

 //-----------------------------------------------------------------------
 /// \brief
 ///  Unsupported COM API.<br>
 /// \b
 ///  Params: Required COM API ID, Supported COM API ID
 ibp_mce_common__unsupported_com_api_2
  =IBP_MCE_COMMON__UNSUPPORTED_COM_API_2,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Достигнут лимит на количество ошибок. Часть последующих сообщений будет проигнорирована.
 ibp_mce_common__err_count_limit_was_reached_0
  =IBP_MCE_COMMON__ERR_COUNT_LIMIT_WAS_REACHED_0,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Универсальное сообщение о BUG-CHECK сбое.<br>
 /// \b
 ///  Params: place, point, reason
 ibp_mce_common__bug_check_3
  =IBP_MCE_COMMON__BUG_CHECK_3,

 //-----------------------------------------------------------------------
 //Ошибка преобразования размера из одного типа в другой
 //source [1], value_name [2], source_value [3], dest_max_value [4]
 ibp_mce_common__fail_size_cast_4
  =IBP_MCE_COMMON__FAIL_SIZE_CAST_4,

 //argument-name, value
 ibp_mce_common__invalid_arg_2
  =IBP_MCE_COMMON__INVALID_ARG_2,

 //Ошибка преобразования числа из одного типа в другой
 //source [1], value_name [2], source_value [3], dest_min_value [4], dest_max_value [5]
 ibp_mce_common__fail_numeric_cast_5
  =IBP_MCE_COMMON__FAIL_NUMERIC_CAST_5,

 /// \brief
 ///  Переполнение в процессе расчета размера памяти под данные.<br>
 /// \b
 ///  Params: method, point
 ibp_mce_common__overflow_in_mem_size_calculation_2
  =IBP_MCE_COMMON__OVERFLOW_IN_MEM_SIZE_CALCULATION_2,

 /// \brief
 ///  Неизвестный сервер базы данных.<br>
 /// \b
 ///  Params: проанализированная сигнатура сервера.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__unknown_dbms_1
  =IBP_MCE_COMMON__UNKNOWN_DBMS_1,

 /// \brief
 ///  Неизвестный клиент сервера базы данных.<br>
 /// \b
 ///  Params: проанализированная сигнатура клиента, dll path.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__unknown_dbms_client_2
  =IBP_MCE_COMMON__UNKNOWN_DBMS_CLIENT_2,

 /// \brief
 ///  Невозможно определить тип серверного клиента. Отсутствует ресурс VERSIONINFO.<br>
 /// \b
 ///  Params: dll path.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__cant_detect_dbms_client_type__no_versioninfo_1
  =IBP_MCE_COMMON__CANT_DETECT_DBMS_CLIENT_TYPE__NO_VERSIONINFO_1,

 /// \brief
 ///  Невозможно определить тип серверного клиента. В VERSIONINFO отсутствует описание продукта.<br>
 /// \b
 ///  Params: dll path.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__cant_detect_dbms_client_type__no_product_descr_1
  =IBP_MCE_COMMON__CANT_DETECT_DBMS_CLIENT_TYPE__NO_PRODUCT_DESCR_1,

 /// \brief
 ///  Невозможно определить тип серверного клиента. В VERSIONINFO отсутствует версия продукта.<br>
 /// \b
 ///  Params: dll path.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__cant_detect_dbms_client_type__no_product_version_1
  =IBP_MCE_COMMON__CANT_DETECT_DBMS_CLIENT_TYPE__NO_PRODUCT_VERSION_1,

 /// \brief
 ///  Formed buffer with parameters is too large.<br>
 /// \b
 ///  Params: bufTypeName, buf size, max size
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__formed_param_buf_is_too_large_3
  =IBP_MCE_COMMON__FORMED_PARAM_BUF_IS_TOO_LARGE_3,

 /// \brief
 ///  Ошибка конвертации системных данных в UNICODE.<br>
 /// \b
 ///  Params: data sign.
 ibp_mce_common__translate_sys_data_to_unicode_1
  =IBP_MCE_COMMON__TRANSLATE_SYS_DATA_TO_UNICODE_1,

 /// \brief
 ///  Database name length is too large.<br>
 /// \b
 ///  Params: name length, max length.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__database_name_length_is_too_large_2
  =IBP_MCE_COMMON__DATABASE_NAME_LENGTH_IS_TOO_LARGE_2,

 /// \brief
 ///  Ошибка конвертирования имени базы данных в кодовую страницу UTF8.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__failed_to_convert_db_name_to_utf8_0
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_DB_NAME_TO_UTF8_0,

 /// \brief
 ///  Ошибка конвертирования параметра подключения в кодовую страницу UTF8.<br>
 /// \b
 ///  Params: paramName
 ibp_mce_common__failed_to_convert_cn_param_to_utf8_1
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_CN_PARAM_TO_UTF8_1,

 /// \brief
 ///  Ошибка конвертирования имени хоста в системную кодовую страницу.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__failed_to_convert_dbms_host_name_to_system_codepage_0
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_DBMS_HOST_NAME_TO_SYSTEM_CODEPAGE_0,

 /// \brief
 ///  Ошибка конвертирования имени порта хоста в системную кодовую страницу.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__failed_to_convert_dbms_host_port_name_to_system_codepage_0
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_DBMS_HOST_PORT_NAME_TO_SYSTEM_CODEPAGE_0,

 /// \brief
 ///  Неподдерживаемая версия сервера базы данных.<br>
 /// \b
 ///  Params: проанализированная сигнатура сервера.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__unsupported_dbms_version_1
  =IBP_MCE_COMMON__UNSUPPORTED_DBMS_VERSION_1,

 /// \brief
 ///  Ошибка конвертирования имени базы данных в системную кодовую страницу.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__failed_to_convert_db_name_to_system_codepage_0
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_DB_NAME_TO_SYSTEM_CODEPAGE_0,

 /// \brief
 ///  Ошибка конвертирования параметра подключения в системную кодовую страницу.<br>
 /// \b
 ///  Params: paramName
 ibp_mce_common__failed_to_convert_cn_param_to_system_codepage_1
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_CN_PARAM_TO_SYSTEM_CODEPAGE_1,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Ошибка конвертирования из UNICODE в кодовую страницу.<br>
 /// \b
 ///  Params: charset name
 ibp_mce_common__failed_to_convert_from_unicode_to_charset_1
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_FROM_UNICODE_TO_CHARSET_1,

 //------------------------------------------------------------------------------
 /// \brief
 ///  Ошибка конвертирования из кодовой страницы в UNICODE.<br>
 /// \b
 ///  Params: charset name
 ibp_mce_common__failed_to_convert_from_charset_to_unicode_1
  =IBP_MCE_COMMON__FAILED_TO_CONVERT_FROM_CHARSET_TO_UNICODE_1,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Неподдерживаемый режим чтения/записи массивов базы данных.<br>
 /// \b
 ///  Params: mode, dbms sign
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__unsupported_array_rw_mode_2
  =IBP_MCE_COMMON__UNSUPPORTED_ARRAY_RW_MODE_2,

 //------------------------------------------------------------------------------
 /// \brief
 ///  Чтения/записи массивов базы данных собственными средствами провайдера
 ///  не поддерживается для подключенного сервера.<br>
 /// \b
 ///  Params: dbms sign, implementation data, ODS
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__direct_array_rw_not_supported_3
  =IBP_MCE_COMMON__DIRECT_ARRAY_RW_NOT_SUPPORTED_3,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Неподдерживаемая конфигурация подключения.<br>
 /// \b
 ///  Params: dbms sign, client sign, ODS
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__unsupported_cn_configuration_3
  =IBP_MCE_COMMON__UNSUPPORTED_CN_CONFIGURATION_3,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Auth data length is too large.<br>
 /// \b
 ///  Params: name length, max length.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_common__auth_data_length_is_too_large_2
  =IBP_MCE_COMMON__AUTH_DATA_LENGTH_IS_TOO_LARGE_2,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Ошибка вызова функции библиотеки libtommath [set01].<br>
 /// \b
 ///  Params: function name, error code, arguments
 ibp_mce_common__failed_to_call_libtommath_set01_func_3
  =IBP_MCE_COMMON__FAILED_TO_CALL_LIBTOMMATH_SET01_FUNC_3,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Ошибка конвертации системных данных из UNICODE.<br>
 /// \b
 ///  Params: data sign, target cs name
 ibp_mce_common__translate_sys_data_from_unicode_2
  =IBP_MCE_COMMON__TRANSLATE_SYS_DATA_FROM_UNICODE_2,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  DLL не содержит VERSIONINFO.<br>
 /// \b
 ///  Params: dll name.
 ibp_mce_common__dll_not_has_versioninfo_1
  =IBP_MCE_COMMON__DLL_NOT_HAS_VERSIONINFO_1,

 /// \brief
 ///  DLL VERSIONINFO не содержит описание файла.<br>
 /// \b
 ///  Params: dll name.
 ibp_mce_common__dll_versioninfo_not_has_file_descr_1
  =IBP_MCE_COMMON__DLL_VERSIONINFO_NOT_HAS_FILE_DESCR_1,

 /// \brief
 ///  DLL VERSIONINFO не содержит версии продукта.<br>
 /// \b
 ///  Params: dll name.
 ibp_mce_common__dll_versioninfo_not_has_prod_version_1
  =IBP_MCE_COMMON__DLL_VERSIONINFO_NOT_HAS_PROD_VERSION_1,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Произошли ошибки установки значений свойств.
 ibp_mce_common__failed_to_set_property_values_0
  =IBP_MCE_COMMON__FAILED_TO_SET_PROPERTY_VALUES_0,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Произошли ошибки установки значения свойства.<br>
 /// \b
 ///  Params: property name, status code
 ibp_mce_common__failed_to_set_property_value_2
  =IBP_MCE_COMMON__FAILED_TO_SET_PROPERTY_VALUE_2,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Ошибка приведения строки к верхнему регистру.<br>
 /// \b
 ///  Params: sourceSign, sourceLength, processedLength
 ibp_mce_common__failed_to_make_upper_str_3
  =IBP_MCE_COMMON__FAILED_TO_MAKE_UPPER_STR_3,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Ошибка приведения строки к нижнему регистру.<br>
 /// \b
 ///  Params: sourceSign, sourceLength, processedLength
 ibp_mce_common__failed_to_make_lower_str_3
  =IBP_MCE_COMMON__FAILED_TO_MAKE_LOWER_STR_3,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Database server version is not defined.<br>
 ibp_mce_common__no_dbms_version_0
  =IBP_MCE_COMMON__NO_DBMS_VERSION_0,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Unsupported type of timezones source.<br>
 /// \b
 ///  Params: type name.
 ibp_mce_common__unsupported_timezones_source_1
  =IBP_MCE_COMMON__UNSUPPORTED_TIMEZONES_SOURCE_1,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Can't calculate object name length.<br>
 /// \b
 ///  Params: error code sign
 ibp_mce_common__cant_calc_object_name_length_1
  =IBP_MCE_COMMON__CANT_CALC_OBJECT_NAME_LENGTH_1,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  The defined property value is not supported with current connection.<br>
 /// \b
 ///  Params: property name, property value sign, dbms sign
 ibp_mce_common__prop_value_is_not_supported_by_current_connection_3
  =IBP_MCE_COMMON__PROP_VALUE_IS_NOT_SUPPORTED_BY_CURRENT_CONNECTION_3,

 ///////////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  [BUG CHECK] Сервис не поддерживается.<br>
 /// \b
 ///  Params: service_guid, interface name
 ibp_mce_common__bug_check__svc_not_supported_2
  =IBP_MCE_COMMON__BUG_CHECK__SVC_NOT_SUPPORTED_2,

 /// \brief
 ///  [BUG CHECK] Сервис не поддерживает запрашиваемый интерфейс.<br>
 /// \b
 ///  Params: service_guid, interface name
 ibp_mce_common__bug_check__svc_not_support_req_interface_2
  =IBP_MCE_COMMON__BUG_CHECK__SVC_NOT_SUPPORT_REQ_INTERFACE_2,

 /// \brief
 ///  [BUG CHECK] Ошибка декодирования значения типа данных. Загружен блок данных с некорректным размером.<br>
 /// \b
 ///  Params: place, point, typeName, actualBlockSize, expectedBlockSize
 ibp_mce_common__bug_check__failed_to_decode_datatype__readed_block_has_wrong_size_5
  =IBP_MCE_COMMON__BUG_CHECK__FAILED_TO_DECODE_DATATYPE__READED_BLOCK_HAS_WRONG_SIZE_5,

 /// \brief
 ///  [BUG CHECK] Загружен блок данных с некорректным размером.<br>
 /// \b
 ///  Params: place, point, actualBlockSize, expectedBlockSize
 ibp_mce_common__bug_check__readed_block_has_wrong_size_4
  =IBP_MCE_COMMON__BUG_CHECK__READED_BLOCK_HAS_WRONG_SIZE_4,

 /// \brief
 ///  [BUG CHECK] Чтение значения колонки с недопустимым статусом.<br>
 /// \b
 ///  Params: place, point, field name, field index, field value status.
 ibp_mce_common__bug_check__cant_read_field_value_with_unexpected_status_5
  =IBP_MCE_COMMON__BUG_CHECK__CANT_READ_FIELD_VALUE_WITH_UNEXPECTED_STATUS_5,

 /// \brief
 ///  [BUG CHECK] Тестирование NULL-состояния значения колонки с недопустимым статусом.<br>
 /// \b
 ///  Params: place, point, field name, field index, field value status.
 ibp_mce_common__bug_check__cant_test_null_state_of_field_value_with_unexpected_status_5
  =IBP_MCE_COMMON__BUG_CHECK__CANT_TEST_NULL_STATE_OF_FIELD_VALUE_WITH_UNEXPECTED_STATUS_5,

 ///////////////////////////////////////////////////////////////////////////////

 //Reserved

 //неизвестный тип клиента базы данных
 ibp_mce_dbobj_unk_dbclient_type_1 //dbclient type
  =IBP_MCE_DBOBJ_UNK_DBCLIENT_TYPE_1,

 /// \brief
 ///  Ошибка получения сведений о сервере и базе данных.
 ///  Отсутствуют данные для некоторых тегов.<br>
 /// \b
 ///  Params: server sign, tag list.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_dbobj_fail_get_db_info__no_data_2
  =IBP_MCE_DBOBJ_FAIL_GET_DB_INFO__NO_DATA_2,

 /// \brief
 ///  Ошибка получения параметров сервера и базы данных.<br>
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_dbobj_fail_get_db_info_0
  =IBP_MCE_DBOBJ_FAIL_GET_DB_INFO_0,

 /// \brief
 ///  Ошибка получения параметров сервера и базы данных.
 ///  Буфер имеет недостаточный размер для получения запрашиваемых данных.<br>
 /// \b
 ///  Params: buf size.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_dbobj_fail_get_db_info__buf_is_small_1
  =IBP_MCE_DBOBJ_FAIL_GET_DB_INFO__BUF_IS_SMALL_1,

 /// \brief
 ///  Ошибка обработки информационного свойства со сведениями о сервере или базе данных.<br>
 /// \b
 ///  Params: tag id.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_dbobj__in_db_info_processing_error_occurred_1
  =IBP_MCE_DBOBJ__IN_DB_INFO_PROCESSING_ERROR_OCCURRED_1,

 /// \brief
 ///  Установка данных с неподдерживаемым внутренним типом данных.<br>
 /// \b
 ///  Params: index, internal_type_id
 /// \note
 ///  Тип сервера указывается через подсистему.
 ibp_mce_dbobj__ie_set_data_with_unk_internal_type_2
  =IBP_MCE_DBOBJ__IE_SET_DATA_WITH_UNK_INTERNAL_TYPE_2,

 /// \brief
 ///  Создание блоба с неизвестным внутренним типом данных.<br>
 /// \b
 ///  Params: index, internal_type_id
 /// \note
 ///  Тип сервера указывается через подсистему.
 ibp_mce_dbobj__ie_create_blob_with_unk_internal_type_2
  =IBP_MCE_DBOBJ__IE_CREATE_BLOB_WITH_UNK_INTERNAL_TYPE_2,

 /// \brief
 ///  Данные с неподдерживаемым серверным sql-типом данных.<br>
 /// \b
 ///  Params: index, native_type_id
 /// \note
 ///  Тип сервера указывается через подсистему.
 ibp_mce_dbobj__ie_data_with_unk_sql_type_2
  =IBP_MCE_DBOBJ__IE_DATA_WITH_UNK_SQL_TYPE_2,

 /// \brief
 ///  Неизвестный серверный blr-тип элементов массива.<br>
 /// \b
 ///  Params: blr_type, table_name, column_name, server-title, client-title
 /// \note
 ///  Нужно еще указывать подсистему, в которой произошла данная ошибка.
 ibp_mce_dbobj__ie_unk_array_element_blr_type_5
  =IBP_MCE_DBOBJ__IE_UNK_ARRAY_ELEMENT_BLR_TYPE_5,

 //ошибка конвертирования данных
 ibp_mce_dbobj_cant_convert_value_between_internal_types_2 //from,to
  =IBP_MCE_DBOBJ_CANT_CONVERT_VALUE_BETWEEN_INTERNAL_TYPES_2,

 /// \brief Превышение максимальной длины строки.<br>
 /// \b Params: value length, column size
 ibp_mce_dbobj_string_overflow_2
  =IBP_MCE_DBOBJ_STRING_OVERFLOW_2,

 //ошибка масштабирования NUMERIC значения
 ibp_mce_dbobj_fail_scale_numeric_0
  =IBP_MCE_DBOBJ_FAIL_SCALE_NUMERIC_0,

 //ошибка сохранения NUMERIC значения в {short,long,int64} формате
 ibp_mce_dbobj_fail_save_numeric_as_native_type_1
  =IBP_MCE_DBOBJ_FAIL_SAVE_NUMERIC_AS_NATIVE_TYPE_1,

 //некорректный масштаб числовой колонки.
 ibp_mce_dbobj_invalid_numeric_column_scale_2 //base_type={short,long,...},scale
  =IBP_MCE_DBOBJ_INVALID_NUMERIC_COLUMN_SCALE_2,

 //некорректный масштаб колонки с массивом
 ibp_mce_dbobj_invalid_numeric_array_scale_4 //base_type,scale,table_name,column_name
  =IBP_MCE_DBOBJ_INVALID_NUMERIC_ARRAY_SCALE_4,

 //Reserved

 //неподдерживаемая размерность массива
 ibp_mce_dbobj_unsupport_array_dimensions_3 //table_name,column_name,dimensions
  =IBP_MCE_DBOBJ_UNSUPPORT_ARRAY_DIMENSIONS_3,

 //некорректные границы одного из измерений массива
 ibp_mce_dbobj_bad_array_bounds_5     //table_name,column_name,dimension,
  =IBP_MCE_DBOBJ_BAD_ARRAY_BOUNDS_5,  //lower_bound,upper_bound

 //внутренняя ошибка чтения массива. Некорректное число прочитанных байт
 ibp_mce_dbobj_ibf_ra_bad_array_cb_readed_4 //table,column,actual_readed,need
  =IBP_MCE_DBOBJ_IBF_RA_BAD_ARRAY_CB_READED_4,

 //неизвестное имя колонки
 ibp_mce_dbobj_unk_column_name_1
  =IBP_MCE_DBOBJ_UNK_COLUMN_NAME_1,

 //поле содержит NULL
 // params: field_index, field_name
 ibp_mce_dbobj_field_has_null_2
  =IBP_MCE_DBOBJ_FIELD_HAS_NULL_2,

 //некорректная точность числовой колонки.
 ibp_mce_dbobj_invalid_numeric_column_precision_2 //base_type={short,long,...},scale
  =IBP_MCE_DBOBJ_INVALID_NUMERIC_COLUMN_PRECISION_2,

 //-----------------------------------------------------------------------

 /// \brief Получено пустое результирующее множество.
 ibp_mce_dbobj_resultset_is_empty_0
  =IBP_MCE_DBOBJ_RESULTSET_IS_EMPTY_0,

 /// \brief Получено результирующее множество с более чем одним рядом.
 ibp_mce_dbobj_resultset_contains_more_that_one_row_0
  =IBP_MCE_DBOBJ_RESULTSET_CONTAINS_MORE_THAT_ONE_ROW_0,

 /// \brief Ошибка получения уникального идентификатора.<br>
 /// \b Params: generator name
 ibp_mce_dbobj_cant_generate_unique_id_1
  =IBP_MCE_DBOBJ_CANT_GENERATE_UNIQUE_ID_1,

 /// \brief Загрузка списка колонок первичного ключа таблицы.<br>
 /// \b Params: TableName
 ibp_mce_dbobj_load_pk_columns_list_of_table_1
  =IBP_MCE_DBOBJ_LOAD_PK_COLUMNS_LIST_OF_TABLE_1,

 /// \brief Загрузка списка обновляемых колонок таблицы.<br>
 /// \b Params: TableName
 ibp_mce_dbobj_load_updatable_columns_list_of_table_1
  =IBP_MCE_DBOBJ_LOAD_UPDATABLE_COLUMNS_LIST_OF_TABLE_1,

 //-----------------------------------------------------------------------
 //service_guid
 ibp_mce_dbobj_ie_svc_not_supported_1
  =IBP_MCE_DBOBJ_IE_SVC_NOT_SUPPORTED_1,

 //service_guid, interface_name
 ibp_mce_dbobj_ie_svc_not_support_req_interface_2
  =IBP_MCE_DBOBJ_IE_SVC_NOT_SUPPORT_REQ_INTERFACE_2,

 //превышение максимальной длины бинарных данных
 ibp_mce_dbobj_binary_overflow_2 //need,max
  =IBP_MCE_DBOBJ_BINARY_OVERFLOW_2,

 ibp_mce_dbobj_column_descr_is_not_found_in_db_2
  =IBP_MCE_DBOBJ_COLUMN_DESCR_IS_NOT_FOUND_IN_DB_2,

 ibp_mce_dbobj_column_not_store_array_2
  =IBP_MCE_DBOBJ_COLUMN_NOT_STORE_ARRAY_2,

 //table, column, load count, wait count
 ibp_mce_dbobj_load_bad_bounds_count_of_array_4
  =IBP_MCE_DBOBJ_LOAD_BAD_BOUNDS_COUNT_OF_ARRAY_4,

 //table, column, def count
 ibp_mce_dbobj_load_many_bounds_count_of_array_3
  =IBP_MCE_DBOBJ_LOAD_MANY_BOUNDS_COUNT_OF_ARRAY_3,

 ibp_mce_dbobj_get_bound_with_wrong_num_4
  =IBP_MCE_DBOBJ_GET_BOUND_WITH_WRONG_NUM_4,

 ibp_mce_dbobj_load_array_descr_data_2
  =IBP_MCE_DBOBJ_LOAD_ARRAY_DESCR_DATA_2,

 ibp_mce_dbobj_load_array_bound_data_3
  =IBP_MCE_DBOBJ_LOAD_ARRAY_BOUND_DATA_3,

 ibp_mce_dbobj__cant_assign_str__large_len_4
  =IBP_MCE_DBOBJ__CANT_ASSIGN_STR__LARGE_LEN_4,

 ibp_mce_dbobj__cstring_data_contains_internal_zeros_0
  =IBP_MCE_DBOBJ__CSTRING_DATA_CONTAINS_INTERNAL_ZEROS_0,

 //Reserved
 //Reserved
 //Reserved

 /// \brief Неизвестная кодовая страница.<br>
 /// \b Params: charset_name
 ibp_mce_dbobj__unknown_charset_name_1
  =IBP_MCE_DBOBJ__UNKNOWN_CHARSET_NAME_1,

 /// \brief Неподдерживаемая ODS базы данных.<br>
 /// \b Params: cur_ods_as_str, req_ods_as_str, dbms descr, provider descr
 ibp_mce_dbobj__not_support_database_ods_4
  =IBP_MCE_DBOBJ__NOT_SUPPORT_DATABASE_ODS_4,

 /// \brief Недопускается сохранение NULL-значений в элементах массивов.
 ibp_mce_dbobj__cant_write_null_into_array_element_0
  =IBP_MCE_DBOBJ__CANT_WRITE_NULL_INTO_ARRAY_ELEMENT_0,

 /// \brief Неизвестная кодовая страница подключения.<br>
 /// \b Params: charset_name
 ibp_mce_dbobj__unknown_connection_charset_1
  =IBP_MCE_DBOBJ__UNKNOWN_CONNECTION_CHARSET_1,

 /// \brief Неизвестная кодовая страница пользователя.<br>
 /// \b Params: charset_name
 ibp_mce_dbobj__unknown_user_charset_1
  =IBP_MCE_DBOBJ__UNKNOWN_USER_CHARSET_1,

 /// \brief Ошибка при транслировании имени пользовательской кодовой страницы.<br>
 /// \b Params: charset_name
 ibp_mce_dbobj__cant_translate_user_charset_name_1
  =IBP_MCE_DBOBJ__CANT_TRANSLATE_USER_CHARSET_NAME_1,

 /// \brief Неизвестная кодовая страница для обработки NONE.<br>
 /// \b Params: charset_name
 ibp_mce_dbobj__unknown_none_charset_1
  =IBP_MCE_DBOBJ__UNKNOWN_NONE_CHARSET_1,

 /// \brief Ошибка при транслировании имени кодовой страницы для обработки NONE.<br>
 /// \b Params: charset_name
 ibp_mce_dbobj__cant_translate_none_charset_name_1
  =IBP_MCE_DBOBJ__CANT_TRANSLATE_NONE_CHARSET_NAME_1,

 /// \brief Недопускается сохранение DEFAULT-значений в элементах массивов.
 ibp_mce_dbobj__cant_write_default_into_array_element_0
  =IBP_MCE_DBOBJ__CANT_WRITE_DEFAULT_INTO_ARRAY_ELEMENT_0,

 /// \brief
 ///  Загрузка списка identity-колонок.
 ibp_mce_dbobj__load_list_of_identity_columns_0
  =IBP_MCE_DBOBJ__LOAD_LIST_OF_IDENTITY_COLUMNS_0,

 /// \brief Неизвестная кодовая страница ODS.<br>
 /// \b Params: charset_name
 ibp_mce_dbobj__unknown_ods_charset_1
  =IBP_MCE_DBOBJ__UNKNOWN_ODS_CHARSET_1,

 /// \brief
 ///  The reset of connection server state was failed.
 ibp_mce_dbobj__failed_to_reset_cn_server_state_0
  =IBP_MCE_DBOBJ__FAILED_TO_RESET_CN_SERVER_STATE_0,

 /// \brief
 ///  Bad FB040 timezone id.
 /// \b
 ///  Params: place, point, id, name, min id, max id
 ibp_mce_dbobj__bug_check__bad_fb040_tz_id__6
  =IBP_MCE_DBOBJ__BUG_CHECK__BAD_FB040_TZ_ID__6,

 /// \brief
 ///  Duplication of timezone id.
 /// \b
 ///  Params: place, point, id, name1, name2
 ibp_mce_dbobj__bug_check__duplication_of_timezone_id__5
  =IBP_MCE_DBOBJ__BUG_CHECK__DUPLICATION_OF_TIMEZONE_ID__5,

 /// \brief
 ///  Duplication of timezone name.
 /// \b
 ///  Params: place, point, name, id1, id2
 ibp_mce_dbobj__bug_check__duplication_of_timezone_name__5
  =IBP_MCE_DBOBJ__BUG_CHECK__DUPLICATION_OF_TIMEZONE_NAME__5,

 //загрузка сведений о доменах -------------------------------------------

 /// \brief Не найдено описание домена для объекта базы данных.<br>
 /// \b Params: relation, field
 ibp_mce_dbobj__cant_find_domain_info_for_db_object_2
  =IBP_MCE_DBOBJ__CANT_FIND_DOMAIN_INFO_FOR_DB_OBJECT_2,

 /// \brief Загрузка сведений о домене для объекта базы данных.<br>
 /// \b Params: relation, field
 ibp_mce_dbobj__load_domain_info_for_db_object_2
  =IBP_MCE_DBOBJ__LOAD_DOMAIN_INFO_FOR_DB_OBJECT_2,

 //Working with COM objects ----------------------------------------------

 //interface, method, err code, err source, err descr
 ibp_mce_com__fail_call_imethod_5
  =IBP_MCE_COM__FAIL_CALL_IMETHOD_5,

 ibp_mce_com__imethod_return_null_obj_ptr_3
  =IBP_MCE_COM__IMETHOD_RETURN_NULL_OBJ_PTR_3,

 ibp_mce_com__cant_generate_uuid_1
  =IBP_MCE_COM__CANT_GENERATE_UUID_1,

 /// \brief Ошибка инициализации COM.
 ibp_mce_com__fail_com_initialize_0
  =IBP_MCE_COM__FAIL_COM_INITIALIZE_0,

 /// \brief Ошибка создания потока данных для маршалинга указателя на интерфейс.
 ibp_mce_com__ptr_marshaler__failed_to_create_data_stream_0
  =IBP_MCE_COM__PTR_MARSHALER__FAILED_TO_CREATE_DATA_STREAM_0,

 /// \brief
 ///  [BUG CHECK] Функция создания потока данных для маршалинга указателя на интерфейс
 ///  (CreateStreamOnHGlobal) вернула нулевой указатель.
 ibp_mce_com__ptr_marshaler__bug_check__CreateStreamOnHGlobal_return_null_ptr_0
  =IBP_MCE_COM__PTR_MARSHALER__BUG_CHECK__CreateStreamOnHGlobal_RETURN_NULL_PTR_0,

 /// \brief Сбой маршалинга указателя на интерфейс.<br>
 /// \b Params: iid
 ibp_mce_com__ptr_marshaler__failed_to_marshal_1
  =IBP_MCE_COM__PTR_MARSHALER__FAILED_TO_MARSHAL_1,

 /// \brief Сбой демаршалинга указателя на интерфейс.<br>
 /// \b Params: iid
 ibp_mce_com__ptr_marshaler__failed_to_unmarshal_1
  =IBP_MCE_COM__PTR_MARSHALER__FAILED_TO_UNMARSHAL_1,

 /// \brief [BUG CHECK] Функция демаршалинга интерфейса вернула нулевой указатель.<br>
 /// \b Params: iid
 ibp_mce_com__ptr_marshaler__bug_check__CoUnmarshalInterface_return_null_ptr_1
  =IBP_MCE_COM__PTR_MARSHALER__BUG_CHECK__CoUnmarshalInterface_RETURN_NULL_PTR_1,

 /// \brief Сбой перемотки потока с данными для маршалинга в начальную позицию.
 ibp_mce_com__ptr_marshaler__failed_to_restart_data_stream_0
  =IBP_MCE_COM__PTR_MARSHALER__FAILED_TO_RESTART_DATA_STREAM_0,

 //-----------------------------------------------------------------------

 /// \brief Операция была отменена.
 ibp_mce_operation_was_canceled_0
  =IBP_MCE_OPERATION_WAS_CANCELED_0,

 //data source -----------------------------------------------------------
 ibp_mce_data_source_user_cancelled_attach_0
  =IBP_MCE_DATA_SOURCE_USER_CANCELLED_ATTACH_0,

 ibp_mce_data_source_already_inited_0
  =IBP_MCE_DATA_SOURCE_ALREADY_INITED_0,

 ibp_mce_data_source_fail_attach_0
  =IBP_MCE_DATA_SOURCE_FAIL_ATTACH_0,

 ibp_mce_no_def_req_init_prop_1
  =IBP_MCE_NO_DEF_REQ_INIT_PROP_1,

 /// \brief
 ///  Подключение имеет открытые объекты.<br>
 /// \b
 ///  Params: obj count
 ibp_mce_data_source_has_open_objects_1
  =IBP_MCE_DATA_SOURCE_HAS_OPEN_OBJECTS_1,

 ibp_mce_data_source_fail_detach_0
  =IBP_MCE_DATA_SOURCE_FAIL_DETACH_0,

 ibp_mce_data_source_user_cancelled_newdb_0
  =IBP_MCE_DATA_SOURCE_USER_CANCELLED_NEWDB_0,

 /// \brief
 ///  Подключение имеет активные транзакции.<br>
 /// \b
 ///  Params: tr count
 ibp_mce_data_source_has_active_trans_1
  =IBP_MCE_DATA_SOURCE_HAS_ACTIVE_TRANS_1,

 //Reserved

 ibp_mce_data_source_is_not_inited_0
  =IBP_MCE_DATA_SOURCE_IS_NOT_INITED_0,

 ibp_mce_fail_create_db_because_ds_inited_0
  =IBP_MCE_FAIL_CREATE_DB_BECAUSE_DS_INITED_0,

 ibp_mce_fail_create_db_0
  =IBP_MCE_FAIL_CREATE_DB_0,

 /// \brief Модификация базы данных не поддерживается.<br>
 /// \b Params: Server Name, Server Version
 ibp_mce_data_source_modification_not_supported_2
  =IBP_MCE_DATA_SOURCE_MODIFICATION_NOT_SUPPORTED_2,

 ibp_mce_fail_drop_db_0
  =IBP_MCE_FAIL_DROP_DB_0,

 //Required, Returned literals
 ibp_mce_fail_get_literal_info_2
  =IBP_MCE_FAIL_GET_LITERAL_INFO_2,

 ibp_mce_ds__integrated_auth_not_supported_2
  =IBP_MCE_DS__INTEGRATED_AUTH_NOT_SUPPORTED_2,

 ibp_mce_ds__unk_integrated_auth_service_name_1
  =IBP_MCE_DS__UNK_INTEGRATED_AUTH_SERVICE_NAME_1,

 ibp_mce_ds__db_client_not_supports_init_prop_3
  =IBP_MCE_DS__DB_CLIENT_NOT_SUPPORTS_INIT_PROP_3,

 /// \brief Can't translate connection string to UTF8
 ibp_mce_ds__cant_translate_cn_str_to_utf8_0
  =IBP_MCE_DS__CANT_TRANSLATE_CN_STR_TO_UTF8_0,

 //Reserved

 ibp_mce_ds__db_client_cant_process_init_prop_value_4
  =IBP_MCE_DS__DB_CLIENT_CANT_PROCESS_INIT_PROP_VALUE_4,

 /// \brief Текущий клиент не поддерживает диалект текущей базы данных.<br>
 /// \b Params: provider version, dbclient name, dbclient version, dbms name, dbms version, server sign, db dialect
 ibp_mce_ds__dbclient_not_support_db_dialect_7
  =IBP_MCE_DS__DBCLIENT_NOT_SUPPORT_DB_DIALECT_7,

 /// \brief Текущий клиент не поддерживает запрошенный диалект базы данных.<br>
 /// \b Params: provider version, dbclient name, dbclient version, required dialect.
 ibp_mce_ds__dbclient_not_support_req_dialect_4
  =IBP_MCE_DS__DBCLIENT_NOT_SUPPORT_REQ_DIALECT_4,

 /// \brief Диалект текущей БД не поддерживается.<br>
 /// \b Params: provider version, dbms name, dbms version, server sign, db dialect.
 ibp_mce_ds__db_dialect_not_supported_5
  =IBP_MCE_DS__DB_DIALECT_NOT_SUPPORTED_5,

 /// \brief Несовместимость запрошенного диалекта и диалекта базы данных.<br>
 /// \b Params: provider version, dbclient name, dbclient version, dbms name, dbms version, server sign, req dialect, db dialect.
 ibp_mce_ds__incompatible_req_and_db_dialect_8
  =IBP_MCE_DS__INCOMPATIBLE_REQ_AND_DB_DIALECT_8,

 //-----------------------------------------------------------------------
 //Reserved

 //-----------------------------------------------------------------------
 //! \brief
 //!  Ошибка обработки параметров подключения из свойства "Extended Properties".
 ibp_mce_ds__failed_parse_cn_params_from_ext_prop_0
  =IBP_MCE_DS__FAILED_PARSE_CN_PARAMS_FROM_EXT_PROP_0,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Источник данных содержит неосвобожденные дочерние объекты.<br>
 /// \b
 ///  Params: approximate number
 ibp_mce_data_source_has_child_objects_1
  =IBP_MCE_DATA_SOURCE_HAS_CHILD_OBJECTS_1,

//Errors of new database creation ----------------------------------------

 /// \brief Сервер не поддерживает определение collation для кодовой страницы БД.<br>
 /// \b Params: DBMS Name, DBMS Version
 ibp_mce_newds__default_db_cset_coll_not_supported_by_dbms_2
  =IBP_MCE_NEWDS__DEFAULT_DB_CSET_COLL_NOT_SUPPORTED_BY_DBMS_2,

 /// \brief Нелья определять collation БД без указания кодовой страницы по-умолчанию.
 ibp_mce_newds__default_db_cset_coll_without_cset_0
  =IBP_MCE_NEWDS__DEFAULT_DB_CSET_COLL_WITHOUT_CSET_0,

 /// \brief Сервер не поддерживает запрашиваемый тип пользователей БД.<br>
 /// \b Params: DBMS Name, DBMS Version, ID of TypeOfDatabaseUsers
 ibp_mce_newds__req_type_of_db_users_not_supported_by_dbms_3
  =IBP_MCE_NEWDS__REQ_TYPE_OF_DB_USERS_NOT_SUPPORTED_BY_DBMS_3,

 //идентификаторы общих ошибок работы с буфером обмена данными -----------
 ibp_mce_bind_error_2
  =IBP_MCE_BIND_ERROR_2,

 //Session ---------------------------------------------------------------
 ibp_mce_sess_disable_auto_trans_0
  =IBP_MCE_SESS_DISABLE_AUTO_TRANS_0,

 ibp_mce_sess_disable_inner_trans_0
  =IBP_MCE_SESS_DISABLE_INNER_TRANS_0,

 ibp_mce_sess_open_rowset_not_support_using_of_index_0
  =IBP_MCE_SESS_OPEN_ROWSET_NOT_SUPPORT_USING_OF_INDEX_0,

 ibp_mce_sess_join_dtc_session_has_active_tr_0
  =IBP_MCE_SESS_JOIN_DTC_SESSION_HAS_ACTIVE_TR_0,

 ibp_mce_sess_join_dtc_cant_query_interface_1
  =IBP_MCE_SESS_JOIN_DTC_CATN_QUERY_INTERFACE_1,

 ibp_mce_sess_join_dtc_cant_get_dtc_interface_1
  =IBP_MCE_SESS_JOIN_DTC_CANT_GET_DTC_INTERFACE_1,

 ibp_mce_sess_join_dtc_cant_create_resource_manager_0
  =IBP_MCE_SESS_JOIN_DTC_CANT_CREATE_RESOURCE_MANAGER_0,

 ibp_mce_sess_join_dtc_cant_enlist_0
  =IBP_MCE_SESS_JOIN_DTC_CANT_ENLIST_0,

 //-----------
 ibp_mce_sess_dtc_tra_cant_notify_about_rollback_0
  =IBP_MCE_SESS_DTC_TRA_CANT_NOTIFY_ABOUT_ROLLBACK_0,

 ibp_mce_sess_dtc_tra_cant_notify_about_commit_0
  =IBP_MCE_SESS_DTC_TRA_CANT_NOTIFY_ABOUT_COMMIT_0,

 ibp_mce_sess_dtc_tra_cant_notify_about_prepare_0
  =IBP_MCE_SESS_DTC_TRA_CANT_NOTIFY_ABOUT_PREPARE_0,

 ibp_mce_sess_dtc_tra_not_support_rollback_retaining_0
  =IBP_MCE_SESS_DTC_TRA_NOT_SUPPORT_ROLLBACK_RETAINING_0,

 ibp_mce_sess_dtc_tra_not_support_prepare_commit_retaining_0
  =IBP_MCE_SESS_DTC_TRA_NOT_SUPPORT_PREPARE_COMMIT_RETAINING_0,

 //ib transaction --------------------------------------------------------
 ibp_mce_ibtrans__not_support_isolevel_1
  =IBP_MCE_IBTRANS__NOT_SUPPORT_ISOLEVEL_1,

 ibp_mce_ibtrans__already_started_0
  =IBP_MCE_IBTRANS__ALREADY_STARTED_0,

 ibp_mce_ibtrans__fail_start_trans_0
  =IBP_MCE_IBTRANS__FAIL_START_TRANS_0,

 ibp_mce_ibtrans__commit_failed_0
  =IBP_MCE_IBTRANS__COMMIT_FAILED_0,

 ibp_mce_ibtrans__commit_failed__make_rollback__0
  =IBP_MCE_IBTRANS__COMMIT_FAILED__MAKE_ROLLBACK__0,

 ibp_mce_ibtrans__commit_retaining_failed__make_rollback__0
  =IBP_MCE_IBTRANS__COMMIT_RETAINING_FAILED__MAKE_ROLLBACK__0,

 ibp_mce_ibtrans__prepare_transaction_failed__make_rollback__0
  =IBP_MCE_IBTRANS__PREPARE_TRANSACTION_FAILED__MAKE_ROLLBACK__0,

 ibp_mce_ibtrans__abort_failed_0
  =IBP_MCE_IBTRANS__ABORT_FAILED_0,

 ibp_mce_ibtrans__abort_retaining_not_supported__make_rollback_0
  =IBP_MCE_IBTRANS__ABORT_RETAINING_NOT_SUPPORTED__MAKE_ROLLBACK_0,

 ibp_mce_ibtrans__abort_retaining_failed_0
  =IBP_MCE_IBTRANS__ABORT_RETAINING_FAILED_0,

 //reserved

 ibp_mce_ibtrans__no_started_0
  =IBP_MCE_IBTRANS__NO_STARTED_0,

 ibp_mce_ibtrans__start_tr_return_null_handle_0
  =IBP_MCE_IBTRANS__START_TR_RETURN_NULL_HANDLE_0,

 ibp_mce_ibtrans__bad_node_number_2
  =IBP_MCE_IBTRANS__BAD_NODE_NUMBER_2,

 ibp_mce_ibtrans__commit_retaining_failed__0
  =IBP_MCE_IBTRANS__COMMIT_RETAINING_FAILED__0,

 ibp_mce_ibtrans__fail_create_sys_savepoint_1
  =IBP_MCE_IBTRANS__FAIL_CREATE_SYS_SAVEPOINT_1,

 ibp_mce_ibtrans__fail_release_sys_savepoint_1
  =IBP_MCE_IBTRANS__FAIL_RELEASE_SYS_SAVEPOINT_1,

 ibp_mce_ibtrans__fail_release_sys_savepoint__make_rollback__1
  =IBP_MCE_IBTRANS__FAIL_RELEASE_SYS_SAVEPOINT__MAKE_ROLLBACK__1,

 ibp_mce_ibtrans__fail_rollback_to_sys_savepoint_1
  =IBP_MCE_IBTRANS__FAIL_ROLLBACK_TO_SYS_SAVEPOINT_1,

 ibp_mce_ibtrans__svp_mark_as_abort_1
  =IBP_MCE_IBTRANS__SVP_MARK_AS_ABORT_1,

 ibp_mce_ibtrans__svp_mark_as_commit_1
  =IBP_MCE_IBTRANS__SVP_MARK_AS_COMMIT_1,

 ibp_mce_ibtrans__svp_is_detach_1
  =IBP_MCE_IBTRANS__SVP_IS_DETACH_1,

 ibp_mce_ibtrans__get_zero_tr_node_0
  =IBP_MCE_IBTRANS__GET_ZERO_TR_NODE_0,

 ibp_mce_ibtrans__incorrect_name_of_user_savepoint_1
  =IBP_MCE_IBTRANS__INCORRECT_NAME_OF_USER_SAVEPOINT_1,

 ibp_mce_ibtrans__not_support_nested_trans_1
  =IBP_MCE_IBTRANS__NOT_SUPPORT_NESTED_TRANS_1,

 ibp_mce_ibtrans__disable_explicit_prepare_dtc_tr_0
  =IBP_MCE_IBTRANS__DISABLE_EXPLICIT_PREPARE_DTC_TR_0,

 ibp_mce_ibtrans__disable_explicit_commit_dtc_tr_0
  =IBP_MCE_IBTRANS__DISABLE_EXPLICIT_COMMIT_DTC_TR_0,

 ibp_mce_ibtrans__disable_explicit_abort_dtc_tr_0
  =IBP_MCE_IBTRANS__DISABLE_EXPLICIT_ABORT_DTC_TR_0,

 ibp_mce_ibtrans__prepare_transaction_failed__1
  =IBP_MCE_IBTRANS__PREPARE_TRANSACTION_FAILED__1,

 /// \brief
 ///  Размер описания подготавливаемой транзакции превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: data size, max size.
 /// \note
 ///  В принципе, можно указать подсистему ошибки.
 ibp_mce_ibtrans__tr_prep_data_is_too_large__2
  =IBP_MCE_IBTRANS__TR_PREP_DATA_IS_TOO_LARGE__2,

#if(IBP_ENGINE_UPDATE_ROWSET!=0)
 ibp_mce_fail_commit_modify_trans_1
  =IBP_MCE_FAIL_COMMIT_MODIFY_TRANS_1,
#endif

 /// \brief
 ///  Ошибка коммита транзакции. Обнаружены активные вложенные транзакции.
 ibp_mce_ibtrans__cant_commit_tr_with_active_nested_tr__0
  =IBP_MCE_IBTRANS__CANT_COMMIT_TR_WITH_ACTIVE_NESTED_TR__0,

 /// \brief
 ///  Ошибка коммита транзакции. Обнаружены активные вложенные транзакции.
 ///  Транзакция будет отменена.
 ibp_mce_ibtrans__cant_commit_tr_with_active_nested_tr__make_rollback__0
  =IBP_MCE_IBTRANS__CANT_COMMIT_TR_WITH_ACTIVE_NESTED_TR__MAKE_ROLLBACK__0,

 /// \brief
 ///  Ошибка подготовки транзакции. Обнаружены активные вложенные транзакции.
 ///  Транзакция будет отменена.
 ibp_mce_ibtrans__cant_prepare_tr_with_active_nested_tr__make_rollback__0
  =IBP_MCE_IBTRANS__CANT_PREPARE_TR_WITH_ACTIVE_NESTED_TR__MAKE_ROLLBACK__0,

 /// \brief Освобождение точки сохранения приведет к неявному завершению вложенной транзакции.<br>
 /// \b Params: svp name.
 ibp_mce_ibtrans__cant_release_svp_with_active_nested_tr__1
  =IBP_MCE_IBTRANS__CANT_RELEASE_SVP_WITH_ACTIVE_NESTED_TR__1,

 /// \brief Пересоздание точки сохранения приведет к неявному завершению вложенной транзакции.<br>
 /// \b Params: svp name.
 ibp_mce_ibtrans__cant_recreate_svp_with_active_nested_tr__1
  =IBP_MCE_IBTRANS__CANT_RECREATE_SVP_WITH_ACTIVE_NESTED_TR__1,

 /// \brief [BUG CHECK] Неизвестная точка сохранения вложенной транзакции.<br>
 /// \b Params: svp name of nested trans.
 ibp_mce_ibtrans__bug_check__unk_nested_trans__1
  =IBP_MCE_IBTRANS__BUG_CHECK__UNK_NESTED_TRANS__1,

 /// \brief Неизвестная точка сохранения.<br>
 /// \b Params: svp name.
 ibp_mce_ibtrans__unk_svp_name__1
  =IBP_MCE_IBTRANS__UNK_SVP_NAME__1,

 /// \brief Ошибка в параметрах транзакции. Неизвестный тег.<br>
 /// \b Params: isolation_name, unk_tag, line, col.
 ibp_mce_ibtrans__params_err__unk_tag_4
  =IBP_MCE_IBTRANS__PARAMS_ERR__UNK_TAG_4,

 /// \brief Ошибка в параметрах транзакции.<br>
 /// \b Params: isolation_name, line, col.
 ibp_mce_ibtrans__params_err__err_in_params_3
  =IBP_MCE_IBTRANS__PARAMS_ERR__ERR_IN_PARAMS_3,

 /// \brief Ошибка в параметрах транзакции. Некорректное использование тега.<br>
 /// \b Params: isolation_name, bad_tag, other_tag.
 ibp_mce_ibtrans__params_err__tag_can_be_use_with_other_tag_only_3
  =IBP_MCE_IBTRANS__PARAMS_ERR__TAG_CAN_BE_USE_WITH_OTHER_TAG_ONLY_3,

 /// \brief Ошибка в параметрах транзакции. Конфликтный или многократно определенный тег.<br>
 /// \b Params: isolation_name, bad_tag, prev_tag, line, col.
 ibp_mce_ibtrans__params_err__conflict_tag_5
  =IBP_MCE_IBTRANS__PARAMS_ERR__CONFLICT_TAG_5,

 /// \brief Переполнение генератора идентификаторов элементов первого уровня транзакции.
 ibp_mce_ibtrans__overflow_tr_node_gen_id_0
  =IBP_MCE_IBTRANS__OVERFLOW_TR_NODE_GEN_ID_0,

 /// \brief
 ///  Ошибка старта новой транзакции. Текущая транзакция находится в подготовленном состоянии.
 ibp_mce_ibtrans__cant_start_tr__tr_in_prepared_state_0
  =IBP_MCE_IBTRANS__CANT_START_TR__TR_IN_PREPARED_STATE_0,

 //------------------------------------------------------------------------
 /// \brief
 ///  Невозможно закоммитить транзакцию.<br>
 /// \b
 ///  Params: detail_of_reason
 ibp_mce_ibtrans__cant_commit_1
  =IBP_MCE_IBTRANS__CANT_COMMIT_1,

 /// \brief
 ///  Невозможно закоммитить транзакцию с сохранением контекста.<br>
 /// \b
 ///  Params: detail_of_reason
 ibp_mce_ibtrans__cant_commit_retaining_1
  =IBP_MCE_IBTRANS__CANT_COMMIT_RETAINING_1,

 /// \brief
 ///  Невозможно откатить транзакцию.<br>
 /// \b
 ///  Params: detail_of_reason
 ibp_mce_ibtrans__cant_rollback_1
  =IBP_MCE_IBTRANS__CANT_ROLLBACK_1,

 /// \brief
 ///  Невозможно откатить транзакцию с сохранением контекста.<br>
 /// \b
 ///  Params: detail_of_reason
 ibp_mce_ibtrans__cant_rollback_retaining_1
  =IBP_MCE_IBTRANS__CANT_ROLLBACK_RETAINING_1,

 /// \brief
 ///  Невозможно подготовить транзакцию к коммиту.<br>
 /// \b
 ///  Params: detail_of_reason
 ibp_mce_ibtrans__cant_prepare_1
  =IBP_MCE_IBTRANS__CANT_PREPARE_1,

 //------------------------------------------------------------------------
 /// \brief Транзакция была отменена.
 ibp_mce_ibtrans__detail_msg__tr_was_aborted_0
  =IBP_MCE_IBTRANS__DETAIL_MSG__TR_WAS_ABORTED_0,

 /// \brief Транзакция была зафиксирована.
 ibp_mce_ibtrans__detail_msg__tr_was_committed_0
  =IBP_MCE_IBTRANS__DETAIL_MSG__TR_WAS_COMMITTED_0,

 /// \brief Транзакция не активна.
 ibp_mce_ibtrans__detail_msg__tr_is_not_active_0
  =IBP_MCE_IBTRANS__DETAIL_MSG__TR_IS_NOT_ACTIVE_0,

 /// \brief Транзакция была подготовлена.
 ibp_mce_ibtrans__detail_msg__tr_was_prepared_0
  =IBP_MCE_IBTRANS__DETAIL_MSG__TR_WAS_PREPARED_0,

 //TIBPColumn ------------------------------------------------------------
 /// \brief Неидентичные описания колонок. Разные имена базовых таблиц.<br>
 /// \b Params: base table1, base table2.
 ibp_mce_column__not_equal__base_table_2
  =IBP_MCE_COLUMN__NOT_EQUAL__BASE_TABLE_2,

 /// \brief Неидентичные описания колонок. Разные имена базовых колонок.<br>
 /// \b Params: base column1, base column2.
 ibp_mce_column__not_equal__base_column_2
  =IBP_MCE_COLUMN__NOT_EQUAL__BASE_COLUMN_2,

 /// \brief Неидентичные описания колонок. Разные типы.<br>
 /// \b Params: type1, type2.
 ibp_mce_column__not_equal__type_2
  =IBP_MCE_COLUMN__NOT_EQUAL__TYPE_2,

 /// \brief Неидентичные описания колонок. Разные размеры.<br>
 /// \b Params: size1, size2.
 ibp_mce_column__not_equal__size_2
  =IBP_MCE_COLUMN__NOT_EQUAL__SIZE_2,

 /// \brief Неидентичные описания колонок. Разные масштабы.<br>
 /// \b Params: scale1, scale2.
 ibp_mce_column__not_equal__scale_2
  =IBP_MCE_COLUMN__NOT_EQUAL__SCALE_2,

 /// \brief Неидентичные описания колонок. Разные точности.<br>
 /// \b Params: precision1, precision2.
 ibp_mce_column__not_equal__precision_2
  =IBP_MCE_COLUMN__NOT_EQUAL__PRECISION_2,

 /// \brief Неидентичные описания колонок. Разные флаги.<br>
 /// \b Params: flags1, flags2.
 ibp_mce_column__not_equal__flags_2
  =IBP_MCE_COLUMN__NOT_EQUAL__FLAGS_2,

 /// \brief Неидентичные описания колонок. Разные кодовые страницы.<br>
 /// \b Params: charset1, charset2.
 ibp_mce_column__not_equal__charset_2
  =IBP_MCE_COLUMN__NOT_EQUAL__CHARSET_2,

 /// \brief Неидентичные описания колонок. Разные структуры.<br>
 /// \b Params: kind of structure1, kind of structure2.
 ibp_mce_column__not_equal__structure_2
  =IBP_MCE_COLUMN__NOT_EQUAL__STRUCTURE_2,

 /// \brief Неидентичные описания колонок. Разные размерности массивов.<br>
 /// \b Params: dim of array1, dim of array2.
 ibp_mce_column__not_equal__array_dim_2
  =IBP_MCE_COLUMN__NOT_EQUAL__ARRAY_DIM_2,

 /// \brief Неидентичные описания колонок. Разные размерности массивов.<br>
 /// \b Params: dim_number [begin from 1], lower1, upper1, lower2, upper2.
 ibp_mce_column__not_equal__array_bound_5
  =IBP_MCE_COLUMN__NOT_EQUAL__ARRAY_BOUND_5,

 /// \brief Неидентичные описания колонок. Разные базовые типы.<br>
 /// \b Params: base type1,base type2
 ibp_mce_column__not_equal__base_type_2
  =IBP_MCE_COLUMN__NOT_EQUAL__BASE_TYPE_2,

 /// \brief Неидентичные описания колонок. Разные базовые размеры.<br>
 /// \b Params: base size1,base size2
 ibp_mce_column__not_equal__base_size_2
  =IBP_MCE_COLUMN__NOT_EQUAL__BASE_SIZE_2,

 /// \brief Неидентичные описания колонок. Разные базовые масштабы.<br>
 /// \b Params: base scale1,base scale2
 ibp_mce_column__not_equal__base_scale_2
  =IBP_MCE_COLUMN__NOT_EQUAL__BASE_SCALE_2,

 /// \brief Неидентичные описания колонок. Разные базовые точности.<br>
 /// \b Params: base precision1,base precision2
 ibp_mce_column__not_equal__base_precision_2
  =IBP_MCE_COLUMN__NOT_EQUAL__BASE_PRECISION_2,

 /// \brief Неидентичные описания колонок. Разные базовые флаги.<br>
 /// \b Params: base flags1,base flags2
 ibp_mce_column__not_equal__base_flags_2
  =IBP_MCE_COLUMN__NOT_EQUAL__BASE_FLAGS_2,

 //Schema ----------------------------------------------------------------
 ibp_mce_schema_unknown_1
  =IBP_MCE_SCHEMA_UNKNOWN_1,

 ibp_mce_schema_restrict_of_column_not_support_3
  =IBP_MCE_SCHEMA_RESTRICT_OF_COLUMN_NOT_SUPPORT_3,

 ibp_mce_schema_incorrect_restrict_required_3
  =IBP_MCE_SCHEMA_INCORRECT_RESTRICT_REQUIRED_3,

 ibp_mce_schema_bad_restrict_type_of_obj_name_4
  =IBP_MCE_SCHEMA_BAD_RESTRICT_TYPE_OF_OBJ_NAME_4,

 //schema id, restriction idx, column name, bad string
 ibp_mce_schema_bad_restrict_value_of_obj_name_4
  =IBP_MCE_SCHEMA_BAD_RESTRICT_VALUE_OF_OBJ_NAME_4,

 ibp_mce_schema_bad_restrict_fail_compare_4
  =IBP_MCE_SCHEMA_BAD_RESTRICT_FAIL_COMPARE_4,

 ibp_mce_schema_bad_restrict_type_4
  =IBP_MCE_SCHEMA_BAD_RESTRICT_TYPE_4,

 ibp_mce_schema_not_supported_1
  =IBP_MCE_SCHEMA_NOT_SUPPORTED_1,

 ibp_mce_schema_columns_fail_process_table_column_2
  =IBP_MCE_SCHEMA_COLUMNS_FAIL_PROCESS_TABLE_COLUMN_2,

 ibp_mce_schema_no_dbcharset_info_0
  =IBP_MCE_SCHEMA_NO_DBCHARSET_INFO_0,

 //charset_id, charset_name, bytes_per_char
 ibp_mce_schema_bad_value_of_bytes_per_char_3
  =IBP_MCE_SCHEMA_BAD_VALUE_OF_BYTES_PER_CHAR_3,

 ibp_mce_schema_no_dbcharset_info_by_id_1
  =IBP_MCE_SCHEMA_NO_DBCHARSET_INFO_BY_ID_1,

 /// \b Params: CharsetID, CollateID
 ibp_mce_schema_no_dbcollate_info_by_id_2
  =IBP_MCE_SCHEMA_NO_DBCOLLATE_INFO_BY_ID_2,

 //name, id1,id2
 ibp_mce_schema_duplication_cset_name_3
  =IBP_MCE_SCHEMA_DUPLICATION_CSET_NAME_3,

 //id, name1, name2
 ibp_mce_schema_duplication_cset_id_3
  =IBP_MCE_SCHEMA_DUPLICATION_CSET_ID_3,

 //column idx, column name, value
 ibp_mce_schema__bad_column_value_3
  =IBP_MCE_SCHEMA__BAD_COLUMN_VALUE_3,

 ibp_mce_schema_unk_proc_param_direction_3
  =IBP_MCE_SCHEMA_UNK_PROC_PARAM_DIRECTION_3,

 /// \brief Загрузка списка collate кодовых страниц
 ibp_mce_schema_load_collates_0
  =IBP_MCE_SCHEMA_LOAD_COLLATES_0,

 ibp_mce_schema_cant_detect_sp_suspend__sp_info_not_avail_1
  =IBP_MCE_SCHEMA_CANT_DETECT_SP_SUSPEND__SP_INFO_NOT_AVAIL_1,

 ibp_mce_schema_cant_detect_sp_suspend__process_failed_1
  =IBP_MCE_SCHEMA_CANT_DETECT_SP_SUSPEND_PROCESS_FAILED_1,

 /// \brief Внутренняя ошибка сортировки схемы.<br>
 /// \b Params: schema_id, column name, compare result
 ibp_mce_schema_ie_sort_is_failed_3
  =IBP_MCE_SCHEMA_IE_SORT_IS_FAILED_3,

 //charset, table, column
 ibp_mce_schema_no_dbcharset_info_by_id_3
  =IBP_MCE_SCHEMA_NO_DBCHARSET_INFO_BY_ID_3,

 //char count, table, column
 ibp_mce_schema_bad_char_count_of_dbobject_3
  =IBP_MCE_SCHEMA_BAD_CHAR_COUNT_OF_DBOBJECT_3,

 /// \brief Несогласованное количество байт и количество символов в колонке.<br>
 /// \b Params: table, column, char count, length, charsetName, byte_per_char
 ibp_mce_schema_uncorrelated_length_and_char_count_6
  =IBP_MCE_SCHEMA_UNCORRELATED_LENGTH_AND_CHAR_COUNT_6,

 /// \brief Дублирование идентификаторов кодовых страниц.<br>
 /// \b Params: CharSetID
 ibp_mce_schema_duplication_cset_id_1
  =IBP_MCE_SCHEMA_DUPLICATION_CSET_ID_1,

 /// \brief Загрузка списка кодовых страниц
 ibp_mce_schema_load_csets_0
  =IBP_MCE_SCHEMA_LOAD_CSETS_0,

 /// \brief Загрузка кодовой страницы.<br>
 /// \b Params: CharSetID
 ibp_mce_schema_load_cset_by_id_1
  =IBP_MCE_SCHEMA_LOAD_CSET_BY_ID_1,

 /// \brief Проблемы при формировании схемы с описаниями таблиц.<br>
 /// \b Params: OLEDB_SchemaName, TableName
 ibp_mce_schema_tables_fail_process_table_2
  =IBP_MCE_SCHEMA_TABLES_FAIL_PROCESS_TABLE_2,

 /// \brief Загрузка collate кодовой страницы.<br>
 /// \b Params: CharSetID, CollateID
 ibp_mce_schema_load_collate_by_id_2
  =IBP_MCE_SCHEMA_LOAD_COLLATE_BY_ID_2,

 /// \brief Загрузка данных из системной таблицы.<br>
 /// \b Params: Table Name
 ibp_mce_schema_load_data_from_system_table_1
  =IBP_MCE_SCHEMA_LOAD_DATA_FROM_SYSTEM_TABLE_1,

 /// \brief Системная таблица не содержит записей.<br>
 /// \b Params: Table Name
 ibp_mce_schema_system_table_is_empty_1
  =IBP_MCE_SCHEMA_SYSTEM_TABLE_IS_EMPTY_1,

 /// \brief Ошибка формирования данных для хранимой процедуры.<br>
 /// \b Params: Procedure Name
 ibp_mce_schema_fail_process_sp_1
  =IBP_MCE_SCHEMA_FAIL_PROCESS_SP_1,

 /// \brief Ошибка формирования данных для параметра хранимой процедуры.<br>
 /// \b Params: Procedure Name, Parameter Name
 ibp_mce_schema_fail_process_sp_param_2
  =IBP_MCE_SCHEMA_FAIL_PROCESS_SP_PARAM_2,

 /// \brief Ошибка формирования данных для колонки хранимой процедуры.<br>
 /// \b Params: Procedure Name, Column Name
 ibp_mce_schema_fail_process_sp_column_2
  =IBP_MCE_SCHEMA_FAIL_PROCESS_SP_COLUMN_2,

 /// \brief Дублирование идентификатора collate кодовой страницы.<br>
 /// \b Params: CharsetID, CollateID
 ibp_mce_schema_duplication_collate_id_2
  =IBP_MCE_SCHEMA_DUPLICATION_COLLATE_ID_2,

 /// \brief Использование одного имени для relation разных типов.<br>
 /// \b Params: rel_name
 ibp_mce_schema__field_dim_ldr__detect_rel_name_duplication_1
  =IBP_MCE_SCHEMA__FIELD_DIM_LDR__DETECT_REL_NAME_DUPLICATION_1,

 /// \brief Неожиданный номер размерности массива.<br>
 /// \b Params: rel_name, field_name, get_dim_number, wait_dim_number
 ibp_mce_schema__field_dim_ldr__unexpected_dim_number_4
  =IBP_MCE_SCHEMA__FIELD_DIM_LDR__UNEXPECTED_DIM_NUMBER_4,

 /// \brief Неожиданный номер размерности массива.<br>
 /// \b Params: rel_name, field_name, dim_number, lower_bound, upper_bound
 ibp_mce_schema__field_dim_ldr__bad_dim_bounds_5
  =IBP_MCE_SCHEMA__FIELD_DIM_LDR__BAD_DIM_BOUNDS_5,

 /// \brief Ошибка формирования данных для хранимой функции.<br>
 /// \b Params: Procedure Name
 ibp_mce_schema__fail_process_sfunc_1
  =IBP_MCE_SCHEMA__FAIL_PROCESS_SFUNC_1,

 /// \brief Ошибка формирования данных для параметра функции.<br>
 /// \b Params: Function Name, Parameter Number, Parameter Name
 ibp_mce_schema__fail_process_sfunc_param_3
  =IBP_MCE_SCHEMA__FAIL_PROCESS_SFUNC_PARAM_3,

 /// \brief Процедуры и функции БД должны иметь непересекающиеся названия.<br>
 /// \b Params: name
 ibp_mce_schema__sproc_and_sfunc_with_eq_name_not_support_1
  =IBP_MCE_SCHEMA__SPROC_AND_SFUNC_WITH_EQ_NAME_NOT_SUPPORT_1,

 /// \brief Системная ошибка в метаданных. Некорректная последовательность в нумерации аргументов функции.<br>
 /// \b Params: function name
 ibp_mce_schema__sys_error_in_sfunc_arg_numbers_1
  =IBP_MCE_SCHEMA__SYS_ERROR_IN_SFUNC_ARG_NUMBERS_1,

 /// \brief Системная ошибка в метаданных. Не удалось определить RET-параметр функции.<br>
 /// \b Params: function name
 ibp_mce_schema__sys_error_sfunc_without_ret_param_1
  =IBP_MCE_SCHEMA__SYS_ERROR_SFUNC_WITHOUT_RET_PARAM_1,

 /// \brief Системная ошибка в метаданных. Обнаружено несколько RET-параметров функции.<br>
 /// \b Params: function name
 ibp_mce_schema__sys_error_sfunc_with_many_ret_param_1
  =IBP_MCE_SCHEMA__SYS_ERROR_SFUNC_WITH_MANY_RET_PARAM_1,

 /// \brief Неизвестная хранимая процедура.<br>
 /// \b Params: Procedure Name
 ibp_mce_schema__unknown_sp_1
  =IBP_MCE_SCHEMA__UNKNOWN_SP_1,

 /// \brief Неоднозначное имя хранимой процедуры.<br>
 /// \b Params: Procedure Name
 ibp_mce_schema__sp_with_mult_def_1
  =IBP_MCE_SCHEMA__SP_WITH_MULT_DEF_1,

 /// \brief Ошибка загрузки сведений для хранимой процедуры.<br>
 /// \b Params: Procedure Name
 ibp_mce_schema__fail_load_sp_info_1
  =IBP_MCE_SCHEMA__FAIL_LOAD_SP_INFO_1,

 /// \brief Неизвестный серверный тип хранимой процедуры.<br>
 /// \b Params: sp name, srv type id
 ibp_mce_schema__unknown_srv_sp_type_2
  =IBP_MCE_SCHEMA__UNKNOWN_SRV_SP_TYPE_2,

 /// \brief
 ///  Ошибка обработки описания индекса.<br>
 /// \b
 ///  Params: index name, table name, column name
 ibp_mce_schema__failed_to_load_index_info_3
  =IBP_MCE_SCHEMA__FAILED_TO_LOAD_INDEX_INFO_3,

 /// \brief
 ///  Parameter direction is not defined.<br>
 /// \b
 ///  Params: proc_name, param_name
 ibp_mce_schema_null_proc_param_direction_2
  =IBP_MCE_SCHEMA_NULL_PROC_PARAM_DIRECTION_2,

//Table open ------------------------------------------------------------
 ibp_mce_empty_table_name_0
  =IBP_MCE_EMPTY_TABLE_NAME_0,

 ibp_mce_incorrect_table_name_1
  =IBP_MCE_INCORRECT_TABLE_NAME_1,

 ibp_mce_unknown_table_1
  =IBP_MCE_UNKNOWN_TABLE_1,

 ibp_mce_invalid_table_id_0
  =IBP_MCE_INVALID_TABLE_ID_0,

 //Внутренний объект запроса ---------------------------------------------
 ibp_mce_cmd_prepare_SQL_stmt_0
  =IBP_MCE_CMD_PREPARE_SQL_STMT_0,

 ibp_mce_cmd_execute_SQL_stmt_0
  =IBP_MCE_CMD_EXECUTE_SQL_STMT_0,

 /// \brief
 ///  Транзакция курсора была завершена.
 ibp_mce_cmd__tr_of_cursor_was_finished_0
  =IBP_MCE_CMD__TR_OF_CURSOR_WAS_FINISHED_0,

 /// \brief
 ///  Ошибка рестарта курсора.
 ibp_mce_cmd__failed_to_restart_cursor_0
  =IBP_MCE_CMD__FAILED_TO_RESTART_CURSOR_0,

 ibp_mce_cmd_get_affected_rows_0
  =IBP_MCE_CMD_GET_AFFECTED_ROWS_0,

 ibp_mce_cmd_cant_translate_stmt_1
  =IBP_MCE_CMD_CANT_TRANSLATE_STMT_1,

 ibp_mce_cmd_fetch_error_0
  =IBP_MCE_CMD_FETCH_ERROR_0,

 ibp_mce_cmd_close_stmt_0
  =IBP_MCE_CMD_CLOSE_STMT_0,

 ibp_mce_cmd_destroy_stmt_0
  =IBP_MCE_CMD_DESTROY_STMT_0,

 /// \brief Текст запроса превысил максимальную длину.<br>
 /// \b Params: stmt length, max length
 ibp_mce_cmd_stmt_too_long_2
  =IBP_MCE_CMD_STMT_TOO_LONG_2,

 /// \brief Ошибка отмены выполнения запроса.
 ibp_mce_cmd_cancel_is_failed_0
  =IBP_MCE_CMD_CANCEL_IS_FAILED_0,

 /// \brief Отмена запросов не поддерживается.
 /// \todo
 ///  Переименовать в "отмена выполнения ОПЕРАЦИИ не поддерживается".
 ///  Не факт, что мы пытались выполнить отмену выполнения запроса.
 ibp_mce_cmd_cancel_not_supported_0
  =IBP_MCE_CMD_CANCEL_NOT_SUPPORTED_0,

 /// \brief Инициализация дескриптора запроса.
 ibp_mce_cmd_alloc_SQL_stmt_0
  =IBP_MCE_CMD_ALLOC_SQL_STMT_0,

 /// \brief Запрос описания колонок.<br>
 /// \b Params: error msg
 ibp_mce_cmd_describe_columns_0
  =IBP_MCE_CMD_DESCRIBE_COLUMNS_0,

 /// \brief
 ///  Ошибка обработки информационного свойства со сведениями о запросе.<br>
 /// \b
 ///  Params: tag id.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_cmd__in_stmt_info_processing_error_occurred_1
  =IBP_MCE_CMD__IN_STMT_INFO_PROCESSING_ERROR_OCCURRED_1,

 /// \brief
 ///  Ошибка получения сведений о запросе.
 ibp_mce_cmd__fail_get_stmt_info_0
  =IBP_MCE_CMD__FAIL_GET_STMT_INFO_0,

 /// \brief
 ///  Ошибка формирования описаний колонок запроса.
 ibp_mce_cmd__describe_stmt_columns_0
  =IBP_MCE_CMD__DESCRIBE_STMT_COLUMNS_0,

 /// \brief
 ///  Ошибка формирования описаний параметров запроса.
 ibp_mce_cmd__describe_stmt_params_0
  =IBP_MCE_CMD__DESCRIBE_STMT_PARAMS_0,

 /// \brief
 ///  Не получено значение информационного свойства запроса.<br>
 /// \b
 ///  Params: tagID/tagSign.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_cmd__get_stmt_info__no_data_1
  =IBP_MCE_CMD__GET_STMT_INFO__NO_DATA_1,

 //Команда ---------------------------------------------------------------
 ibp_mce_cmd_incorrect_text_0
  =IBP_MCE_CMD_INCORRECT_TEXT_0,

 ibp_mce_cmd_incorrect_use_of_params_0
  =IBP_MCE_CMD_INCORRECT_USE_OF_PARAMS_0,

 ibp_mce_cmd_unk_param_accessor_0
  =IBP_MCE_CMD_UNK_PARAM_ACCESSOR_0,

 ibp_mce_cmd_bad_param_accessor_0
  =IBP_MCE_CMD_BAD_PARAM_ACCESSOR_0,

 /// \brief
 ///  Попытка закрытия закрытого курсора.
 ibp_mce_cmd__attempt_to_close_of_closed_cursor_0
  =IBP_MCE_CMD__ATTEMPT_TO_CLOSE_OF_CLOSED_CURSOR_0,

 ibp_mce_cmd_exec_not_implement_0
  =IBP_MCE_CMD_EXEC_NOT_IMPLEMENT_0,

 ibp_mce_cmd_exec_params_not_required_0
  =IBP_MCE_CMD_EXEC_PARAMS_NOT_REQUIRED_0,

 ibp_mce_cmd_is_active_0
  =IBP_MCE_CMD_IS_ACTIVATE_0,

 ibp_mce_cmd_empty_text_0
  =IBP_MCE_CMD_EMPTY_TEXT_0,

 ibp_mce_cmd_not_prepared_0
  =IBP_MCE_CMD_NOT_PREPARED_0,

 ibp_mce_cmd_unknown_stored_procedure_1 //"sp name"
  =IBP_MCE_CMD_UNKNOWN_STORED_PROCEDURE_1,

 /// \brief Неоднозначная установка описания параметра. Переданно несколько описаний.<br>
 /// \b Params: iOrdinal, Name1, Name2
 ibp_mce_cmd_set_ambi_info_for_param_3
  =IBP_MCE_CMD_SET_AMBI_INFO_FOR_PARAM_3,

 ibp_mce_cmd_bad_param_count_in_call_sp_3 //define,need,"sp name"
  =IBP_MCE_CMD_BAD_PARAM_COUNT_IN_CALL_SP_3,

 ibp_mce_cmd_cant_detect_sp_exec_kind_1 //"sp name"
  =IBP_MCE_CMD_CANT_DETECT_SP_EXEC_KIND_1,

 /// \brief Неизвестное имя типа параметра команды.<br>
 /// \b Params: type name
 ibp_mce_cmd_unknown_param_typename_1
  =IBP_MCE_CMD_UNKNOWN_PARAM_TYPENAME_1,

 ibp_mce_cmd_incorrect_text_3
  =IBP_MCE_CMD_INCORRECT_TEXT_3,

 ibp_mce_cmd_not_support_command_text_dialect_1
  =IBP_MCE_CMD_NOT_SUPPORT_COMMAND_TEXT_DIALECT_1,

 /// \brief Обнаружен пустой запрос
 ibp_mce_cmd_empty_stmt_found_0
  =IBP_MCE_CMD_EMPTY_STMT_FOUND_0,

 /// \brief Команды с несколькими SQL запросами не поддерживаются
 ibp_mce_cmd_with_multi_stmt_not_support_0
  =IBP_MCE_CMD_WITH_MULTI_STMT_NOT_SUPPORT_0,

 /// \brief OUT-значение параметра уже было установлено.<br>
 /// \b Params: Param Number, Param Name
 ibp_mce_cmd_out_value_of_param_already_installed_2
  =IBP_MCE_CMD_OUT_VALUE_OF_PARAM_ALREADY_INSTALLED_2,

 /// \brief
 ///  Выборка записей из закрытого курсора.
 ibp_mce_cmd__cant_fetch_from_closed_cursor_0
  =IBP_MCE_CMD__CANT_FETCH_FROM_CLOSED_CURSOR_0,

 /// \brief Ошибка в SET TERM. Не определен новый терминатор запросов.
 ibp_mce_cmd__err_in_set_term__new_stmt_term_is_not_def_0
  =IBP_MCE_CMD__ERR_IN_SET_TERM__NEW_STMT_TERM_IS_NOT_DEF_0,

 /// \brief Ошибка обработки OUT-значения параметра.<br>
 /// \b Params: iOrdinal, ParamName, DataStatus
 ibp_mce_cmd__cant_process_param_out_value_3
  =IBP_MCE_CMD__CANT_PROCESS_PARAM_OUT_VALUE_3,

 /// \brief Ошибка установки OUT-значения параметра в буфер обмена.<br>
 /// \b Params: iBind, iOrdinal, ParamName, DataStatus
 ibp_mce_cmd__cant_set_param_out_value_to_data_buffer_4
  =IBP_MCE_CMD__CANT_SET_PARAM_OUT_VALUE_TO_DATA_BUFFER_4,

 /// \brief Неожиданное завершение запроса. Ожидался список с маркерами параметров.
 ibp_mce_cmd__unexpected_end_of_stmt__expected_param_list_0
  =IBP_MCE_CMD__UNEXPECTED_END_OF_STMT__EXPECTED_PARAM_LIST_0,

 /// \brief Ошибка в тексте запроса. Ожидался маркер параметра.
 ibp_mce_cmd__error_in_stmt__expected_param_marker_0
  =IBP_MCE_CMD__ERROR_IN_STMT__EXPECTED_PARAM_MARKER_0,

 /// \brief Ошибка в тексте запроса. Ожидалась запятая в списке с маркерами параметров.
 ibp_mce_cmd__error_in_stmt__expected_comma_in_param_list_0
  =IBP_MCE_CMD__ERROR_IN_STMT__EXPECTED_COMMA_IN_PARAM_LIST_0,

 /// \brief Различное кол-во элементов в секциях RETURNING и INTO.<br>
 /// \b Params: count in returning, count in into.
 ibp_mce_cmd__error_in_stmt__different_number_of_entries_in_returning_and_into_sections_2
  =IBP_MCE_CMD__ERROR_IN_STMT__DIFFERENT_NUMBER_OF_ENTRIES_IN_RETURNING_AND_INTO_SECTIONS_2,

 /// \brief
 ///  Выборка после достижения конца множества рядов.
 ibp_mce_cmd__cant_fetch_after_eof_0
  =IBP_MCE_CMD__CANT_FETCH_AFTER_EOF_0,

 /// \brief
 ///  Попытка подготовить запрос с незакрытым курсором.
 ibp_mce_cmd__attempt_to_prepare_stmt_with_open_cursor_0
  =IBP_MCE_CMD__ATTEMPT_TO_PREPARE_STMT_WITH_OPEN_CURSOR_0,

 /// \brief
 ///  Попытка повторно выполнить запрос с незакрытым курсором.
 ibp_mce_cmd__attempt_to_reexecute_stmt_with_open_cursor_0
  =IBP_MCE_CMD__ATTEMPT_TO_REEXECUTE_STMT_WITH_OPEN_CURSOR_0,

 /// \brief
 ///  Запрос с отложенным выполнением требует контекст транзакции.
 ibp_mce_cmd__stmt_with_defer_exec_requires_tr_context_0
  =IBP_MCE_CMD__STMT_WITH_DEFER_EXEC_REQUIRES_TR_CONTEXT_0,

 /// \brief
 ///  Создание базы данных через SQL-запрос не поддерживается.
 ibp_mce_cmd__db_creation_through_sql_not_supported_0
  =IBP_MCE_CMD__DB_CREATION_THROUGH_SQL_NOT_SUPPORTED_0,

 /// \brief
 ///  Удаление базы данных через SQL-запрос не поддерживается.
 ibp_mce_cmd__db_dropping_through_sql_not_supported_0
  =IBP_MCE_CMD__DB_DROPPING_THROUGH_SQL_NOT_SUPPORTED_0,

 /// \brief
 ///  Текст команды содержит неподдерживаемое выражение.<br>
 /// \b
 ///  Params: stmt sign
 ibp_mce_cmd__command_text_contains_unsupported_statement_1
  =IBP_MCE_CMD__COMMAND_TEXT_CONTAINS_UNSUPPORTED_STATEMENT_1,

 /// \brief
 ///  [BUG CHECK] Запрос не возвращает результирующее множество.<br>
 /// \b
 ///  Params: check place, check point, stmt signature
 ibp_mce_cmd__bug_check__stmt_is_not_selectable_3
  =IBP_MCE_CMD__BUG_CHECK__STMT_IS_NOT_SELECTABLE_3,

 /// \brief
 ///  Resetting the connection state via SQL is not supported.
 ibp_mce_cmd__resetting_a_cn_state_through_sql_is_not_supported_0
  =IBP_MCE_CMD__RESETTING_A_CN_STATE_THROUGH_SQL_IS_NOT_SUPPORTED_0,

 /// \brief
 ///  Command text contains invalid UTF16 command text.
 ibp_mce_cmd__invalid_utf16_command_text_0
  =IBP_MCE_CMD__INVALID_UTF16_COMMAND_TEXT_0,

 /// \brief
 ///  Closing quote was not found.
 ibp_mce_cmd__closing_quote_not_found_0
  =IBP_MCE_CMD__CLOSING_QUOTE_NOT_FOUND_0,

 /// \brief
 ///  Bad format of q-text token.
 ibp_mce_cmd__bad_format_of_qtext_token_0
  =IBP_MCE_CMD__BAD_FORMAT_OF_QTEXT_TOKEN_0,

 /// \brief
 ///  Bad hex-text token.
 ibp_mce_cmd__bad_htext_token_0
  =IBP_MCE_CMD__BAD_HTEXT_TOKEN_0,

 //команда со скриптом ---------------------------------------------------

 /// \brief В скрипте нельзя использовать неименованные параметры
 ibp_mce_script__not_support_unnamed_params_0
  =IBP_MCE_SCRIPT__NOT_SUPPORT_UNNAMED_PARAMS_0,

 /// \brief В случае скрипта, нельзя передавать параметры без имени.<br>
 /// \b Params: Param Ordinal
 ibp_mce_script__cant_pass_param_without_name_1
  =IBP_MCE_SCRIPT__CANT_PASS_PARAM_WITHOUT_NAME_1,

 /// \brief Неоднозначность отображения параметра запроса [%1] на пользовательское описание.<br>
 /// \b Params: Parameter Name
 ibp_mce_script__ambiguous_map_of_stmt_param_to_user_param_1
  =IBP_MCE_SCRIPT__AMBIGUOUS_MAP_OF_STMT_PARAM_TO_USER_PARAM_1,

 //Ошибки преобразования ODBC запросов -----------------------------------
 ibp_mce_odbc_date_parser_no_end_tag_2
  =IBP_MCE_ODBC_DATE_PARSER_NO_END_TAG_2,

 ibp_mce_odbc_date_parser_bad_value_of_date_part_2
  =IBP_MCE_ODBC_DATE_PARSER_BAD_VALUE_OF_DATE_PART_2,

 ibp_mce_odbc_date_parser_bad_value_of_time_part_2
  =IBP_MCE_ODBC_DATE_PARSER_BAD_VALUE_OF_TIME_PART_2,

 ibp_mce_odbc_date_parser_bad_date_format_1
  =IBP_MCE_ODBC_DATE_PARSER_BAD_DATE_FORMAT_1,

 ibp_mce_odbc_date_parser_bad_time_format_1
  =IBP_MCE_ODBC_DATE_PARSER_BAD_TIME_FORMAT_1,

 ibp_mce_odbc_date_parser_bad_timestamp_format_1
  =IBP_MCE_ODBC_DATE_PARSER_BAD_TIMESTAMP_FORMAT_1,

 ibp_mce_odbc_date_parser_no_beg_tag_2 //tag,odbc_prefix
  =IBP_MCE_ODBC_DATE_PARSER_NO_BEG_TAG_2,

 ibp_mce_bad_square_delim_name_2 //name, current dialect
  =IBP_MCE_BAD_SQUARE_DELIM_NAME_2,

 ibp_mce_odbc_not_support_seq_id_1
  =IBP_MCE_ODBC_NOT_SUPPORT_SEQ_ID_1,

 ibp_mce_odbc_not_support_tsi_2 //function name, time_stamp_interval_name
  =IBP_MCE_ODBC_NOT_SUPPORT_TSI_2,

 ibp_mce_odbc_incorrect_func_parameters_list_1 //function name
  =IBP_MCE_ODBC_INCORRECT_FUNC_PARAMETERS_LIST_1,

 ibp_mce_odbc_optional_parameter_is_not_supported_2 //function name, parameter name
  =IBP_MCE_ODBC_OPTIONAL_PARAMETER_IS_NOT_SUPPORTED_2,

 ibp_mce_odbc_not_support_convert_data_type_1 //data_type_name
  =IBP_MCE_ODBC_NOT_SUPPORT_CONVERT_DATA_TYPE_1,

 //Обработка параметров команды ------------------------------------------
 ibp_mce_bind_parameters_error_1
  =IBP_MCE_BIND_PARAMETERS_ERROR_1,

 ibp_mce_in_param_cannot_mixing_type_of_name_0
  =IBP_MCE_IN_PARAM_CANNOT_MIXING_TYPE_OF_NAME_0,

 ibp_mce_command_requires_param_values_0
  =IBP_MCE_COMMAND_REQUIRED_PARAM_VALUES_0,

 ibp_mce_bad_param_bind_ordinal_2
  =IBP_MCE_BAD_PARAM_BIND_ORDINAL_2,

 ibp_mce_param_info_not_present_1
  =IBP_MCE_PARAM_INFO_NOT_PRESENT_1,

 ibp_mce_unknown_param_bind_direction_2
  =IBP_MCE_UNKNOWN_PARAM_BIND_DIRECTION_2,

 ibp_mce_unknown_param_info_direction_2
  =IBP_MCE_UNKNOWN_PARAM_INFO_DIRECTION_2,

 ibp_mce_bad_in_param_bind_direction_2
  =IBP_MCE_BAD_IN_PARAM_BIND_DIRECTION_2,

 ibp_mce_bad_out_param_bind_direction_2
  =IBP_MCE_BAD_OUT_PARAM_BIND_DIRECTION_2,

 ibp_mce_unk_name_of_in_param_2
  =IBP_MCE_UNK_NAME_OF_IN_PARAM_2,

 ibp_mce_bad_in_param_bind_ordinal_2
  =IBP_MCE_BAD_IN_PARAM_BIND_ORDINAL_2,

 ibp_mce_fail_set_in_param_value_1
  =IBP_MCE_FAIL_SET_IN_PARAM_VALUE_1,

 ibp_mce_fail_reassign_out_param_value_1
  =IBP_MCE_FAIL_REASSIGN_OUT_PARAM_VALUE_1,

 ibp_mce_fail_processing_param_data_0
  =IBP_MCE_FAIL_PROCESSING_PARAM_DATA_0,

 ibp_mce_fail_mem_alloc_for_param_values_0
  =IBP_MCE_FAIL_MEM_ALLOC_FOR_PARAM_VALUES_0,

 ibp_mce_has_critical_errors_0
  =IBP_MCE_HAS_CRITICAL_ERRORS_0,

 ibp_mce_no_present_of_in_params_values_1
  =IBP_MCE_NO_PRESENT_OF_IN_PARAMS_VALUES_1,

 /// \brief Повторное определение IN-значения параметра.<br>
 /// \b Params: param oridnal
 ibp_mce_multiple_def_param_in_value_1
  =IBP_MCE_MULTIPLE_DEF_PARAM_IN_VALUE_1,

 ibp_mce_out_param_cannot_mixing_type_of_name_1
  =IBP_MCE_OUT_PARAM_CANNOT_MIXING_TYPE_OF_NAME_1,

 /// \brief Неоднозначное имя OUT-параметра.<br>
 /// \b Params: param name, param ordinal
 ibp_mce_ambi_name_of_in_param_2
  =IBP_MCE_AMBI_NAME_OF_IN_PARAM_2,

 ibp_mce_out_param_unk_name_2
  =IBP_MCE_OUT_PARAM_UNK_NAME_2,

 ibp_mce_out_param_bad_ordinal_3
  =IBP_MCE_OUT_PARAM_BAD_ORDINAL_3,

 ibp_mce_fail_make_ib_in_param_2
  =IBP_MCE_FAIL_MAKE_IB_IN_PARAM_2,

 ibp_mce_fail_describe_params_0
  =IBP_MCE_FAIL_DESCRIBE_PARAMS_0,

 ibp_mce_generate_wrong_param_list_3 //{IN,OUT},provider_count,server_count
  =IBP_MCE_GENERATE_WRONG_PARAM_LIST_3,

 /// \brief Неоднозначное имя OUT-параметра.<br>
 /// \b Params: param name, param ordinal
 ibp_mce_ambi_name_of_out_param_2
  =IBP_MCE_AMBI_NAME_OF_OUT_PARAM_2,

 /// \brief Несовместимые типы маркеров одного и того же параметра.<br>
 /// \b Params: marker position, parameter name.
 ibp_mce_not_allow_use_param_with_incomp_types_2
  =IBP_MCE_NOT_ALLOW_USE_PARAM_WITH_INCOMP_TYPES_2,

 /// \brief Неоднозначное имя параметра.<br>
 /// \b Params: param name, param ordinal
 ibp_mce_ambi_name_of_param_2
  =IBP_MCE_AMBI_NAME_OF_PARAM_2,

 ibp_mce_not_allow_multi_use_out_param_named_marker_1
  =IBP_MCE_NOT_ALLOW_MULTI_USE_OUT_PARAM_NAMED_MARKER_1,

 ibp_mce_unk_name_of_param_2 //name,iOrdinal
  =IBP_MCE_UNK_NAME_OF_PARAM_2,

 ibp_mce_bad_in_param_info_direction_2 //iOrdinal, Bad Info Direction
  =IBP_MCE_BAD_IN_PARAM_INFO_DIRECTION_2,

 ibp_mce_bad_out_param_info_direction_2 //iOrdinal, Bad Info Direction
  =IBP_MCE_BAD_OUT_PARAM_INFO_DIRECTION_2,

 ibp_mce_bad_ret_param_info_direction_2
  =IBP_MCE_BAD_RET_PARAM_INFO_DIRECTION_2,

 ibp_mce_bad_ret_param_bind_direction_2
  =IBP_MCE_BAD_RET_PARAM_BIND_DIRECTION_2,

 ibp_mce_no_present_of_in_param_entry_values_1
  =IBP_MCE_NO_PRESENT_OF_IN_PARAM_ENTRY_VALUES_1,

 ibp_mce_cant_use_mult_param_sets_with_zero_rowsize_1
  =IBP_MCE_CANT_USE_MULT_PARAM_SETS_WITH_ZERO_ROWSIZE_1,

 /// \brief Не удалось связать OUT-значение параметра с маркером OUT-параметра запроса.<br>
 /// \b Params: iParamOrdinal, ParamName
 ibp_mce_cant_link_out_bind_to_out_param_marker_2
  =IBP_MCE_CANT_LINK_OUT_BIND_TO_OUT_PARAM_MARKER_2,

 /// \brief Не удалось связать IN-значение параметра с маркером IN-параметра запроса.<br>
 /// \b Params: iParamOrdinal, ParamName
 ibp_mce_cant_link_in_bind_to_in_param_marker_2
  =IBP_MCE_CANT_LINK_IN_BIND_TO_IN_PARAM_MARKER_2,

 /// \brief Повторное определение IN-значения параметра.<br/>
 /// \b Params: param oridnal, param name
 ibp_mce_multiple_def_param_in_value_2
  =IBP_MCE_MULTIPLE_DEF_PARAM_IN_VALUE_2,

 //Rowset message --------------------------------------------------------
 ibp_mce_rs_get_rows_by_bookmark_2
  =IBP_MCE_RS_GET_ROWS_BY_BOOKMARK_2,

 ibp_mce_rs_bmk_num_error_2
  =IBP_MCE_RS_BMK_NUM_ERROR_2,

 ibp_mce_rs_row_num_error_2
  =IBP_MCE_RS_ROW_NUM_ERROR_2,

 ibp_mce_rs_row_num_status_error_3
  =IBP_MCE_RS_ROW_NUM_STATUS_ERROR_3,

 ibp_mce_rs_delete_rows_2
  =IBP_MCE_RS_DELETE_ROWS_2,

 ibp_mce_rs_get_rows_status_2
  =IBP_MCE_RS_GET_ROWS_STATUS_2,

 //Rowset Storage --------------------------------------------------------
 ibp_mce_rs_stg___file_storage_is_full_0
  =IBP_MCE_RS_STG___FILE_STORAGE_IS_FULL_0,

 /// \brief Пустой набор рядов
 ibp_mce_rs_stg__recordset_is_empty_0
  =IBP_MCE_RS_STG__RECORDSET_IS_EMPTY_0,

 /// \brief Слишком большое количество рядов в результирующем множестве
 ibp_mce_rs_stg__large_number_of_rows_in_resultset_0
  =IBP_MCE_RS_STG__LARGE_NUMBER_OF_ROWS_IN_RESULTSET_0,

 /// \brief
 ///  The problem with setting data in the exchange (transfer) buffer.<br>
 /// \b
 ///  Params: iOrdinal, Name, BindDbType, DBSTATUS
 ibp_mce_rs_stg__cant_get_column_data_4
  =IBP_MCE_RS_STG__CANT_GET_COLUMN_DATA_4,

 /// \brief
 ///  После сбоя предыдущей операции с курсором, его корректная работа невозможна.
 ibp_mce_rs_stg__incorrect_state_of_cursor_after_last_fail_0
  =IBP_MCE_RS_STG__INCORRECT_STATE_OF_CURSOR_AFTER_LAST_FAIL_0,

 /// \brief
 ///  Фоновая загрузка результирующего множества была отменена.
 ibp_mce_rs_stg__asynch_load__cancelled_0
  =IBP_MCE_RS_STG__ASYNCH_LOAD__CANCELLED_0,

 /// \brief
 ///  Перезапуск асинхронной загрузки либо еще не завершился, либо завершился с ошибками.
 ibp_mce_rs_stg__asynch_load__restart_in_progress_or_failed_0
  =IBP_MCE_RS_STG__ASYNCH_LOAD__RESTART_IN_PROGRESS_OR_FAILED_0,

 /// \brief
 ///  Отсутствует контроллер фоновой рассылки уведомлений. Возможно, его предыдущий
 ///  запуск завершился с ошибками.
 ibp_mce_rs_stg__no_task_for_run_asynch_events_pusher_0
  =IBP_MCE_RS_STG__NO_TASK_FOR_RUN_ASYNCH_EVENTS_PUSHER_0,

 /// \brief
 ///  Фоновая задача для рассылки уведомлений прекратила свою работу.
 ///  Возможно, у неё произошли ошибки.
 ibp_mce_rs_stg__task_for_run_asynch_events_pusher_was_stopped_0
  =IBP_MCE_RS_STG__TASK_FOR_RUN_ASYNCH_EVENTS_PUSHER_WAS_STOPPED_0,

 /////////////////////////////////////////////////////////////////////////
 //DataType Operations

 /// \brief
 ///  Failed too convert between datatypes.<br/>
 /// \b
 ///  Params: source datatype, target datatype
 ibp_mce_datatype__failed_to_convert_between_types_2
  =IBP_MCE_DATATYPE__FAILED_TO_CONVERT_BETWEEN_TYPES_2,

 //-----------------------------------------------------------------------
 /// \brief
 ///  An arithmetic overflow occurred in binary operation.<br/>
 /// \b
 ///  Params: operation sign, target result type, left argument, right argument
 ibp_mce_datatype__arithmetic_overflow_in_op2_4
  =IBP_MCE_DATATYPE__ARITHMETIC_OVERFLOW_IN_OP2_4,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Translation of text into datatype failed.<br/>
 /// \b
 ///  Params: target datatype
 ibp_mce_datatype__translation_of_text_into_datatype_1
  =IBP_MCE_DATATYPE__TRANSLATION_OF_TEXT_INTO_DATATYPE_1,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Translation of exponent value failed. The arithmetic overflow occurred.<br/>
 /// \b
 ///  Params: the signature of exponent value, max value
 ibp_mce_datatype__translation_of_exponent__overflow_2
  =IBP_MCE_DATATYPE__TRANSLATION_OF_EXPONENT__OVERFLOW_2,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Exponent is not in a valid range.<br/>
 /// \b
 ///  Params: exponent value, min value, max value
 ibp_mce_datatype__exponent_is_not_in_valid_range_3
  =IBP_MCE_DATATYPE__EXPONENT_IS_NOT_IN_VALID_RANGE_3,

 //-----------------------------------------------------------------------
 /// \brief
 ///  A bad OLEDB time.<br>
 /// \b
 ///  Params: hour, minutes, seconds, fractions, bad part sign, min, max
 ibp_mce_datatype__bad_oledb_time_7
  =IBP_MCE_DATATYPE__BAD_OLEDB_TIME_7,

 /// \brief
 ///  Can't convert date value.<br>
 /// \b
 ///  Params: date-type, year, month, day, bad_part_name, min_valid_value, max_valid_value
 ibp_mce_datatype__cant_convert_date__part_out_of_range_7
  =IBP_MCE_DATATYPE__CANT_CONVERT_DATE__PART_OUT_OF_RANGE_7,

 ibp_mce_datatype__cant_encode_isc_date_out_of_range_5
  =IBP_MCE_DATATYPE__CANT_ENCODE_ISC_DATE_OUT_OF_RANGE_5,

 ibp_mce_datatype__cant_decode_isc_time_out_of_range_3
  =IBP_MCE_DATATYPE__CANT_DECODE_ISC_TIME_OUT_OF_RANGE_3,

 ibp_mce_datatype__cant_decode_isc_date_out_of_range_5
  =IBP_MCE_DATATYPE__CANT_DECODE_ISC_DATE_OUT_OF_RANGE_5,

 //-----------------------------------------------------------------------
 /// \brief
 ///  The work with timezones requires an ICUIN library.
 ibp_mce_datatype__work_with_timezones_requires_icuin_library_0
  =IBP_MCE_DATATYPE__WORK_WITH_TIMEZONES_REQUIRES_ICUIN_LIBRARY_0,

 //-----------------------------------------------------------------------
 /// \brief
 ///  The unknown external provider of datetime operations.<br/>
 /// \b
 ///  Params: DLL path, DLL description, DLL version
 ibp_mce_datatype__unknown_external_provider_of_datetime_operations_3
  =IBP_MCE_DATATYPE__UNKNOWN_EXTERNAL_PROVIDER_OF_DATETIME_OPERATIONS_3,

 //-----------------------------------------------------------------------
 /// \brief
 ///  The unsupported external provider of datetime operations.<br/>
 /// \b
 ///  Params: DLL path, DLL description, DLL version
 ibp_mce_datatype__unsupported_external_provider_of_datetime_operations_3
  =IBP_MCE_DATATYPE__UNSUPPORTED_EXTERNAL_PROVIDER_OF_DATETIME_OPERATIONS_3,

 /// \brief
 ///  An invalid ISC_TIME.<br>
 /// \b
 ///  Params: value, min value, max value
 ibp_mce_datatype__invalid_isc_time_3
  =IBP_MCE_DATATYPE__INVALID_ISC_TIME_3,

 /// \brief
 ///  An invalid ISC_DATE.<br>
 /// \b
 ///  Params: value, min value, max value, min date, max date
 ibp_mce_datatype__invalid_isc_date_5
  =IBP_MCE_DATATYPE__INVALID_ISC_DATE_5,

 /// \brief
 ///  An invalid ISC_TS_TICKS.<br>
 /// \b
 ///  Params: value, min value, max value
 ibp_mce_datatype__invalid_isc_ts_ticks_3
  =IBP_MCE_DATATYPE__INVALID_ISC_TS_TICKS_3,

 /// \brief
 ///  [FB040] Can't translate UTC timestamp into local timestamp. Out of range.<br>
 /// \b
 ///  Params: utc_ts, fb040_timezone, offset_in_ticks (microseconds)
 ibp_mce_datatype__fb040__cant_translate_utc_ts_into_local_ts__out_of_range_3
  =IBP_MCE_DATATYPE__FB040__CANT_TRANSLATE_UTC_TS_INTO_LOCAL_TS__OUT_OF_RANGE_3,

 /// \brief
 ///  [FB040] Can't translate local timestamp into UTC timestamp. Out of range.<br>
 /// \b
 ///  Params: local_ts, fb040_timezone, offset_in_ticks (microseconds)
 ibp_mce_datatype__fb040__cant_translate_local_ts_into_utc_ts__out_of_range_3
  =IBP_MCE_DATATYPE__FB040__CANT_TRANSLATE_LOCAL_TS_INTO_UTC_TS__OUT_OF_RANGE_3,

 /// \brief
 ///  An invalid time zone offset.<br>
 /// \b
 ///  Params: value, min value, max value
 ibp_mce_datatype__invalid_tz_offset_3
  =IBP_MCE_DATATYPE__INVALID_TZ_OFFSET_3,

 /// \brief
 ///  An invalid time zone offset in minutes.<br>
 /// \b
 ///  Params: value, min value, max value
 ibp_mce_datatype__invalid_tz_offset_in_min_3
  =IBP_MCE_DATATYPE__INVALID_TZ_OFFSET_IN_MIN_3,

 /// \brief
 ///  An invalid time zone offset in microseconds (isc-ticks).<br>
 /// \b
 ///  Params: value, min value, max value
 ibp_mce_datatype__invalid_tz_offset_in_microseconds_3
  =IBP_MCE_DATATYPE__INVALID_TZ_OFFSET_IN_MICROSECONDS_3,

 /// \brief
 ///  An invalid OLEDB timezone.<br>
 /// \b
 ///  Params: hour, minute
 ibp_mce_datatype__invalid_oledb_timezone_2
  =IBP_MCE_DATATYPE__INVALID_OLEDB_TIMEZONE_2,

 /// \brief
 ///  Can't convert DBTIMESTAMPOFFSET into FB040_TS_WITH_TZ. Out of range.<br>
 /// \b
 ///  Params: oledb tso
 ibp_mce_datatype__cant_convert_dbtimestampoffset_into_fb040_ts_with_tz__out_of_range__1
  =IBP_MCE_DATATYPE__CANT_CONVERT_DBTIMESTAMPOFFSET_INTO_FB040_TS_WITH_TZ__OUT_OF_RANGE__1,
 
 /// \brief
 ///  The unknown timezone id.<br>
 /// \b
 ///  Params: timezone id
 ibp_mce_datatype__unknown_timezone_id_1
  =IBP_MCE_DATATYPE__UNKNOWN_TIMEZONE_ID_1,

 /// \brief
 ///  The unknown timezone name.<br>
 /// \b
 ///  Params: timezone name
 ibp_mce_datatype__unknown_timezone_name_1
  =IBP_MCE_DATATYPE__UNKNOWN_TIMEZONE_NAME_1,

 /// \brief
 ///  The timezone is not defined.
 ibp_mce_datatype__timezone_is_not_defined_0
  =IBP_MCE_DATATYPE__TIMEZONE_IS_NOT_DEFINED_0,

 /// \brief
 ///  The date is not defined.
 ibp_mce_datatype__date_is_not_defined_0
  =IBP_MCE_DATATYPE__DATE_IS_NOT_DEFINED_0,

 /// \brief
 ///  The time is not defined.
 ibp_mce_datatype__time_is_not_defined_0
  =IBP_MCE_DATATYPE__TIME_IS_NOT_DEFINED_0,

 /// \brief
 ///  The invalid format of a timezone.
 ibp_mce_datatype__invalid_format_of_timezone_0
  =IBP_MCE_DATATYPE__INVALID_FORMAT_OF_TIMEZONE_0,

 /// \brief
 ///  The invalid format of a date.
 ibp_mce_datatype__invalid_format_of_date_0
  =IBP_MCE_DATATYPE__INVALID_FORMAT_OF_DATE_0,

 /// \brief
 ///  The invalid format of a time.
 ibp_mce_datatype__invalid_format_of_time_0
  =IBP_MCE_DATATYPE__INVALID_FORMAT_OF_TIME_0,

 /// \brief
 ///  The invalid timezone hour.<br>
 /// \b
 ///  Params: hour info
 ibp_mce_datatype__invalid_timezone_hour_1
  =IBP_MCE_DATATYPE__INVALID_TIMEZONE_HOUR_1,

 /// \brief
 ///  The invalid timezone minute.<br>
 /// \b
 ///  Params: minute info
 ibp_mce_datatype__invalid_timezone_minute_1
  =IBP_MCE_DATATYPE__INVALID_TIMEZONE_MINUTE_1,

 /// \brief
 ///  An unexpected data after value.
 ibp_mce_datatype__unexpected_data_after_value_0
  =IBP_MCE_DATATYPE__UNEXPECTED_DATA_AFTER_VALUE_0,

 /// \brief
 ///  An invalid UTF-16 text.
 /// \b
 ///  Params: offset
 ibp_mce_datatype__invalid_utf16_text_1
  =IBP_MCE_DATATYPE__INVALID_UTF16_TEXT_1,

 /// \brief
 ///  No timezone transition data for UTC time.
 /// \b
 ///  Params: timezone name, UTC-time
 ibp_mce_datatype__no_timezone_transition_data_for_utc_time_2
  =IBP_MCE_DATATYPE__NO_TIMEZONE_TRANSITION_DATA_FOR_UTC_TIME_2,
 
 /// \brief
 ///  No timezone transition data for LOCAL time.
 /// \b
 ///  Params: timezone name, LOCAL-time
 ibp_mce_datatype__no_timezone_transition_data_for_local_time_2
  =IBP_MCE_DATATYPE__NO_TIMEZONE_TRANSITION_DATA_FOR_LOCAL_TIME_2,
 
 /// \brief
 ///  A problem with loading the transition data of timezone.
 /// \b
 ///  Params: timezone name
 ibp_mce_datatype__problem_with_loading_transition_data_of_timezone_1
  =IBP_MCE_DATATYPE__PROBLEM_WITH_LOADING_TRANSITION_DATA_OF_TIMEZONE_1,
 
 /// \brief
 ///  Can't translate local timestamp into UTC timestamp. Out of range.<br>
 /// \b
 ///  Params: local ts, timezone name, offset_in_ticks (microseconds)
 ibp_mce_datatype__cant_translate_local_ts_into_utc_ts__out_of_range_3
  =IBP_MCE_DATATYPE__CANT_TRANSLATE_LOCAL_TS_INTO_UTC_TS__OUT_OF_RANGE_3,

 /// \brief
 ///  Can't translate utc timestamp into local timestamp. Out of range.<br>
 /// \b
 ///  Params: utc ts, timezone name, offset_in_ticks (microseconds)
 ibp_mce_datatype__cant_translate_utc_ts_into_local_ts__out_of_range_3
  =IBP_MCE_DATATYPE__CANT_TRANSLATE_UTC_TS_INTO_LOCAL_TS__OUT_OF_RANGE_3,

 ///////////////////////////////////////////////////////////////////////////////

 //! \brief
 //!  Запрещена установка DEFAULT-значения в параметр с типом ISNULL.
 ibp_mce_ibf_cant_set_default_value_into_isnull_parameter_0
  =IBP_MCE_IBF_CANT_SET_DEFAULT_VALUE_INTO_ISNULL_PARAMETER_0,

 //WriteBLOB
 ibp_mce_ibf_fail_create_blob_0
  =IBP_MCE_IBF_FAIL_CREATE_BLOB_0,

 ibp_mce_ibf_inadmis_type_for_blob_1
  =IBP_MCE_IBF_INADMIS_TYPE_FOR_BLOB_1,

 ibp_mce_ibf_fail_close_blob_0
  =IBP_MCE_IBF_FAIL_CLOSE_BLOB_0,

 ibp_mce_ibf_fail_cancel_blob_0
  =IBP_MCE_IBF_FAIL_CANCEL_BLOB_0,

 //WriteArray
 ibp_mce_ibf_wa_cant_write_type_as_array_1
  =IBP_MCE_IBF_WA_CANT_WRITE_TYPE_AS_ARRAY_1,

 ibp_mce_ibf_wa_unk_element_type_1
  =IBP_MCE_IBF_WA_UNK_ELEMENT_TYPE_1,

 ibp_mce_ibf_wa_IBDim_SADim_2
  =IBP_MCE_IBF_WA_IBDIM_SADIM_2,

 ibp_mce_ibf_wa_get_dim_lower_bound_2 /*dim,error*/
  =IBP_MCE_IBF_WA_GET_DIM_LOWER_BOUND_2,

 ibp_mce_ibf_wa_get_dim_upper_bound_2 /*dim,error*/
  =IBP_MCE_IBF_WA_GET_DIM_UPPER_BOUND_2,

 ibp_mce_ibf_wa_incorrect_bounds_of_dim_3 /*lower,upper,dim*/
  =IBP_MCE_IBF_WA_INCORRECT_BOUNDS_OF_DIM_3,

 ibp_mce_ibf_wa_Dim_IBRange_SARange_5
  =IBP_MCE_IBF_WA_DIM_IBRANGE_SARANGE_5,

 //Reserved

 ibp_mce_ibf_wa_fail_get_element_1
  =IBP_MCE_IBF_WA_FAIL_GET_ELEMENT_1,

 ibp_mce_ibf_wa_fail_assign_element_1
  =IBP_MCE_IBF_WA_FAIL_ASSIGN_ELEMENT_1,

 //------------

 //element type, element size
 ibp_mce_cant_create_safearray_2
  =IBP_MCE_CANT_CREATE_SAFEARRAY_2,

 ibp_mce_cant_access_safearray_data_0
  =IBP_MCE_CANT_ACCESS_SAFEARRAY_DATA_0,

 /////////////////////////////////////////////////////////////////////////
 //Запись BLOB полей

 ibp_mce_bw__fail_write_to_db_0
  =IBP_MCE_BW__FAIL_WRITE_TO_DB_0,

 //не поддерживаемая кодировка BLOB поля
 ibp_mce_bw__cs_not_support_1
  =IBP_MCE_BW__CS_NOT_SUPPORT_1,

 //reserved

 ibp_mce_bw__user_storage_bad_work_0
  =IBP_MCE_BW__USER_STORAGE_BAD_WORK_0,

 ibp_mce_bw__user_storage_fail_read_0
  =IBP_MCE_BW__USER_STORAGE_FAIL_READ_0,

 /// \brief Ошибка транслирования кодовых страниц.<br>
 /// \b Params: DestCharsetName
 ibp_mce_bw__fail_translate_from_unicode_to_cs_1
  =IBP_MCE_BW__FAIL_TRANSLATE_FROM_UNICODE_TO_CS_1,

 /// \brief Ошибка перекодирования между кодовыми страницами.<br>
 /// \b Params: SourceCharsetName, DestCharsetName
 ibp_mce_bw__fail_translate_between_cs_2
  =IBP_MCE_BW__FAIL_TRANSLATE_BETWEEN_CS_2,

 //текстовое представление binary data
 ibp_mce_bw__bad_char_in_hex_str_1
  =IBP_MCE_BW__BAD_CHAR_IN_HEX_STR_1,

 ibp_mce_bw__wrong_hex_str_0
  =IBP_MCE_BW__WRONG_HEX_STR_0,

 /// \brief Ошибка получения интерфейса хранилище данных.<br>
 /// \b Params: storage iid
 ibp_mce_bw__fail_query_storage_interface_1
  =IBP_MCE_BW__FAIL_QUERY_STORAGE_INTERFACE_1,

 /// \brief Передано хранилище данных с неподдерживаемым интерфейсом.<br>
 /// \b Params: storage iid
 ibp_mce_bw__unknown_storage_interface_1
  =IBP_MCE_BW__UNKNOWN_STORAGE_INTERFACE_1,

 /// \brief Хранилище не реализует известные интерфейсы.
 ibp_mce_bw__storage_not_support_known_interfaces_0
  =IBP_MCE_BW__STORAGE_NOT_SUPPORT_KNOWN_INTERFACES_0,

 /////////////////////////////////////////////////////////////////////////
 //Чтение BLOB полей

 //ошибка открытия BLOB поля
 ibp_mce_br__fail_open_blob_0
  =IBP_MCE_BR__FAIL_OPEN_BLOB_0,

 //ошибка чтения сегмента BLOB поля
 ibp_mce_br__fail_get_segment_0
  =IBP_MCE_BR__FAIL_GET_SEGMENT_0,

 //ошибка получения информации о длине BLOB
 ibp_mce_br__fail_get_blob_length_0
  =IBP_MCE_BR__FAIL_GET_BLOB_LENGTH_0,

 //get size, max size
 ibp_mce_br__get_bad_segment_size_2
  =IBP_MCE_BR__GET_BAD_SEGMENT_SIZE_2,

 /// \brief Ошибка транслирования кодовых страниц.<br>
 /// \b Params: SourceCharsetName
 ibp_mce_br__fail_translate_from_cs_to_unicode_cs_1
  =IBP_MCE_BR__FAIL_TRANSLATE_FROM_CS_TO_UNICODE_CS_1,

 /// \brief Ошибка перекодирования между кодовыми страницами.<br>
 /// \b Params: SourceCharsetName, DestCharsetName
 ibp_mce_br__fail_translate_between_cs_2
  =IBP_MCE_BR__FAIL_TRANSLATE_BETWEEN_CS_2,

 /// \brief Слишком большая длина BLOB-поля.<br>
 /// \b Params: length type name
 ibp_mce_br__blob_length_is_too_large_1
  =IBP_MCE_BR__BLOB_LENGTH_IS_TOO_LARGE_1,

 /// \brief Сервер не вернул сведения о размере BLOB-поля
 ibp_mce_br__server_do_not_return_blob_length_information_0
  =IBP_MCE_BR__SERVER_DO_NOT_RETURN_BLOB_LENGTH_INFORMATION_0,

 /// \brief Переполнение при расчете размера текстового блоба в виде UCS2 символов.<br>
 /// \b Params: raw_blob_len, blob charset name.
 ibp_mce_br__get_txt_blob_length_in_ucs2__overflow_2
  =IBP_MCE_BR__GET_TXT_BLOB_LENGTH_IN_UCS2__OVERFLOW_2,

 /// \brief Переполнение при расчете размера текстового блоба в виде MBC символов.<br>
 /// \b Params: raw_blob_len, blob charset name, user charset name.
 ibp_mce_br__get_txt_blob_length_in_user_mbc_cs__overflow_3
  =IBP_MCE_BR__GET_TXT_BLOB_LENGTH_IN_USER_MBC_CS__OVERFLOW_3,

 /// \brief Текстовый блоб слишком большой для загрузки в BSTR-строку.
 ibp_mce_br__txt_blob_too_long_for_load_into_bstr_0
  =IBP_MCE_BR__TXT_BLOB_TOO_LONG_FOR_LOAD_INTO_BSTR_0,

 /// \brief Переполнение при расчете количества символов для HEX-представления бинарного блоба.<br>
 /// \b Params: raw_blob_len, HEX-string type sign: STR/WSTR/BSTR.
 ibp_mce_br__cant_present_large_bin_blob_as_hex_str__overflow_2
  =IBP_MCE_BR__CANT_PRESENT_LARGE_BIN_BLOB_AS_HEX_STR__OVERFLOW_2,

 /// \brief Переполнение при расчете размера памяти под текстовое представление блоба.
 ibp_mce_br__overflow_in_calc_mem_size_for_text_data_0
  =IBP_MCE_BR__OVERFLOW_IN_CALC_MEM_SIZE_FOR_TEXT_DATA_0,

 /// \brief Запрошено хранилище с неподдерживаемым режимом доступа.<br>
 /// \b Params: dwFlags.
 ibp_mce_br__unk_storage_access_flags_1
  =IBP_MCE_BR__UNK_STORAGE_ACCESS_FLAGS_1,

 /// \brief Запрошено хранилище с неизвестным интерфейсом.<br>
 /// \b Params: storage iid.
 ibp_mce_br__unk_storage_interface_1
  =IBP_MCE_BR__UNK_STORAGE_INTERFACE_1,

 /// \brief
 ///  Ошибка запроса сведений о размере блоб-поля. Буфер имеет недостаточный размер.<br>
 /// \b
 ///  Params: buffer size
 ibp_mce_br__cant_get_blob_length__buf_is_small_1
  =IBP_MCE_BR__CANT_GET_BLOB_LENGTH__BUF_IS_SMALL_1,

 /// \brief
 ///  Ошибка получения информации о блобе.<br>
 /// \b
 ///  Params: Server error.
 ibp_mce_br__fail_get_blob_info_1
  =IBP_MCE_BR__FAIL_GET_BLOB_INFO_1,

 /////////////////////////////////////////////////////////////////////////
 //BLOB Errors

 /// \brief
 ///  Попытка закрытия закрытого блоба.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_blob__attempt_to_close_of_closed_blob_0
  =IBP_MCE_BLOB__ATTEMPT_TO_CLOSE_OF_CLOSED_BLOB_0,

 /// \brief
 ///  Попытка отмены закрытого блоба.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_blob__attempt_to_cancel_of_closed_blob_0
  =IBP_MCE_BLOB__ATTEMPT_TO_CANCEL_OF_CLOSED_BLOB_0,

 /// \brief
 ///  Чтение из закрытого блоба.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_blob__read_data_from_closed_blob_0
  =IBP_MCE_BLOB__READ_DATA_FROM_CLOSED_BLOB_0,

 /// \brief
 ///  Запись в закрытый блоб.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_blob__write_data_into_closed_blob_0
  =IBP_MCE_BLOB__WRITE_DATA_INTO_CLOSED_BLOB_0,

 /// \brief
 ///  Работа с закрытым блобом.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_blob__work_with_closed_blob_0
  =IBP_MCE_BLOB__WORK_WITH_CLOSED_BLOB_0,

 /////////////////////////////////////////////////////////////////////////
 //Internal Errors

 ibp_mce_ie_no_charset_converter_0
  =IBP_MCE_IE_NO_CHARSET_CONVERTER_0,

 /////////////////////////////////////////////////////////////////////////
 //Charsets Errors

 /// \brief
 ///  CS: Создание объекта для работы с кодовой страницей.<br>
 /// \b
 ///  Params: Charset Name
 ibp_mce_cs__create_charset_object_1
  =IBP_MCE_CS__CREATE_CHARSET_OBJECT_1,

 /// \brief
 ///  CS: Переполнение при расчете длины UNICODE-представления данных.<br>
 /// \b
 ///  Params: Charset Name
 ibp_mce_cs__calc_length_in_ucs2_chars__overflow_1
  =IBP_MCE_CS__CALC_LENGTH_IN_UCS2_CHARS__OVERFLOW_1,

 /// \brief
 ///  CS: Неизвестный внешний поставщик кодовых страниц.<br>
 /// \b
 ///  Params: DLL name, description, version.
 ibp_mce_cs__unknown_external_provider_3
  =IBP_MCE_CS__UNKNOWN_EXTERNAL_PROVIDER_3,

 /// \brief
 ///  CS: Неподдерживаемый внешний поставщик кодовых страниц.<br>
 /// \b
 ///  Params: DLL name, description, version.
 ibp_mce_cs__unsupported_external_provider_3
  =IBP_MCE_CS__UNSUPPORTED_EXTERNAL_PROVIDER_3,

 /// \brief
 ///  CS: Переполнение при расчете длины STR-представления данных.<br>
 /// \b
 ///  Params: Charset Name
 ibp_mce_cs__calc_length_in_mbc_chars__overflow_1
  =IBP_MCE_CS__CALC_LENGTH_IN_MBC_CHARS__OVERFLOW_1,

 ///////////////////////////////////////////////////////////////////////////////
 //ICU Library

 /// \brief
 ///  ICU: Unknown ICUUC/ICUIN library.<br>
 /// \b
 ///  Params: Module sign (ICUUC/ICUIN), DLL name, description, version
 ibp_mce_icu__unknown_module_version_4
  =IBP_MCE_ICU__UNKNOWN_MODULE_VERSION_4,

 /// \brief
 ///  ICU: Unsupported ICUUC/ICUIN library.<br>
 /// \b
 ///  Params: Module sign (ICUUC/ICUIN), DLL name, description, version
 ibp_mce_icu__unsupported_module_version_4
  =IBP_MCE_ICU__UNSUPPORTED_MODULE_VERSION_4,

 /// \brief
 ///  ICU: Ошибка создания конвертора кодовой страницы.<br>
 /// \b
 ///  Params: ICU Provider, Charset Name, ICU Error Code
 ibp_mce_icu__create_cs_conv_3
  =IBP_MCE_ICU__CREATE_CS_CONV_3,

 /// \brief
 ///  ICU: Ошибка вызова функции.<br>
 /// \b
 ///  Params: ICU Provider, Charset Name, Func Name, ICU Error Code
 ibp_mcs_icu__call_func_4
  =IBP_MCS_ICU__CALL_FUNC_4,

 /// \brief
 ///  ICU: Некорректный min-max размер символа.<br>
 /// \b
 ///  Params: ICU Provider, Charset Name, MinCharSize, MaxCharSize
 ibp_mce_icu__bad_min_max_char_size_4
  =IBP_MCE_ICU__BAD_MIN_MAX_CHAR_SIZE_4,

 /// \brief
 ///  ICU: Неподдерживаемый максимальный размер символов.<br>
 /// \b
 ///  Params: ICU Provider, Charset Name, MaxCharSize, LimitMaxCharSize
 ibp_mce_icu__large_max_char_size_4
  =IBP_MCE_ICU__LARGE_MAX_CHAR_SIZE_4,

 /// \brief
 ///  ICU: Bug Check.<br>
 /// \b
 ///  Params: ICU Provider, Charset Name, Function Name, CheckPoint
 ibp_mce_icu__bug_check_4
  =IBP_MCE_ICU__BUG_CHECK_4,

 /// \brief
 ///  ICU: Can't convert one ascii char to unicode.<br>
 /// \b
 ///  Params: ICU Provider, Charset Name
 ibp_mce_icu__cant_conv_one_ascii_to_unicode_2
  =IBP_MCE_ICU__CANT_CONV_ONE_ASCII_TO_UNICODE_2,

 /// \brief
 ///  ICU: Ошибка инициализации.<br>
 /// \b
 ///  Params: ICU Error Code
 ibp_mce_icu__failed_to_initialize_1
  =IBP_MCE_ICU__FAILED_TO_INITIALIZE_1,

 /// \brief
 ///  ICU: ICUIN library is requiring the explicit initialization of ICUUC library.<br>
 /// \b
 ///  Params: ICUIN DLL path, ICUIN DLL version
 ibp_mce_icu__icuin_is_requiring_explicit_initialization_of_icuuc_2
  =IBP_MCE_ICU__ICUIN_IS_REQUIRING_EXPLICIT_INITIALIZATION_OF_ICUUC_2,

 /// \brief
 ///  ICU: ICUIN and ICUUC have different versions.<br>
 /// \b
 ///  Params: ICUIN module, ICUIN version, ICUUC module, ICUUC version
 ibp_mce_icu__icuin_and_icuuc_have_different_versions_4
  =IBP_MCE_ICU__ICUIN_AND_ICUUC_HAVE_DIFFERENT_VERSIONS_4,

 /// \brief
 ///  ICU: There is a problem with opening of the calendar.<br>
 /// \b
 ///  Params: Time Zone Name, ICU Error Code
 ibp_mce_icu__failed_to_open_calendar_2
  =IBP_MCE_ICU__FAILED_TO_OPEN_CALENDAR_2,

 /// \brief
 ///  ICU: [BUG CHECK] The function of an opening a calendar returned a NULL pointer.<br>
 /// \b
 ///  Params: Function Name, Time Zone Name
 ibp_mce_icu__bug_check_func_for_open_calendar_returned_null_ptr_2
  =IBP_MCE_ICU__BUG_CHECK_FUNC_FOR_OPEN_CALENDAR_RETURNED_NULL_PTR_2,

 /// \brief
 ///  ICU: There is a problem with setting of the calendar date (millis).<br>
 /// \b
 ///  Params: ICU Date, Time Zone Name, ICU Error Code
 ibp_mce_icu__failed_to_set_calendar_millis_3
  =IBP_MCE_ICU__FAILED_TO_SET_CALENDAR_MILLIS_3,

 /// \brief
 ///  ICU: There is a problem with setting of the calendar datetime.
 /// \b
 ///  Params: Year, Month, Day, Hour, Minute, Second, Time Zone Name, ICU Error Code
 ibp_mce_icu__failed_to_set_calendar_datetime_8
 =IBP_MCE_ICU__FAILED_TO_SET_CALENDAR_DATETIME_8,

 /// \brief
 ///  ICU: There is a problem with getting of the calendar date offset.<br>
 /// \b
 ///  Params: Time Zone Name, ICU Error Code
 ibp_mce_icu__failed_to_get_calendar_date_offset_2
  =IBP_MCE_ICU__FAILED_TO_GET_CALENDAR_DATE_OFFSET_2,

 /// \brief
 ///  ICU: There is a problem with getting of the calendar dst offset.<br>
 /// \b
 ///  Params: Time Zone Name, ICU Error Code
 ibp_mce_icu__failed_to_get_calendar_dst_offset_2
  =IBP_MCE_ICU__FAILED_TO_GET_CALENDAR_DST_OFFSET_2,

 /// \brief
 ///  ICU: There is a problem with getting (for verification) of the calendar timezone name.<br>
 /// \b
 ///  Params: checked timezone name, ICU Error Code
 ibp_mce_icu__failed_to_get_calendar_timezone_name_2
  =IBP_MCE_ICU__FAILED_TO_GET_CALENDAR_TIMEZONE_NAME_2,

 /// \brief
 ///  ICU: [BUG CHECK] GetTimeZoneID returned an negative value.<br>
 /// \b
 ///  Params: FUNC NAME, RESULT VALUE, TZ NAME
 ibp_mce_icu__bug_check__gettimezoneid_return_negative_value_3
  =IBP_MCE_ICU__BUG_CHECK__GETTIMEZONEID_RETURN_NEGATIVE_VALUE_3,

 /// \brief
 ///  ICU: [BUG CHECK] Calendar is linked with another timezone.<br>
 /// \b
 ///  Params: expected timezone, actual timezone
 ibp_mce_icu__bug_check_calendar_is_linked_with_another_timezone_2
  =IBP_MCE_ICU__BUG_CHECK_CALENDAR_IS_LINKED_WITH_ANOTHER_TIMEZONE_2,

 /// \brief
 ///  ICU: Enumerating of the time zone names was failed.<br>
 /// \b
 ///  Params: ICU Error Code
 ibp_mce_icu__failed_to_enumerate_timezone_names_1
  =IBP_MCE_ICU__FAILED_TO_ENUMERATE_TIMEZONE_NAMES_1,

 /// \brief
 ///  ICU: [BUG CHECK] The function of enumerating timezones returned a NULL pointer.
 /// \b
 ///  Params: Func Name
 ibp_mce_icu__bug_check_func_for_enum_timezones_returned_null_ptr_1
  =IBP_MCE_ICU__BUG_CHECK_FUNC_FOR_ENUM_TIMEZONES_RETURNED_NULL_PTR_1,

 /// \brief
 ///  ICU: Fetching a name from timezone enumeration was failed.<br>
 /// \b
 ///  Params: ICU Error Code
 ibp_mce_icu__failed_to_fetch_name_from_timezone_enum_1
  =IBP_MCE_ICU__FAILED_TO_FETCH_NAME_FROM_TIMEZONE_ENUM_1,

 /// \brief
 ///  ICU: [BUG CHECK] uenum_unext returned a negative length.<br>
 /// \b
 ///  Params: func name, length
 ibp_mce_icu__bug_check_uenum_unext_returned_negative_length_2
  =IBP_MCE_ICU__BUG_CHECK_UENUM_UNEXT_RETURNED_NEGATIVE_LENGTH_2,

 /// \brief
 ///  ICU: Failed to set timezone files directory.<br>
 /// \b
 ///  Params: ICU Error Code
 ibp_mce_icu__failed_to_tzdata_files_dir_1
  =IBP_MCE_ICU__FAILED_TO_TZDATA_FILES_DIR_1,

 ///////////////////////////////////////////////////////////////////////////////
 //Messages for Generators of Database Object Scripts

 /// \b Params: Domain Name, Numeric Base Type, Scale.
 ibp_mce_dbobj__sql_gen__bad_numeric_domain_scale_3
  =IBP_MCE_DBOBJ__SQL_GEN__BAD_NUMERIC_DOMAIN_SCALE_3,

 /// \b Params: Domain Name, Numeric Base Type, Precision.
 ibp_mce_dbobj__sql_gen__bad_numeric_domain_precision_3
  =IBP_MCE_DBOBJ__SQL_GEN__BAD_NUMERIC_DOMAIN_PRECISION_3,

 /// \b Params: Domain Name, Domain Type, Length, Min Length, Max Length.
 ibp_mce_dbobj__sql_gen__bad_text_domain_length_5
  =IBP_MCE_DBOBJ__SQL_GEN__BAD_TEXT_DOMAIN_LENGTH_5,

 /// \b Params: SP Name, Param Name, Param Type (IN/OUT), BadNumber, ReqNumber
 ibp_mce_dbobj__sql_gen__bad_sp_param_number_5
  =IBP_MCE_DBOBJ__SQL_GEN__BAD_SP_PARAM_NUMBER_5,

 /// \b Params: SP Name, Param Name, UnkDirection
 ibp_mce_dbobj__sql_gen__unk_sp_param_direction_3
  =IBP_MCE_DBOBJ__SQL_GEN__UNK_SP_PARAM_DIRECTION_3,

 /// \b Params: Domain Name, UnkSubType
 ibp_mce_dbobj__sql_gen__unk_numeric_domain_subtype_2
  =IBP_MCE_DBOBJ__SQL_GEN__UNK_NUMERIC_DOMAIN_SUBTYPE_2,

 /// \b Params: Domain Name
 ibp_mce_dbobj__sql_gen__blob_domain_without_subtype_1
  =IBP_MCE_DBOBJ__SQL_GEN__BLOB_DOMAIN_WITHOUT_SUBTYPE_1,

 /// \b Params: Domain Name, BLR Type ID
 ibp_mce_dbobj__sql_gen__unk_domain_blr_data_type_2
  =IBP_MCE_DBOBJ__SQL_GEN__UNK_DOMAIN_BLR_DATA_TYPE_2,

 /// \b Params: Domain Name
 ibp_mce_dbobj__sql_gen__domain_without_cset_1
  =IBP_MCE_DBOBJ__SQL_GEN__DOMAIN_WITHOUT_CSET_1,

 /// \b Params: SP Name
 ibp_mce_dbobj__sql_gen__build_sp_header_source_1
  =IBP_MCE_DBOBJ__SQL_GEN__BUILD_SP_HEADER_SOURCE_1,

 /// \b Params: Domain Name, Precision, Scale, Base Domain Type
 ibp_mce_dbobj__sql_gen__bad_numeric_domain_precision_scale_4
  =IBP_MCE_DBOBJ__SQL_GEN__BAD_NUMERIC_DOMAIN_PRECISION_SCALE_4,

 /// \b Params: Stored Procedure Name, Parameter Name
 ibp_mce_dbobj__sql_gen__bad_sp_param_state_2
  =IBP_MCE_DBOBJ__SQL_GEN__BAD_SP_PARAM_STATE_2,

 /// \brief Некорректная длина текстовых данных в байтах.<br>
 /// \b Params: domain name, type name, length, charset name, bytes_per_char
 ibp_mce_dbobj__sql_gen__wrong_text_datatype_length_in_bytes_5
  =IBP_MCE_DBOBJ__SQL_GEN__WRONG_TEXT_DATATYPE_LENGTH_IN_BYTES_5,

 /// \brief Ошибка генерации определения UDF.<br>
 /// \b Params: UDF Name
 ibp_mce_dbobj__sql_gen__build_udf_source_1
  =IBP_MCE_DBOBJ__SQL_GEN__BUILD_UDF_SOURCE_1,

 /// \brief BLOB-аргумент UDF имеет неподдерживаемый субтип.<br>
 /// \b Params: domain name, sub_type_id
 ibp_mce_dbobj__sql_gen__udf_blob_arg_has_not_support_sub_type_2
  =IBP_MCE_DBOBJ__SQL_GEN__UDF_BLOB_ARG_HAS_NOT_SUPPORT_SUB_TYPE_2,

 ///////////////////////////////////////////////////////////////////////////////
 //Array errors

 /// \brief Генерация SDL для дескриптора массива.<br>
 /// \b Params: table name, column name
 ibp_mce_array__create_sdl__failed_2
  =IBP_MCE_ARRAY__CREATE_SDL__FAILED_2,

 /// \brief Генерация SDL. Слишком длинная строка.<br>
 /// \b Params: string length, max length
 ibp_mce_array__create_sdl__too_long_str_2
  =IBP_MCE_ARRAY__CREATE_SDL__TOO_LONG_STR_2,

 /// \brief Запись массива в БД.<br>
 /// \b Params: table name, column name
 ibp_mce_array__write_array_to_db_2
  =IBP_MCE_ARRAY__WRITE_ARRAY_TO_DB_2,

 /// \brief Загрузка массива из БД.<br>
 /// \b Params: table name, column name
 ibp_mce_array__read_array_from_db_2
  =IBP_MCE_ARRAY__READ_ARRAY_FROM_DB_2,

 /// \brief Ошибка формирования дескриптора массива.<br>
 /// \b Params: table name, column name
 ibp_mce_array__build_descr__failed_2
  =IBP_MCE_ARRAY__BUILD_DESCR__FAILED_2,

 /// \brief Переполнение при вычислении количества элементов в массиве.<br>
 /// \b Params: RelationName, FieldName
 ibp_mce_array__calc_total_element_count__overflow_2
  =IBP_MCE_ARRAY__CALC_TOTAL_ELEMENT_COUNT__OVERFLOW_2,

 /// \brief Переполнение при вычислении размера памяти под данные массива.<br>
 /// \b Params: RelationName, FieldName, Total Element Count, Element Size
 ibp_mce_array__calc_memory_size__overflow_4
  =IBP_MCE_ARRAY__CALC_MEMORY_SIZE__OVERFLOW_4,

 /// \brief
 ///  Ошибка загрузки и декодирования низкоуровневого дескриптора массива.
 ibp_mce_array__failed_to_read_and_decode_internal_array_desc_0
  =IBP_MCE_ARRAY__FAILED_TO_READ_AND_DECODE_INTERNAL_ARRAY_DESC_0,

 /// \brief
 ///  Ошибка загрузки и декодирования низкоуровневого дескриптора массива.
 ibp_mce_array__failed_to_encode_and_write_internal_array_desc_0
  =IBP_MCE_ARRAY__FAILED_TO_ENCODE_AND_WRITE_INTERNAL_ARRAY_DESC_0,

 /// \brief
 ///  The value with this type cannot be used to save as an array.<br>
 /// \b
 ///  Params: source value type
 ibp_mce_array__unsupported_source_value_type_1
  =IBP_MCE_ARRAY__UNSUPPORTED_SOURCE_VALUE_TYPE_1,

 //-----------------------------------------------------------------------
 /// \brief
 ///  [BUG CHECK] Некорректный размер элемента в описании массива.<br>
 /// \b
 ///  Params: place, point, table name, column name, type name, size
 ibp_mce_array__bug_check__incorrect_array_element_size_6
  =IBP_MCE_ARRAY__BUG_CHECK__INCORRECT_ARRAY_ELEMENT_SIZE_6,

 //-----------------------------------------------------------------------
 /// \brief
 ///  [BUG CHECK] Неожиданное количество размерностей в данных массива.<br>
 /// \b
 ///  Params: place, point, actualDimCount, expectedDimCount
 ibp_mce_array_blob__bug_check__unexpected_dim_count_4
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__UNEXPECTED_DIM_COUNT_4,

 /// \brief
 ///  [BUG CHECK] Некорректный диапазон размерности в данных массива.<br>
 /// \b
 ///  Params: place, point, iDim, actualLower, actualUpper, defLower, defUpper
 ibp_mce_array_blob__bug_check__incorrect_range_of_dim_7
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__INCORRECT_RANGE_OF_DIM_7,

 /// \brief
 ///  [BUG CHECK] Некорректный масштаб данных массива.<br>
 /// \b
 ///  Params: place, point, baseTypeName, scale
 ibp_mce_array_blob__bug_check__incorrect_scale_4
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__INCORRECT_SCALE_4,

 /// \brief
 ///  [BUG CHECK] Неожиданный размер элемента в данных массива.<br>
 /// \b
 ///  Params: place, point, dataTypeName, actualSize, expectedSize
 ibp_mce_array_blob__bug_check__unexpected_size_of_element_5
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__UNEXPECTED_SIZE_OF_ELEMENT_5,

 /// \brief
 ///  [BUG CHECK] Некорректный размер элемента в данных массива.<br>
 /// \b
 ///  Params: place, point, dataTypeName, element size
 ibp_mce_array_blob__bug_check__incorrect_element_size_4
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__INCORRECT_ELEMENT_SIZE_4,

 /// \brief
 ///  [BUG CHECK] Неизвестный низкоуровневый тип элемента в данных массива.<br>
 /// \b
 ///  Params: place, point, dtypeID
 ibp_mce_array_blob__bug_check__unknown_internal_dtype_3
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__UNKNOWN_INTERNAL_DTYPE_3,

 /// \brief
 ///  [BUG CHECK] Неожиданные данные за последним элементом массива.<br>
 /// \b
 ///  Params: place, point
 ibp_mce_array_blob__bug_check__unexpected_data_after_last_element_2
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__UNEXPECTED_DATA_AFTER_LAST_ELEMENT_2,

 /// \brief
 ///  [BUG CHECK] Несогласованный размер строкового элемента и размер символа в данных массива.<br>
 /// \b
 ///  Params: place, point, dataTypeName, element LENGTH in bytes, charset name, bytes per char
 ibp_mce_array_blob__bug_check__incorrect_length_of_string_element_6
  =IBP_MCE_ARRAY_BLOB__BUG_CHECK__INCORRECT_LENGTH_OF_STRING_ELEMENT_6,

 /////////////////////////////////////////////////////////////////////////

 /// \brief
 ///  Несогласованные настройки глобального кэша парсера SQL-запросов.<br>
 /// \b
 ///  Params: setting name, cur value, req value
 ibp_mce_global_sql_cache__inconsistent_setting_3
  =IBP_MCE_GLOBAL_SQL_CACHE__INCONSISTENT_SETTING_3,

 /////////////////////////////////////////////////////////////////////////
 //Messages for updatable rowset messages

 //TIBSSRowsetStorage ----------------------------------------------------
 ibp_mce_ss_rs_reqursion_in_row_list_0
  =IBP_MCE_SS_RS_REQURSION_IN_ROW_LIST_0,

 ibp_mce_ss_rs_incorrect_row_bmk_0
  =IBP_MCE_SS_RS_INCORRECT_ROW_BMK_0,

 ibp_mce_ss_rs_incorrect_row_data_ptr_0
  =IBP_MCE_SS_RS_INCORRECT_ROW_DATA_PTR_0,

 ibp_mce_ss_rs_fail_read_row_header_0
  =IBP_MCE_SS_RS_FAIL_READ_ROW_HEADER_0,

 ibp_mce_ss_rs_fail_read_row_data_0
  =IBP_MCE_SS_RS_FAIL_READ_ROW_DATA_0,

 ibp_mce_ss_set_data_bad_column_ordinal_3
  =IBP_MCE_SS_SET_DATA_BAD_COLUMN_ORDINAL_3,

 ibp_mce_ss_fail_read_column_data_1
  =IBP_MCE_SS_FAIL_READ_COLUMN_DATA_1,

 ibp_mce_ss_fail_processing_column_data_0
  =IBP_MCE_SS_FAIL_PROCESSING_COLUMN_DATA_0,

 ibp_mce_ss_bind_column_errors_1
  =IBP_MCE_SS_BIND_COLUMN_ERRORS_1,

 /// \brif
 ///  Предыдущая установка значения поля завершилось с ошибками.<br>
 /// \b
 ///  Params: column name.
 ibp_mce_ss__previous_set_field_value_was_failed_1
  =IBP_MCE_SS__PREVIOUS_SET_FIELD_VALUE_WAS_FAILED_1,

 //установка данных колонок ----------------------------------------------

 /// \brief Многократное указание значения для одной и той же колонки.<br>
 /// \b Params: Column Ordinal
 ibp_mce_ss_multiple_values_for_one_column_1
  =IBP_MCE_SS_MULTIPLE_VALUES_FOR_ONE_COLUMN_1,

 ibp_mce_ss_fail_install_column_data_2
  =IBP_MCE_SS_FAIL_INSTALL_COLUMN_DATA_2,

 ibp_mce_ss_fail_copy_column_data_2
  =IBP_MCE_SS_FAIL_COPY_COLUMN_DATA_2,

 //Reserved

 ibp_mce_ss_fail_load_defer_column_value_2
  =IBP_MCE_SS_FAIL_LOAD_DEFER_COLUMN_VALUE_2,

 ibp_mce_ss_fail_refresh_column_data_2
  =IBP_MCE_SS_FAIL_REFRESH_COLUMN_DATA_2,

 //ошибки связанные со служебными запросами ------------------------------

 /// \brief
 ///  Ошибка формирования значения IN-параметра служебного запроса.<br>
 /// \b
 ///  Params: param_idx, full marker sign, column_idx
 ibp_mce_ss_stmt__cant_build_in_param_value_from_column_value_3
  =IBP_MCE_SS_STMT__CANT_BUILD_IN_PARAM_VALUE_FROM_COLUMN_VALUE_3,

 /// \brief
 ///  Ошибка подготовки служебного запроса.<br>
 /// \b
 ///  Params: stmt index
 ibp_mce_ss_stmt__cant_prepare_service_stmt_1
  =IBP_MCE_SS_STMT__CANT_PREPARE_SERVICE_STMT_1,

 /// \brief
 ///  Ошибка формирования IN-параметров для служебного запроса.<br>
 /// \b
 ///  Params: stmt index
 ibp_mce_ss_stmt__cant_build_in_params_for_service_stmt_1
  =IBP_MCE_SS_STMT__CANT_BUILD_IN_PARAMS_FOR_SERVICE_STMT_1,

 /// \brief
 ///  Ошибка выполнения служебного запроса.<br>
 /// \b
 ///  Params: stmt index
 ibp_mce_ss_stmt__cant_execute_service_stmt_1
  =IBP_MCE_SS_STMT__CANT_EXECUTE_SERVICE_STMT_1,

 /// \brief
 ///  Ошибка генерации уникального идентификатора для колонки.<br>
 /// \b
 ///  Params: param_idx, full marker sign, column_idx
 ibp_mce_ss_stmt__cant_generate_unique_id_for_in_param_3
  =IBP_MCE_SS_STMT__CANT_GENERATE_UNIQUE_ID_FOR_IN_PARAM_3,

 /// \brief
 ///  Неподдерживаемый тип сервисного запроса.<br>
 /// \b
 ///  Params: stmt signature
 ibp_mce_ss_stmt__unsupported_stmt_type_1
  =IBP_MCE_SS_STMT__UNSUPPORTED_STMT_TYPE_1,

 /// \brief
 ///  Сервисные запросы, возвращающие множества, не поддерживаются.<br>
 /// \b
 ///  Params: stmt signature
 ibp_mce_ss_stmt__cant_use_select_stmt_1
  =IBP_MCE_SS_STMT__CANT_USE_SELECT_STMT_1,

 /// \brief
 ///  Сервисный запрос должен возвращать множество.<br>
 /// \b
 ///  Params: stmt signature
 ibp_mce_ss_stmt__cant_use_stmt_without_rs_1
  =IBP_MCE_SS_STMT__CANT_USE_STMT_WITHOUT_RS_1,

 /// \brief
 ///  Сервисные запросы многократно модифицируют колонку перед выполнением.<br>
 /// \b
 ///  Params: markers count, column index, column name
 ibp_mce_ss_stmt__sqls_contains_mult_changes_of_col_before_execs_3
  =IBP_MCE_SS_STMT__SQLS_CONTAINS_MULT_CHANGES_OF_COL_BEFORE_EXECS_3,

 /// \brief
 ///  Сервисные запросы многократно модифицируют колонку после выполнения.<br>
 /// \b
 ///  Params: markers count, column index, column name
 ibp_mce_ss_stmt__sqls_contains_mult_changes_of_col_after_execs_3
  =IBP_MCE_SS_STMT__SQLS_CONTAINS_MULT_CHANGES_OF_COL_AFTER_EXECS_3,

 /// \brief
 ///  Выполнение служебного запроса.<br>
 /// \b
 ///  Params: stmt index, message
 ibp_mce_ss_stmt__execution_service_stmt_2
  =IBP_MCE_SS_STMT__EXECUTION_SERVICE_STMT_2,

 /// \brief
 ///  Выполнение служебного запроса завершилось с некоторыми проблемами.<br>
 /// \b
 ///  Params: stmt index
 ibp_mce_ss_stmt__execution_service_stmt_finished_with_some_problems_1
  =IBP_MCE_SS_STMT__EXECUTION_SERVICE_STMT_FINISHED_WITH_SOME_PROBLEMS_1,

 /// \brief
 ///  Ошибка чтения значения OUT-параметра.<br>
 /// \b
 ///  Params: linked column index, linked column name
 ibp_mce_ss_stmt__failed_to_read_out_param_value_2
  =IBP_MCE_SS_STMT__FAILED_TO_READ_OUT_PARAM_VALUE_2,

 /// \brief
 ///  Ошибка установки значения OUT-параметра.<br>
 /// \b
 ///  Params: linked column index, linked column name
 ibp_mce_ss_stmt__failed_to_assign_out_param_value_2
  =IBP_MCE_SS_STMT__FAILED_TO_ASSIGN_OUT_PARAM_VALUE_2,

 //Common errors ---------------------------------------------------------

 /// \brief  В процессе удаления страницы списка с заголовками рядов произошли ошибки.
 ibp_mce_ss__problem_at_row_page_delete_0
  =IBP_MCE_SS__PROBLEM_AT_ROW_PAGE_DELETE_0,

 /// \brief  В процессе удаления страницы списка отложенных изменений произошли ошибки.
 ibp_mce_ss__problem_at_pending_list_page_delete_0
  =IBP_MCE_SS__PROBLEM_AT_PENDING_LIST_PAGE_DELETE_0,

 //Write change back to database -----------------------------------------

 ibp_mce_ss_dbchange_delete_row_failed_0
  =IBP_MCE_SS_DBCHANGE_DELETE_ROW_FAILED_0,

 ibp_mce_ss_dbchange_insert_row_failed_0
  =IBP_MCE_SS_DBCHANGE_INSERT_ROW_FAILED_0,

 ibp_mce_ss_dbchange_update_row_failed_0
  =IBP_MCE_SS_DBCHANGE_UPDATE_ROW_FAILED_0,

 //запрос колонок первичного ключа
 ibp_mce_ss_provider_cant_obtain_PK_of_opened_query_0
  =IBP_MCE_SS_PROVIDER_CANT_OBTAIN_PK_OF_OPENED_QUERY_0,

 ibp_mce_ss_query_table_primary_key_2
  =IBP_MCE_SS_QUERY_TABLE_PRIMARY_KEY_2,

 ibp_mce_ss_unknown_PK_column_of_table_2
  =IBP_MCE_SS_UNKNOWN_PK_COLUMN_OF_TABLE_2,

 ibp_mce_ss_table_has_no_primary_key_1
  =IBP_MCE_SS_TABLE_HAS_NO_PRIMARY_KEY_1,

 /// \brief
 ///  Колонка первичного ключа содержит NULL.<br>
 /// \b
 ///  Params: Column Name, Table Name
 ibp_mce_ss_primary_key_column_of_table_has_NULL_2
  =IBP_MCE_SS_PRIMARY_KEY_COLUMN_OF_TABLE_HAS_NULL_2,

 /// \brief
 ///  Колонка первичного ключа содержит пустое (DEFAULT) значение.<br>
 /// \b
 ///  Params: Column Name, Table Name
 ibp_mce_ss_primary_key_column_of_table_has_EMPTY_value_2
  =IBP_MCE_SS_PRIMARY_KEY_COLUMN_OF_TABLE_HAS_EMPTY_VALUE_2,

 //запрос списка обновляемых колонок набора
 ibp_mce_ss_provider_cant_obtain_updated_column_of_opened_query_0
  =IBP_MCE_SS_PROVIDER_CANT_OBTAIN_UPDATED_COLUMN_OF_OPENED_QUERY_0,

 ibp_mce_ss_query_updated_columns_of_table_2
  =IBP_MCE_SS_QUERY_UPDATED_COLUMNS_OF_TABLE_2,

 ibp_mce_ss_unknown_column_of_table_2
  =IBP_MCE_SS_UNKNOWN_COLUMN_OF_TABLE_2,

 /// \brief (Автоматическое) обновление набора рядов невозможно.
 ibp_mce_ss_update_of_current_result_set_not_supported_0
  =IBP_MCE_SS_UPDATE_OF_CURRENT_RESULT_SET_NOT_SUPPORTED_0,

 /// \brief
 ///  Нет колонок, определяющих первичный ключ записи.
 ibp_mce_ss_no_columns_from_primary_key_0
  =IBP_MCE_SS_NO_COLUMNS_FROM_PRIMARY_KEY_0,

 //вставка нового ряда
 ibp_mce_ss_cant_insert_row_without_values_of_columns_0
  =IBP_MCE_SS_CANT_INSERT_ROW_WITHOUT_VALUES_OF_COLUMNS_0,

 //ошибки генерации нового значения колонки
 ibp_mce_ss_fail_gen_id_2
  =IBP_MCE_SS_FAIL_GEN_ID_2,

 ibp_mce_ss_fail_gen_id_no_data_1
  =IBP_MCE_SS_FAIL_GEN_ID_NO_DATA_1,

 ibp_mce_ss_fail_gen_id_unk_type_2
  =IBP_MCE_SS_FAIL_GEN_ID_UNK_TYPE_2,

 //ошибка обработки отложенных рядов
 //errors,total count
 ibp_mce_ss_fail_commit_pendings_rows_2
  =IBP_MCE_SS_FAIL_COMMIT_PENDINGS_ROWS_2,

 ibp_mce_ss_fail_rollback_pendings_rows_2
  =IBP_MCE_SS_FAIL_ROLLBACK_PENDINGS_ROWS_2,

 //парсер пользовательских запросов управления данными -------------------
 ibp_mce_ss_param_cant_use_unnamed_params_0
  =IBP_MCE_SS_PARAM_CANT_USE_UNNAMED_PARAMS_0,

 //некорректный формат списка параметров
 ibp_mce_ss_bad_format_of_param_list_0
  =IBP_MCE_SS_BAD_FORMAT_OF_PARAM_LIST_0,

 /// \brief
 ///  Запрещение использования маркера параметра с определенным типом.<br>
 /// \b
 ///  Params: index, сигнатура маркера параметра
 ibp_mce_ss_param_invalid_cat_of_parameter_2
  =IBP_MCE_SS_PARAM_INVALID_CAT_OF_PARAMETER_2,

 ibp_mce_ss_param_bad_format_no_gen_name_0
  =IBP_MCE_SS_PARAM_BAD_FORMAT_NO_GEN_NAME_0,

 ibp_mce_ss_param_bad_format_no_col_name_1
  =IBP_MCE_SS_PARAM_BAD_FORMAT_NO_COL_NAME_1,

 ibp_mce_ss_param_bad_format_no_base_col_name_2
  =IBP_MCE_SS_PARAM_BAD_FORMAT_NO_BASE_COL_NAME_2,

 /// \brief К маркеру параметра привязана неизвестная колонка.<br>
 /// \b Params: marker idx, full marker sign.
 ibp_mce_ss_param__unk_col_in_marker_2
  =IBP_MCE_SS_PARAM__UNK_COL_IN_MARKER_2,

 /// \brief Неоднозначный выбор колонки для маркера параметра.<br>
 /// \b Params: marker idx, full marker sign.
 ibp_mce_ss_param__ambiguous_col_selection_for_marker_2
  =IBP_MCE_SS_PARAM__AMBIGUOUS_COL_SELECTION_FOR_MARKER_2,

 /// \brief Нарушен формат маркера параметра.<br>
 /// \b Params: MarkerPrefix
 ibp_mce_ss_param_bad_format_1
  =IBP_MCE_SS_PARAM_BAD_FORMAT_1,

 /// \brief Неопределен префикс именованных параметров
 ibp_mce_ss_named_param_prefix_not_def_0
  =IBP_MCE_SS_NAMED_PARAM_PREFIX_NOT_DEF_0,

 /// \brief Запросы с генерируемым списком параметров не поддерживаются
 ibp_mce_ss_param__stmt_with_auto_gen_param_list_not_supported_0
  =IBP_MCE_SS_PARAM__STMT_WITH_AUTO_GEN_PARAM_LIST_NOT_SUPPORTED_0,

 /// \brief
 ///  Запрос содержит неявный параметра.<br>
 /// \b
 ///  param index, param name, param type, param flags.
 ibp_mce_ss_param__stmt_contains_implicit_param_4
  =IBP_MCE_SS_PARAM__STMT_CONTAINS_IMPLICIT_PARAM_4,

 //парсер правил генерации ключей ----------------------------------------

 /// \brief Неподдерживаемый тип маркера в списке правил авто-генерации ключей множества.<br>
 /// \b Params: MarkerNum, MarkerPrefix
 ibp_mce_ss__auto_gen_key_rule__unsupported_marker_type_2
  =IBP_MCE_SS__AUTO_GEN_KEY_RULE__UNSUPPORTED_MARKER_TYPE_2,

 /// \brief Ошибка в формате списка с правилами генерации ключей
 ibp_mce_ss_auto_gen_key_rule__bad_format_0
  =IBP_MCE_SS_AUTO_GEN_KEY_RULE__BAD_FORMAT_0,

 /// \brief Неоднозначный выбор колонки для правила авто-генерации ключа.<br>
 /// \b Params: MarkerNum, FullMarkerSign
 ibp_mce_ss_auto_gen_key_rule__ambiguous_col_selection_for_marker_2
  =IBP_MCE_SS_AUTO_GEN_KEY_RULE__AMBIGUOUS_COL_SELECTION_FOR_MARKER_2,

 /// \brief Неизвестная колонка в правиле авто-генерации ключа.<br>
 /// \b Params: MarkerNum, FullMarkerSign
 ibp_mce_ss_auto_gen_key_rule__unk_col_in_marker_2
  =IBP_MCE_SS_AUTO_GEN_KEY_RULE__UNK_COL_IN_MARKER_2,

 /// \brief Повторное определение правила генерации значения для колонки.<br>
 /// \b Params: MarkerNum, FullMarkerSign
 ibp_mce_ss_auto_gen_key_rule__rule_for_col_already_defined_2
  =IBP_MCE_SS_AUTO_GEN_KEY_RULE__RULE_FOR_COL_ALREADY_DEFINED_2,

 /// \brief Произошли ошибки при обработке списка правил генерации ключей
 ibp_mce_ss_auto_gen_key_rule__list_process_was_failed_0
  =IBP_MCE_SS_AUTO_GEN_KEY_RULE__LIST_PROCESS_WAS_FAILED_0,

 //refresh ---------------------------------------------------------------

 /// \brief Перечитывание записей для текущего набора рядов не поддерживается.
 ibp_mce_ss_refresh_of_current_result_set_not_supported_0
  =IBP_MCE_SS_REFRESH_OF_CURRENT_RESULT_SET_NOT_SUPPORTED_0,

 /// \brief Запись не зайдена. Она либо удалена, либо недоступна из текущей транзакции.
 ibp_mce_ss_refresh__record_was_deleted_or_not_visible_0
  =IBP_MCE_SS_REFRESH__RECORD_WAS_DELETED_OR_NOT_VISIBLE_0,

 /// \brief Перечитывающий запрос вернул больше одной записи.
 ibp_mce_ss_refresh__get_multiple_rows_0
  =IBP_MCE_SS_REFRESH__GET_MULTIPLE_ROWS_0,

 /// \brief Определено больше одного запроса для чтения текущего состояния записи в БД.<br>
 /// \b Params: stmt count.
 ibp_mce_ss_refresh__multiple_refresh_stmts_1
  =IBP_MCE_SS_REFRESH__MULTIPLE_REFRESH_STMTS_1,

 /// \brief Некорректный пользовательский запрос для перечитывания данных.<br>
 /// \b Params: rowset column count, user stmt column count
 ibp_mce_ss_refresh__user_refresh_stmt__wrong_column_count_2
  =IBP_MCE_SS_REFRESH__USER_REFRESH_STMT__WRONG_COLUMN_COUNT_2,

 /// \brief
 ///  В запросе для перечитывания данных обнаружена колонка, несовместимая с базовым набором рядов.<br>
 /// \b Params: stmt column name, base column number, base column name, reason
 ibp_mce_ss_refresh__wrong_column_in_refresh_stmt_4
  =IBP_MCE_SS_REFRESH__WRONG_COLUMN_IN_REFRESH_STMT_4,

 /// \brief Ошибка перезагрузки данных ряда.<br>
 /// \b Params: row number (from zero), error message
 ibp_mce_ss_refresh__cant_refresh_row_data_2
  =IBP_MCE_SS_REFRESH__CANT_REFRESH_ROW_DATA_2,

 //process of pending row ------------------------------------------------

 /// \brief
 ///  Insert ожидающей записи.<br>
 /// \b
 ///  Params: row number, message
 ibp_mce_ss__commit_pending_row__insert_2
  =IBP_MCE_SS__COMMIT_PENDING_ROW__INSERT_2,

 /// \brief
 ///  Update ожидающей записи.<br>
 /// \b
 ///  Params: row number, message
 ibp_mce_ss__commit_pending_row__update_2
  =IBP_MCE_SS__COMMIT_PENDING_ROW__UPDATE_2,

 /// \brief
 ///  Delete ожидающей записи.<br>
 /// \b
 ///  Params: row number, message
 ibp_mce_ss__commit_pending_row__delete_2
  =IBP_MCE_SS__COMMIT_PENDING_ROW__DELETE_2,

 /////////////////////////////////////////////////////////////////////////
 //CRT Errors

 /// \brief Can't create thread through _beginthreadex.<br/>
 /// \b Params: Thread Name, CRT error code, WIN32 error Code
 ibp_mce_crt__cant_create_thread_3
  =IBP_MCE_CRT__CANT_CREATE_THREAD_3,

 /////////////////////////////////////////////////////////////////////////
 //ZLIB1 Errors

 //! \brief
 //!  ZLIB1 Deflate Initialize Error
 //! \b
 //!  Params: zlib1 error code
 ibp_mce_zlib1__deflate_init_error_1
  =IBP_MCE_ZLIB1__DEFLATE_INIT_ERROR_1,

 //! \brief
 //!  ZLIB1 Inflate Initialize Error
 //! \b
 //!  Params: zlib1 error code
 ibp_mce_zlib1__inflate_init_error_1
  =IBP_MCE_ZLIB1__INFLATE_INIT_ERROR_1,

 //! \brief
 //!  ZLIB1 Deflate Error
 //! \b
 //!  Params: zlib1 error code, flush code
 ibp_mce_zlib1__deflate_error_2
  =IBP_MCE_ZLIB1__DEFLATE_ERROR_2,

 //! \brief
 //!  ZLIB1 Inflate Error
 //! \b
 //!  Params: zlib1 error code, flush code
 ibp_mce_zlib1__inflate_error_2
  =IBP_MCE_ZLIB1__INFLATE_ERROR_2,

 /////////////////////////////////////////////////////////////////////////
 //Win32 Errors

 /// \brief Can't create WIN32_EVENT.<br>
 /// \b Params: Event Name
 ibp_mce_win32__cant_create_event_1
  =IBP_MCE_WIN32__CANT_CREATE_EVENT_1,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Ошибка получения адреса API функции.<br>
 /// \b
 ///  Params:  dll name, func name
 ibp_mce_win32__fail_get_api_func_address_2
  =IBP_MCE_WIN32__FAIL_GET_API_FUNC_ADDRESS_2,

 //-----------------------------------------------------------------------
 /// \brief Can't resume WIN32_THREAD.<br>
 /// \b Params: Thread Name
 ibp_mce_win32__cant_resume_thread_1
  =IBP_MCE_WIN32__CANT_RESUME_THREAD_1,

 //-----------------------------------------------------------------------
 /// \brief Can't set a WIN32_EVENT.<br>
 /// \b Params: Event Name
 ibp_mce_win32__cant_set_event_1
  =IBP_MCE_WIN32__CANT_SET_EVENT_1,

 //-----------------------------------------------------------------------
 /// \brief Can't reset a WIN32_EVENT.<br>
 /// \b Params: Event Name
 ibp_mce_win32__cant_reset_event_1
  =IBP_MCE_WIN32__CANT_RESET_EVENT_1,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Failed to get current system user name.
 ibp_mce_win32__cant_get_current_system_user_name_0
  =IBP_MCE_WIN32__CANT_GET_CURRENT_SYSTEM_USER_NAME_0,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Failed to get local computer name.
 ibp_mce_win32__cant_get_local_computer_name_0
  =IBP_MCE_WIN32__CANT_GET_LOCAL_COMPUTER_NAME_0,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Failed to get current process name.
 ibp_mce_win32__cant_get_current_process_name_0
  =IBP_MCE_WIN32__CANT_GET_CURRENT_PROCESS_NAME_0,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Failed to load dymanic library.<br>
 /// \b
 ///  Params: DLL name, Win32 Error Text.
 ibp_mce_win32__fail_load_dynamic_library_2
  =IBP_MCE_WIN32__FAIL_LOAD_DYNAMIC_LIBRARY_2,

 //------------------------------------------------------------------------
 /// \brief
 ///  Failed to create crypt context.<br>
 /// \b
 ///  Params: win32 error code
 ibp_mce_win32__crypt__failed_to_create_crypt_context_1
  =IBP_MCE_WIN32__CRYPT__FAILED_TO_CREATE_CRYPT_CONTEXT_1,

 //------------------------------------------------------------------------
 /// \brief
 ///  Failed to generate random bytes.<br>
 /// \b
 ///  Params: win32 error code, count of bytes.
 ibp_mce_win32__crypt__failed_to_generate_random_bytes_2
  =IBP_MCE_WIN32__CRYPT__FAILED_TO_GENERATE_RANDOM_BYTES_2,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Ошибка вызова системной auth-функции.<br>
 /// \b
 ///  Params: func name, sec error code
 ibp_mce_win32__auth__fail_func_call_2
  =IBP_MCE_WIN32__AUTH__FAIL_FUNC_CALL_2,

 //-----------------------------------------------------------------------
 /// \brief
 ///  The call of win32-function failed.<br>
 /// \b
 ///  Params: func name, error code
 ibp_mce_win32__fail_call_function_2
  =IBP_MCE_WIN32__FAIL_CALL_FUNCTION_2,

 //Thread errors ---------------------------------------------------------

 //Reserved

 //Reserved

 /// \brief Unexpected exit of thread.<br>
 /// \b Params: Thread Name
 ibp_mce_thread__unexpected_exit_1
  =IBP_MCE_THREAD__UNEXPECTED_EXIT_1,

 //Reserved

 //Task errors -----------------------------------------------------------

 //Reserved

 //File error ------------------------------------------------------------
 /// \brief Can't open file.<br>
 /// \b Params: File Name
 ibp_mce_file__cant_open_1
  =IBP_MCE_FILE__CANT_OPEN_1,

 /// \brief Can't create file.<br>
 /// \b Params: File Name
 ibp_mce_file__cant_create_1
  =IBP_MCE_FILE__CANT_CREATE_1,

 /// \brief Can't close file.<br>
 /// \b Params: File Name
 ibp_mce_file__cant_close_1
  =IBP_MCE_FILE__CANT_CLOSE_1,

 /// \brief Can't write to file.<br>
 /// \b Params: File Name
 ibp_mce_file__cant_write_1
  =IBP_MCE_FILE__CANT_WRITE_1,

 /// \brief Can't read from file.<br>
 /// \b Params: File Name
 ibp_mce_file__cant_read_1
  =IBP_MCE_FILE__CANT_READ_1,

 /// \brief Too large buffer size for write to file.<br>
 /// \b Params: File Name, Buffer Size.
 ibp_mce_file__too_large_buf_for_write_2
  =IBP_MCE_FILE__TOO_LARGE_BUF_FOR_WRITE_2,

 /// \brief Too large buffer size for read from file.<br>
 /// \b Params: File Name, Buffer Size.
 ibp_mce_file__too_large_buf_for_read_2
  =IBP_MCE_FILE__TOO_LARGE_BUF_FOR_READ_2,

 /// \brief Cant generate name for temporary file.
 ibp_mce_file__cant_generate_name_for_temp_file_0
  =IBP_MCE_FILE__CANT_GENERATE_NAME_FOR_TEMP_FILE_0,

 /// \brief Can't set position in file.<br>
 /// \b Params: File Name, Position.
 ibp_mce_file__cant_set_position_in_file_2
  =IBP_MCE_FILE__CANT_SET_POSITION_IN_FILE_2,

 //ISC Errors ------------------------------------------------------------

 /// \brief
 ///  Уcтановка строкового параметра. Ошибка конвертирования в системную символьную таблицу.<br>
 /// \b
 ///  Params: bufTypeName, paramID, paramName
 ibp_mce_isc__param_buf_builder__failed_to_translate_str_to_sys_charset_3
  =IBP_MCE_ISC__PARAM_BUF_BUILDER__FAILED_TO_TRANSLATE_STR_TO_SYS_CHARSET_3,

 /// \brief
 ///  Уcтановка строкового параметра. Превышение максимальной длины.<br>
 /// \b
 ///  Params: bufTypeName, paramID, paramName, paramLen, max paramLen
 ibp_mce_isc__param_buf_builder__value_is_too_large_5
  =IBP_MCE_ISC__PARAM_BUF_BUILDER__VALUE_IS_TOO_LARGE_5,

 /// \brief
 ///  Ошибка преобразования транспортных данных в число.<br>
 /// \b
 ///  Params: value_sign, value_type_sign, buffer length
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_isc__bad_transport_format_of_integer_value_3
  =IBP_MCE_ISC__BAD_TRANSPORT_FORMAT_OF_INTEGER_VALUE_3,

 /// \brief
 ///  Слишком большое число элементов для XSQLDA структуры.<br>
 /// \b
 ///  Params: expected, max
 /// \note
 ///  Желательно указывать подсистему ошибки.
 ibp_mce_isc__too_many_vars_for_XSQLDA_2
  =IBP_MCE_ISC__TOO_MANY_VARS_FOR_XSQLDA_2,

 /// \brief
 ///  Неизвестный BLR тип данных.<br>
 /// \b
 ///  Params: blr_dtype_id
 ibp_mce_isc__unk_blr_data_type_1
  =IBP_MCE_ISC__UNK_BLR_DATA_TYPE_1,

 /// \brief
 ///  Уcтановка строкового параметра. Ошибка конвертирования в кодовую страницу UTF8.<br>
 /// \b
 ///  Params: bufTypeName, paramID, paramName
 ibp_mce_isc__param_buf_builder__failed_to_translate_str_to_utf8_3
  =IBP_MCE_ISC__PARAM_BUF_BUILDER__FAILED_TO_TRANSLATE_STR_TO_UTF8_3,

 /// \brief
 ///  Ошибка обработки статус вектора.<br>
 /// \b
 ///  Params: check_place, check point.
 ibp_mce_isc__status_vector_processing_error_2
  =IBP_MCE_ISC__STATUS_VECTOR_PROCESSING_ERROR_2,

 /// \brief
 ///  Ошибка обработки статус вектора операции.<br>
 /// \b
 ///  Params: operatorID, check_place, check point.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_isc__op_status_vector_processing_error_3
  =IBP_MCE_ISC__OP_STATUS_VECTOR_PROCESSING_ERROR_3,

 /// \brief
 ///  Ошибка обработки информационных raw-данных XSQLVAR-структуры.<br>
 /// \b
 ///  Params: var index.
 /// \note
 ///  Желательно указывать подсистему ошибки.
 ibp_mce_isc__failed_to_process_xsqlvar_info_raw_data_1
  =IBP_MCE_ISC__FAILED_TO_PROCESS_XSQLVAR_INFO_RAW_DATA_1,

 /// \brief
 ///  Ошибка обработки данных XSQLVAR-структуры.<br>
 /// \b
 ///  Params: var index.
 /// \note
 ///  Желательно указывать подсистему ошибки.
 ibp_mce_isc__failed_to_process_the_xsqlvar_1
  =IBP_MCE_ISC__FAILED_TO_PROCESS_THE_XSQLVAR_1,

 /// \brief
 ///  Ошибка обработки элемента MSG-буфера с данными.<br>
 /// \b
 ///  Params: element index.
 /// \note
 ///  Желательно указывать подсистему ошибки.
 ibp_mce_isc__failed_to_parse_element_of_msg_buf_with_data_1
  =IBP_MCE_ISC__FAILED_TO_PARSE_ELEMENT_OF_MSG_BUF_WITH_DATA_1,

 /// \brief
 ///  Размер буфера с BLR-описанием XSQLDA структуры превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: xsqlda sign, buf size, max buf size.
 /// \note
 ///  Желательно указывать подсистему ошибки.
 ibp_mce_isc__blr_data_for_xsqlda_is_too_long_3
  =IBP_MCE_ISC__BLR_DATA_FOR_XSQLDA_IS_TOO_LONG_3,

 /// \brief
 ///  Ошибка установки значений в XSQLDA.<br>
 /// \b
 ///  Params: xsqlda sign.
 ibp_mce_isc__failed_to_set_xsqlda_xvalues_1
  =IBP_MCE_ISC__FAILED_TO_SET_XVAR_VALUES_1,

 /// \brief
 ///  Ошибка записи ARRAY SLICE.<br>
 /// \b
 ///  Params: server error msg.
 ibp_mce_isc__failed_to_put_array_slice_1
  =IBP_MCE_ISC__FAILED_TO_PUT_ARRAY_SLICE_1,

 /// \brief
 ///  Размер буфера с SDL превышает максимально допустимый размер.<br>
 /// \b
 ///  Params: sdl buffer size, max sdl buffer size
 /// \note
 ///  Желательно указывать подсистему ошибки.
 ibp_mce_isc__too_large_sdl_buffer_size_2
  =IBP_MCE_ISC__TOO_LARGE_SDL_BUFFER_SIZE_2,

 /// \brief
 ///  Размер буфера с данными массива превышает максимально допустимый размер.<br>
 /// \b
 ///  Params: sdl buffer size, max sdl buffer size
 /// \note
 ///  Желательно указывать подсистему ошибки.
 ibp_mce_isc__too_large_array_slice_buffer_size_2
  =IBP_MCE_ISC__TOO_LARGE_ARRAY_SLICE_BUFFER_SIZE_2,

 /// \brief
 ///  Ошибка чтения ARRAY SLICE.<br>
 /// \b
 ///  Params: server error msg.
 ibp_mce_isc__failed_to_get_array_slice_1
  =IBP_MCE_ISC__FAILED_TO_GET_ARRAY_SLICE_1,

 /// \brief
 ///  Ошибка обработки BLR кода.<br>
 /// \b
 ///  Params: internal error message
 ibp_mce_isc__failed_to_process_blr_code_1
  =IBP_MCE_ISC__FAILED_TO_PROCESS_BLR_CODE_1,

 /// \brief
 ///  Чтение-запись VARYING массивов средствами сервера не поддерживается.<br>
 /// \b
 ///  Params: имя сервера, версия сервера, имя клиента, версия клиента.
 /// \note
 ///  Желательно указать подсистему ошибки.
 ibp_mce_isc__read_write_of_varying_array_not_supported_4
  =IBP_MCE_ISC__READ_WRITE_OF_VARYING_ARRAY_NOT_SUPPORTED_4,

 /// \brief
 ///  Идентификатор кодовой страницы нельзя представить в виде BYTE.<br>
 /// \b
 ///  Params: charsetID
 ibp_mce_isc__cs_id_cant_be_stored_in_byte_value_1
  =IBP_MCE_ISC__CS_ID_CANT_BE_STORED_IN_BYTE_VALUE_1,

 //-----------------------------------------------------------------------------
 /// \brief
 ///  [BUG CHECK] Некорректное значение sqld во вторичном блоке с данными XSQLDA структуры.<br>
 /// \b
 ///  Params: place, point, sqld, expected sqld, start index
 ibp_mce_isc__bug_check__incorrect_sqld_in_secondary_block_with_xsqlda_data_5
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SQLD_IN_SECONDARY_BLOCK_WITH_XSQLDA_DATA_5,

 /// \brief
 ///  [BUG CHECK] Неожиданные описания xvars для XSQLDA структуры.<br>
 /// \b
 ///  Params: place, point, sqld
 ibp_mce_isc__bug_check__unexpected_xvars_for_xsqlda_3
  =IBP_MCE_ISC__BUG_CHECK__UNEXPECTED_XVARS_FOR_XSQLDA_3,

 /// \brief
 ///  [BUG CHECK] Порядковый номер описания xvar выходит за пределы допустимого диапазона.<br>
 /// \b
 ///  Params: place, point, number, sqld, xvar index
 ibp_mce_isc__bug_check__out_of_range_of_xvar_sequential_number_5
  =IBP_MCE_ISC__BUG_CHECK__OUT_OF_RANGE_OF_XVAR_SEQUENTIAL_NUMBER_5,

 /// \brief
 ///  [BUG CHECK] Неожиданный порядковый номер xvar в описании XSQLDA структуры.<br>
 /// \b
 ///  Params: place, point, actualSeqNumber, expectedSeqNumber
 ibp_mce_isc__bug_check__unexpected_xvar_sequential_number_4
  =IBP_MCE_ISC__BUG_CHECK__UNEXPECTED_XVAR_SEQUENTIAL_NUMBER_4,

 /// \brief
 ///  [BUG CHECK] Повторное определение значения поля XSQLVAR структуры.<br>
 /// \b
 ///  Params: fieldName
 ibp_mce_isc__bug_check__mult_def_of_xsqlvar_field_value_1
  =IBP_MCE_ISC__BUG_CHECK__MULT_DEF_OF_XSQLVAR_FIELD_VALUE_1,

 /// \brief
 ///  [BUG CHECK] Не определено значение поля XSQLVAR структуры.<br>
 /// \b
 ///  Params: fieldName
 ibp_mce_isc__bug_check__not_def_xsqlvar_field_value_1
  =IBP_MCE_ISC__BUG_CHECK__NOT_DEF_XSQLVAR_FIELD_VALUE_1,

 /// \brief
 ///  [BUG CHECK] XSQLVAR определяет отрицательную длину sql-данных.<br>
 /// \b
 ///  Params: sqllen
 ibp_mce_isc__bug_check__negative_sqllength_in_xsqlvar_1
  =IBP_MCE_ISC__BUG_CHECK__NEGATIVE_SQLLENGTH_IN_XSQLVAR_1,

 /// \brief
 ///  [BUG CHECK] Незавершенное определение XSQLVAR структур.<br>
 /// \b
 ///  Params: actual count, expected count.
 ibp_mce_isc__bug_check__incompleted_definition_of_xvars_2
  =IBP_MCE_ISC__BUG_CHECK__INCOMPLETED_DEFINITION_OF_XVARS_2,

 /// \brief
 ///  [BUG CHECK] Некорректная длина данных XSQLVAR структуры.<br>
 /// \b
 ///  Params: sqltype (можно символьная сигнатура), sqllen
 ibp_mce_isc__bug_check__incorrect_sqllen_in_xvar_2
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SQLLEN_IN_XVAR_2,

 /// \brief
 ///  [BUG CHECK] Некорректный масштаб NUMERIC-данных.<br>
 /// \b
 ///  Params: base type [short, long, int64], scale
 ibp_mce_isc__bug_check__incorrect_sqlscale_in_xvar_2
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SQLSCALE_IN_XVAR_2,

 /// \brief
 ///  [BUG CHECK] XSQLVAR::sqltype содержит неизвестный идентификатор sql-типа.<br>
 /// \b
 ///  Params: sqltype
 ibp_mce_isc__bug_check__unknown_sqltype_in_xvar_1
  =IBP_MCE_ISC__BUG_CHECK__UNKNOWN_SQLTYPE_IN_XVAR_1,

 /// \brief
 ///  [BUG CHECK] XSQLVAR::sqlind содержит нулевой указатель.<br>
 /// \b
 ///  Params: sqltype (можно символьная сигнатура)
 ibp_mce_isc__bug_check__null_ptr_to_sqlind_in_xvar_1
  =IBP_MCE_ISC__BUG_CHECK__NULL_PTR_TO_SQLIND_IN_XVAR_1,

 /// \brief
 ///  [BUG CHECK] Некорректная длина VARCHAR-значения.<br>
 /// \b
 ///  Params: size
 ibp_mce_isc__bug_check__incorrect_varchar_data_length_1
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_VARCHAR_DATA_LENGTH_1,

 /// \brief
 ///  [BUG CHECK] Длина VARCHAR-значения превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: data size, buffer size
 ibp_mce_isc__bug_check__varchar_data_length_is_greater_than_buffer_size_2
  =IBP_MCE_ISC__BUG_CHECK__VARCHAR_DATA_LENGTH_IS_GREATER_THAN_BUFFER_SIZE_2,

 /// \brief
 ///  [BUG CHECK] Рассогласованное количество xvar-элементов.<br>
 /// \b
 ///  Params: actualCount, expectedCount
 /// \note
 ///  Имеет смысл указывать подсистему ошибки.
 ibp_mce_isc__bug_check__other_count_of_xvars_2
  =IBP_MCE_ISC__BUG_CHECK__OTHER_COUNT_OF_XVARS_2,

 /// \brief
 ///  [BUG CHECK] Рассогласованние SQL-типов.<br>
 /// \b
 ///  Params: actualSqlType, expectedSqlType
 ibp_mce_isc__bug_check__other_sqltype_of_xvar_2
  =IBP_MCE_ISC__BUG_CHECK__OTHER_SQLTYPE_OF_XVAR_2,

 /// \brief
 ///  [BUG CHECK] XSQLVAR не поддерживает хранение NULL-значения.<br>
 /// \b
 ///  SQL-type indicator
 ibp_mce_isc__bug_check__xvar_not_supports_the_storing_of_null_state_of_value_1
  =IBP_MCE_ISC__BUG_CHECK__XVAR_NOT_SUPPORTS_THE_STORING_OF_NULL_STATE_OF_VALUE_1,

 /// \brief
 ///  [BUG CHECK] Рассогласование масштабов.<br>
 /// \b
 ///  Params: baseSqlType, actualSqlScale, expectedSqlScale
 ibp_mce_isc__bug_check__other_sqlscale_of_xvar_3
  =IBP_MCE_ISC__BUG_CHECK__OTHER_SQLSCALE_OF_XVAR_3,

 /// \brief
 ///  [BUG CHECK] Рассогласование размера.<br>
 /// \b
 ///  Params: sqlType, actualSqlLen, expectedSqlLen
 ibp_mce_isc__bug_check__other_sqllen_of_xvar_3
  =IBP_MCE_ISC__BUG_CHECK__OTHER_SQLLEN_OF_XVAR_3,

 /// \brief
 ///  [BUG CHECK] Некорректное значение XSQLDA::sqld.<br>
 /// \b
 ///  Params: xsqlda name, sqld
 /// \note
 ///  Имеет смысл указывать подсистему ошибки.
 ibp_mce_isc__bug_check__incorrect_sqld_of_xsqlda_2
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SQLD_OF_XSQLDA_2,

 /// \brief
 ///  [BUG CHECK] Некорректное значение XSQLDA::sqln.<br>
 /// \b
 ///  Params: xsqlda name, sqln, sqld
 /// \note
 ///  Имеет смысл указывать подсистему ошибки.
 ibp_mce_isc__bug_check__incorrect_sqln_of_xsqlda_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SQLN_OF_XSQLDA_3,

 /// \brief
 ///  [BUG CHECK] Некорректная версия XSQLDA.<br>
 /// \b
 ///  Params: place, point, xsqlda_name, version
 ibp_mce_isc__bug_check__incorrect_xsqlda_version_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_XSQLDA_VERSION_4,

 /// \brief
 ///  [BUG CHECK] XVAR определяет некорректную длину sql-данных.<br>
 /// \b
 ///  Params: type sign [char, varchar], sqllen
 ibp_mce_isc__bug_check__bad_sqllen_of_xvar_2
  =IBP_MCE_ISC__BUG_CHECK__BAD_SQLLEN_OF_XVAR_2,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Некорректный SDL. Пустой буфер.<br>
 /// \b
 ///  Params: place, point.
 ibp_mce_isc__bug_check__incorrect_sdl__no_data_2
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__NO_DATA_2,

 /// \brief
 ///  Некорректный SDL. Неизвестная версия.<br>
 /// \b
 ///  Params: place, point, sdlVersion
 ibp_mce_isc__bug_check__incorrect_sdl__unk_version_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__UNK_VERSION_3,

 /// \brief
 ///  Некорректный SDL. Неожиданный конец буфера.<br>
 /// \b
 ///  Params: place, point.
 ibp_mce_isc__bug_check__incorrect_sdl__unexpected_end_of_data_2
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__UNEXPECTED_END_OF_DATA_2,

 /// \brief
 ///  Некорректный SDL. Длина строковых данных превышает количество байт до конца буфера.<br>
 /// \b
 ///  Params: place, point, strLen, bufferTailSize
 ibp_mce_isc__bug_check__incorrect_sdl__str_len_exceeed_the_size_of_buffer_tail_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__STR_LEN_EXCEEED_THE_SIZE_OF_BUFFER_TAIL_4,

 /// \brief
 ///  Некорректный SDL. Многократное определение значения элемента.<br>
 /// \b
 ///  Params: place, point, elementTagID, offset
 ibp_mce_isc__bug_check__incorrect_sdl__mult_def_of_element_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__MULT_DEF_OF_ELEMENT_4,

 /// \brief
 ///  Некорректный SDL. Недопустимое количество полей в структуре.<br>
 /// \b
 ///  Params: place, point, fieldCount
 ibp_mce_isc__bug_check__incorrect_sdl__wrong_number_of_struct_fields_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__WRONG_NUMBER_OF_STRUCT_FIELDS_3,

 /// \brief
 ///  Некорректный SDL. Недопустимый интекс размерности массива.<br>
 /// \b
 ///  Params: place, point, boundIndex, maxBoundNumber
 ibp_mce_isc__bug_check__incorrect_sdl__wrong_bound_index_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__WRONG_BOUND_INDEX_4,

 /// \brief
 ///  Некорректный SDL. Многократное определение размерности.<br>
 /// \b
 ///  Params: place, point, boundIndex
 ibp_mce_isc__bug_check__incorrect_sdl__mult_def_of_bound_range_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__MULT_DEF_OF_BOUND_RANGE_3,

 /// \brief
 ///  Некорректный SDL. Некорректные границы размерности.<br>
 /// \b
 ///  Params: place, point, boundIndex, lower, upper
 ibp_mce_isc__bug_check__incorrect_sdl__bad_bound_range_5
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__BAD_BOUND_RANGE_5,

 /// \brief
 ///  Некорректный SDL. Неизвестный идентификатор литеры.<br>
 /// \b
 ///  Params: place, point, literalKind, offset
 ibp_mce_isc__bug_check__incorrect_sdl__unknown_kind_of_literal_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__UNKNOWN_KIND_OF_LITERAL_4,

 /// \brief
 ///  Некорректный SDL. Недопустимое количество полей в элементе.<br>
 /// \b
 ///  Params: place, point, fieldCount
 ibp_mce_isc__bug_check__incorrect_sdl__wrong_number_of_element_fields_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__WRONG_NUMBER_OF_ELEMENT_FIELDS_3,

 /// \brief
 ///  Некорректный SDL. Неожиданный тэг.<br>
 /// \b
 ///  Params: place, point, literalKind, offset
 ibp_mce_isc__bug_check__incorrect_sdl__unexpected_tag_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__UNEXPECTED_TAG_4,

 /// \brief
 ///  Некорректный SDL. Некорректное значение свойства 'index' тэга 'scalar'.<br>
 /// \b
 ///  Params: place, point, index, offset
 ibp_mce_isc__bug_check__incorrect_sdl__incorrect_index_of_scalar_tag_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__INCORRECT_INDEX_OF_SCALAR_TAG_4,

 /// \brief
 ///  Некорректный SDL. Несогласованные размеры буфера и данных. Должны быть идентичны.<br>
 /// \b
 ///  Params: place, point, bufferSize, dataSize
 ibp_mce_isc__bug_check__incorrect_sdl__inconsistent_sizes_of_buffer_and_data_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__INCONSISTENT_SIZES_OF_BUFFER_AND_DATA_4,

 /// \brief
 ///  Некорректный SDL. Отсутствуют данные для тега.<br>
 /// \b
 ///  Params: place, point, tag sign
 ibp_mce_isc__bug_check__incorrect_sdl__no_data_of_tag_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__NO_DATA_OF_TAG_3,

 /// \brief
 ///  Некорректный SDL. Отсутствуют определения размерностей.<br>
 /// \b
 ///  Params: place, point
 ibp_mce_isc__bug_check__incorrect_sdl__no_data_of_dimensions_2
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__NO_DATA_OF_DIMENSIONS_2,

 /// \brief
 ///  Некорректный SDL. Отсутствуют определение размерности.<br>
 /// \b
 ///  Params: place, point, bound index
 ibp_mce_isc__bug_check__incorrect_sdl__no_data_of_dimension_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__NO_DATA_OF_DIMENSION_3,

 /// \brief
 ///  Некорректный SDL. Неизвестный идентификатор BLR типа.<br>
 /// \b
 ///  Params: place, point, blrTypeId, offset
 ibp_mce_isc__bug_check__incorrect_sdl__unk_blr_data_type_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__UNK_BLR_DATA_TYPE_4,

 /// \brief
 ///  Некорректный SDL. Недопустимый размер элемента массива.<br>
 /// \b
 ///  Params: place, point, length, blrTypeSign
 ibp_mce_isc__bug_check__incorrect_sdl__invalid_element_length_4
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__INVALID_ELEMENT_LENGTH_4,

 /// \brief
 ///  Некорректный SDL. Ошибка конвертирование строки в UNICODE.<br>
 /// \b
 ///  Params: place, point, cs_name
 ibp_mce_isc__bug_check__incorrect_sdl__failed_to_translate_str_to_unicode_3
  =IBP_MCE_ISC__BUG_CHECK__INCORRECT_SDL__FAILED_TO_TRANSLATE_STR_TO_UNICODE_3,

 //-----------------------------------------------------------------------
 /// \brief
 ///  Нулевой размер элемента массива.<br>
 /// \b
 ///  Params: place, point, blrTypeId
 ibp_mce_isc__bug_check__zero_array_element_size_3
  =IBP_MCE_ISC__BUG_CHECK__ZERO_ARRAY_ELEMENT_SIZE_3,

 /// \brief
 ///  Несогласованные размеры буфера и элемента массива.<br>
 /// \b
 ///  Params: place, point, slice size, element size,  blrTypeId
 ibp_mce_isc__bug_check__inconsistent_sizes_of_slice_and_element_5
  =IBP_MCE_ISC__BUG_CHECK__INCONSISTENT_SIZES_OF_SLICE_AND_ELEMENT_5,

 /// \brief
 ///  Несогласованные размеры буфера и элемента массива.<br>
 /// \b
 ///  Params: place, point, blrTypeId
 ibp_mce_isc__bug_check__unknown_blr_data_type_3
  =IBP_MCE_ISC__BUG_CHECK__UNKNOWN_BLR_DATA_TYPE_3,

 /// \brief
 ///  Неправильный размер буфера под данные массива.<br>
 /// \b
 ///  Params: place, point, relation name, field name, size, expected size
 ibp_mce_isc__bug_check__invalid_array_buffer_size_6
  =IBP_MCE_ISC__BUG_CHECK__INVALID_ARRAY_BUFFER_SIZE_6,

 /// \brief
 ///  Неизвестный серверный идентификатор типа запроса.<br>
 /// \b
 ///  Params: place, point, stmtTypeID, dbmsSign
 ibp_mce_isc__bug_check__unknown_stmt_type_id_4
  =IBP_MCE_ISC__BUG_CHECK__UNKNOWN_STMT_TYPE_ID_4,

 /// \brief
 ///  Неизвестное значение индикатора XSQVAR.<br>
 /// \b
 ///  Params: place, point, indicatorValue
 ibp_mce_isc__bug_check__unknown_value_of_xsqlvar_indicator_3
  =IBP_MCE_ISC__BUG_CHECK__UNKNOWN_VALUE_OF_XSQLVAR_INDICATOR_3,

 //-----------------------------------------------------------------------

 /// \brief
 ///  IA DESC ERR. Ошибка загрузки сведений о размерности.<br>
 /// \b
 ///  Params: dim index
 ibp_mce_isc__ia_desc_err__failed_to_load_dim_info__1
  =IBP_MCE_ISC__IA_DESC_ERR__FAILED_TO_LOAD_DIM_INFO__1,

 /// \brief
 ///  IA DESC ERR. Ошибка загрузки и декодирования значения поля.<br>
 /// \b
 ///  Params: field sign
 ibp_mce_isc__ia_desc_err__failed_to_load_field_value__1
  =IBP_MCE_ISC__IA_DESC_ERR__FAILED_TO_LOAD_FIELD_VALUE__1,

 /// \brief
 ///  Некорректный IA DESC. Неизвестная версия структуры дескриптора.<br>
 /// \b
 ///  Params: place, point, actual version, expected version
 ibp_mce_isc__ia_desc_err__bug_check__unexpected_format_version__4
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__UNEXPECTED_FORMAT_VERSION__4,

 /// \brief
 ///  Некорректный IA DESC. Некорректное число размерностей.<br>
 /// \b
 ///  Params: place, point, dimensions number
 ibp_mce_isc__ia_desc_err__bug_check__incorrect_dimensions_number__3
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__INCORRECT_DIMENSIONS_NUMBER__3,

 /// \brief
 ///  Некорректный IA DESC. Некорректное количество описаний типов.<br>
 /// \b
 ///  Params: place, point, struct count
 ibp_mce_isc__ia_desc_err__bug_check__struct_count__3
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__STRUCT_COUNT__3,

 /// \brief
 ///  Некорректный IA DESC. Incorrect length of descriptor.<br>
 /// \b
 ///  Params: place, point, length
 ibp_mce_isc__ia_desc_err__bug_check__incorrect_length_of_descriptor__3
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__INCORRECT_LENGTH_OF_DESCRIPTOR__3,

 /// \brief
 ///  Некорректный IA DESC. Несогласованное количество размерностей и длина дескриптора.<br>
 /// \b
 ///  Params: place, point, dimensions number, desc length
 ibp_mce_isc__ia_desc_err__bug_check__inconsistent_dims_and_desc_length__4
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__INCONSISTENT_DIMS_AND_DESC_LENGTH__4,

 /// \brief
 ///  Некорректный IA DESC. Несогласованные размеры элемента.<br>
 /// \b
 ///  Params: place, point, element length1, element length2
 ibp_mce_isc__ia_desc_err__bug_check__inconsistent_element_lengths__4
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__INCONSISTENT_ELEMENT_LENGTHS__4,

 /// \brief
 ///  Некорректный IA DESC. Некорректный размер вложенных размерностей.<br>
 /// \b
 ///  Params: place, point, dimension index, actualLength, expectedLength
 ibp_mce_isc__ia_desc_err__bug_check__wrong_subdimensions_size__5
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__WRONG_SUBDIMENSIONS_SIZE__5,

 /// \brief
 ///  Некорректный IA DESC. Некорректные границы размерности.<br>
 /// \b
 ///  Params: place, point, dimension index, lower, upper
 ibp_mce_isc__ia_desc_err__bug_check__incorrect_range_of_dimension__5
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__INCORRECT_RANGE_OF_DIMENSION__5,

 /// \brief
 ///  Некорректный IA DESC. Дескриптор описывает слишком большое число элементов.<br>
 /// \b
 /// Params: place, point
 ibp_mce_isc__ia_desc_err__bug_check__too_big_elements_number__2
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__TOO_BIG_ELEMENTS_NUMBER__2,

 /// \brief
 ///  Некорректный IA DESC. Указано некорректное общее количество элементов.<br>
 /// \b
 ///  Params: place, point, actualCount, expectedCount
 ibp_mce_isc__ia_desc_err__bug_check__wrong_total_count_of_elements__4
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__WRONG_TOTAL_COUNT_OF_ELEMENTS__4,

 /// \brief
 ///  Некорректный IA DESC. Некорректный общий размер элементов массива.<br>
 /// \b
 ///  Params: place, point, total count, total length, element length
 ibp_mce_isc__ia_desc_err__bug_check__wrong_total_length__5
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__WRONG_TOTAL_LENGTH__5,

 /// \brief
 ///  Некорректный IA DESC. Неожиданное значение поля.<br>
 /// \b
 ///  Params: place, point, fieldSign, fieldValue, expectedValue
 ibp_mce_isc__ia_desc_err__bug_check__unexpected_field_value__5
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__UNEXPECTED_FIELD_VALUE__5,

 /// \brief
 ///  Некорректный IA DESC. Неожиданное значение поля.<br>
 /// \b
 ///  Params: place, point, fieldSign, fieldValue
 ibp_mce_isc__ia_desc_err__bug_check__unexpected_field_value__4
  =IBP_MCE_ISC__IA_DESC_ERR__BUG_CHECK__UNEXPECTED_FIELD_VALUE__4,

 //INET (WinSock) errors -------------------------------------------------

 //Reserved

 /// \brief
 ///  Ошибка определения сетевого адреса хоста.<br>
 /// \b
 ///  Params: hostName
 ibp_mce_winsock__cant_detect_addr_of_host_1
  =IBP_MCE_WINSOCK__CANT_DETECT_ADDR_OF_HOST_1,

 /// \brief
 ///  Неподдерживаемый тип сетевого адреса хоста.<br>
 /// \b
 ///  Params: hostName, detectedAddrType
 ibp_mce_winsock__unk_addr_type_of_host_2
  =IBP_MCE_WINSOCK__UNK_ADDR_TYPE_OF_HOST_2,

 /// \brief
 ///  Ошибка подключения к серверу.<br>
 /// \b
 ///  Params: hostName, port number, last winsock error code
 ibp_mce_winsock__failed_to_connect_to_srv_3
  =IBP_MCE_WINSOCK__FAILED_TO_CONNECT_TO_SRV_3,

 /// \brief
 ///  Ошибка инициализации сокета.<br>
 /// \b
 ///  Params: winsock error code, socket_family, socket_type, socket_protocol
 ibp_mce_winsock__failed_to_init_the_socket_4
  =IBP_MCE_WINSOCK__FAILED_TO_INIT_THE_SOCKET_4,

 //Reserved

 //Reserved

 /// \brief
 ///  Ошибка закрытия сокета.<br>
 /// \b
 ///  Params: winsock error code
 ibp_mce_winsock__failed_to_close_the_socket_1
  =IBP_MCE_WINSOCK__FAILED_TO_CLOSE_THE_SOCKET_1,

 //Reserved

 //Reserved

 /// \brief
 ///  Ошибка записи в порт.<br>
 /// \b
 ///  Params: winsock error code
 ibp_mce_winsock__failed_to_write_to_port_1
  =IBP_MCE_WINSOCK__FAILED_TO_WRITE_TO_PORT_1,

 /// \brief
 ///  Ошибка чтения из порта.<br>
 /// \b
 ///  Params: winsock error code
 ibp_mce_winsock__failed_to_read_from_port_1
  =IBP_MCE_WINSOCK__FAILED_TO_READ_FROM_PORT_1,

 /// \brief
 ///  Ошибка инициализации WinSock.<br>
 /// \b
 ///  Params: winsock error code.
 ibp_mce_winsock__failed_to_initialize_1
  =IBP_MCE_WINSOCK__FAILED_TO_INITIALIZE_1,

 /// \brief
 ///  Ошибка определения адреса хоста. Сбой вызова функции getaddrinfo.<br>
 /// \b
 ///  Params: winsock error code, host name, port name.
 ibp_mce_winsock__getaddrinfo_failed_3
  =IBP_MCE_WINSOCK__GETADDRINFO_FAILED_3,

 /// \brief
 ///  Ошибка подключения к серверу.<br>
 /// \b
 ///  Params: winsock error code, host name, port name, address, socket_family, socket_type, socket_protocol.
 ibp_mce_winsock__failed_to_connect_to_srv_7
  =IBP_MCE_WINSOCK__FAILED_TO_CONNECT_TO_SRV_7,

 //Reserved

 /// \brief
 ///  [BUG CHECK] Неожиданный код завершения операции send.<br>
 /// \b
 ///  Params: result code, winsock error code
 ibp_mce_winsock__bug_check__unexpected_result_code_from_send_operation_2
  =IBP_MCE_WINSOCK__BUG_CHECK__UNEXPECTED_RESULT_CODE_FROM_SEND_OPERATION_2,

 /// \brief
 ///  [BUG CHECK] Обнаружено зацикливание операции send.<br>
 ibp_mce_winsock__bug_check__detected_loop_of_send_0
  =IBP_MCE_WINSOCK__BUG_CHECK__DETECTED_LOOP_OF_SEND_0,

 /// \brief
 ///  [BUG CHECK] Операция send записала больше чем ожидалось.<br>
 /// \b
 ///  Params: actual count, expected count
 ibp_mce_winsock__bug_check__send_write_more_than_expected_2
  =IBP_MCE_WINSOCK__BUG_CHECK__SEND_WRITE_MORE_THAN_EXPECTED_2,

 /// \brief
 ///  [BUG CHECK] Чтение из закрытого порта подключения.<br>
 /// \b
 ///  Params: winsock error code
 ibp_mce_winsock__bug_check__read_from_closed_port_1
  =IBP_MCE_WINSOCK__BUG_CHECK__READ_FROM_CLOSED_PORT_1,

 /// \brief
 ///  [BUG CHECK] Неожиданный код завершения операции recv.<br>
 /// \b
 ///  Params: result code, winsock error code
 ibp_mce_winsock__bug_check__unexpected_result_code_from_recv_operation_2
  =IBP_MCE_WINSOCK__BUG_CHECK__UNEXPECTED_RESULT_CODE_FROM_RECV_OPERATION_2,

 /// \brief
 ///  [BUG CHECK] Операция recv прочитала больше чем ожидалось.<br>
 /// \b
 ///  Params: actual count, expected count
 ibp_mce_winsock__bug_check__recv_read_more_than_expected_2
  =IBP_MCE_WINSOCK__BUG_CHECK__RECV_READ_MORE_THAN_EXPECTED_2,

 //Remote SubSystem Errors -----------------------------------------------

 /// \brief
 ///  Не удалось определить тип подключения к серверу базы данных.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__cant_detect_type_of_cn_0
  =IBP_MCE_REMOTE__CANT_DETECT_TYPE_OF_CN_0,

 /// \brief
 ///  Не удалось определить тип подключения к серверу базы данных.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__connect_was_rejected_0
  =IBP_MCE_REMOTE__CONNECT_WAS_REJECTED_0,

 /// \brief
 ///  Некорректный формат идентификатора хоста.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__bad_inet_cn_to_db_str_format_0
  =IBP_MCE_REMOTE__BAD_INET_CN_TO_DB_STR_FORMAT_0,

 /// \brief
 ///  Некорректный формат идентификатора хоста. Не определен порт подключения.<br>
 /// \b
 ///  Params: host sign
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__bad_inet_cn_to_db_str_format__port_not_defined_1
  =IBP_MCE_REMOTE__BAD_INET_CN_TO_DB_STR_FORMAT__PORT_NOT_DEFINED_1,

 /// \brief
 ///  Некорректное использование сервиса аутентификации.<br>
 /// \b
 ///  Rarams: auth service name
 ibp_mce_remote__incorrect_usage_of_auth_service_1
  =IBP_MCE_REMOTE__INCORRECT_USAGE_OF_AUTH_SERVICE_1,

 /// \brief
 ///  Неудалось определить сервис аутентификации.
 ibp_mce_remote__cant_detect_auth_service_0
  =IBP_MCE_REMOTE__CANT_DETECT_AUTH_SERVICE_0,

 /// \brief
 ///  Неизвестное имя сервиса аутентификации.<br>
 /// \b
 ///  Params: auth plugin name.
 ibp_mce_remote__unk_auth_service_name_1
  =IBP_MCE_REMOTE__UNK_AUTH_SERVICE_NAME_1,

 /// \brief
 ///  Некорректное имя плагина аутентификации.<br>
 /// \b
 ///  Params: auth plugin name.
 ibp_mce_remote__incorrect_auth_service_name_1
  =IBP_MCE_REMOTE__INCORRECT_AUTH_SERVICE_NAME_1,

 /// \brief
 ///  Многократное определение серверного ключа.<br>
 /// \b
 ///  Params: keyType, keyPlugin.
 ibp_mce_remote__multiple_definition_of_known_server_key_2
  =IBP_MCE_REMOTE__MULTIPLE_DEFINITION_OF_KNOWN_SERVER_KEY_2,

 /// \brief
 ///  Процесс аутентификации уже был завершен.
 ibp_mce_remote__auth_seq_already_completed_0
  =IBP_MCE_REMOTE__AUTH_SEQ_ALREADY_COMPLETED_0,

 /// \brief
 ///  Загрузка пакета. Получены некорректные данные.<br>
 /// \b
 ///  Params: data sign, data type, data value
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__receive_pack__xdr__bad_data_3
  =IBP_MCE_REMOTE__RECEIVE_PACK__XDR__BAD_DATA_3,

 /// \brief
 ///  Загрузка пакета. Длина полученной строки превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: data sign, actual length, max length
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__receive_pack__xdr__str_too_long_3
  =IBP_MCE_REMOTE__RECEIVE_PACK__XDR__STR_TOO_LONG_3,

 /// \brief
 ///  Загрузка пакета. Получен пакет с неизвестным идентификатором операции.<br>
 /// \b
 ///  Params: operation id
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__receive_pack__unk_op_id_1
  =IBP_MCE_REMOTE__RECEIVE_PACK__UNK_OP_ID_1,

 /// \brief
 ///  Загрузка пакета. Длина статус вектора превышает максимально допустимую.<br>
 /// \b
 ///  Params: data sign, max length, check point
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__receive_pack__status_vector_is_too_long_3
  =IBP_MCE_REMOTE__RECEIVE_PACK__STATUS_VECTOR_IS_TOO_LONG_3,

 /// \brief
 ///  Загрузка пакета. Неизвестный аргумент в статус векторе.<br>
 /// \b
 ///  Params: data sign, argID
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__receive_pack__unexpected_arg_in_status_vector_2
  =IBP_MCE_REMOTE__RECEIVE_PACK__UNEXPECTED_ARG_IN_STATUS_VECTOR_2,

 /// \brief
 ///  Запись в порт невозможна. Предыдущая операция записи завершилась с ошибками.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__cant_write_to_port__prev_write_op_was_failed_0
  =IBP_MCE_REMOTE__CANT_WRITE_TO_PORT__PREV_WRITE_OP_WAS_FAILED_0,

 /// \brief
 ///  Чтение из порта невозможно. Предыдущая операция чтения завершилась с ошибками.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__cant_read_from_port__prev_read_op_was_failed_0
  =IBP_MCE_REMOTE__CANT_READ_FROM_PORT__PREV_READ_OP_WAS_FAILED_0,

 /// \brief
 ///  Отправка пакета. Ошибка обработки данных MSG-буфера.<br>
 /// \b
 ///  Params: element index
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__encode_packet__xdr__error_in_element_of_msg_data_buffer_1
  =IBP_MCE_REMOTE__ENCODE_PACKET__XDR__ERROR_IN_ELEMENT_OF_MSG_DATA_BUFFER_1,

 /// \brief
 ///  Загрузка пакета. Ошибка загрузки данных MSG-буфера.<br>
 /// \b
 ///  Params: element index
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__decode_packet__xdr__error_in_element_of_msg_data_buffer_1
  =IBP_MCE_REMOTE__DECODE_PACKET__XDR__ERROR_IN_ELEMENT_OF_MSG_DATA_BUFFER_1,

 /// \brief
 ///  Загрузка пакета. Ошибка загрузки данных SLICE-буфера.<br>
 /// \b
 ///  Params: element index
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__decode_packet__xdr__error_in_element_of_slice_data_buffer_1
  =IBP_MCE_REMOTE__DECODE_PACKET__XDR__ERROR_IN_ELEMENT_OF_SLICE_DATA_BUFFER_1,

 /// \brief
 ///  Запись в порт не возможна. Порт переведен в заблокированное состояние.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__cant_write_to_port__port_has_failed_state_0
  =IBP_MCE_REMOTE__CANT_WRITE_TO_PORT__PORT_HAS_FAILED_STATE_0,

 /// \brief
 ///  Чтение из порта не возможно. Порт переведен в заблокированное состояние.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__cant_read_from_port__port_has_failed_state_0
  =IBP_MCE_REMOTE__CANT_READ_FROM_PORT__PORT_HAS_FAILED_STATE_0,

 /// \brief
 ///  Неподдерживаемая архитектура протокола подключения.<br>
 /// \b
 ///  Params: name of protocol architecture
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__unsupported_protocol_architecture_1
  =IBP_MCE_REMOTE__UNSUPPORTED_PROTOCOL_ARCHITECTURE_1,

 /// \brief
 ///  Неподдерживаемый тип протокола подключения.<br>
 /// \b
 ///  Params: name of protocol type, версия протокола установленного соединения.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__unsupported_protocol_type_2
  =IBP_MCE_REMOTE__UNSUPPORTED_PROTOCOL_TYPE_2,

 /// \brief
 ///  Запрашиваемый тип протокола не поддерживается.<br>
 /// \b
 ///  Params: name of protocol type, версия протокола установленного соединения.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__requested_protocol_type_not_supported_2
  =IBP_MCE_REMOTE__REQUESTED_PROTOCOL_TYPE_NOT_SUPPORTED_2,

 /// \brief
 ///  Запрашиваемый протокол соединения не поддерживается.<br>
 /// \b
 ///  Params: identifier of protocol
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__requested_protocol_not_supported_1
  =IBP_MCE_REMOTE__REQUESTED_PROTOCOL_NOT_SUPPORTED_1,

 /// \brief
 ///  Шифрование соединения не возможно. Сервер не предоставил ключи для шифрования соединения.<br>
 /// \b
 ///  Params: name of auth service
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__wire_crypt_not_possible__no_known_server_keys_1
  =IBP_MCE_REMOTE__WIRE_CRYPT_NOT_POSSIBLE__NO_KNOWN_SERVER_KEYS_1,

 /// \brief
 ///  Шифрование соединения не возможно. Сервис аутентификации не предоставил ключи для шифрования соединения.<br>
 /// \b
 ///  Params: name of auth service
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__wire_crypt_not_possible__no_crypt_keys_1
  =IBP_MCE_REMOTE__WIRE_CRYPT_NOT_POSSIBLE__NO_CRYPT_KEYS_1,

 /// \brief
 ///  Шифрование соединения не возможно. Провайдер не поддерживает предложенные типы шифрования.<br>
 /// \b
 ///  Params: name of auth service
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__wire_crypt_not_possible__no_support_for_known_server_keys_1
  =IBP_MCE_REMOTE__WIRE_CRYPT_NOT_POSSIBLE__NO_SUPPORT_FOR_KNOWN_SERVER_KEYS_1,

 /// \brief
 ///  Длина имени сервиса шифрования превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: name length, max length.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__wire_crypt_svc_name_is_too_long_2
  =IBP_MCE_REMOTE__WIRE_CRYPT_SVC_NAME_IS_TOO_LONG_2,

 /// \brief
 ///  Длина названия типа ключа шифрования подключения превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: name length, max length.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__wire_crypt_key_type_name_is_too_long_2
  =IBP_MCE_REMOTE__WIRE_CRYPT_KEY_TYPE_NAME_IS_TOO_LONG_2,

 /// \brief
 ///  Не удалось начать шифрование подключения.<br>
 /// \b
 ///  Params: crypt key type name, wire crypt service name.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__failed_to_start_wire_crypt_2
  =IBP_MCE_REMOTE__FAILED_TO_START_WIRE_CRYPT_2,

 /// \brief
 ///  Неподдерживаемый сервис аутентификации.<br>
 /// \b
 ///  Params: auth service name.
 ibp_mce_remote__auth_service_not_supported_1
  =IBP_MCE_REMOTE__AUTH_SERVICE_NOT_SUPPORTED_1,

 /// \brief
 ///  Несовместимые сервисы аутентификации в "remote:auth" и "Integrated Security".<br>
 /// \b
 ///  Params: auth service name, "Integrated Security" value.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__incompatible_auth_services_2
  =IBP_MCE_REMOTE__INCOMPATIBLE_AUTH_SERVICES_2,

 /// \brief
 ///  Размер данных, полученных от сервиса аутентификации, превышает макимально допустимое значение.<br>
 /// \b
 ///  Params: auth service name, data length, max length
 ibp_mce_remote__auth_data_too_long_3
  =IBP_MCE_REMOTE__AUTH_DATA_TOO_LONG_3,

 /// \brief
 ///  Длина имени сервиса аутентификации превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: name length, max length
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__auth_svc_name_too_long_2
  =IBP_MCE_REMOTE__AUTH_SVC_NAME_TOO_LONG_2,

 /// \brief
 ///  Длина списка имен сервисов аутентификации превышает максимально допустимое значение.<br>
 /// \b
 ///  Params: names length, max length
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__auth_svc_names_too_long_2
  =IBP_MCE_REMOTE__AUTH_SVC_NAMES_TOO_LONG_2,

 /// \brief
 ///  Шифрование подключения не поддерживается.<br>
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__wire_crypt_not_supported_0
  =IBP_MCE_REMOTE__WIRE_CRYPT_NOT_SUPPORTED_0,

 /// \brief
 ///  Неподдерживаемые флаги протокола подключения.<br>
 /// \b
 ///  Params: protocol flags, версия протокола установленного соединения.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__unsupported_protocol_flags_2
  =IBP_MCE_REMOTE__UNSUPPORTED_PROTOCOL_FLAGS_2,

 /// \brief
 ///  Сервер отклонил компрессию подключения.<br>
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__server_rejected_cn_compression_0
  =IBP_MCE_REMOTE__SERVER_REJECTED_CN_COMPRESSION_0,

 /// \brief
 ///  Сервер требует компрессию подключения.<br>
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__server_required_cn_compression_0
  =IBP_MCE_REMOTE__SERVER_REQUIRED_CN_COMPRESSION_0,

 /// \brief
 ///  Неподдерживаемый тип сжатия данных подключения.<br>
 /// \b
 ///  Params: type name.
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__unsupported_wire_compression_type_1
  =IBP_MCE_REMOTE__UNSUPPORTED_WIRE_COMPRESSION_TYPE_1,

 /// \brief
 ///  Сжатие данных подключения не поддерживается.<br>
 /// \note
 ///  Нужно указывать подсистему ошибки.
 ibp_mce_remote__wire_compression_not_supported_0
  =IBP_MCE_REMOTE__WIRE_COMPRESSION_NOT_SUPPORTED_0,

 //-----------------------------------------------------------------------

 /// \brief
 ///  [BUG CHECK] Неожиданный ответ сервера.<br>
 /// \b
 ///  Params: check place, check point, answerID (operationID)
 ibp_mce_remote__bug_check__unexpected_answer_from_server_3
  =IBP_MCE_REMOTE__BUG_CHECK__UNEXPECTED_ANSWER_FROM_SERVER_3,

 /// \brief
 ///  [BUG CHECK] Принята неожиданная версия протокола взаимодействия.<br>
 /// \b
 ///  Params: check place, check point, protocol version id
 ibp_mce_remote__bug_check__accepted_unexpected_protocol_version_3
  =IBP_MCE_REMOTE__BUG_CHECK__ACCEPTED_UNEXPECTED_PROTOCOL_VERSION_3,

 /// \brief
 ///  [BUG CHECK] Принята неожиданная архитектура протокола взаимодействия.<br>
 /// \b
 ///  Params: check place, check point, architectureID
 ibp_mce_remote__bug_check__accepted_unexpected_protocol_arhitecture_3
  =IBP_MCE_REMOTE__BUG_CHECK__ACCEPTED_UNEXPECTED_PROTOCOL_ARHITECTURE_3,

 /// \brief
 ///  [BUG CHECK] Неожиданная версия структуры пакета.<br>
 /// \b
 ///  Params: check place, check point, actualProtocolSetID, expectedProtocolSetID
 ibp_mce_remote__bug_check__unexpected_packet_structure_4
  =IBP_MCE_REMOTE__BUG_CHECK__UNEXPECTED_PACKET_STRUCTURE_4,

 /// \brief
 ///  [BUG CHECK] Ошибка транслирования имени сервиса аутентификации между кодовыми страницами.<br>
 /// \b
 ///  Params: check place, check point, from_cs, to_cs
 ibp_mce_remote__bug_check__cant_translate_auth_service_name_4
  =IBP_MCE_REMOTE__BUG_CHECK__CANT_TRANSLATE_AUTH_SERVICE_NAME_4,

 /// \brief
 ///  [BUG CHECK] Ошибка транслирования списка имен сервисов аутентификации между кодовыми страницами.<br>
 /// \b
 ///  Params: check place, check point, from_cs, to_cs
 ibp_mce_remote__bug_check__cant_translate_auth_service_names_4
  =IBP_MCE_REMOTE__BUG_CHECK__CANT_TRANSLATE_AUTH_SERVICE_NAMES_4,

 /// \brief
 ///  [BUG CHECK] Повторная установка сервиса аутентификации. Возможно зацикливание.<br>
 /// \b
 ///  Params: check place, check point, auth service name
 ibp_mce_remote__bug_check__auth_service_already_was_used_3
  =IBP_MCE_REMOTE__BUG_CHECK__AUTH_SERVICE_ALREADY_WAS_USED_3,

 /// \brief
 ///  [BUG CHECK] Повторная регистрация фабрики сервиса аутентификации.<br>
 /// \b
 ///  Params: check place, check point, auth service name
 ibp_mce_remote__bug_check__auth_service_factory_already_was_registered_3
  =IBP_MCE_REMOTE__BUG_CHECK__AUTH_SERVICE_FACTORY_ALREADY_WAS_REGISTERED_3,

 /// \brief
 ///  [BUG CHECK] Ошибка транслирования имени сервиса шифрования соединения между кодовыми страницами.<br>
 /// \b
 ///  Params: check place, check point, from_cs, to_cs
 ibp_mce_remote__bug_check__cant_translate_wire_crypt_service_name_4
  =IBP_MCE_REMOTE__BUG_CHECK__CANT_TRANSLATE_WIRE_CRYPT_SERVICE_NAME_4,

 /// \brief
 ///  [BUG CHECK] Ошибка транслирования списка имен сервисов шифрования соединения между кодовыми страницами.<br>
 /// \b
 ///  Params: check place, check point, from_cs, to_cs
 ibp_mce_remote__bug_check__cant_translate_wire_crypt_service_names_4
  =IBP_MCE_REMOTE__BUG_CHECK__CANT_TRANSLATE_WIRE_CRYPT_SERVICE_NAMES_4,

 /// \brief
 ///  [BUG CHECK] Ошибка транслирования имени типа ключа шифрования соединения между кодовыми страницами.<br>
 /// \b
 ///  Params: check place, check point, from_cs, to_cs
 ibp_mce_remote__bug_check__cant_translate_wire_crypt_key_type_name_4
  =IBP_MCE_REMOTE__BUG_CHECK__CANT_TRANSLATE_WIRE_CRYPT_KEY_TYPE_NAME_4,

 /// \brief
 ///  [BUG CHECK] Внезапная попытка замены сервиса аутентификации.<br>
 /// \b
 ///  Params: check place, check point, new auth svc name, old auth svc name
 ibp_mce_remote__bug_check__unexpected_attempt_to_change_auth_service_4
  =IBP_MCE_REMOTE__BUG_CHECK__UNEXPECTED_ATTEMPT_TO_CHANGE_AUTH_SERVICE_4,

 //LCPI LIB MESSAGES -----------------------------------------------------

 //! \brief
 //!  String with parameters contains duplicate item with name.<br>
 //! \b
 //!  Params: name
 lcpi_lib_structure__err_mc__parameter_list___duplicate_param__1
  =LCPI_LIB_STRUCTURE__ERR_MC__PARAMETER_LIST___DUPLICATE_PARAM__1,

 //------------------------------------------------------------------------
 //! \brief
 //!  Bad format of quoted item name of parameter list string.
 lcpi_lib_structure__err_mc__parameter_list___bad_fmt_of_quoted_item_name__0
  =LCPI_LIB_STRUCTURE__ERR_MC__PARAMETER_LIST___BAD_FMT_OF_QUOTED_ITEM_NAME__0,

 //-----------------------------------------------------------------------
 //! \brief
 //!  Bad format of quoted item value of parameter list string.
 lcpi_lib_structure__err_mc__parameter_list___bad_fmt_of_quoted_item_value__0
  =LCPI_LIB_STRUCTURE__ERR_MC__PARAMETER_LIST___BAD_FMT_OF_QUOTED_ITEM_VALUE__0,

 //Standard error --------------------------------------------------------
 /// \brief Идентификатор стандартной ошибки, описание которой можно получить по HRESULT.
 ibp_mce_standart_error
  =IDENTIFIER_SDK_ERROR
};//ibp_msg_code_type

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
