////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_utils.h
//! \brief   ��������� ������� ��� ������ � �������� IBProvider'a
//! \author  Kovalenko Dmitry
//! \date    22.02.2007
#ifndef _ibp_error_utils_H_
#define _ibp_error_utils_H_

#if(COMP_CONF_SUPPORT_PRAGMA_ONCE)
# pragma once
#endif

#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_get_custom_error_object.h"

#include "source/ibp_subsystem_ids.h"
#include "source/ibp_char.h"
#include "source/ibp_forward.h"

#include <ole_lib/oledb/oledb_common.h>
//#include <structure/error/t_err_record.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
using structure::t_err_record;
using structure::t_string;
////////////////////////////////////////////////////////////////////////////////
//��������� ���������� "���������������� ���������� � ���������� ������ IBProvider'�"

#if(IBP_EDITION_ID==IBP_EDITION_ID__FREE)

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowFeaturesNotAvailableInFreeEdition(const wchar_t* FeatureName); //throw

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowFreeVersionCanNotWorkWithThisServer
                  (structure::str_parameter ServerName,
                   structure::str_parameter ServerVersion,
                   structure::str_parameter OriginalServerID); //throw

#endif // IBP_EDITION_ID==IBP_EDITION_ID__FREE

////////////////////////////////////////////////////////////////////////////////
//����������� ���������� �� HRESULT

inline HRESULT IBP_MapExceptionToHRESULT(const std::exception* const exc)
{
 return ole_lib::OLE_MapExceptionToHRESULT(exc);
}//IBP_MapExceptionToHRESULT

//------------------------------------------------------------------------
inline HRESULT IBP_MapErrorRecordToHRESULT(const t_err_record* const err_record)
{
 return ole_lib::OLE_MapErrorRecordToHRESULT(err_record);
}//IBP_MapErrorRecordToHRESULT

//------------------------------------------------------------------------
inline HRESULT IBP_MapCurrentExceptionToHRESULT()
{
 return ole_lib::OLE_MapCurrentExceptionToHRESULT();
}//IBP_MapCurrentExceptionToHRESULT

////////////////////////////////////////////////////////////////////////////////
//����������� ���������� �� DBSTATUS

inline DBSTATUS IBP_MapExceptionToDBSTATUS(const std::exception* const exc)
{
 return oledb_lib::MapDBErrorToDBStatus(IBP_MapExceptionToHRESULT(exc));
}//IBP_MapExceptionToDBSTATUS

////////////////////////////////////////////////////////////////////////////////
//����������� ������������� �� ���������� ���� ������

HRESULT IBP_GetMaxByTerribleHRESULT(HRESULT hr1,HRESULT hr2);

////////////////////////////////////////////////////////////////////////////////
//��������� ���������� ������ ���������������

LCPI_CPP_CFG__DECLSPEC__NORETURN
void IBP_ThrowConvertError
       (HRESULT           error_code,
        DBTYPE            wSourceType,
        DBTYPE            wDestType);//throw

LCPI_CPP_CFG__DECLSPEC__NORETURN
void IBP_ReThrowConvertErrorWithCorrectedHResult
       (const std::exception& innerException,
        DBTYPE                wSourceType,
        DBTYPE                wDestType);//throw

LCPI_CPP_CFG__DECLSPEC__NORETURN
void IBP_ReThrowConvertErrorWithCorrectedHResult
       (const std::exception&            innerException,
        lib::structure::t_const_wstr_box sourceTypeSign,
        lib::structure::t_const_wstr_box destTypeSign);//throw

LCPI_CPP_CFG__DECLSPEC__NORETURN
void IBP_ThrowErr__save_numeric_as_native_type
       (HRESULT        hr,
        const wchar_t* baseTypeName);

////////////////////////////////////////////////////////////////////////////////
//��������� ������ "��������������� �������������� �� ��������������"

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowIntegratedAuthIsNotSupported
       (t_ibp_subsystem_id         subsystem_id,
        structure::t_const_str_box db_client_name,
        structure::t_const_str_box db_client_version);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowUnknownNameOfIntegratedAuth
       (t_ibp_subsystem_id subsystem_id,
        t_ibp_str_box      authName);

////////////////////////////////////////////////////////////////////////////////
//��������� ���������� ��� ������ ������������� �������� �������������,
//����������������� ������� �������� ��.

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowInitPropCantPassIntoDBClient
       (t_ibp_subsystem_id          subsystem_id,
        const wchar_t*              prop_name,
        structure::t_const_str_box  db_client_name,
        structure::t_const_str_box  db_client_version);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowInitPropCantProcessCurrentDBClient_I4
       (t_ibp_subsystem_id          subsystem_id,
        const wchar_t*              prop_name,
        structure::t_const_str_box  db_client_name,
        structure::t_const_str_box  db_client_version,
        LONG                        prop_value);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowCantConvertCnPropToUTF8
       (t_ibp_subsystem_id  subsystem_id,
        const wchar_t*      prop_name);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowBugCheck
       (const wchar_t* place,
        const wchar_t* point,
        const wchar_t* reason,
        HRESULT        hr=E_FAIL);

//------------------------------------------------------------------------
#define IBP_BUG_CHECK__DEBUG(place,                  \
                             point,                  \
                             reason)                 \
{                                                    \
 assert_msg(false,structure::tstr_to_str(reason));   \
                                                     \
 ibp::IBP_ThrowBugCheck(place,point,reason);         \
}

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowBugCheck2
       (t_ibp_error&   Errors,
        const wchar_t* place,
        const wchar_t* point,
        const wchar_t* reason,
        HRESULT        hr=E_FAIL);

//------------------------------------------------------------------------
#define IBP_BUG_CHECK2__DEBUG(Errors,                        \
                              place,                         \
                              point,                         \
                              reason)                        \
{                                                            \
 assert_msg(false,structure::tstr_to_str(reason));           \
                                                             \
 ibp::IBP_ThrowBugCheck2(Errors,place,point,reason);         \
}

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowCantTranslateSysDataToUnicode(const wchar_t* pSysDataName);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowCantTranslateSysDataFromUnicode
  (t_ibp_wstr_box sysDataName,
   t_ibp_wstr_box targetCsName);

////////////////////////////////////////////////////////////////////////////////

template<typename DstCharT>
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowCantTranslateSysData(const wchar_t* pSysDataName);

template<>
LCPI_CPP_CFG__DECLSPEC__NORETURN
inline
 void IBP_ThrowCantTranslateSysData<wchar_t>(const wchar_t* const pSysDataName)
 {
  IBP_ThrowCantTranslateSysDataToUnicode(pSysDataName);
 }//IBP_ThrowCantTranslateSysData<char,wchar_t>

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowErr__FailedToMakeUpperStr
       (const wchar_t* sourceSign,
        size_t         sourceLength,
        size_t         processedLength);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowErr__FailedToMakeLowerStr
       (const wchar_t* sourceSign,
        size_t         sourceLength,
        size_t         processedLength);

////////////////////////////////////////////////////////////////////////////////

template<typename TextIterator>
LCPI_CPP_CFG__DECLSPEC__NORETURN
void IBP_ThrowErrorSymbolInCommandText
      (TextIterator beg,
       TextIterator cur_pos);

////////////////////////////////////////////////////////////////////////////////

t_string IBP_ExtractErrorMessage(const std::exception& exc,
                                 LCID                  lcid);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowOverflowArrayTotalElementCount_v2
       (t_ibp_wstr_box ArrayRelationName,
        t_ibp_wstr_box ArrayFieldName);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowSimpleError
       (HRESULT           err_code,
        ibp_msg_code_type msg_code_0);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowSimpleError
       (HRESULT                        err_code,
        ibp_msg_code_type              msg_code_0,
        t_ibp_get_custom_error_object* pGetCErr);

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowSimpleError
       (HRESULT            err_code,
        t_ibp_subsystem_id subsystem_id,
        ibp_msg_code_type  msg_code_0);

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowSimpleError_safe
       (HRESULT           err_code,
        ibp_msg_code_type msg_code_0);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowErrorWithDetail_safe
       (HRESULT           hr,
        ibp_msg_code_type primaryErrMsgID_1,
        ibp_msg_code_type detailErrMsgID_0);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowOverflowInMemSizeCalculation
       (const wchar_t* place,
        const wchar_t* point);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowOperationWasCancelled();

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowDataSourceNotInited();

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowDataSourceAlreadyInitialized();

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowDataSourceHasChildObjects(size_t n);

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowNoTransaction_safe();

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowTransactionAlreadyStarted();

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowBadTrNodeNumber
       (ULONG  TrLevelNumber,
        size_t cTrLevels);

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowCmdIncorrectText();

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowCmdExecParamsNotRequired();

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowCmdError__GetStmtInfo_NoData
       (t_ibp_subsystem_id subsystemID,
        const wchar_t*     propSign);

//------------------------------------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowWriteBlobError__CantQueryStorageObjectInterface
       (HRESULT        hr,
        const wchar_t* pwszInterfaceName);

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowWriteBlobError__UnknownStorageObjectInterface(REFIID riid);

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowWriteBlobError__StorageObjectWithUnsupportedInterfaces();

//------------------------------------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowReadBlobError__WrongStorageAccessFlags(DWORD dwFlags);

//------------------------------------------
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowReadBlobError__UnknownStorageObjectInterface(REFIID riid);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowIscStatusVectorProcessingError
       (const wchar_t* check_place,
        const wchar_t* check_point);

////////////////////////////////////////////////////////////////////////////////

template<class T>
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowIscErr_BugCheck_BadSqlLenOfXVar
       (const wchar_t* sqlTypeSign,
        T              sqllen);

//------------------------------------------
template<class T>
LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowIscErr_BugCheck_BadSqlLenOfXVar
       (t_ibp_subsystem_id subsystem_id,
        const wchar_t*     sqlTypeSign,
        T                  sqllen);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowErr_FormedParamBufIsTooLarge
       (t_ibp_subsystem_id           subsystemID,
        structure::t_const_wstr_box  ucs2BufName,
        size_t                       bufSize,
        size_t                       maxSize);

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowArrayBlobErr__BugCheck__unexpected_dim_count
       (const wchar_t* place,
        const wchar_t* point,
        size_t         actualDimCount,
        size_t         expectedDimCount);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowArrayBlobErr__BugCheck__incorrect_range_of_dim
       (const wchar_t* place,
        const wchar_t* point,
        size_t         iDim,
        long           actualLowerBound,
        long           actualUpperBound,
        long           defLowerBound,
        long           defUpperBound);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowArrayBlobErr__BugCheck__unexpected_element_size
       (const wchar_t* place,
        const wchar_t* point,
        const wchar_t* typeName,
        size_t         actualSize,
        size_t         expectedSize);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowArrayBlobErr__BugCheck__incorrect_element_size
       (const wchar_t* place,
        const wchar_t* point,
        const wchar_t* typeName,
        size_t         actualSize);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowArrayBlobErr__BugCheck__incorrect_element_scale
       (const wchar_t* place,
        const wchar_t* point,
        const wchar_t* typeName,
        short          elementScale);

LCPI_CPP_CFG__DECLSPEC__NORETURN
 void IBP_ThrowArrayBlobErr__BugCheck__incorrect_length_of_string_element
       (const wchar_t*              place,
        const wchar_t*              point,
        const wchar_t*              typeName,
        size_t                      length,
        structure::t_const_wstr_box charsetName,
        size_t                      bytesPerChar);

////////////////////////////////////////////////////////////////////////////////

lib::structure::t_smart_object_ptr<t_ibp_get_custom_error_object>
 IBP_CreateCustomErrorFor_CnFailed();

lib::structure::t_smart_object_ptr<t_ibp_get_custom_error_object>
 IBP_CreateCustomErrorFor_AuthFailed();

////////////////////////////////////////////////////////////////////////////////

LCPI_CPP_CFG__DECLSPEC__NORETURN
void IBP_ThrowFileError(ibp_msg_code_type const     msg_1,
                        structure::t_const_wstr_box wFileName);

////////////////////////////////////////////////////////////////////////////////
//class IBP_ErrorUtils

class IBP_ErrorUtils LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  typedef IBP_ErrorUtils      self_type;

 public:
  /// <summary>
  ///  ������� �������� ����������, ���� ��� ����������� ������ shutdown-������ ������.
  /// </summary>
  static void RethrowModuleShutdownError();

 public:
  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (HRESULT hr);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (const std::exception& e,
                HRESULT               hr,
                ibp_msg_code_type     msg_code,
                Args&&...             args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (HRESULT            hr,
                ibp_msg_code_type  msg_code,
                Args&&...          args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (const std::exception& e,
                HRESULT               hr,
                t_ibp_subsystem_id    subsystem_id,
                ibp_msg_code_type     msg_code,
                Args&&...             args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (HRESULT            hr,
                t_ibp_subsystem_id subsystem_id,
                ibp_msg_code_type  msg_code,
                Args&&...          args);

 private:
  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (HRESULT                         hr,
                ibp_msg_code_type               msg_code,
                t_ibp_error::get_cerr_obj_type* pGetCErr,
                Args&&...                       args)=delete;

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (HRESULT                         hr,
                t_ibp_subsystem_id              subsystem_id,
                ibp_msg_code_type               msg_code,
                t_ibp_error::get_cerr_obj_type* pGetCErr,
                Args&&...                       args)=delete;

 public:
  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__ErrorWithCustomErrorObject
               (HRESULT                         hr,
                ibp_msg_code_type               msg_code,
                t_ibp_error::get_cerr_obj_type* pGetCErr,
                Args&&...                       args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__ErrorWithCustomErrorObject
               (HRESULT                         hr,
                t_ibp_subsystem_id              subsystem_id,
                ibp_msg_code_type               msg_code,
                t_ibp_error::get_cerr_obj_type* pGetCErr,
                Args&&...                       args);

 public:
  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ReThrowWithSameHResult
               (const std::exception& e,
                ibp_msg_code_type     msg_code,
                Args&&...             args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ReThrowWithSameHResult
               (const std::exception& e,
                t_ibp_subsystem_id    subsystem_id,
                ibp_msg_code_type     msg_code,
                Args&&...             args);

 public:
  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ReThrowWithNewHResult
               (const std::exception& e,
                HRESULT               hr,
                ibp_msg_code_type     msg_code,
                Args&&...             args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ReThrowWithNewHResult
               (const std::exception& e,
                HRESULT               hr,
                t_ibp_subsystem_id    subsystem_id,
                ibp_msg_code_type     msg_code,
                Args&&...             args);

 public:
  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__BugCheck__DEBUG
               (const std::exception& e,
                const wchar_t*        place,
                const wchar_t*        point,
                const wchar_t*        reason_template,
                Args&&...             args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__BugCheck__DEBUG
               (const wchar_t*  place,
                const wchar_t*  point,
                const wchar_t*  reason_template,
                Args&&...       args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__BugCheck
               (const wchar_t*  place,
                const wchar_t*  point,
                const wchar_t*  reason_template,
                Args&&...       args);

 private:
  template<typename Container,typename Arg1,typename... Args>
  static void Helper__PushArgs
               (Container& container,
                Arg1&&     arg1,
                Args&&...  args);

  template<typename Container>
  static void Helper__PushArgs
               (Container& container);
};//class IBP_ErrorUtils

////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
////////////////////////////////////////////////////////////////////////////////
#include "source/error_services/ibp_error_utils.cc"
////////////////////////////////////////////////////////////////////////////////
#endif
