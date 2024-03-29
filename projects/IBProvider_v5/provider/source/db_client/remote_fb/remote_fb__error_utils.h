////////////////////////////////////////////////////////////////////////////////
//! \ingroup db_client__remote_fb
//! \file    remote_fb__error_utils.h
//! \brief   ����� ������ ��� ��������� ������.
//! \author  Kovalenko Dmitry
//! \date    15.02.2015.
#ifndef _remote_fb__error_utils_H_
#define _remote_fb__error_utils_H_

#include "source/db_client/remote_fb/protocol/remote_fb__protocol.h"
#include "source/db_client/remote_fb/remote_fb__forward.h"
#include "source/error_services/ibp_error_utils.h"

namespace lcpi{namespace ibp{namespace db_client{namespace remote_fb{
////////////////////////////////////////////////////////////////////////////////
//! \addtogroup db_client__remote_fb
//! @{
////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ErrorUtils

/// <summary>
///  ����� ������ ��� ��������� ������.
/// </summary>
class RemoteFB__ErrorUtils LCPI_CPP_CFG__CLASS__FINAL
{
 private:
  using self_type=RemoteFB__ErrorUtils;

 public: //typedefs ------------------------------------------------------
  using subsystem_id_type=ibp::t_ibp_subsystem_id;

  /// ��� ��� ������������� �������������� �������� � ��������
  using p_operation_id_type=int;

  using wstr_box_type=lib::structure::t_const_wstr_box;

 public:
  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__BugCheck__DEBUG
               (const wchar_t*  place,
                const wchar_t*  point,
                const wchar_t*  reason_template,
                Args&&...       args);

  template<typename... Args>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__Error
               (HRESULT            hr,
                t_ibp_subsystem_id subsystem_id,
                ibp_msg_code_type  msg_code,
                Args&&...          args);

 public:
  /// <summary>
  ///  ��������� ���������� - ������������� �������� ����������� �� ��������������.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolID
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__RequestedProtocolNotSupported
               (subsystem_id_type  subsystem_id,
                wstr_box_type      protocolID);

 public:
  /// <summary>
  ///  ��������� ���������� - ����������� ��� ��������� �����������.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolVersionNum
  //!  Protocol version number.
  //! \param[in] protocolTypeID
  //!  Protocol type identifier.
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__UnsupportedProtocolTypeID
               (subsystem_id_type  subsystem_id,
                unsigned           protocolVersionNum,
                unsigned           protocolTypeID);

  /// <summary>
  ///  ��������� ���������� - ������������� ��� ��������� ����������� �� ��������������.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolVersionNum
  //!  Protocol version number.
  //! \param[in] protocolTypeSign
  //!  Protocol type identifier.
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__ReqProtocolTypeIdDoesNotSupported
               (subsystem_id_type  subsystem_id,
                unsigned           protocolVersionNum,
                wstr_box_type      protocolTypeSign);

  /// <summary>
  ///  ��������� ���������� - ����������� ����� ��������� �����������.
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] protocolVerNum
  //!  Protocol version number.
  //! \param[in] protocolFlags
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__UnsupportedProtocolFlags
               (subsystem_id_type  subsystem_id,
                unsigned           protocolVerNum,
                unsigned           protocolFlags);

 public:
  /// <summary>
  ///  ��������� ���������� - ������ �������� ���������� �����������
  /// </summary>
  //! \param[in] subsystem_id
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__ServerRejectedConnectionCompression
               (subsystem_id_type  subsystem_id);

  /// <summary>
  ///  ��������� ���������� - ������ ������� ���������� �����������
  /// </summary>
  //! \param[in] subsystem_id
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__ServerRequiredConnectionCompression
               (subsystem_id_type  subsystem_id);

  /// <summary>
  ///  ��������� ���������� - ���������������� ��� ������ ������
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] typeName
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__UnsupportedWireCompressionType
               (subsystem_id_type  subsystem_id,
                wstr_box_type      typeName);

 public:
  /// <summary>
  ///  ��������� ���������� - ������ ��������� ������ ������� ��������
  /// </summary>
  //! \param[in] subsystem_id
  //! \param[in] operationID
  //!  ������������� �������� � ��������.
  //! \param[in] place
  //! \param[in] point
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__OpStatusVectorProcessingError
               (subsystem_id_type   subsystem_id,
                p_operation_id_type operationID,
                const wchar_t*      place,
                const wchar_t*      point);

 public:
  /// <summary>
  ///  ��������� ���������� - [BUG CHECK] ������������ ��������� ������.
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] actualProtocolSetID
  //! \param[in] expectedProtocolSetID
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_UnexpectedPacketStructure
               (const wchar_t*            place,
                const wchar_t*            point,
                protocol::PROTOCOL_SET_ID actualProtocolSetID,
                protocol::PROTOCOL_SET_ID expectedProtocolSetID);

  /// <summary>
  ///  ��������� ���������� - [BUG CHECK] ������ ��������� ����������� ������ ���������.
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] protocolVersion
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_AcceptedUnexpectedProtocolVersion
               (const wchar_t*               place,
                const wchar_t*               point,
                protocol::P_PROTOCOL_VERSION protocolVersion);

  /// <summary>
  ///  ��������� ���������� - [BUG CHECK] ������ ��������� ����������� ����������� ���������.
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] protocolArchitecture
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_AcceptedUnexpectedProtocolArchitecture
               (const wchar_t*    place,
                const wchar_t*    point,
                protocol::P_ARCH  protocolArchitecture);

 public:
  /// <summary>
  ///  ��������� ���������� - [BUG CHECK] ����������� ����� �������
  /// </summary>
  //! \param[in] pPort
  //! \param[in] place
  //! \param[in] point
  //! \param[in] answerID
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void SetInvalidPortState_And_Throw_BugCheck_UnexpectedServerAnswer
               (RemoteFB__Port*     pPort,
                const wchar_t*      place,
                const wchar_t*      point,
                p_operation_id_type answerID);

  /// <summary>
  ///  ��������� ���������� - [BUG CHECK] ����������� ����� �������
  /// </summary>
  //! \param[in] Errors
  //!  ��������� ����� ������������ ������
  //! \param[in] pPort
  //! \param[in] place
  //! \param[in] point
  //! \param[in] answerID
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void SetInvalidPortState_And_Throw_BugCheck2_UnexpectedServerAnswer
               (t_ibp_error&        Errors,
                RemoteFB__Port*     pPort,
                const wchar_t*      place,
                const wchar_t*      point,
                p_operation_id_type answerID);

  /// <summary>
  ///  ��������� ���������� - [BUG CHECK] ����������� ������ ���������
  /// </summary>
  //! \param[in] place
  //! \param[in] point
  //! \param[in] protocolVersion
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_UnexpectedProtocolVersion
               (const wchar_t*               place,
                const wchar_t*               point,
                protocol::P_PROTOCOL_VERSION protocolVersion);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_BadCnHandle
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_BadTrHandle
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_TrHandleNotZero
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_BadStmtHandle
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_StmtHandleNotZero
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_BlobHandleNotZero
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_BadBlobHandle
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectBlobHandleMode
               (const wchar_t* place,
                const wchar_t* point,
                int            blobMode);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_UnexpectedChangeOfTransaction
               (const wchar_t*    place,
                const wchar_t*    point,
                protocol::P_OBJCT oldTrID,
                protocol::P_OBJCT newTrID);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void ThrowBugCheck_Incorrect_XSQLDA_Version
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* xsqlda_name,
                long           version);

  template<typename TSQLD>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_Incorrect_XSQLDA_sqld
               (subsystem_id_type subsystem_id,
                const wchar_t*    pXSQLDA_Sign,
                TSQLD             pXSQLDA_sqld);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_Incorrect_XSQLDA_sqln
               (subsystem_id_type subsystem_id,
                const wchar_t*    pXSQLDA_Sign,
                long              pXSQLDA_sqln,
                long              pXSQLDA_sqld);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_UnexpectedUserRowDataBufferSize
               (const wchar_t* place,
                const wchar_t* point,
                size_t         actualSize,
                size_t         expectedSize);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__InvalidArray__ZeroSizeOfElement
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       blrTypeID);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__InvalidArray__InvalidBufferSize
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* relation_name,
                const wchar_t* field_name,
                size_t         DefinedSize,
                size_t         ExpectedSize);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__unexpected_end_of_data
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__unk_version
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       sdlVersion);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__len_of_str_data_exceed_the_size_of_buffer_tail
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       strLength,
                size_t         bufferTailSize);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__mult_def_of_element
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* elementTagID,
                size_t         elementTagOffset);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__wrong_count_of_struct_fields
               (const wchar_t* place,
                const wchar_t* point,
                size_t         fieldCount);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__wrong_index_of_bound
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex,
                size_t         maxBoundCount);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__mult_def_of_bound_range
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__bad_bound_range
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex,
                signed __int32 lower,
                signed __int32 upper);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__unknown_kind_of_literal
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       literalKind,
                size_t         offset);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__wrong_count_of_element_fields
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       fieldCount);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__unexpected_tag
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       tagID,
                size_t         tagOffset);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__incorrect_index_property_of_scalar_tag
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       index,
                size_t         indexOffset);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__inconsistent_sizes_of_buffer_and_data
               (const wchar_t* place,
                const wchar_t* point,
                size_t         bufferSize,
                size_t         dataSize);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data_of_tag
               (const wchar_t* place,
                const wchar_t* point,
                const wchar_t* tagID);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data_of_dimensions
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__no_data_of_dimension
               (const wchar_t* place,
                const wchar_t* point,
                size_t         boundIndex);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__unknown_blrtypeid
               (const wchar_t* place,
                const wchar_t* point,
                unsigned       blrTypeID,
                size_t         offset);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__invalid_element_length
               (const wchar_t* place,
                const wchar_t* point,
                size_t         length,
                const wchar_t* blrTypeSign);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck_IncorrectSDL__failed_to_translate_str_to_unicode
               (const wchar_t* place,
                const wchar_t* point,
                wstr_box_type  cs_name);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__AuthServiceNotSupported
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__UnknownAuthServiceName
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__IncorrectAuthServiceName
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__cant_convert_auth_service_name_from_utf8_to_wstr
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__cant_convert_auth_service_name_from_wstr_to_utf8
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__cant_convert_auth_service_names_from_wstr_to_utf8
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__auth_service_already_was_used
               (const wchar_t* place,
                const wchar_t* point,
                wstr_box_type  authServiceName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__auth_service_factory_already_was_registered
               (const wchar_t* place,
                const wchar_t* point,
                wstr_box_type  authServiceName);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_utf8_to_wstr
               (const wchar_t* place,
                const wchar_t* point);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__cant_convert_name_of_wire_crypt_key_from_wstr_to_utf8
                (const wchar_t* place,
                 const wchar_t* point);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__unknown_wire_crypt_permission
               (const wchar_t*    place,
                const wchar_t*    point,
                unsigned          permission);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_BugCheck__unknown_wire_compression_rule
               (const wchar_t*    place,
                const wchar_t*    point,
                unsigned          rule);

 public:
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__MultipleDefinitionOfServerKey
               (subsystem_id_type subsystem_id,
                wstr_box_type     keyType,
                wstr_box_type     keyPlugin);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__WireCryptImpossibled_NoKnownSrvKeys
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__WireCryptImpossibled_NoCryptKeys
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw__WireCryptImpossibled_NoSupportForKnownServerKeys
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

 public:
  /// <summary>
  ///  ��������� ���������� "������������ ������������� ������� ��������������".
  /// </summary>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_AuthSvcErr__IncorrectUsage__NoCnParam
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName,
                const wchar_t*    cnParamName);

  /// <summary>
  ///  ��������� ���������� "������������ ������������� ������� ��������������".
  /// </summary>
  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_AuthSvcErr__IncorrectUsage__AlreadyWasCompleted
               (subsystem_id_type subsystem_id,
                wstr_box_type     authServiceName);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
               (const wchar_t* place,
                const wchar_t* point,
                size_t         cbAuthData);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_AuthSvcBugCheck__IncorrectLenghtOfAuthData
               (const wchar_t* place,
                const wchar_t* point,
                size_t         cbAuthData,
                size_t         cbExpectedLength);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_AuthSvcBugCheck__TooLongAuthData
               (const wchar_t* place,
                const wchar_t* point,
                size_t         cbAuthData,
                size_t         cbMaxLength);

  LCPI_CPP_CFG__DECLSPEC__NORETURN
  static void Throw_AuthSvcBugCheck__IncorrectServerKey
               (const wchar_t* place,
                const wchar_t* point);
};//class RemoteFB__ErrorUtils

////////////////////////////////////////////////////////////////////////////////
//class RemoteFB__ErrorUtils

template<typename... Args>
LCPI_CPP_CFG__DECLSPEC__NORETURN /*defined for avoiding a possible problem with MSVC*/
void RemoteFB__ErrorUtils::Throw__BugCheck__DEBUG
             (const wchar_t* const place,
              const wchar_t* const point,
              const wchar_t* const reason_template,
              Args&&...            args)
{
 assert(place);
 assert(point);
 assert(reason_template);

 IBP_ErrorUtils::Throw__BugCheck__DEBUG
  (place,
   point,
   reason_template,
   std::forward<Args>(args)...); //throw!
}//Throw__BugCheck__DEBUG

//------------------------------------------------------------------------
template<typename... Args>
LCPI_CPP_CFG__DECLSPEC__NORETURN /*defined for avoiding a possible problem with MSVC*/
void RemoteFB__ErrorUtils::Throw__Error
               (HRESULT            const hr,
                t_ibp_subsystem_id const subsystem_id,
                ibp_msg_code_type  const msg_code,
                Args&&...                args)
{
 assert(FAILED(hr));

 IBP_ErrorUtils::Throw__Error
  (hr,
   subsystem_id,
   msg_code,
   std::forward<Args>(args)...); //throw!
}//Throw__Error

//------------------------------------------------------------------------
template<typename TSQLD>
LCPI_CPP_CFG__DECLSPEC__NORETURN
void RemoteFB__ErrorUtils::Throw_BugCheck_Incorrect_XSQLDA_sqld
                                           (subsystem_id_type const subsystem_id,
                                            const wchar_t*    const pXSQLDA_Sign,
                                            TSQLD             const pXSQLDA_sqld)
{
 assert(pXSQLDA_Sign!=nullptr);

 assert_msg(false,"["<<structure::tstr_to_str(pXSQLDA_Sign)<<"] sqld: "<<pXSQLDA_sqld);

 IBP_ErrorUtils::Throw__Error
  (E_FAIL,
   subsystem_id,
   ibp_mce_isc__bug_check__incorrect_sqld_of_xsqlda_2,
   pXSQLDA_Sign,
   pXSQLDA_sqld);
}//Throw_BugCheck_Incorrect_XSQLDA_sqld

////////////////////////////////////////////////////////////////////////////////
//! @}
////////////////////////////////////////////////////////////////////////////////
}/*nms remote_fb*/}/*nms db_client*/}/*nms ibp*/}/*nms lcpi*/
#endif
