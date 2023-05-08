////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_sqlstate_codes
//! \file    ibp_sqlstate_codes.h
//! \brief   ќпределение SQLSTATE_CODES
//! \author  Kovalenko Dmitry
//! \date    07.04.2010
#ifndef _db_sqlstate_codes_H_
#define _db_sqlstate_codes_H_

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////

#define IBP_SQLSTATE__00000__SUCCESSFUL_COMPLETION_NO_SUBCLASS \
 "00000"

//------------------------------------------------------------------------

//MSDN: General warning

#define IBP_SQLSTATE__01000__WARNING_NO_SUBCLASS \
 "01000"

//------------------------------------------------------------------------

//MSDN: Cursor operation conflict

#define IBP_SQLSTATE__01001__WARNING_CURSOR_OPERATION_CONFLICT \
 "01001"

//------------------------------------------------------------------------

//MSDN: Disconnect error

#define IBP_SQLSTATE__01002__WARNING_DISCONNECT_ERROR \
 "01002"

//------------------------------------------------------------------------

//MSDN: NULL value eliminated in set function

#define IBP_SQLSTATE__01003__WARNING_NULL_VALUE_ELIMINATED_IN_SET_FUNCTION \
 "01003"

//------------------------------------------------------------------------

//MSDN: String data, right-truncated

#define IBP_SQLSTATE__01004__WARNING_STRING_DATA_RIGHT_TRUNCATION_WARNING \
 "01004"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__01005__WARNING_INSUFFICIENT_ITEM_DESCRIPTOR_AREAS \
 "01005"

//------------------------------------------------------------------------

//MSDN: Privilege not revoked

#define IBP_SQLSTATE__01006__WARNING_PRIVILEGE_NOT_REVOKED \
 "01006"

//------------------------------------------------------------------------

//MSDN: Privilege not granted

#define IBP_SQLSTATE__01007__WARNING_PRIVILEGE_NOT_GRANTED \
 "01007"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__01009__WARNING_SEARCH_CONDITION_TOO_LONG_FOR_INFORMATION_SCHEMA \
 "01009"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0100A__WARNING_QUERY_EXPRESSION_TOO_LONG_FOR_INFORMATION_SCHEMA \
 "0100A"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0100B__WARNING_DEFAULT_VALUE_TOO_LONG_FOR_INFORMATION_SCHEMA \
 "0100B"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0100C__WARNING_DYNAMIC_RESULT_SETS_RETURNED \
 "0100C"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0100D__WARNING_ADDITIONAL_RESULT_SETS_RETURNED \
 "0100D"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0100E__WARNING_ATTEMPT_TO_RETURN_TOO_MANY_RESULT_SETS \
 "0100E"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0100F__WARNING_STATEMENT_TOO_LONG_FOR_INFORMATION_SCHEMA \
 "0100F"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0102F__WARNING_ARRAY_DATA_RIGHT_TRUNCATION \
 "0102F"

////////////////////////////////////////////////////////////////////////////////

//MSDN: Invalid connection string attribute
//       SQLBrowseConnect
//       SQLDriverConnec

#define IBP_SQLSTATE__01S00__ODBC__INVALID_CONNECTION_STRING_ATTRIBUTE \
 "01S00"

//------------------------------------------------------------------------

//MSDN: Error in row
//       SQLBulkOperations
//       SQLExtendedFetch
//       SQLSetPos

#define IBP_SQLSTATE__01S01__ODBC__ERROR_IN_ROW \
 "01S01"

//------------------------------------------------------------------------

//MSDN: Option value changed
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect
//       SQLExecDirect
//       SQLExecute
//       SQLParamData
//       SQLPrepare
//       SQLSetConnectAttr
//       SQLSetDescField
//       SQLSetEnvAttr
//       SQLSetStmtAttr

#define IBP_SQLSTATE__01S02__ODBC__OPTION_VALUE_CHANGED \
 "01S02"

//------------------------------------------------------------------------

//MSDN: Attempt to fetch before the result set returned the first rowset
//       SQLExtendedFetch
//       SQLFetchScroll

#define IBP_SQLSTATE__01S06__ODBC__ATTEMPT_TO_FETCH_BEFORE_THE_RESULT_SET_RETURNED_THE_FIRST_ROWSET \
 "01S06"

//------------------------------------------------------------------------

//MSDN: Fractional truncation
//       SQLBulkOperations
//       SQLExecDirect
//       SQLExecute
//       SQLExtendedFetch
//       SQLFetch
//       SQLFetchScroll
//       SQLGetData
//       SQLParamData
//       SQLSetPos

#define IBP_SQLSTATE__01S07__ODBC__FRACTIONAL_TRUNCATION \
 "01S07"

//------------------------------------------------------------------------

//MSDN: Error saving File DSN
//       SQLDriverConnect

#define IBP_SQLSTATE__01S08__ODBC__ERROR_SAVING_FILE_DSN \
 "01S08"

//------------------------------------------------------------------------

//MSDN: Invalid keyword
//       SQLDriverConnect

#define IBP_SQLSTATE__01S09__ODBC__INVALID_KEYWORD \
 "01S09"

////////////////////////////////////////////////////////////////////////////////

#define IBP_SQLSTATE__02000__NO_DATA_NO_SUBCLASS \
 "02000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__02001__NO_DATA_NO_ADDITIONAL_DYNAMIC_RESULT_SETS_RETURNED \
 "02001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__07000__DYNAMIC_SQL_ERROR_NO_SUBCLASS \
 "07000"

//------------------------------------------------------------------------

//MSDN: Wrong number of parameters
//       SQLExecDirect
//       SQLExecute

#define IBP_SQLSTATE__07001__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_DYNAMIC_PARAMETER_SPEC \
 "07001"

//------------------------------------------------------------------------

//MSDN: COUNT field incorrect
//       SQLExecDirect
//       SQLExecute
//       SQLParamData

#define IBP_SQLSTATE__07002__DYNAMIC_SQL_ERROR_USING_CLAUSE_DOES_NOT_MATCH_TARGET_SPEC \
 "07002"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__07003__DYNAMIC_SQL_ERROR_CURSOR_SPECIFICATION_CANNOT_BE_EXECUTED \
 "07003"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__07004__DYNAMIC_SQL_ERROR_USING_CLAUSE_REQUIRED_FOR_DYNAMIC_PARAMETERS \
 "07004"

//------------------------------------------------------------------------

//MSDN: Prepared statement not a cursor-specification
//       SQLColAttribute
//       SQLDescribeCol

#define IBP_SQLSTATE__07005__DYNAMIC_SQL_ERROR_PREPARED_STATEMENT_NOT_A_CURSOR_SPECIFICATION \
 "07005"

//------------------------------------------------------------------------

//MSDN: Restricted data type attribute violation
//       SQLBindCol              SQLFetch
//       SQLBindParameter        SQLFetchScroll
//       SQLBulkOperations       SQLGetData
//       SQLExecDirect           SQLParamData
//       SQLExecute              SQLPutData
//       SQLExtendedFetch        SQLSetPos

#define IBP_SQLSTATE__07006__DYNAMIC_SQL_ERROR_RESTRICTED_DATA_TYPE_ATTRIBUTE_VIOLATION \
 "07006"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__07007__DYNAMIC_SQL_ERROR_USING_CLAUSE_REQUIRED_FOR_RESULT_FIELDS \
 "07007"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__07008__DYNAMIC_SQL_ERROR_INVALID_DESCRIPTOR_COUNT \
 "07008"

//------------------------------------------------------------------------

//MSDN: Invalid descriptor index
//       SQLBindCol                  SQLFetchScroll
//       SQLBindParameter            SQLGetData
//       SQLBulkOperations           SQLGetDescField
//       SQLColAttribute             SQLGetDescRec
//       SQLDescribeCol              SQLParamData
//       SQLDescribeParam            SQLSetDescField
//       SQLFetch                    SQLSetDescRecSQLSetPos

#define IBP_SQLSTATE__07009__DYNAMIC_SQL_ERROR_INVALID_DESCRIPTOR_INDEX \
 "07009"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0700B__DYNAMIC_SQL_ERROR_DATA_TYPE_TRANSFORM_FUNCTION_VIOLATION \
 "0700B"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0700C__DYNAMIC_SQL_ERROR_UNDEFINED_DATA_VALUE \
 "0700C"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0700D__DYNAMIC_SQL_ERROR_INVALID_DATA_TARGET \
 "0700D"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0700E__DYNAMIC_SQL_ERROR_INVALID_LEVEL_VALUE \
 "0700E"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0700F__DYNAMIC_SQL_ERROR_INVALID_DATETIME_INTERVAL_CODE \
 "0700F"

//------------------------------------------------------------------------

//MSDN: Invalid use of default parameter
//       SQLExecDirect
//       SQLExecute
//       SQLParamData
//       SQLPutData

#define IBP_SQLSTATE__07S01__ODBC__INVALID_USE_OF_DEFAULT_PARAMETER \
 "07S01"

//------------------------------------------------------------------------
#define IBP_SQLSTATE__08000__CONNECTION_EXCEPTION_NO_SUBCLASS \
 "08000"

//------------------------------------------------------------------------

//MSDN: Client unable to establish connection
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__08001__CONNECTION_EXCEPTION_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION \
 "08001"

//------------------------------------------------------------------------

//MSDN: Connection name in use
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect
//       SQLSetConnectAttr

#define IBP_SQLSTATE__08002__CONNECTION_EXCEPTION_CONNECTION_NAME_IN_USE \
 "08002"

//------------------------------------------------------------------------

//MSDN: Connection does not exist
//       SQLAllocHandle
//       SQLDisconnect
//       SQLEndTran
//       SQLGetConnectAttr
//       SQLGetInfo
//       SQLNativeSql
//       SQLSetConnectAttr

#define IBP_SQLSTATE__08003__CONNECTION_EXCEPTION_CONNECTION_DOES_NOT_EXIST \
 "08003"

//------------------------------------------------------------------------

//MSDN: Server rejected the connection
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__08004__CONNECTION_EXCEPTION_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION \
 "08004"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE \
 "08006"

//------------------------------------------------------------------------

//MSDN: Connection failure during transaction
//       SQLEndTran

#define IBP_SQLSTATE__08007__CONNECTION_EXCEPTION_TRANSACTION_RESOLUTION_UNKNOWN \
 "08007"

//------------------------------------------------------------------------

//MSDN: Communication link failure
//       SQLBrowseConnect          SQLGetData                 SQLPutData
//       SQLColumnPrivileges       SQLGetDescField            SQLSetConnectAttr
//       SQLColumns                SQLGetDescRec              SQLSetDescField
//       SQLConnect                SQLGetFunctions            SQLSetDescRec
//       SQLCopyDesc               SQLGetInfo                 SQLSetEnvAttr
//       SQLDescribeCol            SQLGetTypeInfo             SQLSetStmtAttr
//       SQLDescribeParam          SQLMoreResults             SQLSpecialColumns
//       SQLDriverConnect          SQLNativeSql               SQLStatistics
//       SQLExecDirect             SQLNumParams               SQLTablePrivileges
//       SQLExecute                SQLNumResultCols           SQLTables
//       SQLExtendedFetch          SQLParamData
//       SQLFetch                  SQLPrepare
//       SQLFetchScroll            SQLPrimaryKeys
//       SQLForeignKeys            SQLProcedureColumns
//       SQLGetConnectAttr         SQLProcedures

#define IBP_SQLSTATE__08S01__ODBC__COMMUNICATION_LINK_FAILURE \
 "08S01"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0A000__FEATURE_NOT_SUPPORTED_NO_SUBCLASS \
 "0A000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0A001__FEATURE_NOT_SUPPORTED_MULTIPLE_ENVIRONMENT_TRANSACTIONS \
 "0A001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0B000__INVALID_TRANSACTION_INITIATION_NO_SUBCLASS \
 "0B000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0E000__INVALID_SCHEMA_NAME_LIST_SPECIFICATION_NO_SUBCLASS \
 "0E000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0F000__LOCATOR_EXCEPTION_NO_SUBCLASS \
 "0F000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0F001__LOCATOR_EXCEPTION_INVALID_SPECIFICATION \
 "0F001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0L000__INVALID_GRANTOR_STATE_NO_SUBCLASS \
 "0L000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0M000__INVALID_SQL_INVOKED_PROCEDURE_REFERENCE_NO_SUBCLASS \
 "0M000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0P000__INVALID_ROLE_SPECIFICATION \
 "0P000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0S000__INVALID_TRANSFORM_GROUP_NAME_SPECIFICATION_NO_SUBCLASS \
 "0S000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0T000__TARGET_TABLE_DISAGREES_WITH_CURSOR_SPECIFICATION_NO_SUBCLASS \
 "0T000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0U000__ATTEMPT_TO_ASSIGN_TO_NON_UPDATABLE_COLUMN_NO_SUBCLASS \
 "0U000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0V000__ATTEMPT_TO_ASSIGN_TO_ORDERING_COLUMN_NO_SUBCLASS \
 "0V000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0Z000__DIAGNOSTICS_EXCEPTION_NO_SUBCLASS \
 "0Z000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__0Z001__DIAGNOSTICS_EXCEPTION_MAXIMUM_NUMBER_OF_DIAGNOSTICS_AREAS_EXCEEDED \
 "0Z001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__21000__CARDINALITY_VIOLATION_NO_SUBCLASS \
 "21000"

//------------------------------------------------------------------------

//MSDN: Insert value list does not match column list
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__21S01__ODBC__INSERT_VALUE_LIST_DOES_NOT_MATCH_COLUMN_LIST \
 "21S01"

//------------------------------------------------------------------------

//MSDN: Degree of derived table does not match column list
//       SQLBulkOperations
//       SQLExecDirect
//       SQLExecute
//       SQLParamData
//       SQLPrepare
//       SQLSetPos

#define IBP_SQLSTATE__21S02__ODBC__DEGREE_OF_DERIVED_TABLE_DOES_NOT_MATCH_COLUMN_LIST \
 "21S02"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22000__DATA_EXCEPTION_NO_SUBCLASS \
 "22000"

//------------------------------------------------------------------------

//MSDN: String data, right-truncated
//       SQLBulkOperations
//       SQLExecDirect
//       SQLExecute
//       SQLFetch
//       SQLFetchScroll
//       SQLParamData
//       SQLPutData
//       SQLSetDescField
//       SQLSetPos

#define IBP_SQLSTATE__22001__DATA_EXCEPTION_STRING_DATA_RIGHT_TRUNCATION \
 "22001"

//------------------------------------------------------------------------

//MSDN: Indicator variable required but not supplied
//       SQLExecDirect
//       SQLExecute
//       SQLExtendedFetch
//       SQLFetch
//       SQLFetchScroll
//       SQLGetData
//       SQLParamData

#define IBP_SQLSTATE__22002__DATA_EXCEPTION_MOST_SPECIFIC_TYPE_MISMATCH \
 "22002"

//------------------------------------------------------------------------

//MSDN: Numeric value out of range
//       SQLBulkOperations                  SQLGetData
//       SQLExecDirect                      SQLGetInfo
//       SQLExecute                         SQLParamData
//       SQLExtendedFetch                   SQLPutData
//       SQLFetch                           SQLSetPos
//       SQLFetchScroll

#define IBP_SQLSTATE__22003__DATA_EXCEPTION_NUMERIC_VALUE_OUT_OF_RANGE \
 "22003"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22004__DATA_EXCEPTION_NULL_VALUE_NOT_ALLOWED \
 "22004"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22005__DATA_EXCEPTION_ERROR_IN_ASSIGNMENT \
 "22005"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22006__DATA_EXCEPTION_INVALID_INTERVAL_FORMAT \
 "22006"

//------------------------------------------------------------------------

//MSDN: Invalid datetime format
//       SQLBulkOperations                  SQLFetchScroll
//       SQLExecDirect                      SQLGetData
//       SQLExecute                         SQLParamData
//       SQLExtendedFetch                   SQLPutData
//       SQLFetch                           SQLSetPos

#define IBP_SQLSTATE__22007__DATA_EXCEPTION_INVALID_DATETIME_FORMAT \
 "22007"

//------------------------------------------------------------------------

//MSDN: Datetime field overflow
//       SQLBulkOperations                  QLParamData
//       SQLExecDirect                      SQLPutData

#define IBP_SQLSTATE__22008__DATA_EXCEPTION_DATETIME_FIELD_OVERFLOW \
 "22008"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22009__DATA_EXCEPTION_INVALID_TIME_ZONE_DISPLACEMENT_VALUE \
 "22009"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200B__DATA_EXCEPTION_ESCAPE_CHARACTER_CONFLICT \
 "2200B"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200C__DATA_EXCEPTION_INVALID_USE_OF_ESCAPE_CHARACTER \
 "2200C"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200D__DATA_EXCEPTION_INVALID_ESCAPE_OCTET \
 "2200D"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200F__DATA_EXCEPTION_ZERO_LENGTH_CHARACTER_STRING \
 "2200F"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200G__DATA_EXCEPTION_NULL_VALUE_NO_INDICATOR_PARAMETER \
 "2200G"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200H__DATA_EXCEPTION_SEQUENCE_GENERATOR_LIMIT_EXCEEDED \
 "2200H"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200P__DATA_EXCEPTION_INTERVAL_VALUE_OUT_OF_RANGE \
 "2200P"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2200Q__DATA_EXCEPTION_MULTISET_VALUE_OVERFLOW \
 "2200Q"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22010__DATA_EXCEPTION_INVALID_INDICATOR_PARAMETER_VALUE \
 "22010"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22011__DATA_EXCEPTION_SUBSTRING_ERROR \
 "22011"

//------------------------------------------------------------------------

//MSDN: Division by zero
//       SQLExecDirect                      SQLFetchScroll
//       SQLExecute                         SQLGetData
//       SQLExtendedFetch                   SQLPutData
//       SQLFetch

#define IBP_SQLSTATE__22012__DATA_EXCEPTION_DIVISION_BY_ZERO \
 "22012"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22013__DATA_EXCEPTION_INVALID_PRECEDING_OR_FOLLOWING_SIZE_IN_WINDOW_FUNCTION \
 "22013"

//------------------------------------------------------------------------

//MSDN: Interval field overflow
//       SQLBulkOperations                  SQLFetchScroll
//       SQLExecDirect                      SQLGetData
//       SQLExecute                         SQLParamData
//       SQLExtendedFetch                   SQLPutData
//       SQLFetch                           SQLSetPos

#define IBP_SQLSTATE__22015__DATA_EXCEPTION_INTERVAL_FIELD_OVERFLOW \
 "22015"

//------------------------------------------------------------------------

//MSDN: Invalid character value for cast specification
//       SQLBulkOperations                  SQLFetchScroll
//       SQLExecDirect                      SQLGetData
//       SQLExecute                         SQLParamData
//       SQLExtendedFetch                   SQLPutData
//       SQLFetch                           SQLSetPos

#define IBP_SQLSTATE__22018__DATA_EXCEPTION_INVALID_CHARACTER_VALUE_FOR_CAST \
 "22018"

//------------------------------------------------------------------------

//MSDN: Invalid escape character
//       SQLExecDirect
//       SQLExecute
//       SQLPrepare

#define IBP_SQLSTATE__22019__DATA_EXCEPTION_INVALID_ESCAPE_CHARACTER \
 "22019"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2201B__DATA_EXCEPTION_INVALID_REGULAR_EXPRESSION \
 "2201B"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2201E__DATA_EXCEPTION_INVALID_ARGUMENT_FOR_NATURAL_LOGARITHM \
 "2201E"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2201F__DATA_EXCEPTION_INVALID_ARGUMENT_FOR_POWER_FUNCTION \
 "2201F"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2201G__DATA_EXCEPTION_INVALID_ARGUMENT_FOR_WIDTH_BUCKET_FUNCTION \
 "2201G"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22021__DATA_EXCEPTION_CHARACTER_NOT_IN_REPERTOIRE \
 "22021"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22022__DATA_EXCEPTION_INDICATOR_OVERFLOW \
 "22022"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22023__DATA_EXCEPTION_INVALID_PARAMETER_VALUE \
 "22023"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22024__DATA_EXCEPTION_UNTERMINATED_C_STRING \
 "22024"

//------------------------------------------------------------------------

//MSDN: Invalid escape sequence
//       SQLExecDirect
//       SQLExecute
//       SQLPrepare

#define IBP_SQLSTATE__22025__DATA_EXCEPTION_INVALID_ESCAPE_SEQUENCE \
 "22025"

//------------------------------------------------------------------------

//MSDN: String data, length mismatch
//       SQLParamData

#define IBP_SQLSTATE__22026__DATA_EXCEPTION_STRING_DATA_LENGTH_MISMATCH \
 "22026"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22027__DATA_EXCEPTION_TRIM_ERROR \
 "22027"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__22029__DATA_EXCEPTION_NONCHARACTER_IN_UCS_STRING \
 "22029"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2202D__DATA_EXCEPTION_NULL_VALUE_SUBSTITUTED_FOR_MUTATOR_SUBJECT_PARAMETER \
 "2202D"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2202E__DATA_EXCEPTION_ARRAY_ELEMENT_ERROR \
 "2202E"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2202G__DATA_EXCEPTION_INVALID_REPEAT_ARGUMENT_IN_A_SAMPLE_CLAUSE \
 "2202G"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2202H__DATA_EXCEPTION_INVALID_SAMPLE_SIZE \
 "2202H"

//------------------------------------------------------------------------

//MSDN: Integrity constraint violation
//       SQLBulkOperations                  SQLParamData
//       SQLExecDirect                      SQLSetPos
//       SQLExecute

#define IBP_SQLSTATE__23000__INTEGRITY_CONSTRAINT_VIOLATION_NO_SUBCLASS \
 "23000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__23001__INTEGRITY_CONSTRAINT_VIOLATION_RESTRICT_VIOLATION \
 "23001"

//------------------------------------------------------------------------

//MSDN: Invalid cursor state
//       SQLBulkOperations         SQLGetStmtAttr           SQLSpecialColumns
//       SQLCloseCursor            SQLGetTypeInfo           SQLStatistics
//       SQLColumnPrivileges       SQLNativeSql             SQLTablePrivileges
//       SQLColumns                SQLPrepare               SQLTables
//       SQLExecDirect             SQLPrimaryKeys
//       SQLExecute                SQLProcedureColumns
//       SQLExtendedFetch          SQLProcedures
//       SQLFetch                  SQLSetConnectAttr
//       SQLFetchScroll            SQLSetCursorName
//       SQLForeignKeys            SQLSetPos
//       SQLGetData                SQLSetStmtAttr

#define IBP_SQLSTATE__24000__INVALID_CURSOR_STATE_NO_SUBCLASS \
 "24000"

//------------------------------------------------------------------------

//MSDN: Invalid transaction state
//       SQLDisconnect

#define IBP_SQLSTATE__25000__INVALID_TRANSACTION_STATE_NO_SUBCLASS \
 "25000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25001__INVALID_TRANSACTION_STATE_ACTIVE_SQL_TRANSACTION \
 "25001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25002__INVALID_TRANSACTION_STATE_BRANCH_TRANSACTION_ALREADY_ACTIVE \
 "25002"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25003__INVALID_TRANSACTION_STATE_INAPPROPRIATE_ACCESS_MODE_FOR_BRANCH_TRANSACTION \
 "25003"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25004__INVALID_TRANSACTION_STATE_INAPPROPRIATE_ISOLATION_LEVEL_FOR_BRANCH_TRANSACTION \
 "25004"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25005__INVALID_TRANSACTION_STATE_NO_ACTIVE_SQL_TRANSACTION_FOR_BRANCH_TRANSACTION \
 "25005"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25006__INVALID_TRANSACTION_STATE_READ_ONLY_SQL_TRANSACTION \
 "25006"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25007__INVALID_TRANSACTION_STATE_SCHEMA_AND_DATA_STATEMENT_MIXING_NOT_SUPPORTED \
 "25007"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__25008__INVALID_TRANSACTION_STATE_HELD_CURSOR_REQUIRES_SAME_ISOLATION_LEVEL \
 "25008"

//------------------------------------------------------------------------
//MSDN: Transaction state
//       SQLEndTran

#define IBP_SQLSTATE__25S01__ODBC__TRANSACTION_STATE \
 "25S01"

//------------------------------------------------------------------------

//MSDN: Transaction is still active
//       SQLEndTran

#define IBP_SQLSTATE__25S02__ODBC__TRANSACTION_IS_STILL_ACTIVE \
 "25S02"

//------------------------------------------------------------------------

//MSDN: Transaction is rolled back
//       SQLEndTran

#define IBP_SQLSTATE__25S03__ODBC__TRANSACTION_IS_ROLLED_BACK \
 "25S03"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__26000__INVALID_SQL_STATEMENT_NAME_NO_SUBCLASS \
 "26000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__27000__TRIGGERED_DATA_CHANGE_VIOLATION_NO_SUBCLASS \
 "27000"

//------------------------------------------------------------------------

//MSDN: Invalid authorization specification
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS \
 "28000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2A000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_IN_DIRECT_STATEMENT_NO_SUBCLASS \
 "2A000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2B000__DEPENDENT_PRIVILEGE_DESCRIPTORS_STILL_EXIST_NO_SUBCLASS \
 "2B000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2C000__INVALID_CHARACTER_SET_NAME_NO_SUBCLASS \
 "2C000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2D000__INVALID_TRANSACTION_TERMINATION_NO_SUBCLASS \
 "2D000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2E000__INVALID_CONNECTION_NAME_NO_SUBCLASS \
 "2E000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2F000__SQL_ROUTINE_EXCEPTION_NO_SUBCLASS \
 "2F000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2F002__SQL_ROUTINE_EXCEPTION_MODIFYING_SQL_DATA_NOT_PERMITTED \
 "2F002"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2F003__SQL_ROUTINE_EXCEPTION_PROHIBITED_SQL_STATEMENT_ATTEMPTED \
 "2F003"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2F004__SQL_ROUTINE_EXCEPTION_READING_SQL_DATA_NOT_PERMITTED \
 "2F004"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2F005__SQL_ROUTINE_EXCEPTION_FUNCTION_EXECUTED_NO_RETURN_STATEMENT \
 "2F005"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__2H000__INVALID_COLLATION_NAME_NO_SUBCLASS \
 "2H000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__30000__INVALID_SQL_STATEMENT \
 "30000"

//------------------------------------------------------------------------
/*
#define IBP_SQLSTATE__30000__INVALID_SQL_STATEMENT_IDENTIFIER_NO_SUBCLASS \
 "30000"
*/
//------------------------------------------------------------------------

#define IBP_SQLSTATE__33000__INVALID_SQL_DESCRIPTOR_NAME_NO_SUBCLASS \
 "33000"

//------------------------------------------------------------------------

//MSDN: Invalid cursor name
//       SQLExecDirect
//       SQLPrepare
//       SQLSetCursorName

#define IBP_SQLSTATE__34000__INVALID_CURSOR_NAME_NO_SUBCLASS \
 "34000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__35000__INVALID_CONDITION_NUMBER_NO_SUBCLASS \
 "35000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__37000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_IN_DYNAMIC_STATEMENT_NO_SUBCLASS \
 "37000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__38000__EXTERNAL_ROUTINE_EXCEPTION_NO_SUBCLASS \
 "38000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__38001__EXTERNAL_ROUTINE_EXCEPTION_CONTAINING_SQL_NOT_PERMITTED \
 "38001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__38002__EXTERNAL_ROUTINE_EXCEPTION_MODIFYING_SQL_DATA_NOT_PERMITTED \
 "38002"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__38003__EXTERNAL_ROUTINE_EXCEPTION_PROHIBITED_SQL_STATEMENT_ATTEMPTED \
 "38003"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__38004__EXTERNAL_ROUTINE_EXCEPTION_READING_SQL_DATA_NOT_PERMITTED \
 "38004"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__39000__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NO_SUBCLASS \
 "39000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__39004__EXTERNAL_ROUTINE_INVOCATION_EXCEPTION_NULL_VALUE_NOT_ALLOWED \
 "39004"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__3B000__SAVEPOINT_EXCEPTION_NO_SUBCLASS \
 "3B000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__3B001__SAVEPOINT_EXCEPTION_INVALID_SPECIFICATION \
 "3B001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__3B002__SAVEPOINT_EXCEPTION_TOO_MANY \
 "3B002"

//------------------------------------------------------------------------

//MSDN: Duplicate cursor name
//       SQLSetCursorName

#define IBP_SQLSTATE__3C000__AMBIGUOUS_CURSOR_NAME_NO_SUBCLASS \
 "3C000"

//------------------------------------------------------------------------

//MSDN: Invalid catalog name
//       SQLExecDirect
//       SQLPrepare
//       SQLSetConnectAttr

#define IBP_SQLSTATE__3D000__INVALID_CATALOG_NAME_NO_SUBCLASS \
 "3D000"

//------------------------------------------------------------------------

//MSDN: Invalid schema name
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__3F000__INVALID_SCHEMA_NAME_NO_SUBCLASS \
 "3F000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__40000__TRANSACTION_ROLLBACK_NO_SUBCLASS \
 "40000"

//------------------------------------------------------------------------

//MSDN: Serialization failure
//       SQLBulkOperations          SQLForeignKeys          SQLSpecialColumns
//       SQLColumnPrivileges        SQLGetTypeInfo          SQLStatistics
//       SQLColumns                 SQLMoreResults          SQLTablePrivileges
//       SQLEndTran                 SQLParamData            SQLTables
//       SQLExecDirect              SQLPrimaryKeys
//       SQLExecute                 SQLProcedureColumns
//       SQLFetch                   SQLProcedures
//       SQLFetchScroll             SQLSetPos

#define IBP_SQLSTATE__40001__TRANSACTION_ROLLBACK_SERIALIZATION_FAILURE \
 "40001"

//------------------------------------------------------------------------

//MSDN: Integrity constraint violation
//       SQLEndTran

#define IBP_SQLSTATE__40002__TRANSACTION_ROLLBACK_INTEGRITY_CONSTRAINT_VIOLATION \
 "40002"

//------------------------------------------------------------------------

//MSDN: Statement completion unknown
//       SQLBulkOperations        SQLForeignKeys          SQLSetPos
//       SQLColumnPrivileges      SQLGetTypeInfo          SQLSpecialColumns
//       SQLColumns               SQLMoreResults          SQLStatistics
//       SQLExecDirect            SQLPrimaryKeys          SQLTablePrivileges
//       SQLExecute               SQLProcedureColumns     SQLTables
//       SQLFetch                 SQLProcedures
//       SQLFetchScroll           SQLParamData

#define IBP_SQLSTATE__40003__TRANSACTION_ROLLBACK_STATEMENT_COMPLETION_UNKNOWN \
 "40003"

////////////////////////////////////////////////////////////////////////////////

//MSDN: Syntax error or access violation
//       SQLBulkOperations         SQLParamData
//       SQLExecDirect             SQLPrepare
//       SQLExecute                SQLSetPos

#define IBP_SQLSTATE__42000__SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION_NO_SUBCLASS \
 "42000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42501__INSUFFICIENT_PRIVILEGE \
 "42501"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42601__SYNTAX_ERROR \
 "42601"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42602__INVALID_NAME \
 "42602"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42611__INVALID_COLUMN_DEFINITION \
 "42611"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42622__NAME_TOO_LONG \
 "42622"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42701__DUPLICATE_COLUMN \
 "42701"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42702__AMBIGUOUS_COLUMN \
 "42702"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42703__UNDEFINED_COLUMN \
 "42703"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42704__UNDEFINED_OBJECT \
 "42704"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42710__DUPLICATE_OBJECT \
 "42710"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42712__DUPLICATE_ALIAS \
 "42712"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42723__DUPLICATE_FUNCTION \
 "42723"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42725__AMBIGUOUS_FUNCTION \
 "42725"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42803__GROUPING_ERROR \
 "42803"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42804__DATATYPE_MISMATCH \
 "42804"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42809__WRONG_OBJECT_TYPE \
 "42809"

//------------------------------------------------------------------------
#define IBP_SQLSTATE__42818__THE_OPERANDS_OF_AN_ARITHMETIC_OR_COMPARISON_OPERATION_ARE_NOT_COMPARABLE \
 "42818"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42830__INVALID_FOREIGN_KEY \
 "42830"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42846__CANNOT_COERCE \
 "42846"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42883__UNDEFINED_FUNCTION \
 "42883"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42939__RESERVED_NAME \
 "42939"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P01__UNDEFINED_TABLE \
 "42P01"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P02__UNDEFINED_PARAMETER \
 "42P02"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P03__DUPLICATE_CURSOR \
 "42P03"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P04__DUPLICATE_DATABASE \
 "42P04"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P05__DUPLICATE_PREPARED_STATEMENT \
 "42P05"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P06__DUPLICATE_SCHEMA \
 "42P06"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P07__DUPLICATE_TABLE \
 "42P07"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P08__AMBIGUOUS_PARAMETER \
 "42P08"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P09__AMBIGUOUS_ALIAS \
 "42P09"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P10__INVALID_COLUMN_REFERENCE \
 "42P10"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P11__INVALID_CURSOR_DEFINITION \
 "42P11"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P12__INVALID_DATABASE_DEFINITION \
 "42P12"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P13__INVALID_FUNCTION_DEFINITION \
 "42P13"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P14__INVALID_PREPARED_STATEMENT_DEFINITION \
 "42P14"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P15__INVALID_SCHEMA_DEFINITION \
 "42P15"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P16__INVALID_TABLE_DEFINITION \
 "42P16"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P17__INVALID_OBJECT_DEFINITION \
 "42P17"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P18__INDETERMINATE_DATATYPE \
 "42P18"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P19__INVALID_RECURSION \
 "42P19"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__42P20__WINDOWING_ERROR \
 "42P20"

////////////////////////////////////////////////////////////////////////////////

//MSDN: Base table or view already exists
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__42S01__ODBC__BASE_TABLE_OR_VIEW_ALREADY_EXISTS \
 "42S01"

//------------------------------------------------------------------------

//MSDN: Base table or view not found
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__42S02__ODBC__BASE_TABLE_OR_VIEW_NOT_FOUND \
 "42S02"

//------------------------------------------------------------------------

//MSDN: Index already exists
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__42S11__ODBC__INDEX_ALREADY_EXISTS \
 "42S11"

//------------------------------------------------------------------------

//MSDN: Index not found
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__42S12__ODBC__INDEX_NOT_FOUND \
 "42S12"

//------------------------------------------------------------------------

//MSDN: Column already exists
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__42S21__ODBC__COLUMN_ALREADY_EXISTS \
 "42S21"

//------------------------------------------------------------------------

//MSDN: Column not found
//       SQLExecDirect
//       SQLPrepare

#define IBP_SQLSTATE__42S22__ODBC__COLUMN_NOT_FOUND \
 "42S22"

//------------------------------------------------------------------------

//MSDN: WITH CHECK OPTION violation
//       SQLBulkOperations
//       SQLExecDirect
//       SQLExecute
//       SQLParamData
//       SQLSetPos

#define IBP_SQLSTATE__44000__WITH_CHECK_OPTION_VIOLATION_NO_SUBCLASS \
 "44000"

////////////////////////////////////////////////////////////////////////////////

//PG

#define IBP_SQLSTATE__53000__INSUFFICIENT_RESOURCES \
 "53000"

//------------------------------------------------------------------------

//PG

#define IBP_SQLSTATE__53100__DISK_FULL \
 "53100"

//------------------------------------------------------------------------

//PG

#define IBP_SQLSTATE__53200__OUT_OF_MEMORY \
 "53200"

//------------------------------------------------------------------------

//PG

#define IBP_SQLSTATE__53300__TOO_MANY_CONNECTIONS \
 "53300"

////////////////////////////////////////////////////////////////////////////////
//Class 54 Ч Program Limit Exceeded

//PG: program_limit_exceeded

#define IBP_SQLSTATE__54000__PROGRAM_LIMIT_EXCEEDED \
 "54000"

//------------------------------------------------------------------------

//PG: statement_too_complex

#define IBP_SQLSTATE__54001__STATEMENT_TOO_COMPLEX \
 "54001"

//------------------------------------------------------------------------

//PG: too_many_columns

#define IBP_SQLSTATE__54011__TOO_MANY_COLUMNS \
 "54011"

//------------------------------------------------------------------------

//PG: too_many_arguments

#define IBP_SQLSTATE__54023__TOO_MANY_ARGUMENTS \
 "54023"

////////////////////////////////////////////////////////////////////////////////
//Class 55 Ч Object Not In Prerequisite State

#define IBP_SQLSTATE__55000__OBJECT_NOT_IN_PREREQUISITE_STATE \
 "55000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__55006__OBJECT_IN_USE \
 "55006"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__55P02__CANT_CHANGE_RUNTIME_PARAM \
 "55P02"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__55P03__LOCK_NOT_AVAILABLE \
 "55P03"

////////////////////////////////////////////////////////////////////////////////

//MSDN: General error
//       All ODBC functions except:
//        SQLError
//        SQLGetDiagField
//        SQLGetDiagRec

#define IBP_SQLSTATE__HY000__CLI_SPECIFIC_CONDITION_NO_SUBCLASS \
 "HY000"

//------------------------------------------------------------------------

//MSDN: Memory allocation error
//       AllODBCfunctionsexcept:
//        SQLError
//        SQLGetDiagField
//        SQLGetDiagRec

#define IBP_SQLSTATE__HY001__ODBC__MEMORY_ALLOCATION_ERROR \
 "HY001"

//------------------------------------------------------------------------

//MSDN: Invalid application buffer type
//       SQLBindCol
//       SQLBindParameter
//       SQLGetData

#define IBP_SQLSTATE__HY003__ODBC__INVALID_APPLICATION_BUFFER_TYPE \
 "HY003"

//------------------------------------------------------------------------

//MSDN: Invalid SQL data type
//       SQLBindParameter
//       SQLGetTypeInfo

#define IBP_SQLSTATE__HY004__ODBC__INVALID_SQL_DATA_TYPE \
 "HY004"

//------------------------------------------------------------------------

//MSDN: Associated statement is not prepared
//       SQLCopyDesc
//       SQLGetDescField
//       SQLGetDescRec

#define IBP_SQLSTATE__HY007__ODBC__ASSOCIATED_STATEMENT_IS_NOT_PREPARED \
 "HY007"

//------------------------------------------------------------------------

//MSDN: Operation canceled
//       All ODBC functions that can be processed asynchronously:
//        SQLBulkOperations        SQLFetchScroll        SQLProcedureColumns
//        SQLColAttribute          SQLForeignKeys        SQLProcedures
//        SQLColumnPrivileges      SQLGetData            SQLPutData
//        SQLColumns               SQLGetTypeInfo        SQLSetPos
//        SQLDescribeCol           SQLMoreResults        SQLSpecialColumns
//        SQLDescribeParam         SQLNumParams          SQLStatistics
//        SQLExecDirect            SQLNumResultCols      SQLTablePrivileges
//        SQLExecute               SQLParamData          SQLTables
//        SQLExtendedFetch         SQLPrepare
//        SQLFetch                 SQLPrimaryKeys

#define IBP_SQLSTATE__HY008__ODBC__OPERATION_CANCELED \
 "HY008"

//------------------------------------------------------------------------

//MSDN: Invalid use of null pointer
//       SQLAllocHandle           SQLNativeSql            SQLSpecialColumns
//       SQLBindParameter         SQLPrepare              SQLStatistics
//       SQLBulkOperations        SQLPrimaryKeys          SQLTablePrivileges
//       SQLColumnPrivileges      SQLProcedureColumns     SQLTables
//       SQLColumns               SQLProcedures
//       SQLExecDirect            SQLPutData
//       SQLForeignKeys           SQLSetConnectAttr
//       SQLGetCursorName         SQLSetCursorName
//       SQLGetData               SQLSetEnvAttr
//       SQLGetFunctions          SQLSetStmtAttr

#define IBP_SQLSTATE__HY009__ODBC__INVALID_USE_OF_NULL_POINTER \
 "HY009"

//------------------------------------------------------------------------

//MSDN: Function sequence error
//       SQLAllocHandle          SQLFetchScroll        SQLPrimaryKeys
//       SQLBindCol              SQLForeignKeys        SQLProcedureColumns
//       SQLBindParameter        SQLFreeHandle         SQLProcedures
//       SQLBulkOperations       SQLFreeStmt           SQLPutData
//       SQLCloseCursor          SQLGetConnectAttr     SQLRowCount
//       SQLColAttribute         SQLGetCursorName      SQLSetConnectAttr
//       SQLColumnPrivileges     SQLGetData            SQLSetCursorName
//       SQLColumns              SQLGetDescField       SQLSetDescField
//       SQLCopyDesc             SQLGetDescRec         SQLSetEnvAttr
//       SQLDescribeCol          SQLGetFunctions       SQLSetDescRec
//       SQLDescribeParam        SQLGetStmtAttr        SQLSetPos
//       SQLDisconnect           SQLGetTypeInfo        SQLSetStmtAttr
//       SQLEndTran              SQLMoreResults        SQLSpecialColumns
//       SQLExecDirect           SQLNumParams          SQLStatistics
//       SQLExecute              SQLNumResultCols      SQLTablePrivileges
//       SQLExtendedFetch        SQLParamData          SQLTables
//       SQLFetch                SQLPrepare

#define IBP_SQLSTATE__HY010__ODBC__FUNCTION_SEQUENCE_ERROR \
 "HY010"

//------------------------------------------------------------------------

//MSDN: Attribute cannot be set now
//       SQLBulkOperations
//       SQLParamData
//       QLSetPos
//       SQLSetStmtAttr

#define IBP_SQLSTATE__HY011__ODBC__ATTRIBUTE_CANNOT_BE_SET_NOW \
 "HY011"

//------------------------------------------------------------------------

//MSDN: Invalid transaction operation code
//       SQLEndTran

#define IBP_SQLSTATE__HY012__ODBC__INVALID_TRANSACTION_OPERATION_CODE \
 "HY012"

//------------------------------------------------------------------------

//MSDN: Memory management error
//       All ODBC functions except:
//        SQLGetDiagField
//        SQLGetDiagRec

#define IBP_SQLSTATE__HY013__ODBC__MEMORY_MANAGEMENT_ERROR \
 "HY013"

//------------------------------------------------------------------------

//MSDN: Limit on the number of handles exceeded
//       SQLAllocHandle

#define IBP_SQLSTATE__HY014__ODBC__LIMIT_ON_THE_NUMBER_OF_HANDLES_EXCEEDED \
 "HY014"

//------------------------------------------------------------------------

//MSDN: No cursor name available
//       SQLGetCursorName

#define IBP_SQLSTATE__HY015__ODBC__NO_CURSOR_NAME_AVAILABLE \
 "HY015"

//------------------------------------------------------------------------

//MSDN: Cannot modify an implementation row descriptor
//       SQLCopyDesc
//       SQLSetDescField
//       SQLSetDescRec

#define IBP_SQLSTATE__HY016__ODBC__CANNOT_MODIFY_AN_IMPLEMENTATION_ROW_DESCRIPTOR \
 "HY016"

//------------------------------------------------------------------------

//MSDN: Invalid use of an automatically allocated descriptor handle
//       SQLFreeHandle
//       SQLSetStmtAttr

#define IBP_SQLSTATE__HY017__ODBC__INVALID_USE_OF_AN_AUTOMATICALLY_ALLOCATED_DESCRIPTOR_HANDLE \
 "HY017"

//------------------------------------------------------------------------

//MSDN: Server declined cancel request
//       SQLCancel

#define IBP_SQLSTATE__HY018__ODBC__SERVER_DECLINED_CANCEL_REQUEST \
 "HY018"

//------------------------------------------------------------------------

//MSDN: Non-character and non-binary data sent in pieces
//       SQLPutData

#define IBP_SQLSTATE__HY019__ODBC__NON_CHARACTER_AND_NON_BINARY_DATA_SENT_IN_PIECES \
 "HY019"

//------------------------------------------------------------------------

//MSDN: Attempt to concatenate a null value
//       SQLPutData

#define IBP_SQLSTATE__HY020__ODBC__ATTEMPT_TO_CONCATENATE_A_NULL_VALUE \
 "HY020"

//------------------------------------------------------------------------

//MSDN: Inconsistent descriptor information
//       SQLBindParameter
//       SQLCopyDesc
//       SQLGetDescField
//       SQLSetDescField
//       SQLSetDescRec

#define IBP_SQLSTATE__HY021__ODBC__INCONSISTENT_DESCRIPTOR_INFORMATION \
 "HY021"

//------------------------------------------------------------------------

//MSDN: Invalid attribute value
//       SQLSetConnectAttr
//       SQLSetEnvAttr
//       SQLSetStmtAttr

#define IBP_SQLSTATE__HY024__ODBC__INVALID_ATTRIBUTE_VALUE \
 "HY024"

//------------------------------------------------------------------------

//MSDN: Invalid string or buffer length
//       SQLBindCol                   SQLFetchScroll           SQLSetConnectAttr
//       SQLBindParameter             SQLForeignKeys           SQLSetCursorName
//       SQLBrowseConnect             SQLGetConnectAttr        SQLSetDescField
//       SQLBulkOperations            SQLGetCursorName         SQLSetDescRec
//       SQLColAttribute              SQLGetData               SQLSetEnvAttr
//       SQLColumnPrivileges          SQLGetDescField          SQLSetStmtAttr
//       SQLColumns                   SQLGetInfo               SQLSetPos
//       SQLConnect                   SQLGetStmtAttr           SQLSpecialColumns
//       SQLDataSources               SQLNativeSql             SQLStatistics
//       SQLDescribeCol               SQLParamData             SQLTablePrivileges
//       SQLDriverConnect             SQLPrepare               SQLTables
//       SQLDrivers                   SQLPrimaryKeys
//       SQLExecDirect                SQLProcedureColumns
//       SQLExecute                   SQLProcedures
//       SQLFetch                     SQLPutData

#define IBP_SQLSTATE__HY090__ODBC__INVALID_STRING_OR_BUFFER_LENGTH \
 "HY090"

//------------------------------------------------------------------------

//MSDN: Invalid descriptor field identifier
//       SQLColAttribute
//       SQLGetDescField
//       SQLSetDescField

#define IBP_SQLSTATE__HY091__ODBC__INVALID_DESCRIPTOR_FIELD_IDENTIFIER \
 "HY091"

//------------------------------------------------------------------------

//MSDN: Invalid attribute/option identifier
//       SQLAllocHandle             SQLGetEnvAttr
//       QLBulkOperations           QLParamData
//       SQLCopyDesc                SQLSetConnectAttr
//       SQLDriverConnect           SQLSetDescField
//       SQLEndTran                 SQLSetEnvAttr
//       SQLFreeStmt                SQLSetPos
//       SQLGetConnectAttr          SQLSetStmtAttr

#define IBP_SQLSTATE__HY092__ODBC__INVALID_ATTRIBUTE_OR_OPTION_IDENTIFIER \
 "HY092"

//------------------------------------------------------------------------

//MSDN: Function type out of range
//       SQLGetFunctions

#define IBP_SQLSTATE__HY095__ODBC__FUNCTION_TYPE_OUT_OF_RANGE \
 "HY095"

//------------------------------------------------------------------------

//MSDN: Invalid information type
//       SQLGetInfo

#define IBP_SQLSTATE__HY096__ODBC__INVALID_INFORMATION_TYPE \
 "HY096"

//------------------------------------------------------------------------

//MSDN: Column type out of range
//       SQLSpecialColumns

#define IBP_SQLSTATE__HY097__ODBC__COLUMN_TYPE_OUT_OF_RANGE \
 "HY097"

//------------------------------------------------------------------------

//MSDN: Scope type out of range
//       SQLSpecialColumns

#define IBP_SQLSTATE__HY098__ODBC__SCOPE_TYPE_OUT_OF_RANGE \
 "HY098"

//------------------------------------------------------------------------

//MSDN: Nullable type out of range
//       SQLSpecialColumns

#define IBP_SQLSTATE__HY099__ODBC__NULLABLE_TYPE_OUT_OF_RANGE \
 "HY099"

//------------------------------------------------------------------------

//MSDN: Uniqueness option type out of range
//       SQLStatistics

#define IBP_SQLSTATE__HY100__ODBC__UNIQUENESS_OPTION_TYPE_OUT_OF_RANGE \
 "HY100"

//------------------------------------------------------------------------

//MSDN: Accuracy option type out of range
//       SQLStatistics

#define IBP_SQLSTATE__HY101__ODBC__ACCURACY_OPTION_TYPE_OUT_OF_RANGE \
 "HY101"

//------------------------------------------------------------------------

//MSDN: Invalid retrieval code
//       SQLDataSources
//       SQLDrivers

#define IBP_SQLSTATE__HY103__ODBC__INVALID_RETRIEVAL_CODE \
 "HY103"

//------------------------------------------------------------------------

//MSDN: Invalid precision or scale value
//       SQLBindParameter

#define IBP_SQLSTATE__HY104__ODBC__INVALID_PRECISION_OR_SCALE_VALUE \
 "HY104"

//------------------------------------------------------------------------

//MSDN: Invalid parameter type
//       SQLBindParameter
//       SQLExecDirect
//       SQLExecute
//       SQLParamData
//       SQLSetDescField

#define IBP_SQLSTATE__HY105__ODBC__INVALID_PARAMETER_TYPE \
 "HY105"

//------------------------------------------------------------------------

//MSDN: Fetch type out of range
//       SQLExtendedFetch
//       SQLFetchScroll

#define IBP_SQLSTATE__HY106__ODBC__FETCH_TYPE_OUT_OF_RANGE \
 "HY106"

//------------------------------------------------------------------------

//MSDN: Row value out of range
//       SQLExtendedFetch
//       SQLFetch
//       SQLFetchScroll
//       SQLSetPos

#define IBP_SQLSTATE__HY107__ODBC__ROW_VALUE_OUT_OF_RANGE \
 "HY107"

//------------------------------------------------------------------------

//MSDN: Invalid cursor position
//       SQLExecDirect            SQLNativeSql
//       SQLExecute               SQLParamData
//       SQLGetData               SQLSetPos
//       SQLGetStmtAttr

#define IBP_SQLSTATE__HY109__ODBC__INVALID_CURSOR_POSITION \
 "HY109"

//------------------------------------------------------------------------

//MSDN: Invalid driver completion
//       SQLDriverConnect

#define IBP_SQLSTATE__HY110__ODBC__INVALID_DRIVER_COMPLETION \
 "HY110"

//------------------------------------------------------------------------

//MSDN: Invalid bookmark value
//       SQLExtendedFetch
//       SQLFetchScroll

#define IBP_SQLSTATE__HY111__ODBC__INVALID_BOOKMARK_VALUE \
 "HY111"

//------------------------------------------------------------------------

//MSDN: Optional feature not implemented
//       SQLBindCol                SQLFetchScroll             SQLProcedures
//       SQLBindParameter          SQLForeignKeys             SQLSetConnectAttr
//       SQLBulkOperations         SQLGetConnectAttr          SQLSetEnvAttr
//       SQLColAttribute           SQLGetData                 SQLSetPos
//       SQLColumnPrivileges       SQLGetEnvAttr              SQLSetStmtAttr
//       SQLColumns                SQLGetInfo                 SQLSpecialColumns
//       SQLDriverConnect          SQLGetStmtAttr             SQLStatistics
//       SQLEndTran                SQLGetTypeInfo             SQLTablePrivileges
//       SQLExecDirect             SQLParamData               SQLTables
//       SQLExecute                SQLPrepare
//       SQLExtendedFetch          SQLPrimaryKeys
//       SQLFetch                  SQLProcedureColumns

#define IBP_SQLSTATE__HYC00__ODBC__OPTIONAL_FEATURE_NOT_IMPLEMENTED \
 "HYC00"

//------------------------------------------------------------------------

//MSDN: Timeout expired
//       SQLBrowseConnect         SQLExtendedFetch        SQLSetPos
//       SQLBulkOperations        SQLForeignKeys          SQLSpecialColumns
//       SQLColumnPrivileges      SQLGetTypeInfo          SQLStatistics
//       SQLColumns               SQLParamData            SQLTablePrivileges
//       SQLConnect               SQLPrepare              SQLTables
//       SQLDriverConnect         SQLPrimaryKeys
//       SQLExecDirect            SQLProcedureColumns
//       SQLExecute               SQLProcedures

#define IBP_SQLSTATE__HYT00__ODBC__TIMEOUT_EXPIRED \
 "HYT00"

//------------------------------------------------------------------------

//MSDN: Connection timeout expired
//       All ODBC functions except:
//        SQLDrivers
//        SQLDataSources
//        SQLGetEnvAttr
//        SQLSetEnvAttr

#define IBP_SQLSTATE__HYT01__ODBC__CONNECTION_TIMEOUT_EXPIRED \
 "HYT01"

////////////////////////////////////////////////////////////////////////////////

#define IBP_SQLSTATE__HZ000__REMOTE_DATABASE_ACCESS_NO_SUBCLASS \
 "HZ000"

////////////////////////////////////////////////////////////////////////////////

//MSDN: Driver does not support this function
//       All ODBC functions except:
//        SQLAllocHandle
//        SQLDataSources
//        SQLDrivers
//        SQLFreeHandle
//        SQLGetFunctions

#define IBP_SQLSTATE__IM001__ODBC__DRIVER_DOES_NOT_SUPPORT_THIS_FUNCTION \
 "IM001"

//------------------------------------------------------------------------

//MSDN: Data source name not found and no default driver specified
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM002__ODBC__DATA_SOURCE_NAME_NOT_FOUND_AND_NO_DEFAULT_DRIVER_SPECIFIED \
 "IM002"

//------------------------------------------------------------------------

//MSDN: Specified driver could not be loaded
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM003__ODBC__SPECIFIED_DRIVER_COULD_NOT_BE_LOADED \
 "IM003"

//------------------------------------------------------------------------

//MSDN: Driver's SQLAllocHandle on SQL_HANDLE_ENV failed
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM004__ODBC__DRIVER_SQLALLOCHANDLE_ON_SQL_HANDLE_ENV_FAILED \
 "IM004"

//------------------------------------------------------------------------

//MSDN: Driver's SQLAllocHandle on SQL_HANDLE_DBC failed
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM005__ODBC__DRIVER_SQLALLOCHANDLE_ON_SQL_HANDLE_DBC_FAILED \
 "IM005"

//------------------------------------------------------------------------

//MSDN: Driver's SQLSetConnectAttr failed
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM006__ODBC__DRIVER_SQLSETCONNECTATTR_FAILED \
 "IM006"

//------------------------------------------------------------------------

//MSDN: No data source or driver specified; dialog prohibited
//       SQLDriverConnect

#define IBP_SQLSTATE__IM007__ODBC__NO_DATA_SOURCE_OR_DRIVER_SPECIFIED_DIALOG_PROHIBITED \
 "IM007"

//------------------------------------------------------------------------

//MSDN: Dialog failed
//       SQLDriverConnect

#define IBP_SQLSTATE__IM008__ODBC__DIALOG_FAILED \
 "IM008"

//------------------------------------------------------------------------

//MSDN: Unable to load translation DLL
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect
//       SQLSetConnectAttr

#define IBP_SQLSTATE__IM009__ODBC__UNABLE_TO_LOAD_TRANSLATION_DLL \
 "IM009"

//------------------------------------------------------------------------

//MSDN: Data source name too long
//       SQLBrowseConnect
//       SQLConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM010__ODBC__DATA_SOURCE_NAME_TOO_LONG \
 "IM010"

//------------------------------------------------------------------------

//MSDN: Driver name too long
//       SQLBrowseConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM011__ODBC__DRIVER_NAME_TOO_LONG \
 "IM011"

//------------------------------------------------------------------------

//MSDN: DRIVER keyword syntax error
//       SQLBrowseConnect
//       SQLDriverConnect

#define IBP_SQLSTATE__IM012__ODBC__DRIVER_KEYWORD_SYNTAX_ERROR \
 "IM012"

//------------------------------------------------------------------------

//MSDN: Trace file error
//       All ODBC functions.

#define IBP_SQLSTATE__IM013__ODBC__TRACE_FILE_ERROR \
 "IM013"

//------------------------------------------------------------------------

//MSDN: Invalid name of File DSN
//       SQLDriverConnect

#define IBP_SQLSTATE__IM014__ODBC__INVALID_NAME_OF_FILE_DSN \
 "IM014"

//------------------------------------------------------------------------

//MSDN: Corrupt file data source
//       SQLDriverConnect

#define IBP_SQLSTATE__IM015__ODBC__CORRUPT_FILE_DATA_SOURCE \
 "IM015"

////////////////////////////////////////////////////////////////////////////////
//Class XX Ч Internal Error

#define IBP_SQLSTATE__XX000__INTERNAL_ERROR \
 "XX000"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__XX001__DATA_CORRUPTED \
 "XX001"

//------------------------------------------------------------------------

#define IBP_SQLSTATE__XX002__INDEX_CORRUPTED \
 "XX002"

////////////////////////////////////////////////////////////////////////////////
//Firebird

#define IBP_SQLSTATE__01101__FIREBIRD__ONGOING_TRANSACTION_HAS_BEEN_COMMITTED \
 "01101"

//------------------------------------------------------------------------
#define IBP_SQLSTATE__01102__FIREBIRD__ONGOING_TRANSACTION_HAS_BEEN_ROLLED_BACK \
 "01102"

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
#endif
