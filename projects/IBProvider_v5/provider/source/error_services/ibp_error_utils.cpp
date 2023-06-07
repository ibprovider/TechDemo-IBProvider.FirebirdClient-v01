////////////////////////////////////////////////////////////////////////////////
//! \ingroup ibp_err
//! \file    ibp_error_utils.cpp
//! \brief   ��������� ������� ��� ������ � �������� IBProvider'a
//! \author  Kovalenko Dmitry
//! \date    22.02.2007
#include <_pch_.h>
#pragma hdrstop

#include "source/error_services/ibp_error_utils.h"
//#include "source/error_services/ibp_error.h"
#include "source/error_services/ibp_error__com_module_is_shutdown.h"

#include "source/error_services/ibp_sqlstate_codes.h"
#include "source/error_services/ibp_custom_error_object__sql.h"

#include <win32lib/win32_error.h>

#include <structure/utilities/string/string_is_null_or_empty.h>

namespace lcpi{namespace ibp{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup ibp_err
//! @{
////////////////////////////////////////////////////////////////////////////////
//��������� ���������� "����������� ���������������� ���������� � Free ������ IBProvider'�"

#if(IBP_EDITION_ID==IBP_EDITION_ID__FREE)

void IBP_ThrowFeaturesNotAvailableInFreeEdition(const wchar_t* const FeatureName) //throw
{
 t_ibp_error exc(DB_E_NOTSUPPORTED,
                 ibp_mce_fe_features_not_available_in_free_edition_1);

 exc<<FeatureName;

 exc.raise_me();
}//IBP_ThrowFeaturesNotAvailableInFreeEdition

//------------------------------------------------------------------------
void IBP_ThrowFreeVersionCanNotWorkWithThisServer
                  (structure::str_parameter const ServerName,
                   structure::str_parameter const ServerVersion,
                   structure::str_parameter const OriginalServerID) //throw

{
 t_ibp_error exc(DB_E_NOTSUPPORTED,
                 ibp_mce_fe_free_edition_not_support_this_server_3);

 exc<<ServerName<<ServerVersion<<OriginalServerID;

 exc.raise_me();
}//IBP_ThrowFreeVersionCanNotWorkWithThisServer

#endif // IBP_EDITION_ID==IBP_EDITION_ID__FREE

////////////////////////////////////////////////////////////////////////////////
//����������� ������������� �� ���������� ���� ������

//! \ingroup ibp_err
/// <summary>
///  ������������ ����� ������ ��-���� ���������� "����������"
/// </summary>
static const HRESULT g_IBP_HRESULT_TerriblePriority[]=
{
 E_UNEXPECTED,
 E_OUTOFMEMORY,
 E_FAIL,
 DB_E_ERRORSOCCURRED,
 DB_S_ERRORSOCCURRED
};//g_IBP_HRESULT_TerriblePriority

//------------------------------------------------------------------------
/// <summary>
///  ������� ����������� ������������� "��-����������" ���� ������
/// </summary>
//! \param[in] hr1
//! \param[in] hr2
//! \return
//!  hr1 ��� hr2, � ����������� �� "����"
HRESULT IBP_GetMaxByTerribleHRESULT(HRESULT const hr1,
                                    HRESULT const hr2)
{
 ///���� hr1==S_OK, �� ������������ hr2
 if(hr1==S_OK)
  return hr2;

 ///���� hr2==S_OK, �� ������������ hr1
 if(hr2==S_OK)
  return hr1;

 ///��� ������ ������������ ����� g_IBP_HRESULT_TerriblePriority
 const HRESULT* const p1=std::find(g_IBP_HRESULT_TerriblePriority,
                                   _END_(g_IBP_HRESULT_TerriblePriority),
                                   hr1);

 const HRESULT* const p2=std::find(g_IBP_HRESULT_TerriblePriority,
                                   _END_(g_IBP_HRESULT_TerriblePriority),
                                   hr2);

 return (p1<p2)?hr1:hr2;
}//IBP_GetMaxByTerribleHRESULT

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������������� NUMERIC � ������� ��� �������.
/// </summary>
//! \param[in] hr
//! \param[in] baseTypeName
void IBP_ThrowErr__save_numeric_as_native_type
                        (HRESULT         const hr,
                         const  wchar_t* const baseTypeName)
{
 assert(FAILED(hr));

 IBP_ErrorUtils::Throw__Error
  (hr,
   ibp_mce_dbobj_fail_save_numeric_as_native_type_1,
   baseTypeName);
}//IBP_ThrowErr__save_numeric_as_native_type

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� ��� ������ "��������������� �������������� �� ��������������"
/// </summary>
void IBP_ThrowIntegratedAuthIsNotSupported(t_ibp_subsystem_id         const subsystem_id,
                                           structure::t_const_str_box const db_client_name,
                                           structure::t_const_str_box const db_client_version)
{
 IBP_ErrorUtils::Throw__ErrorWithCustomErrorObject
  (DB_SEC_E_AUTH_FAILED,
   subsystem_id,
   ibp_mce_ds__integrated_auth_not_supported_2,
   IBP_CreateCustomErrorFor_AuthFailed(),
   db_client_name,
   db_client_version);
}//IBP_ThrowIntegratedAuthIsNotSupported

//------------------------------------------------------------------------
/// <summary>
///  ��������� ���������� ��� ������ "����������� ��� ������� ��������������� ��������������"
/// </summary>
void IBP_ThrowUnknownNameOfIntegratedAuth(t_ibp_subsystem_id const subsystem_id,
                                          t_ibp_str_box      const authName)
{
 IBP_ErrorUtils::Throw__ErrorWithCustomErrorObject
  (DB_SEC_E_AUTH_FAILED,
   subsystem_id,
   ibp_mce_ds__unk_integrated_auth_service_name_1,
   IBP_CreateCustomErrorFor_AuthFailed(),
   authName);
}//IBP_ThrowUnknownNameOfIntegratedAuth

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� ��� ������ ������������� �������� �������������,
///  ����������������� ������� �������� ������� ��.
/// </summary>
void IBP_ThrowInitPropCantPassIntoDBClient(t_ibp_subsystem_id         const subsystem_id,
                                           const wchar_t*             const prop_name,
                                           structure::t_const_str_box const db_client_name,
                                           structure::t_const_str_box const db_client_version)
{
 IBP_ErrorUtils::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_ds__db_client_not_supports_init_prop_3,
   prop_name,
   db_client_name,
   db_client_version);
}//IBP_ThrowInitParamCantPassIntoDBClient

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ����������. �������� �������� ������������� �� ��������������
///  ������� �������� ������� ��.
/// </summary>
void IBP_ThrowInitPropCantProcessCurrentDBClient_I4
                                          (t_ibp_subsystem_id         const subsystem_id,
                                           const wchar_t*             const prop_name,
                                           structure::t_const_str_box const db_client_name,
                                           structure::t_const_str_box const db_client_version,
                                           LONG                       const prop_value)
{
 IBP_ErrorUtils::Throw__Error
  (DB_E_NOTSUPPORTED,
   subsystem_id,
   ibp_mce_ds__db_client_cant_process_init_prop_value_4,
   prop_name,
   db_client_name,
   db_client_version,
   prop_value);
}//IBP_ThrowInitPropCantProcessCurrentDBClient_I4

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowCantConvertCnPropToUTF8(t_ibp_subsystem_id const subsystem_id,
                                      const wchar_t*     const prop_name)
{
 assert(!structure::string_is_null_or_empty(prop_name));

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_common__failed_to_convert_cn_param_to_utf8_1,
   prop_name);
}//IBP_ThrowCantConvertCnPropToUTF8

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ������ "BUG-CHECK"
/// </summary>
//! \param[in] place
//!  ������������
//! \param[in] point
//!  ����� ��������
//! \param[in] reason
//!  �������� ������� ����
//! \param[in] hr
//!  ��� ������
void IBP_ThrowBugCheck(const wchar_t* const place,
                       const wchar_t* const point,
                       const wchar_t* const reason,
                       HRESULT        const hr)
{
 assert(place);
 assert(point);
 assert(reason);
 assert(FAILED(hr));

 IBP_ErrorUtils::Throw__Error
  (hr,
   ibp_mce_common__bug_check_3,
   place,
   point,
   reason);
}//IBP_ThrowBugCheck

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ���������� "BUG-CHECK" ������ � ��������� � ��������� ����������
/// </summary>
//! \param[in,out] Errors
//! \param[in] place
//!  ������������
//! \param[in] point
//!  ����� ��������
//! \param[in] reason
//!  �������� ������� ����
//! \param[in] hr
//!  ��� ������
void IBP_ThrowBugCheck2(t_ibp_error&         Errors,
                        const wchar_t* const place,
                        const wchar_t* const point,
                        const wchar_t* const reason,
                        HRESULT        const hr)
{
 assert(place);
 assert(point);
 assert(reason);
 assert(FAILED(hr));

 t_ibp_error_element::self_ptr
  spErrRec
   (structure::not_null_ptr
     (new t_ibp_error_element
           (hr,
            ibp_mce_common__bug_check_3)));

 assert(spErrRec);

 (*spErrRec)<<place
            <<point
            <<reason;

 Errors.add_error(spErrRec); //throw

 Errors.set_last_error_as_primary();

 Errors.raise_me(hr);
}//IBP_ThrowBugCheck2

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowCantTranslateSysDataToUnicode(const wchar_t* const pSysDataName)
{
 assert(pSysDataName);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_common__translate_sys_data_to_unicode_1,
   pSysDataName);
}//IBP_ThrowCantTranslateSysDataToUnicode

//------------------------------------------------------------------------
void IBP_ThrowCantTranslateSysDataFromUnicode(const wchar_t* const pSysDataName)
{
 assert(pSysDataName);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   ibp_mce_common__translate_sys_data_from_unicode_1,
   pSysDataName);
}//IBP_ThrowCantTranslateSysDataFromUnicode

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowErr__FailedToMakeUpperStr(const wchar_t* const sourceSign,
                                        size_t         const sourceLength,
                                        size_t         const processedLength)
{
 assert(sourceSign);
 assert(sourceLength<=processedLength);

 t_ibp_error exc(E_FAIL,ibp_mce_common__failed_to_make_upper_str_3);

 exc<<sourceSign
    <<sourceLength
    <<processedLength;

 exc.raise_me();
}//IBP_ThrowErr__FailedToMakeUpperStr

//------------------------------------------------------------------------
void IBP_ThrowErr__FailedToMakeLowerStr(const wchar_t* const sourceSign,
                                        size_t         const sourceLength,
                                        size_t         const processedLength)
{
 assert(sourceSign);
 assert(sourceLength<=processedLength);

 t_ibp_error exc(E_FAIL,ibp_mce_common__failed_to_make_lower_str_3);

 exc<<sourceSign
    <<sourceLength
    <<processedLength;

 exc.raise_me();
}//IBP_ThrowErr__FailedToMakeLowerStr

////////////////////////////////////////////////////////////////////////////////

t_string IBP_ExtractErrorMessage(const std::exception& exc,
                                 const LCID            lcid)
{
 if(const structure::t_err_records_r* const x=dynamic_cast<const structure::t_err_records_r*>(&exc))
 {
  if(x->get_record_count()!=0)
  {
   const structure::t_err_record::self_cptr err(x->get_record(0));

   assert(err);

   std::wstring wdescr;

   if(err->get_description(lcid,nullptr,&wdescr))
    return structure::tstr_to_tstr(wdescr);
  }//if
 }//if

 return structure::tstr_to_tstr(exc.what());
}//IBP_ExtractErrorMessage

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowOverflowArrayTotalElementCount_v2(t_ibp_wstr_box const ArrayRelationName,
                                                t_ibp_wstr_box const ArrayFieldName)
{
 t_ibp_error exc(E_FAIL,ibp_mce_array__calc_total_element_count__overflow_2);

 exc<<ArrayRelationName<<ArrayFieldName;

 exc.raise_me();
}//IBP_ThrowOverflowArrayTotalElementCount_v2

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� � �������� ��������� ��� ����������
/// </summary>
//! \param[in] err_code
//!  ��� ������
//! \param[in] msg_code_0
//!  ������������� ������� ���������
void IBP_ThrowSimpleError(HRESULT           const err_code,
                          ibp_msg_code_type const msg_code_0)
{
 t_ibp_error exc(err_code,msg_code_0);

 exc.raise_me();
}//IBP_ThrowSimpleError

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� � �������� ��������� ��� ����������
/// </summary>
//! \param[in] err_code
//!  ��� ������
//! \param[in] msg_code_0
//!  ������������� ������� ���������
//! \param[in] pGetCErr
void IBP_ThrowSimpleError(HRESULT                        const err_code,
                          ibp_msg_code_type              const msg_code_0,
                          t_ibp_get_custom_error_object* const pGetCErr)
{
 t_ibp_error exc(err_code,
                 msg_code_0,
                 pGetCErr);

 exc.raise_me();
}//IBP_ThrowSimpleError

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� � �������� ��������� ��� ����������
/// </summary>
//! \param[in] err_code
//!  ��� ������
//! \param[in] subsystem_id
//!  ������������� ����������
//! \param[in] msg_code_0
//!  ������������� ������� ���������
void IBP_ThrowSimpleError(HRESULT            const err_code,
                          t_ibp_subsystem_id const subsystem_id,
                          ibp_msg_code_type  const msg_code_0)
{
 t_ibp_error exc(err_code,
                 subsystem_id,
                 msg_code_0);

 exc.raise_me();
}//IBP_ThrowSimpleError

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� � �������������� ���������� ���������� ������������ �������.
/// </summary>
//! \param[in] err_code
//! \param[in] msg_code_0
void IBP_ThrowSimpleError_safe(HRESULT           const err_code,
                               ibp_msg_code_type const msg_code_0)
{
 ///��������� ���������, ������� ��������� ��������� ���������� "out of memory".

 t_ibp_error exc(err_code); //no throw

 exc.add_error__no_throw(err_code,msg_code_0); //no throw

 exc.raise_me();
}//IBP_ThrowSimpleError_safe

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowErrorWithDetail_safe(HRESULT           const hr,
                                   ibp_msg_code_type const primaryErrMsgID_1,
                                   ibp_msg_code_type const detailErrMsgID_0)
{
 assert(FAILED(hr));

 t_ibp_error exc(hr);

 try
 {
  const t_ibp_error_element::self_ptr
   spErrRec
    (structure::not_null_ptr
      (new t_ibp_error_element
        (hr,
         primaryErrMsgID_1)));

  (*spErrRec)<<detailErrMsgID_0;

  exc.add_error(spErrRec);
 }
 catch(...)
 {;}

 exc.raise_me();
}//IBP_ThrowErrorWithDetail_safe

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowOverflowInMemSizeCalculation(const wchar_t* const place,
                                           const wchar_t* const point)
{
 assert(place);
 assert(point);

 t_ibp_error exc(E_FAIL,ibp_mce_common__overflow_in_mem_size_calculation_2);

 exc<<place<<point;

 exc.raise_me();
}//IBP_ThrowOverflowInMemSizeCalculation

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "�������� ���� ��������"
/// </summary>
void IBP_ThrowOperationWasCancelled()
{
 IBP_ThrowSimpleError(DB_E_CANCELED,ibp_mce_operation_was_canceled_0);
}//IBP_ThrowOperationWasCancelled

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "�������� ������ �� ���������������"
/// </summary>
void IBP_ThrowDataSourceNotInited()
{
 IBP_ThrowSimpleError(E_FAIL,ibp_mce_data_source_is_not_inited_0);
}//IBP_ThrowDataSourceNotInited

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "��������� ������������� ��������� ������"
/// </summary>
void IBP_ThrowDataSourceAlreadyInitialized()
{
 IBP_ThrowSimpleError(DB_E_ALREADYINITIALIZED,ibp_mce_data_source_already_inited_0);
}//IBP_ThrowDataSourceAlreadyInitialized

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "�������� ������ �������� ��������������� �������� �������"
/// </summary>
//! \param[in] n
void IBP_ThrowDataSourceHasChildObjects(size_t const n)
{
 t_ibp_error exc(DB_E_OBJECTOPEN,ibp_mce_data_source_has_child_objects_1);

 exc<<n;

 exc.raise_me();
}//IBP_ThrowDataSourceHasChildObjects

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "��� �������� ����������". ����������� ���������� �������.
/// </summary>
void IBP_ThrowNoTransaction_safe()
{
 ///��������� ���������, ������� ��������� ��������� ���������� "out of memory".
 IBP_ThrowSimpleError_safe(XACT_E_NOTRANSACTION,ibp_mce_ibtrans__no_started_0);
}//IBP_ThrowNoTransaction_safe

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "���������� ��� ��������� � �������� ���������".
/// </summary>
void IBP_ThrowTransactionAlreadyStarted()
{
 IBP_ThrowSimpleError(XACT_E_XTIONEXISTS,ibp_mce_ibtrans__already_started_0);
}//IBP_ThrowTransactionAlreadyStarted

////////////////////////////////////////////////////////////////////////////////

/// <summary
///  ��������� ���������� "������������ ����� ������ ����������"
/// </summary>
//! \param[in] TrLevelNumber
//! \param[in] cTrLevels
void IBP_ThrowBadTrNodeNumber(ULONG  TrLevelNumber,
                              size_t cTrLevels)
{
 assert(TrLevelNumber>0);
 assert(cTrLevels<TrLevelNumber);

 t_ibp_error exc(E_FAIL,ibp_mce_ibtrans__bad_node_number_2);

 exc<<TrLevelNumber<<cTrLevels;

 exc.raise_me();//throw
}//IBP_ThrowBadTrNodeNumber

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������������ ����� �������".
/// </summary>
void IBP_ThrowCmdIncorrectText()
{
 IBP_ThrowSimpleError(DB_E_ERRORSINCOMMAND,ibp_mce_cmd_incorrect_text_0);
}//IBP_ThrowCmdIncorrectText

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������� �� ������� ����������"
/// </summary>
void IBP_ThrowCmdExecParamsNotRequired()
{
 IBP_ThrowSimpleError(E_FAIL,ibp_mce_cmd_exec_params_not_required_0);
}//IBP_ThrowCmdExecParamsNotRequired

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� ������ �������� �������� ��������������� �������� �������
/// </summary>
//! \param[in] subsystemID
//! \param[in] propSign
//!  �������� ��� ��������������� ��������
void IBP_ThrowCmdError__GetStmtInfo_NoData(t_ibp_subsystem_id const subsystemID,
                                           const wchar_t*     const propSign)
{
 t_ibp_error exc(E_FAIL,
                 subsystemID,
                 ibp_mce_cmd__get_stmt_info__no_data_1);

 exc<<propSign;

 exc.raise_me();
}//IBP_ThrowCmdError__GetStmtInfo_NoData

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������ BLOB ������. ������ ��������� ���������� ������� ���������."
/// </summary>
void IBP_ThrowWriteBlobError__CantQueryStorageObjectInterface
                             (HRESULT        const hr,
                              const wchar_t* const pwszInterfaceName)
{
 assert(FAILED(hr));
 assert(pwszInterfaceName!=nullptr);

 t_ibp_error exc(hr,ibp_mce_bw__fail_query_storage_interface_1);

 exc<<pwszInterfaceName;

 exc.raise_me();
}//IBP_ThrowWriteBlobError__CantQueryStorageObjectInterface

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������ BLOB ������. ����������� ��������� ������� ���������."
/// </summary>
//! \param[in] riid
//!  ���� ��������� ������������� ��������� � ��������� �������
void IBP_ThrowWriteBlobError__UnknownStorageObjectInterface(REFIID riid)
{
 t_ibp_error exc(DB_E_NOTSUPPORTED,ibp_mce_bw__unknown_storage_interface_1);

 exc<<riid;

 exc.raise_me();
}//IBP_ThrowWriteBlobError__UnknownStorageObjectInterface

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������ BLOB ������. ������ ��������� �� ���������
///  ���������� �������������� �����������."
/// </summary>
void IBP_ThrowWriteBlobError__StorageObjectWithUnsupportedInterfaces()
{
 IBP_ThrowSimpleError(DB_E_NOTSUPPORTED,ibp_mce_bw__storage_not_support_known_interfaces_0);
}//IBP_ThrowWriteBlobError__StorageObjectWithUnsupportedInterfaces

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������ BLOB ������. ��������� ��������� � ���������������� ������� �������."
/// </summary>
void IBP_ThrowReadBlobError__WrongStorageAccessFlags(DWORD const dwFlags)
{
 t_ibp_error exc(E_FAIL,ibp_mce_br__unk_storage_access_flags_1);

 exc<<dwFlags;

 exc.raise_me();
}//IBP_ThrowReadBlobError__WrongStorageAccessFlags

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������ BLOB ������. ��������� ��������� � ���������������� �����������."
/// </summary>
void IBP_ThrowReadBlobError__UnknownStorageObjectInterface(REFIID riid)
{
 t_ibp_error exc(E_FAIL,ibp_mce_br__unk_storage_interface_1);

 exc<<riid;

 exc.raise_me();
}//IBP_ThrowReadBlobError__UnknownStorageObjectInterface

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  ��������� ���������� "������ ��� ��������� ������ �������".
/// </summary>
//! \param[in] check_place
//!  Not null.
//! \param[in] check_point
//!  Not null.
void IBP_ThrowIscStatusVectorProcessingError(const wchar_t* const check_place,
                                             const wchar_t* const check_point)
{
 assert(check_place!=nullptr);
 assert(check_point!=nullptr);

 t_ibp_error exc(E_FAIL,ibp_mce_isc__status_vector_processing_error_2);

 exc<<check_place
    <<check_point;

 exc.raise_me();
}//IBP_ThrowStatusVectorProcessingError

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowErr_FormedParamBufIsTooLarge(t_ibp_subsystem_id          const subsystemID,
                                           structure::t_const_wstr_box const ucs2BufName,
                                           size_t                      const bufSize,
                                           size_t                      const maxSize)
{
 assert(maxSize<bufSize);

 t_ibp_error exc(E_FAIL,
                 subsystemID,
                 ibp_mce_common__formed_param_buf_is_too_large_3);

 exc<<ucs2BufName
    <<bufSize
    <<maxSize;

 exc.raise_me();
}//IBP_ThrowErr_FormedParamBufIsTooLarge

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowArrayBlobErr__BugCheck__unexpected_dim_count
       (const wchar_t* const place,
        const wchar_t* const point,
        size_t         const actualDimCount,
        size_t         const expectedDimCount)
{
 assert(place);
 assert(point);
 assert(actualDimCount!=expectedDimCount);

 //ERROR - ��������� ����������� � �������� � ������ �������

 t_ibp_error exc(E_FAIL,
                 ibp_mce_array_blob__bug_check__unexpected_dim_count_4);

 exc<<place
    <<point
    <<actualDimCount
    <<expectedDimCount;

 exc.raise_me();
}//IBP_ThrowArrayBlobErr__BugCheck__unexpected_dim_count

//------------------------------------------------------------------------
void IBP_ThrowArrayBlobErr__BugCheck__incorrect_range_of_dim
       (const wchar_t* const place,
        const wchar_t* const point,
        size_t         const iDim,
        long           const actualLowerBound,
        long           const actualUpperBound,
        long           const defLowerBound,
        long           const defUpperBound)
{
 assert(place);
 assert(point);

 t_ibp_error exc(E_FAIL,
                 ibp_mce_array_blob__bug_check__incorrect_range_of_dim_7);

 exc<<place
    <<point
    <<iDim
    <<actualLowerBound
    <<actualUpperBound
    <<defLowerBound
    <<defUpperBound;

 exc.raise_me();
}//IBP_ThrowArrayBlobErr__BugCheck__incorrect_range_of_dim

//------------------------------------------------------------------------
void IBP_ThrowArrayBlobErr__BugCheck__unexpected_element_size
       (const wchar_t* const place,
        const wchar_t* const point,
        const wchar_t* const typeName,
        size_t         const actualSize,
        size_t         const expectedSize)
{
 assert(place);
 assert(point);
 assert(typeName);
 assert(actualSize!=expectedSize);

 //ERROR - ������������ ������ �������� �������

 t_ibp_error exc(E_FAIL,
                 ibp_mce_array_blob__bug_check__unexpected_size_of_element_5);

 exc<<place
    <<point
    <<typeName
    <<actualSize
    <<expectedSize;

 exc.raise_me();
}//IBP_ThrowArrayBlobErr__BugCheck__unexpected_element_size

//------------------------------------------------------------------------
void IBP_ThrowArrayBlobErr__BugCheck__incorrect_element_size
       (const wchar_t* const place,
        const wchar_t* const point,
        const wchar_t* const typeName,
        size_t         const actualSize)
{
 assert(place);
 assert(point);
 assert(typeName);

 //ERROR - ������������ ������ �������� �������

 t_ibp_error exc(E_FAIL,
                 ibp_mce_array_blob__bug_check__incorrect_element_size_4);

 exc<<place
    <<point
    <<typeName
    <<actualSize;

 exc.raise_me();
}//IBP_ThrowArrayBlobErr__BugCheck__unexpected_element_size

//------------------------------------------------------------------------
void IBP_ThrowArrayBlobErr__BugCheck__incorrect_element_scale
       (const wchar_t* const place,
        const wchar_t* const point,
        const wchar_t* const typeName,
        short          const elementScale)
{
 assert(place);
 assert(point);
 assert(typeName);

 //ERROR - ������������ ������� �����

 t_ibp_error exc(E_FAIL,
                 ibp_mce_array_blob__bug_check__incorrect_scale_4);

 exc<<place
    <<point
    <<typeName
    <<elementScale;

 exc.raise_me();
}//IBP_ThrowArrayBlobErr__BugCheck__unexpected_element_size

//------------------------------------------------------------------------
void IBP_ThrowArrayBlobErr__BugCheck__incorrect_length_of_string_element
       (const wchar_t*              const place,
        const wchar_t*              const point,
        const wchar_t*              const typeName,
        size_t                      const length,
        structure::t_const_wstr_box const charsetName,
        size_t                      const bytesPerChar)
{
 assert(place);
 assert(point);
 assert(typeName);
 assert(bytesPerChar>0);

 //ERROR - ��������������� ������� ��������� ������ � ������� �������.

 t_ibp_error
  exc(E_FAIL,
      ibp_mce_array_blob__bug_check__incorrect_length_of_string_element_6);

 exc<<place
    <<point
    <<typeName
    <<length
    <<charsetName
    <<bytesPerChar;

 exc.raise_me();
}//IBP_ThrowArrayBlobErr__BugCheck__incorrect_length_of_string_element

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  �������� ������� Custom-������ ��� �������� ���� �����������.
/// </summary>
//! \return
//!  Not null.
//!
//! \note
//!  ��������������, ��� ������������ ������ ����� �������������� ��� ������������
//!  ����������� ������ IBProvider.
//!
//!  SQLSTATE ����� ��������� ��� 08006, lNativeError - ��� E_FAIL.
lib::structure::t_smart_object_ptr<t_ibp_get_custom_error_object>
 IBP_CreateCustomErrorFor_CnFailed()
{
 return t_ibp_custom_error_object__sql::create
         (IBP_SQLSTATE__08006__CONNECTION_EXCEPTION_CONNECTION_FAILURE,
          E_FAIL);
}//IBP_CreateCustomErrorFor_CnFailed

////////////////////////////////////////////////////////////////////////////////

/// <summary>
///  �������� ������� Custom-������ ��� �������� ���� ��������������.
/// </summary>
//! \return
//!  Not null.
//!
//! \note
//!  ��������������, ��� ������������ ������ ����� �������������� ��� ������������
//!  ����������� ������ IBProvider.
//!
//!  SQLSTATE ����� ��������� ��� 28000, lNativeError - ��� DB_SEC_E_AUTH_FAILED.
lib::structure::t_smart_object_ptr<t_ibp_get_custom_error_object>
 IBP_CreateCustomErrorFor_AuthFailed()
{
 return t_ibp_custom_error_object__sql::create
         (IBP_SQLSTATE__28000__INVALID_AUTHORIZATION_SPECIFICATION_NO_SUBCLASS,
          DB_SEC_E_AUTH_FAILED);
}//IBP_CreateCustomErrorFor_AuthFailed

////////////////////////////////////////////////////////////////////////////////

void IBP_ThrowFileError(ibp_msg_code_type const     msg_1,
                        structure::t_const_wstr_box wFileName)
{
 t_ibp_error exc(HRESULT_FROM_WIN32(::GetLastError()),msg_1);

 exc<<wFileName;

 exc.raise_me();
}//Helper__ThrowFileError

////////////////////////////////////////////////////////////////////////////////
//class IBP_ErrorUtils

void IBP_ErrorUtils::RethrowModuleShutdownError()
{
 try
 {
  throw;
 }
 catch(const t_ibp_error__com_module_is_shutdown&)
 {
  throw;
 }
 catch(...)
 {
  //��� �����-�� ������ ������
 }
}//RethrowModuleShutdownError

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms ibp*/}/*nms lcpi*/
