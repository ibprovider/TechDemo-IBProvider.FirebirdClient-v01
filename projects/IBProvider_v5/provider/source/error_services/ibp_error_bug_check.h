////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_bug_check.h
//! \brief   Конструкции для обработки внутренних ошибок
//! \author  Kovalenko Dmitry
//! \date    18.01.2009
#ifndef _ibp_error_bug_check_H_
#define _ibp_error_bug_check_H_

#include "source/error_services/ibp_error_utils.h"
#include "source/db_obj/db_types.h"

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_WrongCmdParamCount
      (const wchar_t* place,
       const wchar_t* point,
       size_t         param_count,
       size_t         req_count);

//------------------------------------------------------------------------
/// <summary>
///  BUG CHECK. Макрос для проверки количества параметров, определенных сервером
/// </summary>
#define IBP_BUG_CHECK__CHECK_CMD_PARAM_COUNT(place,                       \
                                             point,                       \
                                             row,                         \
                                             req_count)                   \
{                                                                         \
 assert(row);                                                             \
                                                                          \
 assert_msg(row->sqld()==(req_count),                                     \
            "param_count="<<row->sqld()<<". req_count:"<<(req_count));    \
                                                                          \
 if(row->sqld()!=(req_count))                                             \
 {                                                                        \
  ibp::IBP_ThrowBugCheck_WrongCmdParamCount                               \
   (place,                                                                \
    point,                                                                \
    row->sqld(),                                                          \
    (req_count));                                                         \
 }                                                                        \
}

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_WrongResultSetColumnCount
      (const wchar_t* place,
       const wchar_t* point,
       size_t         column_count,
       size_t         req_count);

//------------------------------------------------------------------------
/// <summary>
///  BUG CHECK. Макрос для проверки количества колонок результирующего множества
/// </summary>
#define IBP_BUG_CHECK__CHECK_RESULTSET_COLUMN_COUNT(place,                \
                                                    point,                \
                                                    row,                  \
                                                    req_count)            \
{                                                                         \
 assert(row);                                                             \
                                                                          \
 assert_msg(row->sqld()==(req_count),                                     \
            "column_count="<<row->sqld()<<". req_count:"<<(req_count));   \
                                                                          \
 if(row->sqld()!=(req_count))                                             \
 {                                                                        \
  ibp::IBP_ThrowBugCheck_WrongResultSetColumnCount                        \
   (place,                                                                \
    point,                                                                \
    row->sqld(),                                                          \
    (req_count));                                                         \
 }                                                                        \
}

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_BadObject
      (const wchar_t* place,
       const wchar_t* point,
       const wchar_t* object_name);

//------------------------------------------------------------------------
/// <summary>
///  BUG CHECK. Макрос для проверки указателя на объект
/// </summary>
#define IBP_BUG_CHECK__DETECT_BAD_OBJECT_NULL_PTR(object,                 \
                                                  place,                  \
                                                  point)                  \
{                                                                         \
 if(object==NULL)                                                         \
 {                                                                        \
  assert(false);                                                          \
                                                                          \
  ibp::IBP_ThrowBugCheck_BadObject                                        \
   (place,                                                                \
    point,                                                                \
    IBP_MAKE_UNICODE_TEXT(#object));                                      \
 }                                                                        \
}

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_Bad_SQLD_SQLN
      (const wchar_t* place,
       const wchar_t* point,
       const wchar_t* fields_name,
       size_t         sqld,
       size_t         sqln);

//------------------------------------------------------------------------
/// <summary>
///  BUG CHECK. Макрос для проверки состояния SQLD и SQLN набора колонок
/// </summary>
#define IBP_BUG_CHECK__DETECT_BAD_SQLD_SQLN(place,                        \
                                            point,                        \
                                            fields)                       \
{                                                                         \
 assert(fields);                                                          \
                                                                          \
 if(fields->sqln()<fields->sqld())                                        \
 {                                                                        \
  assert_msg(false,                                                       \
             "check "<<#fields<<". "                                      \
             "sqld="<<fields->sqld()<<". "                                \
             "sqln="<<fields->sqln());                                    \
                                                                          \
  ibp::IBP_ThrowBugCheck_Bad_SQLD_SQLN                                    \
   (place,                                                                \
    point,                                                                \
    IBP_MAKE_UNICODE_TEXT(#fields),                                       \
    fields->sqld(),                                                       \
    fields->sqln());                                                      \
 }                                                                        \
}

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__OpCtxHasWrongTransaction
      (const wchar_t* place,
       const wchar_t* point);

#define IBP_BUG_CHECK__DETECT_WRONG_OP_CTX_TRANS(op_ctx,                  \
                                                 trans,                   \
                                                 place,                   \
                                                 point)                   \
{                                                                         \
 const db_obj::t_db_transaction_ptr                                            \
  op_ctx_trans                                                                 \
   (db_obj::query_db_service__if_it_exists<db_obj::t_db_transaction>(op_ctx)); \
                                                                               \
 if(op_ctx_trans!=trans)                                                  \
 {                                                                        \
  assert_msg(false,"op_ctx has wrong transaction");                       \
                                                                          \
  ibp::IBP_ThrowBugCheck__OpCtxHasWrongTransaction(place,point);          \
 }                                                                        \
}

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__CnPropNotDefined
      (const wchar_t* place,
       const wchar_t* point,
       const wchar_t* cnPropName);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__UnexpectedPropValueType
      (const wchar_t* place,
       const wchar_t* point,
       const wchar_t* prop_name,
       VARTYPE        varType);

////////////////////////////////////////////////////////////////////////////////

template<typename T>
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__UnexpectedPropValue
      (const wchar_t* place,
       const wchar_t* point,
       const wchar_t* prop_name,
       const T&       value);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_UnknownDBTimeRules
      (const wchar_t* place,
       const wchar_t* point,
       long           rules);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_UnknownDBTimeStampRules
      (const wchar_t* place,
       const wchar_t* point,
       long           rules);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_UnknownDBDateRules
      (const wchar_t* place,
       const wchar_t* point,
       long           rules);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_UnknownSqlParserScope
      (const wchar_t*              place,
       const wchar_t*              point,
       structure::t_const_wstr_box scope);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_UnexpectedOLEDBType
      (const wchar_t* place,
       const wchar_t* point,
       DBTYPE         wType);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd
      (const wchar_t* place,
       const wchar_t* point);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_InfoBuf__UnknownTag
      (const wchar_t* place,
       const wchar_t* point,
       long           tagID);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
      (const wchar_t* place,
       const wchar_t* point,
       long           tagID);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
      (const wchar_t* place,
       const wchar_t* point,
       const wchar_t* tagSign);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_InfoBuf__MultDefOfElement
      (const wchar_t* place,
       const wchar_t* point,
       long           tagID);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
      (const wchar_t* place,
       const wchar_t* point,
       long           tagID,
       size_t         actualLength,
       size_t         maxLength);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement
      (const wchar_t* place,
       const wchar_t* point,
       const wchar_t* tagSign,
       size_t         actualLength,
       size_t         maxLength);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_SvcNotSupported
      (t_ibp_subsystem_id subsystemID,
       REFGUID            serviceID,
       const char*        serviceTypeName);

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck_SvcNotImplReqInterface
      (t_ibp_subsystem_id subsystemID,
       REFGUID            serviceID,
       const char*        interfaceName);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__IncorrectArrayElementSize
      (const wchar_t*              place,
       const wchar_t*              point,
       structure::t_const_wstr_box tableName,
       structure::t_const_wstr_box columnName,
       const wchar_t*              elementTypeName,
       unsigned                    elementSize);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__StmtIsNotSelectable
      (const wchar_t*              place,
       const wchar_t*              point,
       structure::t_const_wstr_box stmtText);

////////////////////////////////////////////////////////////////////////////////

template<typename TLength>
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__IncorrectDataLength
      (const wchar_t*              place,
       const wchar_t*              point,
       TLength                     length);

////////////////////////////////////////////////////////////////////////////////

template<typename TLength,typename TBufSize>
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__TooLargeDataLength
      (const wchar_t*              place,
       const wchar_t*              point,
       TLength                     length,
       TBufSize                    bufSize);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__IncorrectWorkOfGetTempFileName
      (const wchar_t*                                 place,
       const wchar_t*                                 point,
       const structure::t_basic_const_str_box<TCHAR>& tempPath);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__UnexpectedDBVariantCompareResult
      (const wchar_t* place,
       const wchar_t* point,
       int            compare_result);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__UnexpectedDbStatus
      (const wchar_t* place,
       const wchar_t* point,
       int            dbstatus);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__CantReadValueOfFieldWithUnexpectedStatus
      (const wchar_t*              place,
       const wchar_t*              point,
       size_t                      field_index,
       structure::t_const_wstr_box field_name,
       db_obj::t_dbstatus          dbstatus);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__CantTestNullStateOdFieldValueWithUnexpectedStatus
      (const wchar_t*              place,
       const wchar_t*              point,
       size_t                      field_index,
       structure::t_const_wstr_box field_name,
       db_obj::t_dbstatus          dbstatus);

////////////////////////////////////////////////////////////////////////////////

COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__UnexpectedConnectionDialect
      (const wchar_t*              place,
       const wchar_t*              point,
       long                        dialect);

//------------------------------------------------------------------------
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__UnexpectedDatabaseDialect
      (const wchar_t*              place,
       const wchar_t*              point,
       long                        dialect);

//------------------------------------------------------------------------
COMP_CONF_DECLSPEC_NORETURN
void IBP_ThrowBugCheck__DatabaseDialectNotDefined
      (const wchar_t*              place,
       const wchar_t*              point);

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/error_services/ibp_error_bug_check.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
