////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_bug_check.cpp
//! \brief   ����������� ��� ��������� ���������� ������
//! \author  Kovalenko Dmitry
//! \date    18.01.2009
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_bug_check.h"
#include "source/error_services/ibp_error.h"
//#include "source/error_services/ibp_error_messages.h"
#include "source/ibp_utils.h"

#include <ole_lib/ole_auto/ole_auto_variant_type_info.h>
#include <structure/t_str_formatter.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp
//! @{
////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck_WrongCmdParamCount(const wchar_t* const place,
                                          const wchar_t* const point,
                                          size_t         const param_count,
                                          size_t         const req_count)
{
 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   L"Described a wrong number of command parameters [%1]. Requred [%2]",
   param_count,
   req_count);
}//IBP_ThrowBugCheck_WrongCmdParamCount

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck_WrongResultSetColumnCount(const wchar_t* const place,
                                                 const wchar_t* const point,
                                                 size_t         const column_count,
                                                 size_t         const req_count)
{
 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   L"Received wrong number of resultset columns [%1]. Requred [%2]",
   column_count,
   req_count);
}//IBP_ThrowBugCheck_WrongResultSetColumnCount

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck_BadObject(const wchar_t* const place,
                                 const wchar_t* const point,
                                 const wchar_t* const object_name)
{
 assert(place);
 assert(point);
 assert(object_name);

 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   L"bad object [%1]",
   object_name);
}//IBP_ThrowBugCheck_BadObject

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck_Bad_SQLD_SQLN(const wchar_t* const place,
                                     const wchar_t* const point,
                                     const wchar_t* const fields_name,
                                     size_t         const sqld,
                                     size_t         const sqln)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   L"Bad state of %1. SQLD: %2. SQLN: %3",
   fields_name,
   sqld,
   sqln);
}//IBP_ThrowBugCheck_Bad_SQLD_SQLN

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__OpCtxHasWrongTransaction(const wchar_t* const place,
                                                 const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck
  (place,
   point,
   L"wrong transaction in operation context");
}//IBP_ThrowBugCheck__OpCtxHasWrongTransaction

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__CnPropNotDefined(const wchar_t* const place,
                                         const wchar_t* const point,
                                         const wchar_t* const cnPropName)
{
 assert(place);
 assert(point);
 assert(cnPropName);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__prop__not_defined_1,
   cnPropName);
}//IBP_ThrowBugCheck__CnPropNotDefined

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__UnexpectedPropValueType(const wchar_t* const place,
                                                const wchar_t* const point,
                                                const wchar_t* const prop_name,
                                                VARTYPE        const varType)
{
 assert(place);
 assert(point);
 assert(prop_name);

 structure::wstr_formatter
  freason(me_bug_check__prop__unexpected_value_type_2);

 freason<<prop_name;

 if(const ole_lib::TVariantTypeInfo* const x=ole_lib::GetVariantTypeInfo(varType))
  freason<<x->name;
 else
  freason<<const_cast<const unsigned short&>(varType); //check expected type

 IBP_BUG_CHECK__DEBUG
  (place,
   point,
   freason.c_str());
}//IBP_ThrowBugCheck__UnexpectedPropValueType

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck_UnknownDBTimeRules(const wchar_t* const place,
                                          const wchar_t* const point,
                                          long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"dbtime_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownDBTimeRules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownDBTimeStampRules(const wchar_t* const place,
                                               const wchar_t* const point,
                                               long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"dbtimestamp_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownDBTimeStampRules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownDBDateRules(const wchar_t* const place,
                                          const wchar_t* const point,
                                          long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"dbdate_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownDBDateRules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownDBTimeStampWithTzRules
                                         (const wchar_t* const place,
                                          const wchar_t* const point,
                                          long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"dbtimestamp_with_tz_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownDBTimeStampWithTzRules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownDBTimeWithTzRules
                                         (const wchar_t* const place,
                                          const wchar_t* const point,
                                          long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"dbtime_with_tz_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownDBTimeWithTzRules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownInt128Rules(const wchar_t* const place,
                                          const wchar_t* const point,
                                          long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"int128_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownInt128Rules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownDecFloat16Rules(const wchar_t* const place,
                                              const wchar_t* const point,
                                              long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"decfloat16_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownDecFloat16Rules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownDecFloat34Rules(const wchar_t* const place,
                                              const wchar_t* const point,
                                              long           const rules)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"decfloat34_rules",
   rules);
}//IBP_ThrowBugCheck_UnknownDecFloat34Rules

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_UnknownSqlParserScope(const wchar_t*              const place,
                                             const wchar_t*              const point,
                                             structure::t_const_wstr_box const scope)
{
 assert(place);
 assert(point);

 IBP_ThrowBugCheck__UnexpectedPropValue
  (place,
   point,
   L"sql_parser__scope",
   scope);
}//IBP_ThrowBugCheck_UnknownSqlParserScope

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
void IBP_ThrowBugCheck_FailedToTranslateDbNumericIntoWStr
            (const wchar_t* const place,
             const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   L"failed to translate DbNumeric into WStr");
}//IBP_ThrowBugCheck_FailedToTranslateDbNumericIntoWStr

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd(const wchar_t* const place,
                                              const wchar_t* const point)
{
 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unexpected_end_of_buffer_0);
}//IBP_ThrowBugCheck_InfoBuf__UnexpectedEnd

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_InfoBuf__UnknownTag(const wchar_t* const place,
                                           const wchar_t* const point,
                                           long           const tagID)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unk_element_in_info_buffer_1,
   tagID);
}//IBP_ThrowBugCheck_UnknownTagInInfoBuffer

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
                                          (const wchar_t* const place,
                                           const wchar_t* const point,
                                           long           const tagID)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__incorrect_format_of_element_1,
   tagID);
}//IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement
                                          (const wchar_t* const place,
                                           const wchar_t* const point,
                                           const wchar_t* const tagSign)
{
 assert(place);
 assert(point);
 assert(tagSign);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__incorrect_format_of_element_1,
   tagSign);
}//IBP_ThrowBugCheck_InfoBuf__IncorrectFormatOfElement

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_InfoBuf__MultDefOfElement(const wchar_t* const place,
                                                 const wchar_t* const point,
                                                 long           const tagID)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__mult_def_of_element_in_info_buf_1,
   tagID);
}//IBP_ThrowBugCheck_InfoBuf__MultDefOfElement

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement(const wchar_t* const place,
                                                      const wchar_t* const point,
                                                      long           const tagID,
                                                      size_t         const actualLength,
                                                      size_t         const maxLength)
{
 assert(place);
 assert(point);
 assert(maxLength<actualLength);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__size_of_result_data_larger_than_buf_size_3,
   tagID,
   actualLength,
   maxLength);
}//IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement(const wchar_t* const place,
                                                      const wchar_t* const point,
                                                      const wchar_t* const tagSign,
                                                      size_t         const actualLength,
                                                      size_t         const maxLength)
{
 assert(place);
 assert(point);
 assert(tagSign);
 assert(maxLength<actualLength);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__size_of_result_data_larger_than_buf_size_3,
   tagSign,
   actualLength,
   maxLength);
}//IBP_ThrowBugCheck_InfoBuf__TooLargeSizeOfElement

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck_SvcNotSupported(t_ibp_subsystem_id subsystemID,
                                       REFGUID            serviceID,
                                       const char* const  serviceTypeName)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystemID,
   ibp_mce_common__bug_check__svc_not_supported_2,
   serviceID,
   serviceTypeName);
}//Throw_BugCheck_SvcNotSupported

//------------------------------------------------------------------------
void IBP_ThrowBugCheck_SvcNotImplReqInterface(t_ibp_subsystem_id subsystemID,
                                              REFGUID            serviceID,
                                              const char* const  interfaceName)
{
 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystemID,
   ibp_mce_common__bug_check__svc_not_support_req_interface_2,
   serviceID,
   interfaceName);
}//Throw_BugCheck_SvcNotImplReqInterface

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__IncorrectArrayElementSize
                                           (const wchar_t*              const place,
                                            const wchar_t*              const point,
                                            structure::t_const_wstr_box const tableName,
                                            structure::t_const_wstr_box const columnName,
                                            const wchar_t*              const elementTypeName,
                                            unsigned                    const elementSize)
{
 assert(place);
 assert(point);
 assert(elementTypeName);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_array__bug_check__incorrect_array_element_size_6,
   place,
   point,
   tableName,
   columnName,
   elementTypeName,
   elementSize);
}//IBP_ThrowBugCheck__IncorrectArrayElementSize

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__StmtIsNotSelectable(const wchar_t*              const place,
                                            const wchar_t*              const point,
                                            structure::t_const_wstr_box const stmtText)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_cmd__bug_check__stmt_is_not_selectable_3,
   place,
   point,
   IBP_Utils::GetStmtSign(stmtText));
}//IBP_ThrowBugCheck__StmtIsNotSelectable

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__IncorrectWorkOfGetTempFileName
      (const wchar_t*                         const   place,
       const wchar_t*                         const   point,
       const structure::t_basic_const_str_box<TCHAR>& tempPath)
{
 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__win32_err__incorrect_work_of_GetTempFileName_1,
   tempPath);
}//IBP_ThrowBugCheck__IncorrectWorkOfGetTempFileName

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__UnexpectedDBVariantCompareResult
      (const wchar_t* const place,
       const wchar_t* const point,
       int            const compare_result)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unexpected_dbvariant_compare_result_1,
   compare_result);
}//IBP_ThrowBugCheck__UnexpectedDBVariantCompareResult

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__UnexpectedDbStatus
      (const wchar_t* const place,
       const wchar_t* const point,
       int            const dbstatus)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   L"unexpected dbstatus [%1]",
   dbstatus);
}//IBP_ThrowBugCheck__UnexpectedDbStatus

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__CantReadValueOfFieldWithUnexpectedStatus
      (const wchar_t*              const place,
       const wchar_t*              const point,
       size_t                      const field_index,
       structure::t_const_wstr_box const field_name,
       db_obj::t_dbstatus          const dbstatus)
{
 assert(place);
 assert(point);

 assert_msg
  (false,
   "field_index: "<<field_index<<". "
   "field_name: "<<structure::tstr_to_str(field_name)<<". "
   "dbstatus: "<<int(dbstatus));

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_common__bug_check__cant_read_field_value_with_unexpected_status_5,
   place,
   point,
   field_name,
   field_index,
   db_obj::get_dbstatus2_name(dbstatus));
}//IBP_ThrowBugCheck__CantReadValueOfFieldWithUnexpectedStatus

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__CantTestNullStateOdFieldValueWithUnexpectedStatus
      (const wchar_t*              const place,
       const wchar_t*              const point,
       size_t                      const field_index,
       structure::t_const_wstr_box const field_name,
       db_obj::t_dbstatus          const dbstatus)
{
 assert(place);
 assert(point);

 assert_msg
  (false,
   "field_index: "<<field_index<<". "
   "field_name: "<<structure::tstr_to_str(field_name)<<". "
   "dbstatus: "<<int(dbstatus));

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_common__bug_check__cant_test_null_state_of_field_value_with_unexpected_status_5,
   place,
   point,
   field_name,
   field_index,
   db_obj::get_dbstatus2_name(dbstatus));
}//IBP_ThrowBugCheck__CantTestNullStateOdFieldValueWithUnexpectedStatus

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowBugCheck__UnexpectedConnectionDialect
      (const wchar_t* const place,
       const wchar_t* const point,
       long           const dialect)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unexpected_connection_dialect_1,
   dialect);
}//IBP_ThrowBugCheck__UnexpectedConnectionDialect

//------------------------------------------------------------------------
void IBP_ThrowBugCheck__UnexpectedDatabaseDialect
      (const wchar_t* const place,
       const wchar_t* const point,
       long           const dialect)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__unexpected_database_dialect_1,
   dialect);
}//IBP_ThrowBugCheck__UnexpectedDatabaseDialect

//------------------------------------------------------------------------
void IBP_ThrowBugCheck__DatabaseDialectNotDefined
      (const wchar_t* const place,
       const wchar_t* const point)
{
 assert(place);
 assert(point);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   me_bug_check__database_dialect_not_defined_0);
}//IBP_ThrowBugCheck__DatabaseDialectNotDefined

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
